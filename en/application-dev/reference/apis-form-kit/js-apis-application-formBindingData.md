# @ohos.application.formBindingData (formBindingData)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->
The **FormBindingData** module provides APIs for widget data binding. You can use the APIs to create a **FormBindingData** object and obtain related information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module is deprecated since API version 9. You are advised to use [formBindingData](js-apis-app-form-formBindingData.md) instead.
## Modules to Import

```ts
import formBindingData from '@ohos.application.formBindingData';
```

## FormBindingData

Describes a **FormBindingData** object.

**System capability**: SystemCapability.Ability.Form

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | Object | Yes| Data to be displayed on the JS widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|


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
    try {
      let filePath = this.pathDir + "/form.png";
      let file = fileIo.openSync(filePath);
      let formImagesParam: Record<string, number> = {
        'image': file.fd
      };
      let createFormBindingDataParam: Record<string, string | Record<string, number>> = {
        'name': '21°',
        'imgSrc': 'image',
        'formImages': formImagesParam
      };
      formBindingData.createFormBindingData(createFormBindingDataParam);
    } catch (error) {
      console.error(`catch error, error: ${JSON.stringify(error)}`);
    }
  }
  build() {
    Button('createFormBindingData')
      .onClick((event: ClickEvent)=>{
        this.createFormBindingData();
      })
  }
}
```
