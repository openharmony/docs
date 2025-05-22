# Overview of ArkGuard

ArkGuard is a tool designed for source code obfuscation. It converts variable names, function names, class names, and file names into short, meaningless names, making it more difficult to infer the purpose of the code through inspection. In addition, the shortened names in the obfuscated source code sometimes help reduce the package size.
This section describes how to use ArkGuard. It aims to assist you in efficiently applying obfuscation to your source code, thereby increasing its complexity and making reverse engineering more challenging.

- [Obfuscation Principles and Capabilities of ArkGuard](source-obfuscation.md): describes the scope of obfuscation capabilities (including default obfuscation features), obfuscation process, usage of various obfuscate and keep options, and strategies for merging obfuscation rules. It also discusses the limitations of ArkGuard in different language environments.

- [Using ArkGuard for Obfuscation](source-obfuscation-guide.md): offers step-by-step instructions on enabling code obfuscation, setting custom obfuscation rules, and viewing obfuscation effects. It also explains how to perform stack trace deobfuscation in case of errors.

- [Package-specific Obfuscation Recommendations](source-obfuscation-practice.md): provides tailored obfuscation strategies for different package types, such as HAP, HAR, and HSP.
- [Common Issues with ArkGuard](source-obfuscation-questions.md): summarizes common issues encountered during code obfuscation, along with troubleshooting methods and solutions for typical error cases. It aims to help you quickly identify and resolve problems that arise during code obfuscation.
