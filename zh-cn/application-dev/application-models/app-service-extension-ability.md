# 使用AppServiceExtensionAbility实现后台服务
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->

## 概述

从API version 20开始，支持使用[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)组件，为应用提供后台服务能力。主要用于2in1设备上的企业普通应用进行后台服务开发，例如，用于保障网络安全的企业EDR软件，或者管理设备的企业MDM软件等。

## 接口说明

开发者可以在UIAbility中以启动或连接的方式来拉起AppServiceExtensionAbility。两种方式对比如下：

| 拉起方式 | 接口名 | 说明 |
| -------- | -------- | -------- |
| 启动 | [startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20) | UIAbility启动AppServiceExtensionAbility后，两者为弱关联。UIAbility退出后，AppServiceExtensionAbility可以继续存在。|
| 连接 | [connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20) | UIAbility连接AppServiceExtensionAbility后，两者为强关联。UIAbility退出后，AppServiceExtensionAbility也将一起退出。 |

## 约束限制

- AppServiceExtensionAbility当前仅支持2in1设备。

- 应用集成AppServiceExtensionAbility的组件需要申请ACL权限（ohos.permission.SUPPORT_APP_SERVICE_EXTENSION）。该ACL权限当前只对企业普通应用开放申请。

- 如果[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)实例未启动，接口调用方必须为AppServiceExtensionAbility所属应用或者在AppServiceExtensionAbility支持的应用清单（即[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中的应用。

- AppServiceExtensionAbility内不支持调用[window](../reference/apis-arkui/arkts-apis-window.md)相关API。

## 运行机制

- 本文将被启动的AppServiceExtensionAbility为服务端，将启动AppServiceExtensionAbility的组件为客户端。

- 若AppServiceExtensionAbility只通过connect的方式被拉起，那么该AppServiceExtensionAbility的生命周期将受客户端控制，当客户端调用一次[connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)方法，将建立一个连接，当客户端退出或者调用[disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20)方法，该连接将断开。当所有连接都断开后，AppServiceExtensionAbility将自动退出。

- AppServiceExtensionAbility一旦通过start的方式被拉起，将不会自动退出，应用可以调用[stopAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20)方法将AppServiceExtensionAbility退出。

- AppServiceExtensionAbility以start方式启动，并且没有连接的时候，AppServiceExtensionAbility进程可能被挂起（请参考[Background Tasks Kit简介](../task-management/background-task-overview.md)）。

## 实现一个后台服务

### 创建一个后台服务

在DevEco Studio工程中手动新建一个AppServiceExtensionAbility，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为AppServiceExtAbility。

2. 在AppServiceExtAbility目录，右键选择“New &gt; ArkTS File”，新建一个文件并命名为AppServiceExtAbility.ets。

    ```
    ├── ets
    │ ├── AppServiceExtAbility
    │ │   ├── AppServiceExtAbility.ets
    └
    ```

3. 在AppServiceExtAbility.ets文件中，增加导入[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)的依赖包，自定义类继承AppServiceExtensionAbility并实现生命周期回调。

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }
    }

    export default class AppServiceExtAbility extends AppServiceExtensionAbility {
      onCreate(want: Want): void {
        let appServiceExtensionContext = this.context;
        hilog.info(DOMAIN_NUMBER, TAG, `onCreate, want: ${want.abilityName}`);
      };

      onRequest(want: Want, startId: number): void {
        hilog.info(DOMAIN_NUMBER, TAG, `onRequest, want: ${want.abilityName}`);
      };

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(DOMAIN_NUMBER, TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest("test");
      };

      onDisconnect(want: Want): void {
        hilog.info(DOMAIN_NUMBER, TAG, `onDisconnect, want: ${want.abilityName}`);
      };

      onDestroy(): void {
        hilog.info(DOMAIN_NUMBER, TAG, 'onDestroy');
      };
    };
    ```

4. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册AppServiceExtensionAbility，type标签需要设置为“appService”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

    ```json
    {
      "module": {
        // ...
        "extensionAbilities": [
          {
            "name": "AppServiceExtAbility",
            "icon": "$media:icon",
            "description": "appService",
            "type": "appService",
            "exported": true,
            "srcEntry": "./ets/AppServiceExtAbility/AppServiceExtAbility.ets"
          }
        ]
      }
    }
    ```

### 启动一个后台服务

应用通过[startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20)方法启动一个后台服务，服务的[onRequest()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onrequest)回调就会被调用，并在该回调方法中接收到调用者传递过来的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)对象。后台服务启动后，其生命周期独立于客户端，即使客户端已经销毁，该后台服务仍可继续运行。因此，后台服务需要在其工作完成时通过调用[AppServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-appServiceExtensionContext.md)的[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-appServiceExtensionContext.md#terminateself)来自行停止，或者由另一个组件调用[stopAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20)来将其停止。


- 在应用中启动一个新的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

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
                abilityName: 'AppServiceExtAbility'
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

- 在应用中停止一个已启动的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)。

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
                abilityName: 'AppServiceExtAbility'
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

- 已启动的[AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)停止自身。

    ```ts
    import { AppServiceExtensionAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtensionAbility]';

    export default class AppServiceExtension extends AppServiceExtensionAbility {
      onCreate() {
      // 执行业务逻辑
        this.context.terminateSelf().then(() => {
          hilog.info(0x0000, TAG, '----------- terminateSelf succeed -----------');
        }).catch((error: BusinessError) => {
          hilog.error(0x0000, TAG, `terminateSelf failed, error.code: ${error.code}, error.message: $   {error.message}`);
        });
      }
    }
    ```

### 连接一个后台服务

客户端可以通过[connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20)连接服务端（在Want对象中指定启动的目标服务），服务端的[onConnect()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onconnect)就会被调用，并在该回调方法中接收到客户端传递过来的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)对象，从而建立长连接。

服务端的AppServiceExtensionAbility组件会在onConnect()中返回[IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject)对象给作客户端[ConnectOptions](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md)的[onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)方法的入参。开发者通过该IRemoteObject定义通信接口，实现客户端与服务端进行RPC交互。多个客户端可以同时连接到同一个后台服务，客户端完成与服务端的交互后，客户端需要通过调用[disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20)来断开连接。如果所有连接到某个后台服务的客户端均已断开连接，则系统会销毁该服务。

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
    abilityName: 'AppServiceExtAbility'
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

## 客户端与服务端通信

客户端在[onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect)中获取到[rpc.IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject)对象后便可与Service进行通信。

使用[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9)接口向服务端发送消息。

```ts
import { common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_CollaborateAbility]';
const DOMAIN_NUMBER: number = 0xFF00;
const REQUEST_CODE = 1;
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

    data.writeInt(99);
    // 开发者可发送data到目标端应用进行相应操作
    // @param code 表示客户端发送的服务请求代码。
    // @param data 表示客户端发送的{@link MessageSequence}对象。
    // @param reply 表示远程服务发送的响应消息对象。
    // @param options 指示操作是同步的还是异步的。
    // @return 如果操作成功返回{@code true}； 否则返回 {@code false}。

    remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
      let errCode = reply.readInt(); // 在成功连接的情况下，会收到来自目标端返回的信息（100）
      let msg: number = 0;
      if (errCode === 0) {
        msg = reply.readInt();
      }
      // 成功连接后台服务
      hilog.info(DOMAIN_NUMBER, TAG, `sendRequest success, msg:${msg}`);
    }).catch((error: BusinessError) => {
      hilog.info(DOMAIN_NUMBER, TAG, `sendRequest failed, ${JSON.stringify(error)}`);
    });
  },
  onDisconnect(elementName): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
  },
  onFailed(code): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback');
  }
};
// 调用connectAppServiceExtension相关代码
```

## 服务端对客户端身份校验

部分开发者需要使用AppServiceExtensionAbility提供一些较为敏感的服务，可以通过如下方式对客户端身份进行校验。

<!--Del-->
### 通过callerUid识别客户端应用

通过调用[getCallingUid()](../reference/apis-ipc-kit/js-apis-rpc.md#getcallinguid)接口获取客户端的uid，再调用[getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14)接口获取uid对应的bundleName，从而识别客户端身份。此处需要注意的是[getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14)是一个异步接口，因此服务端无法将校验结果返回给客户端，这种校验方式适合客户端向服务端发起执行异步任务请求的场景，示例代码如下：

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = "[AppServiceExtImpl]";
const DOMAIN_NUMBER: number = 0xFF00;

// 开发者需要在这个类型里对接口进行实现
class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    // 开发者自行实现业务逻辑
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
    return true;
  }
}

export default class AppServiceExtension extends AppServiceExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
      return new Stub('test');
  }
  // 其他生命周期
}
```
<!--DelEnd-->

### 通过callerTokenId对客户端进行鉴权

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
    let accessManger = abilityAccessCtrl.createAtManager();
    // 所校验的具体权限由开发者自行选择，此处ohos.permission.GET_BUNDLE_INFO_PRIVILEGED只作为示例
    let grantStatus = accessManger.verifyAccessTokenSync(callerTokenId, 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED');
    if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_DENIED) {
      hilog.error(DOMAIN_NUMBER, TAG, 'PERMISSION_DENIED');
      return false;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'verify access token success.');
    return true;
  }
}

export default class AppServiceExtension extends AppServiceExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
      return new Stub('test');
  }
  // 其他生命周期
}
```

