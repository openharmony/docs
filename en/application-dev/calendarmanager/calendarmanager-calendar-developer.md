# Calendar Management

Calendar is used to store and manage personal or team events. Users can easily view, edit, and share event information on the calendar.

[CalendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarmanager) is used to manage [Calendar](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendar), which includes [CalendarAccount](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendaraccount) and [CalendarConfig](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarconfig).

You can create an application-specific calendar, and add, delete, update, and query this calendar. In addition, each [Event](../reference/apis-calendar-kit/js-apis-calendarManager.md#event) belongs to a specific Calendar and can be managed by using the Calendar. For details, see [Event Management](calendarmanager-event-developer.md).

## Available APIs

The table below lists the main APIs used for calendar management. For details about more APIs and their usage, see [@ohos.calendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md).

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getCalendarManager(context : Context): CalendarManager       | Obtains the **CalendarManager** object based on the context to manage calendars. |
| createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar> | Creates a **Calendar** object based on the calendar account information. This API uses a promise to return the result.|
| getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar> | Obtains the default or specified **Calendar** object. This API uses a promise to return the result.<br>The default **Calendar** object is created when the data storage runs for the first time. You can call this API instead of **createCalendar()** to use the default calendar for a new event.|
| getAllCalendars(): Promise\<Calendar[]>                      | Obtains the created and default **Calendar** objects of the current application. This API uses a promise to return the result.|
| deleteCalendar(calendar: Calendar): Promise\<void>           | Deletes a specified **Calendar** object. This API uses a promise to return the result.                 |
| getConfig(): CalendarConfig                                  | Obtains the calendar configuration information.                                          |
| setConfig(config: CalendarConfig): Promise\<void>            | Sets the calendar configuration information. This API uses a promise to return the result.                     |
| getAccount(): CalendarAccount                                | Obtains the calendar account information.                                          |


## How to Develop

1. Import dependencies.

   ```ts
   // EntryAbility.ets
   import {abilityAccessCtrl,AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarManager } from '@kit.CalendarKit';
   import { window } from '@kit.ArkUI';
   ```

2. Apply for the required permission. When using Calendar Kit, declare the **ohos.permission.READ_CALENDAR** and **ohos.permission.WRITE_CALENDAR** permissions in the **module.json5** file .for reading and writing calendar events. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

3. Obtain the **calendarMgr** object based on the context to manage calendars. You are advised to perform managements in the **EntryAbility.ets** file.

   ```ts
   // EntryAbility.ets
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

4. Create a **Calendar** object based on the calendar account information.

   Query the account information and create a calendar when an exception indicating that the calendar does not exist is thrown. Otherwise, the calendar may be created repeatedly.

   ```ts
   // Index.ets
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarMgr } from '../entryability/EntryAbility';
   import { calendarManager } from '@kit.CalendarKit';
   
   let calendar: calendarManager.Calendar | undefined = undefined;
   // Specify the calendar account information.
   const calendarAccount: calendarManager.CalendarAccount = {
     // Calendar name.
     name: 'MyCalendar',
     // Calendar type.
     type: calendarManager.CalendarType.LOCAL,
     // Display name of the calendar. If this field is left blank, the created calendar is displayed as an empty string on the UI.
     displayName: 'MyCalendar'
   };
   // Create a calendar.
   calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
     calendar = data;
     // Ensure that the calendar account is created before performing subsequent operations.
     // ...
   }).catch((error: BusinessError) => {
     console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
   });
   ```

5. After a calendar is created, it is displayed in black. You need to call the **setConfig()** API to set calendar configuration information, including event reminder and calendar color.

   ```ts
   // Index.ets
   // Calendar configuration information.
   const config: calendarManager.CalendarConfig = {
     // Enable the event reminder.
     enableReminder: true,
     // Set the calendar color.
     color: '#aabbcc'
   };
   // Set the calendar configuration information.
   calendar.setConfig(config).then(() => {
     console.info(`Succeeded in setting config, data->${JSON.stringify(config)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
   });
   ```

6. Query a specified calendar.

    ```ts
   // Index.ets
   calendarMgr?.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
   });
   ```

7. Query a default calendar. The default **Calendar** object is created when the data storage runs for the first time. You can use the default calendar for a new event.

    ```ts
   // Index.ets
   calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
   });
   ```

8. Obtain the created and default **Calendar** objects of the current application.

   Due to data privacy and security concerns, applications with restricted permissions cannot obtain account information created by other applications.

   ```ts
   // Index.ets
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

9. Delete the specified calendar, whose subordinate events are also deleted.

    ```ts
   // Index.ets
   calendarMgr?.deleteCalendar(calendar).then(() => {
     console.info("Succeeded in deleting calendar");
   }).catch((err: BusinessError) => {
     console.error(`Failed to delete calendar. Code: ${err.code}, message: ${err.message}`);
   });
   ```
