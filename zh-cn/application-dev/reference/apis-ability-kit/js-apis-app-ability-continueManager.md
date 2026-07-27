# @ohos.app.ability.continueManager (跨端迁移)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedAbilityManager-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

continueManager（跨端迁移）提供了应用跨端迁移的管理能力，例如获取应用跨端迁移过程中快速拉起目标应用的结果。跨端迁移是指当用户在一个设备上操作某个应用时，可以在另一个设备的同一个应用中快速切换，无缝衔接上一个设备的应用体验。具体是指在用户使用过程中，当使用情景发生变化：之前使用的设备不再适合继续当前任务，或者周围有更合适的设备时，用户可以选择使用新的设备来继续当前的任务。跨端迁移完成后，之前设备的应用可退出或保留，用户可以将注意力集中在被启动的设备上，继续执行任务。<!--Del-->详细的设计逻辑和实现机制请参见[跨端迁移](../../application-models/hop-cross-device-migration.md)。<!--DelEnd-->

> **说明：**
> 
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { continueManager } from '@kit.AbilityKit';
```

## continueManager.on

on(type: 'prepareContinue', context: Context, callback: AsyncCallback\<ContinueResultInfo>): void

在应用被快速拉起时，通过注册回调函数获取结果。使用callback异步回调。

适用于跨设备应用迁移场景，如游戏进度从手机迁移到平板、视频播放跨端同步、文档编辑协作等需要保持应用状态连续的场景。

> **说明：**
>
> 快速拉起功能支持在用户触发迁移、等待迁移数据返回的过程中，并行拉起应用，减小用户等待时间。在源端应用[module.json5配置文件](../../quick-start/module-configuration-file.md)的continueType标签的取值中添加"_ContinueQuickStart"后缀，可以开启快速拉起功能。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备中调用会返回16300501错误码。

**参数**：

  | 参数名 | 类型                                                                                              | 必填 | 说明                                       |
  | -------- |-------------------------------------------------------------------------------------------------| -------- |------------------------------------------|
  | type | string                                                                                          | 是 | 固定值：prepareContinue。                     |
  | context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                                                                                         | 是 | Ability（应用组件）的Context。                         |
  | callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | 是 | 回调函数。当快速拉起结果获取成功，err为undefined，ContinueResultInfo为获取到的快速启动结果。否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[DistributedSchedule错误码](errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16300501 | the system ability work abnormally. |

**示例**：

```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1.已配置快速拉起功能，应用立即启动时触发应用生命周期回调
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // 注册快速拉起结果通知的回调函数
            try {
              continueManager.on('prepareContinue', this.context, (err, continueResultInfo) => {
                if (err.code != 0) {
                  hilog.error(DOMAIN_NUMBER, TAG, 'register failed, cause: %{public}s', JSON.stringify(err));
                  return;
                }
                hilog.info(DOMAIN_NUMBER, TAG, 'register finished, %{public}s', JSON.stringify(continueResultInfo));
              });
            } catch (e) {
              hilog.error(DOMAIN_NUMBER, TAG, 'register failed, cause: %{public}s', JSON.stringify(e));
            }
            // 若应用迁移数据较大，可在此处添加加载页面(页面中显示loading等)
            // 可处理应用自定义跳转、时序等问题
            // ...
        }
    }
}
```

## continueManager.off

off(type: 'prepareContinue', context: Context, callback?: AsyncCallback\<ContinueResultInfo>): void

在应用被快速拉起时，注销回调函数。注销成功后，不再接收快速拉起结果的通知。使用callback异步回调。

适用于跨设备应用迁移完成或取消迁移后的回调清理场景，如应用迁移成功后清理监听、用户取消迁移操作时释放资源等。

> **说明：**
>
> 快速拉起功能支持在用户触发迁移、等待迁移数据返回的过程中，并行拉起应用，减小用户等待时间。在源端应用[module.json5配置文件](../../quick-start/module-configuration-file.md)的continueType标签的取值中添加"_ContinueQuickStart"后缀，可以开启快速拉起功能。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数**：

| 参数名 | 类型                                 | 必填 | 说明                                   |
| -------- |------------------------------------| -------- |--------------------------------------|
| type | string                             | 是 | 固定值：prepareContinue。                 |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | 是 | Ability（应用组件）的Context。                     |
| callback | AsyncCallback&lt;[ContinueResultInfo](js-apis-app-ability-continueManager.md#continueresultinfo)&gt; | 否 | 回调函数。当回调函数注销成功，err为undefined，ContinueResultInfo为获取到的回调函数注销结果。否则为错误对象。若未填写，则注销所有已注册的回调；若已填写，则注销指定的回调函数。 |

**错误码：**

以下错误码详细介绍请参考[DistributedSchedule错误码](errorcode-DistributedSchedule.md)。

| 错误码ID    | 错误信息 |
|----------| -------------------------------- |
| 16300501 | the system ability work abnormally. |

**示例**：

```ts
import { AbilityConstant, UIAbility, Want, continueManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[MigrationAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class MigrationAbility extends UIAbility {
    
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onCreate');

        // 1.已配置快速拉起功能，应用立即启动时触发应用生命周期回调
        if (launchParam.launchReason === AbilityConstant.LaunchReason.PREPARE_CONTINUATION) {
            // 注销快速拉起结果通知的回调函数
            try {
              continueManager.off('prepareContinue', this.context, (err, continueResultInfo) => {
                if (err.code != 0) {
                  hilog.error(DOMAIN_NUMBER, TAG, 'unregister failed, cause: %{public}s', JSON.stringify(err));
                  return;
                }
                hilog.info(DOMAIN_NUMBER, TAG, 'unregister finished, %{public}s', JSON.stringify(continueResultInfo));
              });
            } catch (e) {
              hilog.error(DOMAIN_NUMBER, TAG, 'unregister failed, cause: %{public}s', JSON.stringify(e));
            }
            // 若应用迁移数据较大，可在此处添加加载页面(页面中显示loading等)
            // 可处理应用自定义跳转、时序等问题
            // ...
        }
    }
}
```

## ContinueResultInfo

注册或注销回调函数返回的快速拉起结果，包含操作状态码和结果说明信息，用于应用获取跨端迁移快速拉起的执行结果。

**模型约束**：此接口仅可在Stage模型下使用。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型                                                                            | 只读 | 可选 | 说明       |
| -------- |-------------------------------------------------------------------------------|----|----|----------|
| resultState | [ContinueStateCode](js-apis-app-ability-continueManager.md#continuestatecode) | 否  | 否  | 操作结果状态码。 |
| resultInfo | string                                                                        | 否  | 是  | 操作结果的说明，提供操作成功或失败的详细描述信息。 |

## ContinueStateCode

快速拉起的结果状态码的枚举值。

**模型约束**：此接口仅可在Stage模型下使用。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。


**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 值  | 说明    |
| -------- |----|-------|
| SUCCESS  | 0  | 操作成功。表示快速拉起已成功完成，应用可以继续执行跨端迁移流程。 |
| SYSTEM_ERROR | 1 | 操作失败。表示快速拉起过程中发生系统错误，应用需要提示用户迁移失败，并根据业务场景决定是否需要重试。 |
