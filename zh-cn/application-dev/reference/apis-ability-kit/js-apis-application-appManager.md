# @ohos.application.appManager (appManager)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->
<!--deprecated_code_no_check-->

appManager模块提供应用管理的能力，包括查询当前系统是否处于稳定性测试场景、查询当前设备是否为RAM（Random Access Memory，随机存取存储器）受限设备、获取当前应用程序可以使用的最大内存值、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 8 开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.appManager](js-apis-app-ability-appManager.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import appManager from '@ohos.application.appManager';
```

## appManager.isRunningInStabilityTest

isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前系统是否处于稳定性测试场景。使用callback异步回调。

> **说明：**
>
> 稳定性测试场景指为验证应用在复杂、极端或长期运行条件下的可靠性而设计的特定测试环境。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 以回调方式返回接口运行结果及当前系统是否处于稳定性测试场景，可进行错误处理或其他自定义处理。返回true表示系统处于稳定性测试场景，返回false表示系统不处于稳定性测试场景。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRunningInStabilityTest((error, flag) => {
    if (error && error.code !== 0) {
      console.error(`isRunningInStabilityTest fail, error: ${JSON.stringify(error)}`);
    } else {
      console.info(`isRunningInStabilityTest success, the result is: ${JSON.stringify(flag)}`);
    }
  });
  ```


## appManager.isRunningInStabilityTest

isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前系统是否处于稳定性测试场景。使用Promise异步回调。

> **说明：**
>
> 稳定性测试场景指为验证应用在复杂、极端或长期运行条件下的可靠性而设计的特定测试环境。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise方式返回接口运行结果及当前是否处于稳定性测试场景，可进行错误处理或其他自定义处理。返回true表示系统处于稳定性测试场景，返回false表示系统不处于稳定性测试场景。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRunningInStabilityTest().then((flag) => {
    console.info(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);
  }).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
  });
  ```


## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(): Promise\<boolean>

查询当前设备是否为RAM受限设备（内存资源严重受限的设备）。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 以Promise方式返回接口运行结果及当前设备是否为RAM受限设备，可进行错误处理或其他自定义处理。true：当前设备为RAM受限设备，false：当前设备为非RAM受限设备。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRamConstrainedDevice().then((data) => {
    console.info(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void

查询当前设备是否为RAM受限设备（内存资源严重受限的设备）。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 以回调方式返回接口运行结果及当前设备是否为RAM受限设备，可进行错误处理或其他自定义处理。true：当前设备为RAM受限设备，false：当前设备为非RAM受限设备。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRamConstrainedDevice((error, data) => {
    if (error && error.code !== 0) {
      console.error(`isRamConstrainedDevice fail, error: ${JSON.stringify(error)}`);
    } else {
      console.info(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
    }
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(): Promise\<number>

获取当前应用程序可以使用的最大内存（RAM）值。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 当前应用程序可以使用的最大内存（RAM）值，可根据此值进行错误处理或其他自定义处理，单位是M。使用Promise异步回调。|

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getAppMemorySize().then((data) => {
    console.info(`The size of app memory is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(callback: AsyncCallback\<number>): void

获取当前应用程序可以使用的最大内存（RAM）值。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 是 | 获取当前应用程序可以使用的最大内存（RAM）值，可根据此值进行错误处理或其他自定义处理，单位是M。使用callback异步回调。|

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getAppMemorySize((error, data) => {
    if (error && error.code !== 0) {
      console.error(`getAppMemorySize fail, error: ${JSON.stringify(error)}`);
    } else {
      console.info(`The size of app memory is: ${JSON.stringify(data)}`);
    }
  });
  ```
## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>

获取有关运行进程的信息。使用Promise异步回调。

> 从 API Version 9 开始废弃，建议使用[appManager.getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation)替代。

**需要权限**：ohos.permission.GET_RUNNING_INFO（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessRunningInfo](js-apis-inner-application-processRunningInfo.md)>> | Promise对象，返回有关运行进程的信息。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getProcessRunningInfos().then((data) => {
    console.info(`The process running infos is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.getProcessRunningInfos<sup>(deprecated)</sup>

getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void

获取有关运行进程的信息。使用callback异步回调。

> 从 API Version 9 开始废弃，建议使用[appManager.getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation)替代。

**需要权限**：ohos.permission.GET_RUNNING_INFO（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ProcessRunningInfo](js-apis-inner-application-processRunningInfo.md)>> | 是 | 回调函数，返回有关运行进程的信息。 |

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getProcessRunningInfos((error, data) => {
    if (error && error.code !== 0) {
      console.error(`getProcessRunningInfos fail, error: ${JSON.stringify(error)}`);
    } else {
      console.info(`getProcessRunningInfos success, data: ${JSON.stringify(data)}`);
    }
  });
  ```