# AlphabetIndexer

The **\<Indexer>** component can create a logically indexed array of items in a container for instant location.

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
| arrayValue | Array&lt;string&gt; | Yes| Array of strings to be displayed in the alphabetic index bar. The value cannot be null.|
| selected   | number              | Yes   | Index of the initially selected item. If the value exceeds the value range, the default value 0 is used.    |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.
| Name                 | Type    | Description                                                             |
| ----------------------- | --------------- | ----------------------------------------------------------- |
| color                   | [ResourceColor](ts-types.md#resourcecolor8)      | Font color.<br>Default value: **0x99000000**                          |
| selectedColor           | [ResourceColor](ts-types.md#resourcecolor8)    | Font color of the selected text.<br>Default value: **0xFF254FF7**                          |
| popupColor              | [ResourceColor](ts-types.md#resourcecolor8)       | Font color of the pop-up text.<br>Default value: **0xFF254FF7**                        |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor8)      | Background color of the selected item.<br>Default value: **0x1F0A59F7**                          |
| popupBackground         | [ResourceColor](ts-types.md#resourcecolor8)       | Background color of the pop-up text.<br>Default value: **0xFFF1F3F5**                           |
| usingPopup              | boolean                                  | Whether to use pop-up text.<br>Default value: **false**                        |
| selectedFont            | [Font](ts-types.md#font) | Font style of the selected text.<br>Default value:<br>{<br>fontSize:10,<br> fontStyle:FontStyle.Normal,<br> fontWeight:FontWeight.Normal,<br> fontFamily:HarmonyOS Sans<br>}                          |
| popupFont               | [Font](ts-types.md#font) | Font style of the pop-up text.<br>Default value:<br>{<br>fontSize:10,<br> fontStyle:FontStyle.Normal,<br> fontWeight:FontWeight.Normal,<br> fontFamily:HarmonyOS Sans<br>}                         |
| font                    | [Font](ts-types.md#font) | Default font style of the alphabetic index bar.<br>Default value:<br>{<br>fontSize:10,<br> fontStyle:FontStyle.Normal,<br> fontWeight:FontWeight.Normal,<br> fontFamily:HarmonyOS Sans<br>}                      |
| itemSize                | string \| number            | Size of an item in the alphabetic index bar. The item is a square, and the side length needs to be set. This attribute cannot be set to a percentage.<br>Default value: **24.0**      |
| alignStyle              | IndexerAlign                             | Alignment style of the alphabetic index bar. Left alignment and right alignment are supported.<br>Default value: **IndexerAlign.Right**|
| selected | number | Index of the selected item.<br>Default value: **0**|
| popupPosition | [Position](ts-types.md#position8) | Position of the pop-up window relative to the center of the indexer bar's top border.<br>Default value: **{x:96.0, y:48.0}**|

## IndexerAlign

| Name| Description|
| -------- | -------- |
| Left | The pop-up window is displayed on the right of the alphabetic indexer bar.|
| Right | The pop-up window is displayed on the left of the alphabetic indexer bar.|

## Events

Only the following events are supported.
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
