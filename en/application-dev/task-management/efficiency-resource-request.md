# Requesting Efficiency Resources (ArkTS) (for Privileged System Applications Only)

## Overview

### Introduction

Some system applications need to run for an extended period of time to provide basic system functions. For example, to maintain the connection between the system and server, the application that provides the default persistent connection push service must send heartbeat messages to the server at a short interval. To prevent the application process from being suspended, the application can request efficiency resources.

### Basic Concepts

- **APIs for requesting efficiency resources**: APIs used by a system application to request energy resources for its processes. An application or process can request CPU resources to prevent itself from being suspended.

- **Privileged system application**: a system application that is configured with the [runningResourcesApply privilege](../../device-dev/subsystems/subsys-app-privilege-config-guide.md#device-specific-application-privileges).

### Constraints

- Efficiency resources can be used only by privileged system applications.

- CPU resources can be requested by process or application. Other resources can be requested only by application.

## Available APIs

**Table 1** Main APIs for efficiency resources

The table below lists the main APIs used for efficient resources. For details about more APIs and their usage, see [Background Task Management](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager-sys.md).

| API| Description|
| -------- | -------- |
| applyEfficiencyResources(request: EfficiencyResourcesRequest): void | Requests efficiency resources.|
| resetAllEfficiencyResources(): void | Releases all efficiency resources.|

**Table 2** Parameters for requesting efficiency resources
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| resourceTypes | number | Yes| Type of the resource to request.|
| isApply | boolean | Yes| Whether the request is used to apply for resources.<br>- **true**: The request is used to apply for resources.<br>- **false**: The request is used to release resources.|
| timeOut | number | Yes| Duration for which the resource will be used, in milliseconds.|
| isPersist | boolean | No| Whether the resource is permanently held. The default value is **false**.<br>- **true**: The resource is permanently held.<br>- **false**: The resource is held for a limited period of time.|
| isProcess | boolean | No| Whether the request is initiated by a process. The default value is **false**.<br>- **true**: The request is initiated by a process.<br>- **false**: The request is initiated by an application.|
| reason | string | Yes| Reason for requesting the resource.|

**Table 3** Efficiency resource types
| Name| Value| Description|
| -------- | -------- | -------- |
| CPU | 1 | CPU resource. Such type of resource prevents an application from being suspended.|
| COMMON_EVENT | 2 | Common event resource. Such type of resource ensures that an application in the suspended state can receive common events.|
| TIMER | 4 | Timer resource. Such type of resource ensures that an application in the suspended state can be woken up by system timers.|
| WORK_SCHEDULER | 8 | Deferred task resource. Such type of resource provides a loose control policy for an application.|
| BLUETOOTH | 16 | Bluetooth resource. Such type of resource ensures that an application in the suspended state can be woken up by Bluetooth-related events.|
| GPS | 32 | GPS resource. Such type of resource ensures that an application in the suspended state can be woken up by GPS-related events.|
| AUDIO | 64 | Audio resource. Such type of resource prevents an application from being suspended when the application has an audio being played.|
| RUNNING_LOCK<sup>10+</sup> | 128 | RUNNING_LOCK resource. Such type of resources prevents locks running in the background from being temporarily released when the application is suspended.|
| SENSOR<sup>10+</sup> | 256 | Sensor resource. Such type of resources prevents sensor callbacks from being intercepted.|

## How to Develop

1. Import the module.

   ```ts
   import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Request efficiency resources.

   ```ts
   // The application needs to remain active in the background.
   let request: backgroundTaskManager.EfficiencyResourcesRequest = {
     resourceTypes: backgroundTaskManager.ResourceType.CPU, // The resource type is CPU, which prevents the application process from being suspended.
     isApply: true, // The request is used to apply for the resources.
     timeOut: 0, // Timeout interval. Resources are automatically released when the timeout interval expires.
     reason: "apply", // Reason for the request.
     isPersist: true, // The resources are permanently held.
     isProcess: false, // The request is initiated by an application.
   };
   try {
     backgroundTaskManager.applyEfficiencyResources(request);
     console.info("Succeeded in invoking applyEfficiencyResources.");
   } catch (error) {
     console.error(`Operation applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   ```

3. Release the efficiency resources. After completing work in the background, the application should release the resources in a timer manner. It can release some or all resources.

   ```ts
   // The application releases all the efficiency resources.
   try {
     backgroundTaskManager.resetAllEfficiencyResources();
     console.info("Succeeded in invoking resetAllEfficiencyResources.");
   } catch (error) {
     console.error(`Operation resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   // The application releases some efficiency resources.
   let request: backgroundTaskManager.EfficiencyResourcesRequest = {
     resourceTypes: backgroundTaskManager.ResourceType.CPU,
     isApply: false, // The request is used to release resources.
     timeOut: 0,
     reason: "apply",
     isPersist: true,
     isProcess: false, // The request is initiated by an application.
   };
   try {
     backgroundTaskManager.applyEfficiencyResources(request);
     console.info("Succeeded in invoking applyEfficiencyResources.");
   } catch (error) {
     console.error(`Operation applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
   }
   ```

   > **NOTE**
   > Applications can dynamically request efficiency resources. Therefore, it is recommended that the application proactively releases the resources after the task is complete so as to reduce power consumption and ensure smooth user experience.
