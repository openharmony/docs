# @ohos.sensor (传感器)(系统接口)

sensor模块提供了获取传感器数据的能力，包括获取传感器属性列表，订阅传感器数据，以及一些通用的传感器算法。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。


## 导入模块

```ts
import { sensor } from '@kit.SensorServiceKit';
```

## sensor.on

### COLOR<sup>10+</sup>

on(type: SensorId.COLOR, callback: Callback&lt;ColorResponse&gt;, options?: Options): void

订阅颜色传感器数据。

**系统能力：** SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                        |
| -------- | ------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).COLOR                      | 是   | 传感器类型，该值固定为SensorId.COLOR。                      |
| callback | Callback&lt;[ColorResponse](#colorresponse10)&gt; | 是   | 回调函数，异步上报的传感器数据固定为ColorResponse。         |
| options  | [Options](#options)                               | 否   | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |

**错误码：** 

以下错误码的详细介绍请参见 [ohos.sensor(传感器)错误码](errorcode-sensor.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 14500101 | Service exception. |

**示例：** 

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try{
  sensor.on(sensor.SensorId.COLOR, (data: sensor.ColorResponse) => {
    console.log('Succeeded in getting the intensity of light: ' + data.lightIntensity);
    console.log('Succeeded in getting the color temperature: ' + data.colorTemperature);
  }, { interval: 100000000 });
  setTimeout(() => {
        sensor.off(sensor.SensorId.COLOR);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### SAR<sup>10+</sup>

on(type: SensorId.SAR, callback: Callback&lt;SarResponse&gt;, options?: Options): void

订阅吸收比率传感器数据。

**系统能力：** SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                                        |
| -------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).SAR                    | 是   | 传感器类型，该值固定为SensorId.SAR。                        |
| callback | Callback&lt;[SarResponse](#sarresponse10)&gt; | 是   | 回调函数，异步上报的传感器数据固定为SarResponse。           |
| options  | [Options](#options)                           | 否   | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |

**错误码：** 

以下错误码的详细介绍请参见[ohos.sensor(传感器)错误码](errorcode-sensor.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 14500101 | Service exception. |

**示例：** 

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.SAR, (data: sensor.SarResponse) => {
    console.info('Succeeded in getting specific absorption rate : ' + data.absorptionRatio);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.SAR);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.off

### COLOR<sup>10+</sup>

off(type: SensorId.COLOR, callback?: Callback&lt;ColorResponse&gt;): void

取消订阅颜色传感器数据。

**系统能力：** SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口

**参数：** 

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).COLOR                      | 是   | 传感器类型，该值固定为SensorId.COLOR。                       |
| callback | Callback&lt;[ColorResponse](#colorresponse10)&gt; | 否   | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |

**示例：** 

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

function callback1(data: object) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));
}

function callback2(data: object) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));
}

try {
  sensor.on(sensor.SensorId.COLOR, callback1);
  sensor.on(sensor.SensorId.COLOR, callback2);
  // 仅取消callback1的注册
  sensor.off(sensor.SensorId.COLOR, callback1);
  // 取消注册SensorId.COLOR的所有回调
  sensor.off(sensor.SensorId.COLOR);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### SAR<sup>10+</sup>

off(type: SensorId.SAR, callback?: Callback&lt;SarResponse&gt;): void

取消订阅吸收比率传感器数据。

**系统能力：** SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                                         |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SAR                    | 是   | 传感器类型，该值固定为SensorId.SAR。                         |
| callback | Callback&lt;[SarResponse](#sarresponse10)&gt; | 否   | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |

**示例：**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

function callback1(data: object) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));
}

function callback2(data: object) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));
}

try {
  sensor.on(sensor.SensorId.SAR, callback1);
  sensor.on(sensor.SensorId.SAR, callback2);
  // 仅取消callback1的注册
  sensor.off(sensor.SensorId.SAR, callback1);
  // 取消注册SensorId.SAR的所有回调
  sensor.off(sensor.SensorId.SAR);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

## SensorId<sup>9+</sup>

表示当前支持订阅或取消订阅的传感器类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称                | 值   | 说明                                          |
| ------------------- | ---- | --------------------------------------------- |
| COLOR<sup>10+</sup> | 14   | 颜色传感器。<br>系统API：此接口为系统接口     |
| SAR<sup>10+</sup>   | 15   | 吸收比率传感器。<br>系统API：此接口为系统接口 |

## SensorAccuracy<sup>11+</sup>

传感器数据的精度。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称                | 值   | 说明               |
| ------------------- | ---- | ------------------ |
| ACCURACY_UNRELIABLE | 0    | 传感器数据不可信。 |
| ACCURACY_LOW        | 1    | 传感器低挡位精度。 |
| ACCURACY_MEDIUM     | 2    | 传感器中挡位精度。 |
| ACCURACY_HIGH       | 3    | 传感器高挡位精度。 |

## Response

传感器数据的时间戳。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称                   | 类型                                              | 可读 | 可写 | 说明                         |
| ---------------------- | ------------------------------------------------- | ---- | ---- | ---------------------------- |
| timestamp              | number                                            | 是   | 是   | 传感器数据上报的时间戳。     |
| accuracy<sup>11+</sup> | [SensorAccuracy](#sensoraccuracy11)<sup>11+</sup> | 是   | 否   | 传感器数据上报的精度挡位值。 |

## ColorResponse<sup>10+</sup>

颜色传感器数据，继承于[Response](#response)。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口


| 名称             | 类型   | 可读 | 可写 | 说明                          |
| ---------------- | ------ | ---- | ---- | ----------------------------- |
| lightIntensity   | number | 是   | 是   | 表示光的强度，单位 : 勒克斯。 |
| colorTemperature | number | 是   | 是   | 表示色温，单位 : 开尔文。     |

## SarResponse<sup>10+ </sup>

吸收比率传感器数据，继承于[Response](#response)。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

**系统API：** 此接口为系统接口


| 名称            | 类型   | 可读 | 可写 | 说明                            |
| --------------- | ------ | ---- | ---- | ------------------------------- |
| absorptionRatio | number | 是   | 是   | 表示具体的吸收率，单位 : W/kg。 |

## Options

设置传感器上报频率。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称     | 类型                                                     | 可读 | 可写 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| interval | number/[SensorAccuracy](#sensoraccuracy11)<sup>11+</sup> | 是   | 是   | 表示传感器的上报频率，默认值为200000000ns。该属性有最小值和最大值的限制，由硬件支持的上报频率决定。 |