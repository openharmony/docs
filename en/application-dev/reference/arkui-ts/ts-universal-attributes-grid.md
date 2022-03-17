# Grid


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> - This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
> 
> - The column width and column gap in the grid layout are determined by the nearest parent component **GridContainer**. The component tree that uses grid attributes must contain one **GridContainer** or more.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| useSizeType | {<br/>xs?:&nbsp;number&nbsp;\|&nbsp;{&nbsp;span:&nbsp;number,&nbsp;offset:&nbsp;number&nbsp;},<br/>sm?:&nbsp;number&nbsp;\|&nbsp;{&nbsp;span:&nbsp;number,&nbsp;offset:&nbsp;number&nbsp;},<br/>md?:&nbsp;number&nbsp;\|&nbsp;{&nbsp;span:&nbsp;number,&nbsp;offset:&nbsp;number&nbsp;},<br/>lg?:&nbsp;number&nbsp;\|&nbsp;{&nbsp;span:&nbsp;number,&nbsp;offset:&nbsp;number&nbsp;}<br/>} | - | Number&nbsp;of&nbsp;occupied&nbsp;columns&nbsp;and&nbsp;offset&nbsp;columns&nbsp;for&nbsp;a&nbsp;specific&nbsp;device&nbsp;width&nbsp;type.&nbsp;**span**&nbsp;indicates&nbsp;the&nbsp;number&nbsp;of&nbsp;occupied&nbsp;columns,&nbsp;and&nbsp;**offset**&nbsp;indicates&nbsp;the&nbsp;number&nbsp;of&nbsp;offset&nbsp;columns.<br/>If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;only&nbsp;the&nbsp;number&nbsp;of&nbsp;columns&nbsp;can&nbsp;be&nbsp;set.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;in&nbsp;the&nbsp;format&nbsp;of&nbsp;{"span":&nbsp;1,&nbsp;"offset":&nbsp;0},&nbsp;both&nbsp;the&nbsp;number&nbsp;of&nbsp;occupied&nbsp;columns&nbsp;and&nbsp;the&nbsp;number&nbsp;of&nbsp;offset&nbsp;columns&nbsp;need&nbsp;to&nbsp;be&nbsp;set.<br/>-&nbsp;**xs**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;device&nbsp;width&nbsp;type&nbsp;is&nbsp;**SizeType.XS**.<br/>-&nbsp;**sm**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;device&nbsp;width&nbsp;type&nbsp;is&nbsp;**SizeType.SM**.<br/>-&nbsp;**md**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;device&nbsp;width&nbsp;type&nbsp;is&nbsp;**SizeType.MD**.<br/>-&nbsp;**lg**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;device&nbsp;width&nbsp;type&nbsp;is&nbsp;**SizeType.LG**. | 
| gridSpan | number | 1 | Default&nbsp;number&nbsp;of&nbsp;occupied&nbsp;columns,&nbsp;that&nbsp;is,&nbsp;the&nbsp;number&nbsp;of&nbsp;occupied&nbsp;columns&nbsp;when&nbsp;**span**&nbsp;in&nbsp;**useSizeType**&nbsp;is&nbsp;not&nbsp;set.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;If&nbsp;the&nbsp;**span**&nbsp;attribute&nbsp;is&nbsp;set,&nbsp;the&nbsp;component&nbsp;width&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;grid&nbsp;layout. | 
| gridOffset | number | 0 | Default&nbsp;number&nbsp;of&nbsp;offset&nbsp;columns,&nbsp;that&nbsp;is,&nbsp;the&nbsp;number&nbsp;of&nbsp;offset&nbsp;columns&nbsp;in&nbsp;the&nbsp;start&nbsp;direction&nbsp;of&nbsp;the&nbsp;parent&nbsp;component&nbsp;(which&nbsp;is&nbsp;also&nbsp;the&nbsp;nth&nbsp;column&nbsp;that&nbsp;the&nbsp;component&nbsp;is&nbsp;in)&nbsp;when&nbsp;**offset**&nbsp;in&nbsp;**useSizeType**&nbsp;is&nbsp;not&nbsp;set.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;1.&nbsp;After&nbsp;this&nbsp;attribute&nbsp;is&nbsp;set,&nbsp;the&nbsp;horizontal&nbsp;layout&nbsp;of&nbsp;the&nbsp;current&nbsp;component&nbsp;does&nbsp;not&nbsp;follow&nbsp;the&nbsp;original&nbsp;layout&nbsp;of&nbsp;the&nbsp;parent&nbsp;component.&nbsp;Instead,&nbsp;it&nbsp;offsets&nbsp;along&nbsp;the&nbsp;start&nbsp;direction&nbsp;of&nbsp;the&nbsp;parent&nbsp;component.<br/>>&nbsp;<br/>>&nbsp;2.&nbsp;Offset&nbsp;=&nbsp;(Column&nbsp;width&nbsp;+&nbsp;Gap)&nbsp;x&nbsp;Number&nbsp;of&nbsp;columns<br/>>&nbsp;<br/>>&nbsp;3.&nbsp;After&nbsp;this&nbsp;attribute&nbsp;is&nbsp;set,&nbsp;sibling&nbsp;components&nbsp;will&nbsp;be&nbsp;arranged&nbsp;relatively&nbsp;to&nbsp;this&nbsp;component,&nbsp;as&nbsp;in&nbsp;the&nbsp;relative&nbsp;layout. | 


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
