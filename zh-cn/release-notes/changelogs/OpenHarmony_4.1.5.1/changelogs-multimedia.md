# multimedia子系统变更说明

## cl.multimedia.1 getDevices接口变更

**访问级别**

公开接口

**变更原因**

对于有听筒的设备，即使非通话状态听筒也可以通过接口查询到。

**变更影响**

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，非通话场景返回值也会包含EARPIECE设备。

**变更发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**变更的接口/组件**

变更前：

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，只有通话场景返回值才会包含EARPIECE设备。

变更后：

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors>): void;

getDevices(deviceFlag: DeviceFlag): Promise<AudioDeviceDescriptors>;

对于有听筒的设备，当DeviceFlag为OUTPUT_DEVICES_FLAG、ALL_DEVICES_FLAG时，非通话场景返回值也会包含EARPIECE设备。

**适配指导**

修改后用户调用该接口时，如果需要判断其返回值，需要增加EARPIECE设备的判断。