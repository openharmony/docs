# Permission Application Guide

## When to Use

The [Ability Privilege Level (APL)](accesstoken-overview.md#app-apls) of an application can be **normal**, **system_basic**, or **system_core**. The default APL is **normal**. The [permission types](accesstoken-overview.md#permission-types) include **system_grant** and **user_grant**. For details about the permissions for applications, see the [Application Permission List](permission-list.md).

This document describes:

- [Declaring Permissions in the Configuration File](#declaring-permissions-in-the-configuration-file)
- [Declaring Permissions in the ACL](#declaring-permissions-in-the-acl)
- [Requesting User Authorization](#requesting-user-authorization)
- [Pre-Authorizing user_grant Permissions](#pre-authorizing-user_grant-permissions)

## Declaring Permissions in the Configuration File

During the development, you need to declare the permissions required by your application one by one in the project configuration file. The application cannot obtain the permissions that are not declared in the configuration file. OpenHarmony provides two application models: FA model and stage model. For more information, see [Application Models](../application-models/application-model-description.md). The application bundle and configuration file vary with the application model.

> **NOTE**<br>The default APL of an application is **normal**. When an application needs the **system_basic** or **system_core** APL, you must declare the permission in the configuration file and the [Access Control List (ACL)](#declaring-permissions-in-the-acl).

The following table describes the fields in the configuration file.

| Field     | Mandatory| Description                                                        |
| --------- | -------- | ------------------------------------------------------------ |
| name      | Yes      | Name of the permission.                                                  |
| reason    | No      | Reason for requesting the permission.<br>This field is mandatory when the requested permission needs user authorization (user_grant).|
| usedScene | No      | Application scenario of the permission.<br>This field is mandatory when the requested permission needs user authorization (user_grant).|
| abilities | No      | Abilities that require the permission. The value is an array.<br>**Applicable model**: stage|
| ability   | No      | Abilities that require the permission. The value is an array.<br>**Applicable model**: FA|
| when      | No      | Time when the permission is used. <br>Value:<br>- **inuse**: The permission applies only to a foreground application.<br>- **always**: The permission applies to both the foreground and background applications.|

### Stage Model

If the application is based on the stage model, declare the permissions in [**module.json5**](../quick-start/module-configuration-file.md).

```json
{
  "module" : {
    // ...
    "requestPermissions":[
      {
        "name" : "ohos.permission.PERMISSION1",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.PERMISSION2",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
```

### FA Model

If the application is based on the FA model, declare the required permissions in **config.json**.

```json
{
  "module" : {
    // ...
    "reqPermissions":[
      {
        "name" : "ohos.permission.PERMISSION1",
        "reason": "$string:reason",
        "usedScene": {
          "ability": [
            "FormAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.PERMISSION2",
        "reason": "$string:reason",
        "usedScene": {
          "ability": [
            "FormAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
```

## Declaring Permissions in the ACL

If an application of the **normal** level requires permissions corresponding to the **system_basic** or **system_core** level, you need to declare the required permissions in the ACL.

For example, if an application needs to access audio files of a user and capture screenshots, it requires the **ohos.permission.WRITE_AUDIO** permission (of the **system_basic** level) and the **ohos.permission.CAPTURE_SCREEN** permission (of the **system_core** level). In this case, you need to add the related permissions to the **acl** field in the [HarmonyAppProvision configuration file](app-provision-structure.md).

```json
{
	// ...
	"acls":{
		"allowed-acls":[
			"ohos.permission.WRITE_AUDIO",
            "ohos.permission.CAPTURE_SCREEN"
		]
	}
}
```

## Requesting User Authorization

If an application needs to access user privacy information or use system abilities, for example, accessing location or calendar information or using the camera to take photos or record videos, it must request the permission from users. A permission verification is performed first to determine whether the current invoker has the corresponding permission. If the application has not obtained that permission, a dialog box will be displayed to request user authorization. The following figure shows an example.
<img src="figures/permission-read_calendar.png" width="40%;" />

> **NOTE**<br>Each time before an API protected by a permission is accessed, [**requestPermissionsFromUser()**](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) will be called to request user authorization. After a permission is dynamically granted, the user may revoke the permission. Therefore, the previously granted authorization status cannot be persistent.

### Stage Model

Example: Request the permission for an application to access calendar information.

1. Apply for the **ohos.permission.READ_CALENDAR** permission. For details, see [Declaring Permissions in the Configuration File](#declaring-permissions-in-the-configuration-file).

2. Call [**requestPermissionsFromUser()**](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) in the **onWindowStageCreate()** callback of the UIAbility to dynamically apply for the permission, or request user authorization on the UI based on service requirements. The return value of [requestPermissionsFromUser()](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) indicates whether the application has the target permission. If yes, the target API can be called normally.
   
   Request user authorization in UIAbility.
   
   ```typescript
   import UIAbility from '@ohos.app.ability.UIAbility';
   import window from '@ohos.window';
   import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
   
   export default class EntryAbility extends UIAbility {
       // ...
   
       onWindowStageCreate(windowStage: window.WindowStage) {
           // Main window is created, set main page for this ability
           let context = this.context;
           let atManager = abilityAccessCtrl.createAtManager();
           // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
           const permissions: Array<Permissions> = ['ohos.permission.READ_CALENDAR'];
           atManager.requestPermissionsFromUser(context, permissions).then((data) => {
               console.info(`[requestPermissions] data: ${JSON.stringify(data)}`);
               let grantStatus: Array<number> = data.authResults;
               if (grantStatus[0] === -1) {
                   // The authorization fails.
               } else {
                   // The authorization is successful.
               }
           }).catch((err) => {
               console.error(`[requestPermissions] Failed to start request permissions. Error: ${JSON.stringify(err)}`);
           })
           
           // ...
       }
   }
   ```
   
   Request user authorization on the UI.
   ```typescript
   import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
   import common from '@ohos.app.ability.common';
   
   @Entry
   @Component
   struct Index {
     reqPermissions() {
       let context = getContext(this) as common.UIAbilityContext;
       let atManager = abilityAccessCtrl.createAtManager();
       // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
       const permissions: Array<Permissions> = ['ohos.permission.READ_CALENDAR'];
       atManager.requestPermissionsFromUser(context, permissions).then((data) => {
         console.info(`[requestPermissions] data: ${JSON.stringify(data)}`);
         let grantStatus: Array<number> = data.authResults;
         if (grantStatus[0] === -1) {
           // The authorization fails.
         } else {
           // The authorization is successful.
         }
       }).catch((err) => {
         console.error(`[requestPermissions] Failed to start request permissions. Error: ${JSON.stringify(err)}`);
       })
     }
   
     // Page display.
     build() {
       // ...
     }
   }
   ```

### FA Model

Call [requestPermissionsFromUser()](../reference/apis/js-apis-inner-app-context.md#contextrequestpermissionsfromuser7) to request user authorization.

```js
import featureAbility from '@ohos.ability.featureAbility';

reqPermissions() {
    let context = featureAbility.getContext();
    let array:Array<string> = ["ohos.permission.PERMISSION2"];
    // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
    context.requestPermissionsFromUser(array, 1).then(function(data) {
        console.log("data:" + JSON.stringify(data));
        console.log("data permissions:" + JSON.stringify(data.permissions));
        console.log("data result:" + JSON.stringify(data.authResults));
    }, (err) => {
        console.error('Failed to start ability', err.code);
    });
}
```
## Pre-Authorizing user_grant Permissions
By default, the **user_grant** permissions must be dynamically authorized by the user through a dialog box. However, for pre-installed applications, you can pre-authorize the permissions, for example, the **ohos.permission.MICROPHONE** permission for camera applications, in the [**install_list_permission.json**] file to prevent the user authorization dialog box from being displayed. The [**install_list_permissions.json** file](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_permissions.json) is in the **/system/etc/app/** directory on a device. When the device is started, the **install_list_permissions.json** file is loaded. When the application is installed, the **user_grant** permissions in the file are granted. The **install_list_permissions.json** file contains the following fields:

- **bundleName**: bundle name of the application.
- **app_signature**: fingerprint information of the application. For details, see **Configuration in install_list_capability.json** in [Application Privilege Configuration Guide](../../device-dev/subsystems/subsys-app-privilege-config-guide.md).
- **permissions**: **name** specifies the name of the **user_grant** permission to pre-authorize. **userCancellable** specifies whether the user can revoke the pre-authorization. The value **true** means the user can revoke the pre-authorization; the value **false** means the opposite.

> **NOTE**<br>This file is available only for preinstalled applications.

```json
[
  // ...
  {
    "bundleName": "com.example.myapplication", // Bundle Name.
    "app_signature": ["****"], // Fingerprint information.
    "permissions":[
      {
        "name": "ohos.permission.PERMISSION_X", // Permission to pre-authorize.
        "userCancellable": false // The user cannot revoke the authorization.
      },
      {
        "name": "ohos.permission.PERMISSION_X", // Permission to pre-authorize.
        "userCancellable": true // The user can revoke the authorization.
      }
    ]
  }
]
```
