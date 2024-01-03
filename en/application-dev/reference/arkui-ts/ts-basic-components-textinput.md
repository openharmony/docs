# TextInput

The **\<TextInput>** component provides single-line text input.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TextInput(value?:{placeholder?: ResourceStr, text?: ResourceStr, controller?: TextInputController})

**Parameters**

| Name                    | Type                                    | Mandatory  | Description           |
| ----------------------- | ---------------------------------------- | ---- | --------------- |
| placeholder   | [ResourceStr](ts-types.md#resourcestr)       | No   | Text displayed when there is no input.     |
| text          | [ResourceStr](ts-types.md#resourcestr)       | No   | Current text input.<br>If the component has [stateStyles](ts-universal-attributes-polymorphic-style.md) or any other attribute that may trigger updating configured, you are advised to bind the state variable to the text in real time through the **onChange** event, so as to prevent display errors when the component is updated.<br>Since API version 10, this parameter supports two-way binding through [$$](../../quick-start/arkts-two-way-sync.md). |
| controller<sup>8+</sup> | [TextInputController](#textinputcontroller8) | No   | Text input controller.|

## Attributes

Among the [universal attributes](ts-universal-attributes-size.md) and [universal text attributes](ts-universal-attributes-text-style.md), **fontColor**, **fontSize**, **fontStyle**, **fontWeight**, and **fontFamily** are supported. In addition, the following attributes are supported.

| Name                      | Type                                    | Description                                      |
| ------------------------ | ---------------------------------------- | ---------------------------------------- |
| type                     | [InputType](#inputtype)     | Text box type.<br>Default value: **InputType.Normal**       |
| placeholderColor         | [ResourceColor](ts-types.md#resourcecolor)     | Placeholder text color.<br>The default value follows the theme.  |
| placeholderFont          | [Font](ts-types.md#font) | Placeholder text font.|
| enterKeyType             | [EnterKeyType](#enterkeytype) | Type of the Enter key.<br>Default value: **EnterKeyType.Done**|
| caretColor               | [ResourceColor](ts-types.md#resourcecolor)    | Color of the caret in the text box.<br>Default value: **'#007DFF'**                               |
| maxLength                | number                                   | Maximum number of characters in the text input.                           |
| inputFilter<sup>8+</sup> | {<br>value: [ResourceStr](ts-types.md#resourcestr),<br>error?: (value: string) =&gt; void<br>} | Regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are filtered out. The regular expression can match single characters, but not strings.<br>- **value**: regular expression to set.<br>- **error**: filtered-out content to return when regular expression matching fails.<br>Since API version 11, setting **inputFilter** will invalidate the text filtering effect brought by setting the **type** attribute.|
| copyOption<sup>9+</sup>  | [CopyOptions](ts-appendix-enums.md#copyoptions9) | Whether copy and paste is allowed.<br>Default value: **CopyOptions.LocalDevice**<br>If this attribute is set to **CopyOptions.None**, the paste operation is allowed, but not the copy or cut operation.|
| showPasswordIcon<sup>9+</sup> | boolean | Whether to display the password icon at the end of the password text box.<br>Default value: **true**|
| style<sup>9+</sup> | [TextInputStyle](#textinputstyle9) \| [TextContentStyle](ts-appendix-enums.md#textcontentstyle10) | Text input style. For the inline input style, only **InputType.Normal** is supported.<br>Default value: **TextInputStyle.Default**|
| textAlign<sup>9+</sup>   | [TextAlign](ts-appendix-enums.md#textalign) | Horizontal alignment of the text.<br>Default value: **TextAlign.Start**<br>**NOTE**<br>Available options are **TextAlign.Start**, **TextAlign.Center**, and **TextAlign.End**.<br>To set vertical alignment for the text, use the [align](ts-universal-attributes-location.md) attribute. The **align** attribute alone does not control the horizontal position of the text. In other words, **Alignment.TopStart**, **Alignment.Top**, and **Alignment.TopEnd** produce the same effect, top-aligning the text; **Alignment.Start**, **Alignment.Center**, and **Alignment.End** produce the same effect, centered-aligning the text vertically; **Alignment.BottomStart**, **Alignment.Bottom**, and **Alignment.BottomEnd** produce the same effect, bottom-aligning the text. |
| selectedBackgroundColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | Background color of the selected text.<br>If the opacity is not set, a 20% opacity will be used.|
| caretStyle<sup>10+</sup> | {<br>width: [Length](ts-types.md#length)<br>} | Caret style. It cannot be set in percentage.                                       |
| caretPosition<sup>10+</sup> | number | Caret position.|
| showUnit<sup>10+</sup>                | [CustomBuilder](ts-types.md#custombuilder8)       | Unit for content in the component.<br>By default, there is no unit.<br>This attribute must be used together with **showUnderline**. It is effective only when **showUnderline** is set to **true**.|
| showError<sup>10+</sup> | string \| undefined | Error message displayed when an error occurs.<br>By default, no error message is displayed.<br>**NOTE**<br>If the parameter type is string and the input content does not comply with specifications, the error message is displayed. If the parameter type is undefined, no error message is displayed. See [Example 2](#example-2).|
| showUnderline<sup>10+</sup> | boolean | Whether to show an underline. By default, the underline comes in the color of **'#33182431'**, thickness of 1 px, and text box size of 48 vp. The underline supports only the **InputType.Normal** type.<br>Default value: **false**|
| passwordIcon<sup>10+</sup> | [PasswordIcon](#passwordicon10) | Password icon to display at the end of the password text box.<br>By default, the system-provided icon is used.|
| enableKeyboardOnFocus<sup>10+</sup> | boolean | Whether to enable the input method when the component obtains focus.<br>Default value: **true**  |
| selectionMenuHidden<sup>10+</sup> | boolean | Whether to display the text selection menu when the text box is long-pressed or right-clicked.<br>Default value: **false**|
| barState<sup>10+</sup> | [BarState](ts-appendix-enums.md#barstate) | Scrollbar state when the inline input style is used.<br>Default value: **BarState.Auto**|
| maxLines<sup>10+</sup> | number | Maximum number of lines that can be displayed when the inline input style is used.<br>Default value: **3**<br>**NOTE**<br>Value range: (0, +∞)|
| customKeyboard<sup>10+</sup> | [CustomBuilder](ts-types.md#custombuilder8) | Custom keyboard.<br>**NOTE**<br>When a custom keyboard is set, activating the text box opens the specified custom component, instead of the system input method, and the **enterKeyType** attribute setting for the system keyboard will not take effect.<br>The custom keyboard's height can be set through the **height** attribute of the custom component's root node, and its width is fixed at the default value.<br>The custom keyboard is displayed on top of the current page, without compressing or raising the page.<br>The custom keyboard cannot obtain the focus, but it blocks gesture events.<br>By default, the custom keyboard is closed when the input component loses the focus. You can also use the [TextInputController](#textinputcontroller8).[stopEditing](#stopediting10) API to close the keyboard.|
| enableAutoFill<sup>11+<sup> | boolean | Whether to enable autofill. **true**: enable<br>**false**: disable<br> Default value: **true**|
| passwordRules<sup>11+<sup> | string | Rules for generating passwords.|
| cancelButton<sup>11+</sup> | {<br>style? : [CancelButtonStyle](ts-basic-components-search.md#cancelbuttonstyle10)<br>icon?: [IconOptions](ts-basic-components-search.md#iconoptions10) <br>} | Style of the Cancel button on the right.<br>Default value:<br>{<br>style: CancelButtonStyle.INPUT<br>}<br>The inline mode is not supported.|
| selectAll<sup>11+</sup> | boolean | Whether to select all text in the initial state.<br>Default value: **false**|
| showCounter<sup>11+</sup> | value: boolean, options?: [InputCounterOptions](#inputcounteroptions11) | Counter settings. **options** can be set only when **value** is set to **true**, in which case a character counter is displayed below the text box. This attribute must be used together with **maxlength**. The character counter is displayed in this format: Number of characters that have been entered/Maximum number of characters allowed. It is visible when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. If **options** is not set, the text box border turns red when the number of entered characters reaches the maximum. If **value** is set to **true** and **options** is set, the text box border turns red and the text box shakes when the number of entered characters reaches the maximum, provided that the value of **thresholdPercentage** is valid. If **highlightBorder** is set to **false**, the text box border does not turn red. By default, **highlightBorder** is set to **true**. For the **\<TextInput>** component to show the border, configure it to show an underline. When the component is in inline or password input style, the counter is not displayed. |
>  **NOTE**
>
>  The default value of the universal attribute [padding](ts-universal-attributes-size.md) is as follows:<br>{<br> top: 8 vp,<br> right: 16 vp,<br> bottom: 8 vp,<br> left: 16 vp<br> }
>
>  Since API version 10, **.width('auto')** can be set for the **\<TextInput>** component. Under this setting, the component auto-adapts its width to the text width, while respecting the **constraintSize** configuration and the maximum and minimum width restrictions received by the parent container. For details, see [Size](ts-universal-attributes-size.md#attributes).      

## SubmitEvent<sup>11+</sup>

Defines the user submission event.

| Name| Type| Mandatory| Description                              |
| ------ | -------- | ---- | -------------------------------------- |
| keepEditableState| ?(() => void) | No| Editing status of the text box.<br> When this API is called, the text box remains in editing state.|
| text| string | No| Text in the text box.|

## EnterKeyType

| Name                 | Description       |
| ------------------- | --------- |
| Go     | The Enter key is labeled "Go."  |
| Search | The Enter key is labeled "Search." |
| Send   | The Enter key is labeled "Send." |
| Next   | The Enter key is labeled "Next."|
| Done   | The Enter key     |
| PREVIOUS<sup>11+</sup>   | The Enter key is labeled "Previous."  |
| NEW_LINE<sup>11+</sup>   | The Enter key is labeled "Return."    |

## InputType

| Name                | Description           |
| ------------------ | ------------- |
| Normal   | Normal input mode.<br>The value can contain digits, letters, underscores (_), spaces, and special characters.|
| Password | Password input mode. The value can contain digits, letters, underscores (_), spaces, and special characters. An eye icon is used to show or hide the password, and the password is hidden behind dots by default. The password input mode does not support underlines.|
| Email    | Email address input mode. The value can contain digits, letters, underscores (_), and commas (,). and one at sign (@).|
| Number   | Digit input mode.     |
| PhoneNumber<sup>9+</sup> | Phone number input mode.<br>The value can contain digits, plus signs (+), hyphens (-), asterisks (*), and number signs (#). The length is not limited.|
| USER_NAME<sup>11+<sup> | Username input mode.|
| NEW_PASSWORD<sup>11+<sup> | New password input mode.|
| NUMBER_PASSWORD<sup>11+</sup> | Numeric password input mode. An eye icon is used to show or hide the password, and the password is hidden behind dots by default. The password input mode does not support underlines.|
| SCREEN_LOCK_PASSWORD<sup>11+</sup> | Lock screen password input mode. The value can contain digits, letters, underscores (_), spaces, and special characters. An eye icon is used to show or hide the password, and the password is hidden behind dots by default. The password input mode does not support underlines.<br>**System API**: This is a system API.|
| NUMBER_DECIMAL<sup>11+</sup>  | Number input mode with a decimal point. The value can contain digits and one decimal point.|

## TextInputStyle<sup>9+</sup>

| Name                | Description           |
| ------------------ | ------------- |
| Default   | Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and font size of the selected text.  |
| Inline    | Inline input style. The background height of the selected text is the same as the height of the text box.<br>This style is used in scenarios where editing and non-editing states are obvious, for example, renaming in the file list view.<br>The **showError** attribute is not supported for this style.|

## PasswordIcon<sup>10+</sup>

| Name      | Type                                                    | Mandatory| Description                                              |
| ---------- | -------------------------------------------------------- | ---- | -------------------------------------------------- |
| onIconSrc  | string \| [Resource](ts-types.md#resource)| No  | Icon that can be used to hide the password in password input mode.|
| offIconSrc | string \| [Resource](ts-types.md#resource)| No  | Icon that can be used to show the password in password input mode.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onChange(callback: (value: string) =&gt; void) | Triggered when the input in the text box changes.<br>**value**: text content.<br>This event is triggered when any of the following conditions is met:<br>1. Keyboard input is received.<br>2. Paste and cut is performed.<br>3. Ctrl+V is pressed.|
| onSubmit(callback: (enterKey: EnterKeyType, event<sup>11+</sup>: SubmitEvent) =&gt; void) | Triggered when the Enter key on the keyboard is pressed.<br>**enterKey**: type of the Enter key. If it is **EnterKeyType.NEW_LINE** and the text box is in inline input style, **onSubmit** is not triggered. For details, see [EnterKeyType](#enterkeytype).<br>**event**: submission event. For details, see [SubmitEvent](#submitevent11).|
| onEditChanged(callback: (isEditing: boolean) =&gt; void)<sup>(deprecated)</sup> | Triggered when the input status changes. Since API version 8, **onEditChange** is recommended.|
| onEditChange(callback: (isEditing: boolean) =&gt; void)<sup>8+</sup> | Triggered when the input status changes. The text box is in the editing state when the caret is placed in it. If the value of **isEditing** is **true**, text input is in progress.|
| onCopy(callback:(value: string) =&gt; void)<sup>8+</sup> | Triggered when the copy button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>**value**: text to be copied.|
| onCut(callback:(value: string) =&gt; void)<sup>8+</sup> | Triggered when the cut button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>**value**: text to be cut.|
| onPaste(callback:(value: string, event<sup>11+</sup>: [PasteEvent](ts-basic-components-richeditor.md#pasteevent11)) =&gt; void) | Triggered when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>**value**: text to be pasted.<br>**event**: custom paste event.|
| onTextSelectionChange(callback: (selectionStart: number, selectionEnd: number) => void)<sup>10+</sup> | Triggered when the text selection position changes.<br>**selectionStart**: start position of the text selection area. The start position of text in the text box is **0**.<br>**selectionEnd**: end position of the text selection area.|
| onContentScroll(callback: (totalOffsetX: number, totalOffsetY: number) => void)<sup>10+</sup> | Triggered when the text content is scrolled.<br>**totalOffsetX**: X coordinate offset of the text in the content area.<br>**totalOffsetY**: Y coordinate offset of the text in the content area.|

## TextInputController<sup>8+</sup>

Implements the controller of the **\<TextInput>** component.

### Objects to Import
```
controller: TextInputController = new TextInputController()
```
### caretPosition<sup>8+</sup>

caretPosition(value: number): void

Sets the position of the caret.

**Parameters**

| Name| Type| Mandatory| Description                              |
| ------ | -------- | ---- | -------------------------------------- |
| value  | number   | Yes  | Length from the start of the string to the position where the caret is located.|
### setTextSelection<sup>10+</sup>

setTextSelection(selectionStart: number, selectionEnd: number): void

Sets the text selection area, which will be highlighted.

**Parameters**

| Name        | Type| Mandatory| Description              |
| -------------- | -------- | ---- | ---------------------- |
| selectionStart | number   | Yes  | Start position of the text selection range. The start position of text in the text box is 0.|
| selectionEnd   | number   | Yes  | End position of the text selection range.|
>  **NOTE**
>
>  If **selectionStart** or **selectionEnd** is set to **undefined**, the value **0** will be used.
### stopEditing<sup>10+</sup>

stopEditing(): void

Exits the editing state.

### getTextContentRect<sup>10+</sup>

getTextContentRect(): [RectResult](#rectresult10)

Obtains the position of the edited text area relative to the component and its size. The unit of the return value is pixel.

**Return value**

| Type      | Description      |
| -------------------  | -------- |
| [RectResult](#rectresult10) | Position of the edited text area relative to the component and its size.|

> **NOTE**
>
> - If no text is entered, the return value contains the position information, but the size is 0.
> - The position information is the offset of the first character relative to the editable area.

### RectResult<sup>10+</sup>

Describes the position and size.

| Parameter     | Type    | Description|
| ------- | ------ | ----------------------- |
| x     | number | X coordinate.|
| y     | number | Y coordinate.|
| width | number | Content width.|
| height | number | Content height.|


### getTextContentLineCount<sup>10+</sup>

getTextContentLineCount(): number

Obtains the number of lines of the edited text.

**Return value**

| Type | Description      |
| ----- | -------- |
| number| Number of lines of the edited text.|
### getCaretOffset<sup>11+</sup>

getCaretOffset(): CaretOffset

Returns the position information of the caret.

**Return value**

| Type                     | Description              |
| ----------------------- | ---------------- |
| [CaretOffset](#caretoffset11) | Position of the caret relative to the text box.|

> **NOTE**
>
> - If this API is called when the caret position is updated in the current frame, it will not take effect.

## CaretOffset<sup>11+</sup>
| Name  | Type  | Description             |
| ----- | ------ | ----------------- |
| index | number | Index of the caret position.|
| x | number | X coordinate of the caret relative to the text box.|
| y | number | Y coordinate of the caret relative to the text box.|

## InputCounterOptions<sup>11+</sup>

| Name             | Type   | Description                                                        |
| ------------------- | ------- | ------------------------------------------------------------ |
| thresholdPercentage | number  | Threshold percentage for displaying the character counter. The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. When displayed, the character counter is in the following format: Number of characters that have been entered/Maximum number of characters allowed. <br> Value range: [1,100]<br>If the value exceeds the valid value range, the character counter is not displayed. If the value is **undefined**, the character counter is displayed, but this parameter has no effect.|
| highlightBorder     | boolean | If **options** is not set, the text box border turns red when the number of entered characters reaches the maximum. If the character counter is displayed and **thresholdPercentage** is set to a valid value, the text box border turns red when the number of entered characters reaches the maximum. The value **true** (default) means that the text box border turns red when the number of entered characters reaches the maximum.|

## Example

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = ''
  @State positionInfo: CaretOffset = { index: 0, x: 0, y: 0 }
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      TextInput({ text: this.text, placeholder: 'input your word...', controller: this.controller })
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .caretColor(Color.Blue)
        .width('95%')
        .height(40)
        .margin(20)
        .fontSize(14)
        .fontColor(Color.Black)
        .inputFilter('[a-z]', (e) => {
          console.log(JSON.stringify(e))
        })
        .onChange((value: string) => {
          this.text = value
        })
      Text(this.text)
      Button('Set caretPosition 1')
        .margin(15)
        .onClick(() => {
          // Move the caret to after the first entered character.
          this.controller.caretPosition(1)
        })
      Button('Get CaretOffset')
        .margin(15)
        .onClick(() => {
          this.positionInfo = this.controller.getCaretOffset()
        })
      // Password text box.
      TextInput({ placeholder: 'input your password...' })
        .width('95%')
        .height(40)
        .margin(20)
        .type(InputType.Password)
        .maxLength(9)
        .showPasswordIcon(true)
      // Inline-style text box.
      TextInput({ text: 'inline style' })
        .width('95%')
        .height(50)
        .margin(20)
        .borderRadius(0)
        .style(TextInputStyle.Inline)
    }.width('100%')
  }
}
```

![TextInput](figures/TextInput.png)

### Example 2

```ts
@Entry
@Component
struct TextInputExample {
  @State PassWordSrc1: Resource = $r('app.media.onIcon')
  @State PassWordSrc2: Resource = $r('app.media.offIcon')
  @State TextError: string = ''
  @State Text: string = ''
  @State NameText: string = 'test'

  @Builder itemEnd() {
    Select([{ value: 'KB' },
      { value: 'MB' },
      { value: 'GB' },
      { value: 'TB', }])
      .height("48vp")
      .borderRadius(0)
      .selected(2)
      .align(Alignment.Center)
      .value('MB')
      .font({ size: 20, weight: 500 })
      .fontColor('#182431')
      .selectedOptionFont({ size: 20, weight: 400 })
      .optionFont({ size: 20, weight: 400 })
      .backgroundColor(Color.Transparent)
      .responseRegion({ height: "40vp", width: "80%", x: '10%', y: '6vp' })
      .onSelect((index: number) => {
        console.info('Select:' + index)
      })
  }

  build() {
    Column({ space: 20 }) {
      // Customize the password icon.
      TextInput({ placeholder: 'Custom password icon' })
        .type(InputType.Password)
        .width(380)
        .height(60)
        .passwordIcon({ onIconSrc: this.PassWordSrc1, offIconSrc: this.PassWordSrc2 })
      // Show an underline.
      TextInput({ placeholder: 'Underline style' })
        .showUnderline(true)
        .width(380)
        .height(60)
        .showError('Error')
        .showUnit(this.itemEnd)

      Text (`User name: ${this.Text}`)
        .width('95%')
      TextInput({ placeholder: 'Enter user name', text: this.Text })
        .showUnderline(true)
        .width(380)
        .showError(this.TextError)
        .onChange((value: string) => {
          this.Text = value
        })
        .onSubmit(() => {// If the entered user name is incorrect, the text box will be cleared and the error message will be displayed.
          if (this.Text == this.NameText) {
            this.TextError = ''
          } else {
            this.TextError ='Incorrect user name.'
            this.Text = ''
          }
        })

    }.width('100%')
  }
}
```

![TextInputError](figures/TextInputError.png)

### Example 3

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  controller: TextInputController = new TextInputController()
  @State inputValue: string = ""

  // Create a custom keyboard component.
  @Builder CustomKeyboardBuilder() {
    Column() {
      Button('x').onClick(() => {
        // Disable the custom keyboard.
        this.controller.stopEditing()
      })
      Grid() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item:number|string) => {
          GridItem() {
            Button(item + "")
              .width(110).onClick(() => {
              this.inputValue += item
            })
          }
        })
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
    }.backgroundColor(Color.Gray)
  }

  build() {
    Column() {
      TextInput({ controller: this.controller, text: this.inputValue })
        // Bind the custom keyboard.
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })
    }
  }
}
```

![customKeyboard](figures/textInputCustomKeyboard.png)


### Example 4

```ts
// xxx.ets
@Entry
@Component
struct ClearNodeExample {
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      TextInput({ placeholder: 'input ...', controller: this.controller })
        .width(380)
        .height(60)
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: {
            size: 45,
            src: $r('app.media.icon'),
            color: Color.Blue
          }
        })
    }
  }
}
```

![cancelButton](figures/TextInputCancelButton.png)

### Example 5

```ts
// xxx.ets
@Entry
@Component
struct TextInputExample {
  @State text: string = ''
  controller: TextInputController = new TextInputController()

  build() {
    Column() {
      TextInput({ text: this.text, controller: this.controller })
        .placeholderFont({ size: 16, weight: 400 })
        .width(336)
        .height(56)
        .maxLength(6)
        .showUnderline(true)
		.showCounter(true, { thresholdPercentage: 50, highlightBorder: true })
		// The character counter is in this format: Number of characters that have been entered/Maximum number of characters allowed, which is specified by maxLength().
        // The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by 50% (threshold percentage).
        // When highlightBorder is set to false, the text box border turns red when the number of entered characters reaches the maximum. The default value is true.
    }.width('100%').height('100%').backgroundColor('#F1F3F5')
  }
}
```

![TextInputCounter](figures/TextInputShowCounter.jpg)
