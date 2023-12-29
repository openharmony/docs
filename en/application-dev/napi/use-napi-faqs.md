# OpenHarmony Node-API FAQs


## What if "undefined/not callable" is reported when the module imported to ArkTS/JS is used?

1. Check whether the module name in the .cpp file used in module registration is the same as that in the so name.<br>For example, if the module name is **entry**, the so name must be **libentry.so**, and the **nm_modname** field in **napi_module** must be **entry**. The module names must be of the same case.
   
2. Check whether the .so file is successfully loaded.<br>
   Check the logs of the module loading during application startup. Search for the keyword "dlopen" and check for related error information. Common causes of a loading failure include permission denied, failure to load dependent so, and incorrect loading path.

3. Check whether the dependent .so files are successfully loaded.<br>
   Check that all the dependent .so files are packaged into the application and you have the permission to open them.

4. Check whether the module import mode matches the SO path.<br>
   If the module is imported by using **import xxx from '\@ohos.yyy.zzz'**, you may find **libzzz.z.so** or **libzzz_napi.z.so** in **/system/lib/module/yyy**. If the .so file does not exist or the file names do not match, dlopen-related error will be reported.

   Note that the path is **/system/lib** for a 32-bit system and **/system/lib64** for a 64-bit system.


## What if an unexpected value is returned by an API and "occur exception need return" is reported?

Before the call is complete, some Node-API interfaces are checked for JS exceptions in the VM. If an exception is detected, "occur exception need return" will be reported, with the line number of the code and the Node-API interface name.

You can solve this problem as follows:

- If the exception does not matter, clear the exception.<br>
  Call **napi_get_and_clear_last_exception** before "occur exception need return" is printed to clear the exception.

- Throw the exception to the ArkTS layer for capture.<br>
  Throw the exception directly to the ArkTS layer without going through redundant Native logic.


## What are the differences between the lifecycle of napi_value and napi_ref?

- **native_value** is managed by **HandleScope**. Generally, you do not need to add **HandleScope** for **native_value** (except **complete callback** of **uv_queue_work**).

- **napi_ref** must be deleted manually.


## How do I locate the fault if the return value of a Node-API interface is not "napi_ok"?

When a Node-API interface is successfully executed, an enum value of **napi_ok** is returned. If the return value is not **napi_ok**, locate the fault as follows:

- Before a Node-API interface is executed, the input parameters are verified. A null check is performed first. The code is as follows:
  ```
  CHECK_ENV: null check for env.
  CHECK_ARG: null check for other input parameters.
  ```

- An input parameter type check is performed for some Node-API interfaces. For example, **napi_get_value_double** is used to obtain a C double value from a JS number, and the type of the JS value passed in must be number. The parameter type check is as follows:
  ```
  RETURN_STATUS_IF_FALSE(env, nativeValue->TypeOf() == NATIVE_NUMBER, napi_number_expected);
  ```

- For some interfaces, the execution result is verified. For example, **napi_call_function** is used to execute a JS function. When an exception occurs in the JS function, Node-API returns a status value of **napi_pending_exception**.
  ```
  auto resultValue = engine->CallFunction(nativeRecv, nativeFunc, nativeArgv, argc); 
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- Some status values need to be analyzed based on the specific Node-API interface. Determine the status value, and analyze the situation, in which the status value is returned, to locate the cause of the error.
