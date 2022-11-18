# Matrix Transformation

Matrix transformation enables you to rotate, scale, skew, or translate an image.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import matrix4 from '@ohos.matrix4'
```


## matrix4.init

init(array: Array&lt;number&gt;): Matrix4Transit


Matrix constructor, which is used to create a 4x4 matrix by using the input parameter. Column-major order is used.

**Parameters**

| Name  | Type                | Mandatory | Description                              |
| ----- | ------------------- | --------- | ---------------------------------------- |
| array | Array&lt;number&gt; | Yes       | A number array whose length is 16 (4 x 4). For details, see **array**.<br>Default value:<br>[1, 0, 0, 0,<br>0, 1, 0, 0,<br>0, 0, 1, 0,<br>0, 0, 0, 1] |

**Return value**

| Type           | Description                              |
| -------------- | ---------------------------------------- |
| Matrix4Transit | 4x4 matrix object created based on the input parameter. |

**array**

| Name | Type   | Mandatory | Description                              |
| ---- | ------ | --------- | ---------------------------------------- |
| m00  | number | Yes       | Scaling value of the x-axis. Defaults to **1** for the identity matrix. |
| m01  | number | Yes       | The second value, which is affected by the rotation of the x, y, and z axes. |
| m02  | number | Yes       | The third value, which is affected by the rotation of the x, y, and z axes. |
| m03  | number | Yes       | Meaningless.                             |
| m10  | number | Yes       | The fifth value, which is affected by the rotation of the x, y, and z axes. |
| m11  | number | Yes       | Scaling value of the y-axis. Defaults to **1** for the identity matrix. |
| m12  | number | Yes       | The seventh value, which is affected by the rotation of the x, y, and z axes. |
| m13  | number | Yes       | Meaningless.                             |
| m20  | number | Yes       | The ninth value, which is affected by the rotation of the x, y, and z axes. |
| m21  | number | Yes       | The tenth value, which is affected by the rotation of the x, y, and z axes. |
| m22  | number | Yes       | Scaling value of the z-axis. Defaults to **1** for the identity matrix. |
| m23  | number | Yes       | Meaningless.                             |
| m30  | number | Yes       | Translation value of the x-axis, in px. Defaults to **0** for the identity matrix. |
| m31  | number | Yes       | Translation value of the y-axis, in px. Defaults to **0** for the identity matrix. |
| m32  | number | Yes       | Translation value of the z-axis, in px. Defaults to **0** for the identity matrix. |
| m33  | number | Yes       | Valid in homogeneous coordinates, presenting the perspective projection effect. |

**Example**

```ts
import matrix4 from '@ohos.matrix4'
// Create a 4x4 matrix.
let matrix = matrix4.init([1.0, 0.0, 0.0, 0.0,
                          0.0, 1.0, 0.0, 0.0,
                          0.0, 0.0, 1.0, 0.0,
                          0.0, 0.0, 0.0, 1.0])
@Entry
@Component
struct Tests {
  build() {
    Column() {
      Image($r("app.media.zh"))
        .width("40%")
        .height(100)
        .transform(matrix)
    }
  }
}
```


## matrix4.identity

identity(): Matrix4Transit


Matrix initialization function. Can return an identity matrix object.

**Return value**

| Type           | Description             |
| -------------- | ----------------------- |
| Matrix4Transit | Identity matrix object. |

**Example**

```ts
// The effect of matrix 1 is the same as that of matrix 2.
import matrix4 from '@ohos.matrix4'
let matrix1 = matrix4.init([1.0, 0.0, 0.0, 0.0,
                          0.0, 1.0, 0.0, 0.0,
                          0.0, 0.0, 1.0, 0.0,
                          0.0, 0.0, 0.0, 1.0])
let matrix2 = matrix4.identity()
@Entry
@Component
struct Tests {
  build() {
    Column() {
      Image($r("app.media.zh"))
        .width("40%")
        .height(100)
        .transform(matrix1)
      Image($r("app.media.zh"))
        .width("40%")
        .height(100)
        .margin({ top: 150 })
        .transform(matrix2)
    }
  }
}
```


## matrix4.copy

copy(): Matrix4Transit


Matrix copy function, which is used to copy the current matrix object.

**Return value**

| Type           | Description                        |
| -------------- | ---------------------------------- |
| Matrix4Transit | Copy object of the current matrix. |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
@Entry
@Component
struct Test {
  private matrix1 = Matrix4.identity().translate({x:100})
  private matrix2 = this.matrix1.copy().scale({x:2})

  build() {
    Column() {
      Image($r("app.media.bg1"))
        .width("40%")
        .height(100)
        .transform(this.matrix1)
      Image($r("app.media.bg2"))
        .width("40%")
        .height(100)
        .margin({top:50})
        .transform(this.matrix2)
    }
  }
}
```

![en-us_image_0000001256858419](figures/en-us_image_0000001256858419.png)


## Matrix4


### combine

combine(matrix: Matrix4): Matrix4Transit


Matrix overlay function, which is used to overlay the effects of two matrices to generate a new matrix object.

**Parameters**

| Name   | Type    | Mandatory | Description                   |
| ------ | ------- | --------- | ----------------------------- |
| matrix | Matrix4 | Yes       | Matrix object to be overlaid. |

**Return value**

| Type           | Description                  |
| -------------- | ---------------------------- |
| Matrix4Transit | Object after matrix overlay. |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().translate({x:200}).copy()
  private matrix2 = matrix4.identity().scale({x:2}).copy()

  build() {
    Column() {
      // Before matrix transformation
      Image($r("app.media.icon"))
        .width("40%")
        .height(100)
        .margin({top:50})
      // Translate the x-axis by 200px, and then scale down the x-axis twice.
      Image($r("app.media.icon"))
        .transform(this.matrix1.combine(this.matrix2))
        .width("40%")
      .height(100)
        .margin({top:50})
    }
  }
}
```

![en-us_image_0000001212378428](figures/en-us_image_0000001212378428.png)


### invert

invert(): Matrix4Transit


Matrix inverse function. Can return an inverse matrix of the current matrix object, that is, get an opposite effect.

**Return value**

| Type           | Description                              |
| -------------- | ---------------------------------------- |
| Matrix4Transit | Inverse matrix object of the current matrix. |

**Example**

```ts
import matrix4 from '@ohos.matrix4'
// The effect of matrix 1 (width scaled up by 2x) is opposite to that of matrix 2 (width scaled down by 2x).
let matrix1 = matrix4.identity().scale({x:2})
let matrix2 = matrix1.invert()
@Entry
@Component
struct Tests {
  build() {
    Column() {
      Image($r("app.media.zh"))
        .width(200)
        .height(100)
        .transform(matrix1)
        .margin({ top: 100 })
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

translate({x?: number, y?: number, z?: number}): Matrix4Transit


Matrix translation function, which is used to add the translation effect to the x, y, and z axes of the current matrix.

**Parameter**

| Name | Type   | Mandatory | Description                              |
| ---- | ------ | --------- | ---------------------------------------- |
| x    | number | No        | Translation distance of the x-axis, in px.<br>Default value: **0** |
| y    | number | No        | Translation distance of the y-axis, in px.<br>Default value: **0** |
| z    | number | No        | Translation distance of the z-axis, in px.<br>Default value: **0** |

**Return value**

| Type           | Description                              |
| -------------- | ---------------------------------------- |
| Matrix4Transit | Matrix object after the translation effect is added. |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().translate({x:100, y:200, z:30})

  build() {
    Column() {
      Image($r("app.media.bg1")).transform(this.matrix1)
        .width("40%")
        .height(100)
    }
  }
}
```

![en-us_image_0000001212058494](figures/en-us_image_0000001212058494.png)


### scale

scale({x?: number, y?: number, z?: number, centerX?: number, centerY?: number}): Matrix4Transit


Matrix scaling function, which is used to add the scaling effect to the x, y, and z axes of the current matrix.

**Parameters**

| Name    | Type   | Mandatory | Description                              |
| ------- | ------ | --------- | ---------------------------------------- |
| x       | number | No        | Scaling multiple of the x-axis.<br>Default value: **1** |
| y       | number | No        | Scaling multiple of the y-axis.<br>Default value: **1** |
| z       | number | No        | Scaling multiple of the z-axis.<br>Default value: **1** |
| centerX | number | No        | X coordinate of the center point.<br>Default value: **0** |
| centerY | number | No        | Y coordinate of the center point.<br>Default value: **0** |

**Return value**

| Type           | Description                              |
| -------------- | ---------------------------------------- |
| Matrix4Transit | Matrix object after the scaling effect is added. |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().scale({x:2, y:3, z:4, centerX:50, centerY:50})

  build() {
    Column() { 
      Image($r("app.media.bg1")).transform(this.matrix1)
        .width("40%")
        .height(100)
    }
  }
}
```

![en-us_image_0000001174422898.png](figures/en-us_image_0000001174422898.png)


### rotate

rotate({x?: number, y?: number, z?: number, angle?: number, centerX?: Length, centerY?: Length}): Matrix4Transit


Matrix rotation function, which is used to add the rotation effect to the x, y, and z axes of the current matrix.

**Parameters**

| Name    | Type   | Mandatory | Description                              |
| ------- | ------ | --------- | ---------------------------------------- |
| x       | number | No        | X coordinate of the rotation axis vector.<br>Default value: **1** |
| y       | number | No        | Y coordinate of the rotation axis vector.<br>Default value: **1** |
| z       | number | No        | Z coordinate of the rotation axis vector.<br>Default value: **1** |
| angle   | number | No        | Rotation angle.<br>Default value: **0**  |
| centerX | number | No        | X coordinate of the center point.<br>Default value: **0** |
| centerY | number | No        | Y coordinate of the center point.<br>Default value: **0** |

**Return value**

| Type           | Description                              |
| -------------- | ---------------------------------------- |
| Matrix4Transit | Matrix object after the rotation effect is added. |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().rotate({x:1, y:1, z:2, angle:30})

  build() {
    Column() {
      Image($r("app.media.bg1")).transform(this.matrix1)
        .width("40%")
        .height(100)
    }.width("100%").margin({top:50})
  }
}
```

![en-us_image_0000001211898504](figures/en-us_image_0000001211898504.png)


### transformPoint

transformPoint(point: Point): Point


Matrix point transformation function, which is used to apply the current transformation effect to a coordinate point.

**Parameters**

| Name  | Type  | Mandatory | Description              |
| ----- | ----- | --------- | ------------------------ |
| point | Point | Yes       | Point to be transformed. |

**Return value**

| Type  | Description                              |
| ----- | ---------------------------------------- |
| Point | Point object after matrix transformation |

**Example**

```ts
// xxx.ets
import matrix4 from '@ohos.matrix4'
import prompt from '@system.prompt'

@Entry
@Component
struct Test {
  private matrix1 = matrix4.identity().transformPoint([100, 10])
  
  build() {
    Column() {
     Button("get Point")
      .onClick(() => {
       prompt.showToast({message:JSON.stringify(this.matrix1),duration:2000})
      }).backgroundColor(0x2788D9)
    }.width("100%").padding(50)
  }
}
```

![en-us_image_0000001212218464](figures/en-us_image_0000001212218464.gif)
