# @ObservedV2: Observing Class Property Changes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:13.672Z pushedAt=2026-08-14T02:25:04.261Z -->

**\@ObservedV2** is a class decorator used in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). **\@ObservedV2** is used together with [@Trace](./ts-state-management-trace.md) to decorate classes and class properties, enhancing the observation capability for decorated classes and properties. Compared with [@Observed](./ts-state-management-observed.md) in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), **\@ObservedV2** provides more fine-grained, property-level in-depth observation capabilities. It is suitable for scenarios where changes in nested object properties need to be precisely tracked to drive UI updates, effectively improving the performance and flexibility of state management.

For details, see [@ObservedV2 and @Trace Decorators: Observing Class Property Changes](../../../ui/state-management/arkts-new-observedV2-and-trace.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @ObservedV2

const ObservedV2: ClassDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
// Use @ObservedV2 to enable the Son class to have in-depth observation capabilities (state management V2).
@ObservedV2
class Son {
  // Use @Trace to mark the property to be observed. When the property changes, UI refresh is triggered.
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
        // Set a click event. After a click is made, the value of age increases by 1. The UI is automatically refreshed due to @Trace.
        .onClick(() => {
          this.father.son.age++;
        })
    }
  }
}
```