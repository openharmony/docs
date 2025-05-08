# @ohos.abilityConnectionManager (Cross-Device Connection Management)

The **abilityConnectionManager** module provides APIs for cross-device connection management. After successful networking between devices (login with the same account and enabling of Bluetooth on the devices), a system application and a third-party application can start a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) of the same application across these devices to establish a Bluetooth connection. This way, data (specifically, text) can be transmitted across the devices over the connection.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.createAbilityConnectionSession

createAbilityConnectionSession(serviceName:&nbsp;string,&nbsp;context:&nbsp;Context,&nbsp;peerInfo:&nbsp;PeerInfo ,&nbsp;connectOptions:&nbsp;ConnectOptions):&nbsp;number

Creates a collaboration session between applications.

**Required permissions**: ohos.permission.INTERNET, ohos.permission.GET_NETWORK_INFO, ohos.permission.SET_NETWORK_INFO, and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| serviceName  | string | Yes   | Service name for the application. The service name must be the same on the local end and peer end. The value contains a maximum of 256 characters.|
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes| Application context.|
| peerInfo  | [PeerInfo](#peerinfo)               | Yes   | Collaboration information of the peer end.|
| connectOptions  | [ConnectOptions](#connectoptions)               | Yes   | Connection options for the application.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| number | ID of the collaboration session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

1. On device A, an application calls **createAbilityConnectionSession()** to create a collaboration session and return the session ID.

   ```ts
   import { abilityConnectionManager, distributedDeviceManager } from '@kit.DistributedServiceKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
 
   let dmClass: distributedDeviceManager.DeviceManager;
 
   function initDmClass(): void {
     try {
       dmClass = distributedDeviceManager.createDeviceManager('com.example.remotephotodemo');
     } catch (err) {
       hilog.error(0x0000, 'testTag', 'createDeviceManager err: ' + JSON.stringify(err));
     }
   }
 
   function getRemoteDeviceId(): string | undefined {
     initDmClass();
     if (typeof dmClass === 'object' && dmClass !== null) {
       hilog.info(0x0000, 'testTag', 'getRemoteDeviceId begin');
       let list = dmClass.getAvailableDeviceListSync();
       if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
         hilog.info(0x0000, 'testTag', 'getRemoteDeviceId err: list is null');
         return;
       }
       if (list.length === 0) {
         hilog.info(0x0000, 'testTag', 'getRemoteDeviceId err: list is empty');
         return;
       }
       return list[0].networkId;
     } else {
       hilog.info(0x0000, 'testTag', 'getRemoteDeviceId err: dmClass is null');
       return;
     }
   }
 
   const peerInfo: abilityConnectionManager.PeerInfo = {
     deviceId: "sinkDeviceId",
     bundleName: 'com.example.remotephotodemo',
     moduleName: 'entry',
     abilityName: 'EntryAbility',
     serviceName: 'collabTest'
   };
   const myRecord: Record<string, string> = {
     "newKey1": "value1",
   };
 
   const options: Record<string, string> = {
     'ohos.collabrate.key.start.option': 'ohos.collabrate.value.foreground',
   };
 
   const connectOptions: abilityConnectionManager.ConnectOptions = {
     needSendBigData: true,
     needSendStream: false,
     needReceiveStream: true,
     options: options,
     parameters: myRecord
   };
   let context = getContext(this) as common.UIAbilityContext;
   try {
     this.sessionId = abilityConnectionManager.createAbilityConnectionSession("collabTest", context, peerInfo, connectOptions);
     hilog.info(0x0000, 'testTag', 'createSession sessionId is', this.sessionId);
   } catch (error) {
     hilog.error(0x0000, 'testTag', error);
   }
   ```

2. On device B, **createAbilityConnectionSession** can be called in **onCollaborate**, which is triggered when the application is started.

   ```ts
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { abilityConnectionManager } from '@kit.DistributedServiceKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
 
   export default class EntryAbility extends UIAbility {
     onCollaborate(wantParam: Record<string, Object>): AbilityConstant.OnCollaborateResult {
       hilog.info(0x0000, 'testTag', '%{public}s', 'on collaborate');
       let param = wantParam["ohos.extra.param.key.supportCollaborateIndex"] as Record<string, Object>
       this.onCollab(param);
       return 0;
     }
 
     onCollab(collabParam: Record<string, Object>) {
       const sessionId = this.createSessionFromWant(collabParam);
       if (sessionId == -1) {
         hilog.info(0x0000, 'testTag', 'Invalid session ID.');
         return;
       }
     }
 
     createSessionFromWant(collabParam: Record<string, Object>): number {
       let sessionId = -1;
       const peerInfo = collabParam["PeerInfo"] as abilityConnectionManager.PeerInfo;
       if (peerInfo == undefined) {
         return sessionId;
       }
 
       const options = collabParam["ConnectOptions"] as abilityConnectionManager.ConnectOptions;
       options.needSendBigData = true;
       options.needSendStream = true;
       options.needReceiveStream = false;
       try {
         sessionId = abilityConnectionManager.createAbilityConnectionSession("collabTest", this.context, peerInfo, options);
         AppStorage.setOrCreate('sessionId', sessionId);
         hilog.info(0x0000, 'testTag', 'createSession sessionId is' + sessionId);
       } catch (error) {
         hilog.error(0x0000, 'testTag', error);
       }
       return sessionId;
     }
   }
   ```

## abilityConnectionManager.destroyAbilityConnectionSession

destroyAbilityConnectionSession(sessionId:&nbsp;number):&nbsp;void

Destroys a collaboration session between applications.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | number  | Yes   | Collaboration session ID.  |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'destroyAbilityConnectionSession called');
  abilityConnectionManager.destroyAbilityConnectionSession(this.sessionId);
  ```

## abilityConnectionManager.getPeerInfoById

getPeerInfoById(sessionId:&nbsp;number):&nbsp;PeerInfo&nbsp;|&nbsp;undefined

Obtains information about the peer application in the specified session.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | number  | Yes   | ID of the collaboration session.  |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| PeerInfo | Information about the peer application.|
| undefined | Unknown situation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'getPeerInfoById called');
  const peerInfo = abilityConnectionManager.getPeerInfoById(this.sessionId);
  ```

## abilityConnectionManager.connect

connect(sessionId:&nbsp;number):&nbsp;Promise&lt;ConnectResult&gt;

Sets up a UIAbility connection after a collaboration session is created and the session ID is obtained.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| sessionId | number | Yes   | ID of the collaboration session.   |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;ConnectResult&gt; | Promise used to return the [connection result](#connectresult).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

After an application sets up a collaboration session and obtains the session ID on device A, it calls **connect()** to set up a UIAbility connection and start the application on device B.

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.connect(this.sessionId).then((ConnectResult) => {
    if (!ConnectResult.isConnected) {
      hilog.info(0x0000, 'testTag', 'connect failed');
      return;
    }
  }).catch(() => {
    hilog.error(0x0000, 'testTag', "connect failed");
  })
  ```

## abilityConnectionManager.acceptConnect

acceptConnect(sessionId:&nbsp;number,&nbsp;token:&nbsp;string):&nbsp;Promise&lt;void&gt;

Accepts the UIAbility connection after a collaboration session is set up and the session ID is obtained.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaboration session.   |
| token | string | Yes   | Token value passed by the application on device A.   |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

After **createAbilityConnectionSession** is called on device A to create a collaboration session and the session ID is obtained, the application on device B can call **acceptConnect** to accept the connection.

  ```ts
  import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    }

    onCollaborate(wantParam: Record<string, Object>): AbilityConstant.OnCollaborateResult {
      hilog.info(0x0000, 'testTag', '%{public}s', 'on collaborate');
      let param = wantParam["ohos.extra.param.key.supportCollaborateIndex"] as Record<string, Object>
      this.onCollab(param);
      return 0;
    }

    onCollab(collabParam: Record<string, Object>) {
      const sessionId = this.createSessionFromWant(collabParam);
      if (sessionId == -1) {
        hilog.info(0x0000, 'testTag', 'Invalid session ID.');
        return;
      }
      const collabToken = collabParam["ohos.dms.collabToken"] as string;
      abilityConnectionManager.acceptConnect(sessionId, collabToken).then(() => {
        hilog.info(0x0000, 'testTag', 'acceptConnect success');
      }).catch(() => {
        hilog.error("failed");
      })
    }

    createSessionFromWant(collabParam: Record<string, Object>): number {
      let sessionId = -1;
      const peerInfo = collabParam["PeerInfo"] as abilityConnectionManager.PeerInfo;
      if (peerInfo == undefined) {
        return sessionId;
      }

      const options = collabParam["ConnectOptions"] as abilityConnectionManager.ConnectOptions;
      options.needSendBigData = true;
      options.needSendStream = true;
      options.needReceiveStream = false;
      try {
        sessionId = abilityConnectionManager.createAbilityConnectionSession("collabTest", this.context, peerInfo, options);
        AppStorage.setOrCreate('sessionId', sessionId);
        hilog.info(0x0000, 'testTag', 'createSession sessionId is' + sessionId);
      } catch (error) {
        hilog.error(0x0000, 'testTag', error);
      }
      return sessionId;
    }
  }
  ```

## abilityConnectionManager.disconnect

disconnect(sessionId:&nbsp;number):&nbsp;void

Disconnects the UIAbility connection to end the collaboration session.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description       |
| --------- | ------------------------------------- | ---- | --------- |
| sessionId | number | Yes   | ID of the collaboration session.    |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'disconnectRemoteAbility begin');
  if (this.sessionId == -1) {
    hilog.info(0x0000, 'testTag', 'Invalid session ID.');
  return;
  }
  abilityConnectionManager.disconnect(this.sessionId);
  ```

## abilityConnectionManager.reject

reject(token:&nbsp;string,&nbsp;reason:&nbsp;string):&nbsp;void;

Rejects a connection requet in multi-device application collaboration. After a connection request sent from the peer application is rejected, a rejection reason is returned.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| token | string | Yes   | Token used for application collaboration management.   |
| reason | string | Yes   | Reason why the connection is rejected.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'reject begin');
  const collabToken = collabParam["ohos.dms.collabToken"] as string;
  const reason = "test";
  abilityConnectionManager.reject(collabToken, reason);
  ```

## abilityConnectionManager.on('connect')

on(type:&nbsp;'connect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Enables listening for **connect** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **connect**. This event is triggered when [abilityConnectionManager.connect()](#abilityconnectionmanagerconnect) is called.  |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("connect", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session connect, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('connect')

off(type:&nbsp;'connect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Disables listening for **connect** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **connect**.   |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("connect", this.sessionId);

  ```

## abilityConnectionManager.on('disconnect')

on(type:&nbsp;'disconnect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Enables listening for **disconnect** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **disconnect**. This event is triggered when [abilityConnectionManager.disconnect()](#abilityconnectionmanagerdisconnect) is called.  |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("disconnect", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session disconnect, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('disconnect')

off(type:&nbsp;'disconnect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Disables listening for **disconnect** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **disconnect**.   |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("disconnect", this.sessionId);

  ```

## abilityConnectionManager.on('receiveMessage')

on(type:&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Enables listening for **receiveMessage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **receiveMessage**. This event is triggered when [abilityConnectionManager.sendMessage()](#abilityconnectionmanagersendmessage) is called.  |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("receiveMessage", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'receiveMessage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('receiveMessage')

off(type:&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Disables listening for **receiveMessage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **receiveMessage**.   |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("receiveMessage", this.sessionId);

  ```

## abilityConnectionManager.on('receiveData')

on(type:&nbsp;'receiveData',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Enables listening for **receiveData** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **receiveData**. This event is triggered when [abilityConnectionManager.sendData()](#abilityconnectionmanagersenddata) is called.  |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("receiveData", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'receiveData, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('receiveData')

off(type:&nbsp;'receiveData',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Disables listening for **receiveData** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type. This field has a fixed value of **receiveData**.   |
| sessionId | number  | Yes   | ID of the collaboration session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("receiveData", this.sessionId);

  ```

## abilityConnectionManager.sendMessage

sendMessage(sessionId:&nbsp;number,&nbsp;msg:&nbsp;string):&nbsp;Promise&lt;void&gt;

Sends text messages after a collaboration session is set up.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaboration session.|
| msg | string | Yes   | Text content. The maximum size of the text content is 1 KB.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.sendMessage(this.sessionId, "message send success").then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.error(0x0000, 'testTag', "connect failed");
  })
  ```

## abilityConnectionManager.sendData

sendData(sessionId:&nbsp;number,&nbsp;data:&nbsp;ArrayBuffer):&nbsp;Promise&lt;void&gt;

Sends [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) byte streams from one device to another after a connection is successfully established.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaboration session.|
| data | [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) | Yes   | Byte stream information.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let textEncoder = util.TextEncoder.create("utf-8");
  const arrayBuffer  = textEncoder.encodeInto("data send success");

  abilityConnectionManager.sendData(this.sessionId, arrayBuffer.buffer).then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.info(0x0000, 'testTag', "sendMessage failed");
  })
  ```

## PeerInfo

Defines the application collaboration information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name                   | Type      |Read Only  | Optional  | Description                |
| ----------------- | ------ | ----  | ---- | ------------------ |
| deviceId          | string | Yes   |Yes   | Peer device ID.    |
| bundleName        | string | Yes   |Yes   | Bundle name of the application.|
| moduleName        | string | Yes   |Yes   | Module name of the peer application.|
| abilityName       | string | Yes   |Yes    | Ability name of the peer application.|
| serviceName       | string | Yes   |No    | Service name for the application.|

## ConnectOptions

Connection options for the application.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name         | Type   | Read Only  | Optional  | Description         |
| ----------- | ------- | ---- | ---- | ----------- |
| needSendData    | boolean  | No   | No   | Whether to send data. The value **true** indicates that data needs to be sent, and the value **false** indicates the opposite.    |
| needSendStream    | boolean  | No   | No   | Whether to send streams. The value **true** indicates that streams need to be sent, and the value **false** indicates the opposite.   |
| needReceiveStream    | boolean  | No   | No   | Whether to receive streams. The value **true** indicates that streams need to be received, and the value **false** indicates the opposite.    |
| startOptions | [StartOptionParams](#startoptionparams) | No   | No   | Application startup options.|
| parameters | Record&lt;string, string&gt;  | No   | No   | Additional configuration for the connection.   |

## ConnectResult

Defines the connection result.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type  | Read Only  | Optional  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| isConnected | boolean | Yes   | Yes   | Whether the connection is successful. The value **true** indicates that the connection is successful, and the value **false** indicates the opposite.|
| errorCode | [ConnectErrorCode](#connecterrorcode) | Yes   | No   | Connection error code.|
| reason | string | Yes   | No   | Connection rejection reason.|

## EventCallbackInfo

Defines the event callback information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type   | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| sessionId | number   | Yes   | Yes   |   Collaborative session ID.|
| reason | [DisconnectReason](#disconnectreason)     | Yes   | No   |   Disconnection reason.|
| msg | string   | Yes   | No   |   Received message.|
| data  | ArrayBuffer | Yes   | No   |   Received byte stream.|
| image  | image.PixelMap | Yes   | No   |   Received image.|

## CollaborateEventInfo

Collaboration event information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type  | Read Only  | Optional  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| eventType | [CollaborateEventType](#collaborateeventtype) | Yes   | Yes   | Collaboration event type.|
| eventMsg | string | Yes   | No   | Collaboration event message.|

## ConnectErrorCode

Enumerates connection error codes.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name|  Value| Description|
|-------|-------|-------|
| CONNECTED_SESSION_EXISTS | 0 |A session already exists between applications.|
| PEER_APP_REJECTED | 1 |The peer application rejects the collaboration request.|
| LOCAL_WIFI_NOT_OPEN | 2 |Wi-Fi is disabled at the local end.|
| PEER_WIFI_NOT_OPEN | 3 |Wi-Fi is disabled at the peer end.|
| PEER_ABILITY_NO_ONCOLLABORATE | 4 |The **onCollaborate** callback is not implemented.|

## StartOptionParams

Enumerates application start options.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name|  Value| Description|
|-------|-------|-------|
| START_IN_FOREGROUND | 0 |Start of the peer application in the foreground.|
| START_IN_BACKGROUND | 1 |Start of the peer application in the background.|

## CollaborateEventType

Enumerates collaboration event types.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name|  Value| Description|
|-------|-------|-------|
| SEND_FAILURE | 0 |Task sending failure.|
| COLOR_SPACE_CONVERSION_FAILURE | 1 |Color space conversion failure.|

## DisconnectReason

Enumerates the disconnection reasons.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name|  Value| Description|
|-------|-------|-------|
| PEER_APP_CLOSE_COLLABORATION | 0 |The peer application proactively disables collaboration.|
| PEER_APP_EXIT | 1 |The peer application exits.|
| NETWORK_DISCONNECTED | 2 |The network is disconnected.|

## CollaborationKeys

Enumerates application collaboration key values.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name               |                  Value            | Description                  |
| -------------------| ------------------------------- | ---------------------- |
| PEER_INFO           | ohos.collaboration.key.peerInfo | Key value of the peer device information.|
| CONNECT_OPTIONS     | ohos.collaboration.key.connectOptions | Key value of the connection option.  |
| COLLABORATE_TYPE    | ohos.collaboration.key.abilityCollaborateType | Key value of the collaboration type.  |

## CollaborationValues

Enumerates application collaboration values.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name                                     | Value      | Description                  |
| ----------------------------------------- | -------- | ---------------------- |
| ABILITY_COLLABORATION_TYPE_DEFAULT | ohos.collaboration.value.abilityCollab | Default collaboration.|
| ABILITY_COLLABORATION_TYPE_CONNECT_PROXY  | ohos.collaboration.value.connectProxy | Collaboration via connection proxy.  |
