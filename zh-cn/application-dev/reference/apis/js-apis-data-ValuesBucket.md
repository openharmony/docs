# ValuesBucket

**数据集(ValuesBucket)** 是开发者向数据库插入的数据集合，数据集以键-值对的形式进行传输。

>**说明：**
>
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { ValueType } from '@ohos.data.ValuesBucket';
import { ValuesBucket } from '@ohos.data.ValuesBucket';
```

## ValueType

该类型用于表示数据库允许的数据字段类型。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

| 名称    | 说明                 |
| ------- | -------------------- |
| number  | 表示字段类型为数字。   |
| string  | 表示字段类型为字符串。 |
| boolean | 表示字段类型为布尔值。 |

## ValuesBucket

该类型用于存储一系列键值对。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

| 名称          | 参数类型                                      | 必填 | 说明                                                         |
| ------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| [key: string] | [ValueType](#valuetype)\| Uint8Array \| null | 是   | 键的类型为字符串型；值的类型可以为数字、字符串、布尔值、无符号整型8位数组、空值。 |

