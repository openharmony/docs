# Ellipse


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Ellipse&gt;** component is used to draw an ellipse.


## Required Permissions

None


## Child Components

None


## APIs

ellipse(options?: {width: Length, height: Length})

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
| width | Length | 0 | No | Width&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;ellipse&nbsp;is&nbsp;located. | 
| height | Length | 0 | No | Height&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;ellipse&nbsp;is&nbsp;located. | 


## Example

  
```
@Entry
@Component
struct EllipseExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // Draw an ellipse in a 150 x 70 rectangle.
      Ellipse({ width: 150, height: 80 })
      // Draw an ellipse in a 150 x 70 rectangle.
      Ellipse().width(150).height(80)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058488](figures/en-us_image_0000001212058488.png)
