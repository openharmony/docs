# PhotoAccessHelper Overview

**PhotoAccessHelper** provides album management capabilities, including creating and accessing an album and accessing and modifying media data in albums. You can use the APIs provided by **PhotoAccessHelper** to manage:

- [Media assets (images and videos)](photoAccessHelper-resource-guidelines.md), including:
  - Obtaining the specified media assets.
  - Obtaining an image or video thumbnail.
  - Creating a media asset.
  - Renaming a media asset.
  - Moving a media asset to the trash.
- [User Albums](photoAccessHelper-userAlbum-guidelines.md), including:
  - Creating a user album.
  - Obtaining a user album.
  - Renaming a user album.
  - Adding images and videos to a user album.
  - Obtaining images and videos from a user album.
  - Removing images and videos from a user album.
  - Deleting a user album.
- [System albums](photoAccessHelper-systemAlbum-guidelines.md), including:
  - Favorites
  - Video album
  - Screenshot album
- [Media asset (image, video, and album) change notifications](photoAccessHelper-notify-guidelines.md), including:
  - Registering listening for a specified URI.
  - Unregistering the listening for a specified URI.

> **NOTE**
>
> The **PhotoAccessHelper** development guides apply only to API version 10 based on the stage model.

An application needs to obtain a **photoAccessHelper** instance before accessing and modifying the media data in an album. User personal data is involved in the **photoAccessHelper** module. Therefore, the application needs to apply for the related read and write permissions. Unless otherwise specified, the APIs of the **photoAccessHelper** module apply to **pages/index.ets** of the project or other customized .ets files by default.

Before using the **PhotoAccessHelper** APIs, you need to:

- [Obtain a **photoAccessHelper** instance.](#obtaining-a-photoaccesshelper-instance)
- [Apply for permissions.](#applying-for-permissions)

## Obtaining a photoAccessHelper Instance

The application needs to call [getPhotoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md#photoaccesshelpergetphotoaccesshelper) to obtain a **photoAccessHelper** instance based on the application context. The instance obtained can be used to access or modify the media data (such as image and videos) in an album.

**How to Develop**

1. Import the **photoAccessHelper** module.
2. Use **getContext** to obtain the application context.
3. Obtain a **photoAccessHelper** instance.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';

// The phAccessHelper instance obtained here is a global object. By default, the object obtained here is used in subsequent operations. If the code is not added, an undefined error will be reported.
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
```

## Applying for Permissions

Before applying for permission, ensure that the [basic principles for permission management](../security/accesstoken-overview.md#basic-principles-for-permission-management) are complied with. Apply for the following permissions.

| Permission                        | Description                                      | Authorization Mode  |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | Allows an app to read image and video file information from a user's external storage.| user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | Allows an app to read and write image and video file information on a user's external storage.| user_grant |

The required permissions must be authorized by the user (user_grant). You need to add the permissions in the **module.json5** file, and use [abilityAccessCtrl.requestPermissionsFromUser](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted by the user. If yes, the application can access the data. Otherwise, a dialog box will be displayed to request user authorization.

> **NOTE**<br>Even if the user has granted the permission, the permission will still be checked before an API protected by the permission is called. The permission granted status should not be persisted, because the user can revoke the permission through the system application **Settings**.

**How to Develop**

1. Declare the permissions in the **module.json5** file.<br>Add **requestPermissions** under **module** in the file, and add the required permissions. For details, see [Applying for Permissions](../security/accesstoken-guidelines.md).

  ```json
  {
    "module": {
      "requestPermissions": [
        {
          "name": "ohos.permission.READ_IMAGEVIDEO",
          "reason": "Permissions required for photoAccessHelper related operations",
          "usedScene": {
            "abilities": [
              "EntryAbility"
            ],
            "when": "always"
          }
        },
        {
          "name": "ohos.permission.WRITE_IMAGEVIDEO",
          "reason": "Permissions required for photoAccessHelper related operations",
          "usedScene": {
            "abilities": [
              "EntryAbility"
            ],
            "when": "always"
          }
        },
      ]
    }
  }    
  ```

2. Call **requestPermissionsFromUser** in the **onWindowStageCreate** callback of **Ability.ts** to check for the required permissions. If the permissions are not granted, display a dialog box to request user authorization dynamically.

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import abilityAccessCtrl, {Permissions} from '@ohos.abilityAccessCtrl';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage) {
      let list : Array<Permissions> = ['ohos.permission.READ_IMAGEVIDEO', 'ohos.permission.WRITE_IMAGEVIDEO'];
      let permissionRequestResult;
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(this.context, list, (err, result) => {
        if (err) {
          console.error('requestPermissionsFromUserError: ' + JSON.stringify(err));
        } else {
          permissionRequestResult = result;
          console.info('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
        }
      });
    }
  }
  ```
