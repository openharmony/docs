# @ohos.application.FormExtension

The **FormExtension** module provides APIs related to Form Extension abilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md) instead.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import FormExtension from '@ohos.application.FormExtension';
```

## Attributes

**System capability**: SystemCapability.Ability.Form

| Name   | Type                                               | Readable| Writable| Description                                               |
| ------- | ------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | Yes  | No  | Context of the **FormExtension**. This context is inherited from **ExtensionContext**.|

## onCreate

onCreate(want: Want): formBindingData.FormBindingData

Called to notify the widget provider that a **Form** instance (widget) has been created.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                  | Mandatory| Description                                                        |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](js-apis-application-want.md) | Yes  | Information related to the extension, including the widget ID, name, and style. The information must be managed as persistent data to facilitate subsequent widget update and deletion.|

**Return value**

| Type                                                        | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | A **formBindingData.FormBindingData** object containing the data to be displayed on the widget.|

**Example**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onCreate(want) {
    console.log('FormExtension onCreate, want:' + want.abilityName);
    let dataObj1 = {
      temperature:"11c",
      "time":"11:00"
    };
    let obj1 = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

## FormExtension.onCastToNormal

onCastToNormal(formId: string): void

Called to notify the widget provider that a temporary widget has been converted to a normal one.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| formId | string | Yes  | ID of the widget that requests to be converted to a normal one.|

**Example**

```ts
export default class MyFormExtension extends FormExtension {
  onCastToNormal(formId) {
    console.log('FormExtension onCastToNormal, formId:' + formId);
  }
}
```

## FormExtension.onUpdate

onUpdate(formId: string): void

Called to notify the widget provider that a widget has been updated. After obtaining the latest data, the caller invokes **updateForm** of the [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) class to update the widget data.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget that requests to be updated.|

**Example**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onUpdate(formId) {
    console.log('FormExtension onUpdate, formId:' + formId);
    let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
    this.context.updateForm(formId, obj2).then((data)=>{
      console.log('FormExtension context updateForm, data:' + data);
    }).catch((error) => {
      console.error('Operation updateForm failed. Cause: ' + error);});
    }
}
```

## FormExtension.onVisibilityChange

onVisibilityChange(newStatus: { [key: string]: number }): void

Called to notify the widget provider of the change of visibility.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name   | Type                     | Mandatory| Description                        |
| --------- | ------------------------- | ---- | ---------------------------- |
| newStatus | { [key: string]: number } | Yes  | ID and visibility status of the widget to be changed.|

**Example**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onVisibilityChange(newStatus) {
  console.log('FormExtension onVisibilityChange, newStatus:' + newStatus);
  let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});

  for (let key in newStatus) {
    console.log('FormExtension onVisibilityChange, key:' + key + ", value=" + newStatus[key]);
    this.context.updateForm(key, obj2).then((data)=>{
        console.log('FormExtension context updateForm, data:' + data);
    }).catch((error) => {
        console.error('Operation updateForm failed. Cause: ' + error);});
    }
  }
}
```

## FormExtension.onEvent

onEvent(formId: string, message: string): void

Called to instruct the widget provider to receive and process the widget event.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type  | Mandatory| Description                  |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | Yes  | ID of the widget that requests the event.|
| message | string | Yes  | Event message.            |

**Example**

```ts
export default class MyFormExtension extends FormExtension {
  onEvent(formId, message) {
    console.log('FormExtension onEvent, formId:' + formId + ", message:" + message);
  }
}
```

## FormExtension.onDestroy

onDestroy(formId: string): void

Called to notify the widget provider that a **Form** instance (widget) has been destroyed.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| formId | string | Yes  | ID of the widget to be destroyed.|

**Example**

```ts
export default class MyFormExtension extends FormExtension {
  onDestroy(formId) {
    console.log('FormExtension onDestroy, formId:' + formId);
  }
}
```

## FormExtension.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| config | [Configuration](js-apis-application-configuration.md) | Yes| New configuration.|

**Example**

```ts
class MyFormExtension extends FormExtension {
  onConfigurationUpdated(config) {
    console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
  }
}
```

## FormExtension.onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState;

Called when the widget provider receives the status query result of a widget. By default, the initial state is returned.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | Yes| Description of the widget state, including the bundle name, ability name, module name, widget name, and widget dimension.|

**Example**

```ts
import formInfo from '@ohos.application.formInfo'
class MyFormExtension extends FormExtension {
  onAcquireFormState(want) {
    console.log('FormExtension onAcquireFormState, want:' + want);
    return formInfo.FormState.UNKNOWN;
  }
}
```

## FormExtension.onShare

onShare?(formId: string): {[key: string]: any};

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
class MyFormExtension extends FormExtension {
  onShare(formId) {
    console.log('FormExtension onShare, formId:' + formId);
    let wantParams = {
      "temperature":"20",
      "time":"2022-8-8 09:59",
    };
    return wantParams;
  }
}
```
