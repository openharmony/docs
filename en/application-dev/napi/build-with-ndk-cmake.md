# Building NDK Projects with Command-Line CMake

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @liyiming13-->
<!--Designer: @liyiming13-->
<!--Tester: @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=b2ce85b7434b59119d9d781b6d8f1dadc3db7fdf translatedAt=2026-07-25T03:44:07.590Z pushedAt=2026-07-25T07:08:00.798Z -->

In many complex app projects, C++ source code is built via command-line build systems such as CMake. This section describes how to switch an existing CMake project to the OpenHarmony toolchain, so that you can build the project using command-line CMake.

<!--Del-->

## Downloading the NDK Development Package

<!--DelEnd-->
<!--RP1-->

1. You are advised to use the officially released OpenHarmony SDK package. For the download link, refer to the **Release Notes** of the official OpenHarmony release version.

   Specifically, locate the **Acquiring Source Code from Mirror** section.

   Then, download the SDK package based on your system type.

2. Download from the OpenHarmony SDK Manager in DevEco Studio.

## Decompressing the NDK

After the download is complete, place the compressed package into the created folder and extract it.

The following figure shows the extracted SDK package on Windows/Linux.

![ndk-decomp-structure](figures/ndk-decomp-structure.png)

The following figure shows the extracted SDK package on macOS.

![macos-unzip](figures/macos-unzip.png)

<!--RP1End-->

### Configuring the Environment Variable

If you only use it in DevEco Studio, skip the following steps.

1. Add the CMake build tool bundled with the NDK to the environment variables.

   + Configure environment variables on Linux:

      ```shell
      # Open the .bashrc file.
      vim ~/.bashrc
      # Add the cmake path at the end of the file. This path is the directory where the file is placed. Then save and exit.
      export PATH=${SDK path}/native/build-tools/cmake/bin:$PATH
      # Execute source ~/.bashrc in the command line to make the environment variable take effect.
      source ~/.bashrc
      ```

   + Configure environment variables on macOS:

      ```shell
      # In the current user directory, open the .bash_profile file. If the file does not exist, create it.
      vim ~/.bash_profile
      # Add the cmake path at the end of the file. This path is the directory where the file is placed. Then save and exit.
      export PATH=${SDK path}/native/build-tools/cmake/bin:$PATH
      # Run `source ~/.bash_profile` on the command line to make the environment variables take effect.
      source ~/.bash_profile
      ```

   + Configure environment variables in Windows:

      Right-click **This PC**, select **Properties** from the context menu, and then click **Advanced system settings**. Go to **Environment Variables**, find **Path**, and click **Edit**. Click **New** to add the path, save the changes, and exit. Finally, open cmd. (If the next step cannot be completed, restart the computer and try again.)

      ![windows-path-log](figures/windows-path-log.PNG)

      Open cmd, enter **cmake.exe -version**, and if the command line correctly returns the CMake version number, the environment variable configuration is complete.

      ![cmake-version-check](figures/cmake-version-check.PNG)

2. Check the default CMake path.

   + On Linux and Mac systems:

      ```shell
      # Run the which command to query the current CMake path.
      which cmake
      # The result path is consistent with the setting in .bashrc.
      ~/ohos-sdk/ohos-sdk/linux/native/build-tools/cmake/bin/cmake
      ```

   + In Windows, the CMake installation path is the environment variable path you configured:

      You can check it in the **Path** variable under **This PC** -> **Advanced system settings** -> **Environment Variables**.

## Using the NDK to Compile a Native Program

You can use the NDK development package to quickly develop native dynamic libraries, static libraries, and executable files. The NDK development package provides CMake build tool scripts. The following demonstrates the adaptation process by creating a C/C++ demo project.

### Demo Project

The following is the content of a CMake demo project. This project contains two directories: the `include` directory contains the header files of the library, and the `src` directory contains all source code. The `src` directory contains two files: `sum.cpp`, the algorithm file, and `hello.cpp`, the main entry file that calls the algorithm. The goal is to compile them into an executable program and an algorithm dynamic library.

**Demo Project Directory**

```txt
demo
  ├── CMakeLists.txt
  ├── include
       └── sum.h
  └── src
       ├── CMakeLists.txt
       ├── sum.cpp
       └── hello.cpp
```

**CMakeLists.txt in the Root Directory**

```txt
# Specify the minimum CMake version.
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

# Specify the project name. In this example, the project is named HELLO.
PROJECT(HELLO)

# Add a subdirectory and build the targets in the subdirectory.
ADD_SUBDIRECTORY(src)
```

**Internal CMakeLists.txt**

```txt
SET(LIBHELLO_SRC hello.cpp)

# Set compilation options.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")   
 
# Set linker options. The specific options can be ignored as they are only provided as an example.
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--emit-relocs --verbose")    

# Add a dynamic library target named libsum. A libsum.so file is generated after successful compilation.
ADD_LIBRARY(sum SHARED sum.cpp)

# Generate an executable program. Add an executable target named Hello. A Hello executable is generated after successful compilation.
ADD_EXECUTABLE(Hello ${LIBHELLO_SRC})

# Specify the include directory path for the Hello target.
TARGET_INCLUDE_DIRECTORIES(Hello PUBLIC ../include)

# Specify the libraries to be linked by the Hello target.
TARGET_LINK_LIBRARIES(Hello PUBLIC sum)
```

**Source Code**

hello.cpp source code

```c++
#include <iostream>
#include "sum.h"

int main(int argc,const char **argv)
{
    std::cout<< "hello world!" <<std::endl;
    int total = sum(1, 100);
    std::cout<< "Sum 1 + 100=" << total << std::endl;
    return 0;
}
```

sum.h source code

```c++
int sum(int a, int b);
```

sum.cpp source code

```c++
#include <iostream>
    
int sum(int a, int b)
{
    return a + b;
}
```

### Compiling and Building the Demo Project

**In Linux and Mac System Environments**

In the module directory of the project, create a build directory to store intermediate files generated during CMake build. Note: `ohos-sdk` is the root directory of the downloaded SDK. You need to replace it with the actual download directory.

1. Use `OHOS_STL=c++_shared` to dynamically link the C++ library for building the project. If not specified, `c++_shared` is used by default. The `OHOS_ARCH` parameter determines the specific value based on the system architecture. For example, when `OHOS_ARCH=armeabi-v7a`, a 32-bit dynamic library is compiled; when `OHOS_ARCH=arm64-v8a`, a 64-bit dynamic library is compiled.

   ```shell
    mkdir build && cd build
    cmake -D OHOS_STL=c++_shared -D OHOS_ARCH=arm64-v8a -D OHOS_PLATFORM=OHOS -D CMAKE_TOOLCHAIN_FILE={ohos-sdk}/linux/native/build/cmake/ohos.toolchain.cmake ..
    cmake --build .
   ```

2. Use `OHOS_STL=c++_static` to statically link the C++ library for building the project. When `OHOS_ARCH=armeabi-v7a`, a 32-bit static library is compiled; when `OHOS_ARCH=arm64-v8a`, a 64-bit static library is compiled.

   ```shell
    mkdir build && cd build
    cmake -D OHOS_STL=c++_static -D OHOS_ARCH=arm64-v8a -D OHOS_PLATFORM=OHOS -D CMAKE_TOOLCHAIN_FILE={ohos-sdk}/linux/native/build/cmake/ohos.toolchain.cmake ..
    cmake --build .
   ```

   In this command, the `OHOS_ARCH` and `OHOS_PLATFORM` variables ultimately generate the `--target` parameter for `clang++`, which in this example are `--target=arm-linux-ohos` and `--march=arm64-v8a`.

   `CMAKE_TOOLCHAIN_FILE` specifies the toolchain file, in which `--sysroot={ndk_sysroot directory}` is set for `clang++` by default, telling the compiler the root directory for locating system header files.

> **NOTE**
>
> Dynamic linking loads library files at runtime, effectively saving disk space and memory, but it also adds runtime loading overhead and slightly affects startup performance. Static linking embeds library code directly into the executable, resulting in faster startup but larger file sizes. It is suitable for scenarios sensitive to startup performance or with constrained runtime environments, but not for apps or devices sensitive to disk space.

**On Windows**

When using CMake for building on Windows, unlike on Linux, you need to add the `-G` parameter to select a generator. Pressing `Enter` directly will list the available generators below.

![cmake-windows-G](figures/cmake-windows-G.png)

Here, `cmake .. -G "Ninja"` is used. The parameter in quotation marks is the generator supported by the environment shown in the preceding figure. The built-in generator in the NDK is Ninja.

![cmake-ninja-bin](figures/cmake-ninja-bin.png)

Step 1. Similarly, create a `build` folder in the module directory of the project directory, enter the `build` directory, and run the following command:

```shell
 F:\windows\native\build-tools\cmake\bin\cmake.exe -G "Ninja" -D OHOS_STL=c++_shared -D OHOS_ARCH=arm64-v8a -D OHOS_PLATFORM=OHOS -D CMAKE_TOOLCHAIN_FILE=F:\windows\native\build\cmake\ohos.toolchain.cmake ..
```

> **NOTE**
>
> For debug purposes, add the parameter `-D CMAKE_BUILD_TYPE=Debug`. Both the CMake path and the compilation toolchain `ohos.toolchain.cmake` path are the paths of the downloaded NDK.<br>The execution result is shown in the following figure:

![cmake-config-log](figures/cmake-config-log.png)

The generated build.ninja file is what we need.

Step 2. Use the ninja command to compile and generate the target files. The output location is shown in the following figure:

![build-dir-list](figures/build-dir-list.png)

Run `ninja -f build.ninja` or `cmake --build .` The execution result is as follows:

![ninja-build-log](figures/ninja-build-log.png)

The compiled executable file is located in the src directory under the created build directory.