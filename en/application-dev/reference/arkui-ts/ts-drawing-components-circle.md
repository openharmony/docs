# Circle


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Circle&gt;** component is used to draw a circle.


## Required Permissions

None


## Child Components

None


## APIs

Circle(options?: {width: Length, height: Length})

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
| width | Length | 0 | No | Width&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;circle&nbsp;is&nbsp;located. | 
| height | Length | 0 | No | Height&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;where&nbsp;the&nbsp;circle&nbsp;is&nbsp;located. | 


## Example

  
```
@Entry
@Component
struct CircleExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // Draw a circle whose diameter is 150.
      Circle({ width: 150, height: 150 })
      // Draw a circle whose diameter is 150.
      Circle().width(150).height(150)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256978353](figures/en-us_image_0000001256978353.png)
