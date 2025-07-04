# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Added Mandatory Property orientationId in AbilityInfo.d.ts

The mandatory property **orientationId** is added to [AbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts).

**Access Level**
Public API

**Reason for Change**
To align with the usage habits of end users, applications should be able to configure the default window rotation method based on the device type. Applications reference orientation configurations using resource IDs, and **orientationId** is used to parse the specific configuration.

**Impact of the Change**<br>
This change requires application adaptation.

Before change: The application can compile successfully when constructing AbilityInfo.
After change: Applications must now include the parameter **orientationId** when constructing AbilityInfo.

**Start API Level**
API 9

**Change Since**
OpenHarmony SDK 5.0.2.57

**Key API/Component Changes**<br>
Mandatory property **orientationId** added to **AbilityInfo.d.ts**

**Adaptation Guide**<br>
After upgrading to API 14, if your application constructs the AbilityInfo struct, you must add the mandatory property **orientationId** to the constructed AbilityInfo struct.
