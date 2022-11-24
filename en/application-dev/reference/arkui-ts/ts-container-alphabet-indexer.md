# AlphabetIndexer

The **\<Indexer>** component provides an alphabetic index bar.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

AlphabetIndexer(value: {arrayValue: Array&lt;string&gt;, selected: number})

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| arrayValue | Array&lt;string&gt; | Yes| Array of strings to be displayed in the alphabetic index bar.|
| selected   | number              | Yes   | Index of the initially selected item.    |

## Attributes

| Name                 | Type    | Description                                                             |
| ----------------------- | --------------- | ----------------------------------------------------------- |
| color                   | [ResourceColor](ts-types.md#resourcecolor8)      | Font color.                          |
| selectedColor           | [ResourceColor](ts-types.md#resourcecolor8)    | Font color of the selected text.                          |
| popupColor              | [ResourceColor](ts-types.md#resourcecolor8)       | Font color of the pop-up text.                        |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor8)      | Background color of the selected item.                          |
| popupBackground         | [ResourceColor](ts-types.md#resourcecolor8)       | Background color of the pop-up text.                           |
| usingPopup              | boolean                                  | Whether to use pop-up text.                        |
| selectedFont            | [Font](ts-types.md#font) | Font style of the selected text.                          |
| popupFont               | [Font](ts-types.md#font) | Font style of the pop-up text.                        |
| font                    | [Font](ts-types.md#font) | Default font style of the alphabetic index bar.                     |
| itemSize                | string \| number            | Size of an item in the alphabetic index bar. The item is a square, and the side length needs to be set.      |
| alignStyle              | IndexerAlign                             | Alignment style of the alphabetic index bar. Left alignment and right alignment are supported.<br>Default value: **IndexerAlign.Right**|
| selected | number | Index of the selected item.|
| popupPosition | [Position](ts-types.md#position8) | Position of the pop-up window relative to the center of the indexer bar's top border.|

## IndexerAlign enums

| Name| Description|
| -------- | -------- |
| Left | The pop-up window is displayed on the right of the alphabetic indexer bar.|
| Right | The pop-up window is displayed on the left of the alphabetic indexer bar.|

## Events

| Name| Description|
| -------- | -------- |
| onSelected(callback: (index: number) =&gt; void)<sup>(deprecated)</sup> | Invoked when an item in the alphabetic indexer bar is selected. The return value is the index of the selected item.                                |
| onSelect(callback: (index: number) =&gt; void)<sup>8+</sup> | Invoked when an item in the alphabetic indexer bar is selected. The return value is the index of the selected item.                                |
| onRequestPopupData(callback: (index: number) =&gt; Array&lt;string&gt;)<sup>8+</sup> | Invoked when a request for displaying content in the index prompt window is sent after an item in the alphabetic indexer bar is selected.<br>The return value is a string array corresponding to the indexes. The string array is displayed vertically in the pop-up window. It can display up to five strings at a time and allows scrolling.|
| onPopupSelect(callback: (index: number) =&gt; void)<sup>8+</sup> | Invoked when an item in the index pop-up window is selected.                           |


## Example

```ts
// xxx.ets
@Entry
@Component
struct AlphabetIndexerSample {
  private value: string[] = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

  build() {
    AlphabetIndexer({ arrayValue: this.value, selected: 0 })
      .selectedColor(0xffffff) // Font color of the selected text
      .popupColor(0xFFFAF0) // Font color of the pop-up text
      .selectedBackgroundColor(0xCCCCCC) // Background color of the selected text
      .popupBackground(0xD2B48C) // Background color of the pop-up text
      .usingPopup(true) // Whether to use pop-up text
      .selectedFont({ size: 16, weight: FontWeight.Bolder }) // Font style of the selected text
      .popupFont({ size: 30, weight: FontWeight.Bolder }) // Font style of the pop-up text
      .itemSize(28) // Size of each item (square)
      .alignStyle(IndexerAlign.Left) // Left aligned
      .onSelect((index: number) => {
        console.info(this.value[index] + 'Selected') // Event indicating that an item is selected
      })
      .margin({ left: 50 })
  }
}
```

![en-us_image_0000001212378392](figures/en-us_image_0000001212378392.gif)
