# Facial Authentication

The **userIAM.faceAuth** module provides APIs for face enrollment.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import userIAM_faceAuth from '@ohos.userIAM.faceAuth';
```

## FaceAuthManager

Provides APIs for facial authentication management.

### constructor

constructor()

A constructor used to create a **FaceAuthManager** object.

**System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

**Return value**

| Type                  | Description                |
| ---------------------- | -------------------- |
| [FaceAuthManager](#faceauthmanager) | **FaceAuthManager** object.|

**Example**

  ```js
  import userIAM_faceAuth from '@ohos.userIAM.faceAuth';

  let faceAuthManager = new userIAM_faceAuth.FaceAuthManager()
  ```

### setSurfaceId

setSurfaceId(surfaceId: string): ResultCode;

Sets an [XComponent surface ID](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid) for the face preview page in the face enrollment process.

**System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| surfaceId       | string     | Yes  | ID of the surface held by the [XComponent](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid).|

**Return value**

| Type      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| [ResultCode](#resultcode) | Operation result code.|

**Example**

  ```js
  import userIAM_faceAuth from '@ohos.userIAM.faceAuth';

  let faceAuthManager = new userIAM_faceAuth.FaceAuthManager()
  faceAuthManager.setSurfaceId("0");
  ```

## ResultCode

 Enumerates the operation result codes.

 **System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

| Name                   | Default Value| Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | The operation is successful.          |
| FAIL                    | 1      | The operation fails.          |
