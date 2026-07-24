# @ObservedV2：类属性变化观测

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@ObservedV2是类装饰器，用于[状态管理V2](../../../ui/state-management/arkts-state-management-overview.md#状态管理v2)中。@ObservedV2与[@Trace](./ts-state-management-trace.md)配套使用，装饰类以及类中的属性，使得被装饰的类和属性具有深度观测的能力。相较于[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)的[@Observed](./ts-state-management-observed.md)，@ObservedV2提供了更细粒度的属性级深度观测能力，适用于需要精确追踪嵌套对象属性变化并驱动UI更新的场景，能够有效提升状态管理的性能和灵活性。

开发指南参考：[\@ObservedV2装饰器和\@Trace装饰器：类属性变化观测](../../../ui/state-management/arkts-new-observedV2-and-trace.md)。

> **说明：**
>
> 从API version 12开始，支持该装饰器。

## @ObservedV2

const ObservedV2: ClassDecorator

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
// 使用@ObservedV2类装饰器，使Son类具有深度观测能力（状态管理V2）
@ObservedV2
class Son {
  // 使用@Trace装饰器标记需要观测的属性，属性变化时触发UI刷新
  @Trace age: number = 100;
}
class Father {
  son: Son = new Son();
}
@Entry
@ComponentV2
struct Index {
  father: Father = new Father();

  build() {
    Column() {
      Text(`${this.father.son.age}`)
        // 设置点击事件，点击后age值加1，由于@Trace装饰器，UI会自动刷新
        .onClick(() => {
          this.father.son.age++;
        })
    }
  }
}
```

