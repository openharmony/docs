# 隐私遮罩
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

用于对组件内容进行隐私遮罩处理。

>  **说明：**
>
> - 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## obscured

obscured(reasons: Array&lt;ObscuredReasons&gt;): T

设置组件内容的隐私遮罩类型，在屏幕录制或屏幕共享等场景下对组件内容进行隐私遮挡。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| reasons | Array<[ObscuredReasons](ts-appendix-enums.md#obscuredreasons10)> | 是 | 设置组件内容的遮罩类型，在屏幕录制或屏幕共享等场景下对组件内容进行隐私遮挡。取值原则：请参考[ObscuredReasons](ts-appendix-enums.md#obscuredreasons10)枚举定义，如PLACEHOLDER表示使用占位图遮罩。<br>默认值：[]，未设置遮罩原因时，不对组件内容进行隐私遮罩处理。<br>隐私遮罩效果仅在[Image](ts-basic-components-image.md)组件、[Text](ts-basic-components-text.md)组件<!--Del-->和[FormComponent](ts-basic-components-formcomponent-sys.md)组件<sup>12+</sup><!--DelEnd-->上生效。<br>**说明：**<br>如需在图片加载过程中显示隐私遮罩，需要设置Image组件的宽度和高度；若未设置宽度和高度，图片加载过程中将不会显示隐私遮罩效果。<br>Text组件设置子组件或设置[属性字符串](ts-universal-styled-string.md)时，不支持隐私遮罩。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## 示例

该示例通过obscured对Text、Image组件实现了隐私遮罩效果。

```ts
// xxx.ets
@Entry
@Component
struct ObscuredExample {
  build() {
    Row() {
      Column() {
        Text('Text not set obscured attribute').fontSize(10).fontColor(Color.Black)
        Text('This is an example for text obscured attribute.')
          .fontSize(30)
          .width('600px')
          .fontColor(Color.Black)
          .border({ width: 1 })
        Text('Image not set obscured attribute').fontSize(10).fontColor(Color.Black)
        // $r('app.media.icon')需要替换为开发者所需的图像资源文件。
        Image($r('app.media.icon'))
          .width('200px')
          .height('200px')
        Text('Text set obscured attribute').fontSize(10).fontColor(Color.Black)
        Text('This is an example for text obscured attribute.')
          .fontSize(30)
          .width('600px')
          .fontColor(Color.Black)
          .border({ width: 1 })
          .obscured([ObscuredReasons.PLACEHOLDER])
        Text('Image set obscured attribute').fontSize(10).fontColor(Color.Black)
        // $r('app.media.icon')需要替换为开发者所需的图像资源文件。
        Image($r('app.media.icon'))
          .width('200px')
          .height('200px')
          .obscured([ObscuredReasons.PLACEHOLDER])
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![obscured](figures/obscured.png)

