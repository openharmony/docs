| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：context: DriverExtensionContext;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：onInit(want: Want): void;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：onRelease(): void;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：onConnect(want: Want): rpc.RemoteObject \| Promise\<rpc.RemoteObject>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：onDisconnect(want: Want): void \| Promise\<void>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：DriverExtensionAbility;<br>方法or属性：onDump(params: Array\<string>): Array\<string>;|@ohos.app.ability.DriverExtensionAbility.d.ts|
|新增|NA|类名：deviceManager;<br>方法or属性：function queryDevices(busType?: number): Array\<Readonly\<Device>>;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：deviceManager;<br>方法or属性：function bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>,<br><br>    callback: AsyncCallback\<{deviceId: number, remote: rpc.IRemoteObject}>): void;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：deviceManager;<br>方法or属性：function bindDevice(deviceId: number, onDisconnect: AsyncCallback\<number>): Promise\<{deviceId: number,<br><br>    remote: rpc.IRemoteObject}>;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：deviceManager;<br>方法or属性：function unbindDevice(deviceId: number, callback: AsyncCallback\<number>): void;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：deviceManager;<br>方法or属性：function unbindDevice(deviceId: number): Promise\<number>;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：BusType;<br>方法or属性：USB = 1|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：Device;<br>方法or属性：busType: BusType;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：Device;<br>方法or属性：deviceId: number;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：Device;<br>方法or属性：description: string;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：vendorId: number;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：productId: number;|@ohos.driver.deviceManager.d.ts|
|新增|NA|类名：DriverExtensionContext;<br>方法or属性：updateDriverState(): void;|DriverExtensionContext.d.ts|
