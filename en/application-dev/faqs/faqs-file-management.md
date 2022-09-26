# File Management Development



## What If There is No Return Value or Error Captured After getAlbums Is Called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

The **ohos.permission.READ_MEDIA** permission is required for calling **getAlbums**, and this permission needs user authorization. For details, see OpenHarmony [Application Permission List](../security/permission-list.md).

1. Configure the required permission in the **module.json5** file.
     
   ```
   "requestPermissions": [
     {
       "name": "ohos.permission.READ_MEDIA"
     }
   ]
   ```

2. Add the code for user authorization before the **MainAbility.ts -> onWindowStageCreate** page is loaded.
     
   ```
   private requestPermissions() {
   let permissionList: Array<string> = [
     "ohos.permission.READ_MEDIA"
   ];
   this.context.requestPermissionsFromUser(permissionList)
     .then(data => {
       console.info(`request permission data result = ${data.authResults}`)
     })
     .catch(err => {
       console.error(`fail to request permission error:${err}`)
     })
   }
   ```
