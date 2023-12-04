# @ohos.app.form.formBindingData (formBindingData)

The **FormBindingData** module provides APIs for widget data binding. You can use the APIs to create a **FormBindingData** object and obtain related information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import formBindingData from '@ohos.app.form.formBindingData';
```


## ProxyData<sup>10+</sup>

Defines the subscription information about the widget update by proxy.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key<sup>10+</sup> | string | Yes| Subscriber ID of the widget update by proxy. The value is the same as that of the data publisher.|
| subscriberId<sup>10+</sup> | string | No| Subscription condition of the widget update by proxy. The default value is the current widget ID (specified by **formId**).|


## FormBindingData

Describes a **FormBindingData** object.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | Object | Yes| Data to be displayed on the JS widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|
| proxies<sup>10+</sup> | Array<[proxyData](#proxydata10)> | No| Subscription information of the widget update by proxy. The default value is an empty array.<br>**Model restriction**: This API can be used only in the stage model.<br>|

## createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

Creates a **FormBindingData** object.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type          | Mandatory| Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object\|string | No  | Data to be displayed on the JS widget. The value can be an object containing multiple key-value pairs or a string in JSON format. The image data is identified by **'formImages'**, and the content is multiple key-value pairs, each of which consists of an image identifier and image file descriptor. The final format is {'formImages': {'key1': fd1, 'key2': fd2}}.|


**Return value**

| Type                               | Description                                   |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | **FormBindingData** object created based on the passed data.|


**Example**

```ts
import formBindingData from '@ohos.app.form.formBindingData';
import fs from '@ohos.file.fs';
import Base from '@ohos.base';

try {
  let fd = fs.openSync('/path/to/form.png');

  let createFormBindingDataParam = new Map<string, string | Object>();
  let formImagesParam = new Map<string, Object>();
  formImagesParam.set('image', fd);
  createFormBindingDataParam.set("name", '21°');
  createFormBindingDataParam.set('formImages', formImagesParam);

  formBindingData.createFormBindingData(createFormBindingDataParam);
} catch (error) {
  let code = (error as Base.BusinessError).code;
  let message = (error as Base.BusinessError).message;
  console.error(`catch error, code: ${code}, message: ${message}`);
}
```
