/*
 * Copyright (C) 2018 Daniel Mensinger
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "spvCfg.hpp"

namespace spirvPacker {
namespace info {

//! \brief All currently supported SPIRV id types / categories
enum class IDType { Variable, Function, Type, Constant, Unknown };

//! \brief All currently supported SPIRV types
enum class Type {
  Void,
  Bool,
  Int,
  Float,
  Vector,
  Matrix,
  Image,
  Sampler,
  SampledImage,
  Array,
  RuntimeArray,
  Struct,
  Opaque,
  Pointer,
  Function,
  Event,
  DeviceEvent,
  ReservedID,
  Queue,
  Pipe,
  ForwardPointer,
  PipeStorage,
  NamedBarrier
};

/*!
 * \brief Stores all information of one decoration
 *
 * Add additional i and s values as needed
 */
struct Decoration {
  spv::Decoration dec;
  uint32_t        i0 = UINT32_MAX;
  std::string     s0 = "";
};

class TypeBase;
class ConstBase;
typedef std::shared_ptr<TypeBase>  TYPE_PTR;
typedef std::shared_ptr<ConstBase> CONST_PTR;

//! \brief Base class for all SPIRV type structures
class TypeBase {
 private:
  uint32_t vID = UINT32_MAX;

 public:
  TypeBase() = delete;
  TypeBase(uint32_t _id) : vID(_id) {}
  virtual ~TypeBase() {}
  virtual uint32_t size() const noexcept { return 0; }
  virtual Type     type() const noexcept = 0;
  uint32_t         id() const noexcept { return vID; }
};

class ConstBase {
 private:
  uint32_t vID = UINT32_MAX;

 public:
  ConstBase() = delete;
  ConstBase(uint32_t _id) : vID(_id) {}
  virtual ~ConstBase() {}
  virtual uint32_t value() const noexcept = 0;
  virtual TYPE_PTR type() const noexcept  = 0;
  uint32_t         id() const noexcept { return vID; }
};

class Constant final : public ConstBase {
  TYPE_PTR              typ;
  std::vector<uint32_t> val;

 public:
  Constant(uint32_t _id, TYPE_PTR _type, std::vector<uint32_t> _values) : ConstBase(_id), typ(_type), val(_values) {}
  Constant(uint32_t _id, TYPE_PTR _type, uint32_t _value) : ConstBase(_id), typ(_type), val({_value}) {}
  inline TYPE_PTR              type() const noexcept override { return typ; }
  inline std::vector<uint32_t> values() const noexcept { return val; }
  inline uint32_t              value() const noexcept override {
    if (val.empty())
      return 0;
    return val[0];
  }
};



//! \brief All information of a SPIRV ID
struct IdInfoSPIRV {
  typedef std::map<spv::Decoration, Decoration> DEC_MAP;

  IDType            type            = IDType::Unknown;
  uint32_t          id              = UINT32_MAX;                 //!< \brief The ID
  std::string       name            = "<N/A>";                    //!< \brief The name of the member
  spv::StorageClass storageClass    = spv::StorageClass::Generic; //!< \brief The storage class of a variable
  uint32_t          functionControl = 0;                          //!< \brief The function controll mask for a function

  DEC_MAP   decorations;
  TYPE_PTR  typeInfo = nullptr;
  CONST_PTR constant = nullptr;

  std::map<uint32_t, IdInfoSPIRV> members;
};

struct ShaderIOInfo {
  struct BaseIO {
    TYPE_PTR          type         = nullptr;
    spv::StorageClass storageClass = spv::StorageClass::Generic;
    std::string       name         = "";
  };

  struct IO : BaseIO {
    uint32_t location = 0;
  };
  struct Uniform : BaseIO {
    uint32_t set     = 0;
    uint32_t binding = 0;
  };
  struct SubpassData : Uniform {
    uint32_t inputAttachmentIndex = 0;
  };

  std::vector<IO>          inputs;
  std::vector<IO>          outputs;
  std::vector<Uniform>     uniforms;
  std::vector<Uniform>     pushConstants;
  std::vector<SubpassData> subpassInput;
};


// =============================
// === Begin Type structures ===
// =============================

class TypeVoid final : public TypeBase {
 public:
  TypeVoid(uint32_t _id) : TypeBase(_id) {}
  inline uint32_t size() const noexcept override { return 0; }
  inline Type     type() const noexcept override { return Type::Void; }
};

class TypeBool final : public TypeBase {
 public:
  TypeBool(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Bool; }
};

class TypeInt final : public TypeBase {
 public:
  enum class Signed { No = 0, Yes = 1 };

 private:
  uint32_t s;
  Signed   sign;

 public:
  TypeInt(uint32_t _id, uint32_t _size, Signed _signed) : TypeBase(_id), s(_size), sign(_signed) {}
  TypeInt(uint32_t _id, uint32_t _size, uint32_t _signed)
      : TypeBase(_id), s(_size), sign(static_cast<Signed>(_signed)) {}
  inline uint32_t size() const noexcept override { return s; }
  inline Type     type() const noexcept override { return Type::Int; }
  inline bool     isSigned() const noexcept { return sign == Signed::Yes; }
  inline Signed   signedness() const noexcept { return sign; }
};

class TypeFloat final : public TypeBase {
  uint32_t s;

 public:
  TypeFloat(uint32_t _id, uint32_t _size) : TypeBase(_id), s(_size) {}
  inline uint32_t size() const noexcept override { return s; }
  inline Type     type() const noexcept override { return Type::Float; }
};

class TypeVector final : public TypeBase {
  uint32_t cnt;
  TYPE_PTR comp;

 public:
  TypeVector(uint32_t _id, uint32_t _count, TYPE_PTR _comp) : TypeBase(_id), cnt(_count), comp(_comp) {}
  inline uint32_t size() const noexcept override { return cnt * comp->size(); }
  inline Type     type() const noexcept override { return Type::Vector; }
  inline uint32_t count() const noexcept { return cnt; }
  inline TYPE_PTR component() const noexcept { return comp; }
};

class TypeMatrix final : public TypeBase {
  uint32_t cnt;
  TYPE_PTR comp;

 public:
  TypeMatrix(uint32_t _id, uint32_t _count, TYPE_PTR _comp) : TypeBase(_id), cnt(_count), comp(_comp) {}
  inline uint32_t size() const noexcept override { return cnt * comp->size(); }
  inline Type     type() const noexcept override { return Type::Matrix; }
  inline uint32_t count() const noexcept { return cnt; }
  inline TYPE_PTR component() const noexcept { return comp; }
};

class TypeImage final : public TypeBase {
 public:
  enum class Depth { No = 0, Yes = 1, DontCare = 2 };
  enum class Arrayed { No = 0, Yes = 1 };
  enum class MultiSampling { Single = 0, Multi = 1 };
  enum class Sampled { KnowAtRuntime = 0, WillUseASampler = 1, WillNotUseASampler = 2 };

 private:
  TYPE_PTR             sampledTypePTR;
  spv::Dim             dim;
  Depth                depthEnum;
  Arrayed              arrayedEnum;
  MultiSampling        msEnum;
  Sampled              sampledEnum;
  spv::ImageFormat     format;
  spv::AccessQualifier aq;

 public:
  TypeImage(uint32_t             _id,
            TYPE_PTR             _st,
            spv::Dim             _dim,
            Depth                _depth,
            Arrayed              _arr,
            MultiSampling        _ms,
            Sampled              _sampled,
            spv::ImageFormat     _format,
            spv::AccessQualifier _aq)
      : TypeBase(_id),
        sampledTypePTR(_st),
        dim(_dim),
        depthEnum(_depth),
        arrayedEnum(_arr),
        msEnum(_ms),
        sampledEnum(_sampled),
        format(_format),
        aq(_aq) {}

  TypeImage(uint32_t _id,
            TYPE_PTR _st,
            uint32_t _dim,
            uint32_t _depth,
            uint32_t _arr,
            uint32_t _ms,
            uint32_t _sampled,
            uint32_t _format,
            uint32_t _aq)
      : TypeBase(_id),
        sampledTypePTR(_st),
        dim(static_cast<spv::Dim>(_dim)),
        depthEnum(static_cast<Depth>(_depth)),
        arrayedEnum(static_cast<Arrayed>(_arr)),
        msEnum(static_cast<MultiSampling>(_ms)),
        sampledEnum(static_cast<Sampled>(_sampled)),
        format(static_cast<spv::ImageFormat>(_format)),
        aq(static_cast<spv::AccessQualifier>(_aq)) {}
  inline Type          type() const noexcept override { return Type::Image; }
  inline TYPE_PTR      sampledType() const noexcept { return sampledTypePTR; }
  inline spv::Dim      dimension() const noexcept { return dim; }
  inline Depth         depth() const noexcept { return depthEnum; }
  inline Arrayed       arrayed() const noexcept { return arrayedEnum; }
  inline MultiSampling multiSampling() const noexcept { return msEnum; }
  inline Sampled       sampled() const noexcept { return sampledEnum; }
  spv::ImageFormat     imageFormat() const noexcept { return format; }
  spv::AccessQualifier accessQualifier() const noexcept { return aq; }
};

class TypeSampler final : public TypeBase {
 public:
  TypeSampler(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Sampler; }
};

class TypeSampledImage final : public TypeBase {
  TYPE_PTR img;

 public:
  TypeSampledImage(uint32_t _id, TYPE_PTR _image) : TypeBase(_id), img(_image) {}
  inline Type     type() const noexcept override { return Type::SampledImage; }
  inline TYPE_PTR image() const noexcept { return img; }
};

class TypeArray final : public TypeBase {
  TYPE_PTR  comp;
  CONST_PTR len;

 public:
  TypeArray(uint32_t _id, TYPE_PTR _componentType, CONST_PTR _length)
      : TypeBase(_id), comp(_componentType), len(_length) {}
  inline uint32_t  size() const noexcept override { return comp->size() * len->value(); }
  inline Type      type() const noexcept override { return Type::Array; }
  inline TYPE_PTR  componentType() const noexcept { return comp; }
  inline CONST_PTR length() const noexcept { return len; }
};

class TypeRuntimeArray final : public TypeBase {
  TYPE_PTR comp;

 public:
  TypeRuntimeArray(uint32_t _id, TYPE_PTR _componentType) : TypeBase(_id), comp(_componentType) {}
  inline Type     type() const noexcept override { return Type::RuntimeArray; }
  inline TYPE_PTR componentType() const noexcept { return comp; }
};

class TypeStruct final : public TypeBase {
  std::vector<TYPE_PTR> comps;

 public:
  TypeStruct(uint32_t _id, std::vector<TYPE_PTR> _members) : TypeBase(_id), comps(_members) {}
  inline Type                  type() const noexcept override { return Type::Struct; }
  inline std::vector<TYPE_PTR> members() const noexcept { return comps; }
};

class TypeOpaque final : public TypeBase {
 public:
  TypeOpaque(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Opaque; }
};

class TypePointer final : public TypeBase {
  spv::StorageClass stoClass;
  TYPE_PTR          typ;

 public:
  TypePointer(uint32_t _id, spv::StorageClass _class, TYPE_PTR _type) : TypeBase(_id), stoClass(_class), typ(_type) {}
  TypePointer(uint32_t _id, uint32_t _class, TYPE_PTR _type)
      : TypeBase(_id), stoClass(static_cast<spv::StorageClass>(_class)), typ(_type) {}
  inline Type              type() const noexcept override { return Type::Pointer; }
  inline spv::StorageClass storageClass() const noexcept { return stoClass; }
  inline TYPE_PTR          pointerType() const noexcept { return typ; }
};

class TypeFunction final : public TypeBase {
  TYPE_PTR              retType;
  std::vector<TYPE_PTR> param;

 public:
  TypeFunction(uint32_t _id, TYPE_PTR _ret, std::vector<TYPE_PTR> _parameters)
      : TypeBase(_id), retType(_ret), param(_parameters) {}
  inline Type                  type() const noexcept override { return Type::Function; }
  inline std::vector<TYPE_PTR> parameters() const noexcept { return param; }
  inline TYPE_PTR              returnType() const noexcept { return retType; }
};

class TypeEvent final : public TypeBase {
 public:
  TypeEvent(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Event; }
};

class TypeDeviceEvent final : public TypeBase {
 public:
  TypeDeviceEvent(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::DeviceEvent; }
};

class TypeReservedID final : public TypeBase {
 public:
  TypeReservedID(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::ReservedID; }
};

class TypeQueue final : public TypeBase {
 public:
  TypeQueue(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Queue; }
};

class TypePipe final : public TypeBase {
 public:
  TypePipe(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::Pipe; }
};

class TypePipeStorage final : public TypeBase {
 public:
  TypePipeStorage(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::PipeStorage; }
};

class TypeNamedBarrier final : public TypeBase {
 public:
  TypeNamedBarrier(uint32_t _id) : TypeBase(_id) {}
  inline Type type() const noexcept override { return Type::NamedBarrier; }
};

} // namespace info
} // namespace spirvPacker
