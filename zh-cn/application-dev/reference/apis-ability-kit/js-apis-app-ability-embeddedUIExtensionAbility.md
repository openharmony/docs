# @ohos.app.ability.EmbeddedUIExtensionAbility (跨进程界面嵌入扩展能力)

EmbeddedUIExtensionAbility为开发者提供了跨进程界面嵌入的能力，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。目前EmbeddedUIExtensionAbility只能被同应用的UIAbility拉起，并且仅允许在拥有多进程权限的场景下使用。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [UIExtensionContext](js-apis-inner-application-uiExtensionContext.md) | 否 | 否 | 上下文。 |

## EmbeddedUIExtensionAbility.onCreate

onCreate(): void

EmbeddedUIExtensionAbility创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onCreate() {
      console.info(TAG, `onCreate`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

当EmbeddedUIExtensionAbility界面内容对象创建后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 当前EmbeddedUIExtensionAbility的Want类型信息，包括Ability名称、Bundle名称等。 |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | EmbeddedUIExtensionAbility界面内容相关信息。 |

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility, Want, UIExtensionContentSession } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

当EmbeddedUIExtensionAbility界面内容对象销毁后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| session | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | 是 | EmbeddedUIExtensionAbility界面内容相关信息。 |

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility, UIExtensionContentSession } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onSessionDestroy(session: UIExtensionContentSession) {
      console.info(TAG, `onSessionDestroy`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onForeground

onForeground(): void

EmbeddedUIExtensionAbility生命周期回调，当EmbeddedUIExtensionAbility从后台转到前台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onForeground() {
      console.info(TAG, `onForeground`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onBackground

onBackground(): void

EmbeddedUIExtensionAbility生命周期回调，当EmbeddedUIExtensionAbility从前台转到后台时触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onBackground() {
      console.info(TAG, `onBackground`);
    }
  }
  ```

## EmbeddedUIExtensionAbility.onDestroy

onDestroy(): void | Promise&lt;void&gt;

EmbeddedUIExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。
在执行完onDestroy生命周期回调后，应用可能会退出，从而可能导致onDestroy中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDestroy完成后再继续后续的生命周期。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| void \| Promise\<void> | 无返回结果或无返回结果的Promise对象。       |

**示例：**

  ```ts
  import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';

  const TAG: string = '[testTag] EmbeddedUIExt';

  export default class EmbeddedUIExt extends EmbeddedUIExtensionAbility {
    onDestroy() {
      console.info(TAG, `onDestroy`);
    }
  }
  ```
