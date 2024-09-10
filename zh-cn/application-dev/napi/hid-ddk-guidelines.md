# HID DDK开发指导

## 场景介绍

HID DDK（HID Driver Develop Kit）是为开发者提供的HID设备驱动程序开发套件，支持开发者基于用户态，在应用层开发HID设备驱动。提供了一系列主机侧访问设备的接口，包括创建设备、向设备发送事件、销毁设备。

## 约束与限制

* HID DDK开放API支持非标HID类外设扩展驱动开发场景。

* HID DDK开放API使用范围内仅允许DriverExtensionAbilit生命周期内使用。

* 使用HID DDK开放API需要在module.json5中声明匹配的ACL权限，例如ohos.permission.ACCESS_DDK_HID。

## 接口说明

| 名称 | 描述 |
| -------- | -------- |
| OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties) | 创建HID设备。请在设备使用完后使用OH_Hid_DestroyDevice销毁设备 |
| OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length) | 向指定deviceId的HID设备发送事件。 |
| OH_Hid_DestroyDevice(int32_t deviceId) | 销毁指定deviceId的HID设备。 |

详细的接口说明请参考[HID DDK](../reference/apis-driverdevelopment-kit/_hid_ddk.md)。

## 开发步骤

以下步骤描述了如何使用 **HID DDK**开发HID设备驱动：

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libhid.z.so
```

**头文件**
```c++
#include <hid/hid_ddk_api.h>
#include <hid/hid_ddk_types.h>
```

1. 创建设备。

    使用 **hid_ddk_api.h** 的 **OH_Hid_CreateDevice** 接口创建HID设备，成功返回设备deviceId（**非负数**），失败返回错误码（**负数**）。

    ```c++
   // 构建HID设备属性
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
   // 构建HID设备关注的事件属性
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
    // 创建设备并获取到deviceId
    int32_t deviceId = OH_Hid_CreateDevice(&hidDevice, &hidEventProp);
    ```

2. 向指定deviceId的HID设备发送事件。

    使用 **hid_ddk_api.h** 的 **OH_Hid_EmitEvent** 向指定的deviceId的设备发送事件。

    ```c++
    // 构建需要发送事件
    Hid_EmitItem event = {.type = HID_EV_MSC, .code = HID_MSC_SCAN, .value = 0x000d0042};
    std::vector<Hid_EmitItem> itemVec;
    itemVec.push_back(event);
    // 向指定deviceId的HID设备发送事件
    int32_t ret = OH_Hid_EmitEvent(deviceId, itemVec.data(), (uint16_t)itemVec.size());
    ```

3. 释放资源。

    在所有请求处理完毕，程序退出前，使用 **hid_ddk_api.h** 的 **OH_Hid_DestroyDevice** 接口销毁HID设备。

    ```c++
    // 销毁HID设备
    int32_t ret = OH_Hid_DestroyDevice(deviceId);
    ```
