# OAID Service

## When to Use

An Open Anonymous Device Identifier (OAID) is a non-permanent device identifier. The OAID service is useful for media application developers, ad platforms, and tracking platforms alike. Specifically, it provides personalized ads for users while protecting their personal data privacy, and also interact with third-party tracking platforms to provide conversion attribution analysis for advertisers.

An OAID is a 32-bit Universally Unique Identifier (UUID) generated using a Huawei algorithm. The format is xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx.

The OAID has the following features:
- The OAID is device specific. Different applications on the same device obtain the same OAID.
- The OAID obtained depends on the tracing function of the application. When tracing of the application is enabled, the application obtains a valid OAID. When tracing is disabled, the application obtains an all-zero OAID.
- An OAID is generated when any application on the device enables tracking for the first time.
- The OAID changes when the user restores the factory settings of the device.

## Available APIs

| API| Description|
| -------- | -------- |
| [resetOAID()](../../reference/apis-ads-kit/js-apis-oaid-sys.md#identifierresetoaid):&nbsp;void | Resets an OAID. This is a system API.|


## How to Develop

1. In the **module.json5** file of the module, configure the [ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all.md#ohospermissionapp_tracking_consent) permission. The sample code is as follows:
   ```
   {
     "module": {
       "requestPermissions": [
         {
         "name": "ohos.permission.APP_TRACKING_CONSENT"
         }
       ]
     }
    }
   ```

2. Request authorization from the user in a dialog box when the application is started. For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md). The sample code is as follows:
   ```
   import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
   import { BusinessError } from '@ohos.base';
   import hilog from '@ohos.hilog';
   import common from '@ohos.app.ability.common';
   
   function requestOAIDTrackingConsentPermissions(context: common.Context): void {
     // Display a dialog box when the page is displayed to request the user to grant the ad tracking permission.
     const atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
      try {
        atManager.requestPermissionsFromUser(context, ["ohos.permission.APP_TRACKING_CONSENT"]).then((data) => {
          if (data.authResults[0] == 0) {
            hilog.info(0x0000, 'testTag', '%{public}s', 'request permission success');
          } else {
            hilog.info(0x0000, 'testTag', '%{public}s', 'user rejected');
          }
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', '%{public}s', `request permission failed, error: ${err.code} ${err.message}`);
        })
      } catch(err) {
        hilog.error(0x0000, 'testTag', '%{public}s', `catch err->${err.code}, ${err.message}`);
      }
    }
   ```
   
3. Call **resetOAID()** (a system API) to reset the OAID. The sample code is as follows:
   ```
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   
   // Reset the OAID.
   try {
     identifier.resetOAID();
   } catch (err) {
     hilog.error(0x0000, 'testTag', '%{public}s', `reset oaid catch error: ${err.code} ${err.message}`);
   }
   ```
