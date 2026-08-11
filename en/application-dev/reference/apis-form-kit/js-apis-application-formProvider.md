# @ohos.application.formProvider (formProvider)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=6b0733adc9a538f18ea8143587feeecb737929d9 translatedAt=2026-07-31T08:25:35.406Z pushedAt=2026-07-31T09:22:09.636Z -->

The FormProvider module provides APIs for widget providers. When developing widgets, you can use the APIs provided by this module to update widgets, set widget update time, obtain widget information, and request widget publishing.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is deprecated since API version 9. You are advised to use [formProvider](js-apis-app-form-formProvider.md) instead.

## Modules to Import

```ts
import { formProvider } from '@kit.FormKit';
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

Sets the next update time for a specified widget. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes | Interval before the next update, in minutes. The value must be greater than or equal to 5. |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formProvider } from '@kit.FormKit';
  // Use an existing widget ID (formId).
  let formId: string = '12400633174999288';
  formProvider.setFormNextRefreshTime(formId, 5, (error: BusinessError) => {
    if (error.code) {
      console.error(`formProvider setFormNextRefreshTime, errorCode: ${error.code}, errorMessage: ${error.message}`);
    }
  });
  ```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

Sets the next update time for a specified widget. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | formId | string | Yes  | Widget ID.                              |
  | minute | number | Yes   | Interval before the next update, in minutes. The value must be greater than or equal to 5.     |

**Return value**

  | Type         | Description                             |
  | ------------- | ---------------------------------- |
  | Promise\<void> | Promise that returns no value.     |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formProvider } from '@kit.FormKit';
  // Use an existing widget ID (formId).
  let formId: string = '12400633174999288';
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
    console.info('formProvider setFormNextRefreshTime success');
  }).catch((error: BusinessError) => {
    console.error(`formProvider setFormNextRefreshTime, errorCode: ${error.code}, errorMessage: ${error.message}`);
  });
  ```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback&lt;void&gt;): void

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
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formProvider, formBindingData } from '@kit.FormKit';

  // Use an existing widget ID (formId).
  let formId: string = '12400633174999288';
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj, (error: BusinessError) => {
    if (error.code) {
      console.error(`formProvider updateForm, errorCode: ${error.code}, errorMessage: ${error.message}`);
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
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formProvider, formBindingData } from '@kit.FormKit';

  // Use an existing widget ID (formId).
  let formId: string = '12400633174999288';
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj).then(() => {
    console.info('formProvider updateForm success');
  }).catch((error: BusinessError) => {
    console.error(`formProvider updateForm, errorCode: ${error.code}, errorMessage: ${error.message}`);
  });
  ```