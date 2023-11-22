# @ohos.calendarManager    
本模块提供日历与日程管理能力，包括日历和日程的创建、删除、修改、查询等。日历管理器[CalendarManager](#calendarmanager)用于管理日历[Calendar](#calendar)。日历[Calendar](#calendar)主要包含帐户信息[CalendarAccount](#calendaraccount)和配置信息[CalendarConfig](#calendarconfig)。日历Calendar与日程Event属于一对多关系，一个Calendar可以有多个Event，一个Event只属于一个Calendar。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import calendarManager from '@ohos.calendarManager'    
```  
    
## getCalendarManager    
根据上下文获取CalendarManager对象，用于管理日历。  
 **调用形式：**     
- getCalendarManager(context: Context) : CalendarManager  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文Context，Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CalendarManager |  |  
    
 **示例代码：**   
```ts    
// 获取context  
  // 以下代码中的class EntryAbility extends UIAbility，onWindowStageCreate在工程main/ets/entryability/EntryAbility.ets中，测试ohosTest/ets/testability/TestAbility.ets中有，可直接使用  
  import UIAbility from '@ohos.app.ability.UIAbility';  
  import common from '@ohos.app.ability.common';  
  import window from '@ohos.window';  
  
  export let mContext : common.UIAbilityContext | null = null;  
  class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage: window.WindowStage){  
      mContext = this.context;  
    }  
  }  
  let calendarMgr:calendarManager.CalendarManager = calendarManager.getCalendarManager(mContext as Context);  
    
```    
  
    
## CalendarManager    
下列API示例中需先通过[getCalendarManager()](#calendarmanagergetcalendarmanager)方法获取CalendarManager对象，再通过此对象调用对应方法，进行Calendar的创建、删除、修改、查询等操作。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### createCalendar    
根据日历帐户信息，创建一个Calendar对象，使用callback异步回调。  
 **调用形式：**     
    
- createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar>    
起始版本： 10    
- createCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData  
 **需要权限：** ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| calendarAccount | CalendarAccount | true | 日历帐户信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回创建的Calendar对象。 |  
| Promise<Calendar> | Promise对象，返回创建的Calendar对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let calendar : calendarManager.Calendar | undefined = undefined;  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
删除指定Calendar对象，使用callback异步回调。  
 **调用形式：**     
    
- deleteCalendar(calendar: Calendar): Promise\<void>    
起始版本： 10    
- deleteCalendar(calendar: Calendar, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData  
 **需要权限：** ohos.permission.WRITE_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| calendar | Calendar | true | Calendar对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
获取默认Calendar对象，默认Calendar是日历存储首次运行时创建的，若创建Event时不关注其Calendar归属，则无须通过[createCalendar()](#createcalendar)创建Calendar，直接使用默认Calendar，使用callback异步回调。  
 **调用形式：**     
    
- getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar>    
起始版本： 10    
- getCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void    
起始版本： 10    
- getCalendar(callback: AsyncCallback\<Calendar>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData  
 **需要权限：** ohos.permission.READ_CALENDAR or ohos.permission.READ_WHOLE_CALENDAR    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| calendarAccount | CalendarAccount | false | 日历帐户信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的Calendar对象。 |  
| Promise<Calendar> | Promise对象，返回查询到的Calendar对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let calendar : calendarManager.Calendar | undefined = undefined;  
calendarMgr.getCalendar().then((data: calendarManager.Calendar) => {  
  console.info(`Succeeded in getting calendar data->${JSON.stringify(data)}`);  
  calendar = data;  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get calendar: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
### getAllCalendars    
获取当前应用所有创建的Calendar对象以及默认Calendar对象，使用callback异步回调。  
 **调用形式：**     
    
- getAllCalendars(): Promise\<Calendar[]>    
起始版本： 10    
- getAllCalendars(callback: AsyncCallback\<Calendar[]>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData  
 **需要权限：** ohos.permission.READ_CALENDAR or ohos.permission.WRITE_WHOLE_CALENDAR    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数， 返回查询到的Calendar对象数组。 |  
| Promise<Calendar[]> | Promise对象，返回查询到的Calendar对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
下列API示例中需先通过[createCalendar()](#createcalendar)、[getCalendar()](#getcalendar)中任一方法获取Calendar对象，再通过此对象调用对应方法，对该Calendar下的日程进行创建、删除、修改、查询等操作。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | true | true | 帐户id。 |  
    
### addEvent    
创建日程，入参[Event](#event)不填日程id，使用callback异步回调。  
 **调用形式：**     
    
- addEvent(event: Event): Promise\<number>    
起始版本： 10    
- addEvent(event: Event, callback: AsyncCallback\<number>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | Event | true | Event对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回日程id。 |  
| Promise<number> | Promise对象，返回日程的id。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
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
批量创建日程，入参[Event](#event)不填日程id，使用callback异步回调。  
 **调用形式：**     
    
- addEvents(events: Event[]): Promise\<void>    
起始版本： 10    
- addEvents(events: Event[], callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| events | Event[] | true | Event对象数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
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
删除指定id的日程，使用callback异步回调。  
 **调用形式：**     
    
- deleteEvent(id: number): Promise\<void>    
起始版本： 10    
- deleteEvent(id: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true | 日程id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
calendar.deleteEvent(1).then(() => {  
  console.info("Succeeded in deleting event");  
}).catch((err: BusinessError) => {  
  console.error("Failed to delete event");  
});  
    
```    
  
    
### deleteEvents    
根据日程id，批量删除日程，使用callback异步回调。  
 **调用形式：**     
    
- deleteEvents(ids: number[]): Promise\<void>    
起始版本： 10    
- deleteEvents(ids: number[], callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ids | number[] | true | 日程id数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
calendar.deleteEvents([1, 2]).then(() => {  
  console.info("Succeeded in deleting events");  
}).catch((err: BusinessError) => {  
  console.error("Failed to delete events");  
});  
    
```    
  
    
### updateEvent    
更新日程，使用callback异步回调。  
 **调用形式：**     
    
- updateEvent(event: Event): Promise\<void>    
起始版本： 10    
- updateEvent(event: Event, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | Event | true | Event对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
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
查询Calendar下所有Event，使用callback异步回调。  
 **调用形式：**     
    
- getEvents(eventFilter?: EventFilter, eventKey?: (keyof Event)[]): Promise\<Event[]>    
起始版本： 10    
- getEvents(eventFilter: EventFilter, eventKey: (keyof Event)[], callback: AsyncCallback\<Event[]>):void    
起始版本： 10    
- getEvents(callback: AsyncCallback\<Event[]>):void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventFilter | EventFilter | false | 查询条件。 |  
| eventKey | (keyof Event)[] | false | 查询字段。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回的是Event对象数组。 |  
| Promise<Event[]> | Promise对象，返回日程配置信息数组。 |  
    
 **示例代码1：**   
示例（callback）：  
  
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
  
    
 **示例代码2：**   
示例（promise）：  
  
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
获取日历配置信息。  
 **调用形式：**     
- getConfig(): CalendarConfig  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CalendarConfig | 日历配置信息。 |  
    
 **示例代码：**   
```ts    
const config = calendar.getConfig();console.info("get config success");    
```    
  
    
### setConfig    
设置日历配置信息，使用callback异步回调。  
 **调用形式：**     
    
- setConfig(config: CalendarConfig): Promise\<void>    
起始版本： 10    
- setConfig(config: CalendarConfig, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | CalendarConfig | true | 日历配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
```null    
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
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
const config: calendarManager.CalendarConfig = {  
  enableReminder: true  
};  
calendar.setConfig(config).then(() => {  
  console.info("Succeeded in setting config");  
}).catch((err: BusinessError) => {  
  console.error("Failed to set config");  
});  
    
```    
  
    
### getAccount    
获取日历账户信息。  
 **调用形式：**     
- getAccount(): CalendarAccount  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CalendarAccount | 日历帐户信息。 |  
    
 **示例代码：**   
```ts    
const account = calendar.getAccount();console.info("get account success");    
```    
  
    
## CalendarAccount    
日历帐户信息。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | true | true | 帐户名称。 |  
| type | CalendarType | false | true | 帐户类型。 |  
| displayName | string | false | false | 帐户的显示名称。不填时，默认为空字符串。 |  
    
## CalendarConfig    
日历配置信息。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| enableReminder | boolean | false | false | 是否打开Calendar下所有Event提醒能力。当取值为true时，该Calendar下所有Event具备提醒能力；当取值为false时，不具备提醒能力，默认具备提醒能力。 |  
| color | number \| string | false | false | 设置Calendar颜色。不填时，默认值为'#0A59F7'。  |  
    
## Event    
日程对象，包含日程标题、开始时间、结束时间等信息。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | false | false | 日程id。当调用[addEvent()](#addevent)、[addEvents()](#addevents)创建日程时，不填写此参数。 |  
| type | EventType | false | true | 日程类型。 |  
| title | string | false | false | 日程标题。不填时，默认为空字符串。 |  
| location | Location | false | false | 日程地点。不填时，默认为null。 |  
| startTime | number | false | true | 日程开始时间。 |  
| endTime | number | false | true | 日程结束时间。 |  
| isAllDay | boolean | false | false | 是否为全天日程。当取值为true时，说明为全天日程；当取值为false时，说明不是全天日程，默认为非全天日程。 |  
| attendee | Attendee[] | false | false | 日程参与者。不填时，默认为null。 |  
| timeZone | string | false | false | 日程时区。不填时，默认为当前所在时区，当需要创建与当前不一样的时区时，可填入对应的时区。可通过[getTimeZone()](js-apis-system-date-time.md#systemdatetimegettimezone)获取当前系统时区。 |  
| reminderTime | number[] | false | false | 日程提醒时间。不填时，默认为不提醒。 |  
| recurrenceRule | RecurrenceRule | false | false | 日程重复规则。不填时，默认为不重复。 |  
| description | string | false | false | 日程描述。不填时，默认为空字符串。 |  
| service | EventService | false | false | 日程服务。不填时，默认没有一键服务。 |  
    
## CalendarType    
帐户类型枚举。    
    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOCAL | local | 本地帐户。 |  
| EMAIL | email | 邮箱帐户。 |  
| BIRTHDAY | birthday | 生日帐户。 |  
| CALDAV | caldav | 支持CalDAV协议帐户。 |  
| SUBSCRIBED | subscribed | 订阅帐户。 |  
    
## Location    
日程地点。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| location | string | false | false | 地点位置。默认为空字符串。 |  
| longitude | number | false | false | 地点经度。默认为0。 |  
| latitude | number | false | false | 地点经度。默认为0。 |  
    
## EventFilter    
日程过滤器，查询日程时进行筛选过滤，获取符合条件的日程。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### filterById    
根据日程id过滤日程。  
 **调用形式：**     
- static filterById(ids: number[]): EventFilter  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ids | number[] | true | 日程id数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| EventFilter | 返回日程过滤器对象。 |  
    
 **示例代码：**   
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
根据日程时间过滤日程。  
 **调用形式：**     
- static filterByTime(start: number, end: number): EventFilter  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| start | number | true | 开始时间。 |  
| end | number | true | 结束时间。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| EventFilter |  |  
    
 **示例代码：**   
```null    
import { BusinessError } from '@ohos.base';  
  
const filter = calendarManager.EventFilter.filterByTime(1686931200000, 1687017600000);  
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {  
  console.info("Succeeded in filtering by time");  
}).catch((err: BusinessError) => {  
  console.error("Failed to filter by time");  
});  
    
```    
  
    
### filterByTitle    
根据日程标题过滤日程。  
 **调用形式：**     
- static filterByTitle(title: string): EventFilter  
  
 **系统能力:**  SystemCapability.Applications.CalendarData    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| title | string | true | 日程标题。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| EventFilter | 返回日程过滤器对象。 |  
    
 **示例代码：**   
```null    
import { BusinessError } from '@ohos.base';  
  
const filter = calendarManager.EventFilter.filterByTitle('MyEvent');  
calendar.getEvents(filter).then((data: calendarManager.Event[]) => {  
  console.info("Succeeded in filtering by title");  
}).catch((err: BusinessError) => {  
  console.error("Failed to filter by title");  
});  
    
```    
  
    
## EventType    
日程类型枚举。    
    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NORMAL | 0 | 普通日程。 |  
| IMPORTANT | 1 | 重要日程。支持倒计时。 |  
    
## RecurrenceRule    
日程重复规则。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| recurrenceFrequency | RecurrenceFrequency | false | true | 日程重复规则类型。 |  
| expire | number | false | false | 重复周期截止日。不填时，默认为0。 |  
    
## RecurrenceFrequency    
日程重复规则类型枚举。    
    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| YEARLY | 0 | 每年重复。 |  
| MONTHLY | 1 | 每月重复。 |  
| WEEKLY | 2 | 每周重复。 |  
| DAILY | 3 | 每天重复。 |  
    
## Attendee    
日程参与者。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 参与者的姓名。 |  
| email | string | false | true | 参与者的邮箱。 |  
    
## EventService    
日程服务。  
 **系统能力:**  SystemCapability.Applications.CalendarData    
### 属性    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ServiceType | false | true | 服务类型。 |  
| uri | string | false | true | 服务的uri。可以跳转到三方应用相应界面。 |  
| description | string | false | false | 服务辅助描述。不填时，默认为空字符串。 |  
    
## ServiceType    
日程服务类型枚举。    
    
 **系统能力:**  SystemCapability.Applications.CalendarData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MEETING | Meeting | 一键入会。 |  
| WATCHING | Watching | 一键追剧。 |  
| REPAYMENT | Repayment | 一键直播。 |  
| LIVE | Live | 一键直播。 |  
| SHOPPING | Shopping | 一键购物。 |  
| TRIP | Trip | 一键查看。 |  
| CLASS | Class | 一键上课。 |  
| SPORTS_EVENTS | SportsEvents | 一键看赛事。 |  
| SPORTS_EXERCISE | SportsExercise | 一键运动。 |  
