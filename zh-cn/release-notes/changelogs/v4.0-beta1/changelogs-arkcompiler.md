# 语言编译运行时子系统ChangeLog
## cl.arkcompiler.1 LLVM新增告警及已有告警增强

**变更影响**

OpenHarmony NDK默认不开启-Werror选项，对于已经开启-Werror选项的开发者，建议基于告警检查提示修改错误业务代码或屏蔽

 **关键的编译检查规则变更**

| 新增检查选项 | 作用 | 修改建议 |
| --- | --- | --- |
| Wunused-but-set-variable | 当代码中有未使用的变量时（包含++操作符）提出告警 | 定义变量时添加"maybe_unused"属性或者使用宏区分 |
| Wdeprecated-non-prototype | 当代码中存在没有原型的函数时提出告警 | 添加函数原型并明确参数 |
| Wunqualified-std-cast-call | 当代码中错误使用std::move等时提出告警 | 明确移动语义的使用场景并检查代码 |
| Wdeprecated-builtins | 当代码中使用了废弃的内置函数时提出告警 | 替换使用新版函数 |
| Warray-parameter | 当函数参数中包含数组并且重复定义了不一致的形式时提出告警 | 确认函数参数的一致性 |
| Wbitwise-instead-of-logical | 当在布尔运算中使用按位或时提出告警 | 更新代码在布尔运算中使用逻辑或 |
| Wint-conversion | 当代码中出现int变量转换为指针时提出告警 | 更新代码替换使用新的实现方式 |
| Wdeprecated-declarations | 当代码中使用了废弃的定义（包含函数和变量等）时提出告警 | 更新代码替换使用新的实现方式 |
| Wnull-pointer-subtraction | 当代码中出现空指针减法时提出告警 | 更新代码避免空指针参与减法运算 |
| Wunused-but-set-parameter | 当函数中出现未使用的参数时提出告警 | 更新代码去掉未使用的参数 |
| Warray-bounds | 当代码中出现对数组的越界访问时提出告警 | 检查代码并修改越界访问 |
| Wdeprecated-pragma | 当代码中使用了废弃的宏时提出告警 | 更新代码避免使用废弃的宏 |
| Wreserved-identifier | 当代码中使用了"__"开头的变量时提出告警 | 检查代码避免"__"开头的变量被外部使用 |

 **适配指导**

1. 对于用户代码中存在的LLVM-12未检测出来的问题，需要用户检查并更新代码。
2. LLVM更新废弃了一些旧的实现，需要用户代码适配并更新代码。
3. 开发者评估暂时规避的告警，可采用-Wno-xxx选项规避该error。

问题代码实例

```
void Heap::Resume(TriggerGCType gcType)
{
    if (mode_ != HeapMode::SPAWN &&
        activeSemiSpace_->AdjustCapacity(inactiveSemiSpace_->GetAllocatedSizeSinceGC())) {
        // if activeSpace capacity changes， oldSpace maximumCapacity should change, too.
        size_t multiple = 2;
        // oldSpaceMaxLimit被赋值了但未被使用
        size_t oldSpaceMaxLimit = 0;
        if (activeSemiSpace_->GetInitialCapacity() >= inactiveSemiSpace_->GetInitialCapacity()) {
            size_t delta = activeSemiSpace_->GetInitialCapacity() - inactiveSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() - delta * multiple;
        } else {
            size_t delta = inactiveSemiSpace_->GetInitialCapacity() - activeSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() + delta * multiple;
        }
        inactiveSemiSpace_->SetInitialCapacity(activeSemiSpace_->GetInitialCapacity());
    }
    // irrelated code ...
}
```

oldSpaceMaxLimit变量并未使用，编译器提出告警

```
../../arkcompiler/ets_runtime/ecmascript/mem/heap.cpp:247:16: error: variable 'oldSpaceMaxLimit' set but not used [-Werror,-Wunused-but-set-variable]
        size_t oldSpaceMaxLimit = 0;
```

添加属性后解决

```
void Heap::Resume(TriggerGCType gcType)
{
    if (mode_ != HeapMode::SPAWN &&
        activeSemiSpace_->AdjustCapacity(inactiveSemiSpace_->GetAllocatedSizeSinceGC())) {
        // if activeSpace capacity changes， oldSpace maximumCapacity should change, too.
        size_t multiple = 2;
        // 添加maybe_unused属性，声明不一定使用变量oldSpaceMaxLimit
        [[maybe_unused]] size_t oldSpaceMaxLimit = 0;
        if (activeSemiSpace_->GetInitialCapacity() >= inactiveSemiSpace_->GetInitialCapacity()) {
            size_t delta = activeSemiSpace_->GetInitialCapacity() - inactiveSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() - delta * multiple;
        } else {
            size_t delta = inactiveSemiSpace_->GetInitialCapacity() - activeSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() + delta * multiple;
        }
        inactiveSemiSpace_->SetInitialCapacity(activeSemiSpace_->GetInitialCapacity());
    }
    // irrelated code ...
}
```

## cl.arkcompiler.2 LLVM解析格式差异

 **变更影响**

对于业务依赖version-script或-gcc-toolchain选项的开发者，在沿用LLVM12配置文件或选项时，可能会解析失败

 **关键的编译规则变更**

1. 新版本中修改了符号的表示，现在连续的">"会被编译器表示为">>"，这个在旧版本中会被表示为"> >"，错误使用将导致符号不被解析匹配
2. 废弃-xx选项，如-gcc-toolchain选项，改用--gcc-toolchain选项（该选项在clang3.4以后的版本已表示会弃用，LLVM15上正式废弃）

 **适配指导**

version-script使用方法可以参考

适配实例

对于代码中出现连续两个“>”（忽略中间空格数量），在version-script中（由于 mangling差异）会被分别解析为如下"> >"与">>"两种情况，在15中我们需要使用">>"

原始配置文件

```
{
  global:
  extern "C++" {
    "google::protobuf::TextFormat::ParseFromString(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, google::protobuf::Message*)";
    // LLVM12 "> >"可以被解析，但">>"不行
    "google::protobuf::TextFormat::PrintToString(google::protobuf::Message const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*)";
  };
  local:
    *;
}
```

修改后的配置文件

```
{
  global:
  extern "C++" {
    "google::protobuf::TextFormat::ParseFromString(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, google::protobuf::Message*)";
    // LLVM15 只会解析">>"
    "google::protobuf::TextFormat::PrintToString(google::protobuf::Message const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>*)";
  };
  local:
    *;
}
```

## cl.arkcompiler.3 LLVM emu-tls变更

 **变更影响**

对于LLVM12/LLVM15工具链混用的开发者（禁止行为），会产生libc++.so emu-tls符号无法找到的问题

 **关键的库依赖变更**

LLVM15中将emu-tls符号从目标二进制抽取到了libc++.so中，即__emutls_get_address的属性从内部符号变为外部可见的符号（libc++.so中会包含该符号），可能会导致编译出来的动态库依赖libc++.so。

 **适配指导**

该符号同时也在libclang_rt.builtin.a中，如果不希望依赖libc++.so可以静态链接libclang_rt.builtin.a库。

## cl.arkcompiler.4 LLVM官方release note

 **变更影响**

新增特性及内部接口变更（如LLVM内部的IR，编译器前端修改），详见官方变更文档

 **关键变更文档**

https://releases.llvm.org/13.0.0/docs/ReleaseNotes.html
https://releases.llvm.org/14.0.0/docs/ReleaseNotes.html
https://releases.llvm.org/15.0.0/docs/ReleaseNotes.html

 **适配指导**

详细修改信息以及适配指导见官方文档