# 结果集

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 使用说明

需要通过[RdbStore.query()](js-apis-data-rdb.md#query)获取resultSet对象。

```
import dataRdb from '@ohos.data.rdb';
let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("AGE", 18)
let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
promise.then((resultSet) => {
    console.log("resultSet columnNames:" + resultSet.columnNames);
    console.log("resultSet columnCount:" + resultSet.columnCount);
})
```


## 权限

无


## ResultSet

提供通过查询数据库生成的数据库结果集的访问方法。


### 属性


| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| columnNames | Array&lt;string&gt; | 是 | 获取结果集中所有列的名称。 |
| columnCount | number | 是 | 获取结果集中的列数。 |
| rowCount | number | 是 | 获取结果集中的行数。 |
| rowIndex | number | 是 | 获取结果集当前行的索引。 |
| isAtFirstRow | boolean | 是 | 检查结果集是否位于第一行。 |
| isAtLastRow | boolean | 是 | 检查结果集是否位于最后一行。 |
| isEnded | boolean | 是 | 检查结果集是否位于最后一行之后。 |
| isStarted | boolean | 是 | 检查指针是否移动过。 |
| isClosed | boolean | 是 | 检查当前结果集是否关闭。 |


### getColumnIndex

getColumnIndex(columnName: string): number

根据指定的列名获取列索引。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnName | string | 是 | 表示结果集中指定列的名称。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回指定列的索引。 |

- 示例：
  ```
  resultSet.goToFirstRow()
  const id = resultSet.getLong(resultSet.getColumnIndex("ID"))
  const name = resultSet.getString(resultSet.getColumnIndex("NAME"))
  const age = resultSet.getLong(resultSet.getColumnIndex("AGE"))
  const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"))
  ```


### getColumnName

getColumnName(columnIndex: number): string

根据指定的列索引获取列名。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 表示结果集中指定列的索引。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回指定列的名称。 |

- 示例：
  ```
  const id = resultSet.getColumnName(0)
  const name = resultSet.getColumnName(1)
  const age = resultSet.getColumnName(2)
  ```


### goTo

goTo(offset:number): boolean

向前或向后转至结果集的指定行，相对于其当前位置偏移。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | offset | number | 是 | 表示相对于当前位置的偏移量。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goTo(1);
    resultSet.close();
    resultSet = null;
  })
  ```


### goToRow

goToRow(position: number): boolean

转到结果集的指定行。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | position | number | 是 | 表示要移动到的指定位置。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goToRow(1);
    resultSet.close();
    resultSet = null
  })
  ```


### goToFirstRow

goToFirstRow(): boolean


转到结果集的第一行。


- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goToFirstRow();
    resultSet.close();
    resultSet = null;
  })
  ```


### goToLastRow

goToLastRow(): boolean

转到结果集的最后一行。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goToLastRow();
    resultSet.close();
    resultSet = null;
  })
  ```


### goToNextRow

goToNextRow(): boolean

转到结果集的下一行。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goToNextRow()
    resultSet.close()
    resultSet = null;
  })
  ```


### goToPreviousRow

goToPreviousRow(): boolean

转到结果集的上一行。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.goToPreviousRow();
    resultSet.close();
    resultSet = null
  })
  ```


### getBlob

getBlob(columnIndex: number): Uint8Array

以字节数组的形式获取当前行中指定列的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Uint8Array | 以字节数组的形式返回指定列的值。 |

- 示例：
  ```
  const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"))
  ```


### getString

getString(columnIndex: number): string

以字符串形式获取当前行中指定列的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 以字符串形式返回指定列的值。 |

- 示例：
  ```
  const name = resultSet.getString(resultSet.getColumnIndex("NAME"))
  ```


### getLong

getLong(columnIndex: number): number

以Long形式获取当前行中指定列的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 以Long形式返回指定列的值。 |

- 示例：
  ```
  const age = resultSet.getLong(resultSet.getColumnIndex("AGE"))
  ```


### getDouble

getDouble(columnIndex: number): number

以double形式获取当前行中指定列的值。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 以double形式返回指定列的值。 |

- 示例：
  ```
  const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"))
  ```


### isColumnNull

isColumnNull(columnIndex: number): boolean

检查当前行中指定列的值是否为null。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |

- 示例：
  ```
  const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"))
  ```


### close

close(): void

关闭结果集。


- 示例：
  ```
  let predicates = new dataRdb.RdbPredicates("EMPLOYEE")
  rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet) => {
    resultSet.close();
    resultSet = null
  })
  ```
