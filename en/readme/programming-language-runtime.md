# Programming Language Runtime<a name="EN-US_TOPIC_0000001124628397"></a>

## Introduction<a name="section15963162310012"></a>

This subsystem provides the compilation and execution environment for programs developed with JavaScript, and C/C++, basic libraries that support the runtime, and the runtime-associated APIs, compilers, and auxiliary tools. Modules in this subsystem are classified based on the currently supported programming languages: JavaScript, and C/C++. Each module can be compiled independently and can be combined and separated based on development scenarios.

**Figure  1**  Subsystem architecture<a name="fig4166312527"></a>  
![](figures/subsystem-architecture-1.png "subsystem-architecture-1")

This subsystem consists of the runtime, libraries, and compilers that support the running of  JavaScript, and C/C++ programs, and provides the basic libraries, API , JavaScript engine capability, and a toolchain that supports language compilation.

## Directory Structure<a name="section971210485617"></a>

```
/prebuilts/mingw-w64/ohos/linux-x86_64     # cross-compilation toolchain for Linux platform
    └── clang-mingw
        ├── bin
        ├── lib
        ├── libexec
        ├── NOTICE
        ├── share
        └── x86_64-w64-mingw32
```

## Constraints<a name="section119744591305"></a>

1.  You are not allowed to add or modify the APIs without permission.
2.  The implementation of the JavaScript engine is restricted by the subsystem. There is no configuration item for external systems.

## Usage<a name="section1312121216216"></a>

Basic language capabilities are supported through library files. Some capabilities are integrated into Native, and JavaScript SDKs and integrated into DevEco Studio releases. For details about the usage, see the readme file of each module.

The following list shows the repositories of third-party software and precompilation toolchains that are referenced.

[/third\_party/boost](https://gitee.com/openharmony/third_party_boost)

[/third\_party/quickjs](https://gitee.com/openharmony/third_party_quickjs)

[/third\_party/jerryscript](https://gitee.com/openharmony/third_party_jerryscript)

[/third\_party/mingw-w64](https://gitee.com/openharmony/third_party_mingw-w64)

## Repositories Involved<a name="section1371113476307"></a>

**Programming language runtime subsystem**
