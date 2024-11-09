# BundleInfo (System API)

The **BundleInfo** module defines the bundle information. A third-party application can obtain its own bundle information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with [bundleFlags](js-apis-bundleManager.md#bundleflag) set to the information to be contained in the returned [BundleInfo](js-apis-bundleManager-bundleInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [[BundleInfo](js-apis-bundleManager-bundleInfo.md).

## AppCloneIdentity<sup>12+<sup>

Describes the identity information of an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName | string         | Yes  | No  | Bundle name of the application.         |
| appIndex | number | Yes  | No  | Index of the application clone.|
