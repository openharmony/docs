# SCSI Peripheral DDK Development

## Overview

Small Computer System Interface (SCSI) devices, such as disk arrays, tape libraries, and specific types of storage servers, are widely used in enterprise-level storage solutions and industrial application scenarios. If the operating system does not have an adaptation driver for these devices, the devices cannot be identified or used after being connected. SCSI Peripheral Driver Development Kit (DDK) is a suite provided for SCSI device driver development. It allows you to develop SCSI device drivers at the application layer based on the user mode.

The SCSI Peripheral DDK supports seven common commands (including INQUIRY, READ CAPACITY, TEST UNIT READY, REQUEST SENSE, READ, WRITE, and VERIFY) in the three command sets: SCSI Primary Commands (SPC), SCSI Block Commands (SBC), and Multimedia Commands (MMC). You can use these commands at your preference.

### Basic Concepts

Before developing the SCSI Peripheral DDK, you must understand the following basic concepts:

- **SCSI**

    SCSI is a standard protocol set used for communication between computers and peripherals such as hard disk drives, tape drives, optical disk drives, and scanners.

- **AMS**

    The Ability Manager Service (AMS) is a system service used to coordinate the running relationships of abilities and schedule the lifecycle of abilities.

- **BMS**

    The Bundle Manager Service (BMS) is responsible for application installation, uninstallation, and data management on OpenHarmony.

- **DDK**

    The Driver Development Kit (DDK) is a tool package provided by OpenHarmony for developing drivers for non-standard SCSI peripherals based on the peripheral framework.

- **Non-standard peripherals**

    Non-standard peripherals (also called custom peripherals or dedicated peripherals) are peripherals that do not comply with general standards or are customized for specific application scenarios. This type of device usually requires special software support or special interfaces to implement communication with the host system.

- **Standard peripherals**

    Standard peripherals refer to peripherals (such as USB keyboards and mouse devices) that comply with industry standards and specifications. Such devices typically have uniform interface protocols, physical dimensions, and electrical characteristics, so that they can be used interchangeably between different systems.

- **Logical block**

    A logical block is a basic data storage unit. It represents a data area of a fixed size on a device and is usually used for data read and write operations. The size of a logical block may be 512 bytes, 1024 bytes, 2048 bytes, and so on. A specific size depends on a configuration of the device and a design of the file system.

- **CDB**

    A command descriptor block (CDB) is a standard data structure used to send commands in the SCSI protocol. A CDB is a byte array with a fixed length. It contains the operation code (Opcode) and related parameters of the SCSI command and is used to instruct the device to perform operations (such as read, write, and query).

### Implementation Principles

A non-standard peripheral application obtains the SCSI device ID by using the peripheral management service, and delivers the ID and the action to the SCSI driver application through RPC. The SCSI driver application can obtain the basic information about the SCSI device and read and write data by invoking the SCSI Peripheral DDK API. Then, the DDK API uses the HDI service to deliver instructions to the kernel driver, and the kernel driver uses instructions to communicate with the device.

**Figure 1** Principle of invoking the SCSI Peripheral DDK

![SCSI_Peripheral_DDK schematic diagram](figures/ddk-schematic-diagram.png)

### Constraints

- The open APIs of SCSI Peripheral DDK support the development of standard SCSI peripheral drivers.

- The open APIs of SCSI Peripheral DDK can be used only within the lifecycle of **DriverExtensionAbility**.

- To use the open APIs of SCSI Peripheral DDK, you need to declare the corresponding ACL permission **ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL** in **module.json5**.

## Environment Setup

Before you get started, make necessary preparations by following instructions in [Environment Preparation](environmental-preparation.md).

## How to Develop

### Available APIs

| **Name**| Description|
| -------- | -------- |
| int32_t OH_ScsiPeripheral_Init(void) | Initializes the SCSI Peripheral DDK.|
| int32_t OH_ScsiPeripheral_Release(void) | Releases the SCSI Peripheral DDK.|
| int32_t OH_ScsiPeripheral_Open(uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device **dev) | Opens the SCSI device specified by **deviceId** and **interfaceIndex**.|
| int32_t OH_ScsiPeripheral_Close(ScsiPeripheral_Device **dev) | Disables the SCSI device.|
| int32_t OH_ScsiPeripheral_TestUnitReady(ScsiPeripheral_Device *dev, ScsiPeripheral_TestUnitReadyRequest *request, ScsiPeripheral_Response *response) | Checks whether the logical units are ready.|
| int32_t OH_ScsiPeripheral_Inquiry(ScsiPeripheral_Device *dev, ScsiPeripheral_InquiryRequest *request, ScsiPeripheral_InquiryInfo *inquiryInfo, ScsiPeripheral_Response *response) | Queries basic information about the SCSI device.|
| int32_t OH_ScsiPeripheral_ReadCapacity10(ScsiPeripheral_Device *dev, ScsiPeripheral_ReadCapacityRequest *request, ScsiPeripheral_CapacityInfo *capacityInfo, ScsiPeripheral_Response *response) | Obtains the capacity information about the SCSI device.|
| int32_t OH_ScsiPeripheral_RequestSense(ScsiPeripheral_Device *dev, ScsiPeripheral_RequestSenseRequest *request, ScsiPeripheral_Response *response) | Obtains sense data, that is, information returned by the SCSI device to the host, which is used to report the device status, error information, and diagnosis information.|
| int32_t OH_ScsiPeripheral_Read10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response) | Reads data from a specified logical block.|
| int32_t OH_ScsiPeripheral_Write10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response) | Writes data to a specified logical block of a device.|
| int32_t OH_ScsiPeripheral_Verify10(ScsiPeripheral_Device *dev, ScsiPeripheral_VerifyRequest *request, ScsiPeripheral_Response *response) | Verifies a specified logical block.|
| int32_t OH_ScsiPeripheral_SendRequestByCdb(ScsiPeripheral_Device *dev, ScsiPeripheral_Request *request, ScsiPeripheral_Response *response) | Sends the SCSI command in CDB mode.|
| int32_t OH_ScsiPeripheral_CreateDeviceMemMap(ScsiPeripheral_Device *dev, size_t size, ScsiPeripheral_DeviceMemMap **devMmap) | Creates a buffer.|
| int32_t OH_ScsiPeripheral_DestroyDeviceMemMap(ScsiPeripheral_DeviceMemMap *devMmap) | Destroys a buffer.|
| int32_t OH_ScsiPeripheral_ParseBasicSenseInfo(uint8_t *senseData, uint8_t senseDataLen, ScsiPeripheral_BasicSenseInfo *senseInfo) | Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.|

For details about the interface, see [SCSI Peripheral DDK](../../reference/apis-driverdevelopment-kit/_s_c_s_i.md).

### How to Develop

The following describes how to use the SCSI Peripheral DDK to develop non-standard SCSI peripheral drivers.

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.
```txt
libscsi.z.so
```

**Including Header Files**
```c++
#include <scsi_peripheral/scsi_peripheral_api.h>
#include <scsi_peripheral/scsi_peripheral_types.h>
```

1. Initialize the SCSI Peripheral DDK.

    Use **OH_ScsiPeripheral_Init** in **scsi_peripheral_api.h** to initialize the SCSI Peripheral DDK.

    ```c++
    // Initialize the SCSI Peripheral DDK.
    int32_t ret = OH_ScsiPeripheral_Init();
    ```

2. Open the device.

    After the SCSI Peripheral DDK is initialized, use **OH_ScsiPeripheral_Open** in **scsi_peripheral_api.h** to open the SCSI device.

    ```c++
    uint64_t deviceId = 0x100000003;
    uint8_t interfaceIndex = 0;
    ScsiPeripheral_Device *dev = NULL;
    // Open the SCSI device specified by deviceId and interfaceIndex1.
    ret = OH_ScsiPeripheral_Open(deviceId, interfaceIndex, &dev);
    ```

3. Create a buffer.

    Use **OH_ScsiPeripheral_CreateDeviceMemMap** in **scsi_peripheral_api.h** to create the memory buffer **devMmap**.

    ```c++
    constexpr size_t DEVICE_MEM_MAP_SIZE = 1024;
    ScsiPeripheral_DeviceMemMap *g_scsiDeviceMemMap = nullptr;
    ret = OH_ScsiPeripheral_CreateDeviceMemMap(dev, DEVICE_MEM_MAP_SIZE, &g_scsiDeviceMemMap);
    ```

4. Check whether the logical units are ready.

    Use **OH_ScsiPeripheral_TestUnitReady** in **scsi_peripheral_api.h** to check whether the logical unit is ready.

    ```c++
    ScsiPeripheral_TestUnitReadyRequest testUnitReadyRequest = {0};
    testUnitReadyRequest.timeout = 5000;
    ScsiPeripheral_Response testUnitReadyResponse = {0};
    ret = OH_ScsiPeripheral_TestUnitReady(dev, &testUnitReadyRequest, &testUnitReadyResponse);
    ```

5. Query basic information about the SCSI device.

    Use **OH_ScsiPeripheral_Inquiry** in **scsi_peripheral_api.h** to obtain the basic information about the SCSI device.

    ```c++
    ScsiPeripheral_InquiryRequest inquiryRequest = {0};
    inquiryRequest.allocationLength = 512;
    inquiryRequest.timeout = 5000;
    ScsiPeripheral_InquiryInfo inquiryInfo = {0};
    inquiryInfo.data = g_scsiDeviceMemMap;
    ScsiPeripheral_Response inquiryResponse = {0};
    ret = OH_ScsiPeripheral_Inquiry(dev, &inquiryRequest, &inquiryInfo, &inquiryResponse);
    ```

6. Obtain the capacity information about the SCSI device.

    Use **OH_ScsiPeripheral_ReadCapacity10** in **scsi_peripheral_api.h** to obtain the SCSI device capacity information.

    ```c++
    ScsiPeripheral_ReadCapacityRequest readCapacityRequest = {0};
    readCapacityRequest.lbAddress = 0;
    readCapacityRequest.control = 0;
    readCapacityRequest.byte8 = 0;
    readCapacityRequest.timeout = 5000;
    ScsiPeripheral_CapacityInfo capacityInfo = {0};
    ScsiPeripheral_Response readCapacityResponse = {0};
    ret = OH_ScsiPeripheral_ReadCapacity10(dev, &readCapacityRequest, &capacityInfo, &readCapacityResponse);
    ```

7. Obtain sense data.

    Use **OH_ScsiPeripheral_RequestSense** in **scsi_peripheral_api.h** to obtain sense data.

    ```c++
    ScsiPeripheral_RequestSenseRequest senseRequest = {0};
    senseRequest.allocationLength = SCSIPERIPHERAL_MAX_SENSE_DATA_LEN + 1;
    senseRequest.control = 0;
    senseRequest.byte1 = 0;
    senseRequest.timeout = 5000;
    ScsiPeripheral_Response senseResponse = {0};
    // Information returned by the SCSI device to the host, used to report the device status, error information, and diagnosis information.
    ret = OH_ScsiPeripheral_RequestSense(dev, &senseRequest, &senseResponse);
    ```

8. Parse the sense data.

    Use **OH_ScsiPeripheral_ParseBasicSenseInfo** in **scsi_peripheral_api.h** to parse basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.

    ```c++
    ScsiPeripheral_BasicSenseInfo senseInfo = {0};
    ret = OH_ScsiPeripheral_ParseBasicSenseInfo(senseResponse.senseData, SCSIPERIPHERAL_MAX_SENSE_DATA_LEN, &senseInfo); 
    ```

9. Read data.

    Use **OH_ScsiPeripheral_Read10** in **scsi_peripheral_api.h** to read data from a specified logical block.

    ```c++
    ScsiPeripheral_IORequest readRequest = {0};
    readRequest.lbAddress = 1;
    readRequest.transferLength = 1;
    readRequest.control = 0;
    readRequest.byte1 = 0;
    readRequest.byte6 = 0;
    readRequest.timeout = 20000;
    readRequest.data = g_scsiDeviceMemMap;
    ScsiPeripheral_Response readResponse = {0};
    ret = OH_ScsiPeripheral_Read10(dev, &readRequest, &readResponse);
    ```

10. Write data.

    Use **OH_ScsiPeripheral_Write10** in **scsi_peripheral_api.h** to write data to a specified logical block of the device.

    ```c++
    ScsiPeripheral_IORequest writeRequest = {0};
    writeRequest.lbAddress = 1;
    writeRequest.transferLength = 1;
    writeRequest.control = 0;
    writeRequest.byte1 = 0;
    writeRequest.byte6 = 0;
    writeRequest.timeout = 5000;
    writeRequest.data = g_scsiDeviceMemMap;
    ScsiPeripheral_Response writeResponse = {0};
    ret = OH_ScsiPeripheral_Write10(dev, &writeRequest, &writeResponse);
    ```

11. Verifies a specified logical block.

    Use **OH_ScsiPeripheral_Verify10** in **scsi_peripheral_api.h** to verify a specified logical block.

    ```c++
    ScsiPeripheral_VerifyRequest verifyRequest = {0};
    verifyRequest.lbAddress = 1;
    verifyRequest.verificationLength = 1;
    verifyRequest.timeout = 5000;
    ScsiPeripheral_Response verifyResponse = {0};
    ret = OH_ScsiPeripheral_Verify10(dev, &verifyRequest, &verifyResponse);
    ```

12. Send SCSI commands in CDB mode.

    Use **OH_SCSIPeripheral_SendRequestByCdb** in **scsi_peripheral_api.h** to send SCSI commands.

    ```c++
    ScsiPeripheral_Request sendRequest = {0};
    uint8_t cdbData[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN] = {0x28, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    memcpy(sendRequest.commandDescriptorBlock, cdbData, SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN);
    sendRequest.cdbLength = 10;
    sendRequest.dataTransferDirection = -3;
    sendRequest.timeout = 5000;
    sendRequest.data = g_scsiDeviceMemMap;
    ScsiPeripheral_Response sendResponse = {0};
    ret = OH_ScsiPeripheral_SendRequestByCdb(dev, &sendRequest, &sendResponse);
    ```

13. Destroy a buffer.

    After all requests are processed and before the program exits, use **OH_ScsiPeripheral_DestroyDeviceMemMap** in **scsi_peripheral_api.h** to destroy the buffer.

    ```c++
    ret = OH_ScsiPeripheral_DestroyDeviceMemMap(g_scsiDeviceMemMap);
    ```

14. Close the HID device.

    After the buffer is destroyed, use **OH_ScsiPeripheral_Close** in **scsi_peripheral_api.h** to close the device.

    ```c++
    // Stop the SCSI device.
    ret = OH_ScsiPeripheral_Close(&dev);
    ```

15. Release the SCSI Peripheral DDK.

    After the SCSI device is closed, use **OH_ScsiPeripheral_Release** in **scsi_peripheral_api.h** to release the SCSI Peripheral DDK.

    ```c++
    // Release the SCSI Peripheral DDK.
    ret = OH_ScsiPeripheral_Release();
    ```

### Debugging and Verification

Upon completion of driver application development, you can install the application on the OpenHarmony device. The test procedure is as follows:

1. Click the driver application on the device. The application is started on the device.
2. Check whether the application can read the basic information about the SCSI device.
3. Select a SCSI command, enter parameters, and click the **Send** button.
4. (Optional) Set the direction, CDB data, and CDB length, and click the **Send** button to run the corresponding SCSI command.
