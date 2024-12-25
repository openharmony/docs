# @ohos.app.ability.wantConstant (wantConstant)

wantConstant模块提供want中操作want常数和解释Flags说明的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { wantConstant } from '@kit.AbilityKit';
```

## Params

want的Params操作的常量。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                    | 值                                 | 说明                                                                           |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | 表示是否支持跨任务链返回。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| ABILITY_RECOVERY_RESTART<sup>10+</sup> | ohos.ability.params.abilityRecoveryRestart | 指示当前Ability是否发生了故障恢复重启。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| CONTENT_TITLE_KEY<sup>10+</sup>       | ohos.extra.param.key.contentTitle  | 指示原子化服务支持分享标题的参数的操作。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| SHARE_ABSTRACT_KEY<sup>10+</sup>      | ohos.extra.param.key.shareAbstract | 指示原子化服务支持分享内容的参数的操作。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| SHARE_URL_KEY<sup>10+</sup>           | ohos.extra.param.key.shareUrl      | 指示原子化服务支持分享链接的参数的操作。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| SUPPORT_CONTINUE_PAGE_STACK_KEY<sup>10+</sup>    | ohos.extra.param.key.supportContinuePageStack  | 指示在跨端迁移过程中是否迁移页面栈信息，默认值为true，自动迁移页面栈信息。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SUPPORT_CONTINUE_SOURCE_EXIT_KEY<sup>10+</sup>  | ohos.extra.param.key.supportContinueSourceExit      | 指示跨端迁移源端应用是否退出，默认值为true，源端应用自动退出。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| SHOW_MODE_KEY<sup>12+</sup>  | ohos.extra.param.key.showMode      | 指示展示模式，值为枚举类型wantConstant.ShowMode<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| PARAMS_STREAM<sup>12+</sup>  | ability.params.stream  | 指示携带的文件URI要授权给目标方。对应的value必须是string类型的文件URI数组。文件URI的获取参考[fileUri](../apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath) <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| APP_CLONE_INDEX_KEY<sup>12+</sup>  | ohos.extra.param.key.appCloneIndex  | 指示分身应用索引。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CALLER_REQUEST_CODE<sup>12+</sup>  | ohos.extra.param.key.callerRequestCode  | 当调用[startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult)或[openLink](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)拉起目标方Ability时, 需要目标方返回结果。为了确保目标方能够将结果准确返回到调用方，系统会自动生成唯一的requestCode，以标识本次调用。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| APP_INSTANCE_KEY<sup>14+</sup>  | ohos.extra.param.key.appInstance  | 指示具体的应用实例。 |
| CREATE_APP_INSTANCE_KEY<sup>14+</sup>  | ohos.extra.param.key.createAppInstance  | 指示创建新应用实例。 |
| CALLER_APP_CLONE_INDEX<sup>14+</sup>  | ohos.param.callerAppCloneIndex  | 指示拉起方应用的分身索引。|
| LAUNCH_REASON_MESSAGE<sup>16+</sup>  | ohos.params.launchReasonMessage  | 调用方拉起目标方Ability时，可通过该字段设置拉起原因。调用方必须为系统应用，且需要申请ohos.permission.SET_LAUNCH_REASON_MESSAGE权限。 <br>**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。 |

## Flags

Flags说明。用于表示处理Want的方式。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                                 | 值       | 说明                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                  |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                  |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>12+</sup> | 0x00000040 | 指示该URI可被接收方持久化。该字段仅在平板类设备上生效。|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                              |
| FLAG_START_WITHOUT_TIPS<sup>11+</sup>              | 0x40000000 | 如果隐式启动能力不能匹配任何应用程序，则不会弹出提示对话框。       |
## ShowMode<sup>12+</sup>

ShowMode说明。用于表示拉起原子化服务的展示模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称                                | 值 | 说明           |
| ----------------------------------- |---|--------------|
| WINDOW        | 0 | 指示独立窗口拉起模式。  |
| EMBEDDED_FULL       | 1 | 指示嵌入式全屏拉起模式。 |
