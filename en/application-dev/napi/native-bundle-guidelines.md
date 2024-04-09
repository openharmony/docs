# Native Bundle Development

## When to Use

Use the native bundle APIs to obtain application information.

## Available APIs

| API                                                      | Description                                    |
| :----------------------------------------------------------- | :--------------------------------------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](../reference/apis-ability-kit/_bundle.md#oh_nativebundle_getcurrentapplicationinfo) | Obtains the information about the current application.         |
| [OH_NativeBundle_GetAppId](../reference/apis-ability-kit/_bundle.md#oh_nativebundle_getappid) | Obtains the appId information about the current application.|
| [OH_NativeBundle_GetAppIdentifier](../reference/apis-ability-kit/_bundle.md#oh_nativebundle_getappidentifier) | Obtains the appIdentifier information about the current application.|

## How to Develop

1. **Create a project.**

<div style="text-align:center;">
  <img src="figures/rawfile1.png">
</div>

2. **Add dependencies.**

   After the project is created, the **cpp** directory is created in the project directory. The directory contains files such as **libentry/index.d.ts**, **hello.cpp**, and **CMakeLists.txt**.

   1. Open the **src/main/cpp/CMakeLists.txt** file, and add **libbundle_ndk.z.so** to **target_link_libraries**.

       ```c++
       target_link_libraries(entry PUBLIC libace_napi.z.so libbundle_ndk.z.so)
       ```

   2. Open the **src/main/cpp/hello.cpp** file, and add the header file.

       ```c++
       #include "bundle/native_interface_bundle.h"
       ```

3. **Modify the source file.**

   When the **src/main/cpp/hello.cpp** file is opened, **Init** is called to initialize the API, which is **getCurrentApplicationInfo**.

    ```c++
    EXTERN_C_START
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "getCurrentApplicationInfo", nullptr, GetCurrentApplicationInfo, nullptr, nullptr, nullptr, napi_default, nullptr}
        };
    
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    EXTERN_C_END
    ```

   1. Add the API to the **src/main/cpp/hello.cpp** file.

       ```c++
       static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
       ```

   2. Obtain the native bundle information object from the **hello.cpp** file and convert it to a JavaScript bundle information object. In this way, you can obtain the application information on the JavaScript side.

       ```c++
       static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
       {
           // Call the native API to obtain the application information.
           OH_NativeBundle_ApplicationInfo nativeApplicationInfo = OH_NativeBundle_GetCurrentApplicationInfo();
           napi_value result = nullptr;
           napi_create_object(env, &result);
           // Convert the bundle name obtained by calling the native API to the bundleName attribute in the JavaScript object.
           napi_value bundleName;
           napi_create_string_utf8(env, nativeApplicationInfo.bundleName, NAPI_AUTO_LENGTH, &bundleName);
           napi_set_named_property(env, result, "bundleName", bundleName);
           // Convert the fingerprint information obtained by calling the native API to the fingerprint attribute in the JavaScript object.
           napi_value fingerprint;
           napi_create_string_utf8(env, nativeApplicationInfo.fingerprint, NAPI_AUTO_LENGTH, &fingerprint);
           napi_set_named_property(env, result, "fingerprint", fingerprint);
       
           char* appId = OH_NativeBundle_GetAppId();
           // Convert the application ID obtained by calling the native API to the appId attribute in the JavaScript object.
           napi_value napi_appId;
           napi_create_string_utf8(env, appId, NAPI_AUTO_LENGTH, &napi_appId);
           napi_set_named_property(env, result, "appId", napi_appId);
       
           char* appIdentifier = OH_NativeBundle_GetAppIdentifier();
           // Convert the application identifier obtained by calling the native API to the appIdentifier attribute in the JavaScript object.
           napi_value napi_appIdentifier;
           napi_create_string_utf8(env, appIdentifier, NAPI_AUTO_LENGTH, &napi_appIdentifier);
           napi_set_named_property(env, result, "appIdentifier", napi_appIdentifier);
           // To prevent memory leak, manually release the memory.
           free(nativeApplicationInfo.bundleName);
           free(nativeApplicationInfo.fingerprint);
           free(appId);
           free(appIdentifier);
           return result;
       }
       ```

4. **Call APIs on the JavaScript side.**

   1. Open the **src\main\ets\pages\index.ets** file, and import **libentry.so**.

   2. Call the native API **getCurrentApplicationInfo()** to obtain application information. An example is as follows:

       ```js
       import hilog from '@ohos.hilog';
       import testNapi from 'libentry.so';
       
       @Entry
       @Component
       struct Index {
       @State message: string = 'Hello World';
       
           build() {
               Row() {
               Column() {
                   Text(this.message)
                   .fontSize(50)
                   .fontWeight(FontWeight.Bold)
       
                   Button(){
                   Text("GetCurrentApplicationInfo").fontSize(30)
                   }.type(ButtonType.Capsule)
                   .margin({
                   top: 20
                   })
                   .backgroundColor('#0D9FFB')
                   .width('70%')
                   .height('5%')
                   .onClick(()=>{
                   try {
                       let data = testNapi.getCurrentApplicationInfo();
                       console.info("getCurrentApplicationInfo success, data is " + JSON.stringify(data));
                   } catch (error) {
                       console.error("getCurrentApplicationInfo failed");
                       this.message = "getCurrentApplicationInfo failed";
                   }
                   })
               }
               .width('100%')
               }
               .height('100%')
           }
       }
       ```

For details about the APIs, see [Bundle](../reference/apis-ability-kit/_bundle.md).
