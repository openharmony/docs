# Cross-thread invoking is implemented in native mode.

## Introduction

In OpenHarmony application development practices, some time-consuming tasks, such as I/O operations, domain name resolution, and complex computing, are often encountered. If these tasks are directly executed in the main thread, the main thread will be severely blocked, affecting the normal process of subsequent tasks. As a result, the user interface response is delayed or even frame freezing occurs. Therefore, to improve code performance, such time-consuming tasks are usually executed in subthreads. 
This document focuses on how to use native to implement cross-thread invoking, that is, use thread-safe functions and libuv asynchronous I/O tool libraries to optimize program performance and maintain smooth user experience.

## Notes

The following describes how to create subthreads in native mode to execute time-consuming tasks and ensure seamless interaction with JavaScript. Therefore, developers can use the [NAPI (Node-API)](../reference/native-lib/napi.md) interface provided by the [arkui_napi](https://gitee.com/openharmony/arkui_napi) repository to implement cross-language invoking. The design of the NAPI strictly complies with the NAPI specifications of the [Node.js](https://nodejs.org/api/n-api.html) so that developers can easily understand and use the NAPI. 
It is particularly emphasized that JavaScript functions can be called only in the main thread. If a subthread is created using std::thread or pthread on the native side, napi_env, napi_value, and napi_ref cannot be directly used in the subthread context. To ensure correctness, if the JavaScript function needs to be called back after the native end completes the calculation or processing of the subthread, the result must be transferred back to the main thread through the thread synchronization mechanism. Then the JavaScript function can be securely called in the main thread environment. 
To solve this problem, the following two effective solutions are proposed.

## Solution

### linear safe function

napi_threadsafe_function provides an interface to create a function object that can be shared and securely used among multiple threads. With this mechanism, subthreads can transfer data to the main thread. After receiving the data, the main thread calls the JavaScript callback function to process the data. This interface contains methods for creating and destroying thread-safe functions and for sending messages and synchronizing data between them. The general procedure for using napi_threadsafe_function includes:

Creating a thread-safe function: Call napi_create_threadsafe_function() to create a thread-safe function object. During this process, you need to specify a JavaScript callback function, which is executed on the main thread. In addition, you need to set related context information, which can be shared among multiple threads and can be obtained by calling napi_get_threadsafe_function_context() at any time. In addition, a napi_finalize callback can be selectively provided to perform resource cleanup operations when thread-safe functions are destroyed.

Obtaining the right to use a thread-safe function: Before using a thread-safe function, call the napi_acquire_threadsafe_function() function to indicate that the thread is ready and you can perform operations on the thread-safe function.

Callback from a subthread: In a subthread, napi_call_threadsafe_function() is called to asynchronously trigger the JavaScript callback function and transfer the required data as parameters to the callback function. The call is queued and finally executed on the JavaScript main thread.

Resource cleanup: When a thread-safe function is no longer needed, the resources associated with it should be correctly released and cleaned up. Generally, the napi_release_threadsafe_function() function is called. This function processes the callback that is not complete according to the preset policy and destroys the thread-safe function object.

### Extending the Life Cycle
The lifecycle of a function reference transferred to the native layer at the JavaScript layer is limited to the scope where the function reference is located. To ensure that the function reference can continue to be used beyond the scope, you need to take appropriate measures to extend its lifecycle. 
You can call napi_create_reference to create a reference for a JavaScript object. In this way, the object is prevented from being released in advance due to the garbage collection mechanism, thereby effectively prolonging the lifecycle of the object. However, after creating a reference, remember to call napi_delete_reference to release the reference when it is no longer needed to prevent memory leaks. 
In-depth understanding and proper management of the lifecycle of objects between JavaScript and native interfaces are critical to writing efficient code without memory leakage risks. It is recommended that developers further study documents and best practices related to Lifecycle Management (./develop-Native-modules-using-NAPI-safely-and-efficiently.md) to better master them.

### libuv

[libuv](../reference/native-lib/libuv.md) is an event-driven asynchronous I/O library. Time-consuming operations are directly processed in the main loop (event loop) of libuv, the execution of subsequent tasks is blocked. To solve this problem, libuv maintains a thread pool to perform some time-consuming operations. After these operations are complete, the callback function is added back to the event loop of the main thread for execution. 
By default, the thread pool provided by libuv contains four threads as the basic working unit, but the maximum number of threads can be expanded to 128. You can customize the number of threads in the thread pool by presetting the value of the environment variable UV_THREADPOOL_SIZE. When the thread pool is initialized, the corresponding number of worker threads are created and a uv_queue_work function is run inside each thread. 
It should be noted that the thread pool in libuv is a global shared resource. No matter how many independent event loop instances exist in the application, they share the same thread pool. Such a design aims to effectively utilize system resources while avoiding the overhead caused by frequent creation and destruction of threads.

#### uv_queue_work
   ```c++
    uv_queue_work(uv_loop_t* loop,
                  uv_work_t* req,
                  uv_work_cb work_cb,
                  uv_after_work_cb after_work_cb);
   ```
Initializes a work request. By calling the uv_queue_work function, you can schedule a specified task to be executed on a thread in the thread pool associated with the event loop. Once the task (that is, the work_cb callback function) completes its operation, another callback function after_work_cb is called in the event loop thread. 
The parameters are described as follows: 
loop: pointer to the event loop structure. All asynchronous operations are managed in the event loop context. 
req: pointer to the uv_work_t structure, which is used to transfer data to the work request and callback function. Generally, developers assign user-defined data to the req->data member variable for use in callback. 
work_cb: callback function for executing the actual work. Some time-consuming operations can be performed here. This function runs on a thread in the thread pool. 
after_work_cb: callback function called on the event loop thread after the work is complete. It is usually used to process the work_cb execution result or trigger further operations at the JavaScript layer.   
Note that although the uv_queue_work method does not directly involve the NAPI (Node-API) interface, when interaction with the JavaScript thread is involved, especially when data is transferred from the native layer to the JavaScript layer and callback is triggered, the lifecycle of the napi_value object needs to be correctly managed. napi_handle_scope and related interfaces must be properly used to ensure that the napi_value object created by the JavaScript callback method is valid during the entire execution process and resources are released at a proper time to avoid memory leakage. 

## Example
The following examples use thread-safe functions and libuv to implement native cross-thread invoking. In this example, the variable value is increased by 10 in the JavaScript callback function transferred from the ArkTS. Three subthreads are enabled on the Native side to execute the service logic. After the service logic of the subthreads is complete, the main thread executes the JavaScript callback function transferred from the ArkTS, in this way, the value of the ArkTS variable is increased by 30. [Complete sample code] (https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary/feature/nativeThreadsCallJS) is as follows:
### 1. Using Thread-safe Functions
**ArkTS implements a JavaScript callback function.**  
The parameter is param. In the function body, add 10 to param, bind the variable value, and return the latest param value. Use the callback function as a parameter to call the ThreadSafeTest interface on the Native side. 

   ```typescript
    //  src/main/ets/pages/Index.ets
        
    Button("threadSafeTest")
      .width('40%')
      .fontSize(20)
      .onClick(()=> {
        // Native uses thread-safe functions to implement cross-thread invoking.
        entry.ThreadSafeTest((param: number) => {
          param += 10;
          logger.info('ThreadSafeTest js callback value = ', param.toString());
          this.value = param;
          return param;
        }
      )
    }).margin(20)
   ```
**Implement the ThreadSafeTest interface in the native main thread.**     
After receiving the JavaScript callback function transferred by ArkTS, the interface creates a thread-safe function tsfn through napi_create_threadsafe_function. tsfn calls back ThreadSafeCallJs in the main thread, then, call the JavaScript callback function transferred from the ArkTS end in ThreadSafeCallJs. 
    
  ```c++
    //  src/main/cpp/hello.cpp

    napi_threadsafe_function tsfn; //Thread-safe function
    static int g_cValue; //Save the latest value of value and transfer it to the JS callback function as a parameter.
    int g_threadNum = 3; //Number of threads

    struct CallbackContext {
        napi_env env = nullptr;
        napi_ref callbackRef = nullptr;
        int retData = 0;
    };

    //Security function callback
    static void ThreadSafeCallJs(napi_env env, napi_value js_cb, void *context, void *data)
    {
        CallbackContext *argContent = (CallbackContext *)data;
        if (argContent != nullptr) {
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest CallJs start, retData:[%{public}d]", argContent->retData);
            napi_get_reference_value(env, argContent->callbackRef, &js_cb);
        } else {
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest CallJs argContent is null");
            return;
        }

        napi_valuetype valueType = napi_undefined;
        napi_typeof(env, js_cb, &valueType);
        if (valueType != napi_valuetype::napi_function) {
            OH_LOG_ERROR(LOG_APP, "ThreadSafeTest callback param is not function");
            if (argContent != nullptr) {
                napi_delete_reference(env, argContent->callbackRef);
                delete argContent;
                argContent = nullptr;
                OH_LOG_INFO(LOG_APP, "ThreadSafeTest delete argContent");
            }
            return;
        }
        //Use the current value as a parameter to call the JS function.
        napi_value argv;
        napi_create_int32(env, g_cValue, &argv);
        napi_value result = nullptr;
        napi_call_function(env, nullptr, js_cb, 1, &argv, &result);
        // g_cValue saves the result returned after the JS is called.
        napi_get_value_int32(env, result, &g_cValue);
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest CallJs end, [%{public}d]", g_cValue);
        if (argContent != nullptr) {
            napi_delete_reference(env, argContent->callbackRef);
            delete argContent;
            argContent = nullptr;
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest delete argContent end");
        }
    }
    
    //Use secure functions to call JS functions across threads.
    static napi_value ThreadSafeTest(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value js_cb;
        napi_value workName;
        //Obtain ArkTS parameters.
        napi_get_cb_info(env, info, &argc, &js_cb, nullptr, nullptr);
        // Determine the parameter type.
        napi_valuetype valueType = napi_undefined;
        napi_typeof(env, js_cb, &valueType);
        if (valueType != napi_valuetype::napi_function) {
        OH_LOG_ERROR(LOG_APP, "ThreadSafeTest callback param is not function");
        return nullptr;
        }
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest current value: [%{public}d]", g_cValue);
    
        //Use the security thread to call the JS function across threads.
        napi_create_string_utf8(env, "workItem", NAPI_AUTO_LENGTH, &workName);
        //Create a thread-safe function.
        napi_create_threadsafe_function(env, js_cb, NULL, workName, 0, 1, NULL, NULL, NULL, ThreadSafeCallJs, &tsfn);
  ```
**Invoke the thread-safe function in the native subthread.**    
Create a subthread by using std::thread, call the thread-safe function tsfn by using napi_call_threadsafe_function in the subthread, and transfer the CallbackContext structure data as a parameter to ThreadSafeCallJs. Simple service processing is performed in the subthread. Developers can perform service operations based on their actual requirements. 
  
  ```c++
  //   src/main/cpp/hello.cpp

    //Call the thread-safe function in the subthread.
    for (int i = 0; i < g_threadNum; i++) {
        //Create callback parameters.
        auto asyncContext = new CallbackContext();
        asyncContext->env = env;
        asyncContext->retData = i;
        napi_create_reference(env, js_cb, 1, &asyncContext->callbackRef);
        std::thread t([asyncContext]() {
            //Process the service logic.
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest ChildTread start, index:[%{public}d], value: [%{public}d]",
                        asyncContext->retData, g_cValue);
            asyncContext->retData++;
            //Request thread security functions.
            napi_acquire_threadsafe_function(tsfn);
            //Call the thread-safe function.
            napi_call_threadsafe_function(tsfn, asyncContext, napi_tsfn_nonblocking);
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest ChildTread end, index:[%{public}d], value: [%{public}d]",
                        asyncContext->retData, g_cValue);

            /* If the JS function is directly called in a subthread, the system breaks down.
            napi_value result = nullptr;
            napi_value argv;
            napi_create_int32(env,g_cValue, &argv);
            napi_call_function(env, nullptr, js_cb, 1, &argv, &result);
          */
        });
        t.join();
    }
    //Release the security thread.
    napi_status status = napi_release_threadsafe_function(tsfn, napi_tsfn_release);
    if (status == napi_status::napi_ok) {
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest napi_tsfn_release success.");
    } else {
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest napi_tsfn_release fail !");
    }
  ```

### 2. Using libuv
**ArkTS implements a JavaScript callback function.**     
The parameter is param. In the function body, add 10 to param, bind the variable value, and return the latest param value. Then, the callback function is used as a parameter to call the UvWorkTest interface on the native side.

   ```typescript
    //  src/main/ets/pages/Index.ets
        
    Button("libuvTest")
      .width('40%')
      .fontSize(20)
      .onClick(()=> {
        // Native uses thread-safe functions to implement cross-thread invoking.
        entry.UvWorkTest((param: number) => {
          param += 10;
          logger.info('UvWorkTest js callback value = ', param.toString());
          this.value = param;
          return param;
        }
      )
    }).margin(20)
   ```
**Implement a UvWorkTest interface in the native main thread.**    
After receiving the JavaScript callback function transferred by ArkTS, the interface creates a sub-thread, creates a work task workReq in the execution function CallbackUvWorkTest of the sub-thread, and adds the work task to the libuv queue through uv_queue_work.

  ```c++
  //   src/main/cpp/hello.cpp

    void CallbackUvWorkTest(CallbackContext *context)
    {
        if (context == nullptr) {
            OH_LOG_ERROR(LOG_APP, "UvWorkTest context is nullptr");
            return;
        }
        uv_loop_s *loop = nullptr;
        napi_get_uv_event_loop(context->env, &loop);
        //Create a working data structure. The customized data structure is added to data.
        uv_work_t *workReq = new uv_work_t;
        if (workReq == nullptr) {
            if (context != nullptr) {
                napi_delete_reference(context->env, context->callbackRef);
                delete context;
                OH_LOG_INFO(LOG_APP, "UvWorkTest delete context");
                context = nullptr;
            }
            OH_LOG_ERROR(LOG_APP, "UvWorkTest new uv_work_t fail!");
            return;
        }
        workReq->data = (void *)context;
        //This print is located in the child thread.
        OH_LOG_INFO(LOG_APP, "UvWorkTest childThread_1 [%{public}d]", g_cValue);
        //Add the work task to the libuv queue.
        uv_queue_work(loop, workReq, WorkCallback, AfterWorkCallback);
    }
    
    //Use uv_work callback to call JS functions across threads.
    static napi_value UvWorkTest(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value argv[1] = {0};
        napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    
        napi_valuetype valueType = napi_undefined;
        napi_typeof(env, argv[0], &valueType);
        if (valueType != napi_function) {
            OH_LOG_ERROR(LOG_APP, "UvWorkTest param is not function");
            return nullptr;
        }
    
        OH_LOG_INFO(LOG_APP, "UvWorkTest current value:[%{public}d]", g_cValue);
        for (int i = 0; i < g_threadNum; i++) {
            auto asyncContext = new CallbackContext();
            if (asyncContext == nullptr) {
                OH_LOG_ERROR(LOG_APP, "UvWorkTest new asyncContext fail!");
                return nullptr;
            }
            asyncContext->env = env;
            asyncContext->retData = i;
            OH_LOG_INFO(LOG_APP, "UvWorkTest thread begin index:[%{public}d], value:[%{public}d]", i, g_cValue);
            napi_create_reference(env, argv[0], 1, &asyncContext->callbackRef);
            // using callback function on other thread
            std::thread testThread(CallbackUvWorkTest, asyncContext);
            testThread.detach();
            OH_LOG_INFO(LOG_APP, "UvWorkTest thread end index:[%{public}d], value:[%{public}d]", i, g_cValue);
        }
        return nullptr;
    }
  ```
**Implement work_cb and after_work_cb.**    
work_cb is located in the subthread and executes the actual service logic. after_work_cb is located in the main thread and calls the JavaScript callback function transferred from the ArkTS end through napi_call_function.

  ```c++
    // src/main/cpp/hello.cpp

    void WorkCallback(uv_work_t *workReq)
    {
        // Another subthread. Some time-consuming operations can be performed here. The JS function cannot be called here.
        CallbackContext *context = (CallbackContext *)workReq->data;
        if (context != nullptr) {
            OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack1 childThread_2 [%{public}d]", context->retData);
            context->retData++;
            OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack2 childThread_2 [%{public}d]", context->retData);
        } else {
            OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack3 childThread_2 context is null.");
        }
    }
    
    void AfterWorkCallback(uv_work_t *workReq, int status)
    {
        CallbackContext *context = (CallbackContext *)workReq->data;
        // Executed by the main thread. The JS function can be called here.
        OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack mainThread [%{public}d]", context->retData);
        napi_handle_scope scope = nullptr;
        napi_open_handle_scope(context->env, &scope);
        if (scope == nullptr) {
            if (context != nullptr) {
                napi_delete_reference(context->env, context->callbackRef);
                delete context;
                context = nullptr;
            }
            if (workReq != nullptr) {
                delete workReq;
                workReq = nullptr;
            }
            return;
        }
        napi_value callback = nullptr;
        napi_get_reference_value(context->env, context->callbackRef, &callback);
        napi_value retArg;
        OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack begin [%{public}d]", g_cValue);
        napi_create_int32(context->env, g_cValue, &retArg);
        napi_value ret;
        napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
        //Save the JS callback result.
        napi_get_value_int32(context->env, ret, &g_cValue);
        OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack end [%{public}d]", g_cValue);
    
        napi_close_handle_scope(context->env, scope);
        if (context != nullptr) {
            napi_delete_reference(context->env, co[readme-EN.md](readme-EN.md)ntext->callbackRef);
            delete context;
            OH_LOG_INFO(LOG_APP, "UvWorkTest delete context");
            context = nullptr;
        }
        if (workReq != nullptr) {
            delete workReq;
            OH_LOG_INFO(LOG_APP, "UvWorkTest delete work");
            workReq = nullptr;
        }
    }
  ```

## Summary
In both the thread-safe function and libuv solution, after the execution function of the sub-thread is complete, the sub-thread returns to the main thread, and pushes the JavaScript callback function to the event-loop queue of the main thread for execution. 
The difference is that the sub-threads of libuv belong to the libuv thread pool, while the sub-threads of thread-safe functions need to be created based on service requirements. In addition, in libuv, the JavaScript callback function can be passively executed only after the main function of the subthread is executed. In thread security functions, the JavaScript callback function can be actively called in any thread. 
