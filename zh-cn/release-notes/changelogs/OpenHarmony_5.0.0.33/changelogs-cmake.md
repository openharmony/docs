# cmake变更说明

## cl.cmake.1 应用编译构建对不支持命令强校验

**变更原因**

cmake从3.16.5版本升级到3.28.2版本，引入了该项变更。

**变更影响**

该变更为不兼容性变更。

变更前：

应用编译构建会忽略不支持的命令参数，功能正常。

变更后：

在开发者使用不支持的命令参数（如 -v）时，应用编译构建将出现失败提示，提示内容如下：

````
CMake Error: Unknown argument -v
CMake Error: Run 'cmake --help' for all supported options.
````
**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**适配指导**

1、查询支持的命令参数

命令行执行 cmake --help 可以查看支持的命令参数合集

我们也可以在 [cmake.org](https://cmake.org/cmake/help/v3.28/manual/cmake.1.html) 查看 cmake 官方指导文档，Options 详细描述了支持的命令参数合集及其说明

2、DevEco Studio构建的项目适配，删除项目模块目录下 build-profile.json5 中 arguments 配置的不支持的参数，删除内容如下：

````
{
  "apiType": '',
  "buildOption": {
    "externalNativeOptions": {
      "path": "",
      "arguments": "-v",   // 删除该项配置中不支持的参数，如删除-v
      "cppFlags": "",
    }
  },
  ...
}
````

3、命令行构建的项目适配，删除构建命令中不支持的参数，删除内容如下：

````
{native所在目录}/build-tools/cmake/bin/cmake
-HC:{项目所在目录}/entry/src/main/cpp
-BC:{项目所在目录}/entry/.cxx/default/default/arm64-v8a
-DOHOS_ARCH=arm64-v8a
-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={项目所在目录}/entry/build/default/intermediates/cmake/default/obj/arm64-v8a
-DCMAKE_BUILD_TYPE=Debug
-DOHOS_SDK_NATIVE={native所在目录}
-DCMAKE_SYSTEM_NAME=OHOS
-DCMAKE_OHOS_ARCH_ABI=arm64-v8a
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
-DCMAKE_TOOLCHAIN_FILE={native所在目录}/build/cmake/ohos.toolchain.cmake
-GNinja
-DCMAKE_MAKE_PROGRAM={native所在目录}/build-tools/cmake/bin/ninja
--no-warn-unused-cli
-v  // 删除执行命令中不支持的参数-v
````



## cl.cmake.2 应用编译构建建议cmake_minimum_required修改为不低于3.5.0的版本

**变更原因**

cmake从3.16.5版本升级到3.28.2版本，引入了该项变更。

**变更影响**

该变更为不兼容性变更。

变更前：

开发者使用默认模板（配置为：cmake_minimum_required(VERSION 3.4.1)）时，应用编译构建正常

变更后：

开发者使用默认模板（配置为：cmake_minimum_required(VERSION 3.4.1)）时，将出现告警提示，提示内容如下：

```
CMake Deprecation Warning at CMakeLists.txt:2 (CMAKE_MINIMUM_REQUIRED):
  Compatibility with CMake < 3.5 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value or use a ...<max> suffix to tell
  CMake that the project does not need compatibility with older versions.
```

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**适配指导**

修改项目 CMakeLists.txt 中 cmake_minimum_required 配置，修改内容如下：

````
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)  // 修改为 cmake_minimum_required(VERSION 3.5.0)

project(xxx)
...
````



## cl.cmake.3 应用编译构建harA链接harB的so，导致hap包so冲突

**变更原因**

cmake从3.16.5版本升级到3.28.2版本，引入了该项变更。

**变更影响**

cmake版本升级到3.28.2之后，当某har模块（如harA）的CMakeLists.txt中链接了 ”依赖har模块（如harB）中的so” 时，此so会被打包到harA中，可能导致最终打HAP包时so版本冲突。

 **适配指导**

如果so版本冲突，请在工程级或者模块级build-profile.json5文件中buildOption下添加nativeLib/filter/select字段，根据包名、版本、产物名称等，选择打包或排除so文件到HAP产物。具体请参考[关于select的使用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-cpp-V5#section14491810432)。

````
{
  buildOption:{
    nativeLib:{
      filter:{
        select:[ // select的优先级高于excludes、pickFirsts等配置项
          {
            package: "@ohos/curl", // 包名
            version： "1.3.5", // 包版本
            include： ["libcurl.so"], // 选择打包的native产物
            exclude： ["libc++shared.so"], // 排除的native产物
          },
        ];
      }
    }
  }
}
````

