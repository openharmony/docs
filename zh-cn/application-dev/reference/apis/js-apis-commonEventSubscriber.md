# 公共事件的订阅者

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

获取公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 描述               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 公共事件的结果代码 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
getCode() {
function getCodeCallback(err, Code) {
    if (err.code) {
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

**示例：**

```js
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

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setCodeCallback(err) {
    if (err.code) {
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

| 参数名 | 类型   | 必填 | 描述               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的结果代码 |

**示例：**

```js
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

| 参数名   | 类型                   | 必填 | 描述                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 公共事件的结果数据。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function getDataCallback(err, Data) {
    if (err.code) {
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
| Promise\<string> | 公共事件的结果数据 |

**示例：**

```js
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

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的结果数据   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setDataCallback(err) {
    if (err.code) {
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

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的结果数据。 |

**示例：**

```js
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

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setCodeDataCallback(err) {
    if (err.code) {
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

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的结果代码。 |
| data   | string | 是   | 公共事件的结果数据。 |

**示例：**

```js
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

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为有序公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function isOrderedCallback(err, isOrdered) {
    if (err.code) {
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
| Promise\<boolean> | 当前公共事件的是否为有序公共事件 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 取消当前的公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function abortCallback(err) {
    if (err.code) {
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

**示例：**

```js
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

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function clearAbortCallback(err) {
    if (err.code) {
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

**示例：**

```js
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

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 表示当前有序公共事件是否取消的状态 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function getAbortCallback(err, AbortCommonEvent) {
    if (err.code) {
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
| Promise\<boolean> | 表示当前有序公共事件是否取消的状态 |

**示例：**

```js
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

| 参数名   | 类型                                                         | 必填 | 描述                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 是   | 表示订阅者的订阅信息。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err.code) {
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

```js
var subscriber;	//创建成功的订阅者对象

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent

finishCommonEvent(callback: AsyncCallback\<void\>): void

结束当前已排序的公共事件（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                  | 必填 | 描述                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 表示排序的公共事件结束后的回调函数。 |

**示例：**

```js
var subscriber; //创建成功的订阅者对象

function finishCommonEventCallback() {
  console.log("--------- finishCommonEventCallback ----------");
}

subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent

finishCommonEvent(): Promise\<void\>

结束当前已排序的公共事件（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.finishCommonEvent()
  .then(() => {
    console.info("--------- finishCommonEventCallback ----------");
  })
```