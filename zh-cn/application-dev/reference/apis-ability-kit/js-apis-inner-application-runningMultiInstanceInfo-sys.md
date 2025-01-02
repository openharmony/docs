# RunningMultiInstanceInfo (系统接口)

定义多实例应用在运行态的结构信息。

> **说明：**
> 
> 本模块首批接口从API version 14 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 属性

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 只读 | 可选  | 说明       |
| ------------------------- | ------ | ---- | ---- | --------- |
| instanceKey | string | 是 | 否  | 多实例应用的唯一实例标识。 |
| uid | number | 是 | 否  | 表示应用程序的UID。 |
| pids | Array\<number> | 是 | 否  | 应用的进程ID集合。 |

## 使用说明

通过appManager的[getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12)来获取。

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.etsclock";
  appManager.getRunningMultiAppInfo(bundleName).then((info: appManager.RunningMultiAppInfo) => {
      hilog.info(0x0000, 'testTag', `getRunningMultiAppInfo success`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
    })
} catch (err) {
  hilog.error(0x0000, 'testTag', `getRunningMultiAppInfo error, code: ${err.code}, msg:${err.message}`);
}
```
