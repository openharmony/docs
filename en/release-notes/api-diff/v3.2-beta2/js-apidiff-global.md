# JS API Changes of the Globalization Subsystem

The table below lists the APIs changes of the globalization subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.EnterpriseAdminExtensionAbility | EnterpriseAdminExtensionAbility | onAdminDisabled(): void; | Added|
| ohos.EnterpriseAdminExtensionAbility | EnterpriseAdminExtensionAbility | onAdminEnabled(): void; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | disableSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>disableSuperAdmin(bundleName: String): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | disableAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void;<br>disableAdmin(admin: Want, userId?: number): Promise\<boolean>; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<boolean>): void;<br>enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<boolean>; | Added|
| ohos.i18n | i18n | getUsingLocalDigit(): boolean; | Added|
| ohos.i18n | i18n | setUsingLocalDigit(flag: boolean): boolean; | Added|
| ohos.i18n | Transliterator | transform(text: string): string; | Added|
| ohos.i18n | Transliterator | static getInstance(id: string): Transliterator; | Added|
| ohos.i18n | Transliterator | static getAvailableIDs(): string[]; | Added|
| ohos.i18n | TimeZone | static getTimezoneFromCity(cityID: string): TimeZone; | Added|
| ohos.i18n | TimeZone | static getCityDisplayName(cityID: string, locale: string): string; | Added|
| ohos.i18n | TimeZone | static getAvailableZoneCityIDs(): Array\<string>; | Added|
| ohos.i18n | TimeZone | static getAvailableIDs(): Array\<string>; | Added|
| ohos.i18n | PhoneNumberFormat | getLocationName(number: string, locale: string): string; | Added|
| ohos.i18n | Util | getDateOrder(locale: string): string; | Added|
| resource | Resource | id: number; | Added|
| resource | Resource | moduleName: string; | Added|
| resource | Resource | bundleName: string; | Added|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | isAdminAppActive(admin: Want, callback: AsyncCallback\<boolean>): void;<br>isAdminAppActive(admin: Want): Promise\<boolean>; | Deleted|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void;<br>deactivateSuperAdmin(bundleName: String): Promise\<boolean>; | Deleted|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | deactivateAdmin(admin: Want, callback: AsyncCallback\<boolean>): void;<br>deactivateAdmin(admin: Want): Promise\<boolean>; | Deleted|
| ohos.enterpriseDeviceManager | enterpriseDeviceManager | activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void;<br>activateAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType): Promise\<boolean>; | Deleted|
