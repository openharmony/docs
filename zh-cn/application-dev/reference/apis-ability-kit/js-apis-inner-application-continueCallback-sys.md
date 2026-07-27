# ContinueCallback (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedSched-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

表示跨设备迁移Mission完成后，返回迁移结果的回调函数，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission)。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。
> 本模块接口仅可在Stage模型下使用。

## ContinueCallback.onContinueDone

onContinueDone(result: number): void;

Mission迁移完成后调用，回调参数result返回迁移结果。当目标设备成功接收并启动Mission后，系统会触发此回调通知源设备迁移结果。开发者应根据result参数判断迁移是否成功，并执行相应操作，如提示用户、重试或终止任务。详细的迁移流程和机制请参见[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission)。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| result |  number | 是 | 迁移任务的结果，0表示迁移成功，非0值表示迁移失败。具体错误码及其含义、可能原因和解决措施请参见[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission)的错误码说明。 |

**示例：**

```ts
import { distributedMissionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 调用continueMission方法，发起任务迁移 
distributedMissionManager.continueMission(
  {
    srcDeviceId: '123', // 源设备ID，需通过deviceManager等接口获取
    dstDeviceId: '456', // 目标设备ID，需通过deviceManager等接口获取
    missionId: 123, // 任务ID，需通过distributedMissionManager获取或从其他接口返回
    wantParam: {
      'key': 'value' // 迁移数据
    }
  },
  {
    // 迁移完成回调函数，接收迁移结果
    onContinueDone(result: number) {
      console.info(`onContinueDone, result: ${JSON.stringify(result)}`);
    }
  }, (error: BusinessError) => {
  // 错误处理回调函数
  // 判断是否有错误及错误码
  if (error) {
    console.error(`continueMission failed, error.code: ${error.code}, error.message: ${error.message}`);
  }
  console.info(`continueMission finished`);
});
```
