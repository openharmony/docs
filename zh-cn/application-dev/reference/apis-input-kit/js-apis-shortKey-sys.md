#  @ohos.multimodalInput.shortKey(快捷键)(系统接口)

通过本模块接口，可以设置快捷键拉起Ability的延迟时间，如设置长按快捷键3s后再截屏等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

##  导入模块

```js
import shortKey from '@ohos.multimodalInput.shortKey';
```

##  shortKey.setKeyDownDuration

setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback&lt;void&gt;): void

设置快捷键拉起Ability的延迟时间，使用Callback异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.ShortKey

**参数**：

| 参数名     | 类型                | 必填 | 说明                                                         |
| ---------- | ------------------- | ---- | ------------------------------------------------------------ |
| businessKey| string              | 是   | 业务在多模侧注册的唯一标识，与ability_launch_config.json中的businessId对应。 |
| delay      | number              | 是   | 按下快捷键多长时间后拉起Ability，单位是毫秒（ms），仅支持快捷键按下触发。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数，设置成功时，err为undefined，否则为错误对象。  |                                               

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```js
import shortKey from '@ohos.multimodalInput.shortKey';
try {
  shortKey.setKeyDownDuration("screenshot", 500, (error) => {
    if (error) {
      console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set key down duration success`);
  });
} catch (error) {
  console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## shortKey.setKeyDownDuration

setKeyDownDuration(businessKey: string, delay: number): Promise&lt;void&gt;

设置快捷键拉起Ability的延迟时间，使用Promise异步回调。

**系统能力**：SystemCapability.MultimodalInput.Input.ShortKey

**参数**：

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| businessKey| string | 是   | 业务在多模侧注册的唯一标识，与ability_launch_config.json中的businessId对应。 |
| delay      | number | 是   | 按下快捷键多长时间后拉起Ability，单位是毫秒（ms），仅支持快捷键按下触发。 |

**返回值**：

| 参数          | 说明          |
| ------------- | ------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```js
import shortKey from '@ohos.multimodalInput.shortKey';
try {
  shortKey.setKeyDownDuration("screenshot", 500).then(() => {
    console.log(`Set key down duration success`);
  });
} catch (error) {
  console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## 枚举类型说明


### FingerprintAction

```
enum FingerprintAction
```

**描述**

枚举按键事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

| 枚举值    | 描述 | 
| -------- | --------    |
| DOWN     | 按下事件。   | 
| UP       | 按下事件。 | 
| SLIDE    | 滑动事件。 | 
| RETOUCH  | 双击事件。 | 
| CLICK    | 点击事件。 | 


## FingerprintEvent<sup>12+</sup>


**系统能力：** SystemCapability.MultimodalInput.Input.Core

| 名称      | 类型                                       | 说明                    |
| --------  | --------                                  | --------                |
| action    | [FingerprintAction](#fingerprintaction)   | 按键事件类型。           |
| distanceX | number                                    | 相对于光标位置的x轴偏移量【正数表示向右移动，负数表示向左移动】。 |
| distanceY | number                                    | 相对于光标位置的y轴偏移量【正数表示向上移动，负数表示向下移动】。 |
