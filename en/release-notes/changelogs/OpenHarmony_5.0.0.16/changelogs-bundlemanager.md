# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 System Parameter const.product.developmentmode Deleted

**Access Level**

Others

**Reason for Change**

In API version 9, the bundle manager module uses the system parameter **const.product.developmentmode** to exempt the verification of the device's udid during the installation of an application using a debug signing certificate. Since API version 11, the system supports the developer mode to enhance the control over the installation of such an application. The system parameter can still be used to skip the udid verification. In API version 12, the system parameter is deleted. As a result, the udid verification cannot be skipped during the application installation.

**Change Impact**

This change is a non-compatible change. The system parameter is not described in the document, and the compatibility is not ensured.

The installation of an application using a debug signing certificate is affected. The udid verification cannot be skipped by setting the system parameter. This change does not affect applications in the system image. By default, the system parameter does not exist and becomes invalid after the system is restarted.

**API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.16

**Adaptation Guide**

The control over the udid verification during the installation of an application using a debug signing certificate has been enhanced. The udid verification cannot be skipped by setting the system parameter. To install such an application, ensure that the device's udid is added to the application's signing profile.
