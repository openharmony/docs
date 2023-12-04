# USB Subsystem Changelog

## cl.usb.1 Security Permission Change of the USB Driver API

In version 4.0x or later, the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission needs to be declared for the **bindDevice**, **unbindDevice**, and **queryDevices** APIs in **@ohos.driver.deviceManager**.

function unbindDevice(deviceId: number): Promise\<number>;

function unbindDevice(deviceId: number, callback: AsyncCallback<number>): void;

function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<{deviceId: number, remote: rpc.IRemoteObject}>;

function bindDevice(deviceId: number, onDisconnect: AsyncCallback<number>): Promise<{deviceId: number, remote: rpc.IRemoteObject}>;

function queryDevices(busType?: number): Array<Readonly<Device>>;

**Change Impact**

Before the change, the APIs can be called without declaring the required permission, which poses security risks.

After the change, the APIs can be called only if the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission is declared.

**Involved APIs**

The **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission is required for calling the following APIs:
bindDevice
unbindDevice
queryDevices

**Adaptation Guide**

Apply for the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission when calling the related APIs.
