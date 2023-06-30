# Toggle

The **\<Toggle>** component provides a clickable element in the check box, button, or switch type.

>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component can contain child components only when **ToggleType** is set to **Button**.


## APIs

Toggle(options: { type: ToggleType, isOn?: boolean })

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory  | Description          |
| ---- | ---------- | -----| -------------- |
| type | [ToggleType](#toggletype) | Yes  | Type of the toggle.|
| isOn | boolean    | No  | Whether the toggle is turned on. The value **true** means that the toggle is turned on, and **false** means the opposite.<br>Default value: **false**<br>Since API version 10, this parameter supports [$$](../../quick-start/arkts-two-way-sync.md) for two-way binding of variables.|


## ToggleType

Since API version 9, this API is supported in ArkTS widgets.

| Name      | Description                |
| -------- | ---------------- |
| Checkbox | Check box type.<br>**NOTE**<br>The default value of the universal attribute [margin](ts-universal-attributes-size.md) is as follows:<br>{<br> top: 12 px,<br> right: 12 px,<br> bottom: 12 px,<br> left: 12 px<br> } |
| Button   | Button type. The set string, if any, will be displayed inside the button.      |
| Switch   | Switch type.<br>**NOTE**<br>The default value of the universal attribute [margin](ts-universal-attributes-size.md) is as follows:<br>{<br> top: 6px,<br> right: 14px,<br> bottom: 6 px,<br> left: 14 px<br> } |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name               | Parameter                          | Description                 |
| ---------------- | --------------------------- | ---------------------- |
| selectedColor    | [ResourceColor](ts-types.md#resourcecolor)  | Background color of the component when it is turned on.<br>Since API version 9, this API is supported in ArkTS widgets.|
| switchPointColor | [ResourceColor](ts-types.md#resourcecolor)  | Color of the circular slider when the component is of the **Switch** type.<br>**NOTE**<br>This attribute is valid only when **type** is set to **ToggleType.Switch**.<br>Since API version 9, this API is supported in ArkTS widgets.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name| Description|
| -------- | -------- |
| onChange(callback: (isOn: boolean) =&gt; void) | Triggered when the toggle status changes.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If **isOn** is **true**, it indicates that the toggle changes from off to on. If **isOn** is **false**, it indicates that the toggle changes from on to off.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })
      }
    }.width('100%').padding(24)
  }
}
```

![toggle](figures/toggle.gif)
