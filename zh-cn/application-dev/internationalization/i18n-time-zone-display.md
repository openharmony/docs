# 本地化时区名称

## 使用场景

多语言环境下，不同地区用户对时区的称呼可能存在差异，例如在中文环境下，中部时区称为“中部时区”，在英文环境下，中部时区称为“Central Time Zone”。为了确保时区名称符合当地人语言使用习惯，需要本地化处理。

## 开发步骤

接口具体使用方法和说明请参考[getDisplayName](../reference/apis-localization-kit/js-apis-i18n.md#getdisplayname8)的API文档。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. 本地化时区名称，以美洲/圣保罗为例。
   ```ts
   let timezone: i18n.TimeZone = i18n.getTimeZone('America/Sao_Paulo');
   let timeZoneName: string = timezone.getDisplayName('zh-Hans', true); // timeZoneName = '巴西利亚标准时间'
   ```