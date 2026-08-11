# @ohos.app.form.formProvider (formProvider)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

This module provides capabilities such as retrieving widget information, updating widgets, and setting widget refresh intervals. This module acts as a bridge between the widget provider and the widget management service, communicating with **FormExtension** through the IPC mechanism to perform operations like widget updates and information retrieval. It is suitable for scenarios where the widget provider needs to proactively update widget content, manage the widget lifecycle, and obtain widget running status, helping you implement dynamic widget updates and state management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { formProvider } from '@kit.FormKit';
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result. This API is applicable to scenarios where precise control over widget refresh timing is required, such as in scheduled tasks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | Yes  | Widget ID.                              |
| minute | number | Yes  | Interval after which the widget is refreshed, in minutes. The value range is greater than or equal to 5. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **error** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.
try {
  formProvider.setFormNextRefreshTime(formId, 5, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider setFormNextRefreshTime success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

Sets the next refresh time for a widget. This API uses a promise to return the result. This API is applicable to scenarios where precise control over widget refresh timing is required, such as in scheduled tasks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | Yes  | Widget ID.                              |
| minute | number | Yes  | Interval after which the widget is refreshed, in minutes. The value range is greater than or equal to 5.|

**Return value**

| Type         | Description                             |
| ------------- | ---------------------------------- |
| Promise\<void> | Promise that returns no value.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.
try {
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
    console.info(`formProvider setFormNextRefreshTime success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback&lt;void&gt;): void

Updates a widget. This API uses an asynchronous callback to return the result. This API is applicable to scenarios where widget content needs to be proactively updated when data changes, such as weather data changes, stock price updates, or task progress updates.
> **NOTE**
>
> Starting from API version 20, when widget refresh data is updated via shared memory, the total size of the refreshed data must not exceed 10 MB, and the number of refreshed images must not exceed 20. For API version 19 and earlier versions, the upper limit for image files is 5, with a per-image memory limit of 2 MB. Any images that exceed these limits will display abnormally.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | Yes  | ID of the widget to update.|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update. For details about the restrictions, see the preceding note.   |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **error** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider updateForm success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

Updates a widget. This API uses a promise to return the result. This API is applicable to scenarios where widget content needs to be proactively updated when data changes, such as weather data changes, stock price updates, or task progress updates.
> **NOTE**
>
> Starting from API version 20, when widget refresh data is updated via shared memory, the total size of the refreshed data must not exceed 10 MB, and the number of refreshed images must not exceed 20. For API version 19 and earlier versions, the upper limit for image files is 5, with a per-image memory limit of 2 MB. Any images that exceed these limits will display abnormally.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | Yes  | ID of the widget to update.|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update. For details about the restrictions, see the preceding note.   |

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formBindingData, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.
let param: Record<string, string> = {
  'temperature': '22c',
  'time': '22:00'
}
let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
try {
  formProvider.updateForm(formId, obj).then(() => {
    console.info(`formProvider updateForm success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormsInfo

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the application's widget information on the device. This API uses an asynchronous callback to return the result. This API is applicable to scenarios such as widget management, debugging, and statistics collection. For example, you can use this API to view the configuration information of all widgets of an application or collect statistics on the number of widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Yes| Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getFormsInfo((error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## formProvider.getFormsInfo

getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the application's widget information that meets a filter criterion on the device. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | Yes| Filter criterion.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const filter: formInfo.FormInfoFilter = {
  // Obtain the widget information of the specified module.
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter, (error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormsInfo

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains information about widgets that meet the criteria of the current application. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | No| Widget information filter, which is used to filter widget information based on specified conditions. Pass this parameter when you need to obtain widgets from a specific module or with a specific name. If you need to obtain all widget information, you can omit this parameter. When omitted, it defaults to empty and information about all widgets is returned.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const filter: formInfo.FormInfoFilter = {
  // Obtain the widget information of the specified module.
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {
    console.info(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.openFormEditAbility<sup>18+</sup>

openFormEditAbility(abilityName: string, formId: string, isMainPage?: boolean): void

Opens the widget editing page. This API is applicable to scenarios where users need to configure widget parameters, such as setting the content to be displayed, selecting data sources, and configuring the update frequency.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                                |
| ------ | ------ |----|----------------------------------------------------|
| abilityName | string | Yes | Ability name on the editing page.                                    |
| formId | string | Yes | Widget ID.                                             |
| isMainPage | boolean | No | Whether the page is the main editing page.<br>- **true**: It is the main editing page, suitable for scenarios where the user is configuring the basic widget information for the first time.<br>- **false**: It is not the main editing page, suitable for scenarios where the user is making detailed adjustments or advanced configurations.<br>Default value: **true** (typically sufficient for the first-time widget editing).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID   | Error Message|
|----------| -------- |
| 801      | Capability not supported.function openFormEditAbility can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |
| 16501007 | Form is not trust. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';

const TAG: string = 'FormEditDemo-Page] -->';

@Entry
@Component
struct Page {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    console.info(`${TAG} aboutToAppear.....`);
  }

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('PageHelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Top },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          console.info(`${TAG} onClick.....`);
          formProvider.openFormEditAbility('ability://EntryFormEditAbility', '1386529921');
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## formProvider.closeFormEditAbility<sup>23+</sup>

closeFormEditAbility(isMainPage?: boolean): void

Closes the widget editing page. This API is applicable to scenarios where widget editing is complete or canceled. For example, a user closes the editing page after completing parameter configuration or cancels the editing operation.

**System capability**: SystemCapability.Ability.Form

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type   | Mandatory| Description                                                |
| ------ | ------ |----|----------------------------------------------------|
| isMainPage | boolean | No | Whether to close the main editing page.<br>- **true**: Closes the main editing page, suitable for scenarios where the main editing page needs to be closed after configuration is completed.<br>- **false**: Closes a non-main editing page, suitable for scenarios with multi-level editing pages where the current non-main editing page needs to be closed.<br>Default value: **true** (typically sufficient when closing the current editing page).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID   | Error Message|
|----------| -------- |
| 801      | Capability not supported due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16501015 | Cannot close the widget editing page opened by other apps. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';

const TAG: string = 'FormEditDemo-Page] -->';

@Entry
@Component
struct Page {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    console.info(`${TAG} aboutToAppear.....`);
  }

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('PageHelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Top },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          console.info(`${TAG} onClick.....`);
          try {
            formProvider.closeFormEditAbility();
            console.info(`${TAG} close FormEditAbility success.`);
          } catch (error) {
            console.error(`${TAG} close FormEditAbility failed, code: ${error.code}, message: ${error.message}`);
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## formProvider.openFormManager<sup>18+</sup>

openFormManager(want: Want): void

Opens the Widget Manager page of the current application. This API is applicable to widget management scenarios, for example, previewing all widgets that can be added to the home screen, and adding widgets to Assistant·TODAY or the home screen.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Device behavior differences**: This API returns error code [16501000](./errorcode-form.md#16501000-internal-function-error) if called on wearables.

**Parameters**

| Name | Type   | Mandatory| Description                                                                                                                                                                                                                                                                                                     |
|------| ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Parameter that must contain the following fields:<br>**bundleName**: bundle name of widget.<br>**abilityName**: ability name of the widget.<br>**parameters**:<br>- **ohos.extra.param.key.form_dimension**: [Widget dimension](js-apis-app-form-formInfo.md#formdimension).<br>- **ohos.extra.param.key.form_name**: Widget name.<br>- **ohos.extra.param.key.module_name**: module name of the widget.|
> **NOTE**
>
> If **parameters** is not set or the specified widget does not exist, the default widget configured in [form_config.json](../../form/arkts-ui-widget-configuration.md#widget-configuration) is displayed by default.

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

const want: Want = {
  bundleName: 'com.example.formbutton',
  abilityName: 'EntryFormAbility',
  parameters: {
    'ohos.extra.param.key.form_dimension': 2,
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.module_name': 'entry'
  },
};
try {
  formProvider.openFormManager(want);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedFormInfoById<sup>(deprecated)</sup>

getPublishedFormInfoById(formId: string): Promise&lt;formInfo.FormInfo&gt;

Obtains the information of a specified widget that has been added to the home screen by the current application on the device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

> **NOTE**
>
> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getPublishedRunningFormInfoById](#formprovidergetpublishedrunningforminfobyid20) instead.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ |----| ------- |
| formId | string | Yes| Widget ID.|

**Return value**

| Type                                                               | Description                               |
|-------------------------------------------------------------------| ---------------------------------- |
| Promise&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const formId: string = '388344236';
try {
  formProvider.getPublishedFormInfoById(formId).then((data: formInfo.FormInfo) => {
    console.info(`formProvider getPublishedFormInfoById, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedFormInfos<sup>(deprecated)</sup>

getPublishedFormInfos(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the information of all widgets that has been added to the home screen by the current application on the device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

> **NOTE**
>
> This API is supported since API version 18 and deprecated since API version 20. You are advised to use [getPublishedRunningFormInfos](#formprovidergetpublishedrunningforminfos20) instead.

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getPublishedFormInfos().then((data: formInfo.FormInfo[]) => {
    console.info(`formProvider getPublishedFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.requestOverflow<sup>20+</sup>

requestOverflow(formId: string, overflowInfo: formInfo.OverflowInfo): Promise&lt;void&gt;

Requests an animation. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result.

**Related methods**
- [cancelOverflow()](#formprovidercanceloverflow20): cancels an interactive widget animation request. It is used to cancel an already initiated animation.

> **NOTE**
>
> 1. This API is unavailable in the power-saving mode and will return the error code 16501000.
> 2. If the device's thermal level reaches HOT and no tap event occurs, the API returns error code 16501000. If the thermal level reaches OVERHEATED, the API returns error code 16501000 in any case. For details about thermal level information, see [ThermalLevel](../../reference/apis-basic-services-kit/js-apis-thermal.md#thermallevel).

**Atomic service API**: This API can be used in atomic services since API version 20.

**Device behavior differences:** This API is supported only on certain phone models. On unsupported devices, this API returns error code [801](../errorcode-universal.md#801-api-not-supported).

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                | Mandatory| Description       |
| ------ |--------------------------------------------------------------------| ---- |-----------|
| formId | string                                                             | Yes| Widget ID.|
| overflowInfo | [formInfo.OverflowInfo](js-apis-app-form-formInfo.md#overflowinfo20) | Yes| Animation request parameter information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 801 |   Capability not supported.function requestOverflow can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.
let overflowInfo: formInfo.OverflowInfo = {
  area: {
    left: -10,
    top: -10,
    width: 180,
    height: 180
  },
  duration: 1000,
  useDefaultAnimation: false,
};

try {
  formProvider.requestOverflow(formId, overflowInfo).then(() => {
    console.info('requestOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.cancelOverflow<sup>20+</sup>

cancelOverflow(formId: string): Promise&lt;void&gt;

Cancels an animation. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result.

> **NOTE**
>
> 1. This API is unavailable in the power-saving mode and will return the error code 16501000.
> 2. If the device's thermal level reaches HOT and no tap event occurs, the API returns error code 16501000. If the thermal level reaches OVERHEATED, the API returns error code 16501000 in any case. For details about thermal level information, see [ThermalLevel](../../reference/apis-basic-services-kit/js-apis-thermal.md#thermallevel).

**Atomic service API**: This API can be used in atomic services since API version 20.

**Device behavior differences:** This API is supported only on certain phone models. On unsupported devices, this API returns error code [801](../errorcode-universal.md#801-api-not-supported).

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- |-------|
| formId | string | Yes| Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 801 | Capability not supported.function cancelOverflow can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |
| 16501011 | The form can not support this operation. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.

try {
  formProvider.cancelOverflow(formId).then(() => {
    console.info('cancelOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getFormRect<sup>20+</sup>

getFormRect(formId: string): Promise&lt;formInfo.Rect&gt;

Obtains the position and dimension of a widget. This API uses a promise to return the result. This API is applicable to scenarios where you need to obtain the position and dimensions of a widget on the screen, for example, for widget animation, position calibration, and layout calculation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type        | Mandatory| Description       |
| ------ |-------------| ---- |-----------|
| formId | string      | Yes| Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[formInfo.Rect](js-apis-app-form-formInfo.md#rect20)&gt; | Promise used to return the widget position relative to the upper-left corner of the screen and the widget dimensions.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 801 |   Capability not supported.function getFormRect can not work correctly due to limited device capabilities. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288'; // formId of the widget. Use the actual form ID.

try {
  formProvider.getFormRect(formId).then((data: formInfo.Rect) => {
    console.info(`getFormRect succeed, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedRunningFormInfoById<sup>20+</sup>

getPublishedRunningFormInfoById(formId: string): Promise&lt;formInfo.RunningFormInfo&gt;

Obtains the information of a specified widget that has been added to the home screen by the current application. This API uses a promise to return the result. This API is applicable to scenarios such as widget management and debugging, such as viewing the position and dimensions of a specified widget.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ |----| ------- |
| formId | string | Yes| Widget ID.|

**Return value**

| Type                                                               | Description                               |
|-------------------------------------------------------------------| ---------------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo20)&gt; | Promise used to return the information about the widgets that meet the requirements, including the widget name and dimension.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |
| 16501001  | The ID of the form to be operated does not exist. |
| 16501003  | The form cannot be operated by the current application. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const formId: string = '388344236';

try {
  formProvider.getPublishedRunningFormInfoById(formId).then((data: formInfo.RunningFormInfo) => {
    console.info(`formProvider getPublishedRunningFormInfoById, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.getPublishedRunningFormInfos<sup>20+</sup>

getPublishedRunningFormInfos(): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains information about all widgets that have been added to the home screen. This API uses a promise to return the result. This API is applicable to scenarios such as widget management, batch operations, and statistics collection, such as viewing information about all widgets that have been added to the home screen by an application, and updating the widget status in batches.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#runningforminfo20)&gt;&gt; | Promise used to return the information about widgets that meet the requirements.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getPublishedRunningFormInfos().then((data: formInfo.RunningFormInfo[]) => {
    console.info(`formProvider getPublishedRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.reloadForms<sup>22+</sup>

reloadForms(context: UIAbilityContext, moduleName: string, abilityName: string, formName: string): Promise&lt;number&gt;

For widgets with the same **moduleName**, **abilityName**, and **formName** in the current application, different widget IDs are allocated each time the widgets are added to the home screen. The widget provider can use this API to update these widgets in batches. Compared with the **reloadAllForms** API, this API can be used to update widgets with specific configurations, and is applicable to scenarios where only specific widgets need to be updated. The **reloadAllForms** API updates all widgets that have been added to the home screen by the current application, and is applicable to global refresh scenarios. This API is called in the main process of the application to notify the **FormExtension** process to perform batch updates, and can only be used within a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md). This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------  |
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes  | [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) context, which is used for app identity verification.    |
| moduleName | string | Yes  | Module name of the specified widget, which must be consistent with the module name configured in [form_config.json](../../form/arkts-ui-widget-configuration.md#fields-in-configuration-file). This parameter must be used together with **abilityName** and **formName**. The widget can be located only when all the three parameters match.  |
| abilityName | string | Yes| Ability name of the specified widget, which must be consistent with the ability name configured in [form_config.json](../../form/arkts-ui-widget-configuration.md#fields-in-configuration-file). |
| formName | string | Yes| Name of the widget configured in [form_config.json](../../form/arkts-ui-widget-configuration.md#fields-in-configuration-file).|

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of widgets requested for update.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { formProvider } from '@kit.FormKit';

try {
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // Replace the information with the actual widget information to be updated.
  let moduleName: string = 'entry';
  let abilityName: string = 'EntryFormAbility';
  let formName: string = 'formName';
  formProvider.reloadForms(context, moduleName, abilityName, formName).then((reloadNum: number) => {
    console.info(`reloadForms success, reload number: ${reloadNum}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formProvider.reloadAllForms<sup>22+</sup>

reloadAllForms(context: UIAbilityContext): Promise&lt;number&gt;

Called in the main process of an application to notify the **FormExtension** process to perform a batch update of all widgets added to the home screen by the application. It can only be called within a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) and uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------  |
| context | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes  | [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) context, which is used for app identity verification.    |

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of widgets requested for update.|

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { formProvider } from '@kit.FormKit';

try {
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  formProvider.reloadAllForms(context).then((reloadNum: number) => {
    console.info(`reloadAllForms success, reload number: ${reloadNum}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
