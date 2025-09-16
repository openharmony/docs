# @ohos.ability.dataUriUtils (DataUriUtils)
<!--deprecated_code_no_check-->

The DataUriUtils module provides APIs to process URI objects. You can use the APIs to attach an ID to the end of a given URI and obtain, delete, or update the ID attached to the end of a given URI.

> **NOTE**
> 
> The APIs of this module are supported since API version 7 and deprecated since API version 9. You are advised to use [@ohos.app.ability.dataUriUtils](js-apis-app-ability-dataUriUtils.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import dataUriUtils from '@ohos.ability.dataUriUtils';
```

## dataUriUtils.getId

getId(uri: string): number

Obtains the ID attached to the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | Target URI object.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | ID obtained.|

**Example**

```ts
import dataUriUtils from '@ohos.ability.dataUriUtils';

let id = dataUriUtils.getId('com.example.dataUriUtils/1221');
```



## dataUriUtils.attachId

attachId(uri: string, id: number): string

Attaches an ID to the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | Target URI object.|
| id   | number | Yes  | ID to be attached.           |

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| string | URI object with the ID attached.|

**Example**

```ts
import dataUriUtils from '@ohos.ability.dataUriUtils';

let id = 1122;
let uri = dataUriUtils.attachId(
    'com.example.dataUriUtils',
	id,
);
```



## dataUriUtils.deleteId

deleteId(uri: string): string

Deletes the ID from the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | URI object from which the ID is to be deleted.|

**Return value**

| Type  | Description               |
| ------ | ------------------- |
| string | URI object with the ID deleted.|

**Example**

```ts
import dataUriUtils from '@ohos.ability.dataUriUtils';

let uri = dataUriUtils.deleteId('com.example.dataUriUtils/1221');
```



## dataUriUtils.updateId

updateId(uri: string, id: number): string

Updates the ID in a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------- |
| uri  | string | Yes  | Target URI object.|
| id   | number | Yes  | New ID.          |

**Return value**

| Type  | Description           |
| ------ | --------------- |
| string | URI object with the new ID.|

**Example**

```ts
import dataUriUtils from '@ohos.ability.dataUriUtils';

let id = 1122;
let uri = dataUriUtils.updateId(
    'com.example.dataUriUtils/1221',
	id
);
```
