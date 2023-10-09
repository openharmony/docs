# @ohos.app.form.formAgent (FormAgent)

The **FormAgent** module provides APIs related to the widget agent. Currently, you can use the APIs to request to publish widgets only.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import formAgent from '@ohos.app.form.formAgent';
```

## requestPublishForm

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

Requests to publish a widget to the widget host. This API uses an asynchronous callback to return the result. The widget host is usually the home screen.

**Required permission**: ohos.permission.AGENT_REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-app-ability-want.md) | Yes  | Request used for publishing. The following fields must be included:<br>**bundleName**: bundle name of the target widget.<br>**abilityName**: ability of the target widget.<br>parameters:<br>- **ohos.extra.param.key.form_dimension**: dimension of the target widget.<br>- **ohos.extra.param.key.form_name**: name of the target widget.<br>- **ohos.extra.param.key.module_name**: module name of the target widget.|
| callback | AsyncCallback&lt;string&gt;         | Yes  |  Callback used to return the widget ID.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
  formAgent.requestPublishForm(want, (error: Base.BusinessError, data: string) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formAgent requestPublishForm, form ID is: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);
}
```

## requestPublishForm

requestPublishForm(want: Want): Promise&lt;string&gt;

Requests to publish a widget to the widget host. This API uses a promise to return the result. The widget host is usually the home screen.

**Required permission**: ohos.permission.AGENT_REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name         | Type                                                        | Mandatory| Description                                                        |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-app-ability-want.md) | Yes  | Request used for publishing. The following fields must be included:<br>**bundleName**: bundle name of the target widget.<br>**abilityName**: ability of the target widget.<br>parameters:<br>- **ohos.extra.param.key.form_dimension**: dimension of the target widget.<br>- **ohos.extra.param.key.form_name**: name of the target widget.<br>- **ohos.extra.param.key.module_name**: module name of the target widget.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the widget ID.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import Base from '@ohos.base';

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
    console.log(`formAgent requestPublishForm success, form ID is : ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);
}
```
