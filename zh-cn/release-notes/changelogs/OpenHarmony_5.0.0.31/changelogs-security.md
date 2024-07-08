
# 安全子系统变更说明
## cl.security.1 匿名内存执行权限管控策略变更说明
**访问级别**

公开接口

**变更原因**

为了维护生态的纯净，防止恶意应用向匿名内存注入指令实现任意代码的执行，以绕过代码签名管控，达到变脸或攻击系统的目的，系统需要限制应用内设置匿名内存为可执行的行为。

**变更影响**

该变更为不兼容变更。

应用在申请内存或修改内存权限时，将匿名内存（MAP_ANONYMOUS）的权限设置为可执行（PROT_EXEC），相应行为会被系统拦截。表象为对应系统调用返回失败结果，具体内容如下：
1. 应用调用mmap申请包含执行权限的匿名内存将返回失败（返回MAP_FAILED）。
2. 应用调用mprotect更新匿名内存为可执行执行权限（返回-1，errno输出为EINVAL）。

**起始API Level**

不涉及API变更

**变更发生版本**

从OpenHarmony 5.0.0.31 开始

**变更的接口/组件**

内核

**适配指导**

应用开发者需要适配内存的权限设置。

变更后使用mmap申请匿名内存或调用mprotect修改匿名内存权限时，添加PROT_EXEC权限将被禁止，
具体样例如下：

```
// 被管控样例1：申请匿名内存时设置内存权限为可执行
mmap(NULL, len, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS, -1, 0);

// 被管控样例2：申请匿名内存后，再设置内存的权限为可执行
addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0);
...
mprotect(addr, leng, PROT_READ | PROT_EXEC);
```
