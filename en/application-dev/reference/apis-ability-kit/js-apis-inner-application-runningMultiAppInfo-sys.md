# RunningMultiAppInfo (System API)

The RunningMultiAppInfo module defines the information of an application in multi-app mode in the running state.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                     | Type  | Mandatory | Description      |
| ------------------------- | ------ | ---- | --------- |
| bundleName | string | Yes | Bundle name of the application.|
| mode | [MultiAppMode](js-apis-inner-application-multiAppMode-sys.md) | Yes  | Multi-app mode.|
| runningAppClones | Array<[RunningAppClone](js-apis-inner-application-runningAppClone-sys.md)> | No | Information about application clones with the specific bundle name in the running state.|
| runningMultiInstances<sup>14+</sup> | Array<[RunningMultiInstanceInfo](js-apis-inner-application-runningMultiInstanceInfo-sys.md)> | No | Information about a multi-instance application with the specific bundle name in the running state.|

## How to Use

The **RunningMultiAppInfo** struct is obtained from [getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12) of **appManager**.

**Example**

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
