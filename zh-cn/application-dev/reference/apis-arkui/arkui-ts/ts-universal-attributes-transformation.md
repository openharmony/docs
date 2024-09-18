# 图形变换

用于对组件进行旋转、平移、缩放、矩阵变换等操作。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## rotate

rotate(value: RotateOptions)

设置组件旋转。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                    | 必填 | 说明                                                         |
| ------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [RotateOptions](#rotateoptions对象说明) | 是   | 可使组件在以组件左上角为坐标原点的坐标系中进行旋转（坐标系如下图所示）。其中，(x,&nbsp;y,&nbsp;z）指定一个矢量，作为旋转轴。<br/>旋转轴和旋转中心点都基于坐标系设定，组件发生位移时，坐标系不会随之移动。<br/>默认值:<br/>{<br/>x:&nbsp;0,<br/>y:&nbsp;0,<br/>z:&nbsp;0,<br/>centerX:&nbsp;'50%',<br/>centerY:&nbsp;'50%'<br/>centerZ:&nbsp;0,<br/>perspective:&nbsp;0<br/>}<br/>单位：vp<br/>![coordinates](figures/coordinates.png)<br/>centerZ、perspective从API version 10开始支持在ArkTS卡片中使用。 |

## translate

translate(value: TranslateOptions)

设置组件平移。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                                         |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [TranslateOptions](#translateoptions对象说明) | 是   | 可使组件在以组件左上角为坐标原点的坐标系中进行移动（坐标系如下图所示）。其中，x，y，z的值分别表示在对应轴移动的距离，值为正时表示向对应轴的正向移动，值为负时表示向对应轴的反向移动。移动距离支持数字和字符串（比如'10px'，‘10%’）两种类型。<br/>默认值:<br/>{<br/>x:&nbsp;0,<br/>y:&nbsp;0,<br/>z:&nbsp;0<br/>}<br/>单位：vp<br/>![coordinates](figures/coordinates.png)<br/>**说明：**<br/>z轴方向移动时由于观察点位置不变，z的值接近观察点组件会有放大效果，远离则缩小。<br/>![coordinateNode](figures/coordinateNote.png) |

## scale

scale(value: ScaleOptions)

设置组件缩放。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                  | 必填 | 说明                                                         |
| ------ | ------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ScaleOptions](#scaleoptions对象说明) | 是   | 可以分别设置X轴、Y轴、Z轴的缩放比例，默认值为1，同时可以通过centerX和centerY设置缩放的中心点。<br/>默认值:<br/>{<br/>x:&nbsp;1,<br/>y:&nbsp;1,<br/>z:&nbsp;1,<br/>centerX:'50%',<br/>centerY:'50%'<br/>} |

## transform

transform(value: object)

设置组件的变换矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                    | 必填 | 说明                     |
| ------ | --------------------------------------- | ---- | ------------------------ |
| value  | object | 是   | 设置当前组件的变换矩阵。object当前仅支持[Matrix4Transit](../js-apis-matrix4.md)矩阵对象类型。 |

## RotateOptions对象说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称                      | 类型                       | 必填 | 说明                                                         |
| ------------------------- | -------------------------- | ---- | ------------------------------------------------------------ |
| x                         | number                     | 否   | 旋转轴向量x坐标。                                            |
| y                         | number                     | 否   | 旋转轴向量y坐标。                                            |
| z                         | number                     | 否   | 旋转轴向量z坐标。                                            |
| angle                     | number&nbsp;\|&nbsp;string | 是   | 旋转角度。取值为正时相对于旋转轴方向顺时针转动，取值为负时相对于旋转轴方向逆时针转动。取值可为string类型，如'90deg'。 |
| centerX                   | number&nbsp;\|&nbsp;string | 否   | 变换中心点x轴坐标。                                          |
| centerY                   | number&nbsp;\|&nbsp;string | 否   | 变换中心点y轴坐标。                                          |
| centerZ<sup>10+</sup>     | number                     | 否   | z轴锚点，即3D旋转中心点的z轴分量。                           |
| perspective<sup>10+</sup> | number                     | 否   | 视距，即视点到z=0平面的距离。<br/>旋转轴和旋转中心点都基于坐标系设定，组件发生位移时，坐标系不会随之移动。 |

## TranslateOptions对象说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称 | 类型                       | 必填 | 说明            |
| ---- | -------------------------- | ---- | --------------- |
| x    | number&nbsp;\|&nbsp;string | 否   | x轴的平移距离。 |
| y    | number&nbsp;\|&nbsp;string | 否   | y轴的平移距离。 |
| z    | number&nbsp;\|&nbsp;string | 否   | z轴的平移距离。 |

## ScaleOptions对象说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称    | 类型                       | 必填 | 说明                                                         |
| ------- | -------------------------- | ---- | ------------------------------------------------------------ |
| x       | number                     | 否   | x轴的缩放倍数。x>1时以x轴方向放大，0<x<1时以x轴方向缩小，x<0时沿x轴反向并缩放。 |
| y       | number                     | 否   | y轴的缩放倍数。y>1时以y轴方向放大，0<y<1时以y轴方向缩小，y<0时沿y轴反向并缩放。 |
| z       | number                     | 否   | z轴的缩放倍数。z>1时以z轴方向放大，0<z<1时以z轴方向缩小，z<0时沿z轴反向并缩放。 |
| centerX | number&nbsp;\|&nbsp;string | 否   | 变换中心点x轴坐标。                                          |
| centerY | number&nbsp;\|&nbsp;string | 否   | 变换中心点y轴坐标。                                          |

> **说明：**
>
> 当组件同时设置了rotate和scale属性时，centerX和centerY的取值会发生冲突，此时centerX和centerY的值以最后设定的属性的值为准。

## 示例

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct TransformExample {
  build() {
    Column() {
      Text('rotate').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(14)
      Row()
        .rotate({
          x: 0,
          y: 0,
          z: 1,
          centerX: '50%',
          centerY: '50%',
          angle: 300
        }) // 组件以矢量(0,0,1)为旋转轴，绕中心点顺时针旋转300度
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('translate').width('90%').fontColor(0xCCCCCC).padding(10).fontSize(14)
      Row()
        .translate({ x: 100, y: 10 }) // x轴方向平移100，y轴方向平移10
        .width(100).height(100).backgroundColor(0xAFEEEE).margin({ bottom: 10 })

      Text('scale').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(14)
      Row()
        .scale({ x: 2, y: 0.5 }) // 高度缩小一倍，宽度放大一倍，z轴在2D下无效果
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('Matrix4').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(14)
      Row()
        .width(100).height(100).backgroundColor(0xAFEEEE)
        .transform(matrix4.identity().translate({ x: 50, y: 50 }).scale({ x: 1.5, y: 1 }).rotate({
          x: 0,
          y: 0,
          z: 1,
          angle: 60
        }))
    }.width('100%').margin({ top: 5 })
  }
}
```

![transform](figures/transform.PNG)