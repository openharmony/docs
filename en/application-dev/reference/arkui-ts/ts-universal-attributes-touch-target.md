# Touch Target


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


You can set the touch target for components that support universal click events, touch events, and gestures.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| responseRegion | Array&lt;Rectangle&gt;&nbsp;\|&nbsp;Rectangle | {<br/>x:&nbsp;0,<br/>y:&nbsp;0,<br/>width:&nbsp;'100%',<br/>height:&nbsp;'100%'<br/>} | One&nbsp;or&nbsp;more&nbsp;touch&nbsp;targets,&nbsp;including&nbsp;their&nbsp;location&nbsp;and&nbsp;size.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;The&nbsp;percentage&nbsp;is&nbsp;measured&nbsp;relative&nbsp;to&nbsp;the&nbsp;component&nbsp;itself.<br/>>&nbsp;<br/>>&nbsp;**x**&nbsp;and&nbsp;**y**&nbsp;can&nbsp;be&nbsp;set&nbsp;to&nbsp;a&nbsp;positive&nbsp;or&nbsp;negative&nbsp;percentage&nbsp;value.&nbsp;For&nbsp;example,&nbsp;when&nbsp;**x**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'100%'**,&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;offset&nbsp;from&nbsp;the&nbsp;right&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;by&nbsp;the&nbsp;component's&nbsp;width.&nbsp;When&nbsp;**x**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'-100%'**,&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;offset&nbsp;from&nbsp;the&nbsp;left&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;by&nbsp;the&nbsp;component's&nbsp;width.&nbsp;When&nbsp;**y**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'100%'**,&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;offset&nbsp;from&nbsp;the&nbsp;bottom&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;by&nbsp;the&nbsp;component's&nbsp;height.&nbsp;When&nbsp;**y**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'-100%'**,&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;offset&nbsp;from&nbsp;the&nbsp;top&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;by&nbsp;the&nbsp;component's&nbsp;height.<br/>>&nbsp;<br/>>&nbsp;**width**&nbsp;and&nbsp;**height**&nbsp;can&nbsp;only&nbsp;be&nbsp;set&nbsp;to&nbsp;positive&nbsp;percentage&nbsp;values.&nbsp;When&nbsp;**width**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'100%'**,&nbsp;the&nbsp;width&nbsp;of&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;equal&nbsp;to&nbsp;that&nbsp;of&nbsp;the&nbsp;component;&nbsp;when&nbsp;**height**&nbsp;is&nbsp;set&nbsp;to&nbsp;**'100%'**,&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;touch&nbsp;target&nbsp;is&nbsp;equal&nbsp;to&nbsp;that&nbsp;of&nbsp;the&nbsp;component. | 


- Rectangle attributes
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | Length | No | 0vp | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;touch&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;left&nbsp;edge&nbsp;of&nbsp;the&nbsp;component. | 
  | y | Length | No | 0vp | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;touch&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;left&nbsp;edge&nbsp;of&nbsp;the&nbsp;component. | 
  | width | Length | No | 100% | Width&nbsp;of&nbsp;the&nbsp;touch&nbsp;target. | 
  | height | Length | No | 100% | Height&nbsp;of&nbsp;the&nbsp;touch&nbsp;target. | 

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
  > When both **x** and **y** are set to positive values, the entire touch target offsets towards the lower right corner of the component. How much the touch target offsets is subject to the set values.


## Example

  
```
@Entry
@Component
struct ResponseRegionExample {
  build() {
    Column() {
        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .selectedColor(0x39a2db)
          .backgroundColor(0xAFEEEE)
          .responseRegion({ x: 1.0, y: 1.0, width: 400, height: 400 })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218468](figures/en-us_image_0000001212218468.gif)
