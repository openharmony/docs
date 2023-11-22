# @system.bluetooth    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bluetooth from '@system.bluetooth';  
    
```  
    
## StartBLEScanOptions    
开始搜寻附近的低功耗蓝牙外围设备。此操作比较耗费系统资源，请在搜索并连接到设备后调用[bluetooth.stopBLEScan](#bluetoothstopblescanobject)方法停止搜索。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval | number | false | true | 上报设备的间隔，单位毫秒，默认值为0。0表示找到新设备立即上报，其他数值根据传入的间隔上报。 |  
| success | () => void | false | true | 接口调用成功的回调函数。 |  
| fail | (data: string, code: number) => void | false | true | 接口调用失败的回调函数。 |  
| complete | () => void | false | true | 接口调用结束的回调函数。 |  
    
## StopBLEScanOptions    
停止搜寻附近的低功耗蓝牙外围设备。与[bluetooth.startBLEScan(OBJECT)](#bluetoothstartblescanobject)接口配套使用。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success | () => void | false | true | 接口调用成功的回调函数。 |  
| fail | (data: string, code: number) => void | false | true | 接口调用失败的回调函数。 |  
| complete | () => void | false | true | 接口调用结束的回调函数。 |  
    
## BluetoothDevice  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| addrType | 'public' \| 'random' | false | true |  |  
| addr | string | false | true |  |  
| rssi | number | false | true |  |  
| txpower | string | false | true |  |  
| data | string | false | true |  |  
    
## BLEFoundResponse  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| devices | Array<BluetoothDevice> | false | true |  |  
    
## SubscribeBLEFoundOptions    
寻找到新设备上报时调用的回调函数。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success | (data: BLEFoundResponse) => void | false | true |  |  
| fail | (data: string, code: number) => void | false | true | 接口调用失败的回调函数。 |  
    
## Bluetooth  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
### startBLEScan    
开始搜寻附近的低功耗蓝牙外围设备。此操作比较耗费系统资源，请在搜索并连接到设备后调用[bluetooth.stopBLEScan](#bluetoothstopblescanobject)方法停止搜索。  
 **调用形式：**     
- static startBLEScan(options: StartBLEScanOptions): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | StartBLEScanOptions | true |  |  
    
 **示例代码：**   
```js    
 bluetooth.startBLEScan({  interval:0,  success() {   console.log('call bluetooth.startBLEScan success.');  },  fail(code, data) {   console.log('call bluetooth.startBLEScan failed, code:' + code + ', data:' + data);  },  complete() {   console.log('call bluetooth.startBLEScan complete.');  } });    
```    
  
    
### stopBLEScan    
停止搜寻附近的低功耗蓝牙外围设备。与[bluetooth.startBLEScan(OBJECT)](#bluetoothstartblescanobject)接口配套使用。  
 **调用形式：**     
- static stopBLEScan(options: StopBLEScanOptions): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | StopBLEScanOptions | true |  |  
    
 **示例代码：**   
```js    
 bluetooth.stopBLEScan({  success() {   console.log('call bluetooth.stopBLEScan success.');  },  fail(data, code) {   console.log('call bluethooth.stopBLEScan fail, code:' + code + ', data:' + data);  },  complete() {   console.log('call bluethooth.stopBLEScan complete.');  } });    
```    
  
    
### subscribeBLEFound    
订阅寻找到新设备。再次调用时，会覆盖前一次调用效果，即仅最后一次调用生效。  
 **调用形式：**     
- static subscribeBLEFound(options: SubscribeBLEFoundOptions): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | SubscribeBLEFoundOptions | true |  |  
    
 **示例代码：**   
```js    
 bluetooth.subscribeBLEFound({  success(data) {   console.log('call bluetooth.subscribeBLEFound success, data: ${data}.');  },  fail(data, code) {   console.log('call bluetooth.startBLEScan failed, code:' + code + ', data:' + data);  } });    
```    
  
    
### unsubscribeBLEFound  
 **调用形式：**     
- static unsubscribeBLEFound(): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Lite    
 **示例代码：**   
```js    
 bluetooth.unsubscribeBLEFound();    
```    
  
