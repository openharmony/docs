# CommonEventSubscriber

## getCode

```ts
getCode(callback: AsyncCallback<number>): void
```

以回调形式获取公共事件代码。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                   | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number\> | 是   | 公共事件代码。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取有序公共事件代码回调
function getCodeCB(err, code) {
    if (err.code) {
        console.error(`getCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getCode " + JSON.stringify(code));
    }
}
subscriber.getCode(getCodeCB);
```

## getCode

```ts
getCode(): Promise<number>
```

以Promise形式获取公共事件代码。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<number> | 公共事件代码。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.getCode().then((code) => {
    console.info("getCode " + JSON.stringify(code));
}).catch((err) => {
    console.error(`getCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCode

```ts
setCode(code: number, callback: AsyncCallback<void>): void
```

以回调形式设置公共事件的代码。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的代码。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//设置有序公共事件的代码回调
function setCodeCB(err) {
    if (err.code) {
        console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCB);
```

## setCode

```ts
setCode(code: number): Promise<void>
```

以Promise形式设置公共事件的代码。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的代码。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## getData

```ts
getData(callback: AsyncCallback<string>): void
```

以回调形式获取公共事件的数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 公共事件的数据。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取有序公共事件代码数据回调
function getDataCB(err, data) {
    if (err.code) {
        console.error(`getData failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getData " + JSON.stringify(data));
    }
}
subscriber.getData(getDataCB);
```

## getData

```ts
getData(): Promise<string>
```

以Promise形式获取公共事件的数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| Promise\<string> | 公共事件的数据。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.getData().then((data) => {
    console.info("getData " + JSON.stringify(data));
}).catch((err) => {
    console.error(`getData failed, code is ${err.code}, message is ${err.message}`);
});
```

## setData

setData(data: string, callback: AsyncCallback\<void>): void

以回调形式设置公共事件的数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setDataCB(err) {
    if (err.code) {
        console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCB);
```

## setData

```ts
setData(data: string): Promise<void>
```

以Promise形式设置公共事件的果数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCodeAndData

```ts
setCodeAndData(code: number, data: string, callback:AsyncCallback<void>): void
```

以回调形式设置公共事件代码和数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的代码。   |
| data     | string               | 是   | 公共事件的数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//设置有序公共事件的代码和数据回调
function setCodeDataCB(err) {
    if (err.code) {
        console.error(`setCodeAndData failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCB);
```

## setCodeAndData

```ts
setCodeAndData(code: number, data: string): Promise<void>
```

以Promise形式设置公共事件的代码和数据。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的代码。 |
| data   | string | 是   | 公共事件的数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.error(`setCodeAndData failed, code is ${err.code}, message is ${err.message}`);
});
```

## isOrderedCommonEvent

```ts
isOrderedCommonEvent(callback: AsyncCallback<boolean>): void
```

以回调形式查询当前公共事件的是否为有序公共事件。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为有序事件的回调
function isOrderedCB(err, isOrdered) {
    if (err.code) {
        console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCB);
```

## isOrderedCommonEvent

```ts
isOrderedCommonEvent(): Promise<boolean>
```

以Promise形式查询当前公共事件的是否为有序公共事件。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error(`isOrdered failed, code is ${err.code}, message is ${err.message}`);
});
```

## isStickyCommonEvent

```ts
isStickyCommonEvent(callback: AsyncCallback<boolean>): void
```

以回调形式检查当前公共事件是否为一个粘性事件。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为粘性事件的回调
function isStickyCB(err, isSticky) {
    if (err.code) {
        console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCB);
```

## isStickyCommonEvent

```ts
isStickyCommonEvent(): Promise<boolean>
```

以Promise形式检查当前公共事件是否为一个粘性事件。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error(`isSticky failed, code is ${err.code}, message is ${err.message}`);
});
```

## abortCommonEvent

```ts
abortCommonEvent(callback: AsyncCallback<void>): void
```

以回调形式取消当前的有序公共事件，取消后，有序公共事件不再向下一个订阅者传递。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 取消当前的有序公共事件。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//取消当前有序公共事件的回调
function abortCB(err) {
    if (err.code) {
		console.error(`abortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCB);
```

## abortCommonEvent

```ts
abortCommonEvent(): Promise<void>
```

以Promise形式取消当前的有序公共事件，取消后，公共事件不再向下一个订阅者传递。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error(`abortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## clearAbortCommonEvent

```ts
clearAbortCommonEvent(callback: AsyncCallback<void>): void
```

以回调形式清除当前有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//清除当前公共事件取消状态的回调
function clearAbortCB(err) {
    if (err.code) {
        console.error(`clearAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCB);
```

## clearAbortCommonEvent

```ts
clearAbortCommonEvent(): Promise<void>
```

以Promise形式清除当前有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error(`clearAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getAbortCommonEvent

```ts
getAbortCommonEvent(callback: AsyncCallback<boolean>): void
```

以回调形式获取当前有序公共事件是否取消的状态。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取当前有序公共事件是否取消的回调
function getAbortCB(err, abortEvent) {
    if (err.code) {
        console.error(`getAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("abortCommonEvent " + abortEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCB);
```

## getAbortCommonEvent

```ts
getAbortCommonEvent(): Promise<boolean>
```

以Promise形式获取当前有序公共事件是否取消的状态。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.getAbortCommonEvent().then((abortEvent) => {
    console.info("abortCommonEvent " + JSON.stringify(abortEvent));
}).catch((err) => {
    console.error(`getAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getSubscribeInfo

```ts
getSubscribeInfo(callback: AsyncCallback<CommonEventSubscribeInfo>): void
```

以回调形式获取订阅者的订阅信息。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | 是   | 表示订阅者的订阅信息。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

//获取订阅者信息回调
function getCB(err, subscribeInfo) {
    if (err.code) {
        console.error(`getSubscribeInfo failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
    }
}
subscriber.getSubscribeInfo(getCB);
```

## getSubscribeInfo

```ts
getSubscribeInfo(): Promise<CommonEventSubscribeInfo>
```

以Promise形式获取订阅者的订阅信息。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | 表示订阅者的订阅信息。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.getSubscribeInfo().then((subscribeInfo) => {
    console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
}).catch((err) => {
    console.error(`getSubscribeInfo failed, code is ${err.code}, message is ${err.message}`);
});
```

## finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(callback: AsyncCallback<void>): void
```

以回调形式结束当前有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                  | 必填 | 说明                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 表示有序公共事件结束后的回调函数。 |

**示例：**

```ts
let subscriber; //创建成功的订阅者对象

//结束当前有序公共事件的回调
function finishCB(err) {
  if (err.code) {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
} else {
    console.info("FinishCommonEvent");
}

subscriber.finishCommonEvent(finishCB);
```

## finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(): Promise<void\>
```

以Promise形式结束当前有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
let subscriber;	//创建成功的订阅者对象

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```