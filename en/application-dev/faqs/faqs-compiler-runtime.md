# Compiler and Runtime


## What should I do if a crash occurs when I obtain a string in JSON format from rawfile, convert the string into an object, and call the instance method? (API version 9)

**Symptom**

"jscrash happened in xxxxxxxxx" is displayed, and the crash log contains "Error message: Unexpected Object in JSON".

**Solution**

The prototype of the object obtained by parsing the string in JSON format is object. The prototype chain does not contain the instance method. Therefore, the object cannot be called.

To solve this problem, use either of the following methods:

- Add the prototype to the parsed object.

- Change the instance method to a static method and call it through the class name.

## What should I do to prevent unexpected error behavior when **napi_call_function** is called again after a pending exception is captured in it? (API version 10)

**Symptom**

When **napi_call_function** is called to invoke an ArkTs function, a pending exception is captured.
If security check is not performed upon a pending exception, an error will occur when **napi_call_function** is called next time and the error behavior is unpredictable.

**Solution**

If an error occurs when a native method using **napi_call_function** is called by ArkTS, throw jscrash. Then, try...catch on ArkTS will fail.
If an exception occurs when **napi_call_function** is called, return a response in time.

## Are there any other exception scenarios besides the pending exception in **napi_call_function**? (API version 10)

**Solution**

Theoretically, an exception may occur when a Node-API interface is called. For critical service processes, you need to add the processing logic to check the return value and determine whether an exception occurs. The following is an example:
```cpp
napi_status status = napi_create_object(env, &object);
if (status != napi_ok) {
  napi_throw_error(env, ...);
  return;
}
```
