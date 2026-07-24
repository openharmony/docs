# @ohos.web.WebNativeMessagingExtensionContext (Web Native Messaging Extension Context)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @csliutt-private-->
<!--Designer: @ringking0-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebNativeMessagingExtensionContext是Web原生消息扩展（[WebNativeMessagingExtensionAbility](./arkts-apis-web-webNativeMessagingExtensionAbility.md)）的运行上下文，继承自ExtensionContext，为扩展Ability提供生命周期管理、Ability启动以及原生消息连接控制能力。开发者可在继承WebNativeMessagingExtensionAbility的扩展中通过`this.context`获取该上下文，进而调用[startAbility](#startability)启动其他Ability、调用[startAbilityForResult](#startabilityforresult)启动UIAbility并接收返回结果、调用[terminateSelf](#terminateself)结束当前扩展，或调用[stopNativeConnection](#stopnativeconnection)停止指定的Web原生消息连接。

> **说明:**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';
```

## WebNativeMessagingExtensionContext

WebNativeMessagingExtensionContext是Web原生消息扩展的上下文，包含所需交互能力。

### startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;

使用Promise异步回调启动Ability。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|-------|-------|-------|-------|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 表示需要启动的Ability的信息。 |
| options | [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md) | 否 | 启动选项。 |

**返回值:**

| 类型 | 说明 |
|------|------|
|Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码:**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息                                 |
| -------- | ----------------------------------------|
| 201      | The application does not have permission to call the interface. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000008 | The crowdtesting application expires.  |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service failed to communicate with dependency module. |
| 16000055 | Installation-free timed out. |
| 16000071 | App clone is not supported. |
| 16000072 | App clone or multi-instance is not supported. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The multi-instance is not supported. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Creating a new instance is not supported. |

**示例:**


```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onConnectNative(info: ConnectionInfo): void {
    const abilityWant: Want = {
    bundleName: 'com.example.mybundle',
    abilityName: 'MainAbility'
    };
    try {
        const context = this.context; // 获取 WebNativeMessagingExtensionContext 实例
        context.startAbility(abilityWant);
        console.info('Ability started successfully');
    } catch (err) {
        console.error(`Failed to start ability. Code: ${(err as BusinessError).code},
        Message: ${(err as BusinessError).message}`);
    }
  }
}
```

### startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

启动一个UIAbility，开发者可以通过回调函数接收被拉起的UIAbility退出时的返回结果。使用Promise异步回调。

UIAbility被启动后，有如下情况：
 - 正常情况下可通过调用[terminateSelfWithResult](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)接口使之终止并且返回结果给调用方。
 - 异常情况下比如销毁UIAbility会返回异常信息给调用方，异常信息中resultCode为-1。
 - 只支持拉起自己应用的UIAbility。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Web.Webview.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|-------|-------|-------|-------|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 表示需要启动的UIAbility的信息。 |
| options | [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md) | 否 | 启动选项。 |

**返回值:**

| 类型 | 说明 |
|------|------|
|Promise&lt;[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)&gt; | Promise对象，返回被启动方退出时的结果码和数据。 |

**错误码:**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息                                 |
| -------- | ----------------------------------------|
| 201      | The application does not have permission to call the interface. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000008 | The crowdtesting application expires.  |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled by the AppGallery and cannot be started. |
| 16000013 | The application is controlled by Enterprise Device Manager and cannot be started. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service failed to communicate with dependency module. |
| 16000055 | Installation-free timed out. |
| 16000071 | The application does not support appClone mode in multiAppMode. |
| 16000072 | The application does not support appClone and multi-instance mode in multiAppMode. |
| 16000073 | The app clone index is invalid. |
| 16000076 | The app instance key is invalid. |
| 16000077 | The number of app instances reaches the limit. |
| 16000078 | The application does not support multiple instances. |
| 16000079 | The APP_INSTANCE_KEY cannot be specified. |
| 16000080 | Instances cannot be created for other applications during inter-application startup. |

**示例:**

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';
import { Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onConnectNative(info: ConnectionInfo): void {
    const abilityWant: Want = {
      bundleName: 'com.example.mybundle', // 请开发者替换为实际的 bundleName
      abilityName: 'MainAbility' // 请开发者替换为实际的 abilityName
    };
    try {
      const context = this.context; // 获取 WebNativeMessagingExtensionContext 实例
      context.startAbilityForResult(abilityWant).then((result: common.AbilityResult) => {
        console.info(`Ability started successfully, result code: ${result.resultCode}`);
        if (result.want) {
          console.info(`Result data: ${JSON.stringify(result.want)}`);
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to start ability. Code: ${(err as BusinessError).code},
        Message: ${(err as BusinessError).message}`);
      });
    } catch (err) {
      console.error(`Failed to start ability. Code: ${(err as BusinessError).code},
      Message: ${(err as BusinessError).message}`);
    }
  }
}
```

### terminateSelf
terminateSelf(): Promise&lt;void&gt;

销毁当前Web原生消息扩展。该方法返回一个Promise对象用于异步处理。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**返回值:**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码:**

以下错误码详细介绍请参考[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------- |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.      |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service failed to communicate with dependency module. |

**示例:**

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onConnectNative(info: ConnectionInfo): void {
    try {
        const context = this.context; // 获取 WebNativeMessagingExtensionContext 实例
        context.terminateSelf();
        console.info('Extension terminated successfully');
    } catch (err) {
        console.error(`Failed to terminate extension. Code: ${(err as BusinessError).code},
        Message: ${(err as BusinessError).message}`);
    }
  }
}
```

### stopNativeConnection

stopNativeConnection(connectionId: number): Promise&lt;void&gt;

停止指定的本地连接。使用Promise进行异步回调。

**系统能力:** SystemCapability.Web.Webview.Core

**模型约束:** 此接口仅可在Stage模型下使用。

**参数:**

| 参数名 | 类型 | 必填 | 说明 |
|-------|-------|-------|-------|
| connectionId | number | 是 | 要停止的连接ID。取值范围为正整数，必须是有效的连接ID。当connectionId值无效时，会对应返回错误码。 |

**返回值:**

| 类型 | 说明 |
|------|------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码:**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
|---------|----------|
| 201 | The application does not have permission to call the interface. |
| 16000011 | The context does not exist.      |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service failed to communicate with dependency module. |

**示例:**

```ts
import { WebNativeMessagingExtensionAbility, ConnectionInfo } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

export class MyWebNativeMessagingExtension extends WebNativeMessagingExtensionAbility {
  onConnectNative(info: ConnectionInfo): void {
    const CONNECTION_ID = 12345; // 实际的连接 ID
    try {
        const context = this.context;// 获取 WebNativeMessagingExtensionContext 实例
        context.stopNativeConnection(CONNECTION_ID);
        console.info('Native connection stopped successfully');
    } catch (err) {
        console.error(`Failed to stop native connection. Code: ${(err as BusinessError).code},
        Message: ${(err as BusinessError).message}`);
    }
  }
}
```
