# @ohos.app.ability.dataUriUtils (DataUriUtils)

The **DataUriUtils** module provides APIs to process URI objects. You can use the APIs to attach an ID to the end of a given URI and obtain, delete, or update the ID attached to the end of a given URI.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { dataUriUtils } from '@kit.AbilityKit';
```

## dataUriUtils.getId

getId(uri: string): number

Obtains the ID attached to the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type  | Mandatory | Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | Target URI object. |

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | ID obtained. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { dataUriUtils } from '@kit.AbilityKit';

try {
  let id = dataUriUtils.getId('com.example.dataUriUtils/1221');
  console.info(`get id: ${id}`);
} catch(err) {
  console.error(`get id err ,check the uri ${err}`);
}
```



## dataUriUtils.attachId

attachId(uri: string, id: number): string

Attaches an ID to the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type  | Mandatory | Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | Target URI object. |
| id   | number | Yes  | ID to be attached.           |

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| string | URI object with the ID attached. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { dataUriUtils } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let id = 1122;
try {
  let uri = dataUriUtils.attachId(
    'com.example.dataUriUtils',
    id,
  );
  console.info(`attachId the uri is: ${uri}`);
} catch (err) {
  console.error(`get id err, code: ${JSON.stringify((err as BusinessError).code)}, msg: ${JSON.stringify((err as BusinessError).message)}`);
}
```



## dataUriUtils.deleteId

deleteId(uri: string): string

Deletes the ID from the end of a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type  | Mandatory | Description                       |
| ---- | ------ | ---- | --------------------------- |
| uri  | string | Yes  | URI object from which the ID is to be deleted. |

**Return value**

| Type  | Description               |
| ------ | ------------------- |
| string | URI object with the ID deleted. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { dataUriUtils } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let uri = dataUriUtils.deleteId('com.example.dataUriUtils/1221');
  console.info(`delete id with the uri is: ${uri}`);
} catch(err) {
  console.error(`delete id err, code: ${JSON.stringify((err as BusinessError).code)}, msg: ${JSON.stringify((err as BusinessError).message)}`);
}
```



## dataUriUtils.updateId

updateId(uri: string, id: number): string

Updates the ID in a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type  | Mandatory | Description               |
| ---- | ------ | ---- | ------------------- |
| uri  | string | Yes  | Target URI object. |
| id   | number | Yes  | New ID.           |

**Return value**

| Type  | Description           |
| ------ | --------------- |
| string | URI object with the new ID. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { dataUriUtils } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let id = 1122;
  let uri = dataUriUtils.updateId(
    'com.example.dataUriUtils/1221',
    id
  );
} catch (err) {
  console.error(`update id err, code: ${JSON.stringify((err as BusinessError).code)}, msg: ${JSON.stringify((err as BusinessError).message)}`);
}
```
