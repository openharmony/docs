# wrapBuilder
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The **wrapBuilder** function encapsulates global @Builder functions to improve code maintainability. For details, see [wrapBuilder: Encapsulating Global @Builder](../../../ui/state-management/arkts-wrapBuilder.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## wrapBuilder

wrapBuilder\<Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder\<Args>

A template function that returns a **WrappedBuilder** object. The template parameter **Args extends Object[]** represents the parameter list of the builder function to be encapsulated.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        | Type                                  | Mandatory| Description                                                        |
| -------------- | -------------------------------------- | ---- | ---- |
| builder        | (...args: Args) => void                | Yes  | Global function decorated with @Builder.|

**Example**

```ts
@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(MyBuilder);
```
## WrappedBuilder

Implements the encapsulation class for @Builder functions. The template parameter **Args extends Object[]** must match the parameter type list of the @Builder function.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                   | Read-Only| Optional| Description     |
| ------- | ---------------------- | ---- | ---  | -------- |
| builder | (...args: Args) => void | No | No  | Global function decorated with @Builder.|


### constructor

constructor(builder: (...args: Args) => void)

A constructor used to create a **WrappedBuilder** instance.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                   | Mandatory| Description                                                             |
| --------- | --------------------------------------- | ---- | ----------------------------------------------------------------- |
| builder   | (...args: Args) => void)               | Yes| Global function decorated with @Builder.|

**Example**

```ts
@Builder
function MyBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}
let builderVar: WrappedBuilder<[string, number]> = new WrappedBuilder<[string, number]>(MyBuilder);
```
