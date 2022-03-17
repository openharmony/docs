# Line


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Line&gt;** component is used to draw a straight line.


## Required Permissions

None


## Child Components

None


## APIs

Line(options?: {width: Length, height: Length})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | options | Object | No | - | For&nbsp;details,&nbsp;see&nbsp;the&nbsp;**options**&nbsp;parameters. | 

- options parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | Length | Yes | - | Width. | 
  | height | Length | Yes | - | Height. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;straight&nbsp;line&nbsp;is&nbsp;located. | 
| height | Length | 0 | No | Height&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;straight&nbsp;line&nbsp;is&nbsp;located. | 
| startPoint | Point | [0,&nbsp;0] | Yes | Coordinate&nbsp;(relative&nbsp;coordinate)&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;of&nbsp;the&nbsp;straight&nbsp;line. | 
| endPoint | Point | [0,&nbsp;0] | Yes | Coordinate&nbsp;(relative&nbsp;coordinate)&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;of&nbsp;the&nbsp;straight&nbsp;line. | 


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
