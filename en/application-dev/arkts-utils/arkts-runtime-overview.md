# Overview of ArkTS Runtime
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @guobingbing3-->
<!--Designer: @xwcai98-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

ArkTS Runtime is the default language runtime for applications on OpenHarmony. It supports the bytecode of ArkTS, TS, and JS languages and related standard libraries. It provides the interpreter, Ahead-of-Time (AOT), and Just-In-Time (JIT) for efficient execution, and implements comprehensive cross-language APIs via [Node-API](../napi/napi-introduction.md), supporting multi-language hybrid development.

ArkTS Runtime is primarily composed of four subsystems:

- **Core subsystem**: consists of the foundational runtime libraries that are language-agnostic, including the File component that carries bytecode, the Tooling component that supports Debugger functionality, and the Base library component responsible for adapting system calls.

- **Execution subsystem**: includes the interpreter for executing Ark bytecode, fast-path inline caches, and [file-based modular management for runtime execution](module-principle.md).

- **Compiler subsystem**: includes the stub compiler, an IR-based compilation optimization framework, an AOT static compiler, and an experimental JIT dynamic compiler.

- **Runtime subsystem**: includes the following modules related to the execution of ArkTS/TS/JS:

  - Memory management: object allocator and [garbage collector](gc-introduction.md) (CMS-GC and Partial-Compressing-GC for concurrent marking and partial memory compression)

  - Analysis tools: DFX, and profiling tools for CPU and heap analysis

  - Concurrency management: Ark bytecode file manager in the actor model

  - Standard libraries: standard libraries defined by ECMAScript, efficient container libraries, and object models
  
  - Other: asynchronous work queues, and Node-API that interact with C++
