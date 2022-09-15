# Glossary

## A

- ### Ability

    An abstraction of a functionality that an application can provide. An ability is the minimum unit for the system to schedule applications. An application can contain one or more **Ability** instances.


- ### AMS

    Ability Manager Service, a service that manages abilities.
    
- ### ArkCompiler

    A component-based and configurable multi-language compilation and running platform built in OpenHarmony. Bolstered by key components such as the compiler, toolchain, and runtime, ArkCompiler is able to compile and run code written in various advanced programming languages on multiple chip platforms. It also enables the OpenHarmony standard system and its applications and services to run on a variety of device types, from phones and PCs, tablets, TVs, automobiles, to smart wearables.

- ### ArkUI

  A simplified and high-performance UI development framework for cross-device application design and development, increasing your productivity when creating application UIs for use across devices. For details, see [ArkUI Overview](application-dev/ui/arkui-overview.md).


## B

- ### BMS

    Bundle Manager Service, a service that manages application bundles.


## D

- ### DevEco Device Tool

    A one-stop development environment and all-in-one resource platform for smart device developers. It provides comprehensive capabilities spanning the entire process of device development, from chip template project creation and custom development resource selection to code writing, build, debugging, and burning.

- ### DMS

    Distributed Management Service, a service used for distributed data management.


## F

- ### FA

    Feature Ability, an ability that provides a UI for user interaction in the ability framework of the FA model. The FA supports only the Page ability template.
    
- ### FA model

    Feature Ability model, one of the development models supported by the ability development framework. It is the only application development model supported by API version 8 and earlier. The FA model provides [FAs](#fa) and [Particle abilities (PAs)](#pa). The FA supports the Page ability template, and the PA supports the Service, Data, and Form ability templates. For details, see [FA Model Overview](application-dev/ability/fa-brief.md).


## H

- ### HAP

    OpenHarmony Ability Package, released with the file name extension .hap. One HAP provides all content of an application, including code, resources, third-party libraries, and an application configuration file.

- ### HCS

    HDF Configuration Source (HCS), providing the [Hardware Driver Foundation (HDF)](#hdf) configuration in key-value pairs. HCS removes the dependency between configuration code and driver code, simplifies configuration management.


- ### HC-GEN

    HDF Configuration Generator, a tool for converting a configuration file into a file that can be read by the target software.


- ### HDF

    Hardware Driver Foundation that provides a unified access interface for peripherals and the framework for driver development and management in OpenHarmony.

- ### Hypium

    OpenHarmony automatic test framework, which strives to implement hyper-automatic tests. Hypium is a blend of Hyper Automation and ium, where ium indicates a stable, reliable capability base of the test framework.


## I

- ### IDN

    Intelligent Distributed Networking, a distributed networking unit of OpenHarmony. You can use IDN to obtain the device list and device states and subscribe to the connection state changes of devices on a distributed network.


## P

- ### PA

    Particle Ability, an ability that does not have a UI in the ability framework of the FA model. It provides services and support for FAs. For example, a PA can function as a background service to provide computing power or as a data store to provide data access capabilities. The PA supports Service, Data, and Form ability templates.


## S

- ### Super Virtual Device

    Also called Super Device. It integrates the capabilities of multiple devices through the distributed technology into a virtual hardware resource pool and then centrally manages and schedules these capabilities based on application requirements.

- ### Stage model

    A development model supported by the Ability development framework since API version 9. The stage model provides **Ability** and **ExtensionAbility** classes. The **ExtensionAbility** classes include **ServiceExtensionAbility**, **FormExtensionAbility**, **DataShareExtensionAbility**, and more.

- ### System type
    - Mini system: an operating system for the devices that come with MCU processors, such as Arm Cortex-M and 32-bit RISC-V, and memory greater than or equal to 128 KiB. This system provides rich short-distance connection capabilities and peripheral access bus. The mini system applies to smart home products such as LinkIoT module devices and sensors.
    - Small system: an operating system for the devices that come with application processors, such as Arm Cortex-A, and memory greater than or equal to 1 MiB. This system provides higher security capabilities, a standard graphics framework, and video encoding and decoding capabilities. The small system applies to smart home products such as IP cameras, peephole cameras, and routers as well as smart travel products such as event data recorders (EDRs).
    - Standard system: an operating system for the devices that come with application processors, such as Arm Cortex-A, and memory greater than or equal to 128 MiB. This system provides a complete application framework supporting enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. The standard system applies to high-end refrigerator displays.
