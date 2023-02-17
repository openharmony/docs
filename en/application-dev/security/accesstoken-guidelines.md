# Permission Application Guide

## When to Use

In this example, the application requires the **ohos.permission.PERMISSION1** and **ohos.permission.PERMISSION2** permissions to implement core functions.

- The ability privilege level (APL) of the application is **normal**.
- The level of **ohos.permission.PERMISSION1** is **normal**, and the authorization mode is **system_grant**.
- The level of **ohos.permission.PERMISSION2** is **system_basic**, and the authorization mode is **user_grant**.

> **CAUTION**
>
> In this scenario, the required permissions include a **user_grant** permission. You can check whether the caller has the required permission through permission verification.
>
> If the application has not obtained that permission, a dialog box will be displayed to request user authorization.

For details about the permissions for applications, see the [application permission list](permission-list.md).

## Available APIs

The following lists only the APIs used in this guide. The APIs used vary with the applicatin models. For more information, see [Examples](##Examples).

### FA Model
| API                                                      | Description                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void; | Requests permissions from the user.|
> For details, see [AbilityContext](../reference/apis/js-apis-ability-context.md).


### Stage Model

| API                                                      | Description                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| requestPermissionsFromUser(context: Context, permissions: Array&lt;Permissions&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void; | Requests permissions from the user.|
> For details, see [Ability Access Control](../reference/apis/js-apis-abilityAccessCtrl.md).

## Declaring Permissions

Declare the permissions required by the application one by one in the project configuration file. The application cannot obtain the permissions that are not declared in the configuration file. OpenHarmony provides two application models: FA model and stage model. For more information, see [Application Models](../application-models/application-model-description.md).

The application bundle structure and configuration file vary with the application models.

The following table describes the fields in the configuration files.

| Field     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| name      | Name of the permission.                                                  |
| reason    | Reason for requesting the permission. This field is mandatory for a user_grant permission.|
| usedScene | Scenario of the permission. This field is mandatory for a user_grant permission.|
| ability   | Abilities that require the permission. The value is an array.<br>**Applicable model**: FA           |
| abilities | Abilities that require the permission. The value is an array.<br>**Applicable model**: stage           |
| when      | Time when the permission is used. The value can be **inuse** (the permission can be used only in the foreground) or **always** (the permission can be used in foreground and background).|

### FA Model

For the applications based on the FA model, declare the required permissions in the **config.json** file.

**Example**

```json
{
  "module" : {
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

### Stage Model

For the applications based on the stage model, declare the required permissions in the **module.json5** file.

**Example**

```json
{
  "module" : {
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

## Declaring Permissions in the ACL

The permission level of **ohos.permission.PERMISSION2** is **system_basic**, which is higher than the app's APL. In this case, use the ACL.

In addition to declaring all the permissions in the configuration file, you must declare the permissions whose levels are higher that the app's APL in the app's profile. For details about the fields in the profile, see [HarmonyAppProvision Configuration File](app-provision-structure.md).

For example, declare the required permission in the **acls** field:

```json
{
  "acls": {
    "allowed-acls": [
      "ohos.permission.PERMISSION2"
    ]
  }
}
```

## Applying for the user_grant Permission

After the permissions are declared, the system grants the system_grant permission during the installation of the app. The user_grant permission must be authorized by the user.

Therefore, before allowing the application to call the API protected by the **ohos.permission.PERMISSION2** permission, the system needs to verify whether the application has the permission to do so.

If the verification result indicates that the application has the permission, the application can access the target API. Otherwise, the application needs to request user authorization and then proceeds based on the authorization result. For details, see [Access Control Overview](accesstoken-overview.md).

> **CAUTION**
>
> The permission authorized by a user is not permanent, because the user may revoke the authorization at any time. Each time before the API protected by the permission is called, call **requestPermissionsFromUser()** to request the permission.

## Examples

The procedure for requesting user authorization is as follows:

1. Obtain the ability context.
2. Call **requestPermissionsFromUser()** to request user authorization. The API determines whether to display a dialog box to request user authorization based on whether the application has the permission.
3. Check whether the application has the permission based on the return value. If the application has the permission, the API can be invoked.

### FA Model
```js
  // OnWindowStageCreate of the ability
  onWindowStageCreate() {
    var context = this.context
    let array:Array<string> = ["ohos.permission.PERMISSION2"];
    // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
    context.requestPermissionsFromUser(array).then(function(data) {
      console.log("data type:" + typeof(data));
      console.log("data:" + data);
      console.log("data permissions:" + data.permissions);
      console.log("data result:" + data.authResults);
    }, (err) => {
      console.error('Failed to start ability', err.code);
    });
  }

```
> **NOTE**
> 
> For details about how to use the APIs for the FA model, see [AbilityContext](../reference/apis/js-apis-ability-context.md).

### Stage Model
```js
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

  // OnWindowStageCreate of the ability
  onWindowStageCreate() {
    var context = this.context
    var AtManager = abilityAccessCtrl.createAtManager();
    // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
      AtManager.requestPermissionsFromUser(context, ["ohos.permission.CAMERA"]).then((data) => {
        console.log("data type:" + typeof(data));
        console.log("data:" + data);
        console.log("data permissions:" + data.permissions);
        console.log("data result:" + data.authResults);
      }).catch((err) => {
          console.error('Failed to start ability', err.code);
      })
  }

```
> **NOTE**
> For details about how to use the APIs for the stage model, see [Application Access Control](../reference/apis/js-apis-abilityAccessCtrl.md).

## Pre-Authorizing user_grant Permissions
By default, the **user_grant** permissions must be granted by the user through a dialog box. However, for pre-installed applications, such as screenshot applications, you can pre-authorize the permissions to prevent the user authorization dialog box from being displayed. The [**install_list_permissions.json** file](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_permissions.json) is in the **/system/etc/app/** directory on a device. When the device is started, the **install_list_permissions.json** file is loaded. When the application is installed, the **user_grant** permissions in the file are granted. The **install_list_permissions.json** file is available only for preinstalled applications.
The **install_list_permissions.json** file contains the **bundleName**, **app_signature**, and **permissions** fields.
1. The permissions here are user_grant permissions only. For details about the permissions, see the [Application Permission List](permission-list.md).
2. **userCancellable** specifies whether the user can revoke the authorization. The value **true** means the user can revoke the authorization; the value **false** means the opposite.

```json
[
  {
    "bundleName": "com.ohos.myapplication", // Bundle name.
    "app_signature":[], // Fingerprint information.
    "permissions":[
      {
        "name":"xxxx", // Permission name, which cannot be left blank.
        "userCancellable":false // The user cannot revoke the authorization. This field cannot be left blank.
      },
      {
        "name":"yyy", // Permission name, which cannot be left blank.
        "userCancellable":true // The user can revoke the authorization. This field cannot be left blank.
      }
    ]
  }
]
```