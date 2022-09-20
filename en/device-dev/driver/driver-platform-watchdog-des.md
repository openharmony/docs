# Watchdog


## **Overview**

A watchdog, also called a watchdog timer, is a hardware timing device used to facilitate automatic correction of temporary hardware faults or recover from system malfunctions. If an error occurs in the main program of the system and the watchdog timer is not cleared in time, the watchdog timer sends a reset signal to restore the system to the normal state.


## Available APIs

**Table 1** Watchdog APIs

| API| Description|
| -------- | -------- |
| WatchdogOpen | Opens a watchdog.|
| WatchdogClose | Closes a watchdog.|
| WatchdogStart | Starts a watchdog.|
| WatchdogStop | Stops a watchdog.|
| WatchdogSetTimeout | Sets the watchdog timeout duration.|
| WatchdogGetTimeout | Obtains the watchdog timeout duration.|
| WatchdogGetStatus | Obtains the watchdog status.|
| WatchdogFeed | Feeds a watchdog or resets a watchdog timer.|

> ![](../public_sys-resources/icon-note.gif) **NOTE**
>
> All watchdog APIs provided in this document can be called only in kernel mode.


## Usage Guidelines


### How to Use

The figure below shows how to use the watchdog APIs.

Figure 1 Using watchdog APIs

![image](figures/using-watchdog-process.png)


### Opening a Watchdog

Use **WatchdogOpen()** to open a watchdog. A system may have multiple watchdogs. You need to specify the ID of the watchdog to open.

```
DevHandle WatchdogOpen(int16_t wdtId);
```

**Table 2** Description of WatchdogOpen

| **Parameter**| **Description**|
| -------- | -------- |
| wdtId | Watchdog ID.|
| **Return Value**| **Description**|
| NULL | The operation failed.|
| **DevHandle** pointer| The operation is successful. The pointer to the watchdog device handle is returned.|


```
DevHandle handle = NULL;
handle = WatchdogOpen(0); /* Open watchdog 0.*/
if (handle == NULL) {
    HDF_LOGE("WatchdogOpen: failed, ret %d\n", ret);
    return;
}
```


### Obtaining the Watchdog Status

```
int32_t WatchdogGetStatus(DevHandle handle, int32_t *status); 
```

**Table 3** Description of WatchdogGetStatus

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Watchdog device handle.|
| status | Pointer to the watchdog status obtained.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
int32_t status;
/* Obtain the watchdog status. */
ret = WatchdogGetStatus(handle, &status);
if (ret != 0) {
    HDF_LOGE("WatchdogGetStatus: failed, ret %d\n", ret);
    return;
}
```


### Setting the Timeout Duration

```
int32_t WatchdogSetTimeout(DevHandle *handle, uint32_t seconds); 
```

**Table 4** Description of WatchdogSetTimeout

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Pointer to the watchdog device handle.|
| seconds | Timeout duration to set, in seconds.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
uint32_t timeOut = 60;
/* Set the timeout duration to 60 seconds. */
ret = WatchdogSetTimeout(handle, timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogSetTimeout: failed, ret %d\n", ret);
    return;
}
```


### Obtaining the Timeout Duration

```
int32_t WatchdogGetTimeout(DevHandle *handle, uint32_t *seconds);
```

**Table 5** Description of WatchdogGetTimeout

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Pointer to the watchdog device handle.|
| seconds | Pointer to the timeout duration, in seconds.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
uint32_t timeOut;
/* Obtain the timeout duration, in seconds. */
ret = WatchdogGetTimeout(handle, &timeOut);
if (ret != 0) {
    HDF_LOGE("WatchdogGetTimeout: failed, ret %d\n", ret);
    return;
}
```


### Starting a Watchdog

```
int32_t WatchdogStart(DevHandle handle);
```

**Table 6** Description of WatchdogStart

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Watchdog device handle.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
/* Start the watchdog. */
ret = WatchdogStart(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStart: failed, ret %d\n", ret);
    return;
}
```


### Feeding a Watchdog

```
int32_t WatchdogFeed(DevHandle handle);
```

**Table 7** Description of WatchdogFeed

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Watchdog device handle.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
/* Feed the watchdog. */
ret = WatchdogFeed(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogFeed: failed, ret %d\n", ret);
    return;
}
```


### Stopping a Watchdog

```
int32_t WatchdogStop(DevHandle handle);
```

**Table 8** Description of WatchdogStop

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Watchdog device handle.|
| **Return Value**| **Description**|
| 0 | The operation is successful.|
| Negative value| The operation failed.|


```
int32_t ret;
/* Stop the watchdog. */
ret = WatchdogStop(handle);
if (ret != 0) {
    HDF_LOGE("WatchdogStop: failed, ret %d\n", ret);
    return;
}
```


### Closing a Watchdog

If a watchdog is no longer required, call **WatchdogClose()** to close it.

```
void WatchdogClose(DevHandle handle);
```

**Table 9** Description of WatchdogClose

| **Parameter**| **Description**|
| -------- | -------- |
| handle | Watchdog device handle.|


```
/* Close the watchdog. */
ret = WatchdogClose(handle);
```


## Example

The following example provides the complete development process.

1. Open a watchdog, set the timeout duration, and start the watchdog.

2. Feed the watchdog periodically to ensure that the system is not reset due to timer expiry.
3. Stop feeding the watchdog and check whether the system is reset after the timer expires.

Sample code:

```
#include "watchdog_if.h"
#include "hdf_log.h"
#include "osal_irq.h"
#include "osal_time.h"

#define WATCHDOG_TEST_TIMEOUT     2
#define WATCHDOG_TEST_FEED_TIME   6

static int32_t TestCaseWatchdog(void)
{
    int32_t i;
    int32_t ret;
    uint32_t timeout;
    DevHandle handle = NULL;

    /* Open watchdog 0. */
    handle = WatchdogOpen(0);
    if (handle == NULL) {
        HDF_LOGE("Open watchdog failed!");
        return -1;
    }

    /* Set the timeout duration. */
    ret = WatchdogSetTimeout(handle, WATCHDOG_TEST_TIMEOUT);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: set timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* Obtain the timeout duration. */
    ret = WatchdogGetTimeout(handle, &timeout);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: get timeout fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }
    HDF_LOGI("%s: read timeout back:%u\n", __func__, timeout);

    /* Start the watchdog. The timer starts. */
    ret = WatchdogStart(handle);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: start fail! ret:%d\n", __func__, ret);
        WatchdogClose(handle);
        return ret;
    }

    /* Feed the watchdog every other second. */
    for (i = 0; i < WATCHDOG_TEST_FEED_TIME; i++) {
        HDF_LOGI("%s: feeding watchdog %d times... \n", __func__, i);
        ret = WatchdogFeed(handle);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: feed dog fail! ret:%d\n", __func__, ret);
            WatchdogClose(handle);
            return ret;
        }
        OsalSleep(1);
    }
    /* Because the interval for feeding the watchdog is shorter than the timeout duration, the system does not reset, and logs can be printed normally. */
    HDF_LOGI("%s: no reset ... feeding test OK!!!\n", __func__);

    /* Stop feeding the watchdog to make the timer expire. */
    for (i = 0; i < WATCHDOG_TEST_FEED_TIME; i++) {
        HDF_LOGI("%s: waiting dog buck %d times... \n", __func__, i);
        OsalSleep(1);
    }

    /* The system resets when the timer expires. Theoretically, this log is not displayed. */
    HDF_LOGI("%s: dog hasn't back!!! \n", __func__, i);
    WatchdogClose(handle);
    return -1;
}
```
