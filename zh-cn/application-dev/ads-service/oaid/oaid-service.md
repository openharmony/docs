# 广告标识服务

## 获取OAID信息


### 场景介绍

开放匿名设备标识符（Open Anonymous Device Identifier, OAID，以下简称OAID）：是一种非永久性设备标识符，基于开放匿名设备标识符，可在保护用户个人数据隐私安全的前提下，向用户提供个性化广告，同时三方监测平台也可以向广告主提供转化归因分析。

媒体App、广告平台、三方监测平台等开发者，可获取设备上的OAID，您可基于OAID进行个性化广告推荐或广告转化归因分析。


### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [getOAID()](../../reference/apis/js-apis-oaid.md#identifiergetoaid):Promise&lt;string&gt; | 获取OAID，通过Promise异步返回结果。 |
| [getOAID(callback:&nbsp;AsyncCallback&lt;string&gt;)](../../reference/apis/js-apis-oaid.md#identifiergetoaid-1):&nbsp;void | 获取OAID，通过Callback回调返回值。 |
| [resetOAID()](../../reference/apis/js-apis-oaid.md#identifierresetoaid):&nbsp;void | 重置OAID，此接口为系统接口。 |


### 开发步骤

1. 在模块的module.json5文件中，申请广告跟踪权限[ohos.permission.APP_TRACKING_CONSENT](../../security/permission-list.md#ohospermissionapp_tracking_consent)。示例代码如下所示：
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
   
2. 调用getOAID方法获取OAID信息。示例代码如下所示：
   ```
   import identifier from '@ohos.identifier.oaid';
   import hilog from '@ohos.hilog'; 
   import { BusinessError } from '@ohos.base';
    
   try {
     identifier.getOAID((err: BusinessError, data: string) => {
       if (err.code) {
         hilog.error(0x0000, 'testTag', '%{public}s', `get oaid failed, error: ${err.code} ${err.message}`);
       } else {
         const oaid: string = data;
         hilog.info(0x0000, 'testTag', '%{public}s', `get oaid by callback success, oaid: ${oaid}`);
       }
      });
   } catch (err) {
     hilog.error(0x0000, 'testTag', '%{public}s', `get oaid catch error: ${err.code} ${err.message}`);
   }
   ```
   
3. 调用setOAID方法重置OAID信息，此接口为系统接口。示例代码如下所示：
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
