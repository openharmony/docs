# Polyline


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Polyline&gt;** component is used to draw a polyline.


## Required Permissions

None


## Child Components

None


## APIs

Polyline(options?: {width: Length, height: Length})

- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | No | - | For details, see the **options** parameters. | 

- options parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | Yes | - | Width. | 
  | height | Length | Yes | - | Height. | 


## Attributes

| Name | Type | Default Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width of the rectangle where the polyline is located. | 
| height | Length | 0 | No | Height of the rectangle where the polyline is located. | 
| points | Array&lt;Point&gt; | - | Yes | List of coordinates that the polyline passes through. | 


## Example

  
```ts
@Entry
@Component
struct PolylineExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // Draw a polyline in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 100), and the passing point is (20,60).
        Polyline({ width: 100, height: 100 }).points([[0, 0], [20, 60], [100, 100]])
        // Draw a polyline in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 100), and the passing point is (0,100).
        Polyline().width(100).height(100).points([[0, 0], [0, 100], [100, 100]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218432](figures/en-us_image_0000001212218432.gif)