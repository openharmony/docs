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
- 了解新的并发特性和使用方法：[并发特性变更](./arkts-v1.1-v1.2-concurrency-rules.md)。
- 了解与其他系统交互的规则变更：[ArkTS互操作规则变更](./arkts-v1.1-v1.2-interop-rules.md)。
- 了解builtin的语法和规则变更：[builtin规则变更](./arkts-v1.1-v1.2-builtin-rules.md)。

## ArkTS1.2与ArkTS1.1文件区分方式

ArkTS1.2包含已有的ArkTS1.1特性和新引入的静态类型模式，使用静态类型特性的代码文件通过在文件头增加"use static"导语进行说明。ArkTS语言版本号与"use static"导语是两个维度的配置。"use static"表示静态模式，后续ArkTS版本升级会一直带静态类型特性，文件内"use static"导语可保持不变，无需修改适配。

### 约束限制

- ArkTS1.2静态类型源码文件和声明文件均需在首行增加"use static"，否则默认为ArkTS1.1文件。
- "use static"必须位于文件首行，即使存在import语句、文件注释等，也一样位于这些之前的文件首行。
- "use static"是一个字面量表达式，所以字母大小写敏感，建议与"use strict"一致使用双引号形式。
```typescript
"use static"; // 位于首行，import语句前
import { hilog } from '@kit.PerformanceAnalysisKit';
```
```typescript
"use static"; // 位于首行，文件注释前
// 这是一行注释
import { hilog } from '@kit.PerformanceAnalysisKit';
```