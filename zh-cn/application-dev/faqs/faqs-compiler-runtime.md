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

## 使用HSP的多包场景下场景，直接崩溃并产生cppcrash异常日志，错误信息为resolveBufferCallback get buffer failed

**解决方案**

该问题是由于hsp包解析失败导致，常见加载失败原因有安装失败、文件丢失、缺少权限、安全内存校验失败等，开发者可以根据关键日志进行排查。通常情况下，重新安装应用即可恢复。

| **已知关键错误日志** | **修改建议** |
| -------- | -------- |
| realHapPath is empty | 路径查询失败，无法获取用户安装包信息。建议开发者重新安装应用。 |
| transform real path error: ERROR, pathName: PATH | 使用realpath函数解析路径失败，ERROR表示错误信息，PATH表示hsp路径。建议开发者重新安装应用。 |
| CreateFileMapper, mmap failed, errno ERROR. fileName: FILENAME | 使用mmap函数映射安全内存映射失败，ERROR表示错误信息，FILENAME表示文件名。常见原因是系统内存不足、文件未签名。|

```
