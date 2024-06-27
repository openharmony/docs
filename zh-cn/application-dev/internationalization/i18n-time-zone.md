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
   let timezone = i18n.getTimeZone("America/Sao_Paulo"); // 传入特定时区，创建时区类
   let timezoneId = timezone.getID();// America/Sao_Paulo
   
   // 获取城市Id对应的时区对象
   let aucklandTimezone = i18n.TimeZone.getTimezoneFromCity("Auckland");
   let aucklandTzId = aucklandTimezone.getID(); // Pacific/Auckland
   
   // 时区的本地化名称
   let timeZoneName = timezone.getDisplayName("zh-Hans", true); // 巴西利亚标准时间
   
   // 本地化城市名称
   let cityDisplayName = i18n.TimeZone.getCityDisplayName("Auckland", "zh-Hans") // 奥克兰 (新西兰)
   
   // 时区的固定偏移量
   let rawOffset = timezone.getRawOffset(); // -10800000
   
   // 时区的实际偏移量(固定偏移量+夏令时)
   let offset = timezone.getOffset(1234567890);// -10800000
   
   // 系统支持的时区Id列表
   let ids = i18n.TimeZone.getAvailableIDs(); // ["America/Adak", "Asia/Hovd", "America/Sao_Paulo", "Asia/Jerusalem", "Europe/London",...]
   
   // 系统支持的时区城市Id列表
   let cityIdArray = i18n.TimeZone.getAvailableZoneCityIDs();  // ["Auckland", "Magadan", "Lord Howe Island",...]
   // 遍历时区城市Id列表
   let timezoneList: Array<object> = [];  // 呈现给用户的时区列表
   class Item {
       cityDisplayName : string = "";
       timezoneId : string = "";
       offset : string = "";
       cityId : string = ""
   }
   for (let i =0 ; i < cityIdArray.length ; i++) {
       let cityId = cityIdArray[i];
       let timezone = i18n.TimeZone.getTimezoneFromCity(cityId); // 城市Id对应的时区对象
       let cityDisplayName = i18n.TimeZone.getCityDisplayName(cityId, "zh-CN"); // 本地化城市名称
       let timestamp = (new Date()).getTime()
       let item : Item = {
           cityDisplayName : cityDisplayName,
           timezoneId : timezone.getID(),
           offset : 'GMT'+ (timezone.getOffset(timestamp) / 3600*1000),
           cityId : cityId 
       }
       timezoneList.push(item);
    }
   
   // 指定地理坐标所在的时区对象数组
   let timezoneArray = i18n.TimeZone.getTimezonesByLocation(-43.1, -22.5)
   for (let i =0;i < timezoneArray.length; i++) {
       let tzId = timezoneArray[i].getID(); // America/Sao_Paulo
   }
   ```

### 双时钟应用

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 选择时区列表中的时区放入应用偏好时区列表中。
   ```ts
   let timezone1 = i18n.getTimeZone("America/Sao_Paulo");
   let timezone2 = i18n.getTimeZone();
   let appPreferredTimeZoneList: Array<i18n.TimeZone> = [] // 应用偏好时区列表
   appPreferredTimeZoneList.push(timezone1);
   appPreferredTimeZoneList.push(timezone2);
   ```

3. 遍历应用偏好时区列表，获取各时区时间。
   ```ts
   let locale = i18n.System.getSystemLocale();
   for (let i = 0 ; i < appPreferredTimeZoneList.length ; i++) {
       let timezone = appPreferredTimeZoneList[i].getID();
       let calendar = i18n.getCalendar(locale);
       calendar.setTimeZone(timezone); //设置日历对象的时区
       //获取年月日时分秒
       let year = calendar.get("year"); 
       let month = calendar.get("month");
       let day = calendar.get("date");
       let hour = calendar.get("hour");
       let minute = calendar.get("minute");
       let second = calendar.get("second");
   }
   ```