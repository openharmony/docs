# RunningAppClone (System API)

The RunningAppClone module defines the information of an application clone in the running state.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## How to Use

The RunningAppClone struct is obtained from [getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12) of **appManager**.

## RunningAppClone

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                     | Type  | Read-Only | Optional | Description      |
| ------------------------- | ------ | ---- |  ---- | --------- |
| appCloneIndex | number | No | No | Index of an application clone.|
| uid | number | No | No | UID of the application.|
| pids | Array\<number> | No | No | Process ID set of the application.|

**Example**

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
