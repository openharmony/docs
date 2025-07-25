# ArkTS Changelog

## cl.arkts.1 Forward Fix for TreeSet and TreeMap Comparator Loss on Capacity Expansion

**Access Level**

Public API

**Reason for Change**

When the **add** interface of the TreeSet or TreeMap module triggers a capacity expansion, the custom comparator for TreeSet or TreeMap is lost after the capacity expansion, causing the system to resort to default sorting.

**Impact of the Change**

This change requires application adaptation.

**Before the Change**

For the following code, the expected results do not match the actual execution results, leading to errors.

The reason is that the comparator is lost after capacity expansion, causing **remove(a1)** to fail and subsequent behavior to become abnormal.

```ts
import TreeSet from '@kit.ArkTS';
class A {
time: number;
constructor(time: number) {
  this.time = time;
}
static readonly compared = ((first: A, second: A): number => {
    return second.time - first.time;
  });
}
const a1 = new A(1);
const a2 = new A(2);
const a3 = new A(3);
const a4 = new A(4);
const a5 = new A(5);
const a6 = new A(6);
const set = new TreeSet<A>(A.compared); // Comparator A.compared is lost after add triggers a capacity expansion.
set.add(a1);
set.add(a2);
set.add(a3); // Capacity expansion is triggered, and A.compared is lost.
set.add(a4);
set.add(a5);
set.add(a6);
for (let i = 0; i < 5; ++i) {
  set.remove(a1); // Two different comparison rules used before and after the capacity expansion, and the data structure integrity is compromised.
  console.log(set.has(a1));
  // Expected result: false, false, false, false, false
  // Actual result: false, false, true, true, true
  set.add(a1);
}
for (let item of set) {
  console.log(item.time);
  // Expected result: 6, 5, 4, 3, 2, and 1
  // Actual result: 6, 1, 1
}
```

**After modification:**

The **TaggedTree** comparator remains consistent before and after the capacity expansion. All **add** and **remove** operations on **TaggedTree** use the same comparison rule, and the output results match expectations.

**Start API Level**

8

**Change Since**

OpenHarmony SDK 6.0

**Key API/Component Changes**

TreeSet, TreeMap

**Adaptation Guide**

This is a behavioral change. In most cases, no adaptation is required.

If you use custom comparators and have relied on the incorrect results as correct, you should be aware of the changes in TreeSet and TreeMap results and adapt your code according to the fixed results.
