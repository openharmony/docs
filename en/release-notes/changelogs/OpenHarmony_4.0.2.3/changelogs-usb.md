# USB Subsystem API Changelog

## cl.usb_manager.1 Bundle Name Change

For applications developed based on earlier versions, you need to change the name of the imported bundle. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

|       Original Bundle Name       |    New Bundle Name          |
|------------------  | ------------------- | 
| ohos.usbV9.d.ts | ohos.usbManager.d.ts | 

**Adaptation Guide**

Change **@ohos.usbV9** to **@ohos.usbManager** when importing the bundle.

## cl.usb_manager.2 API Parameter Type Change

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
