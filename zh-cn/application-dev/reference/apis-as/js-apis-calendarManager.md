# @ohos.calendarManager (日程管理能力)

Calendar Kit提供日历与日程管理能力，包括日历的获取，日程的创建功能。日历管理器[CalendarManager](#calendarmanager)用于管理日历[Calendar](#calendar)。日历[Calendar](#calendar)包含帐户信息[CalendarAccount](#calendaraccount)。日历Calendar与日程Event属于一对多关系，一个Calendar可以有多个Event，一个Event只属于一个Calendar。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```typescript
import calendarManager from '@ohos.calendarManager';
```

## calendarManager.getCalendarManager

getCalendarManager(context : Context): CalendarManager

根据上下文获取CalendarManager对象，用于管理日历。

**系统能力**： SystemCapability.Applications.CalendarData

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |

**返回值**：

| 类型                           | 说明                                  |
| ------------------------------ | ------------------------------------- |
| CalendarManager | 返回创建的CalendarManager对象。 |

**示例**：

```typescript
// 获取context
// 获取calendarManager
// !!!以下代码中的class EntryAbility extends UIAbility，onWindowStageCreate在工程main/ets/entryability/EntryAbility.ets中，测试ohosTest/ets/testability/TestAbility.ets中有，可直接使用
// calendarMgr需在主线程中获取，worker线程会获取失败
// 请在调用getCalendarManager接口之前确定已经手动申请成功ohos.permission.WRITE_CALENDAR和ohos.permission.READ_CALENDAR权限，否则会影响后续函数调用
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';
import window from '@ohos.window';

export let mContext : common.UIAbilityContext | null = null;
export let calendarMgr : calendarManager.CalendarManager | null = null;
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    mContext = this.context;
    calendarMgr = calendarManager.getCalendarManager(mContext);
  }
}
```

## CalendarManager

下列API示例中需先通过[getCalendarManager()](#calendarmanagergetcalendarmanager)方法获取CalendarManager对象，再通过此对象调用对应方法，进行Calendar的获取操作。

### getCalendar

getCalendar(callback: AsyncCallback\<Calendar>): void

获取默认Calendar对象，默认Calendar是日历存储首次运行时创建的，可直接使用。

**需要权限**：ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                                 | 必填 | 说明                                 |
| -------- | ------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | 是   | 回调函数，返回查询到的Calendar对象。 |

**示例**：

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../testability/TestAbility'; // 路径适用于测试模块

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
  }
});
```

### getCalendar

getCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void

获取指定Calendar对象，使用callback异步回调。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                 | 必填 | 说明                                 |
| --------------- | ------------------------------------ | ---- | ------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | 是   | 日历帐户信息。                       |
| callback        | AsyncCallback<[Calendar](#calendar)> | 是   | 回调函数，返回查询到的Calendar对象。 |

**示例**：

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../testability/TestAbility'; // 路径适用于测试模块

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to create calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
  }
});
calendarMgr?.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
  }
});
```

### getCalendar

getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar>

获取默认Calendar对象或者指定Calendar对象，使用Promise异步回调。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                | 必填 | 说明                                                         |
| --------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | 否   | 日历帐户信息，用来获取指定Calendar对象，不填时，表示获取默认Calendar对象。 |

**返回值**：

| 类型                           | 说明                                    |
| ------------------------------ | --------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise对象，返回查询到的Calendar对象。 |

**示例**：

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../testability/TestAbility'; // 路径适用于测试模块

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
  calendar = data;
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
});
```

## Calendar

下列API示例中需先通过[getCalendar()](#getcalendar)方法获取Calendar对象，再通过此对象调用对应方法，对该Calendar下的日程进行创建操作。

### 属性

**系统能力**：SystemCapability.Applications.CalendarData

| 名称 | 类型   | 只读 | 必填 | 说明     |
| ---- | ------ | ---- | ---- | -------- |
| id   | number | 是   | 是   | 日历帐户id。 |

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

创建日程，入参[Event](#event)不填日程id，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | [Event](#event)        | 是   | Event对象。            |
| callback | AsyncCallback\<number> | 是   | 回调函数，返回日程id。 |

**示例**：

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../testability/TestAbility'; // 路径适用于测试模块

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
  }
});
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendar.addEvent(event, (err: BusinessError, data: number): void => {
  if (err) {
    console.error(`Failed to addEvent: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in adding event id:${data}`);
  }
});
```

### addEvent

addEvent(event: Event): Promise\<number>

创建日程，入参[Event](#event)不填日程id，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明        |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | 是   | Event对象。 |

**返回值**：

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<number> | Promise对象，返回日程的id。 |

**示例**：

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../testability/TestAbility'; // 路径适用于测试模块

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
  }
});
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendar.addEvent(event).then((data: number) => {
  console.info(`Succeeded in adding event id:${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to addEvent: err->${JSON.stringify(err)}`);
});
```

## CalendarAccount

日历帐户信息。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                          | 只读 | 必填 | 说明                                   |
| ----------- | ----------------------------- | ---- | ---- | -------------------------------------- |
| name        | string                        | 是   | 是   | 帐户名称。                             |
| type        | [CalendarType](#calendartype) | 否   | 是   | 帐户类型。                             |
| displayName | string                        | 否   | 否   | 帐户的显示名称。不填时，默认为空字符串。 |

## Event

日程对象，包含日程标题、开始时间、结束时间等信息。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称           | 类型                              | 只读 | 必填 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| id             | number                            | 是   | 否   | 日程id。当调用[addEvent()](#addevent)|
| type           | [EventType](#eventtype)           | 否   | 是   | 日程类型。                                                   |
| title          | string                            | 否   | 否   | 日程标题。不填时，默认为空字符串。                             |
| location       | [Location](#location)             | 否   | 否   | 日程地点。不填时，默认为null。                               |
| startTime      | number                            | 否   | 是   | 日程开始时间。                                               |
| endTime        | number                            | 否   | 是   | 日程结束时间。                                               |
| isAllDay       | boolean                           | 否   | 否   | 是否为全天日程。当取值为true时，说明为全天日程；当取值为false时，说明不是全天日程，默认为非全天日程。 |
| attendee       | [Attendee](#attendee)[]           | 否   | 否   | 日程参与者。不填时，默认为null。                             |
| timeZone       | string                            | 否   | 否   | 日程时区。不填时，默认为当前所在时区，当需要创建与当前不一样的时区时，可填入对应的时区。可通过[getTimeZone()](../apis/js-apis-system-date-time.md#systemdatetimegettimezone)获取当前系统时区。 |
| reminderTime   | number[]                          | 否   | 否   | 日程提醒时间。不填时，默认为不提醒。                           |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | 否   | 否   | 日程重复规则。不填时，默认为不重复。                           |
| description    | string                            | 否   | 否   | 日程描述。不填时，默认为空字符串。                             |
| service        | [EventService](#eventservice)     | 否   | 否   | 日程服务。不填时，默认没有一键服务。                           |

## CalendarType

帐户类型枚举。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称       | 值           | 说明                 |
| ---------- | ------------ | -------------------- |
| LOCAL      | 'local'      | 本地帐户。           |
| EMAIL      | 'email'      | 邮箱帐户。           |
| BIRTHDAY   | 'birthday'   | 生日帐户。           |
| CALDAV     | 'caldav'     | 支持CalDAV协议帐户。 |
| SUBSCRIBED | 'subscribed' | 订阅帐户。           |

## Location

日程地点。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 类型   | 只读 | 必填 | 说明                     |
| --------- | ------ | ---- | ---- | ------------------------ |
| location  | string | 否   | 否   | 地点位置。默认为空字符串。 |
| longitude | number | 否   | 否   | 地点经度。默认为0。        |
| latitude  | number | 否   | 否   | 地点纬度。默认为0。        |

## EventType

日程类型枚举。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 值   | 说明                 |
| --------- | ---- | -------------------- |
| NORMAL    | 0    | 普通日程。           |
| IMPORTANT | 1    | 重要日程。支持倒计时。 |

## RecurrenceRule

日程重复规则。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称                | 类型                                        | 只读 | 必填 | 说明                            |
| ------------------- | ------------------------------------------- | ---- | ---- | ------------------------------- |
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | 否   | 是   | 日程重复规则类型。              |
| expire              | number                                      | 否   | 否   | 重复周期截止日。不填时，默认为0。 |

## RecurrenceFrequency

日程重复规则类型枚举。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称    | 值   | 说明       |
| ------- | ---- | ---------- |
| YEARLY  | 0    | 每年重复。 |
| MONTHLY | 1    | 每月重复。 |
| WEEKLY  | 2    | 每周重复。 |
| DAILY   | 3    | 每天重复。 |

## Attendee

日程参与者。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称  | 类型   | 只读 | 必填 | 说明           |
| ----- | ------ | ---- | ---- | -------------- |
| name  | string | 否   | 是   | 参与者的姓名。 |
| email | string | 否   | 是   | 参与者的邮箱。 |

## EventService

日程服务。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                        | 只读 | 必填 | 说明                                  |
| ----------- | --------------------------- | ---- | ---- | ------------------------------------- |
| type        | [ServiceType](#servicetype) | 否   | 是   | 服务类型。                            |
| uri         | string                      | 否   | 是   | 服务的uri。可以跳转到三方应用相应界面。 |
| description | string                      | 否   | 否   | 服务辅助描述。不填时，默认为空字符串。  |

## ServiceType

日程服务类型枚举。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称            | 值               | 说明         |
| --------------- | ---------------- | ------------ |
| MEETING         | 'Meeting'        | 一键入会。   |
| WATCHING        | 'Watching'       | 一键追剧。   |
| REPAYMENT       | 'Repayment'      | 一键还款。   |
| LIVE            | 'Live'           | 一键直播。   |
| SHOPPING        | 'Shopping'       | 一键购物。   |
| TRIP            | 'Trip'           | 一键查看。   |
| CLASS           | 'Class'          | 一键上课。   |
| SPORTS_EVENTS   | 'SportsEvents'   | 一键看赛事。 |
| SPORTS_EXERCISE | 'SportsExercise' | 一键运动。   |