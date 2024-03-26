# 语言编译运行时常见问题


## 从rawfile中获取json格式的字符串后，转换成对应的object对象后，再去调用实例方法时直接崩溃(API 9)

**问题现象**

直接报错：jscrash happened in xxxxxxxxx，crash日志中错误信息：Error message: Unexpected Object in JSON

**解决措施**

通过json解析字符串得到的对象的原型是object，其原型链中不存在自有的实例方法，故无法调用。

如需调用该方法，则有以下两种方式：

1. 在解析后的对象上添加对应的原型。

2. 将该实例方法改为静态方法，通过类名去调用。

## napi_call_function出现pending exception时导致下一次使用NAPI方法出错(API 10)

**问题场景**

场景：napi_call_function调用ArkTs函数异常时，系统行为是pending exception而不是Crash。  
后果：导致pending时，如果开发者未作安全校验，则会在下一次使用napi方法时出错，且出错行为无法预期，这种情况下应该如何处理？

**解决方案**

考虑ArkTS侧调用一个native方法，在native方法中使用了napi_call_function，如果产生异常系统就jscrash，那么开发者在ArkTS侧try..catch就会失效。  
调用napi_call_function，如果有异常就需要及时返回。

## 除了napi_call_function会有pending exception，是否还有其他异常场景？(API 10)

**解决方案**

调用NAPI接口理论上都有可能产生异常；所以在业务的关键流程需要对接口调用的返结果进行判断，查看否有异常产生。比如：
```cpp
napi_status status = napi_create_object(env, &object);
if (status != napi_ok) {
  napi_throw_error(env, ...);
  return;
}
```
