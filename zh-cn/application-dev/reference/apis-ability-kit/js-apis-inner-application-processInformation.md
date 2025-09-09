# ProcessInformation
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

运行进程信息，可以通过appManager的[getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation)来获取运行进程信息。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 否 | 否 | 进程ID。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| uid | number | 否 | 否 | 应用程序的UID。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| processName | string | 否 | 否 | 进程名称。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| bundleNames | Array&lt;string&gt; | 否 | 否 | 进程中所有运行的Bundle名称。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| state<sup>10+</sup> | [appManager.ProcessState](js-apis-app-ability-appManager.md#processstate10)| 否 | 否 | 当前进程运行状态。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| bundleType<sup>12+</sup> | [bundleManager.BundleType](js-apis-bundleManager.md#bundletype) | 否 | 否 | 当前进程运行的包类型。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| appCloneIndex<sup>12+</sup> | number   | 否   | 是   | 分身应用索引。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。  |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';

appManager.getRunningProcessInformation((error, data) => {
  if (error) {
    console.error(`getRunningProcessInformation fail, error: ${JSON.stringify(error)}`);
  } else {
    console.info(`getRunningProcessInformation success, data: ${JSON.stringify(data)}`);
  }
});
```
