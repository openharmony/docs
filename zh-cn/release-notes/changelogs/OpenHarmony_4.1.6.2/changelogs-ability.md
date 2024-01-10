# 元能力子系统变更说明

## cl.ability.1 startAbilityByCall接口权限变更

**访问级别**

公开接口

**变更原因**

该接口为公开接口，与ohos.permission.ABILITY_BACKGROUND_COMMUNICATION权限级别不匹配，需要将接口权限修改为ohos.permission.DISTRIBUTED_DATASYNC权限，降低权限级别。

**变更影响**

影响接口调用权限，接口调用权限发生变更。
应用需要配置相应的权限，才可以正常使用。
变更后接口仅支持迁移场景下使用，后续将新增对应系统接口，支持更多场景使用。

**API Level**

9

**变更发生版本**

从Openharmony SDK OpenHarmony_4.1.6.1 开始

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| startAbilityByCall(want: Want): Promise<Caller> | 需要ohos.permission.ABILITY_BACKGROUND_COMMUNICATION权限 | 需要ohos.permission.DISTRIBUTED_DATASYNC权限 |

**适配指导**

业务申请并配置ohos.permission.DISTRIBUTED_DATASYNC权限，仅用于迁移场景使用。