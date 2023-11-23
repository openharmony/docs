# @ohos.display    
屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import display from '@ohos.display'    
```  
    
## hasPrivateWindow<sup>(9+)</sup>    
查询指定display对象上是否有可见的隐私窗口。可通过[setWindowPrivacyMode()](js-apis-window.md#setwindowprivacymode9)接口设置隐私窗口。隐私窗口内容将无法被截屏或录屏。  
 **调用形式：**     
- hasPrivateWindow(displayId: number): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| displayId | number | true | 显示设备的id，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 查询的display对象上是否有可见的隐私窗口。<br>true表示此display对象上有可见的隐私窗口，false表示此display对象上没有可见的隐私窗口。</br> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  let ret: boolean = true;  
  try {  
    ret = display.hasPrivateWindow(displayClass.id);  
  } catch (exception) {  
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));  
  }  
  if (ret == undefined) {  
    console.log("Failed to check has privateWindow or not.");  
  }  
  if (ret) {  
    console.log("There has privateWindow.");  
  } else if (!ret) {  
    console.log("There has no privateWindow.");  
  }  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## on('privateModeChange')<sup>(10+)</sup>    
开启屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。  
 **调用形式：**     
    
- on(type: 'privateModeChange', callback: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私窗口模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { Callback } from '@ohos.base';  
  
let callback: Callback<boolean> = (data: boolean) => {  
  console.info('Listening enabled. Data: ' + JSON.stringify(data));  
};  
try {  
  display.on("privateModeChange", callback);  
} catch (exception) {  
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('privateModeChange')<sup>(10+)</sup>    
关闭屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。  
 **调用形式：**     
    
- off(type: 'privateModeChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
try {  
  display.off("privateModeChange");  
} catch (exception) {  
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## setFoldDisplayMode<sup>(10+)</sup>    
更改可折叠设备的显示模式。  
 **调用形式：**     
- setFoldDisplayMode(mode: FoldDisplayMode): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | FoldDisplayMode | true | 可折叠设备的显示模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码：**   
示例：  
```ts    
import display from '@ohos.display';  
  
try {  
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;  
  display.setFoldDisplayMode(mode);  
} catch (exception) {  
  console.error('Failed to change the fold display mode. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
