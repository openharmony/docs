# 开放匿名设备标识服务

<!--Kit: Ads Kit-->
<!--Subsystem: Advertising-->
<!--Owner: @SukiEvas-->
<!--SE: @zhansf1988-->
<!--TSE: @hongmei_may-->

## 获取OAID信息


### 场景介绍

开放匿名设备标识符（Open Anonymous Device Identifier, 以下简称OAID）是一种非永久性设备标识符。基于OAID，可以在保护用户个人数据隐私安全的前提下，向用户提供个性化广告，同时第三方监测平台也可以向广告主提供转化归因分析。

媒体应用、广告平台、第三方监测平台等开发者可以获取设备上的OAID，基于OAID进行个性化广告推荐或广告转化归因分析。

OAID是基于华为自有算法生成的32位类UUID（Universally Unique Identifier）标识符，格式为xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx。

OAID的特性：
- OAID是设备级标识符，同一台设备上不同的App获取到的OAID值一样。
- OAID的获取受应用的跨应用关联访问权限开关影响：当应用的跨应用关联访问权限开关开启时，该应用可获取到非全0的有效OAID；当应用的跨应用关联访问权限开关关闭时，该应用仅能获取到全0的OAID。
- 同一台设备上首个应用开启应用跨应用关联访问权限开关时，会首次生成OAID。

OAID会在下述场景中发生变化：
- 用户将设备恢复出厂设置。
- 用户操作重置OAID。

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| <!--Del-->[<!--DelEnd-->getOAID<!--Del-->](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid)<!--DelEnd-->(): Promise&lt;string&gt; | 获取OAID，通过Promise异步返回结果。 |
| <!--Del-->[<!--DelEnd-->getOAID<!--Del-->](../../reference/apis-ads-kit/js-apis-oaid.md#identifiergetoaid-1)<!--DelEnd-->(callback:&nbsp;AsyncCallback&lt;string&gt;):&nbsp; void | 获取OAID，通过Callback回调返回值。 |

> **说明：**
> 调用getOAID接口需要申请ohos.permission.APP_TRACKING_CONSENT权限并获取用户授权，存在以下三种情况：<br/>
> 1.如果应用已配置ohos.permission.APP_TRACKING_CONSENT权限，且跨应用关联访问权限为“允许”，则返回OAID。<br/>
> 2.如果应用已配置ohos.permission.APP_TRACKING_CONSENT权限，且跨应用关联访问权限为“禁止”，则返回00000000-0000-0000-0000-000000000000。<br/>
> 3.如果应用未配置ohos.permission.APP_TRACKING_CONSENT权限，则返回00000000-0000-0000-0000-000000000000。


### 开发步骤
1. 在模块的module.json5文件中，申请跨应用关联权限[ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapp_tracking_consent)，该权限为user_grant权限，当申请的权限为user_grant权限时，reason，abilities标签必填，配置方式参见[requestPermissions标签说明](../../security/AccessToken/declare-permissions.md#在配置文件中声明权限)，示例代码如下所示：
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

2. 应用在需要获取OAID信息时，应通过调用requestPermissionFromUser接口获取对应权限。其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md#context的获取方式)。示例代码如下所示：
    ```ts
    import { abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
    import { identifier } from '@kit.AdsKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    async function requestOAID(context: Context): Promise<string | undefined> {
      let isPermissionGranted: boolean = false;
      try {
        const atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
        const result: PermissionRequestResult =
          await atManager.requestPermissionsFromUser(context, ['ohos.permission.APP_TRACKING_CONSENT']);
        isPermissionGranted = result.authResults[0] === abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED;
      } catch (err) {
        hilog.error(0x0000, 'testTag', `Failed to request permission. Code is ${err.code}, message is ${err.message}`);
      }
      if (isPermissionGranted) {
        hilog.info(0x0000, 'testTag', 'Succeeded in requesting permission');
        try {
          const oaid = await identifier.getOAID();
          hilog.info(0x0000, 'testTag', 'Succeeded in getting OAID');
          return oaid;
        } catch (err) {
          hilog.error(0x0000, 'testTag', `Failed to get OAID. Code is ${err.code}, message is ${err.message}`);
        }
      } else {
        hilog.error(0x0000, 'testTag', 'Failed to request permission. User rejected');
      }
      return undefined;
    }
    ```