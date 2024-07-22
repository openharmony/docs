# @ohos.calendarManager (Calendar Manager)

The **calendarManager** module provides APIs for calendar and event management, including those for creating, deleting, modifying, and querying calendars and events.

- A [CalendarManager](#calendarmanager) object is used to manage [Calendar](#calendar) objects.

- A [Calendar](#calendar) object contains the account information [CalendarAccount](#calendaraccount) and configuration information [CalendarConfig](#calendarconfig). Calendars and events are in the one-to-many relationship. That is, a calendar can have multiple events, but an event belongs to only one calendar.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```typescript
import calendarManager from '@ohos.calendarManager';
```

## calendarManager.getCalendarManager

getCalendarManager(context : Context): CalendarManager

Obtains a **CalendarManager** object based on the context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                       | Mandatory | Description                                                                                                            |
| -------- | --------------------------- | ---- |----------------------------------------------------------------------------------------------------------------|
| context  | Context                     | Yes  | Application context. For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md). |

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| CalendarManager | **CalendarManager** object obtained. |

**Example**

```typescript
// Obtain an mContext object.
// Obtain a calendarMgr object.
// The file is auto-generated: entry/src/main/ets/entryability/EntryAbility.ets
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import common from '@ohos.app.ability.common';
import abilityAccessCtrl, { PermissionRequestResult, Permissions } from '@ohos.abilityAccessCtrl';
import { BusinessError } from '@ohos.base';

export let calendarMgr: calendarManager.CalendarManager | null = null;
export let mContext: common.UIAbilityContext | null = null;
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
    mContext = this.context;
    const permissions: Permissions[] = ['ohos.permission.READ_CALENDAR', 'ohos.permission.WRITE_CALENDAR'];
    let atManager = abilityAccessCtrl.createAtManager();
    atManager.requestPermissionsFromUser(mContext, permissions).then((result: PermissionRequestResult) => {
      console.log(`get Permission success, result: ${JSON.stringify(result)}`);
      calendarMgr = calendarManager.getCalendarManager(mContext);
    }).catch((error: BusinessError) => {
      console.error(`get Permission error, error: ${JSON.stringify(error)}`);
    })
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
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

| Name         | Type                                 | Mandatory | Description                              |
| --------------- | ------------------------------------- | ---- | ---------------------------------- |
| calendarAccount | [CalendarAccount](#calendaraccount)   | Yes  | Calendar account information.                    |
| callback        | AsyncCallback\<[Calendar](#calendar)> | Yes  | Callback used to return the created **Calendar** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar: calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'CreateMyCalendarByCallBack',
  type: calendarManager.CalendarType.LOCAL
};
try {
  calendarMgr?.createCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to create calendar, err -> ${JSON.stringify(err)}`);
    } else {
      console.info(`Succeeded to create calendar, data -> ${JSON.stringify(data)}`);
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

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory | Description          |
| --------------- | ----------------------------------- | ---- | -------------- |
| calendarAccount | [CalendarAccount](#calendaraccount) | Yes  | Calendar account information. |

**Return value**

| Type                          | Description                                 |
| ------------------------------ | ------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the created **Calendar** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'CreateMyCalendarByPromise',
  type: calendarManager.CalendarType.LOCAL,
  displayName : 'MyApplication'
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to create calendar data->${JSON.stringify(data)}`);
  calendar = data;
}).catch((error : BusinessError) => {
  console.error(`Failed to create calendar: err->${JSON.stringify(error)}`);
});
```

### deleteCalendar

deleteCalendar(calendar: Calendar, callback: AsyncCallback\<void>): void

Deletes a specified **Calendar** object. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory | Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete. |
| callback | AsyncCallback\<void>  | Yes  | Asynchronous callback that returns no value.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'DeleteMyCalendarByCallBack',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to create calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
    } else {
      console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
      calendarMgr?.deleteCalendar(data, (err1: BusinessError) => {
        if (err1) {
          console.error(`Failed to delete calendar, err -> ${JSON.stringify(err1)}`);
        } else {
          console.info("Succeeded to delete calendar");
        }
      });
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar, error -> ${JSON.stringify(error)}`);
})
```

### deleteCalendar

deleteCalendar(calendar: Calendar): Promise\<void>

Deletes a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                 | Mandatory | Description          |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | Yes  | **Calendar** object to delete. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

const calendarAccount: calendarManager.CalendarAccount = {
  name: 'DeleteMyCalendarByPromise',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to create calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendarMgr?.deleteCalendar(data).then(() => {
      console.info("Succeeded to delete calendar");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete calendar: err -> ${JSON.stringify(err)}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to get calendar: err -> ${JSON.stringify(err)}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar, error -> ${JSON.stringify(error)}`);
})
```

### getCalendar

getCalendar(callback: AsyncCallback\<Calendar>): void

Obtains the default **Calendar** object, which is created when the data storage runs for the first time. This API uses an asynchronous callback to return the result. You can call this API instead of [createCalendar()](#createcalendar) to use the default calendar for a new event.

**Required permissions**: ohos.permission.READ_CALENDAR

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                | Mandatory | Description                                |
| -------- | ------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
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

| Name         | Type                                | Mandatory | Description                                |
| --------------- | ------------------------------------ | ---- | ------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | Yes  | Calendar account information.                      |
| callback        | AsyncCallback<[Calendar](#calendar)> | Yes  | Callback used to return the obtained **Calendar** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const calendarAccount: calendarManager.CalendarAccount = {
  name: 'MyCalendar',
  type: calendarManager.CalendarType.LOCAL
};
calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to create calendar, data -> ${JSON.stringify(data)}`);
  calendarMgr?.getCalendar(calendarAccount, (err: BusinessError, data: calendarManager.Calendar) => {
    if (err) {
      console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
    } else {
      console.info(`Succeeded to get calendar data -> ${JSON.stringify(data)}`);
      calendar = data;
    }
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create calendar, error -> ${JSON.stringify(error)}`);
})
```

### getCalendar

getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar>

Obtains the default **Calendar** object or a specified **Calendar** object. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name         | Type                               | Mandatory | Description                                                        |
| --------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | No  | Calendar account information, which is used to obtain a specified **Calendar** object. If this parameter is not set, the default **Calendar** object is obtained. |

**Return value**

| Type                          | Description                                   |
| ------------------------------ | --------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise used to return the obtained **Calendar** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
  calendar = data;
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
});
```

### getAllCalendars

getAllCalendars(callback: AsyncCallback\<Calendar[]>): void

Obtains the created and default **Calendar** objects of the current application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                  | Mandatory | Description                                     |
| -------- | -------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | Yes  | Callback used to return an array of obtained **Calendar** objects. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

calendarMgr?.getAllCalendars((err: BusinessError, data: calendarManager.Calendar[]) => {
  if (err) {
    console.error(`Failed to get all calendars, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get all calendars, data -> ${JSON.stringify(data)}`);
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
| Promise<[Calendar](#calendar)[]> | Promise used to return an array of obtained **Calendar** objects. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                       |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

calendarMgr?.getAllCalendars().then((data: calendarManager.Calendar[]) => {
  console.info(`Succeeded to get all calendars, data -> ${JSON.stringify(data)}`);
  data.forEach((calendar) => {
    const account = calendar.getAccount();
    console.info(`account -> ${JSON.stringify(account)}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get all calendars, err -> ${JSON.stringify(err)}`);
});
```

### editEvent<sup>12+</sup>

editEvent(event: Event): Promise\<number>

Creates a single event. If the input parameter **Event** is not set to the event ID, the event creation screen is displayed when this API is called. This API, not supported currently, uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name | Type           | Mandatory | Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object. |

**Return value**

| Type          | Description                    |
| -------------- | ------------------------ |
| Promise\<number> | Promise used to return the event ID. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
  console.error(`Failed to create Event, err -> ${JSON.stringify(err)}`);
});
```

## Calendar

In the following API examples, you need to use [createCalendar()](#createcalendar) or [getCalendar()](#getcalendar) to obtain a **Calendar** object before calling related APIs.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name | Type  | Read-only | Mandatory | Description    |
| ---- | ------ | ---- | ---- | -------- |
| id   | number | Yes  | Yes  | Calendar account ID. |

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

Creates an event, with no event ID specified in **Event**. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                  | Mandatory | Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | [Event](#event)        | Yes  | **Event** object.           |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the event ID. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const date = new Date();
const event: calendarManager.Event = {
  type: calendarManager.EventType.NORMAL,
  startTime: date.getTime(),
  endTime: date.getTime() + 60 * 60 * 1000
};
calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
  console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
  calendar = data;
  calendar.addEvent(event, (err: BusinessError, data: number): void => {
    if (err) {
      console.error(`Failed to addEvent, err -> ${JSON.stringify(err)}`);
    } else {
      console.info(`Succeeded to add event, id -> ${data}`);
    }
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
});
```

### addEvent

addEvent(event: Event): Promise\<number>

Creates an event, with no event ID specified in **Event**. This API uses an asynchronous promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name | Type           | Mandatory | Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object. |

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<number> | Promise used to return the event ID. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to addEvent, err -> ${JSON.stringify(err)}`);
    });
  }
});
```

### addEvents

addEvents(events: Event[], callback: AsyncCallback\<void>): void

Creates events in batches, with no event ID specified in **Event**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory | Description           |
| -------- | -------------------- | ---- | --------------- |
| events   | [Event](#event)[]    | Yes  | Array of **Event** objects. |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.     |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvents(events, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to add events, err -> ${JSON.stringify(err)}`);
      } else {
        console.info("Succeeded to add events");
      }
    });
  }
});
```

### addEvents

addEvents(events: Event[]): Promise\<void>

Creates events in batches, with no event ID specified in **Event**. This API uses an asynchronous promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name | Type             | Mandatory | Description           |
| ------ | ----------------- | ---- | --------------- |
| events | [Event](#event)[] | Yes  | Array of **Event** objects. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar: err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.addEvents(events).then(() => {
      console.info("Succeeded to add events");
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
  }
});
```

### deleteEvent

deleteEvent(id: number, callback: AsyncCallback\<void>): void

Deletes an event with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory | Description      |
| -------- | -------------------- | ---- | ---------- |
| id       | number               | Yes  | Event ID.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.deleteEvent(id, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to delete event, err -> ${JSON.stringify(err)}`);
      } else {
        console.info(`Succeeded to delete event, err -> ${JSON.stringify(err)}`);
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

| Name | Type  | Mandatory | Description    |
| ------ | ------ | ---- | -------- |
| id     | number | Yes  | Event ID. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.deleteEvent(id).then(() => {
      console.info("Succeeded to delete event");
    }).catch((err: BusinessError) => {
      console.error("Failed to delete event");
    });
  }
});
```

### deleteEvents

deleteEvents(ids: number[], callback: AsyncCallback\<void>): void

Deletes a batch of events with the specified IDs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory | Description        |
| -------- | -------------------- | ---- | ------------ |
| ids      | number[]             | Yes  | Array of event IDs. |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.  |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.deleteEvents([id1, id2], (err: BusinessError) => {
      if (err) {
        console.error("Failed to delete events");
      } else {
        console.info("Succeeded to delete events");
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

| Name | Type    | Mandatory | Description        |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | Yes  | Array of event IDs. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.deleteEvents([id1, id2]).then(() => {
      console.info("Succeeded to delete events");
    }).catch((err: BusinessError) => {
      console.error("Failed to delete events");
    });
  }
});
```

### updateEvent

updateEvent(event: Event, callback: AsyncCallback\<void>): void

Updates an event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                | Mandatory | Description       |
| -------- | -------------------- | ---- | ----------- |
| event    | [Event](#event)      | Yes  | **Event** object. |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(oriEvent).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      oriEvent.id = data;
      oriEvent.title = 'newUpdate';
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.updateEvent(oriEvent, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to update event, err -> ${JSON.stringify(err)}`);
      } else {
        console.info("Succeeded to update event");
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

| Name | Type           | Mandatory | Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(oriEvent).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      oriEvent.id = data;
      oriEvent.title = 'newUpdate';
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    calendar.updateEvent(oriEvent).then(() => {
      console.info(`Succeeded to update event`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to update event, err -> ${JSON.stringify(err)}`);
    });
  }
});
```

### getEvents

getEvents(callback: AsyncCallback\<Event[]>): void

Obtains all events in a calendar. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                            | Mandatory | Description                             |
| -------- | -------------------------------- | ---- | --------------------------------- |
| callback | AsyncCallback<[Event](#event)[]> | Yes  | Callback used to return an array of events. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar: err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.getEvents((err: BusinessError, data: calendarManager.Event[]) => {
      if (err) {
        console.error(`Failed to get events, err -> ${JSON.stringify(err)}`);
      } else {
        console.info(`Succeeded to get events, data -> ${JSON.stringify(data)}`);
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

| Name     | Type                            | Mandatory | Description                             |
| ----------- | -------------------------------- | ---- | --------------------------------- |
| eventFilter | [EventFilter](#eventfilter)      | Yes  | Filter criteria.                       |
| eventKey    | (keyof [Event](#event))[]        | Yes  | Filter field.                       |
| callback    | AsyncCallback<[Event](#event)[]> | Yes  | Callback used to return an array of events. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    const filter = calendarManager.EventFilter.filterById([id1, id2]);
    calendar.getEvents(filter, ['title', 'type', 'startTime', 'endTime'], (err: BusinessError, data: calendarManager.Event[]) => {
      if (err) {
        console.error(`Failed to get events, err -> ${JSON.stringify(err)}`);
      } else {
        console.info(`Succeeded to get events, data -> ${JSON.stringify(data)}`);
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

| Name     | Type                       | Mandatory | Description      |
| ----------- | --------------------------- | ---- | ---------- |
| eventFilter | [EventFilter](#eventfilter) | No  | Filter criteria. |
| eventKey    | (keyof [Event](#event))[]   | No  | Filter field. |

**Return value**

| Type                      | Description                               |
| -------------------------- | ----------------------------------- |
| Promise<[Event](#event)[]> | Promise used to return the result, which is an array of **Event** objects. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded to get events, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get events, err -> ${JSON.stringify(err)}`);
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
| [CalendarConfig](#calendarconfig) | Calendar configuration information. |

**Example**

```typescript
import { calendarMgr } from '../entryability/EntryAbility';
import { BusinessError } from '@ohos.base';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    const config = calendar.getConfig();
    console.info("get config success");
  }
});
```

### setConfig

setConfig(config: CalendarConfig, callback: AsyncCallback\<void>): void

Sets the calendar configuration information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                             | Mandatory | Description          |
| -------- | --------------------------------- | ---- | -------------- |
| config   | [CalendarConfig](#calendarconfig) | Yes  | Calendar configuration information. |
| callback | AsyncCallback\<void>              | Yes  | Callback used to return the result.    |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const config: calendarManager.CalendarConfig = {
  enableReminder: true,
  color: '#aabbcc'
};
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.setConfig(config, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to set config, err -> ${JSON.stringify(err)}`);
      } else {
        console.info(`Succeeded to set config, config -> ${JSON.stringify(config)}`);
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

| Name | Type                             | Mandatory | Description          |
| ------ | --------------------------------- | ---- | -------------- |
| config | [CalendarConfig](#calendarconfig) | Yes  | Calendar configuration information. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
import { calendarMgr } from '../entryability/EntryAbility';

let calendar : calendarManager.Calendar | undefined = undefined;
const config: calendarManager.CalendarConfig = {
  enableReminder: true,
  color: '#aabbcc'
};
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    calendar.setConfig(config).then(() => {
      console.info(`Succeeded to set config, data->${JSON.stringify(config)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to set config, err->${JSON.stringify(err)}`);
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
| [CalendarAccount](#calendaraccount) | Calendar account information. |

**Example**

```typescript
import { calendarMgr } from '../entryability/EntryAbility';
import { BusinessError } from '@ohos.base';

let calendar : calendarManager.Calendar | undefined = undefined;
calendarMgr?.getCalendar((err: BusinessError, data:calendarManager.Calendar) => {
  if (err) {
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    const account = calendar.getAccount();
    console.info(`get account success, account -> ${JSON.stringify(account)}`);
  }
});
```

## CalendarAccount

Calendar account information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                         | Read-only | Mandatory | Description                                  |
| ----------- | ----------------------------- | ---- | ---- | -------------------------------------- |
| name        | string                        | Yes  | Yes  | Account name.                            |
| type        | [CalendarType](#calendartype) | No  | Yes  | Account type.                            |
| displayName | string                        | No  | No  | Display name of the account. If this parameter is not set, an empty string is used. |

## CalendarConfig

Describes the calendar configuration information.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type    | Read-only   | Mandatory   | Description                                                        |
| -------------- |--------|-------|-------| ------------------------------------------------------------ |
| enableReminder | boolean | No    | No    | Whether to enable the reminder for events in the calendar. The value **true** means to enable the reminder for events in the calendar, and **false** means the opposite. The default value is **true**. |
| color          | number \| string | No  | No  | Calendar color. If this parameter is not set, the default value **'#0A59F7'** is used.               |

## Event

Describes an **Event** object, including the event title, start time, and end time.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type                             | Read-only | Mandatory | Description                                                                                                                                                |
| -------------- | --------------------------------- | ---- | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------|
| id             | number                            | No  | No  | Event ID. This parameter does not need to be set in the [addEvent()](#addevent) or [addEvents()](#addevents) API.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                          |
| type           | [EventType](#eventtype)           | No  | Yes  | Event type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                          |
| title          | string                            | No  | No  | Event title. If this parameter is not set, an empty string is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                              |
| location       | [Location](#location)             | No  | No  | Event location. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                              |
| startTime      | number                            | No  | Yes  | Start time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                 |
| endTime        | number                            | No  | Yes  | End time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                |
| isAllDay       | boolean                           | No  | No  | Whether the event is an all-day event. The value **true** means that the event is an all-day event, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                         |
| attendee       | [Attendee](#attendee)[]           | No  | No  | Event attendee. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                              |
| timeZone       | string                            | No  | No  | Time zone of the event. If this parameter is not set, the current system time zone is used. You can call the [getTimeZone()](../apis-basic-services-kit/js-apis-date-time.md#systemdatetimegettimezone) API to obtain the current system time zone.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| reminderTime   | number[]                          | No  | No  | Amount of time that the reminder occurs before the start of the event, in minutes. For example, if the value is 5, the reminder occurs 5 minutes before the event starts. If this parameter is not set, no reminder is set. The value can be negative.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | No  | No  | Recurrence rule of the event. If this parameter is not set, the value does not recur.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                             |
| description    | string                            | No  | No  | Event description. If this parameter is not set, an empty string is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                               |
| service        | [EventService](#eventservice)     | No  | No  | Event service. If this parameter is not set, no service is available.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                         |
| identifier<sup>12+</sup>     | string                            | No  | No  | A unique ID of an event can be specified. If this parameter is not set, the default null value is used. This parameter is not supported currently.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                           |

## CalendarType

Enumerates the account types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name      | Value          | Description                |
| ---------- | ------------ | -------------------- |
| LOCAL      | 'local'      | Local account.          |
| EMAIL      | 'email'      | Email account.          |
| BIRTHDAY   | 'birthday'   | Birthday account.          |
| CALDAV     | 'caldav'     | CalDAV account. |
| SUBSCRIBED | 'subscribed' | Subscription account.          |

## Location

Event location.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name     | Type  | Read-only | Mandatory | Description                    |
| --------- | ------ | ---- | ---- | ------------------------ |
| location  | string | No  | No  | Location. The default value is an empty string. |
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

| Name | Type    | Mandatory | Description        |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | Yes  | Array of event IDs. |

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id1 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
      id2 = data;
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    const filter = calendarManager.EventFilter.filterById([id1, id2]);
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded to filter by id, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by id, err -> ${JSON.stringify(err)}`);
    });
  }
});
```

### filterByTime

static filterByTime(start: number, end: number): EventFilter

Defines an event time based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name | Type  | Mandatory | Description      |
| ------ | ------ | ---- | ---------- |
| start  | number | Yes  | Start time. |
| end    | number | Yes  | End time. |

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event1).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    await calendar.addEvent(event2).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    const filter = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded to filter by time, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by time, err -> ${JSON.stringify(err)}`);
    });
  }
});
```

### filterByTitle

static filterByTitle(title: string): EventFilter

Defines an event title based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name | Type  | Mandatory | Description      |
| ------ | ------ | ---- | ---------- |
| title  | string | Yes  | Event title. |

**Return value**

| Type                       | Description                |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | **EventFilter** object. |

**Example**

```typescript
import { BusinessError } from '@ohos.base';
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
    console.error(`Failed to get calendar, err -> ${JSON.stringify(err)}`);
  } else {
    console.info(`Succeeded to get calendar, data -> ${JSON.stringify(data)}`);
    calendar = data;
    await calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded to add event, id -> ${data}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event, err -> ${JSON.stringify(err)}`);
    });
    const filter = calendarManager.EventFilter.filterByTitle('MyEvent');
    calendar.getEvents(filter).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded to filter by title, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to filter by title, err -> ${JSON.stringify(err)}`);
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
| IMPORTANT | 1    | Important event. This type of event supports countdown. |

## RecurrenceRule

Event recurrence rule. This type is not supported currently.

**System capability**: SystemCapability.Applications.CalendarData

| Name               | Type                                       | Read-only | Mandatory | Description                                                                       |
| ------------------- | ------------------------------------------- | ---- | ---- |---------------------------------------------------------------------------|
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | No  | Yes  | Type of the event recurrence rule.<br>**Atomic service API**: This API can be used in atomic services since API version 11.          |
| expire              | number                                      | No  | No  | End date of the recurrence period. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| count<sup>12+</sup>               | number                                      | No  | No  | Number of times that an event recurs. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| interval<sup>12+</sup>            | number                                      | No  | No  | Interval for event recurrence. If this parameter is not set, the default value **0** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| excludedDates<sup>12+</sup>       | number[]                                    | No  | No  | Excluded dates of event recurrence.<br>**Atomic service API**: This API can be used in atomic services since API version 12.          |
## RecurrenceFrequency

Enumerates the types of the event recurrence rule.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name   | Value  | Description      |
| ------- | ---- | ---------- |
| YEARLY  | 0    | Yearly. |
| MONTHLY | 1    | Monthly. |
| WEEKLY  | 2    | Weekly. |
| DAILY   | 3    | Daily. |

## Attendee

Describes the event attendee.

**System capability**: SystemCapability.Applications.CalendarData

| Name | Type  | Read-only | Mandatory | Description                                                                   |
| ----- | ------ | ---- | ---- |-----------------------------------------------------------------------|
| name  | string | No  | Yes  | Name of the attendee.<br>**Atomic service API**: This API can be used in atomic services since API version 11.        |
| email | string | No  | Yes  | Email address of the attendee.<br>**Atomic service API**: This API can be used in atomic services since API version 11.       |
| role<sup>12+</sup>  | [AttendeeRole](#attendeerole12) | No  | No  | Role of a party. This field is not supported currently.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## EventService

Event service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                       | Read-only | Mandatory | Description                                 |
| ----------- | --------------------------- | ---- | ---- | ------------------------------------- |
| type        | [ServiceType](#servicetype) | No  | Yes  | Service type.                           |
| uri         | string                      | No  | Yes  | URI of the service. It can be used to redirect the user to a page of another application. |
| description | string                      | No  | No  | Description of the service. If this parameter is not set, an empty string is used. |

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
| SPORTS_EVENTS   | 'SportsEvents'   | Watch a sports event. |
| SPORTS_EXERCISE | 'SportsExercise' | Start exercising.  |

## AttendeeRole<sup>12+</sup>

Attendee role type enumeration. This type is not supported currently.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Value            | Description    |
|--------------|---------------|--------|
| ORGANIZER<sup>12+</sup>    | 'organizer'   | Conference organizer. |
| PARTICIPANT<sup>12+</sup>  | 'participant' | Conference participant. |
