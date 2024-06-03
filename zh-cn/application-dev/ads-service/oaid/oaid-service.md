# 广告标识服务

## 获取OAID信息


### 场景介绍

开放匿名设备标识符（Open Anonymous Device Identifier, OAID，以下简称OAID）：是一种非永久性设备标识符，基于开放匿名设备标识符，可在保护用户个人数据隐私安全的前提下，向用户提供个性化广告，同时三方监测平台也可以向广告主提供转化归因分析。

媒体App、广告平台、三方监测平台等开发者，可获取设备上的OAID，您可基于OAID进行个性化广告推荐或广告转化归因分析。

OAID是基于华为自有算法生成的32位类UUID（Universally Unique Identifier）标识符，格式为xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx。

OAID的特性：
- OAID是设备级标识符，同一台设备上不同的App获取到的OAID值一样。
- OAID的获取受应用的跟踪开关影响：当应用的跟踪开关开启时，该应用可获取到非全0的有效OAID；当应用的跟踪开关关闭时，该应用仅能获取到全0的OAID。
- 同一台设备上首个应用开启应用跟踪开关时，会首次生成OAID。

OAID会在下述场景中发生变化：
- 用户恢复手机出厂设置。
- 用户操作重置OAID。

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [getOAID](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid)(): Promise&lt;string&gt; | 获取OAID，通过Promise异步返回结果。 |
| [getOAID](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid-1)(callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp; void | 获取OAID，通过Callback回调返回值。 |

> **说明：**
> 如调用getOAID接口需要申请ohos.permission.APP_TRACKING_CONSENT权限，并获取用户授权。存在如下三种情况：<br/>
> 1.如应用已配置ohos.permission.APP_TRACKING_CONSENT权限且弹框后用户手动授权，则返回OAID。<br/>
> 2.如应用已配置ohos.permission.APP_TRACKING_CONSENT权限，但弹框后用户未手动授权，则返回00000000-0000-0000-0000-000000000000。<br/>
> 3.如应用未配置ohos.permission.APP_TRACKING_CONSENT权限，则返回00000000-0000-0000-0000-000000000000。


### 开发步骤
1. 在模块的module.json5文件中，申请广告跟踪权限[ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all.md#ohospermissionapp_tracking_consent)，该权限为user_grant权限，当申请的权限为user_grant权限时，reason，abilities标签必填，配置方式参见[requestPermissions标签说明](../../quick-start/module-configuration-file.md#requestpermissions标签)，示例代码如下所示：
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

2. 在应用启动时触发动态授权弹框，向用户请求授权，用户授权成功后，调用getOAID方法获取OAID信息。其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md)。示例代码如下所示：
   ```ts
   import { identifier } from '@kit.AdsKit';
   import { abilityAccessCtrl, common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function requestOAIDTrackingConsentPermissions(context: common.Context): void {
     // 进入页面时触发动态授权弹框，向用户请求授权广告跟踪权限
     const atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
     try {
       atManager.requestPermissionsFromUser(context, ["ohos.permission.APP_TRACKING_CONSENT"]).then((data) => {
         if (data.authResults[0] == 0) {
           hilog.info(0x0000, 'testTag', '%{public}s', 'succeeded in requesting permission');
           identifier.getOAID((err: BusinessError, data: string) => {
			 if (err.code) {
			   hilog.error(0x0000, 'testTag', '%{public}s', `get oaid failed, error: ${err.code} ${err.message}`);
			 } else {
			   const oaid: string = data;
			   hilog.info(0x0000, 'testTag', '%{public}s', `succeeded in getting oaid by callback , oaid: ${oaid}`);
			 }
           });
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
