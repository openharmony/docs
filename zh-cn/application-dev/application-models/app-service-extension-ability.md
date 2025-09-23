# 使用AppServiceExtensionAbility组件实现后台服务
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## 概述

从API version 20开始，支持开发者使用[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)组件，为应用提供后台服务能力，其他三方应用可通过启动或连接该AppServiceExtensionAbility组件获取相应的服务。
例如，企业部署的数据防泄漏 (DLP) 软件需要能够长期无界面长期运行，持续监听文件操作、网络流量，并拦截违规行为，可以使用AppServiceExtensionAbility组件来实现其核心的后台监控服务。
> **说明**
>
> 本文将被启动或被连接的AppServiceExtensionAbility组件称为服务端，将启动或连接AppServiceExtensionAbility组件的应用组件（当前仅支持UIAbility）称为客户端。

## 约束与限制

### 设备限制

AppServiceExtensionAbility组件当前仅支持2in1设备。

### 规格限制

- 应用集成AppServiceExtensionAbility组件需要申请ACL权限（ohos.permission.SUPPORT_APP_SERVICE_EXTENSION）。该ACL权限当前只对企业普通应用开放申请。

- AppServiceExtensionAbility组件内不支持调用[window](../reference/apis-arkui/arkts-apis-window.md)相关API。

## 运作机制

开发者可以在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)中以[启动](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20)或[连接](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)的方式来拉起AppServiceExtensionAbility组件。

- **启动：** 客户端必须为AppServiceExtensionAbility所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用才能调用[startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20)接口。
- **连接：** 如果[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)实例未启动，客户端必须为AppServiceExtensionAbility所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用才能调用[connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)接口。如果实例已启动，则没有上述限制。

下表展示了拉起和连接的几种场景：


> **说明**
>
> “客户端是否可信”为是时，表示客户端属于服务端所属应用或已配置在appIdentifierAllowList中。为否时，表示客户端不属于服务端所属应用且未配置在appIdentifierAllowList中。

| 客户端操作 | 服务端状态 | 客户端是否可信 | 结果说明 |
| --------- | --------- | -------------------------------------------- | ---- |
| startAppServiceExtensionAbility | 未启动     | 是                                       | 成功，服务端通过start方式启动，服务端状态变为已启动。 |
| startAppServiceExtensionAbility | 未启动     | 否                                       | 失败，客户端不在允许列表中，无法调用启动服务。 |
| startAppServiceExtensionAbility | 已启动     | 是                                       | 成功，服务端已经启动，start操作直接返回成功。 |
| startAppServiceExtensionAbility | 已启动     | 否                                       | 失败，客户端不在允许列表中，无法调用启动服务。 |
| connectAppServiceExtensionAbility | 未启动     | 是                                       | 成功，服务端通过connect方式启动，并建立连接。 |
| connectAppServiceExtensionAbility | 未启动     | 否                                       | 失败，客户端不在允许列表中，无法启动服务端。 |
| connectAppServiceExtensionAbility | 已启动     | 是                                       | 成功，服务端已启动，直接建立连接。 |
| connectAppServiceExtensionAbility | 已启动     | 否                                       | 成功，服务端已启动，直接建立连接。 |


## 实现一个后台服务

在DevEco Studio工程中手动新建一个AppServiceExtensionAbility组件，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为MyAppServiceExtAbility。

2. 在MyAppServiceExtAbility目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为MyAppServiceExtAbility.ets。
![](figures/app-service-extension-ability-create-new-file.png)

    其目录结构如下所示：

    ```
    ├── ets
    │ ├── MyAppServiceExtAbility
    │ │   ├── MyAppServiceExtAbility.ets
    └
    ```

3. 在MyAppServiceExtAbility.ets文件中，增加导入[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)的依赖包，自定义类继承AppServiceExtensionAbility组件并实现生命周期回调。

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[MyAppServiceExtAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteMessageRequest(code: number,
        data: rpc.MessageSequence,
        reply: rpc.MessageSequence,
        options: rpc.MessageOption): boolean | Promise<boolean> {
        // 处理客户端发送的消息
        return true;
      }
    }

    export default class MyAppServiceExtAbility extends AppServiceExtensionAbility {
      onCreate(want: Want): void {
        let appServiceExtensionContext = this.context;
        hilog.info(DOMAIN_NUMBER, TAG, `onCreate, want: ${want.abilityName}`);
      }

      onRequest(want: Want, startId: number): void {
        hilog.info(DOMAIN_NUMBER, TAG, `onRequest, want: ${want.abilityName}`);
      }

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(DOMAIN_NUMBER, TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      }

      onDisconnect(want: Want): void {
        hilog.info(DOMAIN_NUMBER, TAG, `onDisconnect, want: ${want.abilityName}`);
      }

      onDestroy(): void {
        hilog.info(DOMAIN_NUMBER, TAG, 'onDestroy');
      }
    };
    ```

4. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册AppServiceExtensionAbility组件，type标签需要设置为“appService”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

    ```json
    {
      "module": {
        // ...
        "extensionAbilities": [
          {
            "name": "MyAppServiceExtAbility",
            "description": "appService",
            "type": "appService",
            "exported": true,
            "srcEntry": "./ets/MyAppServiceExtAbility/MyAppServiceExtAbility.ets",
            "appIdentifierAllowList": [
              // 此处填写允许启动该后台服务的客户端应用的appIdentifier列表
            ],
          }
        ]
      }
    }
    ```

## 启动一个后台服务

应用通过[startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20)方法启动一个后台服务，服务的[onRequest()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onrequest)回调就会被调用，并在该回调方法中接收到调用者传递过来的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)对象。后台服务启动后，其生命周期独立于客户端，即使客户端已经销毁，该后台服务仍可继续运行。因此，后台服务需要在其工作完成时通过调用[AppServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-appServiceExtensionContext.md)的[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-appServiceExtensionContext.md#terminateself)来自行停止，或者由另一个组件调用[stopAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20)来将其停止。

> **说明：**
>
> AppServiceExtensionAbility组件以start方式启动，并且没有连接的时候，AppServiceExtensionAbility组件进程可能被挂起（请参考[Background Tasks Kit简介](../task-management/background-task-overview.md)）。

- 在应用中启动一个新的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)组件。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

  ```ts
  import { common, Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  const TAG: string = '[Page_AppServiceExtensionAbility]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Page_AppServiceExtensionAbility {
    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // UIAbilityContext
              let want: Want = {
                deviceId: '',
                bundleName: 'com.samples.stagemodelabilitydevelop',
                abilityName: 'MyAppServiceExtAbility'
              };
              context.startAppServiceExtensionAbility(want).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting AppServiceExtensionAbility.');
                // 成功启动后台服务
                this.getUIContext().getPromptAction().showToast({
                  message: 'SuccessfullyStartBackendService'
                });
              }).catch((err: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG,
                  `Failed to start AppServiceExtensionAbility. Code is ${err.code}, message is ${err.message}`);
              });
            })
          }

          //...
        }

        //...
      }

      //...
    }
  }
  ```

- 在应用中停止一个已启动的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)组件。

  ```ts
  import { common, Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  const TAG: string = '[Page_AppServiceExtensionAbility]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Page_AppServiceExtensionAbility {
    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // UIAbilityContext
              let want: Want = {
                deviceId: '',
                bundleName: 'com.samples.stagemodelabilitydevelop',
                abilityName: 'MyAppServiceExtAbility'
              };
              context.stopAppServiceExtensionAbility(want).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in stopping AppServiceExtensionAbility.');
                this.getUIContext().getPromptAction().showToast({
                  message: 'SuccessfullyStoppedAStartedBackendService'
                });
              }).catch((err: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG,
                  `Failed to stop AppServiceExtensionAbility. Code is ${err.code}, message is ${err.message}`);
              });
            })
          }

          //...
        }

        //...
      }

      //...
    }
  }
  ```

- 已启动的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)组件停止自身。

    ```ts
    import { AppServiceExtensionAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[MyAppServiceExtAbility]';

    export default class MyAppServiceExtAbility extends AppServiceExtensionAbility {
      onCreate(want: Want) {
      // 执行业务逻辑
        this.context.terminateSelf().then(() => {
          hilog.info(0x0000, TAG, '----------- terminateSelf succeed -----------');
        }).catch((error: BusinessError) => {
          hilog.error(0x0000, TAG, `terminateSelf failed, error.code: ${error.code}, error.message: $   {error.message}`);
        });
      }
    }
    ```

## 连接一个后台服务

### 客户端连接服务端

客户端可以通过[connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)连接服务端（在Want对象中指定连接的目标服务），服务端的[onConnect()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onconnect)就会被调用，并在该回调方法中接收到客户端传递过来的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)对象。

服务端的AppServiceExtensionAbility组件会在onConnect()中返回[IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject)对象给客户端[ConnectOptions](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md)的[onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)方法。开发者通过该IRemoteObject定义通信接口，实现客户端与服务端的RPC交互。多个客户端可以同时连接到同一个后台服务，客户端完成与服务端的交互后，客户端需要通过调用[disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20)来断开连接。如果所有连接到某个后台服务的客户端均已断开连接，则系统会销毁该服务。

- 使用[connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)建立与后台服务的连接。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
  
  ```ts
  import { common, Want } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[Page_AppServiceExtensionAbility]';
  const DOMAIN_NUMBER: number = 0xFF00;

  let connectionId: number;
  let want: Want = {
    deviceId: '',
    bundleName: 'com.samples.stagemodelabilitydevelop',
    abilityName: 'MyAppServiceExtAbility'
  };

  let options: common.ConnectOptions = {
    onConnect(elementName, remote: rpc.IRemoteObject): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onConnect callback');
      if (remote === null) {
        hilog.info(DOMAIN_NUMBER, TAG, `onConnect remote is null`);
        return;
      }
      // 通过remote进行通信
    },
    onDisconnect(elementName): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
    },
    onFailed(code: number): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback', JSON.stringify(code));
    }
  };

  @Entry
  @Component
  struct Page_AppServiceExtensionAbility {
    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // UIAbilityContext
              // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
              connectionId = context.connectAppServiceExtensionAbility(want, options);
              // 成功连接后台服务
              this.getUIContext().getPromptAction().showToast({
                message: 'SuccessfullyConnectBackendService'
              });
              hilog.info(DOMAIN_NUMBER, TAG, `connectionId is : ${connectionId}`);
            })
          }

          //...
        }

        //...
      }

      //...
    }
  }
  ```

- 使用[disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20)断开与后台服务的连接。
  
  ```ts
  import { common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  const TAG: string = '[Page_AppServiceExtensionAbility]';
  const DOMAIN_NUMBER: number = 0xFF00;

  let connectionId: number;

  @Entry
  @Component
  struct Page_AppServiceExtensionAbility {
    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // UIAbilityContext
              // connectionId为调用connectServiceExtensionAbility接口时的返回值，需开发者自行维护
              context.disconnectAppServiceExtensionAbility(connectionId).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'disconnectAppServiceExtensionAbility success');
                // 成功断连后台服务
                this.getUIContext().getPromptAction().showToast({
                  message: 'SuccessfullyDisconnectBackendService'
                });
              }).catch((error: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG, 'disconnectAppServiceExtensionAbility failed');
              });
            })
          }

          //...
        }

        //...
      }

      //...
    }
  }
  ```

### 客户端与服务端通信

客户端在[onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)中获取到[rpc.IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject)对象后便可与服务端进行通信。

**客户端**：使用[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9)接口向服务端发送消息。

```ts
import { common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_AppServiceExtensionAbility]';
const DOMAIN_NUMBER: number = 0xFF00;
const REQUEST_CODE = 1;
let connectionId: number;
let want: Want = {
  deviceId: '',
  bundleName: 'com.samples.stagemodelabilitydevelop',
  abilityName: 'MyAppServiceExtAbility'
};
let options: common.ConnectOptions = {
  onConnect(elementName, remote): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onConnect callback');
    if (remote === null) {
      hilog.info(DOMAIN_NUMBER, TAG, `onConnect remote is null`);
      return;
    }
    let option = new rpc.MessageOption();
    let data = new rpc.MessageSequence();
    let reply = new rpc.MessageSequence();

    // 写入请求数据
    data.writeInt(1);
    data.writeInt(2);

    remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
      if (ret.errCode === 0) {
        hilog.info(DOMAIN_NUMBER, TAG, `sendRequest got result`);
        let sum = ret.reply.readInt();
        hilog.info(DOMAIN_NUMBER, TAG, `sendRequest success, sum:${sum}`);
      } else {
        hilog.error(DOMAIN_NUMBER, TAG, `sendRequest failed`);
      }
    }).catch((error: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `sendRequest failed, ${JSON.stringify(error)}`);
    });
  },
  onDisconnect(elementName): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
  },
  onFailed(code): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback');
  }
};

// 调用connectAppServiceExtensionAbility相关代码
//...

@Entry
@Component
struct Page_AppServiceExtensionAbility {
  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // UIAbilityContext
            connectionId = context.connectAppServiceExtensionAbility(want, options);
            hilog.info(DOMAIN_NUMBER, TAG, `connectionId is : ${connectionId}`);
          })
        }
      }
      //...
    }
  }
}
```

**服务端**：使用[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)接口接收客户端发送的消息。

```ts
import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MyAppServiceExtAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

// 开发者需要在这个类型里对接口进行实现
class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    hilog.info(DOMAIN_NUMBER, TAG, 'onRemoteMessageRequest');
    let sum = data.readInt() + data.readInt();
    reply.writeInt(sum);
    return true;
  }
}

// 服务端实现
export default class MyAppServiceExtAbility extends AppServiceExtensionAbility {
  onCreate(want: Want): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'MyAppServiceExtAbility onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'MyAppServiceExtAbility onDestroy');
  }

  onConnect(want: Want): rpc.RemoteObject {
    hilog.info(DOMAIN_NUMBER, TAG, 'MyAppServiceExtAbility onConnect');
    return new Stub('test');
  }

  onDisconnect(): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'MyAppServiceExtAbility onDisconnect');
  }
}
```

### 服务端对客户端身份校验

部分开发者需要使用AppServiceExtensionAbility组件提供一些较为敏感的服务，可以通过如下方式对客户端身份进行校验。

<!--Del-->
**通过callerUid识别客户端应用**

通过调用[getCallingUid()](../reference/apis-ipc-kit/js-apis-rpc.md#getcallinguid)接口获取客户端的uid，再调用[getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14)接口获取uid对应的bundleName，从而识别客户端身份。此处需要注意的是[getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14)是一个异步接口，因此服务端无法将校验结果返回给客户端，这种校验方式适合客户端向服务端发起执行异步任务请求的场景，示例代码如下：

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { osAccount, BusinessError } from '@kit.BasicServicesKit';

class Stub extends rpc.RemoteObject {
  private validAppIdentifier: string = "your_valid_app_identifier_here";

  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    this.verifyClientIdentity().then((isValid: boolean) => {
      if (isValid) {
        console.info('Client authentication PASSED');
      } else {
        console.error('Client authentication FAILED');
      }
    }).catch((err: BusinessError) => {
      console.error(`Authentication error: ${err.code}, ${err.message}`);
    });
    return true;
  }

  private async verifyClientIdentity(): Promise<boolean> {
    try {
      const callerUid: number = rpc.IPCSkeleton.getCallingUid();
      console.info(`Caller UID: ${callerUid}`);

      const userId: number = await this.getUserIdByUid(callerUid);
      console.info(`User ID: ${userId}`);

      const bundleName: string = await bundleManager.getBundleNameByUid(callerUid);
      console.info(`Bundle Name: ${bundleName}`);

      const bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
      const bundleInfo: bundleManager.BundleInfo = await bundleManager.getBundleInfo(bundleName, bundleFlags, userId);

      if (bundleInfo.signatureInfo && bundleInfo.signatureInfo.appIdentifier) {
        const appIdentifier: string = bundleInfo.signatureInfo.appIdentifier;
        console.info(`App Identifier: ${appIdentifier}`);
        return appIdentifier === this.validAppIdentifier;
      }
      return false;
    } catch (err) {
      if (err instanceof Error) {
        console.error(`Verification failed: ${err.message}`);
      } else {
        console.error(`Verification failed: ${String(err)}`);
      }
      return false;
    }
  }

  private async getUserIdByUid(uid: number): Promise<number> {
    try {
      const accountManager = osAccount.getAccountManager();
      const userId: number = await accountManager.getOsAccountLocalIdForUid(uid);
      return userId;
    } catch (err) {
      if (err instanceof Error) {
        console.error(`Get userId failed: ${err.message}`);
        throw err;
      } else {
        const error = new Error(String(err));
        console.error(`Get userId failed: ${error.message}`);
        throw error;
      }
    }
  }
}

export default class MyAppServiceExtAbility extends AppServiceExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    return new Stub('test');
  }
  // 其他生命周期
}
```
<!--DelEnd-->

**通过callerTokenId对客户端进行鉴权**

通过调用[getCallingTokenId()](../reference/apis-ipc-kit/js-apis-rpc.md#getcallingtokenid8)接口获取客户端的tokenID，再调用[verifyAccessTokenSync()](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#verifyaccesstokensync9)接口判断客户端是否有某个具体权限，由于当前不支持自定义权限，因此只能校验当前[系统所定义的权限](../security/AccessToken/app-permissions.md)。示例代码如下：

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
import { abilityAccessCtrl, bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AppServiceExtImpl]';
const DOMAIN_NUMBER: number = 0xFF00;

// 开发者需要在这个类里进行实现

class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    // 开发者自行实现业务逻辑
    hilog.info(DOMAIN_NUMBER, TAG, `onRemoteMessageRequest: ${data}`);
    let callerUid = rpc.IPCSkeleton.getCallingUid();
    bundleManager.getBundleNameByUid(callerUid).then((callerBundleName) => {
      hilog.info(DOMAIN_NUMBER, TAG, 'getBundleNameByUid: ' + callerBundleName);
      // 对客户端包名进行识别
      if (callerBundleName !== 'com.samples.stagemodelabilitydevelop') { // 识别不通过
        hilog.info(DOMAIN_NUMBER, TAG, 'The caller bundle is not in trustlist, reject');
        return;
      }
    // 识别通过，执行正常业务逻辑
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, 'getBundleNameByUid failed: ' + err.message);
    });

    let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
    let accessManager = abilityAccessCtrl.createAtManager();
    // 所校验的具体权限由开发者自行选择，此处ohos.permission.GET_BUNDLE_INFO_PRIVILEGED只作为示例
    let grantStatus = accessManager.verifyAccessTokenSync(callerTokenId, 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED');
    if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_DENIED) {
      hilog.error(DOMAIN_NUMBER, TAG, 'PERMISSION_DENIED');
      return false;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'verify access token success.');
    return true;
  }
}

export default class MyAppServiceExtAbility extends AppServiceExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
      return new Stub('test');
  }
  // 其他生命周期
}
```

