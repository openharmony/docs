# ProcessRunningInfo
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->
<!--deprecated_code_no_check-->

运行进程信息，可以通过appManager中[getProcessRunningInfos](js-apis-application-appManager.md#appmanagergetprocessrunninginfosdeprecated)方法来获取运行进程信息。

> **说明：** 
> - 本模块接口从API version 9 开始废弃，建议使用[ProcessInformation<sup>9+</sup>](js-apis-inner-application-processInformation.md)替代。
> - 本模块首批接口从API version 8 开始支持。

## 导入模块

```ts
import appManager from '@ohos.application.appManager';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 否 | 否 | 进程ID。 |
| uid | number | 否 | 否 | 应用程序的UID。 |
| processName | string | 否 | 否 | 进程名称。 |
| bundleNames | Array&lt;string&gt; | 否 | 否 | 进程中所有运行的Bundle名称。 |

**示例：**
```ts
import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

appManager.getProcessRunningInfos().then((data) => {
    console.info(`success: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`failed: ${JSON.stringify(error)}`);
});
```
