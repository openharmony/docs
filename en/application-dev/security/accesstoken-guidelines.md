# Permission Application Guide

## When to Use

In this example, the app requires the **ohos.permission.PERMISSION1** and **ohos.permission.PERMISSION2** permissions to implement core functions.

- The ability privilege level (APL) of the app is **normal**.
- The level of **ohos.permission.PERMISSION1** is **normal**, and the authorization mode is **system_grant**.
- The level of **ohos.permission.PERMISSION2** is **system_basic**, and the authorization mode is **user_grant**.

> **CAUTION**
>
> In this scenario, the required permissions include a **user_grant** permission. You can check whether the caller has the required permission through permission verification.
>
> If the permission verification result indicates that the app has not obtained that permission, dynamic user authorization is required.

## Available APIs

The table below lists only the API used in this guide. For more information, see [Ability Access control](../reference/apis/js-apis-ability-context.md).

| API                                                      | Description                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void; | Requests permissions from the user by displaying a dialog box. This API uses an asynchronous callback to return the result.|

## Declaring Permissions

Declare the permissions required by the app one by one in the project configuration file. The app cannot obtain the permissions that are not declared in the configuration file. The ability framework provides two models: Feature Ability (FA) model and stage model. For more information, see [Ability Framework Overview](../ability/ability-brief.md).

Note that the app bundle structure and configuration file vary with the ability framework model.

The following table describes the tags in the configuration file.

| Field     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| name      | Name of the permission.                                                  |
| reason    | Reason for requesting the permission. This field is mandatory for a user_grant permission.|
| usedScene | Scenario of the permission. This field is mandatory for a user_grant permission.|
| ability   | Abilities that use the permission. The value is an array.<br>**Applicable model**: FA           |
| abilities | Abilities that use the permission. The value is an array.<br>**Applicable model**: stage           |
| when      | Time when the permission is used. The value can be **inuse** (the permission can be used only in the foreground) or **always** (the permission can be used in foreground and background).|

### FA Model

For the apps based on the FA model, declare the required permissions in the **config.json** file.

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

For the apps based on the stage model, declare the required permissions in the **module.json5** file.

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

## Declaring the ACL

The permission level of **ohos.permission.PERMISSION2** is **system_basic**, which is higher than the app's APL. In this case, use the ACL.

In addition to declaring all the permissions in the configuration file, you must declare the permissions whose levels are higher that the app's APL in the app's profile. For details about the fields in the profile, see [HarmonyAppProvision Configuration File](../quick-start/app-provision-structure.md).

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

Therefore, before allowing the app to call the API protected by the **ohos.permission.PERMISSION2** permission, the system needs to verify whether the app has the permission to do so.

If the verification result indicates that the app has the permission, the app can access the target API. Otherwise, the app needs to request user authorization and then proceeds based on the authorization result. For details, see [Access Control Overview](accesstoken-overview.md).

> **CAUTION**
>
> The permission authorized by a user is not permanent, because the user may revoke the authorization at any time. Each time before the API protected by the permission is called, call **requestPermissionsFromUser()** to request the permission.

## Example

The procedure for requesting user authorization is as follows:

1. Obtain the ability context.
2. Call **requestPermissionsFromUser()** to request user authorization. The API determines whether to display a dialog box to request user authorization based on whether the app has the permission.
3. Check whether the app has the permission based on the return value. If the app has the permission, the API can be invoked.

```js
  // OnWindowStageCreate of the ability
  onWindowStageCreate() {
    var context = this.context
    let array:Array<string> = ["ohos.permission.PERMISSION2"];
    // requestPermissionsFromUser determines whether to display a dialog box based on the permission authorization status.
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
> **NOTE**<br>
> For details about the APIs, see [AbilityContext](../reference/apis/js-apis-ability-context.md).
