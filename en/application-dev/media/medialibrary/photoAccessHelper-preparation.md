# Before You Start

An application needs to obtain a PhotoAccessHelper instance before accessing or modifying the media data in an album. User personal data is involved in the PhotoAccessHelper module. Therefore, the application must also apply for the related read and write permissions from the user. Unless otherwise specified, the APIs of the PhotoAccessHelper module are used in **pages/index.ets** of the project or other customized .ets files.

## Obtaining a PhotoAccessHelper Instance

The application needs to call [getPhotoAccessHelper](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper) to obtain a PhotoAccessHelper instance based on the application context. Then, the application can use the instance obtained to access or modify the media data (such as images and videos) in an album.

**How to Develop**

1. Import the photoAccessHelper module.
2. Call **getContext** to obtain the application context.
3. Obtain a PhotoAccessHelper instance.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// The photoAccessHelper instance obtained here is a global object. Unless otherwise specified, the object obtained here is used in subsequent operations in this document. If an undefined error is reported, add the code snippet here.
// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
@Entry
@Component
struct Index {
  @State outputText: string = 'Supported formats:\n';

  build() {
    Row() {
      Button("example").onClick(async () => {
        let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
      }).width('100%')
    }
    .height('90%')
  }
}
```

## Requesting Permissions

Before requesting the permissions for the PhotoAccessHelper module, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. The following permissions are required.

| Permission                        | Description                                      | Authorization Mode  |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | Allows an application to read images and videos in the media library.| user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | Allows an application to read and write images and videos in the media library.| user_grant |

The required permissions must be authorized by the user. After adding the permissions in the **module.json5** file, use [abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted by the user. If yes, the application can access the data. Otherwise, display a dialog box to request user authorization.

**How to Develop**
<!--RP1-->
1. Request the required permissions via the ACL. For details, see [Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md).
<!--RP1End-->
2. [Declare the required permissions in the **module.json5** file](../../security/AccessToken/declare-permissions.md).
3. [Request user authorization](../../security/AccessToken/request-user-authorization.md).

> **NOTE**
>
> Even if the user has granted the permission, the permission will still be checked before an API protected by the permission is called. The permission granted status should not be persisted, because the user can revoke the permission through the system application **Settings**.
