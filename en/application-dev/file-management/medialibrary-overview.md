# MediaLibrary Development Overview

The **mediaLibrary** module provides APIs for you to access and modify media files.

- You can manage [media assets (audios, videos, image, and files)](medialibrary-resource-guidelines.md) as follows:
  - Query media assets.
  - Obtain an image or a video.
  - Obtain the thumbnail of an image or a video.
  - Create a media asset.
  - Rename a media asset.
  - Move a media asset to the recycle bin.
- You can manage [file paths](medialibrary-filepath-guidelines.md) as follows:
  - Obtain the public directory that stores files of a certain type.
  - Copy files between the application sandbox and the public directory.
  - Read and write a file.
- You can manage [albums](medialibrary-album-guidelines.md) as follows:
  - Obtain images and videos in an album.
  - Create an album.
  - Rename an album.

> **NOTE**
>
> This development guide applies only to the stage model (available from API version 9).

To access and modify personal media data, an application must obtain a **MediaLibrary** instance and request the media asset read and write permissions from the user.

Before using the **MediaLibrary** APIs to develop features, you must learn how to:

- [Obtain a MediaLibrary Instance](#obtaining-a-medialibrary-instance)
- [Request Permissions](#requesting-permissions)

## Obtaining a MediaLibrary Instance

An application must call [getMediaLibrary](../reference/apis/js-apis-medialibrary.md#medialibrarygetmedialibrary8) to obtain a **MediaLibrary** instance based on the application context. Through this instance, the application can access and modify personal media data (such as audios, videos, images, and files).

**How to Develop**

1. Import the **mediaLibrary** module.
2. Call **getContext** to obtain the application context.
3. Obtain a **MediaLibrary** instance.

```ts
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

const context = getContext(this);
var media = mediaLibrary.getMediaLibrary(context);
```

## Requesting Permissions

To read and write a **MediaLibrary** instance, you must have the required permissions, as described in the table below. Before requesting the permissions, ensure that the [basic principles for permission management](../security/accesstoken-overview.md#basic-principles-for-permission-management) are met.  

| Permission                        | Description                                      | Authorization Mode  |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_MEDIA     | Allows an application to read media files from the user's external storage.| user_grant |
| ohos.permission.WRITE_MEDIA    | Allows an application to read media files from and write media files into the user's external storage.| user_grant |
| ohos.permission.MEDIA_LOCATION | Allows an application to access geographical locations in the user's media file.| user_grant |

After configuring the permissions in the **module.json5** file, the application must call [Context.requestPermissionsFromUser](../reference/apis/js-apis-ability-context.md#abilitycontextrequestpermissionsfromuser) to check for the required permissions and if they are not granted, request the permissions from the user by displaying a dialog box.

> **NOTE**<br>Even if the user has granted a permission, the application must check for the permission before calling an API protected by the permission. It should not persist the permission granted status, because the user can revoke the permission through the system application **Settings**.

**How to Develop**

1. Declare the permissions in the **module.json5** file. Add the **requestPermissions** tag under **module** in the file, and set the tag based on the project requirements. For details about the tag, see [Guide for Requesting Permissions from User](../security/accesstoken-guidelines.md).

   ```json
   {
       "module": {
           "requestPermissions": [
               {
                   "name": "ohos.permission.MEDIA_LOCATION",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                         "MainAbility"
                       ],
                       "when": "always"
               }
               },
               {
                   "name": "ohos.permission.READ_MEDIA",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                           "MainAbility"
                       ],
                       "when": "always"
                   }
               },
               {
                   "name": "ohos.permission.WRITE_MEDIA",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                           "MainAbility"
                       ],
                       "when": "always"
                   }
               }
           ]
       }
   }    
   ```

2. Call **requestPermissionsFromUser** to check for the required permissions and if they are not granted, request the permissions from the user by displaying a dialog box.

   ```ts
   import Ability from '@ohos.application.Ability'
   
   export default class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           var permissions=['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
           var permissionRequestResult;
           this.context.requestPermissionsFromUser(permissions,(err,result) => {
               if(err){
                   console.log('requestPermissionsFromUserError: ' + JSON.stringify(err));
               }else{
                   permissionRequestResult=result;
                   console.log('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
               }    
           });       
       }
   }
   ```

   
