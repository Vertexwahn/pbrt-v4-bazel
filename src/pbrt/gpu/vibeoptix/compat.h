/*
 * pbrt OptiX-compatible names backed by VibeOptiX's driver function table.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PBRT_GPU_VIBEOPTIX_COMPAT_H
#define PBRT_GPU_VIBEOPTIX_COMPAT_H

#include <vibeoptix/api.h>

#include <exception>
#include <string>
#include <utility>

namespace pbrt {

namespace vibeoptix = ::vibeoptix;

using OptixAabb = vibeoptix::Aabb;
using OptixAccelBufferSizes = vibeoptix::AccelBufferSizes;
using OptixAccelBuildOptions = vibeoptix::AccelBuildOptions;
using OptixAccelEmitDesc = vibeoptix::AccelEmitDesc;
using OptixBuildInput = vibeoptix::BuildInput;
using OptixDenoiser = vibeoptix::Denoiser;
using OptixDenoiserGuideLayer = vibeoptix::DenoiserGuideLayer;
using OptixDenoiserLayer = vibeoptix::DenoiserLayer;
using OptixDenoiserOptions = vibeoptix::DenoiserOptions;
using OptixDenoiserParams = vibeoptix::DenoiserParams;
using OptixDenoiserSizes = vibeoptix::DenoiserSizes;
using OptixDeviceContext = vibeoptix::DeviceContext;
using OptixDeviceContextOptions = vibeoptix::DeviceContextOptions;
using OptixImage2D = vibeoptix::Image2D;
using OptixInstance = vibeoptix::Instance;
using OptixModule = vibeoptix::Module;
using OptixModuleCompileOptions = vibeoptix::ModuleCompileOptions;
using OptixPipeline = vibeoptix::Pipeline;
using OptixPipelineCompileOptions = vibeoptix::PipelineCompileOptions;
using OptixPipelineLinkOptions = vibeoptix::PipelineLinkOptions;
using OptixProgramGroup = vibeoptix::ProgramGroup;
using OptixProgramGroupDesc = vibeoptix::ProgramGroupDesc;
using OptixProgramGroupOptions = vibeoptix::ProgramGroupOptions;
using OptixRayFlags = vibeoptix::RayFlags;
using OptixResult = vibeoptix::Result;
using OptixShaderBindingTable = vibeoptix::ShaderBindingTable;
using OptixTraversableHandle = vibeoptix::TraversableHandle;
using OptixVisibilityMask = vibeoptix::VisibilityMask;

#define VIBEOPTIX_API_VERSION 90000
inline constexpr OptixResult OPTIX_SUCCESS = vibeoptix::RESULT_SUCCESS;
inline constexpr size_t OPTIX_SBT_RECORD_HEADER_SIZE = vibeoptix::SBT_RECORD_HEADER_SIZE;
inline constexpr size_t OPTIX_SBT_RECORD_ALIGNMENT = vibeoptix::SBT_RECORD_ALIGNMENT;
inline constexpr int OPTIX_COMPILE_DEFAULT_MAX_REGISTER_COUNT =
    vibeoptix::COMPILE_DEFAULT_MAX_REGISTER_COUNT;
inline constexpr auto OPTIX_BUILD_FLAG_ALLOW_COMPACTION =
    vibeoptix::BUILD_FLAG_ALLOW_COMPACTION;
inline constexpr auto OPTIX_BUILD_FLAG_PREFER_FAST_TRACE =
    vibeoptix::BUILD_FLAG_PREFER_FAST_TRACE;
inline constexpr auto OPTIX_BUILD_INPUT_TYPE_CUSTOM_PRIMITIVES =
    vibeoptix::BUILD_INPUT_TYPE_CUSTOM_PRIMITIVES;
inline constexpr auto OPTIX_BUILD_INPUT_TYPE_INSTANCES = vibeoptix::BUILD_INPUT_TYPE_INSTANCES;
inline constexpr auto OPTIX_BUILD_INPUT_TYPE_TRIANGLES = vibeoptix::BUILD_INPUT_TYPE_TRIANGLES;
inline constexpr auto OPTIX_BUILD_OPERATION_BUILD = vibeoptix::BUILD_OPERATION_BUILD;
inline constexpr auto OPTIX_COMPILE_DEBUG_LEVEL_FULL = vibeoptix::COMPILE_DEBUG_LEVEL_FULL;
inline constexpr auto OPTIX_COMPILE_DEBUG_LEVEL_LINEINFO = vibeoptix::COMPILE_DEBUG_LEVEL_MINIMAL;
inline constexpr auto OPTIX_COMPILE_DEBUG_LEVEL_MODERATE = vibeoptix::COMPILE_DEBUG_LEVEL_MODERATE;
inline constexpr auto OPTIX_COMPILE_DEBUG_LEVEL_NONE = vibeoptix::COMPILE_DEBUG_LEVEL_NONE;
inline constexpr auto OPTIX_COMPILE_OPTIMIZATION_DEFAULT = vibeoptix::COMPILE_OPTIMIZATION_DEFAULT;
inline constexpr auto OPTIX_COMPILE_OPTIMIZATION_LEVEL_0 = vibeoptix::COMPILE_OPTIMIZATION_LEVEL_0;
inline constexpr auto OPTIX_DEVICE_CONTEXT_VALIDATION_MODE_ALL =
    vibeoptix::DEVICE_CONTEXT_VALIDATION_MODE_ALL;
inline constexpr auto OPTIX_EXCEPTION_FLAG_DEBUG = vibeoptix::EXCEPTION_FLAG_USER;
inline constexpr auto OPTIX_EXCEPTION_FLAG_NONE = vibeoptix::EXCEPTION_FLAG_NONE;
inline constexpr auto OPTIX_EXCEPTION_FLAG_STACK_OVERFLOW =
    vibeoptix::EXCEPTION_FLAG_STACK_OVERFLOW;
inline constexpr auto OPTIX_EXCEPTION_FLAG_TRACE_DEPTH = vibeoptix::EXCEPTION_FLAG_TRACE_DEPTH;
inline constexpr auto OPTIX_GEOMETRY_FLAG_DISABLE_ANYHIT =
    vibeoptix::GEOMETRY_FLAG_DISABLE_ANYHIT;
inline constexpr auto OPTIX_GEOMETRY_FLAG_NONE = vibeoptix::GEOMETRY_FLAG_NONE;
inline constexpr auto OPTIX_INDICES_FORMAT_UNSIGNED_INT3 =
    vibeoptix::INDICES_FORMAT_UNSIGNED_INT3;
inline constexpr auto OPTIX_INSTANCE_FLAG_DISABLE_ANYHIT =
    vibeoptix::INSTANCE_FLAG_DISABLE_ANYHIT;
inline constexpr auto OPTIX_INSTANCE_FLAG_NONE = vibeoptix::INSTANCE_FLAG_NONE;
inline constexpr auto OPTIX_PIXEL_FORMAT_FLOAT3 = vibeoptix::PIXEL_FORMAT_FLOAT3;
inline constexpr auto OPTIX_PROGRAM_GROUP_KIND_HITGROUP =
    vibeoptix::PROGRAM_GROUP_KIND_HITGROUP;
inline constexpr auto OPTIX_PROGRAM_GROUP_KIND_MISS = vibeoptix::PROGRAM_GROUP_KIND_MISS;
inline constexpr auto OPTIX_PROGRAM_GROUP_KIND_RAYGEN = vibeoptix::PROGRAM_GROUP_KIND_RAYGEN;
inline constexpr auto OPTIX_PROPERTY_TYPE_COMPACTED_SIZE =
    vibeoptix::PROPERTY_TYPE_COMPACTED_SIZE;
inline constexpr auto OPTIX_RAY_FLAG_NONE = vibeoptix::RAY_FLAG_NONE;
inline constexpr auto OPTIX_TRAVERSABLE_GRAPH_FLAG_ALLOW_ANY =
    vibeoptix::TRAVERSABLE_GRAPH_FLAG_ALLOW_ANY;
inline constexpr auto OPTIX_VERTEX_FORMAT_FLOAT3 = vibeoptix::VERTEX_FORMAT_FLOAT3;
inline constexpr auto OPTIX_DENOISER_ALPHA_MODE_COPY =
    vibeoptix::DENOISER_ALPHA_MODE_COPY;
inline constexpr auto OPTIX_DENOISER_MODEL_KIND_HDR = vibeoptix::DENOISER_MODEL_KIND_HDR;
inline constexpr auto OPTIX_DENOISER_MODEL_KIND_UPSCALE2X =
    vibeoptix::DENOISER_MODEL_KIND_UPSCALE2X;

namespace vibeoptix_detail {

inline thread_local std::string lastError;

template <typename F>
OptixResult call(F &&function) {
    try {
        lastError.clear();
        return std::forward<F>(function)();
    } catch (const std::exception &error) {
        lastError = error.what();
        return vibeoptix::RESULT_ERROR_LIBRARY_NOT_FOUND;
    }
}

}  // namespace vibeoptix_detail

inline const char *optixGetErrorString(OptixResult result) {
    if (!vibeoptix_detail::lastError.empty())
        return vibeoptix_detail::lastError.c_str();
    try {
        return vibeoptix::api().getErrorString(result);
    } catch (const std::exception &error) {
        vibeoptix_detail::lastError = error.what();
        return vibeoptix_detail::lastError.c_str();
    }
}

inline OptixResult optixInit() {
    return vibeoptix_detail::call([] {
        (void)vibeoptix::api();
        return vibeoptix::RESULT_SUCCESS;
    });
}

inline OptixResult optixDeviceContextCreate(CUcontext context,
                                            const OptixDeviceContextOptions *options,
                                            OptixDeviceContext *result) {
    return vibeoptix_detail::call(
        [&] { return vibeoptix::api().deviceContextCreate(context, options, result); });
}

inline OptixResult optixAccelComputeMemoryUsage(
    OptixDeviceContext context, const OptixAccelBuildOptions *options,
    const OptixBuildInput *inputs, unsigned int count, OptixAccelBufferSizes *sizes) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().accelComputeMemoryUsage(context, options, inputs, count, sizes);
    });
}

inline OptixResult optixAccelBuild(
    OptixDeviceContext context, CUstream stream, const OptixAccelBuildOptions *options,
    const OptixBuildInput *inputs, unsigned int count, CUdeviceptr tempBuffer,
    size_t tempSize, CUdeviceptr outputBuffer, size_t outputSize,
    OptixTraversableHandle *handle, const OptixAccelEmitDesc *emitted, unsigned int numEmitted) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().accelBuild(context, stream, options, inputs, count, tempBuffer,
                                           tempSize, outputBuffer, outputSize, handle, emitted,
                                           numEmitted);
    });
}

inline OptixResult optixAccelCompact(OptixDeviceContext context, CUstream stream,
                                     OptixTraversableHandle input, CUdeviceptr output,
                                     size_t outputSize, OptixTraversableHandle *handle) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().accelCompact(context, stream, input, output, outputSize, handle);
    });
}

inline OptixResult optixSbtRecordPackHeader(OptixProgramGroup group, void *header) {
    return vibeoptix_detail::call(
        [&] { return vibeoptix::api().sbtRecordPackHeader(group, header); });
}

inline OptixResult optixModuleCreate(
    OptixDeviceContext context, const OptixModuleCompileOptions *moduleOptions,
    const OptixPipelineCompileOptions *pipelineOptions, const char *input, size_t inputSize,
    char *log, size_t *logSize, OptixModule *module) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().moduleCreate(context, moduleOptions, pipelineOptions, input,
                                              inputSize, log, logSize, module);
    });
}

inline OptixResult optixProgramGroupCreate(
    OptixDeviceContext context, const OptixProgramGroupDesc *descriptions, unsigned int count,
    const OptixProgramGroupOptions *options, char *log, size_t *logSize,
    OptixProgramGroup *groups) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().programGroupCreate(context, descriptions, count, options, log,
                                                    logSize, groups);
    });
}

inline OptixResult optixPipelineCreate(
    OptixDeviceContext context, const OptixPipelineCompileOptions *compileOptions,
    const OptixPipelineLinkOptions *linkOptions, const OptixProgramGroup *groups,
    unsigned int count, char *log, size_t *logSize, OptixPipeline *pipeline) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().pipelineCreate(context, compileOptions, linkOptions, groups,
                                                count, log, logSize, pipeline);
    });
}

inline OptixResult optixPipelineSetStackSize(
    OptixPipeline pipeline, unsigned int directCallableTraversal,
    unsigned int directCallableState, unsigned int continuation, unsigned int graphDepth) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().pipelineSetStackSize(pipeline, directCallableTraversal,
                                                      directCallableState, continuation,
                                                      graphDepth);
    });
}

inline OptixResult optixLaunch(OptixPipeline pipeline, CUstream stream, CUdeviceptr params,
                               size_t paramsSize, const OptixShaderBindingTable *sbt,
                               unsigned int width, unsigned int height, unsigned int depth) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().launch(pipeline, stream, params, paramsSize, sbt, width, height,
                                       depth);
    });
}

inline OptixResult optixDenoiserCreate(OptixDeviceContext context,
                                       vibeoptix::DenoiserModelKind model,
                                       const OptixDenoiserOptions *options,
                                       OptixDenoiser *denoiser) {
    return vibeoptix_detail::call(
        [&] { return vibeoptix::api().denoiserCreate(context, model, options, denoiser); });
}

inline OptixResult optixDenoiserComputeMemoryResources(
    OptixDenoiser denoiser, unsigned int width, unsigned int height,
    OptixDenoiserSizes *sizes) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().denoiserComputeMemoryResources(denoiser, width, height, sizes);
    });
}

inline OptixResult optixDenoiserSetup(
    OptixDenoiser denoiser, CUstream stream, unsigned int width, unsigned int height,
    CUdeviceptr state, size_t stateSize, CUdeviceptr scratch, size_t scratchSize) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().denoiserSetup(denoiser, stream, width, height, state, stateSize,
                                               scratch, scratchSize);
    });
}

inline OptixResult optixDenoiserComputeIntensity(
    OptixDenoiser denoiser, CUstream stream, const OptixImage2D *input,
    CUdeviceptr intensity, CUdeviceptr scratch, size_t scratchSize) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().denoiserComputeIntensity(denoiser, stream, input, intensity,
                                                          scratch, scratchSize);
    });
}

inline OptixResult optixDenoiserInvoke(
    OptixDenoiser denoiser, CUstream stream, const OptixDenoiserParams *params,
    CUdeviceptr state, size_t stateSize, const OptixDenoiserGuideLayer *guide,
    const OptixDenoiserLayer *layers, unsigned int count, unsigned int offsetX,
    unsigned int offsetY, CUdeviceptr scratch, size_t scratchSize) {
    return vibeoptix_detail::call([&] {
        return vibeoptix::api().denoiserInvoke(denoiser, stream, params, state, stateSize, guide,
                                                layers, count, offsetX, offsetY, scratch,
                                                scratchSize);
    });
}

}  // namespace pbrt

#endif  // PBRT_GPU_VIBEOPTIX_COMPAT_H
