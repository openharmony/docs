# @ohos.matrix4 (矩阵变换)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

用于对组件进行[图形变换](arkui-ts/ts-universal-attributes-transformation.md)的各种操作，为组件提供矩阵变换能力，支持对图形进行平移、旋转和缩放等。

Matrix4的使用场景包括：

[图形变换](arkui-ts/ts-universal-attributes-transformation.md)中的[transform](arkui-ts/ts-universal-attributes-transformation.md#transform18)接口通过使用图形变换矩阵Matrix4对象设置组件的二维变换矩阵，[transform3D](arkui-ts/ts-universal-attributes-transformation.md#transform3d20)接口通过使用图形变换矩阵Matrix4对象设置组件的三维变换矩阵。


> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { matrix4 } from '@kit.ArkUI';
```


## matrix4.init

init(options: [number,number,number,number,number,number,number,number,number,number,number,number,number,number,number,number]): Matrix4Transit

Matrix的构造函数，可以通过传入的参数创建一个四阶矩阵，矩阵为列优先，即输入数组的16个值按列依次填充至矩阵：array[0]~array[3]为第1列，array[4]~array[7]为第2列，array[8]~array[11]为第3列，array[12]~array[15]为第4列。当仅需单位矩阵时，推荐使用matrix4.identity()。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| options | [number,number,number,number,<br>number,number,number,number,<br>number,number,number,number,<br>number,number,number,number] | 是   | 参数为长度为16（4\*4）的number数组，&nbsp;详情见四阶矩阵说明。<br>各number取值范围：(-∞, +∞)<br>默认值：<br>[1,&nbsp;0,&nbsp;0,&nbsp;0,<br>0,&nbsp;1,&nbsp;0,&nbsp;0,<br>0,&nbsp;0,&nbsp;1,&nbsp;0,<br>0,&nbsp;0,&nbsp;0,&nbsp;1] |

**返回值：**

| 类型                              | 说明                         |
| --------------------------------- | ---------------------------- |
| [Matrix4Transit](#matrix4transit) | 根据入参创建的四阶矩阵对象。 |

**四阶矩阵说明：**

| 参数名  | 类型     | 必填   | 说明                   |
| ---- | ------ | ---- | -------------------- |
| m00  | number | 是    | x轴缩放值，单位矩阵默认为1。      |
| m01  | number | 是    | 第2个矩阵元素，受xyz轴旋转或倾斜影响。   |
| m02  | number | 是    | 第3个矩阵元素，受xyz轴旋转影响。   |
| m03  | number | 是    | 第4个矩阵元素，受透视投影影响。               |
| m10  | number | 是    | 第5个矩阵元素，受xyz轴旋转或倾斜影响。   |
| m11  | number | 是    | y轴缩放值，单位矩阵默认为1。      |
| m12  | number | 是    | 第7个矩阵元素，受xyz轴旋转影响。   |
| m13  | number | 是    | 第8个矩阵元素，受透视投影影响。               |
| m20  | number | 是    | 第9个矩阵元素，受xyz轴旋转影响。   |
| m21  | number | 是    | 第10个矩阵元素，受xyz轴旋转影响。  |
| m22  | number | 是    | z轴缩放值，单位矩阵默认为1。      |
| m23  | number | 是    | 第12个矩阵元素，受透视投影影响。               |
| m30  | number | 是    | x轴平移值，单位：px，单位矩阵默认为0。 |
| m31  | number | 是    | y轴平移值，单位：px，单位矩阵默认为0。 |
| m32  | number | 是    | z轴平移值，单位：px，单位矩阵默认为0。 |
| m33  | number | 是    | 在齐次坐标下生效，产生透视投影效果。    |

**示例：**

```ts
import { matrix4 } from '@kit.ArkUI';

// 创建一个四阶矩阵
let matrix = matrix4.init(
  [1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0]);

@Entry
@Component
struct Tests {
  build() {
    Column() {
      // $r("app.media.zh")需要替换为开发者所需的图像资源文件。 
      Image($r("app.media.zh"))
        .width('40%')
        .height(100)
        .transform(matrix)
    }
  }
}
```


## matrix4.identity

identity(): Matrix4Transit

Matrix的初始化函数，可以返回一个初始的单位矩阵对象，可作为后续矩阵变换操作的基础。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明           |
| --------------------------------- | -------------- |
| [Matrix4Transit](#matrix4transit) | 单位矩阵对象。 |

**示例：**

```ts
// matrix1 和 matrix2 效果一致
import { matrix4 } from '@kit.ArkUI';

let matrix1 = matrix4.init(
  [1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0]);
let matrix2 = matrix4.identity();

@Entry
@Component
struct Tests {
  build() {
    Column() {
      // $r("app.media.zh")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.zh"))
        .width('40%')
        .height(100)
        .transform(matrix1)
      // $r("app.media.zh")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.zh"))
        .width("40%")
        .height(100)
        .margin({ top: 150 })
        .transform(matrix2)
    }
  }
}
```

## Matrix4Transit

矩阵对象。支持通过链式调用translate、scale、rotate、skew等方法组合多种变换效果。

> **说明：**
>
> 多个变换方法链式调用时，变换的顺序会影响最终结果。例如，先translate后scale与先scale后translate会产生不同的变换效果，需根据预期效果选择正确的调用顺序。
>
> translate、scale、rotate、skew、combine、invert方法会改变调用该函数的原始矩阵。如需保留原始矩阵不被修改，请先调用copy()再进行变换操作，例如：matrix.copy().translate({x:100})。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

### copy

copy(): Matrix4Transit

Matrix的拷贝函数，可以拷贝一份当前的矩阵对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [Matrix4Transit](#matrix4transit) | 当前矩阵的拷贝对象。 |


**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

let matrix1 = matrix4.identity().scale({ x: 1.5 });
let matrix2 = matrix1.copy().translate({ x: 200 });

@Entry
@Component
struct Test {
  imageSize: Length = '300px';

  build() {
    Column({ space: '50px' }) {
      // $r("app.media.testImage")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.testImage"))
        .width(this.imageSize)
        .height(this.imageSize)
      // $r("app.media.testImage")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.testImage"))
        .width(this.imageSize)
        .height(this.imageSize)
        .transform(matrix1)
      // $r("app.media.testImage")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.testImage"))
        .width(this.imageSize)
        .height(this.imageSize)
        .transform(matrix2)
    }.alignItems(HorizontalAlign.Center)
    .height('100%').width('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![matrix4-copy](figures/matrix4-copy.png)

### combine

combine(options: Matrix4Transit): Matrix4Transit

Matrix的叠加函数，可以为当前矩阵增加另一个矩阵的叠加效果，生成一个新的矩阵对象。会改变调用该函数的原始矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                              | 必填 | 说明               |
| ------ | --------------------------------- | ---- | ------------------ |
| options | [Matrix4Transit](#matrix4transit) | 是   | 待叠加的矩阵对象，其变换效果将与当前矩阵进行叠加（矩阵相乘），生成新的变换矩阵。 |

**返回值：**

| 类型                              | 说明               |
| --------------------------------- | ------------------ |
| [Matrix4Transit](#matrix4transit) | 矩阵叠加后的对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().translate({ x: 200 });
  private matrix2 = matrix4.identity().scale({ x: 2 });

  build() {
    Column() {
      // 矩阵变换前
      // $r("app.media.icon")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.icon"))
        .width('40%')
        .height(100)
        .margin({ top: 50 })
      // 先平移x轴200px，再缩放两倍x轴，得到矩阵变换后的效果图
      // $r("app.media.icon")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.icon"))
        .transform(this.matrix1.copy().combine(this.matrix2))
        .width("40%")
        .height(100)
        .margin({ top: 50 })
    }
  }
}
```

![zh-cn_image_0000001118642902](figures/Matrix4-combine.png)


### invert

invert(): Matrix4Transit

Matrix的逆函数，会改变调用该函数的原始矩阵，将其变换为逆矩阵并返回。逆矩阵与原始矩阵相乘结果为单位矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 当前矩阵的逆矩阵对象。 |

**示例：**

```ts
import { matrix4 } from '@kit.ArkUI';

// matrix1(宽放大2倍) 和 matrix2(宽缩小2倍) 效果相反
let matrix1 = matrix4.identity().scale({ x: 2 });
let matrix2 = matrix1.copy().invert();

@Entry
@Component
struct Tests {
  build() {
    Column() {
      // $r("app.media.zh")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.zh"))
        .width(200)
        .height(100)
        .transform(matrix1)
        .margin({ top: 100 })
      // $r("app.media.zh")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.zh"))
        .width(200)
        .height(100)
        .margin({ top: 150 })
        .transform(matrix2)
    }
  }
}
```


### translate

translate(options: TranslateOption): Matrix4Transit

Matrix的平移函数，可以为当前矩阵增加x轴/y轴/z轴平移效果。会改变调用该函数的原始矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| options | [TranslateOption](#translateoption) | 是   | 设置平移参数。 |

**返回值：**

| 类型                              | 说明                         |
| --------------------------------- | ---------------------------- |
| [Matrix4Transit](#matrix4transit) | 平移效果后的矩阵对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().translate({ x: 100, y: 200, z: 30 });

  build() {
    Column() {
      // $r("app.media.bg1")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.bg1")).transform(this.matrix1)
        .width('40%')
        .height(100)
    }
  }
}
```

![zh-cn_image_0000001219662645](figures/Matrix4-translate.png)


### scale

scale(options: ScaleOption): Matrix4Transit

Matrix的缩放函数，可以为当前矩阵增加x轴/y轴/z轴缩放效果。会改变调用该函数的原始矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                        | 必填 | 说明           |
| ------ | --------------------------- | ---- | -------------- |
| options | [ScaleOption](#scaleoption) | 是   | 设置缩放参数。 |

**返回值：**

| 类型                              | 说明                         |
| --------------------------------- | ---------------------------- |
| [Matrix4Transit](#matrix4transit) | 缩放效果后的矩阵对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity()
    .scale({
      x: 2,
      y: 3,
      z: 4,
      centerX: 50,
      centerY: 50
    });

  build() {
    Column() {
      // $r("app.media.testImage")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.testImage")).transform(this.matrix1)
        .width('300px')
        .height("300px")
    }.width("100%").height("100%").justifyContent(FlexAlign.Center)
  }
}
```

![zh-cn_image_0000001219864131](figures/Matrix4-scale.png)


### skew<sup>12+</sup>

skew(x: number, y: number): Matrix4Transit

Matrix的倾斜函数，可以为当前矩阵增加x轴/y轴倾斜效果。会改变调用该函数的原始矩阵。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                        | 必填 | 说明           |
| ------ | --------------------------- | ---- | -------------- |
| x | number | 是   | x轴倾斜参数，用于设置x轴方向的倾斜程度，值为剪切因子（即tan值）。<br>值为0时无倾斜，正值沿x轴正方向倾斜，负值沿x轴负方向倾斜。 |
| y | number | 是   | y轴倾斜参数，用于设置y轴方向的倾斜程度，值为剪切因子（即tan值）。<br>值为0时无倾斜，正值沿y轴正方向倾斜，负值沿y轴负方向倾斜。 |

**返回值：**

| 类型                              | 说明                         |
| --------------------------------- | ---------------------------- |
| [Matrix4Transit](#matrix4transit) | 倾斜效果后的矩阵对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().skew(2, 3);

  build() {
    Column() {
      // $r("app.media.bg1")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.bg1")).transform(this.matrix1)
        .height(100)
        .margin({
          top: 300
        })
    }
    .width('100%')
    .height("100%")
  }
}
```

![zh-cn_image_0000001219864132](figures/Matrix4-skew.jpeg)


### rotate

rotate(options: RotateOption): Matrix4Transit

Matrix的旋转函数，可以为当前矩阵增加x轴/y轴/z轴旋转效果。会改变调用该函数的原始矩阵。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| options | [RotateOption](#rotateoption) | 是   | 设置旋转参数。 |

**返回值：**

| 类型                              | 说明                         |
| --------------------------------- | ---------------------------- |
| [Matrix4Transit](#matrix4transit) | 旋转效果后的矩阵对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity()
    .rotate({
      x: 1,
      y: 1,
      z: 2,
      angle: 30
    });

  build() {
    Column() {
      // $r("app.media.bg1")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.bg1")).transform(this.matrix1)
        .width('40%')
        .height(100)
    }.width("100%").margin({ top: 50 })
  }
}
```

![zh-cn_image_0000001174422898](figures/Matrix4-rotate.png)


### transformPoint

transformPoint(options: [number, number]): [number, number]

Matrix的坐标点转换函数，可以将当前的变换效果作用到一个坐标点上。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型             | 必填 | 说明               |
| ------- | ---------------- | ---- | ------------------ |
| options | [number, number] | 是   | 需要转换的坐标点，格式为[x, y]，其中x为横坐标、y为纵坐标，单位为px。 |

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| [number, number] | 返回矩阵变换后的坐标点，格式为[x, y]。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Test {
  private originPoint: number[] = [50, 50];
  private matrix1 = matrix4.identity().translate({ x: 150, y: -50 });
  private transformPoint = this.matrix1.transformPoint([this.originPoint[0], this.originPoint[1]]);
  private matrix2 = matrix4.identity().translate({ x: this.transformPoint[0], y: this.transformPoint[1] });

  build() {
    Column() {
      Text(`矩阵变换前的坐标：[${this.originPoint}]`)
        .fontSize(16)
      // $r("app.media.image")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.image"))
        .width('600px')
        .height('300px')
        .margin({ top: 50 })
      Text(`矩阵变换后的坐标：[${this.transformPoint}]`)
        .fontSize(16)
        .margin({ top: 100 })
      // $r("app.media.image")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.image"))
        .width('600px')
        .height('300px')
        .margin({ top: 50 })
        .transform(this.matrix2)
    }.width('100%').padding(50)
  }
}
```

![zh-cn_image_0000001219864133](figures/Matrix4-Matrix4.PNG)

### setPolyToPoly<sup>12+</sup>

setPolyToPoly(options: PolyToPolyOptions): Matrix4Transit

将一个多边形的顶点坐标映射到另外一个多边形的顶点坐标。适用于需要进行自定义形变的场景，如图片透视校正、实现3D视觉效果、卡片翻转效果等。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型             | 必填 | 说明               |
| ------ | ---------------- | ---- | ------------------ |
| options | [PolyToPolyOptions](#polytopolyoptions12)  | 是   | 多边形映射参数，用于指定源多边形顶点坐标和目标多边形顶点坐标的映射关系。 |

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [Matrix4Transit](#matrix4transit) | 当前矩阵变换后的对象。 |

> **说明：**
>
> 需要配合组件的scale({centerX:0,centerY:0,x:1})接口使用，将变换中心点设置为组件左上角。默认情况下变换中心点为组件中心点，不配合使用时setPolyToPoly的映射效果将以组件中心点为基准，可能导致变换结果不符合预期。此处scale()应在组件上调用（如Image.scale()），与transform()配合使用，而非矩阵对象的变换方法。

**示例：**

```ts
import { matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private matrix1 = matrix4.identity().setPolyToPoly({
    src: [{ x: 0, y: 0 }, { x: 500, y: 0 }, { x: 0, y: 500 }, { x: 500, y: 500 }],
    dst: [{ x: 0, y: 0 }, { x: 500, y: 0 }, { x: 0, y: 500 }, { x: 750, y: 1000 }], pointCount: 4
  });

  build() {
    Stack() {
      Column().backgroundColor(Color.Blue)
        .width('500px')
        .height('500px')
      // $r("app.media.transition_image1")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.transition_image1'))
        .scale({ centerX: 0, centerY: 0, x: 1 })
        .transform(this.matrix1)
        .width('500px')
        .height('500px')
    }.width('100%').height('100%').opacity(0.5)
  }
}
```

![zh-cn_image_0000001174422898](figures/setPolyTopoly.png)

## TranslateOption

平移参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明                                                        |
| ---- | ------ | ---- | ---------- | ------------------------------------------------- |
| x    | number | 否 | 是   | x轴的平移距离。<br>单位：px<br>默认值：0<br>取值范围 (-∞, +∞) |
| y    | number | 否 | 是   | y轴的平移距离。<br>单位：px<br>默认值：0<br>取值范围 (-∞, +∞) |
| z    | number | 否 | 是   | z轴的平移距离。<br>单位：px<br>默认值：0<br>取值范围 (-∞, +∞) |

## ScaleOption

缩放参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型   | 只读 | 可选 | 说明                                                         |
| ------- | ------ | ---- | ---------- | -------------------------------------------------- |
| x       | number | 否 | 是  | x轴的缩放倍数。x=1时表示不缩放，保持原始大小；x>1时以x轴方向放大；0&lt;x&lt;1时以x轴方向缩小；x&lt;0时沿x轴反向并缩放。<br>默认值：1<br>取值范围 (-∞, +∞) |
| y       | number | 否 | 是  | y轴的缩放倍数。y>1时以y轴方向放大，0&lt;y&lt;1时以y轴方向缩小，y&lt;0时沿y轴反向并缩放。<br>默认值：1<br>取值范围 (-∞, +∞) |
| z       | number | 否 | 是  | z轴的缩放倍数。z=1时表示不缩放，保持原始大小；z>1时以z轴方向放大；0&lt;z&lt;1时以z轴方向缩小；z&lt;0时沿z轴反向并缩放。<br>默认值：1<br>取值范围 (-∞, +∞) |
| centerX | number | 否 | 是  | 变换中心点x轴坐标。<br>单位：px<br>默认值：组件中心点x轴坐标。<br>取值范围 (-∞, +∞)    |
| centerY | number | 否 | 是  | 变换中心点y轴坐标。<br>单位：px<br>默认值：组件中心点y轴坐标。<br>取值范围 (-∞, +∞)    |

## RotateOption

旋转参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型   | 只读 | 可选 | 说明                                                         |
| ------- | ------ | ---- | ---------- | -------------------------------------------------- |
| x       | number | 否 | 是   | 旋转轴向量x坐标，用于指定旋转轴在x方向的分量。当需要绕包含x分量的轴旋转时传入此参数，不传入时旋转轴x分量默认为0。<br>**说明：** 旋转向量中x、y、z至少有一个不为0才有意义。<br>默认值：0<br>取值范围：(-∞, +∞) |
| y       | number | 否 | 是  | 旋转轴向量y坐标，用于指定旋转轴在y方向的分量。当需要绕包含y分量的轴旋转时传入此参数，不传入时旋转轴y分量默认为0。<br>**说明：** 旋转向量中x、y、z至少有一个不为0才有意义。<br>默认值：0<br>取值范围：(-∞, +∞) |
| z       | number | 否 | 是  | 旋转轴向量z坐标，用于指定旋转轴在z方向的分量。当需要绕包含z分量的轴旋转时传入此参数，不传入时旋转轴z分量默认为0。<br>默认值：0<br>取值范围 (-∞, +∞)。<br>**说明：** 旋转向量中x、y、z至少有一个不为0，否则不产生旋转效果。 |
| angle   | number | 否 | 是  | 旋转角度，用于设置组件绕旋转轴的旋转量。当需要旋转组件时传入此参数，不传入时组件不做旋转。<br>单位为度（°）<br>默认值：0 |
| centerX | number | 否 | 是  | 单次矩阵变换操作的中心点相对于组件变换中心点（锚点）的额外x轴偏移值。<br>单位：px<br>默认值：0<br>**说明：** <br>为0时表示x方向的矩阵变换中心恰好为组件x方向锚点，取值表示相对组件x方向锚点的额外偏移量。具体实现可参考[示例3（按中心点旋转）](arkui-ts/ts-universal-attributes-transformation.md#示例3按中心点旋转)。 |
| centerY | number | 否 | 是  | 单次矩阵变换中心点相对于组件变换中心点（锚点）的额外y轴偏移值。<br>单位：px<br>默认值：0<br>**说明：** <br>为0时表示y方向的矩阵变换中心恰好为组件y方向锚点，取值表示相对组件y方向锚点的额外偏移量。具体实现可参考[示例3（按中心点旋转）](arkui-ts/ts-universal-attributes-transformation.md#示例3按中心点旋转)。 |

## PolyToPolyOptions<sup>12+</sup>

多边形到多边形的映射选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明                                                        |
| ---- | ------ | ---- | ---- | ----------------------------------------------------------- |
| src    |  Array<[Point](#point12)> | 否   | 否   | 源多边形顶点坐标，用于定义映射变换的起始形状。 |
| srcIndex    | number | 否   | 是   | 源点坐标起始索引，用于指定从src数组的哪个位置开始取点。当需要从src数组特定位置开始取源点时传入此参数，不传入时从索引0开始取点。<br>默认值：0<br>取值范围：[0, +∞) |
| dst    |  Array<[Point](#point12)>  | 否   | 否   | 目标多边形顶点坐标，用于定义映射变换的目标形状。 |
| dstIndex    | number | 否   | 是   |  目标点坐标起始索引，用于指定从dst数组中取目标点坐标的起始位置。<br>默认值: src.length/2 <br>取值范围：[0, +∞) |
| pointCount    | number | 否   | 是   | 使用到的点数量。前提条件：src和dst数组中的点数量需不少于pointCount。如果为0，则返回单位矩阵；如果为1，则使用1个源点和1个目标点，返回将源点平移到目标点的平移矩阵；如果为2，返回仿射变换矩阵（含旋转、缩放和平移）；如果为3，返回仿射变换矩阵（含旋转、缩放、平移和剪切）；如果为4，返回透视变换矩阵。超出范围时不生效。<br>默认值: 0 <br>取值范围：[0, +∞)|

## Point<sup>12+</sup>

坐标点的数据结构。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 只读 | 可选 | 说明                                                        |
| ---- | ------ | ---- | -------- | --------------------------------------------------- |
| x    |  number | 否 | 否   | x轴坐标。<br>单位：px<br>取值范围：(-∞, +∞) |
| y    | number | 否 | 否   | y轴坐标。<br>单位：px<br>取值范围：(-∞, +∞) |

## matrix4.copy<sup>(deprecated)</sup>

copy(): Matrix4Transit


Matrix的拷贝函数，可以拷贝一份当前的矩阵对象。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.copy](#copy)替代。


**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明                 |
| --------------------------------- | -------------------- |
| [Matrix4Transit](#matrix4transit) | 当前矩阵的拷贝对象。 |

**示例：**

```ts
// xxx.ets
import { matrix4 } from '@kit.ArkUI';

let matrix1 = matrix4.identity().translate({ x: 100 });
// 对matrix1的拷贝矩阵做scale操作，不影响到matrix1
let matrix2 = matrix1.copy().scale({ x: 2 });

@Entry
@Component
struct Test {

  build() {
    Column() {
      // $r("app.media.bg1")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.bg1"))
        .width('40%')
        .height(100)
        .transform(matrix1)
      // $r("app.media.bg2")需要替换为开发者所需的图像资源文件。
      Image($r("app.media.bg2"))
        .width("40%")
        .height(100)
        .margin({ top: 50 })
        .transform(matrix2)
    }
  }
}
```

![zh-cn_image_0000001219744181](figures/Matrix4-copy-01.png)

## matrix4.invert<sup>(deprecated)</sup>

invert(): Matrix4Transit

Matrix的逆函数，可以返回一个当前矩阵对象的逆矩阵，即效果正好相反。会改变调用该函数的原始矩阵。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.invert](#invert)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 当前矩阵的逆矩阵对象。 |

## matrix4.combine<sup>(deprecated)</sup>

combine(options: Matrix4Transit): Matrix4Transit

Matrix的叠加函数，可以将两个矩阵的效果叠加起来作用于当前矩阵。会改变调用该函数的原始矩阵。

> **说明：**
>
> matrixA.combine(matrixB)与matrixB.combine(matrixA)的变换结果不同。combine()的调用顺序决定了变换的叠加顺序，例如先平移后缩放与先缩放后平移的变换效果不同。使用时需根据预期的变换效果选择正确的调用顺序。如需保留原始矩阵不被修改，应先调用copy()再调用combine()，例如：matrixA.copy().combine(matrixB)。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.combine](#combine)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                              | 必填 | 说明               |
| ------- | --------------------------------- | ---- | ------------------ |
| options | [Matrix4Transit](#matrix4transit) | 是   | 待叠加的矩阵对象，其变换效果将与单位矩阵进行叠加。 |

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 叠加后的矩阵对象。 |

## matrix4.translate<sup>(deprecated)</sup>

translate(options: TranslateOption): Matrix4Transit

Matrix的平移函数，可以为当前矩阵增加x轴/y轴/z轴平移效果。会改变调用该函数的原始矩阵。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.translate](#translate)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                | 必填 | 说明           |
| ------- | ----------------------------------- | ---- | -------------- |
| options | [TranslateOption](#translateoption) | 是   | 平移配置参数，用于设置x轴、y轴、z轴的平移距离。 |

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 平移后的矩阵对象。 |

## matrix4.scale<sup>(deprecated)</sup>

scale(options: ScaleOption): Matrix4Transit

Matrix的缩放函数，可以为当前矩阵增加x轴/y轴/z轴缩放效果。会改变调用该函数的原始矩阵。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.scale](#scale)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                        | 必填 | 说明           |
| ------- | --------------------------- | ---- | -------------- |
| options | [ScaleOption](#scaleoption) | 是   | 缩放配置参数，用于设置x轴、y轴、z轴的缩放倍数及变换中心点坐标。 |

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 缩放后的矩阵对象。 |

## matrix4.rotate<sup>(deprecated)</sup>

rotate(options: RotateOption): Matrix4Transit

Matrix的旋转函数，可以为当前矩阵增加x轴/y轴/z轴旋转效果。会改变调用该函数的原始矩阵。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.rotate](#rotate)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                          | 必填 | 说明           |
| ------- | ----------------------------- | ---- | -------------- |
| options | [RotateOption](#rotateoption) | 是   | 旋转配置参数，用于设置旋转轴向量(x/y/z)、旋转角度及变换中心点偏移值。 |

**返回值：**

| 类型                              | 说明                   |
| --------------------------------- | ---------------------- |
| [Matrix4Transit](#matrix4transit) | 旋转后的矩阵对象。 |

## matrix4.transformPoint<sup>(deprecated)</sup>

transformPoint(options: [number, number]): [number, number]

Matrix的坐标点转换函数，可以将当前的变换效果作用到一个坐标点上。

> **说明：**
>
> 从API version 7开始支持，从API version 10开始废弃，建议使用[Matrix4Transit.transformPoint](#transformpoint)替代。

**系统能力：**  SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型             | 必填 | 说明               |
| ------- | ---------------- | ---- | ------------------ |
| options | [number, number] | 是   | 需要转换的坐标点。 |

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| [number, number] | 返回矩阵变换后的坐标点，格式为[x, y]。 |