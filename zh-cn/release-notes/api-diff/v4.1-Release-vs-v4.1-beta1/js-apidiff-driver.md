| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：global；<br>API声明：export type DriverExtensionContext = _DriverExtensionContext;<br>差异内容：NA|类名：global；<br>API声明：export type DriverExtensionContext = _DriverExtensionContext;<br>差异内容：SystemCapability.Driver.ExternalDevice|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增API|NA|类名：deviceManager；<br>API声明：function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>, callback: AsyncCallback\<RemoteDeviceDriver>): void;<br>差异内容：function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>, callback: AsyncCallback\<RemoteDeviceDriver>): void;|api/@ohos.driver.deviceManager.d.ts|
|新增API|NA|类名：deviceManager；<br>API声明：function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<RemoteDeviceDriver>;<br>差异内容：function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<RemoteDeviceDriver>;|api/@ohos.driver.deviceManager.d.ts|
|新增API|NA|类名：deviceManager；<br>API声明： interface RemoteDeviceDriver<br>差异内容： interface RemoteDeviceDriver|api/@ohos.driver.deviceManager.d.ts|
|新增API|NA|类名：RemoteDeviceDriver；<br>API声明：deviceId: number;<br>差异内容：deviceId: number;|api/@ohos.driver.deviceManager.d.ts|
|新增API|NA|类名：RemoteDeviceDriver；<br>API声明：remote: rpc.IRemoteObject;<br>差异内容：remote: rpc.IRemoteObject;|api/@ohos.driver.deviceManager.d.ts|
|起始版本有变化|类名：global；<br>API声明：export type DriverExtensionContext = _DriverExtensionContext;<br>差异内容：NA|类名：global；<br>API声明：export type DriverExtensionContext = _DriverExtensionContext;<br>差异内容：10|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|kit变更|Driver Development Kit|DriverDevelopmentKit|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|kit变更|Driver Development Kit|DriverDevelopmentKit|api/@ohos.driver.deviceManager.d.ts|
