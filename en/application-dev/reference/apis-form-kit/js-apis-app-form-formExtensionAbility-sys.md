# @ohos.app.form.FormExtensionAbility (FormExtensionAbility) (System API)

The **FormExtensionAbility** module provides lifecycle callbacks invoked when a widget is created, destroyed, or updated.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.form.FormExtensionAbility (FormExtensionAbility)](./js-apis-app-form-formExtensionAbility.md).

## Modules to Import

```ts
import { FormExtensionAbility } from '@kit.FormKit';
```

## onShareForm

onShareForm?(formId: string): Record\<string, Object>

Called to notify the widget provider that the widget host is sharing the widget data.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| formId | string | Yes| Widget ID.|

**Return value**

| Type                  | Description                                        |
| ---------------------- | -------------------------------------------- |
| Record\<string, Object> | Data to be shared by the widget, in the form of key-value pairs.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onShareForm(formId: string) {
    console.log(`FormExtensionAbility onShareForm, formId: ${formId}`);
    let wantParams: Record<string, Object> = {
      'temperature': '20',
      'time': '2022-8-8 09:59',
    };
    return wantParams;
  }
};
```

## onAcquireFormData<sup>10+<sup>

onAcquireFormData?(formId: string): Record\<string, Object>

Called to notify the widget provider that the widget host is requesting the custom data.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| formId | string | Yes| Widget ID.|

**Return value**

| Type                  | Description                                        |
| ---------------------- | -------------------------------------------- |
| Record\<string, Object> | Custom data of the widget, in the form of key-value pairs.|

**Example**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormData(formId: string) {
    console.log(`FormExtensionAbility onAcquireFormData, formId: ${formId}`);
    let wantParams: Record<string, Object> = {
      'temperature': '20',
      'time': '2022-8-8 09:59',
    };
    return wantParams;
  }
};
```
