# wantConstant

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import wantConstant from '@ohos.ability.wantConstant'
```

## wantConstant.Action

**系统能力**：SystemCapability.Ability.AbilityBase

权限列表。

| 系统公共事件宏      | 系统公共事件名称          | 订阅者所需权限     |
| ------------ | ------------------ | ---------------------- |
| ACTION_HOME                                 | ohos.want.action.home                    | 无                                                           |
| ACTION_DIAL                                 | ohos.want.action.dial                    | 无                                                           |
| ACTION_SEARCH                               | ohos.want.action.search                  | 无                                                           |
| ACTION_WIRELESS_SETTINGS                    | ohos.settings.wireless                   | 无                                                           |
| ACTION_MANAGE_APPLICATIONS_SETTINGS         | ohos.settings.manage.applications        | 无                                                           |
| ACTION_APPLICATION_DETAILS_SETTINGS         | ohos.settings.application.details        | 无                                                           |
| ACTION_SET_ALARM                            | ohos.want.action.setAlarm                | 无                                                           |
| ACTION_SHOW_ALARMS                          | ohos.want.action.showAlarms              | 无                                                           |
| ACTION_SNOOZE_ALARM                         | ohos.want.action.snoozeAlarm             | 无                                                           |
| ACTION_DISMISS_ALARM                        | ohos.want.action.dismissAlarm            | 无                                                           |
| ACTION_DISMISS_TIMER                        | ohos.want.action.dismissTimer            | 无                                                           |
|  ACTION_SEND_SMS                            | ohos.want.action.sendSms                 | 无                                                           |
| ACTION_CHOOSE                               | ohos.want.action.choose                  | 无                                                           |
| ACTION_IMAGE_CAPTURE<sup>8+</sup>           | ohos.want.action.imageCapture            | 无                                                           |
| ACTION_VIDEO_CAPTUR<sup>8+</sup>            | ohos.want.action.videoCapture            | 无                                                           |
| ACTION_SELECT                               | ohos.want.action.select                  | 无                                                           |
| ACTION_SEND_DATA                            | ohos.want.action.sendData                | 无                                                           |
| ACTION_SEND_MULTIPLE_DATA                   | ohos.want.action.sendMultipleData        | 无                                                           |
| ACTION_SCAN_MEDIA_FILE                      | ohos.want.action.scanMediaFile           | 无                                                           |
| ACTION_VIEW_DATA                            | ohos.want.action.viewData                | 无                                                           |
|  ACTION_EDIT_DATA                           | ohos.want.action.editData                | 无                                                           |
|  INTENT_PARAMS_INTENT                       | ability.want.params.INTENT               | 无                                                           |
|  INTENT_PARAMS_TITLE                        | ability.want.params.TITLE                | 无                                                           |
|  ACTION_FILE_SELECT<sup>7+</sup>            | ohos.action.fileSelect                   | 无                                                           |
|  PARAMS_STREAM<sup>7+</sup>                 | ability.params.stream                    | 无                                                           |
|  ACTION_APP_ACCOUNT_OAUTH <sup>8+</sup>     | ohos.account.appAccount.action.oauth     | 无                                                           |


## wantConstant.Entity

**系统能力**：SystemCapability.Ability.AbilityBase

权限列表。

| 系统公共事件宏      | 系统公共事件名称          | 订阅者所需权限     |
| ------------ | ------------------ | ---------------------- |
| ENTITY_DEFAULT                             | entity.system.default                    | 无                                                           |
| ENTITY_HOME                                | entity.system.homel                      | 无                                                           |
| ENTITY_VOICE                               | ENTITY_VOICE                             | 无                                                           |
| ENTITY_BROWSABLE                           | entity.system.browsable                  | 无                                                           |
| ENTITY_VIDEO                               | entity.system.video                      | 无                                                           |
| ACTION_APPLICATION_DETAILS_SETTINGS        | ohos.settings.application.details        | 无                                                           |


## flags说明

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称                                 | 参数       | 描述                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | 指示对URI执行读取操作的授权。                                  |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | 指示对URI执行写入操作的授权。                                  |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | 将结果返回给元能力。                                           |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | 确定是否可以将本地设备上的功能迁移到远程设备。                   |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | 指定组件是否属于OHOS。                                         |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | 指定是否启动某个能力。                                          |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | 指示URI上可能持久化的授权。                                     |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | 按照前缀匹配的方式验证URI权限。                                 |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | 支持分布式调度系统中的多设备启动。                               |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | 指示无论主机应用程序是否已启动，都将启动使用服务模板的功能。         |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | 表示迁移是可拉回的。                                             |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | 如果未安装指定的功能，请安装该功能。                              |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | 如果未安装，使用后台模式安装该功能。                              |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | 指示清除其他任务的操作。可以为传递给 **[ohos.app.Context](js-apis-ability-context.md)** 中**startAbility**方法的**Want**设置此标志，并且必须与**flag_ABILITY_NEW_MISSION**一起使用。 |
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | 指示在历史任务堆栈上创建任务的操作。                               |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | 指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |