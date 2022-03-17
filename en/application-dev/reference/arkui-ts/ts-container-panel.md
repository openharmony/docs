# Panel


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Panel&gt;** component is a slidable panel that presents lightweight content with flexible sizes. It is a pop-up component.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Panel(value:{show:boolean})

- Parameter
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | show | boolean | Yes | - | Whether&nbsp;the&nbsp;panel&nbsp;is&nbsp;shown&nbsp;or&nbsp;hidden. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| type | PanelType | PanelType.Foldable | Type&nbsp;of&nbsp;the&nbsp;panel. | 
| mode | PanelMode | - | Initial&nbsp;status&nbsp;of&nbsp;the&nbsp;panel. | 
| dragBar | boolean | true | Whether&nbsp;to&nbsp;enable&nbsp;a&nbsp;drag&nbsp;bar.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;that&nbsp;the&nbsp;drag&nbsp;bar&nbsp;will&nbsp;be&nbsp;displayed,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;the&nbsp;opposite. | 
| fullHeight | Length | - | Panel&nbsp;height&nbsp;in&nbsp;the&nbsp;**PanelMode.Full**&nbsp;mode. | 
| halfHeight | Length | - | Panel&nbsp;height&nbsp;in&nbsp;the&nbsp;**PanelMode.Half**&nbsp;mode.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;half&nbsp;of&nbsp;the&nbsp;screen&nbsp;height. | 
| miniHeight | Length | - | Panel&nbsp;height&nbsp;in&nbsp;the&nbsp;**PanelMode.Mini**&nbsp;mode. | 

- PanelType enums
    | Name | Description | 
  | -------- | -------- |
  | Minibar | A&nbsp;minibar&nbsp;panel&nbsp;displays&nbsp;content&nbsp;in&nbsp;the&nbsp;minibar&nbsp;area&nbsp;or&nbsp;a&nbsp;large&nbsp;(fullscreen-like)&nbsp;area. | 
  | Foldable | A&nbsp;foldable&nbsp;panel&nbsp;displays&nbsp;permanent&nbsp;content&nbsp;in&nbsp;a&nbsp;large&nbsp;(fullscreen-like),&nbsp;medium-sized&nbsp;(halfscreen-like),&nbsp;or&nbsp;small&nbsp;area. | 
  | Temporary | A&nbsp;temporary&nbsp;panel&nbsp;displays&nbsp;content&nbsp;in&nbsp;a&nbsp;large&nbsp;(fullscreen-like)&nbsp;or&nbsp;medium-sized&nbsp;(halfscreen-like)&nbsp;area. | 

- PanelMode enums
    | Name | Description | 
  | -------- | -------- |
  | Mini | Displays&nbsp;a&nbsp;**minibar**&nbsp;or&nbsp;**foldable**&nbsp;panel&nbsp;in&nbsp;its&nbsp;minimum&nbsp;size.&nbsp;This&nbsp;attribute&nbsp;does&nbsp;not&nbsp;take&nbsp;effect&nbsp;for&nbsp;**temporary**&nbsp;panels. | 
  | Half | Displays&nbsp;a&nbsp;**foldable**&nbsp;or&nbsp;**temporary**&nbsp;panel&nbsp;in&nbsp;a&nbsp;medium-sized&nbsp;(halfscreen-like)&nbsp;area.&nbsp;This&nbsp;attribute&nbsp;does&nbsp;not&nbsp;take&nbsp;effect&nbsp;for&nbsp;**minibar**&nbsp;panels. | 
  | Full | Displays&nbsp;a&nbsp;panel&nbsp;in&nbsp;a&nbsp;large&nbsp;(fullscreen-like)&nbsp;area. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:&nbsp;(width:&nbsp;number,&nbsp;height:&nbsp;number,&nbsp;mode:&nbsp;PanelMode)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;status&nbsp;of&nbsp;the&nbsp;panel&nbsp;changes.&nbsp;The&nbsp;returned&nbsp;height&nbsp;value&nbsp;is&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;content&nbsp;area.&nbsp;When&nbsp;the&nbsp;value&nbsp;of&nbsp;**dragbar**&nbsp;is&nbsp;**true**,&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;panel&nbsp;is&nbsp;the&nbsp;dragbar&nbsp;height&nbsp;plus&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;content&nbsp;area. | 


## Example


```
@Entry
@Component
struct PanelExample {
  @State show: boolean = false

  build() {
    Column() {
      Text('2021-09-30    Today Calendar: 1.afternoon......Click for details')
        .width('90%').height(50).borderRadius(10)
        .backgroundColor(0xFFFFFF).padding({ left: 20 })
        .onClick(() => {
          this.show = !this.show
        })
      Panel(this.show) { // Display the agenda.
        Column() {
          Text('Today Calendar')
          Divider()
          Text('1. afternoon 4:00 The project meeting')
        }
      }
      .type(PanelType.Foldable).mode(PanelMode.Half)
      .dragBar(true) // The dragbar is enabled by default.
      .halfHeight(500) // Half of the height by default
      .onChange((value: any) => {
        console.info(`width:${value.width},height:${value.height},mode:${value.mode}`)
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001256978381](figures/en-us_image_0000001256978381.gif)
