# NetManager Subsystem Changelog

## cl.netmanager.1 Renaming of OHOS_NetConn_RegisterDnsResolver with the Deprecated Tag Added

**Access Level**

Public API

**Reason for Change**

Only the API name is changed.

**Change Impact**

This change is a non-compatible change.

Before change: The API name is in the OHOS format.

After change: The API name is in the OH format. A deprecated tag is added to the original API, and the function remains unchanged. You are advised to use **OH_NetConn_RegisterDnsResolver** instead.

Incompatible scenarios:
Only the deprecated tag is added. The API functions will remain available in three versions.

**Start API Level**

API 11

**Change Since**

OpenHarmony SDK 5.0.0.43

**Key API/Component Changes**

OH_NetConn_RegisterDnsResolver;

**Adaptation Guide**

```ts
int main() {
    OH_NetConn_CustomDnsResolver resolver;
    // Register a custom DNS resolver.
    int result = OH_NetConn_RegisterDnsResolver(resolver);
    if (result == 0) {
        printf("Custom DNS resolver registered successfully\n");
    } else {
        printf("Failed to register custom DNS resolver, error code: %d\n", result);
    }

    return0;
}
```

## cl.netmanager.2 Renaming of OHOS_NetConn_UnregisterDnsResolver with the Deprecated Tag Added

**Access Level**

Public API

**Reason for Change**

Only the API name is changed.

**Change Impact**

This change is a non-compatible change.

Before change: The API name is in the OHOS format.

After change: The API name is in the OH format. A deprecated tag is added to the original API, and the function remains unchanged. You are advised to use **OH_NetConn_UnregisterDnsResolver** instead.

Incompatible scenarios:
Only the deprecated tag is added. The API functions will remain available in three versions.

**Start API Level**

API 11

**Change Since**

OpenHarmony SDK 5.0.0.43

**Key API/Component Changes**

OH_NetConn_UnregisterDnsResolver;

**Adaptation Guide**

```ts
int main() {
    OH_NetConn_CustomDnsResolver resolver;
    // Register a custom DNS resolver.
    int result = OH_NetConn_RegisterDnsResolver(resolver);
    if (result == 0) {
        printf("Custom DNS resolver registered successfully\n");
    } else {
        printf("Failed to register custom DNS resolver, error code: %d\n", result);
    }

    // Use the custom DNS resolver to resolve domain names.
    // ......

    // Unregister the custom DNS resolver.
    result = OH_NetConn_RegisterDnsResolver();
    if (result == 0) {
        printf("Custom DNS resolver unregistered successfully\n");
    } else {
        printf("Failed to unregister custom DNS resolver, error code: %d\n", result);
    }

    return0;
}
```
