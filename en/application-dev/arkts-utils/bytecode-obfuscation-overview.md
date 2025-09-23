# Overview of ArkGuard for Bytecode Obfuscation
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao; @Valkisop_-->
<!--Designer: @hufeng20-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

Since API version 20, ArkGuard provides the basic bytecode obfuscation capability to convert function names, class names, and file names in code into short and meaningless names, making it more difficult to infer the purpose of the code by reading the code. In addition, the shortened names in the obfuscated bytecode sometimes help reduce the package size.

This section describes how to use ArkGuard. It aims to assist you in efficiently applying obfuscation to your bytecode, thereby increasing its complexity and making reverse engineering more challenging.

Compared with source code obfuscation, bytecode obfuscation targets bytecode files.

- [ArkGuard Principles and Capabilities for Bytecode Obfuscation](bytecode-obfuscation.md): describes the scope of obfuscation capabilities (including default obfuscation features), obfuscation process, usage of various obfuscate and keep options, and strategies for merging obfuscation rules. It also discusses the limitations of ArkGuard in different language environments.

- [Using ArkGuard for Bytecode Obfuscation](bytecode-obfuscation-guide.md): offers step-by-step instructions on enabling bytecode obfuscation, setting custom obfuscation rules, and viewing obfuscation effects. It also explains how to perform stack trace deobfuscation in case of errors.

- [Package-specific Bytecode Obfuscation Recommendations](bytecode-obfuscation-practice.md): provides tailored obfuscation strategies for different package types, such as HAP, HAR, and HSP.

- [Common Issues with ArkGuard in Bytecode Obfuscation](bytecode-obfuscation-questions.md): describes the [differences between bytecode obfuscation and source code obfuscation](bytecode-obfuscation-questions.md#differences-between-bytecode-obfuscation-and-source-code-obfuscation), summarizes common issues encountered during obfuscation, along with troubleshooting methods and solutions for typical error cases. It aims to help you quickly identify and resolve problems that arise during obfuscation.
