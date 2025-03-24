# @ohos.app.form.FormEditExtensionAbility  (FormEditExtensionAbility)

The **FormEditExtensionAbility** module, inherited from **UIExtensionAbility**, provides the widget editing function.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```

## Properties
**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form
  | Name| Type   | Read-Only| Optional |Description|
  | ------ | ------ | ---- | ---- | ---- |
  | context |  [FormEditExtensionContext](./js-apis-inner-application-formEditExtensionContext.md) | No  | No|Context of **FormEditExtensionAbility**. The default value is an object inherited from **UIExtensionContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## onCreate

onCreate(launchParam: AbilityConstant.LaunchParam): void

Called when **FormEditExtensionAbility** is created.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | launchParam |  [AbilityConstant.LaunchParam](../apis-ability-kit/js-apis-app-ability-abilityConstant.md#launchparam) | Yes  | Launch parameter when **FormEditExtensionAbility** is created.                              |


**Example**

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

Loads a widget page. This method is called after the UI content of **FormEditExtensionAbility** is created.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information of **FormEditExtensionAbility**, including the ability name and bundle.|
  | session  |  [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)  | Yes  | **UIExtensionContentSession** object created when the UI content is loaded.|


**Example**

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

Called after the UI content of **FormEditExtensionAbility** is destroyed.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | session  |   [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)  | Yes  | **UIExtensionContentSession** object created when the UI content is loaded.|


**Example**

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

Called when **FormEditExtensionAbility** is switched from the background to the foreground.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Example**

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

Called when **FormEditExtensionAbility** is switched from the foreground to the background.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Example**

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

Called when **FormEditExtensionAbility** is destroyed to clear resources.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Return value**
| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| Promise&lt;void&gt;|Promise that returns no value. |

**Example**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';

const TAG: string = '[testTag] ExampleFormEditAbility';
export default class ExampleFormEditAbility extends FormEditExtensionAbility{
  onDestroy() {
    console.info(TAG, `onDestroy`);
  }
}
```
