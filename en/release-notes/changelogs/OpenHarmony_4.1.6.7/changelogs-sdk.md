# SDK Subsystem Changelog

## cl.sdk.1 Change in the Validation Rule for syscap Values

**Reason for Change**

It is necessary to provide alerts for usage of APIs that are not fully compatible with the system capability set of devices.

For single-device scenarios, an alert is thrown for the use of APIs outside the device's system capability set.

For multi-device scenarios, an alert is thrown for the use of APIs outside the intersection of the system capability sets of all devices.

**Change Impact**

After this change, when nappropriate APIs are used, an alert will appear, with the following message:

"The default system capabilities of devices `<deviceTypes>` do not include the system capability of '`<apiName>`'. Configure the capabilities in syscap.json. It may cause your application to crash on some devices. Attention: Such illegal interface calls will lead to compilation errors in future versions!"

This indicates the use of APIs outside the allowed range, which may not be supported on some devices. In future versions, such practices will be intercepted.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.7

**Key API/Component Changes**

The change only includes the compilation result.

**Adaptation Guide**

Use APIs that meet the system capability set of the device and ensure that the APIs used are compatible with all devices supported by the current application.
