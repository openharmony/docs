# Value Bucket

The **ValueBucket** holds data in key-value (KV) pairs. You can use it to insert data into a database.

>**Note**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { ValueType } from '@ohos.data.ValuesBucket';
import { ValuesBucket } from '@ohos.data.ValuesBucket';
```

## ValueType

Enumerates the value types allowed by the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Name   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.|
| boolean | The value is of Boolean type.|

## ValuesBucket

Holds a set of KV pairs.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Name         | Type                                     | Mandatory| Description                                                        |
| ------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| [key: string] | [ValueType](#valuetype)\| Uint8Array \| null | Yes  | KV pairs in a **ValuesBucket**. The key is of the string type. The value can be a number, string, Boolean value, Unit8Array, or **null**.|
