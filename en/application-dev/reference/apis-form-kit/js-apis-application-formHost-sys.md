# @ohos.application.formHost (formHost) (System API)

The **formHost** module provides APIs related to the widget host, which is an application that displays the widget content and controls the position where the widget is displayed. You can use the APIs to delete, release, and update widgets installed by the same user, and obtain widget information and status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [formHost](js-apis-app-form-formHost-sys.md) instead.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import formHost from '@ohos.application.formHost';
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.deleteForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.deleteForm(formId).then(() => {
  console.log('formHost deleteForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
  } else {
    console.log('formHost releaseForm success');
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
  } else {
    console.log('formHost releaseForm success');
  }
});
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
| isReleaseCache | boolean | No  | Whether to release the cache. The default value is **false**.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.releaseForm(formId, true).then(() => {
  console.log('formHost releaseForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost releaseForm, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.requestForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost requestForm, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.requestForm(formId).then(() => {
  console.log('formHost requestForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost requestForm, error: ${JSON.stringify(error)}`);
});
```

## castTempForm

castTempForm(formId: string, callback: AsyncCallback&lt;void&gt;): void

Converts a temporary widget to a normal one. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| formId | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the widget is converted to a normal one, **error** is undefined; otherwise, **error** is an error object.|

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.castTempForm(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`);
  }
});
```

## castTempForm

castTempForm(formId: string): Promise&lt;void&gt;

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

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.castTempForm(formId).then(() => {
  console.log('formHost castTempForm success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyVisibleForms(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyVisibleForms(formId).then(() => {
  console.log('formHost notifyVisibleForms success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyInvisibleForms(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyInvisibleForms, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.notifyInvisibleForms(formId).then(() => {
  console.log('formHost notifyInvisibleForms success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyInvisibleForms, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.enableFormsUpdate(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.enableFormsUpdate(formId).then(() => {
  console.log('formHost enableFormsUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.disableFormsUpdate(formId, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formId: string[] = ['12400633174999288'];
formHost.disableFormsUpdate(formId).then(() => {
  console.log('formHost disableFormsUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`);
});
```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void

Checks whether the system is ready. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the check is successful, **error** is undefined; otherwise, **error** is an error object.|

**Example**

```ts
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.isSystemReady((error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`);
  }
});
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
import Base from '@ohos.base';

let formId: string = '12400633174999288';
formHost.isSystemReady().then(() => {
  console.log('formHost isSystemReady success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`);
});
```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;formInfo.FormInfo&gt;&gt;): void

Obtains the widget information provided by all applications on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Yes| Callback used to return the result. If the widget information is obtained, **error** is undefined and **data** is the information obtained; otherwise, **error** is an error object.|

**Example**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getAllFormsInfo((error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getAllFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;formInfo.FormInfo&gt;&gt;

Obtains the widget information provided by all applications on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Example**

  ```ts
  import formInfo from '@ohos.app.form.formInfo';
  import Base from '@ohos.base';

  formHost.getAllFormsInfo().then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getAllFormsInfo data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`);
  });
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

**Example**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getFormsInfo('com.example.ohos.formjsdemo', (error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
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

**Example**

```ts
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry', (error: Base.BusinessError, data: formInfo.FormInfo[]) => {
  if (error.code) {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }
});
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
| moduleName | string | No|  Module name.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.FormInfo](js-apis-app-form-formInfo.md)&gt;&gt; | Promise used to return the information obtained.|

**Example**

  ```ts
  import formInfo from '@ohos.app.form.formInfo';
  import Base from '@ohos.base';

  formHost.getFormsInfo('com.example.ohos.formjsdemo', 'entry').then((data: formInfo.FormInfo[]) => {
    console.log(`formHost getFormsInfo, data: ${JSON.stringify(data)}`);
  }).catch((error: Base.BusinessError) => {
    console.error(`formHost getFormsInfo, error: ${JSON.stringify(error)}`);
  });
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

**Example**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.deleteInvalidForms(formIds, (error: Base.BusinessError, data: number) => {
  if (error.code) {
    console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
  }
});
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
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.deleteInvalidForms(formIds).then((data: number) => {
  console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);
}).catch((error: Base.BusinessError) => {
  console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);
});
```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;formInfo.FormStateInfo&gt;): void

Obtains the widget state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| want | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state. The information must contain the bundle name, ability name, module name, widget name, and widget dimensions.|
| callback | AsyncCallback&lt;[formInfo.FormStateInfo](js-apis-application-formInfo.md#formstateinfo)&gt; | Yes| Callback used to return the result. If the widget state is obtained, **error** is undefined and **data** is the widget state obtained; otherwise, **error** is an error object.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

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
formHost.acquireFormState(want, (error:Base.BusinessError, data: formInfo.FormStateInfo) => {
  if (error.code) {
    console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
  }
});
```

## acquireFormState

acquireFormState(want: Want): Promise&lt;formInfo.FormStateInfo&gt;

Obtains the widget state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| want   | [Want](../apis-ability-kit/js-apis-application-want.md) | Yes  | **Want** information carried to query the widget state.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[formInfo.FormStateInfo](js-apis-application-formInfo.md#formstateinfo)&gt; | Promise used to return the widget state obtained.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import formInfo from '@ohos.app.form.formInfo';
import Base from '@ohos.base';

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
formHost.acquireFormState(want).then((data: formInfo.FormStateInfo) => {
  console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);
}).catch((error: Base.BusinessError) => {
  console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);
});
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
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstallation event.|
| callback | Callback&lt;string&gt; | Yes| Callback used to return the widget ID.|

**Example**

```ts
import Base from '@ohos.base';

formHost.on('formUninstall', (formId: string) => {
  console.log(`formHost on formUninstall, formId: ${formId}`);
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
| type | string | Yes  | Event type. The value **'formUninstall'** indicates a widget uninstallation event.|
| callback | Callback&lt;string&gt; | No| Callback used to return the widget ID. If it is left unspecified, it indicates the callback for all the events that have been subscribed.<br> The value must be the same as that in **on('formUninstall')**.|

**Example**

```ts
import Base from '@ohos.base';

formHost.off('formUninstall', (formId: string) => {
  console.log(`formHost on formUninstall, formId: ${formId}`);
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
| isVisible | boolean | Yes  | Whether to make the widgets visible.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the notification is sent, **error** is undefined; otherwise, **error** is an error object.|

**Example**

```ts
import Base from '@ohos.base';

let formIds: string[]= new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsVisible(formIds, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsVisible(formIds, true).then(() => {
  console.log('formHost notifyFormsVisible success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`);
});
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

**Example**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsEnableUpdate(formIds, true, (error: Base.BusinessError) => {
  if (error.code) {
    console.error(`formHost notifyFormsEnableUpdate, error: ${JSON.stringify(error)}`);
  }
});
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

**Example**

```ts
import Base from '@ohos.base';

let formIds: string[] = new Array('12400633174999288', '12400633174999289');
formHost.notifyFormsEnableUpdate(formIds, true).then(() => {
  console.log('formHost notifyFormsEnableUpdate success');
}).catch((error: Base.BusinessError) => {
  console.error(`formHost notifyFormsEnableUpdate, error: ${JSON.stringify(error)}`);
});
```
