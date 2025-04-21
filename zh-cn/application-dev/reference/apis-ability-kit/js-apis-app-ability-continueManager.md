# @ohos.app.ability.continueManager (continueManager)

continueManager提供了应用跨端迁移的管理能力，如获取应用跨端迁移过程中快速拉起目标应用的结果。

> **说明：**
> 
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { continueManager } from '@kit.AbilityKit';
```

## continueManager.on

on(type: 'prepareContinue', context: Context, callback: AsyncCallback&lt;ContinueResultInfo&gt;): void

在应用快速拉起时，注册回调函数以获取快速拉起结果。使用callback异步回调。

> **说明：**
>
> 快速拉起功能支持在用户触发迁移、等待迁移数据返回的过程中，并行拉起应用，减小用户等待时间。在源端应用[module.json5配置文件](../../quick-start/module-configuration-file.md)的continueType标签的取值中添加“_ContinueQuickStart”后缀，可以开启快速拉起功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数**：

  | 参数名 | 类型                                                                                              | 必填 | 说明                                       |
  | -------- |-------------------------------------------------------------------------------------------------| -------- |------------------------------------------|
  | type | string                                                                                          | 是 | 固定值：prepareContinue。                     |
  | context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                                                                                         | 是 | Ability的Context。                         |
  | callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | 是 | 回调函数。当快速拉起结果获取成功，err为undefined，ContinueResultInfo为获取到的快速启动结果。否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 16300501 | the system ability work abnormally. |

**示例**：

  ```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    storage : LocalStorage = new LocalStorage();

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1.已配置快速拉起功能，应用立即启动时触发应用生命周期回调
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // 注册快速拉起结果通知的回调函数
            try {
              continueManager.on("prepareContinue", this.context, (err, continueResultInfo) => {
                if (err.code != 0) {
                  console.error('register failed, cause: ' + JSON.stringify(err));
                  return;
                }
                console.info('register finished, ' + JSON.stringify(continueResultInfo));
              });
            } catch (e) {
              console.error('register failed, cause: ' + JSON.stringify(e));
            }
            //若应用迁移数据较大，可在此处添加加载页面(页面中显示loading等)
            //可处理应用自定义跳转、时序等问题
            // ...
        }
    }
}
  ```

## continueManager.off

off(type: 'prepareContinue', context: Context, callback: AsyncCallback&lt;ContinueResultInfo&gt;): void

在应用快速拉起时，注销回调函数，不再获取快速拉起结果。使用callback异步回调。

> **说明：**
>
> 快速拉起功能支持在用户触发迁移、等待迁移数据返回的过程中，并行拉起应用，减小用户等待时间。在源端应用[module.json5配置文件](../../quick-start/module-configuration-file.md)的continueType标签的取值中添加“_ContinueQuickStart”后缀，可以开启快速拉起功能。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数**：

| 参数名 | 类型                                 | 必填 | 说明                                   |
  | -------- |------------------------------------| -------- |--------------------------------------|
| type | string                             | 是 | 固定值：prepareContinue。                 |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | 是 | Ability的Context。                     |
| callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | 是 | 回调函数。当回调函数注销成功，err为undefined，ContinueResultInfo为获回调函数注销结果。否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](errorcode-DistributedSchedule.md)。

| 错误码ID    | 错误信息 |
|----------| -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 16300501 | the system ability work abnormally. |

**示例**：

  ```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    storage : LocalStorage = new LocalStorage();

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1.已配置快速拉起功能，应用立即启动时触发应用生命周期回调
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // 注销快速拉起结果通知的回调函数
            try {
              continueManager.off("prepareContinue", this.context, (err, continueResultInfo) => {
                if (err.code != 0) {
                  console.error('unregister failed, cause: ' + JSON.stringify(err));
                  return;
                }
                console.info('unregister finished, ' + JSON.stringify(continueResultInfo));
              });
            } catch (e) {
              console.error('unregister failed, cause: ' + JSON.stringify(e));
            }
            //若应用迁移数据较大，可在此处添加加载页面(页面中显示loading等)
            //可处理应用自定义跳转、时序等问题
            // ...
        }
    }
}
  ```

## ContinueResultInfo

注册或注销回调函数返回的快速拉起的结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型                                                                            | 只读 | 可选 | 说明       |
| -------- |-------------------------------------------------------------------------------|----|----|----------|
| resultState | [ContinueStateCode](js-apis-app-ability-continueManager.md#continuestatecode) | 是  | 否  | 操作结果状态码。 |
| resultInfo | string                                                                        | 否  | 是  | 操作结果的说明。 |

## ContinueStateCode

快速拉起的结果状态码的枚举值。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 值  | 说明    | 
| -------- |----|-------|
| SUCCESS  | 0  | 操作成功。 | 
| SYSTEM_ERROR | 其它 | 操作失败。 | 

