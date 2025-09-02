# ArkTS方舟编程语言Changelog

## cl.arkts.1 TreeSet/TreeMap扩容导致比较器丢失问题正向修复

**访问级别**

公开能力

**变更原因**

使用TreeSet/TreeMap模块的add接口触发扩容时，TreeSet/TreeMap自定义比较器会在扩容后丢失，导致扩容之后进行系统默认排序。

**变更影响**

此变更涉及应用适配。

**变更前：**

对于下述代码，预期结果与实际执行结果不一致，结果出现错误。

原因在于扩容后比较器丢失，remove(a1)失败，后续行为异常。

```ts
import { TreeSet } from '@kit.ArkTS';
class A {
time: number;
constructor(time: number) {
  this.time = time;
}
static readonly compared = ((first: A, second: A): number => {
    return second.time - first.time;
  }) as Function as (first: A, second: A) => boolean;
}
const a1 = new A(1);
const a2 = new A(2);
const a3 = new A(3);
const a4 = new A(4);
const a5 = new A(5);
const a6 = new A(6);
const set = new TreeSet<A>(A.compared); // 在add扩容后A.compared丢失
set.add(a1);
set.add(a2);
set.add(a3); // 触发扩容，A.compared丢失
set.add(a4);
set.add(a5);
set.add(a6);
for (let i = 0; i < 5; ++i) {
  set.remove(a1); // 同一个红黑树前后用了两种比较规则，数据结构的性质被破坏
  console.info(set.has(a1).toString());
  // 预期结果：false、false、false、false、false
  // 实际结果：false、false、true、true、true
  set.add(a1);
}
for (let item of set) {
  console.info(item.time.toString());
  // 预期结果：6、5、4、3、2、1
  // 实际结果：6、1、1
}
```

**变更后：**

TaggedTree比较器扩容前后一致，TaggedTree的所有add、remove都用同一个比较规则，输出结果与预期一致。

**起始 API Level**

8

**变更发生版本**

从OpenHarmony SDK 6.0开始。

**变更的接口/组件**

TreeSet、TreeMap

**适配指导**

行为变更，绝大多数情况不需要开发者进行适配。

只有当开发者用到自定义比较器，且将原本错误的结果当成正确的结果进行使用时，需注意TreeSet/TreeMap结果的变化，并按照修复后的结果进行代码适配。