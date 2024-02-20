# 广告标识服务

## 获取OAID信息


### 场景介绍

开放匿名设备标识符（Open Anonymous Device Identifier, OAID，以下简称OAID）：是一种非永久性设备标识符，基于开放匿名设备标识符，可在保护用户个人数据隐私安全的前提下，向用户提供个性化广告，同时三方监测平台也可以向广告主提供转化归因分析。

媒体App、广告平台、三方监测平台等开发者，可获取设备上的OAID，您可基于OAID进行个性化广告推荐或广告转化归因分析。

OAID是基于华为自有算法生成的32位类UUID（Universally Unique Identifier）标识符，格式为xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx。

OAID的特性：
- OAID是设备级标识符，同一台设备上不同的App获取到的OAID值一样。
- OAID的获取受应用的跟踪开关影响：当应用的跟踪开关开启时，该应用可获取到OAID；当应用的跟踪开关关闭时，该应用仅能获取到全0的OAID。
- 同一台设备上首个应用开启应用跟踪开关时，会首次生成OAID。

OAID会在下述场景中发生变化：
- 用户恢复手机出厂设置。

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [resetOAID()](../../reference/apis/js-apis-oaid.md#identifierresetoaid):&nbsp;void | 重置OAID，此接口为系统接口。 |


### 开发步骤

1. 在模块的module.json5文件中，申请广告跟踪权限[ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all.md#ohospermissionapp_tracking_consent)。示例代码如下所示：
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

   在应用启动时触发动态授权弹框，向用户请求授权。其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md)。示例代码如下所示：
   ```
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
   
2. 调用resetOAID方法重置OAID信息，此接口为系统接口。示例代码如下所示：
   ```
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   
   // 重置OAID
   try {
     identifier.resetOAID();
   } catch (err) {
     hilog.error(0x0000, 'testTag', '%{public}s', `reset oaid catch error: ${err.code} ${err.message}`);
   }
   ```
