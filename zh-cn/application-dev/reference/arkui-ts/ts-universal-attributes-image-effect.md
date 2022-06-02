# 图像效果

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| blur | number | - | 为当前组件添加内容模糊效果，入参为模糊半径，模糊半径越大越模糊，为0时不模糊。 |
| backdropBlur | number | - | 为当前组件添加背景模糊效果，入参为模糊半径，模糊半径越大越模糊，为0时不模糊。 |
| shadow | {<br/>radius:&nbsp;number,<br/>color?:&nbsp;Color,<br/>offsetX?:&nbsp;number,<br/>offsetY?:&nbsp;number<br/>} | - | 为当前组件添加阴影效果，入参为模糊半径(必填)、阴影的颜色(可选，默认为灰色)、X轴的偏移量(可选，默认为0)，Y轴的偏移量(可选，默认为0)，偏移量单位为px。 |
| grayscale | number | 0.0 | 为当前组件添加灰度效果。值定义为灰度转换的比例，入参1.0则完全转为灰度图像，入参则0.0图像无变化，入参在0.0和1.0之间时，效果呈线性变化。（百分比) |
| brightness | number | 1.0 | 为当前组件添加高光效果，入参为高光比例，值为1时没有效果，小于1时亮度变暗，0为全黑；大于1时亮度增加，数值越大亮度越大。 |
| saturate | number | 1.0 | 为当前组件添加饱和度效果，饱和度为颜色中的含色成分和消色成分(灰)的比例，入参为1时，显示原图像，大于1时含色成分越大，饱和度越大；小于1时消色成分越大，饱和度越小。（百分比） |
| contrast | number | 1.0 | 为当前组件添加对比度效果，入参为对比度的值，值为1时，显示原图；大于1时，值越大对比度越高，图像越清晰醒目；小于1时，值越小对比度越低；当对比度为0时，图像变为全灰。（百分比） |
| invert | number | 0 | 反转输入的图像。入参为图像反转的比例。值为1时完全反转。值为0则图像无变化。（百分比） |
| colorBlend&nbsp;<sup>8+</sup> | Color | - | 为当前组件添加颜色叠加效果，入参为叠加的颜色。 |
| sepia | number | 0 | 将图像转换为深褐色。入参为图像反转的比例。值为1则完全是深褐色的，值为0图像无变化。&nbsp;（百分比） |
| hueRotate | Angle | 0deg | 为当前组件添加色相旋转效果，入参为旋转的角度值。当入参为0deg时图像无变化(默认值是0deg)，入参没有最大值，超过360deg的值相当于又绕一圈。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ImageEffectsExample {
  build() {
    Column({space: 10}) {
      // 对字体进行模糊
      Text('font blur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Text('text').blur(3).width('90%').height(40)
        .fontSize(16).backgroundColor(0xF9CF93).padding({ left: 5 })

      // 对背景进行模糊
      Text('backdropBlur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Text().width('90%').height(40).fontSize(16).backdropBlur(3)
        .backgroundImage('/comment/bg.jpg')
        .backgroundImageSize({ width: 1200, height: 160 })

      Text('shadow').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40)
        .shadow({ radius: 10, color: Color.Gray, offsetX: 5, offsetY: 5 })

      Text('grayscale').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).grayscale(0.6)

      Text('brightness').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).brightness(2.0)

      Text('saturate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).saturate(2.0)

      Text('contrast').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).contrast(2.0)

      Text('invert').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).invert(1)

      Text('hueRotate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).hueRotate(90)
    }.width('100%').margin({ top: 5 })
  }
}
```


