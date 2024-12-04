# ArkTS Runtime Overview

The ArkTS runtime is the default language runtime of applications on OpenHarmony. It runs the bytecode and related standard libraries of ArkTS, TS, and JS, and supports the interpreter, AOT, and JIT for efficient execution, in addition, it provides a complete cross-language API implementation [Node-API](../napi/napi-introduction.md) and supports multi-language development.

ArkCompiler JS Runtime consists of four subsystems:

- The core subsystem consists of basic language-irrelevant runtime libraries, including File, Tooling, and Base. File provides bytecode. Tooling supports Debugger. Base implements system calls.

- Execution Subsystem: contains the interpreter for executing Ark bytecode, fast path inline cache, and [modular file management and running](module-principle.md).

- Compiler subsystem: includes the stub compiler, IR-based compilation optimization framework, AOT static compiler, and JIT dynamic compiler (in the experiment).

- Runtime subsystem: includes the following modules related to the running of ArkTS, TS, and JS:

  - Memory management: object allocator and [garbage collector](gc-introduction.md) (CMS-GC and Partial-Compressing-GC for concurrent marking and partial memory compression)

  - Analysis tools: DFX tool and CPU and heap profiling tool

  - Concurrency management: abc file manager in the actor concurrency model

  - Standard library: standard library defined by ECMAScript, efficient container library, and object model
  
  - Others: asynchronous work queues and Node-APIs that interact with C++.
