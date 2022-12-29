# @ohos.app.form.FormExtensionAbility

The **FormExtensionAbility** module provides APIs related to Form Extension abilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.Form

| Name   | Type                                               | Readable| Writable| Description                                               |
| ------- | ------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | Yes  | No  | Context of the **FormExtensionAbility**. This context is inherited from **ExtensionContext**.|

## onAddForm

onAddForm(want: Want): formBindingData.FormBindingData

Called to notify the widget provider that a **Form** instance (widget) has been created.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                  | Mandatory| Description                                                        |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](js-apis-application-want.md) | Yes  | Information related to the Extension ability, including the widget ID, name, and style. The information must be managed as persistent data to facilitate subsequent widget update and deletion.|

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | A **formBindingData.FormBindingData** object containing the data to be displayed on the widget.|

**Example**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want) {
    console.log('FormExtensionAbility onAddForm, want:' + want.abilityName);
    let dataObj1 = {
      temperature:"11c",
      "time":"11:00"
    };
    let obj1 = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

## onCastToNormalForm

onCastToNormalForm(formId: string): void

Called to notify the widget provider that a temporary widget has been converted to a normal one.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| formId | string | Yes  | ID of the widget that requests to be converted to a normal one.|

**Example**

```ts
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onCastToNormalForm(formId) {
    console.log('FormExtensionAbility onCastToNormalForm, formId:' + formId);
  }
}
```

## onUpdateForm

onUpdateForm(formId: string): void

Called to notify the widget provider that a widget has been updated. After obtaining the latest data, the caller invokes **updateForm** of the [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) class to update the widget data.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget that requests to be updated.|

**Example**

```ts
import formBindingData from '@ohos.app.form.formBindingData'
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onUpdateForm(formId) {
    console.log('FormExtensionAbility onUpdateForm, formId:' + formId);
    let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
    this.context.updateForm(formId, obj2).then((data)=>{
      console.log('FormExtensionAbility context updateForm, data:' + data);
    }).catch((error) => {
      console.error('Operation updateForm failed. Cause: ' + error);});
    }
}
```

## onChangeFormVisibility

onChangeFormVisibility(newStatus: { [key: string]: number }): void

Called to notify the widget provider of the change of visibility.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name   | Type                     | Mandatory| Description                        |
| --------- | ------------------------- | ---- | ---------------------------- |
| newStatus | { [key: string]: number } | Yes  | ID and visibility status of the widget to be changed.|

**Example**

```ts
import formBindingData from '@ohos.app.form.formBindingData'
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onChangeFormVisibility(newStatus) {
  console.log('FormExtensionAbility onChangeFormVisibility, newStatus:' + newStatus);
  let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});

  for (let key in newStatus) {
    console.log('FormExtensionAbility onChangeFormVisibility, key:' + key + ", value=" + newStatus[key]);
    this.context.updateForm(key, obj2).then((data)=>{
        console.log('FormExtensionAbility context updateForm, data:' + data);
    }).catch((error) => {
        console.error('Operation updateForm failed. Cause: ' + error);});
    }
  }
}
```

## onFormEvent

onFormEvent(formId: string, message: string): void

Called to instruct the widget provider to receive and process the widget event.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | Yes  | ID of the widget that requests the event.|
| message | string | Yes  | Event message.            |

**Example**

```ts
export default class MyFormExtension extends FormExtensionAbility {
  onFormEvent(formId, message) {
    console.log('FormExtensionAbility onFormEvent, formId:' + formId + ", message:" + message);
  }
}
```

## onRemoveForm

onRemoveForm(formId: string): void

Called to notify the widget provider that a **Form** instance (widget) has been destroyed.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget to be destroyed.|

**Example**

```ts
export default class MyFormExtensionAbility extends FormExtensionAbility {
  onRemoveForm(formId) {
    console.log('FormExtensionAbility onRemoveForm, formId:' + formId);
  }
}
```

## onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-configuration.md) | Yes| New configuration.|

**Example**

```ts
class MyFormExtensionAbility extends FormExtensionAbility {
  onConfigurationUpdate(config) {
    console.log('onConfigurationUpdate, config:' + JSON.stringify(config));
  }
}
```

## onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState;

Called when the widget provider receives the status query result of a widget. By default, the initial state is returned.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Description of the widget state, including the bundle name, ability name, module name, widget name, and widget dimension.|

**Example**

```ts
import formInfo from '@ohos.app.form.formInfo';
class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormState(want) {
    console.log('FormExtensionAbility onAcquireFormState, want:' + want);
    return formInfo.FormState.UNKNOWN;
  }
}
```

## onShareForm

onShareForm?(formId: string): { [key: string]: any }

Called by the widget provider to receive shared widget data.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| {[key: string]: any} | Data to be shared by the widget, in the form of key-value pairs.|

**Example**

```ts
class MyFormExtensionAbility extends FormExtensionAbility {
  onShareForm(formId) {
    console.log('FormExtensionAbility onShareForm, formId:' + formId);
    let wantParams = {
      "temperature":"20",
      "time":"2022-8-8 09:59",
    };
    return wantParams;
  }
}
```
