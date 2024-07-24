# @ohos.pasteboard (Pasteboard) (System API)

The **Pasteboard** module provides the copy and paste support for the system pasteboard. You can use the APIs of this module to operate pasteboard content of the plain text, HTML, URI, Want, pixel map, and other types.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.pasteboard (Pasteboard)](js-apis-pasteboard.md).

## Modules to Import

```ts
import pasteboard from '@ohos.pasteboard';
```

### setAppShareOptions<sup>12+</sup>

setShareOptions(shareOptions: ShareOption): void

Sets the global pasteable range of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| shareOptions | [ShareOption](js-apis-pasteboard.md#shareoption9) | Yes| Pasteable range.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12900006 | Settings already exist. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
  console.info('Set app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Set app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### removeAppShareOptions<sup>12+</sup>

removeShareOptions(): void

Deletes the global pasteable range of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.removeAppShareOptions();
  console.info('Remove app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Remove app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```
