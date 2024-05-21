| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|SysCap changed|Class name: global;<br>API declaration: export type DriverExtensionContext = _DriverExtensionContext;<br>Differences: NA|Class name: global;<br>API declaration: export type DriverExtensionContext = _DriverExtensionContext;<br>Differences: SystemCapability.Driver.ExternalDevice|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|API added|NA|Class name: deviceManager;<br>API declaration: function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>, callback: AsyncCallback\<RemoteDeviceDriver>): void;<br>Differences: function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>, callback: AsyncCallback\<RemoteDeviceDriver>): void;|api/@ohos.driver.deviceManager.d.ts|
|API added|NA|Class name: deviceManager;<br>API declaration: function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<RemoteDeviceDriver>;<br>Differences: function bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<RemoteDeviceDriver>;|api/@ohos.driver.deviceManager.d.ts|
|API added|NA|Class name: deviceManager;<br>API declaration:  interface RemoteDeviceDriver<br>Differences:  interface RemoteDeviceDriver|api/@ohos.driver.deviceManager.d.ts|
|API added|NA|Class name: RemoteDeviceDriver;<br>API declaration: deviceId: number;<br>Differences: deviceId: number;|api/@ohos.driver.deviceManager.d.ts|
|API added|NA|Class name: RemoteDeviceDriver;<br>API declaration: remote: rpc.IRemoteObject;<br>Differences: remote: rpc.IRemoteObject;|api/@ohos.driver.deviceManager.d.ts|
|Initial version changed|Class name: global;<br>API declaration: export type DriverExtensionContext = _DriverExtensionContext;<br>Differences: NA|Class name: global;<br>API declaration: export type DriverExtensionContext = _DriverExtensionContext;<br>Differences: 10|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|Kit changed|NA|DriverDevelopmentKit|api/@ohos.app.ability.DriverExtensionAbility.d.ts|
|Kit changed|NA|DriverDevelopmentKit|api/@ohos.driver.deviceManager.d.ts|
