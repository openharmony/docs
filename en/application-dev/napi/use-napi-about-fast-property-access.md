# Accelerating Property Access Using Extended Node-APIs

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @shilei123; @starunvs-->
<!--Designer: @shilei123; @starunvs-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:40:00.386Z pushedAt=2026-08-12T11:14:06.727Z -->

Starting from API version 24, OpenHarmony provides fast property access interfaces based on callsite caching. By creating an `napi_callsite_info` handle for each callsite, you can cache the structural information of an object when repeatedly accessing properties with the same key name, thereby accelerating property access and significantly improving property access performance.

> **NOTE**
>
> - Each distinct callsite should create an independent `napi_callsite_info` handle. The same handle can be reused across multiple calls.
> - `napi_callsite_info` does not support cross-thread usage. Each handle can only be used in the thread where it is created.
> - When no longer needed, you must call `napi_delete_callsite_info` to release the `napi_callsite_info` handle.
> - The `info` parameter of `napi_get_property_with_callsite_info` and `napi_set_property_with_callsite_info` can be NULL, in which case the behavior is equivalent to that of ordinary `napi_get_property`/`napi_set_property`.
> - `napi_get_property_with_callsite_info` and `napi_set_property_with_callsite_info` support a nullable `hit` output parameter (`bool*`): true indicates a hit (fast path), and false indicates a miss.

## When to Use

When you need to perform a large number of repeated property read/write operations on the same property key name (for example, batch processing of object arrays in a hot loop), using callsite caching can improve performance.

**Performance Characteristics**

- **Cache hit** (the object has the same structure): Performance is significantly improved compared to `napi_get_property`/`napi_set_property`.

- **Cache invalidation**: Performance degrades compared to ordinary property access APIs due to additional check and fallback overhead.

  - When too many object types are passed to the same callsite, the cache for that callsite overflows and becomes invalid, permanently falling back to the slow path.

  - **The same `napi_callsite_info` handle must not be used for both get and set.** The cached information for get and set cannot be shared. Passing a handle used for `napi_get_property_with_callsite_info` to `napi_set_property_with_callsite_info` (or vice versa) invalidates the cache and enters the slow path.

     ```c++
     // Incorrect example: The same handle is used for both get and set, causing cache invalidation.
     napi_callsite_info shared_info;
     napi_create_callsite_info(env, &shared_info);
     napi_get_property_with_callsite_info(env, obj, key, shared_info, &val, nullptr);
     napi_set_property_with_callsite_info(env, obj, key, new_val, shared_info, nullptr); // Cache invalidated.
     napi_delete_callsite_info(env, shared_info);

     // Correct example: Use separate handles for get and set.
     napi_callsite_info get_info, set_info;
     napi_create_callsite_info(env, &get_info);
     napi_create_callsite_info(env, &set_info);
     napi_get_property_with_callsite_info(env, obj, key, get_info, &val, nullptr);
     napi_set_property_with_callsite_info(env, obj, key, new_val, set_info, nullptr); // Cache hit.
     napi_delete_callsite_info(env, get_info);
     napi_delete_callsite_info(env, set_info);
     ```

- **Cache miss**: If the cache is valid but a miss occurs, performance drops by 10-100% compared with the regular property access API due to additional check and fallback overhead.

**When to Use:**

- Batch repeated property access on objects with stable structures.

- High-frequency reads and writes of properties with the same key name.

**When Not to Use**

- One-time property access, where the cache initialization overhead cannot be amortized by subsequent calls.

- Highly polymorphic objects (where the same callsite frequently encounters objects with different structures), which causes cache invalidation and performance degradation.

## Available APIs

| Name | Description |
| -------- | -------- |
| [napi_create_callsite_info](../reference/native-lib/napi.md#napi_create_callsite_info) | Creates a callsite info handle for caching property access information. |
| [napi_delete_callsite_info](../reference/native-lib/napi.md#napi_delete_callsite_info) | Deletes a callsite info handle and releases associated cache resources. |
| [napi_get_property_with_callsite_info](../reference/native-lib/napi.md#napi_get_property_with_callsite_info) | Uses callsite info to quickly obtain an object property value. |
| [napi_set_property_with_callsite_info](../reference/native-lib/napi.md#napi_set_property_with_callsite_info) | Uses callsite info to quickly set an object property value. |

## Sample Code

- Module Registration

   ```c++
   // napi_init.cpp
   #include "napi/native_api.h"
   #include <vector>

   // Use the C++ RAII mechanism to manage the lifecycle of napi_callsite_info to avoid missing releases.
   // This is only an example. You can also use other encapsulation methods or directly use the raw APIs.
   class MyCallsiteInfo
   {
      napi_env env_{};
      napi_callsite_info info_{};

   public:
      explicit MyCallsiteInfo(napi_env env) : env_(env)
      {
         if (napi_create_callsite_info(env, &info_) != napi_ok)
         {
             info_ = nullptr;
             // logging
         }
      }
      ~MyCallsiteInfo()
      {
         if (info_ != nullptr) {
               napi_delete_callsite_info(env_, info_);
         }
      }
      napi_callsite_info get() const { return info_; }
   };

   // Example: Batch read the values of a specified property name from an array of objects.
   // Note: The csInfo here is only for get and cannot be used for set at the same time (create a separate handle for set).
   static napi_value NAPI_Global_batchGetProperty(napi_env env, napi_callback_info info)
   {
      napi_value args[2]{};
      size_t argc = 2;
      napi_get_cb_info(env, info, &argc, args, /* thisVar */ nullptr, /* data */ nullptr);
      if (argc < 2) {
         return nullptr;
      }

      // args[0] is the object array, and args[1] is the property key name.
      uint32_t length = 0;
      napi_get_array_length(env, args[0], &length);

      // Create callsite information to cache the object structure for faster subsequent access.
      MyCallsiteInfo csInfo(env);

      napi_value result;
      napi_create_array_with_length(env, length, &result);

      for (uint32_t i = 0; i < length; i++) {
         napi_value element;
         napi_get_element(env, args[0], i, &element);

         napi_value val;
         napi_get_property_with_callsite_info(env, element, args[1], csInfo.get(), &val, nullptr);

         napi_set_element(env, result, i, val);
      }

      return result;
   }

   // Example: Batch set the values of a specified property name in an object array.
   static napi_value NAPI_Global_batchSetProperty(napi_env env, napi_callback_info info)
   {
      napi_value args[3]{};
      size_t argc = 3;
      napi_get_cb_info(env, info, &argc, args, /* thisVar */ nullptr, /* data */ nullptr);
      if (argc < 3) {
         return nullptr;
      }

      // args[0] is the object array, args[1] is the property key name, and args[2] is the value to set.
      uint32_t length = 0;
      napi_get_array_length(env, args[0], &length);

      MyCallsiteInfo csInfo(env);

      for (uint32_t i = 0; i < length; i++) {
         napi_value element;
         napi_get_element(env, args[0], i, &element);

         napi_set_property_with_callsite_info(env, element, args[1], args[2], csInfo.get(), nullptr);
      }

      napi_value undefined;
      napi_get_undefined(env, &undefined);
      return undefined;
   }

   // Module registration
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
      std::vector<napi_property_descriptor> desc{
         {"batchGetProperty", nullptr, NAPI_Global_batchGetProperty, nullptr, nullptr, nullptr, napi_default, nullptr},
         {"batchSetProperty", nullptr, NAPI_Global_batchSetProperty, nullptr, nullptr, nullptr, napi_default, nullptr},
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

- Interface declaration

   ```ts
   // index.d.ts
   export const batchGetProperty: (objects: object[], key: string) => (string | number | boolean | undefined | null)[];
   export const batchSetProperty: (objects: object[], key: string, value: string | number | boolean) => void;
   ```

- ArkTS code example:

   ```ts
   // index.ets
   import testNapi from "libentry.so"

   class Item {
      name: string = '';
      value: string = '';

      constructor(name: string, value: string) {
         this.name = name;
         this.value = value;
      }
   }

   @Entry
   @Component
   struct Index {
      @State message: string = 'Click to run the sample';

      build() {
         Row() {
            Column() {
               Text(this.message)
                  .fontSize(20)
                  .fontWeight(FontWeight.Bold)
                  .onClick(() => {
                     // Construct a batch of objects with the same structure
                     const objects: Item[] = [];
                     for (let i = 0; i < 3; i++) {
                        objects.push(new Item(`item_${i}`, `val_${i}`));
                     }

                     // Use napi_get_property_with_callsite_info to batch read properties.
                     const names = testNapi.batchGetProperty(objects, "name");
                     // Expected result: ["item_0","item_1","item_2"]

                     // Use napi_set_property_with_callsite_info to batch set properties.
                     testNapi.batchSetProperty(objects, "value", "updated");
                     const values = testNapi.batchGetProperty(objects, "value");
                     // Expected result: ["updated","updated","updated"]

                     this.message = `get "name": ${JSON.stringify(names)}\nget "value" after set: ${JSON.stringify(values)}`;
                  })
            }
            .width('100%')
         }
         .height('100%')
      }
   }
   ```