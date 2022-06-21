# Overview<a name="EN-US_TOPIC_0000001152533331"></a>

This topic provides a panorama of all documents for you to obtain helpful information quickly. These documents are classified based on your learning progress and development scenarios of OpenHarmony.

## System Types<a name="section767218232110"></a>

It is good practice to understand the system types for you to find useful documents that can guide your development.

OpenHarmony is an open-source distributed operating system for all scenarios. It uses a component-based design to tailor its features to better suit devices with 128 KiB to GiB-level of RAM. You can integrate a flexible combination of system components based on the hardware capabilities of the device.

To make the integration simple and easy on different hardware, OpenHarmony defines three basic system types. You only need to select a suitable system type and configure the mandatory component set, thereby developing a system for your device at the minimum workload. The definitions of the basic system types are provided as follows for your reference:

-   Mini system

    A mini system runs on the devices whose memory is greater than or equal to 128 KiB and that are equipped with MCU processors such as Arm Cortex-M and 32-bit RISC-V. This system provides multiple lightweight network protocols and graphics frameworks, and a wide range of read/write components for the IoT bus. Typical products include connection modules, sensors, and wearables for smart home.

-   Small system

    A small system runs on the devices whose memory is greater than or equal to 1 MiB and that are equipped with application processors such as Arm Cortex-A. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders \(EDRs\) for smart travel.

-   Standard system

    A standard system runs on the devices whose memory is greater than or equal to 128 MiB and that are equipped with application processors such as Arm Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.


In addition, OpenHarmony provides a series of optional system components that can be configured as required to support feature extension and customization. These system components are combined to form a series of system capabilities that, for better understanding, are described as features or functions for you to choose.

## Document Outline<a name="section19810171681218"></a>

**Table  1**  Mini and small system development guidelines \(reference memory < 128 MB\)

| Topic | Development Scenario | Documents |
| -------- | -------- | -------- |
| About OpenHarmony | Getting familiar with OpenHarmony | - [About OpenHarmony](https://gitee.com/openharmony)<br/>- [Glossary](../glossary.md) |
| Development resources | Preparing for your development | - [Obtaining Source Code](get-code/sourcecode-acquire.md)<br/>- [Tool Acquisition](get-code/gettools-acquire.md) |
| Quick start | Getting started with setup, build, burning, debugging, and running of OpenHarmony | [Mini and Small Systems](quick-start/quickstart-lite-overview.md) |
| Basic capabilities | Using basic capabilities of OpenHarmony | - [Kernel for Mini Systems](kernel/kernel-mini-overview.md)<br/>- [Kernel for Small Systems](kernel/kernel-small-overview.md)<br/>- [Drivers](driver/driver-hdf-overview.md)<br/>- [Subsystems](subsystems/subsys-build-mini-lite.md)<br/>- [Security Guidelines](security/security-guidelines-overall.md)<br/>- [Privacy Protection](security/security-privacy-protection.md) |
| Advanced development | Developing smart devices based on system capabilities | - [WLAN-connected Products](guide/device-wlan-led-control.md)<br/>- [Cameras Without a Screen](guide/device-iotcamera-control-overview.md)<br/>- [Cameras with a Screen](guide/device-camera-control-overview.md) |
| Porting and adaptation | - Porting and adapting the OpenHarmony to an SoC<br/>- Porting and adapting the<br/> OpenHarmony to a third-party library | - [Mini System SoC Porting Guide](porting/oem_transplant_chip_prepare_knows.md)<br/>- [Small System SoC Porting Guide](porting/porting-smallchip-prepare-needs.md)<br/>- [Third-Party Library Porting Guide for Mini and Small Systems](porting/porting-thirdparty-overview.md) |
| Contribution | Contributing components to OpenHarmony | - [HPM Part Overview](hpm-part/hpm-part-about.md)<br/>- [HPM Part Development](hpm-part/hpm-part-development.md)<br/>- [HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference | Referring to development specifications | [FAQs](faqs/faqs-overview.md) |


**Table  2**  Standard system development guidelines \(reference memory ≥ 128 MB\)

| Topic | Development Scenario | Documents |
| -------- | -------- | -------- |
| About OpenHarmony | Getting familiar with OpenHarmony | - [About OpenHarmony](https://gitee.com/openharmony/docs/blob/master/en/OpenHarmony-Overview.md)<br/>- [Glossary](../glossary.md) |
| Development resources | Preparing for your development | - [Obtaining Source Code](get-code/sourcecode-acquire.md)<br/>- [Tool Acquisition](get-code/gettools-acquire.md) |
| Quick start | Getting started with setup, build, burning, debugging, and running of OpenHarmony | [Standard System](quick-start/quickstart-standard-overview.md) |
| Basic capabilities | Using basic capabilities of OpenHarmony | - [Kernel for Standard Systems](kernel/kernel-standard-overview.md)<br/>- [Drivers](driver/driver-hdf-overview.md)<br/>- [Subsystems](subsystems/subsys-build-standard-large.md)<br/>- [Security Guidelines](security/security-guidelines-overall.md)<br/>- [Privacy Protection](security/security-privacy-protection.md) |
| Advanced development | Developing smart devices based on system capabilities | - [Development Guidelines on Clock Apps](guide/device-clock-guide.md)<br/>- [Development Example for Platform Drivers](guide/device-driver-demo.md)<br/>- [Development Example for Peripheral Drivers](guide/device-outerdriver-demo.md) |
| Porting and adaptation | Porting and adapting the OpenHarmony to a third-party library | - [Standard System Porting Guide](porting/standard-system-porting-guide.md)<br/>- [A Method for Rapidly Porting the OpenHarmony Linux Kernel](porting/porting-linux-kernel.md) |
| Contribution | Contributing components to OpenHarmony | - [HPM Part Overview](hpm-part/hpm-part-about.md)<br/>- [HPM Part Development](hpm-part/hpm-part-development.md)<br/>- [HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference | Referring to development specifications | [FAQs](faqs/faqs-overview.md) |


