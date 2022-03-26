# ARK Runtime Subsystem<a name="EN-US_TOPIC_0000001138852894"></a>

## Introduction<a name="section11660541593"></a>

ARK is a unified programming platform developed. Its key components include a compiler, toolchain, and runtime. ARK supports compilation and execution of high-level programming languages on the multiple hardware platform and accelerates the execution of the OpenHarmony operating system and its applications and services on mobile phones, PCs, tablets, TVs, automobiles, and smart wearables. The ARK-JS open sourced this time provides the capability of compiling and running the JavaScript \(JS\) language on the standard system of OpenHarmony.

The ARK-JS consists of two parts: JS compiler toolchain and JS runtime. The JS compiler toolchain compiles JS source code into ARK bytecodes. The JS runtime executes the generated ARK bytecodes. Unless otherwise specified, bytecodes refer to ARK bytecodes in this document.

The following figure shows the architecture of the JS compiler toolchain.

![](figures/en-us_image_ark_frontend.png)

The JS front-end compiler parses the JS source code into an abstract syntax tree \(AST\), which is processed by the AST transformer, bytecode generator, and register allocator. The native emiter generates the ARK bytecode file \(.abc\).

The following figure shows the JS runtime architecture.

![](figures/en-us_image_ark_runtime.png)

ARK-JS Runtime runs ARK bytecode files to implement JS semantic logic.

ARK-JS Runtime consists of the following:

-   Core Runtime

    Core Runtime consists of basic language-irrelevant runtime libraries, including ARK File, Tooling, and ARK Base. ARK File provides bytecodes. Tooling supports Debugger. ARK Base is responsible for implementing system calls.

-   Execution Engine

    The Execution Engine consists of an interpreter that executes bytecodes, Inline Caches that store hidden classes, and Profiler that analyzes and records runtime types.

-   ECMAScript Runtime

    ECMAScript Runtime consists of the JS object allocator, garbage collector \(GC\), and an internal library that supports ECMAScript specifications.

-   ARK Foreign Function Interface \(AFFI\)

    The AFFI provides a C++ function interface for ARK-JS runtime.


## Directory Structure<a name="section161941989596"></a>

```
/ark
├── js_runtime       # JS runtime module
├── runtime_core     # Runtime common module
└── ts2abc           # JS front-end tool
```

## Usage Guide<a name="section18393638195820"></a>

[ARK-Runtime-Usage-Guide](https://gitee.com/openharmony/ark_js_runtime/blob/master/docs/ARK-Runtime-Usage-Guide.md)

## Repositories Involved<a name="section1371113476307"></a>

[ark\_runtime\_core](https://gitee.com/openharmony/ark_runtime_core)

[ark\_js\_runtime](https://gitee.com/openharmony/ark_js_runtime)

[ark\_ts2abc](https://gitee.com/openharmony/ark_ts2abc)
