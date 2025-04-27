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

createAbilityConnectionSession(serviceName:&nbsp;string,&nbsp;context:&nbsp;Context,&nbsp;peerInfo:&nbsp;PeerInfo ,&nbsp;connectOptions:&nbsp;ConnectOptions):&nbsp;number

创建应用间的协同会话。

**需要权限**：ohos.permission.INTERNET、ohos.permission.GET_NETWORK_INFO、ohos.permission.SET_NETWORK_INFO和ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| serviceName  | string | 是    | 应用设置的服务名称（两端必须一致），最大长度为256字符。 |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是 | 表示应用上下文。 |
| peerInfo  | [PeerInfo](#peerinfo)               | 是    | 对端的协同信息。 |
| connectOptions  | [ConnectOptions](#connectoptions)               | 是    | 应用设置的连接选项。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| number | 成功创建的协同会话ID。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

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
     serviceName: 'collabTest'
   };
   const myRecord: Record<string, string> = {
     "newKey1": "value1",
   };
 
   const connectOptions: abilityConnectionManager.ConnectOptions = {
     needSendData: true,
     startOptions: abilityConnectionManager.StartOptionParams.START_IN_FOREGROUND,
     parameters: myRecord
   };
   let context = this.getUIContext().getHostContext();
   try {
     let sessionId = abilityConnectionManager.createAbilityConnectionSession("collabTest", context, peerInfo, connectOptions);
     hilog.info(0x0000, 'testTag', 'createSession sessionId is', sessionId);
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
     onCollaborate(wantParam: Record<string, Object>): AbilityConstant.CollaborateResult {
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

销毁应用间的协同会话。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | number  | 是    | 待销毁的协同会话ID。   |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'destroyAbilityConnectionSession called');
  let sessionId = 100;
  abilityConnectionManager.destroyAbilityConnectionSession(sessionId);
  ```

## abilityConnectionManager.getPeerInfoById

getPeerInfoById(sessionId:&nbsp;number):&nbsp;PeerInfo&nbsp;|&nbsp;undefined

获取指定会话中对端应用信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | number  | 是    | 协同会话ID。   |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| PeerInfo | 接收端的协作应用信息。 |
| undefined | 未知情况。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'getPeerInfoById called');
  let sessionId = 100;
  const peerInfo = abilityConnectionManager.getPeerInfoById(sessionId);
  ```

## abilityConnectionManager.connect

connect(sessionId:&nbsp;number):&nbsp;Promise&lt;ConnectResult&gt;

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

设备A上的应用在创建协同会话成功并获得会话ID后，调用connect()方法启动UIAbility连接，并拉起设备B应用。

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.connect(sessionId).then((ConnectResult) => {
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

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

    onCollaborate(wantParam: Record<string, Object>): AbilityConstant.CollaborateResult {
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

当协同业务执行完毕后，协同双端的任意一台设备，应断开UIAbility的连接，结束协同状态。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明        |
| --------- | ------------------------------------- | ---- | --------- |
| sessionId | number | 是    | 协同会话ID     |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'disconnectRemoteAbility begin');
  let sessionId = 100;
  abilityConnectionManager.disconnect(sessionId);
  ```

## abilityConnectionManager.reject

reject(token:&nbsp;string,&nbsp;reason:&nbsp;string):&nbsp;void;

在跨端应用协同过程中，在拒绝对端的连接请求后，向对端发送拒绝原因。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| token | string | 是    | 用于协作服务管理的令牌。    |
| reason | string | 是    | 连接被拒绝的原因。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { AbilityConstant, UIAbility, Want} from '@kit.AbilityKit';
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class EntryAbility extends UIAbility {
      onCollaborate(wantParam: Record<string, Object>): AbilityConstant.CollaborateResult {
        hilog.info(0x0000, 'testTag', '%{public}s', 'on collaborate');
        let collabParam = wantParam["ohos.extra.param.key.supportCollaborateIndex"] as Record<string, Object>;
        const collabToken = collabParam["ohos.dms.collabToken"] as string;
        const reason = "test";
        hilog.info(0x0000, 'testTag', 'reject begin');
        abilityConnectionManager.reject(collabToken, reason);
        return AbilityConstant.CollaborateResult.REJECT;
      }
  }

  ```

## abilityConnectionManager.on('connect')

on(type:&nbsp;'connect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册connect事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'connect'，完成[abilityConnectionManager.connect()](#abilityconnectionmanagerconnect)调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.on("connect", sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session connect, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('connect')

off(type:&nbsp;'connect',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消connect事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'connect'。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("connect", sessionId);

  ```

## abilityConnectionManager.on('disconnect')

on(type:&nbsp;'disconnect',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册disconnect事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'disconnect'，完成[abilityConnectionManager.disconnect()](#abilityconnectionmanagerdisconnect)调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.on("disconnect", sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session disconnect, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('disconnect')

off(type:&nbsp;'disconnect',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消disconnect事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'disconnect'。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("disconnect", sessionId);

  ```

## abilityConnectionManager.on('receiveMessage')

on(type:&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册receiveMessage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'receiveMessage'，完成[abilityConnectionManager.sendMessage()](#abilityconnectionmanagersendmessage)调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.on("receiveMessage", sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'receiveMessage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('receiveMessage')

off(type:&nbsp;'receiveMessage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消receiveMessage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'receiveMessage'。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("receiveMessage", sessionId);

  ```

## abilityConnectionManager.on('receiveData')

on(type:&nbsp;'receiveData',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册receiveData事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'receiveData'，完成[abilityConnectionManager.sendData()](#abilityconnectionmanagersenddata)调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.on("receiveData", sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'receiveData, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off('receiveData')

off(type:&nbsp;'receiveData',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消receiveData事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件为'receiveData'，完成。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("receiveData", sessionId);

  ```

## abilityConnectionManager.sendMessage

sendMessage(sessionId:&nbsp;number,&nbsp;msg:&nbsp;string):&nbsp;Promise&lt;void&gt;

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.sendMessage(sessionId, "message send success").then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.error(0x0000, 'testTag', "connect failed");
  })
  ```

## abilityConnectionManager.sendData

sendData(sessionId:&nbsp;number,&nbsp;data:&nbsp;ArrayBuffer):&nbsp;Promise&lt;void&gt;

应用连接成功后，设备A或设备B可向对端设备发送[ArrayBuffer](../../arkts-utils/arraybuffer-object.md)字节流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 协同会话ID。 |
| data | [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) | 是    | 字节流信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { util } from '@kit.ArkTS';

  let textEncoder = util.TextEncoder.create("utf-8");
  const arrayBuffer  = textEncoder.encodeInto("data send success");

  let sessionId = 100;
  abilityConnectionManager.sendData(sessionId, arrayBuffer.buffer).then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.info(0x0000, 'testTag', "sendMessage failed");
  })
  ```

## PeerInfo

应用协同信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称                    | 类型       |只读   | 可选   | 说明                 |
| ----------------- | ------ | ----  | ---- | ------------------ |
| deviceId          | string | 是    |是    | 对端设备ID。     |
| bundleName        | string | 是    |是    | 对端应用的包名。 |
| moduleName        | string | 是    |是    | 对端应用的模块名。 |
| abilityName       | string | 是    |是     | 对端应用的组件名。 |
| serviceName       | string | 是    |否     | 应用设置的服务名称。 |

## ConnectOptions

应用连接时所需的连接选项。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称          | 类型    | 只读   | 可选   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| needSendData    | boolean  | 否    | 否    | true代表需要传输数据，false代表不需要传输数据。     |
| startOptions | [StartOptionParams](#startoptionparams) | 否    | 否    | 配置应用启动选项。 |
| parameters | Record&lt;string, string&gt;  | 否    | 否    | 配置连接所需的额外信息。    |

## ConnectResult

连接的结果。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| isConnected | boolean | 是    | 是    | true表示连接成功，false表示连接失败。 |
| errorCode | [ConnectErrorCode](#connecterrorcode) | 是    | 否    | 表示连接错误码。 |
| reason | string | 是    | 否    | 表示拒绝连接的原因。 |

## EventCallbackInfo

回调方法的接收信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型    | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| sessionId | number   | 是    | 是    |   表示当前事件对应的协同会话ID。 |
| reason | [DisconnectReason](#disconnectreason)     | 是    | 否    |   表示断连原因。 |
| msg | string   | 是    | 否    |   表示接收的消息。 |
| data  | ArrayBuffer | 是    | 否    |   表示接收的字节流。 |

## CollaborateEventInfo

协同事件信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| eventType | [CollaborateEventType](#collaborateeventtype) | 是    | 是    | 表示协同事件的类型。 |
| eventMsg | string | 是    | 否    | 表示协同事件的消息内容。 |

## ConnectErrorCode

连接的错误码。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称|  值 | 说明 |
|-------|-------|-------|
| CONNECTED_SESSION_EXISTS | 0 |表示应用之间存在已连接的会话。|
| PEER_APP_REJECTED | 1 |表示对端应用拒绝了协作请求。|
| LOCAL_WIFI_NOT_OPEN | 2 |表示本端WiFi未开启。|
| PEER_WIFI_NOT_OPEN | 3 |表示对端WiFi未开启。|
| PEER_ABILITY_NO_ONCOLLABORATE | 4 |表示未实现onCollaborate方法。|
| SYSTEM_INTERNAL_ERROR | 5 |表示系统内部错误。|

## StartOptionParams

启动选项参数的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称|  值 | 说明 |
|-------|-------|-------|
| START_IN_FOREGROUND | 0 |表示将对端应用启动至前台。|

## CollaborateEventType

协同事件类型的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称|  值 | 说明 |
|-------|-------|-------|
| SEND_FAILURE | 0 |表示任务发送失败。|
| COLOR_SPACE_CONVERSION_FAILURE | 1 |表示色彩空间转换失败。|

## DisconnectReason

当前断连原因的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称|  值 | 说明 |
|-------|-------|-------|
| PEER_APP_CLOSE_COLLABORATION | 0 |表示对端应用主动关闭了协作。|
| PEER_APP_EXIT | 1 |表示对端应用退出。|
| NETWORK_DISCONNECTED | 2 |表示网络断开。|

## CollaborationKeys

应用协作键值的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称                |                  值             | 说明                   |
| -------------------| ------------------------------- | ---------------------- |
| PEER_INFO           | ohos.collaboration.key.peerInfo | 表示对端设备信息的键值。 |
| CONNECT_OPTIONS     | ohos.collaboration.key.connectOptions | 表示连接选项的键值。   |
| COLLABORATE_TYPE    | ohos.collaboration.key.abilityCollaborateType | 表示协作类型的键值。   |

## CollaborationValues

应用协作相关值的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称                                      | 值       | 说明                   |
| ----------------------------------------- | -------- | ---------------------- |
| ABILITY_COLLABORATION_TYPE_DEFAULT | ohos.collaboration.value.abilityCollab | 表示默认的协作类型。 |
| ABILITY_COLLABORATION_TYPE_CONNECT_PROXY  | ohos.collaboration.value.connectProxy | 表示连接代理的协作类型。   |
