# RunningAppClone (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

定义分身应用在运行态的结构信息，被[RunningMultiAppInfo](js-apis-inner-application-runningMultiAppInfo-sys.md)所包含。通过该结构可以获取分身应用的索引、UID和进程ID等信息，适用于需要区分和管理分身应用的场景，便于系统级应用进行应用隔离和资源管理。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 使用说明

通过appManager的[getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12)来获取。

## RunningAppClone

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 只读  | 可选  | 说明       |
| ------------------------- | ------ | ---- |  ---- | --------- |
| appCloneIndex | number | 否  | 否  | 分身应用的索引，用于标识不同的分身实例。索引从0开始，按分身创建顺序递增，0表示主应用实例，1及以上表示分身实例。 |
| uid | number | 否  | 否  | 表示应用的UID。 |
| pids | Array\<number> | 否  | 否  | 应用的进程ID集合，包含应用所有运行的进程ID。一个应用可能运行多个进程，因此返回数组。 |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName: string = 'ohos.samples.etsclock';
  appManager.getRunningMultiAppInfo(bundleName).then((info: appManager.RunningMultiAppInfo) => {
      hilog.info(0x0000, 'testTag', `getRunningMultiAppInfo success`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
}
```
