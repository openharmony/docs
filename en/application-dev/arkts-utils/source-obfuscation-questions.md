# Common Issues with ArkGuard in Source Code Obfuscation
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @zju-wyx-->
<!--Designer: @xiao-peiyang; @dengxinyu-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

## Troubleshooting Functional Issues

### Procedure
1. Configure the `-disable-obfuscation` option in the `obfuscation-rules.txt` file to disable obfuscation, and check whether the issue is caused by obfuscation.
2. If the issue is related to obfuscation, review the documentation to understand the capabilities of obfuscation rules and understand when to configure trustlists to avoid issues. The following describes the four options that are enabled by default. For details, see the description of each option.
    1. [-enable-toplevel-obfuscation](source-obfuscation.md#-enable-toplevel-obfuscation): obfuscates top-level scope names.

    2. [-enable-property-obfuscation](source-obfuscation.md#-enable-property-obfuscation): obfuscates property names. Use [-keep-property-name](source-obfuscation.md#-keep-property-name) to configure a trustlist for property names used in network calls, JSON field, dynamic accesses, and so library interfaces.

    3. [-enable-export-obfuscation](source-obfuscation.md#-enable-export-obfuscation): obfuscates imported or exported names. Generally, this option is used together with `-enable-toplevel-obfuscation` and `-enable-property-obfuscation`. You need to use [-keep-global-name](source-obfuscation.md#-keep-global-name) to configure a trustlist for exported or imported names in scenarios where external APIs of the module cannot be obfuscated.

    4. [-enable-filename-obfuscation](source-obfuscation.md#-enable-filename-obfuscation): obfuscates file names. Use [-keep-file-name](source-obfuscation.md#-keep-file-name) to configure a trustlist for file paths and names in dynamically import or runtime loading scenarios.
3. If your issue matches any typical cases listed below, apply the suggested solutions.
4. If the issue is not covered, use a positive approach to identify the problem (remove specific configuration items if the corresponding functionality is not needed).
5. Analyze runtime crashes as follows:
    1. Open the application runtime logs or click the** Crash** dialog box in DevEco Studio to find the crash stack.
    2. The line numbers in the exception stack match the [compiled product](source-obfuscation-guide.md#viewing-obfuscation-effects), and method names might be obfuscated. Therefore, you are advised to check the compiled product based on the exception stack, analyze the names that cannot be obfuscated, and add them to the trustlist.
6. Analyze functional exceptions (for example, white screens) as follows:
    1. Opening the application runtime logs: Select HiLog and search for logs directly related to the exceptions.

    2. Locating the problematic code segment: Identify the specific code block causing the exceptions through log analysis.

    3. Enhancing log output: Add log printing in the suspected code to check whether the data is normal.

    4. Analyzing and identifying critical fields: Determine if the data exception is caused by obfuscation through the enhanced log output.

    5. Configuring a trustlist for critical fields: Add fields that directly affect application functionality after obfuscation to the trustlist.

### Troubleshooting Unexpected Obfuscation Behavior
If unexpected obfuscation behavior occurs, check whether certain obfuscation options are configured for the dependent local modules or third-party libraries.

Example:
If `-compact` is not configured for the current module, but the code in the obfuscated intermediate product is compressed into a single line, perform the following steps:

1. Check the **dependencies** field in the **oh-package.json5** file of the current module to identify dependencies.
2. Search for **-compact** in the obfuscation configuration file of the dependent modules or third-party libraries.
    * Search for **-compact** in the **consumer-rules.txt** file in the local libraries.
    * Search for **-compact** in all **obfuscation.txt** files in the project-level **oh_modules** directory.

From API version 18 onwards, the obfuscation options in the `obfuscation.txt` file of third-party libraries are not merged in the main module by default. The retained options are still valid.

> **NOTE**
> 
> You are not advised to configure the following options in the **consumer-rules.txt** file of third-party libraries. These options will take effect when obfuscation is enabled in the main module, potentially causing unexpected obfuscation results and even application crashes at runtime. If you find that the **obfuscation.txt** file of a third-party library includes these options, you are advised to contact the team that released the third-party library to remove these options and repackage and release the library. 
> -enable-property-obfuscation  
> -enable-string-property-obfuscation  
> -enable-toplevel-obfuscation  
> -remove-log  
> -compact

## Typical Error Cases and Solutions

### "Error message: Cannot read property xxx of undefined"

**Symptom**

The obfuscation rule configuration is as follows:

```
-enable-property-obfuscation
```

The sample code is as follows:

```ts
// Example JSON file structure (test.json):
/*
{
  "jsonObj": {
    "jsonProperty": "value"
  }
}
*/

// Before obfuscation:
import jsonData from "./testjson";

let jsonProp = jsonData.jsonObj.jsonProperty;

// After obfuscation:
import jsonData from "./test.json";

let jsonProp = jsonData.i.j;
```

**Possible Causes**

After property obfuscation is enabled, the source code will be obfuscated, but the JSON file will not. When the property is accessed using `jsonData.i` in the source code, the property name has been obfuscated, and the corresponding field does not exist in the JSON data. As a result, the obtained value is `undefined`.

**Solution**

Add the fields used in JSON files to the property trustlist. Example:

```
-keep-property-name
jsonObj
jsonProperty
```

### "Error message: is not callable"

**Scenario 1: Exported Method in Namespace with Mismatched Obfuscation**

**Symptom**

The obfuscation rule configuration is as follows:

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

The sample code is as follows:

```ts
// Before obfuscation:
// export.ts
export namespace NS {
  export function foo() {}
}

// import.ts
import { NS } from './export';

NS.foo();
```

```ts
// After obfuscation:
// export.ts
export namespace i {
  export function j() {}
}

// import.ts
import { i } from './export';

i.foo();
```

**Possible Causes**

**foo** in the namespace is an export element and is considered as a property when being called by `NS.foo`. Because the `-enable-property-obfuscation` option is not configured, the property name is not obfuscated during the call.

**Solution**

Solution 1: Configure the `-enable-property-obfuscation` option.

Solution 2: Use the `-keep-global-name` option to configure the methods exported from the namespace to the trustlist. Example:

```
-keep-global-name
foo
```

**Scenario 2: Dynamic Import of a Class with Mismatched Obfuscation**

**Symptom**

The obfuscation rule configuration is as follows:

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

The sample code is as follows:

```ts
// Before obfuscation:
// utils.ts
export function addNum(a: number, b: number): number {
  return a + b;
}

// main.ts
async function loadAndUseAdd() {
  try {
    const mathUtils = await import('./utils');
    const result = mathUtils.addNum(2, 3);
  } catch (error) {
    console.error('Failure reason:', error);
  }
}

loadAndUseAdd();
```

```ts
// After obfuscation:
// utils.ts
export function c1(d1: number, e1: number): number {
    return d1 + e1;
}

// main.ts
async function i() {
    try {
        const a1 = await import("@normalized:N&&&entry/src/main/ets/pages/utils&");
        const b1 = a1.addNum(2, 3);
    }
    catch (z) {
        console.error('Failure reason:', z);
    }
}
i();
```

**Possible Causes**

The **addNum** function is in the top-level scope when it is defined, but is considered as a property when it is accessed through `.addNum`. Because the `-enable-property-obfuscation` option is not configured, the property name is not obfuscated during the call.

**Solution**

Solution 1: Configure the **-enable-property-obfuscation** option.

Solution 2: Use `-keep-global-name` to configure **add** to the trustlist. Example:

```txt
-keep-global-name
addNum
```

**Scenario 3: Crash Caused by Calling Methods in SO Library**

**Symptom**

The obfuscation rule configuration is as follows:

```
-enable-property-obfuscation
-enable-export-obfuscation
```

The sample code is as follows:

```ts
// src/main/cpp/types/libentry/Index.d.ts
export const addNum: (a: number, b: number) => number;
```

```ts
// example.ets
// Before obfuscation:
import testNapi from 'libentry.so';

testNapi.addNum();
```

```ts
// example.ets
// After obfuscation:
import testNapi from "@normalized:Y&&&libentry.so&";

testNapi.m();
```

**Possible Causes**

The obfuscation tool only supports obfuscation of `js/ts/ets` code. Methods in the SO library are defined at the C++ level, so they remain unobfuscated where they are defined. However, when these methods are called from other places, the calling code gets obfuscated.

**Solution**

Add the methods exported from the SO library to the property trustlist. Example:

```txt
-keep-property-name
addNum
```

### Error Message: 'module1/file1' does not provide an export name 'x', which is imported by 'module2/file2'

**Symptom**

The obfuscation rule configuration for the main module and HSP module is as follows:

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

The sample code is as follows:

```ts
// Before obfuscation:
// HSP module
export function addNum() {}

// Entry module
import { addNum } from 'hsp';

addNum();
```

```ts
// After obfuscation:
// HSP module
export function b() {}

// Entry module
import { n } from '@normalized:N&myhsp&&myhsp/Index&';

n();
```

**Possible Causes**

When both `-enable-toplevel-obfuscation` and `-enable-export-obfuscation` are configured, the obfuscation of the main module and called module is as follows:

| Main Module| Dependent Module| Imported/Exported Name Obfuscation|
| ------- | ------- | ----------------------------|
| HAP/HSP | HSP     | The HSP and main module are independently compiled, resulting in inconsistent obfuscated names. Both need trustlist configurations.|
| HAP/HSP | Local HAR| The local HAR is compiled together with the main module, resulting in consistent obfuscated names.|
| HAP/HSP | Third-party library | Exported names and their properties in third-party libraries are collected into the trustlist, so they are not obfuscated during import/export.|

HAP and HSP modules are compiled independently. As a result, the import and export names are different after obfuscation, and an error is reported when HAP references methods of HSP.

**Solution**

Configure the methods exported by the HSP module under `-keep-global-name`, and make corresponding configurations in both the `consumer-rules.txt` and `obfuscation-rules.txt` files of the HSP. Example:

```txt
// consumer-rules.txt
-keep-global-name
addNum

// obfuscation-rules.txt
-keep-global-name
addNum
```

## Exception Without Crash Information After App Launch

### Properties Obfuscated When Record<string, Object> Is Used as an Object Type

**Symptom**

When `Record<string, Object>` is used as an object type, properties like `linkSource` are obfuscated, causing the error.

The sample code is as follows:

```ts
// Before obfuscation:
import { Want } from '@kit.AbilityKit';

let petalMapWant: Want = {
  bundleName: 'com.example.myapplication',
  uri: 'maps://',
  parameters: {
    linkSource: 'com.other.app'
  }
}
```

```ts
// After obfuscation:
import type Want from "@ohos:app.ability.Want";

let petalMapWant: Want = {
    bundleName: 'com.example.myapplication',
    uri: 'maps://',
    parameters: {
        i: 'com.other.app'
    }
};
```

**Possible Causes**

The type `Record<string, Object>` is a generic definition for an object with string keys and does not describe the internal properties in detail. Therefore, the obfuscation tool cannot identify which properties should not be obfuscated. As a result, after `linkSource` is obfuscated, an exception occurs.

**Solution**

Add the problematic property names to the property trustlist. The following is an example:

```
-keep-property-name
linkSource
```

### Property Name Obfuscation Inconsistency Across Files

**Symptom**

The obfuscation rule configuration is as follows:

```
-enable-property-obfuscation
-keep
./file1.ts
```

Import an API of `file1.ts` to `file2.ts`. The API contains an object property, which is retained in `file1.ts` but obfuscated in `file2.ts`. As a result, an exception occurs during invoking.

The sample code is as follows:

```ts
// Before obfuscation:
// file1.ts
export interface MyInfo {
  age: number;
  address: {
    city1: string;
  }
}

// file2.ts
import { MyInfo } from './file1';

const person: MyInfo = {
  age: 20,
  address: {
    city1: "shanghai"
  }
}
```

```ts
// After obfuscation:
// file1.ts
export interface MyInfo {
  age: number;
  address: {
    city1: string;
  }
}

// file2.ts
import { MyInfo } from './file1';

const person: MyInfo = {
  age: 20,
  address: {
    i: "shanghai"
  }
}
```

**Possible Causes**

The `-keep` option retains the code in the `file1.ts` file, but properties within exported types (for example, **address**) are not automatically added to the property trustlist. Therefore, the properties are obfuscated when being used in other files.

**Solution**

Solution 1: Define the property type using `interface` and export it. This will automatically add the property to the trustlist. Example:

```ts
// file1.ts
export interface AddressType {
  city1: string;
}
export interface MyInfo {
  age: number;
  address: AddressType;
}
```

Solution 2: Use the **-keep-property-name** option to add properties within types that are not directly exported to the trustlist. Example:

```
-keep-property-name
city1
```

### String Literal Property Names Obfuscated When -enable-string-property-obfuscation Is Not Configured

**Symptom**

```ts
// Before obfuscation:
const person = {
  myAge: 18
}
person["myAge"] = 20;
```

```ts
// After obfuscation:
const person = {
  myAge: 18
}
person["m"] = 20;
```

**Possible Causes**

`-enable-string-property-obfuscation` is configured in the `consumer-rules.txt` file of other modules on which the main module depends. The main module combines this option, resulting in the obfuscation of string literal property names.

**Solution**

Since API version 18, the obfuscation rules of third-party libraries are not affected by the main module by default. If the API version is earlier than 18, you can use either of the following solutions:

Solution 1: Check whether the `-enable-string-property-obfuscation` option is configured in the `obfuscation.txt` file of the remote HAR. If it is configured, the main module will be affected. In this case, you need to disable it. For details, see [Troubleshooting Unexpected Obfuscation Behavior](source-obfuscation-questions.md#troubleshooting-unexpected-obfuscation-behavior).
Solution 2: If the project is complex and the remote HAR that contains the obfuscation option cannot be found, you can add the property name to the trustlist.

### Exception Caused by Obfuscated Database Fields

**Symptom**

The error information in the hilog file is as follows: `table Account has no column named a23 in 'INSERT INTO Account(a23)'`

**Possible Causes**

The SQL statement uses obfuscated field names, whereas the database expects the original names.

**Solution**

Use the `-keep-property-name` option to add the database fields to the trustlist.
