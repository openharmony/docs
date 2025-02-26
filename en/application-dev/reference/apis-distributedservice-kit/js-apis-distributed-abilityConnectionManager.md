# @ohos.abilityConnectionManager (Cross-Device Connection Management)

The **abilityConnectionManager** module provides APIs for cross-device connection management. After successful networking between devices (login with the same account and enabling of Bluetooth on the devices), a system application and third-party application can start a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) of the same application across the devices. After a connection is successfully established, data can be transmitted across the devices, including strings, [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) byte streams, images, and transport streams (only text for third-party applications).

> **NOTE**
>
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.createAbilityConnectionSession

createAbilityConnectionSession(serverId:&nbsp;string,&nbsp;context:&nbsp;Context,&nbsp;peerInfo:&nbsp;PeerInfo ,&nbsp;connectOpt:&nbsp;ConnectOption):&nbsp;number;

Creates a collaborative session between applications.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| serverId  | string | Yes   | Service name for the application. The service name must be the same on the local end and peer end.|
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes| Application context.| 
| peerInfo  | [PeerInfo](#peerinfo)               | Yes   | Collaboration information of the peer end.|
| connectOpt  | [ConnectOption](#connectoption)               | Yes   | Connection options for the application.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| number | ID of the collaborative session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

1. On device A, an application calls **createAbilityConnectionSession()** to create a collaborative session and return the session ID.

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
     serverId: 'collabTest'
   };
   const myRecord: Record<string, string> = {
     "newKey1": "value1",
   };
 
   const options: Record<string, string> = {
     'ohos.collabrate.key.start.option': 'ohos.collabrate.value.foreground',
   };
 
   const connectOption: abilityConnectionManager.ConnectOption = {
     needSendBigData: true,
     needSendStream: false,
     needReceiveStream: true,
     options: options,
     parameters: myRecord
   };
   let context = getContext(this) as common.UIAbilityContext;
   try {
     this.sessionId = abilityConnectionManager.createAbilityConnectionSession("collabTest", context, peerInfo, connectOption);
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
 
       const options = collabParam["ConnectOption"] as abilityConnectionManager.ConnectOption;
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

destroyAbilityConnectionSession(sessionId:&nbsp;number):&nbsp;void;

Destroys a collaborative session between applications.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string  | Yes   | ID of the collaborative session.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'destroyAbilityConnectionSession called');
  abilityConnectionManager.destroyAbilityConnectionSession(this.sessionId);
  ```

## abilityConnectionManager.connect

connect(sessionId:&nbsp;number):&nbsp;Promise&lt;ConnectResult&gt;;

Sets up a UIAbility connection after a collaborative session is created and the session ID is obtained.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| sessionId | number | Yes   | ID of the collaborative session.   |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;ConnectResult&gt; | Promise used to return the [connection result](#connectresult).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

After an application sets up a collaborative session and obtains the session ID on device A, it calls **connect()** to set up a UIAbility connection and start the application on device B.

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

acceptConnect(sessionId:&nbsp;number,&nbsp;token:&nbsp;string):&nbsp;Promise&lt;void&gt;;

Accepts the UIAbility connection after a collaborative session is set up and the session ID is obtained.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.   |
| token | string | Yes   | Token value passed by the application on device A.   |

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

After **createAbilityConnectionSession** is called on device A to create a collaborative session and the session ID is obtained, the application on device B can call **acceptConnect** to accept the connection.

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

      const options = collabParam["ConnectOption"] as abilityConnectionManager.ConnectOption;
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

disconnect(sessionId:&nbsp;number):&nbsp;void;

Disconnects the UIAbility connection to end the collaborative session.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description       |
| --------- | ------------------------------------- | ---- | --------- |
| sessionId | number | Yes   | ID of the collaborative session.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

## abilityConnectionManager.on

on(type:&nbsp;'connect'&nbsp;|&nbsp;'disconnect'&nbsp;|&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Registers the callback listener for the **connect**, **disconnect**, and **receiveMessage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `connect`: event triggered when `connect()` is called.<br>\- `disconnect`: event is triggered when `disconnect()` is called.<br>\- `receiveMessage`: event triggered when `sendMessage()` is called.  |
| sessionId | number  | Yes   | ID of the collaborative session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("connect", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session connect, sessionId is', callbackInfo.sessionId);
  });

  abilityConnectionManager.on("disconnect", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session disconnect, sessionId is', callbackInfo.sessionId);
  });

  abilityConnectionManager.on("receiveMessage", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveMessage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off

off(type:&nbsp;'connect'&nbsp;|&nbsp;'disconnect'&nbsp;|&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Unregisters the callback listener for the **connect**, **disconnect**, and **receiveMessage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `connect`: event triggered when `connect()` is called.<br>\- `disconnect`: event is triggered when `disconnect()` is called.<br>\- `receiveMessage`: event triggered when `sendMessage()` is called.   |
| sessionId | number  | Yes   | ID of the collaborative session.   |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("connect", this.sessionId);
  abilityConnectionManager.off("disconnect", this.sessionId);
  abilityConnectionManager.off("receiveMessage", this.sessionId);

  ```


## abilityConnectionManager.sendMessage

sendMessage(sessionId:&nbsp;number,&nbsp;msg:&nbsp;string):&nbsp;Promise&lt;void&gt;;

Sends text messages after a collaborative session is set up.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| msg | string | Yes   | Text content. The maximum size of the text content is 1 KB.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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


## PeerInfo

Defines the application collaboration information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name                   | Type      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| deviceId | string | Yes   | No   | Peer device ID.    |
| bundleName        | string | Yes   | No   | Bundle name of the application.|
| moduleName        | string | Yes   | No   | Module name of the peer application.|
| abilityName        | string | Yes   | No   | Ability name of the peer application.|
| serverId        | string | Yes   | No   | Service ID for the application.|

## ConnectOption

Connection options for the application.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name         | Type   | Readable  | Writable  | Description         |
| ----------- | ------- | ---- | ---- | ----------- |
| needSendData    | boolean  | Yes   | Yes   | Whether to send data. The value **true** indicates that data needs to be sent, and the value **false** indicates the opposite.    |
| needSendStream    | boolean  | Yes   | Yes   | Whether to send streams. The value **true** indicates that streams need to be sent, and the value **false** indicates the opposite.   |
| needReceiveStream    | boolean  | Yes   | Yes   | Whether to receive streams. The value **true** indicates that streams need to be received, and the value **false** indicates the opposite.    |
| options | Record&lt;string, string&gt; | Yes   | Yes   | Application startup options.|
| parameters | Record&lt;string, string&gt;  | Yes   | Yes   | Additional configuration for the connection.   |

## ConnectResult

Defines the connection result.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| isConnected | boolean | Yes   | No   | Whether the connection is successful. The value **true** indicates that the connection is successful, and the value **false** indicates the opposite.|
| reason | string | Yes   | No   | Connection rejection reason.|

## EventCallbackInfo

Defines the event callback information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type   | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| sessionId | number   | Yes   | shi    |   Collaborative session ID.|
| reason | [DisconnectReason](#disconnectreason)     | Yes   | No   |   Disconnection reason.|
| msg | string   | Yes   | No   |   Received message.|
| data  | ArrayBuffer | Yes   | No   |   Received byte stream.|
| image  | image.PixelMap | Yes   | No   |   Received image.|

## DisconnectReason

Enumerates the disconnection reasons.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description| 
| -------- | -------- |
| PEER_APP_EXIT | Exit of the peer application.| 
| NETWORK_DISCONNECTED | Network disconnection.| 
