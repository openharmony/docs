# matrix2d    
矩阵对象，可以对矩阵进行缩放、旋转、平移等变换。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## Matrix2D  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scaleX | number | false | false | 水平缩放系数。 |  
| rotateY | number | false | false | 垂直倾斜系数。 |  
| rotateX | number | false | false | 水平倾斜系数。 |  
| scaleY | number | false | false | 垂直缩放系数 |  
| translateX | number | false | false | 水平平移距离，单位为vp。 |  
| translateY | number | false | false | 垂直平移距离，单位为vp。 |  
    
### identity    
创建一个单位矩阵。  
 **调用形式：**     
- identity(): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 单位矩阵。 |  
    
 **示例代码：**   
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
得到当前矩阵的逆矩阵。  
 **调用形式：**     
- invert(): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 逆矩阵结果。 |  
    
 **示例代码：**   
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
  
    
### multiply    
当前矩阵与目标矩阵相乘。  
 **调用形式：**     
- multiply(other?: Matrix2D): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| other | Matrix2D | false | 目标矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 相乘结果矩阵。 |  
    
 **示例代码：**   
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
  
    
### rotate    
对当前矩阵进行旋转运算。  
 **调用形式：**     
- rotate(rx?: number, ry?: number): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rx | number | false | 旋转点的水平方向坐标，单位为vp。 |  
| ry | number | false | 旋转点的垂直方向坐标，单位为vp。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 旋转后结果矩阵对象。 |  
    
 **示例代码：**   
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
  
    
### translate    
对当前矩阵进行左乘平移运算。  
 **调用形式：**     
- translate(tx?: number, ty?: number): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tx | number | false | 水平方向平移距离，单位为vp。 |  
| ty | number | false | 垂直方向平移距离，单位为vp。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 平移后结果矩阵对象。 |  
    
 **示例代码：**   
```null    
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
对当前矩阵进行右乘缩放运算。  
 **调用形式：**     
- scale(sx?: number, sy?: number): Matrix2D  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sx | number | false | 水平缩放比例系数。 |  
| sy | number | false | 垂直缩放比例系数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix2D | 缩放结果矩阵对象。 |  
