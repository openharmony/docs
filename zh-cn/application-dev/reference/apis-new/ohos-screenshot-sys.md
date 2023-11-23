# @ohos.screenshot    
本模块提供屏幕截图的能力，截取屏幕时支持设置截取的区域、大小等图像信息。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import screenshot from '@ohos.screenshot'    
```  
    
## save    
获取屏幕截图。  
 **调用形式：**     
    
- save(options: ScreenshotOptions, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 7    
- save(callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 7    
- save(options?: ScreenshotOptions): Promise\<image.PixelMap>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core  
 **需要权限：** ohos.permission.CAPTURE_SCREEN    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ScreenshotOptions | true | 该类型的参数包含screenRect、imageSize、rotation、displayId四个参数，可以分别设置这四个参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回一个PixelMap对象。 |  
| Promise<image.PixelMap> | Promise对象。返回一个PixelMap对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
参数（options） 示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenshotOptions: screenshot.ScreenshotOptions = {  
  "screenRect": {  
    "left": 200,  
    "top": 100,  
    "width": 200,  
    "height": 200 },  
  "imageSize": {  
    "width": 300,  
    "height": 300 },  
  "rotation": 0,  
  "displayId": 0  
};  
try {  
  screenshot.save(screenshotOptions, (err: BusinessError, pixelMap) => {  
    if (err) {  
      console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());  
    pixelMap.release(); // PixelMap使用完后及时释放内存  
  });  
} catch (exception) {  
  console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  screenshot.save((err: BusinessError, pixelMap) => {  
    if (err) {  
      console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());  
    pixelMap.release(); // PixelMap使用完后及时释放内存  
  });  
} catch (exception) {  
  console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码3：**   
参数（options） 示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenshotOptions: screenshot.ScreenshotOptions = {  
  "screenRect": {  
    "left": 200,  
    "top": 100,  
    "width": 200,  
    "height": 200 },  
  "imageSize": {  
    "width": 300,  
    "height": 300 },  
  "rotation": 0,  
  "displayId": 0  
};  
try {  
  let promise = screenshot.save(screenshotOptions);  
  promise.then((pixelMap) => {  
    console.log('Succeeded in saving sreenshot. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());  
    pixelMap.release(); // PixelMap使用完后及时释放内存  
  }).catch((err: BusinessError) => {  
    console.log('Failed to save screenshot. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to save screenshot. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## Rect    
表示截取图像的区域。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
## Size    
表示截取图像的大小。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
## ScreenshotOptions    
设置截取图像的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| screenRect | Rect | false | false | 表示截取图像的区域，不传值默认为全屏。 |  
| imageSize | Size | false | false | 表示截取图像的大小，不传值默认为全屏。 |  
| rotation | number | false | false | 表示截取图像的旋转角度，当前仅支持输入值为0，默认值为0，该参数应为整数。 |  
| displayId<sup>(8+)</sup> | number | false | false | 表示截取图像的显示设备[Display](js-apis-display.md#display)的ID号，该参数应为整数。 |  
