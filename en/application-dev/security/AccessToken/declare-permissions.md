# Declaring Permissions

To request permissions for your application, declare all the permissions one by one in the project configuration file.

## Declaring Permissions in the Configuration File

Declare the permissions required by your application under **requestPermissions** in the **module.json5** file.

| Field| Description| Data Type| Value Range|
| -------- | -------- | -------- | -------- |
| name | Name of the permission to request.| String| This field is mandatory. The value must be a permission defined in the system. For details, see [Permissions for All Applications](permissions-for-all.md).|
| reason | Reason for requesting the permission.| String| This field is optional. It is used for application release verification. It must be specified for a user_grant permission and support multilingual adaptation.<br>It can be referenced as a string resource in $string: \*\*\* format.<br>For details, see [Specifications for reason](#specifications-for-reason).|
| usedScene | Use case of the permission. This field is used for application release verification. It has two parameters:<br>- **abilities**: names of the abilities (UIAbility or ExtensionAbility) that use the permission.<br>- **when**: when the permission is used.| Object| **usedScene** is mandatory, where:<br>- **abilities** is optional. The value is a string array of multiple UIAbility or ExtensionAbility names<br>- **when** is optional. Set it to **inuse** or **always** for a user_grant permission. It cannot be empty when set.<br>  |

> **NOTE**<br>
> The permissions requested for a module are valid in the entire application. You do not need to request the same permissions for the project.

## Example

> **NOTE**
>
> The values **ohos.permission.PERMISSION1** and **ohos.permission.PERMISSION2** are only examples and do not exist. Set permissions to match your case.

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

## Specifications for reason

The **reason** field (reason for requesting the permission) is mandatory when a user_grant permission is requested. You must declare each required permission in the application's configuration file.

In the dialog box displayed for the user to grant the permission, the [permission group](app-permission-mgmt-overview.md#permission-groups-and-permissions) is displayed. For details about permission groups, see [Application Permission Groups](app-permission-group-list.md).

### Specifications and Suggestions for the reason Field
<!--RP1-->
1. Keep the sentence concise without redundant separators.

   **Recommended sentence pattern**: Used for something/Used to do something/Used for doing something.

   **Example**: Used for code scanning and photographing.

2. To facilitate multilingual adaptation, keep **reason** under 72 characters (36 Chinese characters displayed in two lines on the UI). It cannot exceed 256 characters.

3. If **reason** is not set, the default reason will be used.
<!--RP1End-->
### Presentation of reason

The reason for requesting a permission can be presented in two modes: authorization pop-up window and permission details page of an application in **Settings** > **Privacy** > **Permission manager**.

1. For the permissions in the **Phone**, **Messaging**, **Calendar**, **Contacts**, and **Call logs** permission groups, the content and usage of each permission requested must be presented to the user.

   **Sentence pattern**: Permissions A, used to/for ... Permission B, used to/for ...

   **Example**: Permission A, used to obtain the call status and mobile network information. Permission B, used for secure operation and statistics charging services.

2. For the permissions in other permission groups, the reason for using the first permission requested is presented to the user. The permissions are sorted as they appear in the permission groups under **Permission manager**.

   **Example**: If a permission group consists of permissions A, B, and C in sequence, and permissions C and B are requested, the reason for using permission B is presented to the user.
