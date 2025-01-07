# ArkTS Modular Loading


##  Error Messages Related to Modular Loading Displayed at the Runtime of ArkTS Applications
### "Cannot find dynamic-import module 'xxxx'"

This error indicates that the module to load is not compiled into the application package.

**Possible cause**

An expression is dynamically loaded as an input parameter, but the module path is incorrect.
``` typescript
  import(module).then(m=>{m.foo();}).catch((e: Error)=>{console.info(e.message)});
```

**Locating method**

Print the path information of the module, and check whether the path is correct.

### "Cannot find module 'xxxx' , which is application Entry Point" 
This error indicates that the entry file is not found during application startup.

**Possible cause**

The entry file is not found during application startup.

**Locating method**

(1) Open the application's project-level build file **module.json5** in the **entry/src/main** directory.


The following is an example of some parameters in **module.json5**.
```
{
  "module": {
    "name": "entry",
    "type": "entry",
    ...
    "abilities": [
      {
        "name": "EntryAbility", // Module name.
        "srcEntry": "./ets/entryability/EntryAbility.ts",  // Relative path of the src directory to the project root directory.
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
  }
}
```
(2) Check the value of **srcEntry** under **abilities** in **module.json5**. This parameter specifies the path of the entry file.

### "No export named 'xxxx' which exported by 'xxxx'"
This error indicates that no specific object is found in the module when the .so file in the HAP or HAR of the application is being loaded.

**Possible cause**

The dependency between modules is pre-parsed in the static build phase of the module. If the imported variable name in the .ets file is incorrect, an error message is displayed in DevEco Studio. An error message is also displayed in the application build phase. Note that the dependency of native C++ modules in the application is checked only at runtime.

**Locating method**

Check whether the .so file in the application contains the exported variable that causes the error, and compare the exported variable with the imported variable in the .so file. If they are inconsistent, modify the variable.


## Failure in Loading .so Files

If a .so file fails to be loaded, a JS error indicating loading failure is not explicitly thrown. You can check whether the exported object is **undefined** to determine the loading status of the .so file.

**Loading failure symptom** 

| Loading Type| TS/JS Module| System Library/Application .so File|
| -------- | -------- | -------- |
| Static loading| The VM automatically throws an error and the process exits.| No error is thrown, and the loaded object is **undefined**.|
| Dynamic loading| No error is proactively thrown and the program reaches the reject branch. You can call the **catch** method to capture the error.| No error is proactively thrown and the program reaches the resolve branch. You can check whether the variable exported by the module is **undefined** in the branch.|

**Example 1: Static loading of the system library/application .so file fails.**

```
import testNapi from 'libentry.so'

if (testNapi == undefined) {
  console.error('load libentry.so failed.');
}
```

Command output:
```
load libentry.so failed.
```

**Example 2: Dynamic loading of the system library/application .so file fails.**

```
import('libentry.so')
  .then(m => {
    if (typeof m.default === 'undefined') {
      console.warn(`load libentry.so failed.`);
    } else {
      console.info('load libentry.so success:', m);
    }
    return m;
  })
  .catch((e: Error) => {
    console.error('load libentry.so error:', e);
  });
```

Command output:
```
load libentry.so failed.
```

**Possible cause, locating method, and solution** 

For details, see [Node-API FAQs](https://gitee.com/openharmony/docs/blob/master/en/application-dev/napi/use-napi-faqs.md).


## Initialization Errors at Runtime Caused by Inter-Module Circular Dependency
### Locating Circular Dependencies
The error message "xxx is not initialized" may not be caused by circular dependencies. You need to enable the switch for further confirmation.
```
Enable the switch by running option: hdc shell param set persist.ark.properties 0x2000105c.
After the switch is enabled, run the hdc shell reboot command to restart the device.
Disable the switch by running option: hdc shell param set persist.ark.properties 0x0000105c.
After the switch is disabled, run the hdc shell reboot command to restart the device.
```
Once the switch is enabled, the error that appears is treated as the initial error occurrence. Rectify the error. If the error message "xxx is not initialized" is still displayed, the error is caused by circular dependencies.

### Circular Dependency Principle
1. Module loading sequence 

   According to the ECMAScript specification, the module execution sequence is the sequence of deep traversal loading.

   If the application has a loading link A -> B -> C, then the ArkTS module executes file C, file B, and file A in sequence. 

2. Circular dependency 

   In an application with a loading sequence of A -> B -> A, following the execution sequence of deep traversal, file A's status is initially set to loading. The process then moves to load file B and sets its status to loading before returning to file A. Given that file A is already marked as in the loading phase, as per the defined protocol, the system will bypass modules that are already loading, resulting in file B being executed prior to file A.

   Why do some circular dependencies have no impact but some cause applications to crash?

   As mentioned earlier, even though file B depends on variables from file A, file B runs before file A. If the variables from file A that are imported into file B are not used in the global scope or as static class members, file B will execute normally. However, if file B accesses the variables from file A globally or through the instantiation of classes or other similar methods, which leads to the use of these variables during its execution, the error message "xxx is not initialized" is displayed. This occurs because the circular dependency results in the variables not being initialized in time.

Example:
``` typescript
// A.ets
import { Animal } from './B'
export let a = "this is A";
export function A() {
  return new Animal;
}

// ---------------------

// B.ets
import { a } from './A'
export class Animal {
  static {
    console.log("this is in class");
    let str = a; // Error: a is not initialized
  }
}
```
**Recommended**

``` typescript
// B.ets
import { a } from './A'
export class Animal {
  static {
    console.log("this is in class");
  }
  str = a; // Modification point
}
```

### Solution to Circular Dependencies
[@security/no-cycle](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide_no-cycle-V5)


##  Example Error Scenarios Because ArkTS Symbols Are Not Initialized

The ArkTS coding specification is a subset of the ECMAScript specification. When a symbol that has not been initialized is accessed, an error is thrown during runtime. The following common error scenarios are provided to help you locate and rectify source code errors:

### Access Before const/let Declaration

``` typescript
console.log(a); // Error: Variable 'a' is used before being assigned.
console.log(b); // Error: Variable 'b' is used before being assigned.

let a = '1';
const b = '2';
```
**Recommended**

```
let a = '1';
const b = '2';

console.log(a);
console.log(b);
```


### Instantiation Before Class Declaration

``` typescript
let a = new A(); // Error: Class 'A' used before its declaration.

class A {}
```

**Recommended**

```
class A {}

let a = new A();
```

### Accessing Static Properties of a Class Before Declaration

``` typescript
let a = A.a; // Error: Class 'A' used before its declaration.

class A {
  static a = 1;
}
```

**Recommended**

```
class A {
  static a = 1;
}

let a = A.a;
```

### Accessing let and const That Are Not Declared in a Function

``` typescript
foo(); // Error: Error message:a is not initialized

let a = 1;
const b = 2;

function foo() {
  let v = a + b;
}
```

**Recommended**

```
let a = 1;
const b = 2;

function foo() {
  let v = a + b;
}

foo();
```

### Accessing Static Properties of a Class That Is Not Declared in a Function

``` typescript
foo(); // Error: Error message:A is not initialized

class A {
  static a = 1;
}

function foo() {
  let v = A.a;
  let w = new A();
}
```

**Recommended**

```
class A {
  static a = 1;
}

function foo() {
  let v = A.a;
  let w = new A();
}

foo();
```

### Inter-Module Circular Dependency - const/let

``` typescript
// module1.ets
import { a, b } from './module2'

export let i = 1;
export let m = a;
export const j = 2;
export const n = b;

// ---------------------

// module2.ets
import { i, j } from './module1'

export let a = i; // Error: Error message:i is not initialized
export const b = j; // Error: Error message:j is not initialized
```

**Solution**

For details, see [Solution to Circular Dependencies](#solution-to-circular-dependencies).


### Inter-Module Circular Dependency - Class

``` typescript
// class1.ets
import { b } from './class2'

export class A {
  static a = b;
}

// ---------------------

// class2.ets
import { A } from './class1'
export let b = 1;

const i = A.a; // Error: Error message:A is not initialized
const j = new A(); // Error: Error message:A is not initialized
```

**Solution**

For details, see [Solution to Circular Dependencies](#solution-to-circular-dependencies).
