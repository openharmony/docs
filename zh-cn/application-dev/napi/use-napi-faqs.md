# OpenHarmony Node-API常见问题


## ArkTS/JS侧import xxx from libxxx.so后，使用xxx报错显示undefined/not callable

1. 排查.cpp文件在注册模块时的模块名称与so的名称匹配一致。
   如模块名为entry，则so的名字为libentry.so，napi_module中nm_modname字段应为entry，大小写与模块名保持一致。

2. 排查so是否加载成功。
   应用启动时过滤模块加载相关日志，重点搜索"dlopen"关键字，确认是否有相关报错信息；常见加载失败原因有权限不足、依赖so加载失败以及加载路径错误等。

3. 排查依赖的so是否加载成功。
   确定所依赖的其它so是否打包到应用中以及是否有权限打开。

4. 排查模块导入方式与so路径是否对应。
   若JS侧导入模块的形式为： import xxx from '\@ohos.yyy.zzz'，则该so将在/system/lib/module/yyy中找libzzz.z.so或libzzz_napi.z.so，若so不存在或名称无法对应，则报错日志中会出现dlopen相关日志。

   注意，32位系统路径为/system/lib，64位系统路径为/system/lib64。


## 接口执行结果非预期，日志显示occur exception need return

部分Node-API接口在调用结束前会进行检查，检查虚拟机中是否存在JS异常。如果存在异常，则会打印出occur exception need return日志，并打印出检查点所在的行号，以及对应的Node-API接口名称。

解决此类问题有以下两种思路：

- 若该异常开发者不关心，可以选择直接清除。
  可直接使用napi接口napi_get_and_clear_last_exception，清理异常。调用时机：在打印occur exception need return日志的接口之前调用。

- 将该异常继续向上抛到ArkTS层，在ArkTS层进行捕获。
  发生异常时，可以选择走异常分支， 确保不再走多余的Native逻辑 ，直接返回到ArkTS层。


## napi_value和napi_ref的生命周期有何区别

- native_value由HandleScope管理，一般开发者不需要自己加HandleScope（uv_queue_work的complete callback除外）。

- napi_ref由开发者自己管理，需要手动delete。


## Node-API接口返回值不是napi_ok时，如何排查定位

Node-API接口正常执行后，会返回一个napi_ok的状态枚举值，若napi接口返回值不为napi_ok，可从以下几个方面进行排查。

- Node-API接口执行前一般会进行入参校验，首先进行的是判空校验。在代码中体现为：
  ```
  CHECK_ENV： env判空校验
  CHECK_ARG：其它入参判空校验
  ```

- 某些Node-API接口还有入参类型校验。比如napi_get_value_double接口是获取JS number对应的C double值，首先就要保证的是：JS value类型为number，因此可以看到相关校验。
  ```
  RETURN_STATUS_IF_FALSE(env, nativeValue->TypeOf() == NATIVE_NUMBER, napi_number_expected);
  ```

- 还有一些接口会对其执行结果进行校验。比如napi_call_function这个接口，其功能是执行一个JS function，当JS function中出现异常时，Node-API将会返回napi_pending_exception的状态值。
  ```
  auto resultValue = engine->CallFunction(nativeRecv, nativeFunc, nativeArgv, argc); 
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- 还有一些状态值需要根据相应Node-API接口具体分析：确认具体的状态值，分析这个状态值在什么情况下会返回，再排查具体出错原因。
