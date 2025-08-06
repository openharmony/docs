# Hyperlink
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--SE: @pssea-->
<!--TSE: @jiaoaozihao-->

超链接组件，组件宽高范围内点击实现跳转。

>  **说明：**
>
>  - 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 该组件仅支持与系统浏览器配合使用。

## 需要权限

跳转的目标应用使用网络时，需要申请权限ohos.permission.INTERNET。具体申请方式请参考[声明权限](../../../security/AccessToken/declare-permissions.md)。

## 子组件

可以包含[Image](ts-basic-components-image.md)子组件。

## 接口

Hyperlink(address: string | Resource, content?: string | Resource)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| address | string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是 | Hyperlink组件跳转的网页。 |
| content | string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 否 | Hyperlink组件中超链接显示文本。<br/>**说明：** <br/>组件内有子组件时，不显示超链接文本。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### color

color(value: Color | number | string | Resource)

设置超链接文本的颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [Color](ts-appendix-enums.md#color)&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 超链接文本的颜色。<br /><!--RP1-->默认值：'#ff007dff'<br />warable设备上默认值为：'ff1f71ff'<!--RP1End-->

## 示例

该示例展示了超链接图片和文本跳转的效果。

```ts
@Entry
@Component
struct HyperlinkExample {
  build() {
    Column() {
      Column() {
        Hyperlink('https://example.com/') {
          Image($r('app.media.bg'))
            .width(200)
            .height(100)
        }
      }

      Column() {
        Hyperlink('https://example.com/', 'Go to the developer website') {
        }
        .color(Color.Blue)
      }
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
```

![hyperlink](figures/hyperlink.PNG)
