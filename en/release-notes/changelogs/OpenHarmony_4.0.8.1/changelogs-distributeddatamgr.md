# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 Changed ValuesBucket to a Public Interface

**Change Impact**

For applications developed based on earlier versions, only system applications can use **ValuesBucket**. From this version, **ValuesBucket** can be called by third-party applications.

**Key API/Component Changes**

Before change:

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
After change:

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
## cl.distributeddatamgr.2 Changed Some Predicate Interfaces in dataSharePredicates to Public Interfaces

**Change Impact**

For applications developed based on earlier versions, only system applications can use **dataSharePredicates**. From this version, on, the namespace **dataSharePredicates**, **dataSharePredicates** class, and some predicate interfaces can be called by third-party applications.

**Key API/Component Changes**

The involved interfaces are as follows:

- equalTo(field: string, value: ValueType): DataSharePredicates

- and(): DataSharePredicates

- orderByAsc(field: string): DataSharePredicates

- orderByDesc(field: string): DataSharePredicates

- limit(total: number, offset: number): DataSharePredicates

- in(field: string, value: Array<ValueType>): DataSharePredicates
