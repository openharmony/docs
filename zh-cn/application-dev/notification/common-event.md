# 公共事件开发指导
## 简介
OpenHarmony通过CES（Common Event Service，公共事件服务）为应用程序提供订阅、发布、退订公共事件的能力。

公共事件可分为系统公共事件和自定义公共事件。

+ 系统公共事件：系统将收集到的事件信息，根据系统策略发送给订阅该事件的用户程序。 例如：系统关键服务发布的系统事件（例如：hap安装，更新，卸载等）。

+ 自定义公共事件：应用自定义一些公共事件用来实现跨应用的事件通信能力。

每个应用都可以按需订阅公共事件，订阅成功且公共事件发布，系统会把其发送给应用。这些公共事件可能来自系统、其他应用和应用自身。

## 公共事件订阅开发指导

### 场景介绍
当需要订阅某个公共事件，获取某个公共事件传递的参数时，可以创建一个订阅者对象，用于作为订阅公共事件的载体，订阅公共事件并获取公共事件传递而来的参数。订阅部分系统公共事件需要先申请权限，订阅这些事件所需要的权限请见[公共事件权限列表](../reference/apis/js-apis-commonEvent.md#权限列表)。

### 接口说明
| 接口名                                                                                          | 接口描述 |
| ---------------------------------------------------------------------------------------------- | ----------- |
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback) | 创建订阅者对象(callback) |
| createSubscriber(subscribeInfo: CommonEventSubscribeInfo)                          | 创建订阅者对象(promise)  |
| subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback)              | 订阅公共事件 |

### 开发步骤
1. 导入CommonEvent模块。

```js
import commonEvent from '@ohos.commonEvent';
```

2. 创建订阅者信息，详细的订阅者信息数据类型及包含的参数请见[CommonEventSubscribeInfo文档](../reference/apis/js-apis-commonEvent.md#commoneventsubscribeinfo)介绍。

```js
//用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
private subscriber = null

//订阅者信息
var subscribeInfo = {
    events: ["event"],
}
```

3. 创建订阅者，保存返回的订阅者对象subscriber，用于执行后续的订阅、退订等操作。

```js
//创建订阅者回调
commonEvent.createSubscriber(subscribeInfo, (err, subscriber) => {
    if (err.code) {
        console.error("[CommonEvent]CreateSubscriberCallBack err=" + JSON.stringify(err))
    } else {
        console.log("[CommonEvent]CreateSubscriber")
        this.subscriber = subscriber
        this.result = "Create subscriber succeed"
    }
})
```

4. 创建订阅回调函数，订阅回调函数会在接收到事件时触发。订阅回调函数返回的data内包含了公共事件的名称、发布者携带的数据等信息，公共事件数据的详细参数和数据类型请见[CommonEventData文档](../reference/apis/js-apis-commonEvent.md#commoneventdata)介绍。

```js
//订阅公共事件回调
if (this.subscriber != null) {
    commonEvent.subscribe(this.subscriber, (err, data) => {
        if (err.code) {
            console.error("[CommonEvent]SubscribeCallBack err=" + JSON.stringify(err))
        } else {
            console.log("[CommonEvent]SubscribeCallBack data=" + JSON.stringify(data))
            this.result = "receive, event = " + data.event + ", data = " + data.data + ", code = " + data.code
        }
    })
    this.result = "Subscribe succeed"
} else {
    prompt.showToast({ message: "Need create subscriber" })
}
```

## 公共事件发布开发指导

### 场景介绍
当需要发布某个自定义公共事件时，可以通过此方法发布事件。发布的公共事件可以携带数据，供订阅者解析并进行下一步处理。

### 接口说明
| 接口名                              | 接口描述 |
| ---------------------------------- | ------ |
| publish(event: string, callback: AsyncCallback) | 发布公共事件 |
| publish(event: string, options: CommonEventPublishData, callback: AsyncCallback) | 指定发布信息并发布公共事件 |

### 开发步骤
#### 发布公共事件开发步骤
1. 导入CommonEvent模块。

```js
import commonEvent from '@ohos.commonEvent';
```

2. 传入需要发布的事件名称和回调函数，发布事件。

```js
//发布公共事件
commonEvent.publish("event", (err) => {
    if (err.code) {
        console.error("[CommonEvent]PublishCallBack err=" + JSON.stringify(err))
    } else {
        console.info("[CommonEvent]Publish1")
    }
})
```

#### 指定发布信息发布公共事件的开发步骤
1. 导入CommonEvent模块。

```js
import commonEvent from '@ohos.commonEvent'
```

2. 定义发布事件时需要指定的发布信息，发布信息所包含的详细参数及其参数类型请见[CommonEventPublishData文档](../reference/apis/js-apis-commonEvent.md#commoneventpublishdata)介绍。

```js
//公共事件相关信息
var options = {
    code: 1,			 //公共事件的初始代码
    data: "initial data",//公共事件的初始数据
}
```

3. 传入需要发布的事件名称、需要发布的指定信息和回调函数，发布事件。

```js
//发布公共事件
commonEvent.publish("event", options, (err) => {
    if (err.code) {
        console.error("[CommonEvent]PublishCallBack err=" + JSON.stringify(err))
    } else {
        console.info("[CommonEvent]Publish2")
    }
})
```

## 公共事件取消订阅开发指导

### 场景介绍
订阅者需要取消已订阅的某个公共事件时，可以通过此方法取消订阅事件。

### 接口说明
| 接口名                              | 接口描述 |
| ---------------------------------- | ------ |
| unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback) | 取消订阅公共事件 |

### 开发步骤
1. 导入CommonEvent模块。

```js
import commonEvent from '@ohos.commonEvent';
```

2. 根据[公共事件订阅指导](#公共事件订阅开发指导)的步骤来订阅某个事件。
3. 调用CommonEvent中的unsubscribe方法取消订阅某事件。

```js
if (this.subscriber != null) {
    commonEvent.unsubscribe(this.subscriber, (err) => {
        if (err.code) {
            console.error("[CommonEvent]UnsubscribeCallBack err=" + JSON.stringify(err))
        } else {
            console.log("[CommonEvent]Unsubscribe")
            this.subscriber = null
            this.result = "Unsubscribe succeed"
        }
    })
}
```

## 相关实例

针对公共事件开发，有以下相关实例可供参考：

- [`CommonEvent`：订阅公共事件（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/Notification/CommonEvent)


