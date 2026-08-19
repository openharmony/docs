# @ohos.web.webNativeMessagingExtensionManager (Web Native Messaging Extension Manager)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @csliutt-private-->
<!--Designer: @ringking0-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

webNativeMessagingExtensionManager模块是ArkWeb提供的Web原生消息扩展管理模块，用于在应用侧（调用方）发起并管理到[WebNativeMessagingExtensionAbility](./arkts-apis-web-webNativeMessagingExtensionAbility.md)的连接。开发者可通过[connectNative](#webnativemessagingextensionmanagerconnectnative)方法指定目标扩展Ability并建立连接，通过返回的连接ID与[WebExtensionConnectionCallback](#webextensionconnectioncallback)监听连接建立、断开及失败事件，也可通过[disconnectNative](#webnativemessagingextensionmanagerdisconnectnative)主动释放连接。该模块适用于浏览器扩展与应用通信的场景；使用前需申请[ohos.permission.WEB_NATIVE_MESSAGING](../../security/AccessToken/restricted-permissions.md#ohospermissionweb_native_messaging)权限，且仅在Stage模型下可用。

> **说明**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';
```

## ConnectionNativeInfo
表示Web原生消息连接的连接信息。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| connectionId | number | 否 | 否 | Web原生消息扩展连接的唯一标识，由connectNative方法返回，用于标识和管理连接。 |
| bundleName | string | 否 | 否 | Web原生消息扩展应用的包名。 |
| extensionOrigin | string | 否 | 否 | 浏览器扩展的源URL。 |
| extensionPid | number | 否 | 否 | Web原生消息扩展的进程ID。 |

## NmErrorCode

Native Messaging的错误列表。

**系统能力**：SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| PERMISSION_DENY | 17100203 | 由于缺少ohos.permission.WEB_NATIVE_MESSAGING，权限被拒绝。 |
| WANT_CONTENT_ERROR | 17100202 | Want内容无效。 |
| INNER_ERROR | 17100201 | 表示有内部错误发生。 |

## WebExtensionConnectionCallback

### onConnect
onConnect(connection: ConnectionNativeInfo): void

建立连接时的回调函数。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| connection | [ConnectionNativeInfo](#connectionnativeinfo) | 是 | 连接信息，包含连接ID、扩展应用包名、浏览器扩展源URL和扩展进程ID等信息。 |

**示例:**
```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';
import { common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    try {
        let context: common.UIAbilityContext = this.context; // 获取UIAbilityContext
        let want: Want = {
          bundleName: 'com.example.app',
          abilityName: 'MyWebNativeMessageExtAbility',
          parameters: {
            'ohos.arkweb.messageReadPipe': { 'type': 'FD', 'value': 333 }, //假设此处为合法pipefd
            'ohos.arkweb.messageWritePipe': { 'type': 'FD', 'value': 444 }, //假设此处为合法pipefd
            'ohos.arkweb.extensionOrigin': 'chrome-extension://knldjmfmopnpolahpmmgbagdohdnhkik/' // 此处需要插件URI
          },
        };

        let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
            onConnect(connection) {
                console.info('onConnect, connectionId:' + connection.connectionId);
            },
            onDisconnect(connection) {
                console.info('onDisconnect');
            },
            onFailed(code, errMsg) {
                console.info(`onFailed, code:${code} errMsg:${errMsg}`);
            }
        };

        let connectionId = webNativeMessagingExtensionManager.connectNative(context, want, callback);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectNative failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### onDisconnect
onDisconnect(connection: ConnectionNativeInfo): void

断开连接时的回调函数。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| connection | [ConnectionNativeInfo](#connectionnativeinfo) | 是 | 连接信息，包含连接ID、扩展应用包名、浏览器扩展源URL和扩展进程ID等信息。 |

**示例:**
```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';
import { common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    try {
        let context: common.UIAbilityContext = this.context; // 获取UIAbilityContext
        let want: Want = {
          bundleName: 'com.example.app',
          abilityName: 'MyWebNativeMessageExtAbility',
          parameters: {
            'ohos.arkweb.messageReadPipe': { 'type': 'FD', 'value': 333 }, //假设此处为合法pipefd
            'ohos.arkweb.messageWritePipe': { 'type': 'FD', 'value': 444 }, //假设此处为合法pipefd
            'ohos.arkweb.extensionOrigin': 'chrome-extension://knldjmfmopnpolahpmmgbagdohdnhkik/' // 此处需要插件URI
          },
        };

        let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
            onConnect(connection) {
                console.info('onConnect, connectionId:' + connection.connectionId);
            },
            onDisconnect(connection) {
                console.info('onDisconnect');
            },
            onFailed(code, errMsg) {
                console.info(`onFailed, code:${code} errMsg:${errMsg}`);
            }
        };

        let connectionId = webNativeMessagingExtensionManager.connectNative(context, want, callback);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectNative failed, code is ${code}, message is ${message}`);
    }
  }
}
```

### onFailed
onFailed(code: NmErrorCode, errMsg: string): void

连接失败时的回调函数。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| code | [NmErrorCode](#nmerrorcode) | 是 | 错误码。 |
| errMsg | string | 是 | 错误码对应信息。 |

**示例:**
```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';
import { common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    try {
        let context: common.UIAbilityContext = this.context; // 获取UIAbilityContext
        let want: Want = {
          bundleName: 'com.example.app',
          abilityName: 'MyWebNativeMessageExtAbility',
          parameters: {
            'ohos.arkweb.messageReadPipe': { 'type': 'FD', 'value': 333 }, //假设此处为合法pipefd
            'ohos.arkweb.messageWritePipe': { 'type': 'FD', 'value': 444 }, //假设此处为合法pipefd
            'ohos.arkweb.extensionOrigin': 'chrome-extension://knldjmfmopnpolahpmmgbagdohdnhkik/' // 此处需要插件URI
          },
        };

        let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
            onConnect(connection) {
                console.info('onConnect, connectionId:' + connection.connectionId);
            },
            onDisconnect(connection) {
                console.info('onDisconnect');
            },
            onFailed(code, errMsg) {
                console.info(`onFailed, code:${code} errMsg:${errMsg}`);
            }
        };

        let connectionId = webNativeMessagingExtensionManager.connectNative(context, want, callback);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectNative failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## webNativeMessagingExtensionManager.connectNative
connectNative(context: UIAbilityContext, want: Want, callback: WebExtensionConnectionCallback): number

将当前Ability连接到指定的Web原生消息扩展Ability。

**需要权限**：ohos.permission.WEB_NATIVE_MESSAGING

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | 调用方UIAbility的上下文。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 启动Ability的want信息，其parameters中需包含'ohos.arkweb.messageReadPipe'（读管道FD）、'ohos.arkweb.messageWritePipe'（写管道FD）和'ohos.arkweb.extensionOrigin'（插件URI）。 |
| callback | [WebExtensionConnectionCallback](#webextensionconnectioncallback) | 是 | WebExtensionConnection状态的回调对象。 |

**返回值:**

| 类型 | 说明 |
|------|------|
| number | 连接的标识ID，由[connectNative](#webnativemessagingextensionmanagerconnectnative)方法返回，用于唯一标识一次Web原生消息扩展连接。连接建立后需要通过disconnectNative释放。 |

**错误码:**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
|----------|----------|
| 801 | Capability not supported. |

**示例:**
```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';
import { common } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    try {
        let context: common.UIAbilityContext = this.context; // 获取UIAbilityContext
        let want: Want = {
          bundleName: 'com.example.app',
          abilityName: 'MyWebNativeMessageExtAbility',
          parameters: {
            'ohos.arkweb.messageReadPipe': { 'type': 'FD', 'value': 333 }, //假设此处为合法pipefd
            'ohos.arkweb.messageWritePipe': { 'type': 'FD', 'value': 444 }, //假设此处为合法pipefd
            'ohos.arkweb.extensionOrigin': 'chrome-extension://knldjmfmopnpolahpmmgbagdohdnhkik/' // 此处需要插件URI
          },
        };

        let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
            onConnect(connection) {
                console.info('onConnect, connectionId:' + connection.connectionId);
            },
            onDisconnect(connection) {
                console.info('onDisconnect');
            },
            onFailed(code, errMsg) {
                console.info(`onFailed, code:${code} errMsg:${errMsg}`);
            }
        };

        let connectionId = webNativeMessagingExtensionManager.connectNative(context, want, callback);
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`connectNative failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## webNativeMessagingExtensionManager.disconnectNative
disconnectNative(connectionId: number): Promise&lt;void&gt;

断开指定Web原生消息扩展连接。

**需要权限**：ohos.permission.WEB_NATIVE_MESSAGING

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| connectionId | number | 是 | 连接的标识ID，用于标识一次Web原生消息扩展连接，由[connectNative](#webnativemessagingextensionmanagerconnectnative)方法返回。建立连接后需要通过disconnectNative释放。需使用由connectNative返回的有效连接ID。 |

**返回值:**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码:**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
|----------|----------|
| 201 | Permission verification failed. |
| 801 | Capability not supported. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service failed to communicate with dependency module. |

**示例:**
```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { webNativeMessagingExtensionManager } from '@kit.ArkWeb';

export default class EntryAbility extends UIAbility {
  async disconnect() {
    try {
        let connectionId = 1;
        // 假设之前已连接并获得connectionId
        await webNativeMessagingExtensionManager.disconnectNative(connectionId).then(() => {
            console.info('disconnectNative success');
        })
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`disconnectNative failed, code is ${code}, message is ${message}`);
    }
  }
  onForeground() {
    this.disconnect();
  }
}
```
