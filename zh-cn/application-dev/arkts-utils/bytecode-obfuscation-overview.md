# ArkGuard字节码混淆工具概述
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao; @Valkisop_-->
<!--Designer: @hufeng20-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

从API version 20开始，ArkGuard提供了基础字节码混淆能力，将代码中的函数名、类名、文件名等名字变成简短无意义的名字，提高通过阅读代码猜测其用途的难度。由于混淆后的工程源码中元素名称缩短，有时也可以通过混淆来降低包大小。

本章节详细介绍了ArkGuard字节码混淆工具的使用方法和特点，旨在帮助开发者高效地利用ArkGuard进行字节码混淆，从而提升代码的复杂度，增加逆向工程的难度。

相比源码混淆，字节码混淆的混淆对象是字节码文件。

- [ArkGuard字节码混淆原理及功能](bytecode-obfuscation.md)：说明混淆能力范围（包括默认混淆能力）、混淆流程机制以及各种混淆选项和保留选项的使用方法、混淆规则的合并策略。另外，介绍了ArkGuard在语言环境下的局限性。

- [ArkGuard字节码混淆开启指南](bytecode-obfuscation-guide.md)：提供实操指南，包括如何开启字节码混淆功能、设置自定义混淆规则，以及如何查看混淆效果和进行报错栈还原。

- [不同包类型的字节码混淆建议](bytecode-obfuscation-practice.md)：针对不同类型的包（HAP、HAR、HSP）提供混淆策略建议。

- [ArkGuard字节码混淆常见问题](bytecode-obfuscation-questions.md)：说明[字节码混淆与源码混淆差异](bytecode-obfuscation-questions.md#字节码混淆与源码混淆差异)，总结常见的功能异常情况及其排查方法，并提供典型报错案例的解决方案，帮助开发者快速定位和解决混淆过程中遇到的问题。
