# QRCode

The **\<QRCode>** component is used to display a QR code.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

QRCode(value: string)

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | value | string | Yes| - | Content of the QR code.|


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| color | [ResourceColor](../../ui/ts-types.md) | Black | Color of the QR code.|
| backgroundColor | [ResourceColor](../../ui/ts-types.md) | - | Background color of the QR code.|


## Events

Among all the universal events, only the click event is supported.


## Example

```ts
// xxx.ets
@Entry
@Component
struct QRCodeExample {
  private value: string = 'hello world'

  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).width('90%').fontColor(0xCCCCCC)
      QRCode(this.value).width(200).height(200)

      Text('color').fontSize(9).width('90%').fontColor(0xCCCCCC)
      QRCode(this.value).color(0xF7CE00).width(200).height(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256858415](figures/en-us_image_0000001256858415.png)
