# Calendar Management

<!--Kit: Calendar Kit-->
<!--Subsystem: Applications-->
<!--Owner: @qq_42718467-->
<!--Designer: @qq_42718467-->
<!--Tester: @z30055209-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=2e8ed2014cd1fbe9e33d268d0dc93a7addc42728 translatedAt=2026-07-25T11:27:37.937Z pushedAt=2026-07-25T11:30:59.248Z -->

Calendar is used to store and manage personal or team events. Users can easily view, edit, and share event information on the calendar.

[CalendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarmanager) is used to manage [Calendar](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendar), which includes [CalendarAccount](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendaraccount) and [CalendarConfig](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarconfig).

You can create an application-specific calendar, and add, delete, update, and query this calendar. In addition, each [Event](../reference/apis-calendar-kit/js-apis-calendarManager.md#event) belongs to a specific Calendar and can be managed by using the Calendar. For details, see [Event Management](calendarmanager-event-developer.md).

## Available APIs

The table below lists the main APIs used for calendar management. For details about more APIs and their usage, see [@ohos.calendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md).

| API                                                    | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| getCalendarManager(context: Context): CalendarManager       | Obtains the **CalendarManager** object based on the context to manage calendars. |
| createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar> | Creates a **Calendar** object based on the calendar account information. This API uses a promise to return the result.|
| getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar> | Obtains the default or specified **Calendar** object. This API uses a promise to return the result.<br>The default **Calendar** object is created when the data storage runs for the first time. You can call this API instead of **createCalendar()** to use the default calendar for a new event.|
| getAllCalendars(): Promise\<Calendar[]>                     | Obtains the created and default **Calendar** objects of the current application. This API uses a promise to return the result.|
| deleteCalendar(calendar: Calendar): Promise\<void>          | Deletes a specified **Calendar** object. This API uses a promise to return the result.                 |
| getConfig(): CalendarConfig                                 | Obtains the calendar configuration information.                                          |
| setConfig(config: CalendarConfig): Promise\<void>           | Sets the calendar configuration information. This API uses a promise to return the result.                     |
| getAccount(): CalendarAccount                               | Obtains the calendar account information.                                          |

## How to Develop

1. Import dependencies.

    <!-- @[calendarData_entryAbilityImport](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/entryability/EntryAbility.ets) -->

    ``` TypeScript
    import { abilityAccessCtrl, AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { calendarManager } from '@kit.CalendarKit';
    import { window } from '@kit.ArkUI';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. Apply for the required permission. When using Calendar Kit, declare the **ohos.permission.READ_CALENDAR** and **ohos.permission.WRITE_CALENDAR** permissions in the **module.json5** file for reading and writing calendar events. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

3. Obtain the **calendarMgr** object based on the context to manage calendar accounts. You are advised to perform management operations in the **EntryAbility.ets** file.

    <!-- @[calendarData_entryAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/entryability/EntryAbility.ets) -->

    ``` TypeScript
    const DOMAIN = 0x0000;
    
    export let calendarMgr: calendarManager.CalendarManager | null = null;
    
    export let mContext: common.UIAbilityContext | null = null;
    
    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
      }
    
      onDestroy(): void {
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
      }
    
      onWindowStageCreate(windowStage: window.WindowStage): void {
        // The main window has been created. Set the main page for this ability.
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
            return;
          }
          hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
        });
        mContext = this.context;
        const permissions: Permissions[] = ['ohos.permission.READ_CALENDAR', 'ohos.permission.WRITE_CALENDAR'];
        let atManager = abilityAccessCtrl.createAtManager();
        atManager.requestPermissionsFromUser(mContext, permissions).then((result: PermissionRequestResult) => {
          hilog.info(DOMAIN, 'testTag', 'get Permission success');
          calendarMgr = calendarManager.getCalendarManager(mContext);
        }).catch((error: BusinessError) => {
          hilog.error(DOMAIN, 'testTag', 'get Permission error, Cause: %{public}s', JSON.stringify(error));
        })
      }
    
      onWindowStageDestroy(): void {
        // The main window has been destroyed. Release UI-related resources.
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
      }
    
      onForeground(): void {
        // The ability enters the foreground.
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
      }
    
      onBackground(): void {
        // The ability enters the background.
        hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
      }
    }
    ```

4. Create a **Calendar** object based on the calendar account information.

   Before creating a calendar account, query the account information first. If the account does not exist, an exception is thrown; after catching the exception, create the calendar account. Otherwise, duplicate accounts may be created.

    <!-- @[calendarData_indexImport](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { BusinessError } from '@kit.BasicServicesKit';
    import { calendarMgr } from '../entryability/EntryAbility';
    import { calendarManager } from '@kit.CalendarKit';
    
    let calendar: calendarManager.Calendar | undefined = undefined;
    // Specify the calendar account information.
    const calendarAccount: calendarManager.CalendarAccount = {
      // Calendar account name.
      name: 'MyCalendar',
      // Calendar account type.
      type: calendarManager.CalendarType.LOCAL,
      // Display name of the calendar account. If this field is left blank, the created calendar account is displayed as an empty string on the UI.
      displayName: 'MyCalendar'
    };
    ```

    <!-- @[calendarData_createAccount](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    // Create a calendar account.
    calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
      console.info('%{public}s', `Succeeded in creating calendar data->${JSON.stringify(data)}`);
      calendar = data;
      // Ensure that the calendar account is created before performing subsequent operations.
      // ...
    }).catch((error: BusinessError) => {
      console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
    });
    ```

5. After a calendar account is created, its color is black by default. If no color is specified, the display effect of the calendar account in dark mode may be poor on some versions or devices. You need to call **setConfig()** to set calendar configuration information, including event reminder and calendar color.

    <!-- @[calendarData_setConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    const calendarAccounts: calendarManager.CalendarAccount = {
      name: 'MyCalendar',
      type: calendarManager.CalendarType.LOCAL,
      displayName: 'MyCalendar'
    };
    // Calendar configuration information.
    calendarMgr?.getCalendar(calendarAccounts, (err, data) => {
      // Obtain the calendar account.
      if (err) {
        console.error(`Failed to get calendar, Code is ${err.code}, message is ${err.message}`);
      } else {
        const config: calendarManager.CalendarConfig = {
          // Enable the event reminder.
          enableReminder: true,
          // Set the calendar color.
          color: '#aabbcc'
        };
        // Set the calendar configuration information.
        data.setConfig(config).then(() => {
          console.info('%{public}s', `Succeeded in setting config, data->${JSON.stringify(config)}`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
        })
      }
    });
    ```

6. Query a specified calendar.

    <!-- @[calendarData_getAccountByParam](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    calendarMgr?.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
      console.info('%{public}s', `Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
    });
    ```

7. Query a default calendar account. The default calendar account is created when the calendar storage runs for the first time. If you do not care which account an event belongs to, you do not need to create a separate calendar account and can directly use the default one.

    <!-- @[calendarData_getDefaultAccount](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
      console.info('%{public}s', `Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
    });
    ```

8. Obtain the created and default **Calendar** objects of the current application.

   Due to data privacy and security concerns, applications with restricted permissions cannot obtain account information created by other applications.

    <!-- @[calendarData_getAllCalendars](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    calendarMgr?.getAllCalendars().then((data: calendarManager.Calendar[]) => {
      console.info('%{public}s', `Succeeded in getting all calendars, data -> ${JSON.stringify(data)}`);
      data.forEach((calendar) => {
        const account = calendar.getAccount();
        console.info('%{public}s', `account -> ${JSON.stringify(account)}`);
      })
    }).catch((err: BusinessError) => {
      console.error(`Failed to get all calendars. Code: ${err.code}, message: ${err.message}`);
    });
    ```

9. Delete the specified calendar, whose subordinate events are also deleted.

    <!-- @[calendarData_deleteCalendar](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Calendar/CalendarManager/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    if (!calendar || calendar === null) {
      console.error('Failed to delete calendar. calendar is null');
      return;
    }
    calendarMgr?.deleteCalendar(calendar).then(() => {
      console.info('%{public}s', 'Succeeded in deleting calendar');
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete calendar. Code: ${err.code}, message: ${err.message}`);
    });
    ```