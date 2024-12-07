# OAID Service

## When to Use

An Open Anonymous Device Identifier (OAID) is a non-permanent device identifier. The OAID service is useful for media application developers, ad platforms, and tracking platforms alike. Specifically, it provides personalized ads for users while protecting their personal data privacy, and also interact with third-party tracking platforms to provide conversion attribution analysis for advertisers.

An OAID is a 32-bit Universally Unique Identifier (UUID) generated using a Huawei algorithm. The format is xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx.

The OAID has the following features:
- The OAID is device specific. Different applications on the same device obtain the same OAID.
- The OAID obtained depends on the switch of the **ohos.permission.APP_TRACKING_CONSENT** permission. When the switch is enabled, the application obtains a valid OAID that is not all zeros. When the switch is disabled, the application obtains an all-zero OAID.
- An OAID is generated when any application on the device enables the **ohos.permission.APP_TRACKING_CONSENT** permission for the first time.

The OAID changes in the following scenarios:
- A user restores the factory settings of the device.
- A user resets the OAID.

### Available APIs

| API| Description|
| -------- | -------- |
| <!--Del-->[<!--DelEnd-->getOAID<!--Del-->](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid)<!--DelEnd-->(): Promise&lt;string&gt; | Obtains an OAID. This API uses a promise to return the result.|
| <!--Del-->[<!--DelEnd-->getOAID<!--Del-->](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid-1)<!--DelEnd-->(callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp; void | Obtains an OAID. This API uses an asynchronous callback to return the result.|

> **NOTE**
> To call **getOAID()**, the application must request the permission **ohos.permission.APP_TRACKING_CONSENT** and user authorization. Three situations are possible:
>
> - If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is allowed, the OAID is returned.
> - If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is disallowed, 00000000-0000-0000-0000-000000000000 is returned.
> - If the application has not configured the permission **ohos.permission.APP_TRACKING_CONSENT**, 00000000-0000-0000-0000-000000000000 is returned.


## How to Develop
1. In the **module.json5** file of the module, configure the permission [ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all.md#ohospermissionapp_tracking_consent), which is a user_grant permission. In this case, the **reason** and **abilities** fields are mandatory. For details about the configuration, see [Declaring Permissions in the Configuration File](../../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file). 
   
   The sample code is as follows:
   
   ```ts
   {
     "module": {
       "requestPermissions": [
         {
           "name": "ohos.permission.APP_TRACKING_CONSENT",
           "reason": "$string:reason",
           "usedScene": {
             "abilities": [
               "EntryFormAbility"
             ],
             "when": "inuse"
           }
         }
       ]
     }
   }
   ```

2. To obtain the OAID, the application must call **requestPermissionFromUser** to obtain the corresponding permission. For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md).

   The sample code is as follows:

   ```ts
   import { identifier } from '@kit.AdsKit';
   import { abilityAccessCtrl, common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function requestOAIDTrackingConsentPermissions(context: common.Context): void {
     // When the page is displayed, request the user to grant the permission ohos.permission.APP_TRACKING_CONSENT.
     const atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
     try {
       atManager.requestPermissionsFromUser(context, ["ohos.permission.APP_TRACKING_CONSENT"]).then((data) => {
         if (data.authResults[0] == 0) {
           hilog.info(0x0000, 'testTag', '%{public}s', 'succeeded in requesting permission');
           identifier.getOAID((err: BusinessError, data: string) => {
			 if (err.code) {
			   hilog.error(0x0000, 'testTag', '%{public}s', `get oaid failed, error: ${err.code} ${err.message}`);
			 } else {
			   const oaid: string = data;
			   hilog.info(0x0000, 'testTag', '%{public}s', `succeeded in getting oaid by callback , oaid: ${oaid}`);
			 }
           });
         } else {
           hilog.error(0x0000, 'testTag', '%{public}s', 'user rejected');
         }
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', '%{public}s', `request permission failed, error: ${err.code} ${err.message}`);
       })
     } catch (err) {
       hilog.error(0x0000, 'testTag', '%{public}s', `catch err->${err.code}, ${err.message}`);
     }
   }
   ```
