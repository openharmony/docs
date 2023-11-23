# @ohos.bluetooth.socket    
socket模块提供了操作和管理蓝牙socket的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import socket from '@ohos.bluetooth.socket'    
```  
    
## sppListen    
创建一个服务端监听Socket。  
 **调用形式：**     
    
- sppListen(name: string, options: SppOptions, callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 服务的名称。<br/> |  
| options | SppOptions | true | spp监听配置参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参，服务端Socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let serverNumber = -1;  
function serverSocket(code: BusinessError, number: number) {  
  console.log('bluetooth error code: ' + code.code);  
  if (code.code == 0) {  
    console.log('bluetooth serverSocket Number: ' + number);  
    serverNumber = number;  
  }  
}  
  
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};  
try {  
    socket.sppListen('server1', sppOption, serverSocket);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## sppAccept    
服务端监听socket等待客户端连接。  
 **调用形式：**     
    
- sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverSocket | number | true | 服务端监听socket等待客户端连接。服务端socket的id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参，客户端socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let serverNumber = -1;  
function serverSocket(code: BusinessError, number: number) {  
  console.log('bluetooth error code: ' + code.code);  
  if (code.code == 0) {  
    console.log('bluetooth serverSocket Number: ' + number);  
    serverNumber = number;  
  }  
}  
let clientNumber = -1;  
function acceptClientSocket(code: BusinessError, number: number) {  
  console.log('bluetooth error code: ' + code.code);  
  if (code.code == 0) {  
    console.log('bluetooth clientSocket Number: ' + number);  
    // 获取的clientNumber用作服务端后续读/写操作socket的id。  
    clientNumber = number;  
  }  
}  
try {  
    socket.sppAccept(serverNumber, acceptClientSocket);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## sppConnect    
客户端向远端设备发起spp连接。  
 **调用形式：**     
    
- sppConnect(deviceId: string, options: SppOptions, callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| options | SppOptions | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参，客户端socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};  
try {  
    socket.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## sppCloseServerSocket    
关闭服务端监听Socket，入参socket由sppListen接口返回。  
 **调用形式：**     
- sppCloseServerSocket(socket: number): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket | number | true | 服务端监听socket的id。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let serverNumber = -1;  
function serverSocket(code: BusinessError, number: number) {  
  console.log('bluetooth error code: ' + code.code);  
  if (code.code == 0) {  
    console.log('bluetooth serverSocket Number: ' + number);  
    serverNumber = number;  
  }  
}  
try {  
    socket.sppCloseServerSocket(serverNumber);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## sppCloseClientSocket    
关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- sppCloseClientSocket(socket: number): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket | number | true | 客户端socket的id。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
try {  
    socket.sppCloseClientSocket(clientNumber);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## sppWrite    
通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。  
 **调用形式：**     
- sppWrite(clientSocket: number, data: ArrayBuffer): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| clientSocket | number | true | 客户端socket的id。<br/> |  
| data | ArrayBuffer | true | 写入的数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2901054 | IO error. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
let arrayBuffer = new ArrayBuffer(8);  
let data = new Uint8Array(arrayBuffer);  
data[0] = 123;  
try {  
    socket.sppWrite(clientNumber, arrayBuffer);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## on('sppRead')    
订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
    
- on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写"sppRead"字符串，表示spp读请求事件。<br/> |  
| clientSocket | number | true | 客户端socket的id。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参，读取到的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2901054 | IO error. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
function dataRead(dataBuffer: ArrayBuffer) {  
  let data = new Uint8Array(dataBuffer);  
  console.log('bluetooth data is: ' + data[0]);  
}  
try {  
    socket.on('sppRead', clientNumber, dataRead);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## off('sppRead')    
取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
    
- off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写"sppRead"字符串，表示spp读请求事件。<br/> |  
| clientSocket | number | true | 客户端Socket的id。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
try {  
    socket.off('sppRead', clientNumber);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## SppOptions    
描述spp的配置参数。  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uuid | string | false | true | spp单据的uuid。<br/> |  
| secure | boolean | false | true | 是否是安全通道。<br/> |  
| type | SppType | false | true | Spp链路类型。<br/> |  
    
## SppType    
枚举，Spp链路类型。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SPP_RFCOMM | 0 | 表示rfcomm链路类型。 |  
