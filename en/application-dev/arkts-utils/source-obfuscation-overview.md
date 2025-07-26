# Overview of ArkGuard for Source Code Obfuscation

ArkGuard is a tool designed for source code obfuscation. It converts variable names, function names, class names, and file names into short, meaningless identifiers, making it more difficult to infer the purpose of the code through inspection. In addition, the shortened names in the obfuscated source code sometimes help reduce the package size. 

This section describes how to use ArkGuard for source code obfuscation. It aims to assist you in efficiently applying obfuscation to your source code, thereby increasing its complexity and making reverse engineering more challenging.

- [ArkGuard Principles and Capabilities for Source Code Obfuscation](source-obfuscation.md): describes the scope of obfuscation capabilities, obfuscation process, usage of obfuscation options and retention options, strategies for merging obfuscation rules, and SDK versions where obfuscation features are available.

- [Using ArkGuard for Source Code Obfuscation](source-obfuscation-guide.md): offers step-by-step instructions on enabling source code obfuscation, setting custom obfuscation rules, and viewing obfuscation effects. It also explains how to perform stack trace deobfuscation in case of errors.

- [Package-specific Source Code Obfuscation Recommendations](source-obfuscation-practice.md): provides tailored obfuscation strategies for different package types, such as HAP, HAR, and HSP.
- [Common Issues with ArkGuard in Source Code Obfuscation](source-obfuscation-questions.md): summarizes common abnormal scenarios encountered during code obfuscation, along with troubleshooting methods and solutions for typical error cases. It aims to help you quickly identify and resolve problems that arise during code obfuscation.
