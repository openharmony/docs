# @ohos.commonEventManager (公共事件模块)(系统应用)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本模块提供了公共事件相关的系统接口能力，包括发布公共事件到指定用户、移除[粘性公共事件](../../basic-services/common-event/common-event-glossary.md#sticky-common-event粘性公共事件)以及设置[静态订阅](../../basic-services/common-event/common-event-glossary.md#static-subscription静态订阅)公共事件的使能状态。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[CommonEventManager](./js-apis-commonEventManager.md)。

## 导入模块

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
```

## Support

[系统公共事件](../../basic-services/common-event/common-event-glossary.md#system-common-event系统公共事件)是指由系统服务或系统应用发布的事件，订阅这些系统公共事件需要特定的权限。发布或订阅这些事件需要使用如下链接中的枚举定义。

全部系统公共事件枚举定义请参见[系统定义的公共事件](./common_event/commonEventManager-definitions-sys.md)。

## commonEventManager.publishAsUser

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

向指定用户发布公共事件。使用callback异步回调。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | 是   | 表示要发布的公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions-sys.md)。             |
| userId   | number               | 是   | 表示指定接收此公共事件的用户ID。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当公共事件发布成功，err为undefined，否则为错误对象。             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 1500003  | The common event sending frequency too high.<br> 适用版本：20+ |
| 1500006  | Invalid userId.<br> 适用版本：21+ |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 指定发送的用户
let userId = 100;

// 发布公共事件
try {
    commonEventManager.publishAsUser('event', userId, (err: BusinessError) => {
      if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('publishAsUser');
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

向指定用户发布公共事件并指定发布信息。使用callback异步回调。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions-sys.md)。  |
| userId   | number | 是 | 表示指定接收此公共事件的用户ID。 |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | AsyncCallback\<void>   | 是   | 回调函数。当公共事件发布成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 1500003  | The common event sending frequency too high.<br> 适用版本：20+ |
| 1500006  | Invalid userId.<br> 适用版本：21+ |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 公共事件相关信息
let options: commonEventManager.CommonEventPublishData = {
  code: 0,       // 公共事件的初始代码
  data: 'initial data', // 公共事件的初始数据
};

// 指定发送的用户
let userId = 100;
// 发布公共事件
try {
  commonEventManager.publishAsUser('event', userId, options, (err: BusinessError) => {
    if (err) {
      console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('publishAsUser');
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void

移除[粘性公共事件](../../basic-services/common-event/common-event-glossary.md#sticky-common-event粘性公共事件)。使用callback异步回调。

**系统能力：** SystemCapability.Notification.CommonEvent

**需要权限**：ohos.permission.COMMONEVENT_STICKY

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                             |
| -------- | -------------------- | ---- | -------------------------------- |
| event    | string               | 是   | 表示被移除的粘性公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions-sys.md)。       |
| callback | AsyncCallback\<void> | 是   | 回调函数。当移除粘性公共事件成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |  
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      |   
| 1500004  | A third-party application cannot send system common events.                |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.removeStickyCommonEvent('sticky_event', (err: BusinessError) => {
  if (err) {
    console.error(`removeStickyCommonEvent failed, errCode: ${err.code}, errMsg: ${err.message}`);
    return;
  }
  console.info(`removeStickyCommonEvent success`);
});
```

## commonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string): Promise\<void>

移除已发布的[粘性公共事件](../../basic-services/common-event/common-event-glossary.md#sticky-common-event粘性公共事件)。使用Promise异步回调。

**系统能力：** SystemCapability.Notification.CommonEvent

**需要权限**：ohos.permission.COMMONEVENT_STICKY

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| event  | string | 是   | 表示被移除的粘性公共事件。详见[系统定义的公共事件](./common_event/commonEventManager-definitions.md)。 |

**返回值：**

| 类型           | 说明                         |
| -------------- | ---------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |  
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 
| 1500004  | A third-party application cannot send system common events.                |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.removeStickyCommonEvent('sticky_event').then(() => {
  console.info(`removeStickyCommonEvent success`);
}).catch((err: BusinessError) => {
  console.error(`removeStickyCommonEvent failed, errCode: ${err.code}, errMsg: ${err.message}`);
});
```

## commonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean, callback: AsyncCallback\<void>): void

为当前应用设置[静态订阅](../../basic-services/common-event/common-event-glossary.md#static-subscription静态订阅)事件使能或去使能状态。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | 是   | 表示静态订阅事件使能状态。true：使能，false：去使能。 |
| callback  | AsyncCallback\<void> | 是   | 回调函数。当设置静态订阅事件使能状态成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.setStaticSubscriberState(true, (err: BusinessError) => {
  if (err.code != 0) {
    console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMsg: ${err.message}`);
    return;
  }
  console.info(`setStaticSubscriberState success`);
});
```

## commonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean): Promise\<void>

为当前应用设置[静态订阅](../../basic-services/common-event/common-event-glossary.md#static-subscription静态订阅)事件使能或去使能状态。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | 是   | 表示静态订阅事件使能状态。true：使能，false：去使能。 |

**返回值：**

| 类型           | 说明                         |
| -------------- | ---------------------------- |
| Promise\<void> |  Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**示例：**


```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.setStaticSubscriberState(false).then(() => {
  console.info(`setStaticSubscriberState success`);
}).catch((err: BusinessError) => {
  console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMsg: ${err.message}`);
});
```

## commonEventManager.setStaticSubscriberState<sup>12+</sup>

setStaticSubscriberState(enable: boolean, events?: Array\<string>): Promise\<void>

设置当前应用的[静态订阅](../../basic-services/common-event/common-event-glossary.md#static-subscription静态订阅)公共事件的使能状态。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Notification.CommonEvent

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型          | 必填 | 说明                                                 |
| ------ | ------------- | ---- | ---------------------------------------------------- |
| enable | boolean       | 是   | 表示静态订阅事件使能状态。true：使能，false：去使能。|
| events | Array\<string> | 否   | 表示需要设置的公共事件名称列表，默认为空列表，表示设置当前应用所有的静态订阅公共事件状态。                                  |

**返回值：**

| 类型           | 说明                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[公共事件错误码](./errorcode-CommonEventService.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API.                     |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.      | 
| 1500007  | Failed to send the message to the common event service.        |
| 1500008  | Failed to initialize the common event service. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let eventName: string[] = ['usual.event.SEND_DATA'];
commonEventManager.setStaticSubscriberState(true, eventName).then(() => {
  console.info(`setStaticSubscriberState success`);
}).catch((err: BusinessError) => {
  console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMsg: ${err.message}`);
});
```
