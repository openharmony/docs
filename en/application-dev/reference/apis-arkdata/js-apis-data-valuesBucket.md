# @ohos.data.ValuesBucket (Data Set)

The **ValuesBucket** module defines a data set in key-value (KV) format for inserting data into an RDB store.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import { ValueType, ValuesBucket } from '@kit.ArkData';
```

## ValueType

type ValueType = number | string | boolean

Enumerates the value types allowed by the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.|
| boolean | The value is **true** or **false**.|

## ValuesBucket

type ValuesBucket = Record<string, ValueType | Uint8Array | null>

Defines the types of the key and value in a KV pair. This type is not multi-thread safe. If a **ValuesBucket** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type         | Description                                     |
| ------------- | --------------------------------------------- |
| Record<string, [ValueType](#valuetype) \| Uint8Array \| null> | Types of the key and value in a KV pair. The key type is string, and the value type is [ValueType](#valuetype), Uint8Array, or null. |
