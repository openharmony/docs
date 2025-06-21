# Peripheral Management Module Changelog

## cl.usbddk.1 Change in the Return Value When Incorrect Parameters Are Passed to SendPipeRequest and SendPipeRequestWithAshmem

**Access Level**

Public API

**Reason for the Change**

When **OH_Usb_SendPipeRequest** or **OH_Usb_SendPipeRequestWithAshmem** is called, if the length of **bufferlen** in **devMmap** is greater than the value of **MaxPacketSize**, the API call fails but no error is reported.

**Change Impact**

This change does not require application adaptation.

Before change: If data transfer is interrupted because incorrect parameters are passed to **OH_Usb_SendPipeRequest** or **OH_Usb_SendPipeRequestWithAshmem**, the API call fails but no error is reported.

After change: If data transfer is interrupted because incorrect parameters are passed to **OH_Usb_SendPipeRequest** or **OH_Usb_SendPipeRequestWithAshmem**, the API call fails and an error is reported.

**Start API Level**

SendPipeRequest : API version 10

SendPipeRequestWithAshmem: API version 12

**Change Since**

OpenHarmony 6.0.0.32.

**Key API/Component Changes**

drivers/external_device_manager: OH_Usb_SendPipeRequest and OH_Usb_SendPipeRequestWithAshmem

**Adaptation Guide**

The API functions remain unchanged as long as correct parameters are passed to **OH_Usb_SendPipeRequest** and **OH_Usb_SendPipeRequestWithAshmem**. Therefore, adaptation is not required.

Sample code:

```C
    ...
    static uint8_t g_configIndex = 0;
    static uint64_t g_interfaceHandle = 0;
    static std::tuple<bool, uint8_t, uint8_t, uint16_t> FindForEachInterface(const UsbDdkInterface &interface)
    {
        struct UsbDdkInterfaceDescriptor *intDesc = interface.altsetting;
        uint32_t numSetting = interface.numAltsetting;
        for (uint32_t setIdx = PARAM_0; setIdx < numSetting; ++setIdx) {
            uint32_t numEp = intDesc[setIdx].interfaceDescriptor.bNumEndpoints;
            struct UsbDdkEndpointDescriptor *epDesc = intDesc[setIdx].endPoint;
            for (uint32_t epIdx = PARAM_0; epIdx < numEp; ++epIdx) {
                if (!IsInterruptInEndpoint(epDesc[epIdx].endpointDescriptor)) {
                    continue;
                }
                return { true, intDesc[setIdx].interfaceDescriptor.bInterfaceNumber,
                    epDesc[epIdx].endpointDescriptor.bEndpointAddress, epDesc[epIdx].endpointDescriptor.wMaxPacketSize };
            }
        }
        return { false, {}, {}, {} };
    }

    static std::tuple<bool, uint8_t, uint8_t, uint16_t> GetEndpointInfo(const struct UsbDdkConfigDescriptor *config)
    {
        for (uint32_t intIdx = PARAM_0; intIdx < config->configDescriptor.bNumInterfaces; ++intIdx) {
            auto result = FindForEachInterface(config->interface[intIdx]);
            if (std::get<0>(result)) {
                return result;
            }
        }
        return { false, {}, {}, {} };
    }

    struct UsbDdkConfigDescriptor *config = nullptr;
    // Obtain the device ID by calling the ArkTS queryDevice.
    int32_t ret = OH_Usb_GetConfigDescriptor(deviceId, g_configIndex, &config);
    if (ret != USB_DDK_SUCCESS) {
        // Print the error information for the OH_Usb_GetConfigDescriptor call failure.
        return;
    }

    // Obtain the value of maxPktSize by parsing config.
    auto [result, interface, endpoint, maxPktSize] = GetEndpointInfo(config);
    if (!result) {
        // Print the error information for the GetEndpointInfo call failure.
        return;
    }

    ret = OH_Usb_ClaimInterface(deviceId, interface, &g_interfaceHandle);
    if (ret != USB_DDK_SUCCESS) {
        // Print the error information for the OH_Usb_ClaimInterface call failure.
        return;
    }

    // Call OH_Usb_SendPipeRequest.
    struct UsbDeviceMemMap *devMemMap = nullptr;
    size_t bufferLen = maxPktSize;
    ret = OH_Usb_CreateDeviceMemMap(deviceId, bufferLen, &devMemMap);
    if (ret != USB_DDK_SUCCESS) {
        // Print the error information for the OH_Usb_CreateDeviceMemMap call failure.
        return;
    }
    struct UsbRequestPipe pipe;
    pipe.interfaceHandle = g_interfaceHandle;
    pipe.endpoint = endpoint;
    pipe.timeout = UINT32_MAX;
    ret = OH_Usb_SendPipeRequest(&pipe, devMemMap);
    ...

    // Call OH_Usb_SendPipeRequestWithAshmem.
    size_t bufferLen = maxPktSize;
    const uint8_t name[100] = "TestAshmem";
    DDK_Ashmem *ashmem = nullptr;
    int32_t result = OH_DDK_CreateAshmem(name, bufferLen, &ashmem);
    if (result != USB_DDK_SUCCESS) {
        // Print the error information for the OH_DDK_CreateAshmem call failure.
        return;
    }
    const uint8_t ashmemMapType = 0x03;
    result = OH_DDK_MapAshmem(ashmem, ashmemMapType);
    if (result != USB_DDK_SUCCESS) {
        // Print the error information for the OH_DDK_MapAshmem call failure.
        return;
    }
    struct UsbRequestPipe pipe;
    pipe.interfaceHandle = g_interfaceHandle;
    pipe.endpoint = endpoint;
    pipe.timeout = UINT32_MAX;
    int32_t returnValue = OH_Usb_SendPipeRequestWithAshmem(&pipe, ashmem);
    ...
```
