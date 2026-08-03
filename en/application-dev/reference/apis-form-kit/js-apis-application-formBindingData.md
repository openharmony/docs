# @ohos.application.formBindingData (formBindingData)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=e51968c7c56d4fd4ec628eff339eeb09ceb3837b translatedAt=2026-07-31T08:23:24.651Z pushedAt=2026-08-01T00:25:05.859Z -->

The **FormBindingData** module provides APIs for widget data binding. You can use the APIs to create a **FormBindingData** object and obtain related information.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is deprecated since API version 9. You are advised to use [formBindingData](js-apis-app-form-formBindingData.md) instead.

## Modules to Import

```ts
import { formBindingData } from '@kit.FormKit';
```

## FormBindingData

Provides the widget data binding capability. It is used to store the data to be displayed on the widget.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- |-------- | -------- | -------- |
| data | Object | No | No | Data to be displayed on the JS widget. It can be an object containing several key-value pairs or a string in JSON format. |

## formBindingData.createFormBindingData

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