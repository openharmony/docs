# @ohos.settings (设置数据项名称)(系统接口)

本模块提供访问设置数据项的能力。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.settings (设置数据项名称)](./js-apis-settings.md)。

## 导入模块

```js
import settings from '@ohos.settings';
```

## domainName

提供查询的域名

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| USER_SECURITY<sup>11+</sup>      | string | 是   | 是   | 用户安全属性域                                          |

## settings.setValue<sup>(deprecated)</sup>

setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void

将数据项名称及数据项的值保存到数据库中。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[setValue()](js-apis-settings.md#settingssetvalue10)。

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在FA模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value             | object                                                       | 是   | 数据项值。取值范围随业务变动。                               |
| callback          | AsyncCallback\<boolean>                                      | 是   | 回调函数。返回true表示操作成功，否则操作失败。               |


## settings.setValue<sup>(deprecated)</sup>

setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>

将数据项名称及数据项的值保存到数据库中。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[setValue()](js-apis-settings.md#settingssetvalue10-1)。

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在FA模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value             | object                                                       | 是   | 数据项值。取值范围随业务变动。                               |

**返回值**：

| 类型              | 说明                                               |
| ----------------- | -------------------------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示操作成功，否则返回false。 |

