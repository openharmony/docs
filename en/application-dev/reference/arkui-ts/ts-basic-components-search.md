#  Search

> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **\<Search>** component provides an input area for users to search.

## Required Permissions

None

## Child Components

None

## APIs

Search(options?: { value?: string; placeholder?: string; icon?: string; controller?: SearchController })

- Parameters

  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value  | string | No| - | Text input in the search text box. |
  | placeholder  | string | No  | - | Text displayed when there is no input. |
  | icon | string | No| - | Path to the search icon. By default, the system search icon is used. The supported icon formats are svg, jpg, and png. |
  | controller | SearchController | No| - | Controller. |


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| searchButton | string | –| Text on the search button located next to the search text box. By default, there is no search button. |
| placeholderColor | [ResourceColor](../../ui/ts-types.md) | - | Placeholder text color. |
| placeholderFont | [Font](../../ui/ts-types.md) | - | Placeholder text style. |
| textFont | [Font](../../ui/ts-types.md) | - | Text font for the search text box. |

## Events

| Name | Description |
| -------- | -------- |
| onSubmit(callback: (value: string) => void) | Triggered when users click the search icon or the search button, or tap the search button on a soft keyboard.<br> -**value**: current text input. |
| onChange(callback: (value: string) => void) | Triggered when the input in the text box changes.<br> -**value**: current text input. |
| onCopy(callback: (value: string) => void) | Triggered when data is copied to the pasteboard.<br> -**value**: text copied. |
| onCut(callback: (value: string) => void) | Triggered when data is cut from the pasteboard.<br> -**value**: text cut. |
| onPaste(callback: (value: string) => void) | Triggered when data is pasted from the pasteboard.<br> -**value**: text pasted. |

## SearchController

Defines the controller of the **\<Search>** component.

#### Objects to Import
```
controller: SearchController = new SearchController()
```
#### caretPosition

creatPosition(value: number): void

Sets the position of the caret.

- Parameters

  | Name | Type | Mandatory | Default Value | Description |
  | ---- | ------ | ---- | ---- | --------------------- |
  | value | number | Yes   | - | Length from the start of the character string to the position where the caret is located. |



##  Example

```
@Entry
@Component
struct SearchExample {
  @State changevalue: string = ''
  @State submitvalue: string = ''
  controller: SearchController = new SearchController()

  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text(this.submitvalue)
      Text(this.changevalue)
      Search({value: '', placeholder: 'Type to search', controller: this.controller})
        .searchButton('Search')
        .width(400)
        .height(35)
        .backgroundColor(Color.White)
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 50, weight: 10, family: 'serif', style: FontStyle.Normal })
        .onSubmit((value: string) => {
          this.submitvalue = value
        })
        .onChange((value: string) => {
          this.changevalue = value
        })
        .margin({ top: 30 })
    }
  }
}
```
