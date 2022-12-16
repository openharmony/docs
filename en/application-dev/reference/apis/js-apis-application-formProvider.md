# @ohos.application.formProvider

The **FormProvider** module provides APIs related to the widget provider. You can use the APIs to update a widget, set the next refresh time for a widget, obtain widget information, and request a widget release.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [FormProvider](js-apis-app-form-formProvider.md) instead.

## Modules to Import

```ts
import formProvider from '@ohos.application.formProvider';
```

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes  | Refresh interval, in minutes. The value must be greater than or equal to 5.    |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  var formId = "12400633174999288";
  formProvider.setFormNextRefreshTime(formId, 5, (error, data) => {
      if (error.code) {
          console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
      }
  });
  ```

## setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

Sets the next refresh time for a widget. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes  | Refresh interval, in minutes. The value must be greater than or equal to 5.    |

**Return value**

  | Type         | Description                             |
  | ------------- | ---------------------------------- |
  | Promise\<void> | Promise that returns no value.     |

**Example**

  ```ts
  var formId = "12400633174999288";
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
      console.log('formProvider setFormNextRefreshTime success');
  }).catch((error) => {
      console.log('formProvider setFormNextRefreshTime, error:' + JSON.stringify(error));
  });
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData,callback: AsyncCallback&lt;void&gt;): void

Updates a widget. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type                                                                   | Mandatory| Description            |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | Yes  | ID of the widget to update.|
  | formBindingData.FormBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update.   |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.updateForm(formId, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider updateForm, error:' + JSON.stringify(error));
      }
  });
  ```

## updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

Updates a widget. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type                                                                   | Mandatory| Description            |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | Yes  | ID of the widget to update.|
  | formBindingData.FormBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdat) | Yes  | Data to be used for the update.   |

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var formId = "12400633174999288";
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.updateForm(formId, obj).then(() => {
      console.log('formProvider updateForm success');
  }).catch((error) => {
      console.log('formProvider updateForm, error:' + JSON.stringify(error));
  });
  ```

## getFormsInfo<sup>9+</sup>

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the application's widget information on the device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | Yes| Callback used to return the information obtained.|

**Example**

```ts
formProvider.getFormsInfo((error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
});
```
## getFormsInfo<sup>9+</sup>

getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the application's widget information that meets a filter criterion on the device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-application-formInfo.md#forminfofilter) | Yes| Filter criterion.|
| callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | Yes| Callback used to return the information obtained.|

**Example**

```ts
import formInfo from '@ohos.application.formInfo';
const filter : formInfo.FormInfoFilter = {
    // get info of forms belong to module entry.
    moduleName : "entry"
};
formProvider.getFormsInfo(filter, (error, data) => {
    if (error.code) {
        console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
    }
});
```

## getFormsInfo<sup>9+</sup>

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the application's widget information on the device. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](./js-apis-application-formInfo.md) | No| Filter criterion.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](./js-apis-application-formInfo.md#forminfo-1)&gt;&gt; | Promise used to return the information obtained.|

**Example**

```ts
import formInfo from '@ohos.application.formInfo';
const filter : formInfo.FormInfoFilter = {
    // get info of forms belong to module entry.
    moduleName : "entry"
};
formProvider.getFormsInfo(filter).then((data) => {
    console.log('formProvider getFormsInfo, data:' + JSON.stringify(data));
}).catch((error) => {
    console.log('formProvider getFormsInfo, error:' + JSON.stringify(error));
});
```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<string>): void

Requests to publish a widget carrying data to the widget host. This API uses an asynchronous callback to return the result. This API is usually called by the home screen.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| want | [Want](js-apis-application-want.md)                           | Yes  | Request used for publishing. The following fields must be included:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| formBindingData.FormBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | Yes  | Data used for creating the widget.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Example**

  ```ts
  import formBindingData from '@ohos.application.formBindingData';
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  let obj = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
  formProvider.requestPublishForm(want, obj, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
  });
  ```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, callback: AsyncCallback&lt;string&gt;): void

Requests to publish a widget to the widget host. This API uses an asynchronous callback to return the result. This API is usually called by the home screen.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| want     | [Want](js-apis-application-want.md) | Yes  | Request used for publishing. The following fields must be included:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| callback | AsyncCallback&lt;string&gt;         | Yes  |  Callback used to return the widget ID.|

**Example**

  ```ts
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  formProvider.requestPublishForm(want, (error, data) => {
      if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
      } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
      }
  });
  ```

## requestPublishForm<sup>9+</sup>

requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise&lt;string&gt;

Requests to publish a widget to the widget host. This API uses a promise to return the result. This API is usually called by the home screen.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name         | Type                                                        | Mandatory| Description                                                        |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want            | [Want](js-apis-application-want.md)                          | Yes  | Request used for publishing. The following fields must be included:<br>Information about the target widget.<br>**abilityName**: ability of the target widget.<br>**parameters**:<br>"ohos.extra.param.key.form_dimension"<br>"ohos.extra.param.key.form_name"<br>"ohos.extra.param.key.module_name" |
| formBindingData.FormBindingData | [FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | No  | Data used for creating the widget.                                          |

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the widget ID.|

**Example**

  ```ts
  var want = {
      abilityName: "FormAbility",
      parameters: {
          "ohos.extra.param.key.form_dimension": 2,
          "ohos.extra.param.key.form_name": "widget",
          "ohos.extra.param.key.module_name": "entry"
      }
  };
  formProvider.requestPublishForm(want).then((data) => {
      console.log('formProvider requestPublishForm success, form ID is :' + JSON.stringify(data));
  }).catch((error) => {
      console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
  });
  ```

## isRequestPublishFormSupported<sup>9+<sup>

isRequestPublishFormSupported(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a widget can be published to the widget host. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether the widget can be published to the widget host.|

**Example**

```ts
formProvider.isRequestPublishFormSupported((error, isSupported) => {
  if (error.code) {
    console.log('formProvider isRequestPublishFormSupported, error:' + JSON.stringify(error));
  } else {
    if (isSupported) {
      var want = {
      abilityName: "FormAbility",
      parameters: {
        "ohos.extra.param.key.form_dimension": 2,
        "ohos.extra.param.key.form_name": "widget",
        "ohos.extra.param.key.module_name": "entry"
      }
      };
      formProvider.requestPublishForm(want, (error, data) => {
        if (error.code) {
          console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
        } else {
          console.log('formProvider requestPublishForm, form ID is: ' + JSON.stringify(data));
        }
      });
    }
  }
});
```

## isRequestPublishFormSupported<sup>9+</sup>

isRequestPublishFormSupported(): Promise&lt;boolean&gt;

Checks whether a widget can be published to the widget host. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return whether the widget can be published to the widget host.|

**Example**

```ts
formProvider.isRequestPublishFormSupported().then((isSupported) => {
  if (isSupported) {
    var want = {
    abilityName: "FormAbility",
    parameters: {
        "ohos.extra.param.key.form_dimension": 2,
        "ohos.extra.param.key.form_name": "widget",
        "ohos.extra.param.key.module_name": "entry"
    }
    };
    formProvider.requestPublishForm(want).then((data) => {
      console.log('formProvider requestPublishForm success, form ID is :' + JSON.stringify(data));
    }).catch((error) => {
      console.log('formProvider requestPublishForm, error: ' + JSON.stringify(error));
    });
  }
}).catch((error) => {
  console.log('formProvider isRequestPublishFormSupported, error:' + JSON.stringify(error));
});
```
