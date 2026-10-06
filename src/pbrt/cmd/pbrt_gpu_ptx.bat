@echo off
setlocal

if defined BAZEL_VS (
    call "%BAZEL_VS%\VC\Auxiliary\Build\vcvars64.bat" >nul
) else (
    for /f "tokens=*" %%v in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -nologo -latest -products * -find VC\Auxiliary\Build\vcvars64.bat') do call "%%v" >nul
)
if not defined VSCMD_VER (
    echo CUDA 13.2 GPU builds require Visual Studio 2019, 2022, or 2026 with MSVC. 1>&2
    exit /b 1
)

set "CICC_PATH=external\rules_cuda++toolchain+cuda_nvvm_windows_x86_64_13_2_2\nvvm\nvvm\bin"
set "NVVMIR_LIBRARY_DIR=external\rules_cuda++toolchain+cuda_nvvm_windows_x86_64_13_2_2\nvvm\nvvm\libdevice"

rem The host compiler preprocesses the device code, and CCCL requires MSVC's
rem standard-conforming preprocessor. "%~dp4." avoids a trailing backslash that
rem would escape the closing quote.
"%~1" --ptx -std=c++17 -arch=compute_75 --extended-lambda --expt-relaxed-constexpr ^
    -Xcompiler=/Zc:preprocessor ^
    -DPTEX_STATIC -DPBRT_BUILD_GPU_RENDERER -DPBRT_IS_WINDOWS -DPBRT_IS_MSVC ^
    -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS -D_ENABLE_EXTENDED_ALIGNED_STORAGE ^
    -DPBRT_HAS_INTRIN_H -DPBRT_HAVE__ALIGNED_MALLOC ^
    "-DPBRT_NOINLINE=__declspec(noinline)" -DPBRT_RESTRICT=__restrict ^
    -I external\rules_cuda++toolchain+cuda_cudart_windows_x86_64_13_2_2\cudart\include ^
    -I external\rules_cuda++toolchain+cuda_nvcc_windows_x86_64_13_2_2\nvcc\include ^
    -I external\rules_cuda++toolchain+cuda_cccl_windows_x86_64_13_2_2\cccl\include ^
    -I external\rules_cuda++toolchain+cuda_cccl_windows_x86_64_13_2_2\cccl\include\cccl ^
    -I external\rules_cuda++toolchain+cuda_crt_windows_x86_64_13_2_2\crt\include ^
    -I "%~dp6.." -I src -I "%~dp4." -I external\+http_archive+nanovdb_headers\nanovdb ^
    "%~3" -o "%~4"
if errorlevel 1 exit /b 1

"%~2" --name PBRT_EMBEDDED_PTX "%~4" > "%~5"