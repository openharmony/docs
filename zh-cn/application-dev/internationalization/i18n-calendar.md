# 设置日历和历法

## 使用场景

不同地区的用户使用不同的历法，大多数地区使用公历，也有些地区的用户使用其他历法，例如农历、伊斯兰历或希伯来历。日历上的时间和日期根据历法计算得到，并会随时区和夏令时的变化而调整。因此，用户需要设置符合本地习惯的历法。国际化提供了[Calendar](../reference/apis-localization-kit/js-apis-i18n.md#calendar8)类，可以设置历法、日期、时区、一周的起始日期和一年中第一周的最小天数。此外，还可以判断具体某一天在日历中是否为周末以及计算相差天数。在应用开发过程中，可以根据业务需求选择使用不同功能。

## 开发步骤

以查看公历日期对应的农历日期为例，说明如何使用[Calendar](../reference/apis-localization-kit/js-apis-i18n.md#calendar8)类接口。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 公历相关用法。
   ```ts
   let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans', 'gregory');
   // 设置日历对象的时间日期为2022.06.13 08:00:00
   calendar.setTime(new Date(2022, 5, 13, 8, 0, 0));
   calendar.setTime(10540800000);

   // 设置日历对象的时间日期为2022.06.13 08:00:00
   calendar.set(2022, 5, 13, 8, 0, 0);

   // 设置日历对象的时区
   calendar.setTimeZone('Asia/Shanghai');

   // 获取日历对象的时区
   let timezone: string = calendar.getTimeZone(); // timezone = 'Asia/Shanghai'

   // 获取日历对象的一周起始日
   let firstDayOfWeek: number = calendar.getFirstDayOfWeek(); // firstDayOfWeek = 1

   // 设置每一周的起始日
   calendar.setFirstDayOfWeek(1);

   // 获取一年中第一周的最小天数
   let minimalDaysInFirstWeek: number = calendar.getMinimalDaysInFirstWeek(); // minimalDaysInFirstWeek = 1

   // 设置一年中第一周的最小天数
   calendar.setMinimalDaysInFirstWeek(3);

   // 获取日历对象中与field相关联的值
   let year: number = calendar.get('year'); // year = 2022

   // 获取日历对象本地化名称
   let calendarName: string = calendar.getDisplayName('zh-Hans'); // calendarName = '公历'

   // 判断指定的日期在日历中是否为周末
   let isWeekend: boolean = calendar.isWeekend(new Date(2023, 9, 15)); // isWeekend = true

   // 在日历的给定字段进行加减操作
   calendar.set(2023, 10, 15);
   calendar.add('date', 2);
   let day: number = calendar.get('date'); // day = 17

   // 比较日历和指定日期相差的天数
   let daysDifference: number = calendar.compareDays(new Date(2023, 10, 15)); // daysDifference = -3
   ```

3. 获取公历日期对应的农历日期。
   ```ts
   let calendar: i18n.Calendar = i18n.getCalendar('zh-Hans', 'chinese');
   // 将公历日期设置到calendar对象，时间日期为2023.07.25 08:00:00
   calendar.setTime(new Date(2023, 6, 25, 8, 0, 0));
   // 获取农历年月日
   let year: number = calendar.get('year'); // year = 40，指干支纪年40，范围1-60
   let month: number = calendar.get('month'); // month = 5，指6月
   let day: number = calendar.get('date'); // day = 8，指8日
   ```

**表1** 支持的历法

| 类型 | 中文名称 | 
| -------- | -------- |
| buddhist | 佛历 | 
| chinese | 农历 | 
| coptic | 科普特历 | 
| ethiopic | 埃塞俄比亚历 | 
| hebrew | 希伯来历 | 
| gregory | 公历 | 
| indian | 印度历 | 
| islamic_civil | 伊斯兰希吉来历 | 
| islamic_tbla | 伊斯兰天文历 | 
| islamic_umalqura | 伊斯兰历（乌姆库拉） | 
| japanese | 日本历 | 
| persian | 波斯历 | 
<!--RP1--><!--RP1End-->