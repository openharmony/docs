# Glossary

## A

- ### Ability

    An abstraction of a functionality that an application can provide. An ability is the minimum unit for the system to schedule applications. An application can contain one or more **Ability** instances.


- ### AMS

    Ability Manager Service, a service that manages abilities.
    
- ### ArkCompiler

    A component-based and configurable multi-language compilation and running platform built in OpenHarmony. Bolstered by key components such as the compiler, toolchain, and runtime, ArkCompiler is able to compile and run code written in various advanced programming languages on multiple chip platforms. It also enables the OpenHarmony standard system plus applications and services built wherein to run on a multitude of device types, from phones and PCs, tablets, TVs, automobiles, to smart wearables.

- ### ArkUI

  A simplified and high-performance UI development framework for cross-device application design and development, increasing your productivity when creating application UIs for use across devices. For details, see [ArkUI Overview](application-dev/ui/arkui-overview.md).


## B

- ### BMS

    Bundle Manager Service, a service that manages application bundles.


## D

- ### DevEco Studio for Embedded

    Integrated development environment (IDE) for developing embedded devices.

- ### DMS

    Distributed Management Service, a service used for distributed data management.


## F

- ### FA

    Feature Ability, a type of ability in the FA model of the ability framework that provides a UI for interacting with users. The FA supports only Page abilities.
    
- ### FA model

    Feature Ability model, one of the two models in the ability framework. It applies to application development using API 8 and earlier versions. In this model, there are [Feature Ability (FA)](#fa) and [Particle Ability (PA)](#pa). The FA supports Page abilities, and the PA supports Service, Data, and Form abilities. For details, see [FA Model Overview](application-dev/ability/fa-brief.md).


## H

- ### HAP

    OpenHarmony Ability Package, released as a HAP file. One HAP file describes all content of an application, including code, resources, third-party libraries, and a configuration file.

- ### HCS

    HDF Configuration Source, describing the HDF configuration using key-value pairs. HCS is designed to decouple configuration code from driver code, thereby facilitating configuration management.


- ### HC-GEN

    HDF Configuration Generator, a tool for converting a configuration file into a file that can be read by the target software.


- ### HDF

    Hardware Driver Foundation that allows unified access from peripheral devices and provides foundation for driver development and management.
	
- ### Hypium

    Name of the OpenHarmony automatic test framework, which strives to implement hyper-automatic tests. Hypium is a blend of Hyper Automation and ium, where ium indicates a stable, reliable capability base of the test framework.


## I

- ### IDN

    Intelligent Distributed Networking, a distributed networking capability unit specific to OpenHarmony. You can use IDN to obtain the device list and device states and subscribe to the connection state changes of devices on the distributed network.


## P

- ### PA

    Particle Ability, a type of ability in the FA model of the ability framework that does not provide a UI. It principally provides services and support for the Feature Ability. For example, it provides computing capabilities as a background service or provides data access capabilities as a data warehouse. The PA supports Service, Data, and Form abilities.


## S

- ### Super Virtual Device

    Also called Super Device. It integrates the capabilities of multiple devices through the distributed technology into a virtual hardware resource pool and then centrally manages and schedules these capabilities based on application requirements.

- ### Stage model

    One of the two models in the ability framework, introduced since API 9. In the stage model, there are **Ability** and **ExtensionAbility**. The **ExtensionAbility** is further extended to **ServiceExtensionAbility**, **FormExtensionAbility**, **DataShareExtensionAbility**, and more.

- ### System type
    - Mini system: a system running on the devices that come with MCU processors, such as Arm Cortex-M and 32-bit RISC-V, and memory greater than or equal to 128 KiB. This system provides rich short-distance connection capabilities and a bus for accessing peripherals. This system applies to smart home products such as LinkIoT module devices and sensors.
    - Small system: a system running on the devices that come with application processors such as Arm Cortex-A and memory greater than or equal to 1 MiB. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. This system applies to smart home products such as IP cameras, peephole cameras, and routers as well as smart travel products such as event data recorders (EDRs).
    - Standard system: a system running on the devices that come with application processors such as Arm Cortex-A and memory greater than or equal to 128 MiB. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.
