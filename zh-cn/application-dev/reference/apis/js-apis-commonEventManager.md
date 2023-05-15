# @ohos.commonEventManager (公共事件模块)

本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等。

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

发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | 是   | 表示要发送的公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**错误码：**
以下错误码详细介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
//发布公共事件回调
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", publishCallBack);
} catch(err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```

## CommonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

发布公共事件指定发布信息（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | 是   | 表示发布公共事件的属性。 |
| callback | syncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|


| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**


```ts
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
	isOrdered: true	 //有序公共事件
}

//发布公共事件回调
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", options, publishCallBack);
} catch (err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

向指定用户发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | 是   | 表示要发送的公共事件。             |
| userId   | number               | 是   | 表示指定向该用户ID发送此公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。             |

**错误码：**
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**

```ts
//发布公共事件回调
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

向指定用户发布公共事件并指定发布信息（callback形式）。

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
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**示例：**


```ts
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
}

//发布公共事件回调
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, options, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

创建订阅者（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                         | 必填 | 说明                       |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | 是   | 表示订阅信息。             |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 是   | 表示创建订阅者的回调方法。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |

**示例：**


```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
    events: ["event"]
};

//创建订阅者回调
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

创建订阅者（Promise形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 参数名          | 类型                                                  | 必填 | 说明           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | 返回订阅者对象。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |

**示例：**

```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
	events: ["event"]
};

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
} catch(err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}

```



## CommonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

订阅公共事件（callback形式）。

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
| 401  | The parameter check failed.             |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
//订阅者信息
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
    events: ["event"]
};

//订阅公共事件回调
function SubscribeCallBack(err, data) {
    if (err) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe ");
    }
}

//创建订阅者回调
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCallBack);
        } catch (err) {
            console.error("createSubscriber failed " + JSON.stringify(err));
        }
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

取消订阅公共事件（callback形式）。

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
| 401  | The parameter check failed.             |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**示例：**

```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
//订阅者信息
var subscribeInfo = {
    events: ["event"]
};
//订阅公共事件回调
function subscribeCallBack(err, data) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe");
    }
}
//创建订阅者回调
function createSubscriberCallBack(err, commonEventSubscriber) {
    if (err) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, subscribeCallBack);
        } catch(err) {
            console.info("subscribe failed " + JSON.stringify(err));
        }
    }
}
//取消订阅公共事件回调
function unsubscribeCallBack(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}
//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.info("createSubscriber failed " + JSON.stringify(err));
}

//取消订阅公共事件
try {
    CommonEventManager.unsubscribe(subscriber, unsubscribeCallBack);
} catch (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
}
```

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

获取公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 公共事件的结果代码。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | The application dose not have permission to call the interface. |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not system service.                 |
| 1500007  | The message send error.             |
| 1500008  | The CEMS error.                     |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果代码回调
function getCodeCallback(err, Code) {
    if (err) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

获取公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<number> | 公共事件的结果代码。 |

**错误码：**

错误码介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201  | The application dose not have permission to call the interface. |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not system service.                 |
| 1500007  | The message send error.             |
| 1500008  | The CEMS error.                     |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

设置公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码回调
function setCodeCallback(err) {
    if (err) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

设置公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的结果代码。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

获取公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 公共事件的结果数据。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果数据回调
function getDataCallback(err, Data) {
    if (err) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(Data));
    }
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

获取公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| Promise\<string> | 公共事件的结果数据。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

设置公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setDataCallback(err) {
    if (err) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

设置公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

设置公共事件的结果代码和结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码和结果数据回调
function setCodeDataCallback(err) {
    if (err) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

设置公共事件的结果代码和结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的结果代码。 |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

查询当前公共事件的是否为有序公共事件（callback形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为有序事件的回调
function isOrderedCallback(err, isOrdered) {
    if (err) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

查询当前公共事件的是否为有序公共事件（Promise形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

检查当前公共事件是否为一个粘性事件（callback形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为粘性事件的回调
function isStickyCallback(err, isSticky) {
    if (err) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCallback);
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

检查当前公共事件是否为一个粘性事件（Promise形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 取消当前的公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//取消当前有序公共事件的回调
function abortCallback(err) {
    if (err) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

清除当前公共事件的取消状态，仅对有序公共事件有效（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//清除当前公共事件取消状态的回调
function clearAbortCallback(err) {
    if (err) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

清除当前公共事件的取消状态，仅对有序公共事件有效（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

获取当前有序公共事件是否取消的状态（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前有序公共事件是否取消的回调
function getAbortCallback(err, AbortCommonEvent) {
    if (err) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("AbortCommonEvent " + AbortCommonEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

获取当前有序公共事件是否取消的状态（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

获取订阅者的订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 是   | 表示订阅者的订阅信息。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取订阅者信息回调
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
    }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

获取订阅者的订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 表示订阅者的订阅信息。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void\>): void

结束当前有序公共事件（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                  | 必填 | 说明                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 表示有序公共事件结束后的回调函数。 |

**示例：**

```ts
var subscriber; //创建成功的订阅者对象

//结束当前有序公共事件的回调
function finishCommonEventCallback(err) {
  if (err) {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
} else {
    console.info("FinishCommonEvent");
}
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void\>

结束当前有序公共事件（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称       | 类型                 | 可读 | 可写 | 说明                                                    |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | 是  | 否  | 表示当前接收的公共事件名称。                              |
| bundleName | string               | 是  | 否  | 表示包名称。                                              |
| code       | number               | 是  | 否  | 表示公共事件的结果代码，用于传递int类型的数据。           |
| data       | string               | 是  | 否  | 表示公共事件的自定义结果数据，用于传递string类型的数据。 |
| parameters | {[key: string]: any} | 是  | 否  | 表示公共事件的附加信息。                                  |


## CommonEventPublishData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                  | 类型                 | 可读 | 可写 | 说明                         |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | 是  | 否  | 表示包名称。                   |
| code                  | number               | 是  | 否  | 表示公共事件的结果代码。       |
| data                  | string               | 是  | 否  | 表示公共事件的自定义结果数据。 |
| subscriberPermissions | Array\<string>       | 是  | 否  | 表示订阅者的权限。             |
| isOrdered             | boolean              | 是  | 否  | 表示是否是有序事件。           |
| isSticky              | boolean              | 是  | 否  | 表示是否是粘性事件。仅系统应用或系统服务允许发送粘性事件。 |
| parameters            | {[key: string]: any} | 是  | 否  | 表示公共事件的附加信息。       |

## CommonEventSubscribeInfo

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                | 类型           | 可读 | 可写 | 说明                                                         |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | 是  | 否  | 表示要发送的公共事件。                                         |
| publisherPermission | string         | 是  | 否  | 表示发布者的权限。                                             |
| publisherDeviceId   | string         | 是  | 否  | 表示设备ID，该值必须是同一ohos网络上的现有设备ID。             |
| userId              | number         | 是  | 否  | 表示用户ID。此参数是可选的，默认值当前用户的ID。如果指定了此参数，则该值必须是系统中现有的用户ID。 |
| priority            | number         | 是  | 否  | 表示订阅者的优先级。值的范围是-100到1000。                     |
