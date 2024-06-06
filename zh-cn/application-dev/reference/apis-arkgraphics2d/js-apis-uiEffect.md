# @ohos.uiEffect (效果级联)

本模块提供组件效果的一些基础能力，包括边缘像素扩展，模糊，提亮等。效果被分为Filter和VisualEffect大类，同类效果可以级联在一个效果大类的实例下。

- [Filter](#filter)：用于添加指定Filter效果到组件上。
- [VisualEffect](#visualeffect): 用于添加指定VisualEffect效果到组件上。
- [BrightnessBlender](#brightnessblender): 提亮blender，用于将提亮效果添加到指定的控件上。

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { uiEffect } from "@ohos.graphics.uiEffect";
```

## uiEffect.createFilter
createFilter(): Filter

创建Filter实例用于给组件添加多种filter效果

**系统能力：** SystemCapability.Graphics.Drawing

**参数：** 无

**返回值：**

| 类型              | 说明                 |
| ------------------| ------------------- |
| [Filter](#filter) | 返回Filter的头节点。 |

## uiEffect.createEffect
createEffect(): VisualEffect

创建VisualEffect实例用于给组件添加多种effect效果

**系统能力：** SystemCapability.Graphics.Drawing

**参数：** 无

**返回值：**

| 类型                          | 说明                       |
| ----------------------------- | ------------------------- |
| [VisualEffect](#visualeffect) | 返回VisualEffect的头节点。 |

## uiEffect.createBrightnessBlender
createBrightnessBlender(param: BrightnessBlenderParam): BrightnessBlender

创建BrightnessBlender实例用于给组件添加BrightnessBlender效果

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名  | 类型                                              | 必填 | 说明                        |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | 是   | 用于BrightnessBlender的参数。 |

**返回值：**

| 类型                                     | 说明                     |
| ---------------------------------------- | ----------------------- |
| [BrightnessBlender ](#brightnessblender) | 返回BrightnessBlender。 |

## Filter
Filter效果类，用于将相应的效果添加到指定的控件上。在调用Filter的方法前，需要先通过[createFilter](#uieffectcreatefilter)创建一个Filter实例。

### pixelStretch
pixelStretch(stretchSizes: Array<number>, tileMode: TileMode): Filter

将边缘像素扩展效果添加至组件上

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| stretchSizes  | Array<number>         | 是   | 上下左右四个方向边缘像素扩展的百分比比例，取值范围为[-1, 1]。<br>正值表示向外扩展，上下左右四个方向分别用指定原图比例的边缘像素填充；负值表示内缩，但是最终图像大小不变。<br>注意四个方向对应的参数需统一为非正值或非负值。|
| tileMode      | [TileMode](#tilemode) | 是   | 边缘像素扩展的像素填充模式。 |

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了边缘像素扩展效果的Filter。 |

### blur
blur(blurRadius: number): Filter

将模糊效果添加至组件上

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名       | 类型   | 必填 | 说明       |
| ----------- | -------| ---- | --------- |
| blurRadius  | number | 是   | 模糊半径。 |

**返回值：**

| 类型               | 说明                       |
| ----------------- | -------------------------- |
| [Filter](#filter) | 返回挂载了模糊效果的Filter。 |

### TileMode
[pixelStretch](#pixelstretch)的平铺模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| CLAMP  | 0 | 截断 |
| REPEAT | 1 | 重复 |
| MIRROR | 2 | 镜像 |
| DECAL  | 3 | 透明 |

## VisualEffect
VisualEffect效果类，用于将相应的效果添加到指定的控件上。在调用VisualEffect的方法前，需要先通过[createEffect](#uieffectcreateeffect)创建一个VisualEffect实例。

### backgroundColorBlender
backgroundColorBlender(blender: BrightnessBlender): VisualEffect

将backgroundColorEffect效果添加至组件上

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| blender | [BrightnessBlender](# BrightnessBlender) | 是   | 用于混合背景颜色的blender。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [VisualEffect](#visualeffect) | 返回添加了backgroundColorEffect效果的VisualEffect。 |

## BrightnessBlender
提亮blender，用于将提亮效果添加到指定的控件上。在调用BrightnessBlender前，需要先通过[createBrightnessBlender](#uieffectcreatebrightnessblender)创建一个BrightnessBlender实例。

### BrightnessBlenderParam
BrightnessBlender参数列表

**系统能力：** SystemCapability.Graphics.Drawing

| 名称                | 类型                        | 可读 | 可写 | 说明                            |
| ------------------- | -------------------------- | ---- | ---- | ------------------------------ |
| cubicRate           | number                     | 是   | 是   | 灰度调整的三阶系数。             |
| quadraticRate       | number                     | 是   | 是   | 灰度调整的二阶系数。             |
| linearRate          | number                     | 是   | 是   | 灰度调整的线性系数。             |
| degree              | number                     | 是   | 是   | 灰度调整的比例。                 |
| saturation          | number                     | 是   | 是   | 提亮的基准饱和度。               |
| positiveCoefficient | [number, number, number]   | 是   | 是   | 基于基准饱和度的RGB正向调整参数。 |
| negativeCoefficient | [number, number, number]   | 是   | 是   | 基于基准饱和度的RGB负向调整参数。 |
| fraction            | number                     | 是   | 是   | 提亮效果的混合比例。             |