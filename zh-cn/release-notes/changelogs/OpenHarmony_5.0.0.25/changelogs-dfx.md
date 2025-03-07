# DFX子系统ChangeLog

## cl.hiviewdfx.1 HiSysEvent模块SysEventInfo接口params成员可选性调整

**访问级别**

系统接口

**变更原因**

接口声明和实现不一致

**变更影响**

该变更为不兼容变更。

SysEventInfo接口的params成员已经从必选参数调整为可选参数，影响开发者通过SysEventInfo接口的params成员赋值。

变更前:

```
interface SysEventInfo {
  domain: string;
  name: string;
  eventType: EventType;
  params: object;
}
```

变更后：

```
interface SysEventInfo {
  domain: string;
  name: string;
  eventType: EventType;
  params?: object;
}
```

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 版本开始。

**变更的接口/组件**

hiSysEvent.SysEventInfo

**适配指导**

通过SysEventInfo的params成员赋值不指定类型即可。

```
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

let params = eventInfo.params;
```

## cl.hiviewdfx.2 HiSysEvent模块WatchRule接口tag成员可选性调整

**访问级别**

系统接口

**变更原因**

接口声明和实现不一致

**变更影响**

该变更为不兼容变更。

WatchRule接口的tag成员从必选参数调整为可选参数，影响开发者通过WatchRule接口的tag成员赋值。

变更前:

```
interface WatchRule {
  domain: string;
  name: string;
  tag: string;
  ruleType: RuleType;
}
```

变更后：

```
interface WatchRule {
  domain: string;
  name: string;
  tag?: string;
  ruleType: RuleType;
}
```

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.25 版本开始。

**变更的接口/组件**

hiSysEvent.WatchRule 

**适配指导**

通过WatchRule的tag成员赋值不指定类型即可。

```
let watchRules: hiSysEvent.WatchRule[] = [{
  domain: "RELIABILITY",
  name: "STACK",
  tag: "STABILITY",
  ruleType: hiSysEvent.RuleType.WHOLE_WORD,
} as hiSysEvent.WatchRule];

let tag = watchRules.tag;
```