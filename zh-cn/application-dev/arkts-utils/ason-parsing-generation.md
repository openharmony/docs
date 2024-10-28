# ASON解析与生成

[ASON工具](../reference/apis-arkts/js-apis-arkts-utils.md#arktsutilsason)与JS提供的JSON工具类似，JSON用于进行JS对象的序列化（stringify）、反序列化（parse）。ASON则提供了[Sendable对象](arkts-sendable.md)的序列化、反序列化能力。可以通过ASON.stringify方法将对象转换成字符串，也可以通过ASON.parse方法将字符串转成Sendable对象，以便此对象在并发任务间进行高性能引用传递。

> **说明：**
>
> ASON.parse默认生成的对象为Sendable对象，布局不可变，不支持增删属性。如果需要支持返回对象的布局可变，可以指定返回类型为MAP，此时会全部返回[collections.Map](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsmap)对象，支持增删属性。

## 使用示例

采用ASON提供的接口，对[Sendable对象](arkts-sendable.md)进行序列化、反序列化。

```ts
import { ArkTSUtils, collections } from '@kit.ArkTS';

ArkTSUtils.ASON.parse("{}")
ArkTSUtils.ASON.stringify(new collections.Array(1, 2, 3))
```
