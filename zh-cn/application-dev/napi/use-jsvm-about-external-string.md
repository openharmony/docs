# 使用JSVM-API接口提供Latin1/UTF16格式字符串相关开发

## 简介

JSVM-API中新增创建和使用external string的接口。

## 基本概念

在JSVM-API中，在用户提供的Latin1/UTF16格式字符串所在内存上直接创建对应的JS字符串，和正常的JS字符串能够进行同样的操作。

## 接口说明

| 接口                                   | 功能说明                       |
|----------------------------------------|--------------------------------|
| OH_JSVM_CreateExternalStringLatin1     | 使用ISO-8859-1编码的C字符串，创建一个外部的JavaScript字符串。  |
| OH_JSVM_CreateExternalStringUtf16      | 使用UTF16-LE编码的C字符串，创建一个外部的JavaScript字符串。  |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### 使用接口判断是否是Number Object

cpp部分代码

```cpp

static char stringLatin1[] = "hello";
static char16_t stringUTF16[] = "world";

static JSVM_Value testExternalString(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    OH_JSVM_GetVM(env, &vm);

    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);
    JSVM_Value jsStrLatin1 = nullptr;
    bool copied = true;
    char buf[10];
    OH_JSVM_CreateExternalStringLatin1(env, stringLatin1, strlen(stringLatin1), nullptr, nullptr,
                                       &jsStrLatin1, &copied)
    OH_JSVM_GetValueStringUTF8(env, jsStrLatin1, buf, 10, nullptr);
    OH_LOG_INFO(LOG_APP, "created latin1 string is : %{public}s\n", buf);
    // 这里 copied 为 true 表示创建 external string 失败，否则表示创建成功
    OH_LOG_INFO(LOG_APP, "create external string failed : %{public}d\n", copied);
    copied = true;
    JSVM_Value jsStrUTF16 = nullptr;
    OH_JSVM_CreateExternalStringUtf16(env, stringLatin1, std::char_traits<char16_t>::length(stringUTF16),
                                      nullptr, nullptr, &jsStrUTF16, &copied)
    OH_JSVM_GetValueStringUTF8(env, jsStrUTF16, buf, 10, nullptr);
    OH_LOG_INFO(LOG_APP, "created utf16 string is : %{public}s\n", buf);
    // 这里 copied 为 true 表示创建 external string 失败，否则表示创建成功
    OH_LOG_INFO(LOG_APP, "create external string failed : %{public}d\n", copied);
    OH_JSVM_CloseHandleScope(env, handleScope);

    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = testExternalString},
};

static JSVM_CallbackStruct *method = param;

// wrapperObject方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"testExternalString", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试JS
const char *srcCallNative = R"JS(testExternalString();)JS";

```

## 预期输出结果
```
created latin1 string is : hello
create external string failed: 0
created utf16 string is : world
create external string failed: 0
```
