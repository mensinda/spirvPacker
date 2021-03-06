/*
 * Copyright (C) 2015 EEnginE project
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

#version 450

layout (location = 0) in vec3 iVertex;
layout (location = 1) in vec3 iNormals;
layout (location = 2) in vec2 iUV;

layout (set = 0, binding = 0) uniform UBuffer {
  mat4 mvp;
  float lodBias;
  mat3 normal;
  bool b1;
} uBuff;

layout (location = 0) out vec3  vNormals;
layout (location = 1) out vec2  vUV;
layout (location = 2) out float vLodBias;

void main() {
   vLodBias = uBuff.lodBias + sqrt(uBuff.lodBias);
   vNormals = uBuff.normal * iNormals;
   vUV = iUV;
   gl_Position = uBuff.mvp * vec4(iVertex, 1.0);
}
