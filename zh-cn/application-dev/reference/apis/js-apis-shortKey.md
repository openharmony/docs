#  @ohos.multimodalInput.shortKey(快捷键)

通过本模块接口，可以设置快捷键拉起Ability的延迟时间，如设置长按快捷键3s后进行截屏等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

##  导入模块

```
import shortKey from '@ohos.multimodalInput.shortKey';
```

##  shortKey.setKeyDownDuration

setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback&lt;void&gt;): void

设置快捷键拉起Ability的延迟时间，使用AsyncCallback异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.ShortKey

**参数**：

| 参数名     | 类型                | 必填 | 说明                                                         |
| ---------- | ------------------- | ---- | ------------------------------------------------------------ |
| businessKey| string              | 是   | 业务在多模侧注册的唯一标识，与ability_launch_config.json中的businessId对应 |
| delay      | number              | 是   | 该值仅支持快捷键按下触发，表示按下快捷键多长时间后拉起Ability，单位是毫秒（ms） |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例**：

```
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

设置快捷键拉起Ability的延迟时间，使用Promise异步方式返回结果。

**系统能力**：SystemCapability.MultimodalInput.Input.ShortKey

**参数**：

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| businessKey| string | 是   | 业务在多模侧注册的唯一标识，与ability_launch_config.json中的businessId对应 |
| delay      | number | 是   | 该值仅支持快捷键按下触发，表示按下快捷键多长时间后拉起Ability，单位是毫秒（ms） |

**返回值**：

| 参数          | 说明          |
| ------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例**：

```
try {
  shortKey.setKeyDownDuration("screenshot", 500).then(() => {
    console.log(`Set key down duration success`);
  });
} catch (error) {
  console.log(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
