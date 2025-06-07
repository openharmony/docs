# Interfaces (其他)

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## StoreConfig

管理关系数据库配置。

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | 是   | 数据库文件名，也是数据库唯一标识符。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core   |
| securityLevel | [SecurityLevel](arkts-apis-data-relationalStore-e.md#securitylevel) | 是   | 设置数据库安全级别。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core|
| encrypt       | boolean       | 否   | 指定数据库是否加密，默认不加密。<br/> true：加密。<br/> false：非加密。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| dataGroupId<sup>10+</sup> | string | 否 | 应用组ID，<!--RP1-->暂不支持指定dataGroupId在对应的沙箱路径下创建RdbStore实例。<!--RP1End--><br/>**模型约束：** 此属性仅在Stage模型下可用。<br/>从API version 10开始，支持此可选参数。dataGroupId共沙箱的方式不支持多进程访问加密数据库，当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| customDir<sup>11+</sup> | string | 否 | 数据库自定义路径。<br/>**使用约束：** 数据库路径大小限制为128字节，如果超过该大小会开库失败，返回错误。<br/>从API version 11开始，支持此可选参数。数据库将在如下的目录结构中被创建：context.databaseDir + "/rdb/" + customDir，其中context.databaseDir是应用沙箱对应的路径，"/rdb/"表示创建的是关系型数据库，customDir表示自定义的路径。当此参数不填时，默认在本应用沙箱目录下创建RdbStore实例。从API version 18开始，如果同时配置了rootDir参数，将打开或删除如下路径数据库：rootDir + "/" + customDir + "/" + name。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| rootDir<sup>18+</sup> | string | 否 | 指定数据库根路径。<br/>从API version 18开始，支持此可选参数。将从如下目录打开或删除数据库：rootDir + "/" + customDir。通过设置此参数打开的数据库为只读模式，不允许对数据库进行写操作，否则返回错误码801。配置此参数打开或删除数据库时，应确保对应路径下数据库文件存在，并且有读取权限，否则返回错误码14800010。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| autoCleanDirtyData<sup>11+</sup> | boolean | 否 | 指定是否自动清理云端删除后同步到本地的数据，true表示自动清理，false表示手动清理，默认自动清理。<br/>对于端云协同的数据库，当云端删除的数据同步到设备端时，可通过该参数设置设备端是否自动清理。手动清理可以通过[cleanDirtyData<sup>11+</sup>](arkts-apis-data-relationalStore-RdbStore.md#cleandirtydata11)接口清理。<br/>从API version 11开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client |
| allowRebuild<sup>12+</sup> | boolean | 否 | 指定数据库是否支持异常时自动删除，并重建一个空库空表，默认不删除。<br/>true：自动删除。<br/>false：不自动删除。<br/>从API version 12开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| isReadOnly<sup>12+</sup> | boolean | 否 | 指定数据库是否只读，默认为数据库可读写。<br/>true：只允许从数据库读取数据，不允许对数据库进行写操作，否则会返回错误码801。<br/>false：允许对数据库进行读写操作。<br/>从API version 12开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| pluginLibs<sup>12+</sup> | Array\<string> | 否 | 表示包含有fts（Full-Text Search，即全文搜索引擎）等能力的动态库名的数组。<br/>**使用约束：** <br/>1. 动态库名的数量限制最多为16个，如果超过该数量会开库失败，返回错误。<br/>2. 动态库名需为本应用沙箱路径下或系统路径下的动态库，如果动态库无法加载会开库失败，返回错误。<br/>3. 动态库名需为完整路径，用于被sqlite加载。<br/>样例：[context.bundleCodeDir+ "/libs/arm64/" + libtokenizer.so]，其中context.bundleCodeDir是应用沙箱对应的路径，"/libs/arm64/"表示子目录，libtokenizer.so表示动态库的文件名。当此参数不填时，默认不加载动态库。<br/>4. 动态库需要包含其全部依赖，避免依赖项丢失导致无法运行。<br/>例如：在ndk工程中，使用默认编译参数构建libtokenizer.so，此动态库依赖c++标准库。在加载此动态库时，由于namespace与编译时不一致，链接到了错误的libc++_shared.so，导致`__emutls_get_address`符号找不到。要解决此问题，需在编译时静态链接c++标准库，具体请参见[NDK工程构建概述](../../napi/build-with-ndk-overview.md)。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| cryptoParam<sup>14+</sup> | [CryptoParam](#cryptoparam14) | 否 | 指定用户自定义的加密参数。<br/>当此参数不填时，使用默认的加密参数，见[CryptoParam](#cryptoparam14)各参数默认值。<br/>此配置只有在encrypt选项设置为真时才有效。<br/>从API version 14开始，支持此可选参数。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| vector<sup>18+</sup> | boolean | 否 | 指定数据库是否是向量数据库，true表示向量数据库，false表示关系型数据库，默认为false。<br/>向量数据库适用于存储和处理高维向量数据，关系型数据库适用于存储和处理结构化数据。<br/>当使用向量数据库时，在调用deleteRdbStore接口前，应当确保向量数据库已打开的RdbStore和ResultSet均已成功关闭。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| tokenizer<sup>17+</sup> | [Tokenizer](arkts-apis-data-relationalStore-e.md#tokenizer17) | 否 | 指定用户在fts场景下使用哪种分词器。<br/>当此参数不填时，则在fts下不支持中文以及多国语言分词，但仍可支持英文分词。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| persist<sup>18+</sup> | boolean | 否 | 指定数据库是否需要持久化。true表示持久化，false表示不持久化，即内存数据库。默认为true。<br/>内存数据库不支持加密、backup、restore、跨进程访问及分布式能力，securityLevel属性会被忽略。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |
| enableSemanticIndex<sup>20+</sup> | boolean | 否 | 指定数据库是否启用语义索引处理功能。true表示启用语义索引处理功能，false表示不启用。默认为false。<br/>**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core |

## CryptoParam<sup>14+</sup>

数据库加密参数配置。此配置只有在StoreConfig的encrypt选项设置为true时有效。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| encryptionKey | Uint8Array | 是   | 指定数据库加/解密使用的密钥。<br/>如传入密钥为空，则由数据库负责生成并保存密钥，并使用生成的密钥打开数据库文件。<br/>使用完后用户需要将密钥内容全部置为零。 |
| iterationCount | number | 否 | 整数类型，指定数据库PBKDF2算法的迭代次数，默认值为10000。<br/>迭代次数应当为大于零的整数，若非整数则向下取整。<br/>不指定此参数或指定为零时，使用默认值10000，并使用默认加密算法AES_256_GCM。 |
| encryptionAlgo | [EncryptionAlgo](arkts-apis-data-relationalStore-e.md#encryptionalgo14) | 否 | 指定数据库加解密使用的加密算法。如不指定，默认值为 AES_256_GCM。 |
| hmacAlgo | [HmacAlgo](arkts-apis-data-relationalStore-e.md#hmacalgo14) | 否 | 指定数据库加解密使用的HMAC算法。如不指定，默认值为SHA256。 |
| kdfAlgo | [KdfAlgo](arkts-apis-data-relationalStore-e.md#kdfalgo14) | 否 | 指定数据库加解密使用的PBKDF2算法。如不指定，默认使用和HMAC算法相等的算法。 |
| cryptoPageSize | number | 否 | 整数类型，指定数据库加解密使用的页大小。如不指定，默认值为1024字节。<br/>用户指定的页大小应为1024到65536范围内的整数，并且为2<sup>n</sup>。若指定值非整数，则向下取整。 |

## Asset<sup>10+</sup>

记录资产附件（文件、图片、视频等类型文件）的相关信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称          | 类型                          | 必填  | 说明           |
| ----------- | --------------------------- | --- | ------------ |
| name        | string                      | 是   | 资产的名称。       |
| uri         | string                      | 是   | 资产的uri，在系统里的绝对路径。       |
| path        | string                      | 是   | 资产在应用沙箱里的路径。       |
| createTime  | string                      | 是   | 资产被创建出来的时间。   |
| modifyTime  | string                      | 是   | 资产最后一次被修改的时间。 |
| size        | string                      | 是   | 资产占用空间的大小。    |
| status      | [AssetStatus](arkts-apis-data-relationalStore-e.md#assetstatus10) | 否   | 资产的状态，默认值为ASSET_NORMAL。        |

## ChangeInfo<sup>10+</sup>

记录端云同步过程详情。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                             | 是   | 表示发生变化的表的名称。                                     |
| type     | [ChangeType](arkts-apis-data-relationalStore-e.md#changetype10)        | 是   | 表示发生变化的数据的类型，数据或者资产附件发生变化。         |
| inserted | Array\<string\> \| Array\<number\> | 是   | 记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。 |
| updated  | Array\<string\> \| Array\<number\> | 是   | 记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。 |
| deleted  | Array\<string\> \| Array\<number\> | 是   | 记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。 |

## DistributedConfig<sup>10+</sup>

记录表的分布式配置信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| autoSync   | boolean | 是   | 该值为true时，表示该表支持自动同步和手动同步；该值为false时，表示该表只支持手动同步，不支持自动同步。 |
| asyncDownloadAsset<sup>18+</sup> | boolean | 否 | 表示当前数据库在端云同步时，同步或异步下载资产。true表示优先下载完所有数据后，使用异步任务下载资产；false表示同步下载资产；默认值为false。 |
| enableCloud<sup>18+</sup> | boolean | 否 | 表示当前数据库是否允许端云同步。true表示允许端云同步；false表示不允许端云同步。默认值为true。 |

## Statistic<sup>10+</sup>

描述数据库表的端云同步过程的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称       | 类型   | 必填 | 说明                                     |
| ---------- | ------ | ---- | ---------------------------------------- |
| total      | number | 是   | 表示数据库表中需要端云同步的总行数。     |
| successful | number | 是   | 表示数据库表中端云同步成功的行数。       |
| failed     | number | 是   | 表示数据库表中端云同步失败的行数。       |
| remained   | number | 是   | 表示数据库表中端云同步剩余未执行的行数。 |

## TableDetails<sup>10+</sup>

描述数据库表执行端云同步任务上传和下载的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                      | 必填 | 说明                                       |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| upload   | [Statistic](arkts-apis-data-relationalStore-i.md#statistic10) | 是   | 表示数据库表中端云同步上传过程的统计信息。 |
| download | [Statistic](arkts-apis-data-relationalStore-i.md#statistic10) | 是   | 表示数据库表中端云同步下载过程的统计信息。 |

## ProgressDetails<sup>10+</sup>

描述数据库整体执行端云同步任务上传和下载的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| schedule | [Progress](arkts-apis-data-relationalStore-e.md#progress10)                            | 是   | 表示端云同步过程。                                           |
| code     | [ProgressCode](arkts-apis-data-relationalStore-e.md#progresscode10)                  | 是   | 表示端云同步过程的状态。                                     |
| details  | Record<string, [TableDetails](#tabledetails10)> | 是   | 表示端云同步各表的统计信息。<br>键表示表名，值表示该表的端云同步过程统计信息。 |

## SqlExecutionInfo<sup>12+</sup>

描述数据库执行的SQL语句的统计信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                                               | 只读 | 可选  |说明                                                         |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| sql<sup>12+</sup>           | Array&lt;string&gt;            | 是   |   否   | 表示执行的SQL语句的数组。当[batchInsert](arkts-apis-data-relationalStore-RdbStore.md#batchinsert)的参数太大时，可能有多个SQL。      |
| totalTime<sup>12+</sup>      | number                        | 是   |   否   | 表示执行SQL语句的总时间，单位为μs。                                    |
| waitTime<sup>12+</sup>       | number                        | 是   |   否   | 表示获取句柄的时间，单位为μs。                                         |
| prepareTime<sup>12+</sup>    | number                        | 是   |   否   | 表示准备SQL和绑定参数的时间，单位为μs。                                 |
| executeTime<sup>12+</sup>    | number                        | 是   |   否   | 表示执行SQL语句的时间，单位为μs。 |

## ExceptionMessage<sup>20+</sup>

描述数据库执行的SQL语句的错误信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称     | 类型                                               | 只读 | 可选  |说明                                                         |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| code<sup>20+</sup>      | number                        | 是   |   否   | 表示执行SQL返回的错误码，对应的取值和含义请见[sqlite错误码](https://www.sqlite.org/rescode.html) |
| messgae<sup>20+</sup>       | string                        | 是   |   否   | 表示执行SQL返回的错误信息。                                         |
| sql<sup>20+</sup>    | string                        | 是   |   否   | 表示报错执行的SQL语句。                         |

## TransactionOptions<sup>14+</sup>

事务对象的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| transactionType          | [TransactionType](arkts-apis-data-relationalStore-e.md#transactiontype14)        | 否   | 事务类型。默认为DEFERRED。  |
