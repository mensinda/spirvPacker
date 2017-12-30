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
 * Generated with ./lib/disassembler/default/generateParsers.sh
 *
 * SPIRV version: 1.2.2
 */

#include "spvCfg.hpp"
#include "BinaryOpParser.hpp"

using namespace spirvPacker;
using namespace spirvPacker::dis;
using namespace std;

#define PARSE_PARAM(CURR, END, ARR, KIND, NAME)                                                                        \
  if (CURR >= END)                                                                                                     \
    return END + 1;                                                                                                    \
  ARR.push_back(make_shared<KIND>(NAME, ""));                                                                          \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_NORMAL(CURR, END, ARR, KIND, NAME)                                                                       \
  if (CURR >= END)                                                                                                     \
    return false;                                                                                                      \
  ARR.push_back(make_shared<KIND>(NAME, ""));                                                                          \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_ONE(CURR, END, ARR, KIND, NAME)                                                                          \
  if (CURR >= END)                                                                                                     \
    return true;                                                                                                       \
  ARR.push_back(make_shared<KIND>(NAME, "?"));                                                                         \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_MULT(CURR, END, ARR, KIND, NAME)                                                                         \
  while (CURR < END) {                                                                                                 \
    ARR.push_back(make_shared<KIND>(NAME, "*"));                                                                       \
    CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);                                                  \
  }

bool spirvPacker::dis::parseInstruction(Instruction &_inst) {
  switch (_inst.op) {
    case spv::Op::OpNop: return parse_OpNop(_inst);
    case spv::Op::OpUndef: return parse_OpUndef(_inst);
    case spv::Op::OpSourceContinued: return parse_OpSourceContinued(_inst);
    case spv::Op::OpSource: return parse_OpSource(_inst);
    case spv::Op::OpSourceExtension: return parse_OpSourceExtension(_inst);
    case spv::Op::OpName: return parse_OpName(_inst);
    case spv::Op::OpMemberName: return parse_OpMemberName(_inst);
    case spv::Op::OpString: return parse_OpString(_inst);
    case spv::Op::OpLine: return parse_OpLine(_inst);
    case spv::Op::OpExtension: return parse_OpExtension(_inst);
    case spv::Op::OpExtInstImport: return parse_OpExtInstImport(_inst);
    case spv::Op::OpExtInst: return parse_OpExtInst(_inst);
    case spv::Op::OpMemoryModel: return parse_OpMemoryModel(_inst);
    case spv::Op::OpEntryPoint: return parse_OpEntryPoint(_inst);
    case spv::Op::OpExecutionMode: return parse_OpExecutionMode(_inst);
    case spv::Op::OpCapability: return parse_OpCapability(_inst);
    case spv::Op::OpTypeVoid: return parse_OpTypeVoid(_inst);
    case spv::Op::OpTypeBool: return parse_OpTypeBool(_inst);
    case spv::Op::OpTypeInt: return parse_OpTypeInt(_inst);
    case spv::Op::OpTypeFloat: return parse_OpTypeFloat(_inst);
    case spv::Op::OpTypeVector: return parse_OpTypeVector(_inst);
    case spv::Op::OpTypeMatrix: return parse_OpTypeMatrix(_inst);
    case spv::Op::OpTypeImage: return parse_OpTypeImage(_inst);
    case spv::Op::OpTypeSampler: return parse_OpTypeSampler(_inst);
    case spv::Op::OpTypeSampledImage: return parse_OpTypeSampledImage(_inst);
    case spv::Op::OpTypeArray: return parse_OpTypeArray(_inst);
    case spv::Op::OpTypeRuntimeArray: return parse_OpTypeRuntimeArray(_inst);
    case spv::Op::OpTypeStruct: return parse_OpTypeStruct(_inst);
    case spv::Op::OpTypeOpaque: return parse_OpTypeOpaque(_inst);
    case spv::Op::OpTypePointer: return parse_OpTypePointer(_inst);
    case spv::Op::OpTypeFunction: return parse_OpTypeFunction(_inst);
    case spv::Op::OpTypeEvent: return parse_OpTypeEvent(_inst);
    case spv::Op::OpTypeDeviceEvent: return parse_OpTypeDeviceEvent(_inst);
    case spv::Op::OpTypeReserveId: return parse_OpTypeReserveId(_inst);
    case spv::Op::OpTypeQueue: return parse_OpTypeQueue(_inst);
    case spv::Op::OpTypePipe: return parse_OpTypePipe(_inst);
    case spv::Op::OpTypeForwardPointer: return parse_OpTypeForwardPointer(_inst);
    case spv::Op::OpConstantTrue: return parse_OpConstantTrue(_inst);
    case spv::Op::OpConstantFalse: return parse_OpConstantFalse(_inst);
    case spv::Op::OpConstant: return parse_OpConstant(_inst);
    case spv::Op::OpConstantComposite: return parse_OpConstantComposite(_inst);
    case spv::Op::OpConstantSampler: return parse_OpConstantSampler(_inst);
    case spv::Op::OpConstantNull: return parse_OpConstantNull(_inst);
    case spv::Op::OpSpecConstantTrue: return parse_OpSpecConstantTrue(_inst);
    case spv::Op::OpSpecConstantFalse: return parse_OpSpecConstantFalse(_inst);
    case spv::Op::OpSpecConstant: return parse_OpSpecConstant(_inst);
    case spv::Op::OpSpecConstantComposite: return parse_OpSpecConstantComposite(_inst);
    case spv::Op::OpSpecConstantOp: return parse_OpSpecConstantOp(_inst);
    case spv::Op::OpFunction: return parse_OpFunction(_inst);
    case spv::Op::OpFunctionParameter: return parse_OpFunctionParameter(_inst);
    case spv::Op::OpFunctionEnd: return parse_OpFunctionEnd(_inst);
    case spv::Op::OpFunctionCall: return parse_OpFunctionCall(_inst);
    case spv::Op::OpVariable: return parse_OpVariable(_inst);
    case spv::Op::OpImageTexelPointer: return parse_OpImageTexelPointer(_inst);
    case spv::Op::OpLoad: return parse_OpLoad(_inst);
    case spv::Op::OpStore: return parse_OpStore(_inst);
    case spv::Op::OpCopyMemory: return parse_OpCopyMemory(_inst);
    case spv::Op::OpCopyMemorySized: return parse_OpCopyMemorySized(_inst);
    case spv::Op::OpAccessChain: return parse_OpAccessChain(_inst);
    case spv::Op::OpInBoundsAccessChain: return parse_OpInBoundsAccessChain(_inst);
    case spv::Op::OpPtrAccessChain: return parse_OpPtrAccessChain(_inst);
    case spv::Op::OpArrayLength: return parse_OpArrayLength(_inst);
    case spv::Op::OpGenericPtrMemSemantics: return parse_OpGenericPtrMemSemantics(_inst);
    case spv::Op::OpInBoundsPtrAccessChain: return parse_OpInBoundsPtrAccessChain(_inst);
    case spv::Op::OpDecorate: return parse_OpDecorate(_inst);
    case spv::Op::OpMemberDecorate: return parse_OpMemberDecorate(_inst);
    case spv::Op::OpDecorationGroup: return parse_OpDecorationGroup(_inst);
    case spv::Op::OpGroupDecorate: return parse_OpGroupDecorate(_inst);
    case spv::Op::OpGroupMemberDecorate: return parse_OpGroupMemberDecorate(_inst);
    case spv::Op::OpVectorExtractDynamic: return parse_OpVectorExtractDynamic(_inst);
    case spv::Op::OpVectorInsertDynamic: return parse_OpVectorInsertDynamic(_inst);
    case spv::Op::OpVectorShuffle: return parse_OpVectorShuffle(_inst);
    case spv::Op::OpCompositeConstruct: return parse_OpCompositeConstruct(_inst);
    case spv::Op::OpCompositeExtract: return parse_OpCompositeExtract(_inst);
    case spv::Op::OpCompositeInsert: return parse_OpCompositeInsert(_inst);
    case spv::Op::OpCopyObject: return parse_OpCopyObject(_inst);
    case spv::Op::OpTranspose: return parse_OpTranspose(_inst);
    case spv::Op::OpSampledImage: return parse_OpSampledImage(_inst);
    case spv::Op::OpImageSampleImplicitLod: return parse_OpImageSampleImplicitLod(_inst);
    case spv::Op::OpImageSampleExplicitLod: return parse_OpImageSampleExplicitLod(_inst);
    case spv::Op::OpImageSampleDrefImplicitLod: return parse_OpImageSampleDrefImplicitLod(_inst);
    case spv::Op::OpImageSampleDrefExplicitLod: return parse_OpImageSampleDrefExplicitLod(_inst);
    case spv::Op::OpImageSampleProjImplicitLod: return parse_OpImageSampleProjImplicitLod(_inst);
    case spv::Op::OpImageSampleProjExplicitLod: return parse_OpImageSampleProjExplicitLod(_inst);
    case spv::Op::OpImageSampleProjDrefImplicitLod: return parse_OpImageSampleProjDrefImplicitLod(_inst);
    case spv::Op::OpImageSampleProjDrefExplicitLod: return parse_OpImageSampleProjDrefExplicitLod(_inst);
    case spv::Op::OpImageFetch: return parse_OpImageFetch(_inst);
    case spv::Op::OpImageGather: return parse_OpImageGather(_inst);
    case spv::Op::OpImageDrefGather: return parse_OpImageDrefGather(_inst);
    case spv::Op::OpImageRead: return parse_OpImageRead(_inst);
    case spv::Op::OpImageWrite: return parse_OpImageWrite(_inst);
    case spv::Op::OpImage: return parse_OpImage(_inst);
    case spv::Op::OpImageQueryFormat: return parse_OpImageQueryFormat(_inst);
    case spv::Op::OpImageQueryOrder: return parse_OpImageQueryOrder(_inst);
    case spv::Op::OpImageQuerySizeLod: return parse_OpImageQuerySizeLod(_inst);
    case spv::Op::OpImageQuerySize: return parse_OpImageQuerySize(_inst);
    case spv::Op::OpImageQueryLod: return parse_OpImageQueryLod(_inst);
    case spv::Op::OpImageQueryLevels: return parse_OpImageQueryLevels(_inst);
    case spv::Op::OpImageQuerySamples: return parse_OpImageQuerySamples(_inst);
    case spv::Op::OpConvertFToU: return parse_OpConvertFToU(_inst);
    case spv::Op::OpConvertFToS: return parse_OpConvertFToS(_inst);
    case spv::Op::OpConvertSToF: return parse_OpConvertSToF(_inst);
    case spv::Op::OpConvertUToF: return parse_OpConvertUToF(_inst);
    case spv::Op::OpUConvert: return parse_OpUConvert(_inst);
    case spv::Op::OpSConvert: return parse_OpSConvert(_inst);
    case spv::Op::OpFConvert: return parse_OpFConvert(_inst);
    case spv::Op::OpQuantizeToF16: return parse_OpQuantizeToF16(_inst);
    case spv::Op::OpConvertPtrToU: return parse_OpConvertPtrToU(_inst);
    case spv::Op::OpSatConvertSToU: return parse_OpSatConvertSToU(_inst);
    case spv::Op::OpSatConvertUToS: return parse_OpSatConvertUToS(_inst);
    case spv::Op::OpConvertUToPtr: return parse_OpConvertUToPtr(_inst);
    case spv::Op::OpPtrCastToGeneric: return parse_OpPtrCastToGeneric(_inst);
    case spv::Op::OpGenericCastToPtr: return parse_OpGenericCastToPtr(_inst);
    case spv::Op::OpGenericCastToPtrExplicit: return parse_OpGenericCastToPtrExplicit(_inst);
    case spv::Op::OpBitcast: return parse_OpBitcast(_inst);
    case spv::Op::OpSNegate: return parse_OpSNegate(_inst);
    case spv::Op::OpFNegate: return parse_OpFNegate(_inst);
    case spv::Op::OpIAdd: return parse_OpIAdd(_inst);
    case spv::Op::OpFAdd: return parse_OpFAdd(_inst);
    case spv::Op::OpISub: return parse_OpISub(_inst);
    case spv::Op::OpFSub: return parse_OpFSub(_inst);
    case spv::Op::OpIMul: return parse_OpIMul(_inst);
    case spv::Op::OpFMul: return parse_OpFMul(_inst);
    case spv::Op::OpUDiv: return parse_OpUDiv(_inst);
    case spv::Op::OpSDiv: return parse_OpSDiv(_inst);
    case spv::Op::OpFDiv: return parse_OpFDiv(_inst);
    case spv::Op::OpUMod: return parse_OpUMod(_inst);
    case spv::Op::OpSRem: return parse_OpSRem(_inst);
    case spv::Op::OpSMod: return parse_OpSMod(_inst);
    case spv::Op::OpFRem: return parse_OpFRem(_inst);
    case spv::Op::OpFMod: return parse_OpFMod(_inst);
    case spv::Op::OpVectorTimesScalar: return parse_OpVectorTimesScalar(_inst);
    case spv::Op::OpMatrixTimesScalar: return parse_OpMatrixTimesScalar(_inst);
    case spv::Op::OpVectorTimesMatrix: return parse_OpVectorTimesMatrix(_inst);
    case spv::Op::OpMatrixTimesVector: return parse_OpMatrixTimesVector(_inst);
    case spv::Op::OpMatrixTimesMatrix: return parse_OpMatrixTimesMatrix(_inst);
    case spv::Op::OpOuterProduct: return parse_OpOuterProduct(_inst);
    case spv::Op::OpDot: return parse_OpDot(_inst);
    case spv::Op::OpIAddCarry: return parse_OpIAddCarry(_inst);
    case spv::Op::OpISubBorrow: return parse_OpISubBorrow(_inst);
    case spv::Op::OpUMulExtended: return parse_OpUMulExtended(_inst);
    case spv::Op::OpSMulExtended: return parse_OpSMulExtended(_inst);
    case spv::Op::OpAny: return parse_OpAny(_inst);
    case spv::Op::OpAll: return parse_OpAll(_inst);
    case spv::Op::OpIsNan: return parse_OpIsNan(_inst);
    case spv::Op::OpIsInf: return parse_OpIsInf(_inst);
    case spv::Op::OpIsFinite: return parse_OpIsFinite(_inst);
    case spv::Op::OpIsNormal: return parse_OpIsNormal(_inst);
    case spv::Op::OpSignBitSet: return parse_OpSignBitSet(_inst);
    case spv::Op::OpLessOrGreater: return parse_OpLessOrGreater(_inst);
    case spv::Op::OpOrdered: return parse_OpOrdered(_inst);
    case spv::Op::OpUnordered: return parse_OpUnordered(_inst);
    case spv::Op::OpLogicalEqual: return parse_OpLogicalEqual(_inst);
    case spv::Op::OpLogicalNotEqual: return parse_OpLogicalNotEqual(_inst);
    case spv::Op::OpLogicalOr: return parse_OpLogicalOr(_inst);
    case spv::Op::OpLogicalAnd: return parse_OpLogicalAnd(_inst);
    case spv::Op::OpLogicalNot: return parse_OpLogicalNot(_inst);
    case spv::Op::OpSelect: return parse_OpSelect(_inst);
    case spv::Op::OpIEqual: return parse_OpIEqual(_inst);
    case spv::Op::OpINotEqual: return parse_OpINotEqual(_inst);
    case spv::Op::OpUGreaterThan: return parse_OpUGreaterThan(_inst);
    case spv::Op::OpSGreaterThan: return parse_OpSGreaterThan(_inst);
    case spv::Op::OpUGreaterThanEqual: return parse_OpUGreaterThanEqual(_inst);
    case spv::Op::OpSGreaterThanEqual: return parse_OpSGreaterThanEqual(_inst);
    case spv::Op::OpULessThan: return parse_OpULessThan(_inst);
    case spv::Op::OpSLessThan: return parse_OpSLessThan(_inst);
    case spv::Op::OpULessThanEqual: return parse_OpULessThanEqual(_inst);
    case spv::Op::OpSLessThanEqual: return parse_OpSLessThanEqual(_inst);
    case spv::Op::OpFOrdEqual: return parse_OpFOrdEqual(_inst);
    case spv::Op::OpFUnordEqual: return parse_OpFUnordEqual(_inst);
    case spv::Op::OpFOrdNotEqual: return parse_OpFOrdNotEqual(_inst);
    case spv::Op::OpFUnordNotEqual: return parse_OpFUnordNotEqual(_inst);
    case spv::Op::OpFOrdLessThan: return parse_OpFOrdLessThan(_inst);
    case spv::Op::OpFUnordLessThan: return parse_OpFUnordLessThan(_inst);
    case spv::Op::OpFOrdGreaterThan: return parse_OpFOrdGreaterThan(_inst);
    case spv::Op::OpFUnordGreaterThan: return parse_OpFUnordGreaterThan(_inst);
    case spv::Op::OpFOrdLessThanEqual: return parse_OpFOrdLessThanEqual(_inst);
    case spv::Op::OpFUnordLessThanEqual: return parse_OpFUnordLessThanEqual(_inst);
    case spv::Op::OpFOrdGreaterThanEqual: return parse_OpFOrdGreaterThanEqual(_inst);
    case spv::Op::OpFUnordGreaterThanEqual: return parse_OpFUnordGreaterThanEqual(_inst);
    case spv::Op::OpShiftRightLogical: return parse_OpShiftRightLogical(_inst);
    case spv::Op::OpShiftRightArithmetic: return parse_OpShiftRightArithmetic(_inst);
    case spv::Op::OpShiftLeftLogical: return parse_OpShiftLeftLogical(_inst);
    case spv::Op::OpBitwiseOr: return parse_OpBitwiseOr(_inst);
    case spv::Op::OpBitwiseXor: return parse_OpBitwiseXor(_inst);
    case spv::Op::OpBitwiseAnd: return parse_OpBitwiseAnd(_inst);
    case spv::Op::OpNot: return parse_OpNot(_inst);
    case spv::Op::OpBitFieldInsert: return parse_OpBitFieldInsert(_inst);
    case spv::Op::OpBitFieldSExtract: return parse_OpBitFieldSExtract(_inst);
    case spv::Op::OpBitFieldUExtract: return parse_OpBitFieldUExtract(_inst);
    case spv::Op::OpBitReverse: return parse_OpBitReverse(_inst);
    case spv::Op::OpBitCount: return parse_OpBitCount(_inst);
    case spv::Op::OpDPdx: return parse_OpDPdx(_inst);
    case spv::Op::OpDPdy: return parse_OpDPdy(_inst);
    case spv::Op::OpFwidth: return parse_OpFwidth(_inst);
    case spv::Op::OpDPdxFine: return parse_OpDPdxFine(_inst);
    case spv::Op::OpDPdyFine: return parse_OpDPdyFine(_inst);
    case spv::Op::OpFwidthFine: return parse_OpFwidthFine(_inst);
    case spv::Op::OpDPdxCoarse: return parse_OpDPdxCoarse(_inst);
    case spv::Op::OpDPdyCoarse: return parse_OpDPdyCoarse(_inst);
    case spv::Op::OpFwidthCoarse: return parse_OpFwidthCoarse(_inst);
    case spv::Op::OpEmitVertex: return parse_OpEmitVertex(_inst);
    case spv::Op::OpEndPrimitive: return parse_OpEndPrimitive(_inst);
    case spv::Op::OpEmitStreamVertex: return parse_OpEmitStreamVertex(_inst);
    case spv::Op::OpEndStreamPrimitive: return parse_OpEndStreamPrimitive(_inst);
    case spv::Op::OpControlBarrier: return parse_OpControlBarrier(_inst);
    case spv::Op::OpMemoryBarrier: return parse_OpMemoryBarrier(_inst);
    case spv::Op::OpAtomicLoad: return parse_OpAtomicLoad(_inst);
    case spv::Op::OpAtomicStore: return parse_OpAtomicStore(_inst);
    case spv::Op::OpAtomicExchange: return parse_OpAtomicExchange(_inst);
    case spv::Op::OpAtomicCompareExchange: return parse_OpAtomicCompareExchange(_inst);
    case spv::Op::OpAtomicCompareExchangeWeak: return parse_OpAtomicCompareExchangeWeak(_inst);
    case spv::Op::OpAtomicIIncrement: return parse_OpAtomicIIncrement(_inst);
    case spv::Op::OpAtomicIDecrement: return parse_OpAtomicIDecrement(_inst);
    case spv::Op::OpAtomicIAdd: return parse_OpAtomicIAdd(_inst);
    case spv::Op::OpAtomicISub: return parse_OpAtomicISub(_inst);
    case spv::Op::OpAtomicSMin: return parse_OpAtomicSMin(_inst);
    case spv::Op::OpAtomicUMin: return parse_OpAtomicUMin(_inst);
    case spv::Op::OpAtomicSMax: return parse_OpAtomicSMax(_inst);
    case spv::Op::OpAtomicUMax: return parse_OpAtomicUMax(_inst);
    case spv::Op::OpAtomicAnd: return parse_OpAtomicAnd(_inst);
    case spv::Op::OpAtomicOr: return parse_OpAtomicOr(_inst);
    case spv::Op::OpAtomicXor: return parse_OpAtomicXor(_inst);
    case spv::Op::OpPhi: return parse_OpPhi(_inst);
    case spv::Op::OpLoopMerge: return parse_OpLoopMerge(_inst);
    case spv::Op::OpSelectionMerge: return parse_OpSelectionMerge(_inst);
    case spv::Op::OpLabel: return parse_OpLabel(_inst);
    case spv::Op::OpBranch: return parse_OpBranch(_inst);
    case spv::Op::OpBranchConditional: return parse_OpBranchConditional(_inst);
    case spv::Op::OpSwitch: return parse_OpSwitch(_inst);
    case spv::Op::OpKill: return parse_OpKill(_inst);
    case spv::Op::OpReturn: return parse_OpReturn(_inst);
    case spv::Op::OpReturnValue: return parse_OpReturnValue(_inst);
    case spv::Op::OpUnreachable: return parse_OpUnreachable(_inst);
    case spv::Op::OpLifetimeStart: return parse_OpLifetimeStart(_inst);
    case spv::Op::OpLifetimeStop: return parse_OpLifetimeStop(_inst);
    case spv::Op::OpGroupAsyncCopy: return parse_OpGroupAsyncCopy(_inst);
    case spv::Op::OpGroupWaitEvents: return parse_OpGroupWaitEvents(_inst);
    case spv::Op::OpGroupAll: return parse_OpGroupAll(_inst);
    case spv::Op::OpGroupAny: return parse_OpGroupAny(_inst);
    case spv::Op::OpGroupBroadcast: return parse_OpGroupBroadcast(_inst);
    case spv::Op::OpGroupIAdd: return parse_OpGroupIAdd(_inst);
    case spv::Op::OpGroupFAdd: return parse_OpGroupFAdd(_inst);
    case spv::Op::OpGroupFMin: return parse_OpGroupFMin(_inst);
    case spv::Op::OpGroupUMin: return parse_OpGroupUMin(_inst);
    case spv::Op::OpGroupSMin: return parse_OpGroupSMin(_inst);
    case spv::Op::OpGroupFMax: return parse_OpGroupFMax(_inst);
    case spv::Op::OpGroupUMax: return parse_OpGroupUMax(_inst);
    case spv::Op::OpGroupSMax: return parse_OpGroupSMax(_inst);
    case spv::Op::OpReadPipe: return parse_OpReadPipe(_inst);
    case spv::Op::OpWritePipe: return parse_OpWritePipe(_inst);
    case spv::Op::OpReservedReadPipe: return parse_OpReservedReadPipe(_inst);
    case spv::Op::OpReservedWritePipe: return parse_OpReservedWritePipe(_inst);
    case spv::Op::OpReserveReadPipePackets: return parse_OpReserveReadPipePackets(_inst);
    case spv::Op::OpReserveWritePipePackets: return parse_OpReserveWritePipePackets(_inst);
    case spv::Op::OpCommitReadPipe: return parse_OpCommitReadPipe(_inst);
    case spv::Op::OpCommitWritePipe: return parse_OpCommitWritePipe(_inst);
    case spv::Op::OpIsValidReserveId: return parse_OpIsValidReserveId(_inst);
    case spv::Op::OpGetNumPipePackets: return parse_OpGetNumPipePackets(_inst);
    case spv::Op::OpGetMaxPipePackets: return parse_OpGetMaxPipePackets(_inst);
    case spv::Op::OpGroupReserveReadPipePackets: return parse_OpGroupReserveReadPipePackets(_inst);
    case spv::Op::OpGroupReserveWritePipePackets: return parse_OpGroupReserveWritePipePackets(_inst);
    case spv::Op::OpGroupCommitReadPipe: return parse_OpGroupCommitReadPipe(_inst);
    case spv::Op::OpGroupCommitWritePipe: return parse_OpGroupCommitWritePipe(_inst);
    case spv::Op::OpEnqueueMarker: return parse_OpEnqueueMarker(_inst);
    case spv::Op::OpEnqueueKernel: return parse_OpEnqueueKernel(_inst);
    case spv::Op::OpGetKernelNDrangeSubGroupCount: return parse_OpGetKernelNDrangeSubGroupCount(_inst);
    case spv::Op::OpGetKernelNDrangeMaxSubGroupSize: return parse_OpGetKernelNDrangeMaxSubGroupSize(_inst);
    case spv::Op::OpGetKernelWorkGroupSize: return parse_OpGetKernelWorkGroupSize(_inst);
    case spv::Op::OpGetKernelPreferredWorkGroupSizeMultiple:
      return parse_OpGetKernelPreferredWorkGroupSizeMultiple(_inst);
    case spv::Op::OpRetainEvent: return parse_OpRetainEvent(_inst);
    case spv::Op::OpReleaseEvent: return parse_OpReleaseEvent(_inst);
    case spv::Op::OpCreateUserEvent: return parse_OpCreateUserEvent(_inst);
    case spv::Op::OpIsValidEvent: return parse_OpIsValidEvent(_inst);
    case spv::Op::OpSetUserEventStatus: return parse_OpSetUserEventStatus(_inst);
    case spv::Op::OpCaptureEventProfilingInfo: return parse_OpCaptureEventProfilingInfo(_inst);
    case spv::Op::OpGetDefaultQueue: return parse_OpGetDefaultQueue(_inst);
    case spv::Op::OpBuildNDRange: return parse_OpBuildNDRange(_inst);
    case spv::Op::OpImageSparseSampleImplicitLod: return parse_OpImageSparseSampleImplicitLod(_inst);
    case spv::Op::OpImageSparseSampleExplicitLod: return parse_OpImageSparseSampleExplicitLod(_inst);
    case spv::Op::OpImageSparseSampleDrefImplicitLod: return parse_OpImageSparseSampleDrefImplicitLod(_inst);
    case spv::Op::OpImageSparseSampleDrefExplicitLod: return parse_OpImageSparseSampleDrefExplicitLod(_inst);
    case spv::Op::OpImageSparseSampleProjImplicitLod: return parse_OpImageSparseSampleProjImplicitLod(_inst);
    case spv::Op::OpImageSparseSampleProjExplicitLod: return parse_OpImageSparseSampleProjExplicitLod(_inst);
    case spv::Op::OpImageSparseSampleProjDrefImplicitLod: return parse_OpImageSparseSampleProjDrefImplicitLod(_inst);
    case spv::Op::OpImageSparseSampleProjDrefExplicitLod: return parse_OpImageSparseSampleProjDrefExplicitLod(_inst);
    case spv::Op::OpImageSparseFetch: return parse_OpImageSparseFetch(_inst);
    case spv::Op::OpImageSparseGather: return parse_OpImageSparseGather(_inst);
    case spv::Op::OpImageSparseDrefGather: return parse_OpImageSparseDrefGather(_inst);
    case spv::Op::OpImageSparseTexelsResident: return parse_OpImageSparseTexelsResident(_inst);
    case spv::Op::OpNoLine: return parse_OpNoLine(_inst);
    case spv::Op::OpAtomicFlagTestAndSet: return parse_OpAtomicFlagTestAndSet(_inst);
    case spv::Op::OpAtomicFlagClear: return parse_OpAtomicFlagClear(_inst);
    case spv::Op::OpImageSparseRead: return parse_OpImageSparseRead(_inst);
    case spv::Op::OpSizeOf: return parse_OpSizeOf(_inst);
    case spv::Op::OpTypePipeStorage: return parse_OpTypePipeStorage(_inst);
    case spv::Op::OpConstantPipeStorage: return parse_OpConstantPipeStorage(_inst);
    case spv::Op::OpCreatePipeFromPipeStorage: return parse_OpCreatePipeFromPipeStorage(_inst);
    case spv::Op::OpGetKernelLocalSizeForSubgroupCount: return parse_OpGetKernelLocalSizeForSubgroupCount(_inst);
    case spv::Op::OpGetKernelMaxNumSubgroups: return parse_OpGetKernelMaxNumSubgroups(_inst);
    case spv::Op::OpTypeNamedBarrier: return parse_OpTypeNamedBarrier(_inst);
    case spv::Op::OpNamedBarrierInitialize: return parse_OpNamedBarrierInitialize(_inst);
    case spv::Op::OpMemoryNamedBarrier: return parse_OpMemoryNamedBarrier(_inst);
    case spv::Op::OpModuleProcessed: return parse_OpModuleProcessed(_inst);
    case spv::Op::OpExecutionModeId: return parse_OpExecutionModeId(_inst);
    case spv::Op::OpDecorateId: return parse_OpDecorateId(_inst);
    case spv::Op::OpSubgroupBallotKHR: return parse_OpSubgroupBallotKHR(_inst);
    case spv::Op::OpSubgroupFirstInvocationKHR: return parse_OpSubgroupFirstInvocationKHR(_inst);
    case spv::Op::OpSubgroupAllKHR: return parse_OpSubgroupAllKHR(_inst);
    case spv::Op::OpSubgroupAnyKHR: return parse_OpSubgroupAnyKHR(_inst);
    case spv::Op::OpSubgroupAllEqualKHR: return parse_OpSubgroupAllEqualKHR(_inst);
    case spv::Op::OpSubgroupReadInvocationKHR: return parse_OpSubgroupReadInvocationKHR(_inst);
    case spv::Op::OpGroupIAddNonUniformAMD: return parse_OpGroupIAddNonUniformAMD(_inst);
    case spv::Op::OpGroupFAddNonUniformAMD: return parse_OpGroupFAddNonUniformAMD(_inst);
    case spv::Op::OpGroupFMinNonUniformAMD: return parse_OpGroupFMinNonUniformAMD(_inst);
    case spv::Op::OpGroupUMinNonUniformAMD: return parse_OpGroupUMinNonUniformAMD(_inst);
    case spv::Op::OpGroupSMinNonUniformAMD: return parse_OpGroupSMinNonUniformAMD(_inst);
    case spv::Op::OpGroupFMaxNonUniformAMD: return parse_OpGroupFMaxNonUniformAMD(_inst);
    case spv::Op::OpGroupUMaxNonUniformAMD: return parse_OpGroupUMaxNonUniformAMD(_inst);
    case spv::Op::OpGroupSMaxNonUniformAMD: return parse_OpGroupSMaxNonUniformAMD(_inst);
    case spv::Op::OpFragmentMaskFetchAMD: return parse_OpFragmentMaskFetchAMD(_inst);
    case spv::Op::OpFragmentFetchAMD: return parse_OpFragmentFetchAMD(_inst);
    case spv::Op::OpSubgroupShuffleINTEL: return parse_OpSubgroupShuffleINTEL(_inst);
    case spv::Op::OpSubgroupShuffleDownINTEL: return parse_OpSubgroupShuffleDownINTEL(_inst);
    case spv::Op::OpSubgroupShuffleUpINTEL: return parse_OpSubgroupShuffleUpINTEL(_inst);
    case spv::Op::OpSubgroupShuffleXorINTEL: return parse_OpSubgroupShuffleXorINTEL(_inst);
    case spv::Op::OpSubgroupBlockReadINTEL: return parse_OpSubgroupBlockReadINTEL(_inst);
    case spv::Op::OpSubgroupBlockWriteINTEL: return parse_OpSubgroupBlockWriteINTEL(_inst);
    case spv::Op::OpSubgroupImageBlockReadINTEL: return parse_OpSubgroupImageBlockReadINTEL(_inst);
    case spv::Op::OpSubgroupImageBlockWriteINTEL: return parse_OpSubgroupImageBlockWriteINTEL(_inst);
    default: return false;
  }
}

ITER spirvPacker::dis::parse_ImageOperands(ImageOperands &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::Bias)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::Lod)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::Grad)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::ConstOffset)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::Offset)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::ConstOffsets)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::Sample)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  if (_val.value & static_cast<uint32_t>(spv::ImageOperandsMask::MinLod)) {
    PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "")
  }
  return _pos;
}

ITER spirvPacker::dis::parse_FPFastMathMode(FPFastMathMode &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_SelectionControl(SelectionControl &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_LoopControl(LoopControl &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  if (_val.value & static_cast<uint32_t>(spv::LoopControlMask::DependencyLength)) {
    PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "")
  }
  return _pos;
}

ITER spirvPacker::dis::parse_FunctionControl(FunctionControl &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_MemorySemantics(MemorySemantics &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_MemoryAccess(MemoryAccess &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  if (_val.value & static_cast<uint32_t>(spv::MemoryAccessMask::Aligned)) {
    PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "")
  }
  return _pos;
}

ITER spirvPacker::dis::parse_KernelProfilingInfo(KernelProfilingInfo &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_SourceLanguage(SourceLanguage &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::SourceLanguage>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_ExecutionModel(ExecutionModel &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::ExecutionModel>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_AddressingModel(AddressingModel &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::AddressingModel>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_MemoryModel(MemoryModel &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::MemoryModel>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_ExecutionMode(ExecutionMode &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::ExecutionMode>(*(_pos++));

  switch (_val.value) {
    case spv::ExecutionMode::Invocations: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Number") break;
    case spv::ExecutionMode::LocalSize:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "x")
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "size")
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "y")
      break;
    case spv::ExecutionMode::LocalSizeHint:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "x")
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "size")
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "y")
      break;
    case spv::ExecutionMode::OutputVertices: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Vertex") break;
    case spv::ExecutionMode::VecTypeHint: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Vector") break;
    case spv::ExecutionMode::SubgroupSize: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Subgroup") break;
    case spv::ExecutionMode::SubgroupsPerWorkgroup:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Subgroups")
      break;
    case spv::ExecutionMode::SubgroupsPerWorkgroupId:
      PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "Subgroups")
      break;
    case spv::ExecutionMode::LocalSizeId:
      PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "x")
      PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "size")
      PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "y")
      break;
    case spv::ExecutionMode::LocalSizeHintId: PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "Local") break;
    default: break;
  }
  return _pos;
}

ITER spirvPacker::dis::parse_StorageClass(StorageClass &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::StorageClass>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_Dim(Dim &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::Dim>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_SamplerAddressingMode(SamplerAddressingMode &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::SamplerAddressingMode>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_SamplerFilterMode(SamplerFilterMode &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::SamplerFilterMode>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_ImageFormat(ImageFormat &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::ImageFormat>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_ImageChannelOrder(ImageChannelOrder &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::ImageChannelOrder>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_ImageChannelDataType(ImageChannelDataType &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::ImageChannelDataType>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_FPRoundingMode(FPRoundingMode &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::FPRoundingMode>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_LinkageType(LinkageType &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::LinkageType>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_AccessQualifier(AccessQualifier &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::AccessQualifier>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_FunctionParameterAttribute(FunctionParameterAttribute &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::FunctionParameterAttribute>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_Decoration(Decoration &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::Decoration>(*(_pos++));

  switch (_val.value) {
    case spv::Decoration::SpecId: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Specialization") break;
    case spv::Decoration::ArrayStride: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Array") break;
    case spv::Decoration::MatrixStride: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Matrix") break;
    case spv::Decoration::BuiltIn: PARSE_PARAM(_pos, _end, _val.parameters, BuiltIn, "") break;
    case spv::Decoration::Stream: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Stream") break;
    case spv::Decoration::Location: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Location") break;
    case spv::Decoration::Component: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Component") break;
    case spv::Decoration::Index: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Index") break;
    case spv::Decoration::Binding: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Binding") break;
    case spv::Decoration::DescriptorSet: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Descriptor") break;
    case spv::Decoration::Offset: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Byte") break;
    case spv::Decoration::XfbBuffer: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "XFB") break;
    case spv::Decoration::XfbStride: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "XFB") break;
    case spv::Decoration::FuncParamAttr:
      PARSE_PARAM(_pos, _end, _val.parameters, FunctionParameterAttribute, "Function")
      break;
    case spv::Decoration::FPRoundingMode:
      PARSE_PARAM(_pos, _end, _val.parameters, FPRoundingMode, "Floating-Point")
      break;
    case spv::Decoration::FPFastMathMode: PARSE_PARAM(_pos, _end, _val.parameters, FPFastMathMode, "Fast-Math") break;
    case spv::Decoration::LinkageAttributes:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralString, "Name")
      PARSE_PARAM(_pos, _end, _val.parameters, LinkageType, "Linkage")
      break;
    case spv::Decoration::InputAttachmentIndex:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Attachment")
      break;
    case spv::Decoration::Alignment: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Alignment") break;
    case spv::Decoration::MaxByteOffset: PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Max") break;
    case spv::Decoration::AlignmentId: PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "Alignment") break;
    case spv::Decoration::MaxByteOffsetId: PARSE_PARAM(_pos, _end, _val.parameters, IdRef, "Max") break;
    case spv::Decoration::SecondaryViewportRelativeNV:
      PARSE_PARAM(_pos, _end, _val.parameters, LiteralInteger, "Offset")
      break;
    default: break;
  }
  return _pos;
}

ITER spirvPacker::dis::parse_BuiltIn(BuiltIn &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::BuiltIn>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_Scope(Scope &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::Scope>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_GroupOperation(GroupOperation &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::GroupOperation>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_KernelEnqueueFlags(KernelEnqueueFlags &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::KernelEnqueueFlags>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_Capability(Capability &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = static_cast<spv::Capability>(*(_pos++));

  return _pos;
}

ITER spirvPacker::dis::parse_IdResultType(IdResultType &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_IdResult(IdResult &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_IdMemorySemantics(IdMemorySemantics &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_IdScope(IdScope &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_IdRef(IdRef &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value = *(_pos++);
  return _pos;
}

ITER spirvPacker::dis::parse_LiteralInteger(LiteralInteger &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value.clear();
  _val.value.push_back(*(_pos++));
  return _pos;
}

ITER spirvPacker::dis::parse_LiteralString(LiteralString &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value.clear();
  while (_pos != _end) {
    uint32_t lDat = *_pos;
    _pos++;
    _val.value.push_back(lDat);

    // Break when at least one byte is 0
    if ((lDat & 0xFF000000) == 0 || (lDat & 0x00FF0000) == 0 || (lDat & 0x0000FF00) == 0 || (lDat & 0x000000FF) == 0)
      break;
  }
  return _pos;
}

ITER spirvPacker::dis::parse_LiteralContextDependentNumber(LiteralContextDependentNumber &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value.clear();
  _val.value.push_back(*(_pos++));
  return _pos;
}

ITER spirvPacker::dis::parse_LiteralExtInstInteger(LiteralExtInstInteger &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value.clear();
  _val.value.push_back(*(_pos++));
  return _pos;
}

ITER spirvPacker::dis::parse_LiteralSpecConstantOpInteger(LiteralSpecConstantOpInteger &_val, ITER _pos, ITER _end) {
  (void)_end;
  _val.value.clear();
  _val.value.push_back(*(_pos++));
  return _pos;
}

ITER spirvPacker::dis::parse_PairLiteralIntegerIdRef(PairLiteralIntegerIdRef &_val, ITER _pos, ITER _end) {
  (void)_end;
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_LiteralInteger(_val.value0, _pos, _end);
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_IdRef(_val.value1, _pos, _end);
  return _pos;
}

ITER spirvPacker::dis::parse_PairIdRefLiteralInteger(PairIdRefLiteralInteger &_val, ITER _pos, ITER _end) {
  (void)_end;
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_IdRef(_val.value0, _pos, _end);
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_LiteralInteger(_val.value1, _pos, _end);
  return _pos;
}

ITER spirvPacker::dis::parse_PairIdRefIdRef(PairIdRefIdRef &_val, ITER _pos, ITER _end) {
  (void)_end;
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_IdRef(_val.value0, _pos, _end);
  if (_pos >= _end)
    return _end + 1;

  _pos = parse_IdRef(_val.value1, _pos, _end);
  return _pos;
}

bool spirvPacker::dis::parse_OpNop(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpUndef(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpSourceContinued(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Continued Source")
  return true;
}

bool spirvPacker::dis::parse_OpSource(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, SourceLanguage, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Version")
  PARSE_ONE(lCurr, lEnd, _inst.operands, IdRef, "File")
  PARSE_ONE(lCurr, lEnd, _inst.operands, LiteralString, "Source")
  return true;
}

bool spirvPacker::dis::parse_OpSourceExtension(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Extension")
  return true;
}

bool spirvPacker::dis::parse_OpName(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Name")
  return true;
}

bool spirvPacker::dis::parse_OpMemberName(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Member")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Name")
  return true;
}

bool spirvPacker::dis::parse_OpString(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "String")
  return true;
}

bool spirvPacker::dis::parse_OpLine(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "File")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Line")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Column")
  return true;
}

bool spirvPacker::dis::parse_OpExtension(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Name")
  return true;
}

bool spirvPacker::dis::parse_OpExtInstImport(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Name")
  return true;
}

bool spirvPacker::dis::parse_OpExtInst(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Set")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralExtInstInteger, "Instruction")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Operand 1, +Operand 2, +...")
  return true;
}

bool spirvPacker::dis::parse_OpMemoryModel(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, AddressingModel, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, MemoryModel, "")
  return true;
}

bool spirvPacker::dis::parse_OpEntryPoint(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ExecutionModel, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Entry Point")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Name")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Interface")
  return true;
}

bool spirvPacker::dis::parse_OpExecutionMode(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Entry Point")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ExecutionMode, "Mode")
  return true;
}

bool spirvPacker::dis::parse_OpCapability(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, Capability, "Capability")
  return true;
}

bool spirvPacker::dis::parse_OpTypeVoid(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeBool(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeInt(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Width")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Signedness")
  return true;
}

bool spirvPacker::dis::parse_OpTypeFloat(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Width")
  return true;
}

bool spirvPacker::dis::parse_OpTypeVector(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Component Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Component Count")
  return true;
}

bool spirvPacker::dis::parse_OpTypeMatrix(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Column Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Column Count")
  return true;
}

bool spirvPacker::dis::parse_OpTypeImage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, Dim, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Depth")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Arrayed")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "MS")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Sampled")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageFormat, "")
  PARSE_ONE(lCurr, lEnd, _inst.operands, AccessQualifier, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeSampler(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeSampledImage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image Type")
  return true;
}

bool spirvPacker::dis::parse_OpTypeArray(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Element Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Length")
  return true;
}

bool spirvPacker::dis::parse_OpTypeRuntimeArray(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Element Type")
  return true;
}

bool spirvPacker::dis::parse_OpTypeStruct(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Member 0 type, +member 1 type, +...")
  return true;
}

bool spirvPacker::dis::parse_OpTypeOpaque(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "The name of the opaque type.")
  return true;
}

bool spirvPacker::dis::parse_OpTypePointer(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, StorageClass, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Type")
  return true;
}

bool spirvPacker::dis::parse_OpTypeFunction(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Return Type")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Parameter 0 Type, +Parameter 1 Type, +...")
  return true;
}

bool spirvPacker::dis::parse_OpTypeEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeDeviceEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeReserveId(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypeQueue(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpTypePipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, AccessQualifier, "Qualifier")
  return true;
}

bool spirvPacker::dis::parse_OpTypeForwardPointer(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, StorageClass, "")
  return true;
}

bool spirvPacker::dis::parse_OpConstantTrue(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpConstantFalse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpConstant(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralContextDependentNumber, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpConstantComposite(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Constituents")
  return true;
}

bool spirvPacker::dis::parse_OpConstantSampler(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, SamplerAddressingMode, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, SamplerFilterMode, "")
  return true;
}

bool spirvPacker::dis::parse_OpConstantNull(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpSpecConstantTrue(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpSpecConstantFalse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpSpecConstant(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralContextDependentNumber, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpSpecConstantComposite(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Constituents")
  return true;
}

bool spirvPacker::dis::parse_OpSpecConstantOp(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralSpecConstantOpInteger, "Opcode")
  return true;
}

bool spirvPacker::dis::parse_OpFunction(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, FunctionControl, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Function Type")
  return true;
}

bool spirvPacker::dis::parse_OpFunctionParameter(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpFunctionEnd(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpFunctionCall(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Function")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Argument 0, +Argument 1, +...")
  return true;
}

bool spirvPacker::dis::parse_OpVariable(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, StorageClass, "")
  PARSE_ONE(lCurr, lEnd, _inst.operands, IdRef, "Initializer")
  return true;
}

bool spirvPacker::dis::parse_OpImageTexelPointer(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sample")
  return true;
}

bool spirvPacker::dis::parse_OpLoad(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_ONE(lCurr, lEnd, _inst.operands, MemoryAccess, "")
  return true;
}

bool spirvPacker::dis::parse_OpStore(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Object")
  PARSE_ONE(lCurr, lEnd, _inst.operands, MemoryAccess, "")
  return true;
}

bool spirvPacker::dis::parse_OpCopyMemory(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Source")
  PARSE_ONE(lCurr, lEnd, _inst.operands, MemoryAccess, "")
  return true;
}

bool spirvPacker::dis::parse_OpCopyMemorySized(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Source")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Size")
  PARSE_ONE(lCurr, lEnd, _inst.operands, MemoryAccess, "")
  return true;
}

bool spirvPacker::dis::parse_OpAccessChain(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpInBoundsAccessChain(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpPtrAccessChain(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Element")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpArrayLength(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Structure")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Array member")
  return true;
}

bool spirvPacker::dis::parse_OpGenericPtrMemSemantics(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  return true;
}

bool spirvPacker::dis::parse_OpInBoundsPtrAccessChain(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Element")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpDecorate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, Decoration, "")
  return true;
}

bool spirvPacker::dis::parse_OpMemberDecorate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Structure Type")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Member")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, Decoration, "")
  return true;
}

bool spirvPacker::dis::parse_OpDecorationGroup(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpGroupDecorate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Decoration Group")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Targets")
  return true;
}

bool spirvPacker::dis::parse_OpGroupMemberDecorate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Decoration Group")
  PARSE_MULT(lCurr, lEnd, _inst.operands, PairIdRefLiteralInteger, "Targets")
  return true;
}

bool spirvPacker::dis::parse_OpVectorExtractDynamic(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Index")
  return true;
}

bool spirvPacker::dis::parse_OpVectorInsertDynamic(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Component")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Index")
  return true;
}

bool spirvPacker::dis::parse_OpVectorShuffle(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 2")
  PARSE_MULT(lCurr, lEnd, _inst.operands, LiteralInteger, "Components")
  return true;
}

bool spirvPacker::dis::parse_OpCompositeConstruct(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Constituents")
  return true;
}

bool spirvPacker::dis::parse_OpCompositeExtract(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Composite")
  PARSE_MULT(lCurr, lEnd, _inst.operands, LiteralInteger, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpCompositeInsert(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Object")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Composite")
  PARSE_MULT(lCurr, lEnd, _inst.operands, LiteralInteger, "Indexes")
  return true;
}

bool spirvPacker::dis::parse_OpCopyObject(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpTranspose(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Matrix")
  return true;
}

bool spirvPacker::dis::parse_OpSampledImage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampler")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleDrefImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleDrefExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleProjImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleProjExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleProjDrefImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSampleProjDrefExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageFetch(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageGather(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Component")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageDrefGather(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageRead(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageWrite(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Texel")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  return true;
}

bool spirvPacker::dis::parse_OpImageQueryFormat(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  return true;
}

bool spirvPacker::dis::parse_OpImageQueryOrder(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  return true;
}

bool spirvPacker::dis::parse_OpImageQuerySizeLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Level of Detail")
  return true;
}

bool spirvPacker::dis::parse_OpImageQuerySize(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  return true;
}

bool spirvPacker::dis::parse_OpImageQueryLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  return true;
}

bool spirvPacker::dis::parse_OpImageQueryLevels(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  return true;
}

bool spirvPacker::dis::parse_OpImageQuerySamples(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  return true;
}

bool spirvPacker::dis::parse_OpConvertFToU(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Float Value")
  return true;
}

bool spirvPacker::dis::parse_OpConvertFToS(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Float Value")
  return true;
}

bool spirvPacker::dis::parse_OpConvertSToF(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Signed Value")
  return true;
}

bool spirvPacker::dis::parse_OpConvertUToF(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Unsigned Value")
  return true;
}

bool spirvPacker::dis::parse_OpUConvert(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Unsigned Value")
  return true;
}

bool spirvPacker::dis::parse_OpSConvert(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Signed Value")
  return true;
}

bool spirvPacker::dis::parse_OpFConvert(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Float Value")
  return true;
}

bool spirvPacker::dis::parse_OpQuantizeToF16(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpConvertPtrToU(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  return true;
}

bool spirvPacker::dis::parse_OpSatConvertSToU(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Signed Value")
  return true;
}

bool spirvPacker::dis::parse_OpSatConvertUToS(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Unsigned Value")
  return true;
}

bool spirvPacker::dis::parse_OpConvertUToPtr(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Integer Value")
  return true;
}

bool spirvPacker::dis::parse_OpPtrCastToGeneric(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  return true;
}

bool spirvPacker::dis::parse_OpGenericCastToPtr(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  return true;
}

bool spirvPacker::dis::parse_OpGenericCastToPtrExplicit(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, StorageClass, "Storage")
  return true;
}

bool spirvPacker::dis::parse_OpBitcast(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpSNegate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpFNegate(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpIAdd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFAdd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpISub(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFSub(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpIMul(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFMul(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpUDiv(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSDiv(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFDiv(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpUMod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSRem(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSMod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFRem(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFMod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpVectorTimesScalar(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Scalar")
  return true;
}

bool spirvPacker::dis::parse_OpMatrixTimesScalar(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Matrix")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Scalar")
  return true;
}

bool spirvPacker::dis::parse_OpVectorTimesMatrix(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Matrix")
  return true;
}

bool spirvPacker::dis::parse_OpMatrixTimesVector(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Matrix")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  return true;
}

bool spirvPacker::dis::parse_OpMatrixTimesMatrix(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "LeftMatrix")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "RightMatrix")
  return true;
}

bool spirvPacker::dis::parse_OpOuterProduct(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 2")
  return true;
}

bool spirvPacker::dis::parse_OpDot(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector 2")
  return true;
}

bool spirvPacker::dis::parse_OpIAddCarry(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpISubBorrow(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpUMulExtended(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSMulExtended(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpAny(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  return true;
}

bool spirvPacker::dis::parse_OpAll(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Vector")
  return true;
}

bool spirvPacker::dis::parse_OpIsNan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  return true;
}

bool spirvPacker::dis::parse_OpIsInf(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  return true;
}

bool spirvPacker::dis::parse_OpIsFinite(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  return true;
}

bool spirvPacker::dis::parse_OpIsNormal(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  return true;
}

bool spirvPacker::dis::parse_OpSignBitSet(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  return true;
}

bool spirvPacker::dis::parse_OpLessOrGreater(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "y")
  return true;
}

bool spirvPacker::dis::parse_OpOrdered(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "y")
  return true;
}

bool spirvPacker::dis::parse_OpUnordered(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "x")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "y")
  return true;
}

bool spirvPacker::dis::parse_OpLogicalEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpLogicalNotEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpLogicalOr(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpLogicalAnd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpLogicalNot(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpSelect(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Condition")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Object 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Object 2")
  return true;
}

bool spirvPacker::dis::parse_OpIEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpINotEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpUGreaterThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSGreaterThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpUGreaterThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSGreaterThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpULessThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSLessThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpULessThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpSLessThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdNotEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordNotEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdLessThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordLessThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdGreaterThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordGreaterThan(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdLessThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordLessThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFOrdGreaterThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpFUnordGreaterThanEqual(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpShiftRightLogical(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Shift")
  return true;
}

bool spirvPacker::dis::parse_OpShiftRightArithmetic(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Shift")
  return true;
}

bool spirvPacker::dis::parse_OpShiftLeftLogical(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Shift")
  return true;
}

bool spirvPacker::dis::parse_OpBitwiseOr(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpBitwiseXor(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpBitwiseAnd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 1")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand 2")
  return true;
}

bool spirvPacker::dis::parse_OpNot(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Operand")
  return true;
}

bool spirvPacker::dis::parse_OpBitFieldInsert(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Insert")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Offset")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Count")
  return true;
}

bool spirvPacker::dis::parse_OpBitFieldSExtract(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Offset")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Count")
  return true;
}

bool spirvPacker::dis::parse_OpBitFieldUExtract(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Offset")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Count")
  return true;
}

bool spirvPacker::dis::parse_OpBitReverse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  return true;
}

bool spirvPacker::dis::parse_OpBitCount(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Base")
  return true;
}

bool spirvPacker::dis::parse_OpDPdx(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpDPdy(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpFwidth(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpDPdxFine(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpDPdyFine(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpFwidthFine(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpDPdxCoarse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpDPdyCoarse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpFwidthCoarse(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "P")
  return true;
}

bool spirvPacker::dis::parse_OpEmitVertex(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpEndPrimitive(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpEmitStreamVertex(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Stream")
  return true;
}

bool spirvPacker::dis::parse_OpEndStreamPrimitive(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Stream")
  return true;
}

bool spirvPacker::dis::parse_OpControlBarrier(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Memory")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpMemoryBarrier(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Memory")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicLoad(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicStore(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicExchange(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicCompareExchange(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Equal")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Unequal")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Comparator")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicCompareExchangeWeak(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Equal")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Unequal")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Comparator")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicIIncrement(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicIDecrement(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicIAdd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicISub(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicSMin(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicUMin(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicSMax(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicUMax(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicAnd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicOr(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicXor(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpPhi(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_MULT(lCurr, lEnd, _inst.operands, PairIdRefIdRef, "Variable, Parent, ...")
  return true;
}

bool spirvPacker::dis::parse_OpLoopMerge(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Merge Block")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Continue Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LoopControl, "")
  return true;
}

bool spirvPacker::dis::parse_OpSelectionMerge(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Merge Block")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, SelectionControl, "")
  return true;
}

bool spirvPacker::dis::parse_OpLabel(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpBranch(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target Label")
  return true;
}

bool spirvPacker::dis::parse_OpBranchConditional(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Condition")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "True Label")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "False Label")
  PARSE_MULT(lCurr, lEnd, _inst.operands, LiteralInteger, "Branch weights")
  return true;
}

bool spirvPacker::dis::parse_OpSwitch(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Selector")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Default")
  PARSE_MULT(lCurr, lEnd, _inst.operands, PairLiteralIntegerIdRef, "Target")
  return true;
}

bool spirvPacker::dis::parse_OpKill(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpReturn(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpReturnValue(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpUnreachable(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpLifetimeStart(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Size")
  return true;
}

bool spirvPacker::dis::parse_OpLifetimeStop(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Size")
  return true;
}

bool spirvPacker::dis::parse_OpGroupAsyncCopy(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Destination")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Source")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Elements")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Stride")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  return true;
}

bool spirvPacker::dis::parse_OpGroupWaitEvents(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Events")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Events List")
  return true;
}

bool spirvPacker::dis::parse_OpGroupAll(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpGroupAny(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpGroupBroadcast(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "LocalId")
  return true;
}

bool spirvPacker::dis::parse_OpGroupIAdd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFAdd(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFMin(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupUMin(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupSMin(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFMax(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupUMax(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupSMax(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpReadPipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpWritePipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpReservedReadPipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Index")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpReservedWritePipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Index")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpReserveReadPipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Packets")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpReserveWritePipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Packets")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpCommitReadPipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpCommitWritePipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpIsValidReserveId(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  return true;
}

bool spirvPacker::dis::parse_OpGetNumPipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpGetMaxPipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpGroupReserveReadPipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Packets")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpGroupReserveWritePipePackets(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Packets")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpGroupCommitReadPipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpGroupCommitWritePipe(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Reserve Id")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Packet Alignment")
  return true;
}

bool spirvPacker::dis::parse_OpEnqueueMarker(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Queue")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Events")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Wait Events")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Ret Event")
  return true;
}

bool spirvPacker::dis::parse_OpEnqueueKernel(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Queue")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Flags")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "ND Range")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Num Events")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Wait Events")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Ret Event")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  PARSE_MULT(lCurr, lEnd, _inst.operands, IdRef, "Local Size")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelNDrangeSubGroupCount(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "ND Range")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelNDrangeMaxSubGroupSize(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "ND Range")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelWorkGroupSize(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelPreferredWorkGroupSizeMultiple(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpRetainEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  return true;
}

bool spirvPacker::dis::parse_OpReleaseEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  return true;
}

bool spirvPacker::dis::parse_OpCreateUserEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpIsValidEvent(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  return true;
}

bool spirvPacker::dis::parse_OpSetUserEventStatus(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Status")
  return true;
}

bool spirvPacker::dis::parse_OpCaptureEventProfilingInfo(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Event")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Profiling Info")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpGetDefaultQueue(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpBuildNDRange(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "GlobalWorkSize")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "LocalWorkSize")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "GlobalWorkOffset")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleDrefImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleDrefExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleProjImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleProjExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleProjDrefImplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseSampleProjDrefExplicitLod(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseFetch(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseGather(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Component")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseDrefGather(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Sampled Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "D~ref~")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseTexelsResident(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Resident Code")
  return true;
}

bool spirvPacker::dis::parse_OpNoLine(Instruction &) {
  // No operands
  return true;
}

bool spirvPacker::dis::parse_OpAtomicFlagTestAndSet(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpAtomicFlagClear(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Scope")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpImageSparseRead(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_ONE(lCurr, lEnd, _inst.operands, ImageOperands, "")
  return true;
}

bool spirvPacker::dis::parse_OpSizeOf(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pointer")
  return true;
}

bool spirvPacker::dis::parse_OpTypePipeStorage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpConstantPipeStorage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Packet Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Packet Alignment")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralInteger, "Capacity")
  return true;
}

bool spirvPacker::dis::parse_OpCreatePipeFromPipeStorage(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Pipe Storage")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelLocalSizeForSubgroupCount(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Subgroup Count")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpGetKernelMaxNumSubgroups(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Invoke")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Size")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Param Align")
  return true;
}

bool spirvPacker::dis::parse_OpTypeNamedBarrier(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  return true;
}

bool spirvPacker::dis::parse_OpNamedBarrierInitialize(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Subgroup Count")
  return true;
}

bool spirvPacker::dis::parse_OpMemoryNamedBarrier(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Named Barrier")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Memory")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdMemorySemantics, "Semantics")
  return true;
}

bool spirvPacker::dis::parse_OpModuleProcessed(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, LiteralString, "Process")
  return true;
}

bool spirvPacker::dis::parse_OpExecutionModeId(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Entry Point")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, ExecutionMode, "Mode")
  return true;
}

bool spirvPacker::dis::parse_OpDecorateId(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Target")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, Decoration, "")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupBallotKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupFirstInvocationKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupAllKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupAnyKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupAllEqualKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Predicate")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupReadInvocationKHR(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Index")
  return true;
}

bool spirvPacker::dis::parse_OpGroupIAddNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFAddNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFMinNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupUMinNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupSMinNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupFMaxNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupUMaxNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpGroupSMaxNonUniformAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdScope, "Execution")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, GroupOperation, "Operation")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "X")
  return true;
}

bool spirvPacker::dis::parse_OpFragmentMaskFetchAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  return true;
}

bool spirvPacker::dis::parse_OpFragmentFetchAMD(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Fragment Index")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupShuffleINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Data")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "InvocationId")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupShuffleDownINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Current")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Next")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Delta")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupShuffleUpINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Previous")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Current")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Delta")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupShuffleXorINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Data")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Value")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupBlockReadINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Ptr")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupBlockWriteINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Ptr")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Data")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupImageBlockReadINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResultType, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdResult, "")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  return true;
}

bool spirvPacker::dis::parse_OpSubgroupImageBlockWriteINTEL(Instruction &_inst) {
  auto lCurr = begin(_inst.rawBinary) + 1;
  auto lEnd  = end(_inst.rawBinary);
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Image")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Coordinate")
  PARSE_NORMAL(lCurr, lEnd, _inst.operands, IdRef, "Data")
  return true;
}
