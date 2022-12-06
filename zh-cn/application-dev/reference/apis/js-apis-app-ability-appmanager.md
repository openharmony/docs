# appManager

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import app from '@ohos.app.ability.appManager';
```

## appManager.isRunningInStabilityTest

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 否 | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```js
  import app from '@ohos.app.ability.appManager';
  app.isRunningInStabilityTest((err, flag) => {
      console.log('startAbility result:' + JSON.stringify(err));
  })  
  ```


## appManager.isRunningInStabilityTest

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```js
  import app from '@ohos.app.ability.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringify(flag));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(err));
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
    
  ```js
        app.isRamConstrainedDevice().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(err));
        });
  ```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

查询是否为ram受限设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 否 | 返回当前是否是ram受限设备。 | 

**示例：**
    
  ```js
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
    
  ```js
        app.getAppMemorySize().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + error.code + ', ' + error.message);
        });
  ```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 否 | 应用程序内存大小。 | 

**示例：**
    
  ```js
        app.getAppMemorySize((err, data) => {
            console.log('startAbility result failed :' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
  ```

## appManager.getProcessRunningInformation

getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation>>;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessRunningInformation](#processrunninginformation)>> | 获取有关运行进程的信息。 |

**示例：**
    
  ```js
        app.getProcessRunningInformation().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
  ```

## appManager.getProcessRunningInformation

getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation>>): void;

获取有关运行进程的信息。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ProcessRunningInformation](#processrunninginformation)>> | 否 | 获取有关运行进程的信息。 |

**示例：**
    
  ```js
        app.getProcessRunningInformation((err, data) => {
            console.log('startAbility result failed :' + JSON.stringify(error));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
  ```

## appManager.on

on(type: "applicationState", observer: ApplicationStateObserver): number;

注册全部应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型 |
| observer | [ApplicationStateObserver](#applicationstateobserver) | 否 | 返回观察者的数字代码。 |

**示例：**
    
  ```js
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
  try {
    const observerCode = app.on(applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }

  ```

## appManager.on

on(type: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array\<string>): number;

注册指定应用程序状态观测器。

**需要权限**：ohos.permission.RUNNING_STATE_OBSERVER

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型 |
| observer | [ApplicationStateObserver](#applicationstateobserver) | 否 | 返回观察者的数字代码。 |
| bundleNameList | Array<string> | 否 | 表示需要注册监听的bundleName数组。最大值128。 |

**示例：**
    
  ```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver, bundleNameList);
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
| type | string | 是 | 调用接口类型 |
| observerId | number | 否 | 表示观察者的编号代码。 |
| callback | AsyncCallback\<void> | 否 | 表示指定的回调方法。 |

**示例：**
    
  ```js
    var observerId = 100;

    function unregisterApplicationStateObserverCallback(err) {
      if (err) {
          console.log('------------ unregisterApplicationStateObserverCallback ------------', err);
      }
    }
    try {
      app.off(observerId, unregisterApplicationStateObserverCallback);
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
| type | string | 是 | 调用接口类型 |
| observerId | number | 否 | 表示观察者的编号代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```js
    var observerId = 100;
    
    try {
      app.off(observerId)
        .then((data) => {
          console.log('----------- unregisterApplicationStateObserver success ----------', data);
        })
        .catch((err) => {
          console.log('----------- unregisterApplicationStateObserver fail ----------', err);
        })
    } catch (paramError) {
      console.log('error: ' + paramError.code + ', ' + paramError.message);
    }
  ```

## appManager.getForegroundApplications

getForegroundApplications(callback: AsyncCallback\<Array\<AppStateData>>): void;

获取前台进程的应用程序。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<AppStateData>> | 否 | 表示应用的状态数据。 |

**示例：**
    
  ```js
    function getForegroundApplicationsCallback(err, data) {
      if (err) {
          console.log('--------- getForegroundApplicationsCallback fail ---------', err.code + ': ' + err.message);
      } else {
          console.log('--------- getForegroundApplicationsCallback success ---------', data)
      }
    }
    app.getForegroundApplications(getForegroundApplicationsCallback);
  ```

## appManager.getForegroundApplications

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
    
  ```js
    app.getForegroundApplications()
    .then((data) => {
        console.log('--------- getForegroundApplications success -------', data);
    })
    .catch((err) => {
        console.log('--------- getForegroundApplications fail -------', err.code + ': ' + err.message);
    })
  ```

## appManager.killProcessWithAccount

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

```js
var bundleName = 'bundleName';
var accountId = 0;
try {
  app.killProcessWithAccount(bundleName, accountId)
    .then((data) => {
       console.log('------------ killProcessWithAccount success ------------', data);
    })
    .catch((err) => {
       console.log('------------ killProcessWithAccount fail ------------', err);
    })
} catch (paramError) {
  console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```


## appManager.killProcessWithAccount

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

```js
var bundleName = 'bundleName';
var accountId = 0;
function killProcessWithAccountCallback(err, data) {
   if (err) {
       console.log('------------- killProcessWithAccountCallback fail, err: --------------', err);
   } else {
       console.log('------------- killProcessWithAccountCallback success, data: --------------', data);
   }
}
try {
  app.killProcessWithAccount(bundleName, accountId, killProcessWithAccountCallback);
} catch (paramError) {
  console.log('error: ' + paramError.code + ', ' + paramError.message);
}
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
| bundleName | string | 否 | 表示包名。 |
| callback | AsyncCallback\<void> | 否 | 表示指定的回调方法。 |

**示例：**
    
  ```js
    var bundleName = 'bundleName';
    function killProcessesByBundleNameCallback(err, data) {
      if (err) {
          console.log('------------- killProcessesByBundleNameCallback fail, err: --------------', err);
      } else {
          console.log('------------- killProcessesByBundleNameCallback success, data: --------------', data);
      }
    }
    try {
      app.killProcessesByBundleName(bundleName, killProcessesByBundleNameCallback);
    } catch (paramError) {
      console.log('error: ' + paramError.code + ', ' + paramError.message);
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
| bundleName | string | 否 | 表示包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```js
var bundleName = 'bundleName';
try {
  app.killProcessesByBundleName(bundleName)
   .then((data) => {
       console.log('------------ killProcessesByBundleName success ------------', data);
   })
   .catch((err) => {
       console.log('------------ killProcessesByBundleName fail ------------', err);
   })
} catch (paramError) {
  console.log('error: ' + paramError.code + ', ' + paramError.message);
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
| bundleName | string | 否 | 表示包名。 |
| callback | AsyncCallback\<void> | 否 | 表示指定的回调方法。 |

**示例：**
    
  ```js
    var bundleName = 'bundleName';
    function clearUpApplicationDataCallback(err, data) {
      if (err) {
          console.log('------------- clearUpApplicationDataCallback fail, err: --------------', err);
      } else {
          console.log('------------- clearUpApplicationDataCallback success, data: --------------', data);
      }
    }
    try {
      app.clearUpApplicationData(bundleName, clearUpApplicationDataCallback);
    } catch (paramError) {
      console.log('error: ' + paramError.code + ', ' + paramError.message);
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
| bundleName | string | 否 | 表示包名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
  ```js
  var bundleName = 'bundleName';
  try {
    app.clearUpApplicationData(bundleName)
      .then((data) => {
        console.log('------------ clearUpApplicationData success ------------', data);
      })
      .catch((err) => {
        console.log('------------ clearUpApplicationData fail ------------', err);
      })
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }

  ```

## ApplicationStateObserver.onForegroundApplicationChanged

onForegroundApplicationChanged(appStateData: AppStateData): void;

将在前台或后台应用程序更改时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](#appstatedata) | 否 | 状态更改的应用程序信息。 |

**示例：**
    
```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }

```

## ApplicationStateObserver.onAbilityStateChanged

onAbilityStateChanged(abilityStateData: AbilityStateData): void;

将在能力状态更改时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityStateData | [AbilityStateData](#abilitystatedata) | 否 | 状态更改的能力信息。 |

**示例：**
    
```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }
```

## ApplicationStateObserver.onProcessCreated

onProcessCreated(processData: ProcessData): void;

将在创建进程时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](#processdata) | 否 | 进程信息。 |

**示例：**
    
```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }
```

## ApplicationStateObserver.onProcessDied

onProcessDied(processData: ProcessData): void;

将在进程终止时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](#processdata) | 否 | 进程信息。 |

**示例：**
    
```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }
```

## ApplicationStateObserver.onProcessStateChanged

 onProcessStateChanged(processData: ProcessData): void;

当进程状态更改时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](#processdata) | 否 | 进程信息。 |

**示例：**
    
```js
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
  try {
    const observerCode = app.on("applicationState", applicationStateObserver);
    console.log('-------- observerCode: ---------', observerCode);
  } catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
  }
```

## AppStateData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称        | 可读    | 可写     | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- |-------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName     | 是    | 否      | string               | 否   | 包名。                                |
| uid   | 是    | 否      | number               | 否   | 用户ID。 |
| state  | 是    | 否      | number               | 否   | 应用状态。 |

## AbilityStateData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid                     | number   | 是   | 否   | 进程ID。                    |
| bundleName              | string   | 是   | 否  | 应用包名。                  |
| abilityName             | string   | 是   | 否   | Ability名称。               |
| uid                     | number   | 是   | 否   | 用户ID。                  |
| state                   | number   | 是   | 否   | Ability状态。                |
| moduleName | string   | 是   | 否   | Ability所属的HAP包的名称。    |
| abilityType | string   | 是   | 否   | 能力类型、页面或服务等。    |

## ProcessData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid         | number   | 是   | 否   | 进程ID。                    |
| bundleName  | string   | 是   | 否  | 应用包名。                  |
| uid         | number   | 是   | 否   | 用户ID。                  |
| isContinuousTas         | boolean   | 是   | 否   | 判断过程是否为连续任务。                  |
| isKeepAlive        | boolean   | 是   | 否   | 判断该过程是否保持活跃。                  |

## ProcessRunningInfo

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

| 名称        | 可读    | 可写     | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| pid     | 是    | 否      | number               | 否   | 进程ID。                                |
| uid   | 是    | 否      | number               | 否   | 用户ID。 |
| processName  | 是    | 否      | string               | 否   | 进程的名称。 |
| bundleNames          | 是    | 否      | Array\<string>              | 否   | 进程中运行的bundleName数组。 |

## ApplicationStateObserver

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| [onForegroundApplicationChanged](#applicationstateobserveronforegroundapplicationchanged)         | AsyncCallback\<void>   | 是   | 否   | 应用前后台状态发生变化时执行的回调函数。                    |
| [onAbilityStateChanged](#applicationstateobserveronabilitystatechanged)  | AsyncCallback\<void>   | 是   | 否  | ability状态发生变化时执行的回调函数。                  |
| [onProcessCreated](#applicationstateobserveronprocesscreated)         | AsyncCallback\<void>   | 是   | 否   | 进程创建时执行的回调函数。                  |
| [onProcessDied](#applicationstateobserveronprocessdied)         | AsyncCallback\<void>   | 是   | 否   | 进程销毁时执行的回调函数。                  |

## ProcessRunningInformation
   
进程的运行信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 可读    | 可写     | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| pid     | 是    | 否      | number               | 否   | 进程ID。                                |
| uid   | 是    | 否      | number               | 否   | 用户ID。 |
| processName  | 是    | 否      | string               | 否   | 进程的名称。 |
| bundleNames          | 是    | 否      | Array\<string>              | 否   | 进程中运行的bundleName数组。 | 

## ApplicationState

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 描述                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |   当应用在创建中的时候处于的状态。         |
| STATE_FOREGROUND          | 2   |      当应用切换到前台的时候处于的状态。            |
| STATE_ACTIVE  | 3   |         当应用在获焦的时候处于的状态。     |
| STATE_BACKGROUND        | 4   |       当应用处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |           当应用在销毁的时候处于的状态。       |

## ProcessState

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 描述                               |
| -------------------- | --- | --------------------------------- |
| STATE_CREATE    | 1   |      当进程在创建中的时候处于的状态。       |
| STATE_FOREGROUND          | 2   |            当进程切换到前台的时候处于的状态。      |
| STATE_ACTIVE  | 3   |          当进程在获焦的时候处于的状态。   |
| STATE_BACKGROUND        | 4   |       当进程处于后台不可见时处于的状态。           |
| STATE_DESTROY        | 5   |         当进程在销毁的时候处于的状态。         |
