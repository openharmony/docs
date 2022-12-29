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

  let faceAuthManager = new userIAM_faceAuth.FaceAuthManager();
  ```

### setSurfaceId

setSurfaceId(surfaceId: string): void;

Sets an [XComponent surface ID](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid) for the face preview page in the face enrollment process.

**System capability**: SystemCapability.UserIAM.UserAuth.FaceAuth

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| surfaceId       | string     | Yes  | ID of the surface held by the [XComponent](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid).|

**Example**

  ```js
  import faceAuth from '@ohos.userIAM.faceAuth';

  let surfaceId = "123456";
  let manager = new faceAuth.FaceAuthManager();
  try {
      manager.setSurfaceId(surfaceId);
      console.info("Set the surface ID successfully");
  } catch (e) {
      console.error("Failed to set the surface ID, error = " + e);
  }
  ```
