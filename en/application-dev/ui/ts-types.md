# Types

## Length Type

| Name| Type| Description|
| -------- | -------- | -------- |
| Length | string&nbsp;\|&nbsp;number | Length unit. If the input is a number, use **vp**. If the input is a string, explicitly specify the unit, for example, **'10px'**, or specify the length in percentage, for example, **'100%'**.|


## Angle Type

| Name| Type| Description|
| -------- | -------- | -------- |
| Angle | string&nbsp;\|&nbsp;number | Angle unit. If the input is a number, use **deg**. If the input is a string, use either of the following angle units:<br>-&nbsp;**deg**: for example, **'100deg'**<br>-&nbsp;**rad**: for example, **'3.14rad'** |


## Point Type

| Name| Type| Description|
| -------- | -------- | -------- |
| Point | [Length,&nbsp;Length] | Coordinates of a point. The first value is the x-axis coordinate, and the second value is the y-axis coordinate.|


## Color Type

The **Color** type used by component attribute methods is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| Color | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Color | Color information. If the input is a string, use **rgb** or **rgba** to specify the color. If the input is a number, use Hex format to specify the color. If the input is a **Color** enum, use a color value to specify the color.<br>-&nbsp;'rgb(255,&nbsp;255,&nbsp;255)'<br>-&nbsp;'rgba(255,&nbsp;255,&nbsp;255,&nbsp;1.0)'<br>-&nbsp;Hex format: 0xrrggbb, 0xaarrggbb, '\#FFFFFF'<br>-&nbsp;Enum: Color.Black, Color.White |


The supported **Color** enums are described as follows:


| Color| Value| Illustration|
| -------- | -------- | -------- |
| Black | 0x000000 | ![en-us_image_0000001219864153](figures/en-us_image_0000001219864153.png) |
| Blue | 0x0000ff | ![en-us_image_0000001174104404](figures/en-us_image_0000001174104404.png) |
| Brown | 0xa52a2a | ![en-us_image_0000001219744201](figures/en-us_image_0000001219744201.png) |
| Gray | 0x808080 | ![en-us_image_0000001174264376](figures/en-us_image_0000001174264376.png) |
| Green | 0x008000 | ![en-us_image_0000001174422914](figures/en-us_image_0000001174422914.png) |
| Orange | 0xffa500 | ![en-us_image_0000001219662661](figures/en-us_image_0000001219662661.png) |
| Pink | 0xffc0cb | ![en-us_image_0000001219662663](figures/en-us_image_0000001219662663.png) |
| Red | 0xff0000 | ![en-us_image_0000001219662665](figures/en-us_image_0000001219662665.png) |
| White | 0xffffff | ![en-us_image_0000001174582866](figures/en-us_image_0000001174582866.png) |
| Yellow | 0xffff00 | ![en-us_image_0000001174582864](figures/en-us_image_0000001174582864.png) |


## ColorStop Type

**ColorStop** is used to describe the progressive color stop.

| Name| Type| Description|
| -------- | -------- | -------- |
| ColorStop | [Color,&nbsp;number] | Type of the progressive color stop. The first parameter specifies the color value, and the second parameter specifies the ratio of 0 to 1.|


## Resource Type

The **Resource** type is used to reference resources for setting the value of a component attribute.

You can use **$r** or **$rawfile** to create a **Resource** object. For details, see [Resource Access](ts-application-resource-access.md).

- $r('belonging.type.name')
  **belonging**: system or application resource. The value can be **'sys'** or **'app'**.

  **type**: resource type, which can be **'color'**, **'float'**, **'string'**, or **'media'**.

  **name**: resource name, which is determined during resource definition.

- $rawfile('filename')
  **filename**: name of the file in **resources/rawfile** of the project.

| Name| Type| Description|
| -------- | -------- | -------- |
| Resource | {<br>readonly&nbsp;id:&nbsp;[number];<br>readonly&nbsp;type:&nbsp;[number];<br>readonly&nbsp;params?:&nbsp;any[];<br>} | **id**: resource ID.<br>**type**: resource type (enumerated value).<br>**params**: optional parameters.<br>After a **Resource** object is created using **$r** or **$rawfile**, modifying attribute values of the object is prohibited.|


## ResourceStr Type<sup>8+</sup>

| Name| Type| Description|
| -------- | -------- | -------- |
| ResourceStr | string&nbsp;\|&nbsp;Resource| Resource string.|


## ResourceColor Type<sup>8+</sup>

| Name| Type| Description|
| -------- | -------- | -------- |
| ResourceColor | Color&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;Resource | Resource color.|

## Font Type<sup>8+</sup>

| Name| Type| Description|
| -------- | -------- | -------- |
| Font | {<br>size?: Length;<br>weight?: <a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a> &nbsp;\| number &nbsp;\| string;<br>family?: string &nbsp;\| <a href="ts-types.md#Resource">Resource</a>;<br>style?: <a href="https://gitee.com/superFat/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-universal-attributes-text-style.md#li6906111945316">FontStyle</a>;<br>} | Text style.<br>**size**: font size. For the number type, use the unit fp.<br>**weight**: font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is 400. A larger value indicates a larger font weight.<br>**family**: font family. Use commas (,) to separate multiple fonts. The priority of the fonts is the sequence in which they are placed. An example value is **'Arial, sans-serif'**.<br>**style**: font style.|

## CustomBuilder Type<sup>8+</sup>

You can use **CustomBuilder** to define custom UI descriptions in component attribute methods.

| Name| Type| Description|
| -------- | -------- | -------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | Builder of component attribute methods for defining custom UI descriptions. This type of method must be decorated by **@Builder**. For details, see [@Builder](ts-component-based-builder.md).|


## Example

```
@Entry
@Component
struct dataTypeExample {
  build() {
    Column({ space: 5 }) {
      Text('Length').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Text('90%').width('90%').height(40).backgroundColor(0xF9CF93)
        .textAlign(TextAlign.Center).fontColor(Color.White)
      Text('320').width(320).height(40).backgroundColor(0xF9CF93)
        .textAlign(TextAlign.Center).fontColor(Color.White)
      Text('1000px').width('1000px').height(40).backgroundColor(0xF9CF93)
        .textAlign(TextAlign.Center).fontColor(Color.White)

      Text('Angle').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Text('45deg')
        .width(40).height(40)
        .rotate({ x: 0, y: 0, z: 1, angle: 45, centerX: '50%', centerY: '50%' })
        .fontColor(Color.White)
        .backgroundColor(0xF9CF93).textAlign(TextAlign.Center)

      Text('45rad')
        .width(40).height(40)
        .rotate({ x: 0, y: 0, z: 1, angle: '45rad', centerX: '50%', centerY: '50%' })
        .fontColor(Color.White)
        .backgroundColor(0xF9CF93).textAlign(TextAlign.Center).margin({ top: 30 })

      Text('Point').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Line().width(300).height(40).startPoint([0, 20]).endPoint([300, 20])

      Text('Color').fontColor('#CCCCCC').fontSize(9).width('90%')
      Text('0xF9CF93')
        .fontColor(Color.White).textAlign(TextAlign.Center)
        .width('90%').height(40).backgroundColor(0xF9CF93)

      Text('#F9CF93')
        .fontColor(Color.White).textAlign(TextAlign.Center)
        .width('90%').height(40).backgroundColor('#F9CF93')

      Text('rgb(249, 207, 147)')
        .fontColor(Color.White).textAlign(TextAlign.Center)
        .width('90%').height(40).backgroundColor('rgb(249, 207, 147)')

      Text('rgba(249, 207, 147, 1.0)')
        .fontColor(Color.White).textAlign(TextAlign.Center)
        .width('90%').height(40).backgroundColor('rgba(249, 207, 147, 1.0)')

      Text('Color.Yellow')
        .textAlign(TextAlign.Center)
        .width('90%').height(40).backgroundColor(Color.Yellow)
    }
    .width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001219982719](figures/en-us_image_0000001219982719.png)
