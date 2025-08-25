# Using AppServiceExtensionAbility for Background Services
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

Starting from API version 20, you can use the [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) component to provide backend services. This component is designed primarily for common enterprise applications on 2-in-1 devices, for example, EDR software for network security or MDM software for fleet management.

## Available APIs

You can invoke an AppServiceExtensionAbility from a UIAbility in two ways: starting or connecting. The comparison between the two methods is as follows.

| Invocation Method| API| Description|
| -------- | -------- | -------- |
| Start| [startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20) | After a UIAbility starts an AppServiceExtensionAbility, they have a weak association. The AppServiceExtensionAbility keeps running even after the UIAbility exits.|
| Connect| [connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20) | After a UIAbility connects to an AppServiceExtensionAbility, they have a strong association. The AppServiceExtensionAbility exits along with the UIAbility when the latter exits.|

## Constraints

- The AppServiceExtensionAbility takes effect only on 2-in-1 devices.

- To integrate an AppServiceExtensionAbility, applications must request the ACL permission (ohos.permission.SUPPORT_APP_SERVICE_EXTENSION). This ACL permission is available only for enterprise applications.

- If the [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) instance is not started, the caller must be the application to which the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md) instance belongs or an application in the application list supported by the AppServiceExtensionAbility instance (configured in the **appIdentifierAllowList** property of [extensionAbilities](../quick-start/module-configuration-file.md#extensionabilities)).

- APIs related to [Window](../reference/apis-arkui/arkts-apis-window.md) cannot be called in the AppServiceExtensionAbility.

## Working Principles

- In this document, the component that starts or connects to an AppServiceExtensionAbility is called the client, and the AppServiceExtensionAbility is called the server.

- If an AppServiceExtensionAbility is started only by means of connecting, its lifecycle is controlled by the client. A new connection is set up each time the client calls [connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20). When the client exits or calls [disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20), the connection is interrupted. After all connections are interrupted, the AppServiceExtensionAbility automatically exits.

- Once an AppServiceExtensionAbility is started by means of starting, it will not exit automatically. Applications can call [stopAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20) to stop it.

- When the AppServiceExtensionAbility is started by means of starting and has no active connections, its process may be suspended. For details, see [Introduction to Background Tasks Kit](../task-management/background-task-overview.md).

## Implementing a Background Service

### Creating a Background Service

To manually create an AppServiceExtensionAbility in the DevEco Studio project, perform the following steps:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **AppServiceExtAbility**.

2. Right-click the **AppServiceExtAbility** directory, and choose **New > ArkTS File** to create a file named **AppServiceExtAbility.ets**.

    ```
    ├── ets
    │ ├── AppServiceExtAbility
    │ │   ├── AppServiceExtAbility.ets
    └
    ```

3. In the **AppServiceExtAbility.ets** file, import the [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) module. Customize a class that inherits from AppServiceExtensionAbility and implement the lifecycle callbacks.

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

4. Register the AppServiceExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) of the module in the project. Set **type** to **"appService"** and **srcEntry** to the code path of the AppServiceExtensionAbility component.

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

### Starting a Background Service

An application uses [startAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20) to start a background service. The [onRequest()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onrequest) callback is invoked, through which the background service receives the [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md) object passed by the caller. After the background service is started, its lifecycle is independent of the client. In other words, even if the client is destroyed, the background service remains alive. Therefore, the background service must be stopped by calling [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-appServiceExtensionContext.md#terminateself) when its work is complete. Alternatively, another component can call [stopAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20) to stop the background service.


- Start a new [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) in an application. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

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
                // The background service is started.
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

- Stop the [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) in the application.

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

- Enable the [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) to stop itself.

    ```ts
    import { AppServiceExtensionAbility } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtensionAbility]';

    export default class AppServiceExtension extends AppServiceExtensionAbility {
      onCreate() {
      // Execute the service logic.
        this.context.terminateSelf().then(() => {
          hilog.info(0x0000, TAG, '----------- terminateSelf succeed -----------');
        }).catch((error: BusinessError) => {
          hilog.error(0x0000, TAG, `terminateSelf failed, error.code: ${error.code}, error.message: $   {error.message}`);
        });
      }
    }
    ```

### Connecting to a Background Service

The client can connect to a background service (specified in the Want object) through [connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20). The [onConnect()](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md#onconnect) callback is invoked, through which the background service receives the [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md) object passed by the client. In this way, a persistent connection is established.

The AppServiceExtensionAbility returns an [IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject) object in [onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect). This object is then delivered as an input parameter to the client's [onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect). Through this IRemoteObject, you can define communication interfaces for RPC interaction between the client and server. Multiple clients can simultaneously connect to the same background service. After a client finishes the interaction, it must call [disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20) to disconnect from the service. If all clients connected to a background service are disconnected, the system destroys the service.

- Call [connectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20) to establish a connection to a background service. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
  
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
      // Use remote for communication.
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
              // Save the connection ID, which will be used when the background service is disconnected.
              connectionId = context.connectAppServiceExtensionAbility(want, options);
              // The background service is connected.
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

- Use [disconnectAppServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectappserviceextensionability20) to disconnect from the background service.
  
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
              // connectionId is returned when connectServiceExtensionAbility is called and needs to be manually maintained.
              context.disconnectAppServiceExtensionAbility(connectionId).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'disconnectAppServiceExtensionAbility success');
                // The background service is disconnected.
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

## Communication Between the Client and Server

After obtaining the [rpc.IRemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#iremoteobject) from the [onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect) lifecycle callback, the client can communicate with the AppServiceExtensionAbility.

Call [sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9) to send messages to the server.

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
    // You can send data to the target application for corresponding operations.
    // @param code Indicates the service request code sent by the client.
    // @param data Indicates the {@link MessageSequence} object sent by the client.
    // @param reply Indicates the response message object sent by the remote service.
    // @param options Specifies whether the operation is synchronous or asynchronous.
    // @return Returns {@code true} if the operation is successful; returns {@code false} otherwise.

    remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
      let errCode = reply.readInt(); // Receive the information (100) returned by the target device if the connection is successful.
      let msg: number = 0;
      if (errCode === 0) {
        msg = reply.readInt();
      }
      // The background service is connected.
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
// Call the code related to connectAppServiceExtension.
```

## Client Identity Verification by the Server

If your AppServiceExtensionAbility provides sensitive operations, verify the client's identity with one of the following approaches.

<!--Del-->
### Verifying the Client Identity Based on callerUid

Call [getCallingUid()](../reference/apis-ipc-kit/js-apis-rpc.md#getcallinguid) to obtain the UID of the client, and then call [getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14) to obtain the corresponding bundle name. In this way, the client identity is verified. Note that [getBundleNameByUid()](../reference/apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagergetbundlenamebyuid14) is asynchronous, and therefore the server cannot return the verification result to the client. This verification mode applies when the client sends an asynchronous task request to the server. The sample code is as follows:

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = "[AppServiceExtImpl]";
const DOMAIN_NUMBER: number = 0xFF00;

// You need to implement APIs in this class.
class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    // Implement service logic.
    let callerUid = rpc.IPCSkeleton.getCallingUid();
    bundleManager.getBundleNameByUid(callerUid).then((callerBundleName) => {
      hilog.info(DOMAIN_NUMBER, TAG, 'getBundleNameByUid: ' + callerBundleName);
      // Identify the bundle name of the client.
      if (callerBundleName !== 'com.samples.stagemodelabilitydevelop') { // The verification fails.
        hilog.info(DOMAIN_NUMBER, TAG, 'The caller bundle is not in trustlist, reject');
        return;
      }
      // The verification is successful, and service logic is executed normally.
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
  // Other lifecycle states.
}
```
<!--DelEnd-->

### Verifying the Client Identity Based on callerTokenId

Call [getCallingTokenId()](../reference/apis-ipc-kit/js-apis-rpc.md#getcallingtokenid8) to obtain the token ID of the client, and then call [verifyAccessTokenSync()](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#verifyaccesstokensync9) to check whether the client has the required permission. Currently, the system does not support permission customization. Therefore, only [system-defined permissions](../security/AccessToken/app-permissions.md) can be verified. The sample code is as follows:

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
import { abilityAccessCtrl, bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AppServiceExtImpl]';
const DOMAIN_NUMBER: number = 0xFF00;

// You need to implement APIs in this class.

class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption): boolean | Promise<boolean> {
    // Implement service logic.
    hilog.info(DOMAIN_NUMBER, TAG, `onRemoteMessageRequest: ${data}`);
    let callerUid = rpc.IPCSkeleton.getCallingUid();
    bundleManager.getBundleNameByUid(callerUid).then((callerBundleName) => {
      hilog.info(DOMAIN_NUMBER, TAG, 'getBundleNameByUid: ' + callerBundleName);
      // Identify the bundle name of the client.
      if (callerBundleName !== 'com.samples.stagemodelabilitydevelop') { // The verification fails.
        hilog.info(DOMAIN_NUMBER, TAG, 'The caller bundle is not in trustlist, reject');
        return;
      }
    // The verification is successful, and service logic is executed normally.
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, 'getBundleNameByUid failed: ' + err.message);
    });

    let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
    let accessManger = abilityAccessCtrl.createAtManager();
    // The permission to be verified varies depending on the service requirements. ohos.permission.GET_BUNDLE_INFO_PRIVILEGED is only an example.
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
  // Other lifecycle states.
}
```
