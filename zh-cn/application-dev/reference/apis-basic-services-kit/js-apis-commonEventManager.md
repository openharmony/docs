# @ohos.commonEventManager (公共事件模块)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本模块提供公共事件的发布、订阅、取消订阅等能力。公共事件是一种系统级的事件通知机制，允许应用在系统状态变化（如开机完成、电量变化、屏幕亮灭等）或业务自定义事件发生时，向订阅了该事件的应用发送通知，实现跨组件、跨应用的信息传递。

本模块涉及的关键概念：
- [无序公共事件](../../basic-services/common-event/common-event-glossary.md#unordered-common-event无序公共事件)：CES在转发公共事件时，不考虑订阅者是否接收到该事件，也不保证订阅者接收到该事件的顺序与其订阅顺序一致。
- [有序公共事件](../../basic-services/common-event/common-event-glossary.md#ordered-common-event有序公共事件)：CES在转发公共事件时，根据订阅者设置的优先级等级，优先将公共事件发送给优先级较高的订阅者，等待其成功接收该公共事件之后再将事件发送给优先级较低的订阅者。如果有多个订阅者具有相同的优先级，则他们将随机接收到公共事件。
- [粘性公共事件](../../basic-services/common-event/common-event-glossary.md#sticky-common-event粘性公共事件)：能够让订阅者收到在订阅前已经发送的公共事件就是粘性公共事件。普通的公共事件只能在订阅后发送才能收到，而粘性公共事件的特殊性就是可以先发送后订阅，同时也支持先订阅后发送。发送粘性公共事件必须是系统应用或系统服务。

**API 组合使用关系说明：**

本模块的事件通信遵循三条组合调用链：订阅流、发布流与有序事件流。其中订阅流与发布流通过事件名称关联，发布者与订阅者无需感知对方存在。

**订阅流：创建订阅者 → 注册订阅 → 接收事件 → 取消订阅**

1. 配置订阅者信息，声明订阅的事件名称，可选设置订阅优先级、发布方权限与包名。
2. 通过`commonEventManager.createSubscriberSync`创建订阅者对象。
3. 通过`commonEventManager.subscribe`注册订阅，事件发布时通过回调接收`CommonEventData`，在回调中处理事件数据。
4. 不再需要时，通过`commonEventManager.unsubscribe`取消订阅。

**发布流：发布事件（可选携带数据与属性）**

1. 简单发布：通过`commonEventManager.publish`仅指定事件名发布事件。
2. 携带数据与属性发布：通过`CommonEventPublishData`配置code、data、parameters及`isOrdered`等属性，再调用`publish`发布。

**有序事件流：按优先级顺序投递 + 订阅者协作**

1. 通过`CommonEventPublishData`将`isOrdered`设为`true`，调用`publish`发布有序事件，事件按订阅者优先级依次投递。
2. 高优先级订阅者先收到事件，可在回调中通过`setCodeAndData`等方法修改code与data数据，供后续订阅者接收。
3. 处理完成后调用`finishCommonEvent`，触发事件向下一优先级订阅者投递；若需中止后续投递，可调用`abortCommonEvent`标记事件为中止状态。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
```

## Support

[系统公共事件](../../basic-services/common-event/common-event-glossary.md#system-common-event系统公共事件)是指由系统服务或系统应用发布的事件，订阅这些公共事件需要特定的权限，并使用相应的事件值，详见[系统定义的公共事件](./common_event/commonEventManager-definitions.md)。

## commonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

发布公共事件。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | 是   | 表示要发布的公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions.md)。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当公共事件发布成功时，err为undefined；发布失败时，err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- | 
| 1500003  | The common event sending frequency too high.<br> 适用版本：20+ |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 发布公共事件
try {
  commonEventManager.publish('event', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in publishing common event.`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
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
| event    | string                 | 是   | 表示要发布的公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions.md)。  |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | AsyncCallback\<void>   | 是   | 回调函数。当公共事件发布成功时，err为undefined；发布失败时，err为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1500003  | The common event sending frequency too high.<br> 适用版本：20+ |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 公共事件相关信息，以发布有序公共事件为例
let options: commonEventManager.CommonEventPublishData = {
  code: 0,
  data: 'initial data',
  isOrdered: true // 有序公共事件
};

// 发布公共事件
try {
  commonEventManager.publish('event', options, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in publishing common event.`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
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
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1)> | 是   | 回调函数，用于接收创建的订阅者对象。当公共事件订阅者创建成功时，err为undefined，data为创建成功的CommonEventSubscriber订阅者对象；创建失败时，err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.    | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if (!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1)> | Promise对象，返回创建成功的订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};
// 创建订阅者
commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
  console.info(`Succeeded in creating subscriber.`);
  subscriber = commonEventSubscriber;
}).catch((err: BusinessError) => {
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
});
```

## commonEventManager.createSubscriberSync<sup>10+</sup>

createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber

同步创建订阅者的接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1) | 返回订阅者对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};
// 创建订阅者
try {
  subscriber = commonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1)     | 是   | 表示订阅者对象。                 |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | 是   | 回调函数。当公共事件订阅成功后，事件触发时通过data返回公共事件数据；订阅失败时，err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 801  | Capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500010  | The count of subscriber exceeds system specification. <br> 适用版本：20+|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if (!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // 订阅公共事件
        try {
          commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
            if (err) {
              console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
              return;
            }
            console.info(`Succeeded in subscribing, data is ${JSON.stringify(data)}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1) | 是   | 表示订阅者对象。         |
| callback   | AsyncCallback\<void>                            | 否   | 回调函数。当取消公共事件订阅成功时，err为undefined；取消失败时，err为错误对象。不传该参数时，默认取消订阅且不返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 
| 801  | Capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if (!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // 订阅公共事件
        try {
          commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
            if (err) {
              console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
              return;
            }
            console.info(`Succeeded in subscribing, data is ${JSON.stringify(data)}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}

// 取消订阅公共事件
// 等待异步接口subscribe执行完毕，开发者根据实际业务选择是否需要添加setTimeout
setTimeout(() => {
  try {
    commonEventManager.unsubscribe(subscriber, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to unsubscribe. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      // subscriber不再使用时需要将其置为null，避免内存泄露
      subscriber = null;
      console.info(`Succeeded in unsubscribing.`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to unsubscribe. Code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```

## commonEventManager.subscribeToEvent<sup>20+</sup>

subscribeToEvent(subscriber: CommonEventSubscriber, callback: Callback\<CommonEventData>): Promise\<void>

订阅公共事件，并返回订阅成功或失败信息。使用Promise异步回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名       | 类型                                                | 必填 | 说明                             |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1)     | 是   | 表示订阅者对象。                 |
| callback   | Callback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | 是   | 表示接收公共事件数据的回调函数。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<void>   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            | 
| -------- | ----------------------------------- |
| 801  | Capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500010  | The count of subscriber exceeds system specification. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及取消订阅的动作
let subscriber: commonEventManager.CommonEventSubscriber | null = null;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// 创建订阅者
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if (err) {
        console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // 订阅公共事件
        try {
          commonEventManager.subscribeToEvent(subscriber, (data: commonEventManager.CommonEventData) => {
            console.info(`Succeeded to receive common event, data is ${JSON.stringify(data)}`);
          }).then(() => {
            console.info(`Succeeded in subscribing.`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
      }
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventData<sup>10+</sup>

type CommonEventData = _CommonEventData

描述公共事件的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

| 类型 | 说明 |
| --- | --- |
| [_CommonEventData](js-apis-inner-commonEvent-commonEventData.md) | 表示公共事件的数据。 |

## CommonEventSubscriber<sup>10+</sup>

type CommonEventSubscriber = _CommonEventSubscriber

描述公共事件的订阅者。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

| 类型 | 说明 |
| --- | --- |
| [_CommonEventSubscriber](js-apis-inner-commonEvent-commonEventSubscriber.md#commoneventsubscriber-1) | 描述公共事件的订阅者。 |

## CommonEventSubscribeInfo<sup>10+</sup>

type CommonEventSubscribeInfo = _CommonEventSubscribeInfo

描述公共事件订阅者的信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

| 类型 | 说明 |
| --- | --- |
| [_CommonEventSubscribeInfo](js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 用于表示订阅者的信息。 |

## CommonEventPublishData<sup>10+</sup>

type CommonEventPublishData = _CommonEventPublishData

描述公共事件内容和属性。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Notification.CommonEvent

| 类型 | 说明 |
| --- | --- |
| [_CommonEventPublishData](js-apis-inner-commonEvent-commonEventPublishData.md) | 描述公共事件内容和属性。 |

