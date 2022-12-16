# HiSysEvent

This module provides the system event logging functions, such as configuring trace points, subscribing to system events, and querying system events written to the event file.

> **NOTE**
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.


## Modules to Import

```js
import hiSysEvent from '@ohos.hiSysEvent';
```

## EventType

Enumerates event types.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Value| Description|
| -------- | -------- | -------- |
| FAULT | 1 | Error event.|
| STATISTIC | 2 | Statistic event.|
| SECURITY | 3 | Security event.|
| BEHAVIOR | 4 | User behavior event.|

## SysEventInfo

Defines a system event.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| domain | string | Yes| Event domain.|
| name | string | Yes| Event name.|
| eventType | [EventType](#eventtype) | Yes| Event type.|
| params | object | No| Event parameters.|


## hiSysEvent.write

write(info: SysEventInfo, callback: AsyncCallback&lt;void&gt;): void

Writes event information to the event file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name   | Type                     | Mandatory| Description                                                        |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| info | [SysEventInfo](#syseventinfo) | Yes| System event information.|
| callback  | AsyncCallback&lt;void&gt; | Yes| Callback used to process the received return value.<br>- Value **0**: The event verification is successful, and the event will be written to the event file asynchronously. <br>- A value greater than **0**: Invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored.<br>- A value smaller than **0**: The event parameter verification fails, and the event will not be written to the event file.|

**Error codes**

For details about the error codes, see [HiSysEvent Error Codes](../errorcodes/errorcode-hisysevent.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 11200001 | Invalid event domain.                                            |
| 11200002 | Invalid event name.                                              |
| 11200003 | Abnormal environment.                                            |
| 11200004 | Length of the event is over limit.                               |
| 11200051 | Invalid event parameter.                                         |
| 11200052 | Size of the event parameter of the string type is over limit.    |
| 11200053 | Count of event parameters is over limit.                         |
| 11200054 | Count of event parameter of the array type is over limit.        |

**Example**

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

Writes event information to the event file. This API uses a promise to return the result.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name   | Type                   | Mandatory| Description|
| --------- | ----------------------- | ---- | --------------- |
| info | [SysEventInfo](#syseventinfo) | Yes  | System event information.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise used to return the result. Depending on whether event writing is successful, you can use the **then()** or **catch()** method to process the callback.|

**Error codes**

For details about the error codes, see [HiSysEvent Error Codes](../errorcodes/errorcode-hisysevent.md).

| ID| Error Message|
| -------- | ---------------------------------------------------------------- |
| 11200001 | Invalid event domain.                                            |
| 11200002 | Invalid event name.                                              |
| 11200003 | Abnormal environment.                                            |
| 11200004 | Length of the event is over limit.                               |
| 11200051 | Invalid event parameter.                                         |
| 11200052 | Size of the event parameter of the string type is over limit.    |
| 11200053 | Count of event parameters is over limit.                         |
| 11200054 | Count of event parameter of the array type is over limit.        |

**Example**

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

Enumerates matching rule types.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Value| Description|
| -------- | -------- | -------- |
| WHOLE_WORD | 1 | Whole word matching.|
| PREFIX | 2 | Prefix matching.|
| REGULAR | 3 | Regular expression matching.|

## WatchRule

Defines event subscription rules.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| domain | string | Yes| Event domain.|
| name | string | Yes| Event name.|
| tag | string | No| Event tag.|
| ruleType | [RuleType](#ruletype) | Yes| Matching rule type.|

## Watcher

Defines a watcher for event subscription.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rules | [WatchRule](#watchrule)[] | Yes| Array of matching event subscription rules.|
| onEvent | function | Yes| Callback for event subscription: (info: [SysEventInfo](#syseventinfo)) => void|
| onServiceDied | function | Yes| Callback for disabling of event subscription: () => void|

## hiSysEvent.addWatcher

addWatcher(watcher: Watcher): void

Adds a watcher for event subscription.

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------------------------- | ---- | ------------------------ |
| watcher | [Watcher](#watcher) | Yes| Watcher for event subscription.|

**Error codes**

For details about the error codes, see [HiSysEvent Error Codes](../errorcodes/errorcode-hisysevent.md).

| ID| Error Message|
| -------- | ----------------------------------- |
| 11200101 | Count of watchers is over limit.    |
| 11200102 | Count of watch rules is over limit. |

**Example**

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

Removes a watcher used for event subscription.

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name| Type | Mandatory| Description |
| ------ | ------------- | ---- | ------------------------- |
| watcher | [Watcher](#watcher) | Yes| Watcher for event subscription.|

**Error codes**

For details about the error codes, see [HiSysEvent Error Codes](../errorcodes/errorcode-hisysevent.md).

| ID| Error Message|
| -------- | --------------------------- |
| 11200201 | The watcher does not exist. |

**Example**

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

Defines arguments for an event query.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| beginTime | number | Yes| Start time (13-digit timestamp) for the event query.|
| endTime | number | Yes| End time (13-digit timestamp) for the event query.|
| maxEvents | number | Yes| Maximum number of events that can be queried.|

## QueryRule 

Defines event query rules.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| domain | string | Yes| Event domain.|
| names | string[] | Yes| Array of event names. A **QueryRule** object contains multiple system event names.|

## Querier

Defines an event query instance.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| onQuery | function | Yes| Callback used to return the queried system events: (infos: [SysEventInfo](#syseventinfo)[]) => void.|
| onComplete | function | Yes| Callback used to return the query result statistics: (reason: number, total: number) => void|

## hiSysEvent.query

query(queryArg: QueryArg, rules: QueryRule[], querier: Querier): void

Queries system events.

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------------------------- | ---- | ------------------------ |
| queryArg | [QueryArg](#queryarg) | Yes  | Arguments for event query.|
| rules | [QueryRule](#queryrule)[] | Yes  | Array of event query rules.|
| querier | [Querier](#querier) | Yes  | Event query instance.|

**Error codes**

For details about the error codes, see [HiSysEvent Error Codes](../errorcodes/errorcode-hisysevent.md).

| ID| Error Message|
| -------- | ------------------------------------------- |
| 11200301 | Count of query rules is over limit.         |
| 11200302 | Invalid query rule.                         |
| 11200303 | Count of concurrent queriers is over limit. |
| 11200304 | Query frequency is over limit.              |

**Example**

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
