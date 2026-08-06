# RunningMultiInstanceInfo (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel; @Luobniz21-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

定义多实例应用在运行态的结构信息，包含实例标识、应用UID和进程ID。通过appManager的[getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12)获取，用于监控和管理多实例应用的运行状态。应用多实例相关开发指南请参见[创建应用多实例](../../quick-start/multiInstance.md)。

> **说明：**
> 
> 本模块首批接口从API version 14 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## RunningMultiInstanceInfo

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 只读 | 可选  | 说明       |
| ------------------------- | ------ | ---- | ---- | --------- |
| instanceKey | string | 否 | 否  | 多实例应用的唯一实例标识。 |
| uid | number | 否 | 否  | 表示应用的UID。 |
| pids | Array\<number> | 否 | 否  | 应用的进程ID集合。 |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let bundleName = "ohos.samples.etsclock";
  appManager.getRunningMultiAppInfo(bundleName).then((info: appManager.RunningMultiAppInfo) => {
      console.info(`getRunningMultiAppInfo success`);
    }).catch((err: BusinessError) => {
      console.error(`getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  console.error(`getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
}
```
