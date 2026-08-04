# @ohos.app.form.formHost (formHost) (System API)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

The **formHost** module provides APIs related to the widget host, which is an application that displays the widget content and controls the position where the widget is displayed. You can use the APIs to delete, release, and update widgets installed by the same user, and obtain widget information and status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { formHost } from '@kit.FormKit';
```

## deleteForm

deleteForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a widget. After this API is called, the application can no longer use the widget, and the Widget Manager will not retain the widget information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is deleted, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.deleteForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info('formHost deleteForm success');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## deleteForm

deleteForm(formId: string): Promise&lt;void&gt;

Deletes a widget. After this API is called, the application can no longer use the widget, and the Widget Manager will not retain the widget information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

try {
  let formId: string = '12400633174999288';
  formHost.deleteForm(formId).then(() => {
    console.info('formHost deleteForm success');
  }).catch((error: BusinessError) => {
    console.error(`formHost deleteForm, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## releaseForm

releaseForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

Releases a widget. After this API is called, the application can no longer use the widget, but the Widget Manager still retains the widget cache and storage information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is released, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## releaseForm

releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback&lt;void&gt;): void

Releases a widget. After this API is called, the application can no longer use the widget, but the Widget Manager retains the storage information about the widget and retains or releases the cache information based on the setting. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name        | Type    | Mandatory| Description       |
| -------------- | ------  | ---- | ----------- |
| formId         | string  | Yes  | Widget ID.    |
| isReleaseCache | boolean | Yes  | Whether to release the cache.<br>**true**: Release the cache.<br>**false**: Not release the cache.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is released, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## releaseForm

releaseForm(formId: string, isReleaseCache?: boolean): Promise&lt;void&gt;

Releases a widget. After this API is called, the application can no longer use the widget, but the Widget Manager retains the storage information about the widget and retains or releases the cache information based on the setting. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name        | Type    | Mandatory| Description       |
| -------------- | ------  | ---- | ----------- |
| formId         | string  | Yes  | Widget ID.    |
| isReleaseCache | boolean | No  | Whether to release the cache. The default value is **false**.<br>**true**: Release the cache.<br>**false**: Not release the cache. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.releaseForm(formId, true).then(() => {
    console.info('formHost releaseForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## requestForm

requestForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

Requests a widget update. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is updated, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.requestForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## requestForm

requestForm(formId: string): Promise&lt;void&gt;

Requests a widget update. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.requestForm(formId).then(() => {
    console.info('formHost requestForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## requestFormWithParams<sup>12+</sup>

requestFormWithParams(formId: string, wantParams?: Record<string, Object>): Promise&lt;void&gt;

Carries parameters to request a widget update. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| wantParams | Record<string, Object> | No  | Parameters used for the update.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  let params: Record<string, Object> = {
    'ohos.extra.param.key.host_bg_inverse_color': '#ff000000' as Object
  };
  formHost.requestFormWithParams(formId, params).then(() => {
    console.info('formHost requestFormWithParams success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## castToNormalForm

castToNormalForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

Converts a temporary widget to a normal one. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is converted to a normal one, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.castToNormalForm(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## castToNormalForm

castToNormalForm(formId: string): Promise&lt;void&gt;

Converts a temporary widget to a normal one. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds the maximum allowed. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.castToNormalForm(formId).then(() => {
    console.info('formHost castToNormalForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Instructs the widget framework to make a widget visible. After this API is called, **onVisibilityChange** is invoked to notify the widget provider. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | Yes  | List of widget IDs.        |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget visible, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyVisibleForms(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyVisibleForms

notifyVisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Instructs the widget framework to make a widget visible. After this API is called, **onVisibilityChange** is invoked to notify the widget provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of valid widget IDs.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyVisibleForms(formId).then(() => {
    console.info('formHost notifyVisibleForms success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Instructs the widget framework to make a widget invisible. After this API is called, **onVisibilityChange** is invoked to notify the widget provider. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | Yes  | List of widget IDs.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget invisible, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyInvisibleForms

notifyInvisibleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Instructs the widget framework to make a widget invisible. After this API is called, **onVisibilityChange** is invoked to notify the widget provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId).then(() => {
    console.info('formHost notifyInvisibleForms success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Instructs the widget framework to make a widget updatable. After this API is called, the widget is in the enabled state and can receive updates from the widget provider. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | Yes  | List of widget IDs.        |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget updatable, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.enableFormsUpdate(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## enableFormsUpdate

enableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Instructs the widget framework to make a widget updatable. After this API is called, the widget is in the enabled state and can receive updates from the widget provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.enableFormsUpdate(formId).then(() => {
    console.info('formHost enableFormsUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Instructs the widget framework to make a widget not updatable. After this API is called, the widget cannot receive updates from the widget provider. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds  | Array&lt;string&gt;       | Yes  | List of widget IDs.        |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget not updatable, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.disableFormsUpdate(formId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## disableFormsUpdate

disableFormsUpdate(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Instructs the widget framework to make a widget not updatable. After this API is called, the widget cannot receive updates from the widget provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string[] = ['12400633174999288'];
  formHost.disableFormsUpdate(formId).then(() => {
    console.info('formHost disableFormsUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

Checks whether the system is ready. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the check is successful, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application.   |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.isSystemReady((error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## isSystemReady

isSystemReady(): Promise&lt;void&gt;

Checks whether the system is ready. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application.   |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.isSystemReady().then(() => {
    console.info('formHost isSystemReady success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by all applications on the device (excluding template widgets). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                                          | Mandatory| Description   |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

try {
  formHost.getAllFormsInfo((error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info('formHost getAllFormsInfo success.');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by all applications on the device (excluding template widgets). This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type                                                                                    | Description                   |
|:---------------------------------------------------------------------------------------|:----------------------|
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

try {
  formHost.getAllFormsInfo().then((data: formInfo.FormInfo[]) => {
    console.info('formHost getAllFormsInfo success.');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by a specified application on the device (excluding template widgets). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                                          | Mandatory| Description   |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| bundleName | string                                                                                       | Yes| Bundle name of the application.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', (error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info('formHost getFormsInfo success.');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by a specified application on the device (excluding template widgets). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                                                          | Mandatory| Description   |
| ------ |----------------------------------------------------------------------------------------------| ---- | ------- |
| bundleName | string                                                                                       | Yes| Bundle name of the application.|
| moduleName | string                                                                                       | Yes|  Module name.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error: BusinessError, data: formInfo.FormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info('formHost getFormsInfo success.');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by a specified application on the device (excluding template widgets). This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| bundleName | string | Yes| Bundle name of the application.|
| moduleName | string | No|  Module name. By default, no value is passed.|

**Return value**

| Type                                                                                    | Description                               |
|:---------------------------------------------------------------------------------------| :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data: formInfo.FormInfo[]) => {
    console.info('formHost getFormsInfo success.');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo<sup>12+</sup>

getFormsInfo(filter: formInfo.FormInfoFilter): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by a specified application on the device (excluding template widgets). This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| filter | [formInfo.FormInfoFilter](js-apis-app-form-formInfo.md#forminfofilter) | Yes| Filter criterion.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application.  |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.  |
| 16500060 | Service connection error.  |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';

const filter: formInfo.FormInfoFilter = {
  bundleName: 'ohos.samples.FormApplication',
  moduleName: 'entry',
  supportedDimensions: [FormDimension.Dimension_1_2, FormDimension.Dimension_2_2, FormDimension.Dimension_2_4]
};
try {
  formHost.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {
    console.info('formHost getFormsInfo success.');
  }).catch((error: BusinessError) => {
    console.error(`promise error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;number&gt;): void

Deletes widgets that are not in the valid widget list. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of valid widgets.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the invalid widgets are deleted, **error** is undefined and **data** is the number of widgets deleted; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

try {
  let formIds: string[] = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds, (error: BusinessError, data: number) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info(`formHost deleteInvalidForms, data: ${data}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;): Promise&lt;number&gt;

Deletes invalid widgets from the list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of valid widget IDs.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of widgets deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

try {
  let formIds: string[] = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds).then((data: number) => {
    console.info(`formHost deleteInvalidForms, data: ${data}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;formInfo.FormStateInfo&gt;): void

Obtains the widget state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | **Want** information carried to query the widget state. The information must contain the bundle name, ability name, module name, widget name, and widget dimensions.|
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Yes| Callback used to return the result. If the widget state is obtained, **error** is undefined and **data** is the widget state obtained; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  'deviceId': '',
  'bundleName': 'ohos.samples.FormApplication',
  'abilityName': 'FormAbility',
  'parameters': {
    'ohos.extra.param.key.module_name': 'entry',
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.form_dimension': 2
  }
};
try {
  formHost.acquireFormState(want, (error: BusinessError, data: formInfo.FormStateInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info(`formHost acquireFormState, data: ${data.formState}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormState

acquireFormState(want: Want): Promise&lt;formInfo.FormStateInfo&gt;

Obtains the widget state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | **Want** information carried to query the widget state. The information must contain the bundle name, ability name, module name, widget name, and widget dimensions.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Promise used to return the widget state obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  'deviceId': '',
  'bundleName': 'ohos.samples.FormApplication',
  'abilityName': 'FormAbility',
  'parameters': {
    'ohos.extra.param.key.module_name': 'entry',
    'ohos.extra.param.key.form_name': 'widget',
    'ohos.extra.param.key.form_dimension': 2
  }
};
try {
  formHost.acquireFormState(want).then((data: formInfo.FormStateInfo) => {
    console.info(`formHost acquireFormState, data: ${data.formState}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## on('formUninstall')

on(type: 'formUninstall', callback: Callback&lt;string&gt;): void

Subscribes to widget uninstall events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> Widget uninstall is different from widget removal. When an application is uninstalled, the corresponding widget is automatically uninstalled.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstall event.|
| callback | Callback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

formHost.on('formUninstall', (formId: string) => {
  console.info(`formHost on formUninstall, formId: ${formId}`);
});
```

## off('formUninstall')

off(type: 'formUninstall', callback?: Callback&lt;string&gt;): void

Unsubscribes from widget uninstall events. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> Widget uninstall is different from widget removal. When an application is uninstalled, the corresponding widget is automatically uninstalled.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstall event.|
| callback | Callback&lt;string&gt; | No| Callback used to return the widget ID. If it is left unspecified, it indicates the callback for all the events that have been subscribed.<br> To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formUninstall')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

formHost.off('formUninstall', (formId: string) => {
  console.info(`formHost on formUninstall, formId: ${formId}`);
});
```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Instructs the widgets to make themselves visible. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
| isVisible | boolean | Yes  | Whether the widget is visible.<br>**true**: The widget is visible.<br>**false**: The widget is invisible.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean): Promise&lt;void&gt;

Instructs the widgets to make themselves visible. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
| isVisible | boolean | Yes  | Whether the widget is visible.<br>**true**: The widget is visible.<br>**false**: The widget is invisible.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true).then(() => {
    console.info('formHost notifyFormsVisible success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean, callback: AsyncCallback&lt;void&gt;): void

Instructs the widgets to enable or disable updates. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
| isEnableUpdate | boolean | Yes  | Indicates whether the widget update state is enabled.<br>**true**: yes **false**: no|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean): Promise&lt;void&gt;

Instructs the widgets to enable or disable updates. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
| isEnableUpdate | boolean | Yes  | Instructs the widgets to enable or disable updates.<br>**true**: yes<br>**false**: no|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
    console.info('formHost notifyFormsEnableUpdate success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## shareForm

shareForm(formId: string, deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Shares a specified widget with a remote device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| deviceId | string | Yes  | Remote device ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is shared, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let deviceId: string = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## shareForm

shareForm(formId: string, deviceId: string): Promise&lt;void&gt;

Shares a specified widget with a remote device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| deviceId | string | Yes  | Remote device ID.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form cannot be operated by the current application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let deviceId: string = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId).then(() => {
    console.info('formHost shareForm success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean, callback: AsyncCallback\<void>): void

Notifies that the privacy protection status of the specified widgets changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array\<string\> | Yes  | ID of the widgets.|
| isProtected | boolean | Yes  | Whether a widget requires privacy protection.<br>**true**: The widget requires privacy protection.<br>**false**: The widget does not require privacy protection.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If privacy protection is set successfully, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true, (error: BusinessError) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string\>, isProtected: boolean): Promise\<void\>

Notifies that the privacy protection status of the specified widgets changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formIds     | Array\<string\> | Yes  | ID of the widgets.|
| isProtected | boolean         | Yes  | Whether a widget requires privacy protection.<br>**true**: The widget requires privacy protection.<br>**false**: The widget does not require privacy protection.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred. |

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true).then(() => {
    console.info('formHost notifyFormsPrivacyProtected success');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string, callback: AsyncCallback\<Record\<string, Object>>): void

Requests data from the widget provider. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback\<Record\<string, Object>> | Yes  | Callback used to return the API call result and the widget provider data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. invalid input parameter during form operation. |

**Example**

```ts
import { formHost } from '@kit.FormKit';

let formId: string = '12400633174999288';
try {
  formHost.acquireFormData(formId, (error: BusinessError, data: Record<string, Object>) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.info('formHost acquireFormData success.');
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string): Promise\<Record\<string, Object>>

Requests data from the widget provider. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise\<Record\<string, Object>> | Promise used to return the API call result and the widget provider data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500060 | Service connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. invalid input parameter during form operation. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formHost.acquireFormData(formId).then((data) => {
    console.info('formHost acquireFormData success' + data);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (e) {
  console.error(`catch error, code: ${(e as BusinessError).code}, message: ${(e as BusinessError).message}`);
}
```

## setRouterProxy<sup>11+</sup>

setRouterProxy(formIds: Array&lt;string&gt;, proxy: Callback&lt;Want&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets a router proxy for widgets and obtains the Want information required for redirection. This API uses an asynchronous callback to return the result.



> **NOTE**
>
>- Generally, for a widget added to the home screen, in the case of router-based redirection, the widget framework checks whether the destination is proper and whether the widget has the redirection permission, and then triggers redirection accordingly. For a widget that is added to a widget host and has a router proxy configured, in the case of router-based redirection, the widget framework does not trigger redirection for the widget. Instead, it returns the **want** parameter containing the destination to the widget host. Therefore, if the widget host wants to use the Want information for redirection, it must have the application redirection permission. For details, see
[UIAbilityContext.startAbility()](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability).
>
>- Only one router proxy can be set for a widget. If multiple proxies are set, only the last proxy takes effect.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;       | Yes  | Array of widget IDs.                                              |
| proxy    | Callback&lt;Want&gt;      | Yes  | Callback used to return the Want information required for redirection.                        |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the router proxy is set, **error** is **undefined**; otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct CardExample {
  @State formId: number = 0;
  @State fwidth: number = 420;
  @State fheight: number = 280;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      FormComponent({
        id: this.formId,
        name: "widget",
        bundle: "com.example.cardprovider",
        ability: "EntryFormAbility",
        module: "entry",
        dimension: FormDimension.Dimension_2_2,
        temporary: false,
      })
        .allowUpdate(true)
        .size({ width: this.fwidth, height: this.fheight })
        .visibility(Visibility.Visible)
        .onAcquired((form) => {
          console.info('testTag onAcquired.');
          this.formId = form.id;
          try {
            let formIds: string[] = [this.formId.toString()];
            formHost.setRouterProxy(formIds, (want: Want) => {
              console.info('formHost recv router event.');
              // The widget host processes the redirection.
              this.context.startAbility(want, (err: BusinessError) => {
                console.error(`formHost startAbility error, code: ${err.code}, message: ${err.message}`);
              });
            }, (err: BusinessError) => {
              console.error(`set router proxy error, code: ${err.code}, message: ${err.message}`);
            })
          } catch (e) {
            console.error(`formHost setRouterProxy, code: ${(e as BusinessError).code}, message: ${(e as BusinessError).message}`);
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## setRouterProxy<sup>11+</sup>

setRouterProxy(formIds: Array&lt;string&gt;, proxy: Callback&lt;Want&gt;): Promise&lt;void&gt;

Sets a router proxy for widgets and obtains the Want information required for redirection. This API uses a promise to return the result.

> **NOTE**
>
>- Generally, for a widget added to the home screen, in the case of router-based redirection, the widget framework checks whether the destination is proper and whether the widget has the redirection permission, and then triggers redirection accordingly. For a widget that is added to a widget host and has a router proxy configured, in the case of router-based redirection, the widget framework does not trigger redirection for the widget. Instead, it returns the **want** parameter containing the destination to the widget host. Therefore, if the widget host wants to use the Want information for redirection, it must have the application redirection permission. For details, see [UIAbilityContext.startAbility()](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability).
>
>- Only one router proxy can be set for a widget. If multiple proxies are set, only the last proxy takes effect.



**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type                | Mandatory| Description                                |
| ------- | -------------------- | ---- | ------------------------------------ |
| formIds | Array&lt;string&gt;  | Yes  | Array of widget IDs.                      |
| proxy   | Callback&lt;Want&gt; | Yes  | Callback used to return the Want information required for redirection.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct CardExample {
  @State formId: number = 0;
  @State fwidth: number = 420;
  @State fheight: number = 280;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      FormComponent({
        id: this.formId,
        name: "widget",
        bundle: "com.example.cardprovider",
        ability: "EntryFormAbility",
        module: "entry",
        dimension: FormDimension.Dimension_2_2,
        temporary: false,
      })
        .allowUpdate(true)
        .size({ width: this.fwidth, height: this.fheight })
        .visibility(Visibility.Visible)
        .onAcquired((form) => {
          console.info('testTag onAcquired.');
          this.formId = form.id;
          try {
            let formIds: string[] = [this.formId.toString()];
            formHost.setRouterProxy(formIds, (want: Want) => {
              console.info('formHost recv router event.');
              // The widget host processes the redirection.
              this.context.startAbility(want, (err: BusinessError) => {
                console.error(`formHost startAbility error, code: ${err.code}, message: ${err.message}`);
              });
            }).then(() => {
              console.info('formHost set router proxy success');
            }).catch((err: BusinessError) => {
              console.error(`set router proxy error, code: ${err.code}, message: ${err.message}`);
            })
          } catch (e) {
            console.error(`formHost setRouterProxy, code: ${e.code}, message: ${e.message}`);
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## clearRouterProxy<sup>11+</sup>

clearRouterProxy(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Clears the router proxy set for widgets. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;      | Yes  | Array of widget IDs.                                              |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.clearRouterProxy(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`formHost clear router proxy error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## clearRouterProxy<sup>11+</sup>

clearRouterProxy(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Clears the router proxy set for widgets. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type               | Mandatory| Description          |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | Yes  | Array of widget IDs.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.clearRouterProxy(formIds).then(() => {
    console.info('formHost clear router proxy success');
  }).catch((err: BusinessError) => {
    console.error(`formHost clear router proxy error, code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## setFormsRecyclable<sup>11+</sup>

setFormsRecyclable(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets widgets to be recyclable. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;      | Yes  | Array of widget IDs.                                              |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the widgets are set to be recyclable, **error** is **undefined**; otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.setFormsRecyclable(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`setFormsRecyclable error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## setFormsRecyclable<sup>11+</sup>

setFormsRecyclable(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Sets widgets to be recyclable. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type               | Mandatory| Description          |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | Yes  | Array of widget IDs.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.setFormsRecyclable(formIds).then(() => {
    console.info('setFormsRecyclable success');
  }).catch((err: BusinessError) => {
    console.error(`setFormsRecyclable error, code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## recoverForms<sup>11+</sup>

recoverForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Recovers the specified widgets that have been recycled and updates their state to non‑recyclable. If a widget has not been recycled, its state is still updated to non‑recyclable. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| formIds  | Array&lt;string&gt;      | Yes  | Array of widget IDs.                                              |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the widgets are recovered, **error** is **undefined**; otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recoverForms(formIds, (err: BusinessError) => {
    if (err) {
      console.error(`recoverForms error, code: ${err.code}, message: ${err.message}`);
    }
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
## recoverForms<sup>11+</sup>

recoverForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Recovers recycled widgets and updates their status to non-recyclable, or updates the status of widgets to non-recyclable if the widgets are not recycled. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type               | Mandatory| Description          |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | Yes  | Array of widget IDs.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recoverForms(formIds).then(() => {
    console.info('formHost recoverForms success');
  }).catch((err: BusinessError) => {
    console.error(`formHost recover forms error, code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.error(`catch error, code: ${e.code}, message: ${e.message}`);
}
```
## recycleForms<sup>12+</sup>

recycleForms(formIds: Array&lt;string&gt;): Promise&lt;void&gt;

Recycles widgets, that is, reclaiming widget memory. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type               | Mandatory| Description          |
| ------- | ------------------- | ---- | -------------- |
| formIds | Array&lt;string&gt; | Yes  | Array of widget IDs.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formIds: string[] = ['12400633174999288'];
  formHost.recycleForms(formIds).then(() => {
    console.info('recycle forms success');
  }).catch((err: BusinessError) => {
    console.error(`formHost recycle forms error, code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.error(`catch error, code: ${e.code}, message: ${e.message}`);
}
```

## updateFormLocation<sup>12+</sup>
updateFormLocation(formId: string, location: formInfo.FormLocation): void;

Updates the widget location.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| location |[formInfo.FormLocation](js-apis-app-form-formInfo-sys.md#formlocation12) | Yes| Widget location.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                                   |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.            |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  formHost.updateFormLocation(formId, formInfo.FormLocation.SCREEN_LOCK);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## setPublishFormResult<sup>12+</sup>

setPublishFormResult(formId: string, result: formInfo.PublishFormResult): void;

Sets the result for the operation of adding a widget to the home screen.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| formId | string                                                       | Yes  | Widget ID.        |
| result | [formInfo.PublishFormResult](js-apis-app-form-formInfo-sys.md#publishformresult12) | Yes  | Result of the operation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.            |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  let res: formInfo.PublishFormResult = { code: formInfo.PublishFormErrorCode.SUCCESS, message: '' };
  formHost.setPublishFormResult(formId, res);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## updateFormLockedState<sup>22+</sup>

updateFormLockedState(formId: string, isLocked: boolean): Promise&lt;void&gt;

Notifies the update of the widget lock state. This API uses a promise to return the result.

If an application is locked, its widget will also be locked and masked in a locked style. To use the widget, you need to enter the password set for the widget.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type| Mandatory| Description|
|-------|------|------|-----|
| formId | string | Yes| Widget ID.|
| isLocked | boolean | Yes| A Boolean value indicates whether a widget is in the locked state. The value **true** indicates that the widget is in the locked state, and the value **false** indicates the opposite.|

**Return value**
| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permissions denied.                                          |
| 202      | The caller is not a system app.                |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |
| 16501000 | An internal functional error occurred.                       |
| 16501001 | The ID of the form to be operated does not exist.                       |
| 16501003 | The form cannot be operated by the current application.     |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
let isLocked: boolean = true;

try {
  formHost.updateFormLockedState(formId, isLocked).then(() => {
    console.info(`formHost updateFormLockedState success`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.on('formOverflow')<sup>20+</sup>

on(type: 'formOverflow', callback: Callback&lt;formInfo.OverflowRequest&gt;): void

Subscribes to the interactive widget animation request event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type      | Mandatory| Description|
|----------|--------|---|---------------------------------------|
| type     | string | Yes| Event callback. The supported event is **'formOverflow'**, indicating the interactive widget animation request.|
| callback | Callback&lt;[formInfo.OverflowRequest](js-apis-app-form-formInfo-sys.md#overflowrequest20)&gt; | Yes| Callback used by the widget host to process the animation request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                 |
|-------|-----------------------------------------------------------------------------------------------------------|
| 202   | The application is not a system application.                                                              |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.on('formOverflow', (request: formInfo.OverflowRequest) => {
    console.info(`formHost on formOverflow, formId is ${request.formId}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.off('formOverflow')<sup>20+</sup>

off(type: 'formOverflow', callback?: Callback&lt;formInfo.OverflowRequest&gt;): void

Unsubscribes from the interactive widget animation request event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description                                    |
| ------ | ------ |----|----------------------------------------|
| type | string | Yes | Event callback. The supported event is **'formOverflow'**, indicating the interactive widget animation request.|
| callback |Callback&lt;[formInfo.OverflowRequest](js-apis-app-form-formInfo-sys.md#overflowrequest20)&gt; | No | Callback function, which corresponds to the subscribed interactive widget animation request. By default, all registered interactive widget animation request events are deregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                               |
| --- |-----------------------------------------------------------------------------------------------------------|
| 202 | The application is not a system application.                                                              |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.off('formOverflow', (request: formInfo.OverflowRequest) => {
    console.info(`formHost off formOverflow, formId is ${request.formId}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}   
```

## formHost.on('changeSceneAnimationState')<sup>20+</sup>

on(type: 'changeSceneAnimationState', callback: Callback&lt;formInfo.ChangeSceneAnimationStateRequest&gt;): void

Subscribes to the event of switching the interactive widget state. An interactive widget can be in the active or inactive state. In the inactive state, the interactive widget is the same as a common widget. In the active state, the interactive widget can start the **LiveFormExtensionAbility** process developed by the widget host to implement interactive widget animations. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description                                                  |
| ------ | ------ | ---- |------------------------------------------------------|
| type | string | Yes  | Event type. The event **'changeSceneAnimationState'** is triggered when the interactive widget state is switched.|
| callback |Callback&lt;[formInfo.ChangeSceneAnimationStateRequest](js-apis-app-form-formInfo-sys.md#changesceneanimationstaterequest20)&gt; | Yes| Callback function, which is used by the widget host to process the state switching request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                 |
|-------|-----------------------------------------------------------------------------------------------------------|
| 202   | The application is not a system application.                                                              |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.on('changeSceneAnimationState', (request: formInfo.ChangeSceneAnimationStateRequest): void => {
    console.info(`formHost on changeSceneAnimationState, formId is ${request.formId}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.off('changeSceneAnimationState')<sup>20+</sup>

off(type: 'changeSceneAnimationState', callback?: Callback&lt;formInfo.ChangeSceneAnimationStateRequest&gt;): void

Unsubscribes from the event of switching the interactive widget state. An interactive widget can be in the active or inactive state. In the inactive state, the interactive widget is the same as a common widget. In the active state, the interactive widget can start the **LiveFormExtensionAbility** process developed by the widget host to implement interactive widget animations. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ |----| ------- |
| type | string | Yes | Event type. The event **'changeSceneAnimationState'** is triggered when the interactive widget state is switched.|
| callback |Callback&lt;[formInfo.ChangeSceneAnimationStateRequest](js-apis-app-form-formInfo-sys.md#changesceneanimationstaterequest20)&gt; | No | Callback function, which corresponds to the request for switching the state of a subscribed interactive widget. By default, all registered interactive widget state switching events are deregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.off('changeSceneAnimationState', (request: formInfo.ChangeSceneAnimationStateRequest): void => {
    console.info(`formHost off changeSceneAnimationState, formId is ${request.formId}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.on('getFormRect')<sup>20+</sup>

on(type: 'getFormRect', callback: formInfo.GetFormRectInfoCallback): void

Subscribes to the event of requesting widget position and dimension. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description                                                  |
| ------ | ------ | ---- |------------------------------------------------------|
| type | string | Yes  | Event callback type. The supported event is **'getFormRect'**, indicating requesting widget position and dimension.|
| callback |[formInfo.GetFormRectInfoCallback](js-apis-app-form-formInfo-sys.md#getformrectinfocallback20) | Yes| Callback function used by the widget host to process query requests and return the widget position relative to the upper-left corner of the screen and widget dimensions.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                 |
|-------|-----------------------------------------------------------------------------------------------------------|
| 202   | The application is not a system application.                                                              |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.on('getFormRect', (formId: string): Promise<formInfo.Rect> => {
    // The widget host needs to process the request, and calculate and return the widget dimension and position information.
    return new Promise<formInfo.Rect>((resolve: Function) => {
      console.info(`formHost on getFormRect, formId is ${formId}`);
      let formRect: formInfo.Rect = {
        left: 0,
        top: 0,
        width: 0,
        height: 0
      };
      resolve(formRect);
    })
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.off('getFormRect')<sup>20+</sup>

off(type: 'getFormRect', callback?: formInfo.GetFormRectInfoCallback): void

Unsubscribes from the event of requesting widget position and dimension. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ |----| ------- |
| type | string | Yes | Event callback type. The supported event is **'getFormRect'**, indicating requesting widget position and dimension.|
| callback |[formInfo.GetFormRectInfoCallback](js-apis-app-form-formInfo-sys.md#getformrectinfocallback20) | No | Callback function, corresponding to the subscribed widget position and dimension request. By default, all registered widget position and dimension request event callbacks are deregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.off('getFormRect');
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.updateFormSize<sup>20+</sup>

updateFormSize(formId: string, newDimension: formInfo.FormDimension, newRect: formInfo.Rect): void

Updates the size of the widget.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| newDimension | [formInfo.FormDimension](js-apis-app-form-formInfo.md#formdimension) | Yes| Widget dimension. For example, **Dimension_1_2** indicates a 1 x 2 widget.|
| newRect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | Yes| Widget position information, including the X and Y coordinates of the widget's top-left corner, as well as its width and height.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The caller is not a system app.|
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501012 | The dimension parameter is incorrect. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let formId: string = '12400633174999288';
  let newDimension = formInfo.FormDimension.Dimension_1_2;
  let newRect: formInfo.Rect = {
    left: 1,
    top: 2,
    width: 100,
    height: 100
  };
  formHost.updateFormSize(formId, newDimension, newRect);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getAllTemplateFormsInfo<sup>23+</sup>

getAllTemplateFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the template widget information provided by all applications on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Return value**

| Type                                                                                    | Description                   |
|:---------------------------------------------------------------------------------------|:----------------------|
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getAllTemplateFormsInfo().then((data: formInfo.FormInfo[]) => {
    for (let info of data) {
      console.info(`getAllTemplateFormsInfo bundleName: ${info.bundleName}, moduleName: ${info.moduleName}, name: ${info.name}`);
    }
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```


## getTemplateFormsInfo<sup>23+</sup>

getTemplateFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the template widget information provided by a specified application on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| bundleName | string | Yes| Bundle name of the application.|
| moduleName | string | No|  Module name. By default, no value is passed.|

**Return value**

| Type                                                                                    | Description                               |
|:---------------------------------------------------------------------------------------| :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md#forminfo)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getTemplateFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data: formInfo.FormInfo[]) => {
    for (let info of data) {
      console.info(`getTemplateFormsInfo bundleName: ${info.bundleName}, moduleName: ${info.moduleName}, name: ${info.name}`);
    }
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.onTemplateFormDetailInfoChange<sup>23+</sup>

onTemplateFormDetailInfoChange(callback: formInfo.TemplateFormDetailInfoCallback): void

Subscribes to changes in the static configuration information of template widgets. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.TemplateFormDetailInfoCallback](js-apis-app-form-formInfo-sys.md#templateformdetailinfocallback23) | Yes  | Callback function used to listen for changes in the static configuration information of template widgets.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | Permissions denied.Called by non-system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const callback: formInfo.TemplateFormDetailInfoCallback = (info: formInfo.TemplateFormDetailInfo[]) => {
    for (let templateFormDetailInfo of info) {
      console.info(`TemplateFormDetailInfoCallback bundleName: ${templateFormDetailInfo.bundleName}, moduleName: ${templateFormDetailInfo.moduleName}, formName: ${templateFormDetailInfo.formName}`);
    }
  };
  formHost.onTemplateFormDetailInfoChange(callback);
  console.info(`onTemplateFormDetailInfoChange success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```


## formHost.offTemplateFormDetailInfoChange<sup>23+</sup>

offTemplateFormDetailInfoChange(callback?: formInfo.TemplateFormDetailInfoCallback): void

Unsubscribes from changes in the static configuration information of template widgets. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.TemplateFormDetailInfoCallback](js-apis-app-form-formInfo-sys.md#templateformdetailinfocallback23) | No  | Callback function used to listen for changes in the static configuration information of template widgets.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | Permissions denied.Called by non-system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.offTemplateFormDetailInfoChange();
  console.info(`offTemplateFormDetailInfoChange success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.getFormIdsByFormLocation<sup>24+</sup>

getFormIdsByFormLocation(location: formInfo.FormLocation): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of widget IDs at a specified location on the device. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| location | [formInfo.FormLocation](js-apis-app-form-formInfo-sys.md#formlocation12) | Yes| Widget location.|

**Return value**

| Type                                                                                    | Description                               |
|:---------------------------------------------------------------------------------------| :---------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the obtained widget ID list.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |
| 16501016 | The location of the widget is invalid. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.getFormIdsByFormLocation(formInfo.FormLocation.DESKTOP).then((formIds: Array<string>) => {
    console.info('formHost getFormIdsByFormLocation success.');
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## formHost.onGetWantParamsCallback

onGetWantParamsCallback(callback: formInfo.GetWantParamsCallback): void

Subscribes to widget parameter obtaining events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.GetWantParamsCallback](js-apis-app-form-formInfo-sys.md#getwantparamscallback) | Yes  | Callback used to return the widget parameter information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const callback = (formInfos: formInfo.FormInfo[]): Array<Record<string, Object>> => {
    console.info(`onGetWantParamsCallback formInfos length: ${formInfos.length}`);
    let wantParamsList: Array<Record<string, Object>> = [];
    for (let formInfoItem of formInfos) {
      let wantParams: Record<string, Object> = {};
      wantParams['key'] = 'value';
      wantParamsList.push(wantParams);
    }
    return wantParamsList;
  };
  formHost.onGetWantParamsCallback(callback);
  console.info(`onGetWantParamsCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.offGetWantParamsCallback

offGetWantParamsCallback(callback?: formInfo.GetWantParamsCallback): void

Unsubscribes from widget parameter obtaining events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.GetWantParamsCallback](js-apis-app-form-formInfo-sys.md#getwantparamscallback) | No  | Callback used to return the widget parameter information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.offGetWantParamsCallback();
  console.info(`offGetWantParamsCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.onUpdateFormsConfigCallback

onUpdateFormsConfigCallback(callback: formInfo.UpdateFormsConfigCallback): void

Subscribes to widget configuration update events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.UpdateFormsConfigCallback](js-apis-app-form-formInfo-sys.md#updateformsconfigcallback) | Yes  | Callback used to return the widget parameter update information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const callback = (configInfo: formInfo.FormCustomConfig[]): void => {
    console.info(`onUpdateFormsConfigCallback configInfo length: ${configInfo.length}`);
    for (let config of configInfo) {
      console.info(`bundleName: ${config.bundleName}, moduleName: ${config.moduleName}`);
    }
  };
  formHost.onUpdateFormsConfigCallback(callback);
  console.info(`onUpdateFormsConfigCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.offUpdateFormsConfigCallback

offUpdateFormsConfigCallback(callback?: formInfo.UpdateFormsConfigCallback): void

Unsubscribes from widget configuration update events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.UpdateFormsConfigCallback](js-apis-app-form-formInfo-sys.md#updateformsconfigcallback) | No  | Callback used to return the widget parameter update information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.offUpdateFormsConfigCallback();
  console.info(`offUpdateFormsConfigCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.onDeleteFormsCallback

onDeleteFormsCallback(callback: formInfo.DeleteFormsCallback): void

Subscribes to widget deletion events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.DeleteFormsCallback](js-apis-app-form-formInfo-sys.md#deleteformscallback) | Yes  | Callback used to return the list of deleted widget IDs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost, formInfo } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const callback = (formIds: string[]): void => {
    console.info(`onDeleteFormsCallback formIds length: ${formIds.length}`);
    for (let formId of formIds) {
      console.info(`deleted formId: ${formId}`);
    }
  };
  formHost.onDeleteFormsCallback(callback);
  console.info(`onDeleteFormsCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## formHost.offDeleteFormsCallback

offDeleteFormsCallback(callback?: formInfo.DeleteFormsCallback): void

Unsubscribes from widget deletion events. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API.

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | [formInfo.DeleteFormsCallback](js-apis-app-form-formInfo-sys.md#deleteformscallback) | No  | Callback used to return the list of deleted widget IDs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Widget Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | IPC connection error. |

**Example**

```ts
import { formHost } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formHost.offDeleteFormsCallback();
  console.info(`offDeleteFormsCallback success`);
} catch (error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
