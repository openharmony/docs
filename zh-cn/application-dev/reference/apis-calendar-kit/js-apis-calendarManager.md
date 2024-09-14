# @ohos.calendarManager (日程管理能力)

本模块提供日历与日程管理能力，包括日历和日程的创建、删除、修改、查询等。

- 日历管理器[CalendarManager](#calendarmanager)用于管理日历[Calendar](#calendar)。

- 日历[Calendar](#calendar)主要包含账户信息[CalendarAccount](#calendaraccount)和配置信息[CalendarConfig](#calendarconfig)。日历Calendar与日程Event属于从属关系，需要先创建日历Calendar对象，然后再通过日历Calendar创建日程Event对象，一个Calendar可以有多个Event，一个Event只属于一个Calendar。日历管理器是对日历的管理，日程过滤器是对日程的管理。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```typescript
import { calendarManager } from '@kit.CalendarKit'
```

## calendarManager.getCalendarManager

getCalendarManager(context : Context): CalendarManager

根据上下文获取CalendarManager对象，用于管理日历。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                        | 必填 | 说明                                                                                                             |
| -------- | --------------------------- | ---- |----------------------------------------------------------------------------------------------------------------|
| context  | Context                     | 是   | 应用上下文Context，Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。 |

**返回值**：

| 类型                           | 说明                                  |
| ------------------------------ | ------------------------------------- |
| CalendarManager | 返回创建的CalendarManager对象。 |

**示例**：

```typescript
// 获取上下文mContext
// 获取日历管理器calendarMgr
// 该文件为系统生成，目录：entry/src/main/ets/entryability/EntryAbility.ets
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

下列API示例中需先通过[getCalendarManager()](#calendarmanagergetcalendarmanager)方法获取CalendarManager对象，再通过此对象调用对应方法，进行Calendar的创建、删除、修改、查询等操作。


### createCalendar

createCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void

根据日历账户信息，创建一个Calendar对象，使用callback异步回调。

**需要权限**： ohos.permission.WRITE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                  | 必填 | 说明                               |
| --------------- | ------------------------------------- | ---- | ---------------------------------- |
| calendarAccount | [CalendarAccount](#calendaraccount)   | 是   | 日历账户信息。                     |
| callback        | AsyncCallback\<[Calendar](#calendar)> | 是   | 回调函数，返回创建的Calendar对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

根据日历账户信息，创建一个Calendar对象，使用Promise异步回调。

**需要权限**： ohos.permission.WRITE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                | 必填 | 说明           |
| --------------- | ----------------------------------- | ---- | -------------- |
| calendarAccount | [CalendarAccount](#calendaraccount) | 是   | 日历账户信息。 |

**返回值**：

| 类型                           | 说明                                  |
| ------------------------------ | ------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise对象，返回创建的Calendar对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

删除指定Calendar对象，使用callback异步回调。

**需要权限**： ohos.permission.WRITE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                  | 必填 | 说明           |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | 是   | 即将删除的Calendar对象。 |
| callback | AsyncCallback\<void>  | 是   | 无返回结果的AsyncCallback对象。     |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

删除指定Calendar对象，使用Promise异步回调。

**需要权限**： ohos.permission.WRITE_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                  | 必填 | 说明           |
| -------- | --------------------- | ---- | -------------- |
| calendar | [Calendar](#calendar) | 是   | 即将删除的Calendar对象。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

获取默认Calendar对象，默认Calendar是日历存储首次运行时创建的，若创建Event时不关注其Calendar归属，则无须通过[createCalendar()](#createcalendar)创建Calendar，直接使用默认Calendar，使用callback异步回调。

**需要权限**：ohos.permission.READ_CALENDAR

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                                 | 必填 | 说明                                 |
| -------- | ------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback<[Calendar](#calendar)> | 是   | 回调函数，返回查询到的Calendar对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

获取指定Calendar对象，使用callback异步回调。

**需要权限**： ohos.permission.READ_CALENDAR

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                 | 必填 | 说明                                 |
| --------------- | ------------------------------------ | ---- | ------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount)  | 是   | 日历账户信息。                       |
| callback        | AsyncCallback<[Calendar](#calendar)> | 是   | 回调函数，返回查询到的Calendar对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

获取默认Calendar对象或者指定Calendar对象，使用Promise异步回调。

**需要权限**： ohos.permission.READ_CALENDAR

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名          | 类型                                | 必填 | 说明                                                         |
| --------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| calendarAccount | [CalendarAccount](#calendaraccount) | 否   | 日历账户信息，用来获取指定Calendar对象，不填时，表示获取默认Calendar对象。 |

**返回值**：

| 类型                           | 说明                                    |
| ------------------------------ | --------------------------------------- |
| Promise<[Calendar](#calendar)> | Promise对象，返回查询到的Calendar对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

获取当前应用所有创建的Calendar对象以及默认Calendar对象，使用callback异步回调。

**需要权限**：ohos.permission.READ_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                                   | 必填 | 说明                                      |
| -------- | -------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback<[Calendar](#calendar)[]> | 是   | 回调函数， 返回查询到的Calendar对象数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

获取当前应用所有创建的Calendar对象以及默认Calendar对象，使用Promise异步回调。

**需要权限**： ohos.permission.READ_CALENDAR

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                             | 说明                                        |
| -------------------------------- | ------------------------------------------- |
| Promise<[Calendar](#calendar)[]> | Promise对象，返回查询到的Calendar对象数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 201      | Permission denied.  |
| 401      | Parameter error. Possible causes: Incorrect parameter types.  |
| 801      | Capability not supported.  |

**示例**：

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

创建单个日程，入参Event不填日程id，调用该接口会跳转到日程创建页面，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明        |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | 是   | Event对象。 |

**返回值**：

| 类型           | 说明                                                                          |
| -------------- |-----------------------------------------------------------------------------|
| Promise&lt;number&gt; | Promise对象，返回日程的id，日程id是日程的唯一标识符，是数据库的自增主键，小于0代表日程创建失败，大于0代表日程创建成功，没有等于0的情况。 |

**示例**：

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

下列API示例中需先通过[createCalendar()](#createcalendar)、[getCalendar()](#getcalendar)中任一方法获取Calendar对象，再通过此对象调用对应方法，对该Calendar下的日程进行创建、删除、修改、查询等操作。

### 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称 | 类型   | 只读 | 可选 | 说明                                                                       |
| ---- | ------ | ---- |----|--------------------------------------------------------------------------|
| id   | number | 是   | 否  | 日历账户id，日历账户id是日历账户的唯一标识符，是数据库的自增主键，小于0代表日历账户创建失败，大于0代表日历账户创建成功，没有等于0的情况。 |

### addEvent

addEvent(event: Event, callback: AsyncCallback\<number>): void

创建日程，入参Event不填日程id，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                                    |
| -------- | ---------------------- | ---- |-----------------------------------------------------------------------|
| event    | [Event](#event)        | 是   | Event对象。                                                              |
| callback | AsyncCallback\<number> | 是   | 回调函数，返回日程id，日程id是日程的唯一标识符，是数据库的自增主键，小于0代表日程创建失败，大于0代表日程创建成功，没有等于0的情况。 |

**示例**：

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

创建日程，入参Event不填日程id，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明        |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | 是   | Event对象。 |

**返回值**：

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<number> | Promise对象，返回日程的id。 |

**示例**：

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

批量创建日程，入参Event不填日程id，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                 | 必填 | 说明            |
| -------- | -------------------- | ---- | --------------- |
| events   | [Event](#event)[]    | 是   | Event对象数组。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。      |

**示例**：

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

批量创建日程，入参Event不填日程id，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型              | 必填 | 说明            |
| ------ | ----------------- | ---- | --------------- |
| events | [Event](#event)[] | 是   | Event对象数组。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

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

删除指定id的日程，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                 | 必填 | 说明                                     |
| -------- | -------------------- | ---- |----------------------------------------|
| id       | number               | 是   | 日程id，传入的日程id为正整数，表示已创建日程的id，是日程的唯一标识符。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。                                  |

**示例**：

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
          console.info(`Succeeded in deleting event, err -> ${JSON.stringify(err)}`);
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

删除指定id的日程，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| id     | number | 是   | 日程id。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

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

根据日程id，批量删除日程，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                 | 必填 | 说明         |
| -------- | -------------------- | ---- | ------------ |
| ids      | number[]             | 是   | 日程id数组。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。   |

**示例**：

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

根据日程id，批量删除日程，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | 是   | 日程id数组。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

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

更新日程，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                 | 必填 | 说明        |
| -------- | -------------------- | ---- | ----------- |
| event    | [Event](#event)      | 是   | Event对象。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。  |

**示例**：

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

更新日程，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型            | 必填 | 说明        |
| ------ | --------------- | ---- | ----------- |
| event  | [Event](#event) | 是   | Event对象。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

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

查询当前日历下所有日程，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                             | 必填 | 说明                              |
| -------- | -------------------------------- | ---- | --------------------------------- |
| callback | AsyncCallback<[Event](#event)[]> | 是   | 回调函数，返回的是Event对象数组。 |

**示例**：

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

获取Calendar下符合查询条件的Event，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名      | 类型                             | 必填 | 说明                              |
| ----------- | -------------------------------- | ---- | --------------------------------- |
| eventFilter | [EventFilter](#eventfilter)      | 是   | 查询条件。                        |
| eventKey    | (keyof [Event](#event))[]        | 是   | 查询字段。                        |
| callback    | AsyncCallback<[Event](#event)[]> | 是   | 回调函数，返回的是Event对象数组。 |

**示例**：

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

获取Calendar下符合查询条件的Event，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名      | 类型                        | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---------- |
| eventFilter | [EventFilter](#eventfilter) | 否   | 查询条件。 |
| eventKey    | (keyof [Event](#event))[]   | 否   | 查询字段。 |

**返回值**：

| 类型                       | 说明                                |
| -------------------------- | ----------------------------------- |
| Promise<[Event](#event)[]> | Promise对象，返回的是Event对象数组。 |

**示例**：

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

获取日历配置信息。

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                              | 说明           |
| --------------------------------- | -------------- |
| [CalendarConfig](#calendarconfig) | 日历配置信息。 |

**示例**：

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

设置日历配置信息，使用callback异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名   | 类型                              | 必填 | 说明           |
| -------- | --------------------------------- | ---- | -------------- |
| config   | [CalendarConfig](#calendarconfig) | 是   | 日历配置信息。 |
| callback | AsyncCallback\<void>              | 是   | 回调函数。     |

**示例**：

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

设置日历配置信息，使用Promise异步回调。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型                              | 必填 | 说明           |
| ------ | --------------------------------- | ---- | -------------- |
| config | [CalendarConfig](#calendarconfig) | 是   | 日历配置信息。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

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

获取日历账户信息。

**系统能力**： SystemCapability.Applications.CalendarData

**返回值**：

| 类型                                | 说明           |
| ----------------------------------- | -------------- |
| [CalendarAccount](#calendaraccount) | 日历账户信息。 |

**示例**：

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

日历账户信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                          | 只读 | 可选 | 说明                               |
| ----------- | ----------------------------- | ---- |----|----------------------------------|
| name        | string                        | 是   | 否  | 账户名称（面向开发者）。                     |
| type        | [CalendarType](#calendartype) | 否   | 否  | 账户类型。                            |
| displayName | string                        | 否   | 是  | 账户显示在日历应用上的名称（面向用户）。不填时，默认为空字符串。 |

## CalendarConfig

日历配置信息。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称           | 类型     | 只读    | 可选 | 说明                                                         |
| -------------- |--------|-------|----| ------------------------------------------------------------ |
| enableReminder | boolean | 否     | 是  | 是否打开Calendar下所有Event提醒能力。当取值为true时，该Calendar下所有Event具备提醒能力；当取值为false时，不具备提醒能力，默认具备提醒能力。 |
| color          | number \| string | 否   | 是  | 设置Calendar颜色。不填时，默认值为'#0A59F7'。                |

## Event

日程对象，包含日程标题、开始时间、结束时间等信息。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称           | 类型                              | 只读 | 可选 | 说明                                                                                                                                                                                                      |
| -------------- | --------------------------------- | ---- |----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| id             | number                            | 否   | 是  | 日程id。当调用[addEvent()](#addevent)、[addEvents()](#addevents)创建日程时，不填写此参数。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                            |
| type           | [EventType](#eventtype)           | 否   | 否  | 日程类型。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                            |
| title          | string                            | 否   | 是  | 日程标题。不填时，默认为空字符串。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                |
| location       | [Location](#location)             | 否   | 是  | 日程地点。不填时，默认为null。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                |
| startTime      | number                            | 否   | 否  | 日程开始时间，需要13位时间戳。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                   |
| endTime        | number                            | 否   | 否  | 日程结束时间，需要13位时间戳。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                  |
| isAllDay       | boolean                           | 否   | 是  | 是否为全天日程。当取值为true时，说明为全天日程；当取值为false时，说明不是全天日程，默认为非全天日程。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                           |
| attendee       | [Attendee](#attendee)[]           | 否   | 是  | 会议日程参与者。不填时，默认为null。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                              |
| timeZone       | string                            | 否   | 是  | 日程时区。不填时，默认为当前所在时区，当需要创建与当前不一样的时区时，可填入对应的时区。可通过[getTimeZone()](../apis-basic-services-kit/js-apis-date-time.md#systemdatetimegettimezone)获取当前系统时区。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| reminderTime   | number[]                          | 否   | 是  | 日程提醒时间，单位为分钟。填写x分钟，即距开始时间提前x分钟提醒，不填时，默认为不提醒。为负值时表示延期多长时间提醒。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                        |
| recurrenceRule | [RecurrenceRule](#recurrencerule) | 否   | 是  | 日程重复规则。不填时，默认为不重复。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                               |
| description    | string                            | 否   | 是  | 日程描述。不填时，默认为空字符串。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                 |
| service        | [EventService](#eventservice)     | 否   | 是  | 日程服务。不填时，默认没有一键服务。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                               |
| identifier<sup>12+</sup>     | string                            | 否   | 是  | 写入方可指定日程唯一标识。不填时，默认为null。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                         |
| isLunar<sup>12+</sup>     | boolean                            | 否   | 是  | 是否为农历日程。当取值为true时，说明为农历日程；当取值为false时，说明不是农历日程，默认为非农历日程。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                           |

## CalendarType

账户类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称       | 值           | 说明                 |
| ---------- | ------------ | -------------------- |
| LOCAL      | 'local'      | 本地账户。           |
| EMAIL      | 'email'      | 邮箱账户。           |
| BIRTHDAY   | 'birthday'   | 生日账户。           |
| CALDAV     | 'caldav'     | 支持CalDAV协议账户。 |
| SUBSCRIBED | 'subscribed' | 订阅账户。           |

## Location

日程地点。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 类型   | 只读 | 可选 | 说明                     |
| --------- | ------ | ---- |----| ------------------------ |
| location  | string | 否   | 是  | 地点位置。默认为空字符串。 |
| longitude | number | 否   | 是  | 地点经度。默认为0。        |
| latitude  | number | 否   | 是  | 地点纬度。默认为0。        |

## EventFilter

日程过滤器，查询日程时进行筛选过滤，获取符合条件的日程。

通过[filterById()](#filterbyid)、[filterByTime()](#filterbytime)、[filterByTitle()](#filterbytitle)任一方法获取日程过滤器，传入[getEvents()](#getevents)过滤。

### filterById

static filterById(ids: number[]): EventFilter

根据日程id过滤日程。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| ids    | number[] | 是   | 日程id数组。 |

**返回值**：

| 类型                        | 说明                 |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤器对象。 |

**示例**：

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

根据日程时间过滤日程。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| start  | number | 是   | 开始时间。 |
| end    | number | 是   | 结束时间。 |

**返回值**：

| 类型                        | 说明                 |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤器对象。 |

**示例**：

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

根据日程标题过滤日程。

**系统能力**： SystemCapability.Applications.CalendarData

**参数**：

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| title  | string | 是   | 日程标题。 |

**返回值**：

| 类型                        | 说明                 |
| --------------------------- | -------------------- |
| [EventFilter](#eventfilter) | 返回日程过滤器对象。 |

**示例**：

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

日程类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称      | 值   | 说明                      |
| --------- | ---- |-------------------------|
| NORMAL    | 0    | 普通日程，例如会议，闹钟等日常提醒的日程。   |
| IMPORTANT | 1    | 重要日程，例如结婚纪念日等具有重要意义的日期。 |

## RecurrenceRule

日程重复规则。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称                | 类型                                        | 只读 | 可选 | 说明                                                                                                                                                                                                                                                                                                                              |
| ------------------- | ------------------------------------------- | ---- |----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| recurrenceFrequency | [RecurrenceFrequency](#recurrencefrequency) | 否   | 否  | 日程重复规则类型。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                 |
| expire              | number                                      | 否   | 是  | 重复周期截止日。不填时，默认为0。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                        |
| count<sup>12+</sup>               | number                                      | 否   | 是  | 重复日程的重复次数，取值为非负整数，不填时默认为0，表示不会限定重复次数，会一直重复，取值为负时，效果等同于取值为0。当count与expire同时存在时以count为准。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                     |
| interval<sup>12+</sup>            | number                                      | 否   | 是  | 重复日程的重复间隔，取值为非负整数，不填时默认为0，表示日程按照重复规则一直重复，没有间隔。取值为负时，效果等同于取值为0。当interval与expire同时存在时以expire为准。 <br/>此属性与recurrenceFrequency重复规则相关，不同的重复规则下，表示的重复间隔不同，以interval取2为例，分为以下几种情况：<br/>每天重复时：表示日程每隔两天重复一次。<br/>每周重复时：表示日程每隔两周重复一次。<br/>每月重复时：表示日程每隔两月重复一次。<br/>每年重复时：表示日程每隔两年重复一次。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| excludedDates<sup>12+</sup>       | number[]                                    | 否   | 是  | 重复日程的排除日期，参数取值为时间戳格式，不填时，默认为空，表示没有排除的日期，0或负数为无效值，与空值效果相同。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                 |
| daysOfWeek<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一周第几天重复。不填时，默认为空，表示没有一周第几天重复的规则。范围为1到7，对应周一到周日，其他值为无效值，与空值效果相同。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                         |
| daysOfMonth<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一个月第几天重复。不填时，默认为空，表示没有一个月第几天重复的规则。范围为1到31，1到31对应1到31号，其他值为无效值，与空值效果相同。若当月没有31号，31也为无效值。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                  |
| daysOfYear<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一年第几天重复。不填时，默认为空，表示没有一年第几天重复的规则。范围为1到366，1到366表示一年的1到366天，其他值为无效值，与空值效果相同。若当年没有366天，366也为无效值。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                            |
| weeksOfMonth<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一个月第几周重复。不填时，默认为空，表示没有一个月第几周重复的规则。范围为1到5，1到5为每月的第1到第5周，其他值为无效值，与空值效果相同。若当月没有第五周，5也为无效值。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                  |
| weeksOfYear<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一年中第几周重复。不填时，默认为空，表示没有一年第几周重复的规则。范围为1到53，1到53为每年的第1到第53周，其他值为无效值，与空值效果相同。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                |
| monthsOfYear<sup>12+</sup>       | number[]                                    | 否   | 是  | 按照一年中第几个月重复。不填时，默认为空，表示没有一年第几个月重复的规则。范围为1到12，1到12为每年的1到12月，其他值为无效值，与空值效果相同。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                |
## RecurrenceFrequency

日程重复规则类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称    | 值   | 说明       |
| ------- | ---- | ---------- |
| YEARLY  | 0    | 每年重复。 |
| MONTHLY | 1    | 每月重复。 |
| WEEKLY  | 2    | 每周重复。 |
| DAILY   | 3    | 每天重复。 |

## Attendee

会议日程参与者。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称  | 类型   | 只读 | 可选 | 说明                                                                 |
| ----- | ------ | ---- |----|--------------------------------------------------------------------|
| name  | string | 否   | 否  | 会议日程参与者的姓名。  <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| email | string | 否   | 否  | 会议日程参与者的邮箱。   <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| role<sup>12+</sup>  | [AttendeeRole](#attendeerole12) | 否   | 是  | 会议日程参与者的角色。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |

## EventService

日程服务。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称        | 类型                        | 只读 | 可选 | 说明                                  |
| ----------- | --------------------------- | ---- |----| ------------------------------------- |
| type        | [ServiceType](#servicetype) | 否   | 否  | 服务类型。                            |
| uri         | string                      | 否   | 否  | 服务的uri。可以跳转到三方应用相应界面。 |
| description | string                      | 否   | 是  | 服务辅助描述。不填时，默认为空字符串。  |

## ServiceType

日程服务类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称            | 值               | 说明         |
| --------------- | ---------------- | ------------ |
| MEETING         | 'Meeting'        | 一键入会。   |
| WATCHING        | 'Watching'       | 一键追剧。   |
| REPAYMENT       | 'Repayment'      | 一键还款。   |
| LIVE            | 'Live'           | 一键直播。   |
| SHOPPING        | 'Shopping'       | 一键购物。   |
| TRIP            | 'Trip'           | 一键查看。   |
| CLASS           | 'Class'          | 一键上课。   |
| SPORTS_EVENTS   | 'SportsEvents'   | 一键看赛事。 |
| SPORTS_EXERCISE | 'SportsExercise' | 一键运动。   |

## AttendeeRole<sup>12+</sup>

会议日程参与者角色类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.CalendarData

| 名称           | 值             | 说明     |
|--------------|---------------|--------|
| ORGANIZER<sup>12+</sup>    | 'organizer'   | 会议组织者。 |
| PARTICIPANT<sup>12+</sup>  | 'participant' | 会议参与者。 |