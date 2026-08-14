# @Once: Implementing Initialization Once

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:11.475Z pushedAt=2026-08-14T02:31:47.382Z -->

**\@Once** is an auxiliary decorator used in [State Management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). It must be used together with [@Param](./ts-state-management-param.md) and is applicable to scenarios where data is initialized from an external source only once without accepting subsequent synchronization changes. If **\@Once** is not used together with **\@Param**, an error will be reported during compilation when **\@Once** is used independently.

For details, see [@Once: Implementing Initialization Once](../../../ui/state-management/arkts-new-once.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Once

const Once: PropertyDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
@ComponentV2
struct Child {
  // Use @Param to receive the parameter passed by the parent component.
  // Use @Once to make the data initialized only once from the parent component. Subsequent changes to the parent component will not be synchronized to the child component.
  @Param @Once onceParam: string = '';

  build() {
    Column() {
      Text(`onceParam: ${this.onceParam}`)
      Button('change onceParam')
      // Set a click event. onceParam can be modified in the child component, but the changes will not be synchronized to the parent component.
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
      // Set a click event and change the value of message.
        .onClick(() => {
          this.message = 'parent';
        })
      // Create a child component Child and pass message to onceParam.
      // Due to @Once, subsequent changes to message will not be synchronized to the child component.
      Child({ onceParam: this.message })
    }
  }
}
```