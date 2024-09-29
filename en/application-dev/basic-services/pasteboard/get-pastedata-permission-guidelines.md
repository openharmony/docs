# Requesting Permissions to Access the Pasteboard

## Overview

In API version 12 and later, permission control is added to the pasteboard reading API to enhance user privacy protection.

Related APIs:

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| getData( callback: AsyncCallback&lt;PasteData&gt;): void | Reads a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.|
| getData(): Promise&lt;PasteData&gt; | Reads a **PasteData** object from the pasteboard. This API uses a promise to return the result.|
| getDataSync(): PasteData | Reads data from the system pasteboard. This API returns the result synchronously.|

## Accessing Pasteboard Content

Applications can access the pasteboard content in either of the following ways:

- Using security components

    Applications that use the [security components](../../../application-dev/security/AccessToken/pastebutton.md) to access the pasteboard content do not need to request the permission.

    Applications that use the security components can access the pasteboard content without any adaptation.

- Requesting the **ohos.permission.READ_PASTEBOARD** permission

    **READ_PASTEBOARD** is a user_grant permission. Applications that use customized components can request the **ohos.permission.READ_PASTEBOARD** permission to access the pasteboard content with user authorization.

    To request the **ohos.permission.READ_PASTEBOARD** permission, perform the following steps:

    1. Configure the required permission in **module.json5**. For details, see [Requesting Application Permissions](../../../application-dev/security/AccessToken/determine-application-mode.md).
    ```ts
    "requestPermissions": [
      {
      "name": "ohos.permission.READ_PASTEBOARD",
      }
    ]
    ```

    2. Add a user authorization dialog box before the call to **getData**.
    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { abilityAccessCtrl, common, Permissions, UIAbility, bundleManager } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
    
    async function checkAccessToken(permission: Permissions): Promise<abilityAccessCtrl.GrantStatus> {
      let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
      let grantStatus: abilityAccessCtrl.GrantStatus = abilityAccessCtrl.GrantStatus.PERMISSION_DENIED;
    
      // Obtain the token ID of the application.
      let tokenId: number = 0;
      try {
        let bundleInfo: bundleManager.BundleInfo = await bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION);
        let appInfo: bundleManager.ApplicationInfo = bundleInfo.appInfo;
        tokenId = appInfo.accessTokenId;
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to get bundle info for self. Code is ${err.code}, message is ${err.message}`);
      }
    
      // Check whether the user has granted the permission.
      try {
        grantStatus = await atManager.checkAccessToken(tokenId, permission);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to check access token. Code is ${err.code}, message is ${err.message}`);
      }
    
      return grantStatus;
    }
    
    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
      @State msgList: Array<string> = [];
      // @State oaid: string = '';
      @State permission_state: boolean = true;
    
      reqPermissionsFromUser(permissions: Array<Permissions>): void {
        let context = getContext(this) as common.UIAbilityContext;
        let atManager = abilityAccessCtrl.createAtManager();
        // The return value of requestPermissionsFromUser determines whether to display a dialog box to request user authorization.
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // If the user grants the permission, the application can continue to access the target operation.
              this.permission_state = true;
              this.msgList.push ('Permission requested successfully.');
            }
            else {
              // If the user denies the permission, display a message indicating that user authorization is required, and direct the user to set the permission in the Settings page.
              // openPermissionsInSystemSettings();
              console.error("user did not grant!")
              this.permission_state = false;
              this.msgList.push ('Failed to request the permission.');
            }
          }
          // Authorization successful.
        }).catch((err: String) => {
        })
      }
    
      async getPaste() {
        const permissions: Array<Permissions> = ['ohos.permission.READ_PASTEBOARD'];
        let grantStatus1: abilityAccessCtrl.GrantStatus = await checkAccessToken(permissions[0]);
    
        if (grantStatus1 === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
          try {
            let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
            systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
              if (err) {
                console.error('Failed to get PasteData. Cause: ' + err.message);
                return;
              }
              let text: string = pasteData.getPrimaryText();
              this.msgList.push ('Pasteboard content: '+text);
            });
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', `get oaid by promise catch error: ${err.code} ${err.message}`);
          }
        } else {
          // Request the permission.
          if(this.permission_state) {
            this.reqPermissionsFromUser(permissions)
          }else{
    
          }
        }
      }
    }
    ```
