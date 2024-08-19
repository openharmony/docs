# Dynamically Loading a Native Module in Synchronous Mode


The **loadNativeModule** API is used to dynamically load a native module in synchronous mode. It can be used to load a module only when the module needs to be used, shortening the cold start time. However, the API call involves the loading the .so file. You need to evaluate the impact caused by the .so file loading.

## API Description

```js
loadNativeModule(moduleName: string): Object;
```

| Parameter           | Description         |
| :------------- | :----------------------------- |
| moduleName            | Name of the module to load.      |

Note:

1. **moduleName** must be set to the module name configured in the **module.json5** file in the HAP to which the module to load belongs.
2. **loadNativeModule** can be used only to load modules in the main thread.
3. Dependencies must be configured for the API call regardless of whether the input parameter is a constant string or variable expression.

## Supported Scenarios

| Scenario           | Example          |
| :------------- | :----------------------------- |
| System library module       | Load **@ohos.** or **@system.**.       |
| Native module in an application	| Load **libNativeLibrary.so**. |

## Example

- **Loading a system library module to a HAP**

  ```js
  let hilog: ESObject = loadNativeModule("@ohos.hilog");
  hilog.info(0, "testTag", "loadNativeModule ohos.hilog success");
  ```

- **Loading a native library to a HAP**

  The **index.d.ts** file of **libentry.so** is as follows:

  ```javascript
  //index.d.ts
  export const add: (a: number, b: number) => number;
  ```

1. Configure dependencies in the **oh-package.json5** file.

   ```json
   {
       "dependencies": {
           "libentry.so": "file:../src/main/cpp/types/libentry"
       }
   }
   ```

2. Configure the source package in **build-profile.json5**.

   ```json
   {
       "buildOption" : {
           "arkOptions" : {
               "runtimeOnly" : {
                   "packages": [
                       "libentry.so"
                   ]
               }
           }
       }
   }
   ```

3. Use **loadNativeModule** to load **libentry.so** and call the **add** function.

   ```js
   let module: ESObject = loadNativeModule("libentry.so");
   let sum: number = module.add(1, 2);
   ```