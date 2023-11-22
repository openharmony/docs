# @ohos.app.ability.appManager    
appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appManager from '@ohos.app.ability.appManager'    
```  
    
## ApplicationState    
应用状态，该类型为枚举，可配合[AbilityStateData](js-apis-inner-application-appStateData.md)返回相应的应用状态。  
    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_CREATE | 0 | 当应用在创建中的时候处于的状态。 |  
| STATE_FOREGROUND | 1 | 当应用切换到前台的时候处于的状态。 |  
| STATE_ACTIVE | 2 | 当应用在获焦的时候处于的状态。 |  
| STATE_BACKGROUND | 3 | 当应用处于后台不可见时处于的状态。    |  
| STATE_DESTROY | 4 | 当应用在销毁的时候处于的状态。 |  
    
## on('applicationState')    
取消注册应用程序状态观测器。  
 **调用形式：**     
- on(type: 'applicationState', observer: ApplicationStateObserver): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 调用接口类型，固定填'applicationState'字符串。 |  
| observer | ApplicationStateObserver | true | 表示观测器的编号代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 已注册观测器的数字代码，可用于off接口注销观测器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let applicationStateObserver: appManager.ApplicationStateObserver = {  
    onForegroundApplicationChanged(appStateData) {  
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);  
    },  
    onAbilityStateChanged(abilityStateData) {  
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  
    },  
    onProcessCreated(processData) {  
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);  
    },  
    onProcessDied(processData) {  
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);  
    },  
    onProcessStateChanged(processData) {  
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);  
    }  
};  
try {  
    const observerId = appManager.on('applicationState', applicationStateObserver);  
    console.log(`[appManager] observerCode: ${observerId}`);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## on('applicationState')    
取消注册应用程序状态观测器。  
 **调用形式：**     
- on(type: 'applicationState', observer: ApplicationStateObserver, bundleNameList: Array\<string>): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 调用接口类型，固定填'applicationState'字符串。 |  
| observer | ApplicationStateObserver | true | 表示观测器的编号代码。 |  
| bundleNameList | Array<string> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 已注册观测器的数字代码，可用于off接口取消注册观测器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let applicationStateObserver: appManager.ApplicationStateObserver = {  
    onForegroundApplicationChanged(appStateData) {  
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);  
    },  
    onAbilityStateChanged(abilityStateData) {  
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  
    },  
    onProcessCreated(processData) {  
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);  
    },  
    onProcessDied(processData) {  
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);  
    },  
    onProcessStateChanged(processData) {  
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);  
    }  
};  
let bundleNameList = ['bundleName1', 'bundleName2'];  
try {  
    const observerId = appManager.on('applicationState', applicationStateObserver, bundleNameList);  
    console.log(`[appManager] observerCode: ${observerId}`);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## off('applicationState')    
取消注册应用程序状态观测器。  
 **调用形式：**     
    
- off(type: 'applicationState', observerId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- off(type: 'applicationState', observerId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.RUNNING_STATE_OBSERVER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 调用接口类型，固定填'applicationState'字符串。 |  
| observerId | number | true | 表示观测器的编号代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | 以Promise方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let observerId = 0;  
  
// 1.注册应用状态监听器  
let applicationStateObserver: appManager.ApplicationStateObserver = {  
    onForegroundApplicationChanged(appStateData) {  
        console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);  
    },  
    onAbilityStateChanged(abilityStateData) {  
        console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);  
    },  
    onProcessCreated(processData) {  
        console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);  
    },  
    onProcessDied(processData) {  
        console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);  
    },  
    onProcessStateChanged(processData) {  
        console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);  
    }  
};  
let bundleNameList = ['bundleName1', 'bundleName2'];  
try {  
    observerId = appManager.on('applicationState', applicationStateObserver, bundleNameList);  
    console.log(`[appManager] observerCode: ${observerId}`);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
  
// 2.注销应用状态监听器  
function unregisterApplicationStateObserverCallback(err: BusinessError) {  
    if (err) {  
        console.error(`unregisterApplicationStateObserverCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('unregisterApplicationStateObserverCallback success.');  
    }  
}  
try {  
    appManager.off('applicationState', observerId, unregisterApplicationStateObserverCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## getForegroundApplications    
获取当前所有前台应用的信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。  
 **调用形式：**     
    
- getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void    
起始版本： 9    
- getForegroundApplications(): Promise\<Array\<AppStateData>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式方式返回接口运行结果及应用状态数据数组，可进行错误处理或其他自定义处理。 |  
| Promise<Array<AppStateData>> | 返回前台进程应用程序的数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
function getForegroundApplicationsCallback(err: BusinessError, data: Array<appManager.AppStateData>) {  
    if (err) {  
        console.error(`getForegroundApplicationsCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`getForegroundApplicationsCallback success, data: ${JSON.stringify(data)}`);  
    }  
}  
try {  
    appManager.getForegroundApplications(getForegroundApplicationsCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
<span style="letter-spacing: 0px;">示例(Promise):</span>  
  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
appManager.getForegroundApplications().then((data) => {  
    console.log(`getForegroundApplications success, data: ${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getForegroundApplications fail, err: ${JSON.stringify(err)}`);  
});  
    
```    
  
    
## killProcessWithAccount    
切断account进程（Promise形式）。  
 **调用形式：**     
    
- killProcessWithAccount(bundleName: string, accountId: number): Promise\<void>    
起始版本： 9    
- killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS and ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 应用Bundle名称。 |  
| accountId | number | true | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
let accountId = 0;  
try {  
    appManager.killProcessWithAccount(bundleName, accountId).then(() => {  
        console.log('killProcessWithAccount success');  
    }).catch((err: BusinessError) => {  
        console.error(`killProcessWithAccount fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
let accountId = 0;  
function killProcessWithAccountCallback(err: BusinessError) {  
    if (err) {  
        console.error(`killProcessWithAccountCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('killProcessWithAccountCallback success.');  
    }  
}  
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);  
    
```    
  
    
## killProcessesByBundleName    
通过Bundle名称终止进程。  
 **调用形式：**     
    
- killProcessesByBundleName(bundleName: string): Promise\<void>    
起始版本： 9    
- killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>)    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_BACKGROUND_PROCESSES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
| Promise<void> | 返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
function killProcessesByBundleNameCallback(err: BusinessError) {  
    if (err) {  
        console.error(`killProcessesByBundleNameCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('killProcessesByBundleNameCallback success.');  
    }  
}  
try {  
    appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
try {  
    appManager.killProcessesByBundleName(bundleName).then((data) => {  
        console.log('killProcessesByBundleName success.');  
    }).catch((err: BusinessError) => {  
        console.error(`killProcessesByBundleName fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## clearUpApplicationData    
通过Bundle名称清除应用数据。  
 **调用形式：**     
    
- clearUpApplicationData(bundleName: string): Promise\<void>    
起始版本： 9    
- clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>)    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.CLEAN_APPLICATION_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
| Promise<void> | 以Promise方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
function clearUpApplicationDataCallback(err: BusinessError) {  
    if (err) {  
        console.error(`clearUpApplicationDataCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('clearUpApplicationDataCallback success.');  
    }  
}  
try {  
    appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'bundleName';  
try {  
    appManager.clearUpApplicationData(bundleName).then((data) => {  
        console.log('clearUpApplicationData success.');  
    }).catch((err: BusinessError) => {  
        console.error(`clearUpApplicationData fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## isSharedBundleRunning<sup>(10+)</sup>    
检查共享库是否正在使用。使用Promise异步回调。  
 **调用形式：**     
    
- isSharedBundleRunning(bundleName: string, versionCode: number): Promise\<boolean>    
起始版本： 10    
- isSharedBundleRunning(bundleName: string, versionCode: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 表示要查询的共享库包名。 |  
| versionCode | number | true | 表示要查询的共享库版本号。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示共享库正在使用，返回false表示共享库不在使用。 |  
| Promise<boolean> | Promise对象。返回true表示共享库正在使用，返回false表示共享库不在使用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
const bundleName = "this is a bundleName";  
const versionCode = 1;  
appManager.isSharedBundleRunning(bundleName, versionCode).then((data) => {  
    console.log(`The shared bundle running is: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
  
const bundleName = "this is a bundleName";  
const versionCode = 1;  
appManager.isSharedBundleRunning(bundleName, versionCode, (err, data) => {  
    if (err) {  
        console.error(`err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`The shared bundle running is: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## getProcessMemoryByPid<sup>(10+)</sup>    
通过pid查询对应进程占用的内存大小。  
 **调用形式：**     
    
- getProcessMemoryByPid(pid: number): Promise\<number>    
起始版本： 10    
- getProcessMemoryByPid(pid: number, callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pid | number | true | 表示进程id，详情参考[getRunningProcessInfoByBundleName](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinfobybundlename10)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及进程占用的内存大小（单位KB），可进行错误处理或其他自定义处理。 |  
| Promise<number> | 以Promise方式返回接口运行结果及进程占用的内存大小（单位KB），可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let pid = 0;  
function getProcessMemoryByPidCallback(err: BusinessError, data: number) {  
    if (err) {  
        console.error(`getProcessMemoryByPidCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('getProcessMemoryByPidCallback success.');  
    }  
}  
try {  
    appManager.getProcessMemoryByPid(pid, getProcessMemoryByPidCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let pid = 0;  
try {  
    appManager.getProcessMemoryByPid(pid).then((data) => {  
        console.log('getProcessMemoryByPid success.');  
    }).catch((err: BusinessError) => {  
        console.error(`getProcessMemoryByPid fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
## getRunningProcessInfoByBundleName<sup>(10+)</sup>    
获取有关运行进程的信息。  
 **调用形式：**     
    
- getRunningProcessInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<ProcessInformation>>): void    
起始版本： 10    
- getRunningProcessInfoByBundleName(bundleName: string, userId: number, callback: AsyncCallback\<Array\<ProcessInformation>>): void    
起始版本： 10    
- getRunningProcessInfoByBundleName(bundleName: string): Promise\<Array\<ProcessInformation>>    
起始版本： 10    
- getRunningProcessInfoByBundleName(bundleName: string, userId: number): Promise\<Array\<ProcessInformation>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true |  |  
| userId | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
| Promise<Array<ProcessInformation>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = "bundleName";  
function getRunningProcessInfoByBundleNameCallback(err: BusinessError, data: Array<appManager.ProcessInformation>) {  
    if (err) {  
        console.error(`getRunningProcessInfoByBundleNameCallback fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log('getRunningProcessInfoByBundleNameCallback success.');  
    }  
}  
try {  
    appManager.getRunningProcessInfoByBundleName(bundleName, getRunningProcessInfoByBundleNameCallback);  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = "bundleName";  
try {  
    appManager.getRunningProcessInfoByBundleName(bundleName).then((data) => {  
        console.log('getRunningProcessInfoByBundleName success.');  
    }).catch((err: BusinessError) => {  
        console.error(`getRunningProcessInfoByBundleName fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`[appManager] error: ${code}, ${message} `);  
}  
    
```    
  
