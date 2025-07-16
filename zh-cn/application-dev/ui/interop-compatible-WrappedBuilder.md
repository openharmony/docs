# ArkTS1.2使用ArkTS1.1 WrappedBuilder对象

## 概述

WrappedBuilder对象互操作适用于[ArkTS1.2互操作](../quick-start/arkts-interop-overview.md)中使用WrappedBuilder对象的场景。

## 架构原理

在互操作场景下，[compatibleWrappedBuilder方法](../reference/apis-arkui/arkui-ts/ts-interop-compatible-WrappedBuilder.md)将ArkTS1.1的WrappedBuilder对象转换为占位组件，从而链接ArkTS1.2和ArkTS1.1的UI节点，构建完整的UI界面。


## 设计理念

WrappedBuilder对象互操作适用于主模块使用ArkTS1.2、子模块使用ArkTS1.1的场景。

- 渐进式迁移：逐步将ArkTS1.1组件迁移到新版本。

- 使用旧WrappedBuilder对象：使用稳定的ArkTS1.1 WrappedBuilder对象。

## 限制条件

- 遵循语言[交互基本原则](../quick-start/arkts-interop-overview.md#交互基本原则)的规范。

- 遵循ArkTS1.1 WrappedBuilder对象的使用[限制条件](../quick-start/arkts-wrapBuilder.md#限制条件)。

- ArkTS1.1 WrappedBuilder对象builder属性方法的参数最多不超过10个。

## 开发场景

### 在ArkTS1.2引用ArkTS1.1中的WrappedBuilder对象，并通过引用传递参数

通过在ArkTS1.2中引用ArkTS1.1的WrappedBuilder对象来显示“Hello World!”。

示例如下：

- 创建ArkTS1.1子模块`har1_1`，在`har1_1/src/main/ets/components`目录创建并导出WrappedBuilder对象。

```TypeScript
// har1_1/src/main/ets/components/MainPage.ets

class Tmp {
  paramA2: string = 'Hello World!';
}

@Builder
function overBuilder(param: Tmp) {
  Column() {
    Text(param.paramA2)
  }
}

export const globalBuilder: WrappedBuilder<[Tmp]> = wrapBuilder(overBuilder);
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1_1": "file:../har1_1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1 WrappedBuilder对象。

```TypeScript
'use static';

// entry/src/main/ets/pages/MainPage.ets
import { Entry, Component, Column, Button, ClickEvent, compatibleWrappedBuilder } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

import { globalBuilder } from 'har1_1';

@Entry
@Component
struct MainPage {
  @State stateVar: string = 'Hello World!';

  build() {
    Column() {
      // 无需显式使用占位组件API，框架会自动处理
      let globalBuilderParam = ESValue.instantiateEmptyObject()
      globalBuilderParam.setProperty(ESValue.wrap('paramA2'), ESValue.wrap(this.stateVar))
      compatibleWrappedBuilder(globalBuilder, globalBuilderParam)

      Button('Click me').onClick((e: ClickEvent) => {
        this.stateVar = 'Hello ArkUI!';
      })
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
