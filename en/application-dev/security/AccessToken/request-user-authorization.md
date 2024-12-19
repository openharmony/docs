# Requesting User Authorization

Before an application accesses user privacy information or use a system capability, for example, to obtain location information, access the Calendar, or use the camera to take a photo or record a video, the application needs to request user authorization. The permissions that must be authorized by users are user_grant permissions.

The procedure for requesting user_grant permissions is as follows:

1. Declare the permissions required by your application in the configuration file. 

2. Associate each object that requires a user_grant permission with the related permission. This lets the user know what operations need user authorization.<br>
   For details about the preceding two steps, see [Declaring Permissions](declare-permissions.md).

3. Trigger user authorization via an API when the application in running needs to access the target object. The API first checks whether the user has granted the permission required. If no, a dialog box will be displayed to request authorization from the user.

4. Check the user authorization result, and allow the next step only after the user has granted the permission to the application.

This topic elaborates steps 3 and 4.

## Constraints

- For a user_grant permission, show a rationale to the user in a UI element, clearly explaining why your application needs the permission. Based on the rationale, the user then determines whether to grant the permission.

- Frequent pop-up windows may disturb user experience and are not recommended. If a user rejects the authorization, the window for requesting user authorization will not be displayed again. The application needs to provide information to guide the user to manually grant the permission in **Settings**.

- The system permission pop-up window cannot be obscured.

  The system permission pop-up window cannot be obscured by other components. The information in the pop-up window must be completely displayed so that the user can identify and complete authorization.
  If the system permission pop-up window is displayed in the same position as another component, the system permission pop-up window takes precedence over the other component by default.

- A check for the required permission is mandatory each time before the operation that requires the permission is performed.
  
  You can use [checkAccessToken()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#checkaccesstoken9) to check whether the user has granted specific permissions to your application. This API returns [PERMISSION_GRANTED](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus) or [PERMISSION_DENIED](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus). For details, see the example given below.

- Each time before an API that requires a user_grant permission is called, use [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the user has already granted the permission.

  After a permission is granted, the user may revoke the permission in **Settings**. Therefore, the previous authorization status cannot be persistent.

- When requesting permissions using **onWindowStageCreate()**, the application needs to wait until the **loadContent()** or **setUIContent()** API is complete or call [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) in **loadContent()** or **setUIContent()**. Otherwise, **requestPermissionsFromUser()** will fail before **Content** is loaded.
  <!--RP1--><!--RP1End-->

## How to Develop

The following example steps you through on how to request the location permissions.

**Figure 1** Requesting the location permissions

![en_image_location](figures/en_image_location.png)

1. Request the ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION permissions. For details, see [Declaring Permissions](declare-permissions.md).

2. Check whether the user has granted the permissions.

   Call [checkAccessToken()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#checkaccesstoken9) to check whether the user has already granted the permissions that your application requires. If yes, the application can perform subsequent operations. Otherwise, user authorization is required.

   ```ts
   import { abilityAccessCtrl, bundleManager, Permissions } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   async function checkPermissionGrant(permission: Permissions): Promise<abilityAccessCtrl.GrantStatus> {
     let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
     let grantStatus: abilityAccessCtrl.GrantStatus = abilityAccessCtrl.GrantStatus.PERMISSION_DENIED;
   
     // Obtain the token ID of the application.
     let tokenId: number = 0;
     try {
       let bundleInfo: bundleManager.BundleInfo = await bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION);
       let appInfo: bundleManager.ApplicationInfo = bundleInfo.appInfo;
       tokenId = appInfo.accessTokenId;
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to get bundle info for self. Code is ${err.code}, message is ${err.message}`);
     }
   
     // Check whether the user has granted the permission.
     try {
       grantStatus = await atManager.checkAccessToken(tokenId, permission);
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to check access token. Code is ${err.code}, message is ${err.message}`);
     }
   
     return grantStatus;
   }
   
   async function checkPermissions(): Promise<void> {
     let grantStatus1: boolean = await checkPermissionGrant('ohos.permission.LOCATION') === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED;// Obtain the status of the ohos.permission.LOCATION permission.
     let grantStatus2: boolean = await checkPermissionGrant('ohos.permission.APPROXIMATELY_LOCATION') === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED;// Obtain the status of the ohos.permission.APPROXIMATELY_LOCATION permission.
     // The ohos.permission.LOCATION permission must be requested with the ohos.permission.APPROXIMATELY_LOCATION permission together or after the ohos.permission.APPROXIMATELY_LOCATION permission is available.
     if (grantStatus2 && !grantStatus1) {
        // Request the ohos.permission.LOCATION permission.
     } else if (!grantStatus1 && !grantStatus2) {
        // Request the ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION permissions, or request the ohos.permission.APPROXIMATELY_LOCATION permission.
     } else {
        // If the user grants the permission, the application can access location information.
     }
   }
   ```

3. Request user authorization when your application needs to access location information.

   Call [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to request user authorization. You can specify a list of permissions, such as the permission to access the location, Calendar, camera, or microphone, in the **Array\<Permissions>** parameter of this API. The user can grant or deny the permissions.

   You can have [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) called in **onWindowStageCreate()** of the UIAbility to dynamically request user authorization, or request user authorization on the UI based on service requirements.

   When requesting permissions using **onWindowStageCreate()**, the application needs to wait until the **loadContent()** or **setUIContent()** API is complete or call [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) in **loadContent()** or **setUIContent()**. Otherwise, **requestPermissionsFromUser()** will fail before **Content** is loaded.

   <!--RP1--><!--RP1End-->

   <!--RP2-->
   - Sample code for requesting user authorization using UIAbility

      ```ts
      import { abilityAccessCtrl, common, Permissions, UIAbility } from '@kit.AbilityKit';
      import { window } from '@kit.ArkUI';
      import { BusinessError } from '@kit.BasicServicesKit';
      
      const permissions: Array<Permissions> = ['ohos.permission.LOCATION','ohos.permission.APPROXIMATELY_LOCATION'];
      function reqPermissionsFromUser(permissions: Array<Permissions>, context: common.UIAbilityContext): void {
        let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
        // Determine whether to display a user authorization dialog box based on the return value of requestPermissionsFromUser.
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // If the user grants the permission, the application can perform the subsequent operation.
            } else {
              // If the user denies the permission, display a message indicating that user authorization is required, and direct the user to set the permission in the Settings page.
              return;
            }
          }
          // The authorization is successful.
        }).catch((err: BusinessError) => {
          console.error(`Failed to request permissions from user. Code is ${err.code}, message is ${err.message}`);
        })
      }
      export default class EntryAbility extends UIAbility {
        onWindowStageCreate(windowStage: window.WindowStage): void {
          // ...
          windowStage.loadContent('pages/Index', (err, data) => {
            reqPermissionsFromUser(permissions, this.context);
          // ...
          });
        }
      
        // ...
      }
      ```

   - Sample code for requesting user authorization on the UI

      ```ts
      import { abilityAccessCtrl, common, Permissions } from '@kit.AbilityKit';
      import { BusinessError } from '@kit.BasicServicesKit';
      
      const permissions: Array<Permissions> = ['ohos.permission.LOCATION','ohos.permission.APPROXIMATELY_LOCATION'];
      function reqPermissionsFromUser(permissions: Array<Permissions>, context: common.UIAbilityContext): void {
        let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
        // Determine whether to display a user authorization dialog box based on the return value of requestPermissionsFromUser.
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // If the user grants the permission, the application can perform the subsequent operation.
            } else {
              // If the user denies the permission, display a message indicating that user authorization is required, and direct the user to set the permission in the Settings page.
              return;
            }
          }
          // The authorization is successful.
        }).catch((err: BusinessError) => {
          console.error(`Failed to request permissions from user. Code is ${err.code}, message is ${err.message}`);
        })
      }
      
      @Entry
      @Component
      struct Index {
        aboutToAppear() {
          const context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
          reqPermissionsFromUser(permissions, context);
        }
      
        build() {
          // ...
        }
      }
      ```
   <!--RP2End-->

4. Perform subsequent operations based on the authorization result.

   After [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) is called, the application waits for the user authorization result. If the user grants the permission, the application can perform the subsequent operation. Otherwise, display a message indicating that user authorization is required, and direct the user to set the permission on the **Settings** page.<!--RP3-->

   Path: **Settings**\> **Privacy**\> **Permission manager**\> **Apps**\> Target app<!--RP3End-->
