//! \note This is an automatically generated file
#pragma once

#include "spvCfg.hpp"
#include <string>
#include <vector>

namespace spirvPacker {

struct SPIRVToolDesc {
  uint32_t    value;
  std::string vendor;
  std::string comment;
  std::string tool;
};

SPIRVToolDesc getToolDeskFromMagicNumber(uint32_t _val);

} // namespace spirvPacker
