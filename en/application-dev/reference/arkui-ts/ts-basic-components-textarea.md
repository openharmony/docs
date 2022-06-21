# TextArea


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **\<TextArea>** component provides multi-line text input.


## Required Permissions

None


## Child Components

Not supported


## APIs

TextArea(value?:{placeholder?: string controller?: TextAreaController})

- Parameters
    | Name                    | Type                                     | Mandatory | Default Value | Description                            |
    | ----------------------- | ---------------------------------------- | --------- | ------------- | -------------------------------------- |
    | placeholder             | string                                   | No        | -             | Text displayed when there is no input. |
    | controller<sup>8+</sup> | [TextAreaController](#textareacontroller8) | No      | -             | Text area controller.                  |


## Attributes

In addition to universal attributes, the following attributes are supported.

| Name                     | Type                                     | Default Value | Description                              |
| ------------------------ | ---------------------------------------- | ------------- | ---------------------------------------- |
| placeholderColor         | Color                                    | -             | Placeholder text color.                  |
| placeholderFont          | {<br/>size?: number,<br/>weight?:number \| [FontWeight](ts-universal-attributes-text-style.md),<br/>family?: string,<br/>style?: [FontStyle](ts-universal-attributes-text-style.md)<br/>} | -             | Placeholder text style.<br/>- **size**: font size. If the value is of the number type, the unit fp is used.<br/>- **weight**: font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight.<br/>- **family**: font family. Use commas (,) to separate multiple fonts, for example, **'Arial, sans-serif'**. The priority of the fonts is the sequence in which they are placed.<br/>- **style**: font style. |
| textAlign                | TextAlign                                | Start         | Text horizontal alignment mode. |
| caretColor               | Color                                    | -             | Color of the caret in the text box. |
| inputFilter<sup>8+</sup> | {<br/>value: [ResourceStr](../../ui/ts-types.md)<sup>8+</sup>,<br/>error?: (value:&nbsp;string)<br/>} | -             | Regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are ignored. The specified regular expression can match single characters, but not strings. Example: ^(? =.\*\d)(? =.\*[a-z])(? =.\*[A-Z]).{8,10}$. Strong passwords containing 8 to 10 characters cannot be filtered.<br/>- **value**: indicates the regular expression to set.<br/>- **error**: returns the ignored content when regular expression matching fails. |
| copyOption<sup>9+</sup> | boolean\|[CopyOption](ts-basic-components-text.md) | true | Whether copy and paste is allowed. |

- TextAlign enums
    | Name   | Description                     |
    | ------ | ------------------------------- |
    | Start  | Aligns the header horizontally. |
    | Center | Horizontal center alignment.    |
    | End    | Align the tail horizontally.    |


## Events

| Name                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| onChange(callback: (value: string) =&gt; void) | Triggered when the input changes.        |
| onCopy<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the copy button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be copied. |
| onCut<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the cut button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be cut. |
| onPaste<sup>8+</sup>(callback:(value: string) =&gt; void) | Triggered when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br/>**value**: text to be pasted. |

## TextAreaController<sup>8+</sup>

Defines the controller for controlling the **&lt;TextArea&gt;** component.

### Objects to Import

```
controller: TextAreaController = new TextAreaController()

```

### caretPosition<sup>8+</sup>

caretPosition(value: number): void

Sets the position of the caret.

- Parameters
  | Name  | Type   | Mandatory | Default Value | Description                                                  |
  | ----- | ------ | --------- | ------------- | ------------------------------------------------------------ |
  | value | number | Yes       | -             | Length from the start of the text string to the position where the caret is located. |


## Example


### Multi-line Text Input


```ts
// xxx.ets
@Entry
@Component
struct TextAreaExample1 {
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


### Setting the Caret

```ts
// xxx.ets
@Entry
@Component
struct TextAreaExample2 {
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
