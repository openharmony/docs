# @ohos.multimodalInput.infraredEmitter (红外管理)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

红外管理模块提供产生特定频率和大小的红外信号，以及查询设备支持的频率范围等功能。

> **说明**：
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```js
import { infraredEmitter } from '@kit.InputKit';
```

## infraredEmitter.transmitInfrared<sup>15+</sup>

transmitInfrared(infraredFrequency: number, pattern: Array&lt;number&gt;): void

产生特定频率和特定电平大小的红外信号。

**需要权限**：ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

**参数**：

| 参数名       | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| infraredFrequency | number             | 是    | 红外频率，单位：Hz。 |
| pattern | Array&lt;number&gt; | 是    | 红外电平信号，单位为微秒（μs）。电平信号的数量取值范围为[0,1024]，取值为0时，接口调用不生效。电平信号的取值需大于0。<br/>比如[100,200,300,400]该电平信号数组，其中100μs为高电平信号、200μs为低电平信号、300μs为高电平信号、400μs为低电平信号。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```js
import { infraredEmitter } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            // 设置红外频率及红外电平信号模式
            infraredEmitter.transmitInfrared(38000, [100, 200, 300, 400]);
          } catch (error) {
            console.error(`Failed to transmit infrared signal, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## infraredEmitter.getInfraredFrequencies<sup>15+</sup>

getInfraredFrequencies(): Array&lt;InfraredFrequency&gt;

查询设备支持的红外信号的频率范围。建议先使用[hasIrEmitter](#infraredemitterhasiremitter23)接口查询设备是否支持红外发射器。

**需要权限**：ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

**设备行为差异**：该接口在支持红外发射器的Phone和TV设备上返回红外信号的频率范围，在其他不支持红外发射器的设备上返回一组最大和最小频率，且均为0Hz。建议使用[hasIrEmitter](#infraredemitterhasiremitter23)接口查询设备是否支持红外发射器。

**返回值**：

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Array&lt;[InfraredFrequency](#infraredfrequency15)&gt; | 红外信号的频率范围，包含多组最大和最小频率。<br/>从API version 23开始，当设备不具有红外发射器，返回一组最大和最小频率，且均为0Hz。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |

**示例**：

```js
import { infraredEmitter } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let frequencies = infraredEmitter.getInfraredFrequencies();
            console.info(`Succeeded in getting infrared frequencies, frequencies: ${JSON.stringify(frequencies)}.`);
          } catch (error) {
            console.error(`Failed to get infrared frequencies, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## InfraredFrequency<sup>15+</sup>

红外信号的频率范围。

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

| 名称        | 类型   | 只读   | 可选   | 说明      |
| --------- | ------ | ---- | ---- | ------- |
| max    | number  | 否    | 否 | 最大支持频率，单位：Hz。 |
| min    | number  | 否    | 否 | 最小支持频率，单位：Hz。 |

## infraredEmitter.hasIrEmitter<sup>23+</sup>

hasIrEmitter(): Promise&lt;boolean&gt;

查询设备是否配备红外发射器。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**系统能力**：SystemCapability.MultimodalInput.Input.InfraredEmitter

**返回值**：

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示设备具有红外发射器；返回false表示设备不具有红外发射器。|

**错误码：**

以下错误码的详细介绍请参见[红外管理错误码](errorcode-infraredemitter.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
| -------- | ----------------- |
| 201 | Permission denied. |
| 3800001 | Input service exception. |

**示例**：

```js
import { infraredEmitter } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
            // 查询是否有红外发射器
            infraredEmitter.hasIrEmitter().then((result: boolean) => {
              console.info(`Succeeded in querying infrared emitter: ${JSON.stringify(result)}.`);
            }).catch((error: BusinessError) => {
              console.error(`Failed to query infrared emitter, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`)})
        })
    }
  }
}
```