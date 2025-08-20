# @ohos.app.form.formObserver (formObserver) (System API)

The **formObserver** module provides APIs related to widget listeners. You can use the APIs to subscribe to and unsubscribe from widget addition, removal, and visibility change events, and obtain information about running widgets.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { formObserver } from '@kit.FormKit';
```

## on('formAdd')

 on(type: 'formAdd', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget addition events. This API uses an asynchronous callback to return the information about the new widget.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formAdd'** indicates a widget addition event.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to return the information about the new widget.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
}

formObserver.on('formAdd', callback);
```

## on('formAdd')

 on(type: 'formAdd', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget addition events. This API uses an asynchronous callback to return the information about the new widget.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formAdd'** indicates a widget addition event.|
| hostBundleName | string | Yes| Name of the bundle that functions as the widget host. If no value is passed in, widget addition events of all widget hosts are subscribed to.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to return the information about the new widget.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
}

formObserver.on('formAdd', bundleName, callback);
```

## off('formAdd')

 off(type: "formAdd", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

Unsubscribes from widget addition events. This API uses an asynchronous callback to return the information about the new widget.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formAdd'** indicates a widget addition event.|
| hostBundleName | string | No| Name of the bundle that functions as the widget host.<br> To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('formAdd')**.<br> If no value is passed in, the subscriptions for all the widget hosts are canceled.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | No| Callback used to return the information about the new widget. If no value is passed in, all the subscriptions to the specified event are canceled.<br> To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formAdd')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
}

formObserver.off('formAdd', bundleName, callback);

```
> **NOTE**
>
> **on('formAdd', callback)** and **off('formAdd', callback)** must be used in pairs.
> **on('formAdd', bundleName, callback)** and **off('formAdd', bundleName, callback)** must be used in pairs.
> To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.

## on('formRemove')

 on(type: 'formRemove', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget removal events. This API uses an asynchronous callback to return the information about the widget removed.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formRemove'** indicates a widget removal event.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to return the information about the widget removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`form deleted, data: ${JSON.stringify(data)}`);
}

formObserver.on('formRemove', callback);
```

## on('formRemove')

 on(type: 'formRemove', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget removal events. This API uses an asynchronous callback to return the information about the widget removed.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formRemove'** indicates a widget removal event.|
| hostBundleName | string | Yes| Name of the bundle that functions as the widget host. If no value is passed in, widget removal events of all widget hosts are subscribed to.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to return the information about the widget removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`form deleted, data: ${JSON.stringify(data)}`);
}

formObserver.on('formRemove', bundleName, callback);
```

## off('formRemove')

off(type: "formRemove", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

Unsubscribes from widget removal events. This API uses an asynchronous callback to return the information about the widget removed.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| type | string | Yes  | Event type. The value **'formRemove'** indicates a widget removal event.|
| hostBundleName | string | No| Name of the bundle that functions as the widget host.<br> To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('formRemove')**.<br> If no value is passed in, the subscriptions for all the widget hosts are canceled.|
| observerCallback | Callback&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | No| Callback used to return the information about the widget removed. If no value is passed in, all the subscriptions to the specified event are canceled.<br> To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('formRemove')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log(`a new form added, data: ${JSON.stringify(data)}`);
}

formObserver.off('formRemove', bundleName, callback);
```
> **NOTE**
>
> **on('formRemove', callback)** and **off('formRemove', callback)** must be used in pairs.
> **on('formRemove', bundleName, callback)** and **off('formRemove', bundleName, callback)** must be used in pairs.
> To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.

## on('notifyVisible')

 on(type: 'notifyVisible', observerCallback: Callback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

Subscribes to events indicating that a widget becomes visible. This API uses an asynchronous callback to return the result.

​The event is triggered when [notifyVisibleForms](js-apis-app-form-formHost-sys.md#notifyvisibleforms) is called to notify that the widget becomes visible.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyVisible'** indicates a widget visibility event.     |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes  | Callback used to return an array of widgets that have subscribed to the event.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
}

formObserver.on('notifyVisible', callback);

```

## on('notifyVisible')

 on(type: 'notifyVisible', hostBundleName: string, observerCallback: Callback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

Subscribes to events indicating that a widget becomes visible. This API uses an asynchronous callback to return the result.

​The event is triggered when [notifyVisibleForms](js-apis-app-form-formHost-sys.md#notifyvisibleforms) is called to notify that the widget becomes visible.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyVisible'** indicates a widget visibility event.     |
| hostBundleName | string                                                       | Yes  | Name of the bundle that functions as the widget host, on which the widget visibility state changes are subscribed.|
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes  | Callback used to return an array of widgets that have subscribed to the event.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |


**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
}

formObserver.on('notifyVisible', bundleName, callback);
```

## off('notifyVisible')

 off(type: "notifyVisible", hostBundleName?: string, observerCallback?: Callback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

Unsubscribes from events indicating that a widget becomes visible. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyVisible'** indicates a widget visibility event.|
| hostBundleName | string                                                       | No  | Name of the bundle that functions as the widget host, on which the widget visibility state changes are subscribed.<br> To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('notifyVisible')**.|
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | No  | Callback used to return an array of widgets that have unsubscribed from the event. If no value is passed in, all the subscriptions to the specified event are canceled.<br> To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('notifyVisible')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change visibility, data: ${JSON.stringify(data)}`);
}

formObserver.off('notifyVisible', bundleName, callback);
```

> **NOTE**
>
> **on('notifyVisible', callback)** and **off('notifyVisible', callback)** must be used in pairs.
> **on('notifyVisible', bundleName, callback)** and **off('notifyVisible', bundleName, callback)** must be used in pairs.
> To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.

## on('notifyInvisible')

 on(type: 'notifyInvisible', observerCallback: Callback&lt;Array&lt;formInfo.RunningFormInfo&gt;>): void

Subscribes to events indicating that a widget becomes invisible. This API uses an asynchronous callback to return the result.

​The event is triggered when [notifyInvisibleForms](js-apis-app-form-formHost-sys.md#notifyinvisibleforms) is called to notify that the widget becomes invisible.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyInvisible'** indicates a widget invisibility event.     |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes  | Callback used to return an array of widgets that have subscribed to the event.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
}

formObserver.on('notifyInvisible', callback);
```


## on('notifyInvisible')

 on(type: 'notifyInvisible', hostBundleName: string, observerCallback: Callback&lt;Array&lt;formInfo.RunningFormInfo&gt;>): void

Subscribes to events indicating that a widget becomes invisible. This API uses an asynchronous callback to return the result.

​The event is triggered when [notifyInvisibleForms](js-apis-app-form-formHost-sys.md#notifyinvisibleforms) is called to notify that the widget becomes invisible.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyInvisible'** indicates a widget invisibility event.     |
| hostBundleName | string                                                       | Yes  | Name of the bundle that functions as the widget host, on which the widget visibility state changes are subscribed.|
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes  | Callback used to return an array of widgets that have subscribed to the event.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
}

formObserver.on('notifyInvisible', bundleName, callback);
```

## off('notifyInvisible')

 off(type: "notifyInvisible", hostBundleName?: string, observerCallback?: Callback&lt;Array&lt;formInfo.RunningFormInfo>&gt;): void

Unsubscribes from events indicating that a widget becomes invisible. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type       | string                                                       | Yes  | Event type. This value **'notifyInvisible'** indicates a widget invisibility event.   |
| hostBundleName | string                                                       | No  | Name of the bundle that functions as the widget host, on which the widget visibility state changes are subscribed.<br> To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('notifyVisible')**.<br> |
| observerCallback   | Callback &lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | No  | Callback used to return an array of widgets that have unsubscribed from the event. If no value is passed in, all the subscriptions to the specified event are canceled.<br> To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('notifyInvisible')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let bundleName: string = 'ohos.samples.FormApplication';

let callback = (data: formInfo.RunningFormInfo[]) => {
  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);
}

formObserver.off('notifyInvisible', bundleName, callback);
```

> **NOTE**
>
> **on('notifyInvisible', callback)** and **off('notifyInvisible', callback)** must be used in pairs.
> **on('notifyInvisible', bundleName, callback)** and **off('notifyInvisible', bundleName, callback)** must be used in pairs.
> To cancel the subscription with a given callback or for a given bundle name, the **callback** or **bundleName** parameter in **off()** must be set to the same value as that in **on()**.


## getRunningFormInfos

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, hostBundleName?: string): void

Obtains the information about all non-temporary widgets running on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes| Callback used to return the information about all non-temporary widgets. If the widget information is obtained, **error** is **undefined**, and **data** is the information obtained.|
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If a value is passed in, only the information about the non-temporary widgets that are running under the widget host is returned.<br> If no value is passed in, information about all running non-temporary widgets on the device is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formObserver.getRunningFormInfos((error: BusinessError, data: formInfo.RunningFormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
    }
  }, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfos<sup>11+</sup>

getRunningFormInfos(callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;, isUnusedIncluded: boolean, hostBundleName?: string): void

Obtains the information about all non-temporary widgets running on the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| callback | AsyncCallback&lt;Array&lt;formInfo.[RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes|  Callback used to return the information about all non-temporary widgets. If the widget information is obtained, **error** is **undefined**, and **data** is the information obtained.|
| isUnusedIncluded | boolean | Yes|  Whether the unused widget is included.<br>**true**: The unused widget is included.<br>**false**: The unused widget is not included.|
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If a value is passed in, only the information about the non-temporary widgets that are running under the widget host is returned.<br> If no value is passed in, information about all running non-temporary widgets on the device is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formObserver.getRunningFormInfos((error: BusinessError, data: formInfo.RunningFormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
    }
  }, true, 'com.example.ohos.formjsdemo');
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfos

getRunningFormInfos(hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains the information about all non-temporary widgets running on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If a value is passed in, only the information about the non-temporary widgets that are running under the widget host is returned.<br> If no value is passed in, information about all running non-temporary widgets on the device is returned.|

**Return value**

| Type                                                        | Description                               |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Promise used to return the information about all non-temporary widgets.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formObserver.getRunningFormInfos('com.example.ohos.formjsdemo').then((data: formInfo.RunningFormInfo[]) => {
    console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfos<sup>11+</sup>

getRunningFormInfos(isUnusedIncluded: boolean, hostBundleName?: string):  Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains the information about all non-temporary widgets running on the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type   | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| isUnusedIncluded | boolean | Yes|  Whether the unused widget is included.<br>**true**: The unused widget is included.<br>**false**: The unused widget is not included.|
| hostBundleName | string | No|  Name of the bundle that functions as the widget host. If a value is passed in, only the information about the non-temporary widgets that are running under the widget host is returned.<br> If no value is passed in, information about all running non-temporary widgets on the device is returned.|

**Return value**

| Type                                                        | Description                               |
| :----------------------------------------------------------- | :---------------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Promise used to return the information about all non-temporary widgets.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                                          |
| 202      | The application is not a system application.                                    |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error.                            |
| 16500060 | Service connection error. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  formObserver.getRunningFormInfos(true, 'com.example.ohos.formjsdemo').then((data: formInfo.RunningFormInfo[]) => {
    console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfosByFilter

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter): Promise&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;

Obtains the information about widgets based on the widget provider. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | [formInfo.FormProviderFilter](js-apis-app-form-formInfo-sys.md#formproviderfilter10) | Yes  | Information about the widget provider.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Promise used to return an array of the widgets.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |


```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formInstanceFilter: formInfo.FormProviderFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formObserver.getRunningFormInfosByFilter(formInstanceFilter).then((data: formInfo.RunningFormInfo[]) => {
    console.info('formObserver getRunningFormInfosByFilter success, data:' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfosByFilter

getRunningFormInfosByFilter(formProviderFilter: formInfo.FormProviderFilter, callback: AsyncCallback&lt;Array&lt;formInfo.RunningFormInfo&gt;&gt;): void

Obtains the information about widgets based on the widget provider. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formProviderFilter     | [formInfo.FormProviderFilter](js-apis-app-form-formInfo-sys.md#formproviderfilter10) | Yes  | Information about the widget provider.|
| callback | AsyncCallback&lt;Array&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt;&gt; | Yes| Callback used to used to return an array of the widgets. If the widget information is obtained, **error** is **undefined**, and **data** is the information obtained. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formInstanceFilter: formInfo.FormProviderFilter = {
  bundleName: "com.example.formprovide",
  abilityName: "EntryFormAbility",
  formName: "widget",
  moduleName: "entry"
}
try {
  formObserver.getRunningFormInfosByFilter(formInstanceFilter,(error: BusinessError, data: formInfo.RunningFormInfo[]) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfosByFilter, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfoById

getRunningFormInfoById(formId: string): Promise&lt;formInfo.RunningFormInfo&gt;

Obtains the information about the widget based on the widget ID. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Promise used to return the widget information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId).then((data: formInfo.RunningFormInfo) => {
    console.info('formObserver getRunningFormInfoById success, data:' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfoById<sup>11+</sup>

getRunningFormInfoById(formId: string, isUnusedIncluded: boolean): Promise&lt;formInfo.RunningFormInfo&gt;

Obtains the information about the widget based on the widget ID. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|
| isUnusedIncluded     | boolean | Yes  | Whether the unused widget is included.<br>**true**: The unused widget is included.<br>**false**: The unused widget is not included.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Promise used to return the widget information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                             |
| 202      | The application is not a system application.                       |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId, true).then((data: formInfo.RunningFormInfo) => {
    console.info('formObserver getRunningFormInfoById success, data:' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    console.error(`error, code: ${error.code}, message: ${error.message}`);
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfoById

getRunningFormInfoById(formId: string, callback: AsyncCallback&lt;formInfo.RunningFormInfo&gt;): void

Obtains the information about the widget based on the widget ID. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|
| callback | AsyncCallback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to used to return the widget information. If the widget information is obtained, **error** is **undefined**, and **data** is the information obtained. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permissions denied. |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId,(error: BusinessError, data: formInfo.RunningFormInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfoById, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## getRunningFormInfoById<sup>11+</sup>

getRunningFormInfoById(formId: string, isUnusedIncluded: boolean, callback: AsyncCallback&lt;formInfo.RunningFormInfo&gt;): void

Obtains the information about the widget based on the widget ID. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name     | Type           | Mandatory| Description                            |
| ----------- | --------------- | ---- | -------------------------------- |
| formId     | string | Yes  | Widget ID.|
| isUnusedIncluded     | boolean | Yes  | Whether the unused widget is included.<br>**true**: The unused widget is included.<br>**false**: The unused widget is not included.|
| callback | AsyncCallback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes| Callback used to used to return the widget information. If the widget information is obtained, **error** is **undefined**, and **data** is the information obtained. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Form Error Codes](errorcode-form.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permissions denied.                             |
| 202      | The application is not a system application.                       |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | IPC connection error. |
| 16500100 | Failed to obtain the configuration information. |
| 16501000  | An internal functional error occurred. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

let formId: string = '12400633174999288';
try {
  formObserver.getRunningFormInfoById(formId, true, (error: BusinessError, data: formInfo.RunningFormInfo) => {
    if (error) {
      console.error(`error, code: ${error.code}, message: ${error.message}`);
    } else {
      console.log(`formObserver getRunningFormInfoById, data: ${JSON.stringify(data)}`);
    }
  });
} catch(error) {
  console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## on('router')<sup>11+</sup>

 on(type: 'router', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget router events. This API uses an asynchronous callback to return the information of the widget that triggers the router event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                     |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | Yes  | Event type. The value **'router'** indicates a widget router event.         |
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Router event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('router', callback);
```

## on('router')<sup>11+</sup>

 on(type: 'router', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget router events for a given bundle that functions as the widget host. This API uses an asynchronous callback to return the information of the widget that triggers the router event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. The value **'router'** indicates a widget router event.                            |
| hostBundleName   | string                                   | Yes  | Name of the bundle that functions as the widget host. If no value is passed in, widget router events of all widget hosts are subscribed to.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Router event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('router', hostBundleName, callback);
```

## off('router')<sup>11+</sup>

 off(type: "router", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

Unsubscribes from widget router events. This API uses an asynchronous callback to return the information of the widget that triggers the router event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. The value **'router'** indicates a widget router event.                            |
| hostBundleName   | string                                   | No  | Name of the bundle that functions as the widget host.<br>To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('router')**.<br>If no value is passed in, the subscriptions for all the widget hosts are canceled.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | No  | Callback used to return the widget information. If no value is passed in, all the subscriptions to the specified event are canceled.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('router')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form router event Listening.' + JSON.stringify(data));
};
formObserver.off('router', hostBundleName, callback);
```

## on('message')<sup>11+</sup>

 on(type: 'message', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget message events. This API uses an asynchronous callback to return the information of the widget that triggers the message event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                     |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | Yes  | Event type. This value **'message'** indicates a widget message event.        |
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Message event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('message', callback);
```

## on('message')<sup>11+</sup>

 on(type: 'message', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget message events for a given bundle that functions as the widget host. This API uses an asynchronous callback to return the information of the widget that triggers the message event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. This value **'message'** indicates a widget message event.                           |
| hostBundleName   | string                                   | Yes  | Name of the bundle that functions as the widget host. If no value is passed in, widget message events of all widget hosts are subscribed to.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Message event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('message', hostBundleName, callback);
```

## off('message')<sup>11+</sup>

 off(type: "message", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

Unsubscribes from widget message events. This API uses an asynchronous callback to return the information of the widget that triggers the message event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. This value **'message'** indicates a widget message event.                        |
| hostBundleName   | string                                   | No  | Name of the bundle that functions as the widget host.<br>To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('message')**.<br>If no value is passed in, the subscriptions for all the widget hosts are canceled.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | No  | Callback used to return the widget information. If no value is passed in, all the subscriptions to the specified event are canceled.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('message')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form Message event Listening.' + JSON.stringify(data));
};
formObserver.off('message', hostBundleName, callback);
```

## on('call')<sup>11+</sup>

 on(type: 'call', observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget call events. This API uses an asynchronous callback to return the information of the widget that triggers the call event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                     |
| ---------------- | ---------------------------------------- | ---- | ----------------------------------------- |
| type             | string                                   | Yes  | Event type. This value **'call'** indicates a widget call event.           |
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Call event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('call', callback);
```

## on('call')<sup>11+</sup>

 on(type: 'call', hostBundleName: string, observerCallback: Callback&lt;formInfo.RunningFormInfo&gt;): void

Subscribes to widget call events for a given bundle that functions as the widget host. This API uses an asynchronous callback to return the information of the widget that triggers the call event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. This value **'call'** indicates a widget call event.                              |
| hostBundleName   | string                                   | Yes  | Name of the bundle that functions as the widget host. If no value is passed in, widget call events of all widget hosts are subscribed to.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | Yes  | Callback used to return the widget information.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Call event listening in registered form.' + JSON.stringify(data));
};
formObserver.on('call', hostBundleName, callback);
```

## off('call')<sup>11+</sup>

 off(type: "call", hostBundleName?: string, observerCallback?: Callback&lt;formInfo.RunningFormInfo&gt;): void

Unsubscribes from widget call events. This API uses an asynchronous callback to return the information of the widget that triggers the call event.

**Required permissions**: ohos.permission.OBSERVE_FORM_RUNNING

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name          | Type                                    | Mandatory| Description                                                        |
| ---------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| type             | string                                   | Yes  | Event type. This value **'call'** indicates a widget call event.                          |
| hostBundleName   | string                                   | No  | Name of the bundle that functions as the widget host.<br>To cancel the subscription for a given bundle name, this parameter must be set to the same value as **bundleName** in **on('call')**.<br>If no value is passed in, the subscriptions for all the widget hosts are canceled.|
| observerCallback | Callback&lt;[formInfo.RunningFormInfo](js-apis-app-form-formInfo-sys.md#runningforminfo10)&gt; | No  | Callback used to return the widget information. If no value is passed in, all the subscriptions to the specified event are canceled.<br>To cancel the subscription with a given callback, this parameter must be set to the same value as **callback** in **on('call')**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formInfo, formObserver } from '@kit.FormKit';

let hostBundleName: string = 'ohos.samples.FormApplication';
let callback = (data: formInfo.RunningFormInfo) => {
  console.log('Unregister form Call event Listening.' + JSON.stringify(data));
};
formObserver.off('call', hostBundleName, callback);
```
