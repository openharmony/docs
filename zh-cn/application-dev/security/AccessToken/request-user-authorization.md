# 向用户申请授权


当应用需要访问用户的隐私信息或使用系统能力时，例如获取位置信息、访问日历、使用相机拍摄照片或录制视频等，应该向用户请求授权，这部分权限是user_grant权限。


当应用申请user_grant权限时，需要完成以下步骤：


1. 在配置文件中，声明应用需要请求的权限。

2. 将应用中需要申请权限的目标对象与对应目标权限进行关联，让用户明确地知道，哪些操作需要用户向应用授予指定的权限。
   以上两步请参考章节[声明权限](declare-permissions.md)完成。

3. 运行应用时，在用户触发访问操作目标对象时应该调用接口，精准触发动态授权弹框。该接口的内部会检查当前用户是否已经授权应用所需的权限，如果当前用户尚未授予应用所需的权限，该接口会拉起动态授权弹框，向用户请求授权。

4. 检查用户的授权结果，确认用户已授权才可以进行下一步操作。


本章节会介绍如何完成步骤3和4。


## 约束与限制

- 每次执行需要目标权限的操作时，应用都必须检查自己是否已经具有该权限。
  
  如需检查用户是否已向您的应用授予特定权限，可以使用[checkAccessToken()](../../reference/apis/js-apis-abilityAccessCtrl.md#checkaccesstoken9)函数，此方法会返回[PERMISSION_GRANTED](../../reference/apis/js-apis-abilityAccessCtrl.md#grantstatus)或[PERMISSION_DENIED](../../reference/apis/js-apis-abilityAccessCtrl.md#grantstatus)。具体示例可参考下文。

- 每次访问受目标权限保护的接口之前，都需要使用[requestPermissionsFromUser()](../../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)接口请求相应的权限。
 
  用户可能在动态授予权限后通过系统设置来取消应用的权限，因此不能将之前授予的授权状态持久化。

- user_grant权限授权要基于用户可知可控的原则，需要应用在运行时主动调用系统动态申请权限的接口，系统弹框由用户授权，用户结合应用运行场景的上下文，识别出应用申请相应敏感权限的合理性，从而做出正确的选择。


## 开发步骤

以申请使用麦克风权限为例进行说明。

效果展示：

![zh-cn_image_0000001701708034](figures/zh-cn_image_0000001701708034.png)

1. 申请ohos.permission.MICROPHONE权限，配置方式请参见[声明权限](declare-permissions.md)。

2. 校验当前是否已经授权。
   
   在进行权限申请之前，需要先检查当前应用程序是否已经被授予权限。可以通过调用[checkAccessToken()](../../reference/apis/js-apis-abilityAccessCtrl.md#checkaccesstoken9)方法来校验当前是否已经授权。如果已经授权，则可以直接访问目标操作，否则需要进行下一步操作，即向用户申请授权。

   ```ts
   import bundleManager from '@ohos.bundle.bundleManager';
   import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
   import { BusinessError } from '@ohos.base';
   
   const permissions: Array<Permissions> = ['ohos.permission.MICROPHONE'];
   
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
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to get bundle info for self. Code is ${err.code}, message is ${err.message}`);
     }
   
     // 校验应用是否被授予权限
     try {
       grantStatus = await atManager.checkAccessToken(tokenId, permission);
     } catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to check access token. Code is ${err.code}, message is ${err.message}`);
     }
   
     return grantStatus;
   }
   
   async function checkPermissions(): Promise<void> {
     let grantStatus: abilityAccessCtrl.GrantStatus = await checkAccessToken(permissions[0]);
   
     if (grantStatus === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
       // 已经授权，可以继续访问目标操作
     } else {
       // 申请日历权限
     }
   }
   ```

3. 动态向用户申请授权。
   
   动态向用户申请权限是指在应用程序运行时向用户请求授权的过程。可以通过调用[requestPermissionsFromUser()](../../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)方法来实现。该方法接收一个权限列表参数，例如位置、日历、相机、麦克风等。用户可以选择授予权限或者拒绝授权。

   可以在UIAbility的onWindowStageCreate()回调中调用[requestPermissionsFromUser()](../../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)方法来动态申请权限，也可以根据业务需要在UI中向用户申请授权。

   - 在UIAbility中向用户申请授权。
      
      ```ts
      import UIAbility from '@ohos.app.ability.UIAbility';
      import window from '@ohos.window';
      import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
      import common from '@ohos.app.ability.common';
      import { BusinessError } from '@ohos.base';
      
      const permissions: Array<Permissions> = ['ohos.permission.MICROPHONE'];
      
      function reqPermissionsFromUser(permissions: Array<Permissions>, context: common.UIAbilityContext): void {
        let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
        // requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // 用户授权，可以继续访问目标操作
            } else {
              // 用户拒绝授权，提示用户必须授权才能访问当前页面的功能，并引导用户到系统设置中打开相应的权限
              return;
            }
          }
          // 授权成功
        }).catch((err: BusinessError) => {
          console.error(`Failed to request permissions from user. Code is ${err.code}, message is ${err.message}`);
        })
      }
      
      export default class EntryAbility extends UIAbility {
        onWindowStageCreate(windowStage: window.WindowStage): void {
          reqPermissionsFromUser(permissions, this.context);
          // ...
        }
      
        // ...
      }
      ```
   - 在UI中向用户申请授权。
      
      ```ts
      import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';
      import common from '@ohos.app.ability.common';
      import { BusinessError } from '@ohos.base';
      
      const permissions: Array<Permissions> = ['ohos.permission.MICROPHONE'];
      
      function reqPermissionsFromUser(permissions: Array<Permissions>, context: common.UIAbilityContext): void {
        let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
        // requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
        atManager.requestPermissionsFromUser(context, permissions).then((data) => {
          let grantStatus: Array<number> = data.authResults;
          let length: number = grantStatus.length;
          for (let i = 0; i < length; i++) {
            if (grantStatus[i] === 0) {
              // 用户授权，可以继续访问目标操作
            } else {
              // 用户拒绝授权，提示用户必须授权才能访问当前页面的功能，并引导用户到系统设置中打开相应的权限
              return;
            }
          }
          // 授权成功
        }).catch((err: BusinessError) => {
          console.error(`Failed to request permissions from user. Code is ${err.code}, message is ${err.message}`);
        })
      }
      
      @Entry
      @Component
      struct Index {
        aboutToAppear() {
          const context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
          reqPermissionsFromUser(permissions, context);
        }
      
        build() {
          // ...
        }
      }
      ```

4. 处理授权结果。
   
   调用[requestPermissionsFromUser()](../../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)方法后，应用程序将等待用户授权的结果。如果用户授权，则可以继续访问目标操作。如果用户拒绝授权，则需要提示用户必须授权才能访问当前页面的功能，并引导用户到系统设置中打开相应的权限。

   ```ts
   import Want from '@ohos.app.ability.Want';
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   
   function openPermissionsInSystemSettings(context: common.UIAbilityContext): void {
     let wantInfo: Want = {
       action: 'action.settings.app.info',
       parameters: {
         settingsParamBundleName: 'com.example.myapplication' // 打开指定应用的详情页面
       }
     }
     context.startAbility(wantInfo).then(() => {
       // ...
     }).catch((err: BusinessError) => {
       // ...
     })
   }
   ```
