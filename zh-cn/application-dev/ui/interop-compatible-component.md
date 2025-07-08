# ArkTS1.2使用ArkTS1.1自定义组件

## 概述

UI自定义组件互操作适用于[ArkTS1.2互操作](../quick-start/arkts-interop-overview.md)中使用UI的场景。


## 架构原理

[占位组件](../reference/apis-arkui/arkui-ts/ts-interop-compatible-component.md)链接ArkTS1.2和ArkTS1.1的UI节点，构建完整的UI界面。


## 设计理念

UI自定义组件互操作适用于主模块使用ArkTS1.2、子模块使用ArkTS1.1的场景。

- 渐进式迁移：逐步将ArkTS1.1组件迁移到新版本。

- 使用旧组件：使用稳定的ArkTS1.1自定义组件。


## 约束与限制

- 遵循[语言互操作](../quick-start/arkts-interop-overview.md#交互基本原则)的基本规范。

- ArkTS1.2的占位组件不能使用自定义组件的通用属性和方法。


## 开发场景

### 在ArkTS1.2引用ArkTS1.1中的自定义组件显示UI

下面的代码示例展示了在ArkTS1.2中引用ArkTS1.1的自定义组件来显示“Hello World!”。

- 创建ArkTS1.1子模块`har1.1`，在`har1.1/src/main/ets/components`目录创建并导出自定义组件。

```TypeScript
// har1.1/src/main/ets/components/ChildComponent.ets

@Component
export struct ChildComponent {
  message: string = 'Hello World!';

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontColor(Color.Blue)
    }
    .padding(20)
    .backgroundColor(Color.White)
  }
}
```

- 在主模块`entry`的`oh-package.json5`文件中配置子模块依赖。

```json
// entry/oh-package.json5

"dependencies": {
  "har1.1": "file:../har1.1"
}
```

- 在ArkTS1.2主模块中引入ArkTS1.1组件。

```TypeScript
'use static';

// entry/src/main/ets/pages/MainPage.ets
import { Entry, Component, Column } from '@ohos.arkui.component';

import { ChildComponent } from 'har1.1';

@Entry
@Component
struct MainPage {
  build() {
    Column() {
      // 无需显式使用占位组件API，框架会自动处理
      ChildComponent()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F1F3F5')
  }
}
```


### 使用技巧

- 传递ArkTS1.2数据到ArkTS1.1自定义组件。

```TypeScript
// ArkTS1.1子组件
@Component
export struct ChildComponent {
  name: string = '';

  build() {
    Text(`Hello ${this.name}`)
  }
}

// ArkTS1.2主模块
ChildComponent({ name: 'ArkTS' })
```


- 事件回调处理时，可以将事件回调放置在ArkTS1.2占位组件的父组件上，或放置在ArkTS1.1的子组件上。

```TypeScript
// 放在ArkTS1.1子组件上
import hilog from '@ohos.hilog';

@Component
export struct ChildComponent {

  build() {
    Button('Click')
      .onClick(() => {
        hilog.info(0x0000, 'Interop', 'Hello ArkTS1.1');
      })
  }
}
```

```TypeScript
// 放在ArkTS1.2占位组件的父组件上
import { ClickEvent } from '@ohos.arkui.component';
import hilog from '@ohos.hilog';

Column() {
  ChildComponent()
}
.onClick((e: ClickEvent) => {
  hilog.info(0x0000, 'Interop', 'Hello ArkTS1.2');
})
```


- ArkTS1.2的占位组件不能使用自定义组件的通用属性和方法，可以通过传递样式数据给ArkTS1.1自定义组件来实现。

```TypeScript
// 在ArkTS1.1组件中添加样式透传属性
@Component
export struct ChildComponent {
  backgroundColor: Color = Color.Red;

  build() {
    Column() {}
      .backgroundColor(this.backgroundColor)
  }
}

// ArkTS1.2主模块
ChildComponent({ backgroundColor: '#F1F3F5' })
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
└── har1.1/         # ArkTS1.1子模块
    └── src/
        └── main/
            └── ets/
                └── components/
                    └── ChildComponent.ets
```
