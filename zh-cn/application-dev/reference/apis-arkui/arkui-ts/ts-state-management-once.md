# @Once：初始化同步一次

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Once作为辅助装饰器，用于[状态管理V2](../../../ui/state-management/arkts-state-management-overview.md#状态管理v2)中，需要搭配[@Param](./ts-state-management-param.md)使用，适用于仅从外部初始化一次且不接受后续同步变化的场景。若未与@Param配合使用，@Once单独使用将编译报错。

开发指南参考：[@Once：初始化同步一次](../../../ui/state-management/arkts-new-once.md)。

> **说明：**
>
> 从API version 12开始，支持该装饰器。

## @Once

const Once: PropertyDecorator

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@ComponentV2
struct Child {
  // 使用@Param装饰器接收父组件传入的参数
  // 使用@Once辅助装饰器，表示仅从父组件初始化一次，后续父组件的变化不会同步到子组件
  @Param @Once onceParam: string = '';

  build() {
    Column() {
      Text(`onceParam: ${this.onceParam}`)
      Button('change onceParam')
      // 设置点击事件，子组件内部可以修改onceParam，但不会同步回父组件
        .onClick(() => {
          this.onceParam = 'child';
        })
    }
  }
}

@Entry
@ComponentV2
struct Index {
  @Local message: string = 'Hello World';

  build() {
    Column() {
      Text(`Parent message: ${this.message}`)
      Button('change message')
      // 设置点击事件，修改message的值
        .onClick(() => {
          this.message = 'parent';
        })
      // 创建子组件Child，将message传入onceParam
      // 由于@Once装饰器，后续message的变化不会同步到子组件
      Child({ onceParam: this.message })
    }
  }
}
```

