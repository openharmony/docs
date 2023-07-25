# @ohos.calendarManager (日程管理能力)

本模块提供账户与日程管理能力，包括创建、删除、修改、查询等

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```javascript
import calendarManager from'@ohos.calendarManager';
```


## calendarManager.createCalendar

createCalendar(calendarAccount: [CalendarAccount](#calendaraccount), callback: AsyncCallback<[Calendar](#calendar)>): void

创建账户，使用回调的方式实现异步调用。

**需要权限**： ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                  | 必填 | 说明                               |
| --------------- | ------------------------------------- | ---- | ---------------------------------- |
| calendarAccount | [CalendarAccount](#calendaraccount)   | 是   | 账户信息实例。                     |
| callback        | AsyncCallback\<[Calendar](#calendar)> | 是   | 异步回调，返回创建的Calendar对象。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.createCalendar({ name: 'MyCalendar', type: calendarManager.CalendarType.LOCAL }, (err, data) => {
  if (err) {
    console.log("create calendar failed");
  } else {
    console.log("create calendar success");
  }
});
```

## calendarManager.createCalendar

createCalendar(calendarAccount: [CalendarAccount](#calendaraccount)): Promise<[Calendar](#calendar)>

创建账户，使用Promise方式实现异步调用。

**需要权限**： ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                | 必填 | 说明           |
| --------------- | ----------------------------------- | ---- | -------------- |
| calendarAccount | [CalendarAccount](#calendaraccount) | 是   | 账户信息实例。 |

**返回值**：

| 类型                           | 说明           |
| ------------------------------ | -------------- |
| Promise<[Calendar](#calendar)> | 返回账户实例。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.createCalendar({ name: 'MyCalendar', type: calendarManager.CalendarType.LOCAL }).then((data) => {
  console.log("create calendar success");
}).catch((err) => {
  console.log("create calendar failed");
});
```

## calendarManager.deleteCalendar

deleteCalendar(calendar: [Calendar](#calendar), callback: AsyncCallback<void>): void

删除账户，使用回调的方式实现异步调用。

**需要权限**： ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| calendar | [Calendar](#calendar) | 是   | 账户实例。 |
| callback | AsyncCallback<void>   | 是   | 异步回调。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar({ name: 'MyCalendar', type: calendarManager.CalendarType.LOCAL });
calendarManager.deleteCalendar(calendar, (err, data) => {
  if (err) {
    console.log("delete calendar failed");
  } else {
    console.log("delete calendar success");
  }
});
```

## calendarManager.deleteCalendar

deleteCalendar(calendar: [Calendar](#calendar)): Promise<void>

删除账户，使用Promise方式实现异步调用。

**需要权限**： ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| calendar | [Calendar](#calendar) | 是   | 账户实例。 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar({ name: 'MyCalendar', type: calendarManager.CalendarType.LOCAL });
calendarManager.deleteCalendar(calendar).then((data) => {
  console.log("delete calendar success");
}).catch((err) => {
  console.log("delete calendar failed");
});
```

## calendarManager.getCalendar

getCalendar(callback: AsyncCallback<[Calendar](#calendar)>): void

获取默认账户，使用回调的方式实现异步调用。

**需要权限**：ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                                 | 必填 | 说明                           |
| -------- | ------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | 是   | 异步回调，返回查询的账户实例。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.getCalendar((err, data) => {
  if (err) {
    console.log("get calendar failed");
  } else {
    console.log("get calendar success");
  }
});
```

## calendarManager.getCalendar

getCalendar(calendarAccount: [CalendarAccount](#calendaraccount)，callback: AsyncCallback<[Calendar](#calendar)>): void

获取指定账户，使用回调的方式实现异步调用。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                 | 必填 | 说明                           |
| --------------- | ------------------------------------ | ---- | ------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | 是   | 账户信息实例                   |
| callback        | AsyncCallback<[Calendar](#calendar)> | 是   | 异步回调，返回查询的账户实例。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.getCalendar({ name: 'MyCalendar', type: calendarManager.CalendarType.LOCAL }, (err, data) => {
  if (err) {
    console.log("get calendar failed");
  } else {
    console.log("get calendar success");
  }
});
```

## calendarManager.getCalendar

getCalendar(calendarAccount?: [CalendarAccount](#calendaraccount)): Promise<[Calendar](#calendar)>

获取账户，使用Promise的方式实现异步调用。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                | 必填 | 说明         |
| --------------- | ----------------------------------- | ---- | ------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | 否   | 账户信息实例 |

**返回值**：

| 类型                           | 说明                 |
| ------------------------------ | -------------------- |
| Promise<[Calendar](#calendar)> | 返回查询的账户实例。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';


calendarManager.getCalendar().then((data) => {
  console.log("get calendar success");
}).catch((err) => {
  console.log("get calendar failed");
});
```

## calendarManager.getAllCalendars

getAllCalendars(callback: AsyncCallback<[Calendar](#calendar)[]>): void

获取当前应用所有创建的账户以及默认账户，使用回调的方式实现异步调用。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                                   | 必填 | 说明                                |
| -------- | -------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | 是   | 异步回调， 返回查询的账户实例数组。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.getAllCalendars((err, data) => {
  if (err) {
    console.log("get all calendars failed");
  } else {
    console.log("get all calendars success");
  }
});
```

## calendarManager.getAllCalendars

getAllCalendars(): Promise<[Calendar](#calendar)[]>

获取当前应用所有创建的账户以及默认账户，使用Promise方式实现异步调用。

**需要权限**： ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                             | 说明                     |
| -------------------------------- | ------------------------ |
| Promise<[Calendar](#calendar)[]> | 返回查询的账户实例数组。 |

**错误码：**

| 错误码ID | 错误信息                    |
| -------- | --------------------------- |
| 201      | Permission denied.          |
| 401      | The parameter check failed. |
| 801      | Capability not supported.   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

calendarManager.getAllCalendars().then((data) => {
  console.log("get all calendars success");
}).catch((err) => {
  console.log("get all calendars failed");
});
```

## Calendar

### 属性

**系统能力**：SystemCapability.Applications.CalendarData

| 名称 | 类型   | 只读 | 必填 | 说明   |
| ---- | ------ | ---- | ---- | ------ |
| id   | number | 是   | 是   | 账户id |

### addEvent

addEvent(event:   [Event](#event), callback: AsyncCallback<number>): void

创建日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| event    | [Event](#event)       | 是   | 日程具体参数实例。     |
| callback | AsyncCallback<number> | 是   | 异步回调，返回日程id。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTimer: date.getTime(),
  endTimer: date.getTime() + 60 * 60 * 1000
};
calendar.addEvent(event, (err, data) => {
  if (err) {
    console.log("add event failed");
  } else {
    console.log("add event success");
  }
});
```

### addEvent

addEvent(event:   [Event](#event)): Promise<number>

创建日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明               |
| ------ | --------------- | ---- | ------------------ |
| event  | [Event](#event) | 是   | 日程具体参数实例。 |

**返回值**：

| 类型             | 说明           |
| ---------------- | -------------- |
| Promise\<number> | 返回日程的id。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTimer: date.getTime(),
  endTimer: date.getTime() + 60 * 60 * 1000
};
calendar.addEvent(event).then((data) => {
  console.log("add event success");
}).catch((err) => {
  console.log("add event failed");
});
```

### addEvents

addEvents(events: [Event](#event)[], callback: AsyncCallback<void>): void

批量创建日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                | 必填 | 说明                   |
| -------- | ------------------- | ---- | ---------------------- |
| events   | [Event](#event)[]   | 是   | 日程具体参数实例数组。 |
| callback | AsyncCallback<void> | 是   | 异步回调。             |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const events: calendarManager.Event[] = [
  {
    type: calendarManager.EventType.NORMAL,
    startTimer: date.getTime(),
    endTimer: date.getTime() + 60 * 60 * 1000
  },
  {
    type: calendarManager.EventType.NORMAL,
    startTimer: date.getTime(),
    endTimer: date.getTime() + 60 * 60 * 1000
  }
];
calendar.addEvents(events, (err, data) => {
  if (err) {
    console.log("add events failed");
  } else {
    console.log("add events success");
  }
});
```

### addEvents

addEvents(events:   [Event](#event)[]): Promise<void>

批量创建日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型              | 必填 | 说明                   |
| ------ | ----------------- | ---- | ---------------------- |
| events | [Event](#event)[] | 是   | 日程具体参数实例数组。 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const events: calendarManager.Event[] = [
  {
    type: calendarManager.EventType.NORMAL,
    startTimer: date.getTime(),
    endTimer: date.getTime() + 60 * 60 * 1000
  },
  {
    type: calendarManager.EventType.NORMAL,
    startTimer: date.getTime(),
    endTimer: date.getTime() + 60 * 60 * 1000
  }
];
calendar.addEvents(events).then(() => {
  console.log("add events success");
}).catch((err) => {
  console.log("add events failed");
});
```

### deleteEvent

deleteEvent(id: number, callback: AsyncCallback<void>): void

删除日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                | 必填 | 说明       |
| -------- | ------------------- | ---- | ---------- |
| id       | number              | 是   | 日程id。   |
| callback | AsyncCallback<void> | 是   | 异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
calendar.deleteEvent(1, (err, data) => {
  if (err) {
    console.log("delete event failed");
  } else {
    console.log("delete event success");
  }
});
```

### deleteEvent

deleteEvent(id: number): Promise<void>

删除日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| id     | number | 是   | 日程id。 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
calendar.deleteEvent(1).then(() => {
  console.log("delete event success");
}).catch((err) => {
  console.log("delete event failed");
});
```

### deleteEvents

deleteEvents(ids: number[], callback: AsyncCallback<void>): void

批量删除日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                | 必填 | 说明         |
| -------- | ------------------- | ---- | ------------ |
| ids      | number[]            | 是   | 日程id数组。 |
| callback | AsyncCallback<void> | 是   | 异步回调。   |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
calendar.deleteEvents([1, 2], (err, data) => {
  if (err) {
    console.log("delete events failed");
  } else {
    console.log("delete events success");
  }
});
```

### deleteEvents

deleteEvents(ids: number[]): Promise<void>

批量删除日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | 是   | 日程id数组。 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
calendar.deleteEvents([1, 2]).then(() => {
  console.log("delete events success");
}).catch((err) => {
  console.log("delete events failed");
});
```

### updateEvent

updateEvent(event: [Event](#event), callback: AsyncCallback<void>): void

更新日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                | 必填 | 说明               |
| -------- | ------------------- | ---- | ------------------ |
| event    | [Event](#event)     | 是   | 日程具体参数示例。 |
| callback | AsyncCallback<void> | 是   | 异步回调。         |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const event: calendarManager.Event = {
  id: 1,
  title: 'update',
  type: calendarManager.EventType.NORMAL,
  startTimer: date.getTime(),
  endTimer: date.getTime() + 60 * 60 * 1000
};
calendar.updateEvent(event, (err, data) => {
  if (err) {
    console.log("update event failed");
  } else {
    console.log("update event success");
  }
});
```

### updateEvent

updateEvent(event: [Event](#event)): Promise<void>

更新日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明               |
| ------ | --------------- | ---- | ------------------ |
| event  | [Event](#event) | 是   | 日程具体参数示例。 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const date = new Date();
const event: calendarManager.Event = {
  id: 1,
  title: 'update',
  type: calendarManager.EventType.NORMAL,
  startTimer: date.getTime(),
  endTimer: date.getTime() + 60 * 60 * 1000
};
calendar.updateEvent(event).then(() => {
  console.log("update event success");
}).catch((err) => {
  console.log("update event failed");
});
```

### getEvents

getEvents(callback: AsyncCallback<[Event](#event)[]>): void

查询账户下所有日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                             | 必填 | 说明                             |
| -------- | -------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<[Event](#event)[]> | 是   | 异步回调，返回的是日程实例数组。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
calendar.getEvents((err, data) => {
  if (err) {
    console.log("get events failed");
  } else {
    console.log("get events success");
  }
});
```

### getEvents

getEvents(eventFilter: [EventFilter](#eventfilter), eventKey: (keyof [Event](#event))[], callback: AsyncCallback<[Event](#event)[]>):void

查询账户下符合条件的日程，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名      | 类型                             | 必填 | 说明                             |
| ----------- | -------------------------------- | ---- | -------------------------------- |
| eventFilter | [EventFilter](#eventfilter)      | 是   | 查询条件                         |
| eventKey    | (keyof [Event](#event))[]        | 是   | 查询结果集                       |
| callback    | AsyncCallback<[Event](#event)[]> | 是   | 异步回调，返回的是日程实例数组。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const filter = calendarManager.EventFilter.filterById([1, 2]);
const columns: (keyof calendarManager.Event)[] =  ['title', 'type', 'startTimer', 'endTimer'];
calendar.getEvents(filter, columns, (err, data) => {
  if (err) {
    console.log("get events failed");
  } else {
    console.log("get events success");
  }
});
```

### getEvents

getEvents(eventFilter?: [EventFilter](#eventfilter), eventKey?: (keyof [Event](#event))[]): Promise<[Event](#event)[]>

查询账户下符合条件的日程，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名      | 类型                        | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---------- |
| eventFilter | [EventFilter](#eventfilter) | 否   | 查询条件   |
| eventKey    | (keyof [Event](#event))[]   | 否   | 查询结果集 |

**返回值**：

| 类型                       | 说明               |
| -------------------------- | ------------------ |
| Promise<[Event](#event)[]> | 返回日程实例数组。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
calendar.getEvents(filter).then((data) => {
  console.log("get events success");
}).catch((err) => {
  console.log("get events failed");
});
```

### getConfig

getConfig(): [CalendarConfig](#calendarconfig)

获取账户具体参数。

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                              | 说明               |
| --------------------------------- | ------------------ |
| [CalendarConfig](#calendarconfig) | 返回账户参数实例。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const config = calendar.getConfig();
console.log("get config success");
```

### setConfig

setConfig(config: [CalendarConfig](#calendarconfig), callback: AsyncCallback<void>): void

设置账户参数，使用回调的方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                              | 必填 | 说明             |
| -------- | --------------------------------- | ---- | ---------------- |
| config   | [CalendarConfig](#calendarconfig) | 是   | 账户具体参数实例 |
| callback | AsyncCallback<void>               | 是   | 异步回调。       |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const config: calendarManager.CalendarConfig = {
  enableReminder: true
};
calendar.setConfig(config, (err, data) => {
  if (err) {
    console.log("set config failed");
  } else {
    console.log("set config success");
  }
});
```

### setConfig

setConfig(config:  [CalendarConfig](#calendarconfig)): Promise<void>

设置账户参数，使用Promise方式实现异步调用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型                              | 必填 | 说明             |
| ------ | --------------------------------- | ---- | ---------------- |
| config | [CalendarConfig](#calendarconfig) | 是   | 账户具体参数实例 |

**返回值**：

| 类型          | 说明                  |
| ------------- | --------------------- |
| Promise<void> | Promise类型异步回调。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const config: calendarManager.CalendarConfig = {
  enableReminder: true
};
calendar.setConfig(config).then(() => {
  console.log("set config success");
}).catch((err) => {
  console.log("set config failed");
});
```

### getAccount

getAccount(): [CalendarAccount](#calendaraccount)

获取账户信息。

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                                | 说明               |
| ----------------------------------- | ------------------ |
| [CalendarAccount](#calendaraccount) | 返回账户信息实例。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const account = calendar.getAccount();
console.log("get account success");
```

## CalendarAccount

日历账户。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                          | 只读 | 必填 | 说明           |
| ----------- | ----------------------------- | ---- | ---- | -------------- |
| name        | string                        | 是   | 是   | 账户名称       |
| type        | [CalendarType](#calendartype) | 否   | 是   | 账户类型       |
| displayName | string                        | 否   | 否   | 账户的显示名称 |

## CalendarConfig

账户参数。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称           | 类型          | 只读 | 必填 | 说明         |
| -------------- | ------------- | ---- | ---- | ------------ |
| enableReminder | boolean       | 否   | 否   | 账户提醒能力 |
| color          | ResourceColor | 否   | 否   | 账户颜色     |

## Event

日程实例对象，用于设置日程标题、开始时间、结束时间等具体信息。

**系统能力**：SystemCapability.Notification.ReminderAgent

| 名称           | 类型                              | 只读 | 必填 | 说明           |
| -------------- | --------------------------------- | ---- | ---- | -------------- |
| id             | number                            | 是   | 否   | 日程id         |
| type           | [EventType](#eventtype)           | 否   | 是   | 日程类型       |
| title          | string                            | 否   | 否   | 日程标题       |
| location       | [Location](#location)             | 否   | 否   | 日程地点       |
| startTimer     | number                            | 否   | 是   | 日程开始时间   |
| endTimer       | number                            | 否   | 是   | 日程结束时间   |
| isAllDay       | boolean                           | 否   | 否   | 是否为全天日程 |
| attendee       | [Attendee](#attendee)[]           | 否   | 否   | 日程参与者     |
| timeZone       | string                            | 否   | 否   | 日程时区       |
| reminderTime   | number[]                          | 否   | 否   | 日程提醒时间   |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | 否   | 否   | 日程重复规则   |
| description    | string                            | 否   | 否   | 日程描述       |
| service        | [EventService](#eventservice)     | 否   | 否   | 日程服务       |

## CalendarType

账户类型。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称       | 值         | 说明       |
| ---------- | ---------- | ---------- |
| LOCAL      | local      | 本地账户   |
| EMAIL      | email      | 邮箱账户   |
| BIRTHDAY   | birthday   | 生日账户   |
| CALDAV     | caldav     | CalDAV账户 |
| SUBSCRIBED | subscribed | 订阅账户   |

## Location

日程地点。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 类型    | 只读 | 必填 | 说明     |
| --------- | ------- | ---- | ---- | -------- |
| location  | boolean | 否   | 否   | 地点位置 |
| longitude | number  | 否   | 否   | 地点经度 |
| latitude  | number  | 否   | 否   | 地点纬度 |

## EventFilter

### filterById

filterById(ids: number[]): [EventFilter](#eventfilter)

根据日程id进行过滤

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | 是   | 日程id数组。 |

**返回值**：

| 类型                        | 说明                   |
| --------------------------- | ---------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤实例对象。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const filter = calendarManager.EventFilter.filterById([1, 2]);
calendar.getEvents(filter).then((data) => {
  console.log("filter by id success");
}).catch((err) => {
  console.log("filter by id failed");
});
```

### filterByTime

filterByTime(start: number, end: number):  [EventFilter](#eventfilter)

根据日程时间进行过滤

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| start  | number | 是   | 开始时间。 |
| end    | number | 是   | 结束时间。 |

**返回值**：

| 类型                        | 说明                   |
| --------------------------- | ---------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤实例对象。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const filter = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
calendar.getEvents(filter).then((data) => {
  console.log("filter by time success");
}).catch((err) => {
  console.log("filter by time failed");
});
```

### filterByTitle

filterByTitle(title: string):  [EventFilter](#eventfilter)

根据日程时间进行过滤

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| title  | string | 是   | 日程标题。 |

**返回值**：

| 类型                        | 说明                   |
| --------------------------- | ---------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤实例对象。 |

**示例**：

```javascript
import calendarManager from'@ohos.calendarManager';

const calendar = await calendarManager.getCalendar();
const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
calendar.getEvents(filter).then(() => {
  console.log("filter by title success");
}).catch((err) => {
  console.log("filter by title failed");
});
```

## EventType

日程类型。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 值   | 说明     |
| --------- | ---- | -------- |
| NORMAL    | 0    | 普通日程 |
| IMPORTANT | 1    | 重要日程 |

## RecurrenceRule

日程重复规则。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称                | 类型                                        | 只读 | 必填 | 说明             |
| ------------------- | ------------------------------------------- | ---- | ---- | ---------------- |
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | 否   | 否   | 日程重复规则类型 |
| expire              | number                                      | 否   | 否   | 日程过期时间     |

## RecurrenceFrequency

日程重复规则类型。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称    | 值   | 说明     |
| ------- | ---- | -------- |
| YEARLY  | 0    | 每年重复 |
| MONTHLY | 1    | 每月重复 |
| WEEKLY  | 2    | 每周重复 |
| DAILY   | 3    | 每天重复 |

## Attendee

日程参与者。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称  | 类型   | 只读 | 必填 | 说明         |
| ----- | ------ | ---- | ---- | ------------ |
| name  | string | 否   | 是   | 参与者的姓名 |
| email | string | 否   | 是   | 参与者的邮箱 |

## EventService

日程服务。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                        | 只读 | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---- | ---------- |
| type        | [ServiceType](#servicetype) | 否   | 是   | 服务类型   |
| uri         | string                      | 否   | 是   | 服务的uri  |
| description | string                      | 否   | 否   | 服务的描述 |

## ServiceType

日程服务类型。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称            | 值             | 说明       |
| --------------- | -------------- | ---------- |
| MEETING         | Meeting        | 一键入会   |
| WATCHING        | Watching       | 一键追剧   |
| REPAYMENT       | Repayment      | 一键还款   |
| LIVE            | Live           | 一键直播   |
| SHOPPING        | Shopping       | 一键购物   |
| TRIP            | Trip           | 一键查看   |
| CLASS           | Class          | 一键上课   |
| SPORTS_EVENTS   | SportsEvents   | 一键看赛事 |
| SPORTS_EXERCISE | SportsExercise | 一键运动   |