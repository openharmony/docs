# FormBindingData

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import formBindingData from '@ohos.application.formBindingData';
```

## Required Permissions

None

## formBindingData.createFormBindingData

createFormBindingData(obj?: Object | string): FormBindingData

Creates a **FormBindingData** object.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name| Type          | Mandatory| Description                                                        |
| ------ | -------------- | ---- | ------------------------------------------------------------ |
| obj    | Object or string| No  | Data to be displayed on the JS service widget. The value can be an object containing multiple key-value pairs or a string in JSON format. The image data is identified by "formImages", and the content is multiple key-value pairs, each of which consists of an image identifier and image file descriptor. The final format is {"formImages": {"key1": fd1, "key2": fd2}}.|


**Return value**

| Type                               | Description                                   |
| ----------------------------------- | --------------------------------------- |
| [FormBindingData](#formbindingdata) | **FormBindingData** object created based on the passed data.|


**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  import fileio from '@ohos.fileio';
  let context=featureAbility.getContext();
  context.getOrCreateLocalDir((err,data)=>{
      let path=data+"/xxx.jpg";
      let fd = fileio.openSync(path);
      let obj = {
          "temperature": "21°",
          "formImages": {"image": fd}
      };
      let formBindingDataObj = formBindingData.createFormBindingData(obj);
  })

  
  ```

## Attributes

Describes a **FormBindingData** object.

**System capability**: SystemCapability.Ability.Form

| Name| Readable| Writable| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- | -------- |
| data | Yes| No| Object | Yes| Data to be displayed on the JS service widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|
