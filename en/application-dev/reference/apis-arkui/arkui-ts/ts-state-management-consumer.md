# @Consumer: Synchronizing Across Component Levels in a Two-Way Manner

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=bbb682e63876992d34ec9fd16b00a36fec86c65e translatedAt=2026-08-13T07:00:20.907Z pushedAt=2026-08-14T01:45:42.665Z -->

[@Provider](./ts-state-management-provider.md) and **\@Consumer** are used together in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to implement bidirectional data synchronization across component levels. **\@Consumer** decorates a data consumer to obtain data from a data source. It is applicable to scenarios where states need to be shared and synchronized between multi-level nested components. This avoids complex operations of transferring data level by level through multi-level components and simplifies cross-level state management. If the variable decorated with **\@Consumer** does not find the variable decorated with **\@Provider** with the matching alias in the component tree, it uses its own initial value and does not perform data synchronization.

For details, see [@Provider and @Consumer Decorators: Synchronizing Across Component Levels in a Two-Way Manner](../../../ui/state-management/arkts-new-provider-and-consumer.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Consumer

const Consumer: (aliasName?: string) => PropertyDecorator

Decorates a data consumer to obtain data from a data source. It is used together with **\@Provider** in state management V2 to implement bidirectional data synchronization across component levels. If the variable decorated with **\@Consumer** does not find the variable decorated with **\@Provider** with the matching alias in the component tree, it uses its own initial value and does not perform data synchronization.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| --------- | ------ | ---- | ---------------------------------- |
| aliasName | string | No | Alias, which is used as the matching identifier for bidirectional data synchronization between variables decorated with **\@Consumer** and **\@Provider**. The alias must be the same as that of the **\@Provider** decorated variable. By default, the alias is the variable name. |

**Return value**

| Type | Description |
| --------- | ------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
@Entry
@ComponentV2
struct Index {
  // The @Provider decorated variable provides the data.
  @Provider() str: string = 'aaa';

  build() {
    Column() {
      Child()
    }
  }
}

@ComponentV2
struct Child {
  // The @Consumer decorated variable consumes the data.
  @Consumer() str: string = '';

  build() {
    Column() {
      Text(`${this.str}`)
    }
  }
}
```