# @ohos.commonEventManager (公共事件模块)

本模块提供了公共事件相关的能力，包括发布公共事件、订阅公共事件、以及退订公共事件。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
```

## Support

系统公共事件是指由系统服务或系统应用发布的事件，订阅这些公共事件需要特定的权限、使用相应的值，详见[系统定义的公共事件](./common_event/commonEventManager-definitions.md)。

## commonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

发布公共事件。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | 是   | 表示要发送的公共事件。详见[系统公共事件定义](./common_event/commonEventManager-definitions.md)。 |
| callback | AsyncCallback\<void> | 是   | 表示事件发布后将要执行的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 发布公共事件回调
function publishCB(err: BusinessError) {
  if (err) {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("publish success");
  }
}
// 发布公共事件
try {
  commonEventManager.publish("event", publishCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

发布公共事件。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。详见[系统公共事件定义](./common_event/commonEventManager-definitions.md)。  |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | syncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 公共事件相关信息
let options:commonEventManager.CommonEventPublishData = {
  code: 0,			 // 公共事件的初始代码
  data: "initial data",// 公共事件的初始数据
  isOrdered: true	 // 有序公共事件
}
// 发布公共事件回调
function publishCB(err: BusinessError) {
  if (err) {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("publish success");
  }
}
// 发布公共事件
try {
  commonEventManager.publish("event", options, publishCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

创建订阅者。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                       |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | 是   | 表示订阅信息。             |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 是   | 表示创建订阅者的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber:commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}
// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

创建订阅者。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 以Promise形式返回订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber:commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// 创建订阅者
commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:commonEventManager.CommonEventSubscriber) => {
  console.info("createSubscriber success");
  subscriber = commonEventSubscriber;
}).catch((err: BusinessError) => {
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
});
```

## commonEventManager.createSubscriberSync<sup>10+</sup>

createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber

createSubscriber的同步接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | 返回订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber: commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// 创建订阅者
try {
  subscriber = commonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriberSync failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

订阅公共事件。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名       | 类型                                                | 必填 | 说明                             |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | 是   | 表示订阅者对象。                 |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | 是   | 表示接收公共事件数据的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber:commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// 订阅公共事件回调
function SubscribeCB(err: BusinessError, data:commonEventManager.CommonEventData) {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success, Consume callback " + JSON.stringify(data));
  }
}
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
    // 订阅公共事件
    try {
      commonEventManager.subscribe(subscriber, SubscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}
// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

取消订阅公共事件。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名       | 类型                                             | 必填 | 说明                     |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | 是   | 表示订阅者对象。         |
| callback   | AsyncCallback\<void>                            | 否   | 表示取消订阅的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber:commonEventManager.CommonEventSubscriber; 
// 订阅者信息
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// 订阅公共事件回调
function subscribeCB(err: BusinessError, data:commonEventManager.CommonEventData) {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success, Consume callback " + JSON.stringify(data));
  }
}
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if (err) {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
    // 订阅公共事件
    try {
      commonEventManager.subscribe(subscriber, subscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}
// 取消订阅公共事件回调
function unsubscribeCB(err: BusinessError) {
  if (err) {
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("unsubscribe success");
  }
}
// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}

// 取消订阅公共事件
// 等待异步接口subscribe执行完毕，开发者根据实际业务选择是否需要添加setTimeout
setTimeout(() => {
  try {
    commonEventManager.unsubscribe(subscriber, unsubscribeCB);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```
