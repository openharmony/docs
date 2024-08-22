# @ohos.app.ability.UIExtensionAbility (带界面扩展能力基类)

UIExtensionAbility是特定场景下带界面扩展能力的基类，继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)，新增带界面扩展能力相关的属性和方法。不支持开发者直接继承该基类。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | 否 | 否 | UIExtensionAbility的上下文。 |

## UIExtensionAbility.onCreate

onCreate(launchParam: AbilityConstant.LaunchParam): void

UIExtensionAbility创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| launchParam<sup>12+</sup> | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#abilityconstantlaunchparam) | 是| 创建UIExtensionAbility、上次异常退出的原因信息。|

**示例：**

```ts
import { UIExtensionAbility, AbilityConstant } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onCreate(launchParam: AbilityConstant.LaunchParam) {
    console.info(TAG, `onCreate`);
    console.log(`onCreate, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

## UIExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

当UIExtensionAbility界面内容对象创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前UIExtensionAbility的Want类型信息，包括ability名称、bundle名称等。 |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | UIExtensionAbility界面内容相关信息。 |

**示例：**

```ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
  }
}
```

## UIExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

当UIExtensionAbility界面内容对象销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | UIExtensionAbility界面内容相关信息。 |

**示例：**

```ts
import { UIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onSessionDestroy(session: UIExtensionContentSession) {
    console.info(TAG, `onSessionDestroy`);
  }
}
```

## UIExtensionAbility.onForeground

onForeground(): void

UIExtensionAbility生命周期回调，当UIExtensionAbility从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    console.info(TAG, `onForeground`);
  }
}
```

## UIExtensionAbility.onBackground

onBackground(): void

UIExtensionAbility生命周期回调，当UIExtensionAbility从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onBackground() {
    console.info(TAG, `onBackground`);
  }
}
```

## UIExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。                            |

UIExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。
在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';

const TAG: string = '[testTag] UIExtAbility';

export default class UIExtAbility extends UIExtensionAbility {
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}
```
