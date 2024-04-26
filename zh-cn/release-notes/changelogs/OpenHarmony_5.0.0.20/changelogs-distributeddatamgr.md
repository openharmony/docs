# 分布式数据管理子系统ChangeLog

OpenHarmony 5.0.0.20 版本相较于OpenHarmony 之前的版本，分布式数据管理子系统的API变更如下。

## cl.distributeddatamgr.1 DataShareHelper下的部分接口新增15700013错误码。

新增close接口后，可以主动关闭DataShareHelper实例，关闭后再调用insert、update、on等其他接口抛出该错误码，详情见docs仓的[接口文档](../../../application-dev/reference/apis-arkdata/js-apis-data-dataShare-sys.md)。

**访问级别**

系统接口

**变更原因** 

新增close接口，该接口可以主动关闭DataShareHelper实例。

**变更影响**

变更前：业务不会主动关闭DataShareHelper实例。

变更后：业务主动关闭DataShareHelper实例后，再次使用需要重新createDataShareHelper。

**起始API Level** 

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.20开始。