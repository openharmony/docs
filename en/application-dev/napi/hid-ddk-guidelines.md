# HID DDK Development

## When to Use

The HID driver development kit (HID DDK) is a toolset that helps you develop HID device drivers at the application layer based on the user mode. It provides interfaces for accessing devices from a host, including creating a device, sending an event to a device, and destroying a device after use.

## Available APIs

| Name| Description|
| -------- | -------- |
| OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties) | Creates an HID device. After the device is used, use **OH_Hid_DestroyDevice** to destroy the device.|
| OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length) | Sends an event to the HID device with the specified ID.|
| OH_Hid_DestroyDevice(int32_t deviceId) | Destroys an HID device.|

For details about the APIs, see [HID DDK](../reference/native-apis/_hid_ddk.md).

## How to Develop

The following steps you through the development of an HID device driver with the HID DDK.

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.
```txt
libhid.z.so
```

**Including Header Files**
```c++
#include <hid/hid_ddk_api.h>
#include <hid/hid_ddk_types.h>
```

1. Create a device.<br>Use **OH_Hid_CreateDevice** of **hid_ddk_api.h** to create an HID device. If the operation is successful, **deviceId** is returned. If the operation fails, an error code (negative number) is returned.

    ```c++
   // Construct HID device properties.
   std::vector<Hid_DeviceProp> deviceProp = {HID_PROP_DIRECT};
   Hid_Device hidDevice = {
       .deviceName = deviceName.c_str(), 
       .vendorId = 0x6006, 
       .productId = 0x6006, 
       .version = 1, 
       .bustype = 3,
       .properties = deviceProp.data(),
       .propLength = (uint16_t)deviceProp.size()
   };
   // Construct the event properties related to the HID device.
   std::vector<Hid_EventType> eventType = {HID_EV_ABS, HID_EV_KEY, HID_EV_SYN, HID_EV_MSC};
   Hid_EventTypeArray eventTypeArray = {.hidEventType = eventType.data(), .length = (uint16_t)eventType.size()};
   std::vector<Hid_KeyCode> keyCode = {HID_BTN_TOOL_PEN, HID_BTN_TOOL_RUBBER, HID_BTN_TOUCH,        HID_BTN_STYLUS, HID_BTN_RIGHT};
   Hid_KeyCodeArray keyCodeArray = {.hidKeyCode = keyCode.data(), .length = (uint16_t)keyCode.size()};
   std::vector<Hid_MscEvent> mscEvent = {HID_MSC_SCAN};
   Hid_MscEventArray mscEventArray = {.hidMscEvent = mscEvent.data(), .length = (uint16_t)mscEvent.size()};
   std::vector<Hid_AbsAxes> absAxes = {HID_ABS_X, HID_ABS_Y, HID_ABS_PRESSURE};
   Hid_AbsAxesArray absAxesArray = {.hidAbsAxes = absAxes.data(), .length = (uint16_t)absAxes.size()};
   Hid_EventProperties hidEventProp = { 
       .hidEventTypes = eventTypeArray, 
       .hidKeys = keyCodeArray, 
       .hidAbs = absAxesArray,
       .hidMiscellaneous=mscEventArray
    };
    // Create a device. The device ID of the device created is returned.
    int32_t deviceId = OH_Hid_CreateDevice(hidDevice, hidEventProperties);
   ```

2. Send an event to an HID device.<br>Use **OH_Hid_EmitEvent** of **hid_ddk_api.h** to send an event to the device with the specified **deviceId**.

    ```c++
    // Construct the event to be sent.
    Hid_EmitItem event = {.type = HID_EV_MSC, .code = HID_MSC_SCAN, .value = 0x000d0042};
    std::vector<Hid_EmitItem> itemVec;
    itemVec.push_back(event);
    // Send the event to an HID device.
    int32_t ret = OH_Hid_EmitEvent(deviceId, itemVec.data(), (uint16_t)itemVec.size());
    ```

3. Release resources.<br>Use **OH_Hid_DestroyDevice** of **hid_ddk_api.h** to destroy the device after all requests are processed and before the application exits.

    ```c++
    // Destroy an HID device.
    int32_t ret = OH_Hid_DestroyDevice(deviceId);
    ```
<!--no_check-->