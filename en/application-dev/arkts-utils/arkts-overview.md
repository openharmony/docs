# Introduction to ArkTS

ArkTS is the official high-level language for OpenHarmony application development.

ArkTS provides capabilities such as [declarative UI paradigm](../quick-start/arkts-declarative-ui-description.md), [state management](../quick-start/arkts-state-management-overview.md), and [rendering control](../quick-start/arkts-rendering-control-overview.md), helping you create applications in a more concise and natural manner.

Built on the [TypeScript](https://www.typescriptlang.org/) (TS) ecosystem, ArkTS extends its functionality while maintaining the basic style of TS. It enhances static check and analysis during development through standardized definitions, improving code robustness and achieving better program execution stability and performance. For details about the differences compared with standard TS, see [TypeScript to ArkTS Cookbook](../quick-start/typescript-to-arkts-migration-guide.md). ArkTS also supports efficient interoperability with TS/JavaScript (JS).

The ArkTS common and container libraries enhance the language's basic functionalities, offering capabilities such as [high-precision floating-point operations](../reference/apis-arkts/js-apis-arkts-decimal.md), [binary buffers](buffer.md), and [XML generation, parsing, and conversion](xml-overview.md), as well as various container libraries. These features help you simplify your work and improve development efficiency.

To address the limited concurrency support in TS/JS, ArkTS enhances concurrency programming APIs and capabilities. It provides two concurrency APIs, [TaskPool](taskpool-introduction.md) and [Worker](worker-introduction.md). In addition, ArkTS introduces the concept of Sendable to support object reference passing between concurrent instances, improving communication performance of ArkTS objects in concurrent environments.

ArkCompiler supports the compilation and execution of ArkTS, TS, and JS. Currently, it is divided into two main parts: the ArkTS compilation toolchain and the ArkTS runtime. The ArkTS compilation toolchain is responsible for compiling high-level languages into Ark bytecode files (\*.abc) on the development side, whereas the ArkTS runtime runs the bytecode files on the device side to execute the program logic.

In the future, ArkTS will continue to evolve based on application development and runtime requirements, gradually introducing more features such as enhanced concurrency capabilities, enhanced system types, and distributed development paradigms.
