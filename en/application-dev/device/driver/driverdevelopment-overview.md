# About This Kit

<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=0bd849420b8023922f904909cad7f1ce911d0c8d translatedAt=2026-07-28T02:35:23.664Z pushedAt=2026-07-28T02:55:15.113Z -->

Driver Development Kit (DDK) provides peripheral driver developers with efficient, secure, and feature-rich extended peripheral driver development solutions — ArkTS APIs and C APIs — enabling a seamless plug-and-play experience for end users.

## When to Use

With DDK, you can develop dedicated or extended peripheral drivers in an efficient and secure manner.

1. Professional and dedicated office peripheral driver development

   For example, professional and dedicated peripherals used in scenarios such as banking counters, enterprise offices, and medical testing, including high-speed document cameras, ID card scanners, fingerprint recognition devices, and blood oxygen/glucose monitoring devices.

2. Capability expansion for customized peripheral extensions

   For example, scenarios where vendors open enhanced capabilities for private non-standard HID peripherals, including shortcut customization for writing tablets, pressure sensitivity/drawing area configuration, extended capability settings, mouse lighting effect settings, mouse extra button customization, and advanced settings such as DPI and X/Y axes.

## Typical Use Cases

- You can develop advanced peripheral functions to meet user requirements.

- The extended driver framework supports lifecycle management of peripheral drivers and provides APIs for querying and binding peripheral devices.

## Basic Concepts

- Peripheral driver client: [basic UI-based driver](externaldevice-guidelines.md), which is used to query and bind drivers, and customize the communication mode and data processing mode.

- Peripheral driver: [basic UI-free driver](driverextensionability.md), which is the dedicated peripheral driver or enhanced peripheral driver developed based on DDK.

- External Device Manager: performs lifecycle management of peripheral devices and driver packages.

- Bundle Manager Service (BMS): manages application installation, uninstallation, and data on the system.

- Ability Manager Service (AMS): used to start and stop **DriverExtensionAbility**.

- System Ability (SA): a system service that provides basic system capabilities for devices. For example, the driver extension SA is a system service that provides extended drivers for non-standard peripherals.

- Non-standard peripheral: a peripheral that uses non-standard protocols (also called vendor-defined protocols) for communication.

## Implementation Principles

The HDF extended driver framework provides unified APIs for you to leverage the DDK capabilities for user-mode peripheral driver development.

External Device Manager, the core service of user-mode peripheral management, performs lifecycle management of peripherals and peripheral drivers. In addition, standard ArkTS APIs are provided to query, bind, and unbind peripherals.

### Peripheral Driver Architecture

  **Figure 1** Peripheral driver working mechanism 

![driverExtension](figures/driverExtension.png)

### Operation Process

Figure 2 shows the process for matching a peripheral driver client with a peripheral driver when a peripheral is connected.

**Figure 2** Process for matching a peripheral driver client with a peripheral driver

![timeSeries1](figures/timeSeries1.png)

Figure 3 shows the process for binding the peripheral driver client with a peripheral driver.

**Figure 3** Process of binding the peripheral driver client with a peripheral driver

![timeSeries2](figures/timeSeries2.png)

## Notes and Constraints

To call the ArkTS or C APIs provided by DDK, you need to apply for specified permissions.

The following table lists the required permissions.

| API Type| DDK Type| Permission|
| --------- | --------- | --------- |
| ArkTS-API | N/A | ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER |
| C-API     | UsbDdk | ohos.permission.ACCESS_DDK_USB |
| C-API     | HidDdk | ohos.permission.ACCESS_DDK_HID |
| C-API     | USBSerialDDK | ohos.permission.ACCESS_DDK_USB_SERIAL |
| C-API     | ScsiPeripheralDDK | ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL |

<!--RP1--><!--RP1End-->

For API call restrictions of DriverExtensionAbility, see [Constraints](../../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md#constraints) in the API reference.

## Associated Modules

The following table lists the associated modules you may use during development of peripheral drivers.

| Name| Description|
| --------- | --------- |
| PerformanceAnalysisKit | Introduces [hilog](../../reference/apis-performance-analysis-kit/js-apis-hilog.md) for log printing.|
| BasicServicesKit       | Introduces [BusinessError](../../reference/apis-basic-services-kit/js-apis-base.md#businesserror) to capture error information. |
| IPCKit                 | Introduces [rpc](../../reference/apis-ipc-kit/js-apis-rpc.md) to implement inter-process communication between the driver and the client.|
| AbilityKit             | Introduces [@ohos.application.Want (Want)](../../reference/apis-ability-kit/js-apis-application-want.md) for lifecycle management.|

## Driver Application Specifications

1. Driver application definition

- A driver application is a user-mode driver developed based on DDK for non-standard peripherals.

- Since driver applications are based on **DriverExtensionAbility**, you need to override its lifecycle callback APIs.

2. Driver application installation and uninstallation

- Installation policy

  - When a user installs a driver application, the system installs it in all existing user spaces.

  - When a new user is created, the system installs all previously installed driver applications in that user's space.

- Uninstallation policy: When a user uninstalls a driver application in any user space, the system uninstalls it from all user spaces.

3. DriverExtensionAbility-based lifecycle management

- ExtensionAbility is a general term of scenario-based service extension abilities, such as user-mode peripheral drivers, service widgets, and input methods.

- The lifecycle of each ExtensionAbility is managed by its SA. The SA calls **connectAbility** to start the ExtensionAbility and drive the execution of the defined service APIs. When the service is complete, the SA calls **disconnectAbility** to disconnect the ExtensionAbility. The AMS then determines whether to destroy the ExtensionAbility and its associated process based on whether the ExtensionAbility has any active SA connections. In the user-mode driver development scenario, the system SA that manages the **DriverExtensionAbility** lifecycle is the driver extension SA.

4. API access security control in **DriverExtensionAbility**

- The system supports scenario-based extension abilities built on ExtensionAbility. **DriverExtensionAbility** is a type of ability designed to support the development of user-mode drivers.

- Within **DriverExtensionAbility**, only DDK APIs can be accessed to perform access control and data communication for non-standard peripherals.

- Based on the security constraints and service scenarios in driver development, access to other ArkTS APIs is not allowed within DriverExtensionAbility, which is intended to prevent malicious behavior and data leakage.

- Restricted access to ArkTS APIs in DriverExtensionAbility is implemented as follows:

  - During the initialization and creation of an Extension process, the system loads the required system modules based on the list of restricted-access ArkTS APIs configured for the Extension. At runtime, if a restricted ArkTS API is called in DriverExtensionAbility, the API call fails because the corresponding system module was not loaded during the initialization and creation phases.

- For the list of restricted ArkTS APIs in **DriverExtensionAbility**, see the **DriverExtension** configuration in [frameworks/native/ability/native/etc/extension_blocklist_config.json · OpenHarmony/ability_ability_runtime - AtomGit | GitCode](https://gitcode.com/openharmony/ability_ability_runtime/blob/master/frameworks/native/ability/native/etc/extension_blocklist_config.json).

<!--no_check-->