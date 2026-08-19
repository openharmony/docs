# @Prop: Implementing One-Way Synchronization from Parent to Child Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2996efc9552d09a1d03764710258d0fca6157cdc translatedAt=2026-08-13T07:01:29.978Z pushedAt=2026-08-14T02:41:14.082Z -->

**\@Prop** is used for [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to receive values passed from external sources and establish a one-way synchronization relationship with parent components. When the state variables decorated with [@State](./ts-state-management-state.md) in the parent component change, the changes are synchronously updated to the corresponding **\@Prop** decorated variables in the child component, triggering the child component to re-render. **\@Prop** uses a unidirectional data flow mechanism. Changes to **\@Prop** decorated variables in child components take effect only within the child components and are not synchronized back to the parent component. This is applicable when child components need to respond to state changes of parent components but do not need to modify the parent component's state reversely.

For details, see [@Prop Decorator: Implementing One-Way Synchronization from Parent to Child Components](../../../ui/state-management/arkts-prop.md).

> **NOTE**
>
> This decorator is supported since API version 7.

## @Prop

const Prop: PropertyDecorator

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Example:**

```ts
@Component
struct Child {
  // Use @Prop to receive the value passed by the parent component and establish a unidirectional synchronization relationship with the parent component.
  // Data changes in the parent component will be synchronized to the child component, but changes in the child component will not be synchronized back to the parent component.
  @Prop message: string = 'Hi';

  build() {
    Column() {
      Text(this.message)
    }
  }
}

@Entry
@Component
struct Index {
  // Use @State to declare a state variable as the data source of the @Prop decorated variable.
  @State message: string = 'Hello';

  build() {
    Column() {
      // Create a child component Child and bind message to the @Prop decorated variable of the child component in one-way mode.
      Child({ message: this.message })
    }
  }
}
```