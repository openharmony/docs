# @ohos.app.ability.dialogSession (dialogSession)

The **dialogSession** module provides APIs related to the dialog box.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import dialogSession from '@ohos.app.ability.dialogSession';
```

## DialogAbilityInfo

Provides DialogAbility information, including the bundle name, module name, and ability name.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Yes| Bundle name.|
| moduleName | string | Yes| Yes| Module name.|
| abilityName | string | Yes| Yes| Ability name.|
| abilityIconId | number | Yes| Yes| ID of the ability icon.|
| abilityLabelId | number | Yes| Yes| ID of the ability label.|
| bundleIconId | number | Yes| Yes| ID of the bundle icon.|
| bundleLabelId | number | Yes| Yes| ID of the bundle label.|

## DialogSessionInfo

Provides session information, including the requester information, target application list, and other parameters.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| callerAbilityInfo | [DialogAbilityInfo](js-apis-app-ability-dialogSession.md#dialogabilityinfo)| Yes| Yes| Ability information of the requester.|
| targetAbilityInfos | Array\<[DialogAbilityInfo](js-apis-app-ability-dialogSession.md#dialogabilityinfo)\> | Yes| Yes| Target application list.|
| parameters | Record<string, Object> | Yes| No| Other parameters.|

## getDialogSessionInfo

getDialogSessionInfo(dialogSessionId: string): [DialogSessionInfo](js-apis-app-ability-dialogSession.md#dialogsessioninfo)

Obtains the session information based on the session ID.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | Yes| Session ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [DialogSessionInfo](js-apis-app-ability-dialogSession.md#dialogsessioninfo) | Session information.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import dialogSession from '@ohos.app.ability.dialogSession';
import Want from '@ohos.app.ability.Want';

// want is specified by the system. dialogSessionId is a built-in parameter.
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// Obtain DialogSessionInfo.
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);
```

## sendDialogResult

sendDialogResult(dialogSessionId: string, targetWant: Want, isAllowed: boolean, callback: AsyncCallback\<void\>): void

Sends a request for a dialog box. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | Yes| Session ID.|
  | targetWant | Want | Yes| Target of the request.|
  | isAllowed | boolean | Yes| Request result.|
  | callback | AsyncCallback\<void\> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import dialogSession from '@ohos.app.ability.dialogSession';
import Want from '@ohos.app.ability.Want';

// want is specified by the system. dialogSessionId is a built-in parameter.
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// Obtain DialogSessionInfo.
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);

let isAllow: Boolean = true;

// When isAllow is true, targetWant is one of dialogSessionInfo.targetAbilityInfos.
let targetWant: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  dialogSession.sendDialogResult(dialogSessionId, targetWant, isAllow, (err, data) => {
    if (data) {
      console.log(`sendDialogResult success, data: ${data}`);
    } else {
      console.error(`sendDialogResult error, errorCode: ${err.code}`);
    }
  });
} catch (err) {
  console.error(`sendDialogResult error, errorCode: ${err.code}`);
}
```

## sendDialogResult

sendDialogResult(dialogSessionId: string, targetWant: Want, isAllowed: boolean): Promise\<void\>

Sends a request for a dialog box. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dialogSessionId | string | Yes| Session ID.|
  | targetWant | Want | Yes| Target of the request.|
  | isAllowed | boolean | Yes| Request result.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000005 | The specified process does not have the permission. |
| 16000006  | Cross-user operations are not allowed. |
| 16000050  | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import dialogSession from '@ohos.app.ability.dialogSession';
import Want from '@ohos.app.ability.Want';

// want is specified by the system. dialogSessionId is a built-in parameter.
let dialogSessionId: string = want?.parameters?.dialogSessionId;

// Obtain DialogSessionInfo.
let dialogSessionInfo: dialogSession.DialogSessionInfo = dialogSession.getDialogSessionInfo(dialogSessionId);

let isAllow: Boolean = true;

// When isAllow is true, targetWant is one of dialogSessionInfo.targetAbilityInfos.
let targetWant: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  dialogSession.sendDialogResult(dialogSessionId, targetWant, isAllow)
    .then((data) => {
      console.log(`startChildProcess success, pid: ${data}`);
    }, (err: BusinessError) => {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    })
} catch (err) {
  console.error(`sendDialogResult error, errorCode: ${err.code}`);
}
```
