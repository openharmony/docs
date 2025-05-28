# ArkTS1.2概述

## 介绍

ArkTS1.2版本引入了多项重要特性，例如：
- 静态类型系统。
- 对象天然共享特性，不再依赖Sendable特性，无需添加@Sendable装饰器。
- 互操作特性，提供ArkTS1.2和ArkTS1.1以及TS/JS代码的交互能力。


## 规范指引

详细的规范文档请参考：[ArkTS1.2规范](https://gitee.com/openharmony/arkcompiler_runtime_core/releases)

## ArkTS 迁移指南

为帮助开发者顺利迁移到ArkTS1.2，特提供以下迁移指南。

- 了解ArkTS1.2的基础语法和规则变更：[ArkTS基础规则变更](./arkts-v1.1-v1.2-migration-rules.md)。
- 了解新的并发特性和使用方法：[并发特性变更](./ArkTSConcurrencyRules1.2.md)。
- 了解与其他系统交互的规则变更：[ArkTS互操作规则变更](./arkts-v1.1-v1.2-interop-rules.md)。