# Creating a Strong Reference to an ArkTS Object Using Node-API Extension APIs

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:41:18.733Z pushedAt=2026-08-12T11:15:44.283Z -->

OpenHarmony provides the **napi_strong_ref** APIs to create strong references, which is more efficient than the **napi_ref** APIs.

## When to Use

You can use the **napi_create_strong_reference** API to create a strong reference to an ArkTS object and use the **napi_get_strong_reference_value** API to obtain the referenced ArkTS object.

## Available APIs

| API                           | Description                                 |
| ------------------------------- | ------------------------------------- |
| napi_create_strong_reference    | Creates a strong reference to an ArkTS object.            |
| napi_delete_strong_reference    | Deletes a strong reference.                           |
| napi_get_strong_reference_value | Obtains the ArkTS object value associated with a strong reference object.|

## Sample Code

- Register the modules.

   ```c++
   // napi_init.cpp
   #include "napi/native_api.h"
   #include <vector>

   // napi_strong_ref cannot be used across threads. The example is a single-thread scenario. Do not use this method to declare the reference in service code.
   static napi_strong_ref g_strongRef {};
   static napi_value NAPI_Global_saveOrReplaceObject(napi_env env, napi_callback_info info)
   {
      napi_value args[1]{};
      size_t argc = 1;
      napi_get_cb_info(env, info, &argc, args, /* thisVar */ nullptr, /* data */ nullptr);
      if (argc < 1) {
         return nullptr;
      }

      if (g_strongRef != nullptr) {
         napi_delete_strong_reference(env, g_strongRef);
         g_strongRef = nullptr;
      }
      napi_create_strong_reference(env, args[0], &g_strongRef);
      return nullptr;
   }

   static napi_value NAPI_Global_releaseObject(napi_env env, [[maybe_unused]] napi_callback_info info)
   {
      if (g_strongRef != nullptr) {
         napi_delete_strong_reference(env, g_strongRef);
         g_strongRef = nullptr;
      }
      return nullptr;
   }

   static napi_value NAPI_Global_queryObject(napi_env env, [[maybe_unused]] napi_callback_info info)
   {
      napi_value result {};
      napi_get_strong_reference_value(env, g_strongRef, &result);
      return result;
   }

   // Register the module.
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
      std::vector<napi_property_descriptor> desc{
         {"saveOrReplaceObject", nullptr, NAPI_Global_saveOrReplaceObject, nullptr, nullptr, nullptr, napi_default, nullptr},
         {"releaseObject", nullptr, NAPI_Global_releaseObject, nullptr, nullptr, nullptr, napi_default, nullptr},
         {"queryObject", nullptr, NAPI_Global_queryObject, nullptr, nullptr, nullptr, napi_default, nullptr},
      };
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
   export const saveOrReplaceObject: <T>(val: T) => void;
   export const queryObject: <T>() => T;
   export const releaseObject: () => void;
   ```

- ArkTS sample code

   ```ts
   // index.ets
   import testNapi from "libentry.so"

   const makeTest = <T>(val: T) => {
      testNapi.saveOrReplaceObject(val);
      const result = testNapi.queryObject<T>();
      testNapi.releaseObject();
      if (val !== result) {
         throw new Error("result not equals to input");
      }
   }

   // The following calls are expected to be normal.
   makeTest(0);
   makeTest("0");
   makeTest(true);
   makeTest(BigInt("0"));
   makeTest([]);
   makeTest(new Object());
   makeTest(undefined);
   makeTest(null);
   ```