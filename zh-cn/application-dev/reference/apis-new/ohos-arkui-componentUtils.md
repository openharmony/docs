# @ohos.arkui.componentUtils    
提供获取组件绘制区域坐标和大小的能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import componentUtils from '@ohos.arkui.componentUtils'    
```  
    
## ComponentInfo  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size | Size | false | true | 组件大小。 |  
| localOffset | Offset | false | true | 组件相对于父组件信息。 |  
| windowOffset | Offset | false | true | 组件相对于窗口信息。  |  
| screenOffset | Offset | false | true | 组件相对于屏幕信息。 |  
| translate | TranslateResult | false | true | 组件平移信息。 |  
| scale | ScaleResult | false | true | 组件缩放信息。 |  
| rotate | RotateResult | false | true | 组件旋转信息。 |  
| transform | Matrix4Result | false | true | 仿射矩阵信息，根据入参创建的四阶矩阵对象。 |  
    
## Size  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width | number | false | true | 组件宽度。<br />单位: px |  
| height | number | false | true | 组件高度。<br />单位: px |  
    
## Offset  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x点坐标。<br />单位: px  |  
| y | number | false | true | y点坐标。<br />单位: px  |  
    
## TranslateResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x轴平移距离。<br />单位: px |  
| y | number | false | true | y轴平移距离。<br />单位: px |  
| z | number | false | true | z轴平移距离。<br />单位: px |  
    
## ScaleResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x轴缩放倍数。<br />单位: px |  
| y | number | false | true | y轴缩放倍数。<br />单位: px |  
| z | number | false | true | z轴缩放倍数。<br />单位: px |  
| centerX | number | false | true | 变换中心点x轴坐标。<br />单位: px |  
| centerY | number | false | true |  |  
    
## RotateResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 旋转轴向量x坐标。<br />单位: px |  
| y | number | false | true | 旋转轴向量y坐标。<br />单位: px |  
| z | number | false | true | 旋转轴向量z坐标。<br />单位: px |  
| centerX | number | false | true | 变换中心点x轴坐标。<br />单位: px |  
| centerY | number | false | true | 变换中心点y轴坐标。<br />单位: px  |  
| angle | number | false | true | 旋转角度。<br />单位: px |  
    
## Matrix4Result    
取值范围为长度为16（4*4）的number数组,详情见四阶矩阵说明,单位: px。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
import matrix4 from '@ohos.matrix4';  
import componentUtils from '@ohos.arkui.componentUtils';  
  
@Entry  
@Component  
struct Utils{  
private getComponentRect(key:string) {  
  console.info("Mode Key: " + key);  
  let modePosition = componentUtils.getRectangleById(key);  
  
  let localOffsetWidth = modePosition.size.width;  
  let localOffsetHeight = modePosition.size.height;  
  let localOffsetX = modePosition.localOffset.x;  
  let localOffsetY = modePosition.localOffset.y;  
  
  let windowOffsetX = modePosition.windowOffset.x;  
  let windowOffsetY = modePosition.windowOffset.y;  
  
  let screenOffsetX = modePosition.screenOffset.x;  
  let screenOffsetY = modePosition.screenOffset.y;  
  
  let translateX = modePosition.translate.x;  
  let translateY = modePosition.translate.y;  
  let translateZ = modePosition.translate.z;  
  
  let scaleX = modePosition.scale.x;  
  let scaleY = modePosition.scale.y;  
  let scaleZ = modePosition.scale.z;  
  let scaleCenterX = modePosition.scale.centerX;  
  let scaleCenterY = modePosition.scale.centerY;  
  
  let rotateX = modePosition.rotate.x;  
  let rotateY = modePosition.rotate.y;  
  let rotateZ = modePosition.rotate.z;  
  let rotateCenterX = modePosition.rotate.centerX;  
  let rotateCenterY = modePosition.rotate.centerY;  
  let rotateAngle = modePosition.rotate.angle;  
  
  let Matrix4_1 = modePosition.transform[0];  
  let Matrix4_2 = modePosition.transform[1];  
  let Matrix4_3 = modePosition.transform[2];  
  let Matrix4_4 = modePosition.transform[3];  
  let Matrix4_5 = modePosition.transform[4];  
  let Matrix4_6 = modePosition.transform[5];  
  let Matrix4_7 = modePosition.transform[6];  
  let Matrix4_8 = modePosition.transform[7];  
  let Matrix4_9 = modePosition.transform[8];  
  let Matrix4_10 = modePosition.transform[9];  
  let Matrix4_11 = modePosition.transform[10];  
  let Matrix4_12 = modePosition.transform[11];  
  let Matrix4_13 = modePosition.transform[12];  
  let Matrix4_14 = modePosition.transform[13];  
  let Matrix4_15 = modePosition.transform[14];  
  let Matrix4_16 = modePosition.transform[15];  
  console.info("[getRectangleById] current component obj is: " + modePosition );  
}  
@State x: number = 120;  
@State y: number = 10;  
@State z: number = 100;  
private matrix1 = matrix4.identity().translate({ x: this.x, y: this.y, z: this.z });  
build() {  
  Column() {  
      Image($r("app.media.icon"))  
        .transform(this.matrix1)  
        .translate({ x: 100, y: 10, z: 50})  
        .scale({ x: 2, y: 0.5, z: 1 })  
        .rotate({  
          x: 1,  
          y: 1,  
          z: 1,  
          centerX: '50%',  
          centerY: '50%',  
          angle: 300  
        })  
        .width("40%")  
        .height(100)  
        .key("image_01")  
    Button() {  
      Text('getRectangleById').fontSize(40).fontWeight(FontWeight.Bold);  
    }.margin({ top: 20 })  
    .onClick(() => {  
      this.getComponentRect("image_01");  
    }).id('onClick');  
  }  
}  
}    
```    
  
    
## getRectangleById  
 **调用形式：**     
- getRectangleById(id: string): ComponentInfo  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ComponentInfo |  |  
    
 **示例代码：**   
```ts    
import componentUtils from '@ohos.arkui.componentUtils';let modePosition:componentUtils.ComponentInfo = componentUtils.getRectangleById("onClick");    
```    
  
