# Arkts子系统变更说明

## cl.arkts.1 TreeSet和TreeMap使用clear方法之后比较器失效

**访问级别**

公开接口

**变更原因**

容器类TreeMap和TreeSet的构造函数支持传入比较器，用户可以通过传入比较器来控制元素在二叉树上的插入位置。当用户调用了TreeMap和TreeSet的clear方法时，预期结果为仅清除数据，
实际结果为清除数据的同时还清除了用户传入的比较器，导致再次插入数据时不会遵循用户传入的比较器的规则，而是按照默认比较器的规则，不符合用户预期，需要变更接口行为。

**变更影响**

该变更为非兼容性变更。

**变更前**

- 情况一： 用户传入比较器，调用了TreeMap的clear方法后，比较器失效。

```
//使用comparator firstValue > secondValue，表示为降序排序。
let treeMap : TreeMap<string,string> = new TreeMap<string,string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
let numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item); // key: dd  cc  bb  aa
}
treeMap.clear();
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item); //key: aa  bb  cc  dd
}
```

- 情况二： 用户传入比较器，调用了TreeSet的clear方法后，比较器失效。

```
let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeSet.add("a");
treeSet.add("c");
treeSet.add("d");
treeSet.add("b");
let numbers = Array.from(treeSet.values())
for (let item of numbers) {
  console.log("TreeSet:" + item); // value: d  c  b  a
}
treeSet.clear();
treeSet.add("a");
treeSet.add("c");
treeSet.add("d");
treeSet.add("b");
numbers = Array.from(treeSet.values())
for (let item of numbers) {
  console.log("TreeSet:" + item); // value: a  b  c  d
}
```
**变更后**

- 情况一： 用户传入比较器，调用了TreeMap的clear方法后，比较器正常排序。

```
//使用comparator firstValue > secondValue，表示为降序排序。
let treeMap : TreeMap<string,string> = new TreeMap<string,string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
let numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item); // treeMap: dd  cc  bb  aa
}
treeMap.clear();
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item); // treeMap: dd  cc  bb  aa
}
```

- 情况二： 用户传入比较器，调用了TreeSet的clear方法后，比较器正常排序。

```
let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeSet.add("a");
treeSet.add("c");
treeSet.add("d");
treeSet.add("b");
let numbers = Array.from(treeSet.values())
for (let item of numbers) {
  console.log("TreeSet:" + item); // TreeSet: d  c  b  a
}
treeSet.clear();
treeSet.add("a");
treeSet.add("c");
treeSet.add("d");
treeSet.add("b");
numbers = Array.from(treeSet.values())
for (let item of numbers) {
  console.log("TreeSet:" + item); // TreeSet: d  c  b  a
}
```
**起始API Level**

API8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.clear();
TreeSet.clear();

**适配指导**

接口使用的示例代码可参考:

[TreeMap.clear()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#clear)

[TreeSet.clear()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#clear)

## cl.arkts.2 TreeMap.setAll()接口行为变更

**访问级别**

公开接口

**变更原因**

使用setAll接口添加一个空的TreeMap，预期长度+0，实际长度+1。

**变更影响**

该变更为非兼容性变更。

- **变更前** 使用setAll接口添加一个空map后treeMap.length长度为1

```
let treeMap : TreeMap<string, number> = new TreeMap();
let treeMap1 : TreeMap<string, number> = new TreeMap();
treeMap.setAll(treeMap1); // 将treeMap1中的所有元素添加到treeMap中
console.info("length:", treeMap.length) // length:1
```

- **变更后** 使用setAll接口添加一个空map后treeMap.length长度为0

```
let treeMap : TreeMap<string, number> = new TreeMap();
let treeMap1 : TreeMap<string, number> = new TreeMap();
treeMap.setAll(treeMap1); // 将treeMap1中的所有元素添加到treeMap中
console.info("length:",treeMap.length) // length:0
```

**起始API Level**

API8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.setAll();

**适配指导**

[TreeMap.setAll()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#setall)

## cl.arkts.3 TreeMap、TreeSet的hasKey和has接口行为变更

**访问级别**

公开接口

**变更原因**

1. 对于传入用户自定义比较器的TreeMap， 不能正确区分undefined或null与其他元素的比较关系，导致在没有插入null或undefined的情况下hasKey(null/undefined)错误返回true。
2. 对于传入用户自定义比较器的TreeSet， 不能正确区分undefined或null与其他元素的比较关系，导致在没有插入null或undefined的情况下has(null/undefined)错误返回true。

**变更影响**

该变更为非兼容性变更。

- **变更前**

- 情况一： 对于传入用户自定义比较器的TreeMap，在没有插入null或undefined的情况下hasKey(null/undefined)错误返回true。

```
let treeMap : TreeMap<string, number> = new TreeMap((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa",3);
treeMap.set("dd",1);
let res = treeMap.hasKey(null);
let res1 = treeMap.hasKey(undefined);
console.info("res:", res) // res:true
console.info("res1:",res1) // res1:true
```

- 情况二： 对于传入用户自定义比较器的TreeSet，在没有插入null或undefined的情况下has(null/undefined)错误返回true。

```
let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeSet.add("a");
treeSet.add("c");
let res = treeSet.has(null);
let res1 = treeSet.has(undefined);
console.info("res:", res) // res:true
console.info("res1:",res1) // res1:true
```

- **变更后**

- 情况一： 对于传入用户自定义比较器的TreeMap，在没有插入null或undefined的情况下hasKey(null/undefined)返回fasle。

```
let treeMap : TreeMap<string, number> = new TreeMap((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa",3);
treeMap.set("dd",1);
let res = treeMap.hasKey(null);
let res1 = treeMap.hasKey(undefined);
console.info("res:", res) // res:false
console.info("res1:",res1) // res1:false
```

- 情况二： 对于传入用户自定义比较器的TreeSet，在没有插入null或undefined的情况下has(null/undefined)返回false。

```
let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeSet.add("a");
treeSet.add("c");
let res = treeSet.has(null);
let res1 = treeSet.has(undefined);
console.info("res:", res) // res:false
console.info("res1:",res1) // res1:false
```


**起始API Level**

API8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.hasKey();
TreeSet.has();

**适配指导**

[TreeMap.hasKey()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#haskey)

[TreeSet.has()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#has)
