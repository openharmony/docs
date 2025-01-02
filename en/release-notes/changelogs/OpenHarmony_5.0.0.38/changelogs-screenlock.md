# Screen Lock Changelog

## cl.screenlock.1 System Events Added to EventType

**Access Level**

System API

**Reason for Change**

The **strongAuthChanged** and **screenLockDisabledChanged** system events need to be added to report the enabling of strong authentication and disabling of screen lock.

**Change Impact**

This change is a compatible change.

Before change: The **strongAuthChanged** and **screenLockDisabledChanged** system events are not supported.

After change: The **strongAuthChanged** and **screenLockDisabledChanged** system events are supported.

**Start API Level**

API 12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**
The following is the sample code for registering system lock events:

```typescript
try {
  let isSuccess = screenLock.onSystemEvent((event: screenLock.SystemEvent) => {
    console.log(`Succeeded in Registering the system event which related to screenlock. eventType: ${event.eventType}`)
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to register the system event which related to screenlock, Code: ${error.code}, message: ${error.message}`)
}
```
