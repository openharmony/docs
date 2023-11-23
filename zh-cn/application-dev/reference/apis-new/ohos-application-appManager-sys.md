# @ohos.application.appManager    
appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appManager from '@ohos.application.appManager'    
```  
    
## registerApplicationStateObserver<sup>(deprecated)</sup>    
注册全部应用程序状态观测器。  
 **调用形式：**     
- registerApplicationStateObserver(observer: ApplicationStateObserver): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#on。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| observer<sup>(deprecated)</sup> | ApplicationStateObserver | true | 返回观察者的数字代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
 **示例代码：**   
```ts    
 import appManager from '@ohos.application.appManager';  
 const observerCode = appManager.registerApplicationStateObserver({  onForegroundApplicationChanged(appStateData) {    console.log('------------ onForegroundApplicationChanged -----------', appStateData);  },  onAbilityStateChanged(abilityStateData) {    console.log('------------ onAbilityStateChanged -----------', abilityStateData);  },  onProcessCreated(processData) {    console.log('------------ onProcessCreated -----------', processData);  },  onProcessDied(processData) {    console.log('------------ onProcessDied -----------', processData);  },  onProcessStateChanged(processData) {    console.log('------------ onProcessStateChanged -----------', processData);  } }); console.log('-------- observerCode: ---------', observerCode);    
```    
  
    
## unregisterApplicationStateObserver<sup>(deprecated)</sup>    
取消注册应用程序状态观测器。  
 **调用形式：**     
- unregisterApplicationStateObserver(observerId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| observerId<sup>(deprecated)</sup> | number | true | 表示观察者的编号代码。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示指定的回调方法。 |  
    
 **示例代码：**   
示例 （callback）：  
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  let observerId = 100;  
  
  function unregisterApplicationStateObserverCallback(err: BusinessError) {  
    if (err) {  
        console.error('------------ unregisterApplicationStateObserverCallback ------------', err);  
    }  
  }  
  appManager.unregisterApplicationStateObserver(observerId, unregisterApplicationStateObserverCallback);  
    
```    
  
    
## unregisterApplicationStateObserver<sup>(deprecated)</sup>    
取消注册应用程序状态观测器。  
 **调用形式：**     
- unregisterApplicationStateObserver(observerId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| observerId<sup>(deprecated)</sup> | number | true | 表示观察者的编号代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回执行结果。 |  
    
 **示例代码：**   
示例 （promise）：  
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  let observerId = 100;  
  
  appManager.unregisterApplicationStateObserver(observerId)  
  .then((data) => {  
      console.log('----------- unregisterApplicationStateObserver success ----------', data);  
  })  
  .catch((err: BusinessError) => {  
      console.error('----------- unregisterApplicationStateObserver fail ----------', err);  
  });  
    
```    
  
    
## getForegroundApplications<sup>(deprecated)</sup>    
获取所有当前处于前台的应用信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。  
 **调用形式：**     
- getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#getForegroundApplications。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AppStateData>> | true | callback形式返回所有当前处于前台的应用信息。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  
  appManager.getForegroundApplications((err, data) => {  
    if (err) {  
        console.error('--------- getForegroundApplicationsCallback fail ---------', err);  
    } else {  
        console.log('--------- getForegroundApplicationsCallback success ---------', data);  
    }  
  });  
    
```    
  
    
## getForegroundApplications<sup>(deprecated)</sup>    
获取所有当前处于前台的应用信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。  
 **调用形式：**     
- getForegroundApplications(): Promise\<Array\<AppStateData>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#getForegroundApplications。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<AppStateData>> | Promise形式返回所有当前处于前台的应用信息。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  appManager.getForegroundApplications()  
  .then((data) => {  
      console.log('--------- getForegroundApplications success -------', data);  
  })  
  .catch((err: BusinessError) => {  
      console.error('--------- getForegroundApplications fail -------', err);  
  });  
    
```    
  
    
## killProcessWithAccount<sup>(deprecated)</sup>    
切断account进程（Promise形式）。  
 **调用形式：**     
- killProcessWithAccount(bundleName: string, accountId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#killProcessWithAccount。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| accountId<sup>(deprecated)</sup> | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回执行结果。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
let accountId = 0;  
function killProcessWithAccountCallback(err: BusinessError, data: void) {  
   if (err) {  
       console.error('------------- killProcessWithAccountCallback fail, err: --------------', err);  
   } else {  
       console.log('------------- killProcessWithAccountCallback success, data: --------------', data);  
   }  
}  
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);  
    
```    
  
    
## killProcessWithAccount<sup>(deprecated)</sup>    
通过Bundle名称终止进程。  
 **调用形式：**     
- killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#killProcessWithAccount。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 表示Bundle名称。 |  
| accountId<sup>(deprecated)</sup> | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 切断account进程的回调函数。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
let accountId = 0;  
function killProcessWithAccountCallback(err: BusinessError, data: void) {  
   if (err) {  
       console.error('------------- killProcessWithAccountCallback fail, err: --------------', err);  
   } else {  
       console.log('------------- killProcessWithAccountCallback success, data: --------------', data);  
   }  
}  
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);  
    
```    
  
    
## killProcessesByBundleName<sup>(deprecated)</sup>    
通过Bundle名称终止进程。  
 **调用形式：**     
- killProcessesByBundleName(bundleName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#killProcessesByBundleName。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 表示Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回执行结果。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  let bundleName = 'com.example.myapplication';  
  appManager.killProcessesByBundleName(bundleName)  
    .then((data) => {  
        console.log('------------ killProcessesByBundleName success ------------', data);  
    })  
    .catch((err: BusinessError) => {  
        console.error('------------ killProcessesByBundleName fail ------------', err);  
    });  
    
```    
  
    
## killProcessesByBundleName<sup>(deprecated)</sup>  
 **调用形式：**     
- killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>)  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#killProcessesByBundleName。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 表示Bundle名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示指定的回调方法。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
import { BusinessError } from '@ohos.base';  
  
  let bundleName = 'bundleName';  
  function killProcessesByBundleNameCallback(err: BusinessError, data: void) {  
    if (err) {  
        console.error('------------- killProcessesByBundleNameCallback fail, err: --------------', err);  
    } else {  
        console.log('------------- killProcessesByBundleNameCallback success, data: --------------', data);  
    }  
  }  
  appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);  
    
```    
  
    
## clearUpApplicationData<sup>(deprecated)</sup>    
通过Bundle名称清除应用数据。  
 **调用形式：**     
- clearUpApplicationData(bundleName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#clearUpApplicationData。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_APPLICATION_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 表示Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 返回执行结果。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  let bundleName = 'com.example.myapplication';  
  appManager.killProcessesByBundleName(bundleName)  
    .then((data) => {  
        console.log('------------ killProcessesByBundleName success ------------', data);  
    })  
    .catch((err: BusinessError) => {  
        console.error('------------ killProcessesByBundleName fail ------------', err);  
    });  
    
```    
  
    
## clearUpApplicationData<sup>(deprecated)</sup>    
通过Bundle名称终止进程。  
 **调用形式：**     
- clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>)  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#clearUpApplicationData。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_APPLICATION_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 表示Bundle名称 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 表示指定的回调方法。<br/> |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
import { BusinessError } from '@ohos.base';  
  
  let bundleName = 'bundleName';  
  function killProcessesByBundleNameCallback(err: BusinessError, data: void) {  
    if (err) {  
        console.error('------------- killProcessesByBundleNameCallback fail, err: --------------', err);  
    } else {  
        console.log('------------- killProcessesByBundleNameCallback success, data: --------------', data);  
    }  
  }  
  appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);  
    
```    
  
