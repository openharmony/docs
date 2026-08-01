# @ohos.app.form.formBindingData (formBindingData)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=63ea2217f398de4dc749a4e19504d46a64273860 translatedAt=2026-07-31T08:19:50.231Z pushedAt=2026-07-31T09:12:34.423Z -->

This module provides the widget data binding capability, supporting the creation of FormBindingData objects and the setting of widget display data. It is applicable to scenarios such as widget data update and image data transfer, helping you conveniently manage widget display content and improve the efficiency of widget data management.

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

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| key | string | No | No | Subscription identifier for the widget proxy update, which must be consistent with the data publisher. |
| subscriberId | string | No | Yes | Subscription condition for the widget proxy update, used to specify the message filtering condition for the subscription. After being set, it matches the corresponding widget proxy update message based on **subscriberId**. The default value is **formId** of the current widget. Pass this parameter when a specific subscription condition is required; otherwise, the default value is **formId** of the current widget. |

## FormBindingData

Defines the properties of the FormBindingData object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- |-------- | -------- |
| data | Object | No| No| Data to be displayed on the widget. The value can be an object containing multiple key-value pairs or a JSON string.|
| proxies<sup>10+</sup> | Array<[ProxyData](#proxydata10)> | No | Yes | Subscription information for widget proxy update. After being configured, subscribes to agent refresh messages. The default value is an empty array, indicating that no widget proxy update messages are subscribed to. Pass this parameter when the widget proxy update feature is needed. If not passed, the default value is an empty array (proxy update not used).<br>**Model restriction:** This API can be used only in the stage model.|

## formBindingData.createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

Creates a **FormBindingData** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type          | Mandatory| Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object \| string | No   | Data to be displayed on the widget, used to bind the content displayed on the form UI. This parameter is passed when data needs to be delivered to the widget. It can be an object containing several key-value pairs or a JSON string. If not passed, an empty FormBindingData object is created, and the widget displays the default content. Image data is identified by 'formImages', with the content being key-value pairs of image identifiers and image file descriptors `{'formImages': {'key1': fd1, 'key2': fd2}}`.<br>**Note:** During the [widget update](../../form/arkts-ui-widget-interaction-overview.md) process, when the widget UI receives widget data through [@LocalStorageProp](../../ui/state-management/arkts-localstorage.md#localstorageprop), the FormBindingData object is serialized, meaning the widget data is converted to the string type. Since API version 20, if the widget update data is updated through shared memory, the total update data size does not exceed 10 MB, and the number of update images does not exceed 20. For API version 19 and earlier, the maximum number of image files is 5, with each image limited to 2 MB of memory. Images exceeding the limit may display abnormally. |

**Return value**

| Type                               | Description                                   |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | FormBindingData object created based on the input data, which is used for widget data binding and provides the data to be displayed on the widget . |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

```ts
import { formBindingData } from '@kit.FormKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  content = this.getUIContext().getHostContext() as common.UIAbilityContext;
  pathDir: string = this.content.filesDir;

  createFormBindingData() {
    let filePath = this.pathDir + "/form.png";
    let fd: number = -1;
    try {
      fd = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY).fd;
      let formImagesParam: Record<string, number> = {
        'image': fd
      };
      let createFormBindingDataParam: Record<string, string | Record<string, number>> = {
        'name': '21°',
        'imgSrc': 'image',
        'formImages': formImagesParam
      };
      let formBindingDataObj = formBindingData.createFormBindingData(createFormBindingDataParam);
    } catch (error) {
      console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
    } finally {
      if (fd !== -1) {
        fileIo.closeSync(fd);
      }
    }
  }

  build() {
    Button('createFormBindingData')
      .onClick((event: ClickEvent) => {
        this.createFormBindingData();
      })
  }
}
```