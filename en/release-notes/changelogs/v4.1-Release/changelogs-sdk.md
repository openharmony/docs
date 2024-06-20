# SDK Subsystem Changelog

## cl.sdk.1 Change in System Capability Checks on APIs

**Reason for Change**

An alarm needs to be displayed for use of APIs that are not fully compatible with the system capability set of target devices.

Under single-device scenarios, an alarm should be displayed for use of APIs that use any system capability beyond the system capability set of the target device.

Under multi-device scenarios, an alarm should be displayed for use of APIs that use any system capability beyond the system capability set of all target devices.

**Change Impact**

After the change, an alarm is displayed when an improper API is used. The alarm content is as follows:

"The default system capabilities of devices `<deviceTypes>` do not include system capability of '`<apiName>`'. Configure the capabilities in syscap.json. It may cause your application crush in some devices. Attention: Such illegal interface call will lead to compilation error in the future version!"

The preceding alarm indicates that some APIs are not supported on target devices. Use of these APIs will be blocked in future versions.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.7

**Key API/Component Changes**

Only compilation result changes are involved.

**Adaptation Guide**

Use APIs that only use the system capability set available on the target devices and APIs that work on all target devices of your application.
