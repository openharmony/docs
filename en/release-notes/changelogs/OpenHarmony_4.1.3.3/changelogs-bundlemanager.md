# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Deprecated the verifyCodeParams Field in VerifyCodeParam and InstallParam

**Access Level**

System APIs

**Reason for Change**

The code signature file of an application is integrated into the installation package, rather than being specified by using the **verifyCodeParams** Field.

**Change Impact**

The **verifyCodeParams** field in **VerifyCodeParam** and **InstallParam** of the [installer](../../../application-dev/reference/apis/js-apis-installer.md) module is deprecated. This field is no longer required.

**Valid Since**

OpenHarmony SDK 4.1.3.3

**Deprecated APIs/Components**

| API| Description|
| --------------- | ------- |
| interface VerifyCodeParam | No longer required to specify the code signature file of the installation package.|
| verifyCodeParams?: Array\<VerifyCodeParam>; | No longer required to specify the code signature file of the installation package.|

**Adaptation Guide**

When calling the APIs provided by the **installer** module, you do not need to specify the code signature file of the installation package, because it is integrated into the installation package.
