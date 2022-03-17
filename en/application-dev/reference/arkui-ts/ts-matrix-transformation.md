# Matrix Transformation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import matrix4 from '@ohos.matrix4'
```


## Required Permissions

None


## matrix4.init

init(array: Array&lt;number&gt;): Object


Matrix constructor, which is used to create a 4x4 matrix by using the input parameter. Column-major order is used.


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | array | Array&lt;number&gt; | Yes | [1,&nbsp;0,&nbsp;0,&nbsp;0,<br/>0,&nbsp;1,&nbsp;0,&nbsp;0,<br/>0,&nbsp;0,&nbsp;1,&nbsp;0,<br/>0,&nbsp;0,&nbsp;0,&nbsp;1] | A&nbsp;number&nbsp;array&nbsp;whose&nbsp;length&nbsp;is&nbsp;16&nbsp;(4&nbsp;x&nbsp;4).&nbsp;For&nbsp;details,&nbsp;see&nbsp;the&nbsp;parameter description. |

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | 4x4&nbsp;matrix&nbsp;object&nbsp;created&nbsp;based&nbsp;on&nbsp;the&nbsp;input&nbsp;parameter. | 

- Parameter description
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | m00 | number | Yes | Scaling&nbsp;value&nbsp;of&nbsp;the&nbsp;x-axis.&nbsp;Defaults&nbsp;to&nbsp;**1**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m01 | number | Yes | The&nbsp;second&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m02 | number | Yes | The&nbsp;third&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m03 | number | Yes | Meaningless. | 
  | m10 | number | Yes | The&nbsp;fifth&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m11 | number | Yes | Scaling&nbsp;value&nbsp;of&nbsp;the&nbsp;y-axis.&nbsp;Defaults&nbsp;to&nbsp;**1**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m12 | number | Yes | The&nbsp;seventh&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m13 | number | Yes | Meaningless. | 
  | m20 | number | Yes | The&nbsp;ninth&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m21 | number | Yes | The&nbsp;tenth&nbsp;value,&nbsp;which&nbsp;is&nbsp;affected&nbsp;by&nbsp;the&nbsp;rotation&nbsp;of&nbsp;the&nbsp;x,&nbsp;y,&nbsp;and&nbsp;z&nbsp;axes. | 
  | m22 | number | Yes | Scaling&nbsp;value&nbsp;of&nbsp;the&nbsp;z-axis.&nbsp;Defaults&nbsp;to&nbsp;**1**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m23 | number | Yes | Meaningless. | 
  | m30 | number | Yes | Translation&nbsp;value&nbsp;of&nbsp;the&nbsp;x-axis,&nbsp;in&nbsp;px.&nbsp;Defaults&nbsp;to&nbsp;**0**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m31 | number | Yes | Translation&nbsp;value&nbsp;of&nbsp;the&nbsp;y-axis,&nbsp;in&nbsp;px.&nbsp;Defaults&nbsp;to&nbsp;**0**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m32 | number | Yes | Translation&nbsp;value&nbsp;of&nbsp;the&nbsp;z-axis,&nbsp;in&nbsp;px.&nbsp;Defaults&nbsp;to&nbsp;**0**&nbsp;for&nbsp;the&nbsp;unit&nbsp;matrix. | 
  | m33 | number | Yes | Valid&nbsp;in&nbsp;homogeneous&nbsp;coordinates,&nbsp;presenting&nbsp;the&nbsp;perspective&nbsp;projection&nbsp;effect. | 

- Example
  
  ```
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


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Unit&nbsp;matrix&nbsp;object. | 

- Example
  
  ```
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


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Copy&nbsp;object&nbsp;of&nbsp;the&nbsp;current&nbsp;matrix. | 

- Example
  
  ```
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


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | matrix | Matrix4 | Yes | - | Matrix&nbsp;object&nbsp;to&nbsp;be&nbsp;overlaid. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Object&nbsp;after&nbsp;matrix&nbsp;overlay. | 

- Example
  
  ```
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


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Inverse&nbsp;matrix&nbsp;object&nbsp;of&nbsp;the&nbsp;current&nbsp;matrix. | 

- Example
  
  ```
  import Matrix4 from '@ohos.matrix4'
  // The effect of matrix 1 (width scaled up by 2x) is opposite to that of matrix 2 (width scaled down by 2x).
  let matrix1 = Matrix4.identity().scale({x:2})
  let matrix2 = matrix1.invert()
  ```


### translate

translate({x?: number, y?: number, z?: number}): Object


Matrix translation function, which is used to add the translation effect to the x, y, and z axes of the current matrix.


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 0 | Translation&nbsp;distance&nbsp;of&nbsp;the&nbsp;x-axis,&nbsp;in&nbsp;px. | 
  | y | number | No | 0 | Translation&nbsp;distance&nbsp;of&nbsp;the&nbsp;y-axis,&nbsp;in&nbsp;px. | 
  | z | number | No | 0 | Translation&nbsp;distance&nbsp;of&nbsp;the&nbsp;z-axis,&nbsp;in&nbsp;px. | 


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Matrix&nbsp;object&nbsp;after&nbsp;the&nbsp;translation&nbsp;effect&nbsp;is&nbsp;added. | 

- Example
  
  ```
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


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 1 | Scaling&nbsp;multiple&nbsp;of&nbsp;the&nbsp;x-axis. | 
  | y | number | No | 1 | Scaling&nbsp;multiple&nbsp;of&nbsp;the&nbsp;y-axis. | 
  | z | number | No | 1 | Scaling&nbsp;multiple&nbsp;of&nbsp;the&nbsp;z-axis. | 
  | centerX | number | No | 0 | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point. | 
  | centerY | number | No | 0 | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point. | 


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Matrix&nbsp;object&nbsp;after&nbsp;the&nbsp;scaling&nbsp;effect&nbsp;is&nbsp;added. | 

- Example
  
  ```
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


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | No | 1 | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;rotation&nbsp;axis&nbsp;vector. | 
  | y | number | No | 1 | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;rotation&nbsp;axis&nbsp;vector. | 
  | z | number | No | 1 | Z&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;rotation&nbsp;axis&nbsp;vector. | 
  | angle | number | No | 0 | Rotation&nbsp;angle. | 
  | centerX | number | No | 0 | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point. | 
  | centerY | number | No | 0 | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point. | 


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Object | Matrix&nbsp;object&nbsp;after&nbsp;the&nbsp;rotation&nbsp;effect&nbsp;is&nbsp;added. | 

- Example
  
  ```
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


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | point | Point | Yes | - | Point&nbsp;to&nbsp;be&nbsp;transformed. | 


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Point | Point&nbsp;object&nbsp;after&nbsp;matrix&nbsp;transformation | 

- Example
  
  ```
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
