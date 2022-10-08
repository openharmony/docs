# Matrix Transformation


> **NOTE**
>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import matrix4 from '@ohos.matrix4'
```


## Required Permissions

None


## matrix4.init

init(array: Array&lt;number&gt;): Object


Implements a 4x4 matrix by using the input parameter. The column-major order is used.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | array | Array&lt;number&gt; | Yes | [1, 0, 0, 0,<br/>0, 1, 0, 0,<br/>0, 0, 1, 0,<br/>0, 0, 0, 1] | A number array whose length is 16 (4 x 4). For details, see the parameter description. |

- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | 4x4 matrix object created based on the input parameter. |

- Parameter description
  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | m00 | number | Yes | Scaling value along the x-axis. Defaults to **1** for the identity matrix. |
  | m01 | number | Yes | The second value, which is affected by the rotation along the x, y, and z axes. |
  | m02 | number | Yes | The third value, which is affected by the rotation along the x, y, and z axes. |
  | m03 | number | Yes | Meaningless. |
  | m10 | number | Yes | The fifth value, which is affected by the rotation along the x, y, and z axes. |
  | m11 | number | Yes | Scaling value along the y-axis. Defaults to **1** for the identity matrix. |
  | m12 | number | Yes | The seventh value, which is affected by the rotation along the x, y, and z axes. |
  | m13 | number | Yes | Meaningless. |
  | m20 | number | Yes | The ninth value, which is affected by the rotation along the x, y, and z axes. |
  | m21 | number | Yes | The tenth value, which is affected by the rotation along the x, y, and z axes. |
  | m22 | number | Yes | Scaling value along the z-axis. Defaults to **1** for the identity matrix. |
  | m23 | number | Yes | Meaningless. |
  | m30 | number | Yes | Translation value along the x-axis, in px. Defaults to **0** for the identity matrix. |
  | m31 | number | Yes | Translation value along the y-axis, in px. Defaults to **0** for the identity matrix. |
  | m32 | number | Yes | Translation value along the z-axis, in px. Defaults to **0** for the identity matrix. |
  | m33 | number | Yes | Valid in homogeneous coordinates, presenting the perspective projection effect. |

- Example
  
  ```ts
  import matrix4 from '@ohos.matrix4'
  // Create a 4x4 matrix.
  let matrix = matrix4.init([1.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 1.0])
  ```


## matrix4.identity

identity(): Object


Performs matrix initialization. This API returns an identity matrix object.


- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | Identity matrix object. |

- Example
  
  ```ts
  // The effect of matrix 1 is the same as that of matrix 2.
  import matrix4 from '@ohos.matrix4'
  let matrix = matrix4.init([1.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0,
                            0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 1.0])
  let matrix2 = Matrix4.identity()
  ```


## matrix4.copy

copy(): Object


Copies this matrix object.


- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | Copy of the current matrix object. |

- Example
  
  ```ts
  import matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = matrix4.identity().translate({x:100})
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


Combines this matrix object with another to generate a new matrix object.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | matrix | Matrix4 | Yes | - | Matrix object to combine. |

- Return value
    | Type | Description |
  | -------- | -------- |
  | Object | Object after the combination. |

- Example
  
  ```ts
  import matrix4 from '@ohos.matrix4'
  @Entry
  @Component
  struct Test {
    private matrix1 = matrix4.identity().translate({x:200}).copy()
    private matrix2 = matrix4.identity().scale({x:2}).copy()
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


Inverts this matrix object.


- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | Inverse matrix object of the current matrix. |

- Example
  
  ```ts
  import matrix4 from '@ohos.matrix4'
  // The effect of matrix 1 (width scaled up by 2x) is opposite to that of matrix 2 (width scaled down by 2x).
  let matrix1 = matrix4.identity().scale({x:2})
  let matrix2 = matrix1.copy().invert()
  ```


### translate

translate({x?: number, y?: number, z?: number}): Object


Translates this matrix object along the x, y, and z axes.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 0 | Translation distance along the x-axis, in px. |
  | y | number | No | 0 | Translation distance along the y-axis, in px. |
  | z | number | No | 0 | Translation distance along the z-axis, in px. |


- Return value
    | Type | Description |
  | -------- | -------- |
  | Object | Matrix object after the translation effect is added. |

- Example
  
  ```ts
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

scale({x?: number, y?: number, z?: number, centerX?: number, centerY?: number}): Object


Scales this matrix object along the x, y, and z axes.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 1 | Scaling multiple along the x-axis. |
  | y | number | No | 1 | Scaling multiple along the y-axis. |
  | z | number | No | 1 | Scaling multiple along the z-axis. |
  | centerX | number | No | 0 | X coordinate of the center point. |
  | centerY | number | No | 0 | Y coordinate of the center point. |


- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | Matrix object after the scaling effect is added. |

- Example
  
  ```ts
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

  ![en-us_image_0000001256978367](figures/en-us_image_0000001256978367.png)


### rotate

rotate({x?: number, y?: number, z?: number, angle?: number, centerX?: Length, centerY?: Length}): Object


Rotates this matrix object along x, y, and z axes.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 1 | X coordinate of the rotation axis vector. |
  | y | number | No | 1 | Y coordinate of the rotation axis vector. |
  | z | number | No | 1 | Z coordinate of the rotation axis vector. |
  | angle | number | No | 0 | Rotation angle. |
  | centerX | number | No | 0 | X coordinate of the center point. |
  | centerY | number | No | 0 | Y coordinate of the center point. |


- Return value
  | Type | Description |
  | -------- | -------- |
  | Object | Matrix object after the rotation effect is added. |

- Example
  
  ```ts
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


Applies this transformation effect to a coordinate point.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | point | Point | Yes | - | Point to be transformed. |


- Return value
  | Type | Description |
  | -------- | -------- |
  | Point | Point object after matrix transformation |

- Example
  
  ```ts
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
