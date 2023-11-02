# arkui子系统ChangeLog
## QRCode组件的二维码默认颜色、默认背景颜色和默认尺寸变更

**变更原因**

二维码的UX默认规格变更

**变更影响**

变更前，二维码默认颜色是Color.Black，默认背景颜色是Color.White，组件默认宽高是父组件大小。

变更后，API version 10以前，二维码默认颜色是Color.Black，默认背景颜色是Color.White，组件默认宽高是父组件大小；API version 11开始，二维码默认颜色是系统资源中的ohos_id_color_foreground，默认背景颜色是系统资源中的ohos_id_color_background，组件默认宽度和高度都是240vp。

**适配指导**

请查阅[QRCode组件](../../../application-dev/reference/arkui-ts/ts-basic-components-qrcode.md)文档进行适配。

示例代码:
```ts
// xxx.ets
@Entry
@Component
struct QRCodeExample {
  private value: string = 'hello world'
  build() {
    Column() {
      QRCode(this.value)
    }.width('100%').height('100%')
  }
}
```
