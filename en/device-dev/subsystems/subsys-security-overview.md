# Security Overview


The OpenHarmony security subsystem provides security capabilities that allow for trustworthy applications and devices and permission management. This subsystem has the following modules:


- Application signature verification

  The system uses the application signature and profile to ensure that all applications come from a known and approved source and have not been tampered with. For a debug application, APIs are provided to verify whether the Unique Device Identifier (UDID) of the application matches that of the device. The application can be installed on the device only when the UDIDs match.

- Application permission management

  Application permissions determine what system resources and capabilities an application can access. During application development, you need to declare the permissions required by your application in the application configuration file. Permissions include system_grant permissions (which need to be registered during the application installation) and user_grant permissions (which involve sensitive information and must be granted by the user).

- Inter-process communication (IPC) authentication

  The caller that attempts to invoke the APIs provided by system services through IPC must be authenticated. The system ability (SA) registered with the System Ability Manager (Samgr) can expose APIs to other processes through IPC, with access policies configured. When other processes attempt to call these APIs, the IPC authentication will be triggered. If the processes do not have the required permission, the access request will be rejected.

- DSLM

  The Device Security Level Management (DSLM) module is introduced to manage the security levels of OpenHarmony devices. When different types of user data are transferred or processed in OpenHarmony distributed services, the DSLM APIs can be called to obtain the security levels of related devices for subsequent processing.

- HUKS

  OpenHarmony Universal Keystore (HUKS) provides system-level key management capabilities, ensuring secure management and use of keys throughout their entire lifecycle (generation, storage, use, and destruction). Applications can call the APIs provided by the HUKS module to perform operations on keys. In addition, the keys in plaintext must be used in a trusted execution environment (TEE).

- OpenHarmony SELinux

  OpenHarmony Security-Enhanced Linux (SELinux) provides mandatory access control (MAC) capabilities for system resources such as files, parameters, SAs, and the HDF based on the system architecture characteristics and SELinux.


## Basic Concepts

Before you get started, it is helpful to understand the following basic concepts:

- Samgr

  Samgr manages SAs. For details, see the SA Framework development guidelines.

- BMS

  Bundle Manager Service (BMS) manages application installation, uninstallation, and data on the system.

- Profile

  The profile in this document refers to HarmonyAppProvision, which is in JSON format.

- Debug application

  A debug application is a Harmony Ability Package (HAP) that is signed with a debug certificate and profile obtained from AppGallery.

- Release application

  A release application is a HAP that is signed with a release certificate and profile obtained from AppGallery, and formally released on AppGallery.

- OpenHarmony self-signed application

  A self-signed application is an application that is signed with the signing certificate and profile issued based on the open-source root CA certificate and a key provided by OpenHarmony.


## Constraints

- Only the signatures of the AppGallery debug and release applications and OpenHarmony self-signed applications can be verified.

- The signature verification of a debug application is successful only when the device UDID matches the one in the application UDID list contained in the profile.
