# Matrix2D

**Matrix2D** allows you to perform matrix transformation, such as scaling, rotating, and translating.

>  **NOTE**
> 
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

Matrix2D(unit?: LengthMetricsUnit)

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description                             |
| ------ | -------- | ---- | ------------------------------------- |
| unit<sup>12+</sup>  | [LengthMetricsUnit](../js-apis-arkui-graphics.md#lengthmetricsunit12) | No  | Unit mode of the **Matrix2D** object. The value cannot be dynamically changed once set. The configuration method is the same as that of [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md#lengthmetricsunit12).<br>Default value: **DEFAULT**|

## Attributes

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read Only | Optional  | Description |
| ----- | ----- | --------------- | ------ | ------------------------ |
| [scaleX](#scalex)         | number | No | Yes | Horizontal scale factor.          |
| [scaleY](#scaley)         | number | No | Yes | Vertical scale factor.          |
| [rotateX](#rotatex)       | number | No | Yes | Horizontal tilt coefficient.          |
| [rotateY](#rotatey)       | number | No | Yes | Vertical tilt coefficient.          |
| [translateX](#translatex) | number | No | Yes | Distance to translate on the x-axis.<br>Default unit: vp |
| [translateY](#translatey) | number | No | Yes | Distance to translate on the y-axis.<br>Default unit: vp |

>  **NOTE**
>  
>  You can use the [px2vp](ts-pixel-units.md#pixel-unit-conversion) API to convert the unit.

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

## Methods

### identity

identity(): Matrix2D

Creates an identity matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                 | Description      |
| --------------------- | ---------- |
| [Matrix2D](#matrix2d) | Identity matrix. |

**Example**

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

Obtains an inverse of this matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                 | Description        |
| --------------------- | ------------ |
| [Matrix2D](#matrix2d) | Inverse of the current matrix. |

**Example**

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

Multiplies this matrix by the target matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9. This API is an empty API.

This API is deprecated since API version 10.

**Parameters**

| Name | Type    | Mandatory |  Description  |
| ----- | -------- | ---- | ---------- |
| other | Matrix2D | No | Target matrix.<br>Default value: **null** |

**Return value**

| Type                 | Description          |
| --------------------- | -------------- |
| [Matrix2D](#matrix2d) | Matrix of the multiplication result. |

**Example**

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

Performs a rotation operation on this matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9. This API is an empty API.

This API is deprecated since API version 10. You are advised to use [rotate](#rotate10) instead.

**Parameters**

| Name | Type  | Mandatory | Description                         |
| ---- | ------ | ---- | -------------------------------- |
| rx   | number | No  | Horizontal coordinate of the rotation point.<br>Default unit: vp<br>Default value: **0** |
| ry   | number | No  | Vertical coordinate of the rotation point.<br>Default unit: vp<br>Default value: **0** |

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | Matrix of the rotation result. |

**Example**

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

Performs a right multiplication rotation operation on this matrix, with the specified rotation point as the transform origin.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory | Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| degree | number | Yes | Rotation angle, in radians. A positive angle denotes a clockwise rotation. You can use **Math.PI& / 180** to convert the angle to a radian value.<br>Default value: **0**|
| rx     | number | No | Horizontal coordinate of the rotation point.<br>Default unit: vp<br>Default value: **0**   |
| ry     | number | No | Vertical coordinate of the rotation point.<br>Default unit: vp<br>Default value: **0**   |

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | Matrix of the rotation result. |

**Example**

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

Performs a left multiplication translation operation on this matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                 |
| ---- | ------ | ---- | ---------------------------- |
| tx   | number | No  | Distance to translate on the x-axis.<br>Default unit: vp<br>Default value: **0** |
| ty   | number | No  | Distance to translate on the y-axis.<br>Default unit: vp<br>Default value: **0** |

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | Matrix of the translation result. |

**Example**

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

Performs a right multiplication scaling operation on this matrix.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description              |
| ---- | ------ | ---- | ------------------ |
| sx   | number | No  | Horizontal scale factor.<br>Default value: **1** |
| sy   | number | No  | Vertical scale factor.<br>Default value: **1** |

**Return value**

| Type                 | Description              |
| --------------------- | ------------------ |
| [Matrix2D](#matrix2d) | Matrix of the scale result. |

**Example**

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
