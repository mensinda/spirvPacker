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

#include "spvCfg.hpp"
#include "SimpleReflector.hpp"
#include "Enum2Str.hpp"

using namespace spirvPacker;
using namespace std;
using namespace spv;

using spirvPacker::dis::Kind;

SimpleReflector::~SimpleReflector() {}

bool SimpleReflector::initializeStage() {
  //   auto &lCfg = getStageBaseConfigSection(); // No config yet
  return true;
}

void SimpleReflector::decorate(dis::Decoration *_dec, info::IdInfoSPIRV::DEC_MAP &_out) {
  auto &lDec = _out[_dec->value];
  lDec.dec   = _dec->value;

  // ===============
  // === LAMBDAS ===
  // ===============

  auto _op = [_dec](size_t _id, std::vector<Kind> _kinds) -> shared_ptr<dis::Operand> {
    if (_id >= _dec->parameters.size())
      throw std::runtime_error("Invalid size");

    auto lOP = _dec->parameters[_id];
    for (auto const &j : _kinds)
      if (j == lOP->kind())
        return lOP;

    throw std::runtime_error("Invalid KIND " + Enum2Str::toStr(lOP->kind()));
  };

  auto lGetID  = [=](size_t _id) { return _op(_id, {Kind::IdRef, Kind::IdResult, Kind::IdResultType})->valInt(); };
  auto lGetInt = [=](size_t _id) {
    return _op(_id, {Kind::LiteralInteger, Kind::LinkageType, Kind::BuiltIn})->valInt();
  };
  auto lGetString = [=](size_t _id) { return _op(_id, {Kind::LiteralString})->valStr(); };

  switch (lDec.dec) {
    case Decoration::SpecId:
    case Decoration::ArrayStride:
    case Decoration::MatrixStride:
    case Decoration::BuiltIn:
    case Decoration::Stream:
    case Decoration::Location:
    case Decoration::Component:
    case Decoration::Index:
    case Decoration::Binding:
    case Decoration::DescriptorSet:
    case Decoration::Offset:
    case Decoration::XfbBuffer:
    case Decoration::XfbStride:
    case Decoration::InputAttachmentIndex:
    case Decoration::MaxByteOffset: lDec.i0 = lGetInt(0); break;

    case Decoration::AlignmentId:
    case Decoration::MaxByteOffsetId: lDec.i0 = lGetID(0); break;

    case Decoration::LinkageAttributes:
      lDec.s0 = lGetString(0);
      lDec.i0 = lGetInt(1);
      break;
    default: break;
  }
}


void SimpleReflector::getIdInfo(dis::DisassemblyData &_data, ShaderModule::ID_MAP &_map) {
  uint32_t lID;
  uint32_t lIndex;
  auto     lLogger = getLogger();

  std::vector<Kind> lEnumKinds = {
      Kind::Dim, Kind::ImageFormat, Kind::AccessQualifier, Kind::StorageClass, Kind::FunctionControl};

  for (auto const &i : _data.instructions) {

    // ===============
    // === LAMBDAS ===
    // ===============

    auto _op = [i](size_t _id, std::vector<Kind> _kinds) -> shared_ptr<dis::Operand> {
      if (_id >= i.operands.size())
        throw std::runtime_error("Invalid size");

      auto lOP = i.operands[_id];
      for (auto const &j : _kinds)
        if (j == lOP->kind())
          return lOP;

      throw std::runtime_error("Invalid KIND " + Enum2Str::toStr(lOP->kind()));
    };

    auto _opI      = [=](size_t _id, std::vector<Kind> _kinds) -> uint32_t { return _op(_id, _kinds)->valInt(); };
    auto GetID     = [=](size_t _id) { return _opI(_id, {Kind::IdRef, Kind::IdResult, Kind::IdResultType}); };
    auto GetInt    = [=](size_t _id) { return _opI(_id, {Kind::LiteralInteger}); };
    auto GetEnum   = [=](size_t _id) { return _opI(_id, lEnumKinds); };
    auto GetString = [=](size_t _id) { return _op(_id, {Kind::LiteralString})->valStr(); };
    auto GetDec    = [=](size_t _id) { return dynamic_cast<dis::Decoration *>(_op(_id, {Kind::Decoration}).get()); };

    auto Type = [&](size_t _id = 0) -> info::TYPE_PTR & {
      lID            = GetID(_id);
      _map[lID].id   = lID;
      _map[lID].type = info::IDType::Type;
      return _map[lID].typeInfo;
    };

    auto Const = [&](size_t _id = 0) -> info::CONST_PTR & {
      lID            = GetID(_id);
      _map[lID].id   = lID;
      _map[lID].type = info::IDType::Constant;
      return _map[lID].constant;
    };

    auto GetType = [&](size_t _id) -> info::TYPE_PTR {
      auto tp = _map[GetID(_id)].typeInfo;
      if (!tp)
        throw std::runtime_error("undefined type");
      return tp;
    };

    auto GetConst = [&](size_t _id) -> info::CONST_PTR {
      auto tp = _map[GetID(_id)].constant;
      if (!tp)
        throw std::runtime_error("undefined constant");
      return tp;
    };


    // ===================
    // === Main Switch ===
    // ===================

    switch (i.op) {
        // =============================
        // === Names and Decorations ===
        // =============================

      case Op::OpName:
        lID            = GetID(0);
        _map[lID].id   = lID;
        _map[lID].name = GetString(1);
        break;

      case Op::OpMemberName:
        lID                            = GetID(0);
        lIndex                         = GetInt(1);
        _map[lID].id                   = lID;
        _map[lID].members[lIndex].id   = lIndex;
        _map[lID].members[lIndex].name = GetString(2);
        break;

      case Op::OpDecorate:
      case Op::OpDecorateId:
        lID          = GetID(0);
        _map[lID].id = lID;
        decorate(GetDec(1), _map[lID].decorations);
        break;

      case Op::OpMemberDecorate:
        lID                          = GetID(0);
        lIndex                       = GetInt(1);
        _map[lID].id                 = lID;
        _map[lID].members[lIndex].id = lIndex;
        decorate(GetDec(2), _map[lID].members[lIndex].decorations);
        break;

      case Op::OpDecorationGroup:
      case Op::OpGroupDecorate:
      case Op::OpGroupMemberDecorate:
        lLogger->warn("Group decoration currently unsupported ({})", Enum2Str::toStr(i.op));
        break;

#define NEW(type, ...) std::make_shared<type>(GetID(0), ##__VA_ARGS__)

        // =============
        // === Types ===
        // =============

      case Op::OpTypeVoid: Type() = NEW(info::TypeVoid); break;
      case Op::OpTypeBool: Type() = NEW(info::TypeBool); break;
      case Op::OpTypeInt: Type() = NEW(info::TypeInt, GetInt(1), GetInt(2)); break;
      case Op::OpTypeFloat: Type() = NEW(info::TypeFloat, GetInt(1)); break;
      case Op::OpTypeVector: Type() = NEW(info::TypeVector, GetInt(2), GetType(1)); break;
      case Op::OpTypeMatrix: Type() = NEW(info::TypeMatrix, GetInt(2), GetType(1)); break;
      case Op::OpTypeImage:
        if (i.operands.size() >= 9) {
          Type() = NEW(info::TypeImage,
                       GetType(1), // Type
                       GetEnum(2), // Dim
                       GetInt(3),  // Depth
                       GetInt(4),  // Arrayed
                       GetInt(5),  // MS
                       GetInt(6),  // Sampled
                       GetEnum(7), // image format
                       GetEnum(8)  // Access Qualifier
          );
        } else {
          Type() = NEW(info::TypeImage,
                       GetType(1), // Type
                       GetEnum(2), // Dim
                       GetInt(3),  // Depth
                       GetInt(4),  // Arrayed
                       GetInt(5),  // MS
                       GetInt(6),  // Sampled
                       GetEnum(7), // image format
                       0           // undefined
          );
        }
        break;
      case Op::OpTypeSampler: Type() = NEW(info::TypeSampler); break;
      case Op::OpTypeSampledImage: Type() = NEW(info::TypeSampledImage, GetType(1)); break;
      case Op::OpTypeArray: Type() = NEW(info::TypeArray, GetType(1), GetConst(2)); break;
      case Op::OpTypeRuntimeArray: Type() = NEW(info::TypeRuntimeArray, GetType(1)); break;
      case Op::OpTypeStruct: {
        std::vector<info::TYPE_PTR> types;
        for (size_t j = 1; j < i.operands.size(); ++j)
          types.push_back(GetType(j));

        Type() = NEW(info::TypeStruct, types);
        break;
      }
      case Op::OpTypeOpaque: Type() = NEW(info::TypeOpaque); break;
      case Op::OpTypePointer: Type() = NEW(info::TypePointer, GetEnum(1), GetType(2)); break;
      case Op::OpTypeFunction: {
        std::vector<info::TYPE_PTR> types;
        for (size_t j = 2; j < i.operands.size(); ++j)
          types.push_back(GetType(j));

        Type() = NEW(info::TypeFunction, GetType(1), types);
        break;
      }
      case Op::OpTypeEvent: Type() = NEW(info::TypeEvent); break;
      case Op::OpTypeDeviceEvent: Type() = NEW(info::TypeDeviceEvent); break;
      case Op::OpTypeReserveId: Type() = NEW(info::TypeReservedID); break;
      case Op::OpTypeQueue: Type() = NEW(info::TypeQueue); break;
      case Op::OpTypePipe: Type() = NEW(info::TypePipe); break;
      case Op::OpTypePipeStorage: Type() = NEW(info::TypePipeStorage); break;
      case Op::OpTypeNamedBarrier: Type() = NEW(info::TypeNamedBarrier); break;

      case Op::OpTypeForwardPointer: lLogger->warn("Type '{}' is currently unsupported", Enum2Str::toStr(i.op)); break;

#undef NEW

        // =================
        // === Constants ===
        // =================

      case Op::OpConstant:
        Const(1) =
            std::make_shared<info::Constant>(GetID(1), GetType(0), _opI(2, {Kind::LiteralContextDependentNumber}));
        break;

      case Op::OpConstantTrue:
      case Op::OpConstantFalse:
      case Op::OpConstantComposite:
      case Op::OpConstantSampler:
      case Op::OpConstantNull:
      case Op::OpSpecConstantTrue:
      case Op::OpSpecConstantFalse:
      case Op::OpSpecConstant:
      case Op::OpSpecConstantComposite:
      case Op::OpSpecConstantOp:
        lLogger->warn("Constant '{}' is currently unsupported", Enum2Str::toStr(i.op));
        break;


        // ===========
        // === ETC ===
        // ===========

      case Op::OpVariable:
        lID                    = GetID(1);
        _map[lID].id           = lID;
        _map[lID].type         = info::IDType::Variable;
        _map[lID].typeInfo     = GetType(0);
        _map[lID].storageClass = static_cast<StorageClass>(GetEnum(2));
        break;

      case Op::OpFunction:
        lID                       = GetID(1);
        _map[lID].id              = lID;
        _map[lID].type            = info::IDType::Function;
        _map[lID].typeInfo        = GetType(3);
        _map[lID].functionControl = GetEnum(2);
        break;

      default: break;
    }
  }
}

void SimpleReflector::getIOInfo(ShaderModule::ID_MAP &_map, info::ShaderIOInfo &_info) {
  (void)_info;
  auto lLogger = getLogger();

  for (auto &i : _map) {
    // Only Variables are interresting
    if (i.second.type != info::IDType::Variable)
      continue;

    // Only Pointer point to IO and uniforms
    if (i.second.typeInfo->type() != info::Type::Pointer)
      continue;

    info::TypePointer *lPTR = dynamic_cast<info::TypePointer *>(i.second.typeInfo.get());
    if (!lPTR) {
      lLogger->warn("Corrupt type information for {} (ID: {})", i.second.name, i.second.id);
      continue;
    }

    auto lSerarchFor = [=](spv::Decoration _dec) -> uint32_t {
      uint32_t lRet = UINT32_MAX;
      for (auto &j : i.second.decorations) {
        if (j.second.dec == _dec) {
          lRet = j.second.i0;
          break;
        }
      }

      if (lRet == UINT32_MAX) {
        lLogger->warn("Corrupt IO decoration {} (ID: {})", Enum2Str::toStr(_dec), i.second.id);
        throw std::runtime_error("Corrupt Decoration");
      }
      return lRet;
    };

    // Skip builtin stuff
    if (_map[lPTR->pointerType()->id()].name == "gl_PerVertex" || _map[lPTR->id()].name == "gl_PerVertex")
      continue;

    switch (lPTR->storageClass()) {
      case StorageClass::Input: {
        info::ShaderIOInfo::IO lIn;
        lIn.name         = i.second.name;
        lIn.type         = lPTR->pointerType();
        lIn.storageClass = lPTR->storageClass();
        lIn.location     = lSerarchFor(spv::Decoration::Location);
        _info.inputs.push_back(lIn);
        break;
      }

      case StorageClass::Output: {
        info::ShaderIOInfo::IO lOut;
        lOut.name         = i.second.name;
        lOut.type         = lPTR->pointerType();
        lOut.storageClass = lPTR->storageClass();
        lOut.location     = lSerarchFor(spv::Decoration::Location);
        _info.outputs.push_back(lOut);
        break;
      }

      case StorageClass::UniformConstant: break;

      case StorageClass::Uniform: break;

      case StorageClass::PushConstant: break;

      case StorageClass::Image:
      case StorageClass::Workgroup:
      case StorageClass::CrossWorkgroup:
      case StorageClass::Private:
      case StorageClass::Function:
      case StorageClass::Generic:
      case StorageClass::AtomicCounter:
      case StorageClass::StorageBuffer:
      case StorageClass::Max:
        lLogger->warn("Storage class {} is currently unsupported", Enum2Str::toStr(lPTR->storageClass()));
        break;
    }

    lLogger->debug("Found IO: {} ({})", i.second.name, Enum2Str::toStr(lPTR->storageClass()));
  }
}



StageResult SimpleReflector::reflectModule(ShaderModule &_mod) {
  auto  lLogger  = getLogger();
  auto &lDisData = _mod.getDisassemblyDataRef();
  auto &lIdInfo  = _mod.getIdInformationMapRef();
  auto &lIOInfo  = _mod.getModuleIOInfoRef();

  // Check if there is data
  if (lDisData.magicNumber == 0) {
    lLogger->error("No disasembly information");
    return StageResult::PREVIOUS_STAGE_MISSING;
  }

  try {
    getIdInfo(lDisData, lIdInfo);
    getIOInfo(lIdInfo, lIOInfo);
  } catch (std::runtime_error &e) {
    lLogger->error("Reflection error: '{}'", e.what());
    return StageResult::REFLECTOR_ERROR;
  }

  for (auto &i : lIdInfo) {
    auto PrintDec = [lLogger](info::IdInfoSPIRV &_inf) {
      for (auto k : _inf.decorations) {
        if (k.second.i0 == UINT32_MAX)
          lLogger->debug("   - {}", Enum2Str::toStr(k.second.dec));
        else
          lLogger->debug("   - {} = {}", Enum2Str::toStr(k.second.dec), k.second.i0);
      }
    };

    info::IdInfoSPIRV &lInf = i.second;
    lLogger->debug("ID: {}; type: [{:^8}]; name: {}", lInf.id, Enum2Str::toStr(lInf.type), lInf.name);
    PrintDec(lInf);

    for (auto &j : i.second.members) {
      info::IdInfoSPIRV &lMem = j.second;
      lLogger->debug(" -- Index: {}; type: [{:^8}]; name: {}", lMem.id, Enum2Str::toStr(lMem.type), lMem.name);
      PrintDec(lMem);
    }
  }

  return StageResult::SUCCESS;
}

StageResult SimpleReflector::reflectShader(Shader *_shader) {
  auto lLogger = getLogger();
  if (!_shader) {
    lLogger->error("The shader may not be null.");
    return StageResult::ERROR;
  }

  return StageResult::SUCCESS;
}
