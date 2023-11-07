| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: adminManager;<br>Method or attribute name: function authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: adminManager;<br>Method or attribute name: function authorizeAdmin(admin: Want, bundleName: string): Promise\<void>;|@ohos.enterprise.adminManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: bundleManager;<br>Method or attribute name: function install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: InstallParam;<br>Method or attribute name: userId?: number;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: InstallParam;<br>Method or attribute name: installFlag?: number;|@ohos.enterprise.bundleManager.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function installUserCertificate(admin: Want, certificate: CertBlob, callback: AsyncCallback\<string>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function installUserCertificate(admin: Want, certificate: CertBlob): Promise\<string>;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function uninstallUserCertificate(admin: Want, certUri: string, callback: AsyncCallback\<void>): void;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: deviceSettings;<br>Method or attribute name: function uninstallUserCertificate(admin: Want, certUri: string): Promise\<void>;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: CertBlob;<br>Method or attribute name: inData: Uint8Array;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: CertBlob;<br>Method or attribute name: alias: string;|@ohos.enterprise.deviceSettings.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function setGlobalProxy(admin: Want, httpProxy: connection.HttpProxy): Promise\<void>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getGlobalProxy(admin: Want, callback: AsyncCallback\<connection.HttpProxy>): void;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: networkManager;<br>Method or attribute name: function getGlobalProxy(admin: Want): Promise\<connection.HttpProxy>;|@ohos.enterprise.networkManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void;|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>;|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: UsbPolicy;<br>Method or attribute name: READ_WRITE = 0|@ohos.enterprise.usbManager.d.ts|
|Added|NA|Class name: UsbPolicy;<br>Method or attribute name: READ_ONLY = 1|@ohos.enterprise.usbManager.d.ts|
