# @ohos.app.form.FormExtensionAbility (FormExtensionAbility)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

The **FormExtensionAbility** module provides lifecycle callbacks invoked when a widget is created, destroyed, or updated. This module is applicable to scenarios where you need to implement widget functions in your application. It helps you quickly build a widget data update mechanism, improving user experience in interacting with your application.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The formExtensionAbility is cleared after 10 seconds of inactivity.

## Constraints

To ensure system security and stability and prevent **FormExtensionAbility** from abusing system resources, the system imposes certain restrictions. Importing the following modules is not supported:

- [@ohos.ability.particleAbility (ParticleAbility)](../apis-ability-kit/js-apis-ability-particleAbility.md)
- [@ohos.multimedia.audio (Audio Management)](../apis-audio-kit/arkts-apis-audio.md)
- [@ohos.multimedia.camera (Camera Management)](../apis-camera-kit/arkts-apis-camera.md)
- [@ohos.multimedia.media (Media)](../apis-media-kit/arkts-apis-media.md)
- [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)

## Modules to Import

```ts
import { FormExtensionAbility } from '@kit.FormKit';
```

## FormExtensionAbility

Widget extension class. It provides APIs to notify the widget provider that a widget is being created or the widget visibility status is being changed.

### Attributes

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name   | Type                                                        | Read-Only| Optional| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | No  | No  | Context of the FormExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### FormExtensionAbility.onAddForm

onAddForm(want: Want): formBindingData.FormBindingData

Called to notify the widget provider that a widget is being created. Note that **FormExtensionAbility** will be cleared after 10 seconds of inactivity. Do not perform time-consuming operations in the callback.

**Pairing usage**
- You must call [formBindingData.createFormBindingData()](./js-apis-app-form-formBindingData.md#formbindingdatacreateformbindingdata) to create a widget data object.
- Calling sequence: First create a data object (for example, **dataObj1**), and then call **formBindingData.createFormBindingData(dataObj1)** to create an **FormBindingData** object.
- Return requirements: This function must return a **FormBindingData** object, and the data to be displayed on the widget is passed in through the parameters.

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
| [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | A **formBindingData.FormBindingData** object containing the data to be displayed on the widget. It can be created via [formBindingData.createFormBindingData()](js-apis-app-form-formBindingData.md#formbindingdatacreateformbindingdata).|

**Example**

```ts
import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.info(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let temperatureData: Record<string, string> = {
      'temperature': '11°C',
      'time': '11:00'
    };

    let formBindingDataObj: formBindingData.FormBindingData = formBindingData.createFormBindingData(temperatureData);
    return formBindingDataObj;
  }
}
```

### FormExtensionAbility.onCastToNormalForm

onCastToNormalForm(formId: string): void

Called to notify the widget provider that a temporary widget has been converted to a normal one. Temporary widgets and normal widgets are concepts of the widget host. Temporary widgets have a brief existence, appearing following particular events or user interactions and vanishing automatically upon task completion. Normal widgets are persistent and remain on the home screen until the user actively removes or changes them. The functional widgets used in daily development all fall into this category. Temporary widgets are not used by widget hosts in the current version.

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
    // Called to notify the widget provider that a temporary widget has been converted to a normal one. You need to perform operations as required.
    console.info(`FormExtensionAbility onCastToNormalForm, formId: ${formId}`);
  }
}
```

### FormExtensionAbility.onUpdateForm

onUpdateForm(formId: string, wantParams?: Record<string, Object>): void

Called to notify the widget provider that a widget is being updated, with update parameters carried. After obtaining the latest data, your application should call [updateForm](js-apis-app-form-formProvider.md#formproviderupdateform) of **formProvider** to update the widget data. The **formId** and the **FormBindingData** object must be passed. The data object can be created via **formBindingData.createFormBindingData()**.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget to update.|
| wantParams<sup>12+</sup> | Record<string, Object> | No  | Update parameters, which are used to carry additional information about the widget update. This parameter is passed when custom parameters need to be passed to update the widget. If this parameter is not passed, the value is **undefined**. Supported parameters include **ohos.extra.param.key.host_bg_inverse_color** (whether to enable host background inversion color).|

**Example**

```ts
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onUpdateForm(formId: string, wantParams?: Record<string, Object>) {
    console.info(`FormExtensionAbility onUpdateForm, formId: ${formId},
        wantPara: ${wantParams?.['ohos.extra.param.key.host_bg_inverse_color']}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
    formProvider.updateForm(formId, obj2).then(() => {
      console.info(`FormExtensionAbility context updateForm`);
    }).catch((error: BusinessError) => {
      console.error(`FormExtensionAbility context updateForm failed, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
    });
  }
}
```

### FormExtensionAbility.onChangeFormVisibility

onChangeFormVisibility(newStatus: Record\<string, number>): void

Called to notify the widget provider that the widget visibility status is being changed. This callback is triggered when the widget visibility on the home screen changes (for example, the widget is blocked or moved out of the screen). You can optimize the resource usage of the widget or suspend unnecessary update operations, and update the widget data through **formProvider.updateForm()**. This callback is triggered only when **FormExtensionAbility** is alive. This API is valid only for system applications when **formVisibleNotify** is set to **true**.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| newStatus  | Record\<string, number> | Yes  | ID and visibility status of the widget to be changed.<br>**Note**: The value of the **number** parameter is an integer within the range of [0, 2]. The value **0** indicates an unknown type, the value **1** indicates the visible state, and the value **2** indicates the invisible state. Values beyond the range are invalid and have no effect. This API is valid only for system applications when **formVisibleNotify** is set to **true**.<br>For details, see [formInfo.VisibilityType](js-apis-app-form-formInfo.md#visibilitytype).|

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
    console.info(`FormExtensionAbility onChangeFormVisibility, newStatus: ${newStatus}`);
    let param: Record<string, string> = {
      'temperature': '22°C',
      'time': '22:00'
    }
    let formBindingDataObj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);

    let keys: string[] = getObjKeys(newStatus);

    for (let i: number = 0; i < keys.length; i++) {
      console.info(`FormExtensionAbility onChangeFormVisibility, key: ${keys[i]}, value= ${newStatus[keys[i]]}`);
      formProvider.updateForm(keys[i], formBindingDataObj).then(() => {
        console.info('FormExtensionAbility context updateForm');
      }).catch ((error: BusinessError) => {
        console.error(`Operation updateForm failed, code: ${error.code}, message: ${error.message}`);
      });
    }
  }
}
```

### FormExtensionAbility.onFormEvent

onFormEvent(formId: string, message: string): void

API for the widget provider to receive and handle widget event notifications, such as custom events triggered by the widget host.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | Yes  | ID of the widget that requests the event.|
| message | string | Yes  | Event message, which is used to transfer detailed information about a widget event. The message content is defined by you and is usually a JSON string or a specific identifier, which is used to identify the event type or transfer event data.            |

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    console.info(`FormExtensionAbility onFormEvent, formId: ${formId}, message: ${message}`);
  }
}
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
    console.info(`FormExtensionAbility onRemoveForm, formId: ${formId}`);
  }
}
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
    console.info(`onConfigurationUpdate, config: ${newConfig?.language}`);
  }
}
```

### FormExtensionAbility.onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState

API for the widget provider to receive widget state query notifications. When the widget host (such as the home screen) needs to obtain the current state of a widget (for example, whether the widget is available, and whether it needs to be updated), this method is called. This method can be overridden. By default, the initial widget state is returned. (This method can be selectively overridden.)

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Description of the widget state, including the bundle name, ability name, module name, and widget name.|

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formInfo.FormState](js-apis-app-form-formInfo.md#formstate) | Enumerated values of the current widget status.|

**Example**

```ts
import { FormExtensionAbility, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormState(want: Want) {
    console.info(`FormExtensionAbility onAcquireFormState, want: ${want}`);
    return formInfo.FormState.UNKNOWN;
  }
}
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
    console.info(`FormExtensionAbility onStop`);
  }
}
```

### FormExtensionAbility.onFormLocationChanged<sup>20+</sup>

onFormLocationChanged(formId: string, newFormLocation: formInfo.FormLocation): void

Called when the widget location changes. You can adjust the widget display or preload related content based on the new location information.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| formId | string | Yes| Widget ID.|
| newFormLocation | [formInfo.FormLocation](js-apis-app-form-formInfo.md#formlocation20) | Yes| Enumeration value indicating the current location of the widget (such as home screen and widget center).|

**Example**

```ts
import { formBindingData, FormExtensionAbility, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class EntryFormAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    let formData: Record<string, string | Object> = {
      'data': 'addForm'
    };
    return formBindingData.createFormBindingData(formData);
  }
  onFormLocationChanged(formId: string, newFormLocation: formInfo.FormLocation) {
    console.info('EntryFormAbility onFormLocationChanged current location: ' + newFormLocation);
  }
}
```

### FormExtensionAbility.onSizeChanged<sup>20+</sup>

onSizeChanged(formId: string, newDimension: formInfo.FormDimension, newRect: formInfo.Rect): void

Callback triggered when the widget size changes (for example, when the user adjusts the widget size).

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 20.
  
**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget whose size changes.|
| newDimension | [formInfo.FormDimension](js-apis-app-form-formInfo.md#formdimension) | Yes| Widget dimension. For example, **Dimension_1_2** indicates a 1 x 2 widget.|
| newRect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | Yes| Widget position information, including the X and Y coordinates of the widget's top-left corner, as well as its width and height.|

**Example**

```ts
import { FormExtensionAbility, formInfo } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onSizeChanged(formId: string, newDimension: formInfo.FormDimension, newRect: formInfo.Rect) {
    console.info(`FormExtensionAbility onSizeChanged, formId: ${formId}, newDimension: ${newDimension}`);
  }
}
```
