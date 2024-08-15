# @ohos.app.form.formBindingData (formBindingData)

The **FormBindingData** module provides APIs for widget data binding. You can use the APIs to create a **FormBindingData** object and obtain related information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { formBindingData } from '@kit.FormKit';
```


## ProxyData<sup>10+</sup>

Defines the subscription information about the widget update by proxy.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key<sup>10+</sup> | string | Yes | Subscriber ID of the widget update by proxy. The value is the same as that of the data publisher.|
| subscriberId<sup>10+</sup> | string | No | Subscription condition of the widget update by proxy. The default value is the current widget ID (specified by **formId**).|


## FormBindingData

Describes a **FormBindingData** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| data | Object | Yes | Data to be displayed on the widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|
| proxies<sup>10+</sup> | Array<[ProxyData](#proxydata10)> | No | Subscription information of the widget update by proxy. The default value is an empty array.<br>**Model restriction**: This API can be used only in the stage model.<br>|

## createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

Creates a **FormBindingData** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name | Type          | Mandatory | Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object\|string | No  | Data to be displayed on the widget. The value can be an object containing multiple key-value pairs or a string in JSON format. The image data is identified by **'formImages'**, and the content is multiple key-value pairs, each of which consists of an image identifier and image file descriptor. The final format is {'formImages': {'key1': fd1, 'key2': fd2}}.|


**Return value**

| Type                               | Description                                   |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | **FormBindingData** object created based on the passed data. |

**Error codes**

| ID | Error Message |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed |

For details about the error codes, see [Form Error Codes](errorcode-form.md).


**Example**

```ts
import { formBindingData } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

try {
  let file = fileIo.openSync('/path/to/form.png');
  let formImagesParam: Record<string, number> = {
    'image': file.fd
  };
  let createFormBindingDataParam: Record<string, string | Object> = {
    'name': '21°',
    'imgSrc': 'image',
    'formImages': formImagesParam
  };

  formBindingData.createFormBindingData(createFormBindingDataParam);
} catch (error) {
  let code = (error as BusinessError).code;
  let message = (error as BusinessError).message;
  console.error(`catch error, code: ${code}, message: ${message}`);
}
```
