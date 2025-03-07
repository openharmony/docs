# 方舟编译运行时子系统变更说明

## cl.arkcompiler.1 iconv，iconv_open 接口变更

**访问级别**

公开接口

**变更原因**

iconv新增//IGNORE 和 //TRANSLIT 功能，补充支持正常编码转 gb18030、gbk、gb2312、big5的编码能力。

例如：
    iconv_t cd = iconv_open("UTF-8//IGNORE", "gbk//TRANSLIT");

**变更影响**

此变更涉及应用适配。

变更前：iconv_open(const char *__tocode, const char *__fromcode) 接口入参不支持拓展//IGNORE 和 //TRANSLIT，入参 tocode 不支持gb18030、gbk、gb2312、big5，使用这类入参结果会返回-1。

变更后：

    1、iconv_open(const char *__tocode, const char *__fromcode) 接口入参支持拓展//IGNORE 和 //TRANSLIT，仅入参 tocode 拓展支持gb18030、gbk、gb2312、big5这几种新的编码格式，使用这类入参结果会正常返回结构体指针。

    2、由于切换成icu的实现方式，异常判断逻辑也存在变更，iconv接口现在存在不会对入参进行校验的情况，只会在转换过程中遇到非法字符才会根据//IGNORE 和 //TRANSLIT 的开启状态返回相应的结果。
    
    3、iconv_open 函数返回的结构体指针所指向的内部结构体，其结构发生了变更，结构体的大小也随之增大。

**变更发生版本**

从OpenHarmony SDK 5.1.0.49开始。

**变更的接口/组件**

iconv ,iconv_open 接口。

**适配指导**

```
