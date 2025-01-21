# AutoFillType (系统接口)

表示提供自动填充类型的枚举。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。
> 本模块接口为系统接口。

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillType

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称           | 值  | 说明                               |
| -------------- | --- | --------------------------------- |
| UNSPECIFIED      | 0   | 未定义的类型。                         |
| PASSWORD      | 1   | 密码类型。                     |
| USER_NAME     | 2   | 用户名类型。                     |
| NEW_PASSWORD     | 3   | 新密码类型。                     |
| FULL_STREET_ADDRESS<sup>12+</sup>        | 4    | 详细地址类型。 |
| HOUSE_NUMBER<sup>12+</sup>               | 5    | 门牌号类型。 |
| DISTRICT_ADDRESS<sup>12+</sup>           | 6    | 区/县类型。 |
| CITY_ADDRESS<sup>12+</sup>               | 7    | 市类型。 |
| PROVINCE_ADDRESS<sup>12+</sup>           | 8    | 省类型。 |
| COUNTRY_ADDRESS<sup>12+</sup>            | 9    | 国家类型。 |
| PERSON_FULL_NAME<sup>12+</sup>           | 10   | 姓名类型。 |
| PERSON_LAST_NAME<sup>12+</sup>           | 11   | 姓氏类型。 |
| PERSON_FIRST_NAME<sup>12+</sup>          | 12   | 名字类型。 |
| PHONE_NUMBER<sup>12+</sup>               | 13   | 手机号类型。 |
| PHONE_COUNTRY_CODE<sup>12+</sup>         | 14   | 国家和地区代码类型。 |
| FULL_PHONE_NUMBER<sup>12+</sup>          | 15   | 包含国家和地区代码的手机号类型。 |
| EMAIL_ADDRESS<sup>12+</sup>              | 16   | 邮箱地址类型。 |
| BANK_CARD_NUMBER<sup>12+</sup>           | 17   | 银行卡号类型。 |
| ID_CARD_NUMBER<sup>12+</sup>             | 18   | 身份证号类型。 |
| NICKNAME<sup>12+</sup>                   | 24   | 昵称类型。 |
| DETAIL_INFO_WITHOUT_STREET<sup>12+</sup> | 25   | 无街道地址类型。 |
| FORMAT_ADDRESS<sup>12+</sup>             | 26   | 标准地址类型。 |
| PASSPORT_NUMBER<sup>16+</sup>            | 27   | 护照号。 |
| VALIDITY<sup>16+</sup>                   | 28   | 护照有效期。 |
| ISSUE_AT<sup>16+</sup>                   | 29   | 护照签发地。 |
| ORGANIZATION<sup>16+</sup>               | 30   | 发票抬头名称。 |
| TAX_ID<sup>16+</sup>                     | 31   | 税号。 |
| ADDRESS_CITY_AND_STATE<sup>16+</sup>     | 32   | 所在地区。 |
| FLIGHT_NUMBER<sup>16+</sup>              | 33   | 航班号。 |
| LICENSE_NUMBER<sup>16+</sup>             | 34   | 驾驶证号。 |
| LICENSE_FILE_NUMBER<sup>16+</sup>        | 35   | 驾驶证档案编号。 |
| LICENSE_PLATE<sup>16+</sup>              | 36   | 车牌号。 |
| ENGINE_NUMBER<sup>16+</sup>              | 37   | 行驶证发动机号。 |
| LICENSE_CHASSIS_NUMBER<sup>16+</sup>     | 38   | 车辆识别号。 |
