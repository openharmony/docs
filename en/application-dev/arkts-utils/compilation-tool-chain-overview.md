# Overview of the ArkTS Compilation Toolchain

To support the compilation of ArkTS applications, the ArkTS application SDK offers a comprehensive toolchain. This toolchain is integrated into the [Hvigor](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor) task orchestration tool to compile ArkTS/TS/JS source code into Ark bytecode files (*.abc).

The toolchain begins with syntax transformation, including syntax check and UI transformation, during compilation process. To ensure source code security, the toolchain uses [ArkGuard](source-obfuscation.md) to obfuscate the source code. Before the bytecode is written to disk, the toolchain checks whether [custom bytecode modifications](customize-bytecode-during-compilation.md) are required. If modifications are required, custom modification code is loaded and executed. After generating the bytecode file, the [Disassembler](tool-disassembler.md) tool is used to inspect the file content. For details about the bytecode, see [Ark Bytecode File Format](arkts-bytecode-file-format.md).

The ArkTS compilation toolchain provides the following functions:

1. Syntax check: checks whether the ArkTS/TS syntax is correct.

2. UI transformation: converts ArkTS UI paradigm syntax to standard TS syntax.

3. Source code obfuscation: uses the ArkGuard tool to obfuscate the source code. You can enable this function based on service requirements.

4. Bytecode compilation: The Ark compiler generates Ark bytecode files (\*.abc).

5. Custom bytecode modification: provides an entry for you to modify bytecode before it is written to disk.

6. Disassembly: uses the Disassembler tool to convert bytecode into human-readable assembly instructions.

The following figure shows how the ArkTS compilation toolchain builds a HAP.

![compilation-tool-overview](figures/compilation-tool-overview.png)
