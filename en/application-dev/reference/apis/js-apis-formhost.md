# FormHost

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides APIs related to the widget host.

## Modules to Import

```
import formHost from '@ohos.application.formHost';
```

## Required Permissions

ohos.permission.REQUIRE_FORM

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

## deleteForm

deleteForm(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Deletes a widget. This API uses an asynchronous callback to return the result. After this API is called, the application can no longer use the widget, and the Widget Manager will not retain the widget information.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.deleteForm(formId, (error, data) => {
      if (error) {
          console.log('formHost deleteForm, error:' + error.code);
      }
  });
  ```

## deleteForm

deleteForm(formId: string): Promise&lt;void&gt;;

Deletes a widget. This API uses a promise to return the result. After this API is called, the application can no longer use the widget, and the Widget Manager will not retain the widget information.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Parameters**

  ```js
  var formId = "12400633174999288";
  formHost.deleteForm(formId).catch((error) => {
      console.log('formProvider deleteForm, error:' + JSON.stringify(error));
  });
  ```

## releaseForm

releaseForm(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Releases a widget. This API uses an asynchronous callback to return the result. After this API is called, the application can no longer use the widget, but the Widget Manager still retains the widget cache and storage information.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.releaseForm(formId, (error, data) => {
      if (error) {
          console.log('formHost releaseForm, error:' + error.code);
      }
  });
  ```

## releaseForm

releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback&lt;void&gt;): void;

Releases a widget. This API uses an asynchronous callback to return the result. After this API is called, the application can no longer use the widget, but the Widget Manager retains the storage information about the widget and determines whether to retain the cache information based on the setting.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name        | Type    | Mandatory| Description       |
  | -------------- | ------  | ---- | ----------- |
  | formId         | string  | Yes  | ID of a widget.    |
  | isReleaseCache | boolean | Yes  | Whether to release the cache.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.releaseForm(formId, true, (error, data) => {
      if (error) {
          console.log('formHost releaseForm, error:' + error.code);
      }
  });
  ```

## releaseForm

releaseForm(formId: string, isReleaseCache?: boolean): Promise&lt;void&gt;;

Releases a widget. This API uses a promise to return the result. After this API is called, the application can no longer use the widget, but the Widget Manager retains the storage information about the widget and determines whether to retain the cache information based on the setting.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name        | Type    | Mandatory| Description       |
  | -------------- | ------  | ---- | ----------- |
  | formId         | string  | Yes  | ID of a widget.    |
  | isReleaseCache | boolean | No  | Whether to release the cache.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.releaseForm(formId, true).catch((error) => {
      console.log('formProvider releaseForm, error:' + JSON.stringify(error));
  });
  ```

## requestForm

requestForm(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Requests a widget update. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.requestForm(formId, (error, data) => {
      if (error) {
          console.log('formHost requestForm, error:' + error.code);
      }
  });
  ```

## requestForm

requestForm(formId: string): Promise&lt;void&gt;;

Requests a widget update. This API uses a promise to return the result.

**System capability**

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.requestForm(formId).catch((error) => {
      console.log('formProvider requestForm, error:' + JSON.stringify(error));
  });
  ```

## castTempForm

castTempForm(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Converts a temporary widget to a normal one. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.castTempForm(formId, (error, data) => {
      if (error) {
          console.log('formHost castTempForm, error:' + error.code);
      }
  });
  ```

## castTempForm

castTempForm(formId: string): Promise&lt;void&gt;;

Converts a temporary widget to a normal one. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.castTempForm(formId).catch((error) => {
      console.log('formProvider castTempForm, error:' + JSON.stringify(error));
  });
  ```

## notifyVisibleForms

notifyVisibleForms(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widget framework to make a widget visible. This API uses an asynchronous callback to return the result. After this API is called, **onVisibilityChange** is invoked to notify the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.notifyVisibleForms(formId, (error, data) => {
      if (error) {
          console.log('formHost notifyVisibleForms, error:' + error.code);
      }
  });
  ```

## notifyVisibleForms

notifyVisibleForms(formId: string): Promise&lt;void&gt;;

Instructs the widget framework to make a widget visible. This API uses a promise to return the result. After this API is called, **onVisibilityChange** is invoked to notify the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.notifyVisibleForms(formId).catch((error) => {
      console.log('formProvider notifyVisibleForms, error:' + JSON.stringify(error));
  });
  ```

## notifyInvisibleForms

notifyInvisibleForms(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widget framework to make a widget invisible. This API uses an asynchronous callback to return the result. After this API is called, **onVisibilityChange** is invoked to notify the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.notifyInvisibleForms(formId, (error, data) => {
      if (error) {
          console.log('formHost notifyInvisibleForms, error:' + error.code);
      }
  });
  ```

## notifyInvisibleForms

notifyInvisibleForms(formId: string): Promise&lt;void&gt;;

Instructs the widget framework to make a widget invisible. This API uses a promise to return the result. After this API is called, **onVisibilityChange** is invoked to notify the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.notifyInvisibleForms(formId).catch((error) => {
      console.log('formProvider notifyInvisibleForms, error:' + JSON.stringify(error));
  });
  ```

## enableFormsUpdate

enableFormsUpdate(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widget framework to make a widget to be updatable. This API uses an asynchronous callback to return the result. After this API is called, the widget is in the enabled state and can receive updates from the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.enableFormsUpdate(formId, (error, data) => {
      if (error) {
          console.log('formHost enableFormsUpdate, error:' + error.code);
      }
  });
  ```

## enableFormsUpdate

enableFormsUpdate(formId: string): Promise&lt;void&gt;;

Instructs the widget framework to make a widget to be updatable. This API uses a promise to return the result. After this API is called, the widget is in the enabled state and can receive updates from the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.enableFormsUpdate(formId).catch((error) => {
      console.log('formProvider enableFormsUpdate, error:' + JSON.stringify(error));
  });
  ```

## disableFormsUpdate

disableFormsUpdate(formId: string, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widget framework to make a widget not to be updatable. This API uses an asynchronous callback to return the result. After this API is called, the widget is in the disabled state and cannot receive updates from the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.disableFormsUpdate(formId, (error, data) => {
      if (error) {
          console.log('formHost disableFormsUpdate, error:' + error.code);
      }
  });
  ```

## disableFormsUpdate

disableFormsUpdate(formId: string): Promise&lt;void&gt;;

Instructs the widget framework to make a widget not to be updatable. This API uses a promise to return the result. After this API is called, the widget is in the disabled state and cannot receive updates from the widget provider.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formId | string | Yes  | ID of a widget.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.disableFormsUpdate(formId).catch((error) => {
      console.log('formProvider disableFormsUpdate, error:' + JSON.stringify(error));
  });
  ```

## isSystemReady

isSystemReady(callback: AsyncCallback&lt;void&gt;): void;

Checks whether the system is ready. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.isSystemReady((error, data) => {
      if (error) {
          console.log('formHost isSystemReady, error:' + error.code);
      }
  });
  ```

## isSystemReady

isSystemReady(): Promise&lt;void&gt;;

Checks whether the system is ready. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formId = "12400633174999288";
  formHost.isSystemReady().catch((error) => {
      console.log('formProvider isSystemReady, error:' + JSON.stringify(error));
  });
  ```

## getAllFormsInfo

getAllFormsInfo(callback: AsyncCallback&lt;Array&lt;FormInfo&gt;&gt;): void;

Obtains the widget information provided by all applications on the device. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | Yes| Callback used to return the widget information.|

**Example**

  ```js
  formHost.getAllFormsInfo((error, data) => {
      if (error) {
          console.log('formHost getAllFormsInfo, error:' + error.code);
      }
  });
  ```

## getAllFormsInfo

getAllFormsInfo(): Promise&lt;Array&lt;FormInfo&gt;&gt;;

Obtains the widget information provided by all applications on the device. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | Promise used to return the widget information.|

**Example**

  ```js
  formHost.getAllFormsInfo().catch((error) => {
      console.log('formProvider getAllFormsInfo, error:' + JSON.stringify(error));
  });
  ```

## getFormsInfo

getFormsInfo(bundleName: string, callback: AsyncCallback&lt;Array&lt;FormInfo&gt;&gt;): void;

Obtains the widget information provided by a given application on the device. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | bundleName | string | Yes|  Bundle name of the target application.|
  | callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | Yes| Callback used to return the widget information.|

**Example**

  ```js
  formHost.getFormsInfo("com.example.ohos.accountjsdemo", (error, data) => {
      if (error) {
          console.log('formHost getFormsInfo, error:' + error.code);
      }
  });
  ```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;FormInfo&gt;&gt;): void;

Obtains the widget information provided by a given application on the device. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | bundleName | string | Yes|  Bundle name of the target application.|
  | moduleName | string | Yes|  Module name.|
  | callback | AsyncCallback&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | Yes| Callback used to return the widget information.|

**Example**

  ```js
  formHost.getFormsInfo("com.example.ohos.accountjsdemo", (error, data) => {
      if (error) {
          console.log('formHost getFormsInfo, error:' + error.code);
      }
  });
  ```

## getFormsInfo

getFormsInfo(bundleName: string, moduleName?: string): Promise&lt;Array&lt;FormInfo&gt;&gt;;

Obtains the widget information provided by a given application on the device. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | bundleName | string | Yes|  Bundle name of the target application.|
  | moduleName | string | No|  Module name.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[FormInfo](./js-apis-formInfo.md#forminfo-1)&gt;&gt; | Promise used to return the widget information.|

**Example**

  ```js
  formHost.getAllFormsInfo().catch((error) => {
      console.log('formProvider getAllFormsInfo, error:' + JSON.stringify(error));
  });
  ```

## deleteInvalidForms

deleteInvalidForms(formIds: Array&lt;string&gt;, callback: AsyncCallback&lt;number&gt;): void;

Deletes invalid widgets from the list. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of widgets deleted.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.deleteInvalidForms(formIds, (error, data) => {
      if (error) {
          console.log('formHost deleteInvalidForms, error:' + error.code);
      }
  });
  ```

## deleteInvalidForms

function deleteInvalidForms(formIds: Array&ltstring&gt): Promise&lt;number&gt;;

Deletes invalid widgets from the list. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of widgets deleted.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.deleteInvalidForms(formIds).catch((error) => {
      console.log('formProvider deleteInvalidForms, error:' + JSON.stringify(error));
  });
  ```

## acquireFormState

acquireFormState(want: Want, callback: AsyncCallback&lt;FormStateInfo&gt;): void;

Obtains the widget state. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| want | [Want](js-apis-featureAbility.md#want) | Yes  | **Want** information carried to query the widget state.|
| callback | AsyncCallback&lt;[FormStateInfo](js-apis-formInfo.md#formstateinfo)&gt; | Yes| Callback used to return the widget state.|

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  formHost.acquireFormState(want, (error, data) => {
      if (error) {
          console.log('formHost acquireFormState, error:' + error.code);
      }
  });
  ```

## acquireFormState

function acquireFormState(want: Want): Promise&lt;FormStateInfo&gt;;

Obtains the widget state. This API uses a promise to return the result.

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[FormStateInfo](js-apis-formInfo.md#formstateinfo)&gt; | Promise used to return the widget state.|

**System capability**:

SystemCapability.Ability.Form

**Example**

  ```js
  var want = {
  	"deviceId": "",
  	"bundleName": "com.extreme.test",
  	"abilityName": "com.extreme.test.MainAbility"
  };
  formHost.acquireFormState(want).catch((error) => {
      console.log('formProvider acquireFormState, error:' + JSON.stringify(error));
  });
  ```

## on("formUninstall")

on(type: "formUninstall", callback: Callback&lt;string&gt;): void;

Subscribes to widget uninstall events.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | type | string | Yes  | Type of event to subscribe to. The value **formUninstall** indicates a widget uninstallation event.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  formHost.on("formUninstall", (error, data) => {
      if (error) {
          console.log('formHost on formUninstall, error:' + error.code);
      }
  });
  ```

## off("formUninstall")

off(type: "formUninstall", callback: Callback&lt;string&gt;): void;

Unsubscribes from widget uninstall events.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | type | string | Yes  | Type of event to unsubscribe from. The value **formUninstall** indicates a widget uninstallation event.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  formHost.off("formUninstall", (error, data) => {
      if (error) {
          console.log('formHost off formUninstall, error:' + error.code);
      }
  });
  ```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widgets to make themselves visible. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
  | isVisible | boolean | Yes  | Whether to be visible.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.notifyFormsVisible(formIds, true, (error, data) => {
      if (error) {
          console.log('formHost notifyFormsVisible, error:' + error.code);
      }
  });
  ```

## notifyFormsVisible

notifyFormsVisible(formIds: Array&lt;string&gt;, isVisible: boolean): Promise&lt;void&gt;;

Instructs the widgets to make themselves visible. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
  | isVisible | boolean | Yes  | Whether to be visible.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.notifyFormsVisible(formIds, true).catch((error) => {
      console.log('formProvider notifyFormsVisible, error:' + JSON.stringify(error));
  });
  ```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean, callback: AsyncCallback&lt;void&gt;): void;

Instructs the widgets to enable or disable update. This API uses an asynchronous callback to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
  | isEnableUpdate | boolean | Yes  | Whether to enable update.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.notifyFormsEnableUpdate(formIds, true, (error, data) => {
      if (error) {
          console.log('formHost notifyFormsEnableUpdate, error:' + error.code);
      }
  });
  ```

## notifyFormsEnableUpdate

notifyFormsEnableUpdate(formIds: Array&lt;string&gt;, isEnableUpdate: boolean): Promise&lt;void&gt;;

Instructs the widgets to enable or disable update. This API uses a promise to return the result.

**System capability**:

SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description   |
  | ------ | ------ | ---- | ------- |
  | formIds | Array&lt;string&gt; | Yes  | List of widget IDs.|
  | isEnableUpdate | boolean | Yes  | Whether to enable update.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result indicating whether the API is successfully called.|

**Example**

  ```js
  var formIds = new Array("12400633174999288", "12400633174999289");
  formHost.notifyFormsEnableUpdate(formIds, true).catch((error) => {
      console.log('formProvider notifyFormsEnableUpdate, error:' + JSON.stringify(error));
  });
  ```
