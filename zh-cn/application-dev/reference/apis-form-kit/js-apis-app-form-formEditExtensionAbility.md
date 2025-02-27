# @ohos.app.form.FormEditExtensionAbility  (FormEditExtensionAbility)

FormEditExtensionAbility模块提供卡片编辑功能，继承自UIExtensionAbility。

> **说明：**
>
> 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```

## 属性
**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form
  | 名称 | 类型    | 只读 | 可选  |说明|
  | ------ | ------ | ---- | ---- | ---- |
  | context |  [FormEditExtensionContext](./js-apis-inner-application-formEditExtensionContext.md) | 否   | 否 |FormEditExtensionAbility的上下文环境，默认值是继承自UIExtensionContext的对象。<br/>**原子化服务API：** 从API version16开始，该接口支持在原子化服务中使用。|

## onCreate

onCreate(launchParam: AbilityConstant.LaunchParam): void

FormEditExtensionAbility创建时回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | launchParam |  [AbilityConstant.LaunchParam](../apis-ability-kit/js-apis-app-ability-abilityConstant.md#launchparam) | 是   | 创建FormEditExtensionAbility时的启动参数。                               |


**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
import { AbilityConstant } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExampleFormEditExtensionAbility';
export default class ExampleFomrEditAbility extends FormEditExtensionAbility {
  onCreate(launchParam: AbilityConstant.LaunchParam) {
    console.info(TAG, `onCreate`);
    console.log(`onCreate, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

## onSessionCreate

onSessionCreate(want: Want, session: UIExtensionContentSession): void

执行加载卡片页面操作，FormEditExtensionAbility界面内容对象创建后调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 当前FormEditExtensionAbility的Want类型信息，包括ability名称、bundle等。|
  | session  |  [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)  | 是   | 加载界面内容时创建的UIExtensionContentSession对象。|


**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
import { Want,UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(TAG, `onSessionCreate want: ${JSON.stringify(want)}`);
  }
}
```

## onSessionDestroy

onSessionDestroy(session: UIExtensionContentSession): void

FormEditExtensionAbility界面内容对象销毁后调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | session  |   [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)  | 是   | 加载界面内容时创建的UIExtensionContentSession对象。|


**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility{
  onSessionDestroy() {
    console.info(TAG, `onSessionDestroy`);
  }
}
```
## onForeground

onForeground(): void

FormEditExtensionAbility生命周期回调，FormEditExtensionAbility从后台切到前台时触发。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility{
  onForeground() {
    console.info(TAG, `onForeground`);
  }
}
```
## onBackground

onBackground(): void

FormEditExtensionAbility生命周期回调，FormEditExtensionAbility从前台切到后台时触发。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility{
  onBackground() {
    console.info(TAG, `onBackground`);
  }
}
```

## onDestroy

onDestroy(): void | Promise&lt;void&gt;

FormEditExtensionAbility生命周期回调，销毁时调用，建议在该方法中执行资源清理操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**返回值：**
| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| Promise&lt;void&gt;|无返回结果的Promise对象。  |

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility{
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}
```