| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：TimeZone;<br>方法or属性：static getTimezonesByLocation(longitude: number, latitude: number): Array\<TimeZone>;|@ohos.i18n.d.ts|
|新增|NA|类名：NormalizerMode;<br>方法or属性：NFC = 1|@ohos.i18n.d.ts|
|新增|NA|类名：NormalizerMode;<br>方法or属性：NFD = 2|@ohos.i18n.d.ts|
|新增|NA|类名：NormalizerMode;<br>方法or属性：NFKC = 3|@ohos.i18n.d.ts|
|新增|NA|类名：NormalizerMode;<br>方法or属性：NFKD = 4|@ohos.i18n.d.ts|
|新增|NA|类名：Normalizer;<br>方法or属性：static getInstance(mode: NormalizerMode): Normalizer;|@ohos.i18n.d.ts|
|新增|NA|类名：Normalizer;<br>方法or属性：normalize(text: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：SuggestionType;<br>方法or属性：SUGGESTION_TYPE_NONE = 0|@ohos.i18n.d.ts|
|新增|NA|类名：SuggestionType;<br>方法or属性：SUGGESTION_TYPE_RELATED = 1|@ohos.i18n.d.ts|
|新增|NA|类名：SuggestionType;<br>方法or属性：SUGGESTION_TYPE_SIM = 2|@ohos.i18n.d.ts|
|新增|NA|类名：SortOptions;<br>方法or属性：locale?: string;|@ohos.i18n.d.ts|
|新增|NA|类名：SortOptions;<br>方法or属性：isUseLocalName?: boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：SortOptions;<br>方法or属性：isSuggestedFirst?: boolean;|@ohos.i18n.d.ts|
|新增|NA|类名：LocaleItem;<br>方法or属性：id: string;|@ohos.i18n.d.ts|
|新增|NA|类名：LocaleItem;<br>方法or属性：suggestionType: SuggestionType;|@ohos.i18n.d.ts|
|新增|NA|类名：LocaleItem;<br>方法or属性：displayName: string;|@ohos.i18n.d.ts|
|新增|NA|类名：LocaleItem;<br>方法or属性：localName?: string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：zoneId: string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：cityId: string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：cityDisplayName: string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：offset: number;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：zoneDisplayName: string;|@ohos.i18n.d.ts|
|新增|NA|类名：TimeZoneCityItem;<br>方法or属性：rawOffset?: number;|@ohos.i18n.d.ts|
|新增|NA|类名：SystemLocaleManager;<br>方法or属性：constructor();|@ohos.i18n.d.ts|
|新增|NA|类名：SystemLocaleManager;<br>方法or属性：getLanguageInfoArray(languages: Array\<string>, options?: SortOptions): Array\<LocaleItem>;|@ohos.i18n.d.ts|
|新增|NA|类名：SystemLocaleManager;<br>方法or属性：getRegionInfoArray(regions: Array\<string>, options?: SortOptions): Array\<LocaleItem>;|@ohos.i18n.d.ts|
|新增|NA|类名：SystemLocaleManager;<br>方法or属性：static getTimeZoneCityItemArray(): Array\<TimeZoneCityItem>;|@ohos.i18n.d.ts|
|新增|NA|类名：resourceManager;<br>方法or属性：export function getSystemResourceManager(): ResourceManager;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, density: number, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, density: number): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number, density: number, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number, density: number): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, density: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, density: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number, density: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number, density: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string, density: number, callback: _AsyncCallback\<Uint8Array>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string, density: number): Promise\<Uint8Array>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string, density: number, callback: _AsyncCallback\<string>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string, density: number): Promise\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringSync(resId: number, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringByNameSync(resName: string, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDrawableDescriptor(resId: number, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDrawableDescriptor(resource: Resource, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDrawableDescriptorByName(resName: string, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileList(path: string, callback: _AsyncCallback\<Array\<string>>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileList(path: string): Promise\<Array\<string>>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColor(resId: number, callback: _AsyncCallback\<number>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColor(resId: number): Promise\<number>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColor(resource: Resource, callback: _AsyncCallback\<number>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColor(resource: Resource): Promise\<number>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColorByName(resName: string, callback: _AsyncCallback\<number>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColorByName(resName: string): Promise\<number>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColorSync(resId: number) : number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColorSync(resource: Resource) : number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getColorByNameSync(resName: string) : number;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：addResource(path: string) : void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：removeResource(path: string) : void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFdSync(path: string): RawFileDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：closeRawFdSync(path: string): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileListSync(path: string): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getRawFileContentSync(path: string): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentSync(resId: number, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentSync(resource: Resource, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64Sync(resId: number, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaContentBase64Sync(resource: Resource, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValueSync(resId: number, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringValueSync(resource: Resource, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValueSync(resId: number): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayValueSync(resource: Resource): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getPluralStringByNameSync(resName: string, num: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaByNameSync(resName: string, density?: number): Uint8Array;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getMediaBase64ByNameSync(resName: string, density?: number): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getStringArrayByNameSync(resName: string): Array\<string>;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getConfigurationSync(): Configuration;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager;<br>方法or属性：getDeviceCapabilitySync(): DeviceCapability;|@ohos.resourceManager.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：params?: any[];|resource.d.ts|
|新增|NA|类名：Resource;<br>方法or属性：type?: number;|resource.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|model有变化|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>新版本信息：stagemodelonly|@ohos.resourceManager.d.ts|
|type有变化|类名：PhoneNumberFormatOptions;<br>方法or属性：type?: string;<br>旧版本信息：string|类名：PhoneNumberFormatOptions;<br>方法or属性：type?: string;<br>新版本信息：?string|@ohos.i18n.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>旧版本信息：string|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>旧版本信息：string|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>旧版本信息：string|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>旧版本信息：string|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：string|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：boolean|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：?boolean|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：boolean|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：?boolean|@ohos.intl.d.ts|
|type有变化|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：string|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：string|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：locale?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：locale?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：locale?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：locale?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeZone?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：timeZone?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean;<br>旧版本信息：boolean|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean;<br>新版本信息：?boolean|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：weekday?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：weekday?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：era?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：era?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：year?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：year?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：month?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：month?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：day?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：day?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：hour?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：hour?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：minute?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：minute?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：second?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：second?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：string|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：string|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：string|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string;<br>旧版本信息：string|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currency?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：currency?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currencySign?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：currencySign?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unit?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：unit?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unitDisplay?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：unitDisplay?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：unitUsage?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：unitUsage?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：signDisplay?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：signDisplay?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：compactDisplay?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：compactDisplay?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：notation?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：notation?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：style?: string;<br>旧版本信息：string|类名：NumberOptions;<br>方法or属性：style?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>旧版本信息：string|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean;<br>旧版本信息：boolean|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean;<br>新版本信息：?boolean|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>旧版本信息：number|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>旧版本信息：number|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number;<br>旧版本信息：number|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>旧版本信息：number|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number;<br>旧版本信息：number|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>旧版本信息：number|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>旧版本信息：number|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>旧版本信息：number|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>旧版本信息：number|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>旧版本信息：number|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>新版本信息：?number|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>旧版本信息：string|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>旧版本信息：string|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>旧版本信息：boolean|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>新版本信息：?boolean|@ohos.intl.d.ts|
|type有变化|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>旧版本信息：string|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>旧版本信息：string|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>新版本信息：?string|@ohos.intl.d.ts|
|type有变化|类名：Resource;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：bundleName: string;<br>新版本信息：string|resource.d.ts|
|type有变化|类名：Resource;<br>方法or属性：moduleName: string;<br>旧版本信息：|类名：Resource;<br>方法or属性：moduleName: string;<br>新版本信息：string|resource.d.ts|
|type有变化|类名：Resource;<br>方法or属性：id: number;<br>旧版本信息：|类名：Resource;<br>方法or属性：id: number;<br>新版本信息：number|resource.d.ts|
|跨平台能力有变化|类名：i18n;<br>方法or属性：export function getCalendar(locale: string, type?: string): Calendar;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getCalendar(locale: string, type?: string): Calendar;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：i18n;<br>方法or属性：export function isRTL(locale: string): boolean;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function isRTL(locale: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：i18n;<br>方法or属性：export function getTimeZone(zoneID?: string): TimeZone;<br>旧版本信息：|类名：i18n;<br>方法or属性：export function getTimeZone(zoneID?: string): TimeZone;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：export class System<br>旧版本信息：|类名：System;<br>方法or属性：export class System<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>旧版本信息：|类名：System;<br>方法or属性：static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>旧版本信息：|类名：System;<br>方法or属性：static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static getSystemLanguage(): string;<br>旧版本信息：|类名：System;<br>方法or属性：static getSystemLanguage(): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static getSystemRegion(): string;<br>旧版本信息：|类名：System;<br>方法or属性：static getSystemRegion(): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static getSystemLocale(): string;<br>旧版本信息：|类名：System;<br>方法or属性：static getSystemLocale(): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：System;<br>方法or属性：static is24HourClock(): boolean;<br>旧版本信息：|类名：System;<br>方法or属性：static is24HourClock(): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：I18NUtil;<br>方法or属性：export class I18NUtil<br>旧版本信息：|类名：I18NUtil;<br>方法or属性：export class I18NUtil<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：I18NUtil;<br>方法or属性：static getDateOrder(locale: string): string;<br>旧版本信息：|类名：I18NUtil;<br>方法or属性：static getDateOrder(locale: string): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：setTime(date: Date): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：setTime(date: Date): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：setTime(time: number): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：setTime(time: number): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：set(year: number, month: number, date: number, hour?: number, minute?: number, second?: number): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：set(year: number, month: number, date: number, hour?: number, minute?: number, second?: number): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：setTimeZone(timezone: string): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：setTimeZone(timezone: string): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：getTimeZone(): string;<br>旧版本信息：|类名：Calendar;<br>方法or属性：getTimeZone(): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：getFirstDayOfWeek(): number;<br>旧版本信息：|类名：Calendar;<br>方法or属性：getFirstDayOfWeek(): number;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：setFirstDayOfWeek(value: number): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：setFirstDayOfWeek(value: number): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：getMinimalDaysInFirstWeek(): number;<br>旧版本信息：|类名：Calendar;<br>方法or属性：getMinimalDaysInFirstWeek(): number;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：setMinimalDaysInFirstWeek(value: number): void;<br>旧版本信息：|类名：Calendar;<br>方法or属性：setMinimalDaysInFirstWeek(value: number): void;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：get(field: string): number;<br>旧版本信息：|类名：Calendar;<br>方法or属性：get(field: string): number;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Calendar;<br>方法or属性：isWeekend(date?: Date): boolean;<br>旧版本信息：|类名：Calendar;<br>方法or属性：isWeekend(date?: Date): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：export class Unicode<br>旧版本信息：|类名：Unicode;<br>方法or属性：export class Unicode<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isDigit(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isDigit(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isSpaceChar(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isSpaceChar(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isWhitespace(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isWhitespace(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isRTL(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isRTL(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isIdeograph(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isIdeograph(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isLetter(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isLetter(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isLowerCase(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isLowerCase(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static isUpperCase(char: string): boolean;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static isUpperCase(char: string): boolean;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：Unicode;<br>方法or属性：static getType(char: string): string;<br>旧版本信息：|类名：Unicode;<br>方法or属性：static getType(char: string): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：TimeZone;<br>方法or属性：export class TimeZone<br>旧版本信息：|类名：TimeZone;<br>方法or属性：export class TimeZone<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：TimeZone;<br>方法or属性：getID(): string;<br>旧版本信息：|类名：TimeZone;<br>方法or属性：getID(): string;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：TimeZone;<br>方法or属性：getRawOffset(): number;<br>旧版本信息：|类名：TimeZone;<br>方法or属性：getRawOffset(): number;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：TimeZone;<br>方法or属性：getOffset(date?: number): number;<br>旧版本信息：|类名：TimeZone;<br>方法or属性：getOffset(date?: number): number;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：TimeZone;<br>方法or属性：static getAvailableIDs(): Array\<string>;<br>旧版本信息：|类名：TimeZone;<br>方法or属性：static getAvailableIDs(): Array\<string>;<br>新版本信息：crossplatform|@ohos.i18n.d.ts|
|跨平台能力有变化|类名：intl;<br>方法or属性：declare intl<br>旧版本信息：|类名：intl;<br>方法or属性：declare intl<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：export interface LocaleOptions<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：export interface LocaleOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：calendar?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：collation?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：collation?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：hourCycle?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hourCycle?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：numberingSystem?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：numberingSystem?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：numeric?: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：|类名：LocaleOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：caseFirst?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：export class Locale<br>旧版本信息：|类名：Locale;<br>方法or属性：export class Locale<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：constructor();<br>旧版本信息：|类名：Locale;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：constructor();<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberFormat;<br>方法or属性：constructor();<br>旧版本信息：|类名：NumberFormat;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Collator;<br>方法or属性：constructor();<br>旧版本信息：|类名：Collator;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRules;<br>方法or属性：constructor();<br>旧版本信息：|类名：PluralRules;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：constructor();<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：constructor();<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：constructor(locale: string, options?: LocaleOptions);<br>旧版本信息：|类名：Locale;<br>方法or属性：constructor(locale: string, options?: LocaleOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：language: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：language: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：script: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：script: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：region: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：region: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：baseName: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：baseName: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：caseFirst: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：caseFirst: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：calendar: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：calendar: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：collation: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：collation: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：hourCycle: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：hourCycle: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：numberingSystem: string;<br>旧版本信息：|类名：Locale;<br>方法or属性：numberingSystem: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：numberingSystem: string;<br>旧版本信息：|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：numberingSystem: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：numeric: boolean;<br>旧版本信息：|类名：Locale;<br>方法or属性：numeric: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：toString(): string;<br>旧版本信息：|类名：Locale;<br>方法or属性：toString(): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：maximize(): Locale;<br>旧版本信息：|类名：Locale;<br>方法or属性：maximize(): Locale;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Locale;<br>方法or属性：minimize(): Locale;<br>旧版本信息：|类名：Locale;<br>方法or属性：minimize(): Locale;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：export interface DateTimeOptions<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：export interface DateTimeOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：locale?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：locale?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：dateStyle?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeStyle?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：timeZone?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeZone?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hour12?: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：weekday?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：weekday?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：era?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：era?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：year?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：year?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：month?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：month?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：day?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：day?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：hour?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：hour?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：minute?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：minute?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：second?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：second?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：timeZoneName?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：dayPeriod?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：localeMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string;<br>旧版本信息：|类名：DateTimeOptions;<br>方法or属性：formatMatcher?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：export class DateTimeFormat<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：export class DateTimeFormat<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: DateTimeOptions);<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: DateTimeOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：format(date: Date): string;<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：format(date: Date): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：formatRange(startDate: Date, endDate: Date): string;<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：formatRange(startDate: Date, endDate: Date): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：DateTimeFormat;<br>方法or属性：resolvedOptions(): DateTimeOptions;<br>旧版本信息：|类名：DateTimeFormat;<br>方法or属性：resolvedOptions(): DateTimeOptions;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：export interface NumberOptions<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：export interface NumberOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：currency?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currency?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：currencySign?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currencySign?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：currencyDisplay?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：unit?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unit?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：unitDisplay?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unitDisplay?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：unitUsage?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：unitUsage?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：signDisplay?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：signDisplay?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：compactDisplay?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：compactDisplay?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：notation?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：notation?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：style?: string;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：style?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：style?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：useGrouping?: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumIntegerDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumFractionDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumFractionDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：maximumFractionDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：maximumFractionDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：minimumSignificantDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>旧版本信息：|类名：NumberOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：maximumSignificantDigits?: number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberFormat;<br>方法or属性：export class NumberFormat<br>旧版本信息：|类名：NumberFormat;<br>方法or属性：export class NumberFormat<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: NumberOptions);<br>旧版本信息：|类名：NumberFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: NumberOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberFormat;<br>方法or属性：format(number: number): string;<br>旧版本信息：|类名：NumberFormat;<br>方法or属性：format(number: number): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：NumberFormat;<br>方法or属性：resolvedOptions(): NumberOptions;<br>旧版本信息：|类名：NumberFormat;<br>方法or属性：resolvedOptions(): NumberOptions;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：export interface CollatorOptions<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：export interface CollatorOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：usage?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：sensitivity?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>旧版本信息：|类名：CollatorOptions;<br>方法or属性：ignorePunctuation?: boolean;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Collator;<br>方法or属性：export class Collator<br>旧版本信息：|类名：Collator;<br>方法or属性：export class Collator<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Collator;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: CollatorOptions);<br>旧版本信息：|类名：Collator;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: CollatorOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Collator;<br>方法or属性：compare(first: string, second: string): number;<br>旧版本信息：|类名：Collator;<br>方法or属性：compare(first: string, second: string): number;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：Collator;<br>方法or属性：resolvedOptions(): CollatorOptions;<br>旧版本信息：|类名：Collator;<br>方法or属性：resolvedOptions(): CollatorOptions;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：export interface PluralRulesOptions<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：export interface PluralRulesOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>旧版本信息：|类名：PluralRulesOptions;<br>方法or属性：type?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRules;<br>方法or属性：export class PluralRules<br>旧版本信息：|类名：PluralRules;<br>方法or属性：export class PluralRules<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRules;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: PluralRulesOptions);<br>旧版本信息：|类名：PluralRules;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: PluralRulesOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：PluralRules;<br>方法or属性：select(n: number): string;<br>旧版本信息：|类名：PluralRules;<br>方法or属性：select(n: number): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：export interface RelativeTimeFormatInputOptions<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：export interface RelativeTimeFormatInputOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>旧版本信息：|类名：RelativeTimeFormatInputOptions;<br>方法or属性：numeric?: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：export interface RelativeTimeFormatResolvedOptions<br>旧版本信息：|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：export interface RelativeTimeFormatResolvedOptions<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：locale: string;<br>旧版本信息：|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：locale: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：style: string;<br>旧版本信息：|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：style: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：numeric: string;<br>旧版本信息：|类名：RelativeTimeFormatResolvedOptions;<br>方法or属性：numeric: string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：export class RelativeTimeFormat<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：export class RelativeTimeFormat<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions);<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions);<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：format(value: number, unit: string): string;<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：format(value: number, unit: string): string;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：formatToParts(value: number, unit: string): Array\<object>;<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：formatToParts(value: number, unit: string): Array\<object>;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：RelativeTimeFormat;<br>方法or属性：resolvedOptions(): RelativeTimeFormatResolvedOptions;<br>旧版本信息：|类名：RelativeTimeFormat;<br>方法or属性：resolvedOptions(): RelativeTimeFormatResolvedOptions;<br>新版本信息：crossplatform|@ohos.intl.d.ts|
|跨平台能力有变化|类名：resourceManager;<br>方法or属性：declare resourceManager<br>旧版本信息：|类名：resourceManager;<br>方法or属性：declare resourceManager<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：resourceManager;<br>方法or属性：export type RawFileDescriptor = _RawFileDescriptor;<br>旧版本信息：|类名：resourceManager;<br>方法or属性：export type RawFileDescriptor = _RawFileDescriptor;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：resourceManager;<br>方法or属性：export type Resource = _Resource;<br>旧版本信息：|类名：resourceManager;<br>方法or属性：export type Resource = _Resource;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Direction;<br>方法or属性：export enum Direction<br>旧版本信息：|类名：Direction;<br>方法or属性：export enum Direction<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Direction;<br>方法or属性：DIRECTION_VERTICAL = 0<br>旧版本信息：|类名：Direction;<br>方法or属性：DIRECTION_VERTICAL = 0<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Direction;<br>方法or属性：DIRECTION_HORIZONTAL = 1<br>旧版本信息：|类名：Direction;<br>方法or属性：DIRECTION_HORIZONTAL = 1<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：DeviceType;<br>方法or属性：export enum DeviceType<br>旧版本信息：|类名：DeviceType;<br>方法or属性：export enum DeviceType<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_PHONE = 0x00<br>旧版本信息：|类名：DeviceType;<br>方法or属性：DEVICE_TYPE_PHONE = 0x00<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：export enum ScreenDensity<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：export enum ScreenDensity<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_SDPI = 120<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_SDPI = 120<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_MDPI = 160<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_MDPI = 160<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_LDPI = 240<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_LDPI = 240<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_XLDPI = 320<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_XLDPI = 320<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_XXLDPI = 480<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_XXLDPI = 480<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ScreenDensity;<br>方法or属性：SCREEN_XXXLDPI = 640<br>旧版本信息：|类名：ScreenDensity;<br>方法or属性：SCREEN_XXXLDPI = 640<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：export class Configuration<br>旧版本信息：|类名：Configuration;<br>方法or属性：export class Configuration<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：direction: Direction;<br>旧版本信息：|类名：Configuration;<br>方法or属性：direction: Direction;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：Configuration;<br>方法or属性：locale: string;<br>旧版本信息：|类名：Configuration;<br>方法or属性：locale: string;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：DeviceCapability;<br>方法or属性：export class DeviceCapability<br>旧版本信息：|类名：DeviceCapability;<br>方法or属性：export class DeviceCapability<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：DeviceCapability;<br>方法or属性：screenDensity: ScreenDensity;<br>旧版本信息：|类名：DeviceCapability;<br>方法or属性：screenDensity: ScreenDensity;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：DeviceCapability;<br>方法or属性：deviceType: DeviceType;<br>旧版本信息：|类名：DeviceCapability;<br>方法or属性：deviceType: DeviceType;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：export interface ResourceManager<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：export interface ResourceManager<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resource: Resource): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringValue(resId: number): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayValue(resId: number): Promise\<Array\<string>>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContent(resId: number): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaContentBase64(resId: number): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getDeviceCapability(): Promise\<DeviceCapability>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getDeviceCapability(): Promise\<DeviceCapability>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getConfiguration(callback: _AsyncCallback\<Configuration>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getConfiguration(callback: _AsyncCallback\<Configuration>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getConfiguration(): Promise\<Configuration>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getConfiguration(): Promise\<Configuration>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringValue(resId: number, num: number): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringByName(resName: string): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string): Promise\<Array\<string>>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringArrayByName(resName: string): Promise\<Array\<string>>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaByName(resName: string): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getMediaBase64ByName(resName: string): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number): Promise\<string>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getPluralStringByName(resName: string, num: number): Promise\<string>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringSync(resId: number): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringSync(resId: number): string;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringSync(resource: Resource): string;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getStringByNameSync(resName: string): string;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getStringByNameSync(resName: string): string;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getBoolean(resId: number): boolean;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getBoolean(resId: number): boolean;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getBoolean(resource: Resource): boolean;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getBooleanByName(resName: string): boolean;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getBooleanByName(resName: string): boolean;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getNumber(resId: number): number;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getNumber(resId: number): number;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getNumber(resource: Resource): number;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getNumberByName(resName: string): number;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getNumberByName(resName: string): number;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：release();<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：release();<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string): Promise\<Uint8Array>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFileContent(path: string): Promise\<Uint8Array>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：getRawFd(path: string): Promise\<RawFileDescriptor>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：getRawFd(path: string): Promise\<RawFileDescriptor>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string, callback: _AsyncCallback\<void>): void;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string, callback: _AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
|跨平台能力有变化|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string): Promise\<void>;<br>旧版本信息：|类名：ResourceManager;<br>方法or属性：closeRawFd(path: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.resourceManager.d.ts|
