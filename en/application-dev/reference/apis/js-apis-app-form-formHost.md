# @ohos.app.form.formHost (formHost)

The **formHost** module provides APIs related to the widget host, which is an application that displays the widget content and controls the position where the widget is displayed. You can use the APIs to delete, release, and update widgets installed by the same user, and obtain widget information and status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import formHost from '@ohos.app.form.formHost';
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.deleteForm(formId, (error) => {
  if (error) {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  } else {
    console.log('formHost deleteForm success');
  }
  });
} catch (error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Parameters**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.deleteForm(formId).then(() => {
    console.log('formHost deleteForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isReleaseCache | boolean | Yes  | Whether to release the cache.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is released, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isReleaseCache | boolean | No  | Whether to release the cache. The default value is **false**. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.releaseForm(formId, true).then(() => {
    console.log('formHost releaseForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.requestForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.requestForm(formId).then(() => {
    console.log('formHost requestForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds upper bound. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.castToNormalForm(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501002 | The number of forms exceeds upper bound. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = '12400633174999288';
  formHost.castToNormalForm(formId).then(() => {
    console.log('formHost castTempForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyVisibleForms(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyVisibleForms(formId).then(() => {
    console.log('formHost notifyVisibleForms success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.notifyInvisibleForms(formId).then(() => {
    console.log('formHost notifyInvisibleForms success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.enableFormsUpdate(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.enableFormsUpdate(formId).then(() => {
    console.log('formHost enableFormsUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.disableFormsUpdate(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formId = ['12400633174999288'];
  formHost.disableFormsUpdate(formId).then(() => {
    console.log('formHost disableFormsUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application.   |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.isSystemReady((error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application.   |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.isSystemReady().then(() => {
    console.log('formHost isSystemReady success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by all applications on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getAllFormsInfo((error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getAllFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by all applications on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Return value**

| Type                                                        | Description                               |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getAllFormsInfo().then((data) => {
    console.log('formHost getAllFormsInfo data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by a given application on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| bundleName | string | Yes| Bundle name of the application.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by a given application on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| bundleName | string | Yes| Bundle name of the application.|
| moduleName | string | Yes|  Module name.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by a given application on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| bundleName | string | Yes| Bundle name of the application.|
| moduleName | string | No|  Module name. By default, no value is passed.|

**Return value**

| Type                                                        | Description                               |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data) => {
    console.log('formHost getFormsInfo, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfos<sup>10+</sup>

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, hostBundleName?: string): void

Obtains information about all non-temporary widgets running on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained.|
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If this parameter is specified, only the information about the non-temporary widgets that are running under the widget host is returned.<br>By default, information about all running non-temporary widgets on the device is returned.|

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getRunningFormInfos((error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfos, data: ${JSON.stringify(data)}');
    }
  }, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfos<sup>10+</sup>

getRunningFormInfos(hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains information about all non-temporary widgets running on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If this parameter is specified, only the information about the non-temporary widgets that are running under the widget host is returned.<br>By default, information about all running non-temporary widgets on the device is returned.|

**Return value**

| Type                                                        | Description                               |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  formHost.getRunningFormInfos('com.example.ohos.formjsdemo').then((data) => {
    console.log('formHost getRunningFormInfos, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;number&gt;): void

Deletes invalid widgets from the list. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of valid widget IDs.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the invalid widgets are deleted, **error** is undefined and **data** is the number of widgets deleted; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formIds = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost deleteInvalidForms, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

try {
  let formIds = new Array('12400633174999288', '12400633174999289');
  formHost.deleteInvalidForms(formIds).then((data) => {
    console.log('formHost deleteInvalidForms, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
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
| want | [Want](js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state. The information must contain the bundle name, ability name, module name, widget name, and widget dimensions.|
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Yes| Callback used to return the result. If the widget state is obtained, **error** is undefined and **data** is the widget state obtained; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let want = {
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
  formHost.acquireFormState(want, (error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost acquireFormState, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
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
| want   | [Want](js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state. The information must contain the bundle name, ability name, module name, widget name, and widget dimensions.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Promise used to return the widget state obtained.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let want = {
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
  formHost.acquireFormState(want).then((data) => {
    console.log('formHost acquireFormState, data: ${JSON.stringify(data)}');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## on('formUninstall')

on(type: 'formUninstall', callback: Callback&lt;string&gt;): void

Subscribes to widget uninstall events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstall event.|
| callback | Callback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let callback = function(formId) {
  console.log('formHost on formUninstall, formId: ${formId}');
}
formHost.on('formUninstall', callback);
```

## off('formUninstall')

off(type: 'formUninstall', callback?: Callback&lt;string&gt;): void

Unsubscribes from widget uninstall events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstall event.|
| callback | Callback&lt;string&gt; | No| Callback used to return the widget ID. If it is left unspecified, it indicates the callback for all the events that have been subscribed.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formUninstall')**. |

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let callback = function(formId) {
  console.log('formHost on formUninstall, formId: ${formId}');
}
formHost.off('formUninstall', callback);
```

## on('formAdd')<sup>10+</sup>

 on(type: 'formAdd', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

Subscribes to widget addition events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formAdd'** indicates a widget addition event.|
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | Yes| Callback used to return **RunningFormInfo** of the new widget.|
| bundleName | string | No| Name of the bundle that functions as the widget host. By default, widget addition events of all widget hosts are subscribed to.|

**Example**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formAdd', callback);
formHost.on('formAdd', callback, bundleName);
```

## off('formAdd')<sup>10+</sup>

 off(type: "formAdd", observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

Unsubscribes from widget addition events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formAdd'** indicates a widget addition event.|
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | No| Callback used to return **RunningFormInfo**. By default, all the subscriptions to the specified event are canceled.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formAdd')**.|
| bundleName | string | No| Name of the bundle that functions as the widget host.<br>To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('formAdd')**.<br>By default, the subscriptions for all the widget hosts are canceled.|

**Example**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.off('formAdd', callback);
formHost.off('formAdd', callback, bundleName);
```
> **NOTE**
>
> - **on('formAdd', callback)** and **off('formAdd', callback)** must be used in pairs.
> - **on('formAdd', callback, bundleName)** and **off('formAdd', callback, bundleName)** must be used in pairs.
> - To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.

## on('formRemove')<sup>10+</sup>

 on(type: 'formRemove', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

Subscribes to widget removal events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formRemove'** indicates a widget removal event.|
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | Yes| Callback used to return **RunningFormInfo** of the removed widget.|
| bundleName | string | No| Name of the bundle that functions as the widget host. By default, widget removal events of all widget hosts are subscribed to.|

**Example**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.on('formRemove', callback);
formHost.on('formRemove', callback, bundleName);
```

## off('formRemove')<sup>10+</sup>

 off(type: "formRemove", observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;, bundleName?: string): void

Unsubscribes from widget removal events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formRemove'** indicates a widget removal event.|
| callback | Callback&lt;formInfo.RunningFormInfo&gt; | No| Callback used to return **RunningFormInfo**. By default, all the subscriptions to the specified event are canceled.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formRemove')**. |
| bundleName | string | No| Name of the bundle that functions as the widget host.<br>To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('formRemove')**.<br>By default, the subscriptions for all the widget hosts are canceled. |

**Example**

```ts
import formHost from '@ohos.app.form.formHost';
let bundleName = 'ohos.samples.FormApplication';
let callback = function(data) {
  console.log('a new form added, data: ${JSON.stringify(data)');
}

formHost.off('formRemove', callback);
formHost.off('formRemove', callback, bundleName);
```
> **NOTE**
>
> - **on('formRemove', callback)** and **off('formRemove', callback)** must be used in pairs.
> - **on('formRemove', callback, bundleName)** and **off('formRemove', callback, bundleName)** must be used in pairs.
> - To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Instructs the widgets to make themselves visible. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
| isVisible | boolean | Yes  | Whether to make the widgets visible.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isVisible | boolean | Yes  | Whether to make the widgets visible.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsVisible(formIds, true).then(() => {
    console.log('formHost notifyFormsVisible success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isEnableUpdate | boolean | Yes  | Whether to make the widgets updatable.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isEnableUpdate | boolean | Yes  | Whether to make the widgets updatable.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
    console.log('formHost notifyFormsEnableUpdate success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
let deviceId = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16501000 | An internal functional error occurred. |
| 16501001 | The ID of the form to be operated does not exist. |
| 16501003 | The form can not be operated by the current application. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
let deviceId = 'EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2';
try {
  formHost.shareForm(formId, deviceId).then(() => {
    console.log('formHost shareForm success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
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
| isProtected | boolean | Yes  | Whether privacy protection is enabled.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If privacy protection is set successfully, **error** is undefined; otherwise, **error** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string\>, isProtected: boolean): Promise\<void\>;

Notifies that the privacy protection status of the specified widgets changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formIds     | Array\<string\> | Yes  | ID of the widgets.|
| isProtected | boolean         | Yes  | Whether privacy protection is enabled.              |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

```ts
import formHost from '@ohos.app.form.formHost';

let formIds = new Array('12400633174999288', '12400633174999289');
try {
  formHost.notifyFormsPrivacyProtected(formIds, true).then(() => {
    console.log('formHost notifyFormsPrivacyProtected success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string, callback: AsyncCallback<{[key: string]: Object}>): void;

Requests data from the widget provider. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.acquireFormData(formId, (error) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## acquireFormData<sup>10+</sup>

acquireFormData(formId: string): Promise<{[key: string]: Object}>;

Requests data from the widget provider. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId | string | Yes  | Widget ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16500060 | A service connection error happened, please try again later. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000 | An internal functional error occurred. |

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.acquireFormData(formId).then(() => {
    console.log('formHost acquireFormData success');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfosByFilter<sup>10+</sup>

function getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains the information about widget hosts based on the widget provider information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | [formInfo.FormProviderFilter](js-apis-app-form-formInfo.md#formProviderFilter) | Yes  | Information about the widget provider.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md#RunningFormInfo)&gt;&gt; | Promise used to return the widget host information obtained.|

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16501000  | An internal functional error occurred. |

```ts
import formHost from '@ohos.app.form.formHost';

let formInstanceFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formHost.getRunningFormInfosByFilter(formInstanceFilter).then(data1 => {
    console.info('formHost getRunningFormInfosByFilter return err :');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfosByFilter<sup>10+</sup>

function getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the information about widget hosts based on the widget provider information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | formInfo.FormProviderFilter [formInfo.FormProviderFilter](js-apis-app-form-formInfo.md#formProviderFilter) | Yes  | Information about the widget provider.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget host information is obtained, **error** is **undefined** and **data** is the information obtained; otherwise, **data** is an error object.|

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16501000  | An internal functional error occurred. |

```ts
import formHost from '@ohos.app.form.formHost';

let formInstanceFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formHost.getRunningFormInfosByFilter(formInstanceFilter,(error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfosByFilter, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfoById<sup>10+</sup>

function getRunningFormInfoById(formId: string): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains the information about widget hosts based on the widget ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;formInfo.RunningFormInfo[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the widget host information obtained. |

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16501000  | An internal functional error occurred. |

```ts
import formHost from '@ohos.app.form.formHost';
let formId = '12400633174999288';
try {
  formHost.getRunningFormInfoById(formId).then(data1 => {
    console.info('formHost getRunningFormInfoById return err :');
  }).catch((error) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```

## getRunningFormInfoById<sup>10+</sup>

function getRunningFormInfoById(formId: string, callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the information about widget hosts based on the widget ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget host information is obtained, **error** is **undefined** and **data** is the information obtained; otherwise, **data** is an error object.|

**Error codes**

For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 16500050 | An IPC connection error happened. |
| 16501000  | An internal functional error occurred. |

```ts
import formHost from '@ohos.app.form.formHost';

let formId = '12400633174999288';
try {
  formHost.getRunningFormInfoById(formId,(error, data) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log('formHost getRunningFormInfoById, data: ${JSON.stringify(data)}');
    }
  });
} catch(error) {
  console.error(`catch error, code: ${error.code}, message: ${error.message}`);
}
```
