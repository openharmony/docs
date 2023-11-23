# @ohos.continuation.continuationManager    
continuationManager模块提供了流转/协同入口管理服务能力，包括连接/取消流转管理服务，注册/解注册设备连接变化监听，拉起设备选择模块，更新连接状态。本模块接口用于拉起系统中的设备选择模块，由于该模块功能暂不完备，因此流转能力整体暂不支持用于应用开发。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import continuationManager from '@ohos.continuation.continuationManager'    
```  
    
## on('deviceSelected')<sup>(9+)</sup>    
异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。  
 **调用形式：**     
    
- on(type: 'deviceSelected', token: number, callback: Callback\<Array\<ContinuationResult>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。<br/> |  
| token | number | true | 注册后的token。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 当用户从设备选择模块中选择设备时调用，返回设备ID、设备类型和设备名称供开发者使用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
| 16600004 | The specified callback has been registered. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
let token: number = 1;  
try {  
  continuationManager.on("deviceSelected", token, (data) => {  
    console.info('onDeviceSelected len: ' + data.length);  
    for (let i = 0; i < data.length; i++) {  
      console.info('onDeviceSelected deviceId: ' + JSON.stringify(data[i].id));  
      console.info('onDeviceSelected deviceType: ' + JSON.stringify(data[i].type));  
      console.info('onDeviceSelected deviceName: ' + JSON.stringify(data[i].name));  
    }  
  });  
} catch (err) {  
  console.error('on failed, cause: ' + JSON.stringify(err));  
}  
    
```    
  
    
## off('deviceSelected')<sup>(9+)</sup>    
取消监听设备连接状态。  
 **调用形式：**     
- off(type: 'deviceSelected', token: number): void  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听的事件类型，固定值"deviceSelected"。<br/> |  
| token | number | true | 注册后的token。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
| 16600004 | The specified callback has been registered. |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
let token: number = 1;  
try {  
  continuationManager.off("deviceSelected", token);  
} catch (err) {  
  console.error('off failed, cause: ' + JSON.stringify(err));  
}  
    
```    
  
    
## on('deviceUnselected')<sup>(9+)</sup>    
取消监听设备断开状态。  
 **调用形式：**     
    
- on(type: 'deviceUnselected', token: number, callback: Callback\<Array\<ContinuationResult>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听的事件类型，固定值"deviceUnselected"。<br/> |  
| token | number | true | 注册后的token。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 当用户从设备选择模块中断开设备时调用，返回设备ID、设备类型和设备名称供开发者使用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
| 16600004 | The specified callback has been registered. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
let token: number = 1;  
try {  
  continuationManager.on("deviceUnselected", token, (data) => {  
    console.info('onDeviceUnselected len: ' + data.length);  
    for (let i = 0; i < data.length; i++) {  
      console.info('onDeviceUnselected deviceId: ' + JSON.stringify(data[i].id));  
      console.info('onDeviceUnselected deviceType: ' + JSON.stringify(data[i].type));  
      console.info('onDeviceUnselected deviceName: ' + JSON.stringify(data[i].name));  
    }  
    console.info('onDeviceUnselected finished.');  
  });  
} catch (err) {  
  console.error('on failed, cause: ' + JSON.stringify(err));  
}  
    
```    
  
    
## off('deviceUnselected')<sup>(9+)</sup>    
取消监听设备连接状态。  
 **调用形式：**     
- off(type: 'deviceUnselected', token: number): void  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听的事件类型，固定值"deviceSelected"。<br/> |  
| token | number | true | 注册后的token。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
| 16600004 | The specified callback has been registered. |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
let token: number = 1;  
try {  
  continuationManager.off("deviceUnselected", token);  
} catch (err) {  
  console.error('off failed, cause: ' + JSON.stringify(err));  
}  
    
```    
  
    
## on('deviceConnect')<sup>(deprecated)</sup>    
异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。  
  
 **调用形式：**     
- on(type: 'deviceConnect', callback: Callback\<ContinuationResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#on。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听的事件类型，固定值"deviceConnect"。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<ContinuationResult> | true | 当用户从设备选择模块中选择设备时调用，返回设备ID、设备类型和设备名称供开发者使用。<br/> |  
    
## off('deviceConnect')<sup>(deprecated)</sup>    
异步方法，取消监听设备连接状态，使用Callback形式返回连接的设备信息。  
  
 **调用形式：**     
- off(type: 'deviceConnect', callback?: Callback\<ContinuationResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#off。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 取消监听的事件类型，固定值"deviceConnect"。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<ContinuationResult> | false | 当用户从设备选择模块中选择设备时调用，返回设备ID、设备类型和设备名称供开发者使用。<br/> |  
    
## on('deviceDisconnect')<sup>(deprecated)</sup>    
异步方法，监听设备断开状态，使用Callback形式返回断开的设备信息。  
  
 **调用形式：**     
- on(type: 'deviceDisconnect', callback: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#on。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听的事件类型，固定值"deviceDisconnect"。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<string> | true | 当用户从设备选择模块中断开设备时调用，返回设备ID供开发者使用。<br/> |  
    
## off('deviceDisconnect')<sup>(deprecated)</sup>    
异步方法，取消监听设备断开状态，使用Callback形式返回连接的设备信息。  
 **调用形式：**     
- off(type: 'deviceDisconnect', callback?: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#off。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 取消监听的事件类型，固定值"deviceDisconnect"。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<string> | false | 当用户从设备选择模块中断开设备时调用，返回设备ID供开发者使用。 |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
continuationManager.on("deviceDisconnect", (data) => {  
  console.info('onDeviceDisconnect deviceId: ' + JSON.stringify(data));  
});    
```    
  
    
## register<sup>(deprecated)</sup>    
注册流转管理服务，并获取对应的注册token，无过滤条件，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- register(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#registerContinuation。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | AsyncCallback形式返回流转管理服务连接后生成的token。<br/> |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager'  
  let token: number = -1;  continuationManager.register((err, data) => {    if (err.code != 0) {      console.error('register failed, cause: ' + JSON.stringify(err));      return;    }    console.info('register finished, ' + JSON.stringify(data));    token = data;  });    
```    
  
    
## register<sup>(deprecated)</sup>    
连接流转管理服务，并获取对应的注册token，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- register(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#registerContinuation。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ContinuationExtraParams | true | 过滤可选择设备列表的额外参数。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | AsyncCallback形式返回流转管理服务连接后生成的token。<br/> |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager'  
  let token: number = -1;  continuationManager.register(    {      deviceType: ["00E"]    },    (err, data) => {      if (err.code != 0) {        console.error('register failed, cause: ' + JSON.stringify(err));        return;      }      console.info('register finished, ' + JSON.stringify(data));      token = data;  });    
```    
  
    
## register<sup>(deprecated)</sup>    
连接流转管理服务，并获取对应的注册token，使用Promise方式作为异步方法。  
 **调用形式：**     
- register(options?: ContinuationExtraParams): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#registerContinuation。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ContinuationExtraParams | false | 过滤可选择设备列表的额外参数，该参数可缺省<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise形式返回流转管理服务连接后生成的token。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager'  
  import { BusinessError } from '@ohos.base';  
    
  let token: number = -1;  
  continuationManager.register(  
    { deviceType: ["00E"] }).then((data) => {  
      console.info('register finished, ' + JSON.stringify(data));  
      token = data;  
    }).catch((err: BusinessError) => {  
      console.error('register failed, cause: ' + JSON.stringify(err));  
  });  
    
```    
  
    
## unregister<sup>(deprecated)</sup>    
解注册流转管理服务，传入注册时获取的token进行解注册，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- unregister(token: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#unregisterContinuation。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | AsyncCallback形式返回接口调用结果。<br/> |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  let token: number = 1;  continuationManager.unregister(token, (err, data) => {    if (err.code != 0) {      console.error('unregister failed, cause: ' + JSON.stringify(err));      return;    }    console.info('unregister finished, ' + JSON.stringify(data));  });    
```    
  
    
## unregister<sup>(deprecated)</sup>    
解注册流转管理服务，传入注册时获取的token进行解注册，使用Promise方式作为异步方法。  
 **调用形式：**     
- unregister(token: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#unregisterContinuation。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
  
  let token: number = 1;  
  continuationManager.unregister(token)  
    .then((data) => {  
      console.info('unregister finished, ' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.error('unregister failed, cause: ' + JSON.stringify(err));  
  });  
    
```    
  
    
## updateConnectStatus<sup>(deprecated)</sup>    
通知设备选择模块，更新当前的连接状态，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- updateConnectStatus(     token: number,     deviceId: string,     status: DeviceConnectState,     callback: AsyncCallback\<void>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#updateContinuationState。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。 |  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID。 |  
| status<sup>(deprecated)</sup> | DeviceConnectState | true | 设备连接状态。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | AsyncCallback形式返回接口调用结果。 |  
    
 **示例代码：**   
```ts    
 import continuationManager from '@ohos.continuation.continuationManager';  
  let token: number = -1;  let deviceId: string = "test deviceId";  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err, data) => {    if (err.code != 0) {      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));      return;    }    console.info('updateConnectStatus finished, ' + JSON.stringify(data));  });    
```    
  
    
## updateConnectStatus<sup>(deprecated)</sup>    
通知设备选择模块，更新当前的连接状态，使用Promise方式作为异步方法。  
 **调用形式：**     
- updateConnectStatus(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#updateContinuationState。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID。<br/> |  
| status<sup>(deprecated)</sup> | DeviceConnectState | true | 设备连接状态。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
 **示例代码：**   
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
  
  let token: number = 1;  
  let deviceId: string = "test deviceId";  
  continuationManager.updateConnectStatus(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)  
    .then((data) => {  
      console.info('updateConnectStatus finished, ' + JSON.stringify(data));  
    })  
    .catch((err: BusinessError) => {  
      console.error('updateConnectStatus failed, cause: ' + JSON.stringify(err));  
  });  
    
```    
  
    
## startDeviceManager<sup>(deprecated)</sup>    
拉起设备选择模块，可显示组网内可选择设备列表信息，无过滤条件，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- startDeviceManager(token: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#startContinuationDeviceManager。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | AsyncCallback形式返回接口调用结果。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  let token: number = 1;  continuationManager.startDeviceManager(token, (err, data) => {    if (err.code != 0) {      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));      return;    }    console.info('startDeviceManager finished, ' + JSON.stringify(data));  });    
```    
  
    
## startDeviceManager<sup>(deprecated)</sup>    
拉起设备选择模块，可显示组网内可选择设备列表信息，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
- startDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#startContinuationDeviceManager。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
| options<sup>(deprecated)</sup> | ContinuationExtraParams | true | 过滤可选择设备列表的额外参数。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | AsyncCallback形式返回接口调用结果。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
  
  let token: number = -1;  
  continuationManager.startDeviceManager(  
    token,  
    {  
      deviceType: ["00E"]  
    }).then((data) => {  
      console.info('startDeviceManager finished, ' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));  
  });  
    
```    
  
    
## startDeviceManager<sup>(deprecated)</sup>    
拉起设备选择模块，可显示组网内可选择设备列表信息，使用Promise方式作为异步方法。  
 **调用形式：**     
- startDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.continuation.continuationManager/continuationManager#startContinuationDeviceManager。  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | number | true | 注册后的token。<br/> |  
| options<sup>(deprecated)</sup> | ContinuationExtraParams | false | 过滤可选择设备列表的额外参数，该参数可缺省<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
 **示例代码：**   
示例（promise）：  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
  
  let token: number = -1;  
  continuationManager.startDeviceManager(  
    token,  
    {  
      deviceType: ["00E"]  
    }).then((data) => {  
      console.info('startDeviceManager finished, ' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.error('startDeviceManager failed, cause: ' + JSON.stringify(err));  
  });  
    
```    
  
    
## registerContinuation<sup>(9+)</sup>    
注册流转管理服务，并获取对应的注册token，无过滤条件，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
    
- registerContinuation(callback: AsyncCallback\<number>): void    
起始版本： 9    
- registerContinuation(options: ContinuationExtraParams, callback: AsyncCallback\<number>): void    
起始版本： 9    
- registerContinuation(options?: ContinuationExtraParams): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ContinuationExtraParams | true | 过滤可选择设备列表的额外参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | AsyncCallback形式返回流转管理服务连接后生成的token。 |  
| Promise<number> | Promise形式返回流转管理服务连接后生成的token。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600003 | The number of token registration times has reached the upper limit. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager'  
    
  let token: number = -1;  
  try {  
    continuationManager.registerContinuation((err, data) => {  
      if (err.code != 0) {  
        console.error('registerContinuation failed, cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('registerContinuation finished, ' + JSON.stringify(data));  
      token = data;  
    });  
  } catch (err) {  
    console.error('registerContinuation failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```null    
<span style="font-size: 14px; letter-spacing: 0px;">import continuationManager from '@ohos.continuation.continuationManager';</span>  
  let token: number = -1;  
  try {  
    continuationManager.registerContinuation(  
      {  
        deviceType: ["00E"]  
      },  
      (err, data) => {  
        if (err.code != 0) {  
          console.error('registerContinuation failed, cause: ' + JSON.stringify(err));  
          return;  
        }  
        console.info('registerContinuation finished, ' + JSON.stringify(data));  
        token = data;  
    });  
  } catch (err) {  
    console.error('registerContinuation failed, cause: ' + JSON.stringify(err));  
  }    
```    
  
    
## unregisterContinuation<sup>(9+)</sup>    
解注册流转管理服务，传入注册时获取的token进行解注册，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
    
- unregisterContinuation(token: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- unregisterContinuation(token: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | number | true | 注册后的token。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | AsyncCallback形式返回接口调用结果。 |  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
：<span style="font-size: 14px; letter-spacing: 0px;">import continuationManager from '@ohos.continuation.continuationManager';</span>  import { BusinessError } from '@ohos.base';  
  
  let token: number = 1;  
  try {  
    continuationManager.unregisterContinuation(token, (err, data) => {  
      if (err.code != 0) {  
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('unregisterContinuation finished, ' + JSON.stringify(data));  
    });  
  } catch (err) {  
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
  }    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
    
  let token: number = -1;  
  try {  
    continuationManager.unregisterContinuation(token).then((data) => {  
        console.info('unregisterContinuation finished, ' + JSON.stringify(data));  
      }).catch((err: BusinessError) => {  
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
    });  
  } catch (err) {  
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
## updateContinuationState<sup>(9+)</sup>    
通知设备选择模块，更新当前的连接状态，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
    
- updateContinuationState(     token: number,     deviceId: string,     status: DeviceConnectState,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | number | true | 注册后的token。<br/> |  
| deviceId | string | true | 设备ID。<br/> |  
| status | DeviceConnectState | true | 设备连接状态。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | AsyncCallback形式返回接口调用结果。 |  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
  
  let token: number = 1;  
  try {  
    continuationManager.unregisterContinuation(token, (err, data) => {  
      if (err.code != 0) {  
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('unregisterContinuation finished, ' + JSON.stringify(data));  
    });  
  } catch (err) {  
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  import { BusinessError } from '@ohos.base';  
    
  let token: number = -1;  
  try {  
    continuationManager.unregisterContinuation(token).then((data) => {  
        console.info('unregisterContinuation finished, ' + JSON.stringify(data));  
      }).catch((err: BusinessError) => {  
        console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
    });  
  } catch (err) {  
    console.error('unregisterContinuation failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
## startContinuationDeviceManager<sup>(9+)</sup>    
拉起设备选择模块，可显示组网内可选择设备列表信息，无过滤条件，使用AsyncCallback方式作为异步方法。  
 **调用形式：**     
    
- startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startContinuationDeviceManager(     token: number,     options: ContinuationExtraParams,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | number | true | 注册后的token。<br/> |  
| options | ContinuationExtraParams | true | 过滤可选择设备列表的额外参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | AsyncCallback形式返回接口调用结果。 |  
| Promise<void> | Promise形式返回接口调用结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16600001 | The system ability works abnormally. |  
| 16600002 | The specified token or callback is not registered. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import continuationManager from '@ohos.continuation.continuationManager';  
  
  let token: number = -1;  
  try {  
    continuationManager.startContinuationDeviceManager(token, (err, data) => {  
      if (err.code != 0) {  
        console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('startContinuationDeviceManager finished, ' + JSON.stringify(data));  
    });  
  } catch (err) {  
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
```ts  
  import continuationManager from '@ohos.continuation.continuationManager';  
  
  let token: number = -1;  
  try {  
    continuationManager.startContinuationDeviceManager(  
      token,  
      {  
        deviceType: ["00E"]  
      },  
      (err, data) => {  
        if (err.code != 0) {  
          console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));  
          return;  
        }  
        console.info('startContinuationDeviceManager finished, ' + JSON.stringify(data));  
    });  
  } catch (err) {  
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));  
  }  
    
```    
  
    
## DeviceConnectState    
设备连接状态。    
    
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IDLE | 0 | 设备连接初始状态。 |  
| CONNECTING | 1 | 设备连接中状态。 |  
| CONNECTED | 2 | 设备已连接状态。 |  
| DISCONNECTING | 3 | 设备断开连接状态。 |  
    
## ContinuationMode    
设备选择模块连接模式。    
    
 **系统能力:**  SystemCapability.Ability.DistributedAbilityManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COLLABORATION_SINGLE | 0 | 设备选择模块单选模式。 |  
| COLLABORATION_MULTIPLE | 1 | 设备选择模块多选模式。 |  
