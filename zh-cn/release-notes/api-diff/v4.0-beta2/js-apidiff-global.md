| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
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
