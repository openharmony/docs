# @ohos.commonEvent (公共事件模块)(系统应用)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等，适用于系统服务或应用间通过公共事件进行通信通知的场景，能够帮助开发者实现跨应用的事件发布与订阅，提升应用间的协同效率。

> **说明：**
>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[@ohos.commonEventManager](js-apis-commonEventManager.md)替代。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[CommonEvent](./js-apis-commonEvent.md)。

## 导入模块

```ts
import commonEvent from '@ohos.commonEvent';
```

## Support

系统公共事件是指由系统服务或系统应用发布的事件，订阅这些系统公共事件需要相应的权限。发布或订阅这些事件需要使用如下链接中的枚举定义。

全部系统公共事件枚举定义请参见[系统公共事件定义](./common_event/commonEvent-definitions.md)。

## commonEvent.publishAsUser<sup>(deprecated)</sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

以回调的形式向指定用户发布公共事件。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[commonEventManager.publishAsUser](js-apis-commonEventManager-sys.md#commoneventmanagerpublishasuser)替代。

**系统能力：** `SystemCapability.Notification.CommonEvent`

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | 是   | 表示要发布的公共事件。             |
| userId   | number               | 是   | 表示指定向该用户ID发布此公共事件。 |
| callback | AsyncCallback\<void> | 是   | 公共事件发布结果的回调方法。             |

**示例：**

```ts
import Base from '@ohos.base';

// 发布公共事件回调
let publishCallBack = (err:Base.BusinessError) => {
    if (err.code) {
        console.error(`Failed to publishAsUser. Code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('publishAsUser');
    }
}

// 指定发送的用户
const userId = 100;

// 发布公共事件
commonEvent.publishAsUser('event', userId, publishCallBack);
```

## commonEvent.publishAsUser<sup>(deprecated)</sup>

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

以回调形式向指定用户发布公共事件并指定发布信息。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[commonEventManager.publishAsUser](js-apis-commonEventManager-sys.md#commoneventmanagerpublishasuser-1)替代。

**系统能力：** `SystemCapability.Notification.CommonEvent`

**系统接口**：此接口为系统接口。

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| userId   | number | 是 | 表示指定向该用户ID发布此公共事件。 |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | AsyncCallback\<void>   | 是   | 公共事件发布结果的回调方法。  |

**示例：**


```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

// 公共事件相关信息
let options:CommonEventManager.CommonEventPublishData = {
    code: 0,              // 公共事件的初始代码
    data: 'initial data', // 公共事件的初始数据
};

// 发布公共事件回调
let publishCallBack = (err:Base.BusinessError) => {
    if (err.code) {
        console.error(`Failed to publishAsUser. Code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('publishAsUser');
    }
}

// 指定发送的用户
let userId = 100;

// 发布公共事件
commonEvent.publishAsUser('event', userId, options, publishCallBack);
```
