# @ohos.vibrator

vibrator模块提供控制马达振动启、停的能力。

> **说明**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js  
import vibrator from '@ohos.vibrator'
```

## startVibration

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void>): void

根据指定的振动效果和振动属性触发马达振动。使用callback异步回调。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.MiscDevice

**需要权限：** ohos.permission.VIBRATE

**参数：**

| 参数名    | 类型             | 必填 | 说明                                                         |
| --------- | ---------------- | ---- | ------------------------------------------------------------ |
| effect    | VibrateEffect    | 是   | 马达振动效果，支持如下一种：<br>[VibrateTime](#vibratetime)：按照指定持续时间触发马达振动。 |
| attribute | VibrateAttribute | 是   | 马达振动属性。                                               |

**错误码：**

| 错误信息                 | 错误码ID | 说明           |
| ------------------------ | -------- | -------------- |
| Permission denied        | 201      | 权限校验失败。 |
| Parameter error          | 401      | 参数错误。     |
| Capability not supported | 801      | 不支持此功能。 |
| Device operation failed  | 14600101 | 设备操作失败。 |

**示例代码：**

按照指定持续时间触发马达振动：

```ts  
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## startVibration

startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise<&lt;void>

根据指定的振动效果和振动属性触发马达振动。使用promise异步回调。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.MiscDevice

**需要权限：** ohos.permission.VIBRATE

**参数：**

| 参数名    | 类型             | 必填 | 说明                                                         |
| --------- | ---------------- | ---- | ------------------------------------------------------------ |
| effect    | VibrateEffect    | 是   | 马达振动效果，支持如下一种：<br>[VibrateTime](#vibratetime)：按照指定持续时间触发马达振动。 |
| attribute | VibrateAttribute | 是   | 马达振动属性。                                               |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误信息                 | 错误码ID | 说明           |
| ------------------------ | -------- | -------------- |
| Permission denied        | 201      | 权限校验失败。 |
| Parameter error          | 401      | 参数错误。     |
| Capability not supported | 801      | 不支持此功能。 |
| Device operation failed  | 14600101 | 设备操作失败。 |

**示例代码：**

按照指定持续时间触发马达振动： 

```ts  
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```


## stopVibration

stopVibration(callback: AsyncCallback&lt;void&gt;): void

停止马达振动。使用callback异步回调。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.MiscDevice

**需要权限：** ohos.permission.VIBRATE

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |

**示例代码：**

```ts  
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 停止所有模式的马达振动
  vibrator.stopVibration((error: BusinessError) => {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## stopVibration

stopVibration():Promise&lt;void&gt;

停止马达振动。使用promise异步回调。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.MiscDevice

**需要权限：** ohos.permission.VIBRATE

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例代码：**

```ts  
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 停止所有模式的马达振动
  vibrator.stopVibration().then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```


## Usage

振动使用场景。

**系统能力：** SystemCapability.Sensors.MiscDevice

| 取值范围         | 类型   | 说明                           |
| ---------------- | ------ | ------------------------------ |
| unknown          | string | 没有明确使用场景，最低优先级。 |
| alarm            | string | 用于警报场景。                 |
| ring             | string | 用于铃声场景。                 |
| notification     | string | 用于通知场景。                 |
| communication    | string | 用于通信场景。                 |
| touch            | string | 用于触摸场景。                 |
| media            | string | 用于多媒体场景。               |
| physicalFeedback | string | 用于物理反馈场景。             |
| simulateReality  | string | 用于模拟现实场景。             |

## VibrateAttribute  

马达振动属性。

**系统能力：** SystemCapability.Sensors.MiscDevice

| 名称  | 类型            | 必填 | 说明                   |
| ----- | --------------- | ---- | ---------------------- |
| id    | number          | 否   | 振动器id， 默认值为0。 |
| usage | [Usage](#usage) | 是   | 马达振动的使用场景。   |

## VibrateEffect  

马达振动效果，支持如下一种。

**系统能力：** SystemCapability.Sensors.MiscDevice

| 取值范围    | 说明                           |
| ----------- | ------------------------------ |
| VibrateTime | 按照指定持续时间触发马达振动。 |

## VibrateTime  

固定时长振动类型。

**系统能力：** SystemCapability.Sensors.MiscDevice

| 名称     | 类型   | 必填 | 说明                                       |
| -------- | ------ | ---- | ------------------------------------------ |
| type     | string | 是   | 值为"time"，按照指定持续时间触发马达振动。 |
| duration | number | 是   | 马达持续振动时长, 单位ms。                 |