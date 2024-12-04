# 日程管理

日程指特定的事件或者活动安排，日程管理即对这些事件、活动进行规划和控制，能更有效地利用相关资源、提高生产力和效率，使人们更好地管理时间和任务。

Calendar Kit中的日程[Event](../reference/apis-calendar-kit/js-apis-calendarManager.md#event)归属于某个对应的日历账户[Calendar](../reference/apis-calendar-kit/js-apis-calendarManager.md#calendar)，一个日历账户下可以有多个日程，一个日程只属于一个Calendar。

获取到日历账户对象之后，即可对该账户下的日程进行管理，包括日程的创建、删除、修改、查询等操作。在创建、修改日程时，支持对日程的标题、开始时间、结束时间、日程类型、日程地点、日程提醒时间、日程重复规则等相关信息进行设置，以便进行更丰富更有效的日程管理。

## 接口说明

以下是日程管理的相关接口，更多详细接口及使用请参考[@ohos.calendarManager](../reference/apis-calendar-kit/js-apis-calendarManager.md)。

| 接口名称                                                     | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getCalendarManager(context : Context): CalendarManager       | 根据上下文获取CalendarManager对象，用于管理日历。            |
| createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar> | 根据日历账户信息，创建一个Calendar对象，使用Promise异步回调。 |
| addEvent(event: Event): Promise\<number>                     | 创建日程，入参Event不填日程id，使用Promise异步回调。         |
| editEvent(event: Event): Promise\<number>                    | 创建单个日程，入参Event不填日程id，调用该接口会跳转到日程创建页面，使用Promise异步回调。 |
| deleteEvent(id: number): Promise\<void>                      | 删除指定日程id的日程，使用Promise异步回调。                  |
| updateEvent(event: Event): Promise\<void>                    | 更新日程，使用Promise异步回调。                              |
| getEvents(eventFilter?: EventFilter, eventKey?: (keyof Event)[]): Promise\<Event[]> | 获取Calendar下符合查询条件的Event，使用Promise异步回调。     |

## 开发步骤

1. 导入相关依赖。

   ```ts
   // entry/src/main/ets/entryability/EntryAbility.ets
   import {abilityAccessCtrl,AbilityConstant, common, PermissionRequestResult, Permissions, UIAbility, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarManager } from '@kit.CalendarKit';
   import { window } from '@kit.ArkUI';
   ```

2. 申请权限。使用Calendar Kit时，需要在module.json5中声明申请读写日历日程所需的权限：`ohos.permission.READ_CALENDAR`和`ohos.permission.WRITE_CALENDAR`。具体指导可见[声明权限](../security/AccessToken/declare-permissions.md)。

3. 根据上下文获取日程管理器对象calendarMgr，用于对日历账户进行相关管理操作。推荐在`EntryAbility.ets`文件中进行操作。

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

4. 根据日历账户信息创建Calendar对象，用于进行日程管理。设置日历配置信息，可以根据需要打开日程提醒、设置日历账户颜色。

   ```ts
   // Index.ets
   import { BusinessError } from '@kit.BasicServicesKit';
   import { calendarMgr } from '../entryability/EntryAbility';
   import { calendarManager } from '@kit.CalendarKit';
   
   let calendar: calendarManager.Calendar | undefined = undefined;
   // 指定日历账户信息
   const calendarAccount: calendarManager.CalendarAccount = {
     name: 'MyCalendar',
     type: calendarManager.CalendarType.LOCAL,
     // 日历账户显示名称，该字段如果不填，创建的日历账户在界面显示为空字符串。
     displayName: 'MyCalendar'
   };
   // 日历配置信息
   const config: calendarManager.CalendarConfig = {
     // 打开日程提醒
     enableReminder: true,
     // 设置日历账户颜色
     color: '#aabbcc'
   };
   // 创建日历账户
   calendarMgr?.createCalendar(calendarAccount).then((data: calendarManager.Calendar) => {
     console.info(`Succeeded in creating calendar data->${JSON.stringify(data)}`);
     calendar = data;
     // 请确保日历账户创建成功后，再进行相关日程的管理
   
     // 设置日历配置信息，打开日程提醒、设置日历账户颜色
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

5. 在当前日历账户下添加日历日程，注意入参中不需要填写日程id。

   创建日程时，支持设置日程的标题、开始时间、结束时间、日程类型、日程地点、日程提醒时间、日程重复规则等相关信息。

   日程创建成功后会返回一个日程id，作为日程的唯一标识，后续可按照日程id进行指定日程的更新或删除。

   目前支持以下两种方式来创建日程。

   方式一：可以在日历账户下通过`addEvent()`或`addEvents()`接口创建日程。其中可使用`addEvent()`接口创建单个日程，也可以使用`addEvents()`接口批量创建日程，此处以创建单个日程为例。

   方式二：在获取到日历管理器对象后，可通过`editEvent()`接口创建单个日程。调用此接口创建日程时，会跳转到日程创建页面，在日程创建页面进行相关操作完成日程的创建, `editEvent()`不支持自定义周期性日程创建。

   ```ts
   // Index.ets
   let eventId : number | undefined = undefined;
   const date = new Date();
   const event: calendarManager.Event = {
     // 日程标题
     title: 'title',
     // 日程类型，不推荐三方开发者使用calendarManager.EventType.IMPORTANT，重要日程类型不支持一键服务跳转功能及无法自定义提醒时间
     type: calendarManager.EventType.NORMAL,
     // 日程开始时间
     startTime: date.getTime(),
     // 日程结束时间
     endTime: date.getTime() + 60 * 60 * 1000,
     // 距开始时间提前10分钟提醒
     reminderTime: [10],
     // 日程重复规则，可选属性。如果日程为周期性日程需要填写该属性。
     recurrenceRule: {
       // 日程重复规则类型，支持按天、按周、按月、按年重复
       recurrenceFrequency: calendarManager.RecurrenceFrequency.DAILY,
       // 日程重复次数，该字段和expire属性只需要填写一个，如果两个都填写按照count属性计算。
       count: 100,
       // 重复日程间隔时间，与recurrenceFrequency相关，此示例表示日程每隔2天进行重复。
       interval: 2,
       // 日程过期时间，该字段和count属性只需要填写一个，如果两个都填写按照count属性计算。
       expire: date.getTime() + 60 * 60 * 1000 * 3,
       // 日程排除日期，将该日期从重复日程中排除掉
       excludedDates: [date.getTime() + 60 * 60 * 1000 * 2]
     },
     // 日程服务，可选字段，需要一键服务功能的日程，填写该属性。
     service: {
       // 服务类型，比如一键查看、一键入会、一键追剧等。
       type: calendarManager.ServiceType.TRIP,
       // 服务的uri。可以跳转到三方应用相应界面，格式为deeplink。使用deeplink方式需要在华为HAG云侧进行注册，注册提供的信息为应用包名、应用的服务类型。
       // deeplink包括scheme、host、path以及参数（不包含参数值）
       uri: 'xxx://xxx.xxx.com/xxx',
       // 服务辅助描述信息，可选字段
       description: '一键服务'
     }
   
   };
   // 方式一
   calendar.addEvent(event).then((data: number) => {
     console.info(`Succeeded in adding event, id -> ${data}`);
     eventId = data;
   }).catch((err: BusinessError) => {
     console.error(`Failed to addEvent. Code: ${err.code}, message: ${err.message}`);
   });
   // 方式二
    const eventInfo: calendarManager.Event = {
     // 日程标题
     title: 'title',
     // 日程类型
     type: calendarManager.EventType.NORMAL,
     // 日程开始时间
     startTime: date.getTime(),
     // 日程结束时间
     endTime: date.getTime() + 60 * 60 * 1000
   };
   calendarMgr?.editEvent(eventInfo).then((id: number): void => {
     console.info(`create Event id = ${id}`);
     eventId = id;
   }).catch((err: BusinessError) => {
     console.error(`Failed to create Event. Code: ${err.code}, message: ${err.message}`);
   });
   ```

6. 按照日程id进行指定日程的更新，更新日程相关信息。

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

7. 查询当前日历账户下的所有日程。由于涉及数据隐私安全，进行了权限管控的应用无法获取其他创建的日程信息。根据不同的查询条件和查询字段，返回不同的查询结果。

   当没有查询条件和查询字段时，可查询指定日历账户下的所有日程。
   ```ts
   calendar.getEvents().then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   还支持根据日程id、日程开始和结束时间、日程标题等查询条件来查询日程。
   ```ts
   // 根据日程id查询
   const filterId = calendarManager.EventFilter.filterById([eventId]);
   calendar.getEvents(filterId).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   
   // 根据日程标题查询
   const filterTitle = calendarManager.EventFilter.filterByTitle('update');
   calendar.getEvents(filterTitle).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to get events. Code: ${err.code}, message: ${err.message}`);
   });
   
   // 根据日程开始和结束时间查询
   const filterTime = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);
   calendar.getEvents(filterTime).then((data: calendarManager.Event[]) => {
     console.info(`Succeeded in getting events filter by time, data -> ${JSON.stringify(data)}`);
   }).catch((err: BusinessError) => {
     console.error(`Failed to filter by time. Code: ${err.code}, message: ${err.message}`);
   });
   ```

8. 按照日程id进行指定日程的删除。可以通过`deleteEvent()`接口进行单个日程的删除，也可以通过`deleteEvents()`接口批量删除指定日程，此处以删除单个指定日程为例。

   ```ts
   // Index.ets
   calendar.deleteEvent(eventId).then(() => {
      console.info("Succeeded in deleting event");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete event. Code: ${err.code}, message: ${err.message}`);
   });
   ```
