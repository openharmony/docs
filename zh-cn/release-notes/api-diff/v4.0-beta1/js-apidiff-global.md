| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：TimeZone<br>方法or属性：static getTimezonesByLocation(longitude: number, latitude: number): Array\<TimeZone>;|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: NormalizerMode|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: NormalizerMode<br>方法 or 属性：NFC = 1|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: NormalizerMode<br>方法 or 属性：NFD = 2|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: NormalizerMode<br>方法 or 属性：NFKC = 3|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: NormalizerMode<br>方法 or 属性：NFKD = 4|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: Normalizer|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: Normalizer<br>方法 or 属性：static getInstance(mode: NormalizerMode): Normalizer;|@ohos.i18n.d.ts|
|新增|NA|模块名: ohos.i18n<br>类名: Normalizer<br>方法 or 属性：normalize(text: string): string;|@ohos.i18n.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getStringSync(resId: number, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getStringSync(resource: Resource, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getStringByNameSync(resName: string, ...args: Array\<string \| number>): string;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getDrawableDescriptor(resId: number, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getDrawableDescriptorByName(resName: string, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getDrawableDescriptor(resource: Resource, density?: number): DrawableDescriptor;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getRawFileList(path: string, callback: _AsyncCallback\<Array\<string>>): void;|@ohos.resourceManager.d.ts|
|新增|NA|类名：ResourceManager<br>方法or属性：getRawFileList(path: string): Promise\<Array\<string>>;|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：System<br>起始版本：9|类名：System<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>起始版本：9|类名：System<br>方法 or 属性：static getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>起始版本：9|类名：System<br>方法 or 属性：static getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static getSystemLanguage(): string;<br>起始版本：9|类名：System<br>方法 or 属性：static getSystemLanguage(): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static setSystemLanguage(language: string): void;<br>起始版本：N/A|类名：System<br>方法 or 属性：static setSystemLanguage(language: string): void;<br>起始版本：9|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static getSystemRegion(): string;<br>起始版本：9|类名：System<br>方法 or 属性：static getSystemRegion(): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static getSystemLocale(): string;<br>起始版本：9|类名：System<br>方法 or 属性：static getSystemLocale(): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：System<br>方法 or 属性：static is24HourClock(): boolean;<br>起始版本：9|类名：System<br>方法 or 属性：static is24HourClock(): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：I18NUtil<br>起始版本：9|类名：I18NUtil<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：I18NUtil<br>方法 or 属性：static getDateOrder(locale: string): string;<br>起始版本：9|类名：I18NUtil<br>方法 or 属性：static getDateOrder(locale: string): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：i18n<br>方法 or 属性：function getCalendar(locale: string, type?: string): Calendar;<br>起始版本：8|类名：i18n<br>方法 or 属性：function getCalendar(locale: string, type?: string): Calendar;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：setTime(date: Date): void;<br>起始版本：8|类名：Calendar<br>方法 or 属性：setTime(date: Date): void;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：setTime(time: number): void;<br>起始版本：8|类名：Calendar<br>方法 or 属性：setTime(time: number): void;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：setTimeZone(timezone: string): void;<br>起始版本：8|类名：Calendar<br>方法 or 属性：setTimeZone(timezone: string): void;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：getTimeZone(): string;<br>起始版本：8|类名：Calendar<br>方法 or 属性：getTimeZone(): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：getFirstDayOfWeek(): number;<br>起始版本：8|类名：Calendar<br>方法 or 属性：getFirstDayOfWeek(): number;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：setFirstDayOfWeek(value: number): void;<br>起始版本：8|类名：Calendar<br>方法 or 属性：setFirstDayOfWeek(value: number): void;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：getMinimalDaysInFirstWeek(): number;<br>起始版本：8|类名：Calendar<br>方法 or 属性：getMinimalDaysInFirstWeek(): number;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：setMinimalDaysInFirstWeek(value: number): void;<br>起始版本：8|类名：Calendar<br>方法 or 属性：setMinimalDaysInFirstWeek(value: number): void;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：get(field: string): number;<br>起始版本：8|类名：Calendar<br>方法 or 属性：get(field: string): number;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Calendar<br>方法 or 属性：isWeekend(date?: Date): boolean;<br>起始版本：8|类名：Calendar<br>方法 or 属性：isWeekend(date?: Date): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：i18n<br>方法 or 属性：function isRTL(locale: string): boolean;<br>起始版本：7|类名：i18n<br>方法 or 属性：function isRTL(locale: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>起始版本：9|类名：Unicode<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isDigit(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isDigit(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isSpaceChar(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isSpaceChar(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isWhitespace(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isWhitespace(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isRTL(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isRTL(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isIdeograph(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isIdeograph(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isLetter(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isLetter(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isLowerCase(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isLowerCase(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static isUpperCase(char: string): boolean;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static isUpperCase(char: string): boolean;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：Unicode<br>方法 or 属性：static getType(char: string): string;<br>起始版本：9|类名：Unicode<br>方法 or 属性：static getType(char: string): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：i18n<br>方法 or 属性：function getTimeZone(zoneID?: string): TimeZone;<br>起始版本：7|类名：i18n<br>方法 or 属性：function getTimeZone(zoneID?: string): TimeZone;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：TimeZone<br>起始版本：7|类名：TimeZone<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：TimeZone<br>方法 or 属性：getID(): string;<br>起始版本：7|类名：TimeZone<br>方法 or 属性：getID(): string;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：TimeZone<br>方法 or 属性：getRawOffset(): number;<br>起始版本：7|类名：TimeZone<br>方法 or 属性：getRawOffset(): number;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：TimeZone<br>方法 or 属性：getOffset(date?: number): number;<br>起始版本：7|类名：TimeZone<br>方法 or 属性：getOffset(date?: number): number;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：TimeZone<br>方法 or 属性：static getAvailableIDs(): Array\<string>;<br>起始版本：9|类名：TimeZone<br>方法 or 属性：static getAvailableIDs(): Array\<string>;<br>起始版本：10|@ohos.i18n.d.ts|
|起始版本有变化|类名：intl<br>起始版本：6|类名：intl<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：LocaleOptions<br>起始版本：6|类名：LocaleOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>起始版本：6|类名：Locale<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>方法 or 属性：constructor();<br>起始版本：8|类名：Locale<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>方法 or 属性：constructor(locale: string, options?: LocaleOptions);<br>起始版本：6|类名：Locale<br>方法 or 属性：constructor(locale: string, options?: LocaleOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>方法 or 属性：toString(): string;<br>起始版本：6|类名：Locale<br>方法 or 属性：toString(): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>方法 or 属性：maximize(): Locale;<br>起始版本：6|类名：Locale<br>方法 or 属性：maximize(): Locale;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Locale<br>方法 or 属性：minimize(): Locale;<br>起始版本：6|类名：Locale<br>方法 or 属性：minimize(): Locale;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeOptions<br>起始版本：6|类名：DateTimeOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>起始版本：6|类名：DateTimeFormat<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>方法 or 属性：constructor();<br>起始版本：8|类名：DateTimeFormat<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: DateTimeOptions);<br>起始版本：6|类名：DateTimeFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: DateTimeOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>方法 or 属性：format(date: Date): string;<br>起始版本：6|类名：DateTimeFormat<br>方法 or 属性：format(date: Date): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>方法 or 属性：formatRange(startDate: Date, endDate: Date): string;<br>起始版本：6|类名：DateTimeFormat<br>方法 or 属性：formatRange(startDate: Date, endDate: Date): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：DateTimeFormat<br>方法 or 属性：resolvedOptions(): DateTimeOptions;<br>起始版本：6|类名：DateTimeFormat<br>方法 or 属性：resolvedOptions(): DateTimeOptions;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberOptions<br>起始版本：6|类名：NumberOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberFormat<br>起始版本：6|类名：NumberFormat<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberFormat<br>方法 or 属性：constructor();<br>起始版本：8|类名：NumberFormat<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: NumberOptions);<br>起始版本：6|类名：NumberFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: NumberOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberFormat<br>方法 or 属性：format(number: number): string;<br>起始版本：6|类名：NumberFormat<br>方法 or 属性：format(number: number): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：NumberFormat<br>方法 or 属性：resolvedOptions(): NumberOptions;<br>起始版本：6|类名：NumberFormat<br>方法 or 属性：resolvedOptions(): NumberOptions;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：CollatorOptions<br>起始版本：8|类名：CollatorOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Collator<br>起始版本：8|类名：Collator<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Collator<br>方法 or 属性：constructor();<br>起始版本：8|类名：Collator<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Collator<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: CollatorOptions);<br>起始版本：8|类名：Collator<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: CollatorOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Collator<br>方法 or 属性：compare(first: string, second: string): number;<br>起始版本：8|类名：Collator<br>方法 or 属性：compare(first: string, second: string): number;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：Collator<br>方法 or 属性：resolvedOptions(): CollatorOptions;<br>起始版本：8|类名：Collator<br>方法 or 属性：resolvedOptions(): CollatorOptions;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：PluralRulesOptions<br>起始版本：8|类名：PluralRulesOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：PluralRules<br>起始版本：8|类名：PluralRules<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：PluralRules<br>方法 or 属性：constructor();<br>起始版本：8|类名：PluralRules<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：PluralRules<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: PluralRulesOptions);<br>起始版本：8|类名：PluralRules<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: PluralRulesOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：PluralRules<br>方法 or 属性：select(n: number): string;<br>起始版本：8|类名：PluralRules<br>方法 or 属性：select(n: number): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatInputOptions<br>起始版本：8|类名：RelativeTimeFormatInputOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatResolvedOptions<br>起始版本：8|类名：RelativeTimeFormatResolvedOptions<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：locale: string;<br>起始版本：8|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：locale: string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：style: string;<br>起始版本：8|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：style: string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：numeric: string;<br>起始版本：8|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：numeric: string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：numberingSystem: string;<br>起始版本：8|类名：RelativeTimeFormatResolvedOptions<br>方法 or 属性：numberingSystem: string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>起始版本：8|类名：RelativeTimeFormat<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>方法 or 属性：constructor();<br>起始版本：8|类名：RelativeTimeFormat<br>方法 or 属性：constructor();<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions);<br>起始版本：8|类名：RelativeTimeFormat<br>方法 or 属性：constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions);<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>方法 or 属性：format(value: number, unit: string): string;<br>起始版本：8|类名：RelativeTimeFormat<br>方法 or 属性：format(value: number, unit: string): string;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>方法 or 属性：formatToParts(value: number, unit: string): Array\<object>;<br>起始版本：8|类名：RelativeTimeFormat<br>方法 or 属性：formatToParts(value: number, unit: string): Array\<object>;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：RelativeTimeFormat<br>方法 or 属性：resolvedOptions(): RelativeTimeFormatResolvedOptions;<br>起始版本：8|类名：RelativeTimeFormat<br>方法 or 属性：resolvedOptions(): RelativeTimeFormatResolvedOptions;<br>起始版本：10|@ohos.intl.d.ts|
|起始版本有变化|类名：resourceManager<br>起始版本：6|类名：resourceManager<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：Direction<br>起始版本：6|类名：Direction<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：Direction<br>方法 or 属性：DIRECTION_VERTICAL = 0<br>起始版本：6|类名：Direction<br>方法 or 属性：DIRECTION_VERTICAL = 0<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：Direction<br>方法 or 属性：DIRECTION_HORIZONTAL = 1<br>起始版本：6|类名：Direction<br>方法 or 属性：DIRECTION_HORIZONTAL = 1<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>起始版本：6|类名：DeviceType<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_PHONE = 0x00<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_PHONE = 0x00<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_TABLET = 0x01<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_TABLET = 0x01<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_CAR = 0x02<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_CAR = 0x02<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_PC = 0x03<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_PC = 0x03<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_TV = 0x04<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_TV = 0x04<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_WEARABLE = 0x06<br>起始版本：6|类名：DeviceType<br>方法 or 属性：DEVICE_TYPE_WEARABLE = 0x06<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>起始版本：6|类名：ScreenDensity<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_SDPI = 120<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_SDPI = 120<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_MDPI = 160<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_MDPI = 160<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_LDPI = 240<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_LDPI = 240<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_XLDPI = 320<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_XLDPI = 320<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_XXLDPI = 480<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_XXLDPI = 480<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ScreenDensity<br>方法 or 属性：SCREEN_XXXLDPI = 640<br>起始版本：6|类名：ScreenDensity<br>方法 or 属性：SCREEN_XXXLDPI = 640<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：Configuration<br>起始版本：6|类名：Configuration<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：DeviceCapability<br>起始版本：6|类名：DeviceCapability<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>起始版本：6|类名：ResourceManager<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringValue(resource: Resource): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringValue(resource: Resource): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resource: Resource): Promise\<Array\<string>>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContent(resource: Resource): Promise\<Uint8Array>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resource: Resource): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void;<br>起始版本：6|类名：ResourceManager<br>方法 or 属性：getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getDeviceCapability(): Promise\<DeviceCapability>;<br>起始版本：6|类名：ResourceManager<br>方法 or 属性：getDeviceCapability(): Promise\<DeviceCapability>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getConfiguration(callback: _AsyncCallback\<Configuration>): void;<br>起始版本：6|类名：ResourceManager<br>方法 or 属性：getConfiguration(callback: _AsyncCallback\<Configuration>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getConfiguration(): Promise\<Configuration>;<br>起始版本：6|类名：ResourceManager<br>方法 or 属性：getConfiguration(): Promise\<Configuration>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resource: Resource, num: number): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringByName(resName: string, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringByName(resName: string, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringByName(resName: string): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringByName(resName: string): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayByName(resName: string): Promise\<Array\<string>>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayByName(resName: string): Promise\<Array\<string>>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaByName(resName: string): Promise\<Uint8Array>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaByName(resName: string): Promise\<Uint8Array>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaBase64ByName(resName: string): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaBase64ByName(resName: string): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringByName(resName: string, num: number): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringByName(resName: string, num: number): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringSync(resId: number): string;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringSync(resId: number): string;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringSync(resource: Resource): string;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringSync(resource: Resource): string;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringByNameSync(resName: string): string;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringByNameSync(resName: string): string;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getBoolean(resId: number): boolean;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getBoolean(resId: number): boolean;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getBoolean(resource: Resource): boolean;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getBoolean(resource: Resource): boolean;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getBooleanByName(resName: string): boolean;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getBooleanByName(resName: string): boolean;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getNumber(resId: number): number;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getNumber(resId: number): number;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getNumber(resource: Resource): number;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getNumber(resource: Resource): number;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getNumberByName(resName: string): number;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getNumberByName(resName: string): number;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：release();<br>起始版本：7|类名：ResourceManager<br>方法 or 属性：release();<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringValue(resId: number, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringValue(resId: number, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringValue(resId: number): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringValue(resId: number): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resId: number): Promise\<Array\<string>>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getStringArrayValue(resId: number): Promise\<Array\<string>>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resId: number, num: number): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getPluralStringValue(resId: number, num: number): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContent(resId: number): Promise\<Uint8Array>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContent(resId: number): Promise\<Uint8Array>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resId: number): Promise\<string>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getMediaContentBase64(resId: number): Promise\<string>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getRawFileContent(path: string): Promise\<Uint8Array>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getRawFileContent(path: string): Promise\<Uint8Array>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：getRawFd(path: string): Promise\<RawFileDescriptor>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：getRawFd(path: string): Promise\<RawFileDescriptor>;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：closeRawFd(path: string, callback: _AsyncCallback\<void>): void;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：closeRawFd(path: string, callback: _AsyncCallback\<void>): void;<br>起始版本：10|@ohos.resourceManager.d.ts|
|起始版本有变化|类名：ResourceManager<br>方法 or 属性：closeRawFd(path: string): Promise\<void>;<br>起始版本：9|类名：ResourceManager<br>方法 or 属性：closeRawFd(path: string): Promise\<void>;<br>起始版本：10|@ohos.resourceManager.d.ts|
