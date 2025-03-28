# IPC与RPC通信开发指导(ArkTS)

## 场景介绍

IPC/RPC的主要工作是让运行在不同进程的Proxy和Stub互相通信，包括Proxy和Stub运行在不同设备的情况。

## 开发步骤

> **说明：**
>
> - 当前不支持三方应用实现ServiceExtensionAbility，三方应用的UIAbility组件可以通过[Context](../application-models/uiability-usage.md#获取uiability的上下文信息)连接系统提供的ServiceExtensionAbility实现。
>
> - 当前使用场景： 客户端是三方应用，服务端是系统应用。

### 创建ServiceExtensionAbility，实现服务端

  定义一个stub类，继承自[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)的对象，实现[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)方法，用来处理客户端的请求。

  ```ts
    import { rpc } from '@kit.IPCKit';

    // 定义服务端
    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      // 业务自行复写onRemoteMessageRequest方法，用来处理客户端的请求
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // 根据code处理客户端的请求,
        switch (code) {
          case 1:
            {
              // 按照客户端写入顺序读取对应数据，具体看业务逻辑
            }
        }
        return true;
      }
    }
  ```

  在工程中手动新建一个ServiceExtensionAbility，具体步骤如下：<br/>
      1. 在工程Module对应的ets目录下，右键选择“New > Directory”，新建一个目录并命名为ServiceExtAbility。<br/>
      2. 在ServiceExtAbility目录，右键选择“New > ArkTS File”，新建一个文件并命名为ServiceExtAbility.ets。<br/>
      3. 在ServiceExtAbility.ets文件中，增加导入ServiceExtensionAbility的依赖包，自定义类继承ServiceExtensionAbility并实现生命周期回调，在onConnect生命周期回调里，需要将之前定义的stub对象返回。<br/>

   ```ts
    import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // 定义后台服务
    export default class ServiceAbility extends ServiceExtensionAbility {
      onCreate(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onCreate');
      }

      onRequest(want: Want, startId: number): void {
        hilog.info(0x0000, 'testTag', 'onCreate');
      }

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(0x0000, 'testTag', 'onConnect');
        // 返回stub对象，客户端获取后便可以与ServiceExtensionAbility进行通信
        return new Stub('rpcTestAbility');
      }

      onDisconnect(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onConnect');
      }

     onDestroy(): void {
      hilog.info(0x0000, 'testTag', 'onDestroy');
     }
    }
   ```

### 客户端连接服务，获取服务代理proxy

**构造变量want和connect**

  首先，构造变量want，指定要连接的Ability所在应用的包名、组件名。如果是跨设备的场景，还需要连接目标设备的NetworkId（组网场景下对应设备的标识符，可以使用distributedDeviceManager获取目标设备的NetworkId）。<br/>
  其次，构造变量connect，指定连接成功、连接失败、断开连接时的回调函数。<br/>

  ```ts
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let dmInstance: distributedDeviceManager.DeviceManager | undefined;
    let proxy: rpc.IRemoteObject | undefined;

    // 单个设备连接Ability
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

    // 跨设备连接Ability, 需要构造want时，获取目标设备的NetworkId，connect则沿用上文保持不变
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
        flags: 256
      };
    }
  ```

**连接服务**

  FA模型使用featureAbility提供的[connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilitydisconnectability7)接口连接Ability。

  ```ts
    import { featureAbility } from '@kit.AbilityKit';

    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = featureAbility.connectAbility(want, connect);
  ```

  Stage模型通过context获取服务后用提供的接口[connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability)连接Ability。

  ```ts
    let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = context.connectServiceExtensionAbility(want,connect);
   ```

### 客户端发送信息给服务端

   在成功连接服务后，可以通过onConnect回调拿到服务端的代理对象proxy，通过proxy可以发送信息给服务端。 客户端在onConnect回调里接收到代理对象，调用proxy对象的[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2)方法发起请求给服务端，等服务端处理请求并返回数据时，可在期约（用于表示一个异步操作的成功/失败的结果值）里接收结果。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // 使用期约
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // 在data里写入参数，以传递字符串为例
    data.writeString("hello world");
    let proxy: rpc.IRemoteObject | undefined;
    if (proxy != undefined) {
      proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
            return;
          }
          // 从result.reply里读取结果
          reply.readString();
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest got exception: ' + e);
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    }

   ```

### 服务端处理客户端请求

   服务端被绑定的Ability在onConnect方法里返回继承自[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)的对象，该对象需要实现[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)方法，处理客户端的请求。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // 根据code处理客户端的请求，可使用if判断code，也可采用switch判断，具体方式取决于业务
        if (code == 1) {
          let str = data.readString();
          hilog.info(0x0000, 'testTag', 'stub receive str : ' + str);
          // 服务端使用reply回传信息给客户端
          reply.writeString("hello rpc");
          return true;
        } else {
            hilog.info(0x0000, 'testTag', 'stub unknown code: ' + code);
            return false;
        }
      }
    }
   ```

### 断开连接

   IPC通信结束后，FA模型使用featureAbility的[disconnectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilitydisconnectability7)接口断开连接

  ```ts
    import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

    let want: Want = {
      // 写包名和组件名实际的值
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

    connectId = featureAbility.connectAbility(want, connect);

    function disconnectCallback() {
      hilog.info(0x0000, 'testTag', 'disconnect ability done');
    }
    // 断开连接
    featureAbility.disconnectAbility(connectId, disconnectCallback);
   ```

   Stage模型在获取context后用提供的[disconnectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability-1)接口断开连接。

  ```ts
    import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

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
    let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
    connectId = this.context.connectServiceExtensionAbility(want,connect);
    // 断开连接
    this.context.disconnectServiceExtensionAbility(connectId);
   ```

## 相关实例

针对IPC与RPC通信开发，有以下相关实例可供参考：

- [RPC通信（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/RPC)
