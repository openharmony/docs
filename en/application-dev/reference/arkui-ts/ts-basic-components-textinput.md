# TextInput


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextInput&gt;** component provides single-line text input.


## Required Permissions

None


## Child Components

None


## APIs

TextInput(value?:{placeholder?: string controller?: TextInputController})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | placeholder | string | No | - | Text&nbsp;displayed&nbsp;when&nbsp;there&nbsp;is&nbsp;no&nbsp;input. | 
  | controller<sup>8+</sup> | [TextInputController](#textinputcontroller8) | No | - | Text&nbsp;input&nbsp;controller. | 


## Attributes

In addition to [universal attributes](ts-universal-attributes.md), the following attributes are supported.

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| type | InputType | InputType.Normal | Input&nbsp;box&nbsp;type. |
| placeholderColor | Color | - | Placeholder&nbsp;color. |
| placeholderFont | {<br/>size?:&nbsp;Length,<br/>weight?:&nbsp;number\|[FontWeight](ts-universal-attributes-text-style.md),<br/>family?:&nbsp;string,<br/>style?:&nbsp;[FontStyle](ts-universal-attributes-text-style.md)<br/>} | - | Placeholder&nbsp;text&nbsp;style.<br/>-&nbsp;**size**:&nbsp;font&nbsp;size.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;unit&nbsp;fp&nbsp;is&nbsp;used.<br/>-&nbsp;**weight**:&nbsp;font&nbsp;weight.&nbsp;For&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;value&nbsp;ranges&nbsp;from&nbsp;100&nbsp;to&nbsp;900,&nbsp;at&nbsp;an&nbsp;interval&nbsp;of&nbsp;100.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**400**.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;larger&nbsp;font&nbsp;weight.<br/>-&nbsp;**family**:&nbsp;font&nbsp;family.&nbsp;Use&nbsp;commas&nbsp;(,)&nbsp;to&nbsp;separate&nbsp;multiple&nbsp;fonts,&nbsp;for&nbsp;example,&nbsp;**'Arial,&nbsp;sans-serif'**.&nbsp;The&nbsp;priority&nbsp;of&nbsp;the&nbsp;fonts&nbsp;is&nbsp;the&nbsp;sequence&nbsp;in&nbsp;which&nbsp;they&nbsp;are&nbsp;placed.<br/>-&nbsp;**style**:&nbsp;font&nbsp;style. |
| enterKeyType | EnterKeyType | EnterKeyType.Done | How&nbsp;the&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled. |
| caretColor | Color | - | Color&nbsp;of&nbsp;the&nbsp;caret&nbsp;(also&nbsp;known&nbsp;as&nbsp;the&nbsp;text&nbsp;insertion&nbsp;cursor). |
| maxLength<sup>8+</sup> | number | - | Maximum&nbsp;number&nbsp;of&nbsp;characters&nbsp;in&nbsp;the&nbsp;text&nbsp;input. |
| inputFilter<sup>8+</sup> | {<br/>value:&nbsp;[ResourceStr](../../ui/ts-types.md#resourcestr8),<br/>error?:&nbsp;(value:&nbsp;string)<br/>} | - | Regular&nbsp;expression&nbsp;for&nbsp;input&nbsp;filtering.&nbsp;Only&nbsp;inputs&nbsp;that&nbsp;comply&nbsp;with&nbsp;the&nbsp;regular&nbsp;expression&nbsp;can&nbsp;be&nbsp;displayed.&nbsp;Other&nbsp;inputs&nbsp;are&nbsp;ignored.&nbsp;The&nbsp;specified&nbsp;regular&nbsp;expression&nbsp;can&nbsp;match&nbsp;single&nbsp;characters,&nbsp;but&nbsp;not&nbsp;strings.&nbsp;Example:&nbsp;^(?&nbsp;=.\*\d)(?&nbsp;=.\*[a-z])(?&nbsp;=.\*[A-Z]).{8,10}$.&nbsp;Strong&nbsp;passwords&nbsp;containing&nbsp;8&nbsp;to&nbsp;10&nbsp;characters&nbsp;cannot&nbsp;be&nbsp;filtered.<br/>-&nbsp;**value**:&nbsp;indicates&nbsp;the&nbsp;regular&nbsp;expression&nbsp;to&nbsp;set.<br/>-&nbsp;**error**:&nbsp;returns&nbsp;the&nbsp;ignored&nbsp;content&nbsp;when&nbsp;regular&nbsp;expression&nbsp;matching&nbsp;fails. |

- EnterKeyType enums
    | Name | Description | 
  | -------- | -------- |
  | EnterKeyType.Go | The&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled&nbsp;"Go." | 
  | EnterKeyType.Search | The&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled&nbsp;"Search." | 
  | EnterKeyType.Send | The&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled&nbsp;"Send." | 
  | EnterKeyType.Next | The&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled&nbsp;"Next." | 
  | EnterKeyType.Done | The&nbsp;Enter&nbsp;key&nbsp;is&nbsp;labeled&nbsp;"Done." | 

- InputType enums
    | Name | Description | 
  | -------- | -------- |
  | InputType.Normal | Normal&nbsp;input&nbsp;mode. | 
  | InputType.Password | Password&nbsp;input&nbsp;mode. | 
  | InputType.Email | Email&nbsp;address&nbsp;input&nbsp;mode. | 
  | InputType.Number | Digit&nbsp;input&nbsp;mode. | 


### TextInputController<sup>8+</sup>

Implements the controller of the **&lt;TextInput&gt;** component.

  | Name | Description | 
| -------- | -------- |
| caretPosition(value:&nbsp;number):void | Position&nbsp;of&nbsp;the&nbsp;input&nbsp;cursor.<br/>**value**:&nbsp;indicates&nbsp;the&nbsp;length&nbsp;from&nbsp;the&nbsp;start&nbsp;of&nbsp;the&nbsp;string&nbsp;to&nbsp;the&nbsp;position&nbsp;where&nbsp;the&nbsp;input&nbsp;cursor&nbsp;is&nbsp;located. | 


### Objects to Import


```
controller: TextInputController = new TextInputController()
```


### controller.createPosition

caretPosition(value: number): void

Sets the cursor in a specified position.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Position&nbsp;of&nbsp;the&nbsp;input&nbsp;cursor.<br/>**value**:&nbsp;indicates&nbsp;the&nbsp;length&nbsp;from&nbsp;the&nbsp;start&nbsp;of&nbsp;the&nbsp;string&nbsp;to&nbsp;the&nbsp;position&nbsp;where&nbsp;the&nbsp;input&nbsp;cursor&nbsp;is&nbsp;located. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(value:&nbsp;string)&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;input&nbsp;changes. | 
| onSubmit(callback:&nbsp;(enterKey:&nbsp;EnterKeyType)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;Enter&nbsp;key&nbsp;on&nbsp;the&nbsp;physical&nbsp;or&nbsp;soft&nbsp;keyboard&nbsp;is&nbsp;pressed. | 
| onEditChanged(callback:&nbsp;(isEditing:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;input&nbsp;status&nbsp;changes. | 
| onCopy<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;copy&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;copied. | 
| onCut<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;cut&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;cut. | 
| onPaste<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;the&nbsp;paste&nbsp;button&nbsp;on&nbsp;the&nbsp;pasteboard,&nbsp;which&nbsp;displays&nbsp;when&nbsp;the&nbsp;text&nbsp;box&nbsp;is&nbsp;long&nbsp;pressed,&nbsp;is&nbsp;clicked.<br/>**value**:&nbsp;text&nbsp;to&nbsp;be&nbsp;pasted. | 


## Example


### Single-line Text Input


```
@Entry
@Component
struct TextAreaExample2 {
  @State text: string = ''

  build() {
    Column() {
      TextArea({ placeholder: 'input your word' })
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
        .onChange((value: string) => {
          this.text = value
        })
      Text(this.text).width('90%')
    }
  }
}
```


![en-us_image_0000001212378402](figures/en-us_image_0000001212378402.gif)


### Setting the Input Cursor


```
@Entry
@Component
struct TextInputTest {
    @State text: string = ''
    controller: TextInputController = new TextInputController()
    build() {
        Column() {
            TextInput({ placeholder: 'Please input your words.', controller:this.controller})
            Button('caretPosition')
                .onClick(() => {
                this.controller.caretPosition(4)
            })
        }
    }
}
```

![en-us_image_0000001212058468](figures/en-us_image_0000001212058468.png)
