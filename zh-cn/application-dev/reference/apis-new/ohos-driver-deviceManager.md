# @ohos.driver.deviceManager    
本模块主要提供管理外部设备的相关功能，包括查询设备列表、绑定设备和解除绑定设备。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceManager from '@ohos.driver.deviceManager'    
```  
    
## queryDevices    
获取接入主设备的外部设备列表。如果没有设备接入，那么将会返回一个空的列表。  
 **调用形式：**     
- queryDevices(busType?: number): Array\<Readonly\<Device>>  
  
 **系统能力:**  SystemCapability.Driver.ExternalDevice  
 **需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| busType | number | false | 设备总线类型，不填则查找所有类型设备  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<Readonly<Device>> | 设备信息列表。 | |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | The parameter check failed. |  
| 22900001 | ExternalDeviceManager service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from "@ohos.driver.deviceManager";  
  
  
try {  
  let devices : Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);  
  for (let item of devices) {  
    let device : deviceManager.USBDevice = item as deviceManager.USBDevice;  
    console.info(`Device id is ${device.deviceId}`)  
  }  
} catch (error) {  
  console.error(`Failed to query device. Code is ${error.code}, message is ${error.message}`);  
}  
    
```    
  
    
## bindDevice    
根据queryDevices()返回的设备信息绑定设备。  
 **调用形式：**     
    
- bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>,    callback: AsyncCallback\<{deviceId: number, remote: rpc.IRemoteObject}>): void    
起始版本： 10    
- bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<{deviceId: number,    remote: rpc.IRemoteObject}>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Driver.ExternalDevice  
 **需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 设备ID，通过queryDevices获得  |  
| onDisconnect | AsyncCallback<number> | true | 绑定设备断开的回调            |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 绑定设备的回调，返回绑定设备的通信对象 |  
| Promise<{deviceId: number,  
    remote: rpc.IRemoteObject}> | Promise对象，返回设备ID和IRemoteObject对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | The parameter check failed. |  
| 22900001 | ExternalDeviceManager service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from "@ohos.driver.deviceManager";  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参  
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {  
    console.error(`Device is disconnected`);  
  }, (error : BusinessError, data: {  
      deviceId : number;  
      remote : rpc.IRemoteObject;  
  }) => {  
    if (error) {  
      console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);  
      return;  
    }  
    console.info(`bindDevice success`);  
  });  
} catch (error) {  
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import deviceManager from "@ohos.driver.deviceManager";  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参  
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {  
    console.error(`Device is disconnected`);  
  }).then(data => {  
    console.info(`bindDevice success, Device_Id is ${data.deviceId}.  
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);  
  }, (error: BusinessError) => {  
    console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);  
  });  
} catch (error) {  
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);  
}  
    
```    
  
    
## unbindDevice    
解除设备绑定。  
 **调用形式：**     
    
- unbindDevice(deviceId: number, callback: AsyncCallback\<number>): void    
起始版本： 10    
- unbindDevice(deviceId: number): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Driver.ExternalDevice  
 **需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | number | true | 设备ID，通过queryDevices获得。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 解绑完成的回调。 |  
| Promise<number> | Promise对象，返回设备ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | The parameter check failed. |  
| 22900001 | ExternalDeviceManager service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from "@ohos.driver.deviceManager";  
  
try {  
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参  
  deviceManager.unbindDevice(12345678, (error : BusinessError, data : number) => {  
    if (error) {  
      console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);  
      return;  
    }  
    console.info(`unbindDevice success`);  
  });  
} catch (error) {  
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import deviceManager from "@ohos.driver.deviceManager";  
import { BusinessError } from '@ohos.base';  
  
try {  
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参  
  deviceManager.unbindDevice(12345678).then((data : number) => {  
    console.info(`unbindDevice success, Device_Id is ${data}.`);  
  }, (error : BusinessError) => {  
    console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);  
  });  
} catch (error) {  
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);  
}  
    
```    
  
    
## BusType    
设备总线类型。    
    
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USB | 1 | USB总线类型。  |  
    
## Device    
外设信息。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
### 属性    
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| busType | BusType | false | true | 总线类型。  |  
| deviceId | number | false | true | 设备ID。    |  
| description | string | false | true | 设备描述。  |  
    
## USBDevice    
USB设备信息。  
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
### 属性    
 **系统能力:**  SystemCapability.Driver.ExternalDevice    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| vendorId | number | false | true | USB设备Vendor ID。   |  
| productId | number | false | true | USB设备Product ID。 |  
