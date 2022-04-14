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

-   [Mini and Small System Development Guidelines](#table3762949121211)
-   [Standard System Development Guidelines](#table17667535516)

**Table  1**  Mini and small system development guidelines \(reference memory < 128 MB\)

| Topic | Development&nbsp;Scenario | Documents |
| -------- | -------- | -------- |
| About&nbsp;OpenHarmony | Getting&nbsp;familiar&nbsp;with&nbsp;OpenHarmony | -&nbsp;[About&nbsp;OpenHarmony](https://gitee.com/openharmony)<br/>-&nbsp;[Glossary](glossary/glossary.md) |
| Development&nbsp;resources | Preparing&nbsp;for&nbsp;your&nbsp;development | -&nbsp;[Obtaining&nbsp;Source&nbsp;Code](get-code/sourcecode-acquire.md)<br/>-&nbsp;[Tool&nbsp;Acquisition](get-code/gettools-acquire.md) |
| Quick&nbsp;start | Getting&nbsp;started&nbsp;with&nbsp;setup,&nbsp;build,<br/>&nbsp;burning,&nbsp;debugging,&nbsp;and<br/>&nbsp;running&nbsp;of&nbsp;OpenHarmony | [Mini&nbsp;and&nbsp;Small&nbsp;Systems](quick-start/quickstart-lite-overview.md)) |
| Basic&nbsp;capabilities | Using&nbsp;basic&nbsp;capabilities&nbsp;of<br/>&nbsp;OpenHarmony | -&nbsp;[Kernel&nbsp;for&nbsp;Mini&nbsp;Systems](kernel/kernel-mini-overview.md)<br/>-&nbsp;[Kernel&nbsp;for&nbsp;Small&nbsp;Systems](kernel/kernel-small-overview.md)<br/>-&nbsp;[Drivers](driver/driver-hdf-overview.md)<br/>-&nbsp;[Subsystems](subsystems/subsys-build-mini-lite.md)<br/>-&nbsp;[Security&nbsp;Guidelines](security/security-guidelines-overall.md)<br/>-&nbsp;[Privacy&nbsp;Protection](security/security-privacy-protection.md) |
| Advanced&nbsp;development | Developing&nbsp;smart&nbsp;devices&nbsp;based<br/>&nbsp;on&nbsp;system&nbsp;capabilities | -&nbsp;[WLAN-connected&nbsp;Products](guide/device-wlan-led-control.md)<br/>-&nbsp;[Cameras&nbsp;Without&nbsp;a&nbsp;Screen](guide/device-iotcamera-control-overview.md)<br/>-&nbsp;[Cameras&nbsp;with&nbsp;a&nbsp;Screen](guide/device-camera-control-overview.md) |
| Porting&nbsp;and&nbsp;adaptation | -&nbsp;Porting&nbsp;and&nbsp;adapting&nbsp;the&nbsp;<br/>OpenHarmony&nbsp;to&nbsp;an&nbsp;SoC<br/>-&nbsp;Porting&nbsp;and&nbsp;adapting&nbsp;the<br/>&nbsp;OpenHarmony&nbsp;to&nbsp;a<br/>&nbsp;third-party&nbsp;library | -&nbsp;[Mini&nbsp;System&nbsp;SoC&nbsp;Porting&nbsp;Guide](porting/oem_transplant_chip_prepare_knows.md)<br/>-&nbsp;[Small&nbsp;System&nbsp;SoC&nbsp;Porting&nbsp;Guide](porting/porting-smallchip-prepare-needs.md)<br/>-&nbsp;[Third-Party&nbsp;Library&nbsp;Porting&nbsp;Guide&nbsp;for&nbsp;Mini&nbsp;and&nbsp;Small&nbsp;Systems](porting/porting-thirdparty-overview.md) |
| Contributing&nbsp;components | Contributing&nbsp;components<br/>&nbsp;to&nbsp;OpenHarmony | -&nbsp;[HPM Part Overview](hpm-part/hpm-part-about.md)<br/>-&nbsp;[HPM Part Development](hpm-part/hpm-part-development.md)<br/>-&nbsp;[HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference | Referring&nbsp;to&nbsp;development&nbsp;specifications | [FAQs](faqs/faqs-overview.md) |


**Table  2**  Standard system development guidelines \(reference memory ≥ 128 MB\)

| Topic | Development&nbsp;Scenario | Documents |
| -------- | -------- | -------- |
| About&nbsp;OpenHarmony | Getting&nbsp;familiar&nbsp;with&nbsp;OpenHarmony | -&nbsp;[About&nbsp;OpenHarmony](https://gitee.com/openharmony/docs/blob/master/en/OpenHarmony-Overview.md)<br/>-&nbsp;[Glossary](glossary/glossary.md) |
| Development&nbsp;resources | Preparing&nbsp;for&nbsp;your&nbsp;development | -&nbsp;[Obtaining&nbsp;Source&nbsp;Code](get-code/sourcecode-acquire.md)<br/>-&nbsp;[Tool&nbsp;Acquisition](get-code/gettools-acquire.md) |
| Quick&nbsp;start | Getting&nbsp;started&nbsp;with&nbsp;setup,&nbsp;build,<br/>&nbsp;burning,&nbsp;debugging,&nbsp;and<br/>&nbsp;running&nbsp;of&nbsp;OpenHarmony | [Standard&nbsp;System](quick-start/quickstart-standard-overview.md) |
| Basic&nbsp;capabilities | Using&nbsp;basic&nbsp;capabilities&nbsp;of&nbsp;OpenHarmony | -&nbsp;[Kernel&nbsp;for&nbsp;Standard&nbsp;Systems](kernel/kernel-standard-overview.md)<br/>-&nbsp;[Drivers](driver/driver-hdf-overview.md)<br/>-&nbsp;[Subsystems](subsystems/subsys-build-standard-large.md)<br/>-&nbsp;[Security&nbsp;Guidelines](security/security-guidelines-overall.md)<br/>-&nbsp;[Privacy&nbsp;Protection](security/security-privacy-protection.md) |
| Advanced&nbsp;development | Developing&nbsp;smart&nbsp;devices<br/>&nbsp;based&nbsp;on&nbsp;system&nbsp;capabilities | -&nbsp;[Development&nbsp;Guidelines&nbsp;on&nbsp;Clock&nbsp;Apps](guide/device-clock-guide.md)<br/>-&nbsp;[Development&nbsp;Example&nbsp;for&nbsp;Platform&nbsp;Drivers](guide/device-driver-demo.md)<br/>-&nbsp;[Development&nbsp;Example&nbsp;for&nbsp;Peripheral&nbsp;Drivers](guide/device-outerdriver-demo.md) |
| Porting&nbsp;and&nbsp;adaptation | Porting&nbsp;and&nbsp;adapting&nbsp;the<br/>&nbsp;OpenHarmony&nbsp;to&nbsp;a&nbsp;third-party&nbsp;library | -&nbsp;[Standard&nbsp;System&nbsp;Porting&nbsp;Guide](porting/standard-system-porting-guide.md)<br/>-&nbsp;[A&nbsp;Method&nbsp;for&nbsp;Rapidly&nbsp;Porting&nbsp;the&nbsp;OpenHarmony&nbsp;Linux&nbsp;Kernel](porting/porting-linux-kernel.md) |
| Contributing&nbsp;components | Contributing&nbsp;components<br/>&nbsp;to&nbsp;OpenHarmony | -&nbsp;[HPM Part Overview](hpm-part/hpm-part-about.md)<br/>-&nbsp;[HPM Part Development](hpm-part/hpm-part-development.md)<br/>-&nbsp;[HPM Part Reference](hpm-part/hpm-part-reference.md) |
| Reference | Referring&nbsp;to&nbsp;development&nbsp;specifications | [FAQs](faqs/faqs-overview.md) 

