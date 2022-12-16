# @ohos.ability.dataUriUtils

The **DataUriUtils** module provides APIs to handle utility classes for objects using the **DataAbilityHelper** schema. You can use the APIs to attach an ID to the end of a given URI and obtain, delete, or update the ID attached to the end of a given URI.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

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
| uri  | string | Yes  | URI object from which the ID is to be obtained.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | ID obtained from the URI object.|

**Example**

```ts
dataUriUtils.getId("com.example.dataUriUtils/1221")
```



## dataUriUtils.attachId

attachId(uri: string, id: number): string

Attaches an ID to the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | URI object to which an ID is to be attached.|
| id   | number | Yes  | ID to be attached.           |

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| string | URI object with the ID attached.|

**Example**

```ts
var idint = 1122;
dataUriUtils.attachId(
    "com.example.dataUriUtils",
	idint,
)
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
dataUriUtils.deleteId("com.example.dataUriUtils/1221")
```

## dataUriUtils.updateId

updateId(uri: string, id: number): string

Updates the ID in a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------- |
| uri  | string | Yes  | URI object to be updated.|
| id   | number | Yes  | New ID.           |

**Return value**

| Type  | Description           |
| ------ | --------------- |
| string | URI object with the new ID.|

**Example**

```ts
var idint = 1122;
dataUriUtils.updateId(
    "com.example.dataUriUtils",
	idint
)
```
