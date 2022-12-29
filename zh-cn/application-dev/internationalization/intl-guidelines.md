# Intl开发指导

本模块提供基础的应用国际化能力，包括时间日期格式化、数字格式化、排序等，相关接口在ECMA 402标准中定义。更多接口和使用方式请见[Intl](../reference/apis/js-apis-intl.md)。

[I18N](i18n-guidelines.md)模块提供其他非ECMA 402定义的国际化接口，与本模块共同使用可提供完整地国际化支持能力。

## 设置区域信息

调用[Locale](../reference/apis/js-apis-intl.md#locale)的相关接口实现最大化区域信息或最小化区域信息。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | 实例化Locale对象。 |
| ohos.intl | constructor(locale:string,options?:LocaleOptions) | 基于locale参数及其选项实例化Locale对象。 |
| ohos.intl | toString():string | 将Locale信息转换为字符串。 |
| ohos.intl | maximize():Locale | 最大化区域信息。 |
| ohos.intl | minimize():Locale | 最小化区域信息。 |

### 开发步骤

1. 实例化Locale对象。

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
   var locale = "zh-CN";
   var options = {caseFirst: "false", calendar: "chinese", collation: "pinyin"};
   var localeObj = new intl.Locale(locale, options);
   ```

2. 获取Locale的字符串表示。

     调用toString方法来获取Locale对象的字符串表示，其中包括了语言、区域及其他选项信息。
     
   ```js
   var localeStr = localeObj.toString();
   ```

3. 最大化区域信息。

     调用maximize方法来最大化区域信息，即当缺少脚本与地区信息时，对其进行补全。
     
   ```js
   var maximizedLocale = localeObj.maximize();
   ```

4. 最小化区域信息。

     调用minimize方法来最小化区域信息，即当存在脚本与地区信息时，对其进行删除。
     
   ```js
   var minimizedLocale = localeObj.minimize();
   ```

## 格式化日期时间

调用日期时间格式化[DateTimeFormat](../reference/apis/js-apis-intl.md#datetimeformat)的接口，实现针对特定Locale的日期格式化以及时间段格式化功能。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | 创建日期时间格式化对象。 |
| ohos.intl | constructor(locale:string\|Array&lt;string&gt;,options?:DateTimeOptions) | 创建日期时间格式化对象，并设置提供的Locale和格式化相关属性。 |
| ohos.intl | format(date:Date):string | 依据DateTimeFormat对象的Locale及其他格式化属性，计算日期时间的格式化表示。 |
| ohos.intl | formatRange(startDate:Date,endDate:Date):string | 依据DateTimeFormat对象的Locale及其他格式化属性，计算时间段的格式化表示。 |
| ohos.intl | resolvedOptions():DateTimeOptions | 获取DateTimeFormat对象的相关属性。 |

### 开发步骤

1. 实例化日期时间格式化对象。

   一种方法是使用DateTimeFormat提供的默认构造函数，通过访问系统语言和地区设置，获取系统默认Locale，并将其作为DateTimeFormat对象内部的Locale（intl为导入的模块名）。

   ```js
   var dateTimeFormat = new intl.DateTimeFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建日期时间格式化对象。其中，格式化参数是可选的，完整的格式化参数列表见[DateTimeOptions](../reference/apis/js-apis-intl.md#datetimeoptions)。
   
   ```js
   var options = {dateStyle: "full", timeStyle: "full"};
   var dateTimeFormat = new intl.DateTimeFormat("zh-CN", options);
   ```

2. 格式化日期时间。

     使用DateTimeFormat的format方法对一个Date对象进行格式化，该方法会返回一个字符串作为格式化的结果。
     
   ```js
   var date = new Date();
   var formatResult = dateTimeFormat.format(date);
   ```

3. 格式化时间段。

     使用DateTimeFormat的formatRange方法对一个时间段进行格式化。该方法需要传入两个Date对象，分别表示时间段的起止日期，返回一个字符串作为格式化的结果。
     
   ```js
   var startDate = new Date(2021, 11, 17, 3, 24, 0);
   var endDate = new Date(2021, 11, 18, 3, 24, 0);
   var datefmt = new Intl.DateTimeFormat("en-GB");
   datefmt.formatRange(startDate, endDate);
   ```

4. 访问日期时间格式化对象的相关属性。

     DateTimeFormat的resolvedOptions方法会返回一个对象，该对象包含了DateTimeFormat对象的所有相关属性及其值。
     
   ```js
   var options = dateTimeFormat.resolvedOptions();
   ```

## 数字格式化

调用数字格式化[NumberFormat](../reference/apis/js-apis-intl.md#numberformat)的接口，实现针对特定Locale的数字格式化功能。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<SUP>8+</SUP> | 创建数字格式化对象。 |
| ohos.intl | constructor(locale:string\|Array&lt;string&gt;,options?:NumberOptions) | 创建数字格式化对象，并设置提供的locale和格式化相关属性。 |
| ohos.intl | format(number:number):string | 依据NumberFormat对象的Locale及其他格式化属性，计算数字的格式化表示。 |
| ohos.intl | resolvedOptions():NumberOptions | 获取NumberFormat对象的相关属性。 |

### 开发步骤

1. 实例化数字格式化对象。

   一种方法是使用NumberFormat提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   var numberFormat = new intl.NumberFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建数字格式化对象。其中，格式化参数是可选的，完整的格式化参数列表参见[NumberOptions](../reference/apis/js-apis-intl.md#numberoptions)。
   
   ```js
   var options = {compactDisplay: "short", notation: "compact"};
   var numberFormat = new intl.NumberFormat("zh-CN", options);
   ```

2. 数字格式化。

     使用NumberFormat的format方法对传入的数字进行格式化。该方法返回一个字符串作为格式化的结果。
     
   ```js
   var number = 1234.5678
   var formatResult = numberFormat.format(number);
   ```

3. 访问数字格式化对象的相关属性。

     NumberFormat的resolvedOptions方法会返回一个对象，该对象包含了NumberFormat对象的所有相关属性及其值。
     
   ```js
   var options = numberFormat.resolvedOptions();
   ```

## 字符串排序

不同区域的用户对于字符串排序具有不同的需求。调用字符串排序[Collator](../reference/apis/js-apis-intl.md#collator8)的接口，实现针对特定Locale的字符串排序功能。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | 创建排序对象。 |
| ohos.intl | constructor(locale:string\|Array&lt;string&gt;,options?:CollatorOptions)<sup>8+</sup> | 创建排序对象，并设置提供的locale和其他相关属性。 |
| ohos.intl | compare(first:string,second:string):number<sup>8+</sup> | 依据排序对象的Locale及其属性，计算两个字符串的比较结果。 |
| ohos.intl | resolvedOptions():CollatorOptions<sup>8+</sup> | 获取排序对象的相关属性。 |

### 开发步骤

1. 实例化排序对象。

   一种方法是使用Collator提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   var collator = new intl.Collator();
   ```

     另一种方法是使用开发者提供的Locale和其他相关参数来创建Collator对象，完整的参数列表参见[CollatorOptions](../reference/apis/js-apis-intl.md#collatoroptions9)。
   
   ```js
   var collator= new intl.Collator("zh-CN", {localeMatcher: "best fit", usage: "sort"});
   ```

2. 比较字符串。

     使用Collator的compare方法对传入的两个字符串进行比较。该方法返回一个数值作为比较的结果，返回-1表示第一个字符串小于第二个字符串，返回1表示第一个字符大于第二个字符串，返回0表示两个字符串相同。基于两个字符串的比较结果，开发者可以字符串集合进行排序。
     
   ```js
   var str1 = "first string";
   var str2 = "second string";
   var compareResult = collator.compare(str1, str2);
   ```

3. 访问排序对象的相关属性。

     Collator的resolvedOptions方法会返回一个对象，该对象包含了Collator对象的所有相关属性及其值。
     
   ```js
   var options = collator.resolvedOptions();
   ```

## 判定单复数类别

在一些语言的语法中，当数字后面存在名词时，名词需要根据数字的值采用不同的形式。调用单复数[PluralRules](../reference/apis/js-apis-intl.md#pluralrules8)的接口，可以实现针对特定Locale计算数字单复数类别的功能，从而选择合适的名词单复数表示。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | 创建单复数对象。 |
| ohos.intl | constructor(locale:string\|Array&lt;string&gt;,options?:PluralRulesOptions)<sup>8+</sup> | 创建单复数对象，并设置提供的locale和其他相关属性。 |
| ohos.intl | select(n:number):string<sup>8+</sup> | 依据单复数对象的Locale及其他格式化属性，计算数字的单复数类别。 |


### 开发步骤

1. 实例化单复数对象。

   一种方法是使用PluralRules提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。

   ```js
   var pluralRules = new intl.PluralRules();
   ```

     另一种方法是使用开发者提供的Locale和其他相关参数来创建单复数对象。完整的参数列表参见[PluralRulesOptions](../reference/apis/js-apis-intl.md#pluralrulesoptions9)。
   
   ```js
   var pluralRules = new intl.PluralRules("zh-CN", {localeMatcher: "best fit", type: "cardinal"});
   ```

2. 计算数字单复数类别。

     使用PluralRules的select方法计算传入数字的单复数类别。该方法返回一个字符串作为传入数字的类别，包括："zero", "one", "two", "few", "many", "other"六个类别。
     
   ```js
   var number = 1234.5678
   var categoryResult = plurals.select(number);
   ```

## 相对时间格式化

调用相对时间格式化[RelativeTimeFormat](../reference/apis/js-apis-intl.md#relativetimeformat8)的接口，实现针对特定Locale的相对时间格式化功能。

### 接口说明

| 模块 | 接口名称 | 描述 |
| -------- | -------- | -------- |
| ohos.intl | constructor()<sup>8+</sup> | 创建相对时间格式化对象。 |
| ohos.intl | constructor(locale:string\|Array&lt;string&gt;,options?:RelativeTimeFormatInputOptions)<sup>8+</sup> | 创建相对时间格式化对象，并设置提供的locale和格式化相关属性。 |
| ohos.intl | format(value:number,unit:string):string<sup>8+</sup> | 依据相对时间格式化对象的Locale及其他格式化属性，计算相对时间的格式化表示。 |
| ohos.intl | formatToParts(value:number,unit:string):Array&lt;object&gt;<sup>8+</sup> | 依据相对时间格式化对象的Locale及其他格式化属性，返回相对时间格式化表示的各个部分。 |
| ohos.intl | resolvedOptions():RelativeTimeFormatResolvedOptions<sup>8+</sup> | 获取相对时间格式化对象的相关属性。 |

### 开发步骤

1. 实例化相对时间格式化对象。

   一种方法是使用RelativeTimeFormat提供的默认构造函数，通过访问系统的语言和地区以获取系统默认Locale并进行设置（intl为导入的模块名）。
   
   ```js
   var relativeTimeFormat = new intl.RelativeTimeFormat();
   ```

     另一种方法是使用开发者提供的Locale和格式化参数来创建相对时间格式化对象。其中，格式化参数是可选的，完整的参数列表参见[ RelativeTimeFormatInputOptions](../reference/apis/js-apis-intl.md#relativetimeformatinputoptions9)。
   
   ```
   var relativeTimeFormat = new intl.RelativeTimeFormat("zh-CN", {numeric: "always", style: "long"});
   ```

2. 相对时间格式化。

     使用RelativeTimeFormat的format方法对相对时间进行格式化。方法接收一个表示相对时间长度的数值和表示单位的字符串，其中单位包括："year", "quarter", "month", "week", "day", "hour", "minute", "second"。方法返回一个字符串作为格式化的结果。
     
   ```js
   var number = 2;
   var unit = "year"
   var formatResult = relativeTimeFormat.format(number, unit);
   ```

3. 获取相对时间格式化结果的各个部分。

     获取相对时间格式化结果的各个部分，从而自定义格式化结果。
     
   ```js
   var number = 2;
   var unit = "year"
   var formatResult = relativeTimeFormat.formatToParts(number, unit);
   ```

4. 访问相对时间格式化对象的相关属性。

     RelativeTimeFormat的resolvedOptions方法会返回一个对象，该对象包含了RelativeTimeFormat对象的所有相关属性及其值，完整的属性列表参见[ RelativeTimeFormatResolvedOptions](../reference/apis/js-apis-intl.md#relativetimeformatresolvedoptions8)。
     
   ```js
   var options = numberFormat.resolvedOptions();
   ```

## 相关实例

针对Intl开发，有以下相关实例可供参考：

-[`International`：国际化（JS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/UI/International)

-[`International`：国际化（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/common/International)
