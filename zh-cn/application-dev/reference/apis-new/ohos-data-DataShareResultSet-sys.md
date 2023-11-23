# @ohos.data.DataShareResultSet    
**结果集(DataShareResultSet)** 可提供访问由查询数据库生成的结果集的相关方法，根据提供的行数，查询相应的值，也可查询指定数据类型的值。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DataType    
数据类型枚举。  
    
    
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_NULL | 0 | 表示值类型为空。<br/> |  
| TYPE_LONG | 1 | 表示值类型为长整数值。<br/> |  
| TYPE_DOUBLE | 2 | 表示值类型为双浮点数。<br/> |  
| TYPE_STRING | 3 | 表示值类型为字符串。<br/> |  
| TYPE_BLOB | 4 | 表示值类型为字节数组。<br/> |  
    
## DataShareResultSet    
提供通过查询数据库生成的结果集的相关访问方法。列或键名称作为字符串数组返回，其中字符串的顺序与结果集中的列或键的顺序相同。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| columnNames | Array<string> | false | true | 结果集中所有列的名称。<br/> |  
| columnCount | number | false | true | 结果集中的列数。<br/> |  
| rowCount | number | false | true | 结果集中的行数。<br/> |  
| isClosed | boolean | false | true | 标识当前结果集是否关闭。<br/> |  
    
### goToFirstRow    
转到结果集的第一行。  
  
 **调用形式：**     
- goToFirstRow(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### goToLastRow    
转到结果集的最后一行。  
  
 **调用形式：**     
- goToLastRow(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### goToNextRow    
转到结果集的下一行。  
  
 **调用形式：**     
- goToNextRow(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### goToPreviousRow    
转到结果集的上一行。  
  
 **调用形式：**     
- goToPreviousRow(): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### goTo    
相对于当前位置向前或向后移动指定行数。  
  
 **调用形式：**     
- goTo(offset: number): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 表示相对于当前位置的偏移量。offset为负值表示向前偏移，正值则表示向后偏移。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### goToRow    
转到结果集的指定行。  
  
 **调用形式：**     
- goToRow(position: number): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| position | number | true | 表示要移动到的指定位置。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果成功移动结果集，则为true；否则返回false。 |  
    
### getBlob    
以字节数组的形式获取当前行中指定列的值。如果当前行中指定的列或键的值为空，或者指定的列或键不是Blob类型，则实现类确定是否抛出异常。  
 **调用形式：**     
- getBlob(columnIndex: number): Uint8Array  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 以字节数组的形式返回指定列的值。 |  
    
### getString    
以字符串形式获取当前行中指定列的值。  
  
 **调用形式：**     
- getString(columnIndex: number): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以字符串形式返回指定列的值。 |  
    
### getLong    
以长整数值形式获取当前行中指定列的值。  
  
 **调用形式：**     
- getLong(columnIndex: number): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 以长整数值形式返回指定列的值。 |  
    
### getDouble    
以值类型为双浮点数形式获取当前行中指定列的值。  
  
 **调用形式：**     
- getDouble(columnIndex: number): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 指定的列索引，从0开始。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 值类型为双浮点数形式返回指定列的值。 |  
    
### close    
关闭结果集。  
  
 **调用形式：**     
- close(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
### getColumnIndex    
根据指定的列名获取列索引。  
  
 **调用形式：**     
- getColumnIndex(columnName: string): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnName | string | true | 表示结果集中指定列的名称。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定列的索引。 |  
    
### getColumnName    
根据指定的列索引获取列名。  
  
 **调用形式：**     
- getColumnName(columnIndex: number): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 表示结果集中指定列的索引。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定列的名称。 |  
    
### getDataType    
指定列索引获取该列的数据类型。  
  
 **调用形式：**     
- getDataType(columnIndex: number): DataType  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| columnIndex | number | true | 表示结果集中指定列的索引。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataType | 返回指定列的类型。 |  
