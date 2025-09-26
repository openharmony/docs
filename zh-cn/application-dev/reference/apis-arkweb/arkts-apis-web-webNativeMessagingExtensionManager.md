# @ohos.web.webNativeMessagingExtensionManager (Web Native Messaging Extension Manager)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @weixin_41848015-->
<!--Designer: @libing23232323-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

webNativeMessagingExtensionManager模块提供基于Web标准的消息扩展管理能力。

> **说明**
> 
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import webNativeMessagingExtensionManager from '@kit.ArkWeb';
```

## ConnectionNativeInfo
表示Web原生消息连接的连接信息。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| connectionId | number | 否 | 否 | 连接ID。 |
| bundleName | string | 否 | 否 | Web原生消息扩展应用的包名。 |
| extensionOrigin | string | 否 | 否 | 浏览器扩展的源URL。 |
| extensionPid | number | 否 | 否 | Web原生消息扩展的进程ID。 |

## NmErrorCode

Native Messaging的错误列表。

**系统能力**：SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                                      |
| ------------- | -- |----------------------------------------- |
| PERMISSION_DENY | 17100203 | Permission denied due to missing ohos.permission.WEB_NATIVE_MESSAGING. |
| WANT_CONTENT_ERROR | 17100202 | The want content is invalid. |
| INNER_ERROR | 17100201 | Inner error for native messaging.Error code: |

## WebExtensionConnectionCallback
连接Web原生消息扩展时的输入参数，接收连接状态变化。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| onConnect | connection: [ConnectionNativeInfo](#connectionnativeinfo) | 否 | 否 | 连接成功时的回调。 |
| onDisconnect | connection: [ConnectionNativeInfo](#connectionnativeinfo) | 否 | 否 | 连接断开时的回调。 |
| onFailed | code: [NmErrorCode](#NmErrorCode) | 否 | 否 | 连接失败时的回调, 返回错误码。 |

## webNativeMessagingExtensionManager.connectNative
connectNative(context: UIAbilityContext, want: Want, callback: WebExtensionConnectionCallback): number

将当前Ability连接到指定的Web原生消息扩展Ability。需要申请权限：ohos.permission.WEB_NATIVE_MESSAGING。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | Web原生消息扩展的上下文。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | [WebExtensionConnectionCallback](#Webextensionconnectioncallback) | 是 | WebExtensionConnection状态的回调对象。 |

**返回值:**

| 类型 | 说明 |
|------|------|
| number | 连接标识ID。 |

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
        let want:Want = {
          bundleName: 'com.example.app',
          abilityName: 'MyWebNativeMessageExtAbility',
          parameters: {
            'ohos.arkweb.messageReadPipe': { 'type': 'FD', 'value': 333 }, //假设此处为合法pipefd
            'ohos.arkweb.messageWritePipe': { 'type': 'FD', 'value': 444 }, //假设此处为合法pipefd
            'ohos.arkweb.extensionOrigin': 'chrome-extension://knldjmfmopnpolahpmmgbagdohdnhkik/' //此处需要插件URI
          },
        };

        let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
            onConnect(connection) {
                console.info('onConnect, connectionId:' + connection.connectionId);
            },
            onDisconnect(connection) {
                console.info('onDisconnect');
            },
            onFailed(code) {
                console.info('onFailed, code:' + code);
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

断开指定Web原生消息扩展连接。需要申请权限：ohos.permission.WEB_NATIVE_MESSAGING。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| connectionId | number | 是 | 连接的标识ID。 |

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
| 16000011 | The context does noet exist. |
| 16000050 | Internal error. |

**示例:**
```ts
import { UIAbility, Want } from '@kit.AbilityKit';
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