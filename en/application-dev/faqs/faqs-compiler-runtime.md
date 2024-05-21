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

## What should I do if cppcrash is logged with error "resolveBufferCallback get buffer failed" when multiple HSPs are loaded?

**Solution**

This problem is caused by a failure in parsing the HSP. Generally, a loading failure is caused when the HSP fails to be installed, the file to load does not exist, the application does not have the required permission, or the secure memory verification fails. Locate and resolve the problem based on the error information. Generally, the fault can be rectified by reinstalling the application.

| **Error Log**| Fault  Analysis | **Handling Suggestion** |
| -------- | -------- | -------- |
| realHapPath is empty | Failed to obtain information about the installation package. | Reinstall the application. |
| transform real path error: ERROR, pathName: PATH | Failed to parse the path using **realpath()** function.**ERROR** indicates the error information, and **PATH** indicates the path of the HSP. | Reinstall the application. |
| CreateFileMapper, mmap failed, errno ERROR. fileName: FILENAME | Failed to map the secure memory by using **mmap()** function. **ERROR** indicates the error information, and **FILENAME** indicates the file name. | The system memory is insufficient or the file is not signed. |

