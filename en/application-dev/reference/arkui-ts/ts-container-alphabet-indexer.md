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
| color                   | [ResourceColor](ts-types.md#resourcecolor)       | Font color.<br>Default value: **0x99000000**                          |
| selectedColor           | [ResourceColor](ts-types.md#resourcecolor)     | Font color of the selected text.<br>Default value: **0xFF254FF7**                          |
| popupColor              | [ResourceColor](ts-types.md#resourcecolor)        | Font color of the pop-up text.<br>Default value: **0xFF254FF7**                        |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)       | Background color of the selected item.<br>Default value: **0x1F0A59F7**                          |
| popupBackground         | [ResourceColor](ts-types.md#resourcecolor)        | Background color of the pop-up text.<br>Default value: **0xFFF1F3F5**                           |
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
| onSelected(callback: (index: number) =&gt; void)<sup>(deprecated)</sup> | Invoked when an item in the alphabetic indexer bar is selected. The return value is the index of the selected item. This API is deprecated since API version 8. You are advised to use **onSelect**.                            |
| onSelect(callback: (index: number) =&gt; void)<sup>8+</sup> | Invoked when an item in the alphabetic indexer bar is selected. The return value is the index of the selected item.                                |
| onRequestPopupData(callback: (index: number) =&gt; Array&lt;string&gt;)<sup>8+</sup> | Invoked when a request for displaying content in the index prompt window is sent after an item in the alphabetic indexer bar is selected.<br>The return value is a string array corresponding to the selected index. The string array is displayed vertically in the pop-up window. It can display up to five strings at a time and allows scrolling.|
| onPopupSelect(callback: (index: number) =&gt; void)<sup>8+</sup> | Invoked when an item in the index pop-up window is selected.                           |


## Example

```ts
// xxx.ets
@Entry
@Component
struct AlphabetIndexerSample {
  private arrayA:string[] = ['Ann']
  private arrayB: string[] = ['Ben', 'Bob']
  private arrayC: string[] = ['Calvin', 'Cameron', 'Charlie', 'Charlotte']
  private arrayL: string[] = ['Daisy', 'Daniel', 'Darla', 'David', 'Derek', 'Dorothy', 'Duke']
  private value: string[] = ['#', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N',
  'O', 'P', 'Q', 'R', 'S', 'T', 'U',
  'V', 'W', 'X', 'Y', 'Z']

  build() {
    Stack({ alignContent: Alignment.Start }) {
      Row() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arrayA, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayB, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayC, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayL, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .width('50%')
        .height('100%')

        AlphabetIndexer({ arrayValue: this.value, selected: 0 })
          .selectedColor(0xFFFFFF) // Font color of the selected text.
          .popupColor(0xFFFAF0) // Font color of the pop-up text.
          .selectedBackgroundColor(0xCCCCCC) // Background color of the selected item.
          .popupBackground(0xD2B48C) // Background color of the pop-up text.
          .usingPopup(true) // Whether to use pop-up text.
          .selectedFont({size: 16, weight: FontWeight.Bolder}) // Font style of the selected text.
          .popupFont({ size: 30, weight: FontWeight.Bolder}) // Font style of the pop-up text.
          .itemSize(28) // Size of an item in the alphabetic index bar.
          .alignStyle(IndexerAlign.Left) // Position of the pop-up window relative to the center of the indexer bar's top border, which is left in this example.
          .onSelect((index: number) => {
            console.info(this.value[index] + ' Selected!')
          })
          .onRequestPopupData((index: number) => {
            if (this.value[index] == 'A') {
              return this.arrayA // When index A is selected, the pop-up window displays arrayA corresponding to index A. The same applies when other indexes are selected.
            } else if (this.value[index] == 'B') {
              return this.arrayB
            } else if (this.value[index] == 'C') {
              return this.arrayC
            } else if (this.value[index] == 'L') {
              return this.arrayL
            } else {
              return [] // When no array is available for the selected index, the pop-up window is empty.
            }
          })
          .onPopupSelect((index: number) => {
            console.info('onPopupSelected:' + index)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

![en-us_image_0000001212378392](figures/en-us_image_0000001212378392.gif)
