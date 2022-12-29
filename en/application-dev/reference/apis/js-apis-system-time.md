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
systemTime.setTime(time).then((data) => {
    console.log(`Succeeded in setting systemTime. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to set systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getCurrentTime<sup>8+</sup>

getCurrentTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type      | Mandatory| Description                            |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch.        |

**Example**

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

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type              | Mandatory| Description                           |
| -------- | ----------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch.        |

**Example**

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
    console.log(`Succeeded in getting systemTime. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get systemTime. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealActiveTime<sup>8+</sup>

getRealActiveTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

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

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description   |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

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
    console.log(`Succeeded in getting real active time. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real active time. Cause:` + JSON.stringify(error));
});
```

## systemTime.getRealTime<sup>8+</sup>

getRealTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: in nanoseconds (ns).<br>- **false**: in milliseconds (ms).|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

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

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description     |
| -------- | --------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

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
    console.log(`Succeeded in getting real time. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get real time. Cause:` + JSON.stringify(error));
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
let data = new Date(); 
systemTime.setDate(data).then((value) => {        
    console.log(`Succeeded in setting system date. Data:` + JSON.stringify(value));    
}).catch((error) => {        
    console.error(`Failed to set system date. Cause:` + JSON.stringify(error));
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
        console.error(`Failed to get system date. Cause:` + JSON.stringify(error));
        return;
    }
    console.log(`Succeeded in getting system date. Data:` + JSON.stringify(data));
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
    console.log(`Succeeded in getting system date. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get system date. Cause:` + JSON.stringify(error));
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
| timezone | string                    | Yes  | System time zone to set. For details, see [Supported System Time Zones](#supported-system-time-zones).       |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

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

Sets the system time zone. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_TIME_ZONE

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type  | Mandatory| Description      |
| -------- | ------ | ---- | ---------- |
| timezone | string | Yes  | System time zone to set. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Return value**

| Type               | Description                |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
systemTime.setTimezone('Asia/Shanghai').then((data) => {        
    console.log(`Succeeded in setting system time zone. Data:` + JSON.stringify(data));     
}).catch((error) => {        
    console.error(`Failed to set system time zone. Cause:` + JSON.stringify(error));    
});
```

## systemTime.getTimezone<sup>8+</sup>

getTimezone(callback: AsyncCallback&lt;string&gt;): void

Obtains the system time zone. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

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

Obtains the system time zone. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```js
systemTime.getTimezone().then((data) => {
    console.log(`Succeeded in getting system time zone. Data:` + JSON.stringify(data));
}).catch((error) => {
    console.error(`Failed to get system time zone. Cause:` + JSON.stringify(error));
});
```

## Supported System Time Zones

The following table lists the supported system time zones and the respective offset (unit: h) between each time zone and time zone 0.

| Time Zone                          | Offset        |
| ------------------------------ | --------------------- |
| Antarctica/McMurdo             | 12                    |
| America/Argentina/Buenos_Aires | -3                    |
| Australia/Sydney               | 10                    |
| America/Noronha                | -2                    |
| America/St_Johns               | -3                    |
| Africa/Kinshasa                | 1                     |
| America/Santiago               | -3                    |
| Asia/Shanghai                  | 8                     |
| Asia/Nicosia                   | 3                     |
| Europe/Berlin                  | 2                     |
| America/Guayaquil              | -5                    |
| Europe/Madrid                  | 2                     |
| Pacific/Pohnpei                | 11                    |
| America/Godthab                | -2                    |
| Asia/Jakarta                   | 7                     |
| Pacific/Tarawa                 | 12                    |
| Asia/Almaty                    | 6                     |
| Pacific/Majuro                 | 12                    |
| Asia/Ulaanbaatar               | 8                     |
| America/Mexico_City            | -5                    |
| Asia/Kuala_Lumpur              | 8                     |
| Pacific/Auckland               | 12                    |
| Pacific/Tahiti                 | -10                   |
| Pacific/Port_Moresby           | 10                    |
| Asia/Gaza                      | 3                     |
| Europe/Lisbon                  | 1                     |
| Europe/Moscow                  | 3                     |
| Europe/Kiev                    | 3                     |
| Pacific/Wake                   | 12                    |
| America/New_York               | -4                    |
| Asia/Tashkent                  | 5                     |
