# @ohos.hiSysEvent (System Event Logging) (System API)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lyj_love_code-->
<!--SE: @tangyyan-->
<!--TSE: @gcw_KuLfPSbe-->

The **hiSysEvent** module provides the system event logging functions, such as configuring trace points, subscribing to system events, and querying system events written to the event file.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { hiSysEvent } from '@kit.PerformanceAnalysisKit';
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

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| domain | string | No| No| Event domain.|
| name | string | No| No| Event name.|
| eventType | [EventType](#eventtype) | No| No| Event type.|
| params | object | No| Yes| Event parameters.|


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

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
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

**Example**

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
    // do something here.
  });
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
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

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
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

**Example**

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
  hiSysEvent.write(eventInfo).then(
    () => {
      // do something here.
    }
  ).catch(
    (err: BusinessError) => {
      console.error(`error code: ${err.code}, error msg: ${err.message}`);
    }
  );
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
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

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| domain | string | No| No| Event domain.|
| name | string | No| No| Event name.|
| tag | string | No| Yes| Event tag.|
| ruleType | [RuleType](#ruletype) | No| No| Matching rule type.|

## Watcher

Defines a watcher for event subscription.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| rules | [WatchRule](#watchrule)[] | No| No| Array of matching event subscription rules.|
| onEvent | function | No| No| Callback for event subscription: (info: [SysEventInfo](#syseventinfo)) => void|
| onServiceDied | function | No| No| Callback for disabling of event subscription: () => void|

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

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200101 | The number of watchers exceeds the limit.                                                                                                       |
| 11200102 | The number of watch rules exceeds the limit.                                                                                                    |

**Example**

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
    // do something here.
  },
  onServiceDied: () => {
    // do something here.
  }
};
try {
  hiSysEvent.addWatcher(watcher);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
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

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200201 | The watcher does not exist.                                                                                                                     |

**Example**

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
    // do something here.
  },
  onServiceDied: () => {
    // do something here.
  }
};
try {
  hiSysEvent.addWatcher(watcher);
  hiSysEvent.removeWatcher(watcher);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## QueryArg

Defines arguments for an event query.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| beginTime | number | No| No| Start time (13-digit timestamp) for the event query.|
| endTime | number | No| No| End time (13-digit timestamp) for the event query.|
| maxEvents | number | No| No| Maximum number of events that can be queried.|
| fromSeq<sup>10+</sup> | number | No| Yes| Start SN of the events to be queried. The default value is **-1**.|
| toSeq<sup>10+</sup> | number | No| Yes| End SN of the system events to be queried. The default value is **-1**.|

## QueryRule 

Defines event query rules.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| domain | string | No| No| Event domain.|
| names | string[] | No| No| Array of event names. A **QueryRule** object contains multiple system event names.|
| condition<sup>10+</sup> | string | No| Yes| Additional event conditions. The value of this parameter is in the format of {"version":"V1","condition":{"and":[{"param":"*Parameter*","op":"*Operator*","value":"*Comparison value*"}]}}.|

## Querier

Defines an event query instance.

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| onQuery | function | No| No| Callback used to return the queried system events: (infos: [SysEventInfo](#syseventinfo)[]) => void.|
| onComplete | function | No| No| Callback used to return the query result statistics: (reason: number, total: number) => void|

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

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |
| 11200303 | The number of concurrent queriers exceeds the limit.                                                                                            |
| 11200304 | The query frequency exceeds the limit.                                                                                                          |

**Example**

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
    // do something here.
  });

  let queryArg: hiSysEvent.QueryArg = {
    beginTime: -1,
    endTime: -1,
    maxEvents: 5,
  };
  let queryRules: hiSysEvent.QueryRule[] = [{
    domain: "RELIABILITY",
    names: ["STACK"],
  } as hiSysEvent.QueryRule];
  let querier: hiSysEvent.Querier = {
    onQuery: (infos: hiSysEvent.SysEventInfo[]) => {
      // do something here.
    },
    onComplete: (reason: number, total: number) => {
      // do something here.
    }
  };
  hiSysEvent.query(queryArg, queryRules, querier);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.exportSysEvents<sup>10+</sup>

exportSysEvents(queryArg: QueryArg, rules: QueryRule[]): number

Exports system events in batches and writes them as a file to the fixed directory of the application sandbox (that is, **/data/storage/el2/base/cache/hiview/event/**).

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name  | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| queryArg | [QueryArg](#queryarg)     | Yes  | Event query parameters for the export.                  |
| rules    | [QueryRule](#queryrule)[] | Yes  | Array of event query rules for the export.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | API call timestamp.|

**Error codes**

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |
| 11200304 | The query frequency exceeds the limit.                                                                                                          |

**Example**

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
    // do something here.
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
  console.log(`receive export task time is : ${time}`);

  // Postpone reading of exported events.
  setTimeout(() => {
    let eventDir = '/data/storage/el2/base/cache/hiview/event';
    let filenames = fileIo.listFileSync(eventDir);
    for (let i = 0; i < filenames.length; i++) {
      if (filenames[i].indexOf(time.toString()) != -1) {
        let res = fileIo.readTextSync(eventDir + '/' + filenames[i]);
        let events: string = JSON.parse('[' + res.slice(0, res.length - 1) + ']');
        console.log("read file end, events is :" + JSON.stringify(events));
      }
    }
  }, 10000);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.subscribe<sup>10+</sup>

subscribe(rules: QueryRule[]): number

Subscribes to real-time system events that occur occasionally or occur in a low frequency. These events are written as a file to the fixed directory of the application sandbox (that is, **/data/storage/el2/base/cache/hiview/event/**).

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Parameters**

| Name| Type                     | Mandatory| Description                                      |
| ------ | ------------------------- | ---- | ------------------------------------------ |
| rules  | [QueryRule](#queryrule)[] | Yes  | Array of event query rules for the subscription.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | API call timestamp.|

**Error codes**

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200301 | The number of query rules exceeds the limit.                                                                                                    |
| 11200302 | Invalid query rule.                                                                                                                             |

**Example**

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
    // do something here.
  });

  // Postpone reading of subscribed events.
  setTimeout(() => {
    let eventDir = '/data/storage/el2/base/cache/hiview/event';
    let filenames = fileIo.listFileSync(eventDir);
    for (let i = 0; i < filenames.length; i++) {
      let res = fileIo.readTextSync(eventDir + '/' + filenames[i]);
      let events: string = JSON.parse('[' + res.slice(0, res.length - 1) + ']');
      console.log("read file end, events is :" + JSON.stringify(events));
    }
  }, 10000);
} catch (err) {
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```

## hiSysEvent.unsubscribe<sup>10+</sup>

unsubscribe(): void

Unsubscribes from system events.

**Required permission**: ohos.permission.READ_DFX_SYSEVENT

**System capability**: SystemCapability.HiviewDFX.HiSysEvent

**Error codes**

For details about the following error codes, see [HiSysEvent Error Codes](errorcode-hisysevent-sys.md).

| ID| Error Message|
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied. An attempt was made to read system event forbidden by permission: ohos.permission.READ_DFX_SYSEVENT.                         |
| 202      | System API is not allowed called by Non-system application.                                                                                     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 11200305 | Failed to unsubscribe.                                                                                                                          |

**Example**

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
  console.error(`error code: ${(err as BusinessError).code}, error msg: ${(err as BusinessError).message}`);
}
```
