# 申请访问剪贴板权限

## 概述

API version 12及之后，系统为提升用户隐私安全保护能力，剪贴板读取接口增加权限管控。

涉及接口如下：

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| getData( callback: AsyncCallback&lt;PasteData&gt;): void | 读取系统剪贴板内容，使用callback异步回调。 |
| getData(): Promise&lt;PasteData&gt; | 读取系统剪贴板内容，使用Promise异步回调。 |
| getDataSync(): PasteData | 读取系统剪贴板内容, 此接口为同步接口。 |

## 访问剪贴板内容

剪贴板为应用提供如下两种访问内容的方式。

- 使用安全控件

    使用[安全控件](../../../application-dev/security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

    已经使用了安全控件的应用无需做任何适配就可以访问剪贴板内容。

- 申请ohos.permission.READ_PASTEBOARD权限

    READ_PASTEBOARD是一个user_grant（用户授权）权限，使用自定义控件的应用可以通过申请ohos.permission.READ_PASTEBOARD权限，在用户授权的场景下访问剪贴板内容。

    申请ohos.permission.READ_PASTEBOARD权限步骤：

    1.在module.json5中配置所需申请的权限，更详细的申请流程请参考[申请应用权限](../../../application-dev/security/AccessToken/determine-application-mode.md)。
    ```ts
    "requestPermissions": [
      {
      "name": "ohos.permission.READ_PASTEBOARD",
      }
    ]
    ```

    2.在调用getData接口之前增加用户授权弹窗。
    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { abilityAccessCtrl, common, Permissions, UIAbility, bundleManager } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
    
    async function checkAccessToken(permission: Permissions): Promise<abilityAccessCtrl.GrantStatus> {
      let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
      let grantStatus: abilityAccessCtrl.GrantStatus = abilityAccessCtrl.GrantStatus.PERMISSION_DENIED;
    
      // 获取应用程序的accessTokenID
      let tokenId: number = 0;
      try {
        let bundleInfo: bundleManager.BundleInfo = await bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION);
        let appInfo: bundleManager.ApplicationInfo = bundleInfo.appInfo;
        tokenId = appInfo.accessTokenId;
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`Failed to get bundle info for self. Code is ${err.code}, message is ${err.message}`);
      }
    
      // 校验应用是否被授予权限
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
        // requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // 用户授权，可以继续访问目标操作
              this.permission_state = true;
              this.msgList.push('申请权限成功');
            }
            else {
              // 用户拒绝授权，提示用户必须授权才能访问当前页面的功能，并引导用户到系统设置中打开相应的权限
              // openPermissionsInSystemSettings();
              console.error("user did not grant!")
              this.permission_state = false;
              this.msgList.push('申请权限失败');
            }
          }
          // 授权成功
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
              this.msgList.push('剪贴板内容：'+text);
            });
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', `get oaid by promise catch error: ${err.code} ${err.message}`);
          }
        } else {
          // 申请权限
          if(this.permission_state) {
            this.reqPermissionsFromUser(permissions)
          }else{
    
          }
        }
      }
    }
    ```