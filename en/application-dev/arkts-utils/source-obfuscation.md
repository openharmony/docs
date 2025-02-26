# ArkGuard for Code Obfuscation

## Overview

Source code obfuscation helps reduce the risk of application hacking as well as the application package size by shortening class names and member names.

>**NOTE**
>
> 1. In DevEco Studio versions prior to 5.0.3.600, code obfuscation is enabled by default for new projects, and code developed on the stage model using API version 10 or later is automatically obfuscated. This applies only to code compiled in [release mode](#remarks), and obfuscation applies only to parameter names and local variable names.
> 2. In DevEco Studio 5.0.3.600 and later versions, code obfuscation is disabled by default for new projects. If you want to enable obfuscation, set the **ruleOptions.enable** field in the **build-profile.json5** file of the module to **true**. The **obfuscation-rules.txt** file has the following options enabled by default: **-enable-property-obfuscation**, **-enable-toplevel-obfuscation**, **-enable-filename-obfuscation**, and **-enable-export-obfuscation**. You can customize the obfuscation settings as needed. Enabling the four options may cause the application to crash at runtime. You are advised to read [Enabling Code Obfuscation](#enabling-code-obfuscation) to rectify the fault.

### Constraints

* Only the projects developed on the stage model are supported.
* The build mode of the project is release.
* The **disable-obfuscation** option is not configured for the module and the HAR on which the module depends.

### Code Obfuscation Scope

In a project, the following files can be obfuscated, and the cache files after obfuscation are stored in **build/[...]/release** in the module directory.

* ArkTS files
* TS files
* JS files

## Enabling Code Obfuscation

Code obfuscation has been integrated into the system and can be enabled for use in DevEco Studio.

Currently, only name obfuscation is provided. Other obfuscation capabilities deteriorate performance. You can use code obfuscation to obfuscate the following names:

* Parameter names and local variable names 
* Top-level scope names 
* Property names
* Exported names
* File names

After code obfuscation is enabled, parameter names and local variable names will be obfuscated by default. No option needs to be configured. Obfuscation of top-level scope name, property names, exported names, and file names may cause runtime errors. You can enable or disable these obfuscation capabilities by configuring obfuscation options.

When a module is created, the following content is automatically generated in the module-level build-profile.json5 file:

```
"arkOptions": {
  "obfuscation": {
    "ruleOptions": {
      "enable": true,
      "files": ["./obfuscation-rules.txt"],
    }
  }
}
```

When a library is created, the **consumerFiles** field is automatically generated in addition to the preceding content.

```
"arkOptions": {
  "obfuscation": {
    "ruleOptions": {
      "enable": true,
      "files": ["./obfuscation-rules.txt"],
    }
    "consumerFiles": ["./consumer-rules.txt"]
  }
}
```

If you disable code obfuscation and then want to enable it again, the value of **ruleOptions.enable** must be **true**.

The obfuscation configuration files specified in the **ruleOptions.files** field take effect when the HAP, HSP, or HAR is built.

The obfuscation configuration files specified in the **consumerFiles** field take effect when the module that depends on the library is built. The contents of these obfuscation configuration files are also merged into the **obfuscation.txt** file in the HAR.

During the build of the HAP, HSP, or HAR, the final obfuscation rules are the combination of the **ruleOptions.files** field of the current module, the **consumerFiles** field of the dependent library, and the **obfuscation.txt** file in the dependent HAR. 

During HAR build, the **obfuscation.txt** file in the HAR contains the combination of the **consumerFiles** field of the current HAR, the **consumerFiles** field of the dependent library, and the **obfuscation.txt** file in the dependent HAR. No **obfuscation.txt** file is generated during HAP or HSP build. For details about the merging strategies, see [Obfuscation Rule Merging Strategies](#obfuscation-rule-merging-strategies).

### Obfuscation Rule Configuration File

During the creation of a project or library, DevEco Studio automatically generates the **obfuscation-rules.txt** and **consumer-rules.txt** files. You can write obfuscation rules into these files or other user-defined files, and then add the file paths in **ruleOptions.files** and **consumerFiles**, as shown in the following example.

```
"buildOption": {
  "arkOptions": {
    "obfuscation": {
      "ruleOptions": {
        "enable": true,
        "files": ["./obfuscation-rules.txt", "./myrules.txt"], // Place myrules.txt in the same directory as the build-profile.json5 file.
      }
      "consumerFiles": ["./consumer-rules.txt", "./my-consumer-rules.txt"]
    }
  }
}
```

## Configuring Obfuscation Rules

There are two types of obfuscation rules: [obfuscation options](#obfuscation-options) and [retention options](#retention-options). The former provides a switch for multiple obfuscation capabilities, such as obfuscation of top-level scope names, property names, and file names. The latter provides the trustlist configuration of various obfuscation capabilities.

**NOTE**

Any modification to the obfuscation configuration file takes effect only after a full build of the application.

### Obfuscation Options

#### -disable-obfuscation

Disables code obfuscation. If this option is used, the built HAP, HSP, or HAR is not obfuscated.

#### -enable-property-obfuscation

Enables property obfuscation. If this option is used, all property names except the following are obfuscated:

* Property names of classes and objects that are directly imported or exported by using **import** or **export**. For example, the property name **data** in the following example is not obfuscated.

    ```
    export class MyClass {
       data: string;
    }
    ```

* Property names in ArkUI components. For example, **message** and **data** in the following example are not obfuscated.

    ```
    @Component struct MyExample {
        @State message: string = "hello";
        data: number[] = [];
        // ...
    }
    ```

* Property names specified by [retention options](#retention-options).
* Property names in the SDK API list. The SDK API list is a set of names automatically extracted from the SDK during build. Its cache file is **systemApiCache.json**, which is stored in **build/default/cache/{...}/release/obfuscation** in the project directory.
* String literal property names. For example, **"name"** and **"age"** in the following example are not obfuscated.

    ```
    let person = {"name": "abc"};
    person["age"] = 22;
    ```

    If you want to obfuscate the string literal property name, use the **-enable-string-property-obfuscation** option in addition to the current option, Example:

    ```
    -enable-property-obfuscation
    -enable-string-property-obfuscation
    ```

    **NOTE** 

    **1.** If a string literal property name in the code contains special characters, for example, **let obj = {"\n": 123, "": 4, " ": 5}**, you are advised not to use the **-enable-string-property-obfuscation** option because these names may fail to be kept using [retention options](#retention-options). Special characters refer to characters other than lowercase letters a-z, uppercase letters A-Z, digits 0-9, and underscores (_). 
    **2.** The property trustlist of the SDK API list does not contain the string constants used in the declaration file. For example, the string **'ohos.want.action.home'** in the example is not included in the property trustlist.

    ```
    // Part of the SDK API file @ohos.app.ability.wantConstant:
    export enum Params {
      ACTION_HOME = 'ohos.want.action.home'
    }
    // Source code example:
    let params = obj['ohos.want.action.home'];
    ```

    When the **-enable-string-property-obfuscation** option is used, use the retention option if you want to retain the property names of the SDK API string constants used in the source code, for example, **obj['ohos.want.action.home']**.

#### -enable-toplevel-obfuscation

Enables top-level scope name obfuscation. If this option is used, all names of all top-level scopes except the following are obfuscated:

* Top-level scope names imported or exported using the **import** or **export** statement.
* Top-level scope names that are not declared in the current file.
* Top-level scope names specified by [retention options](#retention-options).
* Top-level scope names in the SDK API list.

#### -enable-filename-obfuscation

Enables file or folder name obfuscation. If this option is used, all file or folder names are obfuscated. For example:

```
// Both directory and filename are confused.
import func from '../directory/filename';
import { foo } from '../directory/filename';
const module = import('../directory/filename');
```

In addition to the following scenarios:

* File or folder names specified by the **main** and **types** fields in the **oh-package.json5** file.
* File or folder names specified by the **srcEntry** field in the **module.json5** file of the module.
* File or folder names specified by [-keep-file-name](#retention-options).
* File or folder names in non-ECMAScript module reference mode (an example in ECMAScript module reference mode, `import {foo} from './filename'`).
* File or folder names in non-path reference mode. For example, **json5** in the example **import module from 'json5'** is not obfuscated.

**NOTE** 

The system loads certain files during application running. For these files, manually configure a trustlist in the [`-keep-file-name`] option to prevent them from being obfuscated. Otherwise, the application may fail to run.
In the following scenarios, you need to manually configure a trustlist: 

* The module contains an ability component. In this case, add all paths configured for **srcEntry** under the **abilities** field in **src/main/module.json5** to the trustlist. 
* The module contains the multithreading service: Worker. In this case, add all paths under the **buildOption'-'sourceOption'-'workers'** field in **build-profiles.json5** to the trustlist.

**NOTE** 

The names of the compilation entry file, ability component file, and Worker multithreaded file cannot be obfuscated and have been automatically added to the trustlist in DevEco Studio 5.0.3.500. No manual configuration is required. For other files that cannot be obfuscated, you need to manually configure their names in the trustlist.

#### -enable-export-obfuscation

Enables obfuscation for names of classes or objects that are directly imported or exported and their property names. If this option is used, the names directly imported or exported in the module are obfuscated, except the following:

* Names of classes or objects exported from remote HARs (packages whose real paths are in **oh_modules**) and their property names are not obfuscated.
* Names and property names specified by [retention options](#retention-options) are not obfuscated.
* Names in the SDK API list are not obfuscated.

**NOTE**

1. To obfuscate property names in imported or exported classes, use both the **-enable-property-obfuscation** and **-enable-export-obfuscation** options. 
2. If the **-enable-export-obfuscation** option is used during HSP build, the externally exposed interfaces must be kept in the **obfuscation-rules.txt** file of the module.
3. During the build of an HAP, an HSP, and an HSP-dependent HAR, if the **-enable-export-obfuscation** option is used, the interfaces imported from the HSP must be kept in the **obfuscation-rules.txt** file in the module. 

    ```
    // Code example (entry file Index.ets in the HSP):
    export { add, customApiName } from './src/main/ets/utils/Calc'

    // Example of retaining an interface name:
    // Configuration of the obfuscation-rules.txt file in the HSP and modules that depend on the HSP:
    -keep-global-name
    add
    customApiName
    ```

#### -compact

Removes unnecessary spaces and all line feeds. If this option is used, all code is compressed to one line.

**NOTE**

The stack information built in release mode contains the line number of code, but not the column number. Therefore, when the **compact** option is used, the source code cannot be located based on the line number in the stack information.

#### -remove-log

Removes the expressions involving direct calls to the **console.** statement in the following scenarios:

1. Calls at the top layer of a file.
2. Calls within a code block. 
3. Calls with a module. 
4. Calls within a **switch** statement.

#### -print-namecache *filepath*

Saves the name cache to the specified file path. The name cache contains mappings before and after name obfuscation. 

**NOTE**

A new **namecache.json** file is generated each time the module if fully built. Therefore, save a copy of the file each time you publish a new version.

#### -apply-namecache *filepath*

Reuses the specified name cache file. The names will be obfuscated according to the cache mappings. If there is no corresponding name, a new random segment name is used.
This option should be used in incremental build scenarios.

By default, DevEco Studio saves cache files in a temporary cache directory and automatically applies the cache files during incremental build. 
Default cache directory: **build/default/cache/{...}/release/obfuscation**

#### -remove-comments

Removes JsDoc comments from the declaration file generated after compilation. 

**NOTE** 

By default, all comments in the source code file generated after the compilation are removed and cannot be retained. 
You can configure **keep-comments** to retain the JsDoc comments in the declaration file.

### Retention Options

#### `-keep-property-name` [,identifiers,...]

Retains the specified property names. Name wildcards are supported. An example is as follows.

```
-keep-property-name
age
firstName
lastName
```

> **NOTE**
>
> - This option takes effect when **-enable-property-obfuscation** is used.
>
> - The property trustlist applies globally. That is, if multiple properties with the same name exist in the code, they will not be confused as long as they match the names in the trustlist configured in **-keep-property-name**.

**Which property names should be retained?**

To ensure correct obfuscation, you are advised to retain all properties that are not accessed using dot notation.

Example:

```
var obj = {x0: 0, x1: 0, x2: 0};
for (var i = 0; i <= 2; i++) {
    console.info(obj['x' + i]);  // x0, x1, and x2 should be retained.
}

Object.defineProperty(obj, 'y', {});  // y should be retained.
console.info(obj.y);

obj.s = 0;
let key = 's';
console.info(obj[key]);        // s should be retained.

obj.u = 0;
console.info(obj.u);           // u will be correctly confused.

obj.t = 0;
console.info(obj['t']);        // When obfuscation of string literal property names is enabled, both t and 't' can be correctly obfuscated. However, it is recommended that 't' be retained.

obj['v'] = 0;
console.info(obj['v']);        // When obfuscation of string literal property names is enabled, 'v' can be correctly obfuscated. However, it is recommended that 'v' be retained.
```

In the case of indirect exports, for example, **export MyClass** and **let a = MyClass; export {a}**, if you do not want to obfuscate property names, use [retention options](#retention-options) to retain them. For property names of directly exported classes or objects, such as **name** and **age** in the following example, if you do not want to obfuscate them, use [retention options](#retention-options) to retain them.

```
export class MyClass {
    person = {name: "123", age: 100};
}
```

If an API (for example, **foo** in the example) of the .so library needs to be used in the ArkTS/TS/JS file, manually retain the API name.

```
import testNapi from 'library.so'
testNapi.foo() // foo should be retained. Example: -keep-property-name foo
```

4. Fields used in JSON files should be retained.

```
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.jsonProperty  // jsonProperty should be retained.
```

Database-related fields should be manually retained.

```
const dataToInsert = {  
  value1: 'example1',   // value1 should be retained.
};
```

When custom decorators are used on member variables, member methods, or parameters in the source code, and the intermediate product of source code compilation is a JS file (for example, compiling release-mode source code HAR or source code containing @ts-ignore or @ts-nocheck), the names of these member variables or member methods should be retained. This is because the names of these member variables/methods are hardcoded as string literals during conversion from TS syntax to standard JS syntax.

Example:

```
class A {
  // 1. Member variable decorator
  @CustomDecoarter
  propertyName: string = ""   // propertyName should be retained.
  // 2. Member method decorator
  @MethodDecoarter
  methodName1(){} // methodName1 should be retained.
  // 3. Method parameter decorator
  methodName2(@ParamDecorator param: string): void { // methodName2 should be retained.
  }
}
```

#### `-keep-global-name` [,identifiers,...]

Retains the specified top-level scope names or imported/exported element names. Name wildcards are supported. Example:

```
-keep-global-name
Person
printPersonName
```

Names exported from the namespace can also be retained using the **-keep-global-name** option. The following is an example:

```
export namespace Ns {
  export const age = 18; // -keep-global-name age: retains variable age.
  export function myFunc () {}; // -keep-global-name myFunc: retains function myFunc.
}
```

> **NOTE**
>
> The trustlist specified by `-keep-global-name` applies globally. That is, if multiple top-level scope names or exported names exist in the code, they will not be confused as long as they match the names in the trustlist configured in **-keep-global-name**.

**Which top-level scope names should be retained?**

In JavaScript, variables in the top-level scope are properties of **globalThis**. If **globalThis** is used to access a global variable in the code, the variable name should be retained.

Example:

```
var a = 0;
console.info(globalThis.a);  // a should be retained.

function foo(){}
globalThis.foo();           // foo should be retained.

var c = 0;
console.info(c);             // c can be correctly obfuscated.

function bar(){}
bar();                      // bar can be correctly obfuscated.

class MyClass {}
let d = new MyClass();      // MyClass can be correctly obfuscated.
```

When importing API names from .so libraries using named imports, if both **-enable-toplevel-obfuscation** and **-enable-export-obfuscation** are configured, the API names should be manually retained.

```
import { testNapi, testNapi1 as myNapi } from 'library.so' // testNapi and testNapi1 should be retained.
```

#### `-keep-file-name` [,identifiers,...]

Retains the file or folder names. You do not need to specify the file name extension. Name wildcards are supported. Example:

```
-keep-file-name
index
entry
```

**Which file names should be retained?**

1. When **require** is used to import file paths, the path should be retained. This is because ArkTS does not support [CommonJS](../arkts-utils/module-principle.md#commonjs module) syntax.

   ```
   const module1 = require('./file1')   // file1 should be retained.
   ```

2. For dynamic imports, since it is impossible to determine whether the parameter in the **import** function is a path, the path should be retained.

   ```
   const moduleName = './file2'         // file2 should be retained.
   const module2 = import(moduleName)
   ```

3. When [dynamic routing](../ui/arkts-navigation-navigation.md#cross-package-dynamic-routing) is used for navigation, the path passed to the routing should be retained. Dynamic routing provides two modes: system routing table and custom routing table. If a custom routing table is used for redirection, the way to configure a trustlist is consistent with the second dynamic reference scenario. However, if the system routing table is used for redirection, the path corresponding to the **pageSourceFile** field in the **resources/base/profile/route_map.json** file of the module should be added to the trustlist.

   ```
     {
       "routerMap": [
         {
           "name": "PageOne",
           "pageSourceFile": "src/main/ets/pages/directory/PageOne.ets",  // The path should be retained.
           "buildFunction": "PageOneBuilder",
           "data": {
             "description" : "this is PageOne"
           }
         }
       ]
     }
   ```

#### `-keep-comments` [,identifiers,...]

Retains the classes, functions, namespaces, enums, structs, interfaces, modules, types, and JsDoc comments above properties in the declaration file generated after compilation. Name wildcards are supported. For example, to retain the JSDoc comments above the **Human** class in the declaration file, use the following configuration:

```
-keep-comments
Human
```

**NOTE**

1. This option takes effect when **-remove-comments** is used.
2. If the classes, functions, namespaces, enums, structs, interfaces, modules, types, and property names in the declaration file generated after compilation are confused, the JsDoc comments above the element cannot be retained using **-keep-comments**. For example, when **exportClass** is configured in **-keep-comments**, if the class name is **exportClass** obfuscated, its JSDoc comments cannot be retained:

```
/*
 * @class exportClass
 */
export class exportClass {}
```

#### `-keep-dts` filepath

Adds names (such as variable names, class names, and property names) in the .d.ts file of the specified file path into the trustlist of **-keep-global-name** and **-keep-property-name**. Note that **filepath** supports only absolute paths and can be specified as a directory. In this case, the names in all .d.ts files in the directory are retained.

#### `-keep` filepath

Retains all names (such as variable names, class names, and property names) in the specified relative path. The path can be a file or directory. If the path is a directory, the files in the directory and subdirectories are not obfuscated. 

The path must be a relative path. **./** and **../** are relative to the directory where the obfuscation configuration file is located. Path wildcards are supported.

```
-keep
./src/main/ets/fileName.ts   // Names in the fileName.ts file are not obfuscated.
../folder                    // Names in all the files under the folder directory and its subdirectories are not obfuscated.
../oh_modules/json5          // Names in all the files in the imported third-party library json5 are not obfuscated.
```

**How to retain remote HAR packages in modules?**

Method 1: Specify the exact path of the remote HAR package in the module-level oh_modules. This path is a symbolic link to the real path in the project-level oh_modules. When configuring the path in the module-level oh_modules as a trustlist, you should specify the bundle name or a directory following the bundle name to correctly link to the real directory path. Therefore, configuring only the parent directory name of the HAR package is not supported.

```
// Positive example:
-keep
./oh_modules/harName1         // Names in all the files under the harName1 directory and its subdirectories are not confused.
./oh_modules/harName1/src     // Names in all the files under the src directory and its subdirectories are not confused.
./oh_modules/folder/harName2  // Names in all the files under the harName2 directory and its subdirectories are not confused.

// Negative example:
-keep
./oh_modules                  // To retain the HAR package in the module-level oh_modules, configuring the parent directory name of the HAR package is not supported.
```

Method 2: Specify the exact path of the remote HAR package in the project-level oh_modules. Since the file paths in the project-level oh_modules are all real paths, any path can be configured.

```
-keep
../oh_modules                  // Names in all the files under the project-level oh_modules and its subdirectories are not confused.
../oh_modules/harName3          // Names in all the files under the harName3 directory and its subdirectories are not confused.
```

The following figure shows the directory structure of module-level oh_moudles and project-level oh_modules in DevEco Studio.

![oh_modules](./figures/oh_modules.png)

**NOTE**

1. For files retained by **-keep filepath**, all exported names and their properties in the dependency chain of these files are also retained.
2. This option does not affect the capability provided by the **-enable-filename-obfuscation** option.

#### Wildcards Supported by Retention Options

##### Name Wildcards

The table below lists the name wildcards supported.

| Wildcard| Description                  | Example                                      |
| ------ | ---------------------- | ------------------------------------------ |
| ?      | Matches any single character.      | "AB?" matches "ABC", but not "AB".        |
| \*     | Matches any number of characters.| "\*AB\*" matches "AB", "aABb", "cAB", and "ABc".|

**Use Example**

Retain all property names that start with **a**.

```
-keep-property-name
a*
```

Retain all single-character property names.

```
-keep-property-name
?
```

Retain all property names.

```
-keep-property-name
*
```

##### Path Wildcards

The table below lists the path wildcards supported.

| Wildcard| Description                                                                    | Example                                             |
| ------ | ------------------------------------------------------------------------ | ------------------------------------------------- |
| ?     | Matches any single character except the path separator (/).                                     | "../a?" matches "../ab", but not "../a/".        |
| \*      | Matches any number of characters except the path separator (/).                               | "../a*/c" matches "../ab/c", but not "../ab/d/s/c".|
| \*\*   | Matches any number of characters.                                                  | "../a**/c" matches "../ab/c" and "../ab/d/s/c". |
| !      | Negation. It can only be placed at the beginning of a path to exclude a certain case configured in the trustlist.| "!../a/b/c.ets" indicates all paths other than "../a/b/c.ets".          |

**Use Example**

Retain the **c.ets** file in the **../a/b/** directory (excluding subdirectories).

```
-keep
../a/b/*/c.ets
```

Retain the **c.ets** file in the **../a/b/** directory and its subdirectories.

```
-keep
../a/b/**/c.ets
```

Retain all files except the **c.ets** file in the **../a/b/** directory. The exclamation mark (!) cannot be used alone. It can only be used to exclude existing cases in the trustlist.

```
-keep
../a/b/
!../a/b/c.ets
```

Retain all the files in the **../a/** directory (excluding subdirectories).

```
-keep
../a/*
```

Retain all the files in the **../a/** directory and its subdirectories.

```
-keep
../a/**
```

Retain all the files in the module.

```
-keep
./**
```

**NOTE**

(1) In these options, the wildcards *, ?, and ! cannot be used for other meanings.
Example:

```
class A {
  '*'= 1
}

-keep-property-name
*
```

In this example, * indicates any number of characters, and all property names are retained (not obfuscated). It does not mean that only the * property is retained.

(2) In the **-keep** option, only the path format / is allowed. The path format \ or \\ is not.

### Comments

You can use **#** to comment out an obfuscation rule file. The line that starts with **#** is treated as a comment. Example:

```
# white list for MainAbility.ets
-keep-global-name
MyComponent
GlobalFunction

-keep-property-name # white list for dynamic property names
firstName
lastName
age
```

During HAR build, comments are not merged into the final **obfuscation.txt** file.

### Obfuscation Rule Merging Strategies

When a module in a project is built, the obfuscation rules used are a combination of the obfuscation rules in the following files:

* File specified by the **ruleOptions.files** field in the **build-profile.json5** file of the module
* File specified by the **consumerFiles** field in the local dependent libraries
* **obfuscation.txt** file in remote dependent HARs

The priorities of obfuscation rules in the preceding files are the same. When building a module, these files are merged according to the following merging strategies (pseudo code).

```
let `listRules` indicates the list of all obfuscation rule files mentioned above.
let finalRule = {
    disableObfuscation: false,
    enablePropertyObfuscation: false,
    enableToplevelObfuscation: false,
    compact: false,
    removeLog: false,
    keepPropertyName: [],
    keepGlobalName: [],
    keepDts: [],
    printNamecache: string,
    applyNamecache: string
}
for each file in `listRules`:
    for each option in file:
        switch(option) {
            case -disable-obfuscation:
                finalRule.disableObfuscation = true;
                continue;
            case -enable-property-obfuscation:
                finalRule.enablePropertyObfuscation = true;
                continue;
            case -enable-toplevel-obfuscation:
                finalRule.enableToplevelObfuscation = true;
                continue;
            case -compact:
                finalRule.compact = true;
                continue;
            case -remove-log:
                finalRule.removeLog = true;
                continue;
            case -print-namecache:
                finalRule.printNamecache = #{specifiedPathName};
                continue;
            case -apply-namecache:
                finalRule.applyNamecache = #{specifiedPathName};
                continue;
            case -keep-property-name:
                finalRule.keepPropertyName.push(#{specifiedName});
                continue;
            case -keep-global-name:
                finalRule.keepGlobalName.push(#{specifiedName});
                continue;
            case -keep-dts:
                finalRule.keepDts.push(#{specifiedPath});
                continue;
        }
    end-for
end-for
```

The final obfuscation rule comes from the object **finalRule**.

During HAR build, the final **obfuscation.txt **file comes from the combination of the **consumerFiles** field of the HDR and the local dependent libraries, and the **obfuscation.txt** file of the dependent HARs.

When the obfuscation configuration file specified by **consumerFiles** contains the following obfuscation rules, these rules will be merged into the **obfuscation.txt** file of a HAR, whereas other obfuscation rules will not.

```
// Obfuscation options
-enable-property-obfuscation
-enable-string-property-obfuscation
-enable-toplevel-obfuscation
-compact
-remove-log

// Retention options
-keep-property-name
-keep-global-name
```

**Precautions**

1. If the obfuscation configuration file specified by **consumerFiles** contains the above obfuscation options, when other modules depend on this HAR, these obfuscation options will be merged with the main module's obfuscation rules, thereby affecting the main module. Therefore, you are not advised to configure obfuscation options in the **consumer-rules.txt** file. Instead, configure only retention options in the file.

2. If the **-keep-dts** option is added to the obfuscation configuration file specified by **consumerFiles**, it will be converted into **-keep-global-name** and **-keep-property-name**.

3. For third-party libraries, the **obfuscation.txt** file only takes effect when the module's **oh-package.json5** file depends on the library. If the dependency is specified in the project's **oh-package.json5** file, the **obfuscation.txt** file in the third-party library will not take effect.

## Deobfuscating Error Stacks

In applications that have undergone obfuscation, code names are changed, making the error stacks printed during crashes harder to understand because they do not match the source code exactly. You can use the hstack plugin in DevEco Studio Command Line Tools to restore the source stack trace and analyze problems. The deobfuscation tool requires the **sourceMaps.json** file and the obfuscation name mapping file **nameCache.json** generated during compilation. Be sure to back them up locally.
![obfuscation-product](figures/obfuscation-product.png)

## Enabling Code Obfuscation

1. Prerequisites for using obfuscation:
    1. Check whether obfuscation is enabled for the current module and whether the release build mode is selected.
    2. Before using obfuscation, you are advised to learn about the capabilities of [obfuscation options](obfuscation-options) and [retention options](retention-options).
3. Enable the obfuscation options in sequence to adapt and verify application functionalities one by one.
    1. When **-enable-toplevel-obfuscation** is configured, access to global variables using **globalThis** fails. To rectify the fault, use **-keep-global-name** to retain the global variable name.
    2. After the preceding adaptation is successful, configure **-enable-property-obfuscation**, and perform adaptation in the following scenarios:
        1. If the code statically defines properties but dynamically accesses them (or vice versa), use **-keep-property-name** to retain the property names. Example:
            ```
            // Static definition, dynamic access: The property name is static during object definition, but is accessed by dynamically constructing the property name (usually using string concatenation).
            const obj = {
              staticName: value  // Static definition
            };
            const fieldName = 'static' + 'Name';  // Dynamic construction of the property name
            console.log(obj[fieldName]);  // Use square bracket notation to dynamically access the property.
            ```
            ```
            // Dynamic definition, static access: The property name is determined during object definition through a dynamic expression, but is statically accessed using dot notation (assuming that you know the result of the property name).
            const obj = {
              [dynamicExpression]: value  // Dynamic definition
            };
            console.log(obj.dynamicPropertyName);  // Use dot notation to statically access the property.
            ```
        2. If the code uses dot notation to access fields not defined in ArkTS/TS/JS code (for example, native so libraries, fixed JSON files, or database fields):
            1. For API calls to so libraries (for example, **import testNapi from 'library.so'; testNapi.foo();**), use **-keep-property-name** to retain the property name **foo**.
            2. For fields in JSON files, use **-keep-property-name** to retain the JSON field names.
            3. For database-related fields, use **-keep-property-name** to retain the database field names.
        3. When building a HAR module for use by other modules, use **-keep-property-name** in the **consumer-rules.txt** file of the HAR module to retain properties that should not be re-obfuscated. The **consumer-rules.txt** file generates the **obfuscation.txt** file during HAR compilation. When the HAR module is depended upon by other modules, DevEco Studio parses the **obfuscation.txt** file to read the trustlist.
        4. Verify application functionality and identify any missed scenarios. If the application functionality is abnormal, find the code of the error line in the corresponding [intermediate products](#viewing-obfuscation-effects) based on the obfuscated error stack, identify the necessary trustlist configurations, and use **-keep-property-name** to retain them.
    3. After the preceding adaptations are successful, configure **-enable-export-obfuscation**, and perform adaptation in the following scenarios:
        1. For HSP modules that provide interfaces and properties to other modules, use **-keep-global-name** to retain the interface names and **-keep-property-name** to retain the property names in exposed classes/interfaces.
        2. When building HAR modules for use by other modules, use **-keep-global-name** to retain interface names and **-keep-property-name** to retain the property names in exposed classes/interfaces in the **obfuscation-rules.txt** file.
        3. For API calls to so libraries (for example, **import { napiA } from 'library.so'**), use **-keep-global-name** to retain the so interface name **napiA**.
        4. Verify application functionality and interface call functionality when the module is depended upon, and identify any missed scenarios. If the application functionality is abnormal, find the code of the error line in the corresponding [intermediate products](#viewing-obfuscation-effects) based on the obfuscated error stack, identify the necessary trustlist configurations, and retain them.
    4. After the preceding adaptations are successful, configure **-enable-filename-obfuscation**, and perform adaptation in the following scenarios:
        1. If the code contains dynamic import statements (for example, **const path = './filePath'; import(path)**), use **-keep-file-name filePath** to retain the file path.
        2. If the application has a [routerMap configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/module-configuration-file-V5#routermap) that describes routing information, use **-keep-file-name** to retain the page source file path, which is specified by **pageSourceFile** field in the routing information.
        3. If the code uses **ohmUrl** for page navigation (for example, **router.pushUrl({url: '@bundle:com.example.routerPage/Library/Index'})**), use **-keep-file-name** to retain the path.
        4. Verify application functionality and identify any missed scenarios. If the application function is abnormal and the error stack contains obfuscated paths, you can query the original path in the **build/default/[...]/release/obfuscation/nameCache.json** file within the module and then locate the source code file. You can also use the [hstack plugin](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-command-line-hstack-V5) to trigger automatic deobfuscation of error stacks. After locating the paths to retain, use **-keep-file-name** to retain them.

## Remarks

* Currently, custom obfuscation plugins are not supported in the hvigor build process.
* If a module that depends on an obfuscated HAR enables obfuscation, the HAR will be obfuscated again.
* To enable the release build mode, select **Product** in the upper right corner of DevEco Studio and set **Build Mode** to **release**. 
![product-release](figures/product-release.png)

## FAQs

### Mappings Between Obfuscation Options and Minimum SDK Versions

| Obfuscation Option| Description | Minimum SDK Version|
| ------- | --------- | ------ |
| -disable-obfuscation         | Disables obfuscation.| 4.0.9.2 |
| -enable-property-obfuscation | Enables property name obfuscation.| 4.0.9.2 |
| -enable-string-property-obfuscation | Enables obfuscation for string literal property names.| 4.0.9.2 |
| -enable-toplevel-obfuscation | Enables top-level scope name obfuscation.| 4.0.9.2 |
| -enable-filename-obfuscation | Enables file or folder name obfuscation for the HAR.<br> Enables file or folder name obfuscation for the HAP/HSP.| 4.1.5.3 <br> 5.0.0.19 |
| -enable-export-obfuscation   | Enables obfuscation for imported/exported names.| 4.1.5.3 |
| -compact                     | Removes unnecessary spaces and all line feeds.| 4.0.9.2 |
| -remove-log                  | Removes the expressions involving direct calls to the console. statement in specific scenarios.| 4.0.9.2 |
| -print-namecache             | Saves the name cache to the specified file path.| 4.0.9.2 |
| -apply-namecache             | Reuses the specified name cache file.| 4.0.9.2 |
| -remove-comments             | Removes all comments in the file.| 4.1.5.3 |
| -keep-property-name          | Retains property names.| 4.0.9.2 |
| -keep-global-name            | Retains top-level scope names.| 4.0.9.2 |
| -keep-file-name              | Retains file or folder names in the HAR.<br> Retains file or folder names in the HAP/HSP.| 4.1.5.3 <br> 5.0.0.19 |
| -keep-dts                    | Retains the names in the .d.ts file in the specified path.| 4.0.9.2 |
| -keep-comments               | Retains the classes, functions, namespaces, enums, structs, interfaces, modules, types, and JsDoc comments above properties in the declaration file generated after compilation.| 4.1.5.3 |
| -keep                        | Retains all names in the specified path.| 5.0.0.18 |
| Wildcard                      | The retention options of the name classes and path classes support wildcards.| 5.0.0.24 |

### Viewing Obfuscation Effects
The following figure shows a simplified compilation process.

![compilation-process](figures/compilation-process.png)

After obfuscation is complete, intermediate products are generated. You can find the obfuscated intermediate products in the **build** directory of the compilation output, as well as the name mapping file and system API trustlist files.

* Obfuscated file directory: build/default/[...]/release/moduleName
* Directory of the name mapping file and system API trustlist file: build/default/[...]/release/obfuscation
  * The name mapping file, named **nameCache.json**, records the mappings between source code names and names after obfuscation.
  * The system API trustlist file, named **systemApiCache.json**, records the APIs and property names that will be kept.

  ![build-product](figures/build-product.png)

### Troubleshooting Functional Issues
#### Procedure
1. Configure the **-disable-obfuscation** option in the **obfuscation-rules.txt** file to disable obfuscation, and check whether the issue is caused by obfuscation.
2. If the function is abnormal after obfuscation is enabled, read the document to understand the capabilities of obfuscation rules, such as [-enable-property-obfuscation](#retention-options), [-enable-toplevel-obfuscation](#retention-options), [-enable-filename-obfuscation](#retention-options), and [-enable-export-obfuscation](#retention-options), and the syntax scenarios that require the configuration of a trustlist to ensure that the application functions properly. The following briefly describes the four retention options that are enabled by default. For details, see the complete description of the corresponding options. 
    1. [-enable-toplevel-obfuscation](#retention-options): retains top-level scope name.
    2. [-enable-property-obfuscation](#retention-options): retains properties. You need to use [-keep-property-name](#retention-options) to configure a trustlist for specified property names in scenarios where obfuscation is not allowed, such as network data access, JSON field access, dynamic property access, and .so library API calls.
    3. [-enable-export-obfuscation](#retention-options): retains exported names. Generally, this option is used together with **-enable-toplevel-obfuscation** and **-enable-property-obfuscation**. You need to use [-keep-global-name](#retention-options) to configure a trustlist for exported or imported names in scenarios where external APIs of the module cannot be obfuscated.
    4. [-enable-filename-obfuscation]: retains file names. You need to use [-keep-file-name](#retention-options) to configure a trustlist for file paths and names in scenarios where file paths are dynamically imported or directly loaded at runtime.
3. If your problem matches any troubleshooting cases listed in [Common Issues](common-issues), apply the suggested solutions.
4. If the issue is not covered, use a positive approach to identify the problem (remove specific configuration items if the corresponding functionality is not needed).
5. Analyze runtime crashes as follows:
    1. Open the application runtime logs or the **Crash** dialog box in DevEco Studio to find the crash stack.
    2. The line number in the crash stack is the line number of the [build product](#viewing-obfuscation-effects), and the method name may also be the obfuscated name. Therefore, you are advised to check the build product based on the crash stack, analyze the names that cannot be obfuscated, and add them to the trustlist.
6. Analyze functional exceptions (for example, white screens) as follows:
    1. Opening the application runtime logs: Select HiLog and search for logs directly related to the exceptions.
    2. Locating the problematic code segment: Identify the specific code block causing the exceptions through log analysis.
    3. Enhancing log output: Add log records for data fields in the suspected code segment.
    4. Analyzing and identifying critical fields: Determine if the data exception is caused by obfuscation through the enhanced log output.
    5. Configuring a trustlist for critical fields: Add fields that directly affect application functionality after obfuscation to the trustlist.

#### Troubleshooting Unexpected Obfuscation Behavior
If unexpected obfuscation behavior occurs, check whether certain obfuscation options are configured for the dependent local modules or third-party libraries.

Example:
If **-compact** is not configured for the current module, but the code in the obfuscated intermediate product is compressed into a single line, perform the following steps:

1. Check the **dependencies** field in the **oh-package.json5** file of the current module to identify dependencies.
2. Search for **-compact** in the obfuscation configuration file of the dependent modules or third-party libraries.
    * Search for **-compact** in the **consumer-rules.txt** file in the local libraries.
    * Search for **-compact** in all **obfuscation.txt** files in the project-level **oh_modules** directory.

**NOTE**

You are not advised to configure the following options in the **obfuscation.txt** file of third-party libraries, as they can cause unexpected behavior or crashes when the main module is obfuscated. Contact the library providers to remove these options and repackage the libraries.

```
-enable-property-obfuscation
-enable-string-property-obfuscation
-enable-toplevel-obfuscation
-remove-log
-compact
```

### Common Issues

#### Errors That May Occur When -enable-property-obfuscation Is Configured

Case 1: The error message "Cannot read property 'xxx' of undefined" is reported.

```
// Before obfuscation:
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.jsonProperty

// After obfuscation:
const jsonData = ('./1.json')
let jsonStr = JSON.parse(jsonData)
let jsonObj = jsonStr.i
```

After property name obfuscation is enabled, **jsonProperty** is obfuscated as a random character **i**. However, the original name is used in the JSON file, causing the error.

**Solution**: Use the **-keep-property-name** option to add the fields used in JSON files to the trustlist.

Case 2: An error message is reported when database-related fields are used and property obfuscation is enabled.

The error message is "table Account has no column named a23 in 'INSET INTO Account(a23)'."

The SQL statement uses database field names that are obfuscated, whereas the database expects the original names.

**Solution**: Use the **-keep-property-name** option to add the database fields to the trustlist.

**Case 3: Properties Obfuscated When Record<string, Object> Is Used as an Object Type**

**Symptom**

When **Record<string, Object>** is used as an object type, properties like **linkSource** are obfuscated, causing the error. Example:

```
// Before obfuscation:
import { Want } from '@kit.AbilityKit';
let petalMapWant: Want = {
  bundleName: 'com.example.myapplication',
  uri: 'maps://',
  parameters: {
    linkSource: 'com.other.app'
  }
}

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

In this example, the object's properties need to be passed to the system to load a specific page, so the property names should not be obfuscated. The type **Record<string, Object>** is a generic definition for an object with string keys and does not describe the internal structure or property types in detail. Therefore, the obfuscation tool cannot identify which properties should not be obfuscated, leading to the obfuscation of internal property names like **linkSource**.

**Solution**

Add the problematic property names to the property trustlist. The following is an example:

```
-keep-property-name
linkSource
```

#### Errors That May Occur When -enable-export-obfuscation and -enable-toplevel-obfuscation Are Configured

When the two options are configured, method name confusion in the following scenarios is involved when the main module calls the methods of other modules:

| Main Module| Dependent Module| Imported/Exported Name Obfuscation|
| ------- | ------- | ----------------------------|
| HAP/HSP | HSP     | The HSP and main module are independently compiled, resulting in inconsistent obfuscated names. Both need trustlist configurations.|
| HAP/HSP | Local HAR| The local HAR is compiled together with the main module, resulting in consistent obfuscated names.|
| HAP/HSP | Third-party library | Exported names and their properties in third-party libraries are collected into the trustlist, so they are not obfuscated during import/export.|

For the HSP, you must add the methods used by other modules to the trustlist. You must add the same trustlist for the main module. Therefore, you are advised to add the obfuscation file configured with the trustlist (for example, **hsp-white-list.txt**) to the obfuscation configuration item of the module that depends on the obfuscation file, that is, the **files** field shown in the following figure.

![obfuscation-config](figures/obfuscation-config.png)

Case 1: When a class is dynamically imported, the class definition is confused, but the class name is not, causing an error.

```
// Before obfuscation:
export class Test1 {}

let mytest = (await import('./file')).Test1

// After obfuscation:
export class w1 {}

let mytest = (await import('./file')).Test1
```

The exported class **Test1** is a top-level domain name. When being dynamically used, it is a property. Because the **-enable-property-obfuscation** option is not configured, the class name is confused, but the property name is not.

**Solution**: Use the **-keep-global-name** option to add **Test1** to the trustlist.

Case 2: For a method in a namespace, the method definition is confused, but the statement that uses the method is not, causing an error.

```
// Before obfuscation:
export namespace ns1 {
  export class person1 {}
}

import {ns1} from './file1'
let person1 = new ns1.person1()

// After obfuscation:
export namespace a3 {
  export class b2 {}
}

import {a3} from './file1'
let person1 = new a3.person1()
```

**person1** in the namespace is an exported element. When being called through **ns1.person1**, it is a property. Because the **-enable-property-obfuscation** option is not configured, the property name is not obfuscated during the call.

**Solution**

1. Configure the **-enable-property-obfuscation** option.
2. Use the **-keep-global-name** option to add the methods exported from the namespace to the trustlist.

Case 3: When declare global is used, a syntax error is reported after obfuscation.

```
// Before obfuscation:
declare global {
  var age : string
}

// After obfuscation:
declare a2 {
  var b2 : string
}
```

The error message "SyntaxError: Unexpected token" is reported.

**Solution**: Use **-keep-global-name** to **add __global** to the trustlist.

#### The **-enable-string-property-obfuscation** option is not configured, but the string literal property name is obfuscated. As a result, the value of the string literal property name is undefined.

```
person["age"] = 22; // Before obfuscation

person["b"] = 22; // After obfuscation
```

**Solution**

1. Check whether **-enable-string-property-obfuscation** is configured for the dependent HAR. If it is configured, the main project will be affected, and you should disable it.
2. If it must be configured, add the property name to the trustlist.
3. If it is not configured and the SDK version is earlier than 4.1.5.3, update the SDK.

#### Errors That May Occur When -enable-filename-obfuscation Is Configured

Case 1: The error message "Error Failed to get a resolved OhmUrl for 'D:code/MyApplication/f12/library1/pages/d.ets' imported by 'undefined'" is reported.

As shown below, the outer layer of the **library1** module contains a directory named **directory**. When file name obfuscation is enabled, **directory** is obfuscated as **f12**, causing the error indicating that the path is not found.

![directory-offuscation](figures/directory-obfuscation.png)

**Solution**

1. If the project directory structure and error message are similar, update the SDK to 5.0.0.26 or later.
2. Use the **-keep-file-name** option to add the directory name **directory** of the module to the trustlist.

Case 2: The error message "Cannot find module 'ets/appability/AppAbility' which is application Entry Point" is reported.

The system loads the ability file when the application is running. Therefore, you must manually configure the trustlist to prevent the specified file from being obfuscated.

**Solution**: Use the **-keep-file-name** option to add the path corresponding to the **srcEntry** field in the **src/main/module.json5** file to the trustlist.

```
-keep-file-name
appability
AppAbility
```

#### Errors That May Occur When -keep-global-name and a Trustlist Are Configured

The error message "Cannot read properties of undefined (reading 'has')" is reported.

**Solution**: Upgrade the SDK to 4.1.6.3 or later.

#### The HAP and HSP depend on the same local source code HAR module.

* If file name obfuscation is enabled, the following issue may occur:
  * Singleton function exceptions: The reason is that the HAP and HSP modules execute independent build and obfuscation processes. The same file names in the shared local source code HAR may be obfuscated differently in the HAP and HSP packages.
  * Interface call failures: The reason is that the HAP and HSP modules execute independent build and obfuscation processes. Different file names in the shared local source code HAR may be obfuscated to the same name in the HAP and HSP packages.
* If **-enable-export-obfuscation** and **-enable-toplevel-obfuscation** are configured, the interface loading failures may occur at runtime.
The HAP and HSP modules execute independent build and obfuscation processes, resulting in different obfuscated names for the interfaces exposed by the shared local source code HAR.

**Solution**

1. Change the shared local source code HAR to a [bytecode HAR](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-har-V5#section179161312181613). This prevents the HAR from being re-obfuscated when being depended upon.
2. Build the shared local source code HAR in [release mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-har-V5#section19788284410). This ensures that file names and exported interfaces are not obfuscated when the HAR is depended upon.

#### Errors That May Occur When both -enable-property-obfuscation and -keep Are Configured 

**Symptom**

The following obfuscation configuration is used:

```
-enable-property-obfuscation
-keep
./file1.ts
```

**file2.ts** imports an interface from **file1.ts**, and the interface contains object-type properties. As a result, these properties are retained in **file1.ts** but obfuscated in **file2.ts**, leading to function exceptions. Example:

```
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

// After obfuscation, the code of file1.ts is retained.
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

The **-keep** option retains the code in the **file1.ts** file, but properties within exported types (for example, **address**) are not automatically added to the property trustlist. Therefore, these properties are obfuscated when being used in other files.

**Solution**

Solution 1: Define the property type using **interface** and export it. This will automatically add the property to the trustlist. Example:

```
// file1.ts
export interface AddressType {
  city1: string
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
