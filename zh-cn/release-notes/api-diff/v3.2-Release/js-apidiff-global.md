| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：i18n;<br>方法or属性：export function getSystemLanguages(): Array\<string>;|NA|@ohos.i18n.d.ts|
|删除|类名：i18n;<br>方法or属性：export function getSystemCountries(language: string): Array\<string>;|NA|@ohos.i18n.d.ts|
|删除|类名：i18n;<br>方法or属性：export function isSuggested(language: string, region?: string): boolean;|NA|@ohos.i18n.d.ts|
|删除|类名：i18n;<br>方法or属性：export function setSystemLanguage(language: string): boolean;|NA|@ohos.i18n.d.ts|
|删除|类名：i18n;<br>方法or属性：export function setSystemRegion(region: string): boolean;|NA|@ohos.i18n.d.ts|
|删除|类名：i18n;<br>方法or属性：export function setSystemLocale(locale: string): boolean;|NA|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getSystemLanguages(): Array\<string>;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getSystemCountries(language: string): Array\<string>;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static isSuggested(language: string, region?: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getSystemLanguage(): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static setSystemLanguage(language: string): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getSystemRegion(): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static setSystemRegion(region: string): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getSystemLocale(): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static setSystemLocale(locale: string): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static is24HourClock(): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static set24HourClock(option: boolean): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static addPreferredLanguage(language: string, index?: number): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static removePreferredLanguage(index: number): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getPreferredLanguageList(): Array\<string>;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getFirstPreferredLanguage(): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getAppPreferredLanguage(): string;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static setUsingLocalDigit(flag: boolean): void;|@ohos.i18n.d.ts|
|新增|NA|类名：System;<br>方法or属性：static getUsingLocalDigit(): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：I18NUtil;<br>方法or属性：static unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：I18NUtil;<br>方法or属性：static getDateOrder(locale: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：PhoneNumberFormat;<br>方法or属性：getLocationName(number: string, locale: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isDigit(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isSpaceChar(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isWhitespace(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isRTL(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isIdeograph(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isLetter(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isLowerCase(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static isUpperCase(char: string): boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：Unicode;<br>方法or属性：static getType(char: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZone;<br>方法or属性：static getAvailableIDs(): Array\<string>;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZone;<br>方法or属性：static getAvailableZoneCityIDs(): Array\<string>;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZone;<br>方法or属性：static getCityDisplayName(cityID: string, locale: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZone;<br>方法or属性：static getTimezoneFromCity(cityID: string): TimeZone;|@ohos.i18n.d.ts|
|新增|NA|类名：Transliterator;<br>方法or属性：static getAvailableIDs(): string[];|@ohos.i18n.d.ts|
|新增|NA|类名：Transliterator;<br>方法or属性：static getInstance(id: string): Transliterator;|@ohos.i18n.d.ts|
|新增|NA|类名：Transliterator;<br>方法or属性：transform(text: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：resourceManager;<br>方法or属性：export type RawFileDescriptor = _RawFileDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：resourceManager;<br>方法or属性：export type Resource = _Resource;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number): Promise\<Array\<string>>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getConfiguration(callback: _AsyncCallback\<Configuration>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string): Promise\<Array\<string>>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringSync(resId: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringByNameSync(resName: string): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getBoolean(resId: number): boolean;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getBooleanByName(resName: string): boolean;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getNumber(resId: number): number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getNumberByName(resName: string): number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFd(path: string): Promise\<RawFileDescriptor>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string, callback: _AsyncCallback\<void>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string): Promise\<void>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：bundleName: string;|resource.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：moduleName: string;|resource.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：id: number;|resource.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>新版本信息：9<br>代替接口： ohos.System.getDisplayCountry|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>新版本信息：9<br>代替接口： ohos.System.getDisplayLanguage|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getSystemLanguage(): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getSystemLanguage(): string;<br>新版本信息：9<br>代替接口： ohos.System.getSystemLanguage|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getSystemRegion(): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getSystemRegion(): string;<br>新版本信息：9<br>代替接口： ohos.System.getSystemRegion|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getSystemLocale(): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getSystemLocale(): string;<br>新版本信息：9<br>代替接口： ohos.System.getSystemLocale|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function is24HourClock(): boolean;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function is24HourClock(): boolean;<br>新版本信息：9<br>代替接口： ohos.System.is24HourClock|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function set24HourClock(option: boolean): boolean;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function set24HourClock(option: boolean): boolean;<br>新版本信息：9<br>代替接口： ohos.System.set24HourClock|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function addPreferredLanguage(language: string, index?: number): boolean;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function addPreferredLanguage(language: string, index?: number): boolean;<br>新版本信息：9<br>代替接口： ohos.System.addPreferredLanguage|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function removePreferredLanguage(index: number): boolean;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function removePreferredLanguage(index: number): boolean;<br>新版本信息：9<br>代替接口： ohos.System.removePreferredLanguage|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getPreferredLanguageList(): Array\<string>;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getPreferredLanguageList(): Array\<string>;<br>新版本信息：9<br>代替接口： ohos.System.getPreferredLanguageList|@ohos.i18n.d.ts|
|废弃版本有变化|类名：i18n;<br>方法or属性：export function getFirstPreferredLanguage(): string;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getFirstPreferredLanguage(): string;<br>新版本信息：9<br>代替接口： ohos.System.getFirstPreferredLanguage|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Util;<br>方法or属性：export interface Util<br>旧版本信息：|类名：Util;<br>方法or属性：export interface Util<br>新版本信息：9<br>代替接口： I18NUtil|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Util;<br>方法or属性：unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string;<br>旧版本信息：|类名：Util;<br>方法or属性：unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string;<br>新版本信息：9<br>代替接口： I18NUtil.unitConvert|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：export class Character<br>旧版本信息：|类名：Character;<br>方法or属性：export class Character<br>新版本信息：9<br>代替接口： Unicode|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isDigit(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isDigit(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isDigit|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isSpaceChar(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isSpaceChar(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isSpaceChar|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isWhitespace(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isWhitespace(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isWhitespace|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isRTL(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isRTL(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isRTL|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isIdeograph(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isIdeograph(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isIdeograph|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isLetter(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isLetter(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isLetter|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isLowerCase(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isLowerCase(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isLowerCase|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：isUpperCase(char: string): boolean;<br>旧版本信息：|类名：Character;<br>方法or属性：isUpperCase(char: string): boolean;<br>新版本信息：9<br>代替接口： Unicode.isUpperCase|@ohos.i18n.d.ts|
|废弃版本有变化|类名：Character;<br>方法or属性：getType(char: string): string;<br>旧版本信息：|类名：Character;<br>方法or属性：getType(char: string): string;<br>新版本信息：9<br>代替接口： Unicode.getType|@ohos.i18n.d.ts|
|废弃版本有变化|类名：AsyncCallback;<br>方法or属性：export interface AsyncCallback<br>旧版本信息：|类名：AsyncCallback;<br>方法or属性：export interface AsyncCallback<br>新版本信息：9<br>代替接口：|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：AsyncCallback;<br>方法or属性：(err: Error, data: T): void;<br>旧版本信息：|类名：AsyncCallback;<br>方法or属性：(err: Error, data: T): void;<br>新版本信息：9<br>代替接口：|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getString(resId: number, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getString(resId: number, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getStringValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getString(resId: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getString(resId: number): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getStringValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getStringArray(resId: number, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArray(resId: number, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getStringArrayValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getStringArray(resId: number): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArray(resId: number): Promise\<Array\<string>>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getStringArrayValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getMedia(resId: number, callback: AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMedia(resId: number, callback: AsyncCallback\<Uint8Array>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getMediaContent|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getMedia(resId: number): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMedia(resId: number): Promise\<Uint8Array>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getMediaContent|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getMediaBase64(resId: number, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaBase64(resId: number, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getMediaContentBase64|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getMediaBase64(resId: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaBase64(resId: number): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getMediaContentBase64|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getPluralString(resId: number, num: number, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralString(resId: number, num: number, callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getPluralStringValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getPluralString(resId: number, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralString(resId: number, num: number): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getPluralStringValue|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getRawFile(path: string, callback: AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFile(path: string, callback: AsyncCallback\<Uint8Array>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getRawFileContent|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getRawFile(path: string): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFile(path: string): Promise\<Uint8Array>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getRawFileContent|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getRawFd|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.getRawFd|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：closeRawFileDescriptor(path: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：closeRawFileDescriptor(path: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.resourceManager.closeRawFd|@ohos.resourceManager.d.ts|
|废弃版本有变化|类名：ResourceManager;<br>方法or属性：closeRawFileDescriptor(path: string): Promise\<void>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：closeRawFileDescriptor(path: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.resourceManager.closeRawFd|@ohos.resourceManager.d.ts|
|type有变化|类名：PhoneNumberFormatOptions;<br>方法or属性：type?: string;<br>旧版本信息：|类名：PhoneNumberFormatOptions;<br>方法or属性：type?: string;<br>新版本信息：string|@ohos.i18n.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：numberingSystem?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：numberingSystem?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：boolean|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：boolean|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：locale?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：locale?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：locale?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：locale?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeZone?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeZone?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean<br>新版本信息：boolean|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：weekday?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：weekday?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：era?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：era?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：year?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：year?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：month?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：month?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：day?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：day?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hour?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hour?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：minute?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：minute?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：second?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：second?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：localeMatcher?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：localeMatcher?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currency?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currency?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currencySign?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currencySign?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unit?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unit?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unitDisplay?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unitDisplay?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unitUsage?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unitUsage?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：signDisplay?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：signDisplay?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：compactDisplay?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：compactDisplay?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：notation?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：notation?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：style?: string<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：style?: string<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean<br>新版本信息：boolean|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>新版本信息：number|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>新版本信息：boolean|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>新版本信息：string|@ohos.intl.d.ts|
|函数有变化|类名：PhoneNumberFormatOptions;<br>方法or属性：type: string;|类名：PhoneNumberFormatOptions;<br>方法or属性：type?: string;|@ohos.i18n.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：calendar: string;|类名：LocaleOptions;<br>方法or属性：calendar?: string;|@ohos.intl.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：collation: string;|类名：LocaleOptions;<br>方法or属性：collation?: string;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：collation: string;|类名：CollatorOptions;<br>方法or属性：collation?: string;|@ohos.intl.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：hourCycle: string;|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：hourCycle: string|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string|@ohos.intl.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：numberingSystem: string;|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：numberingSystem: string|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：numberingSystem: string|类名：NumberOptions;<br>方法or属性：numberingSystem?: string|@ohos.intl.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：numeric: boolean;|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：numeric: boolean;|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;|@ohos.intl.d.ts|
|函数有变化|类名：LocaleOptions;<br>方法or属性：caseFirst: string;|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：caseFirst: string;|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：locale: string|类名：DateTimeOptions;<br>方法or属性：locale?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：locale: string|类名：NumberOptions;<br>方法or属性：locale?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：dateStyle: string|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：timeStyle: string|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：timeZone: string|类名：DateTimeOptions;<br>方法or属性：timeZone?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：hour12: boolean|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：weekday: string|类名：DateTimeOptions;<br>方法or属性：weekday?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：era: string|类名：DateTimeOptions;<br>方法or属性：era?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：year: string|类名：DateTimeOptions;<br>方法or属性：year?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：month: string|类名：DateTimeOptions;<br>方法or属性：month?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：day: string|类名：DateTimeOptions;<br>方法or属性：day?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：hour: string|类名：DateTimeOptions;<br>方法or属性：hour?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：minute: string|类名：DateTimeOptions;<br>方法or属性：minute?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：second: string|类名：DateTimeOptions;<br>方法or属性：second?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：timeZoneName: string|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：dayPeriod: string|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：localeMatcher: string|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：localeMatcher: string|类名：NumberOptions;<br>方法or属性：localeMatcher?: string|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：localeMatcher: string;|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：localeMatcher: string;|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;|@ohos.intl.d.ts|
|函数有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher: string;|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;|@ohos.intl.d.ts|
|函数有变化|类名：DateTimeOptions;<br>方法or属性：formatMatcher: string|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：currency: string|类名：NumberOptions;<br>方法or属性：currency?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：currencySign: string|类名：NumberOptions;<br>方法or属性：currencySign?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：currencyDisplay: string|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：unit: string|类名：NumberOptions;<br>方法or属性：unit?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：unitDisplay: string|类名：NumberOptions;<br>方法or属性：unitDisplay?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：unitUsage: string|类名：NumberOptions;<br>方法or属性：unitUsage?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：signDisplay: string|类名：NumberOptions;<br>方法or属性：signDisplay?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：compactDisplay: string|类名：NumberOptions;<br>方法or属性：compactDisplay?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：notation: string|类名：NumberOptions;<br>方法or属性：notation?: string|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：style: string|类名：NumberOptions;<br>方法or属性：style?: string|@ohos.intl.d.ts|
|函数有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style: string;|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：useGrouping: boolean|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits: number|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits: number;|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：minimumFractionDigits: number|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits: number;|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：maximumFractionDigits: number|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits: number;|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits: number|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits: number;|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;|@ohos.intl.d.ts|
|函数有变化|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits: number|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits: number;|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：usage: string;|类名：CollatorOptions;<br>方法or属性：usage?: string;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：sensitivity: string;|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;|@ohos.intl.d.ts|
|函数有变化|类名：CollatorOptions;<br>方法or属性：ignorePunctuation: boolean;|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;|@ohos.intl.d.ts|
|函数有变化|类名：PluralRulesOptions;<br>方法or属性：type: string;|类名：PluralRulesOptions;<br>方法or属性：type?: string;|@ohos.intl.d.ts|
|函数有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric: string;|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;|@ohos.intl.d.ts|
