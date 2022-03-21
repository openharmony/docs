# Grid


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
> 
> - The column width and column gap in the grid layout are determined by the nearest parent component **GridContainer**. The component tree that uses grid attributes must contain one **GridContainer** or more.


## Required Permissions

None


## Attributes


  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| useSizeType | {<br/>xs?: number \| { span: number, offset: number },<br/>sm?: number \| { span: number, offset: number },<br/>md?: number \| { span: number, offset: number },<br/>lg?: number \| { span: number, offset: number }<br/>} | - | Number of occupied columns and offset columns for a specific device width type. **span** indicates the number of occupied columns, and **offset** indicates the number of offset columns.<br/>If the value is of the number type, only the number of columns can be set. If the value is in the format of {"span": 1, "offset": 0}, both the number of occupied columns and the number of offset columns need to be set.<br/>- **xs** indicates that the device width type is **SizeType.XS**.<br/>- **sm** indicates that the device width type is **SizeType.SM**.<br/>- **md** indicates that the device width type is **SizeType.MD**.<br/>- **lg** indicates that the device width type is **SizeType.LG**. | 
| gridSpan | number | 1 | Default number of occupied columns, that is, the number of occupied columns when **span** in **useSizeType** is not set.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> If the **span** attribute is set, the component width is determined by the grid layout. | 
| gridOffset | number | 0 | Default number of offset columns, that is, the number of offset columns in the start direction of the parent component (which is also the nth column that the component is in) when **offset** in **useSizeType** is not set.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> 1. After this attribute is set, the horizontal layout of the current component does not follow the original layout of the parent component. Instead, it offsets along the start direction of the parent component.<br/>> <br/>> 2. Offset = (Column width + Gap) x Number of columns<br/>> <br/>> 3. After this attribute is set, sibling components will be arranged relatively to this component, as in the relative layout. | 


## Example


```
@Entry
@Component
struct GridContainerExample1 {
  build(){
    GridContainer() {
      Row({}) {
        Row() {
          Text('Left').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 1, offset: 0 },
          md: { span: 1, offset: 0 }, lg: { span: 2, offset: 0 }
        })
        .height("100%")
        .backgroundColor(0x66bbb2cb)
        Row() {
          Text('Center').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 2, offset: 1 },
          md: { span: 5, offset: 1 }, lg: { span: 7, offset: 2 }
        })
        .height("100%")
        .backgroundColor(0x66b6c5d1)
        Row() {
          Text('Right').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 1, offset: 3 },
          md: { span: 2, offset: 6 }, lg: { span: 3, offset: 9 }
        })
        .height("100%")
        .backgroundColor(0x66bbb2cb)
      }
      .height(200)
    }
    .backgroundColor(0xf1f3f5)
    .margin({ top: 10 })
  }
}
```

  **Figure1** Device width type SM
  ![en-us_image_0000001256858405](figures/en-us_image_0000001256858405.png)

  **Figure2** Device width type MD
  ![en-us_image_0000001257058415](figures/en-us_image_0000001257058415.png)

  **Figure3** Device width type LG
  ![en-us_image_0000001212378416](figures/en-us_image_0000001212378416.png)
