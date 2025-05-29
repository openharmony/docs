# ArkCompiler子系统Changelog

## cl.arkcompiler.1 ArkTSUtils.ASON.stringify处理Map和Set里undefined的行为由跳过序列化改为与Ecmascript的标准容器对齐

**访问级别**

公开接口

**变更原因**

往Map或Set里添加undefined元素后，通过ArkTSUtils.ASON.stringify序列化时，会跳过undefined的序列化，导致序列化出来的JSON字符串有问题，不符合JSON标准，后续使用会抛异常。

**变更影响**

此变更不涉及应用适配。

变更前：往Map或Set里添加undefined元素后，通过ArkTSUtils.ASON.stringify序列化出来的是非法JSON字符串。如下示例：

```ts
import { ArkTSUtils } from '@kit.ArkTS'

let map = new Map<string | undefined, string | undefined>();
map.set("a", "A");
map.set("b", undefined);
map.set(undefined, "c");
console.log(ArkTSUtils.ASON.stringify(map));
// 修改前输出：{"a":"A","b":,:"c"}

let set = new Set<string | undefined | null>();
set.add("a");
set.add(undefined);
set.add(null);
console.log(ArkTSUtils.ASON.stringify(set));
// 修改前输出：["a",,null]
```

变更后：对undefined正确处理，通过ArkTSUtils.ASON.stringify序列化出来的字符串符合JSON规范。

undefined的处理规格与Ecmascript的标准容器对齐，Set对齐Array，Map对齐Object。
1. Array里的undefined元素序列化JSON之后变为字符串null。
2. Object里，value为undefined的跳过序列化，key为undefined，value不为undefined时，key序列化为"undefined"。

如下示例：

```ts
import { ArkTSUtils } from '@kit.ArkTS'

let map = new Map<string | undefined, string | undefined>();
map.set("a", "A");
map.set("b", undefined);
map.set(undefined, "c");
console.log(ArkTSUtils.ASON.stringify(map));
// 修改后输出：{"a":"A","undefined":"c"}

let set = new Set<string | undefined | null>();
set.add("a");
set.add(undefined);
set.add(null);
console.log(ArkTSUtils.ASON.stringify(set));
// 修改后输出：["a",null,null]
```

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.1.0.50 开始。

**变更的接口/组件**

arkts.utils.d.ets文件ArkTSUTils.ASON.stringify接口

**适配指导**

往Map或Set里添加undefined元素后，通过ArkTSUtils.ASON.stringify序列化时，注意返回值的变更。
