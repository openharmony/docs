# Rect


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Rect&gt;** component is used to draw a rectangle.


## Required Permissions

None


## Child Components

None


## APIs

Rect(value:{options?: {width: Length,height: Length,radius?: Length | Array&lt;Length&gt;} | {width: Length,height: Length,radiusWidth?: Length,radiusHeight?: Length}})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | No | - | For&nbsp;details,&nbsp;see&nbsp;the&nbsp;**options**&nbsp;parameters. | 

- options parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | Yes | - | Width. | 
  | height | Length | Yes | - | Height. | 
  | radius | Length&nbsp;\|&nbsp;Array&lt;Length&gt; | No | 0 | Radius&nbsp;of&nbsp;a&nbsp;rounded&nbsp;corner.&nbsp;You&nbsp;can&nbsp;set&nbsp;the&nbsp;radius&nbsp;of&nbsp;four&nbsp;rounded&nbsp;corners. | 
  | radiusWidth | Length | No | 0 | Width&nbsp;of&nbsp;the&nbsp;rounded&nbsp;corner. | 
  | radiusHeight | Length | No | 0 | Height&nbsp;of&nbsp;the&nbsp;rounded&nbsp;corner. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width. | 
| height | Length | 0 | No | Height. | 
| radiusWidth | Length | 0 | No | Width&nbsp;of&nbsp;a&nbsp;rounded&nbsp;corner.&nbsp;The&nbsp;width&nbsp;and&nbsp;height&nbsp;are&nbsp;the&nbsp;same&nbsp;when&nbsp;only&nbsp;the&nbsp;width&nbsp;is&nbsp;set. | 
| radiusHeight | Length | 0 | No | Height&nbsp;of&nbsp;the&nbsp;rounded&nbsp;corner.&nbsp;The&nbsp;width&nbsp;and&nbsp;height&nbsp;are&nbsp;the&nbsp;same&nbsp;only&nbsp;when&nbsp;the&nbsp;height&nbsp;is&nbsp;set. | 
| radius | Length&nbsp;\|&nbsp;Array&lt;Length&gt; | 0 | No | Size&nbsp;of&nbsp;the&nbsp;rounded&nbsp;corner. | 


## Example

  
```
@Entry
@Component
struct RectExample {
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle.
      Rect({ width: '90%', height: 50 })
      // Draw a 90% x 50 rectangle.
      Rect().width('90%').height(50)

      Text('with rounded corners').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radiusHeight(20).radiusWidth(20)
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radius(20)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218454](figures/en-us_image_0000001212218454.png)
