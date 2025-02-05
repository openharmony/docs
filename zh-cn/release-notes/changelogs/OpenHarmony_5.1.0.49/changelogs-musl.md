# 方舟编译运行时子系统变更说明

## cl.arkcompiler.1 iconv，iconv_open 接口变更

**访问级别**

公开接口

**变更原因**

iconv新增//IGNORE 和 //TRANSLIT 功能，补充支持正常编码转 gb18030,gbk,gb2312,big5编码能力

**变更影响**

此变更涉及应用适配。

变更前：iconv_open 接口入参不支持//IGNORE 和 //TRANSLIT,和入参 tocode 不支持gb18030,gbk,gb2312,big5，使用这类入参结果会返回-1。

变更后：

    1、iconv_open 接口入参支持//IGNORE 和 //TRANSLIT,和入参 tocode 支持gb18030,gbk,gb2312,big5，使用这类入参结果会正常返回结构体指针。

    2、由于切换成icu的实现方式，异常判断逻辑也存在变更，iconv接口存在现在不会对入参进行校验，只会在转换过程中遇到非法字符才会根据//IGNORE 和 //TRANSLIT 的开启状态返回相应的结果。
    
    3、iconv_open返回值结构体指针，内部使用的结构体结构改变，大小变大。

**变更发生版本**

从OpenHarmony SDK 5.1.0.49开始。

**变更的接口/组件**

iconv ,iconv_open 接口。

**适配指导**

```
