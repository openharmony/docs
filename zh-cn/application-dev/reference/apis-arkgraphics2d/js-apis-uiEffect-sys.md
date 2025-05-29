# @ohos.graphics.uiEffect (效果级联)(系统接口)

本模块提供组件效果的一些基础能力，包括模糊、边缘像素扩展、提亮等。效果被分为Filter和VisualEffect大类，同类效果可以级联在一个效果大类的实例下。在实际开发中，模糊可用于背景虚化，提亮可用于亮屏显示等。

- [Filter](#filter)：用于添加指定Filter效果到组件上。
- [VisualEffect](#visualeffect)：用于添加指定VisualEffect效果到组件上。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 页面仅包含本模块的系统接口，其他公开接口参见[ohos.graphics.uiEffect (效果级联)](js-apis-uiEffect.md)。

## 导入模块

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
```
## uiEffect.createBrightnessBlender
createBrightnessBlender(param: BrightnessBlenderParam): BrightnessBlender

创建BrightnessBlender实例用于给组件添加提亮效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                              | 必填 | 说明                        |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | 是   | 实现提亮效果的参数。 |

**返回值：**

| 类型                                     | 说明                     |
| ---------------------------------------- | ----------------------- |
| [BrightnessBlender ](#brightnessblender) | 返回设置了提亮效果参数的BrightnessBlender。 |

**示例：**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
```

## Filter
Filter效果类，用于将相应的效果添加到指定的组件上。在调用Filter的方法前，需要先通过[createFilter](js-apis-uiEffect.md#uieffectcreatefilter)创建一个Filter实例。

### pixelStretch
pixelStretch(stretchSizes: Array\<number\>, tileMode: TileMode): Filter

将边缘像素扩展效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| stretchSizes  | Array\<number\>         | 是   | 上下左右四个方向边缘像素扩展的百分比比例，取值范围为[-1, 1]。<br/>正值表示向外扩展，上下左右四个方向分别用指定原图比例的边缘像素填充。负值表示内缩，但是最终图像大小不变。<br/>注意四个方向对应的参数需统一为非正值或非负值。|
| tileMode      | [TileMode](#tilemode) | 是   | 边缘像素扩展的像素填充模式。 |


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了边缘像素扩展效果的Filter。 |

**示例：**

```ts
filter.pixelStretch([0.2, 0.2, 0.2, 0.2], uiEffect.TileMode.CLAMP)
```

### waterRipple
waterRipple(progress: number, waveCount: number, x: number, y: number, rippleMode: WaterRippleMode): Filter

将水波纹效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| progress  | number         | 是   | 表示水波纹的进度，取值范围为[0, 1]。<br/>水波纹进度越趋向于1，水波纹展示越完全。<br/>超出取值范围水波纹不会出现效果。|
| waveCount      | number | 是   | 水波纹波动时波纹的个数，取值范围为[1, 3]。<br/>水波纹的个数只能取整数，如果为浮点数或超出取值范围，水波纹不会出现效果。 |
| x      | number | 是   | 水波纹中心在屏幕中第一次出现的x轴位置。<br/>水波纹对屏幕进行归一化处理，左上角的坐标为（0, 0），右上角坐标为（1, 0）。<br/>当x取值为负值时，代表在屏幕左侧。|
| y      | number | 是   | 水波纹中心在屏幕中第一次出现的y轴位置。<br/>水波纹对屏幕进行归一化处理，左上角的坐标为（0, 0），左下角坐标为（0, 1）。<br/>当y取值为负值时，代表在屏幕上方。 |
| rippleMode      | [WaterRippleMode](#waterripplemode) | 是   | 水波纹的场景模式。|


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了水波纹效果的Filter。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.waterRipple(0.5, 2, 0.5, 0.5, uiEffect.WaterRippleMode.SMALL2SMALL)
```

### flyInFlyOutEffect
flyInFlyOutEffect(degree: number, flyMode: FlyMode): Filter

将飞入飞出形变效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| degree  | number         | 是   | 表示控制飞入飞出形变的程度，取值范围为[0, 1]。<br/>越靠近1，变形程度越明显。<br/>超出取值范围形变不会出现效果。|
| flyMode      | [FlyMode](#flymode) | 是   | 飞入飞出的场景模式。<br/>BOTTOM表示从设备底部飞入飞出形变场景。<br/>TOP表示从设备顶部飞入飞出形变场景。 |


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了飞入飞出形变效果的Filter。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.flyInFlyOutEffect(0.5, uiEffect.FlyMode.TOP)
```

### distort<sup>13+</sup>
distort(distortionK: number): Filter

将透镜畸变效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| distortionK  | number         | 是   | 畸变系数，表示透镜畸变的程度，取值范围为[-1, 1]。畸变系数设置小于-1的值时，按值为-1处理；设置大于1的值时，按值为1处理。|

![zh-ch_image_Add_Distort.png](./figures/zh-ch_image_Add_Distort.png)
如上图是对图片组件分别设置畸变参数为-1，0，0.5，1的绘制结果。畸变参数小于0时，效果为桶形畸变；大于0时，效果为枕形畸变；越接近0时，畸变程度越小，等于0时，没有畸变效果。

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了透镜畸变效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.distort(-0.5)
```


### radiusGradientBlur<sup>19+</sup>
radiusGradientBlur(value: number, options: LinearGradientBlurOptions): Filter

为组件内容添加半径线性渐变模糊效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| value  | number         | 是   | 模糊半径，模糊半径越大越模糊。取值范围为[0, 128]。模糊半径设置为0时不模糊；模糊半径设置小于0的值时，按值为0处理；设置大于128的值时，按值为128处理。|
| options  | [LinearGradientBlurOptions](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#lineargradientbluroptions12对象说明)         | 是   | 线性渐变参数，包含两个部分fractionStops和direction。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了半径线性渐变模糊效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.radiusGradientBlur(20, {fractionStops: [[0, 0], [0.5, 0.2], [1.0, 1.0]], direction: GradientDirection.Bottom})
```

## TileMode
像素填充模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| CLAMP  | 0 | 截断。 |
| REPEAT | 1 | 重复。 |
| MIRROR | 2 | 镜像。 |
| DECAL  | 3 | 透明。 |

## WaterRippleMode
水波纹场景模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| SMALL2MEDIUM_RECV  | 0 | 手机碰2in1设备（接收端）。 |
| SMALL2MEDIUM_SEND  | 1 | 手机碰2in1设备（发送端）。 |
| SMALL2SMALL | 2 | 手机碰手机。 |
| MINI_RECV<sup>17+</sup> | 3 | 2in1设备与其它设备共享（键鼠共享场景）。 |

## FlyMode
飞入飞出形变场景模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| BOTTOM  | 0 | 从底部进行飞入飞出形变。 |
| TOP  | 1 | 从顶部进行飞入飞出形变。 |

## VisualEffect
VisualEffect效果类，用于将相应的效果添加到指定的组件上。在调用VisualEffect的方法前，需要先通过[createEffect](js-apis-uiEffect.md#uieffectcreateeffect)创建一个VisualEffect实例。

### backgroundColorBlender
backgroundColorBlender(blender: BrightnessBlender): VisualEffect

将混合器添加至组件上以改变组件背景颜色，具体的更改效果由输入决定，目前仅支持提亮混合器。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| blender | [BrightnessBlender](#brightnessblender) | 是   | 用于混合背景颜色的blender。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [VisualEffect](#visualeffect) | 返回添加了背景颜色更改效果的VisualEffect。 |

**示例：**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
visualEffect.backgroundColorBlender(blender)
```

## Blender<sup>13+</sup>

type Blender = BrightnessBlender

混合器类型，用于描述混合效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [BrightnessBlender](#brightnessblender) | 具有提亮效果的混合器。 |

## BrightnessBlender
提亮混合器，用于将提亮效果添加到指定的组件上。在调用BrightnessBlender前，需要先通过[createBrightnessBlender](#uieffectcreatebrightnessblender)创建一个BrightnessBlender实例。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称                | 类型                        | 只读 | 可选 | 说明                                                              |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | 否   | 否   | 灰度调整的三阶系数。<br/>取值范围[-20, 20]。                        |
| quadraticRate       | number                     | 否   | 否   | 灰度调整的二阶系数。<br/>取值范围[-20, 20]。                        |
| linearRate          | number                     | 否   | 否   | 灰度调整的线性系数。<br/>取值范围[-20, 20]。                        |
| degree              | number                     | 否   | 否   | 灰度调整的比例。<br/>取值范围[-20, 20]。                            |
| saturation          | number                     | 否   | 否   | 提亮的基准饱和度。<br/>取值范围[0, 20]。                            |
| positiveCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB正向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| negativeCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB负向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| fraction            | number                     | 否   | 否   | 提亮效果的混合比例。<br/>取值范围[0, 1]，超出边界会在实现时自动截断。  |

## BrightnessBlenderParam
BrightnessBlender参数列表。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称                | 类型                        | 只读 | 可选 | 说明                                                              |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | 否   | 否   | 灰度调整的三阶系数。<br/>取值范围[-20, 20]。                        |
| quadraticRate       | number                     | 否   | 否   | 灰度调整的二阶系数。<br/>取值范围[-20, 20]。                        |
| linearRate          | number                     | 否   | 否   | 灰度调整的线性系数。<br/>取值范围[-20, 20]。                        |
| degree              | number                     | 否   | 否   | 灰度调整的比例。<br/>取值范围[-20, 20]。                            |
| saturation          | number                     | 否   | 否   | 提亮的基准饱和度。<br/>取值范围[0, 20]。                            |
| positiveCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB正向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| negativeCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB负向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| fraction            | number                     | 否   | 否   | 提亮效果的混合比例。<br/>取值范围[0, 1]，超出边界会在实现时自动截断。  |