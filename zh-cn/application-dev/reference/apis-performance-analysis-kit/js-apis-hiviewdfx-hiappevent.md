# @ohos.hiviewdfx.hiAppEvent (应用事件打点)

本模块提供了应用事件打点能力，包括应用事件落盘、应用事件订阅、应用事件清理、打点功能配置等功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
```

## hiAppEvent.addProcessor<sup>11+</sup>

addProcessor(processor: Processor): number

开发者可添加数据处理者，该数据处理者用于提供事件上云功能，数据处理者的实现可预置在设备中，开发者可根据数据处理者的约束设置属性。

Processor的配置信息需要由数据处理者提供，目前设备内暂未预置可供交互的数据处理者，因此当前事件上云功能不可用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型        | 必填 | 说明              |
| ---------  | ---------- | ---- | -------------    |
| processor  | [Processor](#processor11)  | 是   | 上报事件的数据处理者。|

**返回值：**

| 类型    | 说明                   |
| ------ | ---------------------- |
| number | 所添加上报事件数据处理者的ID。 添加失败返回-1，添加成功返回大于0的值。 |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hilog.info(0x0000, 'hiAppEvent', `addProcessor event was successful, id=${id}`);
} catch (error) {
    hilog.error(0x0000, 'hiAppEvent', `failed to addProcessor event, code=${error.code}`);
}
```

## Processor<sup>11+</sup>

可以上报事件的数据处理者对象。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                | 类型                     | 必填 | 说明                                                                                                        |
| ------------------- | ----------------------- | ---- | ---------------------------------------------------------------------------------------------------------- |
| name                | string                  | 是   | 数据处理者的名称。名称只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度非空且不超过256个字符。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                           |
| debugMode           | boolean                 | 否   | 是否开启debug模式，默认值为false。配置值为true表示开启debug模式，false表示不开启debug模式。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                    |
| routeInfo           | string                  | 否   | 服务器位置信息，默认为空字符串。传入字符串长度不能超过8KB，超过时会被置为默认值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                   |
| appId               | string                  | 否   | 应用id，默认为空字符串。传入字符串长度不能超过8KB，超过时会被置为默认值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| onStartReport       | boolean                 | 否   | 数据处理者在启动时是否上报事件，默认值为false。配置值为true表示上报事件，false表示不上报事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                   |
| onBackgroundReport  | boolean                 | 否   | 当应用程序进入后台时是否上报事件，默认值为false。配置值为true表示上报事件，false表示不上报事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                 |
| periodReport        | number                  | 否   | 事件定时上报时间周期，单位为秒。传入数值必须大于或等于0，小于0时会被置为默认值0，不进行定时上报。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                |
| batchReport         | number                  | 否   | 事件上报阈值，当事件条数达到阈值时上报事件。传入数值必须大于0且小于1000，不在数值范围内会被置为默认值0，不进行上报。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                         |
| userIds             | string[]                | 否   | 数据处理者可以上报的用户ID的name数组。name对应[setUserId](#hiappeventsetuserid11)接口的name参数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。    |
| userProperties      | string[]                | 否   | 数据处理者可以上报的用户属性的name数组。name对应[setUserProperty](#hiappeventsetuserproperty11)接口的name参数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| eventConfigs        | [AppEventReportConfig](#appeventreportconfig11)[]  | 否   | 数据处理者可以上报的事件数组。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                 |
| configId<sup>12+</sup> | number | 否 | 数据处理者配置id。传入数值必须大于或等于0，小于0时会被置为默认值0。传入的值大于0时，与数据处理者的名称name共同唯一标识数据处理者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| customConfigs<sup>12+</sup> | Record\<string, string> | 否 | 自定义扩展参数。传入参数名和参数值不符合规格会默认不配置扩展参数，其规格定义如下：<br>- 参数名为string类型，首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过32个字符。<br>- 参数值为string类型，参数值长度需在1024个字符以内。<br>- 参数个数需在32个以内。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## AppEventReportConfig<sup>11+</sup>

数据处理者可以上报事件的描述配置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称         | 类型    | 必填 | 说明                                                          |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| domain      | string  | 否   | 事件领域。事件领域名称支持数字、字母、下划线字符，需要以字母开头且不能以下划线结尾，长度非空且不超过32个字符。 |
| name        | string  | 否   | 事件名称。首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过48个字符。 |
| isRealTime  | boolean | 否   | 是否实时上报事件。配置值为true表示实时上报事件，false表示不实时上报事件。 |

## hiAppEvent.removeProcessor<sup>11+</sup>

removeProcessor(id: number): void

删除上报事件的数据处理者。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------| ------- | ---- | --------------------------- |
| id    | number  | 是   | 上报事件数据处理者ID。值大于0。|

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hiAppEvent.removeProcessor(id);
} catch (error) {
    hilog.error(0x0000, 'hiAppEvent', `failed to removeProcessor event, code=${error.code}`);
}
```

## hiAppEvent.write

write(info: AppEventInfo, callback: AsyncCallback&lt;void&gt;): void

应用事件打点方法，将事件写入到当天的事件文件中，可接收AppEventInfo类型的事件对象，使用callback方式作为异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名   | 类型                           | 必填 | 说明           |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | 是   | 应用事件对象。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 打点回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled.                            |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
hiAppEvent.write({
  domain: "test_domain",
  name: "test_event",
  eventType: hiAppEvent.EventType.FAULT,
  params: eventParams,
}, (err: BusinessError) => {
  if (err) {
    hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
    return;
  }
  hilog.info(0x0000, 'hiAppEvent', `success to write event`);
});
```

## hiAppEvent.write

write(info: AppEventInfo): Promise&lt;void&gt;

应用事件打点方法，将事件写入到当天的事件文件中，可接收AppEventInfo类型的事件对象，使用Promise方式作为异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                           | 必填 | 说明           |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo) | 是   | 应用事件对象。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11100001 | Function disabled.                            |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let eventParams: Record<string, number | string> = {
  "int_data": 100,
  "str_data": "strValue",
};
hiAppEvent.write({
  domain: "test_domain",
  name: "test_event",
  eventType: hiAppEvent.EventType.FAULT,
  params: eventParams,
}).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to write event`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

## AppEventInfo

提供了应用事件信息的参数选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| domain    | string                  | 是   | 事件领域。事件领域名称支持数字、字母、下划线字符，需要以字母开头且不能以下划线结尾，长度非空且不超过32个字符。 |
| name      | string                  | 是   | 事件名称。首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过48个字符。 |
| eventType | [EventType](#eventtype) | 是   | 事件类型。                                                   |
| params    | object                  | 是   | 事件参数对象，每个事件参数包括参数名和参数值。**系统事件中params包含的字段已由各系统事件定义，具体字段含义在各类系统事件指南的介绍中，例如[崩溃事件介绍](../../dfx/hiappevent-watcher-crash-events.md)。** 针对应用事件，打点写入的参数由开发者定义，其规格如下：<br>- 参数名为string类型，首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过32个字符。<br>- 参数值支持string、number、boolean、数组类型，string类型参数长度需在8*1024个字符以内，超出会做丢弃处理；number类型参数取值需在Number.MIN_SAFE_INTEGER~Number.MAX_SAFE_INTEGER范围内，超出可能会产生不确定值；数组类型参数中的元素类型只能全为string、number、boolean中的一种，且元素个数需在100以内，超出会做丢弃处理。<br>- 参数个数需在32个以内，超出的参数会做丢弃处理。 |

## hiAppEvent.setEventParam<sup>12+</sup>

setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt;

事件自定义参数设置方法，使用Promise方式作为异步回调。在同一生命周期中，可以通过事件领域和事件名称关联系统事件和应用事件，系统事件仅支持崩溃和卡死事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                           | 必填 | 说明           |
| ------ | ------------------------------ | ---- | -------------- |
| params | Record&lt;string, [ParamType](#paramtype12)&gt; | 是 | 事件自定义参数对象。参数名和参数值规格定义如下：<br>- 参数名为string类型，首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过32个字符。<br>- 参数值为[ParamType](#paramtype12)类型，参数值长度需在1024个字符以内。<br>- 参数个数需在64个以内。 |
| domain | string                        | 是 | 事件领域。事件领域可支持关联应用事件和系统事件（hiAppEvent.domain.OS）。 |
| name   | string                        | 否 | 事件名称。默认为空字符串，空字符串表示关联事件领域下的所有事件名称。事件名称可支持关联应用事件和系统事件，其中系统事件仅支持关联崩溃事件（hiAppEvent.event.APP_CRASH）和卡死事件（hiAppEvent.event.APP_FREEZE）。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11101007 | The number of parameter keys exceeds the limit. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "int_data": 100,
  "str_data": "strValue",
};
// 给应用事件追加自定义参数
hiAppEvent.setEventParam(params, "test_domain", "test_event").then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set svent param`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

## hiAppEvent.setEventConfig<sup>16+</sup>

setEventConfig(name: string, config: Record&lt;string, ParamType&gt;): Promise&lt;void&gt;

事件自定义门限触发条件的参数设置方法，使用Promise方式作为异步回调。在同一生命周期中，可以通过事件名称，自定义事件门限触发条件相关的参数。**现在仅支持MAIN_THREAD_JANK事件。参数配置详见：[主线程超时事件检测](../../dfx/hiappevent-watcher-mainthreadjank-events.md#自定义采样栈参数介绍)**。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                           | 必填 | 说明           |
| ------ | ------------------------------ | ---- | -------------- |
| name   | string                        | 是 | 事件名称。 |
| config | Record<string, ParamType> | 是 | 事件自定义参数对象。参数名和参数值规格定义如下：<br>- 参数名为string类型，要求非空，且参数名长度需在1024个字符以内。<br>- 参数值为ParamType类型，参数值长度需在1024个字符以内。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 401 | Parameter error. Possible causes: Parameter error. Possible reasons: 1. Incorrect number of parameters; 2. The parameter type is incorrect; 3.Parameter verification failed. |

**示例：**

该步骤用于模拟自定义MAIN_THREAD_JANK事件参数，以log_type的三种类型为例：

log_type=0，采样栈或者采样trace。
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "0"
};

hiAppEvent.setEventParam("MAIN_THREAD_JANK", params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

log_type=1，仅采集调用栈。
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "1",
  "sample_interval": "100",
  "ignore_startup_time": "11",
  "sample_count": "21",
  "report_times_per_app": "3",
};
hiAppEvent.setEventParam("MAIN_THREAD_JANK", params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

log_type=2，仅收集trace。
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let params: Record<string, hiAppEvent.ParamType> = {
  "log_type": "2"
};
hiAppEvent.setEventParam("MAIN_THREAD_JANK", params).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `success to set event config`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `code: ${err.code}, message: ${err.message}`);
});
```

## ParamType<sup>12+</sup>

type ParamType = number | string | boolean | Array&lt;string&gt;

事件自定义参数值的类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 类型                       | 说明                |
|--------------------------|-------------------|
| number                   | 表示值类型为数字。         |
| string                   | 表示值类型为字符串。        |
| boolean                  | 表示值类型为布尔值。        |
| Array&lt;string&gt;      | 表示值类型为字符串类型的数组。   |

## hiAppEvent.configure

configure(config: ConfigOption): void

应用事件打点配置方法，可用于配置打点开关、目录存储配额大小等功能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                          | 必填 | 说明                     |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | 是   | 应用事件打点配置项对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11103001 | Invalid max storage quota value. |

**示例：**

```ts
// 配置打点开关为关闭状态
let config1: hiAppEvent.ConfigOption = {
  disable: true,
};
hiAppEvent.configure(config1);

// 配置文件目录存储配额为100M
let config2: hiAppEvent.ConfigOption = {
  maxStorage: '100M',
};
hiAppEvent.configure(config2);
```

## ConfigOption

提供了对应用事件打点功能的配置选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | 否   | 打点功能开关，默认值为false。true：关闭打点功能，false：不关闭打点功能。 |
| maxStorage | string  | 否   | 打点数据存放目录的配额大小，默认值为“10M”。<br>在目录大小超出配额后，下次打点会触发对目录的清理操作：按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出配额时结束。<br>配额值字符串规格如下：<br>- 配额值字符串只由数字字符和大小单位字符（单位字符支持[b\|k\|kb\|m\|mb\|g\|gb\|t\|tb]，不区分大小写）构成。<br>- 配额值字符串必须以数字开头，后面可以选择不传单位字符（默认使用byte作为单位），或者以单位字符结尾。 |

## hiAppEvent.setUserId<sup>11+</sup>

setUserId(name: string, value: string): void

设置用户ID。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------  |
| name      | string                    | 是   | 用户ID的key。只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度非空且不超过256个字符。   |
| value     | string                    | 是   | 用户ID的值。长度不超过256，当值为null或空字符串时，则清除用户ID。 |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  hiAppEvent.setUserId('key', 'value');
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to setUserId event, code=${error.code}`);
}
```

## hiAppEvent.getUserId<sup>11+</sup>

getUserId(name: string): string

获取之前通过setUserId接口设置的value值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                    | 必填 | 说明         |
| --------- | ----------------------- | ---- | ----------  |
| name      | string                  | 是   | 用户ID的key。只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。|

**返回值：**

| 类型    | 说明                            |
| ------ | ------------------------------- |
| string | 用户ID的值。没有查到返回空字符串。 |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.setUserId('key', 'value');
try {
  let value: string = hiAppEvent.getUserId('key');
  hilog.info(0x0000, 'hiAppEvent', `getUserId event was successful, userId=${value}`);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to getUserId event, code=${error.code}`);
}
```

## hiAppEvent.setUserProperty<sup>11+</sup>

setUserProperty(name: string, value: string): void

设置用户属性。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| name      | string                    | 是   | 用户属性的key。只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度非空且不超过256个字符。  |
| value     | string                    | 是   | 用户属性的值。长度不超过1024，当值为null、undefine或空，则清除用户属性。  |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  hiAppEvent.setUserProperty('key', 'value');
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to setUserProperty event, code=${error.code}`);
}
```

## hiAppEvent.getUserProperty<sup>11+</sup>

getUserProperty(name: string): string

获取之前通过setUserProperty接口设置的value值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                    | 必填 | 说明          |
| --------- | ----------------------- | ---- | ----------    |
| name      | string                  | 是   | 用户属性的key。只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。|

**返回值：**

| 类型    | 说明                             |
| ------ | -------------------------------- |
| string | 用户属性的值。 没有查到返回空字符串。 |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

hiAppEvent.setUserProperty('key', 'value');
try {
  let value: string = hiAppEvent.getUserProperty('key');
  hilog.info(0x0000, 'hiAppEvent', `getUserProperty event was successful, userProperty=${value}`);
} catch (error) {
  hilog.error(0x0000, 'hiAppEvent', `failed to getUserProperty event, code=${error.code}`);
}
```

## hiAppEvent.addWatcher

addWatcher(watcher: Watcher): AppEventPackageHolder

添加应用事件观察者方法，可用于订阅应用事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | 是   | 应用事件观察者。 |

**返回值：**

| 类型                                             | 说明                                 |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder) | 订阅数据持有者，订阅失败时返回null。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name.           |
| 11102002 | Invalid filtering event domain. |
| 11102003 | Invalid row value.              |
| 11102004 | Invalid size value.             |
| 11102005 | Invalid timeout value.          |

**示例：**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

// 1. 如果观察者传入了回调的相关参数，则可以选择在自动触发的回调函数中对订阅事件进行处理
hiAppEvent.addWatcher({
  name: "watcher1",
  appEventFilters: [
    {
      domain: "test_domain",
      eventTypes: [hiAppEvent.EventType.FAULT, hiAppEvent.EventType.BEHAVIOR]
    }
  ],
  triggerCondition: {
    row: 10,
    size: 1000,
    timeOut: 1
  },
  onTrigger: (curRow: number, curSize: number, holder: hiAppEvent.AppEventPackageHolder) => {
    if (holder == null) {
      hilog.error(0x0000, 'hiAppEvent', "holder is null");
      return;
    }
    hilog.info(0x0000, 'hiAppEvent', `curRow=${curRow}, curSize=${curSize}`);
    let eventPkg: hiAppEvent.AppEventPackage | null = null;
    while ((eventPkg = holder.takeNext()) != null) {
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.packageId=${eventPkg.packageId}`);
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.row=${eventPkg.row}`);
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.size=${eventPkg.size}`);
      for (const eventInfo of eventPkg.data) {
        hilog.info(0x0000, 'hiAppEvent', `eventPkg.data=${eventInfo}`);
      }
    }
  }
});

// 2. 如果观察者未传入回调的相关参数，则可以选择使用返回的holder对象手动去处理订阅事件
// 针对异常退出时产生的崩溃事件（hiAppEvent.event.APP_CRASH）和卡死事件（hiAppEvent.event.APP_FREEZE），系统捕获维测日志有一定耗时，典型情况下30s内完成，极端情况下2min左右完成。在手动处理订阅事件的方法中，建议在进程启动后延时重试调用takeNext()获取此类事件。
let holder = hiAppEvent.addWatcher({
  name: "watcher2",
});
if (holder != null) {
  let eventPkg: hiAppEvent.AppEventPackage | null = null;
  while ((eventPkg = holder.takeNext()) != null) {
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.packageId=${eventPkg.packageId}`);
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.row=${eventPkg.row}`);
    hilog.info(0x0000, 'hiAppEvent', `eventPkg.size=${eventPkg.size}`);
    for (const eventInfo of eventPkg.data) {
      hilog.info(0x0000, 'hiAppEvent', `eventPkg.data=${eventInfo}`);
    }
  }
}

// 3. 观察者可以在实时回调函数onReceive中处理订阅事件
hiAppEvent.addWatcher({
  name: "watcher3",
  appEventFilters: [
    {
      domain: "test_domain",
      eventTypes: [hiAppEvent.EventType.FAULT, hiAppEvent.EventType.BEHAVIOR]
    }
  ],
  onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
    hilog.info(0x0000, 'hiAppEvent', `domain=${domain}`);
    for (const eventGroup of appEventGroups) {
      hilog.info(0x0000, 'hiAppEvent', `eventName=${eventGroup.name}`);
      for (const eventInfo of eventGroup.appEventInfos) {
        hilog.info(0x0000, 'hiAppEvent', `event=${JSON.stringify(eventInfo)}`, );
      }
    }
  }
});
```

## hiAppEvent.removeWatcher

removeWatcher(watcher: Watcher): void

移除应用事件观察者方法，可用于取消订阅应用事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | 是   | 应用事件观察者。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11102001 | Invalid watcher name. |

**示例：**

```ts
// 1. 定义一个应用事件观察者
let watcher: hiAppEvent.Watcher = {
  name: "watcher1",
}

// 2. 添加一个应用事件观察者来订阅事件
hiAppEvent.addWatcher(watcher);

// 3. 移除该应用事件观察者以取消订阅事件
hiAppEvent.removeWatcher(watcher);
```

## Watcher

提供了应用事件观察者的参数选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称             | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | 是   | 观察者名称，用于唯一标识观察者。                             |
| triggerCondition | [TriggerCondition](#triggercondition)                        | 否   | 订阅回调触发条件，需要与回调函数onTrigger一同传入才会生效。           |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | 否   | 订阅过滤条件，在需要对订阅事件进行过滤时传入。               |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | 否   | 订阅回调函数，需要与回调触发条件triggerCondition一同传入才会生效，函数入参说明如下：<br>curRow：在本次回调触发时的订阅事件总数量； <br>curSize：在本次回调触发时的订阅事件总大小，单位为byte；  <br/>holder：订阅数据持有者对象，可以通过其对订阅事件进行处理。 |
| onReceive<sup>11+</sup>        | (domain: string, appEventGroups: Array<[AppEventGroup](#appeventgroup11)>) => void | 否 | 订阅实时回调函数，与回调函数onTrigger同时存在时，只触发此回调，函数入参说明如下：<br>domain：回调事件的领域名称； <br>appEventGroups：回调事件集合。 |

## TriggerCondition

提供了回调触发条件的参数选项，只要满足任一条件就会触发订阅回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称    | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| row     | number | 否   | 满足触发回调的事件总数量，正整数。默认值0，不触发回调。传入负值时，会被置为默认值。             |
| size    | number | 否   | 满足触发回调的事件总大小，正整数，单位为byte。默认值0，不触发回调。传入负值时，会被置为默认值。 |
| timeOut | number | 否   | 满足触发回调的超时时长，正整数，单位为30s。默认值0，不触发回调。传入负值时，会被置为默认值。    |

## AppEventFilter

提供了过滤应用事件的参数选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型                      | 必填 | 说明                     |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | 是   | 需要订阅的事件领域。     |
| eventTypes | [EventType](#eventtype)[] | 否   | 需要订阅的事件类型集合。 |
| names<sup>11+</sup>      | string[]                  | 否   | 需要订阅的事件名称集合。 |

## AppEventPackageHolder

订阅数据持有者类，用于对订阅事件进行处理。

### constructor

constructor(watcherName: string)

类构造函数，创建订阅数据持有者实例，通过观察者名称关联到应用内已添加的观察者对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型              | 必填 | 说明                     |
| ------ | ----------------- | ---- | ------------------------ |
| watcherName | string | 是   | 观察者名称。 |

**示例：**

```ts
let holder1: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher1");
```

### setSize

setSize(size: number): void

设置每次取出的应用事件包的数据大小阈值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | 是   | 数据大小阈值，单位为byte，取值范围是大于等于0的数，超出范围会抛异常。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. |

**示例：**

```ts
let holder2: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher2");
holder2.setSize(1000);
```

### setRow<sup>12+</sup>

setRow(size: number): void

设置每次取出的应用事件包的数据条数，优先级高于setSize，和setSize同时调用时仅setRow生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | 是   | 应用事件条数，单位为条，取值范围是大于0的数，超出范围会抛异常。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](errorcode-hiappevent.md)。

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 11104001 | Invalid size value. |

**示例：**

```ts
let holder3: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher3");
holder3.setRow(1000);
```

### takeNext

takeNext(): AppEventPackage

根据设置的数据大小阈值或条数来取出订阅事件数据，当订阅事件数据全部被取出时返回null作为标识。
1、应用仅调用setSize不调用setRow时，根据数据大小限制取订阅事件。
2、应用调用setRow，无论是否调用setSize，都根据setRow设置的条数取订阅事件。
3、setSize和setRow都没被调用时，默认取1条订阅事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**返回值：**

| 类型                                | 说明                                                   |
| ----------------------------------- | ------------------------------------------------------ |
| [AppEventPackage](#appeventpackage) | 取出的事件包对象，订阅事件数据被全部取出后会返回null。 |

**示例：**

```ts
let holder4: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher4");
let eventPkg = holder4.takeNext();
```

## AppEventPackage

提供了订阅返回的应用事件包的参数定义。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型     | 必填 | 说明                           |
| --------- | -------- | ---- | ------------------------------ |
| packageId | number   | 是   | 事件包ID，从0开始自动递增。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。    |
| row       | number   | 是   | 事件包的事件数量。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| size      | number   | 是   | 事件包的事件大小，单位为byte。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| data      | string[] | 是   | 事件包的事件信息。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。             |
| appEventInfos<sup>12+</sup> | Array<[AppEventInfo](#appeventinfo)> | 是   | 事件对象集合。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## AppEventGroup<sup>11+</sup>

提供了订阅返回的事件组的参数定义。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称          | 类型                            | 必填  | 说明          |
| ------------- | ------------------------------- | ---- | ------------- |
| name          | string                          | 是   | 事件名称。     |
| appEventInfos | Array<[AppEventInfo](#appeventinfo)> | 是   | 事件对象集合。 |

## hiAppEvent.clearData

clearData(): void

应用事件打点数据清理方法，将应用存储在本地的打点数据进行清除。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```ts
hiAppEvent.clearData();
```


## EventType

事件类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 值   | 说明           |
| --------- | ---- | -------------- |
| FAULT     | 1    | 故障类型事件。 |
| STATISTIC | 2    | 统计类型事件。 |
| SECURITY  | 3    | 安全类型事件。 |
| BEHAVIOR  | 4    | 行为类型事件。 |


## hiappevent.domain<sup>11+</sup>

提供了所有预定义事件的领域名称常量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称 | 类型   | 只读   | 说明       |
| ---  | ------ | ------ | ---------- |
| OS   | string | 是 | 系统领域。 |


## hiappevent.event

提供了所有预定义事件的事件名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                      | 类型   | 只读   | 说明                 |
| ------------------------- | ------ | ------ | -------------------- |
| USER_LOGIN                | string | 是 | 用户登录事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| USER_LOGOUT               | string | 是 | 用户登出事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| DISTRIBUTED_SERVICE_START | string | 是 | 分布式服务启动事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| APP_CRASH<sup>11+</sup>   | string | 是 | 应用崩溃事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| APP_FREEZE<sup>11+</sup>  | string | 是 | 应用卡死事件。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。       |
| APP_LAUNCH<sup>12+</sup>  | string | 是 | 应用启动耗时事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| SCROLL_JANK<sup>12+</sup> | string | 是 | 应用滑动丢帧事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| CPU_USAGE_HIGH<sup>12+</sup> | string | 是 | 应用CPU高负载事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BATTERY_USAGE<sup>12+</sup> | string | 是 | 应用24h功耗器件分解统计事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| RESOURCE_OVERLIMIT<sup>12+</sup> | string | 是 | 应用资源泄露事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| ADDRESS_SANITIZER<sup>12+</sup> | string | 是 | 应用踩内存事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| MAIN_THREAD_JANK<sup>12+</sup> | string | 是 | 应用主线程超时事件。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |


## hiappevent.param

提供了所有预定义参数的参数名称常量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                            | 类型   | 只读   | 说明               |
| ------------------------------- | ------ | ------ | ------------------ |
| USER_ID                         | string | 是 | 用户自定义ID。     |
| DISTRIBUTED_SERVICE_NAME        | string | 是 | 分布式服务名称。   |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | 是 | 分布式服务实例ID。 |