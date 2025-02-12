# CommonEventSubscriber

描述公共事件的订阅者。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用说明

在使用CommonEventSubscriber的功能前，需要通过commonEventManager.createSubscriber获取subscriber对象。

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber: commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
	events: ["event"]
};
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) {
  if (err != null) {
    console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in creating subscriber`);
    subscriber = commonEventSubscriber;
  }
}
// 创建订阅者
commonEventManager.createSubscriber(subscribeInfo, createCB);
```

## getCode

getCode(callback: AsyncCallback\<number>): void

获取有序公共事件代码。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                   | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number\> | 是   | 回调函数。返回公共事件代码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取有序公共事件代码回调
function getCodeCallback(err: BusinessError, code: number) {
  if (err != null) {
    console.error(`Failed to get code. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in getting code, code is ` + JSON.stringify(code));
  }
}
subscriber.getCode(getCodeCallback);
```

## getCode

getCode(): Promise\<number>

获取有序公共事件代码。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<number> | Promise对象。返回公共事件代码。 |

**示例：**

```ts
subscriber.getCode().then((code: number) => {
  console.info(`Succeeded in getting code, code is ` + JSON.stringify(code));
}).catch((err: BusinessError) => {
  console.error(`Failed to get code. Code is ${err.code}, message is ${err.message}`);
});
```

## getCodeSync<sup>10+</sup>

getCodeSync(): number

获取有序公共事件代码。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| number | 公共事件代码。 |

**示例：**

```ts
let code = subscriber.getCodeSync();
console.info(`Succeeded in getting code, code is ` + JSON.stringify(code));
```

## setCode

setCode(code: number, callback: AsyncCallback\<void>): void

设置有序公共事件的代码。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的代码。   |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 设置有序公共事件的代码回调
function setCodeCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in setting code.`);
  }
}
subscriber.setCode(1, setCodeCallback);
```

## setCode

setCode(code: number): Promise\<void>

设置有序公共事件的代码。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的代码。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
subscriber.setCode(1).then(() => {
  console.info(`Succeeded in setting code.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
});
```

## setCodeSync<sup>10+</sup>

setCodeSync(code: number): void

设置有序公共事件的代码。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的代码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**示例：**

```ts
try {
  subscriber.setCodeSync(1);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
}
```

## getData

getData(callback: AsyncCallback\<string>): void

获取有序公共事件的数据。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数。返回公共事件的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取有序公共事件代码数据回调
function getDataCallback(err: BusinessError, data: string) {
  if (err != null) {
    console.error(`Failed to get data. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in getting data, data is ` + JSON.stringify(data));
  }
}
subscriber.getData(getDataCallback);
```

## getData

getData(): Promise\<string>

获取有序公共事件的数据。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| Promise\<string> | Promise对象。返回公共事件的数据。 |

**示例：**

```ts
subscriber.getData().then((data: string) => {
  console.info(`Succeeded in getting data, data is ` + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get data. Code is ${err.code}, message is ${err.message}`);
});
```

## getDataSync<sup>10+</sup>

getDataSync(): string

获取有序公共事件的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| string | 公共事件的数据。 |

**示例：**

```ts
let data = subscriber.getDataSync();
console.info(`Succeeded in getting data, data is ${data}`);
```

## setData

setData(data: string, callback: AsyncCallback\<void>): void

设置有序公共事件的数据。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的数据。   |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 设置有序公共事件的结果数据回调
function setDataCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in setting code.`);
  }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

## setData

setData(data: string): Promise\<void>

设置有序公共事件的数据。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
subscriber.setData("publish_data_changed").then(() => {
  console.info(`Succeeded in setting data.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
});
```

## setDataSync<sup>10+</sup>

setDataSync(data: string): void

设置有序公共事件的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**示例：**

```ts
try {
  subscriber.setDataSync("publish_data_changed");
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
}
```

## setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

设置有序公共事件代码和数据。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的代码。   |
| data     | string               | 是   | 公共事件的数据。   |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 设置有序公共事件的代码和数据回调
function setCodeAndDataCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in setting code and data.`);
  }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeAndDataCallback);
```

## setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

设置有序公共事件的代码和数据。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的代码。 |
| data   | string | 是   | 公共事件的数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
  console.info(`Succeeded in setting code and data.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
});
```

## setCodeAndDataSync<sup>10+</sup>

setCodeAndDataSync(code: number, data: string): void

设置有序公共事件的代码和数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的代码。 |
| data   | string | 是   | 公共事件的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**示例：**

```ts
try {
  subscriber.setCodeAndDataSync(1, "publish_data_changed");
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
}

```

## isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

查询当前公共事件是否为有序公共事件。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示有序公共事件；false表示无序公共事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取当前公共事件是否为有序事件的回调
function isOrderedCommonEventCallback(err: BusinessError, isOrdered:boolean) {
  if (err != null) {
    console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("isOrderedCommonEvent " + JSON.stringify(isOrdered));
  }
}
subscriber.isOrderedCommonEvent(isOrderedCommonEventCallback);
```

## isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

查询当前公共事件是否为有序公共事件。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示有序公共事件；false表示无序公共事件。 |

**示例：**

```ts
subscriber.isOrderedCommonEvent().then((isOrdered:boolean) => {
  console.info("isOrderedCommonEvent " + JSON.stringify(isOrdered));
}).catch((err: BusinessError) => {
  console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## isOrderedCommonEventSync<sup>10+</sup>

isOrderedCommonEventSync(): boolean

查询当前公共事件是否为有序公共事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| boolean | 返回true表示有序公共事件；false表示无序公共事件。 |

**示例：**

```ts
let isOrdered  = subscriber.isOrderedCommonEventSync();
console.info("isOrderedCommonEventSync " + JSON.stringify(isOrdered));
```

## isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

检查当前公共事件是否为一个粘性事件。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示是粘性公共事件；false表示不是粘性公共事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取当前公共事件是否为粘性事件的回调
function isStickyCommonEventCallback(err: BusinessError, isSticky:boolean) {
  if (err != null) {
    console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("isStickyCommonEvent " + JSON.stringify(isSticky));
  }
}
subscriber.isStickyCommonEvent(isStickyCommonEventCallback);
```

## isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

检查当前公共事件是否为一个粘性事件。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示是粘性公共事件；false表示不是粘性公共事件。 |

**示例：**

```ts
subscriber.isStickyCommonEvent().then((isSticky:boolean) => {
  console.info("isStickyCommonEvent " + JSON.stringify(isSticky));
}).catch((err: BusinessError) => {
  console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## isStickyCommonEventSync<sup>10+</sup>

isStickyCommonEventSync(): boolean

检查当前公共事件是否为一个粘性事件。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| boolean | 返回true表示是粘性公共事件；false表示不是粘性公共事件。 |

**示例：**

```ts
let isSticky  = subscriber.isStickyCommonEventSync();
console.info("isStickyCommonEventSync " + JSON.stringify(isSticky));
```

## abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 中止当前的有序公共事件的回调
function abortCommonEventCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to abort common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in aborting common event.`);
  }
}
function finishCommonEventCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in finishing common event.`);
  }
}
subscriber.abortCommonEvent(abortCommonEventCallback);
subscriber.finishCommonEvent(finishCommonEventCallback);
```

## abortCommonEvent

abortCommonEvent(): Promise\<void>

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
subscriber.abortCommonEvent().then(() => {
  console.info(`Succeeded in aborting common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to abort common event. Code is ${err.code}, message is ${err.message}`);
});
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

## abortCommonEventSync<sup>10+</sup>

abortCommonEventSync(): void

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**示例：**

```ts
subscriber.abortCommonEventSync();
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

## clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                 | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 取消当前有序公共事件的中止状态的回调
function clearAbortCommonEventCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to clear abort common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in clearing abort common event.`);
  }
}
function finishCommonEventCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in finishing common event.`);
  }
}
subscriber.clearAbortCommonEvent(clearAbortCommonEventCallback);
subscriber.finishCommonEvent(finishCommonEventCallback);
```

## clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
subscriber.clearAbortCommonEvent().then(() => {
  console.info(`Succeeded in clearing abort common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to clear abort common event. Code is ${err.code}, message is ${err.message}`);
});
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

## clearAbortCommonEventSync<sup>10+</sup>

clearAbortCommonEventSync(): void

该接口与[finishCommonEvent](#finishcommonevent9)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**示例：**

```ts
subscriber.clearAbortCommonEventSync();
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

## getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

获取当前有序公共事件是否处于中止状态。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                    | 必填 | 说明                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示当前有序公共事件处于中止状态；false表示当前有序公共事件没有处于中止状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取当前有序公共事件是否处于中止状态回调
function getAbortCommonEventCallback(err: BusinessError, abortEvent: boolean) {
  if (err != null) {
    console.error(`Failed to get abort common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in getting abort common event, abortEvent is ` + JSON.stringify(abortEvent));
  }
}
subscriber.getAbortCommonEvent(getAbortCommonEventCallback);
```

## getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

获取当前有序公共事件是否处于中止状态。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示当前有序公共事件处于中止状态；false表示当前有序公共事件没有处于中止状态。 |

**示例：**

```ts
subscriber.getAbortCommonEvent().then((abortEvent: boolean) => {
  console.info(`Succeeded in getting abort common event, abortEvent is ` + JSON.stringify(abortEvent));
}).catch((err: BusinessError) => {
  console.error(`Failed to get abort common event. Code is ${err.code}, message is ${err.message}`);
});
```

## getAbortCommonEventSync<sup>10+</sup>

getAbortCommonEventSync(): boolean

获取当前有序公共事件是否处于中止状态。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| boolean | 返回true表示当前有序公共事件处于中止状态；false表示当前有序公共事件没有处于中止状态。 |

**示例：**

```ts
let abortEvent = subscriber.getAbortCommonEventSync();
console.info(`Succeeded in getting abort common event, abortEvent is ` + JSON.stringify(abortEvent));
```

## getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

获取订阅者的订阅信息。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | 是   | 回调函数。返回订阅者的订阅信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 获取订阅者信息回调
function getSubscribeInfoCallback(err: BusinessError, subscribeInfo: commonEventManager.CommonEventSubscribeInfo) {
  if (err != null) {
    console.error(`Failed to get subscribe info. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in getting subscribe info, subscribe info is ` + JSON.stringify(subscribeInfo));
  }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

## getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

获取订阅者的订阅信息。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Promise对象。返回订阅者的订阅信息。 |

**示例：**

```ts
subscriber.getSubscribeInfo().then((subscribeInfo: commonEventManager.CommonEventSubscribeInfo) => {
  console.info(`Succeeded in getting subscribe info, subscribe info is ` + JSON.stringify(subscribeInfo));
}).catch((err: BusinessError) => {
  console.error(`Failed to get subscribe info. Code is ${err.code}, message is ${err.message}`);
});
```

## getSubscribeInfoSync<sup>10+</sup>

getSubscribeInfoSync(): CommonEventSubscribeInfo

获取订阅者的订阅信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | 表示订阅者的订阅信息。 |

**示例：**

```ts
let subscribeInfo = subscriber.getSubscribeInfoSync();
console.info(`Succeeded in getting subscribe info, subscribe info is ` + JSON.stringify(subscribeInfo));
```

## finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void>): void

用于订阅者结束对当前有序公共事件的处理。使用callback异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**参数：**

| 参数名   | 类型                  | 必填 | 说明                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。表示被指定的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**示例：**

```ts
// 结束订阅者对当前有序公共事件处理的回调
function finishCommonEventCallback(err: BusinessError) {
  if (err != null) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in finishing common event.`);
  }
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

## finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void>

用于订阅者结束对当前有序公共事件的处理。使用Promise异步回调。

**系统能力**：`SystemCapability.Notification.CommonEvent`

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```