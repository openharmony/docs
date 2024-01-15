# @ohos.app.ability.UIExtensionContentSession (带界面扩展能力界面操作类)

一个UIExtensionComponent控件对应一个UIExtensionContentSession对象，每个UIExtensionAbility的UIExtensionContentSession之间互不影响，可以各自进行操作。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
```

## UIExtensionContentSession.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback, callback: AsyncCallback\<void>) : void;

通过type隐式启动UIExtensionAbility。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | {[key: string]: any} | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，返回接口调用是否成功。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

## UIExtensionContentSession.startAbilityByType<sup>11+</sup>

startAbilityByType(type: string, wantParam: Record<string, Object>,
    abilityStartCallback: AbilityStartCallback) : Promise\<void>;

通过type隐式启动UIExtensionAbility。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 显示拉起的UIExtensionAbility类型。 |
| wantParam | {[key: string]: Object} | 是 | 表示扩展参数。 |
| abilityStartCallback | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 是 | 启动失败后的回调。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象无返回值。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。