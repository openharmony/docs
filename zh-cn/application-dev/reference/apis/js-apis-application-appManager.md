# @ohos.application.appManager (appManager)

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 7 开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.appManager](js-apis-app-ability-appManager.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import app from '@ohos.application.appManager';
```

## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```ts
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest((err, flag) => {
      console.log('startAbility result:' + JSON.stringify(err));
  })  
  ```


## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```ts
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringify(flag));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```


## appManager.isRamConstrainedDevice

isRamConstrainedDevice(): Promise\<boolean>;

查询是否为ram受限设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 是否为ram受限设备。 | 

**示例：**
    
  ```ts
  app.isRamConstrainedDevice().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

查询是否为ram受限设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 返回当前是否是ram受限设备。 | 

**示例：**
    
  ```ts
  app.isRamConstrainedDevice((err, data) => {
      console.log('startAbility result failed:' + JSON.stringify(err));
      console.log('startAbility result success:' + JSON.stringify(data));
  })
  ```

## appManager.getAppMemorySize

getAppMemorySize(): Promise\<number>;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 应用程序内存大小。 | 

**示例：**
    
  ```ts
  app.getAppMemorySize().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 是 | 应用程序内存大小。 | 

**示例：**
    
  ```ts
  app.getAppMemorySize((err, data) => {
      console.log('startAbility result failed :' + JSON.stringify(err));
      console.log('startAbility result success:' + JSON.stringify(data));
  })
  ```
## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>;

获取有关运行进程的信息。

> 从 API Version 9 开始废弃，建议使用[appManager.getProcessRunningInformation<sup>9+</sup>](#appmanagergetprocessrunninginformation9)替代。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<ProcessRunningInfo>> | 获取有关运行进程的信息。 |

**示例：**
    
  ```ts
  app.getProcessRunningInfos().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void;

获取有关运行进程的信息。

> 从 API Version 9 开始废弃，建议使用[appManager.getProcessRunningInformation<sup>9+</sup>](#appmanagergetprocessrunninginformation9-1)替代。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<ProcessRunningInfo>> | 是 | 获取有关运行进程的信息。 |

**示例：**
    
  ```ts
  app.getProcessRunningInfos((err, data) => {
      console.log('startAbility result failed :' + JSON.stringify(err));
      console.log('startAbility result success:' + JSON.stringify(data));
  })
  ```

## appManager.getProcessRunningInformation<sup>9+</sup>

getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>> | 获取有关运行进程的信息。 |

**示例：**
    
  ```ts
  app.getProcessRunningInformation().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```

## appManager.getProcessRunningInformation<sup>9+</sup>

getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>> | 是 | 获取有关运行进程的信息。 |

**示例：**
    
  ```ts
  app.getProcessRunningInformation((err, data) => {
      console.log('startAbility result failed :' + JSON.stringify(err));
      console.log('startAbility result success:' + JSON.stringify(data));
  })
  ```

## appManager.registerApplicationStateObserver<sup>8+</sup>

registerApplicationStateObserver(observer: ApplicationStateObserver): number;

注册全部应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observer | [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) | 是 | 返回观察者的数字代码。 |

**示例：**
    
  ```ts
  var applicationStateObserver = {
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
  }
  const observerCode = app.registerApplicationStateObserver(applicationStateObserver);
  console.log('-------- observerCode: ---------', observerCode);
  ```

## appManager.registerApplicationStateObserver<sup>9+</sup>

registerApplicationStateObserver(observer: ApplicationStateObserver, bundleNameList: Array\<string>): number;

注册指定应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observer | [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) | 是 | 返回观察者的数字代码。 |
| bundleNameList | Array<string> | 是 | 表示需要注册监听的bundleName数组。最大值128。 |

**示例：**
    
  ```ts
  var applicationStateObserver = {
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
  }
  var bundleNameList = ['bundleName1', 'bundleName2'];
  const observerCode = app.registerApplicationStateObserver(applicationStateObserver, bundleNameList);
  console.log('-------- observerCode: ---------', observerCode);
  ```
## appManager.unregisterApplicationStateObserver<sup>8+</sup>

unregisterApplicationStateObserver(observerId: number,  callback: AsyncCallback\<void>): void;

取消注册应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observerId | number | 是 | 表示观察者的编号代码。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**示例：**
    
  ```ts
  var observerId = 100;

  function unregisterApplicationStateObserverCallback(err) {
    if (err) {
        console.log('------------ unregisterApplicationStateObserverCallback ------------', err);
    }
  }
  app.unregisterApplicationStateObserver(observerId, unregisterApplicationStateObserverCallback);
  ```

## appManager.unregisterApplicationStateObserver<sup>8+</sup>

unregisterApplicationStateObserver(observerId: number): Promise\<void>;

取消注册应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| observerId | number | 是 | 表示观察者的编号代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```ts
  var observerId = 100;

  app.unregisterApplicationStateObserver(observerId)
  .then((data) => {
      console.log('----------- unregisterApplicationStateObserver success ----------', data);
  })
  .catch((err) => {
      console.log('----------- unregisterApplicationStateObserver fail ----------', err);
  })
  ```

## appManager.getForegroundApplications<sup>8+</sup>

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;

获取前台进程的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<AppStateData>> | 是 | 表示应用的状态数据。 |

**示例：**
    
  ```ts
  function getForegroundApplicationsCallback(err, data) {
    if (err) {
        console.log('--------- getForegroundApplicationsCallback fail ---------', err);
    } else {
        console.log('--------- getForegroundApplicationsCallback success ---------', data)
    }
  }
  app.getForegroundApplications(getForegroundApplicationsCallback);
  ```

## appManager.getForegroundApplications<sup>8+</sup>

getForegroundApplications(): Promise\<Array\<AppStateData>>;

获取前台进程的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<ProcessRunningInfo>> | 返回进程运行信息的数组。 |

**示例：**
    
  ```ts
  app.getForegroundApplications()
  .then((data) => {
      console.log('--------- getForegroundApplications success -------', data);
  })
  .catch((err) => {
      console.log('--------- getForegroundApplications fail -------', err);
  })
  ```

## appManager.killProcessWithAccount<sup>8+</sup>

killProcessWithAccount(bundleName: string, accountId: number): Promise\<void\>

切断account进程（Promise形式）。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。 | 
  | accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 | 

**示例：**

```ts
var bundleName = 'bundleName';
var accountId = 0;
app.killProcessWithAccount(bundleName, accountId)
   .then((data) => {
       console.log('------------ killProcessWithAccount success ------------', data);
   })
   .catch((err) => {
       console.log('------------ killProcessWithAccount fail ------------', err);
   })
```


## appManager.killProcessWithAccount<sup>8+</sup>

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

切断account进程（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS, ohos.permission.CLEAN_BACKGROUND_PROCESSES

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。 | 
  | accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 | 
  | callback | AsyncCallback\<void\> | 是 | 切断account进程的回调函数。 | 

**示例：**

```ts
var bundleName = 'bundleName';
var accountId = 0;
function killProcessWithAccountCallback(err, data) {
   if (err) {
       console.log('------------- killProcessWithAccountCallback fail, err: --------------', err);
   } else {
       console.log('------------- killProcessWithAccountCallback success, data: --------------', data);
   }
}
app.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
```

## appManager.killProcessesByBundleName<sup>8+</sup>

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);

通过包名终止进程。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**示例：**
    
  ```ts
  var bundleName = 'bundleName';
  function killProcessesByBundleNameCallback(err, data) {
    if (err) {
        console.log('------------- killProcessesByBundleNameCallback fail, err: --------------', err);
    } else {
        console.log('------------- killProcessesByBundleNameCallback success, data: --------------', data);
    }
  }
  app.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
  ```

## appManager.killProcessesByBundleName<sup>8+</sup>

killProcessesByBundleName(bundleName: string): Promise\<void>;

通过包名终止进程。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```ts
  var bundleName = 'bundleName';
  app.killProcessesByBundleName(bundleName)
    .then((data) => {
        console.log('------------ killProcessesByBundleName success ------------', data);
    })
    .catch((err) => {
        console.log('------------ killProcessesByBundleName fail ------------', err);
    })
  ```

## appManager.clearUpApplicationData<sup>8+</sup>

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);

通过包名清除应用数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**示例：**
    
  ```ts
  var bundleName = 'bundleName';
  function clearUpApplicationDataCallback(err, data) {
    if (err) {
        console.log('------------- clearUpApplicationDataCallback fail, err: --------------', err);
    } else {
        console.log('------------- clearUpApplicationDataCallback success, data: --------------', data);
    }
  }
  app.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
  ```

## appManager.clearUpApplicationData<sup>8+</sup>

clearUpApplicationData(bundleName: string): Promise\<void>;

通过包名清除应用数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```ts
  var bundleName = 'bundleName';
  app.clearUpApplicationData(bundleName)
    .then((data) => {
        console.log('------------ clearUpApplicationData success ------------', data);
    })
    .catch((err) => {
        console.log('------------ clearUpApplicationData fail ------------', err);
    })
  ```

## ApplicationState<sup>9+</sup>

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |   当应用在创建中的时候处于的状态。         |
| STATE_FOREGROUND          | 2   |      当应用切换到前台的时候处于的状态。            |
| STATE_ACTIVE  | 3   |         当应用在获焦的时候处于的状态。     |
| STATE_BACKGROUND        | 4   |       当应用处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |           当应用在销毁的时候处于的状态。       |

## ProcessState<sup>9+</sup>

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |      当进程在创建中的时候处于的状态。       |
| STATE_FOREGROUND          | 2   |            当进程切换到前台的时候处于的状态。      |
| STATE_ACTIVE  | 3   |          当进程在获焦的时候处于的状态。   |
| STATE_BACKGROUND        | 4   |       当进程处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |         当进程在销毁的时候处于的状态。         |