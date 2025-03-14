# @ohos.abilityConnectionManager (应用多端协同管理)

abilityConnectionManager模块提供了应用协同接口管理能力。设备组网成功（需登录同账号、双端打开蓝牙）后，系统应用和三方应用可以跨设备拉起同应用的一个[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)，拉起并连接成功后可实现跨设备数据传输（文本信息）。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.createAbilityConnectionSession

createAbilityConnectionSession(serverId:&nbsp;string,&nbsp;context:&nbsp;Context,&nbsp;peerInfo:&nbsp;PeerInfo ,&nbsp;connectOpt:&nbsp;ConnectOption):&nbsp;number;

创建应用间的协同会话。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| serverId  | string | 是    | 应用设置的服务名称（两端必须一致）。 |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是 | 表示应用上下文。 | 
| peerInfo  | [PeerInfo](#peerinfo)               | 是    | 对端的协同信息。 |
| connectOpt  | [ConnectOption](#connectoption)               | 是    | 应用设置的连接选项。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| number | 成功创建的协同会话ID。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

1. 在设备A上，应用需要主动调用createAbilityConnectionSession()接口创建协同会话并返回sessionId。

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
   
2. 在设备B上，对于createAbilityConnectionSession接口的调用，可在应用被拉起后触发协同生命周期函数onCollaborate时，在onCollaborate内进行。

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

销毁应用间的协同会话。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string  | 是    | 待销毁的协同应用会话ID。   |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'destroyAbilityConnectionSession called');
  abilityConnectionManager.destroyAbilityConnectionSession(this.sessionId);
  ```

## abilityConnectionManager.connect

connect(sessionId:&nbsp;number):&nbsp;Promise&lt;ConnectResult&gt;;

创建协同会话成功并获得会话ID后，设备A上可进行UIAbility的连接。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| sessionId | number | 是    | 已创建的协同会话ID。    |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;ConnectResult&gt; | 以Promise形式返回[连接结果](#connectresult)。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

设备A上的应用在创建协同会话成功并获得会话ID后，调用connect()方法启动UIAbility连接，并拉起设备B应用。

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

设备B上的应用，在创建协同会话成功并获得会话ID后，调用acceptConnect()方法接受连接。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 已创建的协同会话ID。    |
| token | string | 是    | 设备A应用传入的token值。    |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

设备B上的应用，在createAbilityConnectionSession接口调用并获取sessionId成功后，可调用acceptConnect接口来选择接受连接。

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

当协同业务执行完毕后，协同双端的任意一台设备，应断开UIAbility的连接，结束协同状态。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明        |
| --------- | ------------------------------------- | ---- | --------- |
| sessionId | number | 是    | 协同会话ID     |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

注册connect、disconnect、receiveMessage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件包括：<br/>\- `'connect'`：完成`connect()`调用，触发该事件。<br/>\- `'disconnect'`：完成`disconnect()`调用，触发该事件。<br/>\- `'receiveMessage'`：完成`sendMessage()`调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

取消connect、disconnect、receiveMessage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件包括：<br/>\- `'connect'`：完成`connect()`调用，触发该事件。<br/>\- `'disconnect'`：完成`disconnect()`调用，触发该事件。<br/>\- `'receiveMessage'`：完成`sendMessage()`调用，触发该事件。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("connect", this.sessionId);
  abilityConnectionManager.off("disconnect", this.sessionId);
  abilityConnectionManager.off("receiveMessage", this.sessionId);

  ```


## abilityConnectionManager.sendMessage

sendMessage(sessionId:&nbsp;number,&nbsp;msg:&nbsp;string):&nbsp;Promise&lt;void&gt;;

应用连接成功后，设备A或设备B可向对端设备发送文本信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 协同会话ID。 |
| msg | string | 是    | 文本信息内容（内容最大限制为1KB）。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

应用协同信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称                    | 类型       | 可读   | 可写   | 说明                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| deviceId | string | 是    | 否    | 对端设备ID。     |
| bundleName        | string | 是    | 否    | 对端应用的包名。 |
| moduleName        | string | 是    | 否    | 对端应用的模块名。 |
| abilityName        | string | 是    | 否    | 对端应用的组件名。 |
| serverId        | string | 是    | 否    | 应用设置的服务ID。 |

## ConnectOption

应用连接时所需的连接选项。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称          | 类型    | 可读   | 可写   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| needSendData    | boolean  | 是    | 是    | true代表需要传输数据，false代表不需要传输数据。     |
| needSendStream    | boolean  | 是    | 是    | true代表需要发送流，false代表不需要发送流。    |
| needReceiveStream    | boolean  | 是    | 是    | true代表需要接收流，false代表不需要接收流。     |
| options | Record&lt;string, string&gt; | 是    | 是    | 配置应用启动选项。 |
| parameters | Record&lt;string, string&gt;  | 是    | 是    | 配置连接所需的额外信息。    |

## ConnectResult

连接的结果。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| isConnected | boolean | 是    | 否    | true表示连接成功，false表示连接失败。 |
| reason | string | 是    | 否    | 表示拒绝连接的原因。 |

## EventCallbackInfo

回调方法的接收信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型    | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| sessionId | number   | 是    | shi    |   表示当前事件对应的协同会话ID。 |
| reason | [DisconnectReason](#disconnectreason)     | 是    | 否    |   表示断连原因。 |
| msg | string   | 是    | 否    |   表示接收的消息。 |
| data  | ArrayBuffer | 是    | 否    |   表示接收的字节流。 |
| image  | image.PixelMap | 是    | 否    |   表示接收的图片。 |

## DisconnectReason

当前断连原因的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 | 
| -------- | -------- |
| PEER_APP_EXIT | 表示对端应用退出。 | 
| NETWORK_DISCONNECTED | 表示网络断开原因。 | 
