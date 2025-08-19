# IPC与RPC通信开发指导(ArkTS)
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong2-->
<!--Adviser: @zhang_yixin13-->

## 场景介绍

IPC/RPC的主要工作是跨进程建立对象通信的连接（客户端进程的Proxy和服务端进程的Stub建立一一对应关系），从而通过Proxy的接口可以和Stub进行IPC/RPC通信。

## 开发步骤

> **说明：**
>
> - 当前不支持三方应用实现ServiceExtensionAbility，三方应用的UIAbility组件可以通过[Context](../application-models/uiability-usage.md#获取uiability的上下文信息)连接系统提供的ServiceExtensionAbility实现。
>
> - 使用场景约束：客户端是第三方/系统应用，服务端是系统应用/服务。

### 创建ServiceExtensionAbility，实现服务端

在工程中手动新建一个ServiceExtensionAbility，具体步骤如下：

1. 在工程Module的ets目录下，右键选择“New > Directory”，新建一个目录并命名为ServiceExtAbility。

2. 在ServiceExtAbility目录，右键选择“New > ArkTS File”，新建一个文件并命名为ServiceExtAbility.ets。

    ```
      ├── ets
      │ ├── ServiceExtAbility
      │ │   ├── ServiceExtAbility.ets
      └
    ```

3. 在ServiceExtAbility.ets文件中，导入ServiceExtensionAbility的依赖包，自定义类继承ServiceExtensionAbility并实现生命周期回调。定义一个继承自[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)的stub类，实现[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)方法，用来处理客户端的请求。在onConnect生命周期回调函数里，创建之前定义的Stub对象并返回。

   ```ts
    import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // 定义服务端
    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      // 业务自行复写onRemoteMessageRequest方法，用来处理客户端的请求
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // 根据code处理客户端的请求
        switch (code) {
          case 1:
            {
              // 按照客户端写入顺序读取对应数据，具体看业务逻辑
              // 此处是根据后面客户端发送信息给服务端做的示例
              data.readString();
              reply.writeString('huichuanxinxi');
            }
        }
        return true;
      }
    }

    // 定义后台服务
    export default class ServiceAbility extends ServiceExtensionAbility {
      onCreate(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onCreate');
      }

      onRequest(want: Want, startId: number): void {
        hilog.info(0x0000, 'testTag', 'onRequest');
      }

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(0x0000, 'testTag', 'onConnect');
        // 返回Stub对象，客户端获取后便可以与ServiceExtensionAbility进行通信
        return new Stub('rpcTestAbility');
      }

      onDisconnect(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onDisconnect');
      }

      onDestroy(): void {
        hilog.info(0x0000, 'testTag', 'onDestroy');
      }
    }
   ```

### 客户端连接服务，获取服务代理对象Proxy

**创建变量want和connect**

1. 创建变量want，指定要连接的Ability所在应用的包名、组件名。在跨设备的场景下，还需要连接目标设备的NetworkId（组网场景下对应设备的标识符，可以使用distributedDeviceManager获取目标设备的NetworkId）。

2. 创建变量connect，指定连接成功、连接失败和断开连接时的回调函数。

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
    let deviceList: Array<distributedDeviceManager.DeviceBasicInfo> | undefined;
    let networkId: string | undefined;
    let want: Want | undefined;
    let connect: common.ConnectOptions | undefined;

    try{
      dmInstance = distributedDeviceManager.createDeviceManager("ohos.rpc.test");
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'createDeviceManager errCode:' + err.code + ', errMessage:' + err.message);
    }

    // 使用distributedDeviceManager获取目标设备NetworkId
    if (dmInstance != undefined) {
      try {
        deviceList = dmInstance.getAvailableDeviceListSync();
        if (deviceList.length !== 0) {
          networkId = deviceList[0].networkId;
          want = {
            bundleName: "ohos.rpc.test.server",
            abilityName: "ohos.rpc.test.service.ServiceAbility",
            deviceId: networkId,
          };
          connect = {
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
      }catch(error) {
        let err: BusinessError = error as BusinessError;
        hilog.error(0x0000, 'testTag', 'createDeviceManager err:' + err);
      }
    }
  ```

**连接服务**

  FA模型使用[connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7)接口连接Ability。

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from '@kit.AbilityKit';

    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = featureAbility.connectAbility(want, connect);
  ```

  Stage模型使用common.UIAbilityContext的[connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability)接口连接Ability。
  在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts

    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    let connectId = context.connectServiceExtensionAbility(want,connect);
   ```

### 客户端发送信息给服务端

   成功连接服务后，可以通过onConnect回调函数获取服务端的代理对象Proxy。然后，使用该Proxy调用[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2)方法发起请求。当服务端处理请求并返回数据时，可在Promise契约（用于表示一个异步操作的成功/失败的结果值）中接收结果。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // 此示例代码段中的proxy是在与服务端连接成功后的onConnect回调里拿到的proxy
    let proxy: rpc.IRemoteObject | undefined;

    // 使用Promise契约
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // 在data里写入参数，以传递字符串为例
    data.writeString("hello world");

    if (proxy != undefined) {
      proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
            return;
          }
          // 从result.reply里读取结果
          // 此处是根据前面创建ServiceExtensionAbility，实现服务端做的示例
          result.reply.readString();
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

   服务端在onConnect回调函数里返回继承自[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)的Stub对象，该对象需要实现[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)方法，处理客户端的请求。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // 服务端Stub根据不同的请求code分别执行对应的处理流程
        if (code == 1) {
          let str = data.readString();
          hilog.info(0x0000, 'testTag', 'stub receive str : ' + str);
          // 服务端使用reply回传请求处理的结果给客户端
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

   IPC通信结束后，FA模型使用[disconnectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilitydisconnectability7)接口断开连接，此处的connectId是在连接服务时保存的。

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from "@kit.AbilityKit";
    import { hilog } from '@kit.PerformanceAnalysisKit';

    function disconnectCallback() {
      hilog.info(0x0000, 'testTag', 'disconnect ability done');
    }
    // 断开连接，使用连接服务成功时保存下来的connectId断开连接
    featureAbility.disconnectAbility(connectId, disconnectCallback);
   ```

   Stage模型使用common.UIAbilityContext提供的[disconnectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectserviceextensionability-1)接口断开连接，此处的connectId是在连接服务时保存的。
   在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    
    // 断开连接，使用连接服务成功时保存下来的connectId断开连接
    context.disconnectServiceExtensionAbility(connectId);
   ```

## 完整示例

针对IPC与RPC通信开发，端到端的完整示例，请参考：

- [IPC通信完整样例-使用Parcelable/ArrayBuffer通信](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/IPC/ObjectTransfer)