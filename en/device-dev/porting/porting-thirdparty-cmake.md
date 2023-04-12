# Porting a Library Built Using CMake


The following shows how to port the double-conversion library.

## Source Code Acquisition

Acquire the source code of double-conversion from [double-conversion](https://github.com/google/double-conversion). The following table lists the directory structure.

**Table 1** Directory structure of the source code

| Directory | Description |
| -------- | -------- |
| double-conversion/cmake/ | Template used for building with CMake |
| double-conversion/double-conversion/ | Directory of source files |
| double-conversion/msvc/ | - |
| double-conversion/test/ | Source files of the test cases |
| double-conversion/.gitignore | - |
| double-conversion/AUTHORS | - |
| double-conversion/BUILD | - |
| double-conversion/CMakeLists.txt | Top-level file used for building with CMake |
| double-conversion/COPYING | - |
| double-conversion/Changelog | - |
| double-conversion/LICENSE | - |
| double-conversion/Makefile | - |
| double-conversion/README.md | - |
| double-conversion/SConstruct | - |
| double-conversion/WORKSPACE | - |

## Porting Guidelines

Cross-compile the double-conversion library by modifying the toolchain to generate executable files for the OpenHarmony platform and then add these files to the OpenHarmony project by invoking CMake via GN.

## Cross-Compilation

### Compilation Reference

The [README.md](https://github.com/google/double-conversion/blob/master/README.md) file in the code repository details the procedures for compiling the double-conversion library using CMake as well as the testing methods. This document focuses on the building, compilation, and testing of the library. If you have any questions during library porting, refer to the **README.md** file. For porting of other third-party libraries that can be independently built with CMake, you can refer to the compilation guides provided by the libraries.

### Cross-Compilation Settings

The following steps show how to configure and modify the toolchains for cross-compiling the libraries built using CMake to compile executable files for the OpenHarmony platform.

1.  Configure the toolchains.

    Add configuration of the clang toolchains to the top-level file **CMakeLists.txt** listed in Table 1.

    ```
    set(CMAKE_CROSSCOMPILING TRUE)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_CXX_COMPILER_ID Clang)
    set(CMAKE_TOOLCHAIN_PREFIX llvm-)
    # Specify the C compiler (ensure that the path of the toolchain has been added to the PATH environment variable) and its flags. To perform cross-compilation using clang, the --target flag must be specified.
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_C_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    # Specify the C++ compiler (ensure that the path of the toolchain has been added to the PATH environment variable) and its flags. To perform cross-compilation, the --target flag must be specified.
    set(CMAKE_CXX_COMPILER clang++) 
    set(CMAKE_CXX_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    # Specify the linker and its flags. --target and --sysroot must be specified. You can specify OHOS_SYSROOT_PATH via the suffix parameter of the cmake command.
    set(MY_LINK_FLAGS "--target=arm-liteos --sysroot=${OHOS_SYSROOT_PATH}")
    set(CMAKE_LINKER clang)
    set(CMAKE_CXX_LINKER clang++)
    set(CMAKE_C_LINKER clang)
    set(CMAKE_C_LINK_EXECUTABLE
        "${CMAKE_C_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    set(CMAKE_CXX_LINK_EXECUTABLE
        "${CMAKE_CXX_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    # Specify the path for searching chained libraries.
    set(CMAKE_SYSROOT ${OHOS_SYSROOT_PATH})
    ```

2.  Perform the compilation.

    Run a Linux command to enter the directory \(listed in Table 1) for storing double-conversion source files and then run the following commands:
    
   ```
   mkdir build && cd build
   cmake .. -DBUILD_TESTING=ON -DOHOS_SYSROOT_PATH="..."
   make -j
   ```

   **OHOS\_SYSROOT\_PATH** specifies the absolute path where **sysroot** is located. For OpenHarmony, set **OHOS\_SYSROOT\_PATH** to the absolute path of the **out/hispark\__xxx_/ipcamera\_hispark\__xxx_/sysroot** directory. This directory is generated after full compilation is complete. Therefore, complete full compilation before porting.

3.  View the result.
    
    After step 2 is complete, a static library file and test cases are generated in the **build** directory.
    
    **Table 2** Directory structure of compiled files

    | Directory                                      | Description                       |
    | -------- | -------- |
    | double-conversion/build/libdouble-conversion.a | Static library file |
    | double-conversion/build/test/ | Test cases and CMake cache files |
    | double-conversion/build/CMakeCache.txt | Cache files during CMake building |
    | double-conversion/build/CMakeFiles/ | - |
    | double-conversion/build/cmake_install.cmake | - |
    | double-conversion/build/CTestTestfile.cmake | - |
    | double-conversion/build/DartConfiguration.tcl | - |
    | double-conversion/build/generated/ | - |
    | double-conversion/build/Makefile | - |
    | double-conversion/build/Testing/ | - |



## Library Test

1. Set up the OpenHarmony environment.

   Using Hi3516D V300 as an example, compile the OpenHarmony image and burn it to the development board. For details, see the content related to the small system in [Quick Start Overview](../quick-start/quickstart-overview.md).

   The following screen is displayed after a successful login to the OS.

   **Figure 1** Successful startup of OpenHarmony

   ![](figures/successful-startup-of-openharmony.png "successful-startup-of-openharmony")

2. Mount the **nfs** directory and put the executable file **cctest** into the **test** directory \(listed in Table 2) to the **nfs** directory.

3.  Perform the test cases.

    If the double-conversion library is not cross-compiled, you can execute the test cases by running the **make test** command and obtain the result via CMake. However, this command is not applicable to the library after cross-compilation. This way, you can perform the test cases by executing the generated test case files.

    - After the **nfs** directory is successfully mounted, run the following command to list all items in the test cases:
    
       ```
       cd nfs
       ./cctest --list
       ```
      
       Some items are as follows:
      
       
        ```
        test-bignum/Assign<
        test-bignum/ShiftLeft<
        test-bignum/AddUInt64<
        test-bignum/AddBignum<
        test-bignum/SubtractBignum<
        test-bignum/MultiplyUInt32<
        test-bignum/MultiplyUInt64<
        test-bignum/MultiplyPowerOfTen<
        test-bignum/DivideModuloIntBignum<
        test-bignum/Compare<
        test-bignum/PlusCompare<
        test-bignum/Square<
        test-bignum/AssignPowerUInt16<
        test-bignum-dtoa/BignumDtoaVariousDoubles<
        test-bignum-dtoa/BignumDtoaShortestVariousFloats<
        test-bignum-dtoa/BignumDtoaGayShortest<
        test-bignum-dtoa/BignumDtoaGayShortestSingle<
        test-bignum-dtoa/BignumDtoaGayFixed<
        test-bignum-dtoa/BignumDtoaGayPrecision<
        test-conversions/DoubleToShortest<
        test-conversions/DoubleToShortestSingle<
        ...
        ```
      
    - Run the following command to test **test-bignum**:

    
          ```
          ./cctest test-bignum
          ```

       The test is passed if the following information is displayed:

    
          ```
          Ran 13 tests.
          ```


## Adding the Compiled double-conversion Library to the OpenHarmony Project

1.  Copy the double-conversion library to the OpenHarmony project.

    Copy this library that can be cross-compiled to the **third\_party** directory of OpenHarmony. To avoid modifying the **BUILD.gn** file in the directory of the third-party library to be ported, add a directory to store adaptation files, including **BUILD.gn**, **build\_thirdparty.py**, and **config.gni**, for converting GN to CMake building.

    **Table 3** Directory structure of the ported library

   | Directory                                                    | Description                                                  |
   | -------- | -------- |
   | OpenHarmony/third_party/double-conversion/BUILD.gn | GN file for adding the third-party library to the OpenHarmony project |
   | OpenHarmony/third_party/double-conversion/build_thirdparty.py | Script file for GN to call the **shell** command to convert compilation from GN to CMake |
   | OpenHarmony/third_party/double-conversion/config.gni | Third-party library compilation configuration file, which can be modified to determine whether the test cases will be used during the building |
   | OpenHarmony/third_party/double-conversion/double-conversion/ | Directory of the third-party library to be ported |

2. Add the GN file to the CMake adaptation file.

   - The following shows the implementation for building using the newly added **BUILD.gn** file. For other third-party libraries that can be independently compiled using CMake, you only need to change the target paths when porting them to OpenHarmony.

     ```
     import("config.gni")
     group("double-conversion") {
         if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
             deps = [":make"]
         }
     }
     if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
         action("make") {
             script = "//third_party/double-  conversion/build_thirdparty.py"
             outputs = ["$root_out_dir/log_dc.txt"]
             exec_path = rebase_path(rebase_path("./build",   ohos_third_party_dir))
             command = "rm * .* -rf && $CMAKE_TOOLS_PATH/cmake ..   $CMAKE_FLAG $CMAKE_TOOLCHAIN_FLAG && make -j"
             args = [
                 "--path=$exec_path",
                 "--command=${command}"
             ]
         }
     }
     ```

   -   The newly added **config.gni** file is used to configure the library in the following example implementation. For other third-party libraries that can be independently compiled using CMake, you only need to change the configuration of **CMAKE\_FLAG** when porting them to OpenHarmony.

     ```
     #CMAKE_FLAG: config compile feature
     CMAKE_FLAG = "-DBUILD_TESTING=ON -DCMAKE_CXX_STANDARD=11"
   
     #toolchain: follow up-layer,depend on $ohos_build_compiler
     if (ohos_build_compiler == "clang") {
         CMAKE_TOOLCHAIN_FLAG = "-DOHOS_SYSROOT_PATH=${root_out_dir}sysroot"
     } else {
         CMAKE_TOOLCHAIN_FLAG = ""
     }

     #CMake tools path,no need setting if this path already joined to $PATH.
     CMAKE_TOOLS_PATH = "setting CMake tools path..."
     ```

   - The following shows the implementation of the newly added **build\_thirdparty.py** file. For other third-party libraries that can be independently compiled using CMake, you can port them to OpenHarmony without modifications.

     
     ```
     import os
     import sys
     from subprocess import Popen
     import argparse
     import shlex
   
     def cmd_exec(command):
         cmd = shlex.split(command)
         proc = Popen(cmd)
         proc.wait()
         ret_code = proc.returncode
         if ret_code != 0:
             raise Exception("{} failed, return code is {}".format(cmd, ret_code))
   
     def main():
         parser = argparse.ArgumentParser()
         parser.add_argument('--path', help='Build path.')
         parser.add_argument('--command', help='Build command.')
         parser.add_argument('--enable', help='enable python.', nargs='*')
         args = parser.parse_args()
   
         if args.enable:
             if args.enable[0] == 'false':
               return
   
         if args.path:
             curr_dir = os.getcwd()
             os.chdir(args.path)
             if args.command:
                 if '&&' in args.command:
                     command = args.command.split('&&')
                     for data in command:
                       cmd_exec(data)
               else:
                   cmd_exec(args.command)
           os.chdir(curr_dir)
   
      if __name__ == '__main__':
         sys.exit(main())
     ```
   
   - Add a configuration item in the configuration file to control compiling of the library. By default, library compilation is disabled.
   
     For example, add the following configuration to the **//build/lite/ohos\_var.gni** file:
   
     ```
     declare_args() {
         ohos_build_thirdparty_migrated_from_fuchisa = true
      }
     ```

3. Build the library.

   Execute the following command:

   ```
   hb build -T //third_party/double-conversion:double-conversion
   ```
   
   If the compilation is successful, a static library file and test cases will be generated in the **build** directory.

 <!--no_check--> 
