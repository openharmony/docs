# @ohos.multimodalInput.inputMonitor    
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputMonitor from '@ohos.multimodalInput.inputMonitor'    
```  
    
## TouchEventReceiver    
触摸（触屏）输入事件的回调函数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor    
## on('touch')    
监听全局触摸（触屏）事件。  
 **调用形式：**     
- on(type: 'touch', receiver: TouchEventReceiver): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'touch'。 |  
| receiver | TouchEventReceiver | true | 回调函数，异步上报触摸屏输入事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
    
 **示例代码：**   
```js    
import { TouchEvent } from '@ohos.multimodalInput.touchEvent';  
try {  
  inputMonitor.on('touch', (touchEvent: TouchEvent) => {  
    console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);  
    return false;  
  });  
} catch (error) {  
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('mouse')<sup>(9+)</sup>    
监听全局鼠标事件。  
 **调用形式：**     
- on(type: 'mouse', receiver: Callback\<MouseEvent>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'mouse'。 |  
| receiver | Callback<MouseEvent> | true | 回调函数，异步上报鼠标输入事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
    
 **示例代码：**   
```js    
import { MouseEvent } from '@ohos.multimodalInput.mouseEvent';  
  
try {  
  inputMonitor.on('mouse', (mouseEvent: MouseEvent) => {  
    console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);  
    return false;  
  });  
} catch (error) {  
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('touch')    
取消监听全局触摸（触屏）事件。  
 **调用形式：**     
- off(type: 'touch', receiver?: TouchEventReceiver): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'touch'。 |  
| receiver | TouchEventReceiver | false | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
    
 **示例代码：**   
```js    
import { TouchEvent } from '@ohos.multimodalInput.touchEvent';  
// 取消监听单个回调函数  
let callback = (touchEvent: TouchEvent) => {  
  console.log(`Monitor on success ${JSON.stringify(touchEvent)}`);  
  return false;  
};  
try {  
  inputMonitor.on('touch', callback);  
  inputMonitor.off('touch', callback);  
  console.log(`Monitor off success`);  
} catch (error) {  
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('mouse')<sup>(9+)</sup>    
取消监听全局鼠标事件。  
 **调用形式：**     
- off(type: 'mouse', receiver?: Callback\<MouseEvent>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'mouse'。 |  
| receiver | Callback<MouseEvent> | false | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
    
 **示例代码：**   
```js    
import { MouseEvent } from '@ohos.multimodalInput.mouseEvent';  
// 取消监听单个回调函数  
let callback = (mouseEvent: MouseEvent) => {  
  console.log(`Monitor on success ${JSON.stringify(mouseEvent)}`);  
  return false;  
};  
try {  
  inputMonitor.on('mouse', callback);  
  inputMonitor.off('mouse', callback);  
  console.log(`Monitor off success`);  
} catch (error) {  
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('pinch')<sup>(10+)</sup>    
监听全局触控板的捏合事件。  
 **调用形式：**     
- on(type: 'pinch', receiver: Callback\<Pinch>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'pinch'。 |  
| receiver | Callback<Pinch> | true | 回调函数，异步上报捏合输入事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
import type { Pinch } from '@ohos.multimodalInput.gestureEvent';  
try {  
  inputMonitor.on('pinch', (pinchEvent) => {  
    console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);  
    return false;  
  });  
} catch (error) {  
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('pinch')<sup>(10+)</sup>    
取消监听全局触控板的捏合事件。  
 **调用形式：**     
- off(type: 'pinch', receiver?: Callback\<Pinch>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'pinch'。 |  
| receiver | Callback<Pinch> | false | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
import { Pinch } from '@ohos.multimodalInput.gestureEvent';  
  
let callback = (pinchEvent: Pinch) => {  
  console.log(`Monitor on success ${JSON.stringify(pinchEvent)}`);  
  return false;  
};  
try {  
  inputMonitor.on('pinch', callback);  
  inputMonitor.off('pinch', callback);  
  console.log(`Monitor off success`);  
} catch (error) {  
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('threeFingersSwipe')<sup>(10+)</sup>    
监听全局触控板的三指滑动事件。  
 **调用形式：**     
- on(type: 'threeFingersSwipe', receiver: Callback\<ThreeFingersSwipe>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'threeFingersSwipe'。 |  
| receiver | Callback<ThreeFingersSwipe> | true | 回调函数，异步上报三指滑动输入事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  inputMonitor.on('threeFingersSwipe', (threeFingersSwipe) => {  
    console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);  
    return false;  
  });  
} catch (error) {  
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('threeFingersSwipe')<sup>(10+)</sup>    
取消监听全局触控板的三指滑动事件。  
 **调用形式：**     
- off(type: 'threeFingersSwipe', receiver?: Callback\<ThreeFingersSwipe>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'threeFingersSwipe'。 |  
| receiver | Callback<ThreeFingersSwipe> | false | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
import { ThreeFingersSwipe } from '@ohos.multimodalInput.gestureEvent';  
  
let callback = (threeFingersSwipe: ThreeFingersSwipe) => {  
  console.log(`Monitor on success ${JSON.stringify(threeFingersSwipe)}`);  
  return false;  
};  
try {  
  inputMonitor.on('threeFingersSwipe', callback);  
  inputMonitor.off("threeFingersSwipe", callback);  
  console.log(`Monitor off success`);  
} catch (error) {  
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('fourFingersSwipe')<sup>(10+)</sup>    
监听全局触控板的四指滑动事件。  
 **调用形式：**     
- on(type: 'fourFingersSwipe', receiver: Callback\<FourFingersSwipe>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'fourFingersSwipe'。 |  
| receiver | Callback<FourFingersSwipe> | true | 回调函数，异步上报四指滑动输入事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  inputMonitor.on('fourFingersSwipe', (fourFingersSwipe) => {  
    console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);  
    return false;  
  });  
} catch (error) {  
  console.log(`Monitor on failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('fourFingersSwipe')<sup>(10+)</sup>    
取消监听全局触控板的四指滑动事件。  
 **调用形式：**     
- off(type: 'fourFingersSwipe', receiver?: Callback\<FourFingersSwipe>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputMonitor  
 **需要权限：** ohos.permission.INPUT_MONITORING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备事件类型，取值'fourFingersSwipe'。 |  
| receiver | Callback<FourFingersSwipe> | false | 需要取消监听的回调函数。若不填，则取消当前应用监听的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```js    
import { FourFingersSwipe } from '@ohos.multimodalInput.gestureEvent';  
  
let callback = (fourFingersSwipe: FourFingersSwipe) => {  
  console.log(`Monitor on success ${JSON.stringify(fourFingersSwipe)}`);  
  return false;  
};  
try {  
  inputMonitor.on('fourFingersSwipe', callback);  
  inputMonitor.off('fourFingersSwipe');  
  console.log(`Monitor off success`);  
} catch (error) {  
  console.log(`Monitor execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
