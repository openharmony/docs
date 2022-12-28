# @ohos.data.ValuesBucket

The **ValueBucket** module holds data in key-value (KV) pairs. You can use it to insert data into a database.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import { ValueType } from '@ohos.data.ValuesBucket';
import { ValuesBucket } from '@ohos.data.ValuesBucket';
```

## ValueType

Enumerates the value types allowed by the database.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | The value is a number.  |
| string  | The value is a string.|
| boolean | The value is of Boolean type.|

## ValuesBucket

Defines the types of the key and value in a KV pair.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Key Type         | Value Type                                     | 
| ------------- | --------------------------------------------- | 
|  string | [ValueType](#valuetype)\| Uint8Array \| null | 
