# Visibility


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| visibility | Visibility | Visibility.Visible | Whether&nbsp;the&nbsp;component&nbsp;is&nbsp;shown&nbsp;or&nbsp;hidden. | 


- Visibility enums
    | Name | Description | 
  | -------- | -------- |
  | Hidden | The&nbsp;component&nbsp;is&nbsp;hidden,&nbsp;and&nbsp;a&nbsp;placeholder&nbsp;is&nbsp;used&nbsp;for&nbsp;it&nbsp;in&nbsp;the&nbsp;layout. | 
  | Visible | The&nbsp;component&nbsp;is&nbsp;shown. | 
  | None | The&nbsp;component&nbsp;is&nbsp;hidden.&nbsp;It&nbsp;is&nbsp;not&nbsp;involved&nbsp;in&nbsp;the&nbsp;layout,&nbsp;and&nbsp;no&nbsp;placeholder&nbsp;is&nbsp;used&nbsp;for&nbsp;it. | 


## Example

  
```
@Entry
@Component
struct VisibilityExample {
  build() {
    Column() {
      Column() {
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Visible).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // The component is hidden and no placeholder is used.
        Row().visibility(Visibility.None).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('Hidden').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // The component is hidden and a placeholder is used.
        Row().visibility(Visibility.Hidden).width('90%').height(80).backgroundColor(0xAFEEEE)
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001257058421](figures/en-us_image_0000001257058421.gif)
