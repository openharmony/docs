# Multimedia Subsystem Changelog

## cl.multimedia.1 getDevices Changed

**Access Level**

Public

**Reason for Change**

**getDevices** returns a device with an earpiece only when the device is in a call.

**Change Impact**

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece even when the device is not in a call.

**Change Since**

OpenHarmony SDK 4.1.5.1

**Key API/Component Changes**

Before change:

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece only in the call scenario.

After change:

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

When **DeviceFlag** is set to **OUTPUT_DEVICES_FLAG** or **ALL_DEVICES_FLAG**, the return value contains a device with an earpiece even not in the call scenario.

**Adaptation Guide**

Add the logic for determining whether a device contains an earpiece in your code.
