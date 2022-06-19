# Matrix Transformation

> **NOTE**<br>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import matrix4 from '@ohos.matrix4'
```

## Required Permissions

None

## matrix4.init

init(array: Array&lt;number&gt;): Object

Matrix constructor, which is used to create a 4x4 matrix by using the input parameter. Column-major order is used.

1. Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | array | Array&lt;number&gt; | Yes | [1, 0, 0, 0,<br/>0, 1, 0, 0,<br/>0, 0, 1, 0,<br/>0, 0, 0, 1] | A number array whose length is 16 (4 x 4). For details, see the parameter description. |

2. Return value
  | Type   | Description                                             |
  | ------ | ------------------------------------------------------- |
  | Object | 4x4 matrix object created based on the input parameter. |

3. Parameter description
  | Name | Type   | Mandatory | Description                                                                     |
  | ---- | ------ | --------- | ------------------------------------------------------------------------------- |
  | m00  | number | Yes       | Scaling value of the x-axis. Defaults to **1** for the unit matrix.             |
  | m01  | number | Yes       | The second value, which is affected by the rotation of the x, y, and z axes.    |
  | m02  | number | Yes       | The third value, which is affected by the rotation of the x, y, and z axes.     |
  | m03  | number | Yes       | Meaningless.                                                                    |
  | m10  | number | Yes       | The fifth value, which is affected by the rotation of the x, y, and z axes.     |
  | m11  | number | Yes       | Scaling value of the y-axis. Defaults to **1** for the unit matrix.             |
  | m12  | number | Yes       | The seventh value, which is affected by the rotation of the x, y, and z axes.   |
  | m13  | number | Yes       | Meaningless.                                                                    |
  | m20  | number | Yes       | The ninth value, which is affected by the rotation of the x, y, and z axes.     |
  | m21  | number | Yes       | The tenth value, which is affected by the rotation of the x, y, and z axes.     |
  | m22  | number | Yes       | Scaling value of the z-axis. Defaults to **1** for the unit matrix.             |
  | m23  | number | Yes       | Meaningless.                                                                    |
  | m30  | number | Yes       | Translation value of the x-axis, in px. Defaults to **0** for the unit matrix.  |
  | m31  | number | Yes       | Translation value of the y-axis, in px. Defaults to **0** for the unit matrix.  |
  | m32  | number | Yes       | Translation value of the z-axis, in px. Defaults to **0** for the unit matrix.  |
  | m33  | number | Yes       | Valid in homogeneous coordinates, presenting the perspective projection effect. |

4. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  // Create a 4x4 matrix.
  let matrix = Matrix4.init([1.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 1.0])
  ```

## matrix4.identity

identity(): Object

Matrix initialization function. Can return a unit matrix object.

1. Return value
  | Type   | Description         |
  | ------ | ------------------- |
  | Object | Unit matrix object. |

2. Example
  
  ```ts
  // The effect of matrix 1 is the same as that of matrix 2.
  import Matrix4 from '@ohos.matrix4'
  let matrix = Matrix4.init([1.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 1.0])
  let matrix2 = Matrix4.identity()
  ```

## matrix4.copy

copy(): Object

Matrix copy function, which is used to copy the current matrix object.

1. Return value
  | Type   | Description                        |
  | ------ | ---------------------------------- |
  | Object | Copy object of the current matrix. |

2. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
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

combine(matrix: Matrix4): Object

Matrix overlay function, which is used to overlay the effects of two matrices to generate a new matrix object.

1. Parameters
  | Name   | Type    | Mandatory | Default Value | Description                   |
  | ------ | ------- | --------- | ------------- | ----------------------------- |
  | matrix | Matrix4 | Yes       | -             | Matrix object to be overlaid. |

2. Return value
  | Type   | Description                  |
  | ------ | ---------------------------- |
  | Object | Object after matrix overlay. |

- Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = Matrix4.identity().translate({x:200}).copy()
    private matrix2 = Matrix4.identity().scale({x:2}).copy()
    build() {
      Column() {
       // Translate the x-axis by 100 pixels and then scale it up or down by 2x.
        Image($r("app.media.bg1")).transform(this.matrix1.combine(this.matrix2)) 
          .width("40%")
          .height(100)
          .margin({top:50})
      }
    }
  }
  ```

  ![en-us_image_0000001212378428](figures/en-us_image_0000001212378428.png)

### invert

invert(): Object

Matrix inverse function. Can return an inverse matrix of the current matrix object, that is, get an opposite effect.

1. Return value
  | Type | Description |
  | ------ | -------- |
  | Object | Inverse matrix object of the current matrix. |

2. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  // The effect of matrix 1 (width scaled up by 2x) is opposite to that of matrix 2 (width scaled down by 2x).
  let matrix1 = Matrix4.identity().scale({x:2})
  let matrix2 = matrix1.invert()
  ```

### translate

translate({x?: number, y?: number, z?: number}): Object

Matrix translation function, which is used to add the translation effect to the x, y, and z axes of the current matrix.

1. Parameters
  | Name | Type   | Mandatory | Default Value | Description                                |
  |----- | ------ | -------- | -------------- | ------------------------------------------ |
  | x    | number | No       | 0              | Translation distance of the x-axis, in px. |
  | y    | number | No       | 0              | Translation distance of the y-axis, in px. |
  | z    | number | No       | 0              | Translation distance of the z-axis, in px. |


2. Return value
  | Type   | Description                                          |
  | ------ | ---------------------------------------------------- |
  | Object | Matrix object after the translation effect is added. |

3. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = Matrix4.identity().translate({x:100, y:200, z:30})
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

scale({x?: number, y?: number, z?: number, centerX?: number, centerY?: number}): Object

Matrix scaling function, which is used to add the scaling effect to the x, y, and z axes of the current matrix.

1. Parameters
  | Name    | Type   | Mandatory | Default Value | Description                       |
  | ------- | ------ | --------- | ------------- | --------------------------------- |
  | x       | number | No        | 1             | Scaling multiple of the x-axis.   |
  | y       | number | No        | 1             | Scaling multiple of the y-axis.   |
  | z       | number | No        | 1             | Scaling multiple of the z-axis.   |
  | centerX | number | No        | 0             | X coordinate of the center point. |
  | centerY | number | No        | 0             | Y coordinate of the center point. |


2. Return value
  | Type   | Description                                      |
  | ------ | ------------------------------------------------ |
  | Object | Matrix object after the scaling effect is added. |

3. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = Matrix4.identity().scale({x:2, y:3, z:4, centerX:50, centerY:50})
    build() {
      Column() { 
        Image($r("app.media.bg1")).transform(this.matrix1)
          .width("40%")
          .height(100)
      }
    }
  }
  ```

  ![en-us_image_0000001256978367](figures/en-us_image_0000001256978367.png)

### rotate

rotate({x?: number, y?: number, z?: number, angle?: number, centerX?: Length, centerY?: Length}): Object

Matrix rotation function, which is used to add the rotation effect to the x, y, and z axes of the current matrix.

1. Parameters
  | Name    | Type   | Mandatory | Default Value | Description                               |
  | ------- | ------ | --------- | ------------- | ----------------------------------------- |
  | x       | number | No        | 1             | X coordinate of the rotation axis vector. |
  | y       | number | No        | 1             | Y coordinate of the rotation axis vector. |
  | z       | number | No        | 1             | Z coordinate of the rotation axis vector. |
  | angle   | number | No        | 0             | Rotation angle.                           |
  | centerX | number | No        | 0             | X coordinate of the center point.         |
  | centerY | number | No        | 0             | Y coordinate of the center point.         |

2. Return value
  | Type   | Description                                       |
  | ------ | ------------------------------------------------- |
  | Object | Matrix object after the rotation effect is added. |

3. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = Matrix4.identity().rotate({x:1, y:1, z:2, angle:30})
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

1. Parameters
  | Name  | Type  | Mandatory | Default Value | Description              |
  | ----- | ----- | --------- | ------------- | ------------------------ |
  | point | Point | Yes       | -             | Point to be transformed. |

2. Return value
  | Type  | Description                               |
  | ----- | ----------------------------------------- |
  | Point | Point object after matrix transformation. |

3. Example
  
  ```ts
  import Matrix4 from '@ohos.matrix4'
  import prompt from '@system.prompt'
  
  @Entry
  @Component
  struct Test {
    private matrix1 = Matrix4.identity().transformPoint([100, 10])
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