# webNativeMessagingExtensionManager (Web Native Messaging Extension Manager)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @bingli-->
<!--Designer: @bingli-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

webNativeMessagingExtensionManager模块提供Web原生的消息扩展管理能力。

> **说明**
> 
> 本模块首批接口从API version 20开始支持。后续版本的新增接口,采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import webNativeMessagingExtensionManager from '@kit.ArkWeb';
```

## ConnectionNativeInfo
表示Web原生消息连接的连接信息。

**系统能力:** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 说明 |
|------|------|------|
| connectionId | number | 连接ID |
| bundleName | string | Web原生消息拓展应用的包名 |
| extensionOrigin | string | 浏览器扩展的源URL |
| extensionPid | number | Web原生消息扩展应用的进程ID |

## WebExtensionConnectionCallback
在连接Web原生消息扩展时作为输入参数,用于接收连接过程中的状态变化。

**系统能力:** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 说明 |
|------|------|------|
| onConnect | connection: [ConnectionNativeInfo](#connectionnativeinfo) | 连接成功时的回调 |
| onDisconnect | connection: [ConnectionNativeInfo](#connectionnativeinfo) | 连接断开时的回调 |
| onFailed | code: number | 连接失败时的回调, 返回错误码 |

## webNativeMessagingExtensionManager.connectNative
connectNative(context: UIAbilityContext, want: Want, callback: WebExtensionConnectionCallback): number

连接当前Ability到指定的Web原生消息扩展Ability。

**系统能力:** SystemCapability.Web.Webview.Core

**参数:**
| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | 目标Web原生消息扩展的Want信息 |
| callback | [WebExtensionConnectionCallback](#Webextensionconnectioncallback) | 是 | 连接状态的回调对象 |

**返回值:**
| 类型 | 说明 |
|------|------|
| number | 返回连接的标识ID |

**错误码:**
| 错误码ID | 错误信息 |
|----------|----------|
| 801 | Capability not supported |

**示例:**
```ts
import webNativeMessagingExtensionManager from '@kit.ArkWeb';
import { UIAbilityContext } from '@kit.AbilityKit';

let context: UIAbilityContext = ...; // 获取UIAbilityContext
let want: Want = {
    bundleName: 'com.example.native_extension',
    abilityName: 'MyWebNativeMessagingExtension'
};
let callback: webNativeMessagingExtensionManager.WebExtensionConnectionCallback = {
    onConnect(connection) {
        console.log('onConnect, connectionId:' + connection.connectionId);
    },
    onDisconnect(connection) {
        console.log('onDisconnect');
    },
    onFailed(code) {
        console.log('onFailed, code:' + code);
    }
};

let connectionId = webNativeMessagingExtensionManager.connectNative(context, want, callback);
```

## webNativeMessagingExtensionManager.disconnectNative
disconnectNative(connectionId: number): Promise&lt;void&gt;

断开与指定Web原生消息扩展的连接。

**系统能力:** SystemCapability.Web.Webview.Core

**参数:**
| 参数名 | 类型 | 必填 | 说明 |
|------|------|------|------|
| connectionId | number | 是 | 连接的标识ID |

**返回值:**
| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的Promise对象 |

**错误码:**
| 错误码ID | 错误信息 |
|----------|----------|
| 801 | Capability not supported |

**示例:**
```ts
// 假设之前已连接并获得connectionId
webNativeMessagingExtensionManager.disconnectNative(connectionId).then(() => {
    console.log('disconnectNative success');
}).catch((err) => {
    console.error('disconnectNative failed, error:' + JSON.stringify(err));
});
```