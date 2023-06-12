# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 ValuesBucket由系统接口变更为公共接口

**变更影响**

基于此前版本开发的应用，仅支持系统应用使用ValuesBucket。现接口类型中的系统接口标识取消，支持第三方开发者使用。

**关键接口/组件变更**

修改前的接口原型：

 ```ts
    /**
     * Indicates possible value types
     *
     * @syscap SystemCapability.DistributedDataManager.DataShare.Core
     * @systemapi
     * @StageModelOnly
     * @since 9
     */
    export type ValueType = number | string | boolean;
 ```
修改后的接口原型：

 ```ts
    /**
     * Indicates possible value types
     *
     * @syscap SystemCapability.DistributedDataManager.DataShare.Core
     * @StageModelOnly
     * @since 10
     */
    export type ValueType = number | string | boolean;
}
 ```
## cl.distributeddatamgr.2 dataSharePredicates部分谓词由系统接口变更为公共接口

**变更影响**

基于此前版本开发的应用，仅支持系统应用使用dataSharePredicates。现命名空间dataSharePredicates、类dataSharePredicates及类内部分谓词接口类型中的系统接口标识取消，支持第三方开发者使用。

**关键接口/组件变更**

部分谓词接口的系统接口说明取消，涉及的接口有：

- equalTo(field: string, value: ValueType): DataSharePredicates

- and(): DataSharePredicates

- orderByAsc(field: string): DataSharePredicates

- orderByDesc(field: string): DataSharePredicates

- limit(total: number, offset: number): DataSharePredicates

- in(field: string, value: Array<ValueType>): DataSharePredicates