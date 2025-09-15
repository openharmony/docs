# Class (RdbPredicates)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Defines the predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false. Multiple predicates statements can be concatenated by using **and()** by default. **RdbPredicates** cannot be passed across threads using Sendable.

## Module to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## constructor

constructor(name: string)

A constructor used to create an **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Database table name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
```

## inDevices

inDevices(devices: Array&lt;string&gt;): RdbPredicates

Creates an **RdbPredicates** object to specify the remote devices to connect on the network during distributed database sync.

> **NOTE**
>
> **devices** can be obtained by using [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).
When calling **sync()**, you need to call **inDevices** to specify the devices. If **inDevices** is not used, data will be synced to all devices on the network by default.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type               | Mandatory| Description                      |
| ------- | ------------------- | ---- | -------------------------- |
| devices | Array&lt;string&gt; | Yes  | IDs of the remote devices to connect.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inDevices(deviceIds);
```

## inAllDevices

inAllDevices(): RdbPredicates

Creates an **RdbPredicates** object to specify all remote devices on the network to connect during distributed database sync.


**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inAllDevices();
```

## equalTo

equalTo(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records in the NAME column where the value is Lisa.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
```


## notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are not equal to the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records in the NAME column where the value is not Lisa.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notEqualTo("NAME", "Lisa");
```


## beginWrap

beginWrap(): RdbPredicates

Creates an **RdbPredicates** object to add a left parenthesis.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object created.|

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .beginWrap()
  .equalTo("AGE", 18)
  .or()
  .equalTo("SALARY", 200.5)
  .endWrap();
```

## endWrap

endWrap(): RdbPredicates

Creates an **RdbPredicates** object to add a right parenthesis.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object created.|

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .beginWrap()
  .equalTo("AGE", 18)
  .or()
  .equalTo("SALARY", 200.5)
  .endWrap();
```

## or

or(): RdbPredicates

Creates an **RdbPredicates** object to add the OR condition.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object created.|

**Example**:

```ts
// Find all records in the NAME column where the value is Lisa or Rose.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .or()
  .equalTo("NAME", "Rose");
```

## and

and(): RdbPredicates

Creates an **RdbPredicates** object to add the AND condition.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object created.|

**Example**:

```ts
// Find the records in the EMPLOYEE table where the NAME column is Lisa and the SALARY column is 200.5.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
  .and()
  .equalTo("SALARY", 200.5);
```

## contains

contains(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that contain the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that contain the string 'os' in the NAME column, for example, Rose.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.contains("NAME", "os");
```

## beginsWith

beginsWith(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that begin with the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that start with "Li" in the NAME column, for example, Lisa.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.beginsWith("NAME", "Li");
```

## endsWith

endsWith(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that end with the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that end with "se" in the NAME column, for example, Rose.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.endsWith("NAME", "se");
```

## isNull

isNull(field: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are **null**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNull("NAME");
```

## isNotNull

isNotNull(field: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are not **null**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNotNull("NAME");
```

## like

like(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are similar to the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Condition for fuzzy match. Generally, this parameter is used together with a wildcard: **%** represents any character of any length, and **_** represents a single character.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are similar to "os" in the NAME column, for example, Rose.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.like("NAME", "%os%");
```

## glob

glob(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that match the given string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| field  | string | Yes  | Column name in the database table.                                          |
| value  | string | Yes  | Value to match.<br>Wildcards are supported. ***** indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find the strings that match "?h*g" in the NAME column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.glob("NAME", "?h*g");
```

## between

between(field: string, low: ValueType, high: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are within the given range (including the min. and max. values) in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Minimum value of the range to set.  |
| high   | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Maximum value of the range to set.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find the records that are greater than or equal to 10 and less than or equal to 50 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.between("AGE", 10, 50);
```

## notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are out of the given range (excluding the min. and max. values) in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Minimum value of the range to set.  |
| high   | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Maximum value of the range to set.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find the records that are less than 10 or greater than 50 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notBetween("AGE", 10, 50);
```

## greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are greater than the given value in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are greater than 18 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThan("AGE", 18);
```

## lessThan

lessThan(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are less than the given value in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are less than 20 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThan("AGE", 20);
```

## greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are greater than or equal to the given value in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are greater than or equal to 18 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThanOrEqualTo("AGE", 18);
```

## lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are less than or equal to the given value in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Yes  | Value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are less than or equal to 20 in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThanOrEqualTo("AGE", 20);
```

## orderByAsc

orderByAsc(field: string): RdbPredicates

Creates an **RdbPredicates** object to sort the records in the specified column in ascending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByAsc("NAME");
```

## orderByDesc

orderByDesc(field: string): RdbPredicates

Creates an **RdbPredicates** object to sort the records in the specified column in descending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByDesc("AGE");
```

## distinct

distinct(): RdbPredicates

Creates an **RdbPredicates** object to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                          |
| ------------------------------------ | ------------------------------ |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object that can filter out duplicate records.|

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").distinct(); // Deduplicate result sets whose NAME is Rose.
```

## limitAs

limitAs(value: number): RdbPredicates

Creates a **RdbPredicates** object to limit the number of records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| value  | number | Yes  | Maximum number of data records. The value should be a positive integer. If a value less than or equal to **0** is specified, the number of records is not limited.|

**Return value**

| Type                                | Description                                |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that specify the maximum number of records.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**              |
| --------- |--------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(3);
```

## offsetAs

offsetAs(rowOffset: number): RdbPredicates

Creates an **RdbPredicates** object to set the start position of the query result. This API must be used together with **limitAs**. Otherwise, no result will be returned. To query all rows after the specified offset, pass in a parameter less than or equal to **0** in **limitAs**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name   | Type  | Mandatory| Description                              |
| --------- | ------ | ---- | ---------------------------------- |
| rowOffset | number | Yes  | Start position of the query result. By default, the start position is the beginning of the result set. If **rowOffset** is a negative number, the start position is the beginning of the result set. If **rowOffset** exceeds the end of the result set, the query result is empty.|

**Return value**

| Type                                | Description                                |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that specify the start position of the returned result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(-1).offsetAs(3);
```

## groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates

Creates a **RdbPredicates** object to group the query results based on the specified columns.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | Yes  | Names of columns to group.|

**Return value**

| Type                                | Description                  |
| ------------------------------------ | ---------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that group rows with the same value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.groupBy(["AGE", "NAME"]);
```

## indexedBy

indexedBy(field: string): RdbPredicates

Creates a **RdbPredicates** object to specify the index column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| field  | string | Yes  | Name of the index column.|

**Return value**

| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | **RdbPredicates** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.indexedBy("SALARY");
```

## in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are in the given range in the specified column.

> **NOTE**
>
> The **value** array cannot be empty; otherwise, this condition becomes invalid. As a result, the operation (such as full query, update, or deletion) is performed on all data. Before calling this API, check whether the **value** array is empty to avoid misoperations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                   |
| ------ | ------------------------------------ | ---- | --------------------------------------- |
| field  | string                               | Yes  | Column name in the database table.                     |
| value  | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find records that are within [18, 20] in the AGE column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("AGE", [18, 20]);
```

## notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Creates an **RdbPredicates** object to search for the records that are out of the given range in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                 |
| ------ | ------------------------------------ | ---- | ------------------------------------- |
| field  | string                               | Yes  | Column name in the database table.                   |
| value  | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find the records that are not within [Lisa, Rose] in the NAME column.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

## notContains<sup>12+</sup>

notContains(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records that do not contain the given value in the specified column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match.|

**Return value**

| Type                           | Description                      |
| ------------------------------- | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find the records that do not contain the string "os" in the NAME column, for example, Lisa.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notContains("NAME", "os");
```

## notLike<sup>12+</sup>

notLike(field: string, value: string): RdbPredicates

Creates an **RdbPredicates** object to search for the records in the specified column that are not similar to the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Condition for fuzzy match. Generally, this parameter is used together with a wildcard: **%** represents any character of any length, and **_** represents a single character.|

**Return value**

| Type                           | Description                      |
| ------------------------------- | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**:

```ts
// Find all the records that are not similar to "os" in the NAME column, for example, Lisa.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notLike("NAME", "%os%");
```

## having<sup>20+</sup>

having(conditions:string, args?: Array\<ValueType>): RdbPredicates

Filters for group data that meets the conditions.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| conditions  | string | Yes  | Condition used to filter the data obtained using [groupBy](#groupby). This parameter cannot be empty and must be used with [groupBy](#groupby). |
| args  | Array<[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)> | No  | Parameters used in **conditions**, which replace the placeholder in the conditional statement. If this parameter is not specified, the default value is an empty array.|

**Return value**

| Type                           | Description                      |
| ------------------------------- | -------------------------- |
| [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Predicates that match the specified field.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 14800001       | Invalid arguments. Possible causes: 1. Parameter is out of valid range; 2. Missing GROUP BY clause. |

**Example 1**:

```ts
// Pass a complete condition.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.groupBy(["AGE"]);
predicates.having("NAME = zhangsan");
```
**Example 2**:

```ts
// Use placeholders in the condition and pass values to args to replace the placeholders.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.groupBy(["AGE"]);
predicates.having("NAME = ?", ["zhangsan"]);
```
