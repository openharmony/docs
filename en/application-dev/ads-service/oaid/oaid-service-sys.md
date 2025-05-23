# Resetting OAID Information (for System Applications Only)

## When to Use

The OAID changes in the following scenarios:
- A user restores the factory settings of the device.

- A system application configures its bundle name in the **etc/advertising/oaid/oaid_service_config.json** file in the device's system directory and calls the **resetOAID()** API to reset the OAID. Note that the bundle name should be appended to the array in the file and separated with others by commas (,).

The following describes how to configure a system application to reset the OAID.

## Available APIs

| API| Description|
| -------- | -------- |
| [resetOAID()](../../reference/apis-ads-kit/js-apis-oaid-sys.md#identifierresetoaid):&nbsp;void | Resets an OAID. This is a system API.|


## How to Develop

1. In the **module.json5** file of the module, configure the [ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapp_tracking_consent) permission. The sample code is as follows:
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

2. Request authorization from the user in a dialog box when the application is started. For details about how to obtain the context, see [Context](../../application-models/application-context-stage.md). The sample code is as follows:
   ```ts
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
   
3. Call **resetOAID()** (a system API) to reset the OAID. The sample code is as follows:
   ```ts
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   
   // Reset the OAID.
   try {
     identifier.resetOAID();
   } catch (err) {
     hilog.error(0x0000, 'testTag', '%{public}s', `reset oaid catch error: ${err.code} ${err.message}`);
   }
   ```
