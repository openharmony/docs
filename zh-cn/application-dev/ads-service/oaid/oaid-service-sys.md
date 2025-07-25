# 重置OAID信息（仅对系统应用开放）

## 场景介绍

OAID会在以下场景中发生变化：
- 系统应用将`bundleName`配置到设备侧系统目录中，文件路径为`etc/advertising/oaid/oaid_service_config.json`。配置方式为：用英文逗号隔开，添加到数组末尾。配置完成后，可主动调用`resetOAID()`接口重置OAID。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [resetOAID()](../../reference/apis-ads-kit/js-apis-oaid-sys.md#identifierresetoaid):&nbsp;void | 重置OAID，此接口为系统接口。 |


## 开发步骤

1. 在模块的module.json5文件中，申请跨应用关联权限[ohos.permission.APP_TRACKING_CONSENT](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapp_tracking_consent)。示例如下：
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
    应用启动时触发动态授权弹框，请求用户授权。获取context的方式参见[各类Context的获取方式](../../application-models/application-context-stage.md)。示例代码如下：
    ```ts
    import { abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    async function requestAppTrackingConsentPermission(context: Context): Promise<void> {
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
      } else {
        hilog.error(0x0000, 'testTag', 'Failed to request permission. User rejected');
      }
    }
    ```

2. 调用resetOAID方法重置OAID信息。示例代码如下所示：
    ```ts
    import { identifier } from '@kit.AdsKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    try {
      identifier.resetOAID();
    } catch (err) {
      hilog.error(0x0000, 'testTag', `Failed to reset OAID. Code is ${err.code}, message is ${err.message}`);
    }
    ```