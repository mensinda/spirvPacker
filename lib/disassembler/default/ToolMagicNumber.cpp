//! \note This is an automatically generated file

#include "spvCfg.hpp"
#include "ToolMagicNumber.hpp"

using namespace spirvPacker;

SPIRVToolDesc spirvPacker::getToolDeskFromMagicNumber(uint32_t _val) {
  switch (_val) {
    case 0:
      return {
          0,                     // value
          "Khronos",             // vendor
          "Reserved by Khronos", // comment
          "<N/A>"                // tool
      };

    case 1:
      return {
          1,             // value
          "LunarG",      // vendor
          "Contact TBD", // comment
          "<N/A>"        // tool
      };

    case 2:
      return {
          2,             // value
          "Valve",       // vendor
          "Contact TBD", // comment
          "<N/A>"        // tool
      };

    case 3:
      return {
          3,                                         // value
          "Codeplay",                                // vendor
          "Contact Neil Henning, neil@codeplay.com", // comment
          "<N/A>"                                    // tool
      };

    case 4:
      return {
          4,                                      // value
          "NVIDIA",                               // vendor
          "Contact Kerch Holt, kholt@nvidia.com", // comment
          "<N/A>"                                 // tool
      };

    case 5:
      return {
          5,                                                      // value
          "ARM",                                                  // vendor
          "Contact Alexander Galazin, alexander.galazin@arm.com", // comment
          "<N/A>"                                                 // tool
      };

    case 6:
      return {
          6,                                            // value
          "Khronos",                                    // vendor
          "Contact Yaxun (Sam) Liu, yaxun.liu@amd.com", // comment
          "LLVM/SPIR-V Translator"                      // tool
      };

    case 7:
      return {
          7,                                      // value
          "Khronos",                              // vendor
          "Contact David Neto, dneto@google.com", // comment
          "SPIR-V Tools Assembler"                // tool
      };

    case 8:
      return {
          8,                                                  // value
          "Khronos",                                          // vendor
          "Contact John Kessenich, johnkessenich@google.com", // comment
          "Glslang Reference Front End"                       // tool
      };

    case 9:
      return {
          9,                                   // value
          "Qualcomm",                          // vendor
          "Contact weifengz@qti.qualcomm.com", // comment
          "<N/A>"                              // tool
      };

    case 10:
      return {
          10,                                           // value
          "AMD",                                        // vendor
          "Contact Daniel Rakos, daniel.rakos@amd.com", // comment
          "<N/A>"                                       // tool
      };

    case 11:
      return {
          11,                                       // value
          "Intel",                                  // vendor
          "Contact Alexey, alexey.bader@intel.com", // comment
          "<N/A>"                                   // tool
      };

    default:
      return {
          _val,        // value
          "<UNKNOWN>", // vendor
          "<UNKNOWN>", // comment
          "<UNKNOWN>"  // tool
      };
  }
}
