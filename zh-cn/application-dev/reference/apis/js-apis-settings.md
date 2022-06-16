# 设置数据项名称

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


本模块提供设置数据项的访问功能相关接口的说明及示例。


## 导入模块

```typescript
import settings from '@ohos.settings';
```



## settings.getUriSync

getUriSync(name: string): string

获取数据项的URI。

**系统能力**：SystemCapability.Applictaions.settings.Core。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name | string | 是 | 数据项的名称。数据项名称分为以下两种：<br> <ul><li>数据库中已存在的数据项，包括：<br></li> <ul><li>亮度：settings.display.SCREEN_BRIGHTNESS_STATUS <br> </li>  <li> 时间格式：settings.date.TIME_FORMAT <br> </li></ul> <li>开发者自行添加的数据项。</li></ul>|

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 数据项的URI。 |

- 示例：
  ```typescript
   // 获取数据项的URI
   let urivar = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
  ```


## settings.getValueSync

getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string

获取数据项的值。

**系统能力**：SystemCapability.Applictaions.settings.Core。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | 是 | 数据管理辅助类。 |
  | name | string | 是 | 数据项的名称。数据项名称分为以下两种：<br> <ul><li>数据库中已存在的数据项，包括：<br></li> <ul><li>亮度：settings.display.SCREEN_BRIGHTNESS_STATUS <br> </li>  <li> 时间格式：settings.date.TIME_FORMAT <br> </li></ul> <li>开发者自行添加的数据项。</li></ul>|
  | defValue | string | 是 | 默认值。由开发者设置，当未从数据库中查询到该数据时，则返回该默认值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回数据项的值。 |

- 示例：
  ```typescript
  import featureAbility from '@ohos.ability.featureAbility';

  //获取数据项亮度的值（该数据项在数据库中已存在）
  let uri = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
  let helper = featureAbility.acquireDataAbilityHelper(uri);
  let value = settings.getValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
  ```


## settings.setValueSync

setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean

设置数据项的值。
如果数据库中已经存在该数据项，则setValueSync方法将更新该数据项的值；如果数据库中尚未存在该数据项，则setValueSync方法将向数据库中插入该数据项。

**需要权限**：ohos.permission.MODIFY_SETTINGS。

**系统能力**：SystemCapability.Applictaions.settings.Core。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataAbilityHelper | [DataAbilityHelper](js-apis-dataAbilityHelper.md) | 是 | 数据管理辅助类。 |
  | name | string | 是 | 数据项的名称。数据项名称分为以下两种：<br> <ul><li>数据库中已存在的数据项，包括：<br></li> <ul><li>亮度：settings.display.SCREEN_BRIGHTNESS_STATUS <br> </li>  <li> 时间格式：settings.date.TIME_FORMAT <br> </li></ul> <li>开发者自行添加的数据项。</li></ul>|
  | value | string | 是 | 数据项的具体数值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回设置数据项的值是否成功的结果。true表示设置成功，false则表示设置失败。 |

- 示例：
  ```typescript
  import featureAbility from '@ohos.ability.featureAbility';

  //更新数据项亮度的值（该数据项在数据库中已存在，故setValueSync方法将更新该数据项的值）
  let uri = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
  let helper = featureAbility.acquireDataAbilityHelper(uri);
  let ret = settings.setValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '100');
  ```
