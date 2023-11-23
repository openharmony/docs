# @ohos.graphics.colorSpaceManager    
本模块提供管理抽象化色域对象的一些基础能力，包括色域对象的创建与色域基础属性的获取等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import colorSpaceManager from '@ohos.graphics.colorSpaceManager'    
```  
    
## ColorSpace    
色域类型枚举。    
    
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN | 0 | 未知的色域类型。 |  
| ADOBE_RGB_1998 | 1 |  RGB色域为Adobe RGB(1998)类型。 |  
| DCI_P3 | 2 | RGB色域为DCI-P3类型。 |  
| DISPLAY_P3 | 3 | RGB色域为Display P3类型。 |  
| SRGB | 4 | RGB色域为SRGB类型。<br>系统默认色域类型。 |  
| CUSTOM | 5 | 用户自定义色域类型。 |  
    
## ColorSpacePrimaries    
色域标准三原色（红、绿、蓝）和白色，使用(x, y)表示其在色彩空间中的位置。  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| redX | number | false | true | 标准红色在色彩空间的x坐标值。 |  
| redY | number | false | true | 标准红色在色彩空间的y坐标值。 |  
| greenX | number | false | true | 标准绿色在色彩空间的x坐标值。 |  
| greenY | number | false | true | 标准绿色在色彩空间的y坐标值。 |  
| blueX | number | false | true | 标准蓝色色在色彩空间的x坐标值。 |  
| blueY | number | false | true | 标准蓝色在色彩空间的y坐标值。 |  
| whitePointX | number | false | true | 标准白色在色彩空间的x坐标值。 |  
| whitePointY | number | false | true | 标准白色在色彩空间的y坐标值。 |  
    
## ColorSpaceManager    
当前色域对象实例。  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
### getColorSpaceName    
获取色域类型。  
 **调用形式：**     
- getColorSpaceName(): ColorSpace  
  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ColorSpace | 返回色域类型枚举值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 18600001 | Parameter value is abnormal. |  
    
 **示例代码：**   
```ts    
try {  
    colorSpace.getColorSpaceName();  
} catch (err) {  
    console.log(`Fail to get colorSpace's name. Cause: ` + JSON.stringify(err));  
}  
    
```    
  
    
### getWhitePoint    
获取色域白点值。  
 **调用形式：**     
- getWhitePoint(): Array\<number>  
  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 返回色域白点值[x, y]。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 18600001 | Parameter value is abnormal. |  
    
 **示例代码：**   
```ts    
try {  
    colorSpace.getWhitePoint();  
} catch (err) {  
    console.log(`Failed to get white point. Cause: ` + JSON.stringify(err));  
}  
    
```    
  
    
### getGamma    
获取色域gamma值。  
 **调用形式：**     
- getGamma(): number  
  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回色域gamma值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 18600001 | Parameter value is abnormal. |  
    
 **示例代码：**   
```ts    
try {  
    colorSpace.getGamma();  
} catch (err) {  
    console.log(`Failed to get gamma. Cause: ` + JSON.stringify(err));  
}  
    
```    
  
    
## create    
创建标准色域对象。  
 **调用形式：**     
- create(colorSpaceName: ColorSpace): ColorSpaceManager  
  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| colorSpaceName | ColorSpace | true | 标准色域类型枚举值。<br>UNKNOWN与CUSTOM不可用于直接创建色域对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ColorSpaceManager | 返回当前创建的色域对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 18600001 | Parameter value is abnormal. |  
    
 **示例代码：**   
```ts    
let colorSpace: colorSpaceManager.ColorSpaceManager;  
try {  
    colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.SRGB);  
} catch (err) {  
    console.log(`Failed to create SRGB colorSpace. Cause: ` + JSON.stringify(err));  
}  
    
```    
  
    
## create    
创建用户自定义色域对象。  
 **调用形式：**     
- create(primaries: ColorSpacePrimaries, gamma: number): ColorSpaceManager  
  
 **系统能力:**  SystemCapability.Graphic.Graphic2D.ColorManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| primaries | ColorSpacePrimaries | true | 色域标准三原色。 |  
| gamma | number | true | 色域gamma值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ColorSpaceManager | 返回当前创建的色域对象实例。<br>色域类型定义为[ColorSpace](#colorspace)枚举值`CUSTOM`。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 18600001 | Parameter value is abnormal. |  
    
 **示例代码：**   
```ts    
let colorSpace: colorSpaceManager.ColorSpaceManager;  
try {  
    let primaries: colorSpaceManager.ColorSpacePrimaries = {  
        redX: 0.1,  
        redY: 0.1,  
        greenX: 0.2,  
        greenY: 0.2,  
        blueX: 0.3,  
        blueY: 0.3,  
        whitePointX: 0.4,  
        whitePointY: 0.4  
    };  
    let gamma = 2.2;  
    colorSpace = colorSpaceManager.create(primaries, gamma);  
} catch (err) {  
    console.log(`Failed to create colorSpace with customized primaries and gamma. Cause: ` + JSON.stringify(err));  
}  
    
```    
  
