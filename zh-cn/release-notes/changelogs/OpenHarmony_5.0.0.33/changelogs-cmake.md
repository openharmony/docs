# cmake变更说明

## cl.cmake.1 编译构建对不支持命令强校验变更

**变更原因**

由于北向开发者诉求，cmake升级到3.28.2，引入了该项变更。

**变更影响**

该变更为非兼容性变更，该变更发生后，在开发者使用不支持的命令参数（如 -v）时，将出现失败提示，提示内容如下：
````
CMake Error: Unknown argument -v
CMake Error: Run 'cmake --help' for all supported options.
````
**变更发生的版本**

从OpenHarmony SDK 5.0.0.33 / cmake 3.28.2开始。

**变更的表现**

变更前：不支持的命令参数会被忽略，编译构建功能正常。

变更后：不支持的命令参数会被强校验，出现失败提示，编译构建功能失败。

**适配指导**

1、DevEco Studio构建的项目适配，删除项目模块目录下 build-profile.json5 中 arguments 配置的不支持的参数，删除内容如下：

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

2、命令行构建的项目适配，删除构建命令中不支持的参数，删除内容如下：

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
-v  // 删除执行命令中不支持的命令参数-v
````

3、执行 cmake --help 查询支持的命令参数合集，不在该范围内的命令即视为不支持的命令参数：

```
Usage

  cmake [options] <path-to-source>
  cmake [options] <path-to-existing-build>
  cmake [options] -S <path-to-source> -B <path-to-build>

Specify a source directory to (re-)generate a build system for it in the
current working directory.  Specify an existing build directory to
re-generate its build system.

Options
  -S <path-to-source>          = Explicitly specify a source directory.
  -B <path-to-build>           = Explicitly specify a build directory.
  -C <initial-cache>           = Pre-load a script to populate the cache.
  -D <var>[:<type>]=<value>    = Create or update a cmake cache entry.
  -U <globbing_expr>           = Remove matching entries from CMake cache.
  -G <generator-name>          = Specify a build system generator.
  -T <toolset-name>            = Specify toolset name if supported by
                                 generator.
  -A <platform-name>           = Specify platform name if supported by
                                 generator.
  --toolchain <file>           = Specify toolchain file
                                 [CMAKE_TOOLCHAIN_FILE].
  --install-prefix <directory> = Specify install directory
                                 [CMAKE_INSTALL_PREFIX].
  -Wdev                        = Enable developer warnings.
  -Wno-dev                     = Suppress developer warnings.
  -Werror=dev                  = Make developer warnings errors.
  -Wno-error=dev               = Make developer warnings not errors.
  -Wdeprecated                 = Enable deprecation warnings.
  -Wno-deprecated              = Suppress deprecation warnings.
  -Werror=deprecated           = Make deprecated macro and function warnings
                                 errors.
  -Wno-error=deprecated        = Make deprecated macro and function warnings
                                 not errors.
  --preset <preset>,--preset=<preset>
                               = Specify a configure preset.
  --list-presets[=<type>]      = List available presets.
  -E                           = CMake command mode.
  -L[A][H]                     = List non-advanced cached variables.
  --fresh                      = Configure a fresh build tree, removing any
                                 existing cache file.
  --build <dir>                = Build a CMake-generated project binary tree.
  --install <dir>              = Install a CMake-generated project binary
                                 tree.
  --open <dir>                 = Open generated project in the associated
                                 application.
  -N                           = View mode only.
  -P <file>                    = Process script mode.
  --find-package               = Legacy pkg-config like mode.  Do not use.
  --graphviz=<file>            = Generate graphviz of dependencies, see
                                 CMakeGraphVizOptions.cmake for more.
  --system-information [file]  = Dump information about this system.
  --log-level=<ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
                               = Set the verbosity of messages from CMake
                                 files.  --loglevel is also accepted for
                                 backward compatibility reasons.
  --log-context                = Prepend log messages with context, if given
  --debug-trycompile           = Do not delete the try_compile build tree.
                                 Only useful on one try_compile at a time.
  --debug-output               = Put cmake in a debug mode.
  --debug-find                 = Put cmake find in a debug mode.
  --debug-find-pkg=<pkg-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of packages
  --debug-find-var=<var-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of result variables
  --trace                      = Put cmake in trace mode.
  --trace-expand               = Put cmake in trace mode with variable
                                 expansion.
  --trace-format=<human|json-v1>
                               = Set the output format of the trace.
  --trace-source=<file>        = Trace only this CMake file/module.  Multiple
                                 options allowed.
  --trace-redirect=<file>      = Redirect trace output to a file instead of
                                 stderr.
  --warn-uninitialized         = Warn about uninitialized values.
  --no-warn-unused-cli         = Don't warn about command line options.
  --check-system-vars          = Find problems with variable usage in system
                                 files.
  --compile-no-warning-as-error= Ignore COMPILE_WARNING_AS_ERROR property and
                                 CMAKE_COMPILE_WARNING_AS_ERROR variable.
  --profiling-format=<fmt>     = Output data for profiling CMake scripts.
                                 Supported formats: google-trace
  --profiling-output=<file>    = Select an output path for the profiling data
                                 enabled through --profiling-format.
  -h,-H,--help,-help,-usage,/? = Print usage information and exit.
  --version,-version,/V [<file>]
                               = Print version number and exit.
  --help <keyword> [<file>]    = Print help for one keyword and exit.
  --help-full [<file>]         = Print all help manuals and exit.
  --help-manual <man> [<file>] = Print one help manual and exit.
  --help-manual-list [<file>]  = List help manuals available and exit.
  --help-command <cmd> [<file>]= Print help for one command and exit.
  --help-command-list [<file>] = List commands with help available and exit.
  --help-commands [<file>]     = Print cmake-commands manual and exit.
  --help-module <mod> [<file>] = Print help for one module and exit.
  --help-module-list [<file>]  = List modules with help available and exit.
  --help-modules [<file>]      = Print cmake-modules manual and exit.
  --help-policy <cmp> [<file>] = Print help for one policy and exit.
  --help-policy-list [<file>]  = List policies with help available and exit.
  --help-policies [<file>]     = Print cmake-policies manual and exit.
  --help-property <prop> [<file>]
                               = Print help for one property and exit.
  --help-property-list [<file>]= List properties with help available and
                                 exit.
  --help-properties [<file>]   = Print cmake-properties manual and exit.
  --help-variable var [<file>] = Print help for one variable and exit.
  --help-variable-list [<file>]= List variables with help available and exit.
  --help-variables [<file>]    = Print cmake-variables manual and exit.
```



## cl.cmake.2 编译构建出现cmake < 3.5告警变更

**变更原因**

由于北向开发者诉求，cmake升级到3.28.2，引入了该项变更。

**变更影响**

该变更为非兼容性变更，该变更发生后，在开发者使用默认模板（配置为：cmake_minimum_required(VERSION 3.4.1)）时，将出现告警提示，提示内容如下：

```
CMake Deprecation Warning at CMakeLists.txt:2 (CMAKE_MINIMUM_REQUIRED):
  Compatibility with CMake < 3.5 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value or use a ...<max> suffix to tell
  CMake that the project does not need compatibility with older versions.
```

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33 / cmake 3.28.2开始。

**变更的表现**

变更前：在开发者使用默认模板（配置为：cmake_minimum_required(VERSION 3.4.1)）时，编译构建功能正常。

变更后：在开发者使用默认模板（配置为：cmake_minimum_required(VERSION 3.4.1)）时，出现告警提示，编译构建功能正常。

**适配指导**

修改项目 CMakeLists.txt 中 cmake_minimum_required 配置，修改内容如下：

````
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)  // 修改为 cmake_minimum_required(VERSION 3.5.0)

project(xxx)
...
````



