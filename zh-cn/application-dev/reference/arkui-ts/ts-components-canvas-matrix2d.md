# Matrix2D对象

矩阵对象，可以对矩阵进行缩放、旋转、平移等变换。

>  **说明：**
> 
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

### identity

identity(): Matrix2D;

创建一个单位矩阵。

从API version 9开始，该接口支持在ArkTS卡片中使用。

### invert

invert(): Matrix2D;

得到当前矩阵的逆矩阵。

从API version 9开始，该接口支持在ArkTS卡片中使用。

### multiply

multiply(other?: Matrix2D): Matrix2D;

当前矩阵与目标矩阵相乘。

从API version 9开始，该接口支持在ArkTS卡片中使用。

该接口从API version 10开始废弃。

**参数：**

| 参数  | 类型     | 必填 | 默认值 | 描述       |
| ----- | -------- | ---- | ------ | ---------- |
| other | Matrix2D | 否   | null   | 目标矩阵。 |

### rotate<sup>10+</sup>

rotate(degree: number, rx?: number, ry?: number): Matrix2D;

以旋转点为中心、对当前矩阵进行右乘旋转运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数   | 类型   | 必填 | 默认值 | 描述                                                         |
| ------ | ------ | ---- | ------ | ------------------------------------------------------------ |
| degree | number | 是   | 0      | 旋转角度，单位为弧度。顺时针方向为正角度，可以通过Math.PI&nbsp;/&nbsp;180将角度转换为弧度值。 |
| rx     | number | 否   | 0      | 旋转点的水平方向坐标，单位为vp。                             |
| ry     | number | 否   | 0      | 旋转点的垂直方向坐标，单位为vp。                             |

### translate

translate(tx?: number, ty?: number): Matrix2D;

对当前矩阵进行左乘平移运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数 | 类型   | 必填 | 默认值 | 描述                         |
| ---- | ------ | ---- | ------ | ---------------------------- |
| tx   | number | 否   | 0      | 水平方向平移距离，单位为vp。 |
| ty   | number | 否   | 0      | 垂直方向平移距离，单位为vp。 |

### scale

scale(sx?: number, sy?: number): Matrix2D;

对当前矩阵进行右乘缩放运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数 | 类型   | 必填 | 默认值 | 描述               |
| ---- | ------ | ---- | ------ | ------------------ |
| sx   | number | 否   | 1      | 水平缩放比例系数。 |
| sy   | number | 否   | 1      | 垂直缩放比例系数。 |

## 属性

| 属性       | 类型   | 描述                                                         |
| ---------- | ------ | ------------------------------------------------------------ |
| scaleX     | number | 水平缩放系数。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| scaleY     | number | 垂直缩放系数。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| rotateX    | number | 水平倾斜系数。从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| rotateY    | number | 垂直倾斜系数。从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| translateX | number | 水平平移距离，单位为vp。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| translateY | number | 垂直平移距离，单位为vp。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |

>  **说明：**
>  
>  可使用[px2vp](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-pixel-units.md)接口进行单位转换。
