# @ohos.arkui.drawableDescriptor    
本模块提供获取pixelMap的能力，包括前景、背景、蒙版和分层图标。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DrawableDescriptor    
创建DrawableDescriptor或LayeredDrawableDescriptor对象。对象构造需要使用全球化接口[getDrawableDescriptor](js-apis-resource-manager.md#getdrawabledescriptor)或[getDrawableDescriptorByName](js-apis-resource-manager.md#getdrawabledescriptorbyname)。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getPixelMap    
获取pixelMap。  
 **调用形式：**     
- getPixelMap(): image.PixelMap  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| image.PixelMap | PixelMap |  
    
 **示例代码：**   
```ts    
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'  
let resManager = getContext().resourceManager  
let pixmap: DrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.icon')  
    .id)) as DrawableDescriptor;  
let pixmapNew: object = pixmap.getPixelMap()  
    
```    
  
    
## LayeredDrawableDescriptor    
当传入资源id或name为包含前景和背景资源的json文件时，生成LayeredDrawableDescriptor对象。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### getForeground    
获取前景的DrawableDescriptor对象。  
 **调用形式：**     
- getForeground(): DrawableDescriptor  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | DrawableDescriptor对象 |  
    
 **示例代码：**   
```ts    
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'  
let resManager = getContext().resourceManager  
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.icon')  
    .id)) as LayeredDrawableDescriptor;  
let drawableNew: object =drawable.getForeground()  
    
```    
  
    
### getBackground    
获取背景的DrawableDescriptor对象。  
 **调用形式：**     
- getBackground(): DrawableDescriptor  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | DrawableDescriptor对象 |  
    
 **示例代码：**   
```ts    
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'  
let resManager = getContext().resourceManager  
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.icon')  
    .id)) as LayeredDrawableDescriptor;  
let drawableNew: object =drawable.getBackground()  
    
```    
  
    
### getMask    
获取蒙版的DrawableDescriptor对象。  
 **调用形式：**     
- getMask(): DrawableDescriptor  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | DrawableDescriptor对象 |  
    
 **示例代码：**   
```ts    
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'  
let resManager = getContext().resourceManager  
let drawable: LayeredDrawableDescriptor = (resManager.getDrawableDescriptor($r('app.media.icon')  
    .id)) as LayeredDrawableDescriptor;  
let drawableNew: object =drawable.getMask()  
    
```    
  
    
### getMaskClipPath    
LayeredDrawableDescriptor的静态方法，获取系统内置的裁切路径参数。  
 **调用形式：**     
- static getMaskClipPath(): string  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回裁切路径的命令字符串 |  
    
 **示例代码：**   
```ts    
import { DrawableDescriptor, LayeredDrawableDescriptor } from '@ohos.arkui.drawableDescriptor'  
Image($r('app.media.icon'))  
    .width('200px').height('200px')  
    .clip(new Path({commands:LayeredDrawableDescriptor.getMaskClipPath()}))  
    
```    
  
