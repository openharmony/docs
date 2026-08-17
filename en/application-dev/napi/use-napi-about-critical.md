# Creating and Destroying a Critical Scope and Accessing String Content Using Node-API Extension APIs

<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=88fc26dbb0c9f93d86550b575acd5207366a25bd translatedAt=2026-08-12T06:38:16.250Z pushedAt=2026-08-12T11:09:56.412Z -->

The Node-API extension APIs **napi_open_critical_scope** and **napi_close_critical_scope** are used to open and close a critical scope, respectively.

> **NOTE**
>
> Non-critical APIs cannot be used in a critical scope, and only one critical scope can be opened in an execution environment. You are advised to open a critical scope only when critical APIs are required, and close the scope in a timely manner after the APIs are used.

## When to Use

Before calling critical APIs, you must open a critical scope using **napi_open_critical_scope** and call the APIs in the critical scope.

After the critical scope is closed, do not use the critical API or its return result. Otherwise, the program may crash or data may be damaged.

## Opening and Closing a Critical Scope and Using Critical APIs

| API                                          | Description                                     | Status Code for Executions Outside the Critical Scope|
| ---------------------------------------------- | ----------------------------------------- | -------------------------- |
| napi_open_critical_scope                       | Opens a critical scope.                         | NA                         |
| napi_close_critical_scope                      | Closes a critical scope.                         | napi_generic_failure       |
| napi_get_buffer_string_utf16_in_critical_scope | Obtains the UTF-16 encoding memory buffer data of an ArkTS string.| napi_generic_failure       |

>**NOTE** 
>
>1. To obtain the memory buffer of an ArkTS string stored in UTF-16-encoding format, use **napi_get_buffer_string_utf16_in_critical_scope**. Otherwise, an error will be returned.
>  
>2. **napi_create_string_utf16** and **napi_create_string_utf8** are used to pass the input data to the VM in the specified encoding format. These functions do not control the internal storage encoding format of strings in the VM.

## Sample Code

- Register the modules.

   ```c++
   // napi_init.cpp
   #include <string>
   #include <string_view>
   #include <vector>

   #include "napi/native_api.h"

      // Use the C++ RAII mechanism to manage the critical scope, ensuring that the critical scope is closed.
      // This is only an example. You can also use other encapsulation methods or the original API.
      class MyCriticalScope
   {
      napi_env env_{};
      napi_critical_scope scope_{};

   public:
      explicit MyCriticalScope(napi_env env) : env_(env)
      {
         if (napi_open_critical_scope(env, &scope_) != napi_ok)
         {
               // If the operation fails, perform necessary error handling or maintenance information supplementation. Details are omitted here.
               // Common failure cause: env is not a valid Node-API execution context (for example, env is nullptr).
         }
      }
      ~MyCriticalScope()
      {
         Close();
      }
      inline void Close()
      {
         if (scope_ == nullptr)
         {
               return;
         }
         // Close the critical scope in the destructor.
         if (napi_close_critical_scope(env_, scope_) != napi_ok)
         {
               // If the operation fails, perform necessary error handling or maintenance information supplementation. Details are omitted here.
               // Common causes:
               // 1. The critical scope is closed repeatedly.
               // 2. env is not a valid Node-API execution context (for example, env is a null pointer).
               // 3. scope is not a valid critical scope handle (for example, scope is a null pointer).
         }
         scope_ = nullptr;
      }
   };

   // Secondary encapsulation method, which is used to copy the underlying buffer of an ArkTS string if failing to obtain the buffer.
   static std::vector<char16_t> GetValueStringUtf16(napi_env env, napi_value value)
   {
      size_t strLength{};
      if (napi_get_value_string_utf16(env, value, nullptr, 0, &strLength) != napi_ok) {
         return {};
      }
      /* The Node-API requires the buffer length to be greater than the string length to accommodate the null terminator of the C string.
       * Therefore, to obtain the complete string, the buffer size must be the string length plus 1.
       */
      std::vector<char16_t> result(strLength + 1);
      if (napi_get_value_string_utf16(env, value, result.data(), result.size(), &strLength) != napi_ok) {
         return {};
      }
      return result;
   }

   static napi_value NAPI_Global_getBufferStringUtf16(napi_env env, napi_callback_info info)
   {
      napi_value args[1]{};
      size_t argc = 1;
      napi_get_cb_info(env, info, &argc, args, /* thisVar */ nullptr, /* data */ nullptr);
      // The number of passed-in parameters is less than the minimum number of required parameters.
      if (argc < 1) {
         return nullptr;
      }
      napi_valuetype argType;

      // The parameter is not a string.
      if (napi_typeof(env, args[0], &argType) != napi_ok || argType != napi_string) {
         return nullptr;
      }

      uint32_t returnCode = 0;
      {
         [[maybe_unused]] MyCriticalScope scope(env);
         size_t bufSize{};
         const char16_t *buf{};
         std::vector<char16_t> copied{}; // Reserved for fallback when the buffer fails to be obtained
         std::u16string_view str;

         if (napi_get_buffer_string_utf16_in_critical_scope(env, args[0], &buf, &bufSize) == napi_ok)
         {
               str = std::u16string_view(buf, bufSize);
         } else {
               scope.Close();
               copied = GetValueStringUtf16(env, args[0]);
               str = std::u16string_view(copied.data(), copied.size());
               returnCode |= (1 << 1);
         }

         // do something with str
         if (str == u"测试字符串") {
               returnCode |= 1;
         }
      }

      napi_value returnResult{};
      napi_create_int32(env, returnCode, &returnResult);
      return returnResult;
   }

   // Register the module.
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
      std::vector<napi_property_descriptor> desc{{"getBufferStringUtf16", nullptr, NAPI_Global_getBufferStringUtf16,
                                                   nullptr, nullptr, nullptr, napi_default, nullptr}};
      napi_define_properties(env, exports, desc.size(), desc.data());
      return exports;
   }
   EXTERN_C_END

   static napi_module demoModule = {
      .nm_version = 1,
      .nm_flags = 0,
      .nm_filename = nullptr,
      .nm_register_func = Init,
      .nm_modname = "entry",
      .nm_priv = ((void *)0),
      .reserved = {0},
   };

   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
      napi_module_register(&demoModule);
   }
   ```

- API declaration

   ```ts
   // index.d.ts
   export const getBufferStringUtf16: (str: string) => number;
   ```

- ArkTS sample code

   ```ts
   // index.ets
   import testNapi from "libentry.so"

   const makeTest = (str: string) => {
      console.info(`status code of get buffer on "${str}": ${testNapi.getBufferStringUtf16(str)}`);
   }
   
   makeTest("hello world"); // Expected result: 2 or 0
   makeTest("你好");        // Expected result: 0 or 2
   makeTest("测试字符串");   // Expected result: 1 or 3
   ```

<!--no_check-->