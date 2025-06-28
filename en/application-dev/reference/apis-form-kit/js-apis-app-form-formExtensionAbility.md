# @ohos.app.form.FormExtensionAbility (FormExtensionAbility)

The **FormExtensionAbility** module provides lifecycle callbacks invoked when a widget is created, destroyed, or updated.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The formExtensionAbility is cleared after 10 seconds of inactivity.
>
> The following modules cannot be referenced in the FormExtensionAbility, as doing so may cause the program to exit abnormally:
> - @ohos.ability.particleAbility (ParticleAbility)
> - @ohos.multimedia.audio (Audio Management)
> - @ohos.multimedia.camera (Camera Management)
> - @ohos.multimedia.media (Media)
> - @ohos.resourceschedule.backgroundTaskManager (Background Task Management)


## Modules to Import

```ts
import { FormExtensionAbility } from '@kit.FormKit';
```

## FormExtensionAbility

Widget extension class. It provides APIs to notify the widget provider that a widget is being created or the widget visibility status is being changed.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

### Attributes

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

| Name   | Type                                                        | Readable| Writable| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | Yes  | No  | Context of the FormExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

### FormExtensionAbility.onAddForm

onAddForm(want: Want): formBindingData.FormBindingData

Called to notify the widget provider that a widget is being created.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                  | Mandatory| Description                                                        |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information of the widget. You can set the **parameters** field to one or more values enumerated in [widget parameters](./js-apis-app-form-formInfo.md#formparam), such as widget ID, widget name, and widget style. The information must be managed as persistent data to facilitate subsequent widget update and deletion.|

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | A **formBindingData.FormBindingData** object containing the data to be displayed on the widget.|

**Example**

```ts
import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.log(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let dataObj1: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };

    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

### FormExtensionAbility.onCastToNormalForm

onCastToNormalForm(formId: string): void

Called to notify the widget provider that a temporary widget is being converted to a normal one.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| formId | string | Yes  | ID of the widget that requests to be converted to a normal one.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onCastToNormalForm(formId: string) {
    console.log(`FormExtensionAbility onCastToNormalForm, formId: ${formId}`);
  }
};
```

### FormExtensionAbility.onUpdateForm

onUpdateForm(formId: string, wantParams?: Record<string, Object>): void

Called to notify the widget provider that a widget is being updated, with update parameters carried. After obtaining the latest data, your application should call [updateForm](js-apis-app-form-formProvider.md#formproviderupdateform) of **formProvider** to update the widget data.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget that requests to be updated.|
| wantParams<sup>12+</sup> | Record<string, Object> | No  | Parameters used for the update.|

**Example**

```ts
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onUpdateForm(formId: string, wantParams?: Record<string, Object>) {
    console.log(`FormExtensionAbility onUpdateForm, formId: ${formId},
        wantPara: ${wantParams?.['ohos.extra.param.key.host_bg_inverse_color']}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
    formProvider.updateForm(formId, obj2).then(() => {
      console.log(`FormExtensionAbility context updateForm`);
    }).catch((error: BusinessError) => {
      console.error(`FormExtensionAbility context updateForm failed, data: ${error}`);
    });
  }
};
```

### FormExtensionAbility.onChangeFormVisibility

onChangeFormVisibility(newStatus: Record\<string, number>): void

Called to notify the widget provider that the widget visibility status is being changed.
This API is valid only for system applications when **formVisibleNotify** is set to **true**.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| newStatus  | Record\<string, number> | Yes  | ID and visibility status of the widget to be changed.|

**Example**

```ts
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

// According to the ArkTS specification, Object.keys and for..in... cannot be used in .ets files to obtain the key value of an object. Use the user-defined function getObjKeys instead.
// Extract this function to a .ts file and export it. Import this function to the required .ets file before using it.
function getObjKeys(obj: Object): string[] {
  let keys = Object.keys(obj);
  return keys;
}

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onChangeFormVisibility(newStatus: Record<string, number>) {
    console.log(`FormExtensionAbility onChangeFormVisibility, newStatus: ${newStatus}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);

    let keys: string[] = getObjKeys(newStatus);

    for (let i: number = 0; i < keys.length; i++) {
      console.log(`FormExtensionAbility onChangeFormVisibility, key: ${keys[i]}, value= ${newStatus[keys[i]]}`);
      formProvider.updateForm(keys[i], obj2).then(() => {
        console.log(`FormExtensionAbility context updateForm`);
      }).catch((error: BusinessError) => {
        console.error(`Operation updateForm failed. Cause: ${JSON.stringify(error)}`);
      });
    }
  }
};
```

### FormExtensionAbility.onFormEvent

onFormEvent(formId: string, message: string): void

Called to instruct the widget provider to process the widget event.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | Yes  | ID of the widget that requests the event.|
| message | string | Yes  | Event message.            |

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message: ${message}`);
  }
};
```

### FormExtensionAbility.onRemoveForm

onRemoveForm(formId: string): void

Called to notify the widget provider that a widget is being destroyed.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget to be destroyed.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onRemoveForm(formId: string) {
    console.log(`FormExtensionAbility onRemoveForm, formId: ${formId}`);
  }
};
```

### FormExtensionAbility.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

Called when system configuration items change. The **onConfigurationUpdate** callback is triggered only when the FormExtensionAbility is alive. <!--Del-->Since API version 20, for system applications, the **onConfigurationUpdate** callback within the FormExtensionAbility will be triggered when the system language changes.<!--DelEnd-->

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](../apis-ability-kit/js-apis-app-ability-configuration.md) | Yes| New configuration.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Configuration } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    // This lifecycle callback is triggered only when the configuration is updated while the FormExtensionAbility is alive.
    // If no operation is performed within 10 seconds after a FormExtensionAbility instance is created, the instance will be deleted.
    console.log(`onConfigurationUpdate, config: ${JSON.stringify(newConfig)}`);
  }
};
```

### FormExtensionAbility.onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState

Called to notify the widget provider that the widget host is requesting the widget state. By default, the initial widget state is returned. (You can override this API as required.)

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Description of the widget state, including the bundle name, ability name, module name, widget name, and widget dimension.|

**Example**

```ts
import { FormExtensionAbility, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormState(want: Want) {
    console.log(`FormExtensionAbility onAcquireFormState, want: ${want}`);
    return formInfo.FormState.UNKNOWN;
  }
};
```

### FormExtensionAbility.onStop<sup>12+</sup>

onStop?(): void

Called when the widget process of the widget provider exits.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.
  
**System capability**: SystemCapability.Ability.Form

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onStop() {
    console.log(`FormExtensionAbility onStop`);
  }
}
```
