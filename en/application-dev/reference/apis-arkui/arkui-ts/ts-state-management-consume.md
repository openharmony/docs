# @Consume: Implementing Two-Way Synchronization with Descendant Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2996efc9552d09a1d03764710258d0fca6157cdc translatedAt=2026-08-13T07:00:20.847Z pushedAt=2026-08-14T01:45:15.234Z -->

[@Provide](./ts-state-management-provide.md) and **\@Consume** are used together for [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to implement two-way synchronization across component levels. This is applicable to scenarios where states need to be shared among multiple layers of nested components. It simplifies the communication logic between components by avoiding the complexity of layer-by-layer data transfer. As a data consumer, the variable decorated with **\@Consume** establishes a bidirectional binding relationship with the variable decorated with **\@Provide** through an alias or variable name. When a variable decorated with **\@Provide** or **\@Consume** changes, the change is automatically synchronized to the other party. An alias is preferred for matching. If no alias is set, a variable name is used for matching.

For details, see [@Provide and @Consume Decorators: Two-Way Synchronization with Descendant Components](../../../ui/state-management/arkts-provide-and-consume.md).

> **NOTE**
>
> This decorator is supported since API version 7.
>
> Since API version 20, **\@Consume** decorated variables support default value assignment. If no matching variable decorated with **\@Provide** is found, the **\@Consume** decorated variable initializes with its default value. When a matching variable decorated with **\@Provide** is found, the **\@Consume** decorated variable uses the value of the **\@Provide** decorated variable, and the default value is ignored.
>
> Since API version 20, cross-BuilderNode pairing of **\@Provide**/**\@Consume** decorated variables is supported. In the BuilderNode scenario, a BuilderNode constructs nodes before being mounted to the tree. Therefore, the **\@Consume** decorated variable defined inside the BuilderNode must be assigned a default value. After the BuilderNode is mounted to the tree, the framework retrieves the **\@Provide** decorated variable closest to the BuilderNode again and establishes a two-way synchronization relationship with the variable.

## @Consume

const Consume: PropertyDecorator & ((value: string) => PropertyDecorator)

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ------ | ---- | -------------- |
| value | string | No | Used to set an alias. If no alias is specified, a variable name is used by default. When an alias is set, an **\@Consume** decorated variable matches and binds to an **\@Provide** decorated variable through the alias. When no alias is set, matching and binding are performed through a variable name, implementing two-way data synchronization across component levels. |

**Return value**

| Type | Description |
| --- | --- |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
@Entry
@Component
struct Index {
  @Provide message: string = 'aaa'; // The @Provide decorated variable provides data. If no alias is set, and the variable name message is used for matching.

  build() {
    Column() {
      Text(`provide: ${this.message}`)
      Child()
    }
  }
}

@Component
struct Child {
  @Consume message: string; // The @Consume decorated variable consumes the data. If no alias is set, the variable name message is used to establish a pairing relationship with the @Provide decorated variable.

  build() {
    Column() {
      Text(`consume: ${this.message}`)
    }
  }
}
```