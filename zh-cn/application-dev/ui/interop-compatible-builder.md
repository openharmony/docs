# ArkTS1.2使用ArkTS1.1全局自定义构建函数

## 概述

全局自定义构建函数互操作适用于[ArkTS1.2互操作](../quick-start/arkts-interop-overview.md)中使用全局自定义构建函数的场景。


## 架构原理

在互操作场景下，将ArkTS1.1全局自定义构建函数的调用转换为占位组件，链接ArkTS1.2和ArkTS1.1的UI节点，构建完整的UI界面。


## 设计理念

全局自定义构建函数互操作适用于主模块使用ArkTS1.2、子模块使用ArkTS1.1的场景。

- 渐进式迁移：逐步将ArkTS1.1组件迁移到新版本。

- 使用旧全局自定义构建函数：使用稳定的ArkTS1.1全局自定义构建函数。

## 参数传递规则

- 遵循语言[交互基本原则](../quick-start/arkts-interop-overview.md#交互基本原则)的规范。

- 遵循ArkTS1.1自定义构建函数[参数传递规则](../quick-start/arkts-builder.md#参数传递规则)。

- ArkTS1.1全局自定义构建函数的参数最多不超过10个。

## 开发场景

### 在ArkTS1.2中引用ArkTS1.1的全局自定义构建函数显示UI

通过在ArkTS1.2中引用ArkTS1.1的全局自定义构建函数来显示“Hello World!”。

示例如下：

- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出全局自定义构建函数。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

@Builder
export function showTextBuilder() {
  Text('Hello World!')
    .fontSize(30)
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1全局自定义构建函数。

```TypeScript
'use static';

// entry/src/main/ets/pages/MainPage.ets
import { Entry, Component, Column } from '@ohos.arkui.component';

import { showTextBuilder } from 'har1_1';

@Entry
@Component
struct MainPage {
  build() {
    Column() {
      // 无需显式使用占位组件API，框架会自动处理
      showTextBuilder()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F1F3F5')
  }
}
```

### 完整示例结构

```text
project/
├── entry/          # ArkTS1.2主模块
│   └── src/
│       └── main/
│           └── ets/
│               └── pages/
│                   └── MainPage.ets
│
└── har1_1/         # ArkTS1.1子模块
    └── src/
        └── main/
            └── ets/
                └── components/
                    └── MainPage.ets
```
