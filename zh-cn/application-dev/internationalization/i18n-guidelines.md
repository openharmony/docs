# I18n开发指导

本模块提供系统相关的或者增强的国际化能力，包括区域管理、电话号码处理、日历等，相关接口为ECMA 402标准中未定义的补充接口。更多接口和使用方式请见[I18N](../reference/apis/js-apis-i18n.md)。

[Intl](intl-guidelines.md)模块提供了ECMA 402标准定义的基础国际化接口，与本模块共同使用可提供完整地国际化支持能力。

## 获取和设置系统国际化相关信息

调用接口访问和设置系统语言、偏好语言、地区、24小时制、本地数字开关等国际化信息。

### 接口说明

| 类名        | 接口名称                                     | 描述                    |
| --------- | ---------------------------------------- | --------------------- |
| System | getDisplayCountry(country:string,locale:string,sentenceCase?:boolean):string<sup>9+</sup> | 获取国家的本地化表示。           |
| System | getDisplayLanguage(language:string,locale:string,sentenceCase?:boolean):string<sup>9+</sup> | 获取语言的本地化表示。           |
| System | getSystemLanguages():Array<string><sup>9+</sup>               | 获取系统语言列表。               |
| System | getSystemCountries(language: string):Array<string><sup>9+</sup>               | 获取针对输入语言系统支持的国家或地区列表。               |
| System | isSuggested(language: string, region?: string): boolean<sup>9+</sup>               | 判断当前语言和地区是否匹配               |
| System | getSystemLanguage():string<sup>9+</sup>               | 获取系统语言。               |
| System | setSystemLanguage(language: string)<sup>9+</sup>               | 设置系统语言。               |
| System | getSystemRegion():string<sup>9+</sup>                 | 获取系统地区。               |
| System | setSystemRegion(region: string)<sup>9+</sup>                 | 设置系统地区。               |
| System | getSystemLocale():string<sup>9+</sup>                 | 获取系统Locale。           |
| System | setSystemLocale(locale: string)<sup>9+</sup>                 | 设置系统Locale。           |
| System | is24HourClock():boolean<sup>9+</sup>     | 判断系统时间是否为24小时制。    |
| System | set24HourClock():boolean<sup>9+</sup>     | 修改系统时间的24小时制设置。    |
| System | addPreferredLanguage(language: string, index?: number)<sup>9+</sup>     | 在系统偏好语言列表的指定位置添加偏好语言。    |
| System | removePreferredLanguage(index: number)<sup>9+</sup>     | 删除系统偏好语言列表中指定位置的偏好语言。    |
| System | getPreferredLanguageList()<sup>9+</sup>     | 获取系统偏好语言列表。    |
| System | getFirstPreferredLanguage()<sup>9+</sup>     | 获取系统偏好语言列表中的第一个偏好语言。    |
| System | getAppPreferredLanguage()<sup>9+</sup>     | 获取应用偏好语言。    |
| System | setUsingLocalDigit(flag: boolean)<sup>9+</sup>     | 设置是否打开本地数字开关。    |
| System | getUsingLocalDigit()<sup>9+</sup>     | 获取系统当前是否打开本地数字开关。    |
|  | isRTL(locale:string):boolean<sup>9+</sup> | locale对应的语言是否为从右到左语言。 |

### 开发步骤
1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 获取和设置系统语言。
   
   调用setSystemLanguage接口设置系统语言（该接口为系统接口，只有具有UPDATE_CONFIGURATION权限的系统应用可以调用）。
   调用getSystemLanguage接口获取系统语言。
   
   ```js
   try {
      I18n.System.setSystemLanguage("en"); // 将系统语言设置为 "en"
      let language = I18n.System.getSystemLanguage(); // language = "en"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

3. 获取和设置系统区域。
   
   调用setSystemRegion接口设置系统国家（该接口为系统接口，只有具有UPDATE_CONFIGURATION权限的系统应用可以调用）。
   调用getSystemRegion接口获取系统国家。

   ```js
   try {
      I18n.System.setSystemRegion("CN"); // 将系统国家设置为 "CN"
      let region = I18n.System.getSystemRegion(); // region = "CN"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

4. 获取和设置系统Locale。

   调用setSystemLocale接口设置系统Locale（该接口为系统接口，只有具有UPDATE_CONFIGURATION权限的系统应用可以调用）。Locale的定义请见[Locale](../internationalization/intl-guidelines.md#设置区域信息)
   调用getSystemLocale接口获取系统Locale。

   ```js
   try {
      I18n.System.setSystemLocale("zh-Hans-CN"); // 将系统Locale设置为 "zh-Hans-CN"
      let locale = I18n.System.getSystemLocale(); // locale = "zh-Hans-CN"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

5. 判断Locale的语言是否为从右到左语言。

   调用isRTL接口获取Locale的语言是否为从右到左语言。

   ```js
   try {
      let rtl = I18n.isRTL("zh-CN"); // rtl = false
      rtl = I18n.isRTL("ar"); // rtl = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

6. 获取和设置系统24小时制设置。

   调用set24HourClock接口打开系统24小时制设置。
   调用is24HourClock接口来判断当前是否打开系统24小时制设置。

   ```js
   try {
      I18n.System.set24HourClock(true);
      let hourClock = I18n.System.is24HourClock(); // hourClock = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

7. 获取语言的本地化表示。

   调用getDisplayLanguage接口获取某一语言的本地化表示。其中，language表示待本地化显示的语言，locale表示本地化的Locale，sentenceCase结果是否需要首字母大写。

   ```js
   try {
      let language = "en";
      let locale = "zh-CN";
      let sentenceCase = false;
      let localizedLanguage = I18n.System.getDisplayLanguage(language, locale, sentenceCase); // localizedLanguage = "英语"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

8. 获取国家的本地化表示。

   调用getDisplayCountry接口获取某一国家的本地化表示。其中，country表示待本地化显示的国家，locale表示本地化的Locale，sentenceCase结果是否需要首字母大写。

   ```js
   try {
      let country = "US";
      let locale = "zh-CN";
      let sentenceCase = false;
      let localizedCountry = I18n.System.getDisplayCountry(country, locale, sentenceCase); // localizedCountry = "美国"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

9. 获取系统语言列表和某个语言系统支持的国家列表。

   调用getSystemLanguages接口获取系统支持的语言列表。
   调用getSystemCountries接口获取某一语言系统支持的地区列表。
   ```js
   
   try {
      let languageList = I18n.System.getSystemLanguages();  // languageList = ["en-Latn-US", "zh-Hans"]
      let countryList = I18n.System.getSystemCountries("zh"); // countryList = ["ZW", "YT", ..., "CN", "DE"], 共240个国家和地区
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

10. 判断语言和国家是否匹配。

   调用isSuggested接口判断语言和地区是否匹配。
   
   ```js
   try {
      let isSuggest = I18n.System.isSuggested("zh", "CN"); // isSuggest = true
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

11. 获取与设置偏好语言。

   调用addPreferredLanguage接口在当前系统偏好语言列表中插入偏好语言。
   调用removePreferredLanguage接口移除系统偏好语言列表中的某个语言。（addPreferredLanguage接口和removePreferredLanguage接口为系统接口，只有具有UPDATE_CONFIGURATION权限的系统应用可以调用。）
   调用getPreferredLanguageList接口获取系统当前偏好语言列表。
   调用getFirstPreferredLanguage接口获取系统偏好语言列表中的第一个偏好语言。
   调用getAppPreferredLanguageList接口获取应用偏好语言，应用偏好语言为系统偏好语言列表中第一个与应用的资源匹配的语言。
   
   ```js
   try {
      I18n.System.addPreferredLanguage("en-GB", 0); // 将"en-GB"设置为系统偏好语言列表的第一个语言
      let list = I18n.System.getPreferredLanguageList(); // 获取当前系统偏好语言列表 list = ["en-GB", ...]
      I18n.System.removePreferredLanguage(list.length - 1); // 移除当前系统偏好语言列表中的最后一个偏好语言
      let firstPreferredLanguage = I18n.System.getFirstPreferredLanguage(); // firstPreferredLanguage = "en-GB"
      let appPreferredLanguage = I18n.System.getAppPreferredLanguage(); // 当应用中包含 "en-GB"资源时，应用偏好语言为"en-GB"
   } catch(error) {
      console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
   }
   ```

12. 获取和设置系统本地化数字开关。

   调用setUsingLocalDigit接口打开本地化数字开关。（此接口为系统接口，只有具有UPDATE_CONFIGURATION权限的系统应用可以调用。）
   调用getUsingLocalDigit接口访问本地化数字开关状态。
   当前只有 "ar", "as", "bn", "fa", "mr", "my", "ne", "ur" 8个语言支持打开本地数字开关。

```js
try {
   I18n.System.setUsingLocalDigit(true); // 打开本地化数字开关
   let status = I18n.System.getUsingLocalDigit(); // status = true
} catch(error) {
   console.error(`call i18n.System interface failed, error code: ${error.code}, message: ${error.message}`)
}
```

## 获取日历信息

调用日历[Calendar](../reference/apis/js-apis-i18n.md#calendar8)相关接口来获取日历的相关信息，例如获取日历的本地化显示、一周起始日、一年中第一周的最小天数等。

### 接口说明

| 类名        | 接口名称                                     | 描述                    |
| --------- | ---------------------------------------- | --------------------- |
|  | getCalendar(locale:string,type?:string):Calendar<sup>8+</sup> | 获取指定locale和type的日历对象。 |
| Calendar | setTime(date:Date): void<sup>8+</sup>    | 设置日历对象内部的时间日期。        |
| Calendar | setTime(time:number): void<sup>8+</sup>  | 设置日历对象内部的时间日期。        |
| Calendar | set(year:number,month:number,date:number,hour?:number,minute?:number,second?:number): void<sup>8+</sup> | 设置日历对象的年、月、日、时、分、秒。   |
| Calendar | setTimeZone(timezone:string): void<sup>8+</sup> | 设置日历对象的时区。            |
| Calendar | getTimeZone():string<sup>8+</sup>        | 获取日历对象的时区。            |
| Calendar | getFirstDayOfWeek():number<sup>8+</sup>  | 获取日历对象的一周起始日。         |
| Calendar | setFirstDayOfWeek(value:number): void<sup>8+</sup> | 设置日历对象的一周起始日。         |
| Calendar | getMinimalDaysInFirstWeek():number<sup>8+</sup> | 获取一年中第一周的最小天数。        |
| Calendar | setMinimalDaysInFirstWeek(value:number): void<sup>8+</sup> | 设置一年中第一周的最小天数。        |
| Calendar | getDisplayName(locale:string):string<sup>8+</sup> | 获取日历对象的本地化表示。         |
| Calendar | isWeekend(date?:Date):boolean<sup>8+</sup> | 判断给定的日期是否在日历中是周末。     |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 实例化日历对象。

   调用getCalendar接口获取指定locale和type的时区对象（i18n为导入的模块）。其中，type表示合法的日历类型，目前合法的日历类型包括："buddhist", "chinese", "coptic", "ethiopic", "hebrew", "gregory", "indian", "islamic_civil", "islamic_tbla", "islamic_umalqura", "japanese", "persian"。当type没有给出时，采用区域默认的日历类型。

   ```js
   let calendar = I18n.getCalendar("zh-CN", "chinese"); // 创建中文农历日历
   ```

3. 设置日历对象的时间。

     调用setTime接口设置日历对象的时间。setTime接口接收两种类型的参数。一种是传入一个Date对象，另一种是传入一个数值表示从1970.1.1 00:00:00 GMT逝去的毫秒数。

   ```js
   let date1 = new Date();
   calendar.setTime(date1);
   let date2 = 1000;
   calendar.setTime(date2);
   ```

4. 设置日历对象的年、月、日、时、分、秒。

     调用set接口设置日历对象的年、月、日、时、分、秒。

   ```js
   calendar.set(2021, 12, 21, 6, 0, 0)
   ```

5. 设置、获取日历对象的时区。

   调用setTimeZone接口和getTimeZone接口来设置、获取日历对象的时区。其中，setTimeZone接口需要传入一个字符串表示需要设置的时区。

   ```js
   calendar.setTimeZone("Asia/Shanghai");
   let timezone = calendar.getTimeZone();  // timezone = "China Standard Time"
   ```

6. 设置、获取日历对象的一周起始日。

   调用setFirstDayOfWeek接口和getFirstDayOfWeek接口设置、获取日历对象的一周起始日。其中，setFirstDayOfWeek需要传入一个数值表示一周的起始日，1代表周日，7代表周六。

   ```js
   calendar.setFirstDayOfWeek(1);
   let firstDayOfWeek = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1
   ```

7. 设置、获取日历对象第一周的最小天数。
     调用setMinimalDaysInFirstWeek接口和getMinimalDaysInFirstWeek接口来设置、获取日历对象第一周的最小天数。

   ```js
   calendar.setMinimalDaysInFirstWeek(3);
   let minimalDaysInFirstWeek = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 3
   ```

8. 获取日历对象的本地化显示。
   调用getDisplayName来获取日历对象的本地化显示。

   ```js
   let localizedName = calendar.getDisplayName("zh-CN"); // localizedName = "农历"
   ```

9. 判断某一个日期是否为周末。

   调用isWeekend接口来判断输入的Date是否为周末。

   ```js
   let date = new Date(2022, 12, 12, 12, 12, 12);
   let weekend = calendar.isWeekend(date); // weekend = false
   ```

## 电话号码格式化

调用电话号码格式化[PhoneNumberFormat](../reference/apis/js-apis-i18n.md#phonenumberformat8)的接口，实现对针对不同国家电话号码的格式化以及判断电话号码格式是否正确的功能。

### 接口说明

| 类名        | 接口名称                                     | 描述                      |
| --------- | ---------------------------------------- | ----------------------- |
| PhoneNumberFormat | constructor(country:string,options?:PhoneNumberFormatOptions)<sup>8+</sup> | 实例化PhoneNumberFormat对象。 |
| PhoneNumberFormat | isValidNumber(number:string):boolean<sup>8+</sup> | 判断number是否是一个格式正确的电话号码。 |
| PhoneNumberFormat | format(number:string):string<sup>8+</sup> | 对number按照指定国家及风格进行格式化。  |
| PhoneNumberFormat | getLocationName(number: string, locale: string): string<sup>9+</sup> | 获取电话号码归属地。  |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 实例化电话号码格式化对象。

   调用PhoneNumberFormat的构造函数来实例化电话号码格式化对象，需要传入电话号码的国家代码及格式化选项。其中，格式化选项是可选的，包括style选项，该选项的取值包括："E164", "INTERNATIONAL", "NATIONAL", "RFC3966"。

   ```js
   let phoneNumberFormat = new I18n.PhoneNumberFormat("CN", {type: "E164"});
   ```

3. 判断电话号码格式是否正确。

     调用isValidNumber接口来判断输入的电话号码的格式是否正确。

   ```js
   let validNumber = phoneNumberFormat.isValidNumber("15812341234"); // validNumber = true
   ```

4. 电话号码格式化。

     调用电话号码格式化对象的format接口来对输入的电话号码进行格式化。

   ```js
   let formattedNumber = phoneNumberFormat.format("15812341234"); // formattedNumber = "+8615812341234"
   ```

## 度量衡转换

度量衡转换接口可以实现度量衡转换的相关功能。

### 接口说明

| 类名        | 接口名称                                     | 描述                                      |
| --------- | ---------------------------------------- | --------------------------------------- |
| I18NUtil | unitConvert(fromUnit:UnitInfo,toUnit:UnitInfo,value:number,locale:string,style?:string):string<sup>9+</sup> | 将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。 |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 度量衡单位转换。

   调用[unitConvert](../reference/apis/js-apis-i18n.md#unitconvert9)接口实现度量衡单位转换，并进行格式化显示的功能。

   ```js
   let fromUnit = {unit: "cup", measureSystem: "US"};
   let toUnit = {unit: "liter", measureSystem: "SI"};
   let number = 1000;
   let locale = "en-US";
   let style = "long";
   let converttedUnit = I18n.I18NUtil.unitConvert(fromUnit, toUnit, number, locale, style); // converttedUnit = "236.588 liters"
   ```

## 字母表索引

调用字母表索引[IndexUtil](../reference/apis/js-apis-i18n.md#indexutil8)的接口可以获取不同Locale的字母表索引，以及实现计算字符串所属索引的功能。

### 接口说明

| 类名        | 接口名称                                     | 描述                      |
| --------- | ---------------------------------------- | ----------------------- |
|  | getInstance(locale?:string):IndexUtil<sup>8+</sup> | 实例化字母表索引对象。             |
| IndexUtil | getIndexList():Array&lt;string&gt;<sup>8+</sup> | 获取当前Locale的索引列表。        |
| IndexUtil | addLocale(locale:string): void<sup>8+</sup> | 将新的Locale对应的索引加入当前索引列表。 |
| IndexUtil | getIndex(text:string):string<sup>8+</sup> | 获取text对应的索引。            |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 实例化字母表索引对象。

   调用getInstance接口来实例化特定locale对应的字母表索引对象。当locale参数为空时，实例化系统默认Locale的字母表索引对象。


   ```js
   let indexUtil = I18n.getInstance("zh-CN");
   ```

3. 获取索引列表。

     调用getIndexList接口来获取当前Locale对应的字母表索引列表。

   ```js
   let indexList = indexUtil.getIndexList(); // indexList = ["...", "A", "B", "C", ..., "X", "Y", "Z", "..."]
   ```

4. 增加新的索引。

     调用addLocale接口，将新的Locale对应的字母表索引添加到当前字母表索引列表中。

   ```js
   indexUtil.addLocale("ar")
   ```

5. 获取字符串对应的索引。

     调用getIndex接口来获取某一字符串对应的字母表索引。

   ```js
   let text = "access index";
   let index = indexUtil.getIndex(text); // index = "A"
   ```

## 获取文本断点位置

当文本比较长无法在一行进行显示时，调用文本断点[BreakIterator8](../reference/apis/js-apis-i18n.md#breakiterator8)的接口，来获取文本可以断行的位置。

### 接口说明

| 类名        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
|  | getLineInstance(locale:string):BreakIterator<sup>8+</sup> | 实例化断行对象。                       |
| BreakIterator | setLineBreakText(text:string): void<sup>8+</sup> | 设置要处理的文本。                      |
| BreakIterator | getLineBreakText():string<sup>8+</sup>   | 获取要处理的文本。                      |
| BreakIterator | current():number<sup>8+</sup>            | 获取当前断行对象在处理文本的位置。              |
| BreakIterator | first():number<sup>8+</sup>              | 将断行对象设置到第一个可断句的分割点。            |
| BreakIterator | last():number<sup>8+</sup>               | 将断行对象设置到最后一个可断句的分割点。           |
| BreakIterator | next(index?:number):number<sup>8+</sup>  | 将断行对象移动index个分割点的位置。           |
| BreakIterator | previous():number<sup>8+</sup>           | 将断行对象移动到前一个分割点的位置。             |
| BreakIterator | following(offset:number):number<sup>8+</sup> | 将断行对象移动到offset指定位置的后面一个分割点的位置。 |
| BreakIterator | isBoundary(offset:number):boolean<sup>8+</sup> | 判断某个位置是否是分割点。                  |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 实例化断行对象。

   调用getLineInstance接口来实例化断行对象。

   ```js
   let locale = "en-US"
   let breakIterator = I18n.getLineInstance(locale);
   ```

3. 设置、访问要断行处理的文本。

   调用setLineBreakText接口和getLineBreakText接口来设置、访问要断行处理的文本。

   ```js
   let text = "Apple is my favorite fruit";
   breakIterator.setLineBreakText(text);
   let breakText = breakIterator.getLineBreakText();  // breakText = "Apple is my favorite fruit"
   ```

4. 获取断行对象当前的位置。

   调用current接口来获取断行对象在当前处理文本中的位置。

   ```js
   let pos = breakIterator.current(); // pos = 0
   ```

5. 设置断行对象的位置。

   系统提供了很多接口可以用于调整断行对象在处理文本中的位置，包括first, last, next, previous, following。

   ```js
   let firstPos = breakIterator.first(); // 将断行对象设置到第一个分割点的位置，即文本的起始位置；firstPos = 0
   let lastPos = breakIterator.last();  // 将断行对象设置到最后一个分割点的位置，即文本末尾的下一个位置；lastPos = 26
   // 将断行对象向前或向后移动一定数量的分割点。
   // 当传入正数时，向后移动；当传入负数时，向前移动；当未传入数值时，则向后移动一个位置；
   // 当移动超出了文本的长度范围，则返回-1；
   let nextPos = breakIterator.next(-2); // nextPos = 12
   let previousPos = breakIterator.previous();  // 将断行对象向前移动向前移动一个分割点，当超出文本长度范围时返回-1； previousPos = 9
   // 将断行对象移动到offset指定位置的后面一个分割点。如果offset所指定的位置的下一个分割点超出了文本的长度范围，则返回-1；
   let followingPos = breakIterator.following(10); // followingPos = 12
   ```

6. 判断某个位置是否为分割点。

   调用isBoundary接口来判断一个接口是否为分割点；如果该位置是分割点，则返回true，并且将断行对象移动到该位置；如果该位置不是分割点，则返回false，并且将断行对象移动到该位置后的一个分割点。

   ```js
   let isboundary = breakIterator.isBoundary(5); // isboundary = false
   ```

## 获取时区

调用时区[TimeZone](../reference/apis/js-apis-i18n.md#timezone)相关接口来获取时区的相关信息，例如获取时区的ID、本地化显示、时区偏移量等。

### 接口说明

| 类名        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
|  | getTimeZone(zoneID?: string): TimeZone<sup>7+</sup> | 获取时区对象。                       |
| TimeZone | getID(): string<sup>7+</sup> | 获取时区ID。                      |
| TimeZone | getDisplayName(locale?: string, isDST?: boolean): string<sup>7+</sup>   | 获取时区的本地化显示。                      |
| TimeZone | getRawOffset(): number<sup>7+</sup>            | 获取时区对象与UTC时区的偏移量。              |
| TimeZone | getOffset(date?: number): number<sup>7+</sup>              | 获取某一时间点时区对象与UTC时区的偏移量。            |
| TimeZone | getAvailableIDs(): Array<string><sup>9+</sup>               | 获取系统支持的时区ID列表。           |
| TimeZone | getAvailableZoneCityIDs(): Array<string><sup>9+</sup>  | 获取系统支持的时区城市ID列表。           |
| TimeZone | getCityDisplayName(cityID: string, locale: string): string<sup>9+</sup>           | 获取时区城市ID的本地化显示。             |
| TimeZone | getTimezoneFromCity(cityID: string): TimeZone<sup>9+</sup> | 获取时区城市ID对应的时区对象。 |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 实例化时区对象，并获取相关时区信息。

   调用getTimeZone接口来获取时区对象。

   ```js
   let timezone = I18n.getTimeZone(); // 使用默认参数可以获取系统时区对象。
   ```

   获取时区ID、本地化显示、时区偏移量、某一时刻的时区偏移量信息。
   
   ```js
   let timezoneID = timezone.getID(); // timezoneID = "Asia/Shanghai"
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "中国标准时间"
   let rawOffset = timezone.getRawOffset(); // rawOffset = 28800000
   let offset = timezone.getOffset(new Date().getTime()); // offset = 28800000
   ```

3. 获取系统支持的时区ID。

   调用getAvailableIDs接口获取系统支持的时区ID列表。
   时区ID列表中的时区ID可以作为getTimeZone接口的参数，来创建TimeZone对象。

   ```js
   let timezoneIDs = I18n.TimeZone.getAvailableIDs(); // timezoneIDs = ["America/Adak", ...]，共包含24个时区ID
   let timezone = I18n.getTimeZone(timezoneIDs[0]);
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "夏威夷-阿留申时间"
   ```

4. 获取系统支持的时区城市ID。

   调用getAvailableZoneCityIDs接口获取系统支持的时区城市ID列表。
   调用getCityDisplayName接口获取时区城市ID的本地化显示。
   调用getTimezoneFromCity接口基于时区城市ID创建时区对象。

   ```js
   let zoneCityIDs = I18n.TimeZone.getAvailableZoneCityIDs(); // ["Auckland", "Magadan", ...]
   let cityDisplayName = I18n.TimeZone.getCityDisplayName(zoneCityIDs[0], "zh-Hans"); // cityDisplayName = "奥克兰(新西兰)"
   let timezone = I18n.TimeZone.getTimezoneFromCity(zoneCityIDs[0]);
   let timezoneDisplayName = timezone.getDisplayName(); // timezoneDisplayName = "新西兰时间"
   ```

## 获取音译对象

调用音译[Transliterator](../reference/apis/js-apis-i18n.md#transliterator9)相关接口来创建音译对象，获取音译字符串。

### 接口说明

| 类名        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
| Transliterator | getAvailableIDs():Array<string><sup>9+</sup> | 获取音译支持的ID列表。                       |
| Transliterator | getInstance(): Transliterator<sup>9+</sup> | 创建音译对象。                      |
| Transliterator | transform(text: string): string<sup>9+</sup>   | 获取音译字符串。                      |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 获取支持音译的ID列表。

   调用getAvailableIDs接口来获取支持音译的ID列表。
   每个ID的格式为 source-destination，例如 ASCII-Latin，表示将ASCII转换为Latin的音译ID。

   ```js
   let ids = I18n.Transliterator.getAvailableIDs(); // ids = ["ASCII-Latin", "Accents-Any", ... ]，共支持671个语言
   ```

3. 创建音译对象，获取音译字符串。

   支持音译的ID列表中的ID可以作为getInstance接口的参数，创建音译对象。
   调用transform接口，获取音译字符串。

   ```js
   let transliterator = I18n.Transliterator.getInstance("Any-Latn"); // Any-Latn表示将任意文本转换为Latn文本
   let transformText = transliterator.transform("你好"); // transformText = "nǐ hǎo "
   ```

## 字符类型判断

调用字符[Unicode](../reference/apis/js-apis-i18n.md#unicode9)相关接口来获取字符的相关信息，例如字符是否是数字、字符是否是空格符等。

### 接口说明

| 类名        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
| Unicode | isDigit(char: string): boolean<sup>9+</sup> | 判断字符是否是数字。                       |
| Unicode | isSpaceChar(char: string): boolean<sup>9+</sup> | 判断字符是否是空格符。                      |
| Unicode | isWhitespace(char: string): boolean<sup>9+</sup>   | 判断字符是否是空白符。                      |
| Unicode | isRTL(char: string): boolean<sup>9+</sup>            | 判断字符是否是从左到右显示的字符。              |
| Unicode | isIdeograph(char: string): boolean<sup>9+</sup>              | 判断字符是否是表意文字。            |
| Unicode | isLetter(char: string): boolean<string><sup>9+</sup>               | 判断字符是否是字母。           |
| Unicode | isLowerCase(char: string): boolean<string><sup>9+</sup>  | 判断字符是否是小写字母。           |
| Unicode | isUpperCase(char: string): boolean<sup>9+</sup>           | 判断字符是否是大写字母。             |
| Unicode | getType(char: string): string<sup>9+</sup> | 获取字符的类型。 |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 判断字符是否具有某种性质。

   判断字符是否是数字。

   ```js
   let isDigit = I18n.Unicode.isDigit("1"); // isDigit = true
   isDigit = I18n.Unicode.isDigit("a"); // isDigit = false
   ```

   判断字符是否是空格符。

   ```js
   let isSpaceChar = I18n.Unicode.isSpaceChar(" "); // isSpaceChar = true
   isSpaceChar = I18n.Unicode.isSpaceChar("\n"); // isSpaceChar = false
   ```

   判断字符是否是空白符。

   ```js
   let isWhitespace = I18n.Unicode.isWhitespace(" "); // isWhitespace = true
   isWhitespace = I18n.Unicode.isWhitespace("\n"); // isWhitespace = true
   ```

   判断字符是否是从左到右书写的文字。

   ```js
   let isRTL = I18n.Unicode.isRTL("مرحبًا"); // isRTL = true，阿拉伯语的文字是从左到右书写的文字
   isRTL = I18n.Unicode.isRTL("a"); // isRTL = false
   ```

   判断字符是否是表意文字。

   ```js
   let isIdeograph = I18n.Unicode.isIdeograph("你好"); // isIdeograph = true
   isIdeograph = I18n.Unicode.isIdeograph("a"); // isIdeograph = false
   ```

   判断字符是否是字母。

   ```js
   let isLetter = I18n.Unicode.isLetter("a"); // isLetter = true
   isLetter = I18n.Unicode.isLetter("."); // isLetter = false
   ```

   判断字符是否是小写字母。

   ```js
   let isLowerCase = I18n.Unicode.isLowerCase("a"); // isLetter = true
   isLowerCase = I18n.Unicode.isLowerCase("A"); // isLetter = false
   ```

   判断字符是否是大写字母。

   ```js
   let isUpperCase = I18n.Unicode.isUpperCase("a"); // isUpperCase = false
   isUpperCase = I18n.Unicode.isUpperCase("A"); // isUpperCase = true
   ```

3. 获取字符的类型。

   调用getType接口获取字符的类型。

   ```js
   let type = I18n.Unicode.getType("a"); // type = U_LOWER_CASE_LETTER
   ```

## 获取日期中年月日的排列顺序

### 接口说明

| 类名        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
| I18NUtil | getDateOrder(locale: string): string<sup>9+</sup> | 判断日期中年月日的排列顺序。                       |

### 开发步骤

1. 导入I18n模块。

   ```js
   import I18n from '@ohos.i18n'
   ```

2. 判断日期的年月日的排序顺序。

   调用getDateOrder接口判断某一Locale的日期中，年月日的排列顺序。
   接口返回一个字符串，由"y"，"L"，"d"三部分组成，分别表示年、月、日，使用中划线进行拼接。例如，"y-L-d"。

   ```js
   let order = I18n.I18NUtil.getDateOrder("zh-CN"); // order = "y-L-d"，表示中文中年月日的顺序为年-月-日。
   ```