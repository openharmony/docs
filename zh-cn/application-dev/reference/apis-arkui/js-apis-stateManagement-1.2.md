# @ohos.arkui.stateManagement (状态管理ArkTS1.2)

状态管理模块提供了应用程序动态刷新、UI数据存储、使能数据观察等能力。

>**说明：**
>
>本模块首批接口从API version 20开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>本模块仅适用于ArkTS1.2。

## 导入模块

```ts
import { UIUtils } from '@ohos.arkui.stateManagement';
```

## UIUtils

UIUtils是状态管理提供的工具，用于处理可观察数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### makeObserved

static makeObserved\<T extends object\>(source: T): T

将不可观察数据转化为可观察数据。支持built-in类型（Array、Map、Set、Date）以及interface字面量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明         |
| ------ | ---- | ---- | ------------ |
| source | T    | 是   | 数据源对象。 |

**返回值：**

| 类型 | 说明               |
| ---- | ------------------ |
| T    | 可观察的数据对象。 |

**示例：**

```ts
import { Entry, Component, Column, Text, ClickEvent } from '@ohos.arkui.component';
import { State, UIUtils } from '@ohos.arkui.stateManagement';
interface Info {
  name: string,
  age: number
}
@Entry
@Component
struct Index {
  // 装饰字面量
  @State info: Info = UIUtils.makeObserved({ name: 'Jack', age: 25} as Info) as Info;
  build() {
    Column() {
      Text(`info.name: ${this.info.name}`)
        .onClick((e: ClickEvent) => {
          this.info.name = 'Tom';
        })
    }
  }
}
```

### getTarget

static getTarget\<T extends object\>(source: T): T

获取状态管理框架包装、代理前的原始对象。支持built-in类型（Array、Map、Set、Date）以及interface字面量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | ---- | ---- | ---------------------------- |
| source | T    | 是   | 状态管理框架包装、代理的对象 |

**返回值：**

| 类型 | 说明                               |
| ---- | ---------------------------------- |
| T    | 状态管理框架包装、代理前的原始对象 |

**示例：**

```ts
import { Entry, Component, Column, Text, ClickEvent } from '@ohos.arkui.component';
import { State, UIUtils } from '@ohos.arkui.stateManagement';
interface Info {
  name: string,
  age: number
}
@Entry
@Component
struct Index {
  rawInfo: Info = { name: 'Jack', age: 25} as Info;
  // 装饰字面量
  @State info: Info = this.rawInfo;
  build() {
    Column() {
      Text(`rawInfo === info: ${this.rawInfo === this.info}`) // false
      Text(`rawInfo === UIUtils.getTarget(info): ${this.rawInfo === UIUtils.getTarget(this.info)}`) // true
    }
  }
}
```

