# 类型定义

## 长度类型

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| Length | string&nbsp;\|&nbsp;number | 用于描述尺寸单位，输入为number类型时，使用vp单位；输入为string类型时，需要显式指定像素单位，如'10px'，也可设置百分比字符串，如'100%'。 | 


## 角度类型

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| Angle | string&nbsp;\|&nbsp;number | 用于角度单位，输入为number类型时，使用deg单位；输入为string类型时需要显示指定角度单位，支持以下两种角度单位：<br/>-&nbsp;deg：如'100deg'。<br/>-&nbsp;rad：如'3.14rad'。 | 


## 点类型

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| Point | [Length,&nbsp;Length] | 用于描述点坐标，第一个值为x轴坐标，第二个值为y坐标。 | 


## 颜色类型

组件属性方法使用的颜色Color说明如下：

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| Color | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Color | 用于描述颜色信息，输入为string类型时，使用rgb或者rgba进行描述；输入为number类型是，使用HEX格式颜色；输入类型为Color枚举时，使用颜色枚举值。<br/>-&nbsp;'rgb(255,&nbsp;255,&nbsp;255)'。<br/>-&nbsp;'rgba(255,&nbsp;255,&nbsp;255,&nbsp;1.0)'。<br/>-&nbsp;HEX格式：0xrrggbb，0xaarrggbb，'\#FFFFFF'。<br/>-&nbsp;枚举格式：Color.Black，Color.White等。 | 


当前支持的Color颜色枚举：


| 颜色名称 | 颜色值 | 颜色示意 | 
| -------- | -------- | -------- |
| Black | 0x000000 | ![zh-cn_image_0000001219864153](figures/zh-cn_image_0000001219864153.png) | 
| Blue | 0x0000ff | ![zh-cn_image_0000001174104404](figures/zh-cn_image_0000001174104404.png) | 
| Brown | 0xa52a2a | ![zh-cn_image_0000001219744201](figures/zh-cn_image_0000001219744201.png) | 
| Gray | 0x808080 | ![zh-cn_image_0000001174264376](figures/zh-cn_image_0000001174264376.png) | 
| Green | 0x008000 | ![zh-cn_image_0000001174422914](figures/zh-cn_image_0000001174422914.png) | 
| Orange | 0xffa500 | ![zh-cn_image_0000001219662661](figures/zh-cn_image_0000001219662661.png) | 
| Pink | 0xffc0cb | ![zh-cn_image_0000001219662663](figures/zh-cn_image_0000001219662663.png) | 
| Red | 0xff0000 | ![zh-cn_image_0000001219662665](figures/zh-cn_image_0000001219662665.png) | 
| White | 0xffffff | ![zh-cn_image_0000001174582866](figures/zh-cn_image_0000001174582866.png) | 
| Yellow | 0xffff00 | ![zh-cn_image_0000001174582864](figures/zh-cn_image_0000001174582864.png) | 


## ColorStop类型

颜色断点类型，用于描述渐进色颜色断点。

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| ColorStop | [Color,&nbsp;number] | 描述渐进色颜色断点类型，第一个参数为颜色值，第二个参数为0~1之间的比例值。 | 


## Resource类型

资源引用类型，用于设置组件属性的值。

可以通过$r或者$rawfile创建Resource类型对象，详见[资源访问](ts-application-resource-access.md)。

- $r('belonging.type.name')
  belonging：系统资源或者应用资源，相应的取值为'sys'和'app'；

  type：资源类型，支持'color'、'float'、'string'、'media'等；

  name：资源名称，在资源定义时确定。

- $rawfile('filename')
  filename：工程中resources/rawfile目录下的文件名称。

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| Resource | {<br/>readonly&nbsp;id:&nbsp;[number];<br/>readonly&nbsp;type:&nbsp;[number];<br/>readonly&nbsp;params?:&nbsp;any[];<br/>} | id：资源id值<br/>type：资源类型（枚举值）<br/>params：可选参数<br/>通过$r或者$rawfile创建Resource类型对象并使用即可，不可以修改Resource中的各属性的值。 | 


## ResourceStr类型<sup>8+</sup>

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| ResourceStr | string&nbsp;\|&nbsp;Resource| 用于描述资源字符串的类型。 | 


## ResourceColor类型<sup>8+</sup>

| 名称 | 类型定义 | 描述 | 
| -------- | -------- | -------- |
| ResourceColor | Color&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;Resource | 用于描述资源颜色类型。 | 

## Font类型<sup>8+</sup>

| 名称 | 类型定义 | 描述 |
| -------- | -------- | -------- |
| Font | {<br/>size?: Length;<br/>weight?: <a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-universal-attributes-text-style.md#li24391125115311">FontWeight</a> &nbsp;\| number &nbsp;\| string;<br/>family?: string &nbsp;\| <a href="ts-types.md#Resource">Resource</a>;<br/>style?: <a href="https://gitee.com/superFat/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-universal-attributes-text-style.md#li6906111945316">FontStyle</a>;<br/>} | 设置文本样式：<br/>size: 设置文本尺寸，Length为number类型时，使用fp单位。<br/>weight: 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。<br/>family: 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。<br/>style: 设置文本的字体样式。 |

## CustomBuilder类型<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称 | 类型定义 | 描述 |
| -------- | -------- | -------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | 这种方法类型必须使用@Builder装饰器修饰。具体用法见[@Builder](ts-component-based-builder.md)。 |


## 示例

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

![zh-cn_image_0000001219982719](figures/zh-cn_image_0000001219982719.png)
