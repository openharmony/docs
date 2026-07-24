# @ohos.hiSysEvent (系统事件打点)(系统接口)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lyj_love_code-->
<!--Designer: @tangyyan-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

本模块提供了系统事件打点能力，包括系统事件的埋点、落盘系统事件的订阅及已落盘的系统事件的查询能力。可用于系统故障诊断、性能监控、用户行为分析等场景，帮助开发者快速定位和解决问题，提升系统可观测性和运维效率。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
```

## EventType

系统事件类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FAULT | 1 | 错误事件类型。 |
| STATISTIC | 2 | 统计事件类型。 |
| SECURITY | 3 | 安全事件类型。 |
| BEHAVIOR | 4 | 用户行为事件类型。 |

## SysEventInfo

系统事件信息对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| domain | string | 否 | 否 | 事件领域。 |
| name | string | 否 | 否 | 事件名称。 |
| eventType | [EventType](#eventtype) | 否 | 否 | 事件类型。 |
| params | object | 否 | 是 |  事件参数。参数需满足验证、字符串类型参数大小限制、参数总数限制、数组类型参数数量限制等要求。详见[系统事件错误码](errorcode-hisysevent-sys.md)：11200001-11200054。 |


## hiSysEvent.write

write(info: SysEventInfo, callback: AsyncCallback&lt;void&gt;): void

系统事件打点接口，接收[SysEventInfo](#syseventinfo)类型的对象作为事件参数，使用callback方式作为异步回调。适用于需要异步记录系统事件以避免阻塞主线程的场景，能够提升应用响应性能。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| info | [SysEventInfo](#syseventinfo) | 是 | 系统事件信息对象，包含事件领域、事件名称、事件类型和事件参数等信息。 |
| callback  | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。<br>- 0表示事件校验成功，事件正常异步写入事件文件；<br>- 正值表示事件打点存在异常，但可以正常写入；<br>- 负值表示事件打点失败。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200001 | Invalid event domain.                                                                                                                           |
| 11200002 | Invalid event name.                                                                                                                             |
| 11200003 | Abnormal environment.                                                                                                                           |
| 11200004 | The event length exceeds the limit.                                                                                                             |
| 11200051 | Invalid event parameter.                                                                                                                        |
| 11200052 | The size of the event parameter of the string type exceeds the limit.                                                                           |
| 11200053 | The number of event parameters exceeds the limit.                                                                                               |
| 11200054 | The number of event parameters of the array type exceeds the limit.                                                                             |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let customizedParams: Record<string, string | number> = {
    'PID': 487,
    'UID': 103,
    'PACKAGE_NAME': "com.ohos.hisysevent.test",
    'PROCESS_NAME': "syseventservice",
    'MSG': "no msg."
  };
  let eventInfo: hiSysEvent.SysEventInfo = {
    domain: "RELIABILITY",
    name: "STACK",
    eventType: hiSysEvent.EventType.FAULT,
    params: customizedParams
  };
  hiSysEvent.write(eventInfo, (err: BusinessError) => {
    // 处理事件写入成功后的操作
  });
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```


## hiSysEvent.write

write(info: SysEventInfo): Promise&lt;void&gt;

系统事件打点接口，接收[SysEventInfo](#syseventinfo)类型的对象作为事件参数，使用promise方式作为异步回调。适用于需要链式调用处理异步结果的场景，能够使代码更加简洁优雅。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名    | 类型                    | 必填 | 说明 |
| --------- | ----------------------- | ---- | --------------- |
| info | [SysEventInfo](#syseventinfo) | 是   | 系统事件。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise实例，可以在其then()、catch()回调方法中分别对系统事件写入成功、写入异常的回调进行处理。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200001 | Invalid event domain.                                                                                                                           |
| 11200002 | Invalid event name.                                                                                                                             |
| 11200003 | Abnormal environment.                                                                                                                           |
| 11200004 | The event length exceeds the limit.                                                                                                             |
| 11200051 | Invalid event parameter.                                                                                                                        |
| 11200052 | The size of the event parameter of the string type exceeds the limit.                                                                           |
| 11200053 | The number of event parameters exceeds the limit.                                                                                               |
| 11200054 | The number of event parameters of the array type exceeds the limit.                                                                             |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let customizedParams: Record<string, string | number> = {
    'PID': 487,
    'UID': 103,
    'PACKAGE_NAME': "com.ohos.hisysevent.test",
    'PROCESS_NAME': "syseventservice",
    'MSG': "no msg."
  };
  let eventInfo: hiSysEvent.SysEventInfo = {
    domain: "RELIABILITY",
    name: "STACK",
    eventType: hiSysEvent.EventType.FAULT,
    params: customizedParams
  };
  // 使用Promise方式写入系统事件，then中处理成功事件，catch中处理错误
  hiSysEvent.write(eventInfo).then(
    () => {
      // 处理事件写入成功后的操作
    }
  ).catch(
    (err: BusinessError) => {
      // 捕获并打印错误信息
      console.error(`error code: ${err.code}, error msg: ${err.message}`);
    }
  );
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## RuleType

匹配规则类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WHOLE_WORD | 1 | 全词匹配类型。 |
| PREFIX | 2 | 前缀匹配类型。 |
| REGULAR | 3 | 正则匹配类型。 |

## WatchRule

系统事件订阅规则对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| domain | string | 否 | 否 | 事件领域。 |
| name | string | 否 | 否 | 事件名称。 |
| tag | string | 否 | 是 | 事件标签。省略时使用空字符串作为默认值。 |
| ruleType | [RuleType](#ruletype) | 否 | 否 | 匹配规则类型。 |

## Watcher

系统事件订阅者对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| rules | [WatchRule](#watchrule)[] | 否 | 否 | 订阅对象数组，每个订阅者对象包含多个订阅规则。 |
| onEvent | function | 否 | 否 | 订阅事件的回调方法(info: [SysEventInfo](#syseventinfo)) => void。当订阅的事件发生时此回调方法会被触发，回调函数接收订阅到的[SysEventInfo](#syseventinfo)，用于处理订阅到的事件数据。|
| onServiceDied | function | 否 | 否 | 系统事件服务关闭的回调方法() => void。当系统事件服务异常关闭或停止时触发，用于处理服务异常情况（如记录日志、重新订阅事件等）。 |

## hiSysEvent.addWatcher

addWatcher(watcher: Watcher): void

订阅系统事件，接收[Watcher](#watcher)类型的对象作为事件参数。适用于需要实时监控系统事件的场景。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------------------------- | ---- | ------------------------ |
| watcher | [Watcher](#watcher) | 是 | 系统事件订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200101 | The number of watchers exceeds the limit.                                                                                                       |
| 11200102 | The number of watch rules exceeds the limit.                                                                                                    |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let watchRules: hiSysEvent.WatchRule[] = [{
    domain: "RELIABILITY",
    name: "STACK",
    tag: "STABILITY",
    ruleType: hiSysEvent.RuleType.WHOLE_WORD,
  } as hiSysEvent.WatchRule];
let watcher: hiSysEvent.Watcher = {
  rules: watchRules,
  onEvent: (info: hiSysEvent.SysEventInfo) => {
    // 处理订阅到的系统事件
  },
  onServiceDied: () => {
    // 处理系统事件服务异常
  }
};
try {
  hiSysEvent.addWatcher(watcher);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.removeWatcher

removeWatcher(watcher: Watcher): void

取消订阅系统事件，接收[Watcher](#watcher)类型的对象作为事件参数。适用于当不再需要监控某些事件时取消订阅的场景。取消订阅成功后，将不再接收该订阅者的事件。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型  | 必填 | 说明  |
| ------ | ------------- | ---- | ------------------------- |
| watcher | [Watcher](#watcher) | 是 | 系统事件订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200201 | The watcher does not exist.                                                                                                                     |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let watchRules: hiSysEvent.WatchRule[] = [{
    domain: "RELIABILITY",
    name: "STACK",
    tag: "STABILITY",
    ruleType: hiSysEvent.RuleType.WHOLE_WORD,
  } as hiSysEvent.WatchRule ];
let watcher: hiSysEvent.Watcher = {
  rules: watchRules,
  onEvent: (info: hiSysEvent.SysEventInfo) => {
    // 处理订阅到的系统事件
  },
  onServiceDied: () => {
    // 处理系统事件服务异常
  }
};
try {
  hiSysEvent.addWatcher(watcher);
  hiSysEvent.removeWatcher(watcher);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## QueryArg

系统事件查询参数对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| beginTime | number | 否 | 否 | 查询的系统事件起始时间（13位时间戳），表示距1970年1月1日0时0分0秒0毫秒的毫秒数。使用-1表示不限制起始时间。与endTime配合使用时，两者取交集。建议设置合理的时间范围以优化查询性能。 |
| endTime | number | 否 | 否 | 查询的系统事件结束时间（13位时间戳），表示距1970年1月1日0时0分0秒0毫秒的毫秒数。使用-1表示不限制结束时间。与beginTime配合使用时，两者取交集。建议设置合理的时间范围以优化查询性能。 |
| maxEvents | number | 否 | 否 | 查询的系统事件最多条数。建议设置合理的值以优化查询性能。 |
| fromSeq<sup>10+</sup> | number | 否 | 是 | 查询的系统事件起始序列号，默认值为-1，表示不限制起始序列号。与toSeq配合使用时，两者取交集。建议设置合理的序列范围以优化查询性能。 |
| toSeq<sup>10+</sup> | number | 否 | 是 | 查询的系统事件结束序列号，默认值为-1，表示不限制结束序列号。与fromSeq配合使用时，两者取交集。建议设置合理的序列范围以优化查询性能。|

## QueryRule

系统事件查询规则对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| domain | string | 否 | 否 | 查询包含的事件领域。 |
| names | string[] | 否 | 否 | 查询所包含的多个事件名称，每个查询规则对象包含多个系统事件名称。 |
| condition<sup>10+</sup> | string | 否 | 是 | 事件的额外参数条件，格式：{"version":"V1","condition":{"and":[{"param":"参数","op":"操作符","value":"比较值"}]}}。<br>参数：指定事件参数的键值，类型为string。<br>操作符支持：=、!=、<、<=、>和>=。<br>value：比较值，类型可为string、number等。<br>支持在“and”数组中配置多个条件，查询结果取交集。建议避免配置过多复杂条件以优化查询性能。默认不传该参数时不进行额外参数过滤。 |

## Querier

系统事件查询者对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| onQuery | function | 否 | 否 | 返回查询到的系统事件的回调方法(infos: [SysEventInfo](#syseventinfo)[]) => void。当查询到系统事件时触发（可能调用多次），回调函数接收查询到的[SysEventInfo](#syseventinfo)数组，用于处理查询结果。|
| onComplete | function | 否 | 否 | 查询结果统计的回调方法(reason: number, total: number) => void。当查询完成时触发（只调用一次），回调函数接收查询结果统计信息：reason表示查询完成的原因（如查询成功、查询超时等），total表示查询到的总事件数。|

## hiSysEvent.query

query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void

查询系统事件。支持按时间范围、事件领域、事件名称等多种查询条件进行匹配查询。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------------------------- | ---- | ------------------------ |
| queryArg | [QueryArg](#queryarg) | 是   | 查询需要配置的查询参数。 |
| rules | [QueryRule](#queryrule)[] | 是   | 查询规则数组，每次查询可配置多个查询规则。 |
| querier | [Querier](#querier) | 是   | 查询者对象，包含查询结果及结束的相关回调。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |
| 11200303 | The number of concurrent queriers exceeds the limit.                                                                                            |
| 11200304 | The query frequency exceeds the limit.                                                                                                          |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let customizedParams: Record<string, string | number> = {
    'PID': 487,
    'UID': 103,
    'PACKAGE_NAME': "com.ohos.hisysevent.test",
    'PROCESS_NAME': "syseventservice",
    'MSG': "no msg."
  };
  let eventInfo: hiSysEvent.SysEventInfo = {
    domain: "RELIABILITY",
    name: "STACK",
    eventType: hiSysEvent.EventType.FAULT,
    params: customizedParams
  };
  hiSysEvent.write(eventInfo, (err: BusinessError) => {
    // 处理事件写入成功后的操作
  });

  let queryArg: hiSysEvent.QueryArg = {
    beginTime: -1,
    endTime: -1,
    maxEvents: 5,
  };
  let queryRules: hiSysEvent.QueryRule[] = [{
    domain: "RELIABILITY",
    names: ["STACK"],
    condition: '{"version":"V1","condition":{"and":[{"param":"PID","op":"=","value":487},{"param":"PROCESS_NAME","op":"=","value":"syseventservice"}]}}'
  } as hiSysEvent.QueryRule];
  let querier: hiSysEvent.Querier = {
    onQuery: (infos: hiSysEvent.SysEventInfo[]) => {
      // 处理查询到的系统事件infos
    },
    onComplete: (reason: number, total: number) => {
      // 处理结束查询
    }
  };
  hiSysEvent.query(queryArg, queryRules, querier);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.exportSysEvents<sup>10+</sup>

exportSysEvents(queryArg: QueryArg, rules: QueryRule[]): number

批量导出系统事件，以文件格式写入应用沙箱固定目录(/data/storage/el2/base/cache/hiview/event/)。调用成功后，返回接口调用时间戳，可用于定位导出的事件文件。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| queryArg | [QueryArg](#queryarg)     | 是   | 导出需要配置的查询参数。                   |
| rules    | [QueryRule](#queryrule)[] | 是   | 查询规则数组，每次导出可配置多个查询规则。 |

**返回值：**

| 类型   | 说明             |
| ------ | ---------------- |
| number | 接口调用时间戳，单位为毫秒（ms）。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |
| 11200304 | The query frequency exceeds the limit.                                                                                                          |

**示例：**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let customizedParams: Record<string, string | number> = {
    'PID': 487,
    'UID': 103,
    'PACKAGE_NAME': "com.ohos.hisysevent.test",
    'PROCESS_NAME': "syseventservice",
    'MSG': "no msg."
  };
  let eventInfo: hiSysEvent.SysEventInfo = {
    domain: "RELIABILITY",
    name: "STACK",
    eventType: hiSysEvent.EventType.FAULT,
    params: customizedParams
  };
  hiSysEvent.write(eventInfo, (err: BusinessError) => {
    // 处理事件写入成功后的操作
  });

  let queryArg: hiSysEvent.QueryArg = {
    beginTime: -1,
    endTime: -1,
    maxEvents: 1,
  };
  let queryRules: hiSysEvent.QueryRule[] = [{
    domain: "RELIABILITY",
    names: ["STACK"],
  } as hiSysEvent.QueryRule];
  let time = hiSysEvent.exportSysEvents(queryArg, queryRules);
  console.info(`receive export task time is : ${time}`);

  // 等待文件写入完成后读取（建议通过监听文件系统事件或轮询文件大小确认）
  setTimeout(() => {
    let eventDir = '/data/storage/el2/base/cache/hiview/event';
    let filenames = fileIo.listFileSync(eventDir);
    for (let i = 0; i < filenames.length; i++) {
      if (filenames[i].indexOf(time.toString()) != -1) {
        let res = fileIo.readTextSync(eventDir + '/' + filenames[i]);
        let events: string = JSON.parse('[' + res.slice(0, res.length - 1) + ']');
        console.info("read file end, events is :" + JSON.stringify(events));
      }
    }
  }, 10000);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.subscribe<sup>10+</sup>

subscribe(rules: QueryRule[]): number

订阅实时系统事件(事件需满足低频率或偶发性的约束条件)，事件发生时立即以文件格式写入应用沙箱固定目录(/data/storage/el2/base/cache/hiview/event/)。用于实时监控关键系统事件并进行告警，如性能异常告警、安全事件监控等场景。适用于低频率或偶发性的关键事件，不建议高频事件使用。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型                      | 必填 | 说明                                       |
| ------ | ------------------------- | ---- | ------------------------------------------ |
| rules  | [QueryRule](#queryrule)[] | 是   | 查询规则数组，每次订阅可配置多个查询规则。 |

**返回值：**

| 类型   | 说明             |
| ------ | ---------------- |
| number | 接口调用时间戳，单位为毫秒（ms）。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |

**示例：**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rules: hiSysEvent.QueryRule[] = [{
    domain: "RELIABILITY",
    names: ["STACK"],
  } as hiSysEvent.QueryRule,
  {
    domain: "BUNDLE_MANAGER",
    names: ["BUNDLE_UNINSTALL"],
  } as hiSysEvent.QueryRule];
  hiSysEvent.subscribe(rules);

  let customizedParams: Record<string, string | number> = {
    'PID': 487,
    'UID': 103,
    'PACKAGE_NAME': "com.ohos.hisysevent.test",
    'PROCESS_NAME': "syseventservice",
    'MSG': "no msg."
  };
  let eventInfo: hiSysEvent.SysEventInfo = {
    domain: "RELIABILITY",
    name: "STACK",
    eventType: hiSysEvent.EventType.FAULT,
    params: customizedParams
  };
  hiSysEvent.write(eventInfo, (err: BusinessError) => {
    // 处理事件写入成功后的操作
  });

  // 等待文件写入完成后读取（建议通过监听文件系统事件或轮询文件大小确认）
  setTimeout(() => {
    let eventDir = '/data/storage/el2/base/cache/hiview/event';
    let filenames = fileIo.listFileSync(eventDir);
    for (let i = 0; i < filenames.length; i++) {
      let res = fileIo.readTextSync(eventDir + '/' + filenames[i]);
      let events: string = JSON.parse('[' + res.slice(0, res.length - 1) + ']');
      console.info("read file end, events is :" + JSON.stringify(events));
    }
  }, 10000);
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.unsubscribe<sup>10+</sup>

unsubscribe(): void

取消订阅所有的实时系统事件。取消订阅成功后，将不再接收实时事件。适用于当不再需要订阅实时事件时调用的场景，能够释放订阅资源，减少资源占用。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](errorcode-hisysevent-sys.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200305 | Unsubscription failed.                                                                                                                          |

**示例：**

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rules: hiSysEvent.QueryRule[] = [{
    domain: "RELIABILITY",
    names: ["STACK"],
  } as hiSysEvent.QueryRule,
  {
    domain: "BUNDLE_MANAGER",
    names: ["BUNDLE_UNINSTALL"],
  } as hiSysEvent.QueryRule];
  hiSysEvent.subscribe(rules);
  hiSysEvent.unsubscribe();
} catch (err) {
  // 捕获并打印错误信息
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

