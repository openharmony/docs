# ContinuableInfo

当注册应用任务流转状态监听的回调时，返回应用任务流转状态和流转信息，注册详见：[on('continueStateChange')接口](js-apis-distributedMissionManager.md#distributedmissionmanageroncontinuestatechange10)。

> **说明：**
> 
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import distributedMissionManager from '@ohos.distributedMissionManager';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 是    | 是    | 表示可任务迁移源设备ID。 |
| bundleName | string | 是    | 是    | 表示任务所属应用包名。 |

**示例：**

```js
  import distributedMissionManager from '@ohos.distributedMissionManager';

  try {
    distributedMissionManager.on('continueStateChange', (data) => {
      console.info("continueStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("continueStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```