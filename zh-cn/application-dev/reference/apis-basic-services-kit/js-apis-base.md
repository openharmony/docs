# @ohos.base (公共回调信息)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Base-->
<!--Owner: @majiajun518-->
<!--Designer: @majiajun518-->
<!--Tester: @jiyong_sd-->
<!--Adviser: @fang-jinxu-->

本模块定义了OpenHarmony ArkTS接口的公共回调类型，包括接口调用时出现的公共回调和公共错误信息。这些回调类型为开发者提供了统一的异步处理机制，适用于需要处理异步操作结果、错误信息回传等场景，可以帮助开发者简化异步编程模型，提高代码的可读性和可维护性。

> **说明：**
>
> - 本模块首批接口从API version 6 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 从API version 12开始，本模块接口支持在ArkTS卡片中使用。

## 导入模块

ArkTS示例： 
```typescript
import { AsyncCallback, BusinessError, Callback, ErrorCallback } from '@kit.BasicServicesKit';
```
JS示例：

```typescript
import base from '@ohos.base';
```

## Callback

Callback\<T> {

(data: T): void;

}

通用回调函数，用于在异步操作成功完成时回传处理结果。类型由开发者自定义。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明                       |
| ---- | ---- | ---- | -------------------------- |
| data | T    | 是   | 接口调用时的公共回调信息。类型由开发者自定义，回调将返回对应类型的数据。 |

## ErrorCallback

ErrorCallback\<T extends Error = BusinessError> {

(err: T): void;

}

通用回调函数，携带错误参数，用于在异步操作失败时回传错误信息。具体错误码值由各接口定义，请参考对应接口的错误码说明。

回调返回的信息为[BusinessError](#businesserror)类型的错误参数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Base

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ---- | ---- | ---- | ---------------------------- |
| err  | T    | 是   | 接口调用失败的公共错误信息，类型默认为BusinessError，包含错误码（code）和可选附加数据（data）。 |

## AsyncCallback

AsyncCallback\<T, E = void> {

(err: BusinessError\<E>, data: T): void;

}

通用回调函数，携带错误参数和异步返回值，用于在异步操作完成时同时回传错误信息或成功数据。

错误参数为[BusinessError](#businesserror)类型。

异步返回值的类型由开发者自定义，回调将返回对应类型的信息。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Base

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                         |
| ---- | ------------------------------------------------------------ | ---- | ---------------------------- |
| err  | [BusinessError](#businesserror) | 是   | 接口调用失败的公共错误信息。接口调用成功时，此参数返回null |
| data | T                   | 是   | 接口调用成功时的异步返回数据，类型由开发者自定义。接口调用失败时，此参数不可用。   |

## BusinessError

BusinessError\<T = void> extends Error { code: number; data?: T; }

错误参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Base

| 名称 | 类型   | 只读 | 可选 | 说明                                                       |
| ---- | ------ | ---- | ---- | ---------------------------------------------------------- |
| code | number | 否 | 否   | 接口调用失败返回的错误码信息。                             |
| data | T      | 否 | 是   | 接口调用失败时返回的附加错误信息。如果不填，则错误对象不包含附加数据。<br>**起始版本：** 9 |