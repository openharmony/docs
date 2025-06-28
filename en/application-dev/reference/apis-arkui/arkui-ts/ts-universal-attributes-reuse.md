# Reuse Options

The **reuse** attribute is used to specify reuse options for custom components decorated with @ReusableV2.

This document is solely for API reference. For details about the usage guidelines and constraints, see [@ReusableV2 Decorator: Reusing Components](../../../ui/state-management/arkts-new-reusableV2.md).

>  **NOTE**
>
> This feature is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.

## reuse

reuse(options: ReuseOptions)

Sets the reuse options for custom components decorated with @ReusableV2.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                         | Mandatory| Description                                          |
| ------- | ----------------------------- | ---- | ---------------------------------------------- |
| options | [ReuseOptions](#reuseoptions) | Yes  | Custom reuse configuration.|

## ReuseOptions

Defines the reuse options.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

| Name   | Type                               | Mandatory| Description                                                        |
| ------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| reuseId | [ReuseIdCallback](#reuseidcallback) | No  | Reuse ID. Components with same **reuseId** will be mutually reused. The default reuse ID is the component name.|

## ReuseIdCallback

type ReuseIdCallback = () => string

Defines the callback used to obtain the reuse ID.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Developer-specified reuse ID.<br>It uses the component name if unspecified or if an empty string **''** is provided.|

## Example

```ts
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      ReusableV2Component()
        .reuse({reuseId: () => 'reuseComponent'}) // Use 'reuseComponent' as reuseId.
      ReusableV2Component()
        .reuse({reuseId: () => ''}) // If an empty string is used, the component name 'ReusableV2Component' is used as reuseId.
      ReusableV2Component() // If reuseId is not specified, the component name 'ReusableV2Component' is used as reuseId.
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  build() {
  }
}
```
