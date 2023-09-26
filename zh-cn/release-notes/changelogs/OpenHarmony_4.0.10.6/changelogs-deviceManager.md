# USB子系统Changelog

## cl.usb.1 USB驱动API接口安全权限变更

从4.0x版本开始，@ohos.driver.deviceManager 中bindDevice、unbindDevice、queryDevices接口在调用时需申请ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER权限。

function unbindDevice(deviceId: number): Promise\<number>;

function unbindDevice(deviceId: number, callback: AsyncCallback<number>): void;

function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<{deviceId: number, remote: rpc.IRemoteObject}>;

function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<{deviceId: number, remote: rpc.IRemoteObject}>;

function queryDevices(busType?: number): Array<Readonly<Device>>;

**变更影响**

变更前接口缺少权限限制，存在安全隐患。

添加了权限标签之后，在调用对应接口时，需要确保申请ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER权限，才能对接口调用

**涉及接口**

对下列接口增加权限要求，需申请ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER权限
bindDevice
unbindDevice
queryDevices

**适配指导**

有了权限标签之后在调用接口时需要申请ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER权限才可以。