# 远端状态订阅开发实例

IPC/RPC提供了订阅远端Stub对象状态的机制。当远端Stub对象死亡时，可以自动触发本端Proxy注册的死亡通知。这种死亡通知订阅需要调用指定接口[registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1)完成。不再需要订阅时，也需要调用指定接口[unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1)取消订阅。

使用这种订阅机制的用户需要继承死亡通知类[DeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#deathrecipient)，并实现[onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied)方法清理资源。该方法会在远端Stub对象所在进程退出或当前RPC通信依赖的软总线连接断开时被回调。

> **注意：**
> - 首先，Proxy订阅Stub死亡通知，若在订阅期间Stub状态正常，则在不再需要时取消订阅。 
> - 其次，若在订阅期间，Stub所在进程退出或当前RPC通信依赖的软总线连接断开，则会自动触发执行业务已向Proxy注册的自定义的[onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied)方法。

## 使用场景

IPC/RPC的订阅机制适用于以下场景：</br>
1. IPC通信，Proxy对象需要感知远端Stub对象所在进程的状态。
2. RPC通信，Proxy对象需要感知远端Stub对象所在进程的状态，或者RPC通信依赖的软总线连接断开。
当Proxy感知到Stub端死亡后，应该清理本地Proxy对象以及相关资源。
> **注意：** RPC不支持匿名Stub对象（没有向SAMgr注册）的死亡通知，IPC支持匿名Stub对象的死亡通知。

## ArkTS侧接口

> **说明：**
>
> - 此文档中的示例代码描述的是系统应用跨进程通信。
>
> - 使用场景约束：客户端是第三方/系统应用，服务端是系统应用/服务

| 接口名                                                       | 返回值类型 | 功能描述                                                     |
| ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) | void       | 注册用于接收远程对象死亡通知的回调，该方法应该在proxy侧调用。 |
| [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) | void       | 注销用于接收远程对象死亡通知的回调。                         |
| [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) | void       | Proxy侧注册死亡通知成功后，当远端Stub对象所在进程死亡时，将自动回调本方法。 |

### 参考代码

  在IPC场景中，创建变量want和connect。
  ```ts
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    let proxy: rpc.IRemoteObject | undefined;

    let want: Want = {
      // 包名和组件名写实际的值
      bundleName: "ohos.rpc.test.server",
      abilityName: "ohos.rpc.test.server.ServiceAbility",
    };
    let connect: common.ConnectOptions = {
      onConnect: (elementName, remoteProxy) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
        proxy = remoteProxy;
      },
      onDisconnect: (elementName) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
      },
      onFailed: () => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
      }
    };
  ```

  在RPC场景中，创建变量want和connect。
  ```ts 
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let dmInstance: distributedDeviceManager.DeviceManager | undefined;
    let proxy: rpc.IRemoteObject | undefined;

    try{
      dmInstance = distributedDeviceManager.createDeviceManager("ohos.rpc.test");
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'createDeviceManager errCode:' + err.code + ', errMessage:' + err.message);
    }

    // 使用distributedDeviceManager获取目标设备NetworkId
    if (dmInstance != undefined) {
      let deviceList = dmInstance.getAvailableDeviceListSync();
      let networkId = deviceList[0].networkId;
      let want: Want = {
        bundleName: "ohos.rpc.test.server",
        abilityName: "ohos.rpc.test.service.ServiceAbility",
        deviceId: networkId,
      };

      let connect: common.ConnectOptions = {
        onConnect: (elementName, remoteProxy) => {
          hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
          proxy = remoteProxy;
        },
        onDisconnect: (elementName) => {
          hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
        },
        onFailed: () => {
          hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
        }
      };
    }
  ```

  FA模型使用[connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7)接口连接Ability。

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from '@kit.AbilityKit';

    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = featureAbility.connectAbility(want, connect);
  ```

  Stage模型使用common.UIAbilityContext的[connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)接口连接Ability。
  在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = context.connectServiceExtensionAbility(want,connect);
   ```

  成功连接服务后，onConnect回调函数中的Proxy对象会被赋值。此时，可以调用Proxy对象的[registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1)接口方法注册死亡回调，在Proxy不再使用的时候，调用[unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1)接口方法注销死亡回调。

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;

  class MyDeathRecipient implements rpc.DeathRecipient{
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    // 此处的0为注册死亡监听的死亡通知的保留标志，暂无实际意义
    proxy.registerDeathRecipient(deathRecipient, 0);
    proxy.unregisterDeathRecipient(deathRecipient, 0);
  }
  ```

## Stub反向感知Proxy死亡状态（匿名Stub的特殊用法）

正向的死亡通知是Proxy感知Stub的状态，要实现反向的死亡通知（即Stub感知Proxy的状态），可以利用反向死亡通知。例如，进程A（原Stub所在进程）和进程B（原Proxy所在进程），进程B获取到进程A的原Proxy对象后，在B进程新建一个匿名Stub对象（未向SAMgr注册），称为回调Stub，通过[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2)接口将回调Stub传给进程A的原Stub，进程A就可以获取到进程B的回调Proxy。只要向回调Proxy注册了死亡通知，当进程B（回调Stub）死亡或者RPC通信依赖的软总线连接断开时，回调Proxy会感知并通知进程A（原Stub），从而实现反向死亡通知。

> **注意：**
> - 反向死亡通知仅限设备内跨进程通信使用，不可用于跨设备。
> - 当匿名Stub对象没有被任何一个Proxy引用时，对象会被自动释放。
