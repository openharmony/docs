# 使用命令行CMake构建NDK工程


在很多复杂应用工程中，C++代码工程是通过CMake等构建系统以命令行方式来编译构建的，接下来介绍如何把已有的CMake工程切换到OpenHarmony工具链中，从而使用命令行CMake构建该工程。


## 下载NDK开发包

1. 推荐使用OpenHarmony正式发布的SDK包。下载链接请从OpenHarmony正式发布版本的[版本说明](../../release-notes/OpenHarmony-v4.0-release.md)中获取，在Release Notes“从站点镜像获取”章节下载。

2. 从DevEco Studio的OpenHarmony SDK Manager中下载。


## 解压NDK开发包

下载完成后，将压缩包放入创建好的文件夹下解压，解压完成效果如下图所示：

![zh-cn_image_0000001726080989](figures/zh-cn_image_0000001726080989.png)

配置Linux下的环境。如果只是在IDE中使用，跳过以下步骤：

1. 将NDK自带的CMake编译工具添加到环境变量中。
   ```
   #打开.bashrc文件
   vim ~/.bashrc
   #在文件最后添加CMake路径，具体路径用实际放置SDK路径代替
   export PATH=~/ohos-sdk/ohos-sdk/linux/native/build-tools/cmake/bin:$PATH
   #在命令行执行source ~/.bashrc使环境变量生效
   source ~/.bashrc
   ```

2. 查看CMake默认路径。
   ```
   #在命令行输入which命令查询当前CMake所在路径
   which cmake
   #结果路径与.bashrc中设置一致
   ~/ohos-sdk/ohos-sdk/linux/native/build-tools/cmake/bin/cmake
   ```


## 使用NDK开发包编译Native程序

应用开发者可以通过NDK开发包快速的开发出Native动态库、静态库与可执行文件。NDK开发包提供CMake编译构建工具脚本，下面通过编写一个C/C++ demo工程来演示适配过程。


### demo工程内容

下面是一个CMake的demo工程内容，此工程包含两个目录，include目录包含此库的头文件，src目录包含全部源码；src目录包含两个文件，sum.cpp的算法文件，以及main.cpp的调用算法的主入口文件，目标是编译成一个可执行程序，以及一个算法动态库。

**demo目录图**

```
demo
  ├── CMakeLists.txt
  ├── include
       └── sum.h
  └── src
       ├── CMakeLists.txt
       ├── sum.cpp
       └── main.cpp
```

**根目录CMakeLists.txt内容**

```
# 指定CMake的最小版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

# 工程名称，这里我们就叫HELLO
PROJECT(HELLO)

#添加一个子目录并构建该子目录。
ADD_SUBDIRECTORY(src)
```

**内部CMakeLists.txt内容**

```
SET(LIBHELLO_SRC hello.cpp)

# 设置编译参数
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")   
 
# 设置链接参数，具体参数可以忽略，纯粹为了举例
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--emit-relocs --verbose")    

# 添加一个libsum动态库目标，编译成功会生成一个libsum.so
ADD_LIBRARY(sum SHARED sum.cpp)

# 生成可执行程序，添加一个Hello的可执行程序目标，编译成功会生成一个Hello可执行程序
ADD_EXECUTABLE(Hello ${LIBHELLO_SRC})

# 指定Hello目标include目录路径
TARGET_INCLUDE_DIRECTORIES(Hello PUBLIC ../include)

# 指定Hello目标需要链接的库名字
TARGET_LINK_LIBRARIES(Hello PUBLIC sum)
```

**源码内容**

hello.cpp源码

```
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

sum.h源码

```
int sum(int a, int b);
```

sum.cpp源码

```
#include <iostream>
    
int sum(int a, int b)
{
    return a + b;
}
```


### 编译构建demo工程

在工程目录下，创建build目录，用来放置CMake构建时产生的中间文件。注意: ohos-sdk是下载下来的SDK的根目录，开发者需要自行替换成实际的下载目录。

1. 采用OHOS_STL=c++_shared动态链接c++库方式构建工程，如不指定，默认采用c++_shared。

   ```
    >mkdir build && cd build
    >cmake -DOHOS_STL=c++_shared -DOHOS_ARCH=armeabi-v7a -DOHOS_PLATFORM=OHOS -DCMAKE_TOOLCHAIN_FILE={ohos-sdk}/linux/native/build/cmake/ohos.toolchain.cmake ..
    >cmake --build .
   ```

2. 采用OHOS_STL=c++_static静态链接c++库方式构建工程。

   ```
    >mkdir build && cd build
    >cmake -DOHOS_STL=c++_static -DOHOS_ARCH=armeabi-v7a -DOHOS_PLATFORM=OHOS -DCMAKE_TOOLCHAIN_FILE={ohos-sdk}/linux/native/build/cmake/ohos.toolchain.cmake ..
    >cmake --build .
   ```

   命令中，OHOS_ARCH与OHOS_PLATFORM两个变量最终会生成clang++的--target命令参数，在此例子中就是--target=arm-linux-ohos --march=armv7a两个参数；CMAKE_TOOLCHAIN_FILE指定了toolchian文件，在此文件中默认给clang++设置了--sysroot={ndk_sysroot目录}，告诉编译器查找系统头文件的根目录。
