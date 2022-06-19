# Rect


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Rect&gt;** component is used to draw a rectangle.


## Required Permissions

None


## Child Components

None


## APIs

Rect(value:{options?: {width: Length,height: Length,radius?: Length | Array&lt;Length&gt;} | {width: Length,height: Length,radiusWidth?: Length,radiusHeight?: Length}})

- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | No | - | For details, see the **options** parameters. | 

- options parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | Yes | - | Width. | 
  | height | Length | Yes | - | Height. | 
  | radius | Length \| Array&lt;Length&gt; | No | 0 | Radius of a rounded corner. You can set the radius of four rounded corners. | 
  | radiusWidth | Length | No | 0 | Width of the rounded corner. | 
  | radiusHeight | Length | No | 0 | Height of the rounded corner. | 


## Attributes

| Name | Type | Default Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width. | 
| height | Length | 0 | No | Height. | 
| radiusWidth | Length | 0 | No | Width of a rounded corner. The width and height are the same when only the width is set. | 
| radiusHeight | Length | 0 | No | Height of the rounded corner. The width and height are the same only when the height is set. | 
| radius | Length \| Array&lt;Length&gt; | 0 | No | Size of the rounded corner. | 


## Example

  
```ts
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