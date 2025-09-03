# Building an NDK Project with Prebuilt Libraries

In an NDK project, you can use the CMake syntax to import and use prebuilt libraries. When prebuilt libraries are referenced, both those in the module's **libs** directory and those declared in the **CMakeList.txt** build script are packaged.

## Constraints for Using Prebuilt Libraries

1. Ensure that the imported dynamic libraries (.so files) are compiled using the [OpenHarmony NDK toolchain](build-with-ndk-overview.md). For details about how to compile prebuilt libraries with the OpenHarmony NDK toolchain, see [Adaptation Process of Using CMake to Build Third-Party Libraries](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-cmake-adapts-to-harmonyos#section1826019653918).

2. Ensure that dependencies of the imported .so dynamic libraries are also imported into the project and compiled using the OpenHarmony NDK toolchain.

## Importing a Prebuilt Library

You can import a prebuilt library by directly copying the library files into the project. For example, the prebuilt library **libavcodec_ffmpeg.so** is located in the following directory during development.

![Snipaste_2023-10-30_14-39-27](figures/Snipaste_2023-10-30_14-39-27.png)

To use it in your project, add it through **add_library** in the module's **CMakeLists.txt** build script and declare information such as the path to the prebuilt library. Then you can declare the link to the prebuilt library in **target_link_libraries**. The following is an example of the build script:

```cmake
add_library(library SHARED hello.cpp)

add_library(avcodec_ffmpeg SHARED IMPORTED)
set_target_properties(avcodec_ffmpeg
    PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/third_party/FFmpeg/libs/${OHOS_ARCH}/libavcodec_ffmpeg.so)

target_link_libraries(library PUBLIC libace_napi.z.so avcodec_ffmpeg)
```

Add **include_directories** in the module's **CMakeLists.txt** build script.

```cmake
include_directories(
    ...
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/FFmpeg/include
)
```

When prebuilt libraries are used in the HAR, the currently built libraries and prebuilt libraries required for linking are packed to the **libs** directory in the HAR, as shown in the following figure.

![en-us_image_0000001693795070](figures/en-us_image_0000001693795070.png)

### Resolving the SONAME Issue with Prebuilt Libraries

Ensure that the imported prebuilt dynamic libraries (.so files) have the correct SONAME set.

If a prebuilt .so file lacks a SONAME, the linker will embed the absolute path of the .so file into the **dynamic section** of dependent binaries. When these binaries are packaged into a HAP for release, the dynamic loader may fail to locate the .so file, leading to runtime errors.

Use the **llvm-readelf** tool to verify whether a .so file has a SONAME set. The tool's path depends on your installation: **${*DevEco Studio installation directory*}/sdk/default/openharmony/native/llvm/bin** or **${*command-line-tools installation directory*}/sdk/default/openharmony/native/llvm/bin/llvm-readelf**.
Example:

```bash
> ${YOUR_PATH}/command-line-tools/sdk/default/openharmony/native/llvm/bin/llvm-readelf -d libavcodec_ffmpeg.so | grep SONAME  
0x000000000000000e (SONAME)             Library soname: [libavcodec_ffmpeg.so]
```

For prebuilt dynamic libraries (.so files) built with CMake, no additional configuration is required for setting the SONAME, since CMake automatically sets the SONAME for them as long as the target platform supports it. 
For prebuilt dynamic libraries (.so files) built with other tools, explicitly configure **ldflags** to set the SONAME.

```bash
${...}/clang++ ${...} -Wl,-soname,libavcodec_ffmpeg.so
```

## Using a Prebuilt Library Integrated in a Remote HAR Dependency

To use a prebuilt library integrated in a remote dependency HAR, write the reference script in **CMakeLists.txt** as follows:

```cmake
set(DEPENDENCY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules)
add_library(library SHARED IMPORTED)
set_target_properties(library
    PROPERTIES
    IMPORTED_LOCATION ${DEPENDENCY_PATH}/library/libs/${OHOS_ARCH}/liblibrary.so)
add_library(entry SHARED hello.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so library)
```

## Using a Prebuilt Library Integrated in a Local HAR

To use a prebuilt library integrated in a local HAR, write the reference script in **CMakeLists.txt** as follows:

```cmake
set(LIBRARY_DIR "${NATIVERENDER_ROOT_PATH}/../../../../library/build/default/intermediates/libs/default/${OHOS_ARCH}/")
add_library(library SHARED IMPORTED)
set_target_properties(library
    PROPERTIES
    IMPORTED_LOCATION ${LIBRARY_DIR}/liblibrary.so)
add_library(entry SHARED hello.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so library)
```
