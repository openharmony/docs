# @ohos.app.form.formProvider (formProvider)

The **formProvider** module provides APIs to obtain widget information, update widgets, and set the update time.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { formProvider } from '@kit.FormKit';
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void

Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | Yes  | Widget ID.                              |
| minute | number | Yes  | Time after which a widget is updated. The value is greater than or equal to 5, in minutes.    |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

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

let formId: string = '12400633174999288';
try {
  formProvider.setFormNextRefreshTime(formId, 5, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formProvider setFormNextRefreshTime success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.setFormNextRefreshTime

setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;

Sets the next refresh time for a widget. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| formId | string | Yes  | Widget ID.                              |
| minute | number | Yes  | Time after which a widget is updated. The value is greater than or equal to 5, in minutes.    |

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

let formId: string = '12400633174999288';
try {
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {
    console.log(`formProvider setFormNextRefreshTime success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData,callback: AsyncCallback&lt;void&gt;): void

Updates a widget. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | Yes  | ID of the widget to update.|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update.   |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

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

let formId: string = '12400633174999288';
try {
  let param: Record<string, string> = {
    'temperature': '22c',
    'time': '22:00'
  }
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
  formProvider.updateForm(formId, obj, (error: BusinessError) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formProvider updateForm success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.updateForm

updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise&lt;void&gt;

Updates a widget. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                   | Mandatory| Description            |
| ------ | ---------------------------------------------------------------------- | ---- | ---------------- |
| formId | string                                                                 | Yes  | ID of the widget to update.|
| formBindingData | [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | Yes  | Data to be used for the update.   |

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

let formId: string = '12400633174999288';
let param: Record<string, string> = {
  'temperature': '22c',
  'time': '22:00'
}
let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
try {
  formProvider.updateForm(formId, obj).then(() => {
    console.log(`formProvider updateForm success`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.getFormsInfo

getFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the application's widget information on the device. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
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
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formProvider.getFormsInfo((error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
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
  // get info of forms belong to module entry.
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter, (error, data) => {
    if (error) {
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);
      return;
    }
    console.log(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.getFormsInfo

getFormsInfo(filter?: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the application's widget information on the device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | No| Filter criterion. By default, no value is passed, indicating that no filtering is performed.|

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
  // get info of forms belong to module entry.
  moduleName: 'entry'
};
try {
  formProvider.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {
    console.log(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.openFormEditAbility<sup>18+</sup>

openFormEditAbility(abilityName: string, formId: string, isMainPage?: boolean): void

Opens the widget editing page.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description                                                |
| ------ | ------ |----|----------------------------------------------------|
| abilityName | string | Yes | Ability name on the editing page.                                    |
| formId | string | Yes | Widget ID.                                             |
| isMainPage | boolean | No | Whether the page is the main editing page. The value **true** (default) means that the page is the main editing page; the value **false** means the opposite.<br> |

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
import { router } from '@kit.ArkUI';

const TAG: string = 'FormEditDemo-Page] -->';

@Entry
@Component
struct Page {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    console.log(`${TAG} aboutToAppear.....`);
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
          console.log(`${TAG} onClick.....`);
          formProvider.openFormEditAbility('ability://EntryFormEditAbility', '1386529921');
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## formProvider.openFormManager<sup>18+</sup>

openFormManager(want: Want): void

Opens the Widget Manager page.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type   | Mandatory| Description                                                                                                                                                                                                                                                                                                     |
|------| ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| want     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Parameter that must contain the following fields:<br>**bundleName**: bundle name of widget.<br>**abilityName**: ability name of the widget.<br>**parameters**:<br>- **ohos.extra.param.key.form_dimension**: [Widget dimension](js-apis-app-form-formInfo.md#formdimension).<br>- **ohos.extra.param.key.form_name**: Widget name.<br>- **ohos.extra.param.key.module_name**: module name of the widget.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

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
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.getPublishedFormInfoById<sup>18+</sup>

getPublishedFormInfoById(formId: string): Promise&lt;formInfo.FormInfo&gt;

Obtains the information of the widget that has been added to the home screen on the device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

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
    console.log(`formProvider getPublishedFormInfoById, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.getPublishedFormInfos<sup>18+</sup>

getPublishedFormInfos(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the information of all widgets that have been added to the home screen on the device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

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
    console.log(`formProvider getPublishedFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.requestOverflow<sup>20+</sup>

requestOverflow(formId: string, overflowInfo: formInfo.OverflowInfo): Promise&lt;void&gt;

Requests an animation. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result.

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
| 16501011 | The form can not support this operation, please check your fom_config's sceneAnimationParams configuration infomation is correct or not. |

**Example**

```ts
import { formInfo, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let overflowInfo: formInfo.OverflowInfo = {
  area: {
    left: -10,
    top: -10,
    width: 180,
    height: 180
  },
  duration: 1000,
};

try {
  formProvider.requestOverflow(formId, overflowInfo).then(() => {
    console.info('requestOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```

## formProvider.cancelOverflow<sup>20+</sup>

cancelOverflow(formId: string): Promise&lt;void&gt;

Cancels an animation. This API takes effect only for [scene-based widgets](../../form/arkts-ui-widget-configuration.md#sceneanimationparams-field). This API uses a promise to return the result.

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
| 16501011 | The form can not support this operation, please check your fom_config's sceneAnimationParams configuration infomation is correct or not. |

**Example**

```ts
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';

try {
  formProvider.cancelOverflow(formId).then(() => {
    console.info('cancelOverflow succeed.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
}
```
