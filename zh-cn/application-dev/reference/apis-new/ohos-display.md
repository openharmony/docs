# @ohos.display    
屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import display from '@ohos.display'    
```  
    
## getDefaultDisplay<sup>(deprecated)</sup>    
获取当前默认的display对象，使用callback异步回调。  
 **调用形式：**     
- getDefaultDisplay(callback: AsyncCallback\<Display>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.display#getDefaultDisplaySync。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Display> | true | 回调函数。返回当前默认的display对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
display.getDefaultDisplay((err: BusinessError, data: display.Display) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));  
  displayClass = data;  
});  
    
```    
  
    
## getDefaultDisplay<sup>(deprecated)</sup>    
获取当前默认的display对象，使用Promise异步回调。  
 **调用形式：**     
- getDefaultDisplay(): Promise\<Display>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.display#getDefaultDisplaySync。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Display> | Promise对象。返回当前默认的display对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
let promise: Promise<display.Display> = display.getDefaultDisplay();  
promise.then((data: display.Display) => {  
  displayClass = data;  
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));  
});  
    
```    
  
    
## getDefaultDisplaySync<sup>(9+)</sup>    
获取当前默认的display对象。  
 **调用形式：**     
- getDefaultDisplaySync(): Display  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Display | 返回默认的display对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1400001 | Invalid display or screen. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## getAllDisplay<sup>(deprecated)</sup>    
获取当前所有的display对象，使用callback异步回调。  
 **调用形式：**     
- getAllDisplay(callback: AsyncCallback\<Array\<Display>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.display#getAllDisplays。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Display>> | true | 回调函数。返回当前所有的display对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base';  
import display from '@ohos.display';  
  
let displayClass: Array<display.Display> = [];  
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {  
  displayClass = data;  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
## getAllDisplay<sup>(deprecated)</sup>    
获取当前所有的display对象，使用Promise异步回调。  
 **调用形式：**     
- getAllDisplay(): Promise\<Array\<Display>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.display#getAllDisplays。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Display>> | Promise对象。返回当前所有的display对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base';  
import display from '@ohos.display';  
  
let displayClass: Array<display.Display> =[];  
let promise: Promise<Array<display.Display>> = display.getAllDisplays();  
promise.then((data: Array<display.Display>) => {  
  displayClass = data;  
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));  
});  
    
```    
  
    
## getAllDisplays<sup>(9+)</sup>    
获取当前所有的display对象，使用callback异步回调。  
 **调用形式：**     
    
- getAllDisplays(callback: AsyncCallback\<Array\<Display>>): void    
起始版本： 9    
- getAllDisplays(): Promise\<Array\<Display>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前所有的display对象。 |  
| Promise<Array<Display>> | Promise对象。返回当前所有的display对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
import display from '@ohos.display';  
  
let displayClass: Array<display.Display> = [];  
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {  
  displayClass = data;  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
import display from '@ohos.display';  
  
let displayClass: Array<display.Display> =[];  
let promise: Promise<Array<display.Display>> = display.getAllDisplays();  
promise.then((data: Array<display.Display>) => {  
  displayClass = data;  
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));  
});  
    
```    
  
    
## on('add' | 'remove' | 'change')    
开启显示设备变化的监听。  
 **调用形式：**     
    
- on(type: 'add' | 'remove' | 'change', callback: Callback\<number>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回监听到的显示设备的id，该参数应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { Callback } from '@ohos.base';  
  
let callback: Callback<number> = (data: number) => {  
  console.info('Listening enabled. Data: ' + JSON.stringify(data));  
};  
try {  
  display.on("add", callback);  
} catch (exception) {  
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('add' | 'remove' | 'change')    
关闭显示设备变化的监听。  
 **调用形式：**     
    
- off(type: 'add' | 'remove' | 'change', callback?: Callback\<number>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回监听到的显示设备的id，该参数应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
try {  
  display.off("remove");  
} catch (exception) {  
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## isFoldable<sup>(10+)</sup>    
检查设备是否可折叠。  
 **调用形式：**     
- isFoldable(): boolean  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | boolean对象，返回当前设备是否可折叠的结果。false表示不可折叠，true表示可折叠。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  let ret: boolean = false;  
  try {  
    ret = display.isFoldable();  
  } catch (exception) {  
    console.error('Failed to check is foldable or not. Code: ' + JSON.stringify(exception));  
  }  
  if (ret == undefined) {  
    console.log("Failed to check is foldable or not.");  
  }  
  if (ret) {  
    console.log("The device is foldable.");  
  } else if (!ret) {  
    console.log("The device is not foldable.");  
  }  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## getFoldStatus<sup>(10+)</sup>    
获取可折叠设备的当前折叠状态。  
 **调用形式：**     
- getFoldStatus(): FoldStatus  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FoldStatus | FoldStatus对象，返回当前可折叠设备的折叠状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
try {  
  display.getFoldStatus();  
} catch (exception) {  
  console.error('Failed to obtain the fold status. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## on('foldStatusChange')<sup>(10+)</sup>    
开启折叠设备折叠状态变化的监听。  
 **调用形式：**     
    
- on(type: 'foldStatusChange', callback: Callback\<FoldStatus>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示折叠设备折叠状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import { Callback } from '@ohos.base';  
  
let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {  
  console.info('Listening enabled. Data: ' + JSON.stringify(data));  
};  
try {  
  display.on('foldStatusChange', callback);  
} catch (exception) {  
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('foldStatusChange')<sup>(10+)</sup>    
开启折叠设备折叠状态变化的监听。  
 **调用形式：**     
    
- off(type: 'foldStatusChange', callback?: Callback\<FoldStatus>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示折叠设备折叠状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
try {  
  display.off('foldStatusChange');  
} catch (exception) {  
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## getFoldDisplayMode<sup>(10+)</sup>    
获取可折叠设备的显示模式。  
 **调用形式：**     
- getFoldDisplayMode(): FoldDisplayMode  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FoldDisplayMode | FoldDisplayMode对象，返回当前可折叠设备的显示模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
try {  
  display.getFoldDisplayMode();  
} catch (exception) {  
  console.error('Failed to obtain the fold display mode. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## on('foldDisplayModeChange')<sup>(10+)</sup>    
开启折叠设备屏幕显示模式变化的监听。  
 **调用形式：**     
    
- on(type: 'foldDisplayModeChange', callback: Callback\<FoldDisplayMode>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示折叠设备屏幕显示模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import { Callback } from '@ohos.base';  
  
let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {  
  console.info('Listening enabled. Data: ' + JSON.stringify(data));  
};  
try {  
  display.on('foldDisplayModeChange', callback);  
} catch (exception) {  
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('foldDisplayModeChange')<sup>(10+)</sup>    
开启折叠设备屏幕显示模式变化的监听。  
 **调用形式：**     
    
- off(type: 'foldDisplayModeChange', callback?: Callback\<FoldDisplayMode>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示折叠设备屏幕显示模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
try {  
  display.off('foldDisplayModeChange');  
} catch (exception) {  
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## getCurrentFoldCreaseRegion<sup>(10+)</sup>    
在当前显示模式下获取折叠折痕区域。  
 **调用形式：**     
- getCurrentFoldCreaseRegion(): FoldCreaseRegion  
  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FoldCreaseRegion | FoldCreaseRegion对象，返回设备在当前显示模式下的折叠折痕区域。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
try {  
  display.getCurrentFoldCreaseRegion();  
} catch (exception) {  
  console.error('Failed to obtain the current fold crease region. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## FoldStatus<sup>(10+)</sup>    
开启折叠设备折叠状态变化的监听。    
    
 **系统能力:**  SystemCapability.Window.SessionManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FOLD_STATUS_UNKNOWN | 0 | 表示设备当前折叠状态未知。 |  
| FOLD_STATUS_EXPANDED | 1 | 表示设备当前折叠状态为完全展开。 |  
| FOLD_STATUS_FOLDED | 2 | 表示设备当前折叠状态为折叠。 |  
| FOLD_STATUS_HALF_FOLDED | 3 | 表示设备当前折叠状态为半折叠。半折叠指完全展开和折叠之间的状态。 |  
    
## FoldDisplayMode<sup>(10+)</sup>    
可折叠设备的显示模式枚举。    
    
 **系统能力:**  SystemCapability.Window.SessionManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FOLD_DISPLAY_MODE_UNKNOWN | 0 | 表示设备当前折叠显示模式未知。 |  
| FOLD_DISPLAY_MODE_FULL | 1 | 表示设备当前全屏显示。 |  
| FOLD_DISPLAY_MODE_MAIN | 2 | 表示设备当前主屏幕显示。 |  
| FOLD_DISPLAY_MODE_SUB | 3 | 表示设备当前子屏幕显示。 |  
| FOLD_DISPLAY_MODE_COORDINATION | 4 | 表示设备当前双屏协同显示。 |  
    
## DisplayState    
显示设备的状态枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_UNKNOWN | 0 | 表示显示设备状态未知。 |  
| STATE_OFF | 1 | 表示显示设备状态为关闭。 |  
| STATE_ON | 2 | 表示显示设备状态为开启。 |  
| STATE_DOZE | 3 | 表示显示设备为低电耗模式。 |  
| STATE_DOZE_SUSPEND | 4 | 表示显示设备为睡眠模式，CPU为挂起状态。 |  
| STATE_VR | 5 | 表示显示设备为VR模式。 |  
| STATE_ON_SUSPEND | 6 | 表示显示设备为开启状态，CPU为挂起状态。 |  
    
## Orientation<sup>(10+)</sup>    
显示设备当前显示的方向枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PORTRAIT | 0 | 表示设备当前以竖屏方式显示。 |  
| LANDSCAPE | 1 | 表示设备当前以横屏方式显示。 |  
| PORTRAIT_INVERTED | 2 | 表示设备当前以反向竖屏方式显示。 |  
| LANDSCAPE_INVERTED | 3 | 表示设备当前以反向横屏方式显示。 |  
    
## FoldCreaseRegion<sup>(10+)</sup>    
折叠折痕区域。  
 **系统能力:**  SystemCapability.Window.SessionManager    
### 属性    
 **系统能力:**  SystemCapability.Window.SessionManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| displayId<sup>(10+)</sup> | number | true | true | 显示器ID，用于识别折痕所在的屏幕 |  
| creaseRects<sup>(10+)</sup> | Array<Rect> | true | true | 折痕区域。 |  
    
## Rect<sup>(9+)</sup>    
矩形区域。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(9+)</sup> | number | false | true | 矩形区域的左边界，单位为像素，该参数应为整数。 |  
| top<sup>(9+)</sup> | number | false | true | 矩形区域的上边界，单位为像素，该参数应为整数 |  
| width<sup>(9+)</sup> | number | false | true | 矩形区域的宽度，单位为像素，该参数应为整数。 |  
| height<sup>(9+)</sup> | number | false | true | 矩形区域的高度，单位为像素，该参数应为整数。 |  
    
## WaterfallDisplayAreaRects<sup>(9+)</sup>    
瀑布屏曲面部分显示区域。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(9+)</sup> | Rect | true | true | 瀑布曲面区域的左侧矩形区域。 |  
| right<sup>(9+)</sup> | Rect | true | true | 瀑布曲面区域的右侧矩形区域。 |  
| top<sup>(9+)</sup> | Rect | true | true | 瀑布曲面区域的顶部矩形区域。 |  
| bottom<sup>(9+)</sup> | Rect | true | true | 瀑布曲面区域的底部矩形区域。 |  
    
## CutoutInfo<sup>(9+)</sup>    
挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| boundingRects<sup>(9+)</sup> | Array<Rect> | true | true | 挖孔、刘海等区域的边界矩形。 |  
| waterfallDisplayAreaRects<sup>(9+)</sup> | WaterfallDisplayAreaRects | true | true | 瀑布屏曲面部分显示区域。 |  
    
## Display    
屏幕实例。描述display对象的属性和方法。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | 显示设备的id号，该参数应为整数。 |  
| name | string | false | true | 显示设备的名称。 |  
| alive | boolean | false | true | 显示设备是否启用。 |  
| state | DisplayState | false | true | 显示设备的状态。 |  
| refreshRate | number | false | true | 显示设备的刷新率，该参数应为整数。 |  
| rotation | number | false | true | 显示设备的屏幕旋转角度。<br>值为0时，表示显示设备屏幕旋转为0°；<br>值为1时，表示显示设备屏幕旋转为90°；<br>值为2时，表示显示设备屏幕旋转为180°；<br>值为3时，表示显示设备屏幕旋转为270°。 |  
| width | number | false | true | 显示设备的宽度，单位为像素，该参数应为整数。 |  
| height | number | false | true | 显示设备的高度，单位为像素，该参数应为整数。 |  
| densityDPI | number | false | true | 显示设备的屏幕密度，表示每英寸点数。该参数为浮点数，一般取值160.0、480.0等。 |  
| orientation<sup>(10+)</sup> | Orientation | false | true | 表示屏幕当前显示的方向。 |  
| densityPixels | number | false | true | 显示设备的逻辑密度，是像素单位无关的缩放系数。该参数为浮点数，一般取值1.0、3.0等。 |  
| scaledDensity | number | false | true | 显示设备的显示字体的缩放因子。该参数为浮点数，通常与densityPixels相同。 |  
| xDPI | number | false | true | x方向中每英寸屏幕的确切物理像素值，该参数为浮点数。 |  
| yDPI | number | false | true | y方向中每英寸屏幕的确切物理像素值，该参数为浮点数。 |  
    
### getCutoutInfo<sup>(9+)</sup>    
获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用callback异步回调。建议应用布局规避该区域。  
 **调用形式：**     
    
- getCutoutInfo(callback: AsyncCallback\<CutoutInfo>): void    
起始版本： 9    
- getCutoutInfo(): Promise\<CutoutInfo>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回描述不可用屏幕区域的CutoutInfo对象 |  
| Promise<CutoutInfo> | Promise对象。返回描述不可用屏幕区域的CutoutInfo对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  displayClass.getCutoutInfo((err: BusinessError, data: display.CutoutInfo) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to get cutoutInfo. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  let promise: Promise<display.CutoutInfo> = displayClass.getCutoutInfo();  
  promise.then((data: display.CutoutInfo) => {  
    console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
