# ArkGuard源码混淆工具概述
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @zju-wyx-->
<!--SE: @xiao-peiyang; @dengxinyu-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

ArkGuard是一款源码混淆工具，提供基础混淆功能。它将代码中的变量名、函数名、类名、文件名等替换为简短无意义的标识符，增加通过阅读代码推测其功能的难度。混淆后，工程源码中的元素名称简化，有助于减小程序包的体积。


本章节介绍ArkGuard源码混淆工具的使用方法和特点，帮助开发者高效利用ArkGuard进行源码混淆，提升代码复杂度，增加逆向工程难度。

- [ArkGuard混淆原理及功能](source-obfuscation.md)：说明混淆能力范围、混淆流程机制、混淆选项和保留选项的使用方法、混淆规则的合并策略，以及混淆各功能上线的SDK版本。

- [ArkGuard混淆开启指南](source-obfuscation-guide.md)：提供实操指南，包括如何开启源码混淆功能、设置自定义混淆规则，以及如何查看混淆效果和进行报错栈还原。

- [不同包类型的源码混淆建议](source-obfuscation-practice.md)：针对不同类型的包（HAP、HAR、HSP）提供混淆策略建议。
- [ArkGuard混淆常见问题](source-obfuscation-questions.md)：总结常见的功能异常场景及其排查方法，提供典型报错案例的解决方案，帮助开发者快速定位和解决问题。
