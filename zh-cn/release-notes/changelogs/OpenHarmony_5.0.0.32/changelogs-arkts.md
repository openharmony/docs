# Arkts子系统变更说明

## cl.arkts.1 TreeSet.clear()和TreeMap.clear()接口行为变更

**访问级别**

公开接口

**变更原因**

容器类TreeMap和TreeSet的构造函数支持传入比较器，用户可以通过传入比较器来控制元素在二叉树上的插入位置。当用户调用了TreeMap和TreeSet的clear方法时，预期结果为仅清除数据，
实际结果为清除数据的同时还清除了用户传入的比较器，导致再次插入数据时不会遵循用户传入的比较器的规则，而是按照默认比较器的规则，不符合用户预期，需要变更接口行为。

**变更影响**

不兼容变更，影响调用clear()后的排序规则。

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

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.clear();
TreeSet.clear();

**适配指导**

TreeSet.clear()和TreeMap.clear()方法行为变更之后，用户无需重新设置比较器也能正常排序，也可以重新设置比较器来改变元素的排序方式。

文档可参考如下：

[TreeMap.clear()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#clear)

[TreeSet.clear()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#clear)

## cl.arkts.2 TreeMap.setAll()接口行为变更

**访问级别**

公开接口

**变更原因**

使用setAll接口添加一个空的TreeMap，预期长度+0，实际长度+1。

**变更影响**

该变更为不兼容性变更，影响调用TreeMap.setAll()后TreeMap的长度。

- **变更前** 使用setAll接口添加treeMap1后treeMap长度为1

```
let treeMap : TreeMap<string, number> = new TreeMap();
let treeMap1 : TreeMap<string, number> = new TreeMap();
treeMap.setAll(treeMap1); // 将treeMap1中的所有元素添加到treeMap中
console.info("length:", treeMap.length) // length:1
```

- **变更后** 使用setAll接口添加treeMap1后treeMap长度为0

```
let treeMap : TreeMap<string, number> = new TreeMap();
let treeMap1 : TreeMap<string, number> = new TreeMap();
treeMap.setAll(treeMap1); // 将treeMap1中的所有元素添加到treeMap中
console.info("length:",treeMap.length) // length:0
```

**起始API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.setAll();

**适配指导**

对于TreeMap.setAll()传入空TreeMap的情况，开发者需要针对变更前后TreeMap的长度变化进行适配。

文档可参考如下：

[TreeMap.setAll()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#setall)

## cl.arkts.3 TreeMap、TreeSet的hasKey和has接口行为变更

**访问级别**

公开接口

**变更原因**

1. 对于传入用户自定义比较器的TreeMap， 不能正确区分undefined或null与其他元素的比较关系，导致在没有插入null或undefined的情况下hasKey(null/undefined)错误返回true。
2. 对于传入用户自定义比较器的TreeSet， 不能正确区分undefined或null与其他元素的比较关系，导致在没有插入null或undefined的情况下has(null/undefined)错误返回true。

**变更影响**

不兼容变更，影响TreeMap.hasKey()、TreeSet.has()传入undefined或null时的返回值。

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

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.32 版本开始。

**变更的接口/组件**

TreeMap.hasKey();
TreeSet.has();

**适配指导**

对于TreeMap.hasKey()、TreeSet.has()接口传入null或undefined的情况。开发者需要针对变更前后返回值的变化进行适配。

文档可参考如下：

[TreeMap.hasKey()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#haskey)

[TreeSet.has()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#has)


## cl.arkts.4 URLParams类append接口添加的值中包含连续空格时行为变更

**访问级别**

公开接口

**变更原因**

URLParams类append接口添加的字符串中包含连续多个空格时，连续空格会被错误处理成只转换为一个'+'，该实现不符合URL的标准。

 **变更影响**

不兼容变更，影响URLParams.append()接口在入参包含连续空格时的处理结果。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URLParams对象的append接口。

变更前：URLParams对象使用append()方法添加键值对时，若添加的字符串中存在连续多个空格时，接口表现为将连续多个空格只转换为一个'+'。
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+e+f"
}
```

变更后：URLParams对象使用append()方法添加键值对时，若添加的字符串中存在连续多个空格时，接口表现为将连续多个空格转换为对应空格数量的'+'。
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+++e+++f"
}
```

**适配指导**

开发者在涉及上面append的使用场景时，在变更生效前如果对append添加的键值对做后续处理操作，变更后需针对表现不同做针对性适配。

## cl.arkts.5 URLParams类在入参字符串中包含大小写不同编码值时，toString()接口表现结果不一致变更

**访问级别**

公开接口

**变更原因**

URLParams类在入参字符串中包含大小写不同编码值时toString()接口返回值有误，主要涉及："%2b"和"%2B"的表现不一致，"%2B"被处理为"%2B"是符合标准的，但"%2b"会被错误处理成'+'。

 **变更影响**

不兼容变更，影响当URLParams构造函数入参字符串中存在"%2b"时URLParams.toString()的返回结果。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URL模块URLParams类toString接口，

变更前：创建URLParams对象，如果入参字符串中存在"%2b"和"%2B"时，在toString()后返回的字符串分别表现为"+"和"%2B"。
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key+=abc%2B"
}
```

变更后：创建URLParams对象，如果入参字符串中存在"%2b"和"%2B"时，在toString()后返回的字符串均表现为"%2B";
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key%2B=abc%2B"
}
```

**适配指导**

开发者在涉及上述使用场景时，在变更生效前如果对toString()返回值做后续处理操作，变更后需针对表现不同做针对性适配。

## cl.arkts.6 URLParams类append接口行为变更

**访问级别**

公开接口

**变更原因**

URLParams使用append()方法时，对入参键值对中的特殊字符会错误进行encode，该行为与URL标准不一致，导致后续对键值对进行增删改查等操作出现异常。

 **变更影响**

不兼容变更，影响当URLParams.append()入参包含中文等特殊字符时该函数的处理结果。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

URLParams类append接口。

变更前：URLParams使用append()方法添加键值对, 若想通过添加的key使用get、has、delete、set接口进行增删改查操作，需先对key进行额外encode。
```ts
{
    const objectParams = new url.URLParams('?fod=1&bard=2')
    objectParams.append("key&大", "abc");
    objectParams.has('key&大');  // false
    objectParams.has('%E5%A4%A7');  // true
    objectParams.get('key&大');  // undefined
    objectParams.get('%E5%A4%A7');  // abc
}
```

变更后: URLParams使用append()方法添加键值对,可直接使用添加的key拿到对应value进行增删改查操作。
```ts
{
    const objectParams = new url.URLParams('?fod=1&bard=2')
    objectParams.append("key&大", "abc");
    objectParams.has('key&大');  // true
    objectParams.has('%E5%A4%A7');  // false
    objectParams.get('key&大');  // abc
    objectParams.get('%E5%A4%A7');  // undefined
}
```

**适配指导**

对于URLParams.append()入参包含中文等特殊字符的情况。开发者需要针对变更前后调用has()、get()、delete()、set()传入这些字符时处理结果及返回值的变化进行适配。