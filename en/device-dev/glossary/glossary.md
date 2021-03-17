# Glossary<a name="EN-US_TOPIC_0000001053048859"></a>

-   [A](#en-us_topic_0000001050749051_section1679023922312)
-   [B](#en-us_topic_0000001050749051_section62182102017)
-   [D](#en-us_topic_0000001050749051_section1670294920236)
-   [F](#en-us_topic_0000001050749051_section5406185415236)
-   [H](#en-us_topic_0000001050749051_section891816813243)
-   [I](#en-us_topic_0000001050749051_section10124052142516)
-   [M](#en-us_topic_0000001050749051_section0352490467)
-   [P](#en-us_topic_0000001050749051_section779354121411)
-   [S](#en-us_topic_0000001050749051_section25661636182615)

## A<a name="en-us_topic_0000001050749051_section1679023922312"></a>

-   **Ability**

    An ability is an abstraction of a functionality that an application can provide. Abilities of applications are classified into two types: Feature Ability \(FA\) and Particle Ability \(PA\).


-   **AbilityForm**

    An AbilityForm displays brief information about a Feature Ability on the UI of another application and provides basic interactive features.


-   **AbilitySlice**

    An AbilitySlice is the combination of a single visualized UI and its interactive logic. AbilitySlice is the fundamental unit of a Feature Ability. A Feature Ability can contain a group of UIs representing closely associated services, and each UI corresponds to one AbilitySlice.

-   **AMS**

    Ability Manager Service, a service that manages abilities


## B<a name="en-us_topic_0000001050749051_section62182102017"></a>

-   **BMS**

    Bundle Manager Service, a service that manages application bundles


## D<a name="en-us_topic_0000001050749051_section1670294920236"></a>

-   **DevEco Studio for Embedded**

    Integrated development environment \(IDE\) for developing embedded devices

-   **DMS**

    Distributed Management Service, a service used for distributed data management

-   **DV**

    Device Virtualization, which employs the virtualization technology to integrate capabilities and resources of different devices


## F<a name="en-us_topic_0000001050749051_section5406185415236"></a>

-   **FA**

    Feature Ability, representing an ability with a UI for interacting with users


## H<a name="en-us_topic_0000001050749051_section891816813243"></a>

-   **HAP**

    HarmonyOSOpenHarmony Ability Package, released as a HAP file. One HAP file describes all content of an application, including code, resources, third-party libraries, and a configuration file.

-   **HCS**

    HDF Configuration Source \(HCS\) describes the HDF configuration using key-value pairs. HCS is designed to decouple configuration code from driver code, thereby facilitating configuration management.


-   **HC-GEN**

    HDF Configuration Generator \(HC-GEN\) is a tool for converting a configuration file into a file that can be read by the target software.


-   **HDF**

    Hardware Driver Foundation that allows unified access from peripheral devices and provides foundation for driver development and management in HarmonyOSOpenHarmony


## I<a name="en-us_topic_0000001050749051_section10124052142516"></a>

-   **IDN**

    Intelligent Distributed Networking, a distributed networking capability unit specific to HarmonyOSOpenHarmony. You can use IDN to obtain the device list and device states and subscribe to the connection state changes of devices on the distributed network.


## M<a name="en-us_topic_0000001050749051_section0352490467"></a>

-   **MSDP**

    Mobile Sensing Development Platform, which provides the capabilities of distributed convergence sensing and distributed device virtualization.

    -   Distributed convergence sensing: Backed by the distributed capabilities of HarmonyOSOpenHarmony, the MSDP integrates the sensing sources of all involved devices to accurately sense users' states such as the space status, motion status, gestures, and health status. It thereby builds ubiquitous basic sensing capabilities, bringing smart life experience to users.
    -   Distributed device virtualization: Backed by the distributed capabilities of HarmonyOSOpenHarmony, the MSDP virtualizes various components \(such as cameras, monitors, speakers, and microphones\) of peripherals into the components available for local devices. Also, it enables local devices to share their components with other devices.


## P<a name="en-us_topic_0000001050749051_section779354121411"></a>

-   **PA**

    Particle Ability, representing an ability without a UI. PAs are invoked to implement Feature Ability \(FA\) functionalities. For example, a PA runs in the background to provide the computing capability or acts as a data warehouse to provide the data access capability.


## S<a name="en-us_topic_0000001050749051_section25661636182615"></a>

-   **SA**

    System Ability. The system abilities include the basic hardware and software services provided by the OS.


-   **Super virtual device**

    Also called super device. It integrates the capabilities of multiple devices through the distributed technology into a virtual hardware resource pool and then centrally manages and schedules these capabilities based on application requirements.

-   **System type**
    -   Mini system: refers to a system running on the devices whose memory is greater than or equal to 128 KB and that are equipped with only limited resources and MCU processors such as ARM Cortex-M and 32-bit RISC-V. This system provides rich short-distance connection capabilities and a bus for accessing peripherals. This system applies to smart home products such as LinkIoT module devices and sensors.
    -   Small system: refers to a system running on the devices whose memory is greater than or equal to 1 MB and that are equipped with application processors such as ARM Cortex-A. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. This system applies to smart home products such as IP cameras, peephole cameras, and routers as well as smart travel products such as event data recorders \(EDRs\).
    -   Standard system: refers to a system running on the devices whose memory is greater than or equal to 128 MB and that are equipped with application processors such as ARM Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.
    -   Large system: refers to a system running on the devices whose memory is greater than or equal to 1 GB and that are equipped with application processors such as ARM Cortex-A. This system provides a complete compatible application framework. This system applies to smart TVs and watches.


