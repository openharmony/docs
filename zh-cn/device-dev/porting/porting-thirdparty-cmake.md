# CMake方式组织编译的库移植


以double-conversion库为例，其移植过程如下文所示。


## 源码获取

从仓库[获取double-conversion源码](https://github.com/google/double-conversion)，其目录结构如下表：

  **表1** 源码目录结构

| 名称 | 描述 |
| -------- | -------- |
| double-conversion/cmake/ | CMake组织编译使用到的模板 |
| double-conversion/double-conversion/ | 源文件目录 |
| double-conversion/msvc/ | - |
| double-conversion/test/ | 测试用例源文件 |
| double-conversion/.gitignore | - |
| double-conversion/AUTHORS | - |
| double-conversion/BUILD | - |
| double-conversion/CMakeLists.txt | CMake方式顶层编译组织文件 |
| double-conversion/COPYING | - |
| double-conversion/Changelog | - |
| double-conversion/LICENSE | - |
| double-conversion/Makefile | - |
| double-conversion/README.md | - |
| double-conversion/SConstruct | - |
| double-conversion/WORKSPACE | - |


## 移植思路

移植思路：通过修改工具链，交叉编译该三方库，生成OpenHarmony平台的可执行文件，最后再通过GN调用CMake的方式添加到OpenHarmony工程中。


## 交叉编译


### 编译参考

代码仓库的[README.md](https://github.com/google/double-conversion/blob/master/README.md)中详细介绍了使用CMake编译double-conversion库的步骤，以及测试方法。本文参考该指导设置该库的编译配置，并完成测试。若开发人员在移植过程中对该库的编译选项配置有疑惑的地方，可参考该指导。对于其他使用CMake可独立编译的三方库，在移植时可以参考其自带的编译指导。


### 设置执行交叉编译

CMake方式可通过指定工具链进行交叉编译，修改并编译该库，生成OpenHarmony平台的可执行文件，步骤如下：

1. 设置工具链
     将下列clang工具链配置添加到该工程的顶层CMakeLists.txt（即表1中的该文件）中即可。
     
   ```
   set(CMAKE_CROSSCOMPILING TRUE)
   set(CMAKE_SYSTEM_NAME Generic)
   set(CMAKE_CXX_COMPILER_ID Clang)
   set(CMAKE_TOOLCHAIN_PREFIX llvm-)
   #指定c编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，使用clang编译时标志中必须指定--target，否则无法交叉编译。
   set(CMAKE_C_COMPILER clang)
   set(CMAKE_C_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4")
   #指定c++编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，必须指定--target，否则无法交叉编译。
   set(CMAKE_CXX_COMPILER clang++) 
   set(CMAKE_CXX_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4")
   #指定链接工具和链接标志，必须指定--target和--sysroot，其中OHOS_ROOT_PATH可通过cmake命令后缀参数来指定。
   set(MY_LINK_FLAGS "--target=arm-liteos --sysroot=${OHOS_SYSROOT_PATH}")
   set(CMAKE_LINKER clang)
   set(CMAKE_CXX_LINKER clang++)
   set(CMAKE_C_LINKER clang)
   set(CMAKE_C_LINK_EXECUTABLE
       "${CMAKE_C_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
   set(CMAKE_CXX_LINK_EXECUTABLE
       "${CMAKE_CXX_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
   #指定链接库的查找路径。
   set(CMAKE_SYSROOT ${OHOS_SYSROOT_PATH})
   ```

2. 执行编译
   linux命令行中进入double-conversion的源文件目录（即标1所示目录），执行下列命令：

   
   ```
   mkdir build && cd build
   cmake .. -DBUILD_TESTING=ON -DOHOS_SYSROOT_PATH="..."
   make -j
   ```

   其中OHOS_SYSROOT_PATH需用绝对路径指定出sysroot目录的位置，以OpenHarmony为例即目录out/hispark_xxx/ipcamera_hispark_xxx/sysroot的绝对路径。上述目录会在全量编译后生成，因此移植前先完成一次全量编译。

3. 查看结果
   步骤2操作完成后，build目录下会生成静态库文件和测试用例：

     **表2** 编译生成文件目录结构
   
   | 名称 | 描述 |
   | -------- | -------- |
   | double-conversion/build/libdouble-conversion.a | 生成的静态库文件 |
   | double-conversion/build/test/ | 目录下存放生成的测试用例和相关CMake缓存文件 |
   | double-conversion/build/CMakeCache.txt | CMake构建过程中的缓存文件 |
   | double-conversion/build/CMakeFiles/ | - |
   | double-conversion/build/cmake_install.cmake | - |
   | double-conversion/build/CTestTestfile.cmake | - |
   | double-conversion/build/DartConfiguration.tcl | - |
   | double-conversion/build/generated/ | - |
   | double-conversion/build/Makefile | - |
   | double-conversion/build/Testing/ | - |


## 测试

1. 搭建OpenHarmony环境
   以Hi3516DV300为例，编译出OpenHarmony镜像，烧写到开发板，相关操作可参考[快速入门小型系统部分](../quick-start/quickstart-overview.md)。

   进入系统如下所示：

     **图1** OpenHarmony启动成功界面

     ![zh-cn_image_0000001218806027](figures/zh-cn_image_0000001218806027.png)

2. 挂载nfs目录，将表2中test目录下cctest可执行文件放入nfs目录

3. 执行用例
   该库采用非交叉编译时用例是通过make test执行，CMake会有相关的执行结果统计；交叉编译时无法使用该方法，因此可直接执行生成的测试文件完成测试。

   - 挂载成功后执行下列命令可列出用例所有条目：

     
     ```
     cd nfs
     ./cctest --list
     ```

     上述命令执行结果部分展示：

     
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

   - 以test-bignum条目为例，执行下列命令开始测试：

     
     ```
     ./cctest test-bignum
     ```

     测试结果如下则表示通过：

     
     ```
     Ran 13 tests.
     ```


## 将该库编译添加到OpenHarmony工程中

1. 复制库到OpenHarmony工程中
   拷贝已经能够成功交叉编译的库到OpenHarmony的third_party目录，为了不修改要移植的三方库目录下的BUILD.gn文件，再添加一层目录放置新增的gn转CMake编译适配文件，新增的文件有BUILD.gn、build_thirdparty.py、 config.gni，新增后的目录结构如下所示。

     **表3** 添加到工程后的目录结构
   
   | 名称 | 描述 |
   | -------- | -------- |
   | OpenHarmony/third_party/double-conversion/BUILD.gn | 将三方库加入工程的gn适配文件 |
   | OpenHarmony/third_party/double-conversion/build_thirdparty.py | GN调用shell命令脚本文件，由上面GN文件将相关命令传入，实现GN转CMake |
   | OpenHarmony/third_party/double-conversion/config.gni | 三方库编译配置文件，可修改该文件来配置用例是否参与构建等 |
   | OpenHarmony/third_party/double-conversion/double-conversion/ | 要移植的三方库目录 |

2. 添加gn到CMake适配文件
   - **新增的BUILD.gn文件实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony平台时只需修改路径即可**。

     
     ```
     import("config.gni")
     group("double-conversion") {
         if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
             deps = [":make"]
         }
     }
     if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
         action("make") {
             script = "//third_party/double-conversion/build_thirdparty.py"
             outputs = ["$root_out_dir/log_dc.txt"]
             exec_path = rebase_path(rebase_path("./build", ohos_third_party_dir))
             command = "rm * .* -rf && $CMAKE_TOOLS_PATH/cmake .. $CMAKE_FLAG $CMAKE_TOOLCHAIN_FLAG && make -j"
             args = [
                 "--path=$exec_path",
                 "--command=${command}"
             ]
         }
     }
     ```

   - **新增的config.gni用于配置该库，实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony时只需修改CMAKE_FLAG的配置即可。**

     
     ```
     #CMAKE_FLAG: config compile feature
     CMAKE_FLAG = "-DBUILD_TESTING=ON -DCMAKE_CXX_STANDARD=11"
   
     #toolchain：follow up-layer，depend on $ohos_build_compiler
     if (ohos_build_compiler == "clang") {
         CMAKE_TOOLCHAIN_FLAG = "-DOHOS_SYSROOT_PATH=${root_out_dir}sysroot"
     } else {
         CMAKE_TOOLCHAIN_FLAG = ""
     }
   
     #CMake tools path,no need setting if this path already joined to $PATH.
     CMAKE_TOOLS_PATH = "setting CMake tools path..."
     ```

   - **新增的build_thirdparty.py实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony时无需修改即可使用。**

     
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

   - 在配置文件中添加开关控制该库编译，默认设为关闭

     在//build/lite/ohos_var.gni文件中添加下列配置：

     
     ```
     declare_args() {
         ohos_build_thirdparty_migrated_from_fuchisa = true
      }
     ```

3. 编译构建
   手动单独构建：

   执行下列命令

   
   ```
   hb build -T //third_party/double-conversion:double-conversion
   ```

   编译成功则build目录下会生成静态库文件和测试用例
