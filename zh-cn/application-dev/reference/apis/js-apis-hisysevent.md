# 系统事件打点

本模块提供了系统事件打点能力，包括系统事件的埋点、落盘系统事件的订阅及已落盘的系统事件的查询能力。

> **说明：**
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块的接口为系统接口。


## 导入模块

```js
import hiSysEvent from '@ohos.hiSysEvent';
```

## EventType

系统事件类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| FAULT | 1 | 错误事件类型。 |
| STATISTIC | 2 | 统计事件类型。 |
| SECURITY | 3 | 安全事件类型。 |
| BEHAVIOR | 4 | 用户行为事件类型。 |

## SysEventInfo

系统事件信息对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| domain | string | 是 | 事件领域。 |
| name | string | 是 | 事件名称。 |
| eventType | [EventType](#eventtype) | 是 | 事件类型。 |
| params | object | 否 | 事件参数。 |


## hiSysEvent.write

write(info: SysEventInfo, callback: AsyncCallback&lt;void&gt;): void

系统事件打点方法，接收[SysEventInfo](#syseventinfo)类型的对象作为事件参数，使用callback方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| info | [SysEventInfo](#syseventinfo) | 是 | 系统事件。 |
| callback  | AsyncCallback&lt;void&gt; | 是 | 回调函数，可以在回调函数中处理接口返回值。<br/>- 0表示事件校验成功，事件正常异步写入事件文件；<br/>- 正值表示事件打点存在异常，但可以正常写入；<br/>- 负值表示事件打点失败。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](../errorcodes/errorcode-hisysevent.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11200001 | Invalid event domain.                                            |
| 11200002 | Invalid event name.                                              |
| 11200003 | Abnormal environment.                                            |
| 11200004 | Length of the event is over limit.                               |
| 11200051 | Invalid event parameter.                                         |
| 11200052 | Size of the event parameter of the string type is over limit.    |
| 11200053 | Count of event parameters is over limit.                         |
| 11200054 | Count of event parameter of the array type is over limit.        |

**示例：**

```js
import hiSysEvent from '@ohos.hiSysEvent';

try {
    hiSysEvent.write({
        domain: "RELIABILITY",
        name: "STACK",
        eventType: hiSysEvent.EventType.FAULT,
        params: {
            PID: 487,
            UID: 103,
            PACKAGE_NAME: "com.ohos.hisysevent.test",
            PROCESS_NAME: "syseventservice",
            MSG: "no msg."
        }
    }, (err, val) => {
        // do something here.
    })
} catch (error) {
    console.error(`error code: ${error.code}, error msg: ${error.message}`);
}
```


## hiSysEvent.write

write(info: SysEventInfo): Promise&lt;void&gt;

系统事件打点方法，接收[SysEventInfo](#syseventinfo)类型的对象作为事件参数，使用promise方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名    | 类型                    | 必填 | 说明 |
| --------- | ----------------------- | ---- | --------------- |
| info | [SysEventInfo](#syseventinfo) | 是   | 系统事件。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise实例，可以在其then()、catch()方法中分别对系统事件写入成功、写入异常的回调进行处理。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](../errorcodes/errorcode-hisysevent.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------------------------------- |
| 11200001 | Invalid event domain.                                            |
| 11200002 | Invalid event name.                                              |
| 11200003 | Abnormal environment.                                            |
| 11200004 | Length of the event is over limit.                               |
| 11200051 | Invalid event parameter.                                         |
| 11200052 | Size of the event parameter of the string type is over limit.    |
| 11200053 | Count of event parameters is over limit.                         |
| 11200054 | Count of event parameter of the array type is over limit.        |

**示例：**

```js
import hiSysEvent from '@ohos.hiSysEvent';

try {
    hiSysEvent.write({
        domain: "RELIABILITY",
        name: "STACK",
        eventType: hiSysEvent.EventType.FAULT,
        params: {
            PID: 487,
            UID: 103,
            PACKAGE_NAME: "com.ohos.hisysevent.test",
            PROCESS_NAME: "syseventservice",
            MSG: "no msg."
        }
    }).then(
        (val) => {
            // do something here.
        }
    ).catch(
        (err) => {
            // do something here.
        }
    )
} catch (error) {
    console.error(`error code: ${error.code}, error msg: ${error.message}`);
}
```

## RuleType

匹配规则类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| WHOLE_WORD | 1 | 全词匹配类型。 |
| PREFIX | 2 | 前缀匹配类型。 |
| REGULAR | 3 | 正则匹配类型。 |

## WatchRule

系统事件订阅规则对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| domain | string | 是 | 事件领域。 |
| name | string | 是 | 事件名称。 |
| tag | string | 否 | 事件标签。 |
| ruleType | [RuleType](#ruletype) | 是 | 匹配规则类型。 |

## Watcher

系统事件订阅者对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| rules | [WatchRule](#watchrule)[] | 是 | 订阅对象数组，每个订阅者对象包含多个订阅规则。 |
| onEvent | function | 是 | 订阅事件的回调方法(info: [SysEventInfo](#syseventinfo)) => void。 |
| onServiceDied | function | 是 | 系统事件服务关闭的回调方法() => void。 |

## hiSysEvent.addWatcher

addWatcher(watcher: Watcher): void

订阅系统事件，接收[Watcher](#watcher)类型的对象作为事件参数。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------------------------- | ---- | ------------------------ |
| watcher | [Watcher](#watcher) | 是 | 系统事件订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](../errorcodes/errorcode-hisysevent.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------- |
| 11200101 | Count of watchers is over limit.    |
| 11200102 | Count of watch rules is over limit. |

**示例：**

```js
import hiSysEvent from '@ohos.hiSysEvent';

let watcher = {
    rules: [{
        domain: "RELIABILITY",
        name: "STACK",
        tag: "STABILITY",
        ruleType: hiSysEvent.RuleType.WHOLE_WORD,
    }],
    onEvent: (info) => {
        // do something here.
    },
    onServiceDied: () => {
        // do something here.
    }
}
try {
    hiSysEvent.addWatcher(watcher)
} catch (error) {
    console.error(`error code: ${error.code}, error msg: ${error.message}`);
}
```

## hiSysEvent.removeWatcher

removeWatcher(watcher: Watcher): void

取消订阅系统事件，接收[Watcher](#watcher)类型的对象作为事件参数。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型  | 必填 | 说明  |
| ------ | ------------- | ---- | ------------------------- |
| watcher | [Watcher](#watcher) | 是 | 系统事件订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](../errorcodes/errorcode-hisysevent.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------- |
| 11200201 | The watcher does not exist. |

**示例：**

```js
import hiSysEvent from '@ohos.hiSysEvent';

let watcher = {
    rules: [{
        domain: "RELIABILITY",
        name: "STACK",
        tag: "STABILITY",
        ruleType: hiSysEvent.RuleType.WHOLE_WORD,
    }],
    onEvent: (info) => {
        // do something here.
    },
    onServiceDied: () => {
        // do something here.
    }
}
try {
    hiSysEvent.addWatcher(watcher)
    hiSysEvent.removeWatcher(watcher)
} catch (error) {
    console.error(`error code: ${error.code}, error msg: ${error.message}`);
}
```

## QueryArg

系统事件查询参数对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| beginTime | number | 是 | 查询的系统事件起始时间（13位时间戳）。 |
| endTime | number | 是 | 查询的系统事件结束时间（13位时间戳）。 |
| maxEvents | number | 是 | 查询的系统事件最多条数。 |

## QueryRule 

系统事件查询规则对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| domain | string | 是 | 查询包含的事件领域。 |
| names | string[] | 是 | 查询所包含的多个事件名称，每个查询规则对象包含多个系统事件名称。 |

## Querier

系统事件查询者对象接口。

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| onQuery | function | 是 | 返回查询到的系统事件的回调方法(infos: [SysEventInfo](#syseventinfo)[]) => void。 |
| onComplete | function | 是 | 查询结果统计的回调方法(reason: number, total: number) => void。 |

## hiSysEvent.query

query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void

查询系统事件。

**需要权限：** ohos.permission.READ_DFX_SYSEVENT

**系统能力：** SystemCapability.HiviewDFX.HiSysEvent

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------------------------- | ---- | ------------------------ |
| queryArg | [QueryArg](#queryarg) | 是   | 查询需要配置的查询参数。 |
| rules | [QueryRule](#queryrule)[] | 是   | 查询规则数组，每次查询可配置多个查询规则。 |
| querier | [Querier](#querier) | 是   | 查询者对象，包含查询结果及结束的相关回调。 |

**错误码：**

以下错误码的详细介绍请参见[系统事件错误码](../errorcodes/errorcode-hisysevent.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------------------- |
| 11200301 | Count of query rules is over limit.         |
| 11200302 | Invalid query rule.                         |
| 11200303 | Count of concurrent queriers is over limit. |
| 11200304 | Query frequency is over limit.              |

**示例：**

```js
import hiSysEvent from '@ohos.hiSysEvent';

try {
    hiSysEvent.write({
        domain: "RELIABILITY",
        name: "STACK",
        eventType: hiSysEvent.EventType.FAULT,
        params: {
            PID: 487,
            UID: 103,
            PACKAGE_NAME: "com.ohos.hisysevent.test",
            PROCESS_NAME: "syseventservice",
            MSG: "no msg."
        }
    }, (err, val) => {
        // do something here.
    })
    hiSysEvent.query({
        beginTime: -1,
        endTime: -1,
        maxEvents: 5,
    }, [{
        domain: "RELIABILITY",
        names: ["STACK"],
    }], {
        onQuery: function (infos) {
            // do something here.
        },
        onComplete: function(reason, total) {
            // do something here.
        }
    })
} catch (error) {
    console.error(`error code: ${error.code}, error msg: ${error.message}`);
}
```