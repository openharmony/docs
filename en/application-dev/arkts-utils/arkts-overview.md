# Introduction to ArkTS

ArkTS is the official high-level language for OpenHarmony application development.

ArkTS provides capabilities such as [declarative UI paradigm](../quick-start/arkts-declarative-ui-description.md), [state management](../quick-start/arkts-state-management-overview.md), and [rendering control](../quick-start/arkts-rendering-control-overview.md), enabling developers to develop applications in a simpler and more natural manner.

ArkTS is further extended based on the [TypeScript](https://www.typescriptlang.org/) (TS) ecosystem to maintain the basic style of TS. In addition, ArkTS enhances static check and analysis in the development phase through standard definitions, improving code robustness and program execution stability and performance. For details about the differences between TypeScript and ArkTS, see [TypeScript to ArkTS Cookbook](../quick-start/typescript-to-arkts-migration-guide.md). ArkTS also supports efficient interoperability with TS/JavaScript (JS).

The ArkTS basic class library and container class library enhance basic language functions and provide capabilities such as [high-precision floating-point operation](../reference/apis-arkts/js-apis-arkts-decimal.md), [binary buffer](buffer.md), [XML generation, parsing, and conversion](xml-overview.md), and multiple container libraries, helps developers simplify development and improve development efficiency.

To address the limited support for TS/JS concurrency, ArkTS enhances the concurrent programming APIs and capabilities by providing [TaskPool](taskpool-introduction.md) and [Worker](worker-introduction.md). Two concurrent APIs are provided for developers to choose. In addition, ArkTS further proposes the concept of Sendable to support the reference transfer of objects between concurrent instances, improving the communication performance of ArkTS objects between concurrent instances.

ArkCompiler supports the compilation and running of ArkTS, TS, and JS. Currently, ArkCompiler consists of the ArkTS compilation toolchain and ArkTS runtime. The ArkTS compiler is responsible for compiling the high-level language into an ARK bytecode file (\*.abc) on the development side, and the ArkTS runtime is responsible for running the bytecode file on the device side to execute the program logic.

ArkTS will continue to accommodate ever-changing app development and running requirements, and gradually provides more features, such as enhanced concurrency, improved system, and distributed development paradigm.
