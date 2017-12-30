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

#include "spvCfg.hpp"
#include "SPIRVOperands.hpp"
#include "Enum2Str.hpp"

using namespace spirvPacker::dis;

std::string ImageOperands::valStr() const { return Enum2Str::spv_ImageOperandsMask_toStr(value); }
std::string FPFastMathMode::valStr() const { return Enum2Str::spv_FPFastMathModeMask_toStr(value); }
std::string SelectionControl::valStr() const { return Enum2Str::spv_SelectionControlMask_toStr(value); }
std::string LoopControl::valStr() const { return Enum2Str::spv_LoopControlMask_toStr(value); }
std::string FunctionControl::valStr() const { return Enum2Str::spv_FunctionControlMask_toStr(value); }
std::string MemorySemantics::valStr() const { return Enum2Str::spv_MemorySemanticsMask_toStr(value); }
std::string MemoryAccess::valStr() const { return Enum2Str::spv_MemoryAccessMask_toStr(value); }
std::string KernelProfilingInfo::valStr() const { return Enum2Str::spv_KernelProfilingInfoMask_toStr(value); }
std::string SourceLanguage::valStr() const { return Enum2Str::toStr(value); }
std::string ExecutionModel::valStr() const { return Enum2Str::toStr(value); }
std::string AddressingModel::valStr() const { return Enum2Str::toStr(value); }
std::string MemoryModel::valStr() const { return Enum2Str::toStr(value); }
std::string ExecutionMode::valStr() const { return Enum2Str::toStr(value); }
std::string StorageClass::valStr() const { return Enum2Str::toStr(value); }
std::string Dim::valStr() const { return Enum2Str::toStr(value); }
std::string SamplerAddressingMode::valStr() const { return Enum2Str::toStr(value); }
std::string SamplerFilterMode::valStr() const { return Enum2Str::toStr(value); }
std::string ImageFormat::valStr() const { return Enum2Str::toStr(value); }
std::string ImageChannelOrder::valStr() const { return Enum2Str::toStr(value); }
std::string ImageChannelDataType::valStr() const { return Enum2Str::toStr(value); }
std::string FPRoundingMode::valStr() const { return Enum2Str::toStr(value); }
std::string LinkageType::valStr() const { return Enum2Str::toStr(value); }
std::string AccessQualifier::valStr() const { return Enum2Str::toStr(value); }
std::string FunctionParameterAttribute::valStr() const { return Enum2Str::toStr(value); }
std::string Decoration::valStr() const { return Enum2Str::toStr(value); }
std::string BuiltIn::valStr() const { return Enum2Str::toStr(value); }
std::string Scope::valStr() const { return Enum2Str::toStr(value); }
std::string GroupOperation::valStr() const { return Enum2Str::toStr(value); }
std::string KernelEnqueueFlags::valStr() const { return Enum2Str::toStr(value); }
std::string Capability::valStr() const { return Enum2Str::toStr(value); }
std::string IdResultType::valStr() const { return std::to_string(value); }
std::string IdResult::valStr() const { return std::to_string(value); }
std::string IdMemorySemantics::valStr() const { return std::to_string(value); }
std::string IdScope::valStr() const { return std::to_string(value); }
std::string IdRef::valStr() const { return std::to_string(value); }
std::string LiteralInteger::valStr() const { return std::to_string(value[0]); }
std::string LiteralString::valStr() const { return reinterpret_cast<char const *>(value.data()); }
std::string LiteralContextDependentNumber::valStr() const { return std::to_string(value[0]); }
std::string LiteralExtInstInteger::valStr() const { return std::to_string(value[0]); }
std::string LiteralSpecConstantOpInteger::valStr() const { return std::to_string(value[0]); }
