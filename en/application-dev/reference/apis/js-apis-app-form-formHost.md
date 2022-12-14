# @ohos.app.form.formHost

The **FormHost** module provides APIs related to the widget host, which is an application that displays the widget content and controls the position where the widget is displayed. You can use the APIs to delete, release, and update widgets installed by the same user, and obtain widget information and status.

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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is deleted, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.deleteForm(formId, (error, data) => {
  if (error) {
    console.log('formHost deleteForm, error:' + JSON.stringify(error));
  } else {
    console.log('formHost deleteForm success');
  }
  });
} catch (error) {
  console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Parameters**

```ts
try {
  var formId = "12400633174999288";
  formHost.deleteForm(formId).then(() => {
    console.log('formHost deleteForm success');
  }).catch((error) => {
    console.log('formHost deleteForm, error:' + JSON.stringify(error));
  });
} catch(error) {
  console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is released, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.releaseForm(formId, (error, data) => {
    if (error) {
      console.log('formHost releaseForm, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is released, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.releaseForm(formId, true, (error, data) => {
    if (error) {
      console.log('formHost releaseForm, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| isReleaseCache | boolean | No  | Whether to release the cache.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.releaseForm(formId, true).then(() => {
    console.log('formHost releaseForm success');
  }).catch((error) => {
    console.log('formHost releaseForm, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is updated, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.requestForm(formId, (error, data) => {
    if (error) {
      console.log('formHost requestForm, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.requestForm(formId).then(() => {
    console.log('formHost requestForm success');
  }).catch((error) => {
    console.log('formHost requestForm, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is converted to a normal one, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.castToNormalForm(formId, (error, data) => {
    if (error) {
      console.log('formHost castTempForm, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.castToNormalForm(formId).then(() => {
    console.log('formHost castTempForm success');
  }).catch((error) => {
    console.log('formHost castTempForm, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget visible, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.notifyVisibleForms(formId, (error, data) => {
    if (error) {
      console.log('formHost notifyVisibleForms, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.notifyVisibleForms(formId).then(() => {
    console.log('formHost notifyVisibleForms success');
  }).catch((error) => {
    console.log('formHost notifyVisibleForms, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget invisible, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.notifyInvisibleForms(formId, (error, data) => {
    if (error) {
      console.log('formHost notifyInvisibleForms, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.notifyInvisibleForms(formId).then(() => {
    console.log('formHost notifyInvisibleForms success');
  }).catch((error) => {
    console.log('formHost notifyInvisibleForms, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget updatable, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.enableFormsUpdate(formId, (error, data) => {
    if (error) {
      console.log('formHost enableFormsUpdate, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.enableFormsUpdate(formId).then(() => {
    console.log('formHost enableFormsUpdate success');
  }).catch((error) => {
    console.log('formHost enableFormsUpdate, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If a notification is sent to the widget framework to make the widget not updatable, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.disableFormsUpdate(formId, (error, data) => {
    if (error) {
      console.log('formHost disableFormsUpdate, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  var formId = ["12400633174999288"];
  formHost.disableFormsUpdate(formId).then(() => {
    console.log('formHost disableFormsUpdate success');
  }).catch((error) => {
    console.log('formHost disableFormsUpdate, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

Checks whether the system is ready. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the check is successful, **err** is undefined; otherwise, **err** is an error object.|

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.isSystemReady((error, data) => {
    if (error) {
      console.log('formHost isSystemReady, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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

**Example**

```ts
try {
  var formId = "12400633174999288";
  formHost.isSystemReady().then(() => {
    console.log('formHost isSystemReady success');
  }).catch((error) => {
    console.log('formHost isSystemReady, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by all applications on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **err** is undefined and **data** is the information obtained; otherwise, **err** is an error object.|

**Example**

```ts
try {
  formHost.getAllFormsInfo((error, data) => {
    if (error) {
      console.log('formHost getAllFormsInfo, error:' + JSON.stringify(error));
    } else {
      console.log('formHost getAllFormsInfo, data:' + JSON.stringify(data));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by all applications on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Example**

```ts
try {
  formHost.getAllFormsInfo().then((data) => {
      console.log('formHost getAllFormsInfo data:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('formHost getAllFormsInfo, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| bundleName | string | Yes|  Bundle name of the application.|
| callback | AsyncCallback&lt;Array&lt;[FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **err** is undefined and **data** is the information obtained; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  formHost.getFormsInfo("com.example.ohos.formjsdemo", (error, data) => {
    if (error) {
      console.log('formHost getFormsInfo, error:' + JSON.stringify(error));
    } else {
      console.log('formHost getFormsInfo, data:' + JSON.stringify(data));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| bundleName | string | Yes|  Bundle name of the application.|
| moduleName | string | Yes|  Module name.|
| callback | AsyncCallback&lt;Array&lt;[FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **err** is undefined and **data** is the information obtained; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  formHost.getFormsInfo("com.example.ohos.formjsdemo", "entry", (error, data) => {
    if (error) {
        console.log('formHost getFormsInfo, error:' + JSON.stringify(error));
    } else {
        console.log('formHost getFormsInfo, data:' + JSON.stringify(data));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| bundleName | string | Yes|  Bundle name of the application.|
| moduleName | string | No|  Module name.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
try {
  formHost.getFormsInfo("com.example.ohos.formjsdemo", "entry").then((data) => {
    console.log('formHost getFormsInfo, data:' + JSON.stringify(data));
  }).catch((error) => {
    console.log('formHost getFormsInfo, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the invalid widgets are deleted, **err** is undefined and **data** is the number of widgets deleted; otherwise, **err** is an error object.|

**Example**

```ts
try {
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.deleteInvalidForms(formIds, (error, data) => {
    if (error) {
      console.log('formHost deleteInvalidForms, error:' + JSON.stringify(error));
    } else {
      console.log('formHost deleteInvalidForms, data:' + JSON.stringify(data));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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

**Example**

```ts
try {
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.deleteInvalidForms(formIds).then((data) => {
    console.log('formHost deleteInvalidForms, data:' + JSON.stringify(data));
  }).catch((error) => {
    console.log('formHost deleteInvalidForms, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| want | [Want](js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state.|
| callback | AsyncCallback&lt;[FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Yes| Callback used to return the result. If the widget state is obtained, **err** is undefined and **data** is the widget state obtained; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var want = {
  "deviceId": "",
  "bundleName": "ohos.samples.FormApplication",
  "abilityName": "FormAbility",
  "parameters": {
    "ohos.extra.param.key.module_name": "entry",
    "ohos.extra.param.key.form_name": "widget",
    "ohos.extra.param.key.form_dimension": 2
  }
};
try {
  formHost.acquireFormState(want, (error, data) => {
    if (error) {
      console.log('formHost acquireFormState, error:' + JSON.stringify(error));
    } else {
      console.log('formHost acquireFormState, data:' + JSON.stringify(data));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| want   | [Want](js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[FormStateInfo](js-apis-app-form-formInfo.md#formstateinfo)&gt; | Promise used to return the widget state obtained.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var want = {
  "deviceId": "",
  "bundleName": "ohos.samples.FormApplication",
  "abilityName": "FormAbility",
  "parameters": {
    "ohos.extra.param.key.module_name": "entry",
    "ohos.extra.param.key.form_name": "widget",
    "ohos.extra.param.key.form_dimension": 2
  }
};
try {
  formHost.acquireFormState(want).then((data) => {
    console.log('formHost acquireFormState, data:' + JSON.stringify(data));
  }).catch((error) => {
    console.log('formHost acquireFormState, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

## on("formUninstall")

on(type: "formUninstall", callback: Callback&lt;string&gt;): void

Subscribes to widget uninstall events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **formUninstall** indicates a widget uninstallation event.|
| callback | Callback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Example**

```ts
let callback = function(formId) {
  console.log('formHost on formUninstall, formId:' + formId);
}
formHost.on("formUninstall", callback);
```

## off("formUninstall")

off(type: "formUninstall", callback?: Callback&lt;string&gt;): void

Unsubscribes from widget uninstall events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **formUninstall** indicates a widget uninstallation event.|
| callback | Callback&lt;string&gt; | No| Callback used to return the widget ID. If it is left unspecified, it indicates the callback for all the events that have been subscribed.|

**Example**

```ts
let callback = function(formId) {
  console.log('formHost on formUninstall, formId:' + formId);
}
formHost.off("formUninstall", callback);
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
| isVisible | boolean | Yes  | Whether to make the widgets visible.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var formIds = new Array("12400633174999288", "12400633174999289");
try {
  formHost.notifyFormsVisible(formIds, true, (error, data) => {
    if (error) {
      console.log('formHost notifyFormsVisible, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var formIds = new Array("12400633174999288", "12400633174999289");
try {
  formHost.notifyFormsVisible(formIds, true).then(() => {
    console.log('formHost notifyFormsVisible success');
  }).catch((error) => {
    console.log('formHost notifyFormsVisible, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var formIds = new Array("12400633174999288", "12400633174999289");
try {
  formHost.notifyFormsEnableUpdate(formIds, true, (error, data) => {
    if (error) {
      console.log('formHost notifyFormsEnableUpdate, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Example**

```ts
var formIds = new Array("12400633174999288", "12400633174999289");
try {
  formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
    console.log('formHost notifyFormsEnableUpdate success');
  }).catch((error) => {
    console.log('formHost notifyFormsEnableUpdate, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is shared, **err** is undefined; otherwise, **err** is an error object.|

**Error codes**

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).


**Example**

```ts
var formId = "12400633174999288";
var deviceId = "EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2";
try {
  formHost.shareForm(formId, deviceId, (error, data) => {
    if (error) {
      console.log('formHost shareForm, error:' + JSON.stringify(error));
    }
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
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
| 401 | If the input parameter is not valid parameter. |
For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).

**Parameters**

```ts
var formId = "12400633174999288";
var deviceId = "EFC11C0C53628D8CC2F8CB5052477E130D075917034613B9884C55CD22B3DEF2";
try {
  formHost.shareForm(formId, deviceId).then(() => {
    console.log('formHost shareForm success');
  }).catch((error) => {
    console.log('formHost shareForm, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

## notifyFormsPrivacyProtected

notifyFormsPrivacyProtected(formIds: Array\<string>, isProtected: boolean, callback: AsyncCallback\<void>): void

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| deviceId | string | Yes  | Remote device ID.|

```ts
var formIds = new Array("12400633174999288", "12400633174999289");
try {
  formHost.notifyFormsPrivacyProtected(formIds, true).then(() => {
    console.log('formHost shareForm success');
  }).catch((error) => {
    console.log('formHost shareForm, error:' + JSON.stringify(error));
  });
} catch(error) {
    console.log(`catch err->${JSON.stringify(error)}`);
}
```

 <!--no_check--> 