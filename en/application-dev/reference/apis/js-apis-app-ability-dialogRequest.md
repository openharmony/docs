# @ohos.app.ability.dialogRequest (dialogRequest)

The **dialogRequest** module provides APIs related to modal dialog box processing, including obtaining the request information (used to bind a modal dialog box) and request callback (used to set the request result).
A modal dialog box is a system pop-up box that intercepts events (such as mouse, keyboard, and touchscreen events) triggered for the page displayed under it. The page can be operated only after the modal dialog box is destroyed.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs provided by this module are used in ServiceExtensionAbilities. For a ServiceExtensionAbility that implements modal dialog boxes, you can use the APIs to obtain the request information and request callback and return the request result.

## Modules to Import

```ts
import dialogRequest from '@ohos.app.ability.dialogRequest';
```

## dialogRequest.getRequestInfo

getRequestInfo(want: Want): RequestInfo

Obtains the request information from Want.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| want  | [Want](js-apis-app-ability-want.md) | Yes  | Want passed in the request for a modal dialog box.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| [RequestInfo](#requestinfo) | **RequestInfo** object obtained, which is used to bind a modal dialog box.|

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';

    const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      getInterfaceDescriptor() {
        return "";
      }

      getCallingPid() {
        return REQUEST_VALUE;
      }

      getCallingUid() {
        return REQUEST_VALUE;
      }

      attachLocalInterface(localInterface: rpc.IRemoteBroker, descriptor: string) {
      }
    }

    let TAG = "getRequestInfoTest";

    export default class ServiceExtAbility extends ServiceExtensionAbility {
      onCreate(want: Want) {
        console.info(TAG, `onCreate, want: ${want.abilityName}`);
      }

      onRequest(want: Want, startId: number) {
        console.info(TAG, `onRequest, want: ${want.abilityName}`);
        try {
          let requestInfo = dialogRequest.getRequestInfo(want);
        } catch (err) {
          console.error(`getRequestInfo err= ${JSON.stringify(err)}`);
        }
      }

      onConnect(want: Want) {
        console.info(TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      }

      onDisconnect(want: Want) {
        console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
      }

      onDestroy() {
        console.info(TAG, `onDestroy`);
      }
    }
   ```

## dialogRequest.getRequestCallback

getRequestCallback(want: Want): RequestCallback

Obtains the request callback from Want.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| want  | [Want](js-apis-app-ability-want.md) | Yes  | Want passed in the request for a modal dialog box.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| [RequestCallback](#requestcallback) | **RequestCallback** object obtained, which is used to set the return result.|

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   
   let TAG = "getRequestCallbackTest";

   const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      getInterfaceDescriptor() {
        return "";
      }

      getCallingPid() {
        return REQUEST_VALUE;
      }

      getCallingUid() {
        return REQUEST_VALUE;
      }

      attachLocalInterface(localInterface: rpc.IRemoteBroker, descriptor: string) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want: Want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want: Want, startId: number) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       try {
            let requestCallback = dialogRequest.getRequestCallback(want);
        } catch(err) {
            console.error(`getRequestInfo err= ${JSON.stringify(err)}`);
        }
     }

     onConnect(want: Want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }

     onDisconnect(want: Want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

## WindowRect<sup>10+</sup>

Defines the location attributes of a modal dialog box.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| left  | number | No  | X-coordinate of the upper left corner of the dialog box.|
| top  | number | No  | Y-coordinate of the upper left corner of the dialog box.|
| width  | number | No  | Width of the dialog box.|
| height  | number | No  | Height of the dialog box.|

## RequestInfo

Defines the request information, which is used as an input parameter for binding the modal dialog box.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type      | Mandatory  | Description    |
| ------------ | ------------------| ------ | ---------------------- |
| windowRect<sup>10+</sup>            | windowRect    | No  | Location attributes of a modal dialog box.         |

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   import window from '@ohos.window';
   
   let TAG = "RequestInfoTest";

   const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      getInterfaceDescriptor() {
        return "";
      }

      getCallingPid() {
        return REQUEST_VALUE;
      }

      getCallingUid() {
        return REQUEST_VALUE;
      }

      attachLocalInterface(localInterface: rpc.IRemoteBroker, descriptor: string) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want: Want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want: Want, startId: number) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       let windowClass: window.Window | undefined = undefined;
       let config: window.Configuration = {name: "dialogWindow", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context};
       try {
            let requestInfo = dialogRequest.getRequestInfo(want);
            window.createWindow(config, (err, data) => {
              if (err.code) {
                  console.error('Failed to create the window. Cause: ' + JSON.stringify(err));
                  return;
              }
              windowClass = data;
              windowClass.bindDialogTarget(requestInfo, () => {
                console.info('Dialog Window Need Destroy.');
              }, (err: BusinessError) => {
                  if (err.code) {
                      console.error(`Failed to bind dialog target. Cause: ${JSON.stringify(err)}`);
                      return;
                  }
                  console.info('Succeeded in binding dialog target.');
              });
            });
        } catch(err) {
            console.error(`getRequestInfo err= ${JSON.stringify(err)}`);
        }
     }

     onConnect(want: Want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }

     onDisconnect(want: Want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

## ResultCode

Enumerates the result codes of the request for the modal dialog box.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Value         | Description    |
| ------------ | ------------------ | ---------------------- |
| RESULT_OK            | 0          | The request succeeds.         |
| RESULT_CANCEL        | 1          | The request fails.         |

## RequestResult
Defines the result of the request for the modal dialog box. It contains **ResultCode** and **ResultWant**.

## Attributes

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| result | [ResultCode](#resultcode) | Yes| Yes| Result code of the request.|
| want<sup>10+</sup> | [ResultWant](js-apis-app-ability-want.md)  | Yes| Yes| Want information, such as the ability name and bundle name.|

## RequestCallback

Provides a callback for setting the modal dialog box request result.

**Model restriction**: This API can be used only in the stage model.

### RequestCallback.setRequestResult

setRequestResult(result: RequestResult): void;

Sets the result of the request for the modal dialog box.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| result | [RequestResult](#requestresult) | Yes| Request result to set.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import Want from '@ohos.app.ability.Want';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   
   let TAG = "setRequestResultTest";

      const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      getInterfaceDescriptor() {
        return "";
      }

      getCallingPid() {
        return REQUEST_VALUE;
      }

      getCallingUid() {
        return REQUEST_VALUE;
      }

      attachLocalInterface(localInterface: rpc.IRemoteBroker, descriptor: string) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want: Want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want: Want, startId: number) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       try {
            let requestCallback = dialogRequest.getRequestCallback(want);
            let myResult: dialogRequest.RequestResult = {
                result : dialogRequest.ResultCode.RESULT_CANCEL,
            };
            requestCallback.setRequestResult(myResult);
        } catch(err) {
            console.error(`getRequestInfo err= ${JSON.stringify(err)}`);
        }
     }

     onConnect(want: Want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }

     onDisconnect(want: Want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
  ```
