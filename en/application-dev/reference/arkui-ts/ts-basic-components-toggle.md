# Toggle


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

None


## APIs

Toggle(options: { type: ToggleType, isOn?: boolean })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | type | ToggleType | Yes | - | Type&nbsp;of&nbsp;the&nbsp;toggle. |
  | isOn | boolean | No | false | Initial&nbsp;state&nbsp;of&nbsp;the&nbsp;toggle.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;If&nbsp;**isOn**&nbsp;is&nbsp;not&nbsp;set&nbsp;during&nbsp;component&nbsp;creation,&nbsp;the&nbsp;selected&nbsp;state&nbsp;can&nbsp;be&nbsp;retained&nbsp;during&nbsp;component&nbsp;reuse.&nbsp;If&nbsp;**isOn**&nbsp;is&nbsp;set,&nbsp;the&nbsp;selected&nbsp;state&nbsp;needs&nbsp;to&nbsp;be&nbsp;retained&nbsp;during&nbsp;component&nbsp;reuse&nbsp;after&nbsp;the&nbsp;selected&nbsp;state&nbsp;is&nbsp;recorded&nbsp;using&nbsp;an&nbsp;event&nbsp;method. |


- ToggleType enums
    | Name | Description | 
  | -------- | -------- |
  | Checkbox | A&nbsp;checkbox&nbsp;is&nbsp;provided.&nbsp;The&nbsp;text&nbsp;setting&nbsp;of&nbsp;the&nbsp;child&nbsp;component&nbsp;does&nbsp;not&nbsp;take&nbsp;effect.&nbsp;If&nbsp;the&nbsp;text&nbsp;setting&nbsp;is&nbsp;required,&nbsp;you&nbsp;can&nbsp;place&nbsp;the&nbsp;**&lt;Text&gt;**&nbsp;component&nbsp;and&nbsp;the&nbsp;current&nbsp;component&nbsp;in&nbsp;the&nbsp;layout&nbsp;component. | 
  | Button | A&nbsp;button&nbsp;is&nbsp;provided.&nbsp;If&nbsp;the&nbsp;text&nbsp;setting&nbsp;is&nbsp;available,&nbsp;the&nbsp;corresponding&nbsp;text&nbsp;content&nbsp;is&nbsp;displayed&nbsp;inside&nbsp;the&nbsp;button. | 
  | Switch | A&nbsp;switch&nbsp;is&nbsp;provided.&nbsp;The&nbsp;text&nbsp;setting&nbsp;of&nbsp;the&nbsp;child&nbsp;component&nbsp;does&nbsp;not&nbsp;take&nbsp;effect.&nbsp;If&nbsp;the&nbsp;text&nbsp;setting&nbsp;is&nbsp;required,&nbsp;you&nbsp;can&nbsp;place&nbsp;the&nbsp;**&lt;Text&gt;**&nbsp;component&nbsp;and&nbsp;the&nbsp;current&nbsp;component&nbsp;in&nbsp;the&nbsp;layout&nbsp;component. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| selectedColor | Color | - | Background&nbsp;color&nbsp;of&nbsp;the&nbsp;toggle&nbsp;when&nbsp;it&nbsp;is&nbsp;enabled. | 
| switchPointColor | Color | - | Color&nbsp;of&nbsp;the&nbsp;circular&nbsp;slider&nbsp;of&nbsp;the&nbsp;**Switch**&nbsp;type.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;type&nbsp;is&nbsp;set&nbsp;to&nbsp;**ToggleType.Switch**. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:&nbsp;(isOn:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;switch&nbsp;status&nbsp;changes. | 


## Example


```
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor(0xed6f21)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor(0x39a2db)
          .switchPointColor(0xe5ffffff)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 28, height: 28 })
          .selectedColor(0xed6f21)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 28, height: 28 })
          .selectedColor(0x39a2db)
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0xed6f21)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').padding({ left: 12, right: 12 })
        }
        .selectedColor(0x39a2db)
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })
      }
    }.width('100%').padding(24)
  }
}
```

![en-us_image_0000001211898522](figures/en-us_image_0000001211898522.gif)
