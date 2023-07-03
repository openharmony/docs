# Matrix2D

**Matrix2D** allows you to perform matrix transformation, such as scaling, rotating, and translating.

>  **NOTE**
> 
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

Matrix2D()

Since API version 9, this API is supported in ArkTS widgets.

## Attributes

| Name                     | Type  | Description                                                        |
| ------------------------- | ------ | ------------------------------------------------------------ |
| [scaleX](#scalex)         | number | Horizontal scale factor. Since API version 9, this API is supported in ArkTS widgets.|
| [scaleY](#scaley)         | number | Vertical scale factor. Since API version 9, this API is supported in ArkTS widgets.|
| [rotateX](#rotatex)       | number | Horizontal tilt coefficient. Since API version 9, this API is supported in ArkTS widgets.|
| [rotateY](#rotatey)       | number | Vertical tilt coefficient. Since API version 9, this API is supported in ArkTS widgets.|
| [translateX](#translatex) | number | Horizontal translation distance, in vp. Since API version 9, this API is supported in ArkTS widgets.|
| [translateY](#translatey) | number | Vertical translation distance, in vp. Since API version 9, this API is supported in ArkTS widgets.|

>  **NOTE**
>  
>  You can use the [px2vp](ts-pixel-units.md) API to convert the unit.

### scaleX

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DScaleX {
  @State message: string = 'Matrix2D ScaleX'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

Since API version 9, this API is supported in ArkTS widgets.

**Return value**

| Type                 | Description      |
| --------------------- | ---------- |
| [Matrix2D](#matrix2d) | Identity matrix.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DIdentity {
  @State message: string = 'Matrix2D Identity'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

Since API version 9, this API is supported in ArkTS widgets.

**Return value**

| Type                 | Description        |
| --------------------- | ------------ |
| [Matrix2D](#matrix2d) | Inverse of the current matrix.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DInvert {
  @State message: string = 'Matrix2D Invert'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

Since API version 9, this API is supported in ArkTS widgets. This API is a null API.

This API is deprecated since API version 10.

**Parameters**

| Parameter | Type    | Mandatory| Default Value| Description      |
| ----- | -------- | ---- | ------ | ---------- |
| other | Matrix2D | No  | null   | Target matrix.|

**Return value**

| Type                 | Description          |
| --------------------- | -------------- |
| [Matrix2D](#matrix2d) | Matrix of the multiplication result.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DMultiply {
  @State message: string = 'Matrix2D Multiply'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
            matrix.scaleX = 1
            matrix.scaleY = 1
            matrix.rotateX = 0
            matrix.rotateY = 0
            matrix.translateX = 0
            matrix.translateY = 0
            var other: Matrix2D = new Matrix2D()
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

### rotate<sup>10+</sup>

rotate(degree: number, rx?: number, ry?: number): Matrix2D

Performs a right multiplication rotation operation on this matrix, with the specified rotation point as the transform origin.

Since API version 10, this API is supported in ArkTS widgets.

**Parameters**

| Parameter  | Type  | Mandatory| Default Value| Description                                                        |
| ------ | ------ | ---- | ------ | ------------------------------------------------------------ |
| degree | number | Yes  | 0      | Rotation angle, in radians. A positive angle denotes a clockwise rotation. You can use **Math.PI& / 180** to convert the angle to a radian value.|
| rx     | number | No  | 0      | Horizontal coordinate (in vp) of the rotation point.                            |
| ry     | number | No  | 0      | Vertical coordinate (in vp) of the rotation point.                            |

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | Matrix of the rotation result.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DRotate {
  @State message: string = 'Matrix2D Rotate'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Parameter| Type  | Mandatory| Default Value| Description                        |
| ---- | ------ | ---- | ------ | ---------------------------- |
| tx   | number | No  | 0      | Horizontal translation distance, in vp.|
| ty   | number | No  | 0      | Vertical translation distance, in vp.|

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [Matrix2D](#matrix2d) | Matrix of the translation result.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DTranslate {
  @State message: string = 'Matrix2D Translate'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Parameter| Type  | Mandatory| Default Value| Description              |
| ---- | ------ | ---- | ------ | ------------------ |
| sx   | number | No  | 1      | Horizontal scale factor.|
| sy   | number | No  | 1      | Vertical scale factor.|

**Return value**

| Type                 | Description              |
| --------------------- | ------------------ |
| [Matrix2D](#matrix2d) | Matrix of the scale result.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Matrix2DScale {
  @State message: string = 'Matrix2D Scale'

  printMatrix(title, matrix) {
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
            var matrix : Matrix2D = new Matrix2D()
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
