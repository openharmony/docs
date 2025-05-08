# Workflow for Requesting Permissions

You need to determine whether your application needs related permissions before accessing data or performing an operation. If permissions are required, request the permissions in the application installation package.

The procedure for requesting a permission varies depending on the permission level and authorization mode. Before requesting a permission, you need to:

1. Determine the permission type in the related permission list.
2. Request the permission by following the corresponding operation path.

 

## Requesting Permissions for <!--Del-->normal <!--DelEnd-->Applications

| Permission Type| Authorization Mode| Operation Path|
| -------- | -------- | -------- |
| [Open system_grant permission](permissions-for-all.md)| system_grant | [Declare permission](declare-permissions.md) &gt; Access API| 
| [Open user_grant permission](permissions-for-all-user.md)| user_grant  | [Declare permission](declare-permissions.md) &gt; [Request user authorization](request-user-authorization.md) &gt; Access API| 
| <!--Del-->[system_grant permission available for system applications via ACL](permissions-for-system-apps.md)<br><!--DelEnd-->[Restricted permission](restricted-permissions.md)| system_grant | <!--RP1-->[Request restricted permission](declare-permissions-in-acl.md)<!--RP1End--> &gt; [Declare permission](declare-permissions.md) > Access API| 
| <!--Del-->[user_grant permission available for system applications via ACL](permissions-for-system-apps-user.md)<br><!--DelEnd-->[Restricted permission](restricted-permissions.md)| user_grant | <!--RP1-->[Request restricted permission](declare-permissions-in-acl.md)<!--RP1End--> &gt; [Declare permission](declare-permissions.md) > [Request user authorization](request-user-authorization.md) > Access API|

<!--Del-->
> **NOTE**
>
> - A normal application cannot request a system_basic permission whose **Enable via ACL** is **false**.
> - You can use DevEco Studio to [request a permission via ACL](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing). However, this approach applies to the applications in debug phase, but not to the applications to be released to an app market. For a commercial application, apply for a release certificate and profile in the app market.

## Requesting Permissions for system_basic Applications

| Permission APL| Authorization Mode| Enable via ACL| Operation Path| 
| -------- | -------- | -------- | -------- |
| normal or system_basic| system_grant | - | [Declare permission](declare-permissions.md) &gt; Access API| 
| normal or system_basic| user_grant | - | [Declare permission](declare-permissions.md) &gt; [Request user authorization](request-user-authorization.md) &gt; Access API| 
| system_core | system_grant | true | [Request restricted permission](declare-permissions-in-acl.md) &gt; [Declare permission](declare-permissions.md) > Access API| 
| system_core | user_grant | true | [Request restricted permission](declare-permissions-in-acl.md) &gt; [Declare permission](declare-permissions.md) > [Request user authorization](request-user-authorization.md) > Access API| 

To change the application APL to system_basic or system_core, modify the HarmonyAppProvision file (**Toolchains / _{Version} _/ lib / UnsgnedReleasedProfileTemplate.json** file in the SDK directory) of the application when developing the application installation package, and sign the application again.

**Example**

Modify the **"bundle-info"** &gt; **"apl"** field in the file.

```json
"bundle-info" : {
    // ...
    "apl": "system_basic",
    // ...
},
```

> **NOTE**
> Modifying the HarmonyAppProvision configuration file applies to the applications in the debug phase, but not to the applications released to the app market. For a commercial application, apply for a release certificate and profile in the app market.

<!--DelEnd-->
