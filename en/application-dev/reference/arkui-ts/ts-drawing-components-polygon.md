# Polygon


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Polygon&gt;** component is used to draw a polygon.


## Required Permissions

None


## Child Components

None


## APIs

Polygon(value:{options?: {width: Length, height: Length}})

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
| width | Length | 0 | No | Width of the rectangle where the polygon is located. | 
| height | Length | 0 | No | Height of the rectangle where the polygon is located. | 
| points | Array&lt;Point&gt; | - | Yes | Vertex coordinates of the polygon. | 


## Example

  
```ts
@Entry
@Component
struct PolygonExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // Draw a triangle in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 0), and the passing point is (50, 100).
        Polygon({ width: 100, height: 100 }).points([[0, 0], [50, 100], [100, 0]])
        // Draw a quadrilateral in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 0), and the passing point is (100, 100).
        Polygon().width(100).height(100).points([[0, 0], [0, 100], [100, 100], [100, 0]])
        // Draw a pentagon in a 100 x 100 rectangle. The start point is (50, 0), the end point is (100, 50), and the passing points are (0, 50), (20, 100), and (80, 100).
        Polygon().width(100).height(100).points([[50, 0], [0, 50], [20, 100], [80, 100], [100, 50]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218458](figures/en-us_image_0000001212218458.gif)