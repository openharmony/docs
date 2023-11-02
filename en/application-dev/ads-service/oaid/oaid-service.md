# OAID Service


## When to Use

The Open Anonymous Device Identifier (OAID) is a non-permanent device identifier. The OAID service provides personalized ads for users while protecting their personal data privacy. It can also interact with third-party tracking platforms to provide conversion attribution analysis for advertisers.

No matter whether you are running a media application, an ad platform, or a tracking platform, you can obtain OAID information from devices. The OAID information can be used to recommend personalized ads to users and attribute ad conversions.


## Available APIs

| API| Description|
| -------- | -------- |
| [getOAID()](../../reference/apis/js-apis-oaid.md#identifiergetoaid):Promise&lt;string&gt; | Obtains an OAID. This API uses a promise to return the result.|
| [getOAID(callback:&nbsp;AsyncCallback&lt;string&gt;)](../../reference/apis/js-apis-oaid.md#identifiergetoaid-1):&nbsp;void | Obtains an OAID. This API uses an asynchronous callback to return the result.|
| [resetOAID()](../../reference/apis/js-apis-oaid.md#identifierresetoaid):&nbsp;void | Resets an OAID. This is a system API.|


## How to Develop

1. In the **module.json5** file of the module, configure the [ohos.permission.APP_TRACKING_CONSENT](../../security/permission-list.md#ohospermissionapp_tracking_consent) permission. The sample code is as follows:
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

2. Request authorization from the user by displaying a dialog box when the application is started. The sample code is as follows:
   ```
   import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
   import { BusinessError } from '@ohos.base';
   import hilog from '@ohos.hilog';
   
   private requestOAIDTrackingConsentPermissions2(context: common.Context): void {
     // Display a dialog box when the page is displayed to request the user to grant the ad tracking permission.
     const atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
      try {
        atManager.requestPermissionsFromUser(context, ["ohos.permission.APP_TRACKING_CONSENT"]).then((data) => {
          if (data.authResults[0] == 0) {
            hilog.info(0x0000, 'testTag', '%{public}s', 'request permission success');
          } else {
            hilog.info(0x0000, 'testTag', '%{public}s', `user rejected`);
          }
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', '%{public}s', `request permission failed, error message: ${err.message}`);
        })
      } catch(err) {
        hilog.error(0x0000, 'testTag', '%{public}s', `catch err->${JSON.stringify(err)}`);
      }
    }
   ```
   
3. Call **getOAID()** to obtain OAID information. The sample code is as follows:
   ```
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   import { BusinessError } from '@ohos.base';
    
   try {
     identifier.getOAID((err: BusinessError, data) => {
       if (err.code) {
         hilog.info(0x0000, 'testTag', '%{public}s', `get oaid failed, message: ${err.message}`);
       } else {
         const oaid: string = data;
         hilog.info(0x0000, 'testTag', '%{public}s', `get oaid by callback success`);
       }
      });
   } catch (err) {
     hilog.error(0x0000, 'testTag', 'get oaid catch error: %{public}d %{public}s', err.code, err.message);
   }
   ```
   
4. Call **setOAID()** (a system API) to reset the OAID information. The sample code is as follows:
   ```
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   
   // Reset the OAID.
   try {
     identifier.resetOAID();
   } catch (err) {
     hilog.error(0x0000, 'testTag', 'reset oaid catch error: %{public}d %{public}s', err.code, err.message);
   }
   ```
