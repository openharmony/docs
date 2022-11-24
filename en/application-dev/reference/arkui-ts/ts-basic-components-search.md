#  Search

The **\<Search>** component provides an input area for users to search.

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
| controller  | SearchController | No  | Controller.                                                    |

## Attributes

| Name                   | Type                                        | Description                                          |
| ----------------------- | ------------------------------------------------ | ---------------------------------------------- |
| searchButton            | string                                           | Text on the search button located next to the search text box. By default, there is no search button.    |
| placeholderColor        | [ResourceColor](ts-types.md#resourcecolor8) | Placeholder text color.                         |
| placeholderFont         | [Font](ts-types.md#font) | Placeholder text style.                     |
| textFont                | [Font](ts-types.md#font)     | Text font for the search text box.                        |

## Events

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onSubmit(callback: (value: string) => void) | Triggered when users click the search icon or the search button, or touch the search button on a soft keyboard.<br> -**value**: current text input.|
| onChange(callback: (value: string) => void) | Triggered when the input in the text box changes.<br> -**value**: current text input. |
| onCopy(callback: (value: string) => void) | Triggered when data is copied to the pasteboard.<br> -**value**: text copied.     |
| onCut(callback: (value: string) => void) | Triggered when data is cut from the pasteboard.<br> -**value**: text cut.     |
| onPaste(callback: (value: string) => void) | Triggered when data is pasted from the pasteboard.<br> -**value**: text pasted.     |

## SearchController

Defines the controller of the **\<Search>** component.

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
  @State changeValue: string = ''
  @State submitValue: string = ''
  controller: SearchController = new SearchController()

  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text(this.submitValue)
      Text(this.changeValue)
      Search({value: this.changeValue, placeholder: 'Type to search', controller: this.controller})
        .searchButton('Search')
        .width(400)
        .height(35)
        .backgroundColor(Color.White)
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 26, weight: 10, family: 'serif', style: FontStyle.Normal })
        .onSubmit((value: string) => {
          this.submitValue = value
        })
        .onChange((value: string) => {
          this.changeValue = value
        })
        .margin({ top: 30, left:10, right:10 })
    }
  }
}
```
![search](figures/search.png)
