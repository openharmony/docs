# @ohos.application.DistributedExtensionContext (协同Extension上下文)
<!--Kit: Distributed Service Kit-->
<!--Subsystem: DistributedSched-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

DistributedExtensionContext模块是DistributedExtensionAbility（分布式扩展能力）的上下文环境，继承自ExtensionContext（扩展上下文）。

> **说明：**
> 
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 使用说明

通过DistributedExtensionAbility子类实例获取DistributedExtensionContext。

<!--code_no_check-->
```ts
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';

export default class DistributedExtension extends DistributedExtensionAbility {
  onCreate() {
    let context = this.context; // 获取DistributedExtensionContext
  }
}
```

## DistributedExtensionContext.connectServiceExtensionAbility

connectServiceExtensionAbility(want: Want, options: ConnectOptions): number

将当前DistributedExtensionAbility连接到远端（其他设备上的）ServiceExtensionAbility，建立连接后通过onConnect回调返回的[rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject)代理与远端ServiceExtensionAbility进行跨设备IPC通信，以使用其对外提供的能力。适用于多设备限定协同场景，例如在当前设备上调用其他设备的后台服务能力。使用时，开发者首先通过Want中的deviceId指定目标设备、bundleName和abilityName指定目标ServiceExtensionAbility，并构造[ConnectOptions](../apis-ability-kit/js-apis-inner-ability-connectOptions.md)实现onConnect、onDisconnect、onFailed三个回调分别处理连接成功、连接断开和连接失败状态；随后调用connectServiceExtensionAbility发起连接并获取返回的连接ID，连接成功后在onConnect回调中拿到IRemoteObject代理对象，基于该代理与远端ServiceExtensionAbility进行IPC通信；使用完毕后需调用[disconnectServiceExtensionAbility](#distributedextensioncontextdisconnectserviceextensionability)断开连接并释放资源。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 传入需要连接的远端ServiceExtensionAbility（服务扩展能力）的Want信息。系统将基于这些信息建立到远端设备的连接。 |
| options | [ConnectOptions](../apis-ability-kit/js-apis-inner-ability-connectOptions.md) | 是   | ConnectOptions类型的配置对象，包含服务连接状态回调。连接成功时触发onConnect，连接断开时触发onDisconnect，连接失败时触发onFailed。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回连接ID，后续通过该ID断开连接。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |

**示例：**

<!--code_no_check-->
```ts
import { AbilityConstant, Want } from '@kit.AbilityKit';
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.AbilityKit';

const TAG = 'DistributedExtAbility';
const DOMAIN = 0xFF00;

export default class DistributedExtAbility extends DistributedExtensionAbility {


  onCreate (want:Want) {
    hilog.info(DOMAIN, TAG, 'onCreate');
    this.testConnectServiceExtensionAbility();
  }

  onCollaborate (wantParam: Record<string, Object>) {
    hilog.info(DOMAIN, TAG, 'onCollaborate');
    return AbilityConstant.CollaborateResult.ACCEPT;
  }

  onDestroy () {
    hilog.info(DOMAIN, TAG, 'onDestroy');
  }

  connectId:number = -1;
  private testConnectServiceExtensionAbility() {
    hilog.info(DOMAIN, TAG, 'testConnectServiceExtensionAbility');
    let deviceId1: string = '';
    try {
      let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
      deviceId1 = dmInstance.getLocalDeviceId();
      const message: string = 'local device id: ' + deviceId1;
      hilog.info(DOMAIN, TAG, message);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLocalDeviceId errCode:' + e.code + ',errMessage:' + e.message);
    }
    const targetWant:Want = {
      deviceId: deviceId1,
      bundleName: 'com.example.test0002',
      abilityName: 'ServiceExtAbility',
    }
    const options: common.ConnectOptions = {
      onConnect: (name: bundleManager.ElementName, remote: rpc.IRemoteObject): void => {
        const message: string = 'onConnect: ' + name;
        hilog.info(DOMAIN, TAG, message);
      },
      onDisconnect: (name: bundleManager.ElementName): void => {
        const message: string = 'onDisconnect: ' + name;
        hilog.info(DOMAIN, TAG, message);
      },
      onFailed: (code: number): void => {
        const message: string = 'onFailed: code=' + code;
        hilog.info(DOMAIN, TAG, message);
      }
    };
    try {
      const id: number = this.context.connectServiceExtensionAbility(targetWant, options);
      this.connectId = id;
      const message: string = 'connect called, id=' + id;
      hilog.info(DOMAIN, TAG, message);
    } catch (err) {
      const message: string = 'connect error: ' + err;
      hilog.info(DOMAIN, TAG, message);
    }
  }
}
```



## DistributedExtensionContext.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(connection: number): Promise\<void\>

断开与远端ServiceExtensionAbility的连接，与[connectServiceExtensionAbility](#distributedextensioncontextconnectserviceextensionability)配对使用。调用connectServiceExtensionAbility后，必须在使用完毕后调用此方法释放连接资源，需要使用connectServiceExtensionAbility返回的连接ID调用此方法。断开连接之后开发者需要将连接成功时onConnect回调中返回的remote对象置空，以避免后续误用已失效的代理对象。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                     |
| ---------- | ------ | ---- | -------------------------------------------------------- |
| connection | number | 是   | 连接ID，必须使用connectServiceExtensionAbility返回的连接ID值。 |

**返回值：**

| 类型            | 说明                               |
| --------------- | ---------------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 16000003 | The connection id does not exist.                            |
| 16000011 | The ability has been destroyed. The context is no longer valid, meaning the context does not exist. |
| 16000050 | Internal error.                                              |

**示例：**

<!--code_no_check-->
```ts
import { AbilityConstant, Want } from '@kit.AbilityKit';
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.AbilityKit';


const TAG = 'DistributedExtAbility';
const DOMAIN = 0xFF00;

export default class DistributedExtAbility extends DistributedExtensionAbility {


  onCreate (want:Want) {
    hilog.info(DOMAIN, TAG, 'onCreate');
  }

  onCollaborate (wantParam: Record<string, Object>) {
    hilog.info(DOMAIN, TAG, 'onCollaborate');
    return AbilityConstant.CollaborateResult.ACCEPT;
  }

  onDestroy () {
    hilog.info(DOMAIN, TAG, 'onDestroy');
    this.testDisconnectServiceExtensionAbility();
  }

  connectId:number = -1;

  private testDisconnectServiceExtensionAbility() {
    hilog.info(DOMAIN, TAG, 'testDisconnectServiceExtensionAbility');
    this.context.disconnectServiceExtensionAbility(this.connectId);
  }
}
```