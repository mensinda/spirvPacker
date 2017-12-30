/*
 * Copyright (C) 2017 Daniel Mensinger
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
/*!
 * \note This is an automatically generated file
 * \warning All changes to this file will be lost
 * Generated with ./lib/generateOperands.sh
 */

#pragma once

#include "spvCfg.hpp"
#include <spirv.hpp>
#include <string>
#include <vector>

namespace spirvPacker {
namespace dis {

typedef std::vector<uint32_t>::iterator ITER;

enum class Category {
  BitEnum,
  Composite,
  Id,
  Literal,
  ValueEnum,
};

enum class Kind {
  ImageOperands,
  FPFastMathMode,
  SelectionControl,
  LoopControl,
  FunctionControl,
  MemorySemantics,
  MemoryAccess,
  KernelProfilingInfo,
  SourceLanguage,
  ExecutionModel,
  AddressingModel,
  MemoryModel,
  ExecutionMode,
  StorageClass,
  Dim,
  SamplerAddressingMode,
  SamplerFilterMode,
  ImageFormat,
  ImageChannelOrder,
  ImageChannelDataType,
  FPRoundingMode,
  LinkageType,
  AccessQualifier,
  FunctionParameterAttribute,
  Decoration,
  BuiltIn,
  Scope,
  GroupOperation,
  KernelEnqueueFlags,
  Capability,
  IdResultType,
  IdResult,
  IdMemorySemantics,
  IdScope,
  IdRef,
  LiteralInteger,
  LiteralString,
  LiteralContextDependentNumber,
  LiteralExtInstInteger,
  LiteralSpecConstantOpInteger,
  PairLiteralIntegerIdRef,
  PairIdRefLiteralInteger,
  PairIdRefIdRef,
};

struct Operand {
  std::string name       = "";
  std::string quantifier = "";

  std::vector<std::shared_ptr<Operand>> parameters;

  virtual Category    category() const = 0;
  virtual Kind        kind() const     = 0;
  virtual std::string doc() const      = 0;

  virtual uint32_t    valInt() const { return UINT32_MAX; }
  virtual std::string valStr() const { return ""; }

  Operand(std::string _name, std::string _quan) : name(_name), quantifier(_quan) {}
  virtual ~Operand() {}
};


struct ImageOperands final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::ImageOperands; }
  inline std::string doc() const override { return ""; }
  ImageOperands(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct FPFastMathMode final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::FPFastMathMode; }
  inline std::string doc() const override { return ""; }
  FPFastMathMode(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct SelectionControl final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::SelectionControl; }
  inline std::string doc() const override { return ""; }
  SelectionControl(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LoopControl final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::LoopControl; }
  inline std::string doc() const override { return ""; }
  LoopControl(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct FunctionControl final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::FunctionControl; }
  inline std::string doc() const override { return ""; }
  FunctionControl(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct MemorySemantics final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::MemorySemantics; }
  inline std::string doc() const override { return ""; }
  MemorySemantics(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct MemoryAccess final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::MemoryAccess; }
  inline std::string doc() const override { return ""; }
  MemoryAccess(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct KernelProfilingInfo final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::BitEnum; }
  inline Kind        kind() const override { return Kind::KernelProfilingInfo; }
  inline std::string doc() const override { return ""; }
  KernelProfilingInfo(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct SourceLanguage final : Operand {
  spv::SourceLanguage value;
  inline uint32_t     valInt() const override { return static_cast<uint32_t>(value); }
  std::string         valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::SourceLanguage; }
  inline std::string doc() const override { return ""; }
  SourceLanguage(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct ExecutionModel final : Operand {
  spv::ExecutionModel value;
  inline uint32_t     valInt() const override { return static_cast<uint32_t>(value); }
  std::string         valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::ExecutionModel; }
  inline std::string doc() const override { return ""; }
  ExecutionModel(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct AddressingModel final : Operand {
  spv::AddressingModel value;
  inline uint32_t      valInt() const override { return static_cast<uint32_t>(value); }
  std::string          valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::AddressingModel; }
  inline std::string doc() const override { return ""; }
  AddressingModel(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct MemoryModel final : Operand {
  spv::MemoryModel value;
  inline uint32_t  valInt() const override { return static_cast<uint32_t>(value); }
  std::string      valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::MemoryModel; }
  inline std::string doc() const override { return ""; }
  MemoryModel(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct ExecutionMode final : Operand {
  spv::ExecutionMode value;
  inline uint32_t    valInt() const override { return static_cast<uint32_t>(value); }
  std::string        valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::ExecutionMode; }
  inline std::string doc() const override { return ""; }
  ExecutionMode(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct StorageClass final : Operand {
  spv::StorageClass value;
  inline uint32_t   valInt() const override { return static_cast<uint32_t>(value); }
  std::string       valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::StorageClass; }
  inline std::string doc() const override { return ""; }
  StorageClass(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct Dim final : Operand {
  spv::Dim        value;
  inline uint32_t valInt() const override { return static_cast<uint32_t>(value); }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::Dim; }
  inline std::string doc() const override { return ""; }
  Dim(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct SamplerAddressingMode final : Operand {
  spv::SamplerAddressingMode value;
  inline uint32_t            valInt() const override { return static_cast<uint32_t>(value); }
  std::string                valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::SamplerAddressingMode; }
  inline std::string doc() const override { return ""; }
  SamplerAddressingMode(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct SamplerFilterMode final : Operand {
  spv::SamplerFilterMode value;
  inline uint32_t        valInt() const override { return static_cast<uint32_t>(value); }
  std::string            valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::SamplerFilterMode; }
  inline std::string doc() const override { return ""; }
  SamplerFilterMode(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct ImageFormat final : Operand {
  spv::ImageFormat value;
  inline uint32_t  valInt() const override { return static_cast<uint32_t>(value); }
  std::string      valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::ImageFormat; }
  inline std::string doc() const override { return ""; }
  ImageFormat(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct ImageChannelOrder final : Operand {
  spv::ImageChannelOrder value;
  inline uint32_t        valInt() const override { return static_cast<uint32_t>(value); }
  std::string            valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::ImageChannelOrder; }
  inline std::string doc() const override { return ""; }
  ImageChannelOrder(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct ImageChannelDataType final : Operand {
  spv::ImageChannelDataType value;
  inline uint32_t           valInt() const override { return static_cast<uint32_t>(value); }
  std::string               valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::ImageChannelDataType; }
  inline std::string doc() const override { return ""; }
  ImageChannelDataType(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct FPRoundingMode final : Operand {
  spv::FPRoundingMode value;
  inline uint32_t     valInt() const override { return static_cast<uint32_t>(value); }
  std::string         valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::FPRoundingMode; }
  inline std::string doc() const override { return ""; }
  FPRoundingMode(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LinkageType final : Operand {
  spv::LinkageType value;
  inline uint32_t  valInt() const override { return static_cast<uint32_t>(value); }
  std::string      valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::LinkageType; }
  inline std::string doc() const override { return ""; }
  LinkageType(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct AccessQualifier final : Operand {
  spv::AccessQualifier value;
  inline uint32_t      valInt() const override { return static_cast<uint32_t>(value); }
  std::string          valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::AccessQualifier; }
  inline std::string doc() const override { return ""; }
  AccessQualifier(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct FunctionParameterAttribute final : Operand {
  spv::FunctionParameterAttribute value;
  inline uint32_t                 valInt() const override { return static_cast<uint32_t>(value); }
  std::string                     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::FunctionParameterAttribute; }
  inline std::string doc() const override { return ""; }
  FunctionParameterAttribute(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct Decoration final : Operand {
  spv::Decoration value;
  inline uint32_t valInt() const override { return static_cast<uint32_t>(value); }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::Decoration; }
  inline std::string doc() const override { return ""; }
  Decoration(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct BuiltIn final : Operand {
  spv::BuiltIn    value;
  inline uint32_t valInt() const override { return static_cast<uint32_t>(value); }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::BuiltIn; }
  inline std::string doc() const override { return ""; }
  BuiltIn(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct Scope final : Operand {
  spv::Scope      value;
  inline uint32_t valInt() const override { return static_cast<uint32_t>(value); }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::Scope; }
  inline std::string doc() const override { return ""; }
  Scope(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct GroupOperation final : Operand {
  spv::GroupOperation value;
  inline uint32_t     valInt() const override { return static_cast<uint32_t>(value); }
  std::string         valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::GroupOperation; }
  inline std::string doc() const override { return ""; }
  GroupOperation(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct KernelEnqueueFlags final : Operand {
  spv::KernelEnqueueFlags value;
  inline uint32_t         valInt() const override { return static_cast<uint32_t>(value); }
  std::string             valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::KernelEnqueueFlags; }
  inline std::string doc() const override { return ""; }
  KernelEnqueueFlags(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct Capability final : Operand {
  spv::Capability value;
  inline uint32_t valInt() const override { return static_cast<uint32_t>(value); }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::ValueEnum; }
  inline Kind        kind() const override { return Kind::Capability; }
  inline std::string doc() const override { return ""; }
  Capability(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct IdResultType final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::Id; }
  inline Kind        kind() const override { return Kind::IdResultType; }
  inline std::string doc() const override {
    return "Reference to an <id> representing the result's type of the enclosing instruction";
  }
  IdResultType(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct IdResult final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::Id; }
  inline Kind        kind() const override { return Kind::IdResult; }
  inline std::string doc() const override {
    return "Definition of an <id> representing the result of the enclosing instruction";
  }
  IdResult(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct IdMemorySemantics final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::Id; }
  inline Kind        kind() const override { return Kind::IdMemorySemantics; }
  inline std::string doc() const override {
    return "Reference to an <id> representing a 32-bit integer that is a mask from the MemorySemantics operand kind";
  }
  IdMemorySemantics(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct IdScope final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::Id; }
  inline Kind        kind() const override { return Kind::IdScope; }
  inline std::string doc() const override {
    return "Reference to an <id> representing a 32-bit integer that is a mask from the Scope operand kind";
  }
  IdScope(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct IdRef final : Operand {
  uint32_t        value;
  inline uint32_t valInt() const override { return value; }
  std::string     valStr() const override;

  inline Category    category() const override { return Category::Id; }
  inline Kind        kind() const override { return Kind::IdRef; }
  inline std::string doc() const override { return "Reference to an <id>"; }
  IdRef(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LiteralInteger final : Operand {
  std::vector<uint32_t> value;
  inline uint32_t       valInt() const override { return value[0]; }
  std::string           valStr() const override;

  inline Category    category() const override { return Category::Literal; }
  inline Kind        kind() const override { return Kind::LiteralInteger; }
  inline std::string doc() const override { return "An integer consuming one or more words"; }
  LiteralInteger(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LiteralString final : Operand {
  std::vector<uint32_t> value;
  inline uint32_t       valInt() const override { return value[0]; }
  std::string           valStr() const override;

  inline Category    category() const override { return Category::Literal; }
  inline Kind        kind() const override { return Kind::LiteralString; }
  inline std::string doc() const override {
    return "A null-terminated stream of characters consuming an integral number of words";
  }
  LiteralString(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LiteralContextDependentNumber final : Operand {
  std::vector<uint32_t> value;
  inline uint32_t       valInt() const override { return value[0]; }
  std::string           valStr() const override;

  inline Category    category() const override { return Category::Literal; }
  inline Kind        kind() const override { return Kind::LiteralContextDependentNumber; }
  inline std::string doc() const override {
    return "A literal number whose size and format are determined by a previous operand in the enclosing instruction";
  }
  LiteralContextDependentNumber(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LiteralExtInstInteger final : Operand {
  std::vector<uint32_t> value;
  inline uint32_t       valInt() const override { return value[0]; }
  std::string           valStr() const override;

  inline Category    category() const override { return Category::Literal; }
  inline Kind        kind() const override { return Kind::LiteralExtInstInteger; }
  inline std::string doc() const override {
    return "A 32-bit unsigned integer indicating which instruction to use and determining the layout of following "
           "operands (for OpExtInst)";
  }
  LiteralExtInstInteger(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct LiteralSpecConstantOpInteger final : Operand {
  std::vector<uint32_t> value;
  inline uint32_t       valInt() const override { return value[0]; }
  std::string           valStr() const override;

  inline Category    category() const override { return Category::Literal; }
  inline Kind        kind() const override { return Kind::LiteralSpecConstantOpInteger; }
  inline std::string doc() const override {
    return "An opcode indicating the operation to be performed and determining the layout of following operands (for "
           "OpSpecConstantOp)";
  }
  LiteralSpecConstantOpInteger(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct PairLiteralIntegerIdRef final : Operand {
  LiteralInteger value0 = {"", ""};
  IdRef          value1 = {"", ""};

  inline Category    category() const override { return Category::Composite; }
  inline Kind        kind() const override { return Kind::PairLiteralIntegerIdRef; }
  inline std::string doc() const override { return ""; }
  PairLiteralIntegerIdRef(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct PairIdRefLiteralInteger final : Operand {
  IdRef          value0 = {"", ""};
  LiteralInteger value1 = {"", ""};

  inline Category    category() const override { return Category::Composite; }
  inline Kind        kind() const override { return Kind::PairIdRefLiteralInteger; }
  inline std::string doc() const override { return ""; }
  PairIdRefLiteralInteger(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};


struct PairIdRefIdRef final : Operand {
  IdRef value0 = {"", ""};
  IdRef value1 = {"", ""};

  inline Category    category() const override { return Category::Composite; }
  inline Kind        kind() const override { return Kind::PairIdRefIdRef; }
  inline std::string doc() const override { return ""; }
  PairIdRefIdRef(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};

} // namespace dis
} // namespace spirvPacker
