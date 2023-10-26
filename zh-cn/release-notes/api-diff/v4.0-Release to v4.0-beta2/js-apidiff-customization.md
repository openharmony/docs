| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：adminManager;<br>方法or属性：function authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：adminManager;<br>方法or属性：function authorizeAdmin(admin: Want, bundleName: string): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：bundleManager;<br>方法or属性：function install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：userId?: number;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：InstallParam;<br>方法or属性：installFlag?: number;|@ohos.enterprise.bundleManager.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function installUserCertificate(admin: Want, certificate: CertBlob): Promise\<string>;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：deviceSettings;<br>方法or属性：function uninstallUserCertificate(admin: Want, certUri: string): Promise\<void>;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：CertBlob;<br>方法or属性：inData: Uint8Array;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：CertBlob;<br>方法or属性：alias: string;|@ohos.enterprise.deviceSettings.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：networkManager;<br>方法or属性：function getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>;|@ohos.enterprise.networkManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>;|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：UsbPolicy;<br>方法or属性：READ_WRITE = 0|@ohos.enterprise.usbManager.d.ts|
|新增|NA|类名：UsbPolicy;<br>方法or属性：READ_ONLY = 1|@ohos.enterprise.usbManager.d.ts|
