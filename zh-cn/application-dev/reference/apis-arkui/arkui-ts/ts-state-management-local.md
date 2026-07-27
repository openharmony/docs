# @Local：组件内部状态

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Local用于[状态管理V2](../../../ui/state-management/arkts-state-management-overview.md#状态管理v2)中，表示组件内部的状态，使得自定义组件内部的变量具有观测能力。适用于需要在自定义组件内部维护和观测局部状态的场景（如计数器、开关状态等）。使用@Local可以简化组件内部状态管理逻辑，当状态变化时自动触发UI刷新，无需手动管理。

开发指南参考：[@Local装饰器：组件内部状态](../../../ui/state-management/arkts-new-local.md)。

> **说明：**
>
> 从API version 12开始，支持该装饰器。

## @Local

const Local: PropertyDecorator

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@Entry
@ComponentV2
struct LocalExample {
  @Local count: number = 0; // 定义一个Local变量
  build() {
    Column() {
      Text(`${this.count}`)
    }
  }
}
```

