# @Param: Inputting External Parameters to Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:14.789Z pushedAt=2026-08-14T02:36:36.382Z -->

**\@Param** is used in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to receive external input and implement unidirectional data synchronization between parent and child components. This is applicable to scenarios where a parent component needs to pass state data to its child component in a unidirectional manner. It simplifies communication between components and ensures a clear data flow direction. Variables decorated with **\@Param** cannot be directly modified in a component. If a child component needs to synchronize data to its parent component, use **\@Param** together with [@Event](./ts-state-management-event.md).

For details, see [@Param Decorator: Inputting External Parameters to Components](../../../ui/state-management/arkts-new-param.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Param

const Param: PropertyDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
@ComponentV2
struct Child {
  // Use @Param to receive the parameter passed by the parent component to implement unidirectional data synchronization between the parent and child components.
  @Param message: string = '';
  build() {
    Column() {
      Text(`Child message: ${this.message}`)
    }
  }
}
@Entry
@ComponentV2
struct Index {
  @Local message: string = 'Hello';
  build() {
    Column() {
      Text(`Parent message: ${this.message}`)
      Button('change message')
        // Set a click event and change the value of message. The change will be unidirectionally synchronized to the child component.
        .onClick(() => {
          this.message = 'Hello World';
        })
      // Create a child component Child and pass message to the @Param decorated variable of the child component.
      Child({ message: this.message })
    }
  }
}
```