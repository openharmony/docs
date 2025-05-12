# @ohos.application.formProvider (formProvider)

The **FormProvider** module provides APIs related to the widget provider. You can use the APIs to update a widget, set the next refresh time for a widget, obtain widget information, and request a widget release.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [formProvider](js-apis-app-form-formProvider.md) instead.

## Modules to Import

```ts
import formProvider from '@ohos.application.formProvider';
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes  | Time for the next refresh. The value must be greater than or equal to 5, in minutes.    |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  import Base from '@ohos.base';
  import formProvider from '@ohos.application.formProvider';

  let formId: string = '12400633174999288';
  formProvider.setFormNextRefreshTime(formId, 5, (error: Base.BusinessError) => {
    if (error.code) {
      console.error(`formProvider setFormNextRefreshTime, error: ${JSON.stringify(error)}`);
    }
  });
  ```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

Sets the next refresh time for a widget. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes  | Time for the next refresh. The value must be greater than or equal to 5, in minutes.    |

**Return value**

  | Type         | Description                             |
  | ------------- | ---------------------------------- |
  | Promise\<void> | Promise that returns no value.     |

**Example**

  ```ts
  import Base from '@ohos.base';
  import formProvider from '@ohos.application.formProvider';

  let formId: string = '12400633174999288';
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
    console.log('formProvider setFormNextRefreshTime success');
  }).catch((error: Base.BusinessError) => {
    console.error(`formProvider setFormNextRefreshTime, error: ${JSON.stringify(error)}`);
  });
  ```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData,callback: AsyncCallback&lt;void&gt;): void

Updates a widget. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type                                                                   | Mandatory| Description            |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | Yes  | ID of the widget to update.|
  | formBindingData | [formBindingData.FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update.   |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  import Base from '@ohos.base';
  import formBindingData from '@ohos.application.formBindingData';
  import formProvider from '@ohos.application.formProvider';

  let formId: string = '12400633174999288';
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj, (error: Base.BusinessError) => {
    if (error.code) {
      console.error(`formProvider updateForm, error: ${JSON.stringify(error)}`);
    }
  });
  ```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

Updates a widget. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type                                                                   | Mandatory| Description            |
  | ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
  | formId | string                                                                 | Yes  | ID of the widget to update.|
  | formBindingData | [formBindingData.FormBindingData](js-apis-application-formBindingData.md#formbindingdata)  | Yes  | Data to be used for the update.   |

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

  ```ts
  import Base from '@ohos.base';
  import formBindingData from '@ohos.application.formBindingData';
  import formProvider from '@ohos.application.formProvider';

  let formId: string = '12400633174999288';
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj).then(() => {
    console.log('formProvider updateForm success');
  }).catch((error: Base.BusinessError) => {
    console.error(`formProvider updateForm, error: ${JSON.stringify(error)}`);
  });
  ```
