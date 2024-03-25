# Window Subsystem Changelog

## cl.window.1 New Error Code Added for setWindowPrivacyMode

**Access Level**

Public API

**Reason for Change**

According to the API reference of **setWindowPrivacyMode**, the **ohos.permission.PRIVACY_WINDOW** permission is required for calling this API. However, if the permission is not carried, error code 201 is not returned.

**Change Impact**

This change is a non-compatible change. When an application calls **setWindowPrivacyMode** without requesting the **ohos.permission.PRIVACY_WINDOW** permission, error code 201 is returned. The application needs to handle the error.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

Before the change, if the application calls **setWindowPrivacyMode** without carrying the **ohos.permission.PRIVACY_WINDOW** permission, no error code indicating permission verification failure is returned. However, the setting fails.

After the change, if the application calls **setWindowPrivacyMode** without carrying the **ohos.permission.PRIVACY_WINDOW** permission, error code 201 indicating permission verification failure is returned, and the setting fails.

**Adaptation Guide**

If the **ohos.permission.PRIVACY_WINDOW** permission is not configured when the application calls **setWindowPrivacyMode**, error code 201 is returned through the callback. Handle the error.

```
import { UIAbility }from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
        console.log('onWindowStageCreate');
        let promise = windowStage.getMainWindow();
        promise.then((windowClass: window.Window)=>{
            windowClass.setWindowPrivacyMode(true, (err: BusinessError)=> {
                if (err.code) {
                    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in setting the window to privacy mode.');
            });
        }).catch((err: BusinessError)=>{
            console.log("Failed to get main window. Cause:" + JSON.stringify(err));
        })
    }
};
```
