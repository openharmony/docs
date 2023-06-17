# @ohos.systemDateTime (System Time and Time Zone)

The **systemDateTime** module provides system time and time zone features. You can use the APIs of this module to set and obtain the system time and time zone.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import systemDateTime from '@ohos.systemDateTime';
```

## systemDateTime.setTime

setTime(time : number, callback : AsyncCallback&lt;void&gt;) : void

Sets the system time. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

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
try {
    systemDateTime.setTime(time, (error) => {
        if (error) {
            console.info(`Failed to set time. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in setting time`);
	});
} catch(e) {
    console.info(`Failed to set time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.setTime

setTime(time : number) : Promise&lt;void&gt;

Sets the system time. This API uses a promise to return the result.

**System API**: This is a system API.

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
try {
    systemDateTime.setTime(time).then(() => {
    	console.info(`Succeeded in setting time.`);
	}).catch((error) => {
    	console.info(`Failed to set time. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to set time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getCurrentTime

getCurrentTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type      | Mandatory| Description                            |
| -------- | -------------- | ---- | ------------------ |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds. |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch.        |

**Example**

```js
try {
    systemDateTime.getCurrentTime(true, (error, time) => {
        if (error) {
            console.info(`Failed to get currentTime. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting currentTime : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get currentTime. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getCurrentTime

getCurrentTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since the Unix epoch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type              | Mandatory| Description                           |
| -------- | ----------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time elapsed since the Unix epoch, in milliseconds.        |

**Example**

```js
try {
    systemDateTime.getCurrentTime((error, time) => {
        if (error) {
            console.info(`Failed to get currentTime. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting currentTime : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get currentTime. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getCurrentTime

getCurrentTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since the Unix epoch. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                    |
| ------ | ------- | ---- | ------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.<br/>Default value: **false** |

**Return value**

| Type       | Description                              |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since the Unix epoch.|

**Example**

```js
try {
    systemDateTime.getCurrentTime().then((time) => {
    	console.info(`Succeeded in getting currentTime : ${time}`);
	}).catch((error) => {
    	console.info(`Failed to get currentTime. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to get currentTime. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | ---------- | ---- | -------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds. |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

```js
try {
    systemDateTime.getRealActiveTime(true, (error, time) => {
        if (error) {
            console.info(`Failed to get real active time. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting real active time : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get real active time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description   |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.|

**Example**

```js
try {
    systemDateTime.getRealActiveTime((error, time) => {
        if (error) {
            console.info(`Failed to get real active time. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting real active time : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get real active time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealActiveTime

getRealActiveTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, excluding the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                             |
| ------ | ------- | ---- | ----------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.<br/>Default value: **false** |

**Return value**

| Type                 | Description        |
| -------------- | -------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, excluding the deep sleep time.|

**Example**

```js
try {
    systemDateTime.getRealActiveTime().then((time) => {
    	console.info(`Succeeded in getting real active time : ${time}`);
	}).catch((error) => {
    	console.info(`Failed to get real active time. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to get real active time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(isNano: boolean, callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description  |
| -------- | --------------- | ---- | ------------------------------- |
| isNano   | boolean                     | Yes  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds. |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

```js
try {
    systemDateTime.getRealTime(true, (error, time) => {
        if (error) {
            console.info(`Failed to get real time. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting real time : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get real time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the time elapsed since system startup, including the deep sleep time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                       | Mandatory| Description     |
| -------- | --------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the time.  |

**Example**

```js
try {
    systemDateTime.getRealTime((error, time) => {
        if (error) {
            console.info(`Failed to get real time. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting real time : ${time}`);
	});
} catch(e) {
    console.info(`Failed to get real time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getRealTime

getRealTime(isNano?: boolean): Promise&lt;number&gt;

Obtains the time elapsed since system startup, including the deep sleep time. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name| Type   | Mandatory| Description                              |
| ------ | ------- | ---- | ------------------------------- |
| isNano | boolean | No  | Whether the time to return is in nanoseconds.<br>- **true**: The time to return is in nanoseconds.<br>- **false**: The time to return is in milliseconds.<br/>Default value: **false** |

**Return value**

| Type                 | Description      |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the time elapsed since system startup, including the deep sleep time.|

**Example**

```js
try {
    systemDateTime.getRealTime().then((time) => {
    	console.info(`Succeeded in getting real time : ${time}`);
	}).catch((error) => {
    	console.info(`Failed to get real time. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to get real time. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.setDate

setDate(date: Date, callback: AsyncCallback&lt;void&gt;): void

Sets the system date. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type                     | Mandatory| Description            |
| -------- | ------------- | ---- | --------------------- |
| date     | Date                      | Yes  | Target date to set.                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
let date = new Date();
try {
    systemDateTime.setDate(date, (error) => {
        if (error) {
            console.info(`Failed to set date. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in setting date.`);
	});
} catch(e) {
    console.info(`Failed to set date. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.setDate

setDate(date: Date): Promise&lt;void&gt;

Sets the system date. This API uses a promise to return the result.

**System API**: This is a system API.

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
let date = new Date(); 
try {
    systemDateTime.setDate(date).then(() => {
    	console.info(`Succeeded in setting date.`);
	}).catch((error) => {
    	console.info(`Failed to set date. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to set date. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getDate

getDate(callback: AsyncCallback&lt;Date&gt;): void

Obtains the current system date. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type          | Mandatory| Description                  |
| -------- | -------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;Date&gt; | Yes  | Callback used to return the current system date.|

**Example**

```js
try {
    systemDateTime.getDate((error, date) => {
        if (error) {
            console.info(`Failed to get date. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in getting date : ${date}`);;
	});
} catch(e) {
    console.info(`Failed to get date. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getDate

getDate(): Promise&lt;Date&gt;

Obtains the current system date. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| Promise&lt;Date&gt; | Promise used to return the current system date.|

**Example**

```js
try {
    systemDateTime.getDate().then((date) => {
    	console.info(`Succeeded in getting date : ${date}`);
	}).catch((error) => {
    	console.info(`Failed to get date. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to get date. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string, callback: AsyncCallback&lt;void&gt;): void

Sets the system time zone. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                 |
| -------- | ------------- | ---- | -------------------------- |
| timezone | string                    | Yes  | System time zone to set. For details, see [Supported System Time Zones](#supported-system-time-zones).       |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
try {
    systemDateTime.setTimezone('Asia/Shanghai', (error) => {
        if (error) {
            console.info(`Failed to set timezone. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in setting timezone.`);
	});
} catch(e) {
    console.info(`Failed to set timezone. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.setTimezone

setTimezone(timezone: string): Promise&lt;void&gt;

Sets the system time zone. This API uses a promise to return the result.

**System API**: This is a system API.

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
try {
    systemDateTime.setTimezone('Asia/Shanghai').then(() => {
    	console.info(`Succeeded in setting timezone.`);
	}).catch((error) => {
    	console.info(`Failed to set timezone. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to set timezone. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getTimezone

getTimezone(callback: AsyncCallback&lt;string&gt;): void

Obtains the system time zone. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Parameters**

| Name  | Type             | Mandatory| Description                |
| -------- | --------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```js
try {
    systemDateTime.getTimezone((error, data) => {
        if (error) {
            console.info(`Failed to get timezone. message:${error.message}, code:${error.code}`);
            return;
        }
    	console.info(`Succeeded in get timezone : ${data}`);;
	});
} catch(e) {
    console.info(`Failed to get timezone. message:${e.message}, code:${e.code}`);
}
```

## systemDateTime.getTimezone

getTimezone(): Promise&lt;string&gt;

Obtains the system time zone. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Time

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the system time zone. For details, see [Supported System Time Zones](#supported-system-time-zones).|

**Example**

```js
try {
    systemDateTime.getTimezone().then((data) => {
    	console.info(`Succeeded in getting timezone: ${data}`);
	}).catch((error) => {
    	console.info(`Failed to get timezone. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
    console.info(`Failed to get timezone. message:${e.message}, code:${e.code}`);
}
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
