# SystemCapability

<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @mgy917-->
<!--Designer: @jiangwensai-->
<!--Tester: @Lyuxin-->
<!--Adviser: @RayShih-->
<!-- md-trans-meta sourceCommit=49ccb69ba4ecc6a5565616c00b758158767a7282 translatedAt=2026-08-18T15:27:54.016Z pushedAt=2026-08-19T02:43:02.594Z -->

This document systematically describes the definition and purpose of SystemCapability (SysCap), as well as the adaptation development strategies in single-device and multi-device app development scenarios.

## What Is SystemCapability (SysCap)

SystemCapability, hereinafter referred to as SysCap, identifies a collection of APIs that implement a specific open capability, as shown in the following figure.


Take the Bluetooth SysCap named SystemCapability.Communication.Bluetooth.Core as an example. It represents a set of Bluetooth capability-related APIs, including:

- Bluetooth device scanning APIs

- Bluetooth device pairing and connection APIs

- Data sending and receiving APIs

- Bluetooth state management APIs, etc.

## Purpose of SysCap

The purposes of SysCap are as follows:

1. Primary responsibility: isolate the open capability differences between device types.

   Still using Bluetooth as an example, different device types support Bluetooth differently. To help developers determine whether related APIs are available, the SysCap mechanism is introduced.

   Developers can use the [canIUse](../reference/common/js-apis-syscap.md#caniuse) API to determine whether the open capability API collection represented by a specified SysCap can be called on the target device type.

2. Secondary responsibility: classify features.

   The open capability API collection represented by each SysCap corresponds to an independent functional feature in the operating system. For example, the API collection identified by the Bluetooth SysCap mentioned above logically belongs to "Bluetooth core communication capability".

> **NOTE**
> 
> Different product models of the same device type may have inconsistent software and hardware specifications. Therefore, developers need to use canIUse and the capability query interface to determine availability before using an API. For example, some phones do not support the POI feature. Therefore, developers need to first use canIUse to determine whether SystemCapability.Location.Location.Core can be called on the phone, and then use [geoLocationManager.isPoiServiceSupported](apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerispoiservicesupported20) to query whether the system (that is, the software) supports the POI service. Only after all these are supported can developers use POI-related APIs normally. For details, see [SysCap Adaptation App Development](#syscap-adaptation-app-development).

## Relationship Between SysCap, SDK, and Kit

SysCap, SDK, and Kit form a structured and hierarchical architecture, as shown in the following figure:
 

1. The SDK consists of multiple functionally independent Kits.

2. Each Kit contains one or more SysCaps, and each SysCap belongs to only one Kit.

3. Each SysCap identifies/represents one or more APIs.

This structured design enables developers to precisely and efficiently locate and call the required APIs through the intelligent prompts and auto-completion of development tools (such as DevEco Studio) when writing code, significantly reducing the risk of misuse and improving development efficiency.

Take the Tablet device as an example. If a developer imports the specific content of a module starting with "a" in an .ets file (for example, interfaces, classes, functions, variables, objects, etc.), DevEco Studio auto-completes all the specific content of the module that is available on the Tablet, as shown in the following figure:
 

## Relationship Between SysCap and Device Type

In the "device-define" folder of the SDK, JSON files define the SysCap collection supported by each device type. For example, the tablet.json file defines that the Tablet device supports SysCaps such as SystemCapability.ArkUI.ArkUI.Full and SystemCapability.Communication.NFC.Core, as shown in the following figure:


When creating a project in DevEco Studio, developers need to select the device type of the app:


Alternatively, after creating a project, developers can specify the device types supported by the app by modifying [deviceTypes](../quick-start/module-configuration-file.md#devicetypes) in the module.json5 file:


DevEco Studio automatically identifies the device types in the project, locates the corresponding SysCap collection under "device-define" in the SDK, and then extracts the APIs supported by the device for intelligent prompts and auto-completion, helping developers precisely and efficiently call the required APIs.

> **NOTE**
>
> When there are multiple device types, the SysCap collection identified by DevEco Studio is the union of these device types.

## SysCap Adaptation App Development

As described above, SysCap is a mechanism for isolating open capability differences between device types. However, in actual app development, after completing the isolation determination at the SysCap level, developers also need to pay attention to the following:

1. Different device models of the same device type may cause some APIs under the same SysCap to be called abnormally due to factors such as hardware configuration differences.

2. The same device model may cause some APIs under the same SysCap to be called abnormally due to dynamic hardware changes (such as pluggable devices).

Therefore, in actual app development, developers need to perform related code adaptation development to ensure that the app provides a good and stable user experience on various devices.

Adaptation development mainly includes the following four parts.

### Using canIUse to Determine Whether a SysCap Can Be Called

Use the [canIUse](../reference/common/js-apis-syscap.md#caniuse) API to determine whether the API collection corresponding to a SysCap can be called: true indicates that it can be called, and false indicates that it cannot be called (the SysCap is not included in the corresponding device type).

**ArkTS API Usage Example**

```js
if (canIUse("SystemCapability.Location.Location.Core")) {
 console.info("The device supports SystemCapability.Location.Location.Core");
} else {
 console.info("The device does not support SystemCapability.Location.Location.Core");
}
```

**Native API Usage Example**

```c++
#include <stdio.h>
#include <stdlib.h>
#include "syscap_ndk.h"

char syscap[] = "SystemCapability.ArkUI.ArkUI.Full";
bool result = canIUse(syscap);
if (result) {
 printf("SysCap: %s is supported!\n", syscap);
} else {
 printf("SysCap: %s is not supported!\n", syscap);
}
```

### Using the Capability Query Interface to Determine Whether an API Is Available

Use system-side APIs such as isXXXAvailable(), isXXXSupported(), and canMakeXXX() to determine whether an API is available.

> **NOTE**
>
> Not all APIs have a capability query interface. If the API to be verified does not have a capability query interface, you can determine whether the API is available through proactive listening or error code exception handling.

```javascript
import { geoLocationManager } from '@kit.LocationKit';

if (!canIUse("SystemCapability.Location.Location.Core")) { // First, determine whether the capability collection is available. This step applies only to multi-device application development and can be skipped in single-device application development.
  return;
}
try {
  if (geoLocationManager.isPoiServiceSupported()) { // Then, query the POI service capability.
    geoLocationManager.getPoiInfo().then((poiInfo) => { // After confirming that the capability is supported, call the API to obtain location information.
      if (poiInfo !== undefined) {
        console.info("get PoiInfo:" + JSON.stringify(poiInfo));
      }
    })
  }
} catch (error) {
  console.error("getPoiInfo errCode:" + error.code + ", errMessage:" + error.message);
}
```

### Proactively Listening for Extended Capability Changes

In hardware dynamic extension scenarios, plugging or unplugging some hardware causes capability changes. Developers can proactively listen for extended capability changes.

For example, for a USB camera, there are dynamic plugging and unplugging scenarios. The system provides the on listening API to support developers in handling dynamic changes of the camera device.

```javascript
import { BusinessError } from '@kit.BasicServicesKit';
import { camera } from '@kit.CameraKit';

callback(err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error('cameraStatus with errorCode = ' + err.code);
    return;
  }
  console.info(`camera : ${cameraStatusInfo.camera.cameraId}, status: ${cameraStatusInfo.status}`);
}
registerCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', this.callback); // Listen for the camera status to handle dynamic hardware devices.
}
```

### Error Code Exception Handling

To handle exceptions that may occur when calling APIs, developers also need to perform error code exception handling.

1. Synchronous APIs must use try...catch to handle exceptions to avoid app crashes. 

   ```javascript
   import { omapi } from '@kit.ConnectivityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   let seService : omapi.SEService;
   let seReaders : omapi.Reader[];
   
   // Initialize seService before using it.
   function secureElementDemo() {
     // Obtain the readers.
     try {
       seReaders = seService.getReaders();
     } catch (error) {
      if(error.code=== 801) {
       console.error('This device does not support this capability');
      }
     }
   }
   ```

2. Asynchronous APIs use .catch to capture asynchronous exceptions. Developers can also choose not to handle exceptions, and the app will not crash. 

   ```javascript
   import { media } from '@kit.MediaKit';

   let avScreenCaptureRecorder: media.AVScreenCaptureRecorder | undefined;
   media.createAVScreenCaptureRecorder().then((captureRecorder: media.AVScreenCaptureRecorder) => {
     // Execute normal business.
     if (captureRecorder != null) {
       avScreenCaptureRecorder = captureRecorder;
       console.info('Succeeded in creating avScreenCaptureRecorder');
     } else {
       console.error('Failed to create avScreenCaptureRecorder');
     }
   }).catch((error: BusinessError) => {
     // Handle business logic errors.
     console.error(`createAVScreenCaptureRecorder catchCallback, error message:${error.message}`);
   });
   ```

3. Use global capture to add an exception capture listener globally, which can capture exceptions not caught by try...catch. After adding it, the app will not exit proactively when an exception is thrown. For details, see [errorManager.on('error')](apis-ability-kit/js-apis-app-ability-errorManager.md#errormanageronerror).

## Adaptation Development in Single-Device and Multi-Device App Development Scenarios

App development can be divided into the following:

1. Single-device app development: the Device type of the app project is configured with only one device type.

2. Multi-device app development: the Device type of the app project is configured with multiple device types.

### Adaptation Development in Single-Device App Development Scenarios

In single-device app development, DevEco Studio identifies only one device type. The adaptation development process is shown in the following figure:


1. If an API has inconsistent capabilities across different device models of the same device type, use the capability query interface to determine the API capability availability. (Note: The capability query mechanism here is not canIUse. For details, see [Using the Capability Query Interface to Determine Whether an API Is Available](#using-the-capability-query-interface-to-determine-whether-an-api-is-available).)

2. To avoid exceptions when calling APIs, developers need to perform error code exception handling.

### Adaptation Development in Multi-Device App Development Scenarios

In multi-device app development, DevEco Studio needs to identify multiple device types simultaneously. The adaptation development process is shown in the following figure:


1. Use canIUse to determine whether the SysCap collection within the union but outside the intersection is available. 

   - canIUse applies only to multi-device app development. In single-device app development, you can directly query the API capability.

   - In multi-device app development scenarios, when the device type to which a SysCap belongs is within the union of the [deviceTypes](../quick-start/module-configuration-file.md#devicetypes) selection range and the API support range but not within their intersection (for example, the device types selected are Phone/Tablet, but the API supports only Phone/2in1), you must use canIUse to verify availability.

2. If an API has inconsistent capabilities across different device models of the same device type, use the capability query interface to determine the API capability availability. (Note: The capability query mechanism here is not canIUse.)

3. To avoid exceptions when calling APIs, perform error code exception handling.