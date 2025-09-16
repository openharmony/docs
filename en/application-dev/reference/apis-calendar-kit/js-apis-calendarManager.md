# @ohos.calendarManager (Calendar Manager)

<!--Kit: Calendar Kit-->
<!--Subsystem: Applications-->
<!--Owner: @qq_42718467-->
<!--Designer: @huangxinwei-->
<!--Tester: @z30055209-->
<!--Adviser: @ge-yafang-->

The **calendarManager** module provides APIs for calendar and event management, including those for creating, deleting, modifying, and querying calendars and events.

- A [CalendarManager](#calendarmanager) object is used to manage [Calendar](#calendar) objects.

- A [Calendar](#calendar) object contains the account information [CalendarAccount](#calendaraccount) and configuration information [CalendarConfig](#calendarconfig). An **Event** object is subordinate to a **Calendar** object. To create an **Event** object, you need to create a **Calendar** object first. A **Calendar** contains multiple **Event** objects, but an **Event** belongs to only one **Calendar**. **CalendarManager** is used to manage calendars, and **EventFilter** is used to manage events.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - To read a calendar or event, you should request the ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR permission.
> 
> - To add, delete, or modify a calendar or event, you should request the ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR permission.

The following table lists the supported operations after the corresponding permission is requested.

| Permission                    | Operations on the Calendar Account                      | Operations on the Event                                          |
| ------------------------------ | -------------------------------------------- | ------------------------------------------------------------ |
| ohos.permission.READ_CALENDAR  | - Read the system calendar account.<br>- Read the calendar account created by the application.| - Read the specified events under the system calendar account.<br>- Read the specified events under the calendar account created by the application.|
| ohos.permission.WRITE_CALENDAR | - Add, delete, or modify calendar accounts created by the application.              | - Add, delete, or modify the specified events under the system calendar account.<br>- Add, delete, or modify the specified events under the calendar account created by the application.|
| ohos.permission.READ_WHOLE_CALENDAR | - Read all calendar accounts.                     | - Read all events created by applications.             |
| ohos.permission.WRITE_WHOLE_CALENDAR | - Add, delete, or modify all calendar accounts.               | - Add, delete, or modify all events created by applications.         |


## Modules to Import

```typescript
import { calendarManager } from '@kit.CalendarKit';
```

## calendarManager.getCalendarManager

getCalendarManager(context: Context): CalendarManager

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
      console.info(`get Permission success, result: ${JSON.stringify(result)}`);
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

Before calling any of the following APIs, you must use [getCalendarManager()](#calendarmanagergetcalendarmanager) to obtain a **CalendarManager** object first.

**System capability**: SystemCapability.Applications.CalendarData


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

**Required permissions**: ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR

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

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

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

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

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

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

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

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                                  | Mandatory| Description                                     |
| -------- | -------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | Yes  | Callback used to return an array of the obtained **Calendar** objects.|

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

**Required permissions**: ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR

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

Edits an event on the event creation page, with no event ID specified in **Event**. This API uses a promise to return the result. Events created using this API cannot be queried or modified by third-party applications, but only by the system calendar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type           | Mandatory| Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object.|

**Return value**

| Type          | Description                                                                         |
| -------------- |-----------------------------------------------------------------------------|
| Promise&lt;number&gt; | Promise used to return the event ID. The event ID is the unique identifier of an event and is the auto-increment primary key of the database. If the event creation fails, no value is returned; if the value is less than **0**, the event creation is canceled; if the value is greater than **0**, the event creation is successful. The return value cannot be **0**|

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

**System capability**: SystemCapability.Applications.CalendarData

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name| Type  | Read Only| Optional| Description                                                                      |
| ---- | ------ | ---- |----|--------------------------------------------------------------------------|
| id   | number | Yes  | No | Calendar account ID, which is the unique identifier of a calendar account and is the auto-increment primary key of the database. If the value is less than **0**, the account creation fails; if the value is greater than **0**, the account creation succeeds.|

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

Adds an event, with no event ID, **instanceStartTime**, and **instanceEndTime** specified in **Event**. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                   |
| -------- | ---------------------- | ---- |-----------------------------------------------------------------------|
| event    | [Event](#event)        | Yes  | **Event** object.                                                             |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the event ID. The event ID is the unique identifier of an event and is the auto-increment primary key of the database. If the value is less than **0**, the event creation fails; if the value is greater than **0**, the event creation succeeds.|

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

Adds an event, with no event ID, **instanceStartTime**, and **instanceEndTime** specified in **Event**. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type           | Mandatory| Description       |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | Yes  | **Event** object.|

**Return value**

| Type            | Description                      |
| ---------------- |--------------------------|
| Promise\<number> | Promise used to return the event ID. The ID is greater than 0. |

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

Adds events in batches, with no event ID, **instanceStartTime**, and **instanceEndTime** specified in **Event**. This API uses an asynchronous callback to return the result.

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

Adds events in batches, with no event ID, **instanceStartTime**, and **instanceEndTime** specified in **Event**. This API uses a promise to return the result.

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

| Name  | Type                | Mandatory| Description                                    |
| -------- | -------------------- | ---- |----------------------------------------|
| id       | number               | Yes  | Event ID, which is the unique identifier of an event. If the input event ID is a positive integer, the event is created.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                                 |

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
    calendar.addEvent(event).then((data: number) => {
      console.info(`Succeeded in adding event, id -> ${data}`);
      id = data;
      calendar?.deleteEvent(id, (err: BusinessError) => {
        if (err) {
          console.error(`Failed to delete event. Code: ${err.code}, message: ${err.message}`);
        } else {
          console.info(`Succeeded in deleting event`);
        }
      });
    }).catch((err: BusinessError) => {
      console.error(`Failed to add event. Code: ${err.code}, message: ${err.message}`);
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

Obtains all events in the current calendar. This API uses an asynchronous callback to return the result.

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
If there is only one input parameter, the filter criteria, corresponding to the type **EventFilter**, must be set as the parameter.
If no input parameter is specified, all events under the specified calendar account can be queried.

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
    // Perform fuzzy query based on MyEvent. If an event of the MyEvent1 type exists, the event can also be queried.
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
    console.info(`Succeeded in getting config, config -> ${JSON.stringify(config)}`);
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

### queryEventInstances<sup>18+</sup>

queryEventInstances(start: number, end: number, ids?: number[], eventKey?: (keyof Event)[]): Promise\<Event[]>

Queries the event instance with a specified event key in a calendar. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.CalendarData

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name     | Type                       | Mandatory  | Description        |
| ----------- | --------------------------- |------|------------|
| start  | number | Yes   | Start time of an event. The value is a 13-digit timestamp.   |
| end    | number | Yes   | End time of an event. The value is a 13-digit timestamp.   |
| ids    | number[] | No   | Array of event IDs to be queried, which can be empty or undefined. Otherwise, the value of each ID must be greater than **0**.   |
| eventKey    | (keyof [Event](#event))[]   | No   | Event key for querying events.|

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
    calendar?.queryEventInstances(date.getTime(), date.getTime() + 60 * 60 * 1000, undefined, 
      ["title", "startTime", "endTime", "instanceStartTime", "instanceEndTime",]).then((data: calendarManager.Event[]) => {
      console.info(`Succeeded in getting event instances, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get event instances. Code: ${err.code}, message: ${err.message}`);
    });
  }
});
```

## CalendarAccount

Describes the calendar account information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                         | Read Only| Optional| Description                                          |
| ----------- | ----------------------------- | ---- |----|----------------------------------------------|
| name        | string                        | Yes  | No | Account name (defined by developers), with a maximum of 5000 characters.                  |
| type        | [CalendarType](#calendartype) | No  | No | Account type.                                       |
| displayName | string                        | No  | Yes | Account name displayed on the calendar application (defined by users). If this parameter is not specified, the default value is an empty string with a maximum of 64 characters.|

## CalendarConfig

Describes the calendar configuration information.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type    | Read Only   | Optional| Description                                                        |
| -------------- |--------|-------|----| ------------------------------------------------------------ |
| enableReminder | boolean | No    | Yes | Whether to enable the reminder for events in the calendar. The value **true** means to enable the reminder for events in the calendar, and **false** means the opposite. The default value is **true**.|
| color          | number \| string | No  | Yes | Calendar color. If the value is a number, the value ranges from 0x000000 to 0xFFFFFF or from 0x00000000 to 0xFFFFFFFF. If the value is a string, the value contains 7 or 9 characters, for example, **#FFFFFF** or **#FFFFFFFFF**. If this parameter is not specified or the input data is incorrect, the default value **#0A59F7** is used.|

## Event

Describes an **Event** object, including the event title, start time, and end time.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Type                             | Read Only| Optional| Description                                                                                                                                                                                                                                      |
| -------------- | --------------------------------- | ---- |----|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| id             | number                            | No  | Yes | Event ID. When you call [addEvent()](#addevent) or [addEvents()](#addevents) to create an event, this parameter is not required. When you call [deleteEvent()](#deleteevent) or [deleteEvents()](#deleteevents) to delete an event, this parameter is required and must be set to an array of positive integers. If this parameter is set to an invalid value, an error will be reported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.         |
| type           | [EventType](#eventtype)           | No  | No | Event type.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                            |
| title          | string                            | No  | Yes | Event title, with a maximum of 5000 characters. If this parameter is not specified, the default value is an empty string.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                  |
| location       | [Location](#location)             | No  | Yes | Event location. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                |
| startTime      | number                            | No  | No | Start time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                   |
| endTime        | number                            | No  | No | End time of the event. The value is a 13-digit timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                  |
| isAllDay       | boolean                           | No  | Yes | Whether the event is an all-day event. The value **true** means that the event is an all-day event, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                           |
| attendee       | [Attendee](#attendee)[]           | No  | Yes | Attendees of a conference event. If this parameter is not set, the default null value is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                              |
| timeZone       | string                            | No  | Yes | Time zone of the event, with a maximum of 5000 characters. If this parameter is not specified or set to an invalid value, the current time zone is used by default. If a different time zone is required, enter the corresponding time zone. You can call [systemDateTime.getTimezone()](../apis-basic-services-kit/js-apis-date-time.md#systemdatetimegettimezone) to obtain the current system time zone.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| reminderTime   | number[]                          | No  | Yes | Amount of time that the reminder occurs before the start of the event, in minutes. For example, if the value is 5, the reminder occurs 5 minutes before the event starts. If this parameter is not set, no reminder is set. A negative value indicates the delay time for sending a notification.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                        |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | No  | Yes | Recurrence rule of an event. If this parameter is not set, the value does not recur.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                               |
| description    | string                            | No  | Yes | Event description, with a maximum of 5000 characters. If this parameter is not specified, the default value is an empty string.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                   |
| service        | [EventService](#eventservice)     | No  | Yes | <!--RP1-->Event service. If this parameter is not set, no service is available. This function is not supported currently.<!--RP1End-->   <br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                |
| identifier<sup>12+</sup>     | string                            | No  | Yes | Unique ID of an event, with a maximum of 5000 characters. If this parameter is not specified, the default value is **null**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                           |
| isLunar<sup>12+</sup>     | boolean                            | No  | Yes | Whether it is a lunar calendar event. The value **true** means that the event is a lunar calendar event, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                           |
| instanceStartTime<sup>18+</sup> | number                            | No  | Yes | Start time of the event. The value is a 13-digit timestamp. This parameter does not need to be set in [addEvent()](#addevent) or [addEvents()](#addevents).<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                                |
| instanceEndTime<sup>18+</sup>   | number                            | No  | Yes | End time of the event. The value is a 13-digit timestamp. This parameter does not need to be set in [addEvent()](#addevent) or [addEvents()](#addevents).<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                                                                               |

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

| Name     | Type  | Read Only| Optional| Description                    |
| --------- | ------ | ---- |----| ------------------------ |
| location  | string | No  | Yes | Location, with a maximum of 5000 characters. If this parameter is not specified, the default value is an empty string.|
| longitude | number | No  | Yes | Longitude of the location. The value ranges from -180 to 180. The default value is **0**. |
| latitude  | number | No  | Yes | Latitude of the location. The value ranges from -90 to 90. The default value is **0**. |

## EventFilter

Implements an event filter.

You can use [filterById()](#filterbyid), [filterByTime()](#filterbytime), or [filterByTitle()](#filterbytitle) to obtain an event filter, and then pass the filter in [getEvents()](#getevents) for filtering.

**System capability**: SystemCapability.Applications.CalendarData

### filterById

static filterById(ids: number[]): EventFilter

Defines an event ID based filter.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | Yes  | An array of event IDs, where each event ID must be a positive integer.|

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
| start  | number | Yes  | Start time. The value is a 13-digit timestamp.|
| end    | number | Yes  | End time. The value is a 13-digit timestamp.|

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

Filters events by event title. This API supports fuzzy match.

**System capability**: SystemCapability.Applications.CalendarData

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| title  | string | Yes  | Event title, with a maximum of 5000 characters.|

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

| Name     | Value  | Description                     |
| --------- | ---- |-------------------------|
| NORMAL    | 0    | Normal event, such as conference or an alarm clock.  |
| IMPORTANT | 1    | Important event, such as wedding anniversary, are not recommended for third-party developers. Important events do not support one-click service redirection and custom reminder time.|

## RecurrenceRule

Describes the recurrence rule of an event.

**System capability**: SystemCapability.Applications.CalendarData

| Name               | Type                                       | Read Only| Optional| Description                                                                                                                                                                                                                                                                                                                             |
| ------------------- | ------------------------------------------- | ---- |----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | No  | No | Type of the event recurrence rule.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                                                |
| expire              | number                                      | No  | Yes | End date of the recurrence period. The value is a 13-digit timestamp. If this parameter is not specified, the event has no end date.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                                                                                                                                                          |
| count<sup>12+</sup>               | number                                      | No  | Yes | Number of the recurrent event. The value is a non-negative integer. If this parameter is not set, the default value **0** is used, indicating that the number of recurrent events is infinite; if the value is negative, the effect is the same as that of **0**. If both **count** and **expire** exist, **count** is used.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                    |
| interval<sup>12+</sup>            | number                                      | No  | Yes | Interval for a recurrent event. The value is a non-negative integer. If this parameter is not set, the default value **0** is used, indicating that the event is repeated based on the recurrence rule without intervals; if the value is negative, the effect is the same as that of **0**. If both **interval** and **expire** exist, **expire** is used.<br>This attribute is related to the **recurrenceFrequency** rule. The recurrence interval varies according to the recurrence rule. For example, if the **interval** value is **2**, the following situations occur:<br>Daily recurrence: The event repeats every two days.<br>Weekly recurrence: The event repeats every two weeks.<br>Monthly recurrence: The event repeats every two months.<br>Yearly recurrence: The event repeats every two years.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| excludedDates<sup>12+</sup>       | number[]                                    | No  | Yes | Excluded date of a recurrent event. The value is in the timestamp format. If this parameter is not set, the default value is empty, indicating that no date is excluded; if the value is **0** or a negative number, the effect is the same as that of the empty value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                                |
| daysOfWeek<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by day of a week. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 7, corresponding to Monday to Sunday. Other values are invalid and have the same effect as the empty value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                                        |
| daysOfMonth<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by day of a month. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 31, corresponding to the first to the last days of each month. Other values are invalid and have the same effect as **null**. The value **29**, **30**, or **31** is invalid if the corresponding date does not exist in the current month.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                |
| daysOfYear<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by day of a year. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 366, corresponding to the first to the last days of each year. Other values are invalid and have the same effect as the empty value. If this year only has 365 days, the value **366** is invalid.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                           |
| weeksOfMonth<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by week of a month. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 5, corresponding to the first to the last weeks of each month. Other values are invalid and have the same effect as the empty value. If this month only has four weeks, the value **5** is invalid.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                 |
| weeksOfYear<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by week of a year. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 53, corresponding to the first to the last weeks of each year. Other values are invalid and have the same effect as the empty value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                               |
| monthsOfYear<sup>12+</sup>       | number[]                                    | No  | Yes | Repeats by month of a year. If this parameter is not set, the default value is empty, indicating that there is no recurrence rule. The value ranges from 1 to 12, corresponding to the first to the last months of each year. Other values are invalid and have the same effect as the empty value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                                               |
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

Describes the attendee information in a conference event.

**System capability**: SystemCapability.Applications.CalendarData

| Name | Type  | Read Only| Optional| Description                                                                |
| ----- | ------ | ---- |----|--------------------------------------------------------------------|
| name  | string | No  | No | Name of the attendee, with a maximum of 5000 characters.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| email | string | No  | No | Email address of the attendee, with a maximum of 5000 characters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| role<sup>12+</sup>  | [AttendeeRole](#attendeerole12) | No  | Yes | Role of the attendee.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| status<sup>18+</sup> | [AttendeeStatus](#attendeestatus18) | No  | Yes| Status of the attendee. If this parameter is not set, the default value is empty.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| type<sup>18+</sup>   | [AttendeeType](#attendeetype18)     | No  | Yes| Type of the attendee. If this parameter is not set, the default value is empty.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## EventService

Describes the event service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.CalendarData

| Name       | Type                       | Read Only| Optional| Description                                 |
| ----------- | --------------------------- | ---- |----|-------------------------------------|
| type        | [ServiceType](#servicetype) | No  | No | Service type.                              |
| uri         | string                      | No  | No | Service URI, in the DeepLink format. It can be used to redirect the user to a page of another application. The value is a string with a maximum of 5000 characters.|
| description | string                      | No  | Yes | Description of the service, with a maximum of 5000 characters. If this parameter is not specified, the default value is an empty string.                |

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

Enumerates the attendee role types in a conference event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.CalendarData

| Name          | Value            | Description    |
|--------------|---------------|--------|
| ORGANIZER   | 'organizer'   | Conference organizer.|
| PARTICIPANT | 'participant' | Conference participant.|

## AttendeeStatus<sup>18+</sup>

Enumerates the status types of an attendee.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Applications.CalendarData

| Name                        | Value  | Description      |
|----------------------------|-----|----------|
| UNKNOWN      | 0   | The attendee status is unknown.|
| TENTATIVE    | 1   | The attendee status is tentative.|
| ACCEPTED     | 2   | The attendee has accepted the conference invitation. |
| DECLINED     | 3   | The attendee has rejected the conference invitation. |
| UNRESPONSIVE | 4   | The attendee does not respond. |

## AttendeeType<sup>18+</sup>

Enumerates the types of attendees invited to a conference event.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Applications.CalendarData

| Name                    | Value  | Description                |
|------------------------|-----|--------------------|
| REQUIRED | 1   | Required attendee.          |
| OPTIONAL | 2   | Optional attendee.          |
| RESOURCE | 3   | Resources (such as TVs or projectors) used in a conference.|
