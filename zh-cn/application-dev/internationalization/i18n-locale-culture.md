# 区域标识与文化习惯划分


## 功能介绍

广义地讲，区域标识是指通过数字、字母、符号或组合，作为唯一标识识别特定地理区域。

在国际化中，区域标识是对用户群体的抽象，包括用户语言、脚本（使用的文字系统，如中文可用简体字或繁体字）、所在国家或地区，以及其他一些文化习惯（如历法、数字系统）等。区域标识是应用实现国际化能力的基础，开发过程中需通过目标区域标识对象控制和实现国际化行为。


## 实现原理

区域标识由语言、脚本、国家地区和扩展参数四部分组成。其中，语言是必填内容，详细说明可参考表1；支持的扩展参数参考表2，不同语言对应的数字系统参考表3，表中未列出的语言均使用阿拉伯数字系统。

**表1** 区域标识组成

| 组成成分 | 说明 | 
| -------- | -------- |
| 语言 | 表示用户使用的语言，由2~3个小写英文字母组成。例如，中文使用”zh”表示。<br/>更多语言代码列表请参考ISO-639标准。 | 
| 脚本 | 表示用户使用的字符集，由首字母大写的4个英文字母组成。例如，简体使用”Hans”表示。<br/>更多脚本代码列表请参考ISO-15924标准。 | 
| 国家地区 | 表示用户所在的国家或地区，使用2个大写英文字母表示。例如，中国使用”CN”表示。<br/>更多的国家地区代码列表请参考ISO-3166标准。 | 
| 扩展参数 | 表示用户其他的特征，包括历法、字符串排序、数字系统、小时周期，由小写字母u开头，每一个扩展参数由key和value组成，使用中划线拼接。例如，农历拼音排序使用”u-ca-chinese-co-pinyin”。<br/>支持的扩展参数请参考表2，更多的扩展参数取值请参考BCP 47扩展。 | 

**表2** 扩展参数

| 参数 | 说明 | 
| -------- | -------- |
| ca | 表示用户使用的历法系统。例如，农历使用”chinese”表示。 | 
| co | 表示用户使用的字符串排序规则，包括。例如，按照拼音排序使用”pinyin”表示。 | 
| hc | 表示用户使用的小时周期。例如，0~11小时周期使用”h11”表示。 | 
| nu | 表示用户使用的数字系统。例如，阿拉伯数字系统使用”arab”表示，具体请参考表3。 | 
| kn | 表示用户排序时对数字的处理方式。<br/>- “true”表示将数字作为整体进行数值比较。<br/>- “false”表示将数字作为普通字符比较。 | 
| kf | 表示用户排序时是否考虑字符的大小写。<br/>- “upper”表示将大写字母排序在前。<br/>- “lower”表示将小写字母排序在前。<br/>- “false”表示使用当前区域的默认值。 | 

**表3** 语言和本地数字系统

| 语言 | 本地数字系统 | 
| -------- | -------- |
| ar | arab | 
| as | beng | 
| bn | beng | 
| fa | arabext | 
| mr | deva | 
| my | mymr | 
| ne | deva | 
| ur | latn | 
| 其他语言 | arab | 


## 开发步骤

以时间日期格式化为例，[DateTimeFormat](../reference/apis-localization-kit/js-apis-intl.md#datetimeformat)类的详细说明请参考API文档。

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建区域标识对象。如下给出了三种方法。
   - 按照实现原理中给出的格式，将区域识别的字符串传入Locale构造函数，创建区域识别对象。
   - 在LocaleOptions中配置区域特性，然后使用区域标识字符串和LocaleOptions创建区域识别对象。通过LocaleOptions对象设置的属性会自动覆盖字符串中对应的属性值。
   - 使用默认的Locale构造函数，创建区域识别对象。使用默认Locale构造函数创建的区域对象表示当前系统区域。

   ```ts
   let zhLocale: intl.Locale = new intl.Locale('zh-Hans-CN-u-nu-latn');

   // 方法二：通过区域标识字符串和LocaleOptions对象创建区域标识对象
   let enLocale: intl.Locale = new intl.Locale('en', { numberingSystem: 'latn' });

   // 方法三：通过默认Locale函数创建系统区域标识对象
   let systemLocale: intl.Locale = new intl.Locale();
   ```

3. 格式化时间日期。
   创建区域识别对象后，将其传入时间日期格式类的构造函数，创建指定区域标识的时间日期格式化类，并实现格式化。与步骤2对应，步骤3呈现了三种实现时间日期格式化的方法。

   ```ts
   let date: Date = new Date(2023, 9, 15);

   // 方法一
   let zhDateTimeFmt: intl.DateTimeFormat = new intl.DateTimeFormat(zhLocale.toString());
   let formattedResult: string = zhDateTimeFmt.format(date); // formattedResult = '2023/10/15'

   // 方法二
   let enDateTimeFmt: intl.DateTimeFormat = new intl.DateTimeFormat(enLocale.toString());
   formattedResult = enDateTimeFmt.format(date); // formattedResult = '10/15/23'

   // 方法三
   let systemDateTimeFmt: intl.DateTimeFormat = new intl.DateTimeFormat(systemLocale.toString());
   formattedResult = systemDateTimeFmt.format(date); // formattedResult = '2023/10/15' （具体显示效果依赖于当前系统环境）
   ```
