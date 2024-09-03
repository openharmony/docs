# NetManager系统Changelog

## cl.netmanager.1 OHOS_NetConn_RegisterDnsResolver注册自定义DNS解析接口添加废弃标签并改名

**访问级别**

公开接口

**变更原因**

接口命名变动，原有功能保留不变

**变更影响**

该变更为不兼容变更。

变更前：接口命名是OHOS格式

变更后：接口命名变更为OH，原接口添加废弃标签，功能保留，推荐使用OH_NetConn_RegisterDnsResolver

不兼容场景：
仅添加了废弃标签，原接口功能会保留3个版本

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始

**变更的接口/组件**

1、 OH_NetConn_RegisterDnsResolver；

**适配指导**

```ts
int main() {
    OH_NetConn_CustomDnsResolver resolver;
    // 注册自定义DNS解析器
    int result = OH_NetConn_RegisterDnsResolver(resolver);
    if (result == 0) {
        printf("Custom DNS resolver registered successfully\n");
    } else {
        printf("Failed to register custom DNS resolver, error code: %d\n", result);
    }

    return0;
}
```

## cl.netmanager.2 OHOS_NetConn_UnregisterDnsResolver取消注册自定义DNS解析接口添加废弃标签并改名

**访问级别**

公开接口

**变更原因**

接口命名变动，原有功能保留不变

**变更影响**

该变更为不兼容变更。

变更前：接口命名是OHOS格式

变更后：接口命名变更为OH，原接口添加废弃标签，功能保留，推荐使用OH_NetConn_UnregisterDnsResolver

不兼容场景：
仅添加了废弃标签，原接口功能会保留3个版本

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始

**变更的接口/组件**

1、 OH_NetConn_UnregisterDnsResolver；

**适配指导**

```ts
int main() {
    OH_NetConn_CustomDnsResolver resolver;
    // 注册自定义DNS解析器
    int result = OH_NetConn_RegisterDnsResolver(resolver);
    if (result == 0) {
        printf("Custom DNS resolver registered successfully\n");
    } else {
        printf("Failed to register custom DNS resolver, error code: %d\n", result);
    }

    // 现在可以使用自定义的DNS解析器来解析域名
    // ......

    // 取消注册自定义DNS解析器
    result = OH_NetConn_RegisterDnsResolver();
    if (result == 0) {
        printf("Custom DNS resolver unregistered successfully\n");
    } else {
        printf("Failed to unregister custom DNS resolver, error code: %d\n", result);
    }

    return0;
}
```