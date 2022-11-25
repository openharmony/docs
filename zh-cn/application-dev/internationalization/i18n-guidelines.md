# I18n开发指导

本模块提供系统相关的或者增强的国际化能力，包括区域管理、电话号码处理、日历等，相关接口为ECMA 402标准中未定义的补充接口。更多接口和使用方式请见[I18N](../reference/apis/js-apis-i18n.md)。

[Intl](intl-guidelines.md)模块提供了ECMA 402标准定义的基础国际化接口，与本模块共同使用可提供完整地国际化支持能力。

## 获取系统语言区域信息

调用系统提供的接口访问系统的语言区域信息。

### 接口说明

| 模块        | 接口名称                                     | 描述                    |
| --------- | ---------------------------------------- | --------------------- |
| ohos.i18n | getSystemLanguage():string               | 获取系统语言。               |
| ohos.i18n | getSystemRegion():string                 | 获取系统区域。               |
| ohos.i18n | getSystemLocale():string                 | 获取系统Locale。           |
| ohos.i18n | isRTL(locale:string):boolean<sup>7+</sup> | locale对应的语言是否为从右到左语言。 |
| ohos.i18n | is24HourClock():boolean<sup>7+</sup>     | 获取当前系统时间是否采用24小时制。    |
| ohos.i18n | getDisplayLanguage(language:string,locale:string,sentenceCase?:boolean):string | 获取语言的本地化表示。           |
| ohos.i18n | getDisplayCountry(country:string,locale:string,sentenceCase?:boolean):string | 获取国家的本地化表示。           |

### 开发步骤

1. 获取系统语言。

   调用getSystemLanguage方法获取当前系统设置的语言（i18n为导入的模块）。

   ```js
   var language = i18n.getSystemLanguage();
   ```

2. 获取系统区域。

     调用getSystemRegion方法获取当前系统设置的区域

   ```js
   var region = i18n.getSystemRegion();
   ```

3. 获取系统Locale。

     调用getSystemLocale方法获取当前系统设置的Locale

   ```js
   var locale = i18n.getSystemLocale();
   ```

4. 判断Locale的语言是否为RTL语言。

   调用isRTL方法获取Locale的语言是否为从右到左语言。

   ```js
   var rtl = i18n.isRTL("zh-CN");
   ```

5. 判断当前系统时间是否采用24小时制。

     调用is24HourClock方法来判断当前系统的时间是否采用24小时制。

   ```js
   var hourClock = i18n.is24HourClock();
   ```

6. 获取语言的本地化表示。

     调用getDisplayLanguage方法获取某一语言的本地化表示。其中，language表示待本地化显示的语言，locale表示本地化的Locale，sentenceCase结果是否需要首字母大写。

   ```js
   var language = "en";
   var locale = "zh-CN";
   var sentenceCase = false;
   var localizedLanguage = i18n.getDisplayLanguage(language, locale, sentenceCase);
   ```

7. 获取国家的本地化表示。

     调用getDisplayCountry方法获取某一国家的本地化表示。其中，country表示待本地化显示的国家，locale表示本地化的Locale，sentenceCase结果是否需要首字母大写。

   ```js
   var country = "US";
   var locale = "zh-CN";
   var sentenceCase = false;
   var localizedCountry = i18n.getDisplayCountry(country, locale, sentenceCase);
   ```

## 获取日历信息

调用日历[Calendar](../reference/apis/js-apis-i18n.md#calendar8)相关接口来获取日历的相关信息，例如获取日历的本地化显示、一周起始日、一年中第一周的最小天数等。

### 接口说明

| 模块        | 接口名称                                     | 描述                    |
| --------- | ---------------------------------------- | --------------------- |
| ohos.i18n | getCalendar(locale:string,type?:string):Calendar<sup>8+</sup> | 获取指定locale和type的日历对象。 |
| ohos.i18n | setTime(date:Date): void<sup>8+</sup>    | 设置日历对象内部的时间日期。        |
| ohos.i18n | setTime(time:number): void<sup>8+</sup>  | 设置日历对象内部的时间日期。        |
| ohos.i18n | set(year:number,month:number,date:number,hour?:number,minute?:number,second?:number): void<sup>8+</sup> | 设置日历对象的年、月、日、时、分、秒。   |
| ohos.i18n | setTimeZone(timezone:string): void<sup>8+</sup> | 设置日历对象的时区。            |
| ohos.i18n | getTimeZone():string<sup>8+</sup>        | 获取日历对象的时区。            |
| ohos.i18n | getFirstDayOfWeek():number<sup>8+</sup>  | 获取日历对象的一周起始日。         |
| ohos.i18n | setFirstDayOfWeek(value:number): void<sup>8+</sup> | 设置日历对象的一周起始日。         |
| ohos.i18n | getMinimalDaysInFirstWeek():number<sup>8+</sup> | 获取一年中第一周的最小天数。        |
| ohos.i18n | setMinimalDaysInFirstWeek(value:number): void<sup>8+</sup> | 设置一年中第一周的最小天数。        |
| ohos.i18n | getDisplayName(locale:string):string<sup>8+</sup> | 获取日历对象的本地化表示。         |
| ohos.i18n | isWeekend(date?:Date):boolean<sup>8+</sup> | 判断给定的日期是否在日历中是周末。     |

### 开发步骤

1. 实例化日历对象。

   调用getCalendar方法获取指定locale和type的时区对象（i18n为导入的模块）。其中，type表示合法的日历类型，目前合法的日历类型包括："buddhist", "chinese", "coptic", "ethiopic", "hebrew", "gregory", "indian", "islamic_civil", "islamic_tbla", "islamic_umalqura", "japanese", "persian"。当type没有给出时，采用区域默认的日历类型。

   ```js
   var calendar = i18n.getCalendar("zh-CN", "gregory");
   ```

2. 设置日历对象的时间。

     调用setTime方法设置日历对象的时间。setTime方法接收两种类型的参数。一种是传入一个Date对象，另一种是传入一个数值表示从1970.1.1 00:00:00 GMT逝去的毫秒数。

   ```js
   var date1 = new Date();
   calendar.setTime(date1);
   var date2 = 1000;
   calendar.setTime(date2);
   ```

3. 设置日历对象的年、月、日、时、分、秒。

     调用set方法设置日历对象的年、月、日、时、分、秒。

   ```js
   calendar.set(2021, 12, 21, 6, 0, 0)
   ```

4. 设置、获取日历对象的时区。

   调用setTimeZone方法和getTimeZone方法来设置、获取日历对象的时区。其中，setTimeZone方法需要传入一个字符串表示需要设置的时区。

   ```js
   calendar.setTimeZone("Asia/Shanghai");
   var timezone = calendar.getTimeZone();
   ```

5. 设置、获取日历对象的一周起始日。

   调用setFirstDayOfWeek方法和getFirstDayOfWeek方法设置、获取日历对象的一周起始日。其中，setFirstDayOfWeek需要传入一个数值表示一周的起始日，1代表周日，7代表周六。

   ```js
   calendar.setFirstDayOfWeek(1);
   var firstDayOfWeek = calendar.getFirstDayOfWeek();
   ```

6. 设置、获取日历对象第一周的最小天数
     调用setMinimalDaysInFirstWeek方法和getMinimalDaysInFirstWeek方法来设置、获取日历对象第一周的最小天数。

   ```js
   calendar.setMinimalDaysInFirstWeek(3);
   var minimalDaysInFirstWeek = calendar.getMinimalDaysInFirstWeek();
   ```

7. 获取日历对象的本地化显示
   调用getDisplayName来获取日历对象的本地化显示。

   ```js
   var localizedName = calendar.getDisplayName("zh-CN");
   ```

8. 判断某一个日期是否为周末。

   调用isWeekend方法来判断输入的Date是否为周末。

   ```js
   var date = new Date();
   var weekend = calendar.isWeekend(date);
   ```

## 电话号码格式化

调用电话号码格式化[PhoneNumberFormat](../reference/apis/js-apis-i18n.md#phonenumberformat8)的接口，实现对针对不同国家电话号码的格式化以及判断电话号码格式是否正确的功能。

### 接口说明

| 模块        | 接口名称                                     | 描述                      |
| --------- | ---------------------------------------- | ----------------------- |
| ohos.i18n | constructor(country:string,options?:PhoneNumberFormatOptions)<sup>8+</sup> | 实例化PhoneNumberFormat对象。 |
| ohos.i18n | isValidNumber(number:string):boolean<sup>8+</sup> | 判断number是否是一个格式正确的电话号码。 |
| ohos.i18n | format(number:string):string<sup>8+</sup> | 对number按照指定国家及风格进行格式化。  |

### 开发步骤

1. 实例化电话号码格式化对象。

   调用PhoneNumberFormat的构造函数来实例化电话号码格式化对象，需要传入电话号码的国家代码及格式化选项。其中，格式化选项是可选的，包括style选项，该选项的取值包括："E164", "INTERNATIONAL", "NATIONAL", "RFC3966"。

   ```js
   var phoneNumberFormat = new i18n.PhoneNumberFormat("CN", {type: "E164"});
   ```

2. 判断电话号码格式是否正确。

     调用isValidNumber方法来判断输入的电话号码的格式是否正确。

   ```js
   var validNumber = phoneNumberFormat.isValidNumber("15812341234");
   ```

3. 电话号码格式化。

     调用电话号码格式化对象的format方法来对输入的电话号码进行格式化。

   ```js
   var formattedNumber = phoneNumberFormat.format("15812341234");
   ```

## 度量衡转换

度量衡转换接口可以实现度量衡转换的相关功能。

### 接口说明

| 模块        | 接口名称                                     | 描述                                      |
| --------- | ---------------------------------------- | --------------------------------------- |
| ohos.i18n | unitConvert(fromUnit:UnitInfo,toUnit:UnitInfo,value:number,locale:string,style?:string):string<sup>8+</sup> | 将fromUnit的单位转换为toUnit的单位，并根据区域与风格进行格式化。 |

### 开发步骤

1. 度量衡单位转换。

   调用[unitConvert](../reference/apis/js-apis-i18n.md#unitconvert9)方法实现度量衡单位转换，并进行格式化显示的功能。

   ```js
   var fromUnit = {unit: "cup", measureSystem: "US"};
   var toUnit = {unit: "liter", measureSystem: "SI"};
   var number = 1000;
   var locale = "en-US";
   var style = "long";
   i18n.Util.unitConvert(fromUtil, toUtil, number, locale, style);
   ```

## 字母表索引

调用字母表索引[IndexUtil](../reference/apis/js-apis-i18n.md#indexutil8)的接口可以获取不同Locale的字母表索引，以及实现计算字符串所属索引的功能。

### 接口说明

| 模块        | 接口名称                                     | 描述                      |
| --------- | ---------------------------------------- | ----------------------- |
| ohos.i18n | getInstance(locale?:string):IndexUtil<sup>8+</sup> | 实例化字母表索引对象。             |
| ohos.i18n | getIndexList():Array&lt;string&gt;<sup>8+</sup> | 获取当前Locale的索引列表。        |
| ohos.i18n | addLocale(locale:string): void<sup>8+</sup> | 将新的Locale对应的索引加入当前索引列表。 |
| ohos.i18n | getIndex(text:string):string<sup>8+</sup> | 获取text对应的索引。            |

### 开发步骤

1. 实例化字母表索引对象。

   调用getInstance方法来实例化特定locale对应的字母表索引对象。当locale参数为空时，实例化系统默认Locale的字母表索引对象。


   ```js
   var indexUtil = i18n.getInstance("zh-CN");
   ```

2. 获取索引列表。

     调用getIndexList方法来获取当前Locale对应的字母表索引列表。

   ```js
   var indexList = indexUtil.getIndexList();
   ```

3. 增加新的索引。

     调用addLocale方法，将新的Locale对应的字母表索引添加到当前字母表索引列表中。

   ```js
   indexUtil.addLocale("ar")
   ```

4. 获取字符串对应的索引。

     调用getIndex方法来获取某一字符串对应的字母表索引。

   ```js
   var text = "access index";
   indexUtil.getIndex(text);
   ```

## 获取文本断点位置

当文本比较长无法在一行进行显示时，调用文本断点[BreakIterator8](../reference/apis/js-apis-i18n.md#breakiterator8)的接口，来获取文本可以断行的位置。

### 接口说明

| 模块        | 接口名称                                     | 描述                             |
| --------- | ---------------------------------------- | ------------------------------ |
| ohos.i18n | getLineInstance(locale:string):BreakIterator<sup>8+</sup> | 实例化断行对象。                       |
| ohos.i18n | setLineBreakText(text:string): void<sup>8+</sup> | 设置要处理的文本。                      |
| ohos.i18n | getLineBreakText():string<sup>8+</sup>   | 获取要处理的文本。                      |
| ohos.i18n | current():number<sup>8+</sup>            | 获取当前断行对象在处理文本的位置。              |
| ohos.i18n | first():number<sup>8+</sup>              | 将断行对象设置到第一个可断句的分割点。            |
| ohos.i18n | last():number<sup>8+</sup>               | 将断行对象设置到最后一个可断句的分割点。           |
| ohos.i18n | next(index?:number):number<sup>8+</sup>  | 将断行对象移动index个分割点的位置。           |
| ohos.i18n | previous():number<sup>8+</sup>           | 将断行对象移动到前一个分割点的位置。             |
| ohos.i18n | following(offset:number):number<sup>8+</sup> | 将断行对象移动到offset指定位置的后面一个分割点的位置。 |
| ohos.i18n | isBoundary(offset:number):boolean<sup>8+</sup> | 判断某个位置是否是分割点。                  |

### 开发步骤

1. 实例化断行对象。

   调用getLineInstance方法来实例化断行对象。

   ```js
   var locale = "en-US"
   var breakIterator = i18n.getLineInstance(locale);
   ```

2. 设置、访问要断行处理的文本。

   调用setLineBreakText方法和getLineBreakText方法来设置、访问要断行处理的文本。

   ```js
   var text = "Apple is my favorite fruit";
   breakIterator.setLineBreakText(text);
   var breakText = breakIterator.getLineBreakText();
   ```

3. 获取断行对象当前的位置。

   调用current方法来获取断行对象在当前处理文本中的位置。

   ```js
   var pos = breakIterator.current();
   ```

4. 设置断行对象的位置。

   系统提供了很多接口可以用于调整断行对象在处理文本中的位置，包括first, last, next, previous, following。

   ```js
   var firstPos = breakIterator.first(); // 将断行对象设置到第一个分割点的位置，即文本的起始位置；
   var lastPos = breakIterator.last();  // 将断行对象设置到最后一个分割点的位置，即文本末尾的下一个位置；
   // 将断行对象向前或向后移动一定数量的分割点。
   // 当传入正数时，向后移动；当传入负数时，向前移动；当未传入数值时，则向后移动一个位置；
   // 当移动超出了文本的长度范围，则返回-1；
   var nextPos = breakIterator.next(-2);
   var previousPos = breakIterator.previous();  // 将断行对象向前移动向前移动一个分割点，当超出文本长度范围时返回-1；
   // 将断行对象移动到offset指定位置的后面一个分割点。如果offset所指定的位置的下一个分割点超出了文本的长度范围，则返回-1；
   var followingPos = breakIterator.following(10); 
   ```

5. 判断某个位置是否为分割点。

   调用isBoundary方法来判断一个方法是否为分割点；如果该位置是分割点，则返回true，并且将断行对象移动到该位置；如果该位置不是分割点，则返回false，并且将断行对象移动到该位置后的一个分割点。

   ```js
   var isboundary = breakIterator.isBoundary(5);
   ```