# @ohos.application.StaticSubscriberExtensionContext (StaticSubscriberExtensionContext)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The **StaticSubscriberExtensionContext** module, inherited from **ExtensionContext**, provides context for StaticSubscriberExtensionAbilities.

You can use the APIs of this module to start StaticSubscriberExtensionAbilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { StaticSubscriberExtensionContext } from '@kit.BasicServicesKit';
```

## Usage

Before using the **StaticSubscriberExtensionContext** module, you must first obtain a **StaticSubscriberExtensionAbility** instance.

```ts
import { StaticSubscriberExtensionAbility, StaticSubscriberExtensionContext } from '@kit.BasicServicesKit';
```

## StaticSubscriberExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability that belongs to the same application as this StaticSubscriberExtensionAbility. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.

**Required permissions**: ohos.permission.START_ABILITIES_FROM_BACKGROUND

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                      |
| -------- | ----------------------------------- | ---- | -------------------------- |
| want     | [Want](../apis-ability-kit/js-apis-wantAgent.md) | Yes  | Want information about the target ability.   |
| callback | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.      |
| 16000001 | The specified ability does not exist.                        |
| 16000002 | Incorrect ability type.                                      |
| 16000004 | Cannot start an invisible component.                           |
| 16000005 | The specified process does not have the permission.          |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |
| 16000053 | The ability is not on the top of the UI.                     |
| 16000055 | Installation-free timed out.                                 |
| 16200001 | The caller has been released.                                |
| 16300003 | The target application is not the current application.       |

**Example**

  ```ts
import { commonEventManager, BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  bundleName: "com.example.myapp",
  abilityName: "MyAbility"
};

class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
  onReceiveEvent(event: commonEventManager.CommonEventData) {
    console.info(`onReceiveEvent, event: ${JSON.stringify(event)}`);

    try {
      this.context.startAbility(want, (error: BusinessError) => {
        if (error) {
          // Process service logic errors.
          console.error(`startAbility failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}.`);
          return;
        }
        // Carry out normal service processing.
        console.info('startAbility succeed');
      });
    } catch (paramError) {
      // Process input parameter errors.
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`startAbility failed, error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}.`);
    }
  }
}
  ```

## StaticSubscriberExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

Starts an ability that belongs to the same application as this StaticSubscriberExtensionAbility. This API uses a promise to return the result.

Observe the following when using this API:
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **visible** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.

**Required permissions**: ohos.permission.START_ABILITIES_FROM_BACKGROUND

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type                               | Mandatory| Description                   |
| ------ | ----------------------------------- | ---- | ----------------------- |
| want   | [Want](../apis-ability-kit/js-apis-wantAgent.md) | Yes  | Want information about the target ability.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Params error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.      |
| 16000001 | The specified ability does not exist.                        |
| 16000002 | Incorrect ability type.                                      |
| 16000004 | Cannot start an invisible component.                           |
| 16000005 | The specified process does not have the permission.          |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |
| 16000053 | The ability is not on the top of the UI.                     |
| 16000055 | Installation-free timed out.                                 |
| 16200001 | The caller has been released.                                |
| 16300003 | The target application is not the current application.       |

**Example**

  ```ts
import { commonEventManager, BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let want: Want = {
  bundleName: "com.example.myapp",
  abilityName: "MyAbility"
};

class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
  onReceiveEvent(event: commonEventManager.CommonEventData) {
    console.info(`onReceiveEvent, event: ${JSON.stringify(event)}`);
    try {
      this.context.startAbility(want)
        .then(() => {
          // Carry out normal service processing.
          console.info('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // Process service logic errors.
          console.error(`startAbility failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}.`);
        });
    } catch (paramError) {
      // Process input parameter errors.
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.error(`startAbility failed, error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}.`);
    }
  }
}
  ```
