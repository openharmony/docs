# 视效设置
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供接口设置组件视觉效果，包括滤镜效果（如：模糊、像素扩展等）和非滤镜效果（如：点光源等）。

>  **说明：**
>
> - 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## visualEffect

visualEffect(effect: VisualEffect): T

设置非滤镜视觉效果，如点光源等。具体可添加的效果参见VisualEffect的方法说明。

>**说明：**
>
> 从API version 20开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| effect | [VisualEffect](#visualeffect-1) | 是   | 非滤镜视觉效果，如点光源等非滤镜效果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## backgroundFilter

backgroundFilter(filter: Filter): T

设置背景滤镜视觉效果，作用于组件背景层。各滤镜的绘制顺序参见[materialFilter](#materialfilter23)。

>**说明：**
>
> 从API version 20开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| filter | [Filter](#filter) | 是   | 背景滤镜视觉效果，如模糊、像素扩展等滤镜效果。该滤镜绘制晚于materialFilter，位于materialFilter上层。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## foregroundFilter

foregroundFilter(filter: Filter): T

设置前景滤镜（内容）视觉效果，如模糊、像素扩展等。多个滤镜同时设置在同一组件上时，前景滤镜的绘制位于所有其他滤镜之上。绘制顺序从底到顶为：materialFilter → backgroundFilter → compositingFilter → foregroundFilter。

>**说明：**
>
> 从API version 20开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| filter | [Filter](#filter) | 是   | 前景滤镜（内容）视觉效果，如模糊、像素扩展等滤镜效果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## compositingFilter

compositingFilter(filter: Filter): T

设置合成滤镜视觉效果，如模糊、像素扩展等。合成滤镜用于对组件前景与背景合成后的整体图像应用滤镜效果。多个滤镜同时设置在同一组件上时，合成滤镜的绘制位于背景滤镜之上、前景滤镜之下。绘制顺序从底到顶为：materialFilter → backgroundFilter → compositingFilter → foregroundFilter。

>**说明：**
>
> 从API version 20开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| filter | [Filter](#filter) | 是   | 合成滤镜视觉效果，如模糊、像素扩展等滤镜效果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## materialFilter<sup>23+</sup>

materialFilter(filter: Filter \| undefined): T

设置系统材质滤镜视觉效果，系统材质为系统预定义的材质样式。系统材质滤镜的绘制早于[backgroundFilter](#backgroundfilter)绘制，即位于backgroundFilter的更底层。绘制顺序从底到顶为：materialFilter → backgroundFilter → compositingFilter → foregroundFilter。

>**说明：**
>
> 该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                 |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| filter | [Filter](#filter) &nbsp;\|&nbsp; undefined | 是   | 系统材质滤镜视觉效果。该滤镜绘制早于backgroundFilter，位于backgroundFilter更底层。设置为undefined时恢复为无系统材质滤镜效果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## Filter

type Filter = import('../api/@ohos.graphics.uiEffect').default.Filter

导入Filter类型对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型   | 说明                     |
| ------ | ------------------------ |
| import('../api/@ohos.graphics.uiEffect').default.[Filter](../../apis-arkgraphics2d/js-apis-uiEffect.md#filter) | 用于将滤镜效果添加到指定的组件上。 |

## VisualEffect

type VisualEffect = import('../api/@ohos.graphics.uiEffect').default.VisualEffect

导入VisualEffect类型对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型   | 说明                     |
| ------ | ------------------------ |
| import('../api/@ohos.graphics.uiEffect').default.[VisualEffect](../../apis-arkgraphics2d/js-apis-uiEffect.md#visualeffect) | 用于将非滤镜视觉效果添加到指定的组件上。 |

## 示例

该示例主要演示前景滤镜、背景滤镜和合成滤镜的模糊效果。

```ts
// xxx.ets
import { uiEffect } from '@kit.ArkGraphics2D';

@Entry
@Component
struct FilterEffectExample {
  @State foregroundBlurFilter: uiEffect.Filter = uiEffect.createFilter().blur(10);
  @State backgroundBlurFilter: uiEffect.Filter = uiEffect.createFilter().blur(10);
  @State compositingBlurFilter: uiEffect.Filter = uiEffect.createFilter().blur(10);

  build() {
    Column({ space: 15 }) {

      Text('foregroundFilter').fontSize(20).width('75%').fontColor('#DCDCDC')
      Text('前景滤镜')
        .width(100)
        .height(100)
        .backgroundColor('#ADD8E6')
        // $r("app.media.app_icon")需在项目的“resources/base/media”目录下准备名为app_icon的图片资源文件
        .backgroundImage($r('app.media.app_icon'))
        .backgroundImageSize({ width: 80, height: 80 })
        .foregroundFilter(this.foregroundBlurFilter) // 通过foregroundFilter设置模糊效果

      Text('backgroundFilter').fontSize(20).width('75%').fontColor('#DCDCDC')
      Text('背景滤镜')
        .width(100)
        .height(100)
        .backgroundColor('#ADD8E6')
        // $r("app.media.app_icon")需替换为开发者所需的资源文件
        .backgroundImage($r('app.media.app_icon'))
        .backgroundImageSize({ width: 80, height: 80 })
        .backgroundFilter(this.backgroundBlurFilter) // 通过backgroundFilter设置模糊效果

      Text('compositingFilter').fontSize(20).width('75%').fontColor('#DCDCDC')
      Text('合成滤镜')
        .width(100)
        .height(100)
        .backgroundColor('#ADD8E6')
        // $r("app.media.app_icon")需替换为开发者所需的资源文件
        .backgroundImage($r('app.media.app_icon'))
        .backgroundImageSize({ width: 80, height: 80 })
        .compositingFilter(this.compositingBlurFilter) // 通过compositingFilter设置模糊效果
    }
    .height('100%')
    .width('100%')
  }
}
```

![filterEffect](figures/filterEffectWithText.jpg)
