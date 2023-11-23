# @ohos.bluetooth.connection    
connection模块提供了对蓝牙操作和管理的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import connection from '@ohos.bluetooth.connection'    
```  
    
## pairCredibleDevice    
向可信的远端设备发起蓝牙配对。通过非蓝牙扫描的方式(例如NFC等)获取到外设的地址，可以通过该接口发起配对。  
 **调用形式：**     
    
- pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback\<void>): void    
起始版本： 10    
- pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | <table><tbody><tr><td>表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。</td></tr><tr></tr></tbody></table> |  
| transport | BluetoothTransport | true | <table><tbody><tr><td>表示设备类型，例如传统蓝牙设备或低功耗蓝牙设备。</td></tr><tr></tr></tbody></table> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当发起配对成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 返回promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    connection.pairCredibleDevice('68:13:24:79:4C:8C', connection.BluetoothTransport  
        .TRANSPORT_BR_EDR, (err: BusinessError) => {  
        if (err) {  
            console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
            return;  
        }  
        console.info('pairCredibleDevice, err: ' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## cancelPairedDevice    
删除配对的远程设备。  
 **调用形式：**     
    
- cancelPairedDevice(deviceId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- cancelPairedDevice(deviceId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当删除远程配对设备成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 返回promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
## cancelPairingDevice    
删除正在配对中的远程设备。  
 **调用形式：**     
    
- cancelPairingDevice(deviceId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- cancelPairingDevice(deviceId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当删除远程配对设备成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 返回promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    connection.cancelPairingDevice('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## getLocalProfileUuids    
获取本地设备的profile UUID。  
 **调用形式：**     
    
- getLocalProfileUuids(callback: AsyncCallback\<Array\<ProfileUuids>>): void    
起始版本： 10    
- getLocalProfileUuids(): Promise\<Array\<ProfileUuids>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取UUID成功，err为undefined，否则为错误对象。 |  
| Promise<Array<ProfileUuids>> | 返回promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    connection.getLocalProfileUuids('XX:XX:XX:XX:XX:XX', (err: BusinessError, data: Array<connection.ProfileUuids>) => {  
        console.info('getLocalProfileUuids, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));  
    });  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## getRemoteProfileUuids    
获取对端蓝牙设备支持的Profile UUID。  
 **调用形式：**     
    
- getRemoteProfileUuids(deviceId: string, callback: AsyncCallback\<Array\<ProfileUuids>>): void    
起始版本： 10    
- getRemoteProfileUuids(deviceId: string): Promise\<Array\<ProfileUuids>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取UUID成功，err为undefined，否则为错误对象。 |  
| Promise<Array<ProfileUuids>> | 返回promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    connection.getRemoteProfileUuids('XX:XX:XX:XX:XX:XX', (err: BusinessError, data: Array<connection.ProfileUuids>) => {  
        console.info('getRemoteProfileUuids, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));  
    });  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## PinRequiredParam    
描述配对请求参数。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pinType | PinType | false | true | 表示要配对的设备类型。<br/>此接口为系统接口。<br/> |  
    
## PinType    
枚举，蓝牙配对类型。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PIN_TYPE_ENTER_PIN_CODE | 0 | 用户需要输入对端设备上显示的PIN码。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_ENTER_PASSKEY | 1 | 用户需要输入对端设备上显示的PASSKEY。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_CONFIRM_PASSKEY | 2 | 用户需要确认本地设备上显示的PASSKEY。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_NO_PASSKEY_CONSENT | 3 | 无PASSKEY，用户需要接受或拒绝配对请求。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_NOTIFY_PASSKEY | 4 | 本地设备显示PASSKEY，用户需要在对端设备上输入该PASSKEY。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_DISPLAY_PIN_CODE | 5 | bluetooth 2.0设备，用户需要输入对端设备上显示的PIN码。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_OOB_CONSENT | 6 | 用户需要接受或拒绝OOB配对请求。<br/>此接口为系统接口。<br/> |  
| PIN_TYPE_PIN_16_DIGITS | 7 | 用户需要输入对端设备上显示的16位PIN码。<br/>此接口为系统接口。 |  
