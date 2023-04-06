# JS API Changes of the Globalization Subsystem

The table below lists the APIs changes of the globalization subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| DeviceSettingsManager | DeviceSettingsManager | setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>setDateTime(admin: Want, time: number): Promise\<void>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | getDeviceSettingsManager(callback: AsyncCallback\<DeviceSettingsManager>): void;<br>getDeviceSettingsManager(): Promise\<DeviceSettingsManager>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>isSuperAdmin(bundleName: String): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<boolean>): void;<br>setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminAppActive(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminAppActive(admin: Want): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>deactivateSuperAdmin(bundleName: String): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>deactivateAdmin(admin: Want): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | AdminType | ADMIN_TYPE_SUPER = 0x01 | Added|
| ohos.enterpriseDeviceManager | AdminType | ADMIN_TYPE_NORMAL = 0x00 | Added|
| ohos.enterpriseDeviceManager | EnterpriseInfo | description: string; | Added|
| ohos.enterpriseDeviceManager | EnterpriseInfo | name: string; | Added|
| ohos.i18n | i18n | getAppPreferredLanguage(): string; | Added|
| ohos.resourceManager | ResourceManager | getNumberByName(resName: string): number; | Added|
| ohos.resourceManager | ResourceManager | getNumber(resId: number): number; | Added|
| ohos.resourceManager | ResourceManager | getBooleanByName(resName: string): boolean; | Added|
| ohos.resourceManager | ResourceManager | getBoolean(resId: number): boolean; | Added|
| ohos.resourceManager | ResourceManager | getStringByNameSync(resName: string): string; | Added|
| ohos.resourceManager | ResourceManager | getStringSync(resId: number): string; | Added|
| ohos.resourceManager | ResourceManager | getPluralStringByName(resName: string, num: number, callback: AsyncCallback\<string>): void;<br>getPluralStringByName(resName: string, num: number): Promise\<string>; | Added|
| ohos.resourceManager | ResourceManager | getMediaBase64ByName(resName: string, callback: AsyncCallback\<string>): void;<br>getMediaBase64ByName(resName: string): Promise\<string>; | Added|
| ohos.resourceManager | ResourceManager | getMediaByName(resName: string, callback: AsyncCallback\<Uint8Array>): void;<br>getMediaByName(resName: string): Promise\<Uint8Array>; | Added|
| ohos.resourceManager | ResourceManager | getStringArrayByName(resName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getStringArrayByName(resName: string): Promise\<Array\<string>>; | Added|
| ohos.resourceManager | ResourceManager | getStringByName(resName: string, callback: AsyncCallback\<string>): void;<br>getStringByName(resName: string): Promise\<string>; | Added|
