# Line


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **<Line\>** component is used to draw a straight line.


## Required Permissions

None


## Child Components

None


## APIs

Line(options?: {width: Length, height: Length})

- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | No | - | Options of the line to draw. For details, see the **options** parameters. | 

- options parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | Yes | - | Line width. | 
  | height | Length | Yes | - | Line height. | 


## Attributes

| Name | Type | Default Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width of the rectangle where the straight line is located. | 
| height | Length | 0 | No | Height of the rectangle where the straight line is located. | 
| startPoint | Point | [0, 0] | Yes | Coordinate (relative coordinate) of the start point of the straight line. | 
| endPoint | Point | [0, 0] | Yes | Coordinate (relative coordinate) of the end point of the straight line. | 


## Example

  
```
@Entry
@Component
struct LineExample {
  build() {
    Column() {
      Line({ width: 50, height: 100 }).startPoint([0, 0]).endPoint([50, 100])
      Line().width(200).height(200).startPoint([50, 50]).endPoint([150, 150])
    }.margin({ top: 5 })
  }
}
```

![en-us_image_0000001256858387](figures/en-us_image_0000001256858387.jpg)
