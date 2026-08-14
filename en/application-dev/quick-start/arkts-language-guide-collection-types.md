# Collection Types

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d6200ee580e2d2b406a92c0e4a15bf6480d0d39a translatedAt=2026-08-13T08:55:11.161Z pushedAt=2026-08-13T12:36:14.670Z -->

Collection types are used to store multiple data items. ArkTS provides various collection types, including arrays, tuples, Set, Map, and others, each with its specific purposes and characteristics. ArkTS collections are primarily classified along two dimensions: structure and mutability. Structurally, they are divided into arrays (Array), sets (Set), and dictionaries (Map); in terms of mutability, they are divided into mutable collections and read-only collections (such as ReadonlyArray). Understanding the differences among these types in terms of ordering, uniqueness, and key-value mapping is the prerequisite for type selection.

## Mutable and Read-Only Collections

Collections are classified into mutable and read-only types based on modification permissions. Mutable collections support adding, deleting, and modifying elements, while read-only collections only allow reading.

<!-- @[ts_mutable_and_readonly_collections](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// Mutable collection
let mutableArray: number[] = [1, 2, 3];
mutableArray.push(4);  // Can be added.

let mutableSet: Set<number> = new Set([1, 2]);
mutableSet.add(3);     // Can be added.

let mutableMap: Map<string, number> = new Map();
mutableMap.set('key', 10);  // Can be added.

// Read-only collection (using ReadonlyArray).
let readonlyArray: ReadonlyArray<number> = [1, 2, 3];
readonlyArray.push(4);  // Compilation error: cannot be modified.
```

## Array

An array is the most commonly used data structure for storing an ordered collection of elements. Elements in an array are arranged by index, starting from 0, and can be dynamically added and removed.

Arrays are commonly used to store ordered data lists (such as user lists, product lists, and log records), represent sequence data (such as time series and event streams), process batch data (such as batch operations, batch conversions, and batch queries), or serve as stacks or queues (such as task queues and history records). Their core characteristics include: elements are stored in insertion order with indexes starting from 0 (ordering), elements can be dynamically added, removed, and modified (mutability), all elements must be of the same type or a union type (type constraint), and the length can change at any time (dynamic length).

### Array Declaration and Initialization

An array can be created using a literal or a constructor. Specify the element type at declaration to ensure type safety.

<!-- @[array_creation_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Use the type suffix []
let numbers: number[] = [1, 2, 3, 4, 5];
let strings: string[] = ['a', 'b', 'c'];
let booleans: boolean[] = [true, false, true];

// Use the generic Array
let numbers2: Array<number> = [1, 2, 3];
let strings2: Array<string> = ['hello', 'world'];

// Empty array
let empty: number[] = [];
let empty2: string[] = [];

// Union type array
let mixed: (number | string)[] = [1, 'two', 3, 'four'];
let nullable: (number | null)[] = [1, null, 3];

// Create using the spread operator
let original: number[] = [1, 2, 3];
let copy: number[] = [...original];
let extended: number[] = [...original, 4, 5];
```

`number[]` and `Array<number>` are functionally equivalent. The `number[]` form is recommended because it is more concise, while the `Array<T>` syntax is suitable for scenarios where generics need to be emphasized. The spread operator `...original` creates a new array, and modifying the copy does not affect the original array.

### Accessing and Modifying Array Elements

Array elements are accessed and modified by index, commonly used in scenarios such as reading values, updating data, data processing, and runtime state updates.

<!-- @[array_element_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arr: number[] = [10, 20, 30, 40, 50];

// Read an element.
let first: number = arr[0];   // 10
let second: number = arr[1];  // 20
let last: number = arr[arr.length - 1];  // 50

// Modify an element.
arr[0] = 100;
arr[1] = 200;
console.info(`${arr.join(', ')}`);  // 100, 200, 30, 40, 50

// Access out of bounds.
let outOfBounds: number | undefined = arr[10];
console.info(`${outOfBounds}`);  // undefined

// Safe access
let index: number = 5;
if (index >= 0 && index < arr.length) {
  let safe: number = arr[index];
}
```

Accessing an array out of bounds returns `undefined` instead of throwing an exception. Therefore, perform a boundary check before accessing an index that is not guaranteed to be valid.

### Iterating Over an Array

Array iteration is commonly used for data processing, searching, statistics, and transformation. When choosing an approach: use `for...of` when you only need the value, use a `for` loop when you need the index, use `forEach` for functional-style processing, and do not modify the array length during iteration.

<!-- @[array_for_loop_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterArr: number[] = [1, 2, 3, 4, 5];

for (let value of iterArr) {
  console.info(`${value}`);
}

// Obtain the index and value.
for (let i: number = 0; i < iterArr.length; i++) {
  console.info(`Index ${i}: ${iterArr[i]}`);
}
```

The `forEach` method iterates over an array in a functional style and executes a callback for each element:

<!-- @[array_forEach_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let forEachArr: number[] = [1, 2, 3];

forEachArr.forEach((value: number, index: number): void => {
  console.info(`Index ${index}: ${value}`);
});
```

`forEach` does not support `break`. Use `for...of` or a `for` loop when you need to exit the iteration early. In ArkTS, arrow function parameters must have explicit type annotations; the parameter type annotation cannot be omitted.

<!-- @[array_indexed_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterArr2: number[] = [1, 2, 3];

for (let i: number = 0; i < iterArr2.length; i++) {
  console.info(`${iterArr2[i]}`);
}
```

### Common Array Operations

Arrays provide common operations such as push, pop, shift, and splice for adding, deleting, modifying, and querying elements.

<!-- @[array_add_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let elemArr: number[] = [1, 2];

// push: append to the end
elemArr.push(3);
elemArr.push(4, 5);  // can add multiple
let newLength: number = elemArr.push(6);  // return the new length

// unshift: add to the beginning
elemArr.unshift(0);
elemArr.unshift(-1, -2);  // can add multiple elements

console.info(`${elemArr.join(', ')}`);  // -1, -2, 0, 1, 2, 3, 4, 5, 6
```

To delete elements, use methods such as pop, shift, and splice:

<!-- @[array_remove_elements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let elemArr2: number[] = [1, 2, 3, 4, 5];

// pop: delete from the end
let elemLast: number | undefined = elemArr2.pop();  // 5
console.info(`${elemArr2.join(', ')}`);  // 1, 2, 3, 4

// shift: delete from the beginning
let elemFirst: number | undefined = elemArr2.shift();  // 1
console.info(`${elemArr2.join(', ')}`);  // 2, 3, 4

// splice: delete the specified position
let removed: number[] = elemArr2.splice(1, 2);  // Delete the two elements starting from index 1.
console.info(`${elemArr2.join(', ')}`);  // 2
console.info(`${removed.join(', ')}`);  // 3, 4
```

The `concat` and `slice` methods are used to concatenate and extract arrays. Both return a new array without modifying the original array:

<!-- @[array_concat_and_slice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arr1: number[] = [1, 2];
let arr2: number[] = [3, 4];

// concat: concatenate arrays
let combined: number[] = arr1.concat(arr2);
console.info(`${combined.join(', ')}`);  // 1, 2, 3, 4
let sliceExtended: number[] = arr1.concat(3, 4, [5, 6]);
console.info(`${sliceExtended.join(', ')}`);  // 1, 2, 3, 4, 5, 6

// slice: split/extract
let sliceArr: number[] = [1, 2, 3, 4, 5];
let sub: number[] = sliceArr.slice(1, 4);
console.info(`${sub.join(', ')}`);  // 2, 3, 4
let tail: number[] = sliceArr.slice(2);
console.info(`${tail.join(', ')}`);  // 3, 4, 5
let sliceCopy: number[] = sliceArr.slice();
console.info(`${sliceCopy.join(', ')}`);  // 1, 2, 3, 4, 5 (copy)
```

The search and filter methods of an array include `indexOf`, `includes`, `find`, and `filter`:

<!-- @[array_search_and_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let filterArr: number[] = [1, 2, 3, 2, 1];

// indexOf: Find the index.
let filterIndex: number = filterArr.indexOf(2);  // 1 (first match)
let lastIndex: number = filterArr.lastIndexOf(2);  // 3 (last match)
let notFound: number = filterArr.indexOf(10);  // -1

// includes: check whether it contains
let has2: boolean = filterArr.includes(2);  // true
let has10: boolean = filterArr.includes(10);  // false

// find: conditional search
let filterNumbers: number[] = [1, 5, 10, 15, 20];
let found: number | undefined = filterNumbers.find((value: number): boolean => {
  return value > 10;
});  // 15

let foundIndex: number = filterNumbers.findIndex((value: number): boolean => {
  return value > 10;
});  // 3

// filter: filter
let allNumbers: number[] = [1, 2, 3, 4, 5, 6];
let evens: number[] = allNumbers.filter((value: number): boolean => {
  return value % 2 === 0;
});
console.info(`${evens.join(', ')}`);  // 2, 4, 6

let greaterThan3: number[] = allNumbers.filter((value: number): boolean => {
  return value > 3;
});
console.info(`${greaterThan3.join(', ')}`);  // 4, 5, 6
```

## Tuple

A tuple is an ordered collection with a fixed length and fixed types. A tuple differs from an array: a tuple has a fixed length and each position can have a different type, whereas an array has a variable length and all elements share the same type.

- Represent data with a fixed structure, such as a coordinate point `[x, y]` or an RGB color `[r, g, b]`.

- Return multiple values, such as a function returning `[result, error]`.

- Represent a key-value pair, such as `[key, value]`.

- Defines data of specific types at specific positions (for example, `[id, name, age]`).

### Tuple Declaration and Initialization

A tuple is declared by explicitly specifying the element type at each position, with a fixed length and type sequence.

<!-- @[tuple_basics](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Tuple in TypeScript
let tuple: [number, string] = [1, 'hello'];
let coordinate: [number, number] = [10, 20];
let user: [number, string, boolean] = [1, 'Alice', true];

// In ArkTS, tuples are usually represented by arrays
let pair: number[] = [1, 2];  // A two-element array simulates a tuple
let triple: [number, string, boolean] = [1, 'text', true];  // Type annotation
```

In the type annotation above, the type at each position can be different, thereby expressing data with a fixed structure. In ArkTS, a simple fixed-length array can serve as a substitute for a tuple.

### Accessing Tuple Elements

Tuple elements are accessed by index. Each position has an explicit type, based on which the compiler performs type checking. Tuples are also commonly used to return multiple related values from a function.

<!-- @[tuple_element_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Index access.
let accessTuple: [number, string] = [1, 'hello'];
let num: number = accessTuple[0];    // 1
let str: string = accessTuple[1];    // 'hello'

// Access the tuple in array form.
let accessPair: number[] = [10, 20];
let accessFirst: number = accessPair[0];   // 10
let accessSecond: number = accessPair[1];  // 20

// Safe access (with type checking).
function getPairElement(arr: number[], index: number): number | undefined {
  if (arr.length === 2 && index >= 0 && index < 2) {
    return arr[index];
  }
  return undefined;
}
```

When a tuple is accessed by index, the compiler retains the precise type information for each position (for example, `tuple[0]` is `number` and `tuple[1]` is `string`). In contrast, when an array form (such as `number[]`) is used to simulate a tuple, the type information is less precise than that of a real tuple, and you must perform boundary checks manually when accessing it.

### Read-Only Characteristics of Tuples

A read-only tuple ensures that its data is not modified. It is suitable for scenarios such as configuration data, constant coordinates, and function parameter protection, where the compiler enforces checks on modification operations.

<!-- @[ts_readonly_tuple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// Read-only tuple in TypeScript
let readonlyTuple: readonly [number, string] = [1, 'hello'];
readonlyTuple[0] = 2;  // Compilation error

// Simulate with ReadonlyArray in ArkTS
let readonlyPair: ReadonlyArray<number> = [1, 2];
readonlyPair[0] = 3;  // Compilation error.
```

TypeScript uses the `readonly` keyword to modify tuples. ArkTS does not support this syntax; instead, use `ReadonlyArray` to achieve an equivalent read-only constraint. The read-only check is performed at compile time with no runtime overhead, making it suitable for immutable scenarios such as protecting configuration data and function parameters.

### Differences Between Tuples and Arrays

A tuple has a fixed length and a fixed sequence of types, whereas an array has a variable length and a uniform element type.

<!-- @[tuple_vs_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Tuple: fixed length and types
let point: [number, number] = [10, 20];  // Can contain only two numbers

// Array: variable length, uniform type
let tupleNumbers: number[] = [1, 2, 3, 4, 5];  // More number elements can be added.

// A tuple represents a fixed structure.
let userTuple: [number, string, boolean] = [1, 'Alice', true];
console.info(`${userTuple.join(', ')}`);  // 1, Alice, true

// An array represents a dynamic collection.
let userIds: number[] = [1, 2, 3, 4, 5];
userIds.push(6);  // Can be added.
```

## Set

A Set stores a collection of unique elements and is suitable for scenarios such as deduplication and membership checks. Unlike an array, the elements in a Set are unique.

### Set Declaration and Initialization

A Set stores a collection of unique values. It is created through the constructor, which specifies the element type.

<!-- @[set_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Create an empty Set.
let emptySet: Set<number> = new Set();

// Create from an array.
let numbersSet: Set<number> = new Set([1, 2, 3, 4, 5]);

// Add initial elements.
let stringSet: Set<string> = new Set();
stringSet.add('a');
stringSet.add('b');
```

### Core Features of Set

Set guarantees element uniqueness, automatically removes duplicates, and provides efficient existence checks.

<!-- @[set_uniqueness](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let set: Set<number> = new Set([1, 2, 2, 3, 3, 3]);
console.info(`${set.size}`);  // 3 (duplicates removed)

// Adding a duplicate element has no effect.
set.add(1);
console.info(`${set.size}`);  // 3 (unchanged)

// Remove duplicate elements from the array.
let uniqueArr: number[] = [1, 2, 2, 3, 3, 3];
let unique: number[] = Array.from(new Set(uniqueArr));
console.info(`${unique.join(', ')}`);  // 1, 2, 3
```

### Common Operations on Set

Set provides basic operations such as adding, deleting, searching, and traversing, and all elements are unique without duplicates.

<!-- @[set_add_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let addSet: Set<number> = new Set();

addSet.add(1);
addSet.add(2);
addSet.add(3);

let addedSet: Set<number> = addSet.add(4);  // Return the Set itself.
```

Use the `delete` method to delete an element, which returns whether the deletion succeeds:

<!-- @[set_delete_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let delSet: Set<number> = new Set([1, 2, 3]);

let deleted: boolean = delSet.delete(2);  // true (successfully deleted)
let isRemoved: boolean = delSet.delete(10);  // false (does not exist)

console.info(`${delSet.size}`);  // 2
```

Use the `has` method to check whether an element exists in the Set:

<!-- @[set_has_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let hasSet: Set<number> = new Set([1, 2, 3]);

let has1: boolean = hasSet.has(1);  // true
let hasHas10: boolean = hasSet.has(10);  // false
```

To iterate over a Set, use `for...of` or `forEach`, or obtain an iterator through `values()` or `keys()`:

<!-- @[set_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterSet: Set<number> = new Set([1, 2, 3]);

// for...of loop
for (let value of iterSet) {
  console.info(`${value}`);
}

// forEach method
iterSet.forEach((value: number): void => {
  console.info(`${value}`);
});

// Obtain all values.
let values: IterableIterator<number> = iterSet.values();
for (let value of values) {
  console.info(`${value}`);
}

// Obtain all keys (in a Set, keys equal values).
let keys: IterableIterator<number> = iterSet.keys();
for (let key of keys) {
  console.info(`${key}`);
}
```

A Set and an array can be converted to each other. You can use the uniqueness of a Set to deduplicate an array:

<!-- @[set_array_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Convert a Set to an array.
let convSet: Set<number> = new Set([1, 2, 3]);
let convArr: number[] = Array.from(convSet);
console.info(`${convArr.join(', ')}`);  // 1, 2, 3

// Convert an array to a Set.
let convNumbers: number[] = [1, 2, 2, 3];
let setFromArr: Set<number> = new Set(convNumbers);
console.info(`${Array.from(setFromArr).join(', ')}`);  // 1, 2, 3

// Remove duplicates.
let duplicates: number[] = [1, 1, 2, 2, 3, 3];
let convUnique: number[] = Array.from(new Set(duplicates));
console.info(`${convUnique.join(', ')}`);  // 1, 2, 3
```

The `clear` method removes all elements from the Set:

<!-- @[set_clear_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let clearSet: Set<number> = new Set([1, 2, 3]);
clearSet.clear();
console.info(`${clearSet.size}`);  // 0
```

## Map

Map is a collection that stores key-value pairs, where both keys and values can be of any type.

### Map Declaration and Initialization

A Map is used to store a collection of key-value pairs. It is created through a constructor, with the types of keys and values specified.

<!-- @[map_creation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Create an empty Map.
let emptyMap: Map<string, number> = new Map();

// Create from an array (an array of key-value pairs).
let initMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2],
  ['c', 3]
]);

// Add initial key-value pairs.
let map: Map<string, number> = new Map();
map.set('one', 1);
map.set('two', 2);
```

### Accessing, Adding, and Deleting Key-Value Pairs

Map accesses and modifies key-value pairs through the get, set, and delete methods, supporting dynamic data management.

<!-- @[map_basic_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let opsMap: Map<string, number> = new Map();

// Add a key-value pair
opsMap.set('a', 1);
opsMap.set('b', 2);
opsMap.set('c', 3);

// Access a value
let valueA: number | undefined = opsMap.get('a');  // 1
let valueB: number | undefined = opsMap.get('b');  // 2
let opsNotFound: number | undefined = opsMap.get('x');  // undefined

// Check whether a key exists
let hasA: boolean = opsMap.has('a');  // true
let hasX: boolean = opsMap.has('x');  // false

// Delete the key-value pair.
let opsDeleted: boolean = opsMap.delete('b');  // true
let opsNotDeleted: boolean = opsMap.delete('x');  // false

// Update the value.
opsMap.set('a', 10);  // Update the value of 'a'.

// Clear the map.
opsMap.clear();
console.info(`${opsMap.size}`);  // 0
```

### Iterating Over a Map

To iterate over a Map, use forEach or a for-of loop. You can iterate over keys, values, or key-value pairs.

<!-- @[map_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let iterMap: Map<string, number> = new Map([
  ['a', 1],
  ['b', 2],
  ['c', 3]
]);

// Iterate using forEach
iterMap.forEach((value: number, key: string): void => {
  console.info(`${key}: ${value}`);
});

// Iterate entries using for...of
for (let entry of iterMap.entries()) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}

// Iterate keys using for...of
for (let key of iterMap.keys()) {
  console.info(`${key}`);
}

// Iterate values using for...of.
for (let value of iterMap.values()) {
  console.info(`${value}`);
}

// Iterate without destructuring and explicitly read the entry element.
for (let entry of iterMap.entries()) {
  let key: string = entry[0];
  let value: number = entry[1];
  console.info(`${key}: ${value}`);
}
```

### Record<K,V> Type

`Record<K, V>` is a built-in utility type in ArkTS that maps a key type `K` to a value type `V`, and is suitable for expressing "string-keyed objects". When the keys are fixed to strings or numbers and the structure is relatively simple, it is lighter than `Map` and is commonly initialized with an object literal.

<!-- @[record_type_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let ages: Record<string, number> = {
  'John': 25,
  'Mary': 21
};
ages['John']; // 25
```

The key type `K` can be `string` or `number` (excluding `bigint`), and the value type `V` can be any type. Reading by subscript returns `V | undefined`, so you must check for null before use.

When the value is a composite structure, you can use an interface to describe its shape:

<!-- @[record_type_complex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
interface PersonInfo {
  age: number;
  salary: number;
}
let staff: Record<string, PersonInfo> = {
  'John': { age: 25, salary: 10},
  'Mary': { age: 21, salary: 20}
};
```

Compared with `Map`, `Record` is based on object literals, its keys can only be strings or numbers, it has no `size` property (you must use `Object.keys(obj).length` to compute it), and it does not support keys of arbitrary types. When you need keys of arbitrary types, dynamic addition and removal of key-value pairs, or preservation of insertion order, prefer `Map` (see [Differences Between Map and Ordinary Objects](#differences-between-map-and-ordinary-objects)).

### Differences Between Map and Ordinary Objects

Map keys can be of any type, while object keys can only be strings. Therefore, Map is more suitable for dynamic key-value storage.

<!-- @[map_vs_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Map: any key type
let objMap2: Map<number, string> = new Map();
objMap2.set(1, 'one');
objMap2.set(2, 'two');

class KeyObject {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

let objMap: Map<KeyObject, string> = new Map();
let keyObj: KeyObject = new KeyObject(1);
objMap.set(keyObj, 'value');

// Record: suitable for expressing string-keyed objects
let obj: Record<string, number> = {};
obj['key1'] = 1;
obj['key2'] = 2;

let objValue: number | undefined = obj['key1'];
if (objValue !== undefined) {
  console.info(`${objValue}`);
}

// Map: preserves order
let orderedMap: Map<string, number> = new Map();
orderedMap.set('a', 1);
orderedMap.set('b', 2);
orderedMap.set('c', 3);
console.info(`${Array.from(orderedMap.keys()).join(', ')}`);  // a, b, c (order preserved)

// Map: obtain the size directly.
console.info(`${orderedMap.size}`);  // 3

// Object: compute the size.
let objSize: number = Object.keys(obj).length;
```

## Read-only Collection Types

Read-only collection types prohibit modification operations and are suitable for passing immutable data.

### Readonly Array (ReadonlyArray)

ReadonlyArray provides a read-only interface and prohibits modification operations such as `push` and `pop`.

<!-- @[ts_readonly_array_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let readonlyArr: ReadonlyArray<number> = [1, 2, 3];

// Read-only
readonlyArr.push(4);      // Compilation error
readonlyArr[0] = 10;      // Compilation error
readonlyArr.pop();        // Compilation error.

// Can be read.
let first: number = readonlyArr[0];  // 1
let length: number = readonlyArr.length;  // 3

// Can be iterated.
for (let value of readonlyArr) {
  console.info(`${value}`);
}

// Create a read-only array.
let mutable: number[] = [1, 2, 3];
let readonly: ReadonlyArray<number> = mutable;  // Convert to read-only.

// Type alias
type ReadOnlyNumbers = ReadonlyArray<number>;
let nums: ReadOnlyNumbers = [1, 2, 3];
```

### Read-only Map and Read-only Set

Read-only collections are declared through the `ReadonlyMap` or `ReadonlySet` type to prevent accidental modification. `ReadonlyMap` and `ReadonlySet` are built-in read-only interfaces in ArkTS.

<!-- @[readonly_map_set_interfaces](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
interface ReadonlyMap<K, V> {
  get(key: K): V | undefined;
  has(key: K): boolean;
  size: number;
  forEach(callback: (value: V, key: K) => void): void;
}

interface ReadonlySet<T> {
  has(value: T): boolean;
  size: number;
  forEach(callback: (value: T) => void): void;
}

// Return a read-only interface when used.
function getReadOnlyMap(): ReadonlyMap<string, number> {
  let map: Map<string, number> = new Map();
  map.set('a', 1);
  return map;  // Return a read-only view.
}
```

### When to Use Read-only Collections

Read-only collections are suitable for scenarios where data should not be modified, such as configuration data and constant lists.

<!-- @[readonly_collection_scenarios](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Configuration data: read-only, to prevent accidental modification.
const CONFIG: ReadonlyArray<string> = ['api', 'db', 'cache'];

// Function parameters: read-only, to protect the original data.
function processItems(items: ReadonlyArray<number>): number {
  let sum: number = 0;
  for (let item of items) {
    sum += item;
  }
  return sum;
}

let scenariosNumbers: number[] = [1, 2, 3];
processItems(scenariosNumbers);  // Pass a read-only view.

// Return a read-only result to prevent external modification.
function getConstants(): ReadonlyArray<string> {
  return ['CONST_A', 'CONST_B'];
}
```

## Collection Traversal and Iterators

Collection traversal uses for-of, forEach, and the iterator interface to access elements one by one.

### for...of Loop

The for-of loop iterates over iterable objects with concise syntax and directly obtains the element value.

<!-- @[for_of_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// array
let iterArr3: number[] = [1, 2, 3];
for (let value of iterArr3) {
  console.info(`${value}`);
}

// Set
let iterSet2: Set<number> = new Set([1, 2, 3]);
for (let value of iterSet2) {
  console.info(`${value}`);
}

// Map
let iterMap2: Map<string, number> = new Map([['a', 1], ['b', 2]]);
for (let entry of iterMap2) {
  console.info(`${entry[0]}: ${entry[1]}`);  // a: 1, b: 2
}

// string
let text: string = 'Hello';
for (let char of text) {
  console.info(`${char}`);
}
```

### Using the Iterator Interface

The iterator retrieves values on demand through the next() method, allowing you to manually control the traversal pace.

<!-- @[iterator_manual_traversal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Obtain the iterator.
let traverseArr: number[] = [1, 2, 3];
let iterator: IterableIterator<number> = traverseArr.values();

// Traverse manually.
let result: IteratorResult<number> = iterator.next();
while (!result.done) {
  console.info(`${result.value}`);
  result = iterator.next();
}

// Set iterator
let traverseSet: Set<string> = new Set(['a', 'b', 'c']);
let setIterator: IterableIterator<string> = traverseSet.values();

console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"a","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"b","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":"c","done":false}
console.info(`${JSON.stringify(setIterator.next())}`);  // {"value":undefined,"done":true}

// Map iterator
let traverseMap: Map<string, number> = new Map([['x', 10], ['y', 20]]);
let mapIterator: IterableIterator<[string, number]> = traverseMap.entries();

console.info(`${JSON.stringify(mapIterator.next())}`);  // {"value":["x",10],"done":false}
```

### Destructuring Assignment of Collections

ArkTS does not support destructuring assignment of collections. Access elements one by one through indexes or iterators.

**TypeScript Comparison**

<!-- @[ts_destructuring_alternatives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
// Array destructuring
let [a, b] = [1, 2];

// Correct approach: assign separately
let arr: number[] = [1, 2];
let aVal: number = arr[0];
let bVal: number = arr[1];

// Map destructuring
let map: Map<string, number> = new Map([['key', 10]]);
let [mapKey, mapValue] = map.entries().next().value;

// Correct approach: assign separately
let entry: [string, number] | undefined = Array.from(map.entries())[0];
if (entry !== undefined) {
  let entryKey: string = entry[0];
  let entryValue: number = entry[1];
}

// Set destructuring
let [setFirst, setSecond] = new Set([1, 2]);

// Correct approach: assign separately
let set: Set<number> = new Set([1, 2]);
let values: number[] = Array.from(set);
let firstVal: number = values[0];
let secondVal: number = values[1];
```

## Procedure

1. Determine the data relationship: use `Array` for ordered lists, `Set` for collections of unique values, `Map` for key-value indexing, and prefer explicit interfaces or tuples for fixed-length data structures where positions correspond to types.

2. Specify element types: Declare the specific types of array elements, Set elements, and Map keys and values. Do not use `any` or `unknown` to receive collection content.

3. Confirm mutability boundaries: Use `ReadonlyArray` when a function only reads a collection. When writing is required, modify the collection only in its creator or in functions dedicated to updating it.

4. Choose an access method: Access results that may return `undefined`, such as array indexing, `find`, and `Map.get`, must be checked before use.

5. Choose an iteration method: Use `for...of` for read-only values, use `for` or `forEach` with type annotations when an index is needed, and explicitly read `entry[0]` and `entry[1]` when iterating over a `Map`.

6. Check ArkTS restrictions: Do not use destructuring assignment to iterate over collections, do not use object keys as ordinary object indexes, and do not directly expose mutable collections to callers that should not modify them.

## Anti-patterns

The following patterns are common in TypeScript, but they are error-prone when migrating to ArkTS or writing code for long-term maintenance.

Anti-pattern 1: Ignoring read results that may be `undefined`.

<!-- @[ts_map_safe_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let scores: Map<string, number> = new Map();
scores.set('Alice', 95);

// Counterexample: Map.get may return undefined
let aliceScore: number = scores.get('Alice');

// Recommended: check before use
let aliceScoreSafe: number | undefined = scores.get('Alice');
if (aliceScoreSafe !== undefined) {
  console.info(`${aliceScoreSafe}`);
}
```

Anti-pattern 2: Using an array to serve as a unique collection.

<!-- @[unique_collection_with_set](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Counterexample: Manually calling includes on every insertion makes it easy to miss deduplication logic.
let ids: number[] = [];
if (!ids.includes(1001)) {
  ids.push(1001);
}

// Recommended: Let Set express uniqueness.
let uniqueIds: Set<number> = new Set();
uniqueIds.add(1001);
uniqueIds.add(1001);
console.info(`${uniqueIds.size}`);  // 1
```

Anti-pattern 3: Using destructuring to iterate over `Map`.

**TypeScript comparison**

<!-- @[ts_map_entry_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Collections.ts) -->

``` TypeScript
let userScores: Map<string, number> = new Map([['Alice', 95], ['Bob', 88]]);

// TypeScript equivalent; ArkTS does not use destructuring:
for (let [name, score] of userScores) {
  console.info(`${name}: ${score}`);
}

// Recommended: explicitly read the entry
for (let entry of userScores.entries()) {
  let name: string = entry[0];
  let score: number = entry[1];
  console.info(`${name}: ${score}`);
}
```

Anti-pattern 4: using an ordinary object to store object keys.

The keys of an ordinary object (`Record<string, T>`) can only be strings. To use an object as a key, you must manually call `toString()` to convert it, which loses the object identity. Different objects may produce the same string key after conversion, causing overwrites.

<!-- @[object_key_with_record](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Use an ordinary object to store object keys, which requires manually calling toString() to convert.
class RecordCacheKey {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }

  toString(): string {
    return `key-${this.id}`;
  }
}

let recordKey: RecordCacheKey = new RecordCacheKey(1);
let recordCache: Record<string, string> = {};
recordCache[recordKey.toString()] = 'value';
console.info(`${recordCache[recordKey.toString()]}`); // value
```

Recommended approach: Use `Map` to store object keys, which preserves object identity and requires no manual conversion.

<!-- @[object_key_with_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
class CacheKey {
  public id: number;

  constructor(id: number) {
    this.id = id;
  }
}

let key: CacheKey = new CacheKey(1);

let cache: Map<CacheKey, string> = new Map();
cache.set(key, 'value');
console.info(`${cache.get(key)!}`); // value
```

Anti-pattern 5: Modifying an input parameter that should only be read.

<!-- @[readonly_array_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
// Anti-pattern: The array passed by the caller is modified.
function appendDefault(items: string[]): void {
  items.push('default');
}

// Recommended: Declare it as ReadonlyArray in read-only scenarios.
function countItems(items: ReadonlyArray<string>): number {
  return items.length;
}
```

## Advanced Array Methods

Arrays provide functional methods such as `map`, `filter`, `reduce`, `sort`/`reverse`, and `flat`/`flatMap`, which support chained composition to build a "filter → transform → aggregate" data processing pipeline. These methods return a new array (except `sort`/`reverse`) and do not modify the original array.

### map: Map Each Element

`map` applies a transformation to each element of the array and returns a new array.

<!-- @[array_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let amNumbers: number[] = [1, 2, 3, 4, 5];

let amDoubled: number[] = amNumbers.map((n: number): number => n * 2);
console.info(`${amDoubled.join(', ')}`);  // 2, 4, 6, 8, 10

let amStrings: string[] = amNumbers.map((n: number): string => `Item ${n}`);
console.info(`${amStrings.join(', ')}`);  // Item 1, Item 2, Item 3, Item 4, Item 5
```

### filter: Filtering Elements

The `filter` method runs a predicate function on each element of the array and returns a new array consisting of all elements that satisfy the condition, while the original array remains unchanged. It is commonly used for data filtering, such as filtering active users from a user list or filtering on-sale products from a product list.

<!-- @[array_filter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let afNumbers: number[] = [1, 2, 3, 4, 5, 6];

let afEvens: number[] = afNumbers.filter((n: number): boolean => n % 2 === 0);
console.info(`${afEvens.join(', ')}`);  // 2, 4, 6
```

### reduce: Reduce an Array

`reduce` reduces an array to a single value, and an initial value must be provided.

<!-- @[array_reduce](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let arNumbers: number[] = [1, 2, 3, 4, 5];

let arSum: number = arNumbers.reduce((acc: number, n: number): number => acc + n, 0);
console.info(`${arSum.toString()}`);  // 15

let arProduct: number = arNumbers.reduce((acc: number, n: number): number => acc * n, 1);
console.info(`${arProduct.toString()}`);  // 120
```

### sort and reverse: Sorting

The `sort` method sorts array elements in place and accepts an optional comparison function to customize the sorting rule. The `reverse` method reverses the order of array elements. Both modify the original array. To preserve the original array, call `slice()` to create a copy before sorting.

<!-- @[array_sort](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let asNumbers: number[] = [3, 1, 4, 1, 5, 9, 2, 6];

let asAscending: number[] = [...asNumbers].sort((a: number, b: number): number => a - b);
console.info(`${asAscending.join(', ')}`);  // 1, 1, 2, 3, 4, 5, 6, 9

let asDescending: number[] = [...asNumbers].sort((a: number, b: number): number => b - a);
console.info(`${asDescending.join(', ')}`);  // 9, 6, 5, 4, 3, 2, 1, 1

let asReversed: number[] = [...asNumbers].reverse();
console.info(`${asReversed.join(', ')}`);  // 6, 2, 9, 5, 1, 4, 1, 3
```

### Combining map, filter, and reduce

`map`, `filter`, and `reduce` can be combined through chained calls to implement a "filter → transform → aggregate" data processing pipeline. For example, use `filter` to select valid data, then `map` to extract key fields, and finally `reduce` to compute the aggregate value. In chained calls, each step returns a new array without affecting the original data.

<!-- @[array_chain](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
interface AcProduct {
  name: string;
  price: number;
  category: string;
}

let acProducts: AcProduct[] = [
  { name: 'Laptop', price: 999, category: 'Electronics' },
  { name: 'Mouse', price: 25, category: 'Electronics' },
  { name: 'Book', price: 15, category: 'Books' },
  { name: 'Keyboard', price: 75, category: 'Electronics' }
];

let acTotal: number = acProducts
  .filter((p) => p.category === 'Electronics')
  .map((p) => p.price)
  .reduce((acc: number, price: number) => acc + price, 0);

console.info(`Electronics total: ${acTotal}`);  // 1099
```

### flat and flatMap

`flat()` flattens a nested array into a one-dimensional array, and you can specify the flattening depth. `flatMap()` first applies a mapping function to each element and then flattens the result by one level, which is equivalent to calling `map()` followed by `flat()`. It is commonly used to transform and flatten nested structures. Both can also be implemented manually with `reduce` and the spread operator to achieve the same effect.

<!-- @[flat_flatmap_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let ffnNested: number[][] = [[1, 2], [3, 4], [5, 6]];

// flat: Flatten a two-dimensional array into a one-dimensional array.
let ffnFlat: number[] = ffnNested.flat();
console.info(`${ffnFlat.join(', ')}`); // 1, 2, 3, 4, 5, 6

// flatMap: Map each element and then flatten by one level.
let ffnWords: string[] = ['hello world', 'foo bar'];
let ffnFlatMapped: string[] = ffnWords.flatMap((s: string): string[] => s.split(' '));
console.info(`${ffnFlatMapped.join(', ')}`); // hello, world, foo, bar

// Use reduce and the spread operator instead of flat.
let ffnFlatReduce: number[] = ffnNested.reduce((acc: number[], arr: number[]): number[] => {
  return [...acc, ...arr];
}, []);
console.info(`${ffnFlatReduce.join(', ')}`); // 1, 2, 3, 4, 5, 6
```

## Manual Traversal with Iterators

Obtain an iterator through `values()` and use the `next()` method to manually control the traversal pace.

<!-- @[iterator_manual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Collections.ets) -->

``` TypeScript
let imArr: number[] = [10, 20, 30];
let imIter: IterableIterator<number> = imArr.values();

let imResult: IteratorResult<number> = imIter.next();
while (!imResult.done) {
  console.info(`${imResult.value.toString()}`);
  imResult = imIter.next();
}
// Output: 10, 20, 30

// Set iterator
let imSet: Set<string> = new Set<string>();
imSet.add('a');
imSet.add('b');
let imSetIter: IterableIterator<string> = imSet.values();
let imSetResult: IteratorResult<string> = imSetIter.next();
while (!imSetResult.done) {
  console.info(`${imSetResult.value}`);
  imSetResult = imSetIter.next();
}
// Output: a, b

// Map iterator
let imMap: Map<string, number> = new Map<string, number>();
imMap.set('x', 10);
imMap.set('y', 20);
let imMapIter: IterableIterator<[string, number]> = imMap.entries();
let imMapResult: IteratorResult<[string, number]> = imMapIter.next();
while (!imMapResult.done) {
  let entry: [string, number] = imMapResult.value;
  console.info(`${entry[0]}: ${entry[1]}`);
  imMapResult = imMapIter.next();
}
// Output: x: 10, y: 20
```