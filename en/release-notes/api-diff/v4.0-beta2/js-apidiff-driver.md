| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: context: DriverExtensionContext;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: onInit(want: Want): void;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: onRelease(): void;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: onConnect(want: Want): rpc.RemoteObject \| Promise\<rpc.RemoteObject>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: onDisconnect(want: Want): void \| Promise\<void>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: DriverExtensionAbility;<br>Method or attribute name: onDump(params: Array\<string>): Array\<string>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|Added|NA|Class name: deviceManager;<br>Method or attribute name: function queryDevices(busType?: number): Array\<Readonly\<Device>>;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: deviceManager;<br>Method or attribute name: function bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>,<br><br>    callback: AsyncCallback\<{deviceId: number, remote: rpc.IRemoteObject}>): void;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: deviceManager;<br>Method or attribute name: function bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<{deviceId: number,<br><br>    remote: rpc.IRemoteObject}>;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: deviceManager;<br>Method or attribute name: function unbindDevice(deviceId: number, callback: AsyncCallback\<number>): void;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: deviceManager;<br>Method or attribute name: function unbindDevice(deviceId: number): Promise\<number>;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: BusType;<br>Method or attribute name: USB = 1|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: Device;<br>Method or attribute name: busType: BusType;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: Device;<br>Method or attribute name: deviceId: number;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: Device;<br>Method or attribute name: description: string;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: vendorId: number;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: productId: number;|@ohos.driver.deviceManager.d.ts|
|Added|NA|Class name: DriverExtensionContext;<br>Method or attribute name: updateDriverState(): void;|DriverExtensionContext.d.ts|
