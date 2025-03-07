# Event Management

An event refers to a specific event or activity arrangement. Event management is to arrange events or activities to effectively use related resources, improve productivity and efficiency, and enable users to better manage time and tasks.

An [Event](../reference/apis-calendar-kit/js-apis-calendarManager.md#event) in Calendar Kit belongs to a [Calendar](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendar). A calendar can contain multiple events, but an event can only belong to one calendar.

After obtaining the **Calendar** object, you can create, delete, modify and query the events belonging to this calendar. When creating or modifying an event, you can set the event title, start time, end time, event type, event location, event reminder, and event recurrence rule to facilitate event management.

## Available APIs

The table below lists the main APIs used for event management. For details about more APIs and their usage, see [@ohos.calendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md).

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getCalendarManager(context : Context): CalendarManager       | Obtains a **CalendarManager** object based on the context.           |
| createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar> | Creates a **Calendar** object based on the calendar account information. This API uses a promise to return the result.|
| addEvent(event: Event): Promise\<number>                     | Creates an event, with no event ID specified in **Event**. This API uses a promise to return the result.        |
| editEvent(event: Event): Promise\<number>                    | Creates a single event. If the input parameter **Event** is not set to the event ID, the event creation screen is displayed when this API is called. This API uses a promise to return the result.|
| deleteEvent(id: number): Promise\<void>                      | Deletes an event with the specified ID. This API uses a promise to return the result.                 |
| updateEvent(event: Event): Promise\<void>                    | Updates an event. This API uses a promise to return the result.                             |
| getEvents(eventFilter?: EventFilter, eventKey?: (keyof Event)[]): Promise\<Event[]> | Obtains all events in a calendar that match the filter criteria. This API uses a promise to return the result.    |

## How to Develop

1. Import dependencies.

   ```ts
   // entry/src/main/ets/entryability/EntryAbility.ets
   import {abilityAccessCtrl,AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarManager } from '@kit.CalendarKit';
   import { window } from '@kit.ArkUI';
   ```

2. Apply for the required permission. When using Calendar Kit, declare the **ohos.permission.READ_CALENDAR** and **ohos.permission.WRITE_CALENDAR** permissions in the **module.json5** file .for reading and writing calendar events. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

3. Obtain the **calendarMgr** object based on the context to manage calendars. You are advised to perform managements in the **EntryAbility.ets** file.

   ```ts
   // entry/src/main/ets/entryability/EntryAbility.ets
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

4. Create a **Calendar** object based on the calendar account information to manage events. Set the calendar configuration information, such as event reminder and calendar color, as required.

   ```ts
   // Index.ets
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarMgr } from '../entryability/EntryAbility';
   import { calendarManager } from '@kit.CalendarKit';
   
   let calendar: calendarManager.Calendar | undefined = undefined;
   // Specify the calendar account information.
   const calendarAccount: calendarManager.CalendarAccount = {
     name: 'MyCalendar',
     type: calendarManager.CalendarType.LOCAL,
     // Display name of the calendar. If this field is left blank, the created calendar is displayed as an empty string on the UI.
     displayName: 'MyCalendar'
   };
   // Calendar configuration information.
   const config: calendarManager.CalendarConfig = {
     // Enable the event reminder.
     enableReminder: true,
     // Set the calendar color.
     color: '#aabbcc'
   };
   // Create a calendar.
   calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
     calendar = data;
     // Ensure that the calendar is successfully created before managing related events.
   
     // Set the calendar configuration information, including event reminder and calendar color.
     calendar.setConfig(config).then(() => {
       console.info(`Succeeded in setting config, data->${JSON.stringify(config)}`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
     });
     // ...
   }).catch((error: BusinessError) => {
     console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
   });
   ```

5. Add an event to the current calendar without specifying the event ID.

   When creating an event, you can set the event title, start time, end time, event type, event location, event reminder time, and event recurrence rule.

   After an event is created, an event ID is returned as the unique identifier. You can update or delete the event based on the event ID.

   Currently, you can create an event in either of the following methods:

   Method 1: Use the **addEvent()** or **addEvents()** API to create an event in the calendar. You can use the **addEvent()** API to create a single event or use the **addEvents()** API to create events in batches. The following describes how to create a single event.

   Method 2: After obtaining the **calendarManager** object, you can use the **editEvent()** API to create a single event. In this case, the event creation page is displayed, where you can perform related operations to create an event. Note that **editEvent()** does not support the creation of custom periodic events.

   ```ts
   // Index.ets
   let eventId : number | undefined = undefined;
   const date = new Date();
   const event: calendarManager.Event = {
     // Event title.
     title: 'title',
     // Event type. Third-party developers are not advised to use calendarManager.EventType.IMPORTANT. Important events do not support quick service redirection and custom reminder time.
     type: calendarManager.EventType.NORMAL,
     // Start time of the event.
     startTime: date.getTime(),
     // End time of the event.
     endTime: date.getTime() + 60 * 60 * 1000,
     // A 10-minute-countdown reminder before the start time.
     reminderTime: [10],
     // Event recurrence rule. Mandatory if the event is a periodic one; otherwise, optional.
     recurrenceRule: {
       // Event recurrence frequency, which can be daily, weekly, monthly, or yearly.
       recurrenceFrequency: calendarManager.RecurrenceFrequency.DAILY,
       // Number of event recurrence times. Either count or expire needs to be set. If both attributes are set, the value of the count attribute is used.
       count: 100,
       // Interval for event recurrence, which is related to recurrenceFrequency. This example indicates that the event is repeated every two days.
       interval: 2,
       // Event expiration time. Either count or expire needs to be set. If both attributes are set, the value of the count attribute is used.
       expire: date.getTime() + 60 * 60 * 1000 * 3,
       // Excluded date. If set, the specified date is excluded from the repeated event.
       excludedDates: [date.getTime() + 60 * 60 * 1000 * 2]
     },
     // Event service (optional). Set this attribute for the event that requires the one-click service.
     service: {
       // Service type, for example, TRIP, MEETING, or WATCHING.
       type: calendarManager.ServiceType.TRIP,
       // Service URI, in the DeepLink format, which supports redirection to a specific page of a third-party application. To use the DeepLink mode, you need to register your application with the Huawei HAG Cloud with the registration information including the application bundle name and application service type.
       // DeepLink includes scheme, host, path, and parameters (excluding values).
       uri: 'xxx://xxx.xxx.com/xxx',
       // Service auxiliary description (optional).
       description: 'One-click service'
     }
   
   };
   // Method 1
   calendar.addEvent(event).then((data: number) => {
     console.info(`Succeeded in adding event, id -> ${data}`);
     eventId = data;
   }).catch((err: BusinessError) => {
     console.error(`Failed to addEvent. Code: ${err.code}, message: ${err.message}`);
   });
   // Method 2
    const eventInfo: calendarManager.Event = {
     // Event title.
     title: 'title',
     // Event type.
     type: calendarManager.EventType.NORMAL,
     // Start time of the event.
     startTime: date.getTime(),
     // End time of the event.
     endTime: date.getTime() + 60 * 60 * 1000
   };
   calendarMgr?.editEvent(eventInfo).then((id: number): void => {
     console.info(`create Event id = ${id}`);
     eventId = id;
   }).catch((err: BusinessError) => {
     console.error(`Failed to create Event. Code: ${err.code}, message: ${err.message}`);
   });
   ```

6. Update information about a specified event based on the event ID.

   ```ts
   // Index.ets
   const updateEvent: calendarManager.Event = {
     title: 'updateTitle',
     description: 'updateEventTest',
     type: calendarManager.EventType.NORMAL,
     id: eventId,
     startTime: date.getTime(),
     endTime: date.getTime() + 60 * 60 * 1000
   };
   calendar.updateEvent(updateEvent).then(() => {
     console.info(`Succeeded in updating event`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to update event. Code: ${err.code}, message: ${err.message}`);
   });
   ```

7. Query all events belonging to the current calendar. Due to data privacy and security concerns, applications with restricted permissions cannot obtain account information created by other applications. Query results vary with query conditions and fields.

   If no query condition or field is set, all events of the specified calendar can be queried.
   ```ts
   calendar.getEvents().then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   You can also query events by the event ID, start time and end time of the event, or event title.
   ```ts
   // Query by the event ID.
   const filterId = calendarManager.EventFilter.filterById([eventId]);
   calendar.getEvents(filterId).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   
   // Query by the event title.
   const filterTitle = calendarManager.EventFilter.filterByTitle('update');
   calendar.getEvents(filterTitle).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   
   // Query by the start time and end time.
   const filterTime = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
   calendar.getEvents(filterTime).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events filter by time, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to filter by time. Code: ${err.code}, message: ${err.message}`);
   });
   ```

8. Delete a specified event by event ID. You can use the **deleteEvent()** API to create a single event or use the **deleteEvents()** API to delete events in batches. The following describes how to delete a single event.

   ```ts
   // Index.ets
   calendar.deleteEvent(eventId).then(() => {
      console.info("Succeeded in deleting event");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete event. Code: ${err.code}, message: ${err.message}`);
   });
   ```
