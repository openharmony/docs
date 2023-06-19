# 通过静默数据访问实现数据共享


## 场景介绍

典型跨应用访问数据的用户场景下，应用会存在多次被拉起的情况。

为了降低应用拉起次数，提高访问速度，OpenHarmony提供了一种不拉起数据提供方直接访问数据库的方式，即静默数据访问。

静默数据仅支持数据库的基本访问，如果有业务处理，建议将业务处理放到数据访问方。

如果业务过于复杂，无法放到数据访问方，建议通过DataShareExtensionAbility拉起数据提供方实现功能。


## 运作机制

**图1** 静默数据访问视图

![silent_dataShare](figures/silent_dataShare.jpg)

- 和跨应用数据共享方式不同的是，静默数据访问借助数据管理服务通过目录映射方式直接读取数据提供方的配置，按规则进行预处理后，并访问数据库。

- 数据访问方如果使用静默数据访问方式，URI需严格按照如下格式：
  datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}?Proxy=true

  Proxy=true表示通过静默方式访问数据不拉起数据提供方，如果没有此项则会拉起数据提供方。

  数据管理服务会读取对应bundleName作为数据提供方应用，读取配置，进行权限校验并访问对应数据。


## 约束与限制

- 目前仅关系型数据库支持静默数据访问方式。

- 整个系统最多同时并发16路查询，有多出来的查询请求需要排队处理。

- 不支持代理创建数据库，如果需要创建数据库，需要拉起数据提供方。


## 实现说明

URI需严格按照如下格式：

datashare:///{bundleName}/{moduleName}/{storeName}/{tableName}?Proxy=true

其他开发步骤与实现，具体可参照[通过DataShareExtensionAbility实现数据共享](share-data-by-datashareextensionability.md)。
