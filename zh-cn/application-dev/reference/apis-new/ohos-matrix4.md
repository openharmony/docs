# @ohos.matrix4    
本模块提供矩阵变换功能，可对图形进行平移、旋转和缩放等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import matrix4 from '@ohos.matrix4'    
```  
    
## TranslateOption  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | false | x轴的平移距离，单位px。<br/>默认值：0<br/>取值范围 (-∞, +∞) |  
| y | number | false | false | y轴的平移距离，单位px。<br/>默认值：0<br/>取值范围 (-∞, +∞) |  
| z | number | false | false | z轴的平移距离，单位px。<br/>默认值：0<br/>取值范围 (-∞, +∞) |  
    
## ScaleOption  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | false | x轴的缩放倍数。x>1时以x轴方向放大，0lt;xlt;1时以x轴方向缩小，x<0时沿x轴反向并缩放。<br/>默认值：1<br/>取值范围 (-∞, +∞) |  
| y | number | false | false | y轴的缩放倍数。y>1时以y轴方向放大，0lt;ylt;1时以y轴方向缩小，y<0时沿y轴反向并缩放。<br/>默认值：1<br/>取值范围 (-∞, +∞) |  
| z | number | false | false | z轴的缩放倍数。z>1时以z轴方向放大，0lt;zlt;1时以z轴方向缩小，z<0时沿z轴反向并缩放。<br/>默认值：1<br/>取值范围 (-∞, +∞) |  
| centerX | number | false | false | 变换中心点x轴坐标。<br/>默认值：0。<br/>取值范围 (-∞, +∞) |  
| centerY | number | false | false | 变换中心点y轴坐标。<br/>默认值：0。<br/>取值范围 (-∞, +∞) |  
    
## RotateOption  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | false | 旋转轴向量x坐标。<br/>默认值：0。<br/>取值范围 (-∞, +∞) |  
| y | number | false | false | 旋转轴向量y坐标。<br/>默认值：0。<br/>取值范围 (-∞, +∞) |  
| z | number | false | false | 旋转轴向量z坐标。<br/>默认值：0。<br/>取值范围 (-∞, +∞)。<br/>**说明：** 旋转向量中x、y、z至少有一个不为0才有意义。 |  
| centerX | number | false | false | 变换中心点x轴坐标。<br/>默认值：0 |  
| centerY | number | false | false | 变换中心点y轴坐标。<br/>默认值：0 |  
| angle | number | false | false | 旋转角度。<br/>默认值：0  |  
    
## Matrix4Transit  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### copy    
Matrix的拷贝函数，可以拷贝一份当前的矩阵对象。  
 **调用形式：**     
- copy(): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 当前矩阵的拷贝对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 100 })  
  // 对matrix1的拷贝矩阵做scale操作，不影响到matrix1  
  private matrix2 = this.matrix1.copy().scale({ x: 2 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1"))  
        .width("40%")  
        .height(100)  
        .transform(this.matrix1)  
      Image($r("app.media.bg2"))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
        .transform(this.matrix2)  
    }  
  }  
}  
    
```    
  
![zh-cn_image_0000001219744181](figures/zh-cn_image_0000001219744181.png)  
    
### invert    
Matrix的逆函数，可以返回一个当前矩阵对象的逆矩阵，即效果正好相反。  
 **调用形式：**     
- invert(): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 当前矩阵的逆矩阵对象。 |  
    
 **示例代码：**   
```ts    
import matrix4 from '@ohos.matrix4'  
// matrix1(宽放大2倍) 和 matrix2(宽缩小2倍) 效果相反  
let matrix1 = matrix4.identity().scale({ x: 2 })  
let matrix2 = matrix1.copy().invert()  
  
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
  
    
### combine    
Matrix的叠加函数，可以将两个矩阵的效果叠加起来生成一个新的矩阵对象。  
 **调用形式：**     
- combine(options: Matrix4Transit): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Matrix4Transit | true | 待叠加的矩阵对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 叠加后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 200 })  
  private matrix2 = matrix4.identity().scale({ x: 2 })  
  
  build() {  
    Column() {  
      // 矩阵变换前  
      Image($r("app.media.icon"))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
      // 先平移x轴200px，再缩放两倍x轴，得到矩阵变换后的效果图  
      Image($r("app.media.icon"))  
        .transform(this.matrix1.copy().combine(this.matrix2))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
    }  
  }  
}  
    
```    
  
<span style="letter-spacing: 0px;">![zh-cn_image_0000001118642902](figures/zh-cn_image_0000001118642902.png)</span>  
  
    
### translate    
Matrix的平移函数，可以为当前矩阵增加x轴/y轴/z轴平移效果。  
 **调用形式：**     
- translate(options: TranslateOption): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TranslateOption | true | 设置平移参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 平移后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 100, y: 200, z: 30 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }  
  }  
}  
    
```    
  
![zh-cn_image_0000001219662645](figures/zh-cn_image_0000001219662645.png)  
    
### scale    
Matrix的缩放函数，可以为当前矩阵增加x轴/y轴/z轴缩放效果。  
 **调用形式：**     
- scale(options: ScaleOption): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ScaleOption | true | 设置缩放参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 缩放后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().scale({ x:2, y:3, z:4, centerX:50, centerY:50 })  
  
  build() {  
    Column() {   
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }  
  }  
}  
    
```    
  
    
### rotate    
Matrix的旋转函数，可以为当前矩阵增加x轴/y轴/z轴旋转效果。  
 **调用形式：**     
- rotate(options: RotateOption): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RotateOption | true | 设置旋转参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 缩放后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().rotate({ x: 1, y: 1, z: 2, angle: 30 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }.width("100%").margin({ top: 50 })  
  }  
}  
    
```    
  
    
### transformPoint    
Matrix的坐标点转换函数，可以将当前的变换效果作用到一个坐标点上。  
 **调用形式：**     
- transformPoint(options: [number, number]): [number, number]  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | [number, number] | true | 需要转换的坐标点。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| [number, number] | 返回矩阵变换后的Point对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private originPoint: number[] = [50, 50]  
  private matrix_1 = matrix4.identity().translate({ x: 150, y: -50 })  
  private transformPoint = this.matrix_1.transformPoint([this.originPoint[0], this.originPoint[1]])  
  private matrix_2 = matrix4.identity().translate({ x: this.transformPoint[0], y: this.transformPoint[1] })  
  
  build() {  
    Column() {  
      Text(`矩阵变换前的坐标：[${this.originPoint}]`)  
        .fontSize(16)  
      Image($r("app.media.image"))  
        .width('600px')  
        .height('300px')  
        .margin({ top: 50 })  
      Text(`矩阵变换后的坐标：[${this.transformPoint}]`)  
        .fontSize(16)  
        .margin({ top: 100 })  
      Image($r("app.media.image"))  
        .width('600px')  
        .height('300px')  
        .margin({ top: 50 })  
        .transform(this.matrix_2)  
    }.width("100%").padding(50)  
  }  
}  
    
```    
  
    
## init  
 **调用形式：**     
- init(     options: [       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number     ]   ): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | [       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number,       number     ] | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit |  |  
    
## identity    
Matrix的初始化函数，可以返回一个单位矩阵对象。  
 **调用形式：**     
- identity(): Matrix4Transit  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 单位矩阵对象。 |  
    
 **示例代码：**   
```ts    
// matrix1 和 matrix2 效果一致  
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
  
    
## copy<sup>(deprecated)</sup>    
Matrix的拷贝函数，可以拷贝一份当前的矩阵对象。  
 **调用形式：**     
- copy(): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 当前矩阵的拷贝对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 100 })  
  // 对matrix1的拷贝矩阵做scale操作，不影响到matrix1  
  private matrix2 = this.matrix1.copy().scale({ x: 2 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1"))  
        .width("40%")  
        .height(100)  
        .transform(this.matrix1)  
      Image($r("app.media.bg2"))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
        .transform(this.matrix2)  
    }  
  }  
}  
    
```    
  
    
## invert<sup>(deprecated)</sup>    
Matrix的逆函数，可以返回一个当前矩阵对象的逆矩阵，即效果正好相反。  
 **调用形式：**     
- invert(): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 当前矩阵的逆矩阵对象。 |  
    
 **示例代码：**   
```ts    
import matrix4 from '@ohos.matrix4'  
// matrix1(宽放大2倍) 和 matrix2(宽缩小2倍) 效果相反  
let matrix1 = matrix4.identity().scale({ x: 2 })  
let matrix2 = matrix1.copy().invert()  
  
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
  
    
## combine<sup>(deprecated)</sup>    
Matrix的叠加函数，可以将两个矩阵的效果叠加起来生成一个新的矩阵对象。  
 **调用形式：**     
- combine(options: Matrix4Transit): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | Matrix4Transit | true | 待叠加的矩阵对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 叠加后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 200 })  
  private matrix2 = matrix4.identity().scale({ x: 2 })  
  
  build() {  
    Column() {  
      // 矩阵变换前  
      Image($r("app.media.icon"))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
      // 先平移x轴200px，再缩放两倍x轴，得到矩阵变换后的效果图  
      Image($r("app.media.icon"))  
        .transform(this.matrix1.copy().combine(this.matrix2))  
        .width("40%")  
        .height(100)  
        .margin({ top: 50 })  
    }  
  }  
}  
    
```    
  
    
## translate<sup>(deprecated)</sup>    
Matrix的平移函数，可以为当前矩阵增加x轴/y轴/z轴平移效果。  
 **调用形式：**     
- translate(options: TranslateOption): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | TranslateOption | true | 设置平移参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 平移后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().translate({ x: 100, y: 200, z: 30 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }  
  }  
}  
    
```    
  
    
## scale<sup>(deprecated)</sup>    
Matrix的缩放函数，可以为当前矩阵增加x轴/y轴/z轴缩放效果。  
 **调用形式：**     
- scale(options: ScaleOption): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ScaleOption | true | 设置缩放参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 缩放后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().scale({ x:2, y:3, z:4, centerX:50, centerY:50 })  
  
  build() {  
    Column() {   
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }  
  }  
}  
    
```    
  
    
## rotate<sup>(deprecated)</sup>    
Matrix的旋转函数，可以为当前矩阵增加x轴/y轴/z轴旋转效果。  
 **调用形式：**     
- rotate(options: RotateOption): Matrix4Transit  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | RotateOption | true | 设置旋转参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Matrix4Transit | 旋转后的矩阵对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private matrix1 = matrix4.identity().rotate({ x: 1, y: 1, z: 2, angle: 30 })  
  
  build() {  
    Column() {  
      Image($r("app.media.bg1")).transform(this.matrix1)  
        .width("40%")  
        .height(100)  
    }.width("100%").margin({ top: 50 })  
  }  
}  
    
```    
  
    
## transformPoint<sup>(deprecated)</sup>    
Matrix的坐标点转换函数，可以将当前的变换效果作用到一个坐标点上。  
 **调用形式：**     
- transformPoint(options: [number, number]): [number, number]  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | [number, number] | true | 需要转换的坐标点。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| [number, number] | 返回矩阵变换后的Point对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import matrix4 from '@ohos.matrix4'  
  
@Entry  
@Component  
struct Test {  
  private originPoint: number[] = [50, 50]  
  private matrix_1 = matrix4.identity().translate({ x: 150, y: -50 })  
  private transformPoint = this.matrix_1.transformPoint([this.originPoint[0], this.originPoint[1]])  
  private matrix_2 = matrix4.identity().translate({ x: this.transformPoint[0], y: this.transformPoint[1] })  
  
  build() {  
    Column() {  
      Text(`矩阵变换前的坐标：[${this.originPoint}]`)  
        .fontSize(16)  
      Image($r("app.media.image"))  
        .width('600px')  
        .height('300px')  
        .margin({ top: 50 })  
      Text(`矩阵变换后的坐标：[${this.transformPoint}]`)  
        .fontSize(16)  
        .margin({ top: 100 })  
      Image($r("app.media.image"))  
        .width('600px')  
        .height('300px')  
        .margin({ top: 50 })  
        .transform(this.matrix_2)  
    }.width("100%").padding(50)  
  }  
}  
    
```    
  
