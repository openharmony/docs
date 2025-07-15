# 日历账户管理

日历账户‌用于存储和管理个人或团队的日程，通过日历账户，用户可以方便地查看、编辑和共享日程信息。

日历管理器[CalendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarmanager)用于管理日历账户[Calendar](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendar)。日历账户主要包含账户信息[CalendarAccount](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendaraccount)和配置信息[CalendarConfig](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendarconfig)。

开发者可以创建属于应用特有的日历账户，还可以对日历账户进行新增、删除、更新和查询。此外，每个日程[Event](../reference/apis-calendar-kit/js-apis-calendarManager.md#event)归属于某一个特定的日历账户，可以通过日历账户对该账户下面的日程进行管理，具体相关指导可见[日程管理](calendarmanager-event-developer.md)。

## 接口说明

以下是日历账户管理的相关接口，更多详细接口及使用请参考[@ohos.calendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md)。

| 接口名称                                                     | 描述                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| getCalendarManager(context: Context): CalendarManager       | 根据上下文获取日历管理器对象CalendarManager，用于管理日历。  |
| createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar> | 根据日历账户信息，创建一个Calendar对象，使用Promise异步回调。 |
| getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar> | 获取默认Calendar对象或者指定Calendar对象，使用Promise异步回调。<br>默认Calendar是日历存储首次运行时创建的，若创建Event时不关注其Calendar归属，则无须通过createCalendar()创建Calendar，直接使用默认Calendar。 |
| getAllCalendars(): Promise\<Calendar[]>                     | 获取当前应用所有创建的Calendar对象以及默认Calendar对象，使用Promise异步回调。 |
| deleteCalendar(calendar: Calendar): Promise\<void>          | 删除指定Calendar对象，使用Promise异步回调。                  |
| getConfig(): CalendarConfig                                 | 获取日历配置信息。                                           |
| setConfig(config: CalendarConfig): Promise\<void>           | 设置日历配置信息，使用Promise异步回调。                      |
| getAccount(): CalendarAccount                               | 获取日历账户信息。                                           |


## 开发步骤

1. 导入相关依赖。

   ```ts
   // EntryAbility.ets
   import { abilityAccessCtrl, AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarManager } from '@kit.CalendarKit';
   import { window } from '@kit.ArkUI';
   ```

2. 申请权限。使用Calendar Kit时，需要在module.json5中声明申请读写日历日程所需的权限：`ohos.permission.READ_CALENDAR`和`ohos.permission.WRITE_CALENDAR`。具体指导可见[声明权限](../security/AccessToken/declare-permissions.md)。

3. 根据上下文获取日程管理器对象calendarMgr，用于对日历账户进行相关管理操作。推荐在`EntryAbility.ets`文件中进行操作。

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

4. 根据日历账户信息，创建一个日历账户Calendar对象。

   创建日历账户之前，开发者需要先根据账户信息进行查询，如果账户不存在则抛出异常信息，捕获到异常再进行日历账户的创建，否则可能会出现账户重复创建的问题。

   ```ts
   // Index.ets
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarMgr } from '../entryability/EntryAbility';
   import { calendarManager } from '@kit.CalendarKit';
   
   let calendar: calendarManager.Calendar | undefined = undefined;
   // 指定日历账户信息
   const calendarAccount: calendarManager.CalendarAccount = {
     // 日历账户名称
     name: 'MyCalendar',
     // 日历账户类型
     type: calendarManager.CalendarType.LOCAL,
     // 日历账户显示名称，该字段如果不填，创建的日历账户在界面显示为空字符串。
     displayName: 'MyCalendar'
   };
   // 创建日历账户
   calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
     calendar = data;
     // 请确保日历账户创建成功后，再进行后续相关操作
     // ...
   }).catch((error: BusinessError) => {
     console.error(`Failed to create calendar. Code: ${error.code}, message: ${error.message}`);
   });
   ```

5. 日历账户创建之后，日历账户颜色默认为黑色，不指定日历账户颜色可能导致部分版本/设备深色模式下显示效果不佳。开发者需要调用setConfig()接口设置日历配置信息，包括是否打开日历账户下的日程提醒能力、设置日历账户颜色。

   ```ts
   // Index.ets
   // 日历配置信息
   const config: calendarManager.CalendarConfig = {
     // 打开日程提醒
     enableReminder: true,
     // 设置日历账户颜色
     color: '#aabbcc'
   };
   // 设置日历配置信息
   calendar.setConfig(config).then(() => {
     console.info(`Succeeded in setting config, data->${JSON.stringify(config)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to set config. Code: ${err.code}, message: ${err.message}`);
   });
   ```

6. 可以查询指定日历账户。

    ```ts
   // Index.ets
   calendarMgr?.getCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
   });
    ```

7. 也可以查询默认日历账户，默认日历账户是日历存储首次运行时创建的，若创建日程时不关注归属哪个账户，则无须单独创建日历账户，可以直接使用默认日历账户。

    ```ts
   // Index.ets
   calendarMgr?.getCalendar().then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in getting calendar, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get calendar. Code: ${err.code}, message: ${err.message}`);
   });
    ```

8. 获取当前应用所有创建的日历账户及默认日历账户Calendar对象。

   由于涉及数据隐私安全，进行了权限管控的应用无法获取其他应用创建的账户信息。

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

9. 删除指定的日历账户，删除账户后，该账户下的所有日程会全部删除。

    ```ts
   // Index.ets
   calendarMgr?.deleteCalendar(calendar).then(() => {
     console.info("Succeeded in deleting calendar");
   }).catch((err: BusinessError) => {
     console.error(`Failed to delete calendar. Code: ${err.code}, message: ${err.message}`);
   });
    ```