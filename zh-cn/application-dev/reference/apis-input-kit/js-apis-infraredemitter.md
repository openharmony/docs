# @ohos.multimodalInput.infraredEmitter (红外管理)

红外管理模块提供产生特定频率和大小的红外信号，以及查询设备支持的频率范围等功能。

> **说明**：
>
> - 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```js
import { infraredEmitter } from '@kit.InputKit';
```

## infraredEmitter.transmitInfrared 

transmitInfrared(infraredFrequency: number, pattern: Array&lt;number&gt;): void

产生特定频率和特定电平大小的红外信号。

**需要权限**：ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**系统能力**：SystemCapability.MultimodalInput.Input. InfraredEmitter

**参数**：

| 参数名       | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| infraredFrequency | number             | 是    | 红外频率，单位Hz。 |
| pattern | Array&lt;number&gt; | 是    | 红外电平信号，单位是us，电平信号取值范围[0,1024]。<br/>比如[100,200,300,400]该电平信号数组，其中表示100us为高电平信号、200us为低电平信号、300us为高电平信号、400us为低电平信号。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**示例**：

```js
try {
  infraredEmitter.transmitInfrared(38000, [100, 200, 300, 400]);
} catch (error) {
  console.log(`transmitInfrared failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## infraredEmitter.getInfraredFrequencies

getInfraredFrequencies(): Array&lt;InfraredFrequency&gt;

查询手机支持的红外信号的频率范围。

**需要权限**：ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

**返回值**：

| 参数                  | 说明                  |
| ------------------- | ------------------- |
| Array&lt;[InfraredFrequency](#infraredfrequency)&gt; | 频率范围，包含多组最大和最小频率。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |

**示例**：

```js
try {
  let frequencies = infraredEmitter.getInfraredFrequencies();
  console.log(`frequencies: ${JSON.stringify(frequencies)}`);
} catch (error) {
  console.log(`Get infrared frequencies failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

##  InfraredFrequency

红外信号的频率范围。

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

| 名称                               | 类型 | 必填   | 说明  |
| -------------------------------- | ---- | ------ | ------ |
| max                       | number | 是 | 最大支持频率，单位为Hz |
| min                          | number | 是  | 最小支持频率，单位为Hz |
