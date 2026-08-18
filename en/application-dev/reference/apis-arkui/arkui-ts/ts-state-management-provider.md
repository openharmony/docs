# @Provider: Synchronizing Across Component Levels in a Two-Way Manner

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:36.420Z pushedAt=2026-08-14T02:57:01.162Z -->

**\@Provider** and [@Consumer](./ts-state-management-consumer.md) are used together in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to implement bidirectional data synchronization across component levels. **\@Provider** decorates a data provider to provide data for child components. It is applicable to scenarios where state data needs to be shared across multiple layers of components (with deep component layers) to avoid layer-by-layer data transfer. This simplifies the state management process and reduces the coupling between components.

For details, see [@Provider and @Consumer Decorators: Synchronizing Across Component Levels in a Two-Way Manner](../../../ui/state-management/arkts-new-provider-and-consumer.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Provider

const Provider: (aliasName?: string) => PropertyDecorator

Decorates a data provider to provide data for child components. It is used together with **\@Consumer** in state management V2 to implement bidirectional data synchronization across component levels.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Parameter Name | Type   | Mandatory | Description                               |
| ------ | ------ | ---- | ---------------------------------- |
| aliasName  | string | No   | Alias, which is used as the matching identifier for bidirectional data synchronization between variables decorated with **\@Provider** and **\@Consumer**. The alias must be the same as that of the **\@Consumer** decorated variable. By default, the alias is the variable name. |

**Return value**

| Type | Description |
| ---- | ---- |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
@Entry
@ComponentV2
struct Index {
  // The @Provider decorated variable provides the original data.
  @Provider() str: string = 'aaa';

  build() {
    Column() {
      Text(`parent: ${this.str}`)
      Child()
    }
  }
}

@ComponentV2
struct Child {
  // The @Consumer decorated variable synchronizes data.
  @Consumer() str: string = '';

  build() {
    Column() {
      Text(`child: ${this.str}`)
    }
  }
}
```