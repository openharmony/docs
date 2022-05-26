# ValuesBucket

**数据集（ValuesBucket）** 

>**说明：** 
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { ValueType } from './@ohos.data.ValuesBucket';
import { ValuesBucket } from './@ohos.data.ValuesBucket';
```

## ValueType

用于表示允许的数据字段类型。

| 名称      | 说明                 |
| --------- | -------------------- |
| *number*  | 表示值类型为数字。   |
| *string*  | 表示值类型为字符串。 |
| *boolean* | 表示值类型为布尔值。 |

## ValuesBucket

用于存储键值对。

| 名称          | 参数类型                        | 必填 | 说明             |
| ------------- | ------------------------------- | ---- | ---------------- |
| [key: string] | ValueType \| Uint8Array \| null | 是   | 用于存储键值对。 |
