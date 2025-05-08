# @ohos.userIAM.faceAuth (Facial Authentication) (System API)

The **userIAM.faceAuth** module provides APIs for face enrollment.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';
```

## FaceAuthManager

Provides APIs for facial authentication management.

### constructor

constructor()

A constructor used to create a **FaceAuthManager** object.

**System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

**System API**: This is a system API.

**Return value**

| Type                  | Description                |
| ---------------------- | -------------------- |
| [FaceAuthManager](#faceauthmanager) | **FaceAuthManager** object.|

**Example**

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';

let faceAuthManager = new faceAuth.FaceAuthManager();
```

### setSurfaceId

setSurfaceId(surfaceId: string): void;

Sets an [XComponent surface ID](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid) for the face preview page in the face enrollment process. This API must be used with [addCredential](../apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8).

**System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name        | Type                              | Mandatory | Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| surfaceId       | string     | Yes  | ID of the surface held by [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid). |

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

**Error codes**

| ID | Error Message |
| -------- | ------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 12700001 | The service is unavailable. |

**Example**

```ts
import { faceAuth } from '@kit.UserAuthenticationKit';

// The surfaceId is obtained from the XComponent control. The surfaceId here is only an example.
let surfaceId = '123456';
let manager = new faceAuth.FaceAuthManager();
try {
  manager.setSurfaceId(surfaceId);
  console.info('set surface id success');
} catch (error) {
  console.error('set surface id failed, error = ' + error);
}
```
