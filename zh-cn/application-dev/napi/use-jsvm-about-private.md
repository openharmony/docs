# 使用JSVM-API接口进行private相关开发

## 简介

JSVM-API中提供操作private属性能力的接口。

## 基本概念

在JSVM-API中，提供用户创建private key的能力，并且能够在object上使用这个key创建、删除对应的属性，同时持久化保存private key symbol。

## 接口说明

| 接口                                    | 功能说明                       |
|----------------------------------------|--------------------------------|
| OH_JSVM_CreateDataReference            | 在JSVM中创建一个带有指定引用计数的数据引用 |
| OH_JSVM_GetReferenceData               | 检查指定的引用是否有效,返回该引用关联的JavaScript数据,无效result设置为NULL|
| OH_JSVM_CreatePrivate                  | 创建一个js private key对象。   |
| OH_JSVM_SetPrivate                     | 为传入的object设置一个private属性。   |
| OH_JSVM_GetPrivate                     | 为传入的object获取private key对应的private属性。   |
| OH_JSVM_DeletePrivate                  | 为传入的object删除private key对应的private属性。   |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### 使用接口创建 private key 并添加对应 private property，随后删除

cpp部分代码

```cpp
static JSVM_Value privateTest(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_VM vm;
    JSVM_HandleScope outerScope;
    OH_JSVM_GetVM(env, &vm);
    OH_JSVM_OpenHandleScope(env, &outerScope);

    JSVM_HandleScope handleScope;
    JSVM_Data privateKey;
    JSVM_Value object;
    JSVM_Value property;
    JSVM_Ref privateRef;
    {
        OH_JSVM_OpenHandleScope(env, &handleScope);
        OH_JSVM_CreateObject(env, &object);
        OH_JSVM_CreatePrivate(env, nullptr, &privateKey);
        OH_JSVM_CreateInt32(env, 1, &property);
        OH_JSVM_SetPrivate(env, object, privateKey, property);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        int propertyValue = 0;
        OH_JSVM_GetValueInt32(env, property, &propertyValue);
        OH_LOG_INFO(LOG_APP, "private property set: %{public}d\n", propertyValue);
        OH_JSVM_DeletePrivate(env, object, privateKey);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        bool isUndefined = false;
        OH_JSVM_IsUndefined(env, property, &isUndefined);
        OH_LOG_INFO(LOG_APP, "private property deleted is undefined: %{public}d\n", isUndefined);
        OH_JSVM_CreateDataReference(env, privateKey, 1, &privateRef);
        OH_JSVM_CloseHandleScope(env, handleScope);
    }
    {
        OH_JSVM_OpenHandleScope(env, &handleScope);
        OH_JSVM_GetReferenceData(env, privateRef, &privateKey);
        OH_JSVM_CreateObject(env, &object);
        OH_JSVM_CreateInt32(env, 2, &property);
        OH_JSVM_SetPrivate(env, object, privateKey, property);
        OH_JSVM_GetPrivate(env, object, privateKey, &property);
        int propertyValue = 0;
        OH_JSVM_GetValueInt32(env, property, &propertyValue);
        OH_LOG_INFO(LOG_APP, "second private property set: %{public}d\n", propertyValue);
        OH_JSVM_CloseHandleScope(env, handleScope);
    }

    OH_JSVM_CloseHandleScope(env, outerScope);
    return nullptr;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = privateTest},
};

static JSVM_CallbackStruct *method = param;

// wrapperObject方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"privateTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试JS
const char *srcCallNative = R"JS(privateTest();)JS";
```

## 预期输出结果
```
private property set: 1
private property deleted is undefined: 1
second private property set: 2
```
