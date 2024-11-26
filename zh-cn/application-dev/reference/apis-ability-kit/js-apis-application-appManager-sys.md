# @ohos.application.appManager (appManager)(系统接口)

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 8 开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.appManager](js-apis-app-ability-appManager.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.application.appManager (appManager)](js-apis-app-ability-wantConstant.md)。

## 导入模块

```ts
import appManager from '@ohos.application.appManager';
```

## appManager.registerApplicationStateObserver

registerApplicationStateObserver(observer: ApplicationStateObserver): number

注册全部应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observer | [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) | 是 | 表示程序状态观测器，用于观测应用的生命周期变化。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| number | 已注册观测器的数字代码。|

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  const observerCode = appManager.registerApplicationStateObserver({
    onForegroundApplicationChanged(appStateData) {
        console.log('------------ onForegroundApplicationChanged -----------', appStateData);
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('------------ onAbilityStateChanged -----------', abilityStateData);
    },
    onProcessCreated(processData) {
        console.log('------------ onProcessCreated -----------', processData);
    },
    onProcessDied(processData) {
        console.log('------------ onProcessDied -----------', processData);
    },
    onProcessStateChanged(processData) {
        console.log('------------ onProcessStateChanged -----------', processData);
    }
  });
  console.log('-------- observerCode: ---------', observerCode);
  ```

## appManager.unregisterApplicationStateObserver

unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback\<void>): void

取消注册应用程序状态观测器。使用callback异步回调。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observerId | number | 是 | 表示观察者的编号代码。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的callback回调方法。 |

**示例：**
    
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

## appManager.unregisterApplicationStateObserver

unregisterApplicationStateObserver(observerId: number): Promise\<void>

取消注册应用程序状态观测器。使用Promise异步回调。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observerId | number | 是 | 表示观察者的编号代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。。 |

**示例：**
    
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

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void

获取所有当前处于前台的应用信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。使用callback异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 是 | 回调函数，返回所有当前处于前台的应用信息。 |

**示例：**
    
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

## appManager.getForegroundApplications

getForegroundApplications(): Promise\<Array\<AppStateData>>

获取所有当前处于前台的应用信息。该应用信息由[AppStateData](js-apis-inner-application-appStateData.md)定义。使用Promise异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | Promise对象，返回所有当前处于前台的应用信息。 |

**示例：**
    
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

## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number): Promise\<void\>

切断account进程（Promise形式）。

> **说明：** 
>
> 当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用Bundle名称。 |
| accountId | number | 是 | 系统账号的账号ID，详情参考[getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

let bundleName = 'bundleName';
let accountId = 0;
appManager.killProcessWithAccount(bundleName, accountId)
   .then((data) => {
       console.log('------------ killProcessWithAccount success ------------', data);
   })
   .catch((err: BusinessError) => {
       console.error('------------ killProcessWithAccount fail ------------', err);
   });
```


## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

切断account进程（callback形式）。

> **说明：** 
>
> 当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.CLEAN_BACKGROUND_PROCESSES

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用Bundle名称。 |
| accountId | number | 是 | 系统账号的账号ID，详情参考[getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalidfromprocess)。 |
| callback | AsyncCallback\<void\> | 是 | 回调函数，当切断account进程成功。，err为undefined，否则为错误对象。 |

**示例：**

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

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>)

通过Bundle名称终止进程。使用callback异步回调。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当通过Bundle名称终止进程成功，err为undefined，否则为错误对象。 |

**示例：**
    
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

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string): Promise\<void>

通过Bundle名称终止进程。使用Promise异步回调。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>)

通过Bundle名称清除应用数据。使用callback异步回调。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当通过Bundle名称清除应用数据成功，err为undefined，否则为错误对象。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let bundleName = 'bundleName';
  function clearUpApplicationDataCallback(err: BusinessError, data: void) {
    if (err) {
        console.error('------------- clearUpApplicationDataCallback fail, err: --------------', err);
    } else {
        console.log('------------- clearUpApplicationDataCallback success, data: --------------', data);
    }
  }
  appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
  ```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string): Promise\<void>

通过Bundle名称清除应用数据。使用Promise异步回调。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**: 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  let bundleName = 'bundleName';
  appManager.clearUpApplicationData(bundleName)
    .then((data) => {
        console.log('------------ clearUpApplicationData success ------------', data);
    })
    .catch((err: BusinessError) => {
        console.error('------------ clearUpApplicationData fail ------------', err);
    });
  ```