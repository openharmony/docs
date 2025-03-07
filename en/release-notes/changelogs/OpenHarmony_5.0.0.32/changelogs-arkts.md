# ArkTS Subsystem Changelog

## cl.arkts.1 Behavior of TreeSet.clear() and TreeMap.clear() Is Changed

**Access Level**

Public API

**Reason for Change**

The constructors of the **TreeMap** and **TreeSet** classes support the input of a comparator, through which you can control the position to which an element is inserted in the binary tree. 

When the **clear** API of **TreeMap** and **TreeSet** is called, the expected result is that only data is cleared. However, the actual result is that both the data and the passed-in comparator are cleared. As a result, when the API for inserting data is called again, the rules of the default comparator, rather than those of the passed-in comparator, are used. Consequently, the result does not meet the expectation.

**Change Impact**

This change is a non-compatible change. It affects the sorting rule after **clear()** is called.

**Before Change**

- Case 1: When a user passes in a comparator and calls the **clear** API of **TreeMap**, the comparator becomes invalid.

  ```
  // Use comparator firstValue > secondValue to sort data in descending order.
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

- Case 2: When a user passes in a comparator and calls the **clear** API of **TreeSet**, the comparator becomes invalid.

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

**After Change**

- Case 1: When a user passes in a comparator and calls the **clear** API of **TreeMap**, the comparator functions normally.

  ```
  // Use comparator firstValue > secondValue to sort data in descending order.
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

- Case 2: When a user passes in a comparator and calls the **clear** API of **TreeSet**, the comparator functions normally.

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

**Start API Level**

8

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

TreeMap.clear();

TreeSet.clear();

**Adaptation Guide**

After the behavior of **TreeSet.clear()** and **TreeMap.clear()** is changed, you can sort elements without resetting the comparator. You can also reset the comparator to change the sorting mode of elements.

The reference documents are as follows:

[TreeMap.clear()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#clear)

[TreeSet.clear()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#clear)

## cl.arkts.2 Behavior of TreeMap.setAll() Is Changed

**Access Level**

Public API

**Reason for Change**

When **setAll** is called to add an empty tree map, the expected length is +0, but the actual length is +1.

**Change Impact**

This change is a non-compatible change. It affects the tree map length after **TreeMap.setAll()** is called.

- Before change: When treeMap1 is added using **setAll**, the tree map length is 1.

  ```
  let treeMap : TreeMap<string, number> = new TreeMap();
  let treeMap1 : TreeMap<string, number> = new TreeMap();
  treeMap.setAll(treeMap1); // Add all elements in treeMap1 to treeMap.
  console.info("length:", treeMap.length) // length:1
  ```

- After change: When treeMap1 is added using **setAll**, the tree map length is 0.

  ```
  let treeMap : TreeMap<string, number> = new TreeMap();
  let treeMap1 : TreeMap<string, number> = new TreeMap();
  treeMap.setAll(treeMap1); // Add all elements in treeMap1 to treeMap.
  console.info("length:",treeMap.length) // length:0
  ```

**Start API Level**

8

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

TreeMap.setAll();

**Adaptation Guide**

If **TreeMap.setAll()** passes in an empty tree map, adapt to the tree map length changes.

The reference documents are as follows:

[TreeMap.setAll()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#setall)

## cl.arkts.3 Behavior of hasKey and has of TreeMap and TreeSet Is Changed

**Access Level**

Public API

**Reason for Change**

1. For a **TreeMap** object with a user-defined comparator, the comparison relationship between undefined or null and other elements cannot be correctly distinguished. As a result, **hasKey(null/undefined)** returns **true** when null or undefined is not inserted.
2. For a **TreeSet** object with a user-defined comparator, the comparison relationship between undefined or null and other elements cannot be correctly distinguished. As a result, **has(null/undefined)** returns **true** when null or undefined is not inserted.

**Change Impact**

This change is a non-compatible change. It affects the return value of **TreeMap.hasKey()** and **TreeSet.has()** when undefined or null is passed in.

**Before Change**

- Case 1: For a **TreeMap** object with a user-defined comparator, if null or undefined is not inserted, **hasKey(null/undefined)** returns **true**.

  ```
  let treeMap : TreeMap<string, number> = new TreeMap((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
  treeMap.set("aa",3);
  treeMap.set("dd",1);
  let res = treeMap.hasKey(null);
  let res1 = treeMap.hasKey(undefined);
  console.info("res:", res) // res:true
  console.info("res1:",res1) // res1:true
  ```

- Case 2: For a **TreeSet** object with a user-defined comparator, if null or undefined is not inserted, **has(null/undefined)** returns **true**.

  ```
  let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
  treeSet.add("a");
  treeSet.add("c");
  let res = treeSet.has(null);
  let res1 = treeSet.has(undefined);
  console.info("res:", res) // res:true
  console.info("res1:",res1) // res1:true
  ```

**After Change**

- Case 1: For a **TreeMap** object with a user-defined comparator, if null or undefined is not inserted, **hasKey(null/undefined)** returns **false**.

  ```
  let treeMap : TreeMap<string, number> = new TreeMap((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
  treeMap.set("aa",3);
  treeMap.set("dd",1);
  let res = treeMap.hasKey(null);
  let res1 = treeMap.hasKey(undefined);
  console.info("res:", res) // res:false
  console.info("res1:",res1) // res1:false
  ```

- Case 2: For a **TreeSet** object with a user-defined comparator, if null or undefined is not inserted, **has(null/undefined)** returns **false**.

  ```
  let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
  treeSet.add("a");
  treeSet.add("c");
  let res = treeSet.has(null);
  let res1 = treeSet.has(undefined);
  console.info("res:", res) // res:false
  console.info("res1:",res1) // res1:false
  ```


**Start API Level**

8

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

TreeMap.hasKey();

TreeSet.has();

**Adaptation Guide**

When null or undefined is passed in, you need to adapt to the return value changes of **TreeMap.hasKey()** and **TreeSet.has()**.

The reference documents are as follows:

[TreeMap.hasKey()](../../../application-dev/reference/apis-arkts/js-apis-treemap.md#haskey)

[TreeSet.has()](../../../application-dev/reference/apis-arkts/js-apis-treeset.md#has)


## cl.arkts.4 Behavior Is Changed When the Value Added by append of the URLParams Class Contains Consecutive Spaces

**Access Level**

Public API

**Reason for Change**

If a string added by the **append** API of the **URLParams** class contains consecutive spaces, the consecutive spaces are incorrectly converted to only one plus sign (+). This implementation does not comply with the URL standard.

 **Change Impact**

This change is a non-compatible change. It affects the processing result of the **URLParams.append()** API when the input parameter contains consecutive spaces.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

**append** of a **URLParams** object.

Before change: When a **URLParams** object uses **append()** to add the key-value pair that contains consecutive spaces, the API converts the consecutive spaces to only one plus sign (+).
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+e+f"
}
```

After change: When a **URLParams** object uses **append()** to add the key-value pair that contains multiple consecutive spaces, the API converts the consecutive spaces to the corresponding number of plus signs (+).
```ts
{
    const objectParams = new url.URLParams("key=abc")
    console.log(objectParams.toString())  // "key=abc"
    objectParams.append('key1', 'd   e   f');
    console.log(objectParams.toString())  // "key=abc&key1=d+++e+++f"
}
```

**Adaptation Guide**

If the preceding scenario is used in your code, make adaptation to the key-value pairs added by **append** accordingly.

## cl.arkts.5 Return Value of toString() of the URLParams Class Is Inconsistent When the Passed-in String Contains Both Uppercase and Lowercase Encoding Values

**Access Level**

Public API

**Reason for Change**

For the **URLParams** class, the return value of the **toString()** API is incorrect when the passed-in string contains of the URLParams constructor both uppercase and lowercase encoding values. Specifically, "%2B" is processed as "%2B", whereas "%2b" is incorrectly processed as "+".

 **Change Impact**

This change is a non-compatible change. It affects the return value of **URLParams.toString()** when the passed-in string of the URLParams constructor contains "%2b".

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

**toString** API of the URLParams class of the URL module.

Before change: During the creation of a URLParams object, if both "%2b" and "%2B" exist in the passed-in string, they are displayed as "+" and "%2B" in the return value of **toString()**, respectively.
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key+=abc%2B"
}
```

After change: During the creation of a URLParams object, if both "%2b" and "%2B" exist in the passed-in string, they are displayed both as "%2B" in the return value of **toString()**.
```ts
{
    const objectParams = new url.URLParams("key%2b=abc%2B")
    console.log(objectParams.toString())  // "key%2B=abc%2B"
}
```

**Adaptation Guide**

If the preceding scenario is used in your code, make adaptation to the return value of **toString()**.

## cl.arkts.6 Behavior of append of the URLParams Class Is Changed

**Access Level**

Public API

**Reason for Change**

When the **append()** API of the **URLParams** class is called, special characters in the passed-in key-value pair are incorrectly encoded. This behavior is inconsistent with the URL standard. As a result, exceptions occur when the key-value pair is added, deleted, modified, or queried.

 **Change Impact**

This change is a non-compatible change. If affects the processing result of the **URLParams.append()** API when the passed-in key-value pair contains special characters such as Chinese characters.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.32

**Key API/Component Changes**

**append** API of the **URLParams** class.

Before change: The **append()** API of the **URLParams** class is used to add a key-value pair. When you want to use the **get**, **has**, **delete**, or **set** API with the added key to add, delete, modify, or query data, you must encode the key first.
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

After change: The **append()** API of the **URLParams** class is used to add a key-value pair. You can directly use the added key to obtain the corresponding value for adding, deleting, modifying, and querying.
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

**Adaptation Guide**

If the passed-in parameter of **URLParams.append()** contains special characters such as Chinese characters, you need to adapt to the changes in the processing result and return value of **has()**, **get()**, **delete()**, and **set()**.

 <!--no_check--> 