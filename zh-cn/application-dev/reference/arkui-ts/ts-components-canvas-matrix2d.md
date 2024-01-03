# Matrix2D

矩阵对象，可以对矩阵进行缩放、旋转、平移等变换。

>  **说明：**
> 
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

Matrix2D()

从API version 9开始，该接口支持在ArkTS卡片中使用。

## 属性

| 属性                      | 类型   | 描述                                                         |
| ------------------------- | ------ | ------------------------------------------------------------ |
| [scaleX](#scalex)         | number | 水平缩放系数。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| [scaleY](#scaley)         | number | 垂直缩放系数。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| [rotateX](#rotatex)       | number | 水平倾斜系数。从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| [rotateY](#rotatey)       | number | 垂直倾斜系数。从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| [translateX](#translatex) | number | 水平平移距离，单位为vp。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| [translateY](#translatey) | number | 垂直平移距离，单位为vp。 从API version 9开始，该接口支持在ArkTS卡片中使用。 |

>  **说明：**
>  
>  可使用[px2vp](ts-pixel-units.md#像素单位转换)接口进行单位转换。

### scaleX

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DScaleX {
  @State message: string = 'Matrix2D ScaleX'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set scaleX")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### scaleY

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DScaleY {
  @State message: string = 'Matrix2D ScaleY'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set scaleY")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleY = 1
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### rotateX

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DRotateX {
  @State message: string = 'Matrix2D RotateX'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set rotateX")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.rotateX = Math.sin(45 / Math.PI)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### rotateY

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DRotateY {
  @State message: string = 'Matrix2D RotateY'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set rotateY")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.rotateY = Math.cos(45 / Math.PI)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### translateX

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DTranslateX {
  @State message: string = 'Matrix2D TranslateX'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set translateX")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.translateX = 10
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### translateY

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DTranslateY {
  @State message: string = 'Matrix2D TranslateY'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("Set translateY")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.translateY = 10
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 方法

### identity

identity(): Matrix2D

创建一个单位矩阵。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**返回值：**

| 类型                  | 说明       |
| --------------------- | ---------- |
| [Matrix2D](#matrix2d) | 单位矩阵。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DIdentity {
  @State message: string = 'Matrix2D Identity'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix identity")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix = matrix.identity()
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### invert

invert(): Matrix2D

得到当前矩阵的逆矩阵。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**返回值：**

| 类型                  | 说明         |
| --------------------- | ------------ |
| [Matrix2D](#matrix2d) | 逆矩阵结果。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DInvert {
  @State message: string = 'Matrix2D Invert'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix invert")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 2
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 10
            matrix.translateY = 20
            matrix.invert()
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### multiply<sup>(deprecated) </sup>

multiply(other?: Matrix2D): Matrix2D

当前矩阵与目标矩阵相乘。

从API version 9开始，该接口支持在ArkTS卡片中使用。该接口为空接口。

该接口从API version 10开始废弃。

**参数：**

| 参数  | 类型     | 必填 | 默认值 | 描述       |
| ----- | -------- | ---- | ------ | ---------- |
| other | Matrix2D | 否   | null   | 目标矩阵。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [Matrix2D](#matrix2d) | 相乘结果矩阵。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DMultiply {
  @State message: string = 'Matrix2D Multiply'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix multiply")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            let other: Matrix2D = new Matrix2D()
            other.scaleX = 2
            other.scaleY = 2
            other.rotateX = 0
            other.rotateY = 0
            other.translateX = 10
            other.translateY = 10
            other.multiply(other)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### rotate<sup>(deprecated) </sup>

rotate(rx?: number, ry?: number): Matrix2D

对当前矩阵进行旋转运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。该接口为空接口。

该接口从API version 10开始废弃，推荐使用[rotate](#rotate10)。

**参数：**

| 参数 | 类型   | 必填 | 默认值 | 描述                             |
| ---- | ------ | ---- | ------ | -------------------------------- |
| rx   | number | 否   | 0      | 旋转点的水平方向坐标，单位为vp。 |
| ry   | number | 否   | 0      | 旋转点的垂直方向坐标，单位为vp。 |

**返回值：**

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | 旋转后结果矩阵对象。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DRotate {
  @State message: string = 'Matrix2D Rotate'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix rotate")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            matrix.rotate(10, 10)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### rotate<sup>10+</sup>

rotate(degree: number, rx?: number, ry?: number): Matrix2D

以旋转点为中心、对当前矩阵进行右乘旋转运算。

从API version 10开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数   | 类型   | 必填 | 默认值 | 描述                                                         |
| ------ | ------ | ---- | ------ | ------------------------------------------------------------ |
| degree | number | 是   | 0      | 旋转角度，单位为弧度。顺时针方向为正角度，可以通过Math.PI&nbsp;/&nbsp;180将角度转换为弧度值。 |
| rx     | number | 否   | 0      | 旋转点的水平方向坐标，单位为vp。                             |
| ry     | number | 否   | 0      | 旋转点的垂直方向坐标，单位为vp。                             |

**返回值：**

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | 旋转后结果矩阵对象。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DRotate {
  @State message: string = 'Matrix2D Rotate'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix rotate")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            matrix.rotate(90 / Math.PI, 10, 10)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### translate

translate(tx?: number, ty?: number): Matrix2D

对当前矩阵进行左乘平移运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数 | 类型   | 必填 | 默认值 | 描述                         |
| ---- | ------ | ---- | ------ | ---------------------------- |
| tx   | number | 否   | 0      | 水平方向平移距离，单位为vp。 |
| ty   | number | 否   | 0      | 垂直方向平移距离，单位为vp。 |

**返回值：**

| 类型                  | 说明                 |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | 平移后结果矩阵对象。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DTranslate {
  @State message: string = 'Matrix2D Translate'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix translate")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            matrix.translate(100, 100)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### scale

scale(sx?: number, sy?: number): Matrix2D

对当前矩阵进行右乘缩放运算。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数 | 类型   | 必填 | 默认值 | 描述               |
| ---- | ------ | ---- | ------ | ------------------ |
| sx   | number | 否   | 1      | 水平缩放比例系数。 |
| sy   | number | 否   | 1      | 垂直缩放比例系数。 |

**返回值：**

| 类型                  | 说明               |
| --------------------- | ------------------ |
| [Matrix2D](#matrix2d) | 缩放结果矩阵对象。 |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DScale {
  @State message: string = 'Matrix2D Scale'

  printMatrix(title: string, matrix: Matrix2D) {
    console.log(title)
    console.log("Matrix [scaleX = " + matrix.scaleX + ", scaleY = " + matrix.scaleY +
                ", rotateX = " + matrix.rotateX + ", rotateY = " + matrix.rotateY +
                ", translateX = " + matrix.translateX + ", translateY = " + matrix.translateY + "]")
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button("matrix scale")
          .onClick(() => {
            let matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            matrix.scale(0.5, 0.5)
            this.printMatrix(this.message, matrix)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```