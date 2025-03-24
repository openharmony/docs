# @ohos.bundleState (Device Usage Statistics)

This module provides APIs for collecting statistics on device usage.

> **NOTE**
>
> The APIs of this module are deprecated since API version 9. The substitute APIs are open only to system applications.
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import bundleState from '@ohos.bundleState'
```

## bundleState.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the application specified by **bundleName** is in the idle state.  This API uses an asynchronous callback to return the result. A third-party application can only check the idle state of itself. A system application can check the idle state of other applications only when it is granted with the ohos.permission.BUNDLE_ACTIVE_INFO permission.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of an application.                          |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// When a third-party application uses the sample code, change bundleName to its own bundle name.
bundleState.isIdleState("com.ohos.camera", (err: BusinessError, res: boolean) => {
  if (err) {
    console.error('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
  } else {
    console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
  }
});
```

## bundleState.isIdleState

isIdleState(bundleName: string): Promise&lt;boolean&gt;

Checks whether the application specified by **bundleName** is in the idle state.  This API uses a promise to return the result. A third-party application can only check the idle state of itself. A system application can check the idle state of other applications only when it is granted with the ohos.permission.BUNDLE_ACTIVE_INFO permission. 

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description            |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes   | Bundle name of an application.|

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
// When a third-party application uses the sample code, change bundleName to its own bundle name.
bundleState.isIdleState("com.ohos.camera").then((res: boolean) => {
  console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.error('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
});
```
