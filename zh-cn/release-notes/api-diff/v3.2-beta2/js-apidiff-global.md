# 全球化子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，全球化子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.EnterpriseAdminExtensionAbility | EnterpriseAdminExtensionAbility | onAdminDisabled(): void; | 新增 |
| ohos.EnterpriseAdminExtensionAbility | EnterpriseAdminExtensionAbility | onAdminEnabled(): void; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | disableSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>disableSuperAdmin(bundleName: String): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | disableAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>disableAdmin(admin: Want, userId?: number): Promise\<boolean>; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<boolean>): void;<br>enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<boolean>; | 新增 |
| ohos.i18n | i18n | getUsingLocalDigit(): boolean; | 新增 |
| ohos.i18n | i18n | setUsingLocalDigit(flag: boolean): boolean; | 新增 |
| ohos.i18n | Transliterator | transform(text: string): string; | 新增 |
| ohos.i18n | Transliterator | static getInstance(id: string): Transliterator; | 新增 |
| ohos.i18n | Transliterator | static getAvailableIDs(): string[]; | 新增 |
| ohos.i18n | TimeZone | static getTimezoneFromCity(cityID: string): TimeZone; | 新增 |
| ohos.i18n | TimeZone | static getCityDisplayName(cityID: string, locale: string): string; | 新增 |
| ohos.i18n | TimeZone | static getAvailableZoneCityIDs(): Array\<string>; | 新增 |
| ohos.i18n | TimeZone | static getAvailableIDs(): Array\<string>; | 新增 |
| ohos.i18n | PhoneNumberFormat | getLocationName(number: string, locale: string): string; | 新增 |
| ohos.i18n | Util | getDateOrder(locale: string): string; | 新增 |
| resource | Resource | id: number; | 新增 |
| resource | Resource | moduleName: string; | 新增 |
| resource | Resource | bundleName: string; | 新增 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminAppActive(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminAppActive(admin: Want): Promise\<boolean>; | 删除 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>deactivateSuperAdmin(bundleName: String): Promise\<boolean>; | 删除 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>deactivateAdmin(admin: Want): Promise\<boolean>; | 删除 |
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType): Promise\<boolean>; | 删除 |

