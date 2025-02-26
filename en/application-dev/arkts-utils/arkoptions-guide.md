# Configuring arkOptions in build-profile.json5

## Overview

**arkOptions** is used to configure settings related to ArkTS compilation. This topic describes the configuration of the **types** and **transformLib** options in **arkOptions**. For more settings, see [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5).

## types

### Description

  Field **types** in **arkOptions**

| Name| Description| Data Type| Optional|
| -------- | -------- | -------- | -------- |
| types | Specifies type declaration files to be globally imported, avoiding the need to import them individually in each source file.| Array| Optional, defaults to an empty array|

### Example

Below provides an example configuration of the **types** Field in **arkOptions**.

Add the **types** field to the **arkOptions** property in the **buildOption** section of the module-level **build-profile.json5** file.
```json
// In /entry/build-profile.json5
{
  "arkOptions": {
    "types": ["chai", "./oh_modules/@types/mocha", "./src/main/ets/pages/global"]
  }
}
```

The **types** field can be set to a package name, relative path to a package, or relative path to a declaration file. It supports searches only within the current module. If there are files with the same name but different extensions in a directory, the default loading order is .d.ets > .d.ts.<br>
(1) Package name: Searches for declaration files defined by the package name in the **oh_modules/@types/** directory, for example, "chai".<br>
(2) Relative path to a package: Searches for declaration files based on the relative path to **build-profile.json5**, for example, "./oh_modules/@types/mocha".<br>
(3) Relative path to a declaration file: Searches for declaration files in the specified relative path, for example, "./src/main/ets/pages/global".

### Precautions

If you specify a package name or a relative path to a package in the **types** field, configure **dependencies** in the project-level **/entry/oh-package.json5** file as follows:
```json
"dependencies": {
  "@types/chai": "latest",
  "@types/mocha": "latest"
}
```

If you specify a relative path to a declaration file in the **types** field, ensure the corresponding declaration file exists in the module. Below is the content of a declaration file named **global.d.ts** in **src/main/ets/pages**:
```typescript
declare namespace Global {
  type ObjectType = string | number;
}
```

After configuring types, you can use these global types in your code:
```typescript
// In entry/src/main/ets/pages/Index.ets
let a: Chai.Message;
let b: Mocha.HookFunction;
let c: Global.ObjectType;
```

## transformLib

### Description

Field **transformLib** in **arkOptions**

| Name| Description| Configuration Scope| Data Type| Optional|
| -------- | -------- | -------- | -------- | -------- |
| transformLib | Specifies the bytecode instrumentation plugin configuration, allowing you to modify bytecode during compilation. This field is supported only in the stage model. The format is a relative path pointing to the dynamic library implementing the instrumentation functionality. The dynamic library must be generated on the corresponding platform and cannot be copied or renamed across platforms.| Module-level| String| Optional, defaults to not using this feature|

### Example

Below provides an example configuration of the **transformLib** Field in **arkOptions**.

Add the **transformLib** field to the **arkOptions** property in the **buildOption** section of the module-level **build-profile.json5** file.
```json
// In /entry/build-profile.json5
{
  "buildOption": {
    "arkOptions": {
      "transformLib": "./dll/example.dll"
    }
  }
}

```
For details about how to modify Ark bytecode, see [Customizing Ark Bytecode During Compilation](customize-bytecode-during-compilation.md).

### Precautions

- If this field is not configured, the feature is not used by default.
- The configuration takes effect for HAP and HSP modules immediately. For HAR modules, only bytecode HAR configurations are effective; non-bytecode HAR configurations are ignored.
- The file format must be .dll (for Windows) or .so (for Linux/macOS).
