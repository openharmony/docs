# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 ArkTSUtils.ASON.stringify Behavior for Handling undefined in Maps and Sets Aligned with EcmaScript Standard Containers

**Access Level**

Public API

**Reason for Change**

If an undefined element is added to a Map or Set and then serialized using **ArkTSUtils.ASON.stringify**, the serialization of the undefined element will be skipped. As a result, the serialized JSON string does not comply with the JSON standard, and an exception is thrown when the JSON string is used.

**Impact of the Change**

This change does not require application adaptation.

Before: After an undefined element is added to a Map or Set, the serialized string is an invalid JSON string. Example:

```ts
import { ArkTSUtils } from '@kit.ArkTS'

let map = new Map<string | undefined, string | undefined>();
map.set("a", "A");
map.set("b", undefined);
map.set(undefined, "c");
console.log(ArkTSUtils.ASON.stringify(map));
// Output before change: {"a":"A","b":,:"c"}

let set = new Set<string | undefined | null>();
set.add("a");
set.add(undefined);
set.add(null);
console.log(ArkTSUtils.ASON.stringify(set));
// Output before change: ["a",, null]
```

After change: undefined is correctly processed. The string serialized by **ArkTSUtils.ASON.stringify** complies with the JSON specifications.

The processing specifications of undefined are aligned with those of the standard containers in Ecmascript. Set is aligned with Array, and Map is aligned with Object.
1. The undefined elements in the array are serialized into the null string.
2. In an object, if the value is undefined, the object is not serialized. If the key is undefined and the value is not undefined, the key is serialized as undefined.

Example:

```ts
import { ArkTSUtils } from '@kit.ArkTS'

let map = new Map<string | undefined, string | undefined>();
map.set("a", "A");
map.set("b", undefined);
map.set(undefined, "c");
console.log(ArkTSUtils.ASON.stringify(map));
// Output after change: {"a":"A","undefined":"c"}.

let set = new Set<string | undefined | null>();
set.add("a");
set.add(undefined);
set.add(null);
console.log(ArkTSUtils.ASON.stringify(set));
// Output after change: ["a",null,null].
```

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.1.0.50

**Key API/Component Changes**

**ArkTSUTils.ASON.stringify** in the **arkts.utils.d.ets** file

**Adaptation Guide**

After adding undefined elements to a Map or Set, note the change of the return value when **ArkTSUtils.ASON.stringify** is used for serialization.
