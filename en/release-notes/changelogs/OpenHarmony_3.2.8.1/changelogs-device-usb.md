# USB Manager ChangeLog

## cl.usb_manager.1 Error Information Return Method Change of APIs

The USB manager API uses service logic return values to indicate the error information, which does not comply with the API error code specifications of OpenHarmony. Beginning from API version 9, error information is returned by throwing exceptions.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Changed the USB module name from **@ohos.usb.d.ts** to **@ohos.usbV9.d.ts**, and added error code processing for all APIs in the module.

**Adaptation Guide**

Take the **getDevices** API as an example. The sample code is as follows:

```ts
import usbV9 from '@ohos.usbV9'

try {
usbV9.getDevices(); // If an improper parameter is passed to this API, an exception will be thrown.
} catch (err) {
console.error("getDevices errCode:" + err.code + ",errMessage:" + err.message);
}
```
