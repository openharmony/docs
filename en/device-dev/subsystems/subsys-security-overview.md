# Overview<a name="EN-US_TOPIC_0000001058831526"></a>

-   [Basic Concepts](#section175012297491)
-   [Limitations and Constraints](#section2029921310472)

The OpenHarmony security subsystem provides security capabilities that make your applications and devices more secure and help you manage permissions. This subsystem has the following modules:

-   Application signature verification

    To ensure the content integrity of applications, the system controls sources of the applications through application signatures and profiles. For a debugging application, the system uses the signature verification API to check whether the Unique Device Identifier \(UDID\) of the application matches that of the device, so as to ensure that the application is installed on the right device.

-   Application permission management

    Application permissions determine what system resources and capabilities an application can access. During application development, you need to declare the permissions that the application may require in the  **profile.json**  file. Static permissions need to be registered during application installation, while dynamic permissions usually involve sensitive information and need users' dynamic authorization.

-   Trusted device group management

    You can create and query a group of trusted devices that use the same ID or a peer-to-peer group created by scanning a QR code or using OneHop. With this capability, distributed applications can perform trusted authentication between devices and request from the distributed virtual bus for secure sessions between devices.


## Basic Concepts<a name="section175012297491"></a>

Before developing an application that depends on the signature verification component, you should understand the following basic concepts:

-   Samgr

    System Ability Manager \(Samgr\) is a module of OpenHarmony for managing system capabilities. For details, see the Application Framework development guidelines.


-   BMS

    Bundle Manager Service \(BMS\) manages application installation, uninstallation, and data on OpenHarmony.


-   Profile

    The profile in this document refers to HarmonyAppProvision \(profile for short\). HarmonyAppProvision is in JSON format.


-   Debugging application

    A debugging application is a HAP that is signed with a debugging certificate and profile obtained from the application market.


-   Released application

    This application refers to a HAP that is signed with a distribution certificate and profile obtained from the application market, but has been released in the application market.


-   OpenHarmony self-signed application

    A self-signed application is one that has been signed with the signing certificate and profile issued by OpenHarmony's open-source root CA, which is comprised of a certificate and a key.


## Limitations and Constraints<a name="section2029921310472"></a>

-   Only signatures of debugging, released, and OpenHarmony self-signed applications can be verified.
-   To verify the signature of a debugging application, the UDID of the device on which the debugging application is installed must be in the UDID list contained in the profile.

