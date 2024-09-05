# @ohos.calendarManager (Calendar Manager)

The **calendarManager** module provides APIs for calendar and event management, including those for creating, deleting, modifying, and querying calendars and events.

- A [CalendarManager](#calendarmanager) object is used to manage [Calendar](#calendar) objects.

- A [Calendar](#calendar) object contains the account information [CalendarAccount](#calendaraccount) and configuration information [CalendarConfig](#calendarconfig). Calendars and events are in the one-to-many relationship. That is, a calendar can have multiple events, but an event belongs to only one calendar.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```typescript
import { calendarManager } from '@kit.CalendarKit'
```

## calendarManager.getCalendarManager

getCalendarManager(context : Context): CalendarManager

Obtains a **CalendarManager** object based on the context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                                                            |
| -------- | --------------------------- | ---- |----------------------------------------------------------------------------------------------------------------|
| context  | Context                     | Yes  | Application context. For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| CalendarManager | **CalendarManager** object obtained.|

**Example**

```typescript
// Obtain an mContext object.
// Obtain a calendarMgr object.
// The file is auto-generated: entry/src/main/ets/entryability/EntryAbility.ets
import {
  abilityAccessCtrl,
  AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarManager } from '@kit.CalendarKit';
import { window } from '@kit.ArkUI';

export let calendarMgr: calendarManager.CalendarManager | null = null;
export let mContext: common.UIAbilityContext | null = null;
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    console.info("Ability onCreate");
  }

  onDestroy(): void {
    console.info("Ability onDestroy");
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    console.info("Ability onWindowStageCreate");

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
    mContext = this.context;
    const permissions: Permissions[] = ['ohos.permission.READ_CALENDAR', 'ohos.permission.WRITE_CALENDAR'];
    let atManager = abilityAccessCtrl.createAtManager();
    atManager.requestPermissionsFromUser(mContext, permissions).then((result: PermissionRequestResult) => {
      console.log(`get Permission success, result: ${JSON.stringify(result)}`);
      calendarMgr = calendarManager.getCalendarManager(mContext);
    }).catch((error: BusinessError) => {
      console.error(`get Permission error, error. Code: ${error.code}, message: ${error.message}`);
    })
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    console.info("Ability onWindowStageDestroy");
  }

  onForeground(): void {
    // Ability has brought to foreground
    console.info("Ability onForeground");
  }

  onBackground(): void {
    // Ability has back to background
    console.info("Ability onBackground");
  }
}
```

## CalendarManager

Before calling any of the following APIs, you must use [getCalendarManager()](#calendarmanagergetcalendarmanager) to obtain a **CalendarManager** object.


### createCalendar

createCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void

Creates a **Calendar** object based on the calendar account information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                                 | Mandatory| Description                              |
| --------------- | ------------------------------------- | ---- | ---------------------------------- |
| calendarAccount | [CalendarAccount](#calendaraccount)   | Yes  | Calendar account information.                    |
| callback        | AsyncCallback\<[Calendar](#calendar)> | Yes  | Callback used to return the created **Calendar** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar: calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'CreateMyCalendarByCallBack',
  type: calendarManager.CalendarType.LOCAL
};
try {
  calendarMgr?.createCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to create calendar. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating calendar, data -> ${JSON.stringify(data)}`);
      calendar = data;
    }
  });
} catch (error) {
  console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
}
```

### createCalendar

createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar>

Creates a **Calendar** object based on the calendar account information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory| Description          |
| --------------- | ----------------------------------- | ---- | -------------- |
| calendarAccount | [CalendarAccount](#calendaraccount) | Yes  | Calendar account information.|

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the created **Calendar** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'CreateMyCalendarByPromise',
  type: calendarManager.CalendarType.LOCAL,
  displayName : 'MyApplication'
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
  calendar = data;
}).catch((error : BusinessError) => {
  console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
});
```

### deleteCalendar

deleteCalendar(calendar: Calendar, callback: AsyncCallback\<void>): void

Deletes a specified **Calendar** object. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory| Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete.|
| callback | AsyncCallback\<void>  | Yes  | Asynchronous callback that returns no value.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'DeleteMyCalendarByCallBack',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in creating calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
      calendarMgr?.deleteCalendar(data, (err1: BusinessError) => {
        if (err1) {
          console.error(`Failed to delete calendar. Code: ${err1.code}, message: ${err1.message}`);
        } else {
          console.info("Succeeded in deleting calendar");
        }
      });
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
})
```

### deleteCalendar

deleteCalendar(calendar: Calendar): Promise\<void>

Deletes a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory| Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'DeleteMyCalendarByPromise',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in creating calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendarMgr?.deleteCalendar(data).then(() => {
      console.info("Succeeded in deleting calendar");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete calendar. Code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
})
```

### getCalendar

getCalendar(callback: AsyncCallback\<Calendar>): void

Obtains the default **Calendar** object, which is created when the data storage runs for the first time. This API uses an asynchronous callback to return the result. You can call this API instead of [createCalendar()](#createcalendar) to use the default calendar for a new event.

**Required permissions**: ohos.permission.READ_CALENDAR

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                | Mandatory| Description                                |
| -------- | ------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
  }
});
```

### getCalendar

getCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void

Obtains a specified **Calendar** object. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                                | Mandatory| Description                                |
| --------------- | ------------------------------------ | ---- | ------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | Yes  | Calendar account information.                      |
| callback        | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in creating calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting calendar data -> ${JSON.stringify(data)}`);
      calendar = data;
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
})
```

### getCalendar

getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar>

Obtains the default **Calendar** object or a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory| Description                                                        |
| --------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | No  | Calendar account information, which is used to obtain a specified **Calendar** object. If this parameter is not set, the default **Calendar** object is obtained.|

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the obtained **Calendar** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
  calendar = data;
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
});
```

### getAllCalendars

getAllCalendars(callback: AsyncCallback\<Calendar[]>): void

Obtains the created and default **Calendar** objects of the current application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                  | Mandatory| Description                                     |
| -------- | -------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | Yes  | Callback used to return an array of obtained **Calendar** objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

calendarMgr?.getAllCalendars((err: BusinessError, data: calendarManager.Calendar[]) => {
  if (err) {
    console.error(`Failed to get all calendars. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting all calendars, data -> ${JSON.stringify(data)}`);
    data.forEach((calendar) => {
      const account = calendar.getAccount();
      console.info(`account -> ${JSON.stringify(account)}`);
    })
  }
});
```

### getAllCalendars

getAllCalendars(): Promise\<Calendar[]>

Obtains the created and default **Calendar** objects of the current application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Return value**

| Type                            | Description                                       |
| -------------------------------- | ------------------------------------------- |
| Promise<[Calendar](#calendar)[]> | Promise used to return an array of obtained **Calendar** objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

calendarMgr?.getAllCalendars().then((data: calendarManager.Calendar[]) => {
  console.info(`Succeeded in getting all calendars, data -> ${JSON.stringify(data)}`);
  data.forEach((calendar) => {
    const account = calendar.getAccount();
    console.info(`account -> ${JSON.stringify(account)}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get all calendars. Code: ${err.code}, message: ${err.message}`);
});
```

### editEvent<sup>12+</sup>

editEvent(event: Event): Promise\<number>

Creates a single event. If the input parameter **Event** is not set to the event ID, the event creation screen is displayed when this API is called. This API uses a Promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type           | Mandatory| Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object.|

**Return value**

| Type          | Description                    |
| -------------- | ------------------------ |
| Promise\<number> | Promise used to return the event ID.|

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

const date = new Date();
const event: calendarManager.Event = {
  title: 'title',
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.editEvent(event).then((eventId: number): void => {
  console.info(`create Event id = ${eventId}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create Event. Code: ${err.code}, message: ${err.message}`);
});
```

## Calendar

In the following API examples, you need to use [createCalendar()](#createcalendar) or [getCalendar()](#getcalendar) to obtain a **Calendar** object before calling related APIs.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name| Type  | Read-only| Optional| Description    |
| ---- | ------ | ---- |----| -------- |
| id   | number | Yes  | No | Calendar account ID.|

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

Creates an event, with no event ID specified in **Event**. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | [Event](#event)        | Yes  | **Event** object.           |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the event ID.|

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
  calendar = data;
  calendar.addEvent(event, (err: BusinessError, data: number): void => {
    if (err) {
      console.error(`Failed to addEvent. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
});
```

### addEvent

addEvent(event: Event): Promise\<number>

Creates an event, with no event ID specified in **Event**. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to addEvent. Code: ${err.code}, message: ${err.message}`);
    });
  }
});
```

### addEvents

addEvents(events: Event[], callback: AsyncCallback\<void>): void

Creates events in batches, with no event ID specified in **Event**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory| Description           |
| -------- | -------------------- | ---- | --------------- |
| events   | [Event](#event)[]    | Yes  | Array of **Event** objects.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.     |

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
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
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvents(events, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to add events. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info("Succeeded in adding events");
      }
    });
  }
});
```

### addEvents

addEvents(events: Event[]): Promise\<void>

Creates events in batches, with no event ID specified in **Event**. This API uses a promise to return the result.

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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
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
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvents(events).then(() => {
      console.info("Succeeded in adding events");
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id: number = 0;
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.deleteEvent(id, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to delete event. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`Succeeded in deleting event, err -> ${JSON.stringify(err)}`);
      }
    });
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id: number = 0;
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.deleteEvent(id).then(() => {
      console.info("Succeeded in deleting event");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete event. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id1: number = 0;
let id2: number = 0;
const date = new Date();
const event1: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
const event2: calendarManager.Event = {
  type: calendarManager.EventType.IMPORTANT,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.deleteEvents([id1, id2], (err: BusinessError) => {
      if (err) {
        console.error(`Failed to delete events. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info("Succeeded in deleting events");
      }
    });
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id1: number = 0;
let id2: number = 0;
const date = new Date();
const event1: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
const event2: calendarManager.Event = {
  type: calendarManager.EventType.IMPORTANT,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.deleteEvents([id1, id2]).then(() => {
      console.info("Succeeded in deleting events");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete events. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const oriEvent: calendarManager.Event = {
  title: 'update',
  type: calendarManager.EventType.NORMAL,
  description: 'updateEventTest',
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(oriEvent).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      oriEvent.id = data;
      oriEvent.title = 'newUpdate';
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.updateEvent(oriEvent, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to update event. Code: ${err.code}, message: ${err.message}`);
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const oriEvent: calendarManager.Event = {
  title: 'update',
  type: calendarManager.EventType.NORMAL,
  description: 'updateEventTest',
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(oriEvent).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      oriEvent.id = data;
      oriEvent.title = 'newUpdate';
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    calendar.updateEvent(oriEvent).then(() => {
      console.info(`Succeeded in updating event`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to update event. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.getEvents((err: BusinessError, data: calendarManager.Event[]) => {
      if (err) {
        console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
      }
    });
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id1: number = 0;
let id2: number = 0;
const date = new Date();
const event1: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
const event2: calendarManager.Event = {
  type: calendarManager.EventType.IMPORTANT,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    const filter = calendarManager.EventFilter.filterById([id1, id2]);
    calendar.getEvents(filter, ['title', 'type', 'startTime', 'endTime'], (err: BusinessError, data: calendarManager.Event[]) => {
      if (err) {
        console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
      }
    });
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
| Promise<[Event](#event)[]> | Promise used to return the result, which is an array of **Event** objects.|

**Example**

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const event: calendarManager.Event = {
  title: 'MyEvent',
  type: calendarManager.EventType.IMPORTANT,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { calendarMgr } from '../entryability/EntryAbility';
import { BusinessError } from '@kit.BasicServicesKit';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    const config = calendar.getConfig();
    console.info("Succeeded in getting config");
  }
});
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const config: calendarManager.CalendarConfig = {
  enableReminder: true,
  color: '#aabbcc'
};
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.setConfig(config, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.info(`Succeeded in setting config, config -> ${JSON.stringify(config)}`);
      }
    });
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const config: calendarManager.CalendarConfig = {
  enableReminder: true,
  color: '#aabbcc'
};
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.setConfig(config).then(() => {
      console.info(`Succeeded in setting config, data->${JSON.stringify(config)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { calendarMgr } from '../entryability/EntryAbility';
import { BusinessError } from '@kit.BasicServicesKit';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    const account = calendar.getAccount();
    console.info(`succeeded in getting account, account -> ${JSON.stringify(account)}`);
  }
});
```

## CalendarAccount

Describes the calendar account information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                         | Read-only| Optional| Description                                  |
| ----------- | ----------------------------- | ---- |----| -------------------------------------- |
| name        | string                        | Yes  | No | Account name.                            |
| type        | [CalendarType](#calendartype) | No  | No | Account type.                            |
| displayName | string                        | No  | Yes | Display name of the account. If this parameter is not set, an empty string is used.|

## CalendarConfig

Describes the calendar configuration information.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type    | Read-only   | Optional| Description                                                        |
| -------------- |--------|-------|----| ------------------------------------------------------------ |
| enableReminder | boolean | No    | Yes | Whether to enable the reminder for events in the calendar. The value **true** means to enable the reminder for events in the calendar, and **false** means the opposite. The default value is **true**.|
| color          | number \| string | No  | Yes | Calendar color. If this parameter is not set, the default value **'#0A59F7'** is used.               |

## Event

Describes an **Event** object, including the event title, start time, and end time.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type                             | Read-only| Optional| Description                                                                                                                                                                                                     |
| -------------- | --------------------------------- | ---- |----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| id             | number                            | No  | Yes | Event ID. This parameter does not need to be set in the [addEvent()](#addevent) or [addEvents()](#addevents) API.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                           |
| type           | [EventType](#eventtype)           | No  | No | Event type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                           |
| title          | string                            | No  | Yes | Event title. If this parameter is not set, an empty string is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                               |
| location       | [Location](#location)             | No  | Yes | Event location. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                               |
| startTime      | number                            | No  | No | Start time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                  |
| endTime        | number                            | No  | No | End time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                 |
| isAllDay       | boolean                           | No  | Yes | Whether the event is an all-day event. The value **true** means that the event is an all-day event, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                          |
| attendee       | [Attendee](#attendee)[]           | No  | Yes | Event attendee. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                               |
| timeZone       | string                            | No  | Yes | Time zone of the event. If this parameter is not set, the current system time zone is used. You can call the [getTimeZone()](../apis-basic-services-kit/js-apis-date-time.md#systemdatetimegettimezone) API to obtain the current system time zone.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| reminderTime   | number[]                          | No  | Yes | Amount of time that the reminder occurs before the start of the event, in minutes. For example, if the value is 5, the reminder occurs 5 minutes before the event starts. If this parameter is not set, no reminder is set. The value can be negative.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                 |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | No  | Yes | Recurrence rule of the event. If this parameter is not set, the value does not recur.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                              |
| description    | string                            | No  | Yes | Event description. If this parameter is not set, an empty string is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                |
| service        | [EventService](#eventservice)     | No  | Yes | Event service. If this parameter is not set, no service is available.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                              |
| identifier<sup>12+</sup>     | string                            | No  | Yes | A unique ID of an event can be specified. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                        |
| isLunar<sup>12+</sup>     | boolean                            | No  | Yes | Whether it is a lunar calendar event. The value **true** means that the event is a lunar calendar event, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                          |

## CalendarType

Enumerates the account types.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name     | Type  | Read-only| Optional| Description                    |
| --------- | ------ | ---- |----| ------------------------ |
| location  | string | No  | Yes | Location. The default value is an empty string.|
| longitude | number | No  | Yes | Longitude of the location. The default value is **0**.       |
| latitude  | number | No  | Yes | Latitude of the location. The default value is **0**.       |

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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
let id1: number = 0;
let id2: number = 0;
const date = new Date();
const event1: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
const event2: calendarManager.Event = {
  type: calendarManager.EventType.IMPORTANT,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    const filter = calendarManager.EventFilter.filterById([id1, id2]);
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded in getting events filter by id, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by id. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const event1: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: 1686931200000,
  endTime: 1687017600000
};
const event2: calendarManager.Event = {
  type: calendarManager.EventType.IMPORTANT,
  startTime: 1686931200000,
  endTime: 1687017600000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    const filter = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded in getting events filter by time, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by time. Code: ${err.code}, message: ${err.message}`);
    });
  }
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

```typescript
import { BusinessError } from '@kit.BasicServicesKit';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const event: calendarManager.Event = {
  title: 'MyEvent',
  type: calendarManager.EventType.NORMAL,
  startTime: 1686931200000,
  endTime: 1687017600000
};
calendarMgr?.getCalendar(async (err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
    });
    const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded in getting events filter by title, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by title. Code: ${err.code}, message: ${err.message}`);
    });
  }
});
```

## EventType

Enumerates event types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name     | Value  | Description                |
| --------- | ---- | -------------------- |
| NORMAL    | 0    | Normal event.          |
| IMPORTANT | 1    | Important event. This type of event supports countdown.|

## RecurrenceRule

Describes the recurrence rule of the event.

**System capability**: SystemCapability.Applications.CalendarData

| Name               | Type                                       | Read-only| Optional| Description                                                                       |
| ------------------- | ------------------------------------------- | ---- |----|---------------------------------------------------------------------------|
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | No  | No | Type of the event recurrence rule.<br>**Atomic service API**: This API can be used in atomic services since API version 11.          |
| expire              | number                                      | No  | Yes | End date of the recurrence period. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| count<sup>12+</sup>               | number                                      | No  | Yes | Number of times that an event recurs. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| interval<sup>12+</sup>            | number                                      | No  | Yes | Interval for event recurrence. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| excludedDates<sup>12+</sup>       | number[]                                    | No  | Yes | Excluded dates of event recurrence.<br>**Atomic service API**: This API can be used in atomic services since API version 12.          |
## RecurrenceFrequency

Enumerates the types of the event recurrence rule.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name   | Value  | Description      |
| ------- | ---- | ---------- |
| YEARLY  | 0    | Yearly.|
| MONTHLY | 1    | Monthly.|
| WEEKLY  | 2    | Weekly.|
| DAILY   | 3    | Daily.|

## Attendee

Describes the attendee of the event.

**System capability**: SystemCapability.Applications.CalendarData

| Name | Type  | Read-only| Optional| Description                                                                   |
| ----- | ------ | ---- |----|-----------------------------------------------------------------------|
| name  | string | No  | No | Name of the attendee.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| email | string | No  | No | Email address of the attendee.<br>**Atomic service API**: This API can be used in atomic services since API version 11.       |
| role<sup>12+</sup>  | [AttendeeRole](#attendeerole12) | No  | Yes | Participant role.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## EventService

Describes the event service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                       | Read-only| Optional| Description                                 |
| ----------- | --------------------------- | ---- |----| ------------------------------------- |
| type        | [ServiceType](#servicetype) | No  | No | Service type.                           |
| uri         | string                      | No  | No | URI of the service. It can be used to redirect the user to a page of another application.|
| description | string                      | No  | Yes | Description of the service. If this parameter is not set, an empty string is used. |

## ServiceType

Enumerates the event service types.

**Atomic service API**: This API can be used in atomic services since API version 11.

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

## AttendeeRole<sup>12+</sup>

Enumerates the participant role types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Value            | Description    |
|--------------|---------------|--------|
| ORGANIZER<sup>12+</sup>    | 'organizer'   | Conference organizer.|
| PARTICIPANT<sup>12+</sup>  | 'participant' | Conference participant.|
