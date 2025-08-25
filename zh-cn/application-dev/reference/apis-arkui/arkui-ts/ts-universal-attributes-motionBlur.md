# 运动模糊
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @yangfan229-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

设置组件由缩放大小或位移变化引起的运动过程中的动态模糊效果。需要与动画的AnimateParam的onFinish参数配合使用。

>  **说明：**
>
>  从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## motionBlur

motionBlur(value: MotionBlurOptions): T

在当前组件由缩放大小或位移变化引起的运动过程中，增加动态模糊效果。

1、不建议在组件内转场、共享元素转场、组件内隐式元素转场和粒子动画场景中使用该属性，否则会产生非预期效果。

2、该属性需要在开始状态将motionBlur的参数radius设置为0，否则冷启动时会有非预期效果。

3、该属性需要与动画的AnimateParam的onFinish参数配合使用,需要在运动模糊动画结束后将motionBlur的参数radius置为0，否则会产生非预期效果。

4、在使用该属性过程中，不要在使用过程中频繁更改同一个组件的模糊半径，否则会产生非预期效果。比如示例中的动画，频繁点击会出现模糊效果偶尔失效的情况。

5、运动模糊锚点坐标需要与动画缩放的锚点保持一致，否则会产生非预期效果。

6、模糊半径建议设置1以内，否则会产生非预期效果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                            | 必填 | 说明               |
| ------ | ----------------------------------------------- | ---- | ------------------ |
| value  | [MotionBlurOptions](#motionbluroptions对象说明) | 是   | 定义运动模糊参数。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## motionBlur<sup>18+</sup>

motionBlur(motionBlur: Optional\<MotionBlurOptions>): T

在当前组件由缩放大小或位移变化引起的运动过程中，增加动态模糊效果。与[motionBlur](#motionblur)相比，motionBlur参数新增了对undefined类型的支持。

1、不建议在组件内转场、共享元素转场、组件内隐式元素转场、粒子动画场景下使用该属性，否则会产生非预期效果。

2、该属性需要在开始状态将motionBlur的参数radius设置为0，否则冷启动时会有非预期效果。

3、该属性需要与动画的AnimateParam的onFinish参数配合使用，需要在运动模糊动画结束后将motionBlur的参数radius置为0，否则会产生非预期效果。

4、在使用该属性过程中，不要在使用过程中频繁更改同一个组件的模糊半径，否则会产生非预期效果。比如示例中的动画，频繁点击会出现模糊效果偶尔失效的情况。

5、运动模糊锚点坐标需要与动画缩放的锚点保持一致，否则会产生非预期效果。

6、模糊半径建议设置1以内，否则会产生非预期效果。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

|   参数名    |    类型                                                      |  必填  |     说明                                                       |
| ---------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| motionBlur | Optional\<[MotionBlurOptions](#motionbluroptions对象说明)> | 是   | 定义运动模糊参数。<br/>当motionBlur的值为undefined时，维持之前取值。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件。 |

## MotionBlurOptions对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                                                        | 必填  | 说明                                                         |
| ------------- | ----------------------------------------------------------- | ----- | ------------------------------------------------------------ |
| radius | number      | 是    | 模糊半径，取值范围[0.0, ∞)，建议设置1.0以内。 |
| anchor | [MotionBlurAnchor](#motionbluranchor对象说明) | 是    | 运动模糊锚点坐标。运动模糊锚点坐标设置时需要与动画缩放的锚点保持一致设置。 |

## MotionBlurAnchor对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                                                        | 必填  | 说明                                                         |
| ------------- | ----------------------------------------------------------- | ----- | ------------------------------------------------------------ |
| x | number      | 是    | 锚点坐标x值，取值范围[0.0, 1.0]。 |
| y | number      | 是    | 锚点坐标y值，取值范围[0.0, 1.0]。 |

## 示例

属性动画状态下添加运动模糊效果。
```ts
// xxx.ets
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct motionBlurTest {
  @State widthSize: number = 400;
  @State heightSize: number = 320;
  @State flag: boolean = true;
  @State radius: number = 0;
  @State x: number = 0;
  @State y: number = 0;

  build() {
    Column() {
      Column() {
        Image($r('app.media.testImg'))
          .width(this.widthSize)
          .height(this.heightSize)
          .onClick(() => {
            this.radius = 5;
            this.x = 0.5;
            this.y = 0.5;
            if (this.flag) {
              this.widthSize = 100;
              this.heightSize = 80;
            } else {
              this.widthSize = 400;
              this.heightSize = 320;
            }
            this.flag = !this.flag;
          })
          .animation({
            duration: 2000,
            curve: curves.springCurve(10, 1, 228, 30),
            onFinish: () => {
              this.radius = 0;
            }
          })
          .motionBlur({ radius: this.radius, anchor: { x: this.x, y: this.y } })
      }
    }.width('100%').margin({ top: 5 })
  }
}
```

![motionBlurTest](figures/motionBlur.gif)
