# Multithreaded Operations with Custom Native Transferable Objects

In ArkTS application development, there are numerous scenarios that require binding ArkTS objects with native objects. ArkTS objects write data into native objects, which then transfer the data to the destination. A common example is writing data from an ArkTS object into a C++ database.

Native Transferable objects support two distinct modes: shared mode and transfer mode. The following demonstrates how to implement both modes.

1. Implement features in native code.

   ```cpp
   // napi_init.cpp
   #include <mutex>
   #include <unordered_set>
   #include "napi/native_api.h"
   #include <hilog/log.h>
   
   class CustomNativeObject {
   public:
       CustomNativeObject() {}
       ~CustomNativeObject() = default;
       static CustomNativeObject& GetInstance()
       {
           static CustomNativeObject instance;
           return instance;
       }
   
       static napi_value GetAddress(napi_env env, napi_callback_info info)
       {
           napi_value thisVar = nullptr;
           napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
           if (thisVar == nullptr) {
               return nullptr;
           }
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           
           uint64_t addressVal = reinterpret_cast<uint64_t>(object);
           napi_value address = nullptr;
           napi_create_bigint_uint64(env, addressVal, &address);
           return address;
       }
   
       // Obtain the array size.
       static napi_value GetSetSize(napi_env env, napi_callback_info info)
       {
           napi_value thisVar = nullptr;
           napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
           if (thisVar == nullptr) {
               return nullptr;
           }
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           CustomNativeObject* obj = static_cast<CustomNativeObject*>(object);
           std::lock_guard<std::mutex> lock(obj->numberSetMutex_);
           uint32_t setSize = reinterpret_cast<CustomNativeObject*>(object)->numberSet_.size();
           napi_value napiSize = nullptr;
           napi_create_uint32(env, setSize, &napiSize);
           return napiSize;
       }
   
       // Insert an element into the array.
       static napi_value Store(napi_env env, napi_callback_info info)
       {
           size_t argc = 1;
           napi_value args[1] = {nullptr};
           napi_value thisVar = nullptr;
           napi_get_cb_info(env, info, &argc, args, &thisVar, nullptr);
           if (argc != 1) {
               napi_throw_error(env, nullptr, "Store args number must be one.");
               return nullptr;
           }
           napi_valuetype type = napi_undefined;
           napi_typeof(env, args[0], &type);
           if (type != napi_number) {
               napi_throw_error(env, nullptr, "Store args is not number.");
               return nullptr;
           }
           if (thisVar == nullptr) {
               return nullptr;
           }
           
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           
           uint32_t value = 0;
           napi_get_value_uint32(env, args[0], &value);
           CustomNativeObject* obj = static_cast<CustomNativeObject*>(object);
           std::lock_guard<std::mutex> lock(obj->numberSetMutex_);
           reinterpret_cast<CustomNativeObject *>(object)->numberSet_.insert(value);
           return nullptr;
       }
   
       // Delete an element from the array.
       static napi_value Erase(napi_env env, napi_callback_info info)
       {
           size_t argc = 1;
           napi_value args[1] = {nullptr};
           napi_value thisVar = nullptr;
           napi_get_cb_info(env, info, &argc, args, &thisVar, nullptr);
           if (argc != 1) {
               napi_throw_error(env, nullptr, "Erase args number must be one.");
               return nullptr;
           }
           napi_valuetype type = napi_undefined;
           napi_typeof(env, args[0], &type);
           if (type != napi_number) {
               napi_throw_error(env, nullptr, "Erase args is not number.");
               return nullptr;
           }
           if (thisVar == nullptr) {
               return nullptr;
           }
           
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           
           uint32_t value = 0;
           napi_get_value_uint32(env, args[0], &value);
           
           CustomNativeObject* obj = static_cast<CustomNativeObject*>(object);
           std::lock_guard<std::mutex> lock(obj->numberSetMutex_);
           reinterpret_cast<CustomNativeObject *>(object)->numberSet_.erase(value);
           return nullptr;
       }
   
       // Clear the array.
       static napi_value Clear(napi_env env, napi_callback_info info)
       {
           napi_value thisVar = nullptr;
           napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
           if (thisVar == nullptr) {
               return nullptr;
           }
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           CustomNativeObject* obj = static_cast<CustomNativeObject*>(object);
           std::lock_guard<std::mutex> lock(obj->numberSetMutex_);
           reinterpret_cast<CustomNativeObject *>(object)->numberSet_.clear();
           return nullptr;
       }
       
       // Set the transmission mode.
       static napi_value SetTransferDetached(napi_env env, napi_callback_info info)
       {
           size_t argc = 1;
           napi_value args[1];
           napi_value thisVar;
           napi_get_cb_info(env, info, &argc, args, &thisVar, nullptr);
           if (argc != 1) {
               napi_throw_error(env, nullptr, "SetTransferDetached args number must be one.");
               return nullptr;
           }
           
           if (thisVar == nullptr) {
               return nullptr;
           }
           
           napi_valuetype type = napi_undefined;
           napi_typeof(env, args[0], &type);
           if (type != napi_boolean) {
               napi_throw_error(env, nullptr, "SetTransferDetached args is not boolean.");
               return nullptr;
           }
           
           bool isDetached;
           napi_get_value_bool(env, args[0], &isDetached);
           
           void* object = nullptr;
           napi_unwrap(env, thisVar, &object);
           if (object == nullptr) {
               return nullptr;
           }
           CustomNativeObject* obj = static_cast<CustomNativeObject*>(object);
           std::lock_guard<std::mutex> lock(obj->numberSetMutex_);
           obj->isDetached_ = isDetached;
           return nullptr;
       }
       
       bool isDetached_ = false;
   
   private:
       CustomNativeObject(const CustomNativeObject &) = delete;
       CustomNativeObject &operator=(const CustomNativeObject &) = delete;
   
       std::unordered_set<uint32_t> numberSet_{};
       std::mutex numberSetMutex_{};
   };
   
   void FinializeCallback(napi_env env, void *data, void *hint)
   {
       return;
   }
   
   // Detach a callback. Generally, it is called in serialization to perform cleanup operations when the object is detached.
   void* DetachCallback(napi_env env, void *value, void *hint)
   {
       if (hint == nullptr) {
           return value;
       }
       napi_value jsObject = nullptr;
       napi_get_reference_value(env, reinterpret_cast<napi_ref>(hint), &jsObject);
       void* object = nullptr;
       if (static_cast<CustomNativeObject*>(value)->isDetached_) {
           napi_remove_wrap(env, jsObject, &object);
       }
       return value;
   }
   
   // Attach the callback, which is called during deserialization.
   napi_value AttachCallback(napi_env env, void* value, void* hint)
   {
       napi_value object = nullptr;
       napi_create_object(env, &object);
       napi_property_descriptor desc[] = {
           {"getAddress", nullptr, CustomNativeObject::GetAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"getSetSize", nullptr, CustomNativeObject::GetSetSize, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"store", nullptr, CustomNativeObject::Store, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"erase", nullptr, CustomNativeObject::Erase, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"clear", nullptr, CustomNativeObject::Clear, nullptr, nullptr, nullptr, napi_default, nullptr}};
       napi_define_properties(env, object, sizeof(desc) / sizeof(desc[0]), desc);
       // Bind the ArkTS object's lifecycle of the native object.
       napi_wrap(env, object, value, FinializeCallback, nullptr, nullptr);
       // Enable the ArkTS object to carry native information.
       napi_coerce_to_native_binding_object(env, object, DetachCallback, AttachCallback, value, nullptr);
       return object;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           {"getAddress", nullptr, CustomNativeObject::GetAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"getSetSize", nullptr, CustomNativeObject::GetSetSize, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"store", nullptr, CustomNativeObject::Store, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"erase", nullptr, CustomNativeObject::Erase, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"clear", nullptr, CustomNativeObject::Clear, nullptr, nullptr, nullptr, napi_default, nullptr},
           {"setTransferDetached", nullptr, CustomNativeObject::SetTransferDetached, nullptr, nullptr, nullptr, napi_default, nullptr}};
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       auto &object = CustomNativeObject::GetInstance();
       napi_wrap(env, exports, reinterpret_cast<void*>(&object), FinializeCallback, nullptr, nullptr);
       napi_ref exportsRef;
       napi_create_reference(env, exports, 1, &exportsRef);
       napi_coerce_to_native_binding_object(env, exports, DetachCallback, AttachCallback, reinterpret_cast<void*>(&object), exportsRef);
       return exports;
   }
   EXTERN_C_END
   
   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```


2. Declare the APIs in ArkTS.

   ```ts
   // Index.d.ts
   export const getAddress: () => number;
   export const getSetSize: () => number;
   export const store: (a: number) => void;
   export const erase: (a: number) => void;
   export const clear: () => void;
   export const setTransferDetached: (b : boolean) => number;
   ```

3. Call native functions from ArkTS objects.
   
   In transfer mode, after cross-thread transfer, the original ArkTS object is unbound from the native object and can no longer access it. The following is an example:
   ```ts
   import testNapi from 'libentry.so';
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   function getAddress() {
     let address: number = testNapi.getAddress();
     console.info("taskpool:: address is " + address);
   }
   
   @Concurrent
   function store(a:number, b:number, c:number) {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before store");
     testNapi.store(a);
     testNapi.store(b);
     testNapi.store(c);
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after store");
   }
   
   @Concurrent
   function erase(a:number) {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before erase");
     testNapi.erase(a);
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after erase");
   }
   
   @Concurrent
   function clear() {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before clear");
     testNapi.clear();
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after clear");
   }
   
   // Transfer mode.
   async function test(): Promise<void> {
     // Set setTransferDetached to true to enable the transfer mode.
     testNapi.setTransferDetached(true);
     let address:number = testNapi.getAddress();
     console.info("host thread address is " + address);
   
     let task1 = new taskpool.Task(getAddress, testNapi);
     await taskpool.execute(task1);
     
     let task2 = new taskpool.Task(store, 1, 2, 3);
     await taskpool.execute(task2);
   
     let task3 = new taskpool.Task(store, 4, 5, 6);
     await taskpool.execute(task3);

     // In transfer mode, after testNapi is transferred across threads, the main thread can no longer access the value of the native object.
     let size:number = testNapi.getSetSize();
     // The output log is "host thread size is undefined".
     console.info("host thread size is " + size);
   
     let task4 = new taskpool.Task(erase, 3);
     await taskpool.execute(task4);
   
     let task5 = new taskpool.Task(erase, 5);
     await taskpool.execute(task5);
   
     let task6 = new taskpool.Task(clear);
     await taskpool.execute(task6);
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               test();
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

   In shared mode, the original ArkTS object retains access to the native object after cross-thread transfer. The following is an example:
   ```ts
   import testNapi from 'libentry.so';
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   function getAddress() {
     let address: number = testNapi.getAddress();
     console.info("taskpool:: address is " + address);
   }
   
   @Concurrent
   function store(a:number, b:number, c:number) {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before store");
     testNapi.store(a);
     testNapi.store(b);
     testNapi.store(c);
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after store");
   }
   
   @Concurrent
   function erase(a:number) {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before erase");
     testNapi.erase(a);
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after erase");
   }
   
   @Concurrent
   function clear() {
     let size:number = testNapi.getSetSize();
     console.info("set size is " + size + " before clear");
     testNapi.clear();
     size = testNapi.getSetSize();
     console.info("set size is " + size + " after clear");
   }
   
   // Shared mode.
   async function test(): Promise<void> {
     let address:number = testNapi.getAddress();
     console.info("host thread address is " + address);
   
     let task1 = new taskpool.Task(getAddress, testNapi);
     await taskpool.execute(task1);
   
     let task2 = new taskpool.Task(store, 1, 2, 3);
     await taskpool.execute(task2);
   
     let task3 = new taskpool.Task(store, 4, 5, 6);
     await taskpool.execute(task3);
   
     // In shared mode, after testNapi is transferred across threads, the main thread can continue to access the value of the native object.
     let size:number = testNapi.getSetSize();
     // The output log is "host thread size is 6".
     console.info("host thread size is " + size);
   
     let task4 = new taskpool.Task(erase, 3);
     await taskpool.execute(task4);
   
     let task5 = new taskpool.Task(erase, 5);
     await taskpool.execute(task5);
   
     let task6 = new taskpool.Task(clear);
     await taskpool.execute(task6);
   }
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               test();
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
