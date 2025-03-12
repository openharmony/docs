# @ohos.app.ability.continueManager (continueManager)

The continueManager module provides capabilities for managing cross-device application migration. For example, it allows you to obtain the result of quickly launching the target application during the cross-device migration process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { continueManager } from '@kit.AbilityKit';
```

## continueManager.on

on(type: 'prepareContinue', context: Context, callback: AsyncCallback&lt;ContinueResultInfo&gt;): void

Registers a callback to obtain the result of quickly launching the application during the cross-device continuity process. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedManagementService

**Parameters**

  | Name| Type                                                                                             | Mandatory| Description                                      |
  | -------- |-------------------------------------------------------------------------------------------------| -------- |------------------------------------------|
  | type | string                                                                                          | Yes| The value is fixed at **prepareContinue**.                    |
  | context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                                                                                         | Yes| Context of the ability.                        |
  | callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | Yes| Callback used to return the result. If obtaining the quick start result is successful, **err** is undefined, and **ContinueResultInfo** is the obtained quick startup result. Otherwise, **err** is an error object.|

**Example**

  ```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    storage : LocalStorage = new LocalStorage();

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1. Quick start is configured. Trigger the lifecycle callback when the application is launched immediately.
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // Register the callback to obtain the quick start result.
            this.registerQuickStartCallback();
            // If the application data to migrate is large, add a loading screen here (for example, displaying "loading" on the screen).
            // Handle issues related to custom redirection and timing.
            // ...
        }
    }
    
    async registerQuickStartCallback() : Promise<void>{
        continueManager.on("prepareContinue", this.context, (err, continueResultInfo)=>{
            if (err.code != 0) {
                console.error('register failed, cause: ' + JSON.stringify(err));
                return;
            }
            console.info('register finished, ' + JSON.stringify(continueResultInfo));
        });
    }
}
  ```

## continueManager.off

off(type: 'prepareContinue', context: Context, callback: AsyncCallback&lt;ContinueResultInfo&gt;): void

Unregisters the callback used to obtain the result of quickly launching the application during the cross-device continuity process. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.DistributedManagementService

**Parameters**

| Name| Type                                | Mandatory| Description                                  |
  | -------- |------------------------------------| -------- |--------------------------------------|
| type | string                             | Yes| The value is fixed at **prepareContinue**.                |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | Yes| Context of the ability.                    |
| callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | Yes| Callback used to return the result. If the callback is unregistered, **err** is undefined, and **ContinueResultInfo** is the callback unregistration result. Otherwise, **err** is an error object.|

**Example**

  ```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    storage : LocalStorage = new LocalStorage();

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1. Quick start is configured. Trigger the lifecycle callback when the application is launched immediately.
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // Register the callback to obtain the quick start result.
            this.registerQuickStartCallback();
            // If the application data to migrate is large, add a loading screen here (for example, displaying "loading" on the screen).
            // Handle issues related to custom redirection and timing.
            // ...
        }
    }
    
    async registerQuickStartCallback() : Promise<void>{
        continueManager.off("prepareContinue", this.context, (err, continueResultInfo)=>{
            if (err.code != 0) {
                console.error('register failed, cause: ' + JSON.stringify(err));
                return;
            }
            console.info('register finished, ' + JSON.stringify(continueResultInfo));
        });
    }
}
  ```

## ContinueResultInfo

Describes the quick start result returned by the callback.

**System capability**: SystemCapability.Ability.DistributedManagementService

| Name| Type                                                                           | Read-Only| Optional| Description      |
| -------- |-------------------------------------------------------------------------------|----|----|----------|
| resultState | [ContinueStateCode](js-apis-app-ability-continueManager.md#continuestatecode) | Yes | No | Status code of the operation result.|
| resultInfo | string                                                                        | No | Yes | Description of the operation result.|

## ContinueStateCode

Enumerates the status codes of the quick start result.

**System capability**: SystemCapability.Ability.DistributedManagementService

| Name| Value | Description   | 
| -------- |----|-------|
| SUCCESS  | 0  | Operation succeeded.| 
| SYSTEM_ERROR | Others| Operation failed.| 
