# @Entry: Page Entry

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The custom component decorated by @Entry is used as the entry of the UI page.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Entry

A single page can only have one @Entry decorated custom component serving as its entry.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
@Entry
@Component
struct Index {
  build() {
    Text('@Entry Test')
  }
}
```

## EntryOptions<sup>10+</sup>

Describes the named route options.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name                        | Type                                                        | Mandatory| Description                                                        |
| ------------------------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| routeName                      | string                                                       | No  | Name of the target named route.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| storage                        | [LocalStorage](../../../ui/state-management/arkts-localstorage.md) | No  | Stores page-level UI status.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| useSharedStorage<sup>12+</sup> | boolean                                                      | No  | Whether to use the LocalStorage instance passed by [LocalContent](../arkts-apis-window-WindowStage.md#loadcontent9). The default value is **false**. **true**: Use the shared LocalStorage instance. **false**: Do not use the shared LocalStorage instance.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

**Example**

```ts
@Entry({routeName: 'myPage'})
@Component
struct Index {
  build() {
    Text('Index')
  }
}
```
