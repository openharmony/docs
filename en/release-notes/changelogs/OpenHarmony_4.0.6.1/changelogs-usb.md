# USB Subsystem API Changelog

## cl.usb_manager.1 SDK API Deletion

For applications developed based on earlier versions, you need to change the name of the imported bundle. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The **@ohos.usbV9.d.ts** file is replaced by the **@ohos.usbManager.d.ts** file.

|         New Bundle        |     Original Bundle   |    Deleted Bundle   |
| -------------------- | ------------- | --------------- |
| ohos.usbManager.d.ts | ohos.usb.d.ts | ohos.usbV9.d.ts |

You need to import **@ohos.usbManager** to use USB service APIs.

  ```ts
  import usbManager from '@ohos.usbManager';
  ```

**Adaptation Guide**

For details about usage of each API, see the [API Reference](../../../application-dev/reference/apis/js-apis-usbManager.md).
