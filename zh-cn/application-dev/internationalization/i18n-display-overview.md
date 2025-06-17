# 概述
本地化表示是指将语言、地区、脚本、时区、历法和日期等区域性元素按照本地的语言习惯显示。

本模块提供以下三种方式进行本地化表示：
1. [本地化名称](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/DisplayNames)：采用Intl.Displaynames接口本地化表示语言、地区、脚本、货币、历法和时间字段（如年、月、日等）。
2. [本地化语言与地区名称](i18n-language-region-display.md)：采用i18n.System.getDisplayLanguage和i18n.System.getDisplayCountry接口实现本地化表示语言和地区。
3. [本地化时区名称](i18n-time-zone-display.md)：采用i18n.TimeZone接口实现本地化表示时区名称。
