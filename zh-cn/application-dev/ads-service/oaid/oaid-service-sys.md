# 重置OAID信息（仅对系统应用开放）

## 场景介绍

OAID会在下述场景中发生变化：
- 用户恢复手机出厂设置。
- 系统应用将bundleName配置到设备侧系统目录中，文件路径：etc/advertising/oaid/oaid_service_config.json，配置方式：用英文逗号隔开，添加到数组末尾。即可主动调用resetOAID()接口重置OAID。
下面为系统应用开发者给出重置OAID的开发指导。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [resetOAID()](../../reference/apis-ads-kit/js-apis-oaid-sys.md#identifierresetoaid):&nbsp;void | 重置OAID，此接口为系统接口。 |


## 开发步骤

1. 在模块的module.json5文件中，申请广告跟踪权限[ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapp_tracking_consent)。示例代码如下所示：
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

   在应用启动时触发动态授权弹框，向用户请求授权。其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md)。示例代码如下所示：
   ```ts
   import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
   import { BusinessError } from '@ohos.base';
   import hilog from '@ohos.hilog';
   import common from '@ohos.app.ability.common';
   
   function requestOAIDTrackingConsentPermissions(context: common.Context): void {
     // 进入页面时触发动态授权弹框，向用户请求授权广告跟踪权限
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
   
2. 调用resetOAID方法重置OAID信息，此接口为系统接口。示例代码如下所示：
   ```ts
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   
   // 重置OAID
   try {
     identifier.resetOAID();
   } catch (err) {
     hilog.error(0x0000, 'testTag', '%{public}s', `reset oaid catch error: ${err.code} ${err.message}`);
   }
   ```
