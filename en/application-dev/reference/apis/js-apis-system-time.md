# System Time and Time Zone

The **systemTime** module provides system time and time zone features. You can use the APIs of this module to set and obtain the system time and time zone.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import systemTime from '@ohos.systemTime';
```

## systemTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

Sets the system time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_TIME

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type           | Mandatory| Description                                      |
| -------- | ----------- | ---- | ---------------- |
| time     | number                    | Yes  | Timestamp to set, in milliseconds.                        |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
// Set the system time to 2021-01-20 02:36:25.
let time = 1611081385000;
systemTime.setTime(time, (error) => {
    if (error) {
        console.error(`Failed to set systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log('Succeeded in setting systemTime.');
});
```

## systemTime.setTime

setTime(time : number) : Promise&lt;void&gt;

Sets the system time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_TIME

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| time   | number | Yes  | Timestamp to set, in milliseconds.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
// Set the system time to 2021-01-20 02:36:25.
let time = 1611081385000;
systemTime.setTime(time).then(() => {
    console.log('Succeeded in setting systemTime.');
}).catch((error) => {
    console.error(`Failed to set systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano?: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type      | Mandatory| Description                            |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | No  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch.        |

**Example**

```js
systemTime.getCurrentTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting systemTime.Data: ` + JSON.stringify(data));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since the Unix epoch. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                    |
| ------ | ------- | ---- | ------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|

**Return value**

| Type       | Description                              |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since the Unix epoch.|

**Example**

```js
systemTime.getCurrentTime().then((data) => {
    console.log(`Succeeded in getting systemTime.Data: ` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano?: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | No  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

```js
systemTime.getRealActiveTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get real active systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real active systemTime. Data: ` + JSON.stringify(data));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | ----------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|

**Return value**

| Type                 | Description        |
| -------------- | -------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, excluding the deep sleep time.|

**Example**

```js
systemTime.getRealActiveTime().then((data) => {
    console.log(`Succeeded in getting real active systemTime. Data: ` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real active systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(isNano?: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | No  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

```js
systemTime.getRealTime(true, (error, data) => {
    if (error) {
        console.error(`Failed to get real systemTime. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting real active systemTime. Data: ` + JSON.stringify(data));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, including the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                              |
| ------ | ------- | ---- | ------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|

**Return value**

| Type                 | Description      |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, including the deep sleep time.|

**Example**

```js
systemTime.getRealTime().then((data) => {
    console.log(`Succeeded in getting real active systemTime. Data: ` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

Sets the system date. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_TIME

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                     | Mandatory| Description            |
| -------- | ------------- | ---- | --------------------- |
| date     | Date                      | Yes  | Target date to set.                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
let data = new Date("October 13, 2020 11:13:00");
systemTime.setDate(data,(error) => {       
    if (error) {            
    console.error('Failed to set systemDate. Cause: ' + JSON.stringify(error));           
    return;       
}        
    console.info('Succeeded in setting systemDate.');    
});
```

## systemTime.setDate

setDate(date: Date): Promise&lt;void&gt;

Sets the system date. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_TIME

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type| Mandatory| Description      |
| ------ | ---- | ---- | ---------- |
| date   | Date | Yes  | Target date to set.|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let data = new Date("October 13, 2020 11:13:00"); 
systemTime.setDate(data).then(() => {        
    console.log('Succeeded in setting systemDate.');    
}).catch((error) => {        
    console.error(`Failed to set systemDate. Cause: ` + JSON.stringify(error));
});
```

## systemTime.getDate<sup>8+</sup>

getDate(callback: AsyncCallback&lt;Date&gt;): void

Obtains the current system date. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type          | Mandatory| Description                  |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Date&gt; | Yes  | Callback used to return the current system date.|

**Example**

```js
systemTime.getDate((error, data) => {
    if (error) {
        console.error(`Failed to get systemDate. Cause: ` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting systemDate. Data: ` + JSON.stringify(data));
});
```

## systemTime.getDate<sup>8+</sup>

getDate(): Promise&lt;Date&gt;

Obtains the current system date. This API uses a promise to return the result.  

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | Promise used to return the current system date.|

**Example**

```js
systemTime.getDate().then((data) => {
    console.log(`Succeeded in getting systemDate. Data: ` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get systemDate. Cause: ` + JSON.stringify(error));
});
```

## systemTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

Sets the system time zone. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_TIME_ZONE

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                 |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | Yes  | System time zone to set.                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
systemTime.setTimezone('Asia/Shanghai', (error) => {       
    if (error) {          
        console.error('Failed to set systemTimeZone. Cause: ' + JSON.stringify(error));         
        return;       
    }       
    console.info('Succeeded in setting systemTimeZone.'); 
});
```

## systemTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

Sets the system time zone. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_TIME_ZONE

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| timezone | string | Yes  | System time zone to set.|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
systemTime.setTimezone('Asia/Shanghai').then(() => {        
    console.log('Succeeded in setting systemTimeZone.');     
}).catch((error) => {        
    console.error(`Failed to set systemTimeZone. Cause: ` + JSON.stringify(error));    
});
```

## systemTime.getTimezone<sup>8+</sup>

getTimezone(callback: AsyncCallback&lt;string&gt;): void

Obtains the system time zone. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the system time zone.|

**Example**

```js
systemTime.getTimezone((error, data) => {
    if (error) {
        console.error(`Failed to get systemTimeZone. Cause: ` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting systemTimeZone. Data: ` + JSON.stringify(data));
});
```

## systemTime.getTimezone<sup>8+</sup>

getTimezone(): Promise&lt;string&gt;

Obtains the system time zone. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the system time zone.|

**Example**

```js
systemTime.getTimezone().then((data) => {
    console.log(`Succeeded in getting systemTimeZone. Data: ` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get systemTimeZone. Cause: ` + JSON.stringify(error));
});
```
