# ArkTS Compilation Toolchain Overview

To support ArkTS application compilation, the ArkTS compilation and building SDK provides a complete compilation tool chain, which can be deployed on the orchestration tool of Hvigor compilation tasks, compile the ArkTS/TS/JS source code of your app into an ARK bytecode file (\*.abc).

During the compilation, the first phase is the syntax conversion phase, including syntax check and UI conversion. To ensure source code security, use [ArkGuard](source-obfuscation.md) to obfuscate the source code and determine whether to [customize the bytecode](customize-bytecode-during-compilation.md) before the bytecode is flushed to disks, if necessary, load and execute the customized code. After the bytecode file is generated, use [Disassembler](tool-disassembler.md) to view the content in the bytecode file. For details about the bytecode, see [Ark Bytecode Overview](arkts-bytecode-overview.md).

The ArkTS compilation toolchain provides the following functions:

1. Syntax check: checks whether the ArkTS/TS syntax is correct.

2. UI conversion: converts the UI normal form syntax of ArkTS to the standard TS syntax.

3. Source code obfuscation: Use the ArkGuard source code obfuscation tool to obfuscate the source code. You can enable this function based on service requirements.

4. Bytecode compilation: The Ark compiler compiles the Ark bytecode file (\*.abc).

5. Custom modification of Ark bytecode: provides an entry for developers to modify bytecode. This API is called before bytecode compilation and flushing.

6. Disassembly: Use the Disassembler tool to disassemble byte data into readable assembly instructions.

The following figure shows the process details.

![compilation-tool-overview](figures/compilation-tool-overview.png)
