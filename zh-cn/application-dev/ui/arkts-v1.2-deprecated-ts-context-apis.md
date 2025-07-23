# 页面上下文

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## getContext

ArkTS1.1接口声明：[getContext(component?: Object):Context](../reference/apis-arkui/js-apis-getContext.md#getContext)

替代的ArkTS1.2接口声明：[getHostContext(): Context | undefined](../reference/apis-arkui/js-apis-arkui-UIContext.md#getHostContext12)

适配方法如下：

ArkTS1.1

```
getContext();
```

ArkTS1.2

```
UIContext.getFocusedUIContext().getHostContext();
```
