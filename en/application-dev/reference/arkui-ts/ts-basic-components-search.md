#  Search

The **\<Search>** component provides an area for users to enter search queries.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

Search(options?: { value?: string; placeholder?: string; icon?: string; controller?: SearchController })

**Parameters**

| Name     | Type        | Mandatory| Description                                                    |
| ----------- | ---------------- | ---- | ------------------------------------------------------------ |
| value       | string           | No  | Text input in the search text box.                                                |
| placeholder | string           | No  | Text displayed when there is no input.                                        |
| icon        | string           | No  | Path to the search icon. By default, the system search icon is used. The supported icon formats are .svg, .jpg, and .png.|
| controller  | SearchController | No  | Controller of the **\<Search>** component.                                                    |

## Attributes


| Name                   | Type                                        | Description                                          |
| ----------------------- | ------------------------------------------------ | ---------------------------------------------- |
| searchButton            | string                                           | Text on the search button located next to the search text box. By default, there is no search button.        |
| placeholderColor        | [ResourceColor](ts-types.md#resourcecolor8)      | Placeholder text color.                          |
| placeholderFont         | [Font](ts-types.md#font)                         | Placeholder text font.                          |
| textFont                | [Font](ts-types.md#font)                         | Text font for the search text box.                              |
| textAlign               | [TextAlign](ts-appendix-enums.md#textalign)      | Text alignment mode in the search text box.<br>Default value: **TextAlign.Start**   |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                        | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------------ |
| onSubmit(callback: (value: string) => void) | Invoked when users click the search icon or the search button, or touch the search button on a soft keyboard.<br> - **value**: current text input. |
| onChange(callback: (value: string) => void) | Invoked when the input in the text box changes.<br> - **value**: current text input. |
| onCopy(callback: (value: string) => void)   | Invoked when data is copied to the pasteboard, which is displayed when the search text box is long pressed.<br> - **value**: text copied. |
| onCut(callback: (value: string) => void)    | Invoked when data is cut from the pasteboard, which is displayed when the search text box is long pressed.<br> - **value**: text cut. |
| onPaste(callback: (value: string) => void)  | Invoked when data is pasted from the pasteboard, which is displayed when the search text box is long pressed.<br> -**value**: text pasted. |

## SearchController

Implements the controller of the **\<Search>** component. Currently, the controller can be used to control the caret position.

### Objects to Import
```
controller: SearchController = new SearchController()
```
### caretPosition

caretPosition(value: number): void

Sets the position of the caret.

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | -------- | ---- | ---------------------------------- |
| value  | number   | Yes  | Length from the start of the character string to the position where the caret is located.|

##  Example

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State changeValue: string = '';
  @State submitValue: string = '';
  controller: SearchController = new SearchController();

  build() {
    Column() {
      Text('onSubmit:' + this.submitValue).fontSize(18).margin(15)
      Text('onChange:' + this.changeValue).fontSize(18).margin(15)
      Search({ value: this.changeValue, placeholder: 'Type to search...', controller: this.controller })
        .searchButton('SEARCH')
        .width(400)
        .height(40)
        .backgroundColor(Color.White)
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .onSubmit((value: string) => {
          this.submitValue = value;
        })
        .onChange((value: string) => {
          this.changeValue = value;
        })
        .margin(20)
      Button('Set caretPosition 1')
        .onClick(() => {
          // Move the caret to after the first entered character.
          this.controller.caretPosition(1);
        })
    }.width('100%')
  }
}
```

![search](figures/search.gif)
