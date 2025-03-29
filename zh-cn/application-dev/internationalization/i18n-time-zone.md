# 时区

## 使用场景

全球各国家和地区的经度不同，地方时间也有所不同，因此划分了不同的时区。例如英国采用0时区，中国采用东8时区，中国时间要比英国快8个小时，中国北京中午12:00是英国伦敦凌晨4点。时区模块主要用于获取时区列表，同时，应用可基于获取的时区列表实现自身业务逻辑，如双时钟应用。

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

   // 获取城市Id对应的时区对象
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

   // 系统支持的时区Id列表
   let availableIDs: Array<string> = i18n.TimeZone.getAvailableIDs(); // availableIDs = ['America/Adak', 'Asia/Hovd', ...]

   // 系统支持的时区城市Id列表
   let cityIDs: Array<string> = i18n.TimeZone.getAvailableZoneCityIDs(); // cityIDs = ['Auckland', 'Magadan', ...]

   // 遍历时区城市Id列表
   let timezoneList: Array<object> = []; // 呈现给用户的时区列表

   class Item {
     cityDisplayName: string = "";
     timezoneId: string = "";
     offset: string = "";
     cityId: string = ""
   }

   for (let i = 0; i < cityIDs.length; i++) {
     let cityId: string = cityIDs[i];
     let timezone: i18n.TimeZone = i18n.TimeZone.getTimezoneFromCity(cityId); // 城市Id对应的时区对象
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