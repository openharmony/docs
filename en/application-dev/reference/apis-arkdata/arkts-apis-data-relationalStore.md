# Module Description
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

The relational database (RDB) manages data based on relational models. The **relationalStore** module provides a complete mechanism for managing local databases based on the underlying SQLite. You can use the APIs to perform operations such as adding, deleting, modifying, and querying data, and directly run SQL statements. In addition, you can obtain sendable data using [ResultSet.getSendableRow](arkts-apis-data-relationalStore-ResultSet.md#getsendablerow12) and transfer the data across threads.

To ensure successful data access, limit the size of a data record to 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

Querying data from a large amount of data may take time or even cause application suspension. In this case, you can perform batch operations. For details, see [Batch Database Operations](../../arkts-utils/batch-database-operations-guide.md). Moreover, observe the following:
- The number of data records to be queried at a time should not exceed 5000.
- Use [TaskPool](../apis-arkts/js-apis-taskpool.md) if there is a large amount of data needs to be queried.
- Keep concatenated SQL statements as concise as possible.
- Query data in batches.

The **relationalStore** module provides the following functionalities:

- [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](arkts-apis-data-relationalStore-RdbStore.md): provides APIs for managing data in an RDB store.
- [ResultSet](arkts-apis-data-relationalStore-ResultSet.md): provides APIs for accessing the result set obtained from the RDB store.
- [Transaction](arkts-apis-data-relationalStore-Transaction.md): provides APIs for managing transaction objects.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Module to Import

```ts
import { relationalStore } from '@kit.ArkData';
```
