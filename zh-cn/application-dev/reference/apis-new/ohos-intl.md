# @ohos.intl    
本模块提供基础的应用国际化能力，包括时间日期格式化、数字格式化、排序等，相关接口在ECMA 402标准中定义。[I18N模块](js-apis-i18n.md)提供其他非ECMA 402定义的国际化接口，与本模块共同使用可提供完整地国际化支持能力。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import intl from '@ohos.intl'    
```  
    
## LocaleOptions    
表示区域初始化选项。从API9开始，LocaleOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| calendar | string | false | true | 日历参数，如："buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", "islamicc"。 |  
| calendar<sup>(9+)</sup> | string | false | false | 日历参数，如："buddhist", "chinese", "coptic", "dangi", "ethioaa", "ethiopic", "gregory", "hebrew", "indian", "islamic", "islamic-umalqura", "islamic-tbla", "islamic-civil", "islamic-rgsa", "iso8601", "japanese", "persian", "roc", "islamicc"。 |  
| collation | string | false | true | 排序参数，取值包括："big5han", "compat", "dict", "direct", "ducet", "emoji", "eor", "gb2312", "phonebk", "phonetic", "pinyin", "reformed", "search", "searchjl", "standard", "stroke", "trad", "unihan", "zhuyin"。 |  
| collation<sup>(9+)</sup> | string | false | false | 排序参数，取值包括："big5han", "compat", "dict", "direct", "ducet", "emoji", "eor", "gb2312", "phonebk", "phonetic", "pinyin", "reformed", "search", "searchjl", "standard", "stroke", "trad", "unihan", "zhuyin"。 |  
| hourCycle | string | false | true | 时制格式，取值包括："h11","h12","h23","h24"。 |  
| hourCycle<sup>(9+)</sup> | string | false | false | 时制格式，取值包括："h11","h12","h23","h24"。 |  
| numberingSystem | string | false | true | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。 |  
| numberingSystem<sup>(9+)</sup> | string | false | false | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。 |  
| numeric | boolean | false | true | 是否使用12小时制。默认值：false。 |  
| numeric<sup>(9+)</sup> | boolean | false | false | 是否使用12小时制。默认值：false。 |  
| caseFirst | string | false | true | 表示大写、小写的排序顺序，取值范围："upper","lower","false"。 |  
| caseFirst<sup>(9+)</sup> | string | false | false | 表示大写、小写的排序顺序，取值范围："upper","lower","false"。 |  
    
## Locale  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| language | string | false | true | 与区域设置相关的语言，如：zh。 |  
| script | string | false | true | 语言的书写方式，如：Hans。 |  
| region | string | false | true | 与区域设置相关的地区，如：CN。 |  
| baseName | string | false | true | Locale的基本核心信息（由语言脚本与地区组成），如：zh-Hans-CN。 |  
| caseFirst | string | false | true | 区域的整理规则是否考虑大小写，取值包括："upper","lower","false"。 |  
| calendar | string | false | true | 区域的日历信息，取值包括："buddhist","chinese","coptic","dangi","ethioaa","ethiopic","gregory","hebrew","indian","islamic","islamic-umalqura","islamic-tbla","islamic-civil","islamic-rgsa","iso8601","japanese","persian","roc","islamicc"。 |  
| collation | string | false | true | 区域的排序规则，取值包括："big5han","compat","dict","direct","ducet","eor","gb2312","phonebk","phonetic","pinyin","reformed","searchjl","stroke","trad","unihan","zhuyin"。 |  
| hourCycle | string | false | true | 区域的时制信息，取值包括："h12","h23","h11","h24"。 |  
| numberingSystem | string | false | true | 区域使用的数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。 |  
| numeric | boolean | false | true | 是否对数字字符具有特殊的排序规则处理。默认值：false。 |  
    
### toString    
获取区域对象的字符串表示。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 区域对象的字符串表示。 |  
    
 **示例代码：**   
```js    
// 创建 "en-GB" Locale对象  
let locale = new Intl.Locale("en-GB");  
let localeID = locale.toString(); // localeID = "en-GB"    
```    
  
    
### maximize    
最大化区域信息，若缺少脚本与地区信息，则补齐。  
 **调用形式：**     
- maximize(): Locale  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Locale | 最大化后的区域对象。 |  
    
 **示例代码：**   
```js    
// 创建 "zh" Locale对象  
let locale = new Intl.Locale("zh");  
// 补齐Locale对象的脚本和地区  
let maximizedLocale = locale.maximize();  
let localeID = maximizedLocale.toString(); // localeID = "zh-Hans-CN"  
  
// 创建 "en-US" Locale对象  
locale = new Intl.Locale("en-US");  
// 补齐Locale对象的脚本  
maximizedLocale = locale.maximize();  
localeID = maximizedLocale.toString(); // localeID = "en-Latn-US"    
```    
  
    
### minimize    
最小化区域信息，若包含脚本与地区信息，则去除。  
 **调用形式：**     
- minimize(): Locale  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Locale | 最小化后的区域对象。 |  
    
 **示例代码：**   
```js    
// 创建 "zh-Hans-CN" Locale对象  
let locale = new Intl.Locale("zh-Hans-CN");  
// 去除Locale对象的脚本和地区  
let minimizedLocale = locale.minimize();  
let localeID = minimizedLocale.toString(); // localeID = "zh"  
  
// 创建 "en-US" Locale对象  
locale = new Intl.Locale("en-US");  
// 去除Locale对象的地区  
minimizedLocale = locale.minimize();  
localeID = minimizedLocale.toString(); // localeID = "en"    
```    
  
    
## DateTimeOptions    
表示时间日期格式化选项。从API9开始，DateTimeOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | true | 区域参数，如：zh-Hans-CN。 |  
| locale<sup>(9+)</sup> | string | false | false | 区域参数，如：zh-Hans-CN。 |  
| dateStyle | string | false | true | 日期显示格式，取值包括："long","short","medium","full"。 |  
| dateStyle<sup>(9+)</sup> | string | false | false | 日期显示格式，取值包括："long","short","medium","full"。 |  
| timeStyle | string | false | true | 时间显示格式，取值包括："long","short","medium","full"。 |  
| timeStyle<sup>(9+)</sup> | string | false | false | 时间显示格式，取值包括："long","short","medium","full"。 |  
| hourCycle | string | false | true | 时制格式，取值包括："h11","h12","h23","h24"。 |  
| hourCycle<sup>(9+)</sup> | string | false | false | 时制格式，取值包括："h11","h12","h23","h24"。 |  
| timeZone | string | false | true | 使用的时区（合法的IANA时区ID）。 |  
| timeZone<sup>(9+)</sup> | string | false | false | 使用的时区（合法的IANA时区ID）。 |  
| numberingSystem | string | false | true | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。 |  
| numberingSystem<sup>(9+)</sup> | string | false | false | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。 |  
| hour12 | boolean | false | true | 是否使用12小时制。若hour12和hourCycle未设置且系统24小时开关打开时，hour12属性的默认值为false。 |  
| hour12<sup>(9+)</sup> | boolean | false | false | 是否使用12小时制。若hour12和hourCycle未设置且系统24小时开关打开时，hour12属性的默认值为false。 |  
| weekday | string | false | true | 工作日的显示格式，取值包括："long","short","narrow"。 |  
| weekday<sup>(9+)</sup> | string | false | false | 工作日的显示格式，取值包括："long","short","narrow"。 |  
| era | string | false | true | 时代的显示格式，取值包括："long","short","narrow"。 |  
| era<sup>(9+)</sup> | string | false | false | 时代的显示格式，取值包括："long","short","narrow"。 |  
| year | string | false | true | 年份的显示格式，取值包括："numeric","2-digit"。 |  
| year<sup>(9+)</sup> | string | false | false | 年份的显示格式，取值包括："numeric","2-digit"。 |  
| month | string | false | true | 月份的显示格式，取值包括："numeric","2-digit","long","short","narrow"。 |  
| month<sup>(9+)</sup> | string | false | false | 月份的显示格式，取值包括："numeric","2-digit","long","short","narrow"。 |  
| day | string | false | true | 日期的显示格式，取值包括："numeric","2-digit"。 |  
| day<sup>(9+)</sup> | string | false | false | 日期的显示格式，取值包括："numeric","2-digit"。 |  
| hour | string | false | true | 小时的显示格式，取值包括："numeric","2-digit"。 |  
| hour<sup>(9+)</sup> | string | false | false | 小时的显示格式，取值包括："numeric","2-digit"。 |  
| minute | string | false | true | 分钟的显示格式，取值包括："numeric","2-digit"。 |  
| minute<sup>(9+)</sup> | string | false | false | 分钟的显示格式，取值包括："numeric","2-digit"。 |  
| second | string | false | true | 秒钟的显示格式，取值包括："numeric","2-digit"。 |  
| second<sup>(9+)</sup> | string | false | false | 秒钟的显示格式，取值包括："numeric","2-digit"。 |  
| timeZoneName | string | false | true | 时区名称的本地化表示。 |  
| timeZoneName<sup>(9+)</sup> | string | false | false | 时区名称的本地化表示。 |  
| dayPeriod | string | false | true | 时段的显示格式，取值包括："long","short","narrow"。 |  
| dayPeriod<sup>(9+)</sup> | string | false | false | 时段的显示格式，取值包括："long","short","narrow"。 |  
| localeMatcher | string | false | true | 要使用的区域匹配算法，取值包括："lookup","bestfit"。 |  
| localeMatcher<sup>(9+)</sup> | string | false | false | 要使用的区域匹配算法，取值包括："lookup","bestfit"。 |  
| formatMatcher | string | false | true | 要使用的格式匹配算法，取值包括："basic","bestfit"。 |  
| formatMatcher<sup>(9+)</sup> | string | false | false | 要使用的格式匹配算法，取值包括："basic","bestfit"。 |  
    
## DateTimeFormat    
创建时间日期格式化对象。  
 **系统能力:**  SystemCapability.Global.I18n    
### format    
格式化时间日期字符串。  
 **调用形式：**     
- format(date: Date): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date | Date | true | 时间日期对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 格式化后的时间日期字符串 |  
    
 **示例代码：**   
```js    
let date = new Date(2021, 11, 17, 3, 24, 0);  
// 使用 en-GB locale创建DateTimeFormat对象  
let datefmt = new Intl.DateTimeFormat("en-GB");  
let formattedDate = datefmt.format(date); // formattedDate "17/12/2021"  
  
// 使用 en-GB locale创建DateTimeFormat对象，dateStyle设置为full，timeStyle设置为medium  
datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });  
formattedDate = datefmt.format(date); // formattedDate "Friday, 17 December 2021 at 03:24:00"    
```    
  
    
### formatRange    
格式化时间日期段字符串。  
 **调用形式：**     
- formatRange(startDate: Date, endDate: Date): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| startDate | Date | true | 起始的时间日期。 |  
| endDate | Date | true | 结束的时间日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 格式化后的时间日期段字符串。 |  
    
 **示例代码：**   
```js    
let startDate = new Date(2021, 11, 17, 3, 24, 0);  
let endDate = new Date(2021, 11, 18, 3, 24, 0);  
// 使用 en-GB locale创建DateTimeFormat对象  
let datefmt = new Intl.DateTimeFormat("en-GB");  
let formattedDateRange = datefmt.formatRange(startDate, endDate); // formattedDateRange = "17/12/2021-18/12/2021"    
```    
  
    
### resolvedOptions    
获取DateTimeFormat对象的格式化选项。  
 **调用形式：**     
- resolvedOptions(): DateTimeOptions  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DateTimeOptions | DateTimeFormat对象的格式化选项。 |  
    
 **示例代码：**   
```js    
let datefmt = new Intl.DateTimeFormat("en-GB", { dateStyle: 'full', timeStyle: 'medium' });  
// 返回DateTimeFormat对象的配置项  
let options = datefmt.resolvedOptions();  
let dateStyle = options.dateStyle; // dateStyle = "full"  
let timeStyle = options.timeStyle; // timeStyle = "medium"    
```    
  
    
## NumberOptions    
表示设备支持的能力。从API9开始，NumberOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | true | 区域参数，如："zh-Hans-CN"。locale属性默认值为系统Locale。 |  
| locale<sup>(9+)</sup> | string | false | false | 区域参数，如："zh-Hans-CN"。locale属性默认值为系统Locale。 |  
| currency | string | false | true | 货币单位，如："EUR"，"CNY"，"USD"等。 |  
| currency<sup>(9+)</sup> | string | false | false | 货币单位，如："EUR"，"CNY"，"USD"等。 |  
| currencySign | string | false | true | 货币单位的符号显示，取值包括："standard"，"accounting"。currencySign属性默认值为standard。 |  
| currencySign<sup>(9+)</sup> | string | false | false | 货币单位的符号显示，取值包括："standard"，"accounting"。currencySign属性默认值为standard。 |  
| currencyDisplay | string | false | true | 货币的显示方式，取值包括："symbol","narrowSymbol","code","name"。currencyDisplay属性默认值为symbol。 |  
| currencyDisplay<sup>(9+)</sup> | string | false | false | 货币的显示方式，取值包括："symbol","narrowSymbol","code","name"。currencyDisplay属性默认值为symbol。 |  
| unit | string | false | true | 单位名称，如："meter"，"inch"，“hectare”等。 |  
| unit<sup>(9+)</sup> | string | false | false | 单位名称，如："meter"，"inch"，“hectare”等。 |  
| unitDisplay | string | false | true | 单位的显示格式，取值包括："long","short","narrow"。unitDisplay属性默认值为short。 |  
| unitDisplay<sup>(9+)</sup> | string | false | false | 单位的显示格式，取值包括："long","short","narrow"。unitDisplay属性默认值为short。 |  
| unitUsage<sup>(8+)</sup> | string | false | true | 单位的使用场景，取值包括："default","area-land-agricult","area-land-commercl","area-land-residntl","length-person","length-person-small","length-rainfall","length-road","length-road-small","length-snowfall","length-vehicle","length-visiblty","length-visiblty-small","length-person-informal","length-person-small-informal","length-road-informal","speed-road-travel","speed-wind","temperature-person","temperature-weather","volume-vehicle-fuel"。unitUsage属性默认值为default。 |  
| unitUsage<sup>(9+)</sup> | string | false | false | 单位的使用场景，取值包括："default","area-land-agricult","area-land-commercl","area-land-residntl","length-person","length-person-small","length-rainfall","length-road","length-road-small","length-snowfall","length-vehicle","length-visiblty","length-visiblty-small","length-person-informal","length-person-small-informal","length-road-informal","speed-road-travel","speed-wind","temperature-person","temperature-weather","volume-vehicle-fuel"。unitUsage属性默认值为default。 |  
| signDisplay | string | false | true | 数字符号的显示格式，取值包括："auto","never","always","expectZero"。signDisplay属性默认值为auto。 |  
| signDisplay<sup>(9+)</sup> | string | false | false | 数字符号的显示格式，取值包括："auto","never","always","expectZero"。signDisplay属性默认值为auto。 |  
| compactDisplay | string | false | true | 紧凑型的显示格式，取值包括："long","short"。compactDisplay属性默认值为short。 |  
| compactDisplay<sup>(9+)</sup> | string | false | false | 紧凑型的显示格式，取值包括："long","short"。compactDisplay属性默认值为short。 |  
| notation | string | false | true | 数字的格式化规格，取值包括："standard","scientific","engineering","compact"。notation属性默认值为standard。 |  
| notation<sup>(9+)</sup> | string | false | false | 数字的格式化规格，取值包括："standard","scientific","engineering","compact"。notation属性默认值为standard。 |  
| localeMatcher | string | false | true | 要使用的区域匹配算法，取值包括："lookup","bestfit"。localeMatcher属性默认值为best fit。 |  
| localeMatcher<sup>(9+)</sup> | string | false | false | 要使用的区域匹配算法，取值包括："lookup","bestfit"。localeMatcher属性默认值为best fit。 |  
| style | string | false | true | 数字的显示格式，取值包括："decimal","currency","percent","unit"。style属性默认值为decimal。 |  
| style<sup>(9+)</sup> | string | false | false | 数字的显示格式，取值包括："decimal","currency","percent","unit"。style属性默认值为decimal。 |  
| numberingSystem | string | false | true | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。numberingSystem属性默认值为locale的默认数字系统。 |  
| numberingSystem<sup>(9+)</sup> | string | false | false | 数字系统，取值包括："adlm","ahom","arab","arabext","bali","beng","bhks","brah","cakm","cham","deva","diak","fullwide","gong","gonm","gujr","guru","hanidec","hmng","hmnp","java","kali","khmr","knda","lana","lanatham","laoo","latn","lepc","limb","mathbold","mathdbl","mathmono","mathsanb","mathsans","mlym","modi","mong","mroo","mtei","mymr","mymrshan","mymrtlng","newa","nkoo","olck","orya","osma","rohg","saur","segment","shrd","sind","sinh","sora","sund","takr","talu","tamldec","telu","thai","tibt","tirh","vaii","wara","wcho"。numberingSystem属性默认值为locale的默认数字系统。 |  
| useGrouping | boolean | false | true | 是否分组显示。useGrouping属性默认值为auto。 |  
| useGrouping<sup>(9+)</sup> | boolean | false | false | 是否分组显示。useGrouping属性默认值为auto。 |  
| minimumIntegerDigits | number | false | true | 表示要使用的最小整数位数，取值范围：1~21。minimumIntegerDigits属性默认值为1。 |  
| minimumIntegerDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最小整数位数，取值范围：1~21。minimumIntegerDigits属性默认值为1。 |  
| minimumFractionDigits | number | false | true | 表示要使用的最小分数位数，取值范围：0~20。minimumFractionDigits属性默认值为0。 |  
| minimumFractionDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最小分数位数，取值范围：0~20。minimumFractionDigits属性默认值为0。 |  
| maximumFractionDigits | number | false | true | 表示要使用的最大分数位数，取值范围：1~21。maximumFractionDigits属性默认值为3。 |  
| maximumFractionDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最大分数位数，取值范围：1~21。maximumFractionDigits属性默认值为3。 |  
| minimumSignificantDigits | number | false | true | 表示要使用的最低有效位数，取值范围：1~21。minimumSignificantDigits属性默认值为1。 |  
| minimumSignificantDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最低有效位数，取值范围：1~21。minimumSignificantDigits属性默认值为1。 |  
| maximumSignificantDigits | number | false | true | 表示要使用的最大有效位数，取值范围：1~21。maximumSignificantDigits属性默认值为21。 |  
| maximumSignificantDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最大有效位数，取值范围：1~21。maximumSignificantDigits属性默认值为21。 |  
    
## NumberFormat    
创建数字格式化对象。  
 **系统能力:**  SystemCapability.Global.I18n    
### format    
格式化数字字符串。  
 **调用形式：**     
- format(number: number): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| number | number | true | 数字对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 格式化后的数字字符串 |  
    
 **示例代码：**   
```js    
// 使用 ["en-GB", "zh"] locale列表创建NumberFormat对象，因为en-GB为合法LocaleID，因此使用en-GB创建NumberFormat对象  
let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});  
let formattedNumber = numfmt.format(1223); // formattedNumber = 1.223E3    
```    
  
    
### resolvedOptions    
获取NumberFormat 对象的格式化选项。  
 **调用形式：**     
- resolvedOptions(): NumberOptions  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NumberOptions | NumberFormat对象的格式化选项。 |  
    
 **示例代码：**   
```js    
let numfmt = new Intl.NumberFormat(["en-GB", "zh"], {style:'decimal', notation:"scientific"});  
// 获取NumberFormat对象配置项  
let options = numfmt.resolvedOptions();  
let style = options.style; // style = decimal  
let notation = options.notation; // notation = scientific    
```    
  
    
## CollatorOptions<sup>(8+)</sup>    
表示Collator可设置的属性。从API9中，CollatorOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| localeMatcher<sup>(8+)</sup> | string | false | true | locale匹配算法，取值范围："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| localeMatcher<sup>(9+)</sup> | string | false | false | locale匹配算法，取值范围："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| usage<sup>(8+)</sup> | string | false | true | 比较的用途，取值范围："sort","search"。usage属性默认值为sort。 |  
| usage<sup>(9+)</sup> | string | false | false | 比较的用途，取值范围："sort","search"。usage属性默认值为sort。 |  
| sensitivity<sup>(8+)</sup> | string | false | true | 表示字符串中的哪些差异会导致非零结果值，取值范围："base","accent","case","letiant"。sensitivity属性默认值为variant。 |  
| sensitivity<sup>(9+)</sup> | string | false | false | 表示字符串中的哪些差异会导致非零结果值，取值范围："base","accent","case","letiant"。sensitivity属性默认值为variant。 |  
| ignorePunctuation<sup>(8+)</sup> | boolean | false | true | 表示是否忽略标点符号，取值范围：true,false。ignorePunctuation属性默认值为false。 |  
| ignorePunctuation<sup>(9+)</sup> | boolean | false | false | 表示是否忽略标点符号，取值范围：true,false。ignorePunctuation属性默认值为false。 |  
| collation<sup>(8+)</sup> | string | false | true | 排序规则，取值范围："big5han","compat","dict","direct","ducet","eor","gb2312","phonebk","phonetic","pinyin","reformed","searchjl","stroke","trad","unihan","zhuyin"。collation属性默认值为default。 |  
| collation<sup>(9+)</sup> | string | false | false | 排序规则，取值范围："big5han","compat","dict","direct","ducet","eor","gb2312","phonebk","phonetic","pinyin","reformed","searchjl","stroke","trad","unihan","zhuyin"。collation属性默认值为default。 |  
| numeric<sup>(8+)</sup> | boolean | false | true | 是否使用数字排序，取值范围：true,false。numeric属性默认值为false。 |  
| numeric<sup>(9+)</sup> | boolean | false | false | 是否使用数字排序，取值范围：true,false。numeric属性默认值为false。 |  
| caseFirst<sup>(8+)</sup> | string | false | true | 表示大写、小写的排序顺序，取值范围："upper","lower","false"。caseFirst属性默认值为false |  
| caseFirst<sup>(9+)</sup> | string | false | false | 表示大写、小写的排序顺序，取值范围："upper","lower","false"。caseFirst属性默认值为false |  
    
## Collator<sup>(8+)</sup>    
创建排序对象。  
 **系统能力:**  SystemCapability.Global.I18n    
### compare<sup>(8+)</sup>    
依据Collator的排序策略对两个字符串进行比较。  
 **调用形式：**     
- compare(first: string, second: string): number  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| first | string | true | 进行比较第一个字符串。 |  
| second | string | true | 进行比较的第二个字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 比较结果。当number为负数，表示first排序在second之前；当number为0，表示first与second排序相同；当number为正数，表示first排序在second之后。 |  
    
 **示例代码：**   
```js    
// 使用en-GB locale创建Collator对象  
let collator = new Intl.Collator("en-GB");  
// 比较 "first" 和 "second" 的先后顺序  
let compareResult = collator.compare("first", "second"); // compareResult = -1    
```    
  
    
### resolvedOptions<sup>(8+)</sup>    
返回Collator对象的属性。  
 **调用形式：**     
- resolvedOptions(): CollatorOptions  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CollatorOptions | 返回的Collator对象的属性。 |  
    
 **示例代码：**   
```js    
let collator = new Intl.Collator("zh-Hans", { usage: 'sort', ignorePunctuation: true });  
// 获取Collator对象的配置项  
let options = collator.resolvedOptions();  
let usage = options.usage; // usage = "sort"  
let ignorePunctuation = options.ignorePunctuation; // ignorePunctuation = true    
```    
  
    
## PluralRulesOptions<sup>(8+)</sup>    
表示PluralRules对象可设置的属性。从API9开始，PluralRulesOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| localeMatcher<sup>(8+)</sup> | string | false | true | locale匹配算法，取值包括："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| localeMatcher<sup>(9+)</sup> | string | false | false | locale匹配算法，取值包括："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| type<sup>(8+)</sup> | string | false | true | 排序的类型，取值包括："cardinal","ordinal"。type属性默认值为cardinal。 |  
| type<sup>(9+)</sup> | string | false | false | 排序的类型，取值包括："cardinal","ordinal"。type属性默认值为cardinal。 |  
| minimumIntegerDigits<sup>(8+)</sup> | number | false | true | 表示要使用的最小整数位数，取值范围：1~21。minimumIntegerDigits属性默认值为1。 |  
| minimumIntegerDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最小整数位数，取值范围：1~21。minimumIntegerDigits属性默认值为1。 |  
| minimumFractionDigits<sup>(8+)</sup> | number | false | true | 表示要使用的最小分数位数，取值范围：0~20。minimumFractionDigits属性默认值为0。 |  
| minimumFractionDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最小分数位数，取值范围：0~20。minimumFractionDigits属性默认值为0。 |  
| maximumFractionDigits<sup>(8+)</sup> | number | false | true | 表示要使用的最大分数位数，取值范围：1~21。maximumFractionDigits属性默认值为3。 |  
| maximumFractionDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最大分数位数，取值范围：1~21。maximumFractionDigits属性默认值为3。 |  
| minimumSignificantDigits<sup>(8+)</sup> | number | false | true | 表示要使用的最低有效位数，取值范围：1~21。minimumSignificantDigits属性默认值为1。 |  
| minimumSignificantDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最低有效位数，取值范围：1~21。minimumSignificantDigits属性默认值为1。 |  
| maximumSignificantDigits<sup>(8+)</sup> | number | false | true | 表示要使用的最大有效位数，取值范围：1~21。maximumSignificantDigits属性默认值为21。 |  
| maximumSignificantDigits<sup>(9+)</sup> | number | false | false | 表示要使用的最大有效位数，取值范围：1~21。maximumSignificantDigits属性默认值为21。 |  
    
## PluralRules<sup>(8+)</sup>    
创建单复数对象来计算数字的单复数类别。  
 **系统能力:**  SystemCapability.Global.I18n    
### select<sup>(8+)</sup>    
返回一个字符串表示该数字的单复数类别。  
 **调用形式：**     
- select(n: number): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| n | number | true | 待获取单复数类别的数字。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 单复数类别，取值包括："zero"，"one"，"two","few","many","others"。 |  
    
 **示例代码：**   
```js    
// 使用 zh-Hans locale创建PluralRules对象  
let zhPluralRules = new Intl.PluralRules("zh-Hans");  
// 计算 zh-Hans locale中数字1对应的单复数类别  
let plural = zhPluralRules.select(1); // plural = other  
  
// 使用 en-US locale创建PluralRules对象  
let enPluralRules = new Intl.PluralRules("en-US");  
// 计算 en-US locale中数字1对应的单复数类别  
plural = enPluralRules.select(1); // plural = one    
```    
  
    
## RelativeTimeFormatInputOptions<sup>(8+)</sup>    
表示RelativeTimeFormat对象可设置的属性。从API9开始，RelativeTimeFormatInputOptions中的属性改为可选。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| localeMatcher<sup>(8+)</sup> | string | false | true | locale匹配算法，取值包括："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| localeMatcher<sup>(9+)</sup> | string | false | false | locale匹配算法，取值包括："bestfit","lookup"。localeMatcher属性默认值为best fit。 |  
| numeric<sup>(8+)</sup> | string | false | true | 输出消息的格式，取值包括："always","auto"。numeric属性默认值为always。 |  
| numeric<sup>(9+)</sup> | string | false | false | 输出消息的格式，取值包括："always","auto"。numeric属性默认值为always。 |  
| style<sup>(8+)</sup> | string | false | true | 国际化消息的长度，取值包括："long","short","narrow"。style属性默认值为long。 |  
| style<sup>(9+)</sup> | string | false | false | 国际化消息的长度，取值包括："long","short","narrow"。style属性默认值为long。 |  
    
## RelativeTimeFormatResolvedOptions<sup>(8+)</sup>    
表示RelativeTimeFormat对象可设置的属性。  
 **系统能力:**  SystemCapability.Global.I18n    
### 属性    
 **系统能力:**  SystemCapability.Global.I18n    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale<sup>(8+)</sup> | string | false | true | 包含区域设置信息的字符串，包括语言以及可选的脚本和区域。 |  
| style<sup>(8+)</sup> | string | false | true | 输出消息的格式，取值包括："always","auto"。 |  
| numeric<sup>(8+)</sup> | string | false | true | 国际化消息的长度，取值包括："long","short","narrow"。 |  
| numberingSystem<sup>(8+)</sup> | string | false | true | 使用的数字系统。 |  
    
## RelativeTimeFormat<sup>(8+)</sup>    
创建相对时间格式化对象。  
 **系统能力:**  SystemCapability.Global.I18n    
### format<sup>(8+)</sup>    
依据locale和格式化选项，对value和unit进行格式化。  
 **调用形式：**     
- format(value: number, unit: string): string  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 相对时间格式化的数值。 |  
| unit | string | true | 相对时间格式化的单位，取值包括："year","quarter","month","week","day","hour","minute","second"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 格式化后的相对时间。 |  
    
 **示例代码：**   
```js    
// 使用 zh-CN locale创建RelativeTimeFormat对象  
let relativetimefmt = new Intl.RelativeTimeFormat("zh-CN");  
// 计算 zh-CN locale中数字3，单位quarter的本地化表示  
let formatResult = relativetimefmt.format(3, "quarter"); // formatResult = "3个季度后"    
```    
  
    
### formatToParts<sup>(8+)</sup>    
返回一个对象数组，表示可用于自定义区域设置格式的相对时间格式。  
 **调用形式：**     
- formatToParts(value: number, unit: string): Array\<object>  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 相对时间格式化的数值。 |  
| unit | string | true | 相对时间格式化的单位，取值包括："year","quarter","month","week","day","hour","minute","second"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<object> | 返回可用于自定义区域设置格式的相对时间格式的对象数组。 |  
    
 **示例代码：**   
```js    
// 使用 en locale创建RelativeTimeFormat对象，numeric设置为auto  
let relativetimefmt = new Intl.RelativeTimeFormat("en", {"numeric": "auto"});  
let parts = relativetimefmt.formatToParts(10, "seconds"); // parts = [ {type: "literal", value: "in"}, {type: "integer", value: 10, unit: "second"}, {type: "literal", value: "seconds"} ]    
```    
  
    
### resolvedOptions<sup>(8+)</sup>    
获取RelativeTimeFormat对象的格式化选项。  
 **调用形式：**     
- resolvedOptions(): RelativeTimeFormatResolvedOptions  
  
 **系统能力:**  SystemCapability.Global.I18n    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RelativeTimeFormatResolvedOptions | RelativeTimeFormat对象的格式化选项。 |  
    
 **示例代码：**   
```js    
// 使用 en-GB locale创建RelativeTimeFormat对象  
let relativetimefmt= new Intl.RelativeTimeFormat("en-GB", { style: "short" });  
// 获取RelativeTimeFormat对象配置项  
let options = relativetimefmt.resolvedOptions();  
let style = options.style; // style = "short"    
```    
  
