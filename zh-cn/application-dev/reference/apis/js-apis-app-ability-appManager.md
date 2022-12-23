# @ohos.app.ability.appManager (appManager)

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import appManager from '@ohos.app.ability.appManager';
```

## appManager.isRunningInStabilityTest

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型| 说明 | 
  | -------- | -------- |
  |AsyncCallback&lt;boolean&gt; |以回调方式返回接口运行结果及当前是否处于稳定性测试场景，可进行错误处理或其他自定义处理。true: 处于稳定性测试场景，false：处于非稳定性测试场景。 | 

**示例：**
    
```ts
appManager.isRunningInStabilityTest((err, flag) => {
    if (err.code != 0) {
        conseole.log("isRunningInStabilityTest faile, err: " + JSON.stringify(err));
    } else {
        console.log("The result of isRunningInStabilityTest is:" + JSON.stringify(flag));
    }
})  
```


## appManager.isRunningInStabilityTest

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise方式返回接口运行结果及当前是否处于稳定性测试场景，可进行错误处理或其他自定义处理。true: 处于稳定性测试场景，false：处于非稳定性测试场景。 | 

**示例：**
    
```ts
appManager.isRunningInStabilityTest().then((flag) => {
    console.log("The result of isRunningInStabilityTest is:" + JSON.stringify(flag));
}).catch((error) => {
    console.log("error:" + JSON.stringify(error));
});
```


## appManager.isRamConstrainedDevice

isRamConstrainedDevice(): Promise\<boolean>;

查询是否为ram受限设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise方式返回接口运行结果及当前设备是否为ram受限设备，可进行错误处理或其他自定义处理。true：当前设备为ram受限设备，false：当前设备为非ram受限设备。 | 

**示例：**
    
```ts
appManager.isRamConstrainedDevice().then((data) => {
    console.log("The result of isRamConstrainedDevice is:" + JSON.stringify(data));
}).catch((error) => {
    console.log("error:" + JSON.stringify(error));
});
```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

查询是否为ram受限设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | AsyncCallback&lt;boolean&gt; |以回调方式返回接口运行结果及当前设备是否为ram受限设备，可进行错误处理或其他自定义处理。true：当前设备为ram受限设备，false：当前设备为非ram受限设备。 | 

**示例：**
    
```ts
appManager.isRamConstrainedDevice((err, data) => {
    if (err.code != 0) {
        console.log("isRamConstrainedDevice faile, err: " + JSON.stringify(err));
    } else {
        console.log("The result of isRamConstrainedDevice is:" + JSON.stringify(data));
    }
})
```

## appManager.getAppMemorySize

getAppMemorySize(): Promise\<number>;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 以Promise方式返回接口运行结果及应用程序内存大小，可进行错误处理或其他自定义处理。 | 

**示例：**
    
```ts
appManager.getAppMemorySize().then((data) => {
    console.log("The size of app memory is:" + JSON.stringify(data));
}).catch((error) => {
    console.log("error:" + JSON.stringify(error));
});
```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  |AsyncCallback&lt;number&gt; |以回调方式返回接口运行结果及应用程序内存大小，可进行错误处理或其他自定义处理。 | 

**示例：**
    
```ts
appManager.getAppMemorySize((err, data) => {
    if (err.code != 0) {
        console.log("getAppMemorySize faile, err: " + JSON.stringify(err));
    } else {
        console.log("The size of app memory is:" + JSON.stringify(data));
    }
})
```

## appManager.getProcessRunningInformation<sup>9+</sup>

getProcessRunningInformation(): Promise\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>>;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
appManager.getProcessRunningInformation().then((data) => {
    console.log("The process running information is:" + JSON.stringify(data));
}).catch((error) => {
    console.log("error:" + JSON.stringify(error));
});
```

## appManager.getProcessRunningInformation<sup>9+</sup>

getProcessRunningInformation(callback: AsyncCallback\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>>): void;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
|AsyncCallback\<Array\<[ProcessRunningInformation](js-apis-inner-application-processRunningInformation.md)>> | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
appManager.getProcessRunningInformation((err, data) => {
    if (err.code != 0) {
        console.log("getProcessRunningInformation faile, err: " + JSON.stringify(err));
    } else {
        console.log("The process running information is:" + JSON.stringify(data));
    }
})
```

## appManager.on

on(type: "applicationState", observer: [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md)): number;

注册全部应用程序的状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填"applicationState"字符串。 |
| observer | [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md) | 是 | 应用状态观测器，用于观测应用的生命周期变化。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| number | 已注册观测器的数字代码，可用于off接口取消注册观测器。|

**示例：**
    
```js
var applicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log('------------ onForegroundApplicationChanged -----------' + JSON.stringify(appStateData));
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('------------ onAbilityStateChanged -----------' + JSON.stringify(abilityStateData));
    },
    onProcessCreated(processData) {
        console.log('------------ onProcessCreated -----------' + JSON.stringify(processData));
    },
    onProcessDied(processData) {
        console.log('------------ onProcessDied -----------' + JSON.stringify(processData));
    },
    onProcessStateChanged(processData) {
        console.log('------------ onProcessStateChanged -----------' + JSON.stringify(processData));
    }
}
try {
    const observerCode = appManager.on(applicationStateObserver);
    console.log('-------- observerCode: ---------' + observerCode);
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```

## appManager.on

on(type: "applicationState", observer: [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md), bundleNameList: Array\<string>): number;

注册指定应用程序的状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填"applicationState"字符串。 |
| observer | [ApplicationStateObserver](./js-apis-inner-application-applicationStateObserver.md) | 是 | 应用状态观测器，用于观测应用的生命周期变化。 |
| bundleNameList | Array<string> | 是 | 表示需要注册监听的bundleName数组。最大值128。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| number | 已注册观测器的数字代码，可用于off接口注销观测器。|

**示例：**
    
```js
var applicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log('------------ onForegroundApplicationChanged -----------' + JSON.stringify(appStateData));
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('------------ onAbilityStateChanged -----------' + JSON.stringify(abilityStateData));
    },
    onProcessCreated(processData) {
        console.log('------------ onProcessCreated -----------' + JSON.stringify(processData));
    },
    onProcessDied(processData) {
        console.log('------------ onProcessDied -----------' + JSON.stringify(processData));
    },
    onProcessStateChanged(processData) {
        console.log('------------ onProcessStateChanged -----------' + JSON.stringify(processData));
    }
}
var bundleNameList = ['bundleName1', 'bundleName2'];
try {
    const observerCode = appManager.on("applicationState", applicationStateObserver, bundleNameList);
    console.log('-------- observerCode: ---------', observerCode);
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
 ```

## appManager.off

off(type: "applicationState", observerId: number,  callback: AsyncCallback\<void>): void;

取消注册应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填"applicationState"字符串。 |
| observerId | number | 是 | 表示观测器的编号代码。 |
| callback | AsyncCallback\<void> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
var observerId = 100;

function unregisterApplicationStateObserverCallback(err) {
    if (err.code != 0) {
        console.log("unregisterApplicationStateObserverCallback faile, err: " + JSON.stringify(err));
    } else {
        console.log("unregisterApplicationStateObserverCallback success.");
    }
}
try {
    appManager.off(observerId, unregisterApplicationStateObserverCallback);
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```

## appManager.off

off(type: "applicationState", observerId: number): Promise\<void>;

取消注册应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型，固定填"applicationState"字符串。 |
| observerId | number | 是 | 表示观测器的编号代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 以Promise方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
var observerId = 100;
    
try {
    appManager.off(observerId).then((data) => {
        console.log("unregisterApplicationStateObserver success, data: " + JSON.stringify(data));
    }).catch((err) => {
        console.log("unregisterApplicationStateObserver faile, err: " + JSON.stringify(err));
    })
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>>): void;

获取前台的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 是 | 以回调方式返回接口运行结果及应用状态数据数组，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
function getForegroundApplicationsCallback(err, data) {
    if (err.code != 0) {
        console.log("getForegroundApplicationsCallback fail, err: " + JSON.stringify(err));
    } else {
        console.log("getForegroundApplicationsCallback success, data: " + JSON.stringify(data));
    }
}
try {
    appManager.getForegroundApplications(getForegroundApplicationsCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>>): void;

获取前台进程的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 是 | 以Promise方式返回接口运行结果及应用状态数据数组，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
function getForegroundApplicationsCallback(err, data) {
    if (err.code != 0) {
        console.log("getForegroundApplicationsCallback fail, err: " + JSON.stringify(err));
    } else {
        console.log("getForegroundApplicationsCallback success, data: " + JSON.stringify(data));
    }
}
try {
    appManager.getForegroundApplications(getForegroundApplicationsCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## appManager.getForegroundApplications

getForegroundApplications(): Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>>;

获取前台进程的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[AppStateData](js-apis-inner-application-appStateData.md)>> | 返回前台进程应用程序的数组。 |

**示例：**
    
```ts
appManager.getForegroundApplications().then((data) => {
    console.log("getForegroundApplications success, data: " + JSON.stringify(data));
}).catch((err) => {
    console.log("getForegroundApplications fail, err: " + JSON.stringify(err));
})
```

## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number): Promise\<void\>

切断account进程（Promise形式）。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES，ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

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
try {
    appManager.killProcessWithAccount(bundleName, accountId).then(() => {
        console.log("killProcessWithAccount success");
    }).catch((err) => {
        console.log("killProcessWithAccount fail, err: " + JSON.stringify(err));
    })
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```


## appManager.killProcessWithAccount

killProcessWithAccount(bundleName: string, accountId: number, callback: AsyncCallback\<void\>): void

切断account进程（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES，ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，当accountId为当前用户时，不需要校验ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。 | 
  | accountId | number | 是 | 系统帐号的帐号ID，详情参考[getCreatedOsAccountsCount](js-apis-osAccount.md#getosaccountlocalidfromprocess)。 | 
  | callback | AsyncCallback\<void\> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 | 

**示例：**

```ts
var bundleName = 'bundleName';
var accountId = 0;
function killProcessWithAccountCallback(err, data) {
    if (err.code != 0) {
        console.log("killProcessWithAccountCallback fail, err: " + JSON.stringify(err));
    } else {
        console.log("killProcessWithAccountCallback success.");
    }
}
appManager.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string, callback: AsyncCallback\<void>);

通过包名终止进程。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |
| callback | AsyncCallback\<void> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
var bundleName = 'bundleName';
function killProcessesByBundleNameCallback(err, data) {
    if (err.code != 0) {
        console.log("killProcessesByBundleNameCallback fail, err: " + JSON.stringify(err));
    } else {
        console.log("killProcessesByBundleNameCallback success.");
    }
}
try {
    appManager.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## appManager.killProcessesByBundleName

killProcessesByBundleName(bundleName: string): Promise\<void>;

通过包名终止进程。

**需要权限**：ohos.permission.CLEAN_BACKGROUND_PROCESSES

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示应用包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
```ts
var bundleName = 'bundleName';
try {
    appManager.killProcessesByBundleName(bundleName).then((data) => {
        console.log("killProcessesByBundleName success.");
    }).catch((err) => {
        console.log("killProcessesByBundleName fail, err: " + JSON.stringify(err));
    })
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## appManager.clearUpApplicationData

clearUpApplicationData(bundleName: string, callback: AsyncCallback\<void>);

通过包名清除应用数据。

**需要权限**：ohos.permission.CLEAN_APPLICATION_DATA

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 表示包名。 |
| callback | AsyncCallback\<void> | 是 | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
var bundleName = 'bundleName';
function clearUpApplicationDataCallback(err, data) {
    if (err) {
        console.log("clearUpApplicationDataCallback fail, err: " + JSON.stringify(err));
    } else {
        console.log("clearUpApplicationDataCallback success.");
    }
}
try {
    appManager.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## appManager.clearUpApplicationData

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
| Promise\<void> | 以Promise方式返回接口运行结果，可进行错误处理或其他自定义处理。 |

**示例：**
    
```ts
var bundleName = 'bundleName';
try {
    appManager.clearUpApplicationData(bundleName).then((data) => {
        console.log("clearUpApplicationData success.");
    }).catch((err) => {
        console.log("clearUpApplicationData fail, err: " + JSON.stringify(err));
    })
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## ApplicationState

应用状态，该类型为枚举，可配合[AbilityStateData](js-apis-inner-application-appStateData.md)返回相应的应用状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |   当应用在创建中的时候处于的状态。         |
| STATE_FOREGROUND          | 2   |      当应用切换到前台的时候处于的状态。            |
| STATE_ACTIVE  | 3   |         当应用在获焦的时候处于的状态。     |
| STATE_BACKGROUND        | 4   |       当应用处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |           当应用在销毁的时候处于的状态。       |

## ProcessState

进程状态，该类型为枚举，可配合[ProcessData](js-apis-inner-application-processData.md)返回相应的进程状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |      当进程在创建中的时候处于的状态。       |
| STATE_FOREGROUND          | 2   |            当进程切换到前台的时候处于的状态。      |
| STATE_ACTIVE  | 3   |          当进程在获焦的时候处于的状态。   |
| STATE_BACKGROUND        | 4   |       当进程处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |         当进程在销毁的时候处于的状态。         |
