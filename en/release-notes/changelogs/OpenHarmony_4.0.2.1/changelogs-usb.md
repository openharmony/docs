# USB Subsystem API Changelog

## cl.usb_manager.1 System API Change

Runtime authentication is performed for system APIs of the USB manager. An asynchronous API throws an error code via **Promise.reject**.

If your application is developed based on earlier versions, modify the return values of functions. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

| Bundle Name           | Original API                                                      | New API                                                      |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.usbV9.d.ts | function setCurrentFunctions(funcs: FunctionType): Promise<boolean>; | function setCurrentFunctions(funcs: FunctionType): Promise<void>; |
| ohos.usbV9.d.ts | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<boolean>; | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<void>; |

## cl.usb_manager.2 SDK API Deletion

The **@ohos.usbV9.d.ts** file was deleted in OpenHarmony 4.0.5.5.

You need to import **@ohos.usbManager** to use USB service APIs.

  ```ts
  import usbManager from '@ohos.usbManager';
  ```

**Adaptation Guide**

For details about usage of each API, see the [API Reference](../../../application-dev/reference/apis/js-apis-usbManager.md).
