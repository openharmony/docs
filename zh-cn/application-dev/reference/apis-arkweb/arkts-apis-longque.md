# Class (Longque)

Longque JS API 是龙雀 JS 引擎为开发者提供的 JS 接口。

> **说明：**
>
> - 本模块接口从API version 20开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 接口的版本可通过 `__Longque__.version` 获得，开发者可使用该版本进行特性判断。
>

## createDelegate

```
export function createDelegate(
  underlyingObject: object,
  initObject?: object,
  propertyFilterFlags?: PropertyFilterFlags): object;
```

创建委托对象。


**参数：**

| 参数名    | 类型   | 必填   | 说明        |
| ------ | ------ | ---- | ----------- |
| underlyingObject | object | 是    | 表示被委托的底层对象。 |
| initObject | object | 否    | 表示初始委托对象。 |
| propertyFilterFlags | PropertyFilterFlags | 否    | 表示属性过滤器。 |