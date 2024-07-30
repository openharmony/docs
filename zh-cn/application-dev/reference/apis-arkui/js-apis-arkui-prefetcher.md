# Prefetcher
配合LazyForEach，为List、Grid、Waterfall和Swiper等容器组件滑动浏览时提供内容预加载能力，提升用户浏览体验。

>  **说明：**
>  本模块首批接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## IPrefetcher
实现此接口以提供预取能力。

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setDataSource
setDataSource(dataSource: IDataSourcePrefetching): void;

设置支持预取的DataSource以绑定到Prefetcher

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| dataSource  | IDataSourcePrefetching | 是   | 支持预取能力的数据源 |

### visibleAreaChanged
visibleAreaChanged(minVisible: number, maxVisible: number): void

当可见区域边界发生改变时调用此方法。支持与List、`Grid`、`Waterfall`和`Swiper`组件配合使用

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| minVisible  | number | 是   | 列表可见区域的上界 |
| maxVisible  | number | 是   | 列表可见区域的下界 |

## BasicPrefetcher
BasicPrefetcher是IPrefetcher的基础实现。它提供了一种智能数据预取算法，以根据屏幕上可见区域的实时变化和预取持续时间的变化来决定应预取哪些数据项。它还可以根据用户的滚动操作来确定哪些预取请求应该被取消。

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor
constructor(dataSource?: IDataSourcePrefetching)

传入支持预取的DataSource以绑定到Prefetcher

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| dataSource  | IDataSourcePrefetching | 否  | 支持预取能力的数据源 |

### setDataSource
setDataSource(dataSource: IDataSourcePrefetching): void;

设置支持预取的DataSource以绑定到Prefetcher

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| dataSource  | IDataSourcePrefetching | 是   | 支持预取能力的数据源 |

### visibleAreaChanged
visibleAreaChanged(minVisible: number, maxVisible: number): void

当可见区域边界发生改变时调用此方法。支持与List、`Grid`、`Waterfall`和`Swiper`组件配合使用

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| minVisible  | number | 是   | 列表可见区域的上界 |
| maxVisible  | number | 是   | 列表可见区域的下界 |

## IDataSourcePrefetching

实现该接口，提供具备预取能力的DataSource

**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### prefetch
**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 预取数据项索引值 |

### cancel
**元服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数说明：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 取消预取数据项索引值  |
