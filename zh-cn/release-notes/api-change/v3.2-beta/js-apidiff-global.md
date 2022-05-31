# 全球化子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，全球化子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| DeviceSettingsManager | DeviceSettingsManager | setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void;<br>setDateTime(admin: Want, time: number): Promise\<void>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | getDeviceSettingsManager(callback: AsyncCallback\<DeviceSettingsManager>): void;<br>getDeviceSettingsManager(): Promise\<DeviceSettingsManager>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>isSuperAdmin(bundleName: String): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<boolean>): void;<br>setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | getEnterpriseInfo(admin: Want, callback: AsyncCallback\<EnterpriseInfo>): void;<br>getEnterpriseInfo(admin: Want): Promise\<EnterpriseInfo>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminAppActive(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminAppActive(admin: Want): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>deactivateSuperAdmin(bundleName: String): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>deactivateAdmin(admin: Want): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | AdminType | ADMIN_TYPE_SUPER = 0x01 | 新增 |
| ohos.enterpriseDeviceManager | AdminType | ADMIN_TYPE_NORMAL = 0x00 | 新增 |
| ohos.enterpriseDeviceManager | EnterpriseInfo | description: string; | 新增 |
| ohos.enterpriseDeviceManager | EnterpriseInfo | name: string; | 新增 |
| ohos.i18n | i18n | getAppPreferredLanguage(): string; | 新增 |
| ohos.resourceManager | ResourceManager | getNumberByName(resName: string): number; | 新增 |
| ohos.resourceManager | ResourceManager | getNumber(resId: number): number; | 新增 |
| ohos.resourceManager | ResourceManager | getBooleanByName(resName: string): boolean; | 新增 |
| ohos.resourceManager | ResourceManager | getBoolean(resId: number): boolean; | 新增 |
| ohos.resourceManager | ResourceManager | getStringByNameSync(resName: string): string; | 新增 |
| ohos.resourceManager | ResourceManager | getStringSync(resId: number): string; | 新增 |
| ohos.resourceManager | ResourceManager | getPluralStringByName(resName: string, num: number, callback: AsyncCallback\<string>): void;<br>getPluralStringByName(resName: string, num: number): Promise\<string>; | 新增 |
| ohos.resourceManager | ResourceManager | getMediaBase64ByName(resName: string, callback: AsyncCallback\<string>): void;<br>getMediaBase64ByName(resName: string): Promise\<string>; | 新增 |
| ohos.resourceManager | ResourceManager | getMediaByName(resName: string, callback: AsyncCallback\<Uint8Array>): void;<br>getMediaByName(resName: string): Promise\<Uint8Array>; | 新增 |
| ohos.resourceManager | ResourceManager | getStringArrayByName(resName: string, callback: AsyncCallback\<Array\<string>>): void;<br>getStringArrayByName(resName: string): Promise\<Array\<string>>; | 新增 |
| ohos.resourceManager | ResourceManager | getStringByName(resName: string, callback: AsyncCallback\<string>): void;<br>getStringByName(resName: string): Promise\<string>; | 新增 |

