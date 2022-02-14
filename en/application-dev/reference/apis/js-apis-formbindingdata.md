# FormBindingData

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
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

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | -------------- | ---- | ------------------------------------------------------------ |
  | obj    | Object or string| No| Data to be displayed on the JS service widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|



- Return value

  | Type| Description|
  | ----------------------------------- | --------------------------------------- |
  | [FormBindingData](#formbindingdata) | **FormBindingData** object created based on the passed data.|



- Example

  ```
  let obj = {"temperature": "21°"};
  let formBindingDataObj = formBindingData.createFormBindingData(obj);
  ```

## FormBindingData

Describes a **FormBindingData** object.

| Name| Type| Description|
| ---- | -------------- | ------------------------------------------------------------ |
| obj  | Object or string| Data to be displayed on the JS service widget. The value can be an object containing multiple key-value pairs or a string in JSON format.|
