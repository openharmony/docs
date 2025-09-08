# 形状裁剪
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

用于对组件进行裁剪、遮罩处理。

>  **说明：**
>
> 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## clip<sup>12+</sup>

clip(value: boolean): T

是否对子组件超出当前组件范围外的区域进行裁剪。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 参数为boolean类型，设置是否按照父容器边缘轮廓进行裁剪。<br/>默认值：false <br/>true表示按照父容器边缘轮廓进行裁剪，false表示不对子组件进行裁剪。 <br/>**说明：** 设置为true后，子组件超出当前组件范围外的区域将不响应绑定的手势事件。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## clip<sup>18+</sup>

clip(clip: Optional\<boolean>): T

是否对子组件超出当前组件范围外的区域进行裁剪。与[clip<sup>12+</sup>](#clip12)相比，clip参数新增了对undefined类型的支持。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型               | 必填                                                         | 说明 |
| ------ | ------------------ | ------------------------------------------------------------ | ---- |
| clip   | Optional\<boolean> | 是 |  参数为boolean类型，设置是否按照父容器边缘轮廓进行裁剪。<br/>默认值：false <br/>**说明：** 设置为true后，子组件超出当前组件范围外的区域将不响应绑定的手势事件。<br/>当clip的值为undefined时，恢复为不对子组件超出当前组件范围外的区域进行裁剪。    |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## clip<sup>(deprecated)</sup>

clip(value: boolean | CircleAttribute | EllipseAttribute | PathAttribute | RectAttribute): T

按指定的形状对当前组件进行裁剪。

> **说明：**  
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[clip](#clip12)和[clipShape](#clipshape12)替代。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | boolean&nbsp;\|&nbsp;[CircleAttribute](ts-drawing-components-circle.md)&nbsp;\|&nbsp;[EllipseAttribute](ts-drawing-components-ellipse.md)&nbsp;\|&nbsp;[PathAttribute](ts-drawing-components-path.md)&nbsp;\|&nbsp;[RectAttribute](ts-drawing-components-rect.md) | 是   | 参数为相应类型的组件，按指定的形状对当前组件进行裁剪；参数为boolean类型时，设置是否按照父容器边缘轮廓进行裁剪。<br/>默认值：false <br/>**说明：** 参数为对应类型的组件时，裁剪不会导致被裁剪区域无法响应绑定的手势事件。参数为boolean类型时，裁剪会导致被裁剪区域无法响应绑定的手势事件。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## clipShape<sup>12+</sup>

clipShape(value: CircleShape | EllipseShape | PathShape | RectShape): T

按指定的形状（形状中可包含位置信息）对当前组件进行裁剪。

> **说明：**  
>
> 不同的形状支持的属性范围不同，路径是一种形状，除此之外还有椭圆、矩形等形状。
>
> 路径的形状不支持设置宽度和高度。具体形状支持的属性参考具体形状的文档。
>
> 形状中的[fill](../js-apis-arkui-shape.md#fill)属性对clipShape接口不生效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [CircleShape](#circleshape12)&nbsp;\|&nbsp;[EllipseShape](#ellipseshape12)&nbsp;\|&nbsp;[PathShape](#pathshape12)&nbsp;\|&nbsp;[RectShape](#rectshape12) | 是   | 参数为相应类型的组件，按指定的形状（形状中可包含位置信息）对当前组件进行裁剪。<br/>**说明：** 裁剪不会导致被裁剪区域无法响应绑定的手势事件。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## clipShape<sup>18+</sup>

clipShape(shape: Optional\<CircleShape | EllipseShape | PathShape | RectShape>): T

按指定的形状（形状中可包含位置信息）对当前组件进行裁剪。与[clipShape<sup>12+</sup>](#clipshape12)相比，shape参数新增了对undefined类型的支持。

> **说明：**  
>
> 不同的形状支持的属性范围不同，路径是一种形状，除此之外还有椭圆、矩形等形状。
>
> 路径的形状不支持设置宽度和高度。具体形状支持的属性参考具体形状的文档。
>
> 形状中的[fill](../js-apis-arkui-shape.md#fill)属性对clipShape接口不生效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| shape  | Optional\<[CircleShape](#circleshape12)&nbsp;\|&nbsp;[EllipseShape](#ellipseshape12)&nbsp;\|&nbsp;[PathShape](#pathshape12)&nbsp;\|&nbsp;[RectShape](#rectshape12)> | 是   | 参数为相应类型的组件，按指定的形状（形状中可包含位置信息）对当前组件进行裁剪。<br/>**说明：** 裁剪不会导致被裁剪区域无法响应绑定的手势事件。<br/>当shape的值为undefined时，会重置当前值。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## CircleShape<sup>12+</sup>

type CircleShape = CircleShape

导入CircleShape类型对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                     |
| ------ | ------------------------ |
| [CircleShape](../js-apis-arkui-shape.md#circleshape) | 圆形形状。 |

## EllipseShape<sup>12+</sup>

type EllipseShape = EllipseShape

导入EllipseShape类型对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                     |
| ------ | ------------------------ |
| [EllipseShape](../js-apis-arkui-shape.md#ellipseshape) | 椭圆形状。 |

## PathShape<sup>12+</sup>

type PathShape = PathShape

导入PathShape类型对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                     |
| ------ | ------------------------ |
| [PathShape](../js-apis-arkui-shape.md#pathshape) | 接口路径。 |

## RectShape<sup>12+</sup>

type RectShape = RectShape

导入RectShape类型对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                     |
| ------ | ------------------------ |
| [RectShape](../js-apis-arkui-shape.md#rectshape) | 矩形形状。 |

## mask<sup>12+</sup>

mask(value: ProgressMask): T

为组件上添加可调节进度的遮罩。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                                 |
| ------ | ------------------------------- | ---- | ---------------------------------------------------- |
| value  | [ProgressMask](#progressmask10) | 是   | 在当前组件上加上可动态设置进度、最大值和颜色的遮罩。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## mask<sup>18+</sup>

mask(mask: Optional\<ProgressMask>): T

为组件上添加可调节进度的遮罩。与[mask<sup>12+</sup>](#mask12)相比，mask参数新增了对undefined类型的支持。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                             |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| mask | Optional\<[ProgressMask](#progressmask10)> | 是 | 在当前组件上加上可动态设置进度、最大值和颜色的遮罩。<br/>当mask的值为undefined时，恢复为无进度遮罩效果。     |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## mask<sup>(deprecated)</sup>

mask(value: CircleAttribute | EllipseAttribute | PathAttribute | RectAttribute | ProgressMask): T

为组件上添加指定形状的遮罩。

> **说明：**  
>
> 从API version 7开始支持，从API version 12开始废弃。建议使用[mask](#mask12)和[maskShape](#maskshape12)替代。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                             |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| value  | [CircleAttribute](ts-drawing-components-circle.md)&nbsp;\|&nbsp;[EllipseAttribute](ts-drawing-components-ellipse.md)&nbsp;\|&nbsp;[PathAttribute](ts-drawing-components-path.md)&nbsp;\|&nbsp;[RectAttribute](ts-drawing-components-rect.md) \|&nbsp;[ProgressMask](#progressmask10)<sup>10+</sup> | 是   | 在当前组件上加上指定形状的遮罩。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## maskShape<sup>12+</sup>

maskShape(value: CircleShape | EllipseShape | PathShape | RectShape): T

为组件上添加指定形状的遮罩。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                             |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| value  | [CircleShape](#circleshape12)&nbsp;\|&nbsp;[EllipseShape](#ellipseshape12)&nbsp;\|&nbsp;[PathShape](#pathshape12)&nbsp;\|&nbsp;[RectShape](#rectshape12) | 是   | 在当前组件上加上指定形状的遮罩。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## maskShape<sup>18+</sup>

maskShape(shape: Optional\<CircleShape | EllipseShape | PathShape | RectShape>): T

为组件上添加指定形状的遮罩。与[maskShape<sup>12+</sup>](#maskshape12)相比，shape参数新增了对undefined类型的支持。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| shape  | Optional\<[CircleShape](#circleshape12)&nbsp;\|&nbsp;[EllipseShape](#ellipseshape12)&nbsp;\|&nbsp;[PathShape](#pathshape12)&nbsp;\|&nbsp;[RectShape](#rectshape12)> | 是   | 在当前组件上加上指定形状的遮罩。<br/>当shape的值为undefined时，会重置当前值。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## ProgressMask<sup>10+</sup>

ProgressMask设置遮罩的进度、最大值和颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor<sup>10+</sup>

constructor(value: number, total: number, color: ResourceColor)

构造ProgressMask对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                   | 必填 | 说明           |
| ------ | ------------------------------------------ | ---- | ------------------ |
| value  | number                                     | 是   | 进度遮罩的当前值。<br/> 取值范围：[0.0, +∞) |
| total  | number                                     | 是   | 进度遮罩的最大值。<br/> 取值范围：[0.0, +∞) |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 进度遮罩的颜色。   |

### updateProgress<sup>10+</sup>

updateProgress(value: number): void

更新进度遮罩的进度值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| ------ | -------- | ---- | ------------------ |
| value  | number   | 是   | 进度遮罩的当前值。 |

### updateColor<sup>10+</sup>

updateColor(value: ResourceColor): void

更新进度遮罩的颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                   | 必填 | 说明         |
| ------ | ------------------------------------------ | ---- | ---------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 进度遮罩的颜色。 |

### enableBreathingAnimation<sup>12+</sup>

enableBreathingAnimation(value: boolean): void

进度满时的呼吸光晕动画开关。默认关闭呼吸光晕动画。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                   | 必填 | 说明         |
| ------ | ------------------------------------------ | ---- | ---------------- |
| value  | boolean | 是   | 设置为true则开启呼吸光晕动画。默认值：false |


## 示例

### 示例1（使用不同裁剪属性）

```ts
// xxx.ets
import { CircleShape, RectShape } from '@kit.ArkUI';

@Entry
@Component
struct ClipAndMaskExample {
  build() {
    Column({ space: 15 }) {
      Text('clip').fontSize(12).width('75%').fontColor('#DCDCDC')
      Row() {
        // $r("app.media.testImg")需要替换为开发者所需的图像资源文件。
        Image($r('app.media.testImg')).width('500px').height('280px')
      }
      .clip(true) // 如这里不设置clip为true，则Row组件的圆角不会限制其中的Image组件，Image组件的四个角会超出Row
      .borderRadius(20)

      // 用一个280px直径的圆对图片进行裁剪
      // $r("app.media.testImg")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.testImg'))
        .clipShape(new CircleShape({ width: '280px', height: '280px' }))
        .width('500px').height('280px')

      Text('mask').fontSize(12).width('75%').fontColor('#DCDCDC')
      // 给图片添加了一个500px*280px的方形遮罩
      // $r("app.media.testImg")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.testImg'))
        .maskShape(new RectShape({ width: '500px', height: '280px' }).fill(Color.Gray))
        .width('500px').height('280px')

      // 给图片添加了一个280px*280px的圆形遮罩
      // $r("app.media.testImg")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.testImg'))
        .maskShape(new CircleShape({ width: '280px', height: '280px' }).fill(Color.Gray))
        .width('500px').height('280px')
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![clipAndMask](figures/clipAndMask.PNG)

### 示例2（裁剪属性动画）

```ts
@Entry
@Component
struct ProgressMaskExample {
  @State progressFlag1: boolean = true;
  @State color: Color = 0x01006CDE;
  @State value: number = 10.0;
  @State enableBreathingAnimation: boolean = false;
  @State progress: ProgressMask = new ProgressMask(10.0, 100.0, Color.Gray);

  build() {
    Column({ space: 15 }) {
      Text('progress mask').fontSize(12).width('75%').fontColor('#DCDCDC')
      // 给图片添加了一个280px*280px的进度遮罩
      // $r("app.media.testImg")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.testImg'))
        .width('500px').height('280px')
        .mask(this.progress)
        .animation({
          duration: 2000, // 动画时长
          curve: Curve.Linear, // 动画曲线
          delay: 0, // 动画延迟
          iterations: 1, // 播放次数
          playMode: PlayMode.Normal // 动画模式
        }) // 对Button组件的宽高属性进行动画配置

      // 更新进度遮罩的进度值
      Button('updateProgress')
        .onClick((event?: ClickEvent) => {
          this.value += 10;
          this.progress.updateProgress(this.value);
        }).width(200).height(50).margin(20)

      // 更新进度遮罩的颜色
      Button('updateColor')
        .onClick((event?: ClickEvent) => {
          if (this.progressFlag1) {
            this.progress.updateColor(0x9fff0000);
          } else {
            this.progress.updateColor(0x9f0000ff);
          }
          this.progressFlag1 = !this.progressFlag1
        }).width(200).height(50).margin(20)

      // 开关呼吸光晕动画
      Button('enableBreathingAnimation:' + this.enableBreathingAnimation)
        .onClick((event?: ClickEvent) => {
          this.enableBreathingAnimation = !this.enableBreathingAnimation;
          this.progress.enableBreathingAnimation(this.enableBreathingAnimation);
        }).width(200).height(50).margin(20)

      // 恢复进度遮罩
      Button('click reset!')
        .onClick((event?: ClickEvent) => {
          this.value = 0;
          this.progress.updateProgress(this.value);
        }).width(200).height(50).margin(20)
    }
    .width('100%')
    .margin({ top: 15 })
  }
}
```

![progressMask](figures/progressMask.gif)
