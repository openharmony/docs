# @ohos.web.WebNativeMessagingExtensionContext (Web Native Messaging Extension Context)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @bingli-->
<!--Designer: @bingli-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

WebNativeMessagingExtensionContext 是 Web 原生消息扩展的上下文, 继承自 ExtensionContext。它提供了与 WebNativeMessagingExtension 特定资源的交互能力。

> **说明:**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import WebNativeMessagingExtensionContext from '@kit.ArkWeb';
```

## WebNativeMessagingExtensionContext

### startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

启动一个新的 ability。使用 Promise 异步回调。

**系统能力:** SystemCapability.Web.Webview.Core

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|-------|-------|-------|-------|
| want | [Want](../apis-ability-kit/js-apis-ability-want.md) | 是 | 表示需要启动的 ability 的信息 |
| options | [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md) | 否 | 启动选项 |

**返回值:**

| 类型 | 说明 |
|------|------|
|Promise&lt;void&gt; | 无返回结果的 Promise 对象 |

**错误码:**

| 错误码ID | 错误信息                                 |
| -------- | ----------------------------------------|
| 202      | The application is not system-app, can not use system-api. |
| 401      | Parameter error. Possible causes: 1. Mandatory Parameters are left unspecified. 2. Incorrect parameter types.      |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires.  |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

**示例:**

```ts
import { want } from '@kit.AbilityKit';

const abilityWant: want.Want = {
    bundleName: 'com.example.mybundle',
    abilityName: 'MainAbility'
};

try {
    const context = ...; // 获取 WebNativeMessagingExtensionContext 实例
    await context.startAbility(abilityWant);
    console.log('Ability started successfully');
} catch (err) {
    console.error(`Failed to start ability. Code: ${err.code}, Message: ${err.message}`);
}
```

### terminateSelf
terminateSelf(): Promise&lt;void&gt;

销毁当前 Web 原生消息扩展。使用 Promise 异步回调。

**系统能力:** SystemCapability.Web.Webview.Core

**返回值:**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的 Promise 对象 |

**错误码:**

以下错误码详细介绍请参考[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.      |
| 16000050 | Internal error. |

**示例:**

```ts
try {
    const context = ...; // 获取 WebNativeMessagingExtensionContext 实例
    await context.terminateSelf();
    console.log('Extension terminated successfully');
} catch (err) {
    console.error(`Failed to terminate extension. Code: ${err.code}, Message: ${err.message}`);
}
```

### stopNativeConnection

stopNativeConnection(connectionId: number): Promise&lt;void&gt;

停止指定的本地连接。使用 Promise 异步回调。

**系统能力:** SystemCapability.Web.Webview.Core

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|-------|-------|-------|-------|
| connectionId | number | 是 | 要停止的连接 ID |

**返回值:**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的 Promise 对象 |

**错误码:**

| 错误码ID | 错误信息 |
|---------|----------|
| 201 | 应用无权调用此接口 |

**示例:**

```ts
const CONNECTION_ID = 12345; // 实际的连接 ID

try {
    const context = ...; // 获取 WebNativeMessagingExtensionContext 实例
    await context.stopNativeConnection(CONNECTION_ID);
    console.log('Native connection stopped successfully');
} catch (err) {
    console.error(`Failed to stop native connection. Code: ${err.code}, Message: ${err.message}`);
}
```