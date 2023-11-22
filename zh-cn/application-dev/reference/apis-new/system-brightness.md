# @system.brightness    
该模块提供屏幕亮度和模式的查询、调节接口。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## BrightnessResponse<sup>(deprecated)</sup>    
包含屏幕亮度的对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 7 开始废弃。<br>屏幕亮度，范围：1到255。 |  
    
## GetBrightnessOptions<sup>(deprecated)</sup>    
获取屏幕亮度模式的参数对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: BrightnessResponse) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用成功的回调函数。data为[BrightnessModeResponse](#brightnessmoderesponse)类型的返回值。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用结束的回调函数。 |  
    
## SetBrightnessOptions<sup>(deprecated)</sup>    
设置屏幕亮度的参数对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 7 开始废弃。<br>屏幕亮度，值为1-255之间的整数。<br/>-如果值小于等于0，系统按1处理。<br/>-如果值大于255，系统按255处理。<br/>-如果值为小数，系统将处理为整数。例如设置为8.1，系统按8处理。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用结束的回调函数。 |  
    
## BrightnessModeResponse<sup>(deprecated)</sup>    
包含屏幕亮度模式的对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 7 开始废弃。<br>0表示手动调节屏幕亮度模式，1表示自动调节屏幕亮度模式。 |  
    
## GetBrightnessModeOptions<sup>(deprecated)</sup>    
获取屏幕亮度模式的参数对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: BrightnessModeResponse) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用成功的回调函数。data为[BrightnessModeResponse](#brightnessmoderesponse)类型的返回值。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用结束的回调函数。 |  
    
## SetBrightnessModeOptions<sup>(deprecated)</sup>    
设置屏幕亮度模式的参数对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 7 开始废弃。<br>0表示手动调节屏幕亮度模式，1表示自动调节屏幕亮度模式。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用结束的回调函数。 |  
    
## SetKeepScreenOnOptions<sup>(deprecated)</sup>    
设置屏幕常亮的参数对象。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| keepScreenOn<sup>(deprecated)</sup> | boolean | false | true | 从API version 3 开始支持，从API version 7 开始废弃。<br>true表示保持屏幕常亮，false表示取消屏幕常亮。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 7 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Brightness<sup>(deprecated)</sup>    
该模块提供屏幕亮度和模式的查询、调节接口。    
从API version 3 开始支持，从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
### getValue<sup>(deprecated)</sup>    
获得设备当前的屏幕亮度值。  
 **调用形式：**     
- static getValue(options?: GetBrightnessOptions): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetBrightnessOptions | false | 获取屏幕亮度的参数对象。可选，默认为空。 |  
    
 **示例代码：**   
```js    
 brightness.getValue({   success: (data: BrightnessResponse) => {    console.log('success get brightness value:' + data.value);   },   fail: (data: string, code: number) => {    console.error('get brightness fail, code: ' + code + ', data: ' + data);   } });    
```    
  
    
### setValue<sup>(deprecated)</sup>    
设置设备当前的屏幕亮度值。  
 **调用形式：**     
- static setValue(options?: SetBrightnessOptions): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SetBrightnessOptions | false | 设置屏幕亮度的参数对象。可选，默认为空。 |  
    
 **示例代码：**   
```js    
 brightness.setValue({   value: 100,   success: () => {    console.log('handling set brightness success.');   },   fail: (data: string, code: number) => {    console.error('handling set brightness value fail, code:' + code + ', data: ' + data);   } });    
```    
  
    
### getMode<sup>(deprecated)</sup>    
获得当前屏幕亮度模式。  
 **调用形式：**     
- static getMode(options?: GetBrightnessModeOptions): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetBrightnessModeOptions | false | 获取屏幕亮度模式的参数对象。可选，默认为空。 |  
    
 **示例代码：**   
```js    
brightness.getMode({   success: (data: BrightnessModeResponse) => {    console.log('success get mode:' + data.mode);   },   fail: (data: string, code: number) => {    console.error('handling get mode fail, code:' + code + ', data: ' + data);   } });    
```    
  
    
### setMode<sup>(deprecated)</sup>    
设置设备当前的屏幕亮度模式。  
 **调用形式：**     
- static setMode(options?: SetBrightnessModeOptions): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SetBrightnessModeOptions | false | 设置屏幕亮度模式的参数对象。可选，默认为空。 |  
    
 **示例代码：**   
```js    
 brightness.setMode({   mode: 1,   success: () => {    console.log('handling set mode success.');   },   fail: (data: string, code: number) => {    console.error('handling set mode fail, code:' + code + ', data: ' + data);   } });    
```    
  
    
### setKeepScreenOn<sup>(deprecated)</sup>    
设置屏幕是否保持常亮状态，开启常亮模式推荐在onShow()阶段调用。  
 **调用形式：**     
- static setKeepScreenOn(options?: SetKeepScreenOnOptions): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.DisplayPowerManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SetKeepScreenOnOptions | false | 设置屏幕常亮的参数对象。可选，默认为空。 |  
    
 **示例代码：**   
```js    
 brightness.setKeepScreenOn({   keepScreenOn: true,   success: () => {    console.log('handling set keep screen on success.');   },   fail: (data: string, code: number) => {    console.error('handling set keep screen on fail, code:' + code + ', data: ' + data);   } });    
```    
  
