# ArkTS Terminology

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @vigavi-->
<!--Designer: @vigavi-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-07-28T07:29:11.176Z pushedAt=2026-07-30T08:48:47.384Z -->

## A

### Ark Bytecode

The binary product generated after ArkTS/TS/JS source code is compiled by the compilation toolchain. The file extension is .abc, and it is loaded and executed by the ArkTS runtime on the device side.

### ArkGuard

ArkGuard is a code obfuscator in the ArkTS compilation toolchain, supporting both source code obfuscation and bytecode obfuscation modes. It transforms ArkTS/TS/JS code into a functionally equivalent but difficult-to-read-and-understand form, increasing the difficulty of reverse engineering.

### ASON

A serialization and deserialization tool for Sendable objects provided by ArkTS. Its functionality is similar to how JSON handles JS objects, supporting mutual conversion between JSON strings and Sendable objects. The generated Sendable objects can be passed between concurrent tasks with high performance.

## E

### es2abc

The compiler that compiles ArkTS source code into ArkTS bytecode (abc files). It is responsible for compiling ArkTS source code into Ark Bytecode and is one of the core components of the ArkCompiler compilation toolchain.

## S

### Sendable

A shareable object mechanism proposed by ArkTS that supports efficient sharing of objects between concurrent instances through reference passing, avoiding the deep copy overhead of traditional structured cloning.