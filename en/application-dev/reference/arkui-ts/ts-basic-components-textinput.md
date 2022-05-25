# TextInput

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextInput&gt;** component provides single-line text input.


## Required Permissions

None


## Child Components

None


## APIs

TextInput(value?:{placeholder?: string controller?: TextInputController})

- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | placeholder | string | No | - | Text displayed when there is no input. |
  | controller<sup>8+</sup> | [TextInputController](#textinputcontroller8) | No | - | Text input controller. |


## Attributes

In addition to universal attributes, the following attributes are supported.

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| type | InputType | InputType.Normal | Input box type. |
| placeholderColor | Color | - | Placeholder color. |
| placeholderFont | {<br/>size?: Length,<br/>weight?: number\|[FontWeight](ts-universal-attributes-text-style.md),<br/>family?: string,<br/>style?: [FontStyle](ts-universal-attributes-text-style.md)<br/>} | - | Placeholder text style.<br/>- **size**: font size. If the value is of the number type, the unit fp is used.<br/>- **weight**: font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight.<br/>- **family**: font family. Use commas (,) to separate multiple fonts, for example, **'Arial, sans-serif'**. The priority of the fonts is the sequence in which they are placed.<br/>- **style**: font style. |
| enterKeyType | EnterKeyType | EnterKeyType.Done | How the Enter key is labeled. |
| caretColor | Color | - | Color of the caret (also known as the text insertion cursor). |
| maxLength<sup>8+</sup> | number | - | Maximum number of characters in the text input. |
| inputFilter<sup>8+</sup> | {<br/>value: [ResourceStr](../../ui/ts-types.md)<sup>8+</sup>,<br/>error?: (value: string)<br/>} | - | Regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are ignored. The specified regular expression can match single characters, but not strings. Example: ^(? =.\*\d)(? =.\*[a-z])(? =.\*[A-Z]).{8,10}$. Strong passwords containing 8 to 10 characters cannot be filtered.<br/>- **value**: indicates the regular expression to set.<br/>- **error**: returns the ignored content when regular expression matching fails. |

- EnterKeyType enums
    | Name | Description |
  | -------- | -------- |
  | EnterKeyType.Go | The Enter key is labeled "Go." |
  | EnterKeyType.Search | The Enter key is labeled "Search." |
  | EnterKeyType.Send | The Enter key is labeled "Send." |
  | EnterKeyType.Next | The Enter key is labeled "Next." |
  | EnterKeyType.Done | The Enter key is labeled "Done." |

- InputType enums
    | Name | Description |
  | -------- | -------- |
  | InputType.Normal | Normal input mode. |
  | InputType.Password | Password input mode. |
  | InputType.Email | Email address input mode. |
  | InputType.Number | Digit input mode. |


## Events

| Name | Description |
| -------- | -------- |
| onChange(value: string) =&gt; void | Triggered when the input changes. |
| onSubmit(callback: (enterKey: EnterKeyType) =&gt; void) | Triggered when the Enter key on the physical or soft keyboard is pressed. |
| onEditChanged(callback:&nbsp;(isEditing:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)<sup>(deprecated) </sup> | Triggered when the input status changes. |
| onEditChange(callback:&nbsp;(isEditing:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) <sup>8+</sup> | Triggered when the input status changes. |
| onCopy<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the copy button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be copied. |
| onCut<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the cut button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be cut. |
| onPaste<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be pasted. |

### TextInputController<sup>8+</sup>

Implements the controller of the **&lt;TextInput&gt;** component.


### Objects to Import


```
controller: TextInputController = new TextInputController()
```


#### caretPosition

caretPosition(value: number): void

Sets the cursor in a specified position.

- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Position of the input cursor.<br/>**value**: indicates the length from the start of the string to the position where the input cursor is located. |



## Example


### Single-line Text Input


```
@Entry
@Component
struct TextInputExample1 {
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
struct TextInputExample2 {
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
