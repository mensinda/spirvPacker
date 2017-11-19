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
 *
 */

#pragma once

#define SPDLOG_TRACE_ON

#include <spdlog/spdlog.h>
#include <stddef.h>
#include <stdint.h>

#define WIDEN2(x) L##x
#define WIDEN(x) WIDEN2(x)

#define W_FILE WIDEN(__FILE__)

// Detect compiler function macro
#if defined __clang__
// #    define W_FUNC __PRETTY_FUNCTION__ // A bit to long ...
#define W_FUNC __func__
#elif defined __GNUC__
// #    define W_FUNC __PRETTY_FUNCTION__ // A bit to long ...
#define W_FUNC __func__
#elif defined _MSC_VER
// #    define W_FUNC __PRETTY_FUNCTION__ // A bit to long ...
#define W_FUNC __FUNCTION__
#else
#define W_FUNC __func__
#endif

// clang-format off

#define SPIRV_PACKER_VERSION_MAJOR  @CM_VERSION_MAJOR@
#define SPIRV_PACKER_VERSION_MINOR  @CM_VERSION_MINOR@
#define SPIRV_PACKER_VERSION_PATCH  @CM_VERSION_PATCH@
#define SPIRV_PACKER_LAST_TAG_DIFF  @CM_TAG_DIFF@
#define SPIRV_PACKER_COMMIT         "@CM_VERSION_GIT@"
#define SPIRV_PACKER_INSTALL_PREFIX "@CMAKE_INSTALL_PREFIX@"

#define STD_FILESYSTEM_IS_EXPERIMENTAL true
#define SOURCE_DIR "@PROJECT_SOURCE_DIR@"

#define SPDLOG_LOGGER_NAME   "spirvPacker"
#define SPDLOG_FORMAT_STRING "(%d:%m:%C %H:%M:%S) [%L]: %v"

// clang-format on

namespace spirvPacker {

inline std::shared_ptr<spdlog::logger> getLogger() {
  std::shared_ptr<spdlog::logger> lLogger = spdlog::get(SPDLOG_LOGGER_NAME);

  if (!lLogger) {
    lLogger = spdlog::stdout_color_mt(SPDLOG_LOGGER_NAME);
    lLogger->set_pattern(SPDLOG_FORMAT_STRING);
  }

  return lLogger;
}

} // namespace spirvPacker
