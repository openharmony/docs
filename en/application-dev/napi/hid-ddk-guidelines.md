# HID DDK Development

## When to Use

The HID driver development kit (DDK) is a toolset that helps you develop HID device drivers at the application layer based on the user mode. It provides interfaces for accessing devices from a host, including creating a device, sending events to a device, and destroying a device.

## Constraints

* The open APIs of the HID DDK can be used to develop drivers of non-standard HID peripherals.

* The open APIs of the HID DDK can be used only within the DriverExtensionAbility lifecycle.

* To use the open APIs of the HID DDK, you need to declare the matching ACL permissions in **module.json5**, for example, **ohos.permission.ACCESS_DDK_HID**.

## **Available APIs**

| Name| Description|
| -------- | -------- |
| OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties) | Creates a HID device. When the device is no longer needed, use **OH_Hid_DestroyDevice** to destroy it.|
| OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length) | Sends events to a HID device.|
| OH_Hid_DestroyDevice(int32_t deviceId) | Destroys a HID device.|

For details about the APIs, see [HID DDK](../reference/apis-driverdevelopment-kit/_hid_ddk.md).

## How to Develop

The following steps you through the development of a HID device driver with the HID DDK.

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

1. Create a device.

    Use **OH_Hid_CreateDevice** in **hid_ddk_api.h** to create an HID device. If the operation is successful, **deviceId** (a non-negative number) is returned. If the operation fails, an error code (a negative number) is returned.

    ```c++
   // Construct HID device properties.
   std::vector<Hid_DeviceProp> deviceProp = {HID_PROP_DIRECT};
   std::string deviceName = "keyboard"
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
   std::vector<Hid_KeyCode> keyCode = {HID_BTN_TOOL_PEN, HID_BTN_TOOL_RUBBER, HID_BTN_TOUCH, HID_BTN_STYLUS, HID_BTN_RIGHT};
   Hid_KeyCodeArray keyCodeArray = {.hidKeyCode = keyCode.data(), .length = (uint16_t)keyCode.size()};
   std::vector<Hid_MscEvent> mscEvent = {HID_MSC_SCAN};
   Hid_MscEventArray mscEventArray = {.hidMscEvent = mscEvent.data(), .length = (uint16_t)mscEvent.size()};
   std::vector<Hid_AbsAxes> absAxes = {HID_ABS_X, HID_ABS_Y, HID_ABS_PRESSURE};
   Hid_AbsAxesArray absAxesArray = {.hidAbsAxes = absAxes.data(), .length = (uint16_t)absAxes.size()};
   Hid_EventProperties hidEventProp = {
       .hidEventTypes = eventTypeArray,
       .hidKeys = keyCodeArray,
       .hidAbs = absAxesArray,
       .hidMiscellaneous = mscEventArray
    };
    // Create a device. The device ID of the device created is returned.
    int32_t deviceId = OH_Hid_CreateDevice(&hidDevice, &hidEventProp);
    ```

2. Sends events to a HID device.

    Use **OH_Hid_EmitEvent** of **hid_ddk_api.h** to send an event to the device with the specified **deviceId**.

    ```c++
    // Construct the event to be sent.
    Hid_EmitItem event = {.type = HID_EV_MSC, .code = HID_MSC_SCAN, .value = 0x000d0042};
    std::vector<Hid_EmitItem> itemVec;
    itemVec.push_back(event);
    // Send the event to a HID device.
    int32_t ret = OH_Hid_EmitEvent(deviceId, itemVec.data(), (uint16_t)itemVec.size());
    ```

3. Release resources.

    Use **OH_Hid_DestroyDevice** of **hid_ddk_api.h** to destroy the device after all requests are processed and before the application exits.

    ```c++
    // Destroy a HID device.
    int32_t ret = OH_Hid_DestroyDevice(deviceId);
    ```
