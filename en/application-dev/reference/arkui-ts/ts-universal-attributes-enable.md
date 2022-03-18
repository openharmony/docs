# Enable/Disable


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| enabled | boolean | true | The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;that&nbsp;the&nbsp;component&nbsp;is&nbsp;available&nbsp;and&nbsp;can&nbsp;respond&nbsp;to&nbsp;operations&nbsp;such&nbsp;as&nbsp;clicking.&nbsp;The&nbsp;value&nbsp;**false**&nbsp;means&nbsp;that&nbsp;the&nbsp;component&nbsp;does&nbsp;not&nbsp;respond&nbsp;to&nbsp;operations&nbsp;such&nbsp;as&nbsp;clicking. | 


## Example

  
```
@Entry
@Component
struct EnabledExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // No response upon a click.
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![en-us_image_0000001212218428](figures/en-us_image_0000001212218428.gif)
