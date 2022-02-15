# FormExtension

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides **FormExtension** APIs.

## Modules to Import

```
import FormExtension from '@ohos.application.FormExtension';
```

## Required Permissions

None

## Attributes

| Name| Type| Readable| Writable| Description|
| ------- | ------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context | [FormExtensionContext](js-apis-formextensioncontext.md) | Yes| No| Context of the **FormExtension**. This class is inherited from **ExtensionContext**.|

## onCreate

onCreate(want: Want): formBindingData.FormBindingData

Called to notify the widget provider that a **Form** instance (widget) has been created.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
  | want   | [Want](js-apis-featureAbility.md#want) | Yes| Information related to the extension, including the widget ID, name, and style. The information must be managed as persistent data to facilitate subsequent widget update and deletion.|

- Return value

  | Type| Description|
  | ------------------------------------------------------------ | ----------------------------------------------------------- |
  | [formBindingData.FormBindingData](js-apis-formbindingdata.md#formbindingdata) | A **formBindingData.FormBindingData** object containing the data to be displayed on the widget.|

- Example

  ```
  onCreate(want) {
      console.log('FormExtension onCreate, want:' + want.abilityName);
      let dataObj1 = {
          temperature:"11c",
          "time":"11:00"
      };
      let obj1 = formBindingData.createFormBindingData(dataObj1);
      return obj1;
  }
  ```

## onCastToNormal

onCastToNormal(formId: string): void

Called to notify the widget provider that a temporary widget has been converted to a normal one.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------------------------ |
  | formId | string | Yes| ID of the widget that requests to be converted to a normal one.|

- Example

  ```
  onCastToNormal(formId) {
      console.log('FormExtension onCastToNormal, formId:' + formId);
  }
  ```

## onUpdate

onUpdate(formId: string): void

Called to notify the widget provider that a widget has been updated. After obtaining the latest data, the caller invokes **updateForm** of the [FormExtensionContext](js-apis-formextensioncontext.md) class to update the widget data.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------------------ |
  | formId | string | Yes| ID of the widget that requests to be updated.|

- Example

  ```
  onUpdate(formId) {
      console.log('FormExtension onUpdate, formId:' + formId);
      let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
      this.context.updateForm(formId, obj2)
          .then((data)=>{
              console.log('FormExtension context updateForm, data:' + data);
          }).catch((error) => {
          console.error('Operation updateForm failed. Cause: ' + error);});
  }
  ```

## onVisibilityChange

onVisibilityChange(newStatus: { [key: string]: number }): void

Called to notify the widget provider of the change of visibility.

- Parameters

  | Name| Type| Mandatory| Description|
  | --------- | ------------------------- | ---- | ---------------------------- |
  | newStatus | { [key: string]: number } | Yes| ID and visibility status of the widget to be changed.|

- Example

  ```
  onVisibilityChange(newStatus) {
      console.log('FormExtension onVisibilityChange, newStatus:' + newStatus);
      let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});

      for (let key in newStatus) {
          console.log('FormExtension onVisibilityChange, key:' + key + ", value=" + newStatus[key]);
          this.context.updateForm(key, obj2)
              .then((data)=>{
                  console.log('FormExtension context updateForm, data:' + data);
              }).catch((error) => {
              console.error('Operation updateForm failed. Cause: ' + error);});
      }
  }
  ```

## onEvent

onEvent(formId: string, message: string): void

Called to instruct the widget provider to receive and process the widget event.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------- | ------ | ---- | ---------------------- |
  | formId  | string | Yes| ID of the widget that requests the event.|
  | message | string | Yes| Event message.|

- Example

  ```
  onEvent(formId, message) {
      console.log('FormExtension onEvent, formId:' + formId + ", message:" + message);
  }
  ```

## onDestroy

onDestroy(formId: string): void

Called to notify the widget provider that a **Form** instance (widget) has been destroyed.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------------------ |
  | formId | string | Yes| ID of the widget to be destroyed.|

- Example

  ```
  onDestroy(formId) {
      console.log('FormExtension onDestroy, formId:' + formId);
  }
  ```
