# @ohos.multimodalInput.inputDevice    
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputDevice from '@ohos.multimodalInput.inputDevice'    
```  
    
## ChangedType<sup>(9+)</sup>    
定义监听设备热插拔事件。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
    
| 取值范围 | 说明 |  
| --------| --------|  
| add | 表示输入设备插入。 |  
| remove | 表示输入设备移除。 |  
    
## SourceType<sup>(9+)</sup>    
轴的输入源类型。比如鼠标设备可上报x轴事件，则x轴的输入源就是鼠标。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
    
| 取值范围 | 说明 |  
| --------| --------|  
| keyboard | 表示输入设备是键盘。 |  
| mouse | 表示输入设备是鼠标。 |  
| touchpad | 表示输入设备是触摸板。 |  
| touchscreen | 表示输入设备是触摸屏。 |  
| joystick | 表示输入设备是操纵杆。 |  
| trackball | 表示输入设备是轨迹球。 |  
    
## AxisType<sup>(9+)</sup>    
输入设备的轴类型。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
    
| 取值范围 | 说明 |  
| --------| --------|  
| touchmajor | 表示touchmajor轴。 |  
| touchminor | 表示touchminor轴。 |  
| orientation | 表示orientation轴。 |  
| x | 表示x轴。 |  
| y | 表示y轴。 |  
| pressure | 表示pressure轴。 |  
| toolminor | 表示toolminor轴。 |  
| toolmajor | 表示toolmajor轴。 |  
|  | 无。 |  
    
## KeyboardType<sup>(9+)</sup>    
定义键盘输入设备的类型。    
    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 表示无按键设备。 |  
| UNKNOWN | 1 | 表示未知按键设备。 |  
| ALPHABETIC_KEYBOARD | 2 | 表示全键盘设备。 |  
| DIGITAL_KEYBOARD | 3 | 表示小键盘设备。 |  
| HANDWRITING_PEN | 4 | 表示手写笔设备。 |  
| REMOTE_CONTROL | 5 | 表示遥控器设备。 |  
    
## DeviceListener<sup>(9+)</sup>    
输入设备热插拔的描述信息。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(9+)</sup> | ChangedType | false | true | 输入设备插入或者移除。 |  
| deviceId<sup>(9+)</sup> | number | false | true | 输入设备的唯一标识，同一个物理设备反复插拔，设备id会发生变化。 |  
    
## on('change')<sup>(9+)</sup>    
监听输入设备的热插拔事件。  
 **调用形式：**     
- on(type: 'change', listener: Callback\<DeviceListener>): void  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备的事件类型。 |  
| listener | Callback<DeviceListener> | true | 回调函数，异步上报输入设备热插拔事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let isPhysicalKeyboardExist = true;  
try {  
  inputDevice.on("change", (data: inputDevice.DeviceListener) => {  
    console.log(`Device event info: ${JSON.stringify(data)}`);  
    inputDevice.getKeyboardType(data.deviceId, (err: Error, type: inputDevice.KeyboardType) => {  
      console.log("The keyboard type is: " + type);  
      if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD  data.type == 'add') {  
        // 监听物理键盘已连接。  
        isPhysicalKeyboardExist = true;  
      } else if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD  data.type == 'remove') {  
        // 监听物理键盘已断开。  
        isPhysicalKeyboardExist = false;  
      }  
    });  
  });  
  // 根据isPhysicalKeyboardExist的值决定软键盘是否弹出。  
} catch (error) {  
  console.log(`Get device info failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('change')<sup>(9+)</sup>    
取消监听输入设备的热插拔事件。在应用退出前调用，取消监听。  
 **调用形式：**     
- off(type: 'change', listener?: Callback\<DeviceListener>): void  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 输入设备的事件类型。 |  
| listener | Callback<DeviceListener> | false | 取消监听的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
function callback(data: inputDevice.DeviceListener) {  
  console.log(`Report device event info: ${JSON.stringify(data, [`type`, `deviceId`])}`);  
};  
  
try {  
  inputDevice.on("change", callback);  
} catch (error) {  
  console.log(`Listen device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
  
// 取消指定的监听。  
try {  
  inputDevice.off("change", callback);  
} catch (error) {  
  console.log(`Cancel listening device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
  
// 取消所有监听。  
try {  
  inputDevice.off("change");  
} catch (error) {  
  console.log(`Cancel all listening device event failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## AxisRange    
输入设备的轴信息。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| source | SourceType | false | true | 轴的输入源类型。 |  
| axis | AxisType | false | true | 轴的类型。 |  
| max | number | false | true | 轴的最大值。 |  
| min | number | false | true | | min                     | number                    | 是 | 否 | 轴的最小值。   | |  
| fuzz<sup>(9+)</sup> | number | false | true | 轴的模糊值。 |  
| flat<sup>(9+)</sup> | number | false | true | 轴的基准值。 |  
| resolution<sup>(9+)</sup> | number | false | true | 轴的分辨率。 |  
    
## InputDeviceData    
输入设备的描述信息。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | true | 输入设备的唯一标识，同一个物理设备反复插拔，设备id会发生变化。 |  
| name | string | false | true | 输入设备的名字。 |  
| sources | Array<SourceType> | false | true | 输入设备支持的源类型。比如有的键盘上附带触摸板，则此设备有keyboard和touchpad两种输入源。 |  
| axisRanges | Array<AxisRange> | false | true | 输入设备的轴信息。 |  
| bus<sup>(9+)</sup> | number | false | true | 输入设备的总线类型。 |  
| product<sup>(9+)</sup> | number | false | true | 输入设备的产品信息。 |  
| vendor<sup>(9+)</sup> | number | false | true | | vendor<sup>9+</sup>  | number                                 | 是 | 否 | 输入设备的厂商信息。                                         | |  
| version<sup>(9+)</sup> | number | false | true | 输入设备的版本信息。 |  
| phys<sup>(9+)</sup> | string | false | true | 输入设备的物理地址。 |  
| uniq<sup>(9+)</sup> | string | false | true | 输入设备的唯一标识。 |  
    
## getDeviceIds<sup>(deprecated)</sup>    
获取所有输入设备的id列表，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
- getDeviceIds(callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimodalInput.inputDevice#getDeviceList。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 回调函数，异步返回所有输入设备的id列表。 |  
    
 **示例代码：**   
示例代码（callback）：  
```js    
inputDevice.getDeviceIds((error: Error, ids: Array<Number>) => {  if (error) {    console.log(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);    return;  }  console.log(`Device id list: ${JSON.stringify(ids)}`);});    
```    
  
    
## getDeviceIds<sup>(deprecated)</sup>    
获取所有输入设备的id列表，使用Promise异步方式返回结果。  
 **调用形式：**     
- getDeviceIds(): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimodalInput.inputDevice#getDeviceList。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | Promise对象，异步返回所有输入设备的id列表。 |  
    
 **示例代码：**   
示例代码（promise）：  
```js    
inputDevice.getDeviceIds().then((ids: Array<Number>) => {  console.log(`Device id list: ${JSON.stringify(ids)}`);});    
```    
  
    
## getDevice<sup>(deprecated)</sup>    
获取指定输入设备的信息，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
- getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimodalInput.inputDevice#getDeviceInfo。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | number | true | 输入设备id。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<InputDeviceData> | true | 回调函数，异步返回输入设备信息。 |  
    
 **示例代码：**   
示例代码（callback）：  
```js    
inputDevice.getDevice(1, (error: Error, deviceData: inputDevice.InputDeviceData) => {  if (error) {    console.log(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);    return;  }  console.log(`Device info: ${JSON.stringify(deviceData)}`);});    
```    
  
    
## getDevice<sup>(deprecated)</sup>    
获取指定输入设备的信息，使用Promise异步方式返回结果。  
 **调用形式：**     
- getDevice(deviceId: number): Promise\<InputDeviceData>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.multimodalInput.inputDevice#getDeviceInfo。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | number | true | 输入设备id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<InputDeviceData> | Promise对象，异步返回输入设备信息。 |  
    
 **示例代码：**   
示例代码（promise）：  
```js    
// 获取输入设备id为1的设备信息。inputDevice.getDevice(1).then((deviceData: inputDevice.InputDeviceData) => {  console.log(`Device info: ${JSON.stringify(deviceData)}`);});    
```    
  
    
## getDeviceList<sup>(9+)</sup>    
获取所有输入设备的id列表，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getDeviceList(callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getDeviceList(): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回所有输入设备的id列表。 |  
| Promise<Array<number>> | Promise对象，异步返回所有输入设备的id列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.getDeviceList((error: Error, ids: Array<Number>) => {  
    if (error) {  
      console.log(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Device id list: ${JSON.stringify(ids)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.getDeviceList().then((ids: Array<Number>) => {  
    console.log(`Device id list: ${JSON.stringify(ids)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get device id list, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getDeviceInfo<sup>(9+)</sup>    
获取指定输入设备的信息，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getDeviceInfo(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void    
起始版本： 9    
- getDeviceInfo(deviceId: number): Promise\<InputDeviceData>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回输入设备信息。 |  
| Promise<InputDeviceData> | Promise对象，异步返回输入设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.getDeviceInfo(1, (error: Error, deviceData: inputDevice.InputDeviceData) => {  
    if (error) {  
      console.log(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Device info: ${JSON.stringify(deviceData)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.getDeviceInfo(1).then((deviceData: inputDevice.InputDeviceData) => {  
    console.log(`Device info: ${JSON.stringify(deviceData)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getDeviceInfoSync<sup>(10+)</sup>    
获取指定输入设备的信息。  
 **调用形式：**     
- getDeviceInfoSync(deviceId: number): InputDeviceData  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputDeviceData |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let deviceData: inputDevice.InputDeviceData = inputDevice.getDeviceInfoSync(1)  
  console.log(`Device info: ${JSON.stringify(deviceData)}`)  
} catch (error) {  
  console.log(`Failed to get device info, error: ${JSON.stringify(error, [`code`, `message`])}`)  
}  
    
```    
  
    
## supportKeys<sup>(9+)</sup>    
获取输入设备是否支持指定的键码值，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- supportKeys(deviceId: number, keys: Array\<KeyCode>, callback: AsyncCallback\<Array\<boolean>>): void    
起始版本： 9    
- supportKeys(deviceId: number, keys: Array\<KeyCode>): Promise\<Array\<boolean>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备id，同一个物理设备反复插拔，设备id会发生变化。 |  
| keys | Array<KeyCode> | true | 需要查询的键码值，最多支持5个按键查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回查询结果。 |  
| Promise<Array<boolean>> | Promise对象，异步返回查询结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.supportKeys(1, [17, 22, 2055], (error: Error, supportResult: Array<Boolean>) => {  
    console.log(`Query result: ${JSON.stringify(supportResult)}`);  
  });  
} catch (error) {  
  console.log(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
inputDevice.supportKeys(1, [17, 22, 2055]).then((supportResult: Array<Boolean>) => {  
console.log(`Query result: ${JSON.stringify(supportResult)}`);  
});  
} catch (error) {  
console.log(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## supportKeysSync<sup>(10+)</sup>    
获取输入设备是否支持指定的键码值。  
 **调用形式：**     
- supportKeysSync(deviceId: number, keys: Array\<KeyCode>): Array\<boolean>  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备id，同一个物理设备反复插拔，设备id会发生变化。 |  
| keys | Array<KeyCode> | true | 需要查询的键码值，最多支持5个按键查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<boolean> | 返回查询结果。true表示支持，false表示不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let supportResult: Array<Boolean> = inputDevice.supportKeysSync(1, [17, 22, 2055])  
  console.log(`Query result: ${JSON.stringify(supportResult)}`)  
} catch (error) {  
  console.log(`Query failed, error: ${JSON.stringify(error, [`code`, `message`])}`)  
}  
    
```    
  
    
## getKeyboardType<sup>(9+)</sup>    
获取输入设备的键盘类型，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void    
起始版本： 9    
- getKeyboardType(deviceId: number): Promise\<KeyboardType>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备的唯一标识，同一个物理设备反复插拔，设备id会发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回查询结果。 |  
| Promise<KeyboardType> | Promise对象，异步返回查询结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.getKeyboardType(1, (error: Error, type: Number) => {  
    if (error) {  
      console.log(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Keyboard type: ${JSON.stringify(type)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.getKeyboardType(1).then((type: Number) => {  
    console.log(`Keyboard type: ${JSON.stringify(type)}`);  
  });  
} catch (error) {  
  console.log(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getKeyboardTypeSync<sup>(10+)</sup>    
获取输入设备的键盘类型。  
 **调用形式：**     
- getKeyboardTypeSync(deviceId: number): KeyboardType  
  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 输入设备的唯一标识，同一个物理设备反复插拔，设备id会发生变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| KeyboardType | 返回查询结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
try {  
  let type: number = inputDevice.getKeyboardTypeSync(1)  
  console.log(`Keyboard type: ${JSON.stringify(type)}`)  
} catch (error) {  
  console.log(`Failed to get keyboard type, error: ${JSON.stringify(error, [`code`, `message`])}`)  
}  
    
```    
  
