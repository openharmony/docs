# @Provide: Implementing Two-Way Synchronization with Descendant Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2996efc9552d09a1d03764710258d0fca6157cdc translatedAt=2026-08-13T07:01:40.702Z pushedAt=2026-08-14T02:50:47.184Z -->

**\@Provide** and [@Consume](./ts-state-management-consume.md) are used together for [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1) to implement two-way synchronization across component levels. This is applicable to scenarios where state data needs to be transferred across multiple component levels to avoid layer-by-layer transfer. It can solve the problem of complex state transfer when there are many component levels. Variables decorated with **\@Provide** are used as data sources. Bidirectional binding relationships are established between the data sources and variables decorated with **\@Consume** through aliases or variable names. When a variable decorated with **\@Provide** or **\@Consume** changes, the change is automatically synchronized to the other party.

For details, see [@Provide and @Consume Decorators: Two-Way Synchronization with Descendant Components](../../../ui/state-management/arkts-provide-and-consume.md).

> **NOTE**
>
> This decorator is supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Provide

const Provide: PropertyDecorator & ((value: string | ProvideOptions) => PropertyDecorator)

**Widget capability:** This API can be used in ArkTS widgets since API version 9.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                        | Mandatory | Description                         |
| ------ | ------------------------------------------------- | ---- | ---------------------------- |
| value  | string \| [ProvideOptions](#provideoptions11) | No   | Used to set an alias or used as an alias that can be overridden.<br>If the type is string, the value is directly used as an alias. Descendant components can access data through this alias.<br>When the type is ProvideOptions, if **allowOverride** is set, the value will be used as an alias and the alias can be overridden; if **allowOverride** is not set, an alias is a variable name and cannot be overridden.<br>When this parameter is not specified, a variable name is used and cannot be overridden. If an **\@Provide** decorated variable is defined with the same name in this case, an error will be reported at runtime. |

**Return value**

| Type | Description |
| --- | --- |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value. |

## ProvideOptions<sup>11+</sup>

Options of the **\@Provide** decorator. You can use **allowOverride** to override the alias of an **\@Provide** decorated variable with the same name in the same component tree. It is suitable for scenarios where a child component needs to override the alias of the **\@Provide** decorated variable with the same name in the parent component, improving the flexibility of cross-level state management. For details, see [Support for the allowOverride Parameter](../../../ui/state-management/arkts-provide-and-consume.md#support-for-the-allowoverride-parameter).

**Widget capability:** This API can be used in ArkTS widgets since API version 11.

**Atomic service API:** This API can be used in atomic services since API version 11.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Properties**

| Name | Type | Read-Only | Optional | Description |
| ------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| allowOverride | string | No | Yes | Alias of an **\@Provide** decorated variable that can be overridden. In detail, you can use this property to override the alias of an **\@Provide** decorated variable with the same name in the same component tree.<br>If the property is not specified, the alias of an **\@Provide** decorated variable cannot be overridden. If you define an **\@Provide** decorated variable with the same name without setting **allowOverride**, an error will be reported at runtime. |

**Example:**

```ts
@Entry
@Component
struct Index {
  @Provide message: string = 'aaa'; // The @Provide decorated variable provides data. If no alias is set, the variable name message is used for matching.

  build() {
    Column() {
      Text(`provide: ${this.message}`)
      Child()
    }
  }
}

@Component
struct Child {
  @Consume message: string; // The @Consume decorated variable consumes data. If no alias is set, the variable name message is used to establish a pairing relationship with the @Provide decorated variable.

  build() {
    Column() {
      Text(`consume: ${this.message}`)
    }
  }
}
```