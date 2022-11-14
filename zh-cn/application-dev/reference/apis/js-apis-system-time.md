# 系统时间、时区

本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import systemTime from '@ohos.systemTime';
```

## systemTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

设置系统时间，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型            | 必填 | 说明                                       |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | 是   | 目标时间戳（ms）。                         |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
systemTime.setTime(time, (error, data) => {
    if (error) {
        console.error(`Failed to set systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in setting systemTime. Data:` + JSON.stringify(data));
});
```

## systemTime.setTime

setTime(time : number) : Promise&lt;void&gt;

设置系统时间，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| time   | number | 是   | 目标时间戳（ms）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
systemTime.setTime(time).then((data) => {
    console.log(`Succeeded in setting systemTime. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to set systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自Unix纪元以来经过的时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型       | 必填 | 说明                             |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数（ns）。 <br>- false：表示返回结果为毫秒数（ms）。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自Unix纪元以来经过的时间。         |

**示例：**

```js
systemTime.getCurrentTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting systemTime. Data:` + JSON.stringify(data));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(callback: AsyncCallback&lt;number&gt;): void

获取自Unix纪元以来经过的时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型               | 必填 | 说明                            |
| -------- | ----------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自Unix纪元以来经过的时间。         |

**示例：**

```js
systemTime.getCurrentTime((error, data) => {
    if (error) {
        console.error(`Succeeded in getting systemTime. Data:` + JSON.stringify(error));
        return;
    }
    console.log(`Failed to get systemTime. Cause:` + JSON.stringify(data));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

获取自Unix纪元以来经过的时间，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                     |
| ------ | ------- | ---- | ------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |

**返回值：**

| 类型        | 说明                               |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自Unix纪元以来经过的时间。 |

**示例：**

```js
systemTime.getCurrentTime().then((data) => {
    console.log(`Succeeded in getting systemTime. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明   |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |

**示例：**

```js
systemTime.getRealActiveTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get real active time. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real active time. Data:` + JSON.stringify(data));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明    |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |

**示例：**

```js
systemTime.getRealActiveTime((error, data) => {
    if (error) {
        console.error(`Failed to get real active time. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real active time. Data:` + JSON.stringify(data));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

获取自系统启动以来经过的时间，不包括深度睡眠时间，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | ----------------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |

**返回值：**

| 类型                  | 说明         |
| -------------- | -------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |

**示例：**

```js
systemTime.getRealActiveTime().then((data) => {
    console.log(`Succeeded in getting real active time. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real active time. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明   |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | 是   | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。   |

**示例：**

```js
systemTime.getRealTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get real time. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real time. Data:` + JSON.stringify(data));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(callback: AsyncCallback&lt;number&gt;): void

获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                        | 必填 | 说明      |
| -------- | --------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。   |

**示例：**

```js
systemTime.getRealTime((error, data) => {
    if (error) {
        console.error(`Failed to get real time. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real time. Data:` + JSON.stringify(data));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(isNano?: boolean): Promise&lt;number&gt;

获取自系统启动以来经过的时间，包括深度睡眠时间，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ------------------------------- |
| isNano | boolean | 否   | 返回结果是否为纳秒数。<<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |

**返回值：**

| 类型                  | 说明       |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回自系统启动以来经过的时间，包括深度睡眠时间。 |

**示例：**

```js
systemTime.getRealTime().then((data) => {
    console.log(`Succeeded in getting real time. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real time. Cause:` + JSON.stringify(error));
});
```

## systemTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

设置系统日期，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型                      | 必填 | 说明             |
| -------- | ------------- | ---- | --------------------- |
| date     | Date                      | 是   | 目标日期。                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
let data = new Date();
systemTime.setDate(data,(error, data) => {       
    if (error) {            
    console.error('Failed to set system date. Cause:' + JSON.stringify(error));           
    return;       
}        
    console.info('Succeeded in setting system date. Data:' + JSON.stringify(data));    
});
```

## systemTime.setDate

setDate(date: Date): Promise&lt;void&gt;

设置系统日期，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名 | 类型 | 必填 | 说明       |
| ------ | ---- | ---- | ---------- |
| date   | Date | 是   | 目标日期。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let data = new Date(); 
systemTime.setDate(data).then((value) => {        
    console.log(`Succeeded in setting system date. Data:` + JSON.stringify(value));    
}).catch((error) => {        
    console.error(`Failed to set system date. Cause:` + JSON.stringify(error));
});
```

## systemTime.getDate<sup>8+</sup>

getDate(callback: AsyncCallback&lt;Date&gt;): void

获取当前系统日期，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型           | 必填 | 说明                   |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Date&gt; | 是   | 回调函数，返回当前系统日期。 |

**示例：**

```js
systemTime.getDate((error, data) => {
    if (error) {
        console.error(`Failed to get system date. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting system date. Data:` + JSON.stringify(data));
});
```

## systemTime.getDate<sup>8+</sup>

getDate(): Promise&lt;Date&gt;

获取当前系统日期，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                | 说明                                      |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | Promise对象，返回当前系统日期。 |

**示例：**

```js
systemTime.getDate().then((data) => {
    console.log(`Succeeded in getting system date. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get system date. Cause:` + JSON.stringify(error));
});
```

## systemTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

设置系统时区，使用callback异步回调。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                  |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | 是   | 系统时区。                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
systemTime.setTimezone('Asia/Shanghai', (error, data) => {       
    if (error) {          
        console.error('Failed to set system time zone. Cause:' + JSON.stringify(error));         
        return;       
    }       
    console.info('Succeeded in setting system time zone. Data:' + JSON.stringify(data)); 
});
```

## systemTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

设置系统时区，使用Promise异步回调。

**需要权限：** ohos.permission.SET_TIME_ZONE

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| timezone | string | 是   | 系统时区。 |

**返回值：**

| 类型                | 说明                 |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
systemTime.setTimezone('Asia/Shanghai').then((data) => {        
    console.log(`Succeeded in setting system time zone. Data:` + JSON.stringify(data));     
}).catch((error) => {        
    console.error(`Failed to set system time zone. Cause:` + JSON.stringify(error));    
});
```

## systemTime.getTimezone<sup>8+</sup>

getTimezone(callback: AsyncCallback&lt;string&gt;): void

获取系统时区，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**参数：**

| 参数名   | 类型              | 必填 | 说明                 |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回系统时区。 |

**示例：**

```js
systemTime.getTimezone((error, data) => {
    if (error) {
        console.error(`Failed to get system time zone. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting system time zone. Data:` + JSON.stringify(data));
});
```

## systemTime.getTimezone<sup>8+</sup>

getTimezone(): Promise&lt;string&gt;

获取系统时区，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Time

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回系统时区。 |

**示例：**

```js
systemTime.getTimezone().then((data) => {
    console.log(`Succeeded in getting system time zone. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get system time zone. Cause:` + JSON.stringify(error));
});
```