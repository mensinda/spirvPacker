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

#include <stddef.h>
#include <stdint.h>

// clang-format off

#define SPIRV_PACKER_VERSION_MAJOR  @CM_VERSION_MAJOR@
#define SPIRV_PACKER_VERSION_MINOR  @CM_VERSION_MINOR@
#define SPIRV_PACKER_VERSION_PATCH  @CM_VERSION_PATCH@
#define SPIRV_PACKER_LAST_TAG_DIFF  @CM_TAG_DIFF@
#define SPIRV_PACKER_COMMIT         "@CM_VERSION_GIT@"
#define SPIRV_PACKER_INSTALL_PREFIX "@CMAKE_INSTALL_PREFIX@"

namespace spirvPacker {

}

// clang-format on
