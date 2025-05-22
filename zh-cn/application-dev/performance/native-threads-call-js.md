# 利用native的方式实现跨线程调用

## 简介

在OpenHarmony应用开发实践中，经常会遇到一些耗时的任务，如I/O操作、域名解析以及复杂计算等。这些任务如果直接在主线程中执行，将会严重阻塞主线程，影响后续任务的正常流程，进而导致用户界面响应延迟甚至卡顿。因此，为了提升代码性能，通常会将这类耗时任务放在子线程中执行。  
本文将聚焦于如何利用native的方式实现跨线程调用，即采用线程安全函数和libuv异步I/O工具库这两种策略，来优化程序性能并保持流畅的用户体验。

## 注意事项

以下将详细阐述如何运用native方式创建子线程以执行耗时任务，并确保与JavaScript的无缝交互。为此，开发者可以利用[arkui_napi](https://gitee.com/openharmony/arkui_napi)仓库提供的[NAPI（Node-API）](../reference/native-lib/napi.md)接口来实现跨语言调用的桥梁。该NAPI的设计严格遵循[Node.js](https://nodejs.org/api/n-api.html)的NAPI规范，以便开发者能够更轻松地理解和使用。  
特别强调的是，JavaScript函数通常只能在主线程里调用。如果native侧通过std::thread或pthread创建了子线程，那么napi_env、napi_value以及napi_ref是不能直接在子线程上下文中使用的。为确保正确性，当native端在子线程完成其计算或处理后，若需要回调JavaScript函数，必须先通过线程同步机制将结果传递回主线程，然后才能安全地在主线程环境中调用JavaScript函数。  
为解决这一问题，以下将提出两种有效的解决方案。

## 解决方案

### 线性安全函数

napi_threadsafe_function 提供了接口来创建一个可以在多线程间共享并安全使用的函数对象。通过这个机制，子线程可以将数据传递给主线程，主线程接收到数据后会调用JavaScript回调函数进行处理。该接口包含用于创建、销毁线程安全函数以及在其之间发送消息和同步数据的方法。使用napi_threadsafe_function的一般步骤包括： 

**创建线程安全函数：** 通过调用napi_create_threadsafe_function()创建一个线程安全函数对象。在此过程中，需要指定一个JavaScript回调函数，该函数将在主线程上执行；同时设定相关的上下文信息，这个上下文可以在多个线程之间共享，可以随时通过调用napi_get_threadsafe_function_context()来获取。此外，还可以选择性地提供一个napi_finalize回调，用于在销毁线程安全函数时执行资源清理操作。

**获取使用权：** 在开始使用线程安全函数之前，调用napi_acquire_threadsafe_function()函数表明线程已准备就绪，可以开始对该线程安全函数进行操作。

**从子线程调用回调：** 在子线程中，通过调用napi_call_threadsafe_function()来异步触发JavaScript回调函数，并将所需数据作为参数传递给该回调函数。调用会被排队，并最终在JavaScript主线程上执行。

**资源清理：** 当线程安全函数不再需要时，应当正确地释放和清理与其关联的资源。通常调用napi_release_threadsafe_function()函数来完成的，该函数会按照预定的策略处理尚未执行完毕的回调，并最终销毁线程安全函数对象。

### 延长生命周期
在JavaScript层面传递给native层的函数引用，其生命周期仅限于它所在的作用域内。若要确保在超出该作用域后仍能继续使用这个函数引用，需要采取适当的方法来延长其生命周期。  
可以通过调用napi_create_reference为JavaScript对象创建一个引用（reference）。这样可以避免对象因垃圾回收机制而被提前释放，从而有效地延长它的生命周期。然而，在创建引用之后，务必牢记要在不再需要该引用时，调用napi_delete_reference来释放引用，以防止内存泄漏问题的发生。  
深入理解并妥善管理JavaScript与native接口之间对象的生命周期，对于编写高效且无内存泄漏隐患的代码至关重要。建议开发者进一步研究[生命周期管理](./develop-Native-modules-using-NAPI-safely-and-efficiently.md)相关文档和最佳实践，以便更好地掌握。

### libuv

[libuv](../reference/native-lib/libuv.md)是一个基于事件驱动的异步I/O库，对于耗时操作，如果直接在libuv的主循环（event loop）中处理，会阻塞后续任务的执行。为解决这个问题，libuv内部维护了一个线程池，用于执行一些耗时操作，并在这些操作完成后，将回调函数添加回主线程的event loop中等待执行。  
默认情况下，libuv提供的线程池包含4个线程作为基本工作单元，但最大线程数可以扩展到128个。通过预先设置环境变量 UV_THREADPOOL_SIZE 的值，可以自定义线程池中的线程数量。当线程池初始化时，会创建相应数量的工作线程，并在每个线程内部运行一个   uv_queue_work 函数。  
值得注意的是，libuv 中的线程池是全局共享资源，不论应用中有多少个独立的事件循环实例，它们都共用同一个线程池。这样的设计旨在有效利用系统资源，同时避免因频繁创建和销毁线程带来的开销。

#### uv_queue_work
   ```c++
    uv_queue_work(uv_loop_t* loop,
                  uv_work_t* req,
                  uv_work_cb work_cb,
                  uv_after_work_cb after_work_cb);
   ```
初始化一个工作请求，通过调用uv_queue_work函数，可以安排指定的任务，在与事件循环（event loop）关联的线程池中的一个线程上执行。一旦该任务（即work_cb回调函数）完成其操作，将在事件循环线程中调用另一个回调函数after_work_cb。  
各参数的具体意义如下：  
**loop：** 指向事件循环结构体的指针，所有异步操作都在这个事件循环上下文中进行管理。  
**req：** 指向uv_work_t结构体的指针，用于传递给工作请求和回调函数的数据。通常开发者会将自定义数据赋值给req->data成员变量以在回调中使用。  
**work_cb：** 执行实际工作的回调函数，一些耗时的操作可以在此执行，该函数在线程池的一个线程上运行。  
**after_work_cb：** 工作完成后在事件循环线程上调用的回调函数，常用于处理work_cb执行结果或触发进一步的JavaScript层面的操作。    
需要注意的是，尽管uv_queue_work方法本身不直接涉及NAPI（Node-API）接口，但当涉及到与JavaScript线程交互时，特别是从native层向JavaScript层传递数据并触发回调时，需要正确地管理napi_value对象的生命周期。这需要合理使用napi_handle_scope和相关接口，来确保在JavaScript回调方法创建的napi_value对象，在整个执行过程中保持有效，并在适当的时候释放资源，以避免内存泄漏问题。  

## 示例代码
下面的示例分别用线程安全函数和libuv实现了native的跨线程调用。该示例在ArkTS端传入的JavaScript回调函数中对变量value进行加10运算，在native侧开启了3个子线程执行业务逻辑，子线程业务逻辑完成之后回到主线程执行ArkTS端传入的JavaScript回调函数，从而完成了对ArkTS端变量value的加30操作。[完整的示例代码](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary/feature/nativeThreadsCallJS)如下：
### 1.使用线程安全函数
**ArkTS实现一个JavaScript回调函数。**  
参数为param，函数体中对参数param加10后绑定变量value，并返回最新的param值。将回调函数作为参数调用native侧的ThreadSafeTest接口。  

   ```typescript
    //  src/main/ets/pages/Index.ets
        
    Button("threadSafeTest")
      .width('40%')
      .fontSize(20)
      .onClick(()=> {
        // native使用线程安全函数实现跨线程调用
        entry.ThreadSafeTest((param: number) => {
          param += 10;
          logger.info('ThreadSafeTest js callback value = ', param.toString());
          this.value = param;
          return param;
        }
      )
    }).margin(20)
   ```
**native主线程中实现一个ThreadSafeTest接口。**     
接口接收到ArkTS传入的JavaScript回调函数后通过napi_create_threadsafe_function创建一个线程安全函数tsfn，tsfn会回调主线程中的ThreadSafeCallJs，然后在ThreadSafeCallJs中调用ArkTS端传入的JavaScript回调函数。  
    
  ```c++
    //  src/main/cpp/hello.cpp

    napi_threadsafe_function tsfn;   // 线程安全函数
    static int g_cValue;             // 保存value最新的值,作为参数传给js回调函数
    int g_threadNum = 3;             // 线程数

    struct CallbackContext {
        napi_env env = nullptr;
        napi_ref callbackRef = nullptr;
        int retData = 0;
    };

    // 安全函数回调
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
        // 将当前value值作为参数调用js函数
        napi_value argv;
        napi_create_int32(env, g_cValue, &argv);
        napi_value result = nullptr;
        napi_call_function(env, nullptr, js_cb, 1, &argv, &result);
        // g_cValue保存调用js后的返回结果
        napi_get_value_int32(env, result, &g_cValue);
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest CallJs end, [%{public}d]", g_cValue);
        if (argContent != nullptr) {
            napi_delete_reference(env, argContent->callbackRef);
            delete argContent;
            argContent = nullptr;
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest delete argContent end");
        }
    }
    
    // 使用安全函数跨线程调用js函数
    static napi_value ThreadSafeTest(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value js_cb;
        napi_value workName;
        // 获取ArkTS 参数
        napi_get_cb_info(env, info, &argc, &js_cb, nullptr, nullptr);
        // 判断参数类型
        napi_valuetype valueType = napi_undefined;
        napi_typeof(env, js_cb, &valueType);
        if (valueType != napi_valuetype::napi_function) {
        OH_LOG_ERROR(LOG_APP, "ThreadSafeTest callback param is not function");
        return nullptr;
        }
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest current value: [%{public}d]", g_cValue);
    
        // 使用安全线程跨线程调用js 函数
        napi_create_string_utf8(env, "workItem", NAPI_AUTO_LENGTH, &workName);
        // 创建线程安全函数
        napi_create_threadsafe_function(env, js_cb, NULL, workName, 0, 1, NULL, NULL, NULL, ThreadSafeCallJs, &tsfn);
  ```
**在native子线程中调用线程安全函数。**    
通过std::thread创建子线程，在子线程中通过napi_call_threadsafe_function调用线程安全函数tsfn，把CallbackContext 结构体数据作为参数传入ThreadSafeCallJs。这里在子线程中进行了简单的业务处理，开发者可以根据自身实际需求进行相应的业务操作。  
  
  ```c++
  //   src/main/cpp/hello.cpp

    // 在子线程中调用线程安全函数
    for (int i = 0; i < g_threadNum; i++) {
        // 创建回调参数
        auto asyncContext = new CallbackContext();
        asyncContext->env = env;
        asyncContext->retData = i;
        napi_create_reference(env, js_cb, 1, &asyncContext->callbackRef);
        std::thread t([asyncContext]() {
            // 处理业务逻辑
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest ChildTread start, index:[%{public}d], value: [%{public}d]",
                        asyncContext->retData, g_cValue);
            asyncContext->retData++;
            // 请求线程安全函数
            napi_acquire_threadsafe_function(tsfn);
            // 调用线程安全函数
            napi_call_threadsafe_function(tsfn, asyncContext, napi_tsfn_nonblocking);
            OH_LOG_INFO(LOG_APP, "ThreadSafeTest ChildTread end, index:[%{public}d], value: [%{public}d]",
                        asyncContext->retData, g_cValue);

            /* 以下直接在子线程中调用js函数,会崩溃
            napi_value result = nullptr;
            napi_value argv;
            napi_create_int32(env,g_cValue, &argv);
            napi_call_function(env, nullptr, js_cb, 1, &argv, &result);
          */
        });
        t.join();
    }
    // 释放安全线程
    napi_status status = napi_release_threadsafe_function(tsfn, napi_tsfn_release);
    if (status == napi_status::napi_ok) {
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest napi_tsfn_release success.");
    } else {
        OH_LOG_INFO(LOG_APP, "ThreadSafeTest napi_tsfn_release fail !");
    }
  ```

### 2.使用libuv
**ArkTS实现一个JavaScript回调函数。**     
参数为param，函数体中对参数param加10后绑定变量value，并返回最新的param值。然后将回调函数作为参数调用native侧的UvWorkTest接口。 

   ```typescript
    //  src/main/ets/pages/Index.ets
        
    Button("libuvTest")
      .width('40%')
      .fontSize(20)
      .onClick(()=> {
        // native使用线程安全函数实现跨线程调用
        entry.UvWorkTest((param: number) => {
          param += 10;
          logger.info('UvWorkTest js callback value = ', param.toString());
          this.value = param;
          return param;
        }
      )
    }).margin(20)
   ```
**native主线程中实现一个UvWorkTest接口。**    
接口接收到ArkTS传入的JavaScript回调函数后创建子线程，在子线程的执行函数CallbackUvWorkTest中创建工作任务workReq，通过uv_queue_work将工作任务添加到libuv队列中。

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
        // 创建工作数据结构,自定义数据结构添加在data中
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
        // 此打印位于子线程
        OH_LOG_INFO(LOG_APP, "UvWorkTest childThread_1 [%{public}d]", g_cValue);
        // 添加工作任务到libuv的队列中
        uv_queue_work(loop, workReq, WorkCallback, AfterWorkCallback);
    }
    
    // 使用uv_work callback 实现跨线程调用js函数
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
**实现work_cb与after_work_cb。**    
work_cb位于子线程中，执行实际的业务逻辑；after_work_cb位于主线程中，通过napi_call_function调用ArkTS端传入的JavaScript回调函数。

  ```c++
    // src/main/cpp/hello.cpp

    void WorkCallback(uv_work_t *workReq)
    {
        // 另外一个子线程,一些耗时操作可以在此进行. 此处不能调用js函数.
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
        // 主线程执行，可以在此调用js函数
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
        // 保存js回调结果
        napi_get_value_int32(context->env, ret, &g_cValue);
        OH_LOG_INFO(LOG_APP, "UvWorkTest CallBack end [%{public}d]", g_cValue);
    
        napi_close_handle_scope(context->env, scope);
        if (context != nullptr) {
            napi_delete_reference(context->env, context->callbackRef);
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

## 总结
线程安全函数和libuv方案都是在子线程的执行函数运行结束后回到主线程，并将JavaScript回调函数push到主线程的event-loop队列里等待被执行。  
两者的差异在于libuv的子线程属于libuv线程池，而线程安全函数的子线程需要根据业务要求自己创建。另外在libuv中，JavaScript回调函数只能在子线程的主函数执行完毕后被动被执行；而在线程安全函数中，JavaScript回调函数则可以在任意线程中主动调用。  
