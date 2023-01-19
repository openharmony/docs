# Security Overview

The OpenHarmony security subsystem provides security capabilities that make your applications and devices more secure and help you manage permissions. This subsystem has the following modules:

-   Application signature verification

    To ensure the content integrity of applications, the system controls sources of the applications through application signatures and profiles. For a debugging application, the system uses the signature verification API to check whether the Unique Device Identifier (UDID) of the application matches that of the device, so as to ensure that the application is installed on the right device.

-   Application permission management

    Application permissions determine what system resources and capabilities an application can access. During application development, you need to declare the permissions required by the application in the application configuration file (**config.json**). Static permissions need to be registered during application installation, while dynamic permissions usually involve sensitive information and need users' dynamic authorization.

-   Trusted device group management

    You can create and query a group of trusted devices that use the same HUAWEI ID or a peer-to-peer group created by scanning a QR code or using OneHop. With this capability, distributed applications can perform trusted authentication between devices and request from the distributed virtual bus for secure sessions between devices.

-   DSLM

    The Device Security Level Management (DSLM) module is introduced to manage the security levels of OpenHarmony devices. When different types of user data are hopped or processed in OpenHarmony distributed services, the DSLM APIs can be called to obtain the security levels of related devices for subsequent processing.


## Basic Concepts

Before developing an application that depends on the signature verification component, you should understand the following basic concepts:

-   Samgr

    System Ability Manager (Samgr) is a module of OpenHarmony for managing system capabilities. For details, see the Application Framework development guidelines.


-   BMS

    Bundle Manager Service (BMS) manages application installation, uninstallation, and data on OpenHarmony.

- Profile

  The profile in this document refers to HarmonyAppProvision, which is in JSON format.


-   Debug application

    A debug application is an OpenHarmony Ability Package (HAP) that is signed with a debug certificate and profile obtained from the application store.


-   Release application

    A release application is a HAP that is signed with a release certificate and profile obtained from the application store, and formally released in the application store.


-   OpenHarmony self-signed application

    A self-signed application is an application that is signed with the signing certificate and profile issued by OpenHarmony's open-source root CA, which is composed of a certificate and a key.


## Constraints

-   Only signatures of the debug, release, and OpenHarmony self-signed applications can be verified.
-   To verify the signature of a debug application, the UDID of the device on which the debug application is installed must be in the UDID list contained in the profile.
