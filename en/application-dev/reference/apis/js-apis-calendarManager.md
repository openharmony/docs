# @ohos.calendarManager (Calendar Manager)

The **calendarManager** module provides APIs for calendar and event management, including those for creating, deleting, modifying, and querying calendars and events. A [CalendarManager](#calendarmanager) object is used to manage [Calendar](#calendar) objects. A [Calendar](#calendar) object contains the account information [CalendarAccount](#calendaraccount) and configuration information [CalendarConfig](#calendarconfig). Calendars and events are in the one-to-many relationship. That is, a calendar can have multiple events, but an event belongs to only one calendar.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import calendarManager from '@ohos.calendarManager';
```

## calendarManager.getCalendarManager

getCalendarManager(context : Context): CalendarManager

Obtains a **CalendarManager** object based on the context.

**System capability**: SystemCapability.Applications.CalendarData

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | Yes  | Application context. For details about the application context of the stage model, see [Context](js-apis-inner-application-context.md).|

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| CalendarManager | **CalendarManager** object obtained.|

**Example**

```ts
  // Obtain the context.
  // Obtain a calendarManager object.
  // In the following code, class EntryAbility extends UIAbility and onWindowStageCreate are available in main/ets/entryability/EntryAbility.ets and ohosTest/ets/testability/TestAbility.ets files and can be directly used.
  // calendarMgr must be obtained in the main thread, not in the worker thread.
  import UIAbility from '@ohos.app.ability.UIAbility';
  import common from '@ohos.app.ability.common';
  import window from '@ohos.window';

  export let mContext : common.UIAbilityContext | null = null;
  export let calendarMgr : calendarManager.CalendarManager | null = null;
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage){
      mContext = this.context;
    }
    calendarMgr = calendarManager.getCalendarManager(mContext);
  }
   
```

## CalendarManager

Before calling any of the following APIs, you must use [getCalendarManager()](#calendarmanagergetcalendarmanager) to obtain a **CalendarManager** object.


### createCalendar

createCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void

Creates a **Calendar** object based on the calendar account information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                                 | Mandatory| Description                              |
| --------------- | ------------------------------------- | ---- | ---------------------------------- |
| calendarAccount | [CalendarAccount](#calendaraccount)   | Yes  | Calendar account information.                    |
| callback        | AsyncCallback\<[Calendar](#calendar)> | Yes  | Callback used to return the created **Calendar** object.|

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

let calendar: calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
try {
  calendarMgr.createCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to create calendar: err->${JSON.stringify(err)}`);
    } else {
      console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
      calendar = data;
    }
  });
} catch (error) {
  console.error(`Failed to create calendar: err->${JSON.stringify(error)}`);
}
```

### createCalendar

createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar>

Creates a **Calendar** object based on the calendar account information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory| Description          |
| --------------- | ----------------------------------- | ---- | -------------- |
| calendarAccount | [CalendarAccount](#calendaraccount) | Yes  | Calendar account information.|

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the created **Calendar** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL,
  displayName : 'MyApplication'
};
calendarMgr.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
  calendar = data;
}).catch((error : BusinessError) => {
  console.error(`Failed to create calendar: err->${JSON.stringify(error)}`);
});
```

### deleteCalendar

deleteCalendar(calendar: Calendar, callback: AsyncCallback\<void>): void

Deletes a specified **Calendar** object. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory| Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete.|
| callback | AsyncCallback\<void>  | Yes  | Asynchronous callback that returns no value.    |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info("Succeeded in getting calendar");
    calendarMgr.deleteCalendar(data, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to delete calendar: err->${JSON.stringify(err)}`);
      } else {
        console.info("Succeeded in deleting calendar");
      }
    });
  }
});
```

### deleteCalendar

deleteCalendar(calendar: Calendar): Promise\<void>

Deletes a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory| Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info("Succeeded in getting calendar");
  calendarMgr.deleteCalendar(data).then(() => {
    console.info("Succeeded in deleting calendar");
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete calendar: err->${JSON.stringify(err)}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
});
```

### getCalendar

getCalendar(callback: AsyncCallback\<Calendar>): void

Obtains the default **Calendar** object, which is created when the data storage runs for the first time. This API uses an asynchronous callback to return the result. You can call this API instead of [createCalendar()](#createcalendar) to use the default calendar for a new event.

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                | Mandatory| Description                                |
| -------- | ------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
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

Obtains a specified **Calendar** object. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                                | Mandatory| Description                                |
| --------------- | ------------------------------------ | ---- | ------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | Yes  | Calendar account information.                      |
| callback        | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
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

Obtains the default **Calendar** object or a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory| Description                                                        |
| --------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | No  | Calendar account information, which is used to obtain a specified **Calendar** object. If this parameter is not set, the default **Calendar** object is obtained.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the obtained **Calendar** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
  calendar = data;
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
});
```

### getAllCalendars

getAllCalendars(callback: AsyncCallback\<Calendar[]>): void

Obtains the created and default **Calendar** objects of the current application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                  | Mandatory| Description                                     |
| -------- | -------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | Yes  | Callback used to return an array of obtained **Calendar** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

calendarMgr.getAllCalendars((err: BusinessError, data: calendarManager.Calendar[]) => {
  if (err) {
    console.error(`Failed to get all calendars: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting all calendars->${JSON.stringify(data)}`);
    data.forEach((calendar) => {
      const account = calendar.getAccount();
      console.info(`account->${JSON.stringify(account)}`);
    })
  }
});
```

### getAllCalendars

getAllCalendars(): Promise\<Calendar[]>

Obtains the created and default **Calendar** objects of the current application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Return value**

| Type                            | Description                                       |
| -------------------------------- | ------------------------------------------- |
| Promise<[Calendar](#calendar)[]> | Promise used to return an array of obtained **Calendar** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import {calendarMgr} from '../testability/TestAbility'; // The path is applicable to the test module.

calendarMgr.getAllCalendars().then((data: calendarManager.Calendar[]) => {
  console.info(`Succeeded in getting all calendars->${JSON.stringify(data)}`);
  data.forEach((calendar) => {
    const account = calendar.getAccount();
    console.info(`account->${JSON.stringify(account)}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get all calendars: err->${JSON.stringify(err)}`);
});
```

## Calendar

In the following API examples, you need to use [createCalendar()](#createcalendar) or [getCalendar()](#getcalendar) to obtain a **Calendar** object before calling related APIs.

### Attributes

**System capability**: SystemCapability.Applications.CalendarData

| Name| Type  | Read-only| Mandatory| Description    |
| ---- | ------ | ---- | ---- | -------- |
| id   | number | Yes  | Yes  | Calendar account ID.|

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

Creates an event, with no event ID specified in [Event](#event). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | [Event](#event)        | Yes  | **Event** object.           |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the event ID.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

Creates an event, with no event ID specified in [Event](#event). This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type           | Mandatory| Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<number> | Promise used to return the event ID.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### addEvents

addEvents(events: Event[], callback: AsyncCallback\<void>): void

Creates a batch of events, with no event ID specified in [Event](#event). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory| Description           |
| -------- | -------------------- | ---- | --------------- |
| events   | [Event](#event)[]    | Yes  | Array of **Event** objects.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.     |

**Example**

```ts
import { BusinessError } from '@ohos.base';

const date = new Date();
const events: calendarManager.Event[] = [
  {
    type: calendarManager.EventType.NORMAL,
    startTime: date.getTime(),
    endTime: date.getTime() + 60 * 60 * 1000
  },
  {
    type: calendarManager.EventType.NORMAL,
    startTime: date.getTime(),
    endTime: date.getTime() + 60 * 60 * 1000
  }
];
calendar.addEvents(events, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to addEvent: err->${JSON.stringify(err)}`);
  } else {
    console.info("Succeeded in adding events");
  }
});
```

### addEvents

addEvents(events: Event[]): Promise\<void>

Creates a batch of events, with no event ID specified in [Event](#event). This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type             | Mandatory| Description           |
| ------ | ----------------- | ---- | --------------- |
| events | [Event](#event)[] | Yes  | Array of **Event** objects.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const date = new Date();
const events: calendarManager.Event[] = [
  {
    type: calendarManager.EventType.NORMAL,
    startTime: date.getTime(),
    endTime: date.getTime() + 60 * 60 * 1000
  },
  {
    type: calendarManager.EventType.NORMAL,
    startTime: date.getTime(),
    endTime: date.getTime() + 60 * 60 * 1000
  }
];
calendar.addEvents(events).then(() => {
  console.info("Succeeded in adding events");
}).catch((err: BusinessError) => {
  console.error(`Failed to addEvent: err->${JSON.stringify(err)}`);
});
```

### deleteEvent

deleteEvent(id: number, callback: AsyncCallback\<void>): void

Deletes an event with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| id       | number               | Yes  | Event ID.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

calendar.deleteEvent(1, (err: BusinessError) => {
  if (err) {
    console.error("Failed to delete event");
  } else {
    console.info("Succeeded in deleting event");
  }
});
```

### deleteEvent

deleteEvent(id: number): Promise\<void>

Deletes an event with the specified ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| id     | number | Yes  | Event ID.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

calendar.deleteEvent(1).then(() => {
  console.info("Succeeded in deleting event");
}).catch((err: BusinessError) => {
  console.error("Failed to delete event");
});
```

### deleteEvents

deleteEvents(ids: number[], callback: AsyncCallback\<void>): void

Deletes a batch of events with the specified IDs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory| Description        |
| -------- | -------------------- | ---- | ------------ |
| ids      | number[]             | Yes  | Array of event IDs.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

calendar.deleteEvents([1, 2], (err: BusinessError) => {
  if (err) {
    console.error("Failed to delete events");
  } else {
    console.info("Succeeded in deleting events");
  }
});
```

### deleteEvents

deleteEvents(ids: number[]): Promise\<void>

Deletes a batch of events with the specified IDs. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | Yes  | Array of event IDs.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

calendar.deleteEvents([1, 2]).then(() => {
  console.info("Succeeded in deleting events");
}).catch((err: BusinessError) => {
  console.error("Failed to delete events");
});
```

### updateEvent

updateEvent(event: Event, callback: AsyncCallback\<void>): void

Updates an event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory| Description       |
| -------- | -------------------- | ---- | ----------- |
| event    | [Event](#event)      | Yes  | **Event** object.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

const date = new Date();
const oriEvent: calendarManager.Event = {
  title: 'update',
  type: calendarManager.EventType.NORMAL,
  description: 'updateEventTest',
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendar.addEvent(oriEvent, (err: BusinessError, data: number): void => {
  if (err) {
    console.error(`Failed to addEvent: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in adding event id:${data}`);
    oriEvent.id = data; // must set id
    oriEvent.title = 'newUpdate';
    calendar.updateEvent(oriEvent, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to updateEvent: err->${JSON.stringify(err)}`);
      } else {
        console.info("Succeeded in updating event");
      }
    });
  }
});
```

### updateEvent

updateEvent(event: Event): Promise\<void>

Updates an event. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type           | Mandatory| Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterByTitle('update');
calendar.getEvents(filter).then((events : calendarManager.Event[]) => {
  console.info(`Succeeded in getEvents`);
  if (events.length < 1) {
    return;
  }
  let newEvent = events[0];
  newEvent.title = 'newUpdate';
  calendar.updateEvent(newEvent).then(() => {
    console.info(`Succeeded in updateEvent`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to updateEvent err->${JSON.stringify(err)}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to getEvents err->${JSON.stringify(err)}`);
});
```

### getEvents

getEvents(callback: AsyncCallback\<Event[]>): void

Obtains all events in a calendar. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                            | Mandatory| Description                             |
| -------- | -------------------------------- | ---- | --------------------------------- |
| callback | AsyncCallback<[Event](#event)[]> | Yes  | Callback used to return an array of events.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

calendar.getEvents((err: BusinessError, data: calendarManager.Event[]) => {
  if (err) {
    console.error("Failed to get events");
  } else {
    console.info("Succeeded in getting events");
  }
});
```

### getEvents

getEvents(eventFilter: EventFilter, eventKey: (keyof Event)[], callback: AsyncCallback\<Event[]>):void

Obtains all events in a calendar that match the filter criteria. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name     | Type                            | Mandatory| Description                             |
| ----------- | -------------------------------- | ---- | --------------------------------- |
| eventFilter | [EventFilter](#eventfilter)      | Yes  | Filter criteria.                       |
| eventKey    | (keyof [Event](#event))[]        | Yes  | Filter field.                       |
| callback    | AsyncCallback<[Event](#event)[]> | Yes  | Callback used to return an array of events.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterById([1, 2]);
calendar.getEvents(filter, ['title', 'type', 'startTime', 'endTime'], (err: BusinessError, data: calendarManager.Event[]) => {
  if (err) {
    console.error("Failed to get events");
  } else {
    console.info("Succeeded in getting events");
  }
});
```

### getEvents

getEvents(eventFilter?: EventFilter, eventKey?: (keyof Event)[]): Promise\<Event[]>

Obtains all events in a calendar that match the filter criteria. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name     | Type                       | Mandatory| Description      |
| ----------- | --------------------------- | ---- | ---------- |
| eventFilter | [EventFilter](#eventfilter) | No  | Filter criteria.|
| eventKey    | (keyof [Event](#event))[]   | No  | Filter field.|

**Return value**

| Type                      | Description                               |
| -------------------------- | ----------------------------------- |
| Promise<[Event](#event)[]> | Promise used to return an array of events.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
  console.info("Succeeded in getting events");
}).catch((err: BusinessError) => {
  console.error("Failed to get events");
});
```

### getConfig

getConfig(): CalendarConfig

Obtains the calendar configuration information.

**System capability**: SystemCapability.Applications.CalendarData

**Return value**

| Type                             | Description          |
| --------------------------------- | -------------- |
| [CalendarConfig](#calendarconfig) | Calendar configuration information.|

**Example**

```ts
const config = calendar.getConfig();
console.info("get config success");
```

### setConfig

setConfig(config: CalendarConfig, callback: AsyncCallback\<void>): void

Sets the calendar configuration information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                             | Mandatory| Description          |
| -------- | --------------------------------- | ---- | -------------- |
| config   | [CalendarConfig](#calendarconfig) | Yes  | Calendar configuration information.|
| callback | AsyncCallback\<void>              | Yes  | Callback used to return the result.    |

**Example**

```ts
import { BusinessError } from '@ohos.base';

const config: calendarManager.CalendarConfig = {
  enableReminder: true
};
calendar.setConfig(config, (err: BusinessError) => {
  if (err) {
    console.error("Failed to set config");
  } else {
    console.info("Succeeded in setting config");
  }
});
```

### setConfig

setConfig(config: CalendarConfig): Promise\<void>

Sets the calendar configuration information. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type                             | Mandatory| Description          |
| ------ | --------------------------------- | ---- | -------------- |
| config | [CalendarConfig](#calendarconfig) | Yes  | Calendar configuration information.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const config: calendarManager.CalendarConfig = {
  enableReminder: true,
  color: '#aabbcc'
};
calendar.setConfig(config).then(() => {
  console.info("Succeeded in setting config");
}).catch((err: BusinessError) => {
  console.error("Failed to set config");
});
```

### getAccount

getAccount(): CalendarAccount

Obtains the calendar account information.

**System capability**: SystemCapability.Applications.CalendarData

**Return value**

| Type                               | Description          |
| ----------------------------------- | -------------- |
| [CalendarAccount](#calendaraccount) | Calendar account information.|

**Example**

```ts
const account = calendar.getAccount();
console.info("get account success");
```

## CalendarAccount

Describes the calendar account information.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                         | Read-only| Mandatory| Description                                  |
| ----------- | ----------------------------- | ---- | ---- | -------------------------------------- |
| name        | string                        | Yes  | Yes  | Account name.                            |
| type        | [CalendarType](#calendartype) | No  | Yes  | Account type.                            |
| displayName | string                        | No  | No  | Display name of the account. If this parameter is not set, an empty string is used.|

## CalendarConfig

Describes the calendar configuration information.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type                                               | Read-only| Mandatory| Description                                                        |
| -------------- | --------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| enableReminder | boolean                                             | No  | No  | Whether to enable the reminder for events in the calendar. The value **true** means to enable the reminder for events in the calendar, and **false** means the opposite. The default value is **true**.|
| color          | string/number | No  | No  | Calendar color. If this parameter is not set, the default value **'#0A59F7'** is used.               |

## Event

Describes an **Event** object, including the event title, start time, and end time.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type                             | Read-only| Mandatory| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| id             | number                            | Yes  | No  | Event ID. This parameter does not need to be set in the [addEvent()](#addevent) or [addEvents()](#addevents) API.|
| type           | [EventType](#eventtype)           | No  | Yes  | Event type.                                                  |
| title          | string                            | No  | No  | Event title. If this parameter is not set, an empty string is used.                            |
| location       | [Location](#location)             | No  | No  | Event location. If this parameter is not set, the default null value is used.                              |
| startTime      | number                            | No  | Yes  | Start time of the event.                                              |
| endTime        | number                            | No  | Yes  | End time of the event.                                              |
| isAllDay       | boolean                           | No  | No  | Whether the event is an all-day event. The value **true** means that the event is an all-day event, and **false** means the opposite. The default value is **false**.|
| attendee       | [Attendee](#attendee)[]           | No  | No  | Event attendee. If this parameter is not set, the default null value is used.                            |
| timeZone       | string                            | No  | No  | Time zone of the event. If this parameter is not set, the current system time zone is used. You can call the [getTimeZone()](js-apis-system-date-time.md#systemdatetimegettimezone) API to obtain the current system time zone.|
| reminderTime   | number[]                          | No  | No  | Event reminder time. If this parameter is not set, no reminder is set.                          |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | No  | No  | Recurrence rule of the event. If this parameter is not set, the value does not recur.                          |
| description    | string                            | No  | No  | Event description. If this parameter is not set, an empty string is used.                            |
| service        | [EventService](#eventservice)     | No  | No  | Event service. If this parameter is not set, no service is available.                          |

## CalendarType

Enumerates the account types.

**System capability**: SystemCapability.Applications.CalendarData

| Name      | Value          | Description                |
| ---------- | ------------ | -------------------- |
| LOCAL      | 'local'      | Local account.          |
| EMAIL      | 'email'      | Email account.          |
| BIRTHDAY   | 'birthday'   | Birthday account.          |
| CALDAV     | 'caldav'     | CalDAV account.|
| SUBSCRIBED | 'subscribed' | Subscription account.          |

## Location

Describes the event location.

**System capability**: SystemCapability.Applications.CalendarData

| Name     | Type  | Read-only| Mandatory| Description                    |
| --------- | ------ | ---- | ---- | ------------------------ |
| location  | string | No  | No  | Location. The default value is an empty string.|
| longitude | number | No  | No  | Longitude of the location. The default value is **0**.       |
| latitude  | number | No  | No  | Latitude of the location. The default value is **0**.       |

## EventFilter

Implements an event filter.

You can use [filterById()](#filterbyid), [filterByTime()](#filterbytime), or [filterByTitle()](#filterbytitle) to obtain an event filter, and then pass the filter in [getEvents()](#getevents) for filtering.

### filterById

static filterById(ids: number[]): EventFilter

Defines an event ID based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | Yes  | Array of event IDs.|

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterById([1, 2]);
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
  console.info("Succeeded in filtering by id");
}).catch((err: BusinessError) => {
  console.error("Failed to filter by id");
});
```

### filterByTime

static filterByTime(start: number, end: number): EventFilter

Defines an event time based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| start  | number | Yes  | Start time.|
| end    | number | Yes  | End time.|

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
  console.info("Succeeded in filtering by time");
}).catch((err: BusinessError) => {
  console.error("Failed to filter by time");
});
```

### filterByTitle

static filterByTitle(title: string): EventFilter

Defines an event title based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| title  | string | Yes  | Event title.|

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
  console.info("Succeeded in filtering by title");
}).catch((err: BusinessError) => {
  console.error("Failed to filter by title");
});
```

## EventType

Enumerates event types.

**System capability**: SystemCapability.Applications.CalendarData

| Name     | Value  | Description                |
| --------- | ---- | -------------------- |
| NORMAL    | 0    | Normal event.          |
| IMPORTANT | 1    | Important event. This type of event supports countdown.|

## RecurrenceRule

Describes the event recurrence rule.

**System capability**: SystemCapability.Applications.CalendarData

| Name               | Type                                       | Read-only| Mandatory| Description                           |
| ------------------- | ------------------------------------------- | ---- | ---- | ------------------------------- |
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | No  | Yes  | Type of the event recurrence rule.             |
| expire              | number                                      | No  | No  | End date of the recurrence period. If this parameter is not set, the default value **0** is used.|

## RecurrenceFrequency

Enumerates the types of the event recurrence rule.

**System capability**: SystemCapability.Applications.CalendarData

| Name   | Value  | Description      |
| ------- | ---- | ---------- |
| YEARLY  | 0    | Yearly.|
| MONTHLY | 1    | Monthly.|
| WEEKLY  | 2    | Weekly.|
| DAILY   | 3    | Daily.|

## Attendee

Describes the event attendee.

**System capability**: SystemCapability.Applications.CalendarData

| Name | Type  | Read-only| Mandatory| Description          |
| ----- | ------ | ---- | ---- | -------------- |
| name  | string | No  | Yes  | Name of the attendee.|
| email | string | No  | Yes  | Email address of the attendee.|

## EventService

Describes the event service.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                       | Read-only| Mandatory| Description                                 |
| ----------- | --------------------------- | ---- | ---- | ------------------------------------- |
| type        | [ServiceType](#servicetype) | No  | Yes  | Service type.                           |
| uri         | string                      | No  | Yes  | URI of the service. It can be used to redirect the user to a page of another application.|
| description | string                      | No  | No  | Description of the service. If this parameter is not set, an empty string is used. |

## ServiceType

Enumerates the event service types.

**System capability**: SystemCapability.Applications.CalendarData

| Name           | Value              | Description        |
| --------------- | ---------------- | ------------ |
| MEETING         | 'Meeting'        | Join a meeting.  |
| WATCHING        | 'Watching'       | Watch a video.  |
| REPAYMENT       | 'Repayment'      | Make a payment.  |
| LIVE            | 'Live'           | Watch live TV.  |
| SHOPPING        | 'Shopping'       | Go shopping.  |
| TRIP            | 'Trip'           | View the trip.  |
| CLASS           | 'Class'          | Join class.  |
| SPORTS_EVENTS   | 'SportsEvents'   | Watch a sports event.|
| SPORTS_EXERCISE | 'SportsExercise' | Start exercising.  |
