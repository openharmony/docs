# DataUriUtils Module

## Modules to Import

```js
import dataUriUtils from '@ohos.ability.dataUriUtils';
```

## DataUriUtils.getId

- Functionality

  Obtains the ID attached to the end of a given URI.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ------ | ---- | ------------------------- |
| uri  | Read-only| string | Yes| URI object from which the ID is to be obtained.|

- Return values

  Returns the ID obtained from the URI object.

- Example

```js
import dataUriUtils from '@ohos.ability.datauriutils'
dataUriUtils.getIdSync("com.example.dataUriUtils/1221")
```



## DataUriUtils.attachId

- Functionality

  Attaches an ID to the end of a given URI.

- Parameters


| Name| Readable/Writable| Type| Mandatory| Description|
| ---- | -------- | ------ | ---- | ------------------------- |
| uri  | Read-only| string | Yes| URI object to which an ID is to be attached.|
| id   | Read-only| number | Yes| ID to be attached.|

- Return values

  Returns the URI object with the ID attached.

- Example

```js
import dataUriUtils from '@ohos.ability.datauriutils'
var idint = 1122;
dataUriUtils.attachId(
    "com.example.dataUriUtils"
	idint,
)
```



## DataUriUtils.deleteId

- Functionality

  Deletes the ID from the end of a given URI.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ------------------------- |
  | uri  | Read-only| string | Yes| URI object from which the ID is to be deleted.|

- Return values

  Returns the URI object with the ID deleted.

- Example

```js
import dataUriUtils from '@ohos.ability.datauriutils'
dataUriUtils.deleteId("com.example.dataUriUtils/1221")
```



## DataUriUtils.updateId

- Functionality

  Updates the ID in a given URI.

- Parameters

  | Name| Readable/Writable| Type| Mandatory| Description|
  | ---- | -------- | ------ | ---- | ------------------- |
  | uri  | Read-only| string | Yes| URI object to be updated.|
  | id   | Read-only| number | Yes| New ID.|

- Return values

  Returns the URI object with the new ID.

- Example

```js
import dataUriUtils from '@ohos.ability.datauriutils'
var idint = 1122;
dataUriUtils.updateId(
    "com.example.dataUriUtils"
	idint,
)
```
