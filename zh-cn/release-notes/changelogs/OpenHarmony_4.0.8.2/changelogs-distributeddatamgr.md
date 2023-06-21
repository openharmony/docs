
# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 js-apis-application-dataShareExtensionAbility API version 9开始支持的context属性删除，新增API version 10的context属性取消可选标识符。

**变更影响**

基于此前版本开发的应用，使用context需切换SDK至API version 10。

**关键接口/组件变更**

删除的API version 9的接口原型：

 ```ts
    /**
     * Indicates datashare extension ability context.
     *
     * @type ?{ ExtensionContext }
     * @syscap SystemCapability.DistributedDataManager.DataShare.Provider
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    context?: ExtensionContext;
 ```
新增的API version 10的接口原型：

 ```ts
    /**
     * Indicates datashare extension ability context.
     *
     * @type { ExtensionContext }
     * @syscap SystemCapability.DistributedDataManager.DataShare.Provider
     * @systemapi
     * @StageModelOnly
     * @since 10
     */
    context: ExtensionContext;
 ```