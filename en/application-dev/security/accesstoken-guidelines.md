# Access Control Development

## When to Use

In this example, the app requires the **ohos.permission.PERMISSION1** and **ohos.permission.PERMISSION2** permissions to implement core functions.

- The ability privilege level (APL) of the app is **normal**.
- The level of **ohos.permission.PERMISSION1** is **normal**, and the authorization mode is **system_grant**.
- The level of **ohos.permission.PERMISSION2** is **system_basic**, and the authorization mode is **user_grant**.

> **NOTICE**
>
> In this scenario, the required permissions include a **user_grant** permission. You can check whether the caller has the required permission through permission verification.
>
> If the permission verification result indicates that the app has not obtained that permission, dynamic user authorization is required.
>
## Available APIs

The table below lists only the API used in this guide. For more information, see the [API Reference](../reference/apis/js-apis-abilityAccessCtrl.md).

| API                                                      | Description                                            |
| ------------------------------------------------------------ | --------------------------------------------------- |
| verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | Verifies whether an app has the specified permission. This API uses a promise to return the result.|

## Declaring Permissions

### config.json

Declare the permissions required by the app one by one in the **config.json** file. The app can obtain permissions that have been declared in the **config.json** file.

**Description of config.json**

| Field     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| name      | Name of the permission.                                                  |
| reason    | Reason for requesting the permission. This field is mandatory for a user_grant permission.|
| usedScene | Scenario of the permission. This field is mandatory for a user_grant permission.|
| abilities | Abilities that use the permission. The value is an array.|
| when      | Time when the permission is used. The value can be **inuse** (the permission can be used only in the foreground) or **always** (the permission can be used in foreground and background).|

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
        ],
    }
}
```
## Declaring the ACL

The permission level of **ohos.permission.PERMISSION2** is **system_basic**, which is higher than the app's APL. In this case, use the ACL.

In addition to declaring all the permissions in the **config.json** file, you must declare the permissions whose levels are higher than the app's APL in the app's [profile](../quick-start/app-provision-structure.md). In this example, declare the permission under the **acls** field:
```json
{
    "version-name": "1.0.0",
    "version-code": 1,
    "app-distribution-type": "os_integration",
    "uuid": "5027b99e-5f9e-465d-9508-a9e0134ffe18",
    "validity": {
        "not-before": 1594865258,
        "not-after": 1689473258
    },
    "type": "release",
    "bundle-info": {
        "developer-id": "OpenHarmony",
        "distribution-certificate": "-----BEGIN CERTIFICATE-----\nMIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMGMxCzAJBgNVBAYTAkNO\nMRQwEgYDVQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVh\nbTEjMCEGA1UEAxMaT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gQ0EwHhcNMjEwMjAy\nMTIxOTMxWhcNNDkxMjMxMTIxOTMxWjBoMQswCQYDVQQGEwJDTjEUMBIGA1UEChML\nT3Blbkhhcm1vbnkxGTAXBgNVBAsTEE9wZW5IYXJtb255IFRlYW0xKDAmBgNVBAMT\nH09wZW5IYXJtb255IEFwcGxpY2F0aW9uIFJlbGVhc2UwWTATBgcqhkjOPQIBBggq\nhkjOPQMBBwNCAATbYOCQQpW5fdkYHN45v0X3AHax12jPBdEDosFRIZ1eXmxOYzSG\nJwMfsHhUU90E8lI0TXYZnNmgM1sovubeQqATo1IwUDAfBgNVHSMEGDAWgBTbhrci\nFtULoUu33SV7ufEFfaItRzAOBgNVHQ8BAf8EBAMCB4AwHQYDVR0OBBYEFPtxruhl\ncRBQsJdwcZqLu9oNUVgaMAwGCCqGSM49BAMDBQADaAAwZQIxAJta0PQ2p4DIu/ps\nLMdLCDgQ5UH1l0B4PGhBlMgdi2zf8nk9spazEQI/0XNwpft8QAIwHSuA2WelVi/o\nzAlF08DnbJrOOtOnQq5wHOPlDYB4OtUzOYJk9scotrEnJxJzGsh/\n-----END CERTIFICATE-----\n",
        "bundle-name": "com.ohos.permissionmanager",
		"apl": "system_core",
        "app-feature": "hos_system_app"
    },
    "acls": {
        "allowed-acls": [
            "ohos.permission.PERMISSION2"
        ]
    },
    "permissions": {
        "restricted-permissions": []
    },
    "issuer": "pki_internal"
}
```

## Applying for the user_grant Permission

After the permissions are declared, the system grants the system_grant permission during the installation of the app. The user_grant permission must be authorized by the user.

Therefore, before allowing the app to call the API protected by the **ohos.permission.PERMISSION2** permission, the system needs to verify whether the app has the permission to do so.

If the verification result indicates that the app has the permission, the app can access the target API. Otherwise, the app needs to request user authorization and then proceeds based on the authorization result. For details, see [Access Control Overview](accesstoken-overview.md).

> **Precautions**
>
> The permissions authorized by user are not permanent, because the user may revoke the authorization at any time. Therefore, even if the user has granted the requested permission to an app, the app's permission must be verified before the app calls an API protected by the permission.

## Example

The procedure is as follows:

1. Obtain the ability context.
2. Call **requestPermissionsFromUser** to verify whether the app has required permissions.
3. Proceed based on the permission verification result.

```js
  // OnWindowStageCreate lifecycle of the ability
  onWindowStageCreate() {
    var context = this.context
    let array:Array<string> = ["ohos.permission.PERMISSION2"];
    // requestPermissionsFromUser determines whether to invoke a pop-up window based on the permission authorization status.
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
> For details about how to use **requestPermissionsFromUser**, see [API Reference](../reference/apis/js-apis-ability-context.md).
