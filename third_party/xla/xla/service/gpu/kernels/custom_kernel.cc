/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "xla/service/gpu/kernels/custom_kernel.h"

#include <cstddef>
#include <utility>

#include "xla/stream_executor/kernel_spec.h"
#include "xla/stream_executor/launch_dim.h"

namespace xla::gpu::kernel {

CustomKernel::CustomKernel(se::MultiKernelLoaderSpec kernel_spec,
                           se::BlockDim block_dims, se::ThreadDim thread_dims,
                           size_t shared_memory_bytes)
    : kernel_spec_(std::move(kernel_spec)),
      block_dims_(block_dims),
      thread_dims_(thread_dims),

      shared_memory_bytes_(shared_memory_bytes) {}

const se::MultiKernelLoaderSpec& CustomKernel::kernel_spec() const {
  return kernel_spec_;
}

se::BlockDim CustomKernel::block_dims() const { return block_dims_; }

se::ThreadDim CustomKernel::thread_dims() const { return thread_dims_; }

size_t CustomKernel::shared_memory_bytes() const {
  return shared_memory_bytes_;
}

}  // namespace xla::gpu::kernel
