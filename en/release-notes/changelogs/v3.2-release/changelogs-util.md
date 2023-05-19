# Util Subsystem Changelog

Compared with OpenHarmony 3.2 Beta4, OpenHarmony 3.2.10.7(MR) has the following API changes in the util subsystem.

## cl.util.1. randomUUID Name Changed
The **randomUUID** function name is changed to **generateRandomUUID**.

Before change: function randomUUID(entropyCache?: boolean): string <br>After change: function generateRandomUUID(entropyCache?: boolean): string

You need to adapt your application.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module     | Method/Attribute/Enum/Constant  | Change Type|
| :---------- | -------------------   | -------  |
| @ohos.util  | function randomUUID(entropyCache?: boolean): string        | Deleted |
| @ohos.util  | function generateRandomUUID(entropyCache?: boolean): string| Added |

**Adaptation Guide**

Refer to the code snippet below to call **generateRandomUUID** in your application.

Example:

```ts
import util from '@ohos.util'
let uuid = util.generateRandomUUID(true);
console.log("RFC 4122 Version 4 UUID:" + uuid);
// Output:
// RFC 4122 Version 4 UUID:88368f2a-d5db-47d8-a05f-534fab0a0045
```

## cl.util.2 randomBinaryUUID Name Changed
The **randomBinaryUUID** function name is changed to **generateRandomBinaryUUID**.

Before change: function randomBinaryUUID(entropyCache?: boolean): Uint8Array<br>After change: function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array

You need to adapt your application.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module     | Method/Attribute/Enum/Constant  | Change Type|
| :---------- | -------------------   | -------  |
| @ohos.util  | function randomBinaryUUID(entropyCache?: boolean): Uint8Array;       | Deleted |
| @ohos.util  | function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array| Added |

**Adaptation Guide**

Refer to the code snippet below to call **generateRandomBinaryUUID** in your application.

Example:

```ts
import util from '@ohos.util'
let uuid = util.generateRandomBinaryUUID(true);
console.log(JSON.stringify(uuid));
// Output:
// 138,188,43,243,62,254,70,119,130,20,235,222,199,164,140,150
```

## cl.util.3. contains Parameter Type in the LRUCache Class Changed
The **contains** parameter type in the LRUCache class is changed from **object** to **K**.

Before change: contains(key: object): boolean <br>After change: contains(key: K): boolean

You need to adapt your application.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module    | Class    | Method/Attribute/Enum/Constant             | Change Type|
| :--------  | ---------| -------------------------------- | -------- |
| @ohos.util | LRUCache |  contains(key: object): boolean  | Deleted    |
| @ohos.util | LRUCache |  contains(key: K): boolean       | Added    |

**Adaptation Guide**

Follow the code snippet to use the **contains** function in your application.

Example:

```ts
import util from '@ohos.util'
let pro = new util.LRUCache();
pro.put(2,10);
let obj = {1:"key"};
let result = pro.contains(obj);
```
