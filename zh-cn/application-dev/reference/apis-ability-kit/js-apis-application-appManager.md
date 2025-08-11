# @ohos.application.appManager (appManager)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--SE: @yzkp-->
<!--TSE: @lixueqing513-->
<!--deprecated_code_no_check-->

appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。

> **说明：**
> 
> 本模块首批接口从API version 8 开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.appManager](js-apis-app-ability-appManager.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import appManager from '@ohos.application.appManager';
```

## appManager.isRunningInStabilityTest

isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前是否处于稳定性测试场景。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示当前处于稳定性测试场景；返回false表示当前不处于稳定性测试场景。 | 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRunningInStabilityTest((error, flag) => {
    if (error && error.code !== 0) {
        console.error(`isRunningInStabilityTest fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`isRunningInStabilityTest success, the result is: ${JSON.stringify(flag)}`);
    }
  });
  ```


## appManager.isRunningInStabilityTest

isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示当前处于稳定性测试场景；返回false表示当前不处于稳定性测试场景。 | 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRunningInStabilityTest().then((flag) => {
      console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```


## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(): Promise\<boolean>

查询是否为ram受限设备。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。返回true表示是ram受限设备；返回false表示不是ram受限设备。 | 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.isRamConstrainedDevice().then((data) => {
      console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.isRamConstrainedDevice<sup>7+<sup>

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void

查询是否为ram受限设备。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示当前是ram受限设备；返回false表示当前不是ram受限设备。 | 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.isRamConstrainedDevice((error, data) => {
      if (error && error.code !== 0) {
          console.error(`isRamConstrainedDevice fail, error: ${JSON.stringify(error)}`);
      } else {
          console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);
      }
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(): Promise\<number>

获取当前应用程序可以使用的内存的值。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 获取当前应用程序可以使用的内存的值，可根据此值进行错误处理或其他自定义处理，单位是M。使用Promise异步回调。| 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';
  import { BusinessError } from '@ohos.base';

  appManager.getAppMemorySize().then((data) => {
      console.log(`The size of app memory is: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
      console.error(`error: ${JSON.stringify(error)}`);
  });
  ```

## appManager.getAppMemorySize<sup>7+<sup>

getAppMemorySize(callback: AsyncCallback\<number>): void

获取应用程序的内存大小。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 是 | 获取当前应用程序可以使用的内存的值，可根据此值进行错误处理或其他自定义处理，单位是M。使用callback异步回调。| 

**示例：**
    
  ```ts
  import appManager from '@ohos.application.appManager';

  appManager.getAppMemorySize((error, data) => {
      if (error && error.code !== 0) {
          console.error(`getAppMemorySize fail, error: ${JSON.stringify(error)}`);
      } else {
          console.log(`The size of app memory is: ${JSON.stringify(data)}`);
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
      console.log(`The process running infos is: ${JSON.stringify(data)}`);
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
          console.log(`getProcessRunningInfos success, data: ${JSON.stringify(data)}`);
      }
  });
  ```