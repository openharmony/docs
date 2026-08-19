# 前景属性设置
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

设置组件的前景属性，通过模糊半径参数对组件前景内容应用模糊效果。

>  **说明：**
>
> - 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## foregroundEffect

foregroundEffect(options: ForegroundEffectOptions): T

设置组件的前景模糊效果。仅在组件范围内生效，与backgroundEffect、blur等接口连用时超出组件范围的效果无法生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| options | [ForegroundEffectOptions](#foregroundeffectoptions) | 是   | 设置组件前景效果，包括：模糊半径。效果仅在组件范围内生效，与backgroundEffect、blur等接口连用时超出组件范围的效果无法生效。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## ForegroundEffectOptions

前景效果参数，用于配置组件前景的模糊半径，控制前景内容的模糊程度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        |   类型         |   只读 |   可选 |  说明                        |
| ----         |  ----         |   ---- |   ---- | --------------------------  |
| radius       | number        |   否   |   否   |   模糊半径，设置后组件前景呈现模糊效果，数值越大模糊程度越高。取值范围：[0, +∞)，0表示不产生模糊效果。传入负数时自动修正为0。仅在组件范围内生效，与backgroundBlur等效果类接口连用时超出组件范围的效果无法生效。     |

## 示例

该示例演示通过foregroundEffect接口设置前景属性。

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      // $r('app.media.icon')需要替换为开发者所需的图像资源文件。
      Image($r('app.media.icon'))
          .width(100)
          .height(100)
          // 设置前景模糊效果，模糊半径为20
          .foregroundEffect({ radius: 20 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

效果图如下：

radius表示模糊半径，数值越大，效果越模糊。

![foregroundColor_circle](figures/foregroundEffect.jpg)
