# @ohos.web.WebNativeMessagingExtensionAbility (Web Native Messaging Extension Ability)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @csliutt-private-->
<!--Designer: @ringking0-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebNativeMessagingExtensionAbility是ArkWeb提供的Web原生消息通信扩展基类，继承自ExtensionAbility（扩展能力基类），允许Web页面通过Native Messaging机制与系统原生服务建立安全、双向的管道通信通道。开发者通过继承该类并实现其生命周期回调（如[onConnectNative](#onconnectnative)、[onDisconnectNative](#ondisconnectnative)、[onDestroy](#ondestroy)），可以在Web页面发起连接请求时感知连接建立、获取调用方身份与双向管道文件描述符（见[ConnectionInfo](#connectioninfo)），并在连接断开或扩展销毁时完成资源释放。该能力主要用于浏览器扩展与应用通信的场景，实现高效的消息传递和数据交换，提升扩展的集成度和功能性。应用侧需自行管理管道读写、权限校验及Ability生命周期。

> **说明:**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { WebNativeMessagingExtensionAbility } from '@kit.ArkWeb';
```

## WebNativeMessagingExtensionAbility

为开发者提供Web原生消息通信能力，继承自ExtensionAbility。

### 属性

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| context | [WebNativeMessagingExtensionContext](arkts-apis-web-webNativeMessagingExtensionContext.md) | 否 | 否 | 当前Web原生消息扩展Ability的上下文。 |

### onConnectNative

onConnectNative(info: ConnectionInfo): void

Web原生消息连接建立时回调此方法。在此回调中，可以获取连接信息，用于后续的消息通信处理。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ---- | ------ |
| info | [ConnectionInfo](#connectioninfo) | 是 | 连接信息对象。 |

**示例:**

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onConnectNative(info: ConnectionInfo): void {
    console.info('Web Native connection established!');
    console.info(`Connection ID: ${info.connectionId}`);
    console.info(`Caller bundle: ${info.bundleName}`);
    // 在此处处理连接建立后的业务逻辑
  }
}
```

### onDisconnectNative

onDisconnectNative(info: ConnectionInfo): void

Web原生消息连接断开时回调此方法。在此回调中，可以释放与该连接相关的资源，并完成必要的清理工作。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ---- | ------ |
| info | [ConnectionInfo](#connectioninfo) | 是 | 连接信息对象。 |

**示例:**

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onDisconnectNative(info: ConnectionInfo): void {
    console.info('Web Native connection closed!');
    console.info(`Connection ID: ${info.connectionId}`);
    // 在此处处理连接断开后的清理工作
  }
}
```

### onDestroy

onDestroy(): void

WebNativeMessagingExtensionAbility销毁时回调。在此回调中，可以释放所有占用的资源，并完成最终的清理操作。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**示例:**

```ts
import { WebNativeMessagingExtensionAbility } from '@kit.ArkWeb';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onDestroy(): void {
    console.info('WebNativeMessagingExtensionAbility is about to be destroyed!');
    // 在此处释放资源或者执行清理操作
  }
}
```

## ConnectionInfo

Web原生消息连接的信息对象。

**系统能力:** SystemCapability.Web.Webview.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| connectionId | number | 否 | 否 | 连接的唯一标识符，用于区分和管理不同的Web原生消息连接，可用于在日志、状态跟踪或资源清理时定位特定连接。 |
| bundleName | string | 否 | 否 | 调用方的应用包名，用于身份识别和权限校验，可据此判断是否允许该应用建立连接或进行消息交互。 |
| extensionOrigin | string | 否 | 否 | 调用方扩展的原始URL，用于安全控制和来源识别，可据此判断扩展的合法性或实施基于域名的访问策略。 |
| fdRead | number | 否 | 否 | 用于读取数据的管道文件描述符，可通过此文件描述符从Web端读取消息数据。 |
| fdWrite | number | 否 | 否 | 用于写入数据的管道文件描述符，可通过此文件描述符向Web端发送消息数据。 |