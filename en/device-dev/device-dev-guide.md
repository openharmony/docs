# Overview<a name="ZH-CN_TOPIC_0000001152533331"></a>

This topic provides a panorama of all documents for you to obtain helpful information quickly. These documents are classified based on your learning progress and development scenarios of OpenHarmony.

## System Types<a name="section767218232110"></a>

It is good practice to understand the system types for you to find useful documents that can guide your development.

OpenHarmony is an open-source distributed operating system for all scenarios. It uses a component-based design to tailor its features to better suit devices with 128 KiB to GiB-level of RAM. You can integrate a flexible combination of system components based on the hardware capabilities of the device.

To make the integration simple and easy on different hardware, OpenHarmony defines three basic system types. You only need to select a suitable system type and configure the mandatory component set, thereby developing a system for your device at the minimum workload. The definitions of the basic system types are provided as follows for your reference:

-   Mini system

    A mini system fits into the devices that come with Micro Controller Units (MCUs), such as Arm Cortex-M and 32-bit RISC-V processors, and memory greater than or equal to 128 KiB. This system provides multiple lightweight network protocols, a graphics framework, and a wide range of read/write components with the IoT bus. Typical products include connection modules, sensors, and wearables for smart home.

-   Small system

    A small system fits into the devices that come with application processors, such as Arm Cortex-A, and memory greater than or equal to 1 MiB. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders (EDRs) for easy travel.

-   Standard system

    A standard system fits into the devices that come with application processors, such as Arm Cortex-A, and memory greater than or equal to 128 MiB. This system provides a complete application framework supporting enhanced interactions, 3D GPU, hardware composer, diverse components, and various animations. Typical products include high-end refrigerator displays.


In addition, OpenHarmony provides a wide array of system components that can be configured as required to support feature extension and customization. These system components are combined to form a series of system capabilities that, for better understanding, are described as features or functions for you to choose.

## Document Outline<a name="section19810171681218"></a>

-   [Mini and Small System Development Guidelines](#table3762949121211)
-   [Standard System Development Guidelines](#table17667535516)

**Table 1** Mini and small system development guidelines (reference memory < 128 MB)

| Topic| Development Scenario| Related Documentation|
| -------- | -------- | -------- |
| About OpenHarmony| Getting familiar with OpenHarmony| -&nbsp;[About OpenHarmony](https://gitee.com/openharmony)<br>-&nbsp;[Glossary](../glossary.md) |
| Development resources| Preparing for your development| -&nbsp;[Obtaining Source Code](get-code/sourcecode-acquire.md)<br>-&nbsp;[Obtaining Tools](get-code/gettools-acquire.md) |
| Getting started| Getting started with setup, build, burning, debugging, and running of OpenHarmony| [Mini and Small Systems](quickstart/quickstart-lite.md)|
| Basic capabilities| Using basic capabilities of OpenHarmony| -&nbsp;[Kernel for Mini System](kernel/kernel-mini-overview.md)<br>-&nbsp;[Kernel for Small System](kernel/kernel-small-overview.md)<br>-&nbsp;[HDF](driver/driver-hdf-overview.md)<br>-&nbsp;[Subsystems](subsystems/subsys-build-mini-lite.md)<br>-&nbsp;[Security Guidelines](security/security-guidelines-overall.md)<br>-&nbsp;[Privacy Protection](security/security-privacy-protection.md)|
| Advanced development| Developing smart devices based on system capabilities| -&nbsp;[WLAN-connected Products](guide/device-wlan-led-control.md)<br>-&nbsp;[Cameras Without a Screen](guide/device-iotcamera-control-overview.md)<br>-&nbsp;[Cameras with a Screen](guide/device-camera-control-overview.md) |
| Porting and adaptation| -&nbsp;Porting and adapting OpenHarmony to an SoC<br>-&nbsp;Porting and adapting OpenHarmony to a third-party library| -&nbsp;[Mini System SoC Porting](porting/oem_transplant_chip_prepare_knows.md)<br>-&nbsp;[Small System SoC Porting](porting/porting-smallchip-prepare-needs.md)<br>-&nbsp;[Third-Party Library Porting for Mini and Small Systems](porting/porting-thirdparty-overview.md) |
| Contributing components| Contributing components to OpenHarmony| -&nbsp;[HPM Part Overview](hpm-part/hpm-part-about.md)<br>-&nbsp;[HPM Part Development](hpm-part/hpm-part-development.md)<br>-&nbsp;[HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference| Referring to development specifications| [FAQs](faqs/faqs-overview.md) |


**Table 2** Standard system development guidelines (reference memory ≥ 128 MB)
| Topic| Development Scenario| Related Documentation|
| -------- | -------- | -------- |
| About OpenHarmony| Getting familiar with OpenHarmony| -&nbsp;[About OpenHarmony](https://gitee.com/openharmony)<br>-&nbsp;[Glossary](../glossary.md) |
| Development resources| Preparing for your development| -&nbsp;[Obtaining Source Code](get-code/sourcecode-acquire.md)<br>-&nbsp;[Obtaining Tools](get-code/gettools-acquire.md) |
| Getting started| Getting started with setup, build, burning, debugging, and running of OpenHarmony| [Standard System](quick-start/)|
| Basic capabilities| Using basic capabilities of OpenHarmony| -&nbsp;[Kernel Development](kernel/kernel-standard.md)<br>-&nbsp;[HDF](driver/driver-hdf-overview.md)<br>-&nbsp;[Subsystems](subsystems/subsys-build-standard-large.md)<br>-&nbsp;[Security Guidelines](security/security-guidelines-overall.md)<br>-&nbsp;[Privacy Protection](security/security-privacy-protection.md)|
| Advanced development| Developing smart devices based on system capabilities| -&nbsp;[Development Guidelines on Clock Apps](guide/device-clock-guide.md)<br>-&nbsp;[Development Example for Platform Drivers](guide/device-driver-demo.md)<br>-&nbsp;[Development Example for Peripheral Drivers](guide/device-outerdriver-demo.md) |
| Porting and adaptation| Porting and adapting OpenHarmony to a third-party library| -&nbsp;[Standard System Porting Guide](porting/standard-system-porting-guide.md)<br>-&nbsp;[A Method for Rapidly Porting the OpenHarmony Linux Kernel](porting/porting-linux-kernel.md) |
| Contributing components| Contributing components to OpenHarmony| -&nbsp;[HPM Part Overview](hpm-part/hpm-part-about.md)<br>-&nbsp;[HPM Part Development](hpm-part/hpm-part-development.md)<br>-&nbsp;[HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference| Referring to development specifications| [FAQs](faqs/faqs-overview.md) |
