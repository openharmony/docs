# Enable/Disable

The **enabled** attribute sets whether a component responds to user interactions, such as [click events](ts-universal-events-click.md), [touch events](ts-universal-events-touch.md), [drag events](ts-universal-events-drag-drop.md), [key events](ts-universal-events-key.md), [focus events](ts-universal-focus-event.md), and [mouse events](ts-universal-mouse-key.md).

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name   | Type| Description                                                        |
| ------- | -------- | ------------------------------------------------------------ |
| enabled | boolean  | Whether the component responds to user interactions, including clicks and touches. The value **true** means that the component responds to user interactions, and **false** means the opposite.<br>Default value: **true**<br>Since API version 9, this API is supported in ArkTS widgets. |


## Example

```ts
// xxx.ets
@Entry
@Component
struct EnabledExample {
  
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // The component does not respond to clicks.
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![en-us_image_0000001212218428](figures/en-us_image_0000001212218428.gif)
