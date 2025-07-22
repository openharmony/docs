# 时区

## 使用场景

全球各国家和地区的经度不同，地方时间也有所不同，因此划分了不同的时区。例如英国采用0时区，中国采用东8时区，中国时间要比英国快8个小时，中国北京中午12:00是英国伦敦凌晨4点。时区模块可用于获取时区列表，应用可基于时区列表实现业务逻辑，如双时钟应用。<br/>从API version 20开始，时区模块还可用于获取时区跳变时间点、偏移量等，时区的跳变逻辑参考[夏令时跳变](./i18n-dst-transition.md)。

## 接口说明

时区模块关键接口如下表所示，具体API说明详见[国际化-I18n](../reference/apis-localization-kit/js-apis-i18n.md)。

| 接口名 | 描述 |
| -------- | -------- |
| getTimeZone(zoneID?: string): TimeZone | 获取时区ID对应的时区对象。 |
| getID(): string | 获取时区对象的ID。 |
| getDisplayName(locale?: string, isDST?: boolean): string | 获取时区对象名称在指定语言下的翻译。 |
| getRawOffset(): number | 获取时区的固定偏移量。 |
| getOffset(date?: number): number | 获取某一时刻时区对象所表示时区的偏移量。 |
| getAvailableIDs(): Array&lt;string&gt; | 获取系统支持的时区ID列表。 |
| getAvailableZoneCityIDs(): Array&lt;string&gt; | 获取系统支持的时区城市ID列表 |
| getCityDisplayName(cityID: string, locale: string): string | 获取时区城市名称在指定语言下的翻译。 |
| getTimezoneFromCity(cityID: string): TimeZone | 根据城市ID创建对应的时区对象。 |
| getTimezonesByLocation(longitude: number, latitude: number): Array&lt;TimeZone&gt; | 根据地理坐标获取所在时区对象的数组。 |
| getZoneRules(): ZoneRules | 获取时区跳变规则。 |
| nextTransition(date?: number): ZoneOffsetTransition | 获取指定时间的下一个时区跳变对象。 |
| getMilliseconds(): number | 获取时区跳变点的时间戳。 |
| getOffsetAfter(): number | 获取时区跳变后的偏移量。 |
| getOffsetBefore(): number | 获取时区跳变前的偏移量。 |

## 开发步骤

### 时区相关功能

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 开发实例，包括获取特定时区、计算固定和实际时区偏移量、获取和遍历时区列表等。
   ```ts
   // 获取巴西时区
   let timezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo'); // 传入特定时区，创建时区类
   let timezoneId: string = timezone.getID(); // timezoneId = 'America/Sao_Paulo'

   // 获取城市ID对应的时区对象
   let aucklandTimezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity('Auckland');
   timezoneId = aucklandTimezone.getID(); // timezoneId = 'Pacific/Auckland'

   // 时区的本地化名称
   let timeZoneName: string = timezone.getDisplayName('zh-Hans', true); // timeZoneName = '巴西利亚标准时间'

   // 本地化城市名称
   let cityDisplayName: string = i18n.TimeZone.getCityDisplayName('Auckland', 'zh-Hans'); // cityDisplayName = '奥克兰 (新西兰)'

   // 时区的固定偏移量
   let rawOffset: number = timezone.getRawOffset(); // rawOffset = -10800000

   // 时区的实际偏移量（固定偏移量+夏令时）
   let offset: number = timezone.getOffset(1234567890); // offset = -10800000

   // 系统支持的时区ID列表
   let availableIDs: Array<string> = i18n.TimeZone.getAvailableIDs(); // availableIDs = ['America/Adak', 'Asia/Hovd', ...]

   // 系统支持的时区城市ID列表
   let cityIDs: Array<string> = i18n.TimeZone.getAvailableZoneCityIDs(); // cityIDs = ['Auckland', 'Magadan', ...]

   // 遍历时区城市ID列表
   let timezoneList: Array<object> = []; // 呈现给用户的时区列表

   class Item {
     cityDisplayName: string = "";
     timezoneId: string = "";
     offset: string = "";
     cityId: string = ""
   }

   for (let i = 0; i < cityIDs.length; i++) {
     let cityId: string = cityIDs[i];
     let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity(cityId); // 城市ID对应的时区对象
     let cityDisplayName: string = i18n.TimeZone.getCityDisplayName(cityId, 'zh-CN'); // 本地化城市名称
     let timestamp: number = (new Date()).getTime();
     let item: Item = {
        cityDisplayName: cityDisplayName,
        timezoneId: timezone.getID(),
        offset: 'GMT' + (timezone.getOffset(timestamp) / 3600 * 1000),
        cityId: cityId
     };
     timezoneList.push(item);
   }

   // 指定地理坐标所在的时区对象数组
   let timezoneArray: Array<i18n.TimeZone> = i18n.TimeZone.getTimezonesByLocation(-43.1, -22.5);

   // 获取指定时间的下一个时间跳变点
   let tijuanaTzId: string = 'America/Tijuana';
   let tijuanaTimeZone: i18n.TimeZone = i18n.getTimeZone(tijuanaTzId); // 获取蒂华纳时区
   let zoneRules: i18n.ZoneRules = tijuanaTimeZone.getZoneRules(); // 获取蒂华纳时区的时间跳变规则
   let someTime = new Date(2025, 4, 13);
   let zoneOffsetTrans: i18n.ZoneOffsetTransition = zoneRules.nextTransition(someTime.getTime());
   zoneOffsetTrans.getMilliseconds(); // 跳变点的时间戳: 1762074000000
   zoneOffsetTrans.getOffsetAfter(); // 跳变后的偏移量: -28800000
   zoneOffsetTrans.getOffsetBefore(); // 跳变前的偏移量: -25200000
   // 将跳变点时间格式化
   let dateTimeFormat: Intl.DateTimeFormat = new Intl.DateTimeFormat('en-US', {
     timeZone: tijuanaTzId,
     dateStyle: 'long',
     timeStyle: 'long',
     hour12: false
   });
   let dateFormat: string =
     dateTimeFormat.format(new Date(zoneOffsetTrans.getMilliseconds())); // November 2, 2025, 1:00:00 PST
   ```

### 双时钟应用

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 选择时区列表中的时区放入应用偏好时区列表中。
   ```ts
   let pauloTimezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo');
   let defaultTimezone: i18n.TimeZone = i18n.getTimeZone();
   let appPreferredTimeZoneList: Array<i18n.TimeZone> = []; // 应用偏好时区列表
   appPreferredTimeZoneList.push(pauloTimezone);
   appPreferredTimeZoneList.push(defaultTimezone);
   ```

3. 遍历应用偏好时区列表，获取各时区时间。
   ```ts
   let locale: string = i18n.System.getSystemLocale();
   for (let i = 0; i < appPreferredTimeZoneList.length; i++) {
     let timezone: string = appPreferredTimeZoneList[i].getID();
     let calendar: i18n.Calendar = i18n.getCalendar(locale);
     calendar.setTimeZone(timezone); // 设置日历对象的时区
     // 获取年月日时分秒
     let year: number = calendar.get('year');
     let month: number = calendar.get('month');
     let day: number = calendar.get('date');
     let hour: number = calendar.get('hour');
     let minute: number = calendar.get('minute');
     let second: number = calendar.get('second');
   }
   ```