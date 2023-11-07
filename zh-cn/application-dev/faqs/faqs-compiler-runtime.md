# 语言编译运行时常见问题


## 从rawfile中获取json格式的字符串后，转换成对应的object对象后，再去调用实例方法时直接崩溃(API 9)

**问题现象**

直接报错：jscrash happened in xxxxxxxxx，crash日志中错误信息：Error message: Unexpected Object in JSON

**解决措施**

通过json解析字符串得到的对象的原型是object，其原型链中不存在自有的实例方法，故无法调用。

如需调用该方法，则有以下两种方式：

1. 在解析后的对象上添加对应的原型。

2. 将该实例方法改为静态方法，通过类名去调用。
