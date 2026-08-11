# @ohos.app.form.formAgent (FormAgent) (System API)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=c85b75d8023cf23712791d9bbf1c3edc12e94276 translatedAt=2026-07-31T08:19:27.592Z pushedAt=2026-07-31T09:38:15.610Z -->

The FormAgent module provides APIs for widget agent-related capabilities, currently including only requesting to publish a widget. It is applicable to scenarios where a system app needs to publish a widget to the widget host (such as the home screen), helping system apps conveniently request form publishing and simplifying the widget publishing process.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { formAgent } from '@kit.FormKit';
```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

Requests to publish a widget to the widget host. This API uses an asynchronous callback to return the result. The widget host is usually the home screen. This is applicable to scenarios where a system app needs to proactively add a widget to the home screen.

**Required permission**: ohos.permission.AGENT_REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Publish request, which must contain the following fields.<br>**bundleName**: **bundleName** of the target widget's owner app.<br>**abilityName**: ability of the target widget's owner app.<br>**parameters**:<br>- **ohos.extra.param.key.form_dimension**: target widget dimension. Values: **1** for 2x2, **2** for 2x4, **3** for 4x4, and so on. For details, see the widget configuration.<br>- **ohos.extra.param.key.form_name**: target widget name.<br>- **ohos.extra.param.key.module_name**: **moduleName** of the target widget.|
| callback | AsyncCallback&lt;string&gt; | Yes | Callback used to return the widget ID asynchronously. The callback parameters are as follows: **error** indicates the error object, which is null if the operation is successful; **data** indicates the widget ID, which is a string. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501008 | Waiting for the form addition to the desktop timed out. <br/>Applicable version: 12+|

**Example**

```ts
import { formAgent } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.ohos.exampledemo',
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formAgent.requestPublishForm(want, (error: BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.info(`formAgent requestPublishForm, form ID is: ${data}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## requestPublishForm

requestPublishForm(want: Want): Promise&lt;string&gt;

Requests to publish a widget to the widget host. This API uses a promise to return the result. The widget host is usually the home screen. This is applicable to scenarios where a system app needs to proactively add a widget to the home screen.

**Required permission**: ohos.permission.AGENT_REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name         | Type                                                        | Mandatory| Description                                                        |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Publish request, which must contain the following fields:<br>**bundleName**: bundle name of the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>- **ohos.extra.param.key.form_dimension**: dimension of the target widget.<br>- **ohos.extra.param.key.form_name**: name of the target widget.<br>- **ohos.extra.param.key.module_name**: module name of the target widget.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the widget ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501008 | Waiting for the form addition to the desktop timed out.<br/>Applicable version: 12+ |

**Example**

```ts
import { formAgent } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.ohos.exampledemo',
  abilityName: 'FormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  }
};
try {
  formAgent.requestPublishForm(want).then((data: string) => {
    console.info(`formAgent requestPublishForm success, form ID is : ${data}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## updateFormCrossBundle

updateFormCrossBundle(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

Updates a widget across apps. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permission:** ohos.permission.UPDATE_FORM_CROSS_BUNDLE

**System capability:** SystemCapability.Ability.Form

**System API**: This is a system API.

**Since**: 26.0.0

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ------ | ---- | -------|
| formId | string | Yes | ID of the widget to be updated.|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes | Widget data used for the update.|

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Universal Error Code](../errorcode-universal.md) and [Widget Error Code](errorcode-form.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | Possible cause IPC connection error. Such as the remote object does not exist. |
| 16500060 | Possible cause Service State error. Such as the form is recovering. |
| 16501000 | Possible cause internal functional error. Such as virtualization failed. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form to be operated has been deleted already. |
| 16501007 | The form to be operated is not trusted. |

**Example**

```ts
import { formBindingData, formAgent } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '123456789'; // Widget ID of the form. Replace it with the actual widget ID.
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  };
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formAgent.updateFormCrossBundle(formId, obj).then(() => {
    console.info('formAgent updateFormCrossBundle success');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error?.code}, message: ${error?.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error?.code}, message: ${error?.message}`);
}
```