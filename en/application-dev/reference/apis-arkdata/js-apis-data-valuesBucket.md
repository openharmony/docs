# @ohos.data.ValuesBucket (Data Set)

**ValuesBucket** is a dataset in the form of key-value (KV) pairs that can be inserted in the database.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import { ValueType, ValuesBucket } from '@kit.ArkData';
```

## ValueType

type ValueType = number | string | boolean

Defines the value types allowed in a **ValuesBucket** instance.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.|
| boolean | The value is **true** or **false**.|

## ValuesBucket

type ValuesBucket = Record<string, ValueType | Uint8Array | null>

Defines the types of the key and value in a KV pair. This type is not multi-thread safe. If a **ValuesBucket** instance is operated by multiple threads at the same time in an application, use a lock for it.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type         | Description                                     |
| ------------- | --------------------------------------------- |
| Record<string, [ValueType](#valuetype) \| Uint8Array \| null> | Types of the key and value in a KV pair. The key type is string, and the value type can be [ValueType](#valuetype), Uint8Array, or null.|
