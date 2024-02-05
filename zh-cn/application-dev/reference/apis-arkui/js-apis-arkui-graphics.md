# Graphics

自定义节点相关属性定义的详细信息。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { DrawContext, Size, Offset, Position, Pivot, Scale, Translation, Matrix4, Rotation, Frame } from "@ohos.arkui.node";
```

## Size

用于返回组件布局大小的宽和高，单位为vp。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 可读 | 可写 | 说明                   |
| ------ | ------ | ---- | ---- | ---------------------- |
| width  | number | 是   | 是   | 组件的宽度，单位为vp。 |
| height | number | 是   | 是   | 组件的高度，单位为vp。 |

## Position

用于设置或返回组件的位置。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                     |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | 是   | 是   | 水平方向位置，单位为vp。 |
| y    | number | 是   | 是   | 垂直方向位置，单位为vp。 |

## Frame

用于设置或返回组件的布局大小和位置，单位为vp。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 可读 | 可写 | 说明                     |
| ------ | ------ | ---- | ---- | ------------------------ |
| x      | number | 是   | 是   | 水平方向位置，单位为vp。 |
| y      | number | 是   | 是   | 垂直方向位置，单位为vp。 |
| width  | number | 是   | 是   | 组件的宽度，单位为vp。   |
| height | number | 是   | 是   | 组件的高度，单位为vp。   |

## Pivot

用于设置组件的轴心坐标，轴心会作为组件的旋转/缩放中心点，影响旋转和缩放效果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                                                         |
| ---- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x    | number | 是   | 是   | 轴心的X轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |
| y    | number | 是   | 是   | 轴心的Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |

## Scale

用于设置组件的缩放比例。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                                         |
| ---- | ------ | ---- | ---- | -------------------------------------------- |
| x    | number | 是   | 是   | X轴的缩放参数。该参数为浮点数，默认值为1.0。 |
| y    | number | 是   | 是   | Y轴的缩放参数。该参数为浮点数，默认值为1.0。 |

## Translation

用于设置组件的平移量。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                         |
| ---- | ------ | ---- | ---- | ---------------------------- |
| x    | number | 是   | 是   | 水平方向的平移量，单位为vp。 |
| y    | number | 是   | 是   | 垂直方向的平移量，单位为vp。 |

## Rotation

用于设置组件的旋转角度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                           |
| ---- | ------ | ---- | ---- | ------------------------------ |
| x    | number | 是   | 是   | x 轴方向的旋转角度，单位为vp。 |
| y    | number | 是   | 是   | y 轴方向的旋转角度，单位为vp。 |
| z    | number | 是   | 是   | z 轴方向的旋转角度，单位为vp。 |

## Offset

用于设置组件或效果的偏移。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 可读 | 可写 | 说明                         |
| ---- | ------ | ---- | ---- | ---------------------------- |
| x    | number | 是   | 是   | x 轴方向的偏移量，单位为vp。 |
| y    | number | 是   | 是   | y 轴方向的偏移量，单位为vp。 |

## Matrix4

用于设置组件的变换信息，该类型为一个 4x4 矩阵，使用一个长度为16的`number[]`进行表示，例如：
```ts
const transform: Matrix4 = [
  1, 0, 45, 0,
  0, 1,  0, 0,
  0, 0,  1, 0,
  0, 0,  0, 1
]
```

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## DrawContext

图形绘制上下文，提供绘制所需的画布宽度和高度。

### size

get size(): Size

获取画布的宽度和高度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型          | 说明             |
| ------------- | ---------------- |
| [Size](#size) | 画布的宽度和高度 |