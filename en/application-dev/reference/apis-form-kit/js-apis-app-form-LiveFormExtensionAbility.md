# @ohos.app.form.LiveFormExtensionAbility  (LiveFormExtensionAbility)

The **LiveFormExtensionAbility** module, inherited from [ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md), provides interactive widget functions, including creating and destroying interactive widgets.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```
## LiveFormExtensionAbility
Interactive widget extension class. It provides APIs for the widget provider to receive notifications about widget creation and destruction.

### Properties

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type   | Read-Only| Optional |Description|
| ------ | ------ | ---- | ---- | ---- |
| context |  [LiveFormExtensionContext](./js-apis-application-LiveFormExtensionContext.md) | No  | No|Context of the **LiveFormExtensionAbility**. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onLiveFormCreate

onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void

Called after the UI content of **LiveFormExtensionAbility** is created.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | Yes| Interactive widget information, including the widget ID.|
| session      | [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI information.|

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    console.info(TAG, `onLiveFormCreate, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```

### onLiveFormDestroy

onLiveFormDestroy(liveFormInfo: LiveFormInfo): void

Called to clear resources when this **LiveFormExtensionAbility** is destroyed.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | Yes| Interactive widget information, including the widget ID.|

**Example**

```ts
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.info(TAG, `onLiveFormDestroy, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```
### LiveFormInfo

Defines the interactive widget information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type| Read-Only| Optional| Description|
| ------ | ------ | ---- | ---- | -------- |
| formId | string | No| No| Widget ID.|
| rect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | No| No| Widget location and dimension.|
| borderRadius | number | No| No| Widget corner radius. The value must be greater than 0, in vp.|
