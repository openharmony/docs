# @ohos.hiviewdfx.hiAppEvent (应用事件打点)

本模块提供了应用事件打点能力，包括应用事件落盘、应用事件订阅、应用事件清理、打点功能配置等功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
```

## hiAppEvent.addProcessor<sup>11+</sup>

addProcessor(processor: Processor): number

开发者可添加数据处理者，该数据处理者用于提供事件上云功能，数据处理者的实现可预置在设备中，开发者可根据数据处理者的约束设置属性。

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
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hiLog.info('hiAppEvent', `addProcessor event was successful, id=${id}`);
} catch (error) {
    hiLog.info('hiAppEvent', `failed to addProcessor event, code=${error.code}`);
} 
```

## Processor<sup>11+</sup>

可以上报事件的数据处理者对象。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                | 类型                     | 必填 | 说明                                                                                                        |
| ------------------- | ----------------------- | ---- | ---------------------------------------------------------------------------------------------------------- |
| name                | string                  | 是   | 数据处理者的名称。                                                                                           |
| debugMode           | boolean                 | 否   | 是否开启debug模式。配置值为true表示开启debug模式，false表示不开启debug模式。                                    |
| routeInfo           | string                  | 否   | 服务器位置信息，不超过8kB。                                                                                   |
| onStartReport       | boolean                 | 否   | 数据处理者在启动时是否上报事件。配置值为true表示上报事件，false表示不上报事件。                                   |
| onBackgroundReport  | boolean                 | 否   | 当应用程序进入后台时是否上报事件。配置值为true表示上报事件，false表示不上报事件。                                 |
| periodReport        | number                  | 否   | 根据时间周期定时上报事件。单位为秒，数值不小于0，如果为0则不上报。                                                |
| batchReport         | number                  | 否   | 当事件条数达到数量阈值时上报事件。阈值的数值范围为大于0且小于1000。不在数值范围内则不上报。                         |
| userIds             | string[]                | 否   | 数据处理者可以上报的用户ID的name数组。name值只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。    |
| userProperties      | string[]                | 否   | 数据处理者可以上报的用户属性的name数组。name值只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。   |
| eventConfigs        | [AppEventReportConfig](#appeventreportconfig11)[]  | 否   | 数据处理者可以上报的事件数组。                                                                                 |

## AppEventReportConfig<sup>11+</sup>

数据处理者可以上报事件的描述配置。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称         | 类型    | 必填 | 说明                                                          |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| domain      | string  | 否   | 事件领域。事件领域名称支持数字、小写字母、下划线字符，需要以小写字母开头且不能以下划线结尾，长度非空且不超过16个字符。 |
| name        | string  | 否   | 事件名称。首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过48个字符。 |
| isRealTime  | boolean | 否   | 是否实时上报事件。配置值为true表示实时上报事件，false表示不实时上报事件。 |

## hiAppEvent.removeProcessor<sup>11+</sup>

removeProcessor(id: number): void

删除上报事件的数据处理者。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型    | 必填 | 说明                         |
| ------| ------- | ---- | --------------------------- |
| id    | number  | 是   | 上报事件数据处理者ID。值大于0。|
	
**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

try {
    let processor: hiAppEvent.Processor = {
      name: 'analytics_demo'
    };
    let id: number = hiAppEvent.addProcessor(processor);
    hiAppEvent.removeProcessor(id);
} catch (error) {
    hiLog.info('hiAppEvent', `failed to removeProcessor event, code=${error.code}`);
} 
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo), callback: AsyncCallback&lt;void&gt;): void

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo)类型的事件对象，使用callback方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名   | 类型                           | 必填 | 说明           |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | 是   | 应用事件对象。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 打点回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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
    console.error(`code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.log(`success to write event`);
});
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo)): Promise&lt;void&gt;

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo)类型的事件对象，使用Promise方式作为异步回调。

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

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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
  console.log(`success to write event`);
}).catch((err: BusinessError) => {
  console.error(`code: ${err.code}, message: ${err.message}`);
});
```

## AppEventInfo

提供了应用事件信息的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| domain    | string                  | 是   | 事件领域。事件领域名称支持数字、小写字母、下划线字符，需要以小写字母开头且不能以下划线结尾，长度非空且不超过16个字符。 |
| name      | string                  | 是   | 事件名称。首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过48个字符。 |
| eventType | [EventType](#eventtype) | 是   | 事件类型。                                                   |
| params    | object                  | 是   | 事件参数对象，每个事件参数包括参数名和参数值，其规格定义如下：<br>- 参数名为string类型，首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过16个字符。<br>- 参数值支持string、number、boolean、数组类型，string类型参数长度需在8*1024个字符以内，超出会做丢弃处理；number类型参数取值需在Number.MIN_SAFE_INTEGER~Number.MAX_SAFE_INTEGER范围内，超出可能会产生不确定值；数组类型参数中的元素类型只能全为string、number、boolean中的一种，且元素个数需在100以内，超出会做丢弃处理。<br>- 参数个数需在32个以内，超出的参数会做丢弃处理。 |

## hiAppEvent.configure

configure(config: [ConfigOption](configoption)): void

应用事件打点配置方法，可用于配置打点开关、目录存储配额大小等功能。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                          | 必填 | 说明                     |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | 是   | 应用事件打点配置项对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
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

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | 否   | 打点功能开关，默认值为false。true：关闭打点功能，false：不关闭打点功能。 |
| maxStorage | string  | 否   | 打点数据存放目录的配额大小，默认值为“10M”。<br>在目录大小超出配额后，下次打点会触发对目录的清理操作：按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出配额时结束。 |

## hiAppEvent.setUserId<sup>11+</sup>

setUserId(name: string, value: string): void

设置用户ID。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------  |
| name      | string                    | 是   | 用户ID的key。只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。   |
| value     | string                    | 是   | 用户ID的值。长度不超过256，当值为null、undefine或空，则清除用户ID。 |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

try {
  hiAppEvent.setUserId('key', 'value');
} catch (error) {
  hiLog.info('hiAppEvent', `failed to setUseId event, code=${error.code}`);
} 
```

## hiAppEvent.getUserId<sup>11+</sup>

getUserId(name: string): string

获取之前通过setUserId接口设置的value值。

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
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

hiAppEvent.setUserId('key', 'value');
try {
  let value: string = hiAppEvent.getUserId('key');
  hiLog.info('hiAppEvent', `getUseId event was successful, userId=${value}`);/* "value" */
} catch (error) {
  hiLog.info('hiAppEvent', `failed to getUseId event, code=${error.code}`);
} 
```

## hiAppEvent.setUserProperty<sup>11+</sup>

setUserProperty(name: string, value: string): void

设置用户属性。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| name      | string                    | 是   | 用户属性的key。 只能包含大小写字母、数字、下划线和 $，不能以数字开头，长度不超过256。  |
| value     | string                    | 是   | 用户属性的值。长度不超过1024，当值为null、undefine或空，则清除用户ID。  |

**错误码：**

| 错误码ID | 错误信息          |
| ------- | ----------------- |
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

try {
  hiAppEvent.setUserProperty('key', 'value');
} catch (error) {
  hiLog.info('hiAppEvent', `failed to setUserProperty event, code=${error.code}`);
} 
```

## hiAppEvent.getUserProperty<sup>11+</sup>

getUserProperty(name: string): string

获取之前通过setUserProperty接口设置的value值。

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
| 401     | Parameter error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

hiAppEvent.setUserProperty('key', 'value');
try {
  let value: string = hiAppEvent.getUserProperty('key');
  hiLog.info('hiAppEvent', `getUserProperty event was successful, userProperty=${value}`);/* "value" */
} catch (error) {
  hiLog.info('hiAppEvent', `failed to getUserProperty event, code=${error.code}`);
} 
```

## hiAppEvent.addWatcher

addWatcher(watcher: [Watcher](#watcher)): [AppEventPackageHolder](#appeventpackageholder)

添加应用事件观察者方法，可用于订阅应用事件。

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

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 11102001 | Invalid watcher name.           |
| 11102002 | Invalid filtering event domain. |
| 11102003 | Invalid row value.              |
| 11102004 | Invalid size value.             |
| 11102005 | Invalid timeout value.          |

**示例：**

```ts
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
      console.error("holder is null");
      return;
    }
    console.info(`curRow=${curRow}, curSize=${curSize}`);
    let eventPkg: hiAppEvent.AppEventPackage | null = null;
    while ((eventPkg = holder.takeNext()) != null) {
      console.info(`eventPkg.packageId=${eventPkg.packageId}`);
      console.info(`eventPkg.row=${eventPkg.row}`);
      console.info(`eventPkg.size=${eventPkg.size}`);
      for (const eventInfo of eventPkg.data) {
        console.info(`eventPkg.data=${eventInfo}`);
      }
    }
  }
});

// 2. 如果观察者未传入回调的相关参数，则可以选择使用返回的holder对象手动去处理订阅事件
let holder = hiAppEvent.addWatcher({
  name: "watcher2",
});
if (holder != null) {
  let eventPkg: hiAppEvent.AppEventPackage | null = null;
  while ((eventPkg = holder.takeNext()) != null) {
    console.info(`eventPkg.packageId=${eventPkg.packageId}`);
    console.info(`eventPkg.row=${eventPkg.row}`);
    console.info(`eventPkg.size=${eventPkg.size}`);
    for (const eventInfo of eventPkg.data) {
      console.info(`eventPkg.data=${eventInfo}`);
    }
  }
}
```

## hiAppEvent.removeWatcher

removeWatcher(watcher: [Watcher](#watcher)): void

移除应用事件观察者方法，可用于取消订阅应用事件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | 是   | 应用事件观察者。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
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

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称             | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | 是   | 观察者名称，用于唯一标识观察者。                             |
| triggerCondition | [TriggerCondition](#triggercondition)                        | 否   | 订阅回调触发条件，需要与回调函数一同传入才会生效。           |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | 否   | 订阅过滤条件，在需要对订阅事件进行过滤时传入。               |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | 否   | 订阅回调函数，需要与回调触发条件一同传入才会生效，函数入参说明如下：<br>curRow：在本次回调触发时的订阅事件总数量； <br>curSize：在本次回调触发时的订阅事件总大小，单位为byte；  <br/>holder：订阅数据持有者对象，可以通过其对订阅事件进行处理。 |

## TriggerCondition

提供了回调触发条件的参数选项，只要满足任一条件就会触发订阅回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称    | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| row     | number | 否   | 满足触发回调的事件总数量。             |
| size    | number | 否   | 满足触发回调的事件总大小，单位为byte。 |
| timeOut | number | 否   | 满足触发回调的超时时长，单位为30s。    |

## AppEventFilter

提供了过滤应用事件的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型                      | 必填 | 说明                     |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | 是   | 需要订阅的事件领域。     |
| eventTypes | [EventType](#eventtype)[] | 否   | 需要订阅的事件类型集合。 |

## AppEventPackageHolder

订阅数据持有者类，用于对订阅事件进行处理。

### constructor

constructor(watcherName: string)

类构造函数，创建订阅数据持有者实例，通过观察者名称关联到应用内已添加的观察者对象。

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

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | 是   | 数据大小阈值，单位为byte，默认值为512*1024。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 11104001 | Invalid size value. |

**示例：**

```ts
let holder2: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher2");
holder2.setSize(1000);
```

### takeNext

takeNext(): [AppEventPackage](#appeventpackage)

根据设置的数据大小阈值来取出订阅事件数据，当订阅事件数据全部被取出时返回null作为标识。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**返回值：**

| 类型                                | 说明                                                   |
| ----------------------------------- | ------------------------------------------------------ |
| [AppEventPackage](#appeventpackage) | 取出的事件包对象，订阅事件数据被全部取出后会返回null。 |

**示例：**

```ts
let holder3: hiAppEvent.AppEventPackageHolder = new hiAppEvent.AppEventPackageHolder("watcher3");
let eventPkg = holder3.takeNext();
```

## AppEventPackage

提供了订阅返回的应用事件包的参数定义。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型     | 必填 | 说明                           |
| --------- | -------- | ---- | ------------------------------ |
| packageId | number   | 是   | 事件包ID，从0开始自动递增。    |
| row       | number   | 是   | 事件包的事件数量。             |
| size      | number   | 是   | 事件包的事件大小，单位为byte。 |
| data      | string[] | 是   | 事件包的事件信息。             |

## hiAppEvent.clearData

clearData(): void

应用事件打点数据清理方法，将应用存储在本地的打点数据进行清除。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```ts
hiAppEvent.clearData();
```


## EventType

事件类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 值   | 说明           |
| --------- | ---- | -------------- |
| FAULT     | 1    | 故障类型事件。 |
| STATISTIC | 2    | 统计类型事件。 |
| SECURITY  | 3    | 安全类型事件。 |
| BEHAVIOR  | 4    | 行为类型事件。 |


## event

提供了所有预定义事件的事件名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                      | 类型   | 说明                 |
| ------------------------- | ------ | -------------------- |
| USER_LOGIN                | string | 用户登录事件。       |
| USER_LOGOUT               | string | 用户登出事件。       |
| DISTRIBUTED_SERVICE_START | string | 分布式服务启动事件。 |


## param

提供了所有预定义参数的参数名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                            | 类型   | 说明               |
| ------------------------------- | ------ | ------------------ |
| USER_ID                         | string | 用户自定义ID。     |
| DISTRIBUTED_SERVICE_NAME        | string | 分布式服务名称。   |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | 分布式服务实例ID。 |