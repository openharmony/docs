# Programming Language Runtime

## Introduction

The programming language runtime subsystem provides the compilation and execution environment for programs developed with JavaScript and C/C++. It also provides basic libraries that support the runtime, and runtime-associated APIs, compilers, and auxiliary tools. Modules in this subsystem are classified based on the currently supported programming languages: JavaScript and C/C++. Each module can be compiled independently and can be combined and separated based on development scenarios.

This subsystem consists of the runtime, libraries, and compilers that support the running of  JavaScript and C/C++ programs, and provides the basic libraries, APIs, JavaScript engine, and a toolchain that supports language compilation.

**Figure  1**  Subsystem architecture

![](figures/subsystem-architecture-1.png "subsystem-architecture-1")

## Directory Structure

```
/prebuilts/mingw-w64/ohos/linux-x86_64     # Cross-compilation toolchain for Linux platform
    └── clang-mingw
        ├── bin
        ├── lib
        ├── libexec
        ├── NOTICE
        ├── share
        └── x86_64-w64-mingw32
```

## Constraints

1.  You are not allowed to add or modify the APIs without permission.
2.  The implementation of the JavaScript engine is restricted by the subsystem. There is no configuration item for external systems.

## Usage

Basic language capabilities are supported through library files. Some capabilities are integrated into Native, and JavaScript SDKs and integrated into DevEco Studio releases. For details about the usage, see the readme file of each module.

## Repositories Involved

The following list shows the repositories of third-party software and precompilation toolchains that are referenced:

[/third\_party/jerryscript](https://gitee.com/openharmony/third_party_jerryscript)

[/third\_party/mingw-w64](https://gitee.com/openharmony/third_party_mingw-w64)