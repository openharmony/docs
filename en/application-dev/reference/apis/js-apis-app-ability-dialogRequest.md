# @ohos.app.ability.dialogRequest (dialogRequest)

The **dialogRequest** module provides APIs related to modal dialog box processing, including obtaining the request information (used to bind a modal dialog box) and request callback (used to set the request result).
A modal dialog box is a system pop-up box that intercepts events (such as mouse, keyboard, and touchscreen events) triggered for the page displayed under it. The page can be operated only after the modal dialog box is destroyed.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs provided by this module are used in ServiceExtensionAbilities. For a ServiceExtensionAbility that implements modal dialog boxes, you can use the APIs to obtain the request information and request callback and return the request result.

## Modules to Import

```js
import dialogRequest from '@ohos.app.ability.dialogRequest';
```

## dialogRequest.getRequestInfo

getRequestInfo(want: Want): RequestInfo

Obtains the request information from Want.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| want  | [Want](js-apis-application-want.md) | Yes  | Want passed in the request for a modal dialog box.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| [RequestInfo](#requestinfo) | **RequestInfo** object obtained, which is used to bind a modal dialog box.|

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';

    const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des) {
        super(des);
      }

      onRemoteRequest(code, data, reply, option) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      queryLocallInterface(descriptor) {
        return null;
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

      attachLocalInterface(localInterface, descriptor) {
      }
    }

    let TAG = "getRequestInfoTest";

    export default class ServiceExtAbility extends ServiceExtensionAbility {
      onCreate(want) {
        console.info(TAG, `onCreate, want: ${want.abilityName}`);
      }

      onRequest(want, startId) {
        console.info(TAG, `onRequest, want: ${want.abilityName}`);
        try {
          var requestInfo = dialogRequest.getRequestInfo(want);
        } catch (err) {
          console.error('getRequestInfo err= ${JSON.stringify(err)}');
        }
      }

      onConnect(want) {
        console.info(TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      }

      onDisconnect(want) {
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
| want  | [Want](js-apis-application-want.md) | Yes  | Want passed in the request for a modal dialog box.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| [RequestCallback](#requestcallback) | **RequestCallback** object obtained, which is used to set the return result.|

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   
   let TAG = "getRequestCallbackTest";

   const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des) {
        super(des);
      }

      onRemoteRequest(code, data, reply, option) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      queryLocallInterface(descriptor) {
        return null;
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

      attachLocalInterface(localInterface, descriptor) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want, startId) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       try {
            var requestCallback = dialogRequest.getRequestCallback(want);
        } catch(err) {
            console.error('getRequestInfo err= ${JSON.stringify(err)}');
        }
     }

     onConnect(want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }

     onDisconnect(want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

## RequestInfo

Defines the request information, which is used as an input parameter for binding the modal dialog box.
**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   import window from '@ohos.window';
   
   let TAG = "RequestInfoTest";

   const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des) {
        super(des);
      }

      onRemoteRequest(code, data, reply, option) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      queryLocallInterface(descriptor) {
        return null;
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

      attachLocalInterface(localInterface, descriptor) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want, startId) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       try {
            var requestInfo = dialogRequest.getRequestInfo(want);
            window.bindDialogTarget(requestInfo, () => {
                console.info('Dialog Window Need Destroy.');
            }, (err) => {
                if (err.code) {
                    console.error('Failed to bind dialog target. Cause: ${JSON.stringify(err)}');
                    return;
                }
                console.info('Succeeded in binding dialog target.');
            });
        } catch(err) {
            console.error('getRequestInfo err= ${JSON.stringify(err)}');
        }
     }

     onConnect(want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");

     }

     onDisconnect(want) {
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
Defines the result of the request for the modal dialog box. Only the result code is included.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| result | [ResultCode](#resultcode) | Yes| Yes| Result code of the request.|

## RequestCallback

Provides a callback for setting the modal dialog box request result.

### RequestCallback.setRequestResult

setRequestResult(result: RequestResult): void;

Sets the result of the request for the modal dialog box.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

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
   import rpc from '@ohos.rpc';
   import dialogRequest from '@ohos.app.ability.dialogRequest';
   
   let TAG = "setRequestResultTest";

      const REQUEST_VALUE = 1;

    class StubTest extends rpc.RemoteObject {
      constructor(des) {
        super(des);
      }

      onRemoteRequest(code, data, reply, option) {
        if (code === REQUEST_VALUE) {
          let optFir = data.readInt();
          let optSec = data.readInt();
          reply.writeInt(optFir + optSec);
        }
        return true;
      }

      queryLocallInterface(descriptor) {
        return null;
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

      attachLocalInterface(localInterface, descriptor) {
      }
    }

   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }

     onRequest(want, startId) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
       try {
            var requestCallback = dialogRequest.getRequestCallback(want);
            let myResult = {
                result : dialogRequest.ResultCode.RESULT_CANCEL,
            };
            requestCallback.setRequestResult(myResult);
        } catch(err) {
            console.error('getRequestInfo err= ${JSON.stringify(err)}');
        }
     }

     onConnect(want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
     }

     onDisconnect(want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }

     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
  ```
