# Intl开发指导

本模块提供基础的应用国际化能力，包括时间日期格式化、数字格式化、排序等，相关接口在ECMA 402标准中定义。更多接口和使用方式请见[Intl](../reference/apis/js-apis-intl.md)。

[I18N](i18n-guidelines.md)模块提供其他非ECMA 402定义的国际化接口，与本模块共同使用可提供完整地国际化支持能力。

## 设置区域信息

调用[Locale](../reference/apis/js-apis-intl.md#locale)的相关接口实现最大化区域信息或最小化区域信息。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| Locale | constructor()<sup>8+</sup> | 实例化Locale对象。 |
| Locale | constructor(locale:string,options?:LocaleOptions) | 基于locale参数及其选项实例化Locale对象。 |
| Locale | toString():string | 将Locale信息转换为字符串。 |
| Locale | maximize():Locale | 最大化区域信息。 |
| Locale | minimize():Locale | 最小化区域信息。 |

### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化Locale对象。

   使用Locale的构造函数创建Locale对象，该方法接收一个表示Locale的字符串及可选的[属性](../reference/apis/js-apis-intl.md#localeoptions)列表（intl为导入的模块名）。

   表示Locale的字符串参数可以分为以下四部分：语言、脚本、地区、扩展参数。各个部分按照顺序使用中划线“-”进行连接。
   -  语言：必选，使用2个或3个小写英文字母表示（可参考ISO-639标准），例如英文使用“en”表示，中文使用“zh”表示。
   -  脚本：可选，使用4个英文字母表示，其中首字母需要大写，后面3个使用小写字母（可参考ISO-15924）。例如，中文繁体使用脚本“Hant”表示，中文简体使用脚本“Hans”表示。
   -  国家或地区：可选，使用两个大写字母表示（可参考ISO-3166），例如中国使用“CN”表示，美国使用“US”表示；
   -  扩展参数：可选，由key和value两部分组成，目前支持以下扩展参数（可参考BCP 47扩展）。各个扩展参数之间没有严格的顺序，使用“-key-value”的格式书写。扩展参数整体使用“-u”连接到语言、脚本、地区后面。例如“zh-u-nu-latn-ca-chinese”表示使用“latn”数字系统，“chinese”日历系统。扩展参数也可以通过第二个参数传入。
      | 扩展参数ID | 扩展参数说明 |
      | -------- | -------- |
      | ca | 表示日历系统 |
      | co | 表示排序规则 |
      | hc | 表示守时惯例 |
      | nu | 表示数字系统 |
      | kn | 表示字符串排序、比较时是否考虑数字的实际值 |
      | kf | 表示字符串排序、比较时是否考虑大小写 |

   
   ```js
   let locale = "zh-CN";
   let options = {caseFirst: "false", calendar: "chinese", collation: "pinyin"};
   let localeObj = new Intl.Locale(locale, options);
   ```

3. 获取Locale的字符串表示。

     调用toString方法来获取Locale对象的字符串表示，其中包括了语言、区域及其他选项信息。
     
   ```js
   let localeStr = localeObj.toString(); // localeStr = "zh-CN-u-ca-chinese-co-pinyin-kf-false
   ```

4. 最大化区域信息。

     调用maximize方法来最大化区域信息，即当缺少脚本与地区信息时，对其进行补全。
     
   ```js
   let maximizedLocale = localeObj.maximize();
   let maximizedLocaleStr = maximizedLocale.toString(); // localeStr = "zh-Hans-CN-u-ca-chinese-co-pinyin-kf-false
   ```

5. 最小化区域信息。

     调用minimize方法来最小化区域信息，即当存在脚本与地区信息时，对其进行删除。
     
   ```js
   let minimizedLocale = localeObj.minimize();
   let minimizedLocaleStr = minimizedLocale.toString(); // zh-u-ca-chinese-co-pinyin-kf-false
   ```

## 格式化日期时间

调用日期时间格式化[DateTimeFormat](../reference/apis/js-apis-intl.md#datetimeformat)的接口，实现针对特定Locale的日期格式化以及时间段格式化功能。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| DateTimeFormat | constructor()<sup>8+</sup> | 创建日期时间格式化对象。 |
| DateTimeFormat | constructor(locale:string\|Array&lt;string&gt;,options?:DateTimeOptions) | 创建日期时间格式化对象，并设置提供的Locale和格式化相关属性。 |
| DateTimeFormat | format(date:Date):string | 依据DateTimeFormat对象的Locale及其他格式化属性，计算日期时间的格式化表示。 |
| DateTimeFormat | formatRange(startDate:Date,endDate:Date):string | 依据DateTimeFormat对象的Locale及其他格式化属性，计算时间段的格式化表示。 |
| DateTimeFormat | resolvedOptions():DateTimeOptions | 获取DateTimeFormat对象的相关属性。 |

### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化日期时间格式化对象。

   一种方法是使用DateTimeFormat提供的默认构造函数，通过访问系统语言和地区设置，获取系统默认Locale，并将其作为DateTimeFormat对象内部的Locale。

   ```js
   let dateTimeFormat = new Intl.DateTimeFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建日期时间格式化对象。其中，格式化参数是可选的，完整的格式化参数列表见[DateTimeOptions](../reference/apis/js-apis-intl.md#datetimeoptions6)。
   
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   ```

3. 格式化日期时间。

     使用DateTimeFormat的format方法对一个Date对象进行格式化，该方法会返回一个字符串作为格式化的结果。
     
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   let date = new Date(2022, 12, 12, 12, 12, 12);
   let formatResult = dateTimeFormat.format(date); // formatResult = "2023年1月12日星期四 中国标准时间 下午12:12:12"
   ```

4. 格式化时间段。

     使用DateTimeFormat的formatRange方法对一个时间段进行格式化。该方法需要传入两个Date对象，分别表示时间段的起止日期，返回一个字符串作为格式化的结果。
     
   ```js
   let startDate = new Date(2021, 11, 17, 3, 24, 0);
   let endDate = new Date(2021, 11, 18, 3, 24, 0);
   let datefmt = new Intl.DateTimeFormat("en-GB");
   let formatRangeResult = datefmt.formatRange(startDate, endDate); // formatRangeResult = "17/12/2021-18/12/2021"
   ```

5. 访问日期时间格式化对象的相关属性。

     DateTimeFormat的resolvedOptions方法会返回一个对象，该对象包含了DateTimeFormat对象的所有相关属性及其值。
     
   ```js
   let options = {dateStyle: "full", timeStyle: "full"};
   let dateTimeFormat = new Intl.DateTimeFormat("zh-CN", options);
   let resolvedOptions = dateTimeFormat.resolvedOptions(); // resolvedOptions = {"locale": "zh-CN", "calendar": "gregorian", "dateStyle":"full", "timeStyle":"full", "timeZone": "CST"}
   ```

## 数字格式化

调用数字格式化[NumberFormat](../reference/apis/js-apis-intl.md#numberformat)的接口，实现针对特定Locale的数字格式化功能。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| NumberFormat | constructor()<SUP>8+</SUP> | 创建数字格式化对象。 |
| NumberFormat | constructor(locale:string\|Array&lt;string&gt;,options?:NumberOptions) | 创建数字格式化对象，并设置提供的locale和格式化相关属性。 |
| NumberFormat | format(number:number):string | 依据NumberFormat对象的Locale及其他格式化属性，计算数字的格式化表示。 |
| NumberFormat | resolvedOptions():NumberOptions | 获取NumberFormat对象的相关属性。 |

### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化数字格式化对象。

   一种方法是使用NumberFormat提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   let numberFormat = new Intl.NumberFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建数字格式化对象。其中，格式化参数是可选的，完整的格式化参数列表参见[NumberOptions](../reference/apis/js-apis-intl.md##numberoptions6)。
   
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   ```

3. 数字格式化。

     使用NumberFormat的format方法对传入的数字进行格式化。该方法返回一个字符串作为格式化的结果。
     
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   let number = 1234.5678;
   let formatResult = numberFormat.format(number); // formatResult = "1235"
   ```

4. 访问数字格式化对象的相关属性。

     NumberFormat的resolvedOptions方法会返回一个对象，该对象包含了NumberFormat对象的所有相关属性及其值。
     
   ```js
   let options = {compactDisplay: "short", notation: "compact"};
   let numberFormat = new Intl.NumberFormat("zh-CN", options);
   let resolvedOptions = numberFormat.resolvedOptions();  // resolvedOptions = {"locale": "zh-CN", "compactDisplay": "short", "notation": "compact", "numberingSystem": "Latn"}
   ```

## 字符串排序

不同区域的用户对于字符串排序具有不同的需求。调用字符串排序[Collator](../reference/apis/js-apis-intl.md#collator8)的接口，实现针对特定Locale的字符串排序功能。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| Collator | constructor()<sup>8+</sup> | 创建排序对象。 |
| Collator | constructor(locale:string\|Array&lt;string&gt;,options?:CollatorOptions)<sup>8+</sup> | 创建排序对象，并设置提供的locale和其他相关属性。 |
| Collator | compare(first:string,second:string):number<sup>8+</sup> | 依据排序对象的Locale及其属性，计算两个字符串的比较结果。 |
| Collator | resolvedOptions():CollatorOptions<sup>8+</sup> | 获取排序对象的相关属性。 |

### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化排序对象。

   一种方法是使用Collator提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   let collator = new Intl.Collator();
   ```

     另一种方法是使用开发者提供的Locale和其他相关参数来创建Collator对象，完整的参数列表参见[CollatorOptions](../reference/apis/js-apis-intl.md#collatoroptions8)。
     其中，sensitivity参数用于控制哪些级别的差异会被用于比较两个字符串。取值"base"表示，仅比较字符本身，不考虑重音符号、大小写差异。例如，'a' != 'b'，'a' == 'á'，'a' == 'A'。取值"accent"表示考虑重音符号，不考虑大小写的差异。例如，'a' != 'b'，'a' != 'á'，'a' == 'A'。取值"case"表示考虑大小写的差异，不考虑重音符号的差异。例如，'a' != 'b'，'a' == 'á'，'a' != 'A'。取值"variant"表示考虑重音符号、大小写等方面差异。例如'a' != 'b'，'a' != 'á'，'a' != 'A'。
   
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort", sensitivity: "case"});
   ```

3. 比较字符串。

     使用Collator的compare方法对传入的两个字符串进行比较。该方法返回一个数值作为比较的结果，返回-1表示第一个字符串小于第二个字符串，返回1表示第一个字符大于第二个字符串，返回0表示两个字符串相同。基于两个字符串的比较结果，开发者可以字符串集合进行排序。
     
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort", sensitivity: "case"});
   let str1 = "first string";
   let str2 = "second string";
   let compareResult = collator.compare(str1, str2); // compareResult = -1
   str1 = "first";
   str2 = "First";
   compareResult = collator.compare(str1, str2); // compareResult = -1
   ```

4. 访问排序对象的相关属性。

     Collator的resolvedOptions方法会返回一个对象，该对象包含了Collator对象的所有相关属性及其值。
     
   ```js
   let collator= new Intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort"});
   let options = collator.resolvedOptions(); // options = {"localeMatcher": "best fit", "locale": "zh-CN", "usage": "sort", "sensitivity": "variant", "ignorePunctuation": "false", "numeric": false, "caseFirst": "false", "collation": "default"}
   ```

## 判定单复数类别

在一些语言的语法中，当数字后面存在名词时，名词需要根据数字的值采用不同的形式。调用单复数[PluralRules](../reference/apis/js-apis-intl.md#pluralrules8)的接口，可以实现针对特定Locale计算数字单复数类别的功能，从而选择合适的名词单复数表示。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| PluralRules | constructor()<sup>8+</sup> | 创建单复数对象。 |
| PluralRules | constructor(locale:string\|Array&lt;string&gt;,options?:PluralRulesOptions)<sup>8+</sup> | 创建单复数对象，并设置提供的locale和其他相关属性。 |
| PluralRules | select(n:number):string<sup>8+</sup> | 依据单复数对象的Locale及其他格式化属性，计算数字的单复数类别。 |


### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化单复数对象。

   一种方法是使用PluralRules提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   let pluralRules = new Intl.PluralRules();
   ```

     另一种方法是使用开发者提供的Locale和其他相关参数来创建单复数对象。完整的参数列表参见[PluralRulesOptions](../reference/apis/js-apis-intl.md#pluralrulesoptions8)。
   
   ```js
   let pluralRules = new Intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"});
   ```

3. 计算数字单复数类别。

     使用PluralRules的select方法计算传入数字的单复数类别。该方法返回一个字符串作为传入数字的类别，包括："zero", "one", "two", "few", "many", "other"六个类别。
     
   ```js
   let pluralRules = new Intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"});
   let number = 1234.5678;
   let categoryResult = pluralRules.select(number); // categoryResult = "other"
   ```

## 相对时间格式化

调用相对时间格式化[RelativeTimeFormat](../reference/apis/js-apis-intl.md#relativetimeformat8)的接口，实现针对特定Locale的相对时间格式化功能。

### 接口说明

| 类名 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| RelativeTimeFormat | constructor()<sup>8+</sup> | 创建相对时间格式化对象。 |
| RelativeTimeFormat | constructor(locale:string\|Array&lt;string&gt;,options?:RelativeTimeFormatInputOptions)<sup>8+</sup> | 创建相对时间格式化对象，并设置提供的locale和格式化相关属性。 |
| RelativeTimeFormat | format(value:number,unit:string):string<sup>8+</sup> | 依据相对时间格式化对象的Locale及其他格式化属性，计算相对时间的格式化表示。 |
| RelativeTimeFormat | formatToParts(value:number,unit:string):Array&lt;object&gt;<sup>8+</sup> | 依据相对时间格式化对象的Locale及其他格式化属性，返回相对时间格式化表示的各个部分。 |
| RelativeTimeFormat | resolvedOptions():RelativeTimeFormatResolvedOptions<sup>8+</sup> | 获取相对时间格式化对象的相关属性。 |

### 开发步骤

1. 导入Intl模块。

   未正确导入包可能会产生不明确的接口行为。
   
   ```js
   import Intl from '@ohos.intl';
   ```

2. 实例化相对时间格式化对象。

   一种方法是使用RelativeTimeFormat提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。
   
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建相对时间格式化对象。其中，格式化参数是可选的，完整的参数列表参见[RelativeTimeFormatInputOptions](../reference/apis/js-apis-intl.md#relativetimeformatinputoptions8)。
   
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   ```

3. 相对时间格式化。

     使用RelativeTimeFormat的format方法对相对时间进行格式化。方法接收一个表示相对时间长度的数值和表示单位的字符串，其中单位包括："year", "quarter", "month", "week", "day", "hour", "minute", "second"。方法返回一个字符串作为格式化的结果。
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let number = 2;
   let unit = "year";
   let formatResult = relativeTimeFormat.format(number, unit); // 2年后
   ```

4. 获取相对时间格式化结果的各个部分。

     获取相对时间格式化结果的各个部分，从而自定义格式化结果。
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let number = 2;
   let unit = "year";
   let formatPartsResult = relativeTimeFormat.formatToParts(number, unit); // formatPartsResult = [{"type": "integer", "value": "2", "unit": "year"}, {"type":"literal", "value": "年后"}]
   ```

5. 访问相对时间格式化对象的相关属性。

     RelativeTimeFormat的resolvedOptions方法会返回一个对象，该对象包含了RelativeTimeFormat对象的所有相关属性及其值，完整的属性列表参见[ RelativeTimeFormatResolvedOptions](../reference/apis/js-apis-intl.md#relativetimeformatresolvedoptions8)。
     
   ```js
   let relativeTimeFormat = new Intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   let options = relativeTimeFormat.resolvedOptions(); // options = {"locale": "zh-CN", "style": "long", "numeric": "always", "numberingSystem": "latn"}
   ```

## 相关实例

针对Intl开发，有以下相关实例可供参考：

- [`International`：国际化（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Internationalnation/International)
