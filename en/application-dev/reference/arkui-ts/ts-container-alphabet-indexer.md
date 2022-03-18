# AlphabetIndexer


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;AlphabetIndexer&gt;** component provides an alphabetic index bar.


## Required Permissions

None


## Child Components

None


## APIs

AlphabetIndexer(value: {arrayValue : Array&lt;string&gt;, selected : number})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | arrayValue | Array&lt;string&gt; | Yes | - | Array&nbsp;of&nbsp;strings&nbsp;to&nbsp;be&nbsp;displayed&nbsp;in&nbsp;the&nbsp;alphabetic&nbsp;index&nbsp;bar. | 
  | selected | number | Yes | - | ID&nbsp;of&nbsp;a&nbsp;selected&nbsp;item. | 


## Attributes

  | Name | Type | Description | 
| -------- | -------- | -------- |
| selectedColor | Color | Font&nbsp;color&nbsp;of&nbsp;the&nbsp;selected&nbsp;text. | 
| popupColor | Color | Font&nbsp;color&nbsp;of&nbsp;the&nbsp;pop-up&nbsp;text. | 
| selectedBackgroundColor | Color | Background&nbsp;color&nbsp;of&nbsp;the&nbsp;selected&nbsp;text. | 
| popupBackground | Color | Background&nbsp;color&nbsp;of&nbsp;the&nbsp;pop-up&nbsp;text. | 
| usingPopup | boolean | Whether&nbsp;to&nbsp;use&nbsp;pop-up&nbsp;text. | 
| selectedFont | {<br/>size?:&nbsp;number,<br/>weight?:&nbsp;FontWeight,<br/>family?:&nbsp;string,<br/>style?:&nbsp;FontStyle<br/>} | Font&nbsp;style&nbsp;of&nbsp;the&nbsp;selected&nbsp;text. | 
| popupFont | {<br/>size?:&nbsp;number,<br/>weight?:&nbsp;FontWeight,<br/>family?:&nbsp;string,<br/>style?:&nbsp;FontStyle<br/>} | Font&nbsp;style&nbsp;of&nbsp;the&nbsp;pop-up&nbsp;text. | 
| font | {<br/>size?:&nbsp;number,<br/>weight?:&nbsp;FontWeight,<br/>family?:&nbsp;string,<br/>style?:&nbsp;FontStyle<br/>} | Default&nbsp;font&nbsp;style&nbsp;of&nbsp;the&nbsp;alphabetic&nbsp;index&nbsp;bar. | 
| itemSize | Length | Size&nbsp;of&nbsp;an&nbsp;item&nbsp;in&nbsp;the&nbsp;alphabetic&nbsp;index&nbsp;bar.&nbsp;The&nbsp;item&nbsp;is&nbsp;a&nbsp;square,&nbsp;and&nbsp;the&nbsp;side&nbsp;length&nbsp;needs&nbsp;to&nbsp;be&nbsp;set. | 
| alignStyle | IndexerAlign | Alignment&nbsp;style&nbsp;of&nbsp;the&nbsp;alphabetic&nbsp;index&nbsp;bar.&nbsp;Left&nbsp;alignment&nbsp;and&nbsp;right&nbsp;alignment&nbsp;are&nbsp;supported.&nbsp;The&nbsp;alignment&nbsp;style&nbsp;affects&nbsp;the&nbsp;position&nbsp;of&nbsp;the&nbsp;pop-up&nbsp;window. | 

- IndexerAlign enums
    | Name | Description | 
  | -------- | -------- |
  | Left | The&nbsp;pop-up&nbsp;window&nbsp;is&nbsp;displayed&nbsp;on&nbsp;the&nbsp;right&nbsp;of&nbsp;the&nbsp;alphabetic&nbsp;indexer&nbsp;bar. | 
  | Right | The&nbsp;pop-up&nbsp;window&nbsp;is&nbsp;displayed&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;alphabetic&nbsp;indexer&nbsp;bar. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onSelected(index:&nbsp;number)&nbsp;=&gt;&nbsp;void | Callback&nbsp;invoked&nbsp;when&nbsp;an&nbsp;item&nbsp;in&nbsp;the&nbsp;alphabetic&nbsp;indexer&nbsp;bar&nbsp;is&nbsp;selected. | 
| onRequestPopupData(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;Array&lt;string&gt;)<sup>8+</sup> | Invoked&nbsp;when&nbsp;a&nbsp;request&nbsp;for&nbsp;displaying&nbsp;content&nbsp;in&nbsp;the&nbsp;index&nbsp;prompt&nbsp;window&nbsp;is&nbsp;sent&nbsp;when&nbsp;an&nbsp;item&nbsp;in&nbsp;the&nbsp;alphabetic&nbsp;indexer&nbsp;bar&nbsp;is&nbsp;selected.<br/>The&nbsp;return&nbsp;value&nbsp;is&nbsp;a&nbsp;string&nbsp;array&nbsp;corresponding&nbsp;to&nbsp;the&nbsp;indexes.&nbsp;The&nbsp;string&nbsp;array&nbsp;is&nbsp;displayed&nbsp;vertically&nbsp;in&nbsp;the&nbsp;pop-up&nbsp;window.&nbsp;It&nbsp;can&nbsp;display&nbsp;up&nbsp;to&nbsp;five&nbsp;strings&nbsp;at&nbsp;a&nbsp;time&nbsp;and&nbsp;allows&nbsp;scrolling. | 
| onPopupSelected(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void)<sup>8+</sup> | Invoked&nbsp;when&nbsp;an&nbsp;item&nbsp;in&nbsp;the&nbsp;index&nbsp;pop-up&nbsp;window&nbsp;is&nbsp;selected. | 


## Example

  
```
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
      .onSelected((index: number) => {
        console.info(this.value[index] + 'Selected') // Event indicating that an item is selected
      })
      .margin({ left: 50 })
  }
}
```

![en-us_image_0000001212378392](figures/en-us_image_0000001212378392.gif)
