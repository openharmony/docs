# @ohos.app.ability.AppServiceExtensionAbility (应用后台服务扩展组件)

AppServiceExtensionAbility模块提供后台服务相关扩展能力，包括后台服务的创建、销毁、连接、断开等生命周期回调。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 约束限制

- 当前仅支持2in1设备。
- 当前仅适用于企业普通应用。

## 导入模块

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
```


## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [AppServiceExtensionContext](js-apis-inner-application-appServiceExtensionContext.md)  | 是 | 否 | AppServiceExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。 |


## AppServiceExtensionAbility.onCreate

onCreate(want: Want): void

在AppServiceExtensionAbility实例创建时，系统会触发该回调。应用可以在该接口中执行自己的业务逻辑初始化操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是 | 调用方拉起当前AppServiceExtensionAbility实例时传递的Want类型信息，包括Ability名称、Bundle名称等。 |

**示例：**

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';

    class AppServiceExtAbility extends AppServiceExtensionAbility {
      onCreate(want: Want) {
        hilog.info(0x0000, TAG, `onCreate, want: ${want.abilityName}`);
      }
    }
    ```

## AppServiceExtensionAbility.onDestroy

onDestroy(): void

在AppServiceExtensionAbility实例销毁时，系统会触发该回调。应用可以在该接口中执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

    ```ts
    import { AppServiceExtensionAbility } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';

    class AppServiceExtAbility extends AppServiceExtensionAbility {
      onDestroy() {
        hilog.info(0x0000, TAG, `onDestroy`);
      }
    }
    ```

## AppServiceExtensionAbility.onRequest

onRequest(want: Want, startId: number): void

使用[startAppServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartappserviceextensionability20)拉起AppServiceExtensionAbility实例时，系统会触发该回调。

- 如果该实例已创建，则会直接回调该接口。
- 如果该实例此前未被创建，则会先创建实例并触发[onCreate()](#appserviceextensionabilityoncreate)回调，再回调该接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是 | 调用方拉起当前AppServiceExtensionAbility实例时传递的Want类型信息，包括Ability名称、Bundle名称等。 |
| startId | number | 是 | 返回拉起次数。首次拉起初始值返回1，多次之后自动递增。 |

**示例：**

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';

    class AppServiceExtAbility extends AppServiceExtensionAbility {
      onRequest(want: Want, startId: number) {
        hilog.info(0x0000, TAG, `onRequest, want: ${want.abilityName}, startId: ${startId}`);
      }
    }
    ```

## AppServiceExtensionAbility.onConnect

onConnect(want: Want): rpc.RemoteObject

调用方使用[connectAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectappserviceextensionability20)连接AppServiceExtensionAbility实例时，系统会触发该回调。

- 如果该实例已创建，则会直接回调该接口。
- 如果该实例此前未被创建，则会先创建实例并触发[onCreate()](#appserviceextensionabilityoncreate)回调，再回调该接口。

应用需要在该接口中返回一个RemoteObject对象，用于客户端和服务端进行通信。当AppServiceExtensionAbility实例处于连接状态时，如果调用方发起新的连接，系统会返回缓存的RemoteObject对象，而不会重复回调[onConnect()](#appserviceextensionabilityonconnect)接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| 是 | 调用方拉起当前AppServiceExtensionAbility实例时传递的Want类型信息，包括Ability名称、Bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | 一个RemoteObject对象，用于客户端和服务端进行通信。 |

**示例：**

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';

    class StubTest extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
      }
    }

    class AppServiceExtAbility extends AppServiceExtensionAbility {
      onConnect(want: Want) {
        hilog.info(0x0000, TAG, `onConnect, want: ${want.abilityName}`);
        return new StubTest('test');
      }
    }
    ```

## AppServiceExtensionAbility.onDisconnect

onDisconnect(want: Want): void

当所有连接方断开与AppServiceExtensionAbility实例的连接时，系统会触发该回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| 是 | 调用方拉起当前AppServiceExtensionAbility实例时传递的Want类型信息，包括Ability名称、Bundle名称等。 |

**示例：**

    ```ts
    import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[AppServiceExtAbility]';

    class AppServiceExtAbility extends AppServiceExtensionAbility {
      onDisconnect(want: Want) {
        hilog.info(0x0000, TAG, `onDisconnect, want: ${want.abilityName}`);
      }
    }
    ```
