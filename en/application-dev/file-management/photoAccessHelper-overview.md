# PhotoAccessHelper Overview

**PhotoAccessHelper** provides album management capabilities, including creating and accessing an album and accessing and modifying media data in albums. You can use the APIs provided by **PhotoAccessHelper** to:

- [Manage media assets (images and videos)](photoAccessHelper-resource-guidelines.md), including:
  - Obtaining the specified media assets.
  - Obtaining image and video thumbnails.
  - Creating a media asset.
  - Renaming a media asset.
  - Moving a media asset to the trash.
- [Manage user albums](photoAccessHelper-userAlbum-guidelines.md), including:
  - Creating a user album.
  - Obtaining a user album.
  - Renaming a user album.
  - Adding images and videos to a user album.
  - Obtaining images and videos from a user album.
  - Removing images and videos from a user album.
  - Deleting a user album.
- [Manage system albums](photoAccessHelper-systemAlbum-guidelines.md), including:
  - Favorites
  - Video album
  - Screenshot album
- [Manage media asset (image, video, and album) change notifications](photoAccessHelper-notify-guidelines.md), including:
  - Registering listening for the specified URI.
  - Unregistering the listening for the specified URI.

> **NOTE**
>
> This development guide applies only to API version 10 based on the stage model.

An application needs to obtain a **PhotoAccessHelper** instance before accessing and modifying the media data in an album. User personal data is involved in the **photoAccessHelper** module. Therefore, the application needs to apply for the related read and write permissions. Unless otherwise specified, the APIs of the **photoAccessHelper** module are used in **pages/index.ets** of the project or other customized .ets files by default.

Before using the **PhotoAccessHelper** APIs, you need to:

  - [Obtain a **PhotoAccessHelper** instance](#obtaining-a-photoaccesshelper-instance).
  - [Apply for permissions](#applying-for-permissions).

## Obtaining a PhotoAccessHelper Instance

The application needs to call [getPhotoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md#photoaccesshelpergetphotoaccesshelper) to obtain a **PhotoAccessHelper** instance based on the application context. The instance obtained can be used to access or modify the media data (such as images and videos) in an album.

**How to Develop**

1. Import the **photoAccessHelper** module.
2. Use **getContext** to obtain the application context.
3. Obtain a **PhotoAccessHelper** instance.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';

// The photoAccessHelper instance obtained here is a global object. By default, the object obtained here is used in subsequent operations in this document. If an undefined error is reported, add the code snippet here.
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
```

## Applying for Permissions

Before applying for permission, ensure that the [basic principles for permission management](../security/accesstoken-overview.md#basic-principles-for-permission-management) are complied with. Apply for the following permissions.

| Permission                        | Description                                      | Authorization Mode  |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | Allows an application to read image and video file information from a user's external storage.| user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | Allows an application to read and write image and video file information on a user's external storage.| user_grant |

The required permissions must be authorized by the user (user_grant). After adding the permissions in the **module.json5** file, use [abilityAccessCtrl.requestPermissionsFromUser](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted by the user. If yes, the application can access the data. Otherwise, a dialog box will be displayed to request user authorization.

**How to Develop**

1. [Declare the required permissions in the **module.json5** file](../security/accesstoken-guidelines.md#stage-model).
2. [Request user authorization](../security/accesstoken-guidelines.md#stage-model-1).

> **NOTE**
>
> Even if the user has granted the permission, the permission will still be checked before an API protected by the permission is called. The permission granted status should not be persisted, because the user can revoke the permission through the system application **Settings**.
