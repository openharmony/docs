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

For details, see the [API Reference](../../../application-dev/reference/apis/js-apis-usbManager.md).


## cl.usb_manager.2 Bundle Name Change

For applications developed based on earlier versions, you need to change the name of the imported bundle. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

|       Original Bundle       |    New Bundle           |
|------------------  | ------------------- | 
| ohos.usbV9.d.ts | ohos.usbManager.d.ts | 

**Adaptation Guide**

Change **@ohos.usbV9** to **@ohos.usbManager** when importing the bundle.

## cl.usb_manager.3 API Parameter Type Change

For applications developed based on earlier versions, you need to modify the parameter type. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

|   Original Class Name  |   New Class Name  | 
|---------------| ------------- |
| interface USBConfig | interface USBConfiguration | 

|   Original Namespace  |   New Namespace  | 
|---------------| ------------- |
| @namespace usbV9 | @namespace usbManager | 

| Bundle Name           | Original API                                                      | New API                                                      |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.usbManager.d.ts | function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number; | function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number; | 

**Adaptation Guide**

When calling **setConfiguration**, change the parameter type from **USBConfig** to **USBConfiguration**.


## cl.usb_manager.4 SDK API Deletion

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

For details, see the [API Reference](../../../application-dev/reference/apis/js-apis-usbManager.md).
