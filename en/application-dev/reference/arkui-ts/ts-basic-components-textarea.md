# TextArea


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextArea&gt;** component provides multi-line text input.


## Required Permissions

None


## Child Component

N/A


## APIs

TextArea(value?:{placeholder?: string controller?: TextAreaController})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | placeholder | string | No | - | Text&nbsp;displayed&nbsp;when&nbsp;there&nbsp;is&nbsp;no&nbsp;input. | 
  | controller<sup>8+</sup> | [TextAreaController](#textareacontroller8) | No | - | Text&nbsp;area&nbsp;controller. | 


## Attributes

In addition to [universal attributes](ts-universal-attributes.md), the following attributes are supported.

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| placeholderColor | Color | - | Placeholder&nbsp;text&nbsp;color. |
| placeholderFont | {<br/>size?:&nbsp;number,<br/>weight?:number&nbsp;\|&nbsp;[FontWeight](ts-universal-attributes-text-style.md),<br/>family?:&nbsp;string,<br/>style?:&nbsp;[FontStyle](ts-universal-attributes-text-style.md)<br/>} | - | Placeholder&nbsp;text&nbsp;style.<br/>-&nbsp;**size**:&nbsp;font&nbsp;size.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;unit&nbsp;fp&nbsp;is&nbsp;used.<br/>-&nbsp;**weight**:&nbsp;font&nbsp;weight.&nbsp;For&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;value&nbsp;ranges&nbsp;from&nbsp;100&nbsp;to&nbsp;900,&nbsp;at&nbsp;an&nbsp;interval&nbsp;of&nbsp;100.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**400**.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;larger&nbsp;font&nbsp;weight.<br/>-&nbsp;**family**:&nbsp;font&nbsp;family.&nbsp;Use&nbsp;commas&nbsp;(,)&nbsp;to&nbsp;separate&nbsp;multiple&nbsp;fonts,&nbsp;for&nbsp;example,&nbsp;**'Arial,&nbsp;sans-serif'**.&nbsp;The&nbsp;priority&nbsp;of&nbsp;the&nbsp;fonts&nbsp;is&nbsp;the&nbsp;sequence&nbsp;in&nbsp;which&nbsp;they&nbsp;are&nbsp;placed.<br/>-&nbsp;**style**:&nbsp;font&nbsp;style. |
| textAlign | TextAlign | Start | Sets&nbsp;the&nbsp;text&nbsp;horizontal&nbsp;alignment&nbsp;mode. |
| caretColor | Color | - | Sets&nbsp;the&nbsp;color&nbsp;of&nbsp;the&nbsp;cursor&nbsp;in&nbsp;the&nbsp;text&nbsp;box. |
| inputFilter<sup>8+</sup> | {<br/>value:&nbsp;[ResourceStr](../../ui/ts-types.md),<br/>error?:&nbsp;(value:&nbsp;string)<br/>} | - | Regular&nbsp;expression&nbsp;for&nbsp;input&nbsp;filtering.&nbsp;Only&nbsp;inputs&nbsp;that&nbsp;comply&nbsp;with&nbsp;the&nbsp;regular&nbsp;expression&nbsp;can&nbsp;be&nbsp;displayed.&nbsp;Other&nbsp;inputs&nbsp;are&nbsp;ignored.&nbsp;The&nbsp;specified&nbsp;regular&nbsp;expression&nbsp;can&nbsp;match&nbsp;single&nbsp;characters,&nbsp;but&nbsp;not&nbsp;strings.&nbsp;Example:&nbsp;^(?&nbsp;=.\*\d)(?&nbsp;=.\*[a-z])(?&nbsp;=.\*[A-Z]).{8,10}$.&nbsp;Strong&nbsp;passwords&nbsp;containing&nbsp;8&nbsp;to&nbsp;10&nbsp;characters&nbsp;cannot&nbsp;be&nbsp;filtered.<br/>-&nbsp;**value**:&nbsp;indicates&nbsp;the&nbsp;regular&nbsp;expression&nbsp;to&nbsp;set.<br/>-&nbsp;**error**:&nbsp;returns&nbsp;the&nbsp;ignored&nbsp;content&nbsp;when&nbsp;regular&nbsp;expression&nbsp;matching&nbsp;fails. |

- TextAlign enums
    | Name | Description | 
  | -------- | -------- |
  | Start | Aligns&nbsp;the&nbsp;header&nbsp;horizontally. | 
  | Center | Horizontal&nbsp;center&nbsp;alignment. | 
  | End | Align&nbsp;the&nbsp;tail&nbsp;horizontally. | 


### TextAreaController<sup>8+</sup>

Defines the controller for controlling the **&lt;TextArea&gt;** component.

  | Name | Description | 
| -------- | -------- |
| caretPosition(value:&nbsp;number):&nbsp;void | Position&nbsp;of&nbsp;the&nbsp;input&nbsp;cursor.<br/>**value**:&nbsp;indicates&nbsp;the&nbsp;length&nbsp;from&nbsp;the&nbsp;start&nbsp;of&nbsp;the&nbsp;string&nbsp;to&nbsp;the&nbsp;position&nbsp;where&nbsp;the&nbsp;input&nbsp;cursor&nbsp;is&nbsp;located. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;input&nbsp;changes. | 
| onCopy<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;copy&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;copied. | 
| onCut<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;cut&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;cut. | 
| onPaste<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;paste&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;pasted. | 


## Example


### Multi-line Text Input


```
@Entry
@Component
struct TextAreaExample2 {
  @State text: string = ''
  build() {
    Column() {
      TextArea({ placeholder: 'input your word'})
        .placeholderColor("rgb(0,0,225)")
        .placeholderFont({ size: 30, weight: 100, family: 'cursive', style: FontStyle.Italic })
        .textAlign(TextAlign.Center)
        .caretColor(Color.Blue)
        .height(50)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .fontFamily("sans-serif")
        .fontStyle(FontStyle.Normal)
        .fontColor(Color.Red)
        .inputFilter('^[\u4E00-\u9FA5A-Za-z0-9_]+$',(value: string) => {
          console.info("hyb"+value)
        })
        .onChange((value: string) => {
          this.text = value
        })
      Text(this.text).width('90%')
    }
  }
}
```

![en-us_image_0000001256858399](figures/en-us_image_0000001256858399.gif)


### Setting the Input Cursor


```
@Entry
@Component
struct TextAreaTest {
    controller: TextAreaController = new TextAreaController()
    build() {
        Column() {
            TextArea({ placeholder: 'input your word',controller:this.controller })
            Button('caretPosition')
                .onClick(() => {
                    this.controller.caretPosition(4)
                })
          }
    }
}
```

![en-us_image_0000001212058476](figures/en-us_image_0000001212058476.png)
