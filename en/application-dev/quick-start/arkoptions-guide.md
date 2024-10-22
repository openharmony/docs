# arkOptions Configuration


## Configuration File Tag

  **Table 1** types field in the arkOptions tag

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| types | Type declaration files to import globally. Using this field can avoid individual imports in each source file.| Array| Yes (initial value: left empty)|

## types Field Configuration in arkOptions

 Add the **types** field to the **arkOptions** attribute of the **buildOption** tag in the **build-profile.json5** configuration file of a module.

```json
// In /entry/build-profile.json5
{
  "arkOptions": {
    "types": ["chai", "./oh_modules/@types/mocha", "./src/main/ets/pages/global"]
  }
}
```

The **types** field can be set to a bundle name, relative path to the bundle location, or relative path to the declaration file. Only the search in the current module is supported. If files with the same name (with different file name extensions) exists in the specified directory, the files are loaded in the following order, from high to low: **.d.ets** > **.d.ts**.<br>
 (1) Inputting package name: If a bundle name is specified, it is used to search for the declaration files in **oh_modules/@types/**, xxx.<br>
 (2) Inputting relative path of the package: Search the defined declaration file at the relative path of **build-profile.json5**, for example, **./oh_modules/@types/mocha**.<br>
 (3) Inputting relative path of the declaration file: Search the declaration file in the relative path, for example, **./src/main/ets/pages/global**.

*NOTE*

If you input the package name or the relative path of the package location in the **types** field, **dependencies** at **project file/entry/oh-package.json5** should be set as follows:
```json
"dependencies": {
  "@types/chai": "latest",
  "@types/mocha": "latest"
}
```

If you input the relative path of the declaration file in the **types** field, make sure the corresponding declaration file, such as the **src/main/ets/pages/global.d.ts** file, exists in the module. The content of the declaration file is as follows:
```typescript
declare namespace Global {
  type ObjectType = string | number;
}
```

After **types** is set to globally import type declarations, the types declared can be used as follows:
```typescript
// In entry/src/main/ets/pages/Index.ets
let a: Chai.Message;
let b: Mocha.HookFunction;
let c: Global.ObjectType;
```
