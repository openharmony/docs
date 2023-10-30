# @ohos.commonEventManager (公共事件模块)

本模块提供了公共事件相关的能力，包括发布公共事件、订阅公共事件、以及退订公共事件。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import CommonEventManager from '@ohos.commonEventManager';
```

## Support

系统公共事件是指由系统服务或系统应用发布的事件，订阅这些系统公共事件需要特定的权限。发布或订阅这些事件需要使用如下链接中的枚举定义。

全部系统公共事件枚举定义请参见[系统公共事件定义](./commonEventManager-definitions.md)。

## CommonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

发布公共事件，并在发布后执行相应的回调函数。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | 是   | 表示要发送的公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示事件发布后将要执行的回调函数。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
import Base from '@ohos.base';

//发布公共事件回调
function publishCB(err:Base.BusinessError) {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

以回调的形式发布公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | syncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
import Base from '@ohos.base';

//公共事件相关信息
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
	isOrdered: true	 //有序公共事件
}

//发布公共事件回调
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", options, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

以回调的形式向指定用户发布公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | 是   | 表示要发送的公共事件。             |
| userId   | number               | 是   | 表示指定向该用户ID发送此公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。             |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
import Base from '@ohos.base';

//发布公共事件回调
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
let userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

以回调形式向指定用户发布公共事件并指定发布信息。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| userId   | number | 是 | 表示指定向该用户ID发送此公共事件。 |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | AsyncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not System services or System app.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**


```ts
import Base from '@ohos.base';

//公共事件相关信息
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
}

//发布公共事件回调
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
let userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, options, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

以回调形式创建订阅者。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                       |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | 是   | 表示订阅信息。             |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 是   | 表示创建订阅者的回调方法。 |

**示例：**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

//创建订阅者回调
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

以Promise形式创建订阅者。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 返回订阅者对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
	events: ["event"]
};

//创建订阅者
CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err:Base.BusinessError) => {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
});

```

## CommonEventManager.createSubscriberSync<sup>10+</sup>

createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber

createSubscriber的同步接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | 返回订阅者对象。 |

**示例：**

```ts
import Base from '@ohos.base';

let subscriber: CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
let subscribeInfo: CommonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};

//创建订阅者
try {
    subscriber = CommonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriberSync failed, code is ${err.code}, message is ${err.message}`);
}

```

## CommonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

以回调形式订阅公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名       | 类型                                                | 必填 | 说明                             |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | 是   | 表示订阅者对象。                 |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | 是   | 表示接收公共事件数据的回调函数。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

//订阅公共事件回调
function SubscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe ");
    }
}

//创建订阅者回调
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCB);
        } catch (error) {
            let err:Base.BusinessError = error as Base.BusinessError;
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        }
    } else {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

以回调形式取消订阅公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名       | 类型                                             | 必填 | 说明                     |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | 是   | 表示订阅者对象。         |
| callback   | AsyncCallback\<void>                            | 否   | 表示取消订阅的回调方法。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
//订阅者信息
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};
//订阅公共事件回调
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe");
    }
}
//创建订阅者回调
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if (err) {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, subscribeCB);
        } catch (error) {
            let err:Base.BusinessError = error as Base.BusinessError;
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        }
    }
}
//取消订阅公共事件回调
function unsubscribeCB(err:Base.BusinessError) {
    if (err) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribe");
    }
}
//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}

//取消订阅公共事件
//等待异步接口subscribe执行完毕，开发者根据实际业务选择是否需要添加setTimeout
setTimeout(() => {
  try {
    CommonEventManager.unsubscribe(subscriber, unsubscribeCB);
  } catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```

## CommonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void

以回调形式移除粘性公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**需要权限**:  ohos.permission.COMMONEVENT_STICKY

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                             |
| -------- | -------------------- | ---- | -------------------------------- |
| event    | string               | 是   | 表示被移除的粘性公共事件。       |
| callback | AsyncCallback\<void> | 是   | 表示移除粘性公共事件的回调方法。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not system service.                 |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**示例：**


```ts
import Base from '@ohos.base';

CommonEventManager.removeStickyCommonEvent("sticky_event", (err:Base.BusinessError) => {
    if (err) {
        console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);
        return;
    }
    console.info(`Remove sticky event AsyncCallback success`);
});
```

## CommonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string): Promise\<void>

以Promise形式移除粘性公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**需要权限**:  ohos.permission.COMMONEVENT_STICKY

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| event  | string | 是   | 表示被移除的粘性公共事件。 |

**返回值：**

| 类型           | 说明                         |
| -------------- | ---------------------------- |
| Promise\<void> | 表示移除粘性公共事件的对象。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500004  | not system service.                 |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**示例：**


```ts
import Base from '@ohos.base';

CommonEventManager.removeStickyCommonEvent("sticky_event").then(() => {
    console.info(`Remove sticky event AsyncCallback success`);
}).catch ((err:Base.BusinessError) => {
    console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```

## CommonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean, callback: AsyncCallback\<void>): void;

方法介绍：为当前应用设置静态订阅事件使能或去使能状态。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | 是   | 表示静态订阅事件使能状态。 true:使能 false：去使能。 |
| callback  | AsyncCallback\<void> | 是   | 表示设置静态订阅事件使能状态的回调方法。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**示例：**


```ts
import Base from '@ohos.base';

CommonEventManager.setStaticSubscriberState(true, (err:Base.BusinessError) => {
    if (!err) {
        console.info(`Set static subscriber state callback failed, err is null.`);
        return;
    }
    if (err.code !== undefined && err.code != null) {
        console.info(`Set static subscriber state callback failed, errCode: ${err.code}, errMes: ${err.message}`);
        return;
    }
    console.info(`Set static subscriber state callback success`);
});
```

## CommonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean): Promise\<void>;

方法介绍：为当前应用设置静态订阅事件使能或去使能状态。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | 是   | 表示静态订阅事件使能状态。 true:使能 false：去使能。 |

**返回值：**

| 类型           | 说明                         |
| -------------- | ---------------------------- |
| Promise\<void> | 表示设置静态订阅事件使能状态的对象。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**示例：**


```ts
import Base from '@ohos.base';

CommonEventManager.setStaticSubscriberState(false).then(() => {
    console.info(`Set static subscriber state promise success`);
}).catch ((err:Base.BusinessError) => {
    console.info(`Set static subscriber state promise failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```
