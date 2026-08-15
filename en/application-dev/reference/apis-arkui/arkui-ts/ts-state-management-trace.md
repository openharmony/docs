# @Trace: Observing Class Property Changes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=bbb682e63876992d34ec9fd16b00a36fec86c65e translatedAt=2026-08-13T07:02:09.756Z pushedAt=2026-08-14T03:21:40.617Z -->

**\@Trace** is a property decorator used in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). [@ObservedV2](./ts-state-management-observedv2.md) and **\@Trace** are used together to decorate classes and class properties, enhancing the observation capability for decorated classes and properties. That is, they can recursively observe changes in property values of nested objects and trigger automatic UI refresh. They are applicable to scenarios where precise observation and management of class property changes are required.

For details, see [@ObservedV2 and @Trace Decorators: Observing Class Property Changes](../../../ui/state-management/arkts-new-observedV2-and-trace.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Trace

const Trace: PropertyDecorator

Declares an observable property. **\@Trace** must be used together with **\@ObservedV2** and takes effect only in classes decorated with **\@ObservedV2**.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
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
      // After a click is made, the value of age increases by 1. The UI is automatically refreshed due to the @Trace decorator.
        .onClick(() => {
          this.father.son.age++;
        })
    }
  }
}
```