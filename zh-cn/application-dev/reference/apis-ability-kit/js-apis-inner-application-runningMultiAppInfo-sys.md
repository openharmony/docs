# RunningMultiAppInfo (系统接口)

定义应用多开在运行态的结构信息。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 使用说明

通过appManager的[getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12)来获取。

## RunningMultiAppInfo

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                      | 类型   | 只读  | 可选  | 说明       |
| ------------------------- | ------ | ---- | ---- | --------- |
| bundleName | string | 否  | 否  | 应用的包名。 |
| mode | [MultiAppMode](js-apis-inner-application-multiAppMode-sys.md) | 否  | 否  | 应用多开模式。 |
| runningAppClones | Array<[RunningAppClone](js-apis-inner-application-runningAppClone-sys.md)> | 否  | 是  | 特定包名在运行态的分身应用信息。 |
| runningMultiInstances<sup>14+</sup> | Array<[RunningMultiInstanceInfo](js-apis-inner-application-runningMultiInstanceInfo-sys.md)> | 否  | 是  | 特定包名在运行态的多实例应用信息。 |

**示例：**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let bundleName = "ohos.samples.etsclock";
  appManager.getRunningMultiAppInfo(bundleName)
    .then((info: appManager.RunningMultiAppInfo) => {
      console.info(`getRunningMultiAppInfo success, data: ${JSON.stringify(info)}`);
    }).catch((err: BusinessError) => {
    console.error(`getRunningMultiAppInfo failed, code: ${err.code}, msg:${err.message}`);
  })
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`getRunningMultiAppInfo error, code: ${code}, msg:${msg}`);
}
```
