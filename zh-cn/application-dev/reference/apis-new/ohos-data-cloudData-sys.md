# @ohos.data.cloudData    
端云协同提供结构化数据（RDB Store）端云同步的能力。即：云作为数据的中心节点，通过与云的数据同步，实现数据云备份、同帐号设备间的数据一致性。  
  
该模块提供以下端云协同相关的常用功能：  
  
- [Config](#config)：提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import cloudData from '@ohos.data.cloudData'    
```  
    
## ClearAction<sup>(10+)</sup>    
清除本地下载的云端数据的行为枚举。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CLEAR_CLOUD_INFO | 0 | 清除从云端下载的数据的云标识，相关数据作为本地数据保存。 |  
| CLEAR_CLOUD_DATA_AND_INFO | 1 | 清除从云端下载的数据，不包括本地已修改的云端数据。  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = 'test_id';  
let switches: Record<string, boolean> = { 'test_bundleName1': true, 'test_bundleName2': false };  
try {  
  cloudData.Config.enableCloud(account, switches, (err) => {  
    if (err === undefined) {  
      console.info('Succeeded in enabling cloud');  
    } else {  
      console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
    
## Config<sup>(10+)</sup>    
提供配置端云协同的方法，包括云同步打开、关闭、清理数据、数据变化通知。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config    
### enableCloud<sup>(10+)</sup>    
打开端云协同，使用callback异步回调。  
 **调用形式：**     
    
- static enableCloud(       accountId: string,       switches: { [bundleName: string]: boolean },       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- static enableCloud(accountId: string, switches: { [bundleName: string]: boolean }): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config  
 **需要权限：** ohos.permission.CLOUDDATA_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 具体打开的云帐号ID。  |  
| switches | { [bundleName: string]: boolean } | true | 各应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = 'test_id';  
let switches: Record<string, boolean> = { 'test_bundleName1': true, 'test_bundleName2': false };  
try {  
  cloudData.Config.enableCloud(account, switches).then(() => {  
    console.info('Succeeded in enabling cloud');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to enable.Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
    
### disableCloud<sup>(10+)</sup>    
关闭端云协同，使用callback异步回调。  
 **调用形式：**     
    
- static disableCloud(accountId: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- static disableCloud(accountId: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config  
 **需要权限：** ohos.permission.CLOUDDATA_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 具体打开的云帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = 'test_id';  
try {  
  cloudData.Config.disableCloud(account, (err) => {  
    if (err === undefined) {  
      console.info('Succeeded in disabling cloud');  
    } else {  
      console.error(`Failed to disableCloud. Code: ${err.code}, message: ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
    
### changeAppCloudSwitch<sup>(10+)</sup>    
修改单个应用端云协同开关，使用callback异步回调。  
 **调用形式：**     
    
- static changeAppCloudSwitch(       accountId: string,       bundleName: string,       status: boolean,       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- static changeAppCloudSwitch(accountId: string, bundleName: string, status: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config  
 **需要权限：** ohos.permission.CLOUDDATA_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 具体打开的云帐号ID。  |  
| bundleName | string | true | 应用名。 |  
| status | boolean | true | 应用的端云协同开关信息，true为打开该应用端云开关，false为关闭该应用端云开关。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = 'test_id';  
let bundleName = 'test_bundleName';  
try {  
  cloudData.Config.changeAppCloudSwitch(account, bundleName, true, (err) => {  
    if (err === undefined) {  
      console.info('Succeeded in changing App cloud switch');  
    } else {  
      console.error(`Failed to change App cloud switch. Code: ${err.code}, message: ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
    
### notifyDataChange<sup>(10+)</sup>    
通知云端的数据变更，使用callback异步回调。  
 **调用形式：**     
    
- static notifyDataChange(accountId: string, bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- static notifyDataChange(accountId: string, bundleName: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Server  
 **需要权限：** ohos.permission.CLOUDDATA_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 具体打开的云帐号ID。 |  
| bundleName | string | true | 应用名。           |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = 'test_id';  
let bundleName = 'test_bundleName';  
try {  
  cloudData.Config.notifyDataChange(account, bundleName, (err) => {  
    if (err === undefined) {  
      console.info('Succeeded in notifying the change of data');  
    } else {  
      console.error(`Failed to notify the change of data. Code: ${err.code}, message: ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
    
### clear<sup>(10+)</sup>    
清除本地下载的云端数据，使用callback异步回调。  
 **调用形式：**     
    
- static clear(       accountId: string,       appActions: { [bundleName: string]: ClearAction },       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- static clear(accountId: string, appActions: { [bundleName: string]: ClearAction }): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.CloudSync.Config  
 **需要权限：** ohos.permission.CLOUDDATA_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountId | string | true | 具体打开的云帐号ID。              |  
| appActions | { [bundleName: string]: ClearAction } | true | 要清除数据的应用信息及清除规则。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let account = "test_id";  
type dataType = Record<string, cloudData.ClearAction>  
let appActions: dataType = {  
  'test_bundleName1': cloudData.ClearAction.CLEAR_CLOUD_INFO,  
  'test_bundleName2': cloudData.ClearAction.CLEAR_CLOUD_DATA_AND_INFO  
};  
try {  
  cloudData.Config.clear(account, appActions, (err) => {  
    if (err === undefined) {  
      console.info('Succeeding in clearing cloud data');  
    } else {  
      console.error(`Failed to clear cloud data. Code: ${err.code}, message: ${err.message}`);  
    }  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);  
}  
    
```    
  
