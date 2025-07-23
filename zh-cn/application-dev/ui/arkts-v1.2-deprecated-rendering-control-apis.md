# 渲染控制

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## onDataAdded

ArkTS1.1接口声明：[onDataAdded(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondataaddeddeprecated)

替代的ArkTS1.2接口声明：[onDataAdd(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondataadd8)

适配方法如下：

ArkTS1.1

```ts
onDataAdded(0)
```

ArkTS1.2

```ts
onDataAdd(0)
```

## onDataMoved

ArkTS1.1接口声明：[onDataMoved(from: number, to: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatamoveddeprecated)

替代的ArkTS1.2接口声明：[onDataMove(from: number, to: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatamove8)

适配方法如下：

ArkTS1.1

```ts
onDataMoved(0, 1)
```

ArkTS1.2

```ts
onDataMove(0, 1)
```

## onDataDeleted

ArkTS1.1接口声明：[onDataDeleted(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatadeleteddeprecated)

替代的ArkTS1.2接口声明：[onDataDelete(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatadelete8)

适配方法如下：

ArkTS1.1

```ts
onDataDeleted(0)
```

ArkTS1.2

```ts
onDataDelete(0)
```

## onDataChanged

ArkTS1.1接口声明：[onDataChanged(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatachangeddeprecated)

替代的ArkTS1.2接口声明：[onDataChange(index: number): void](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md#ondatachange8)

适配方法如下：

ArkTS1.1

```ts
onDataChanged(0)
```

ArkTS1.2

```ts
onDataChange(0)
```