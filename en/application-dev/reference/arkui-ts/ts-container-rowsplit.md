# RowSplit

The **\<RowSplit>** lays out child components horizontally and inserts a vertical divider between every two child components.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Supported

## APIs

RowSplit()


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| resizeable | boolean | Whether the divider can be dragged.<br/>Default value: **false** |

>  **NOTE**
>
> The divider of **\<RowSplit>** can change the width of the left and right child components, but only to the extent that the resultant width falls within the maximum and minimum widths of the child components.
>
> Universal attributes such as **clip** and **margin** are supported. If **clip** is not set, the default value **true** is used.


## Example

```ts
// xxx.ets
@Entry
@Component
struct RowSplitExample {
  build() {
    Column() {
      Text('The second line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      RowSplit() {
        Text('1').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('10%').height(100).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('10%').height(100).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('10%').height(100).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .resizeable(true) // The divider can be dragged.
      .width('90%').height(100)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001219982729](figures/en-us_image_0000001219982729.gif)
