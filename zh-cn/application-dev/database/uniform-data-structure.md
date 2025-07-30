# 标准化数据结构 (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--SE: @junathuawei1; @zph000-->
<!--TSE: @lj_liujing; @yippo; @logic42-->


## 场景介绍

针对[UTD标准化数据类型](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md#uniformdatatype)中的部分常见类型，为了方便业务使用，我们按照不同的数据类型提供了标准化数据结构，例如系统定义的桌面图标类型（对应的标准化数据类型标识为'openharmony.app-item'），我们明确定义了该数据结构对应的相关描述信息。

某些业务场景下应用可以直接使用我们具体定义的UTD标准化数据结构，例如跨应用拖拽场景。拖出方应用可以按照标准化数据结构将拖拽数据写入[拖拽事件](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7)，拖入方应用从拖拽事件中读取拖拽数据并按照标准化数据结构进行数据的解析。这使得不同应用间的数据交互遵从相同的标准定义，有效减少了跨应用数据交互的开发工作量。

## 接口说明

UDMF针对部分标准化数据类型定义的标准化数据结构如下所示：

| 数据结构                                                                                                |       数据类型        | 说明   |
|-----------------------------------------------------------------------------------------------------| :-------------------: |------|
| [PlainText](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#plaintext)                  |      'general.plain-text'        | 纯文本。  |
| [Hyperlink](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#hyperlink)                  |       'general.hyperlink'       | 超链接。  |
| [HTML](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#html)                            |         'general.html'          | 富文本。  |
| [OpenHarmonyAppItem](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#openharmonyappitem) | 'openharmony.app-item'    | 图标。   |
| [ContentForm](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#contentform14)            | 'general.content-form'    | 内容卡片。 |

## 开发步骤

以使用标准化数据结构定义数据内容（包含超链接、纯文本两条数据记录）为例，提供基本的开发步骤。

数据提供方可通过UMDF提供的addRecord()接口添加数据记录，使用getRecords()接口获取当前数据对象内的所有数据记录。

  ```ts
  // 1. 导入unifiedDataChannel和uniformTypeDescriptor模块。
  import { uniformDataStruct, uniformTypeDescriptor, unifiedDataChannel } from '@kit.ArkData';
  
  // 2. 创建超链接数据记录。
  let hyperlinkDetails : Record<string, string> = {
    'attr1': 'value1',
    'attr2': 'value2',
  }
  let hyperlink : uniformDataStruct.Hyperlink = {
    uniformDataType:'general.hyperlink',
    url : 'www.XXX.com',
    description : 'This is the description of this hyperlink',
    details : hyperlinkDetails,
  }
  
  hyperlink.description = '...';  // 修改hyperlink属性description
  
  console.info(`hyperlink url = ${hyperlink.url}`);  // 访问对象属性。
  
  // 3. 创建纯文本数据类型记录，将其添加到刚才创建的UnifiedData对象。
  let plainTextDetails : Record<string, string> = {
    'attr1': 'value1',
    'attr2': 'value2',
  }
  let plainText : uniformDataStruct.PlainText = {
    uniformDataType: 'general.plain-text',
    textContent : 'This is plainText textContent example',
    abstract : 'this is abstract',
    details : plainTextDetails,
  }
  // 4. 创建一个统一数据对象实例。
  let unifiedData = new unifiedDataChannel.UnifiedData();
  let hyperlinkRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, hyperlink);
  let plainTextRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
  
  // 5. 添加plainText数据记录。
  unifiedData.addRecord(hyperlinkRecord);
  unifiedData.addRecord(plainTextRecord);
  
  // 6. 记录添加完成后，可获取当前UnifiedData对象内的所有数据记录。
  let records = unifiedData.getRecords();
  
  // 7. 遍历每条记录，判断该记录的数据类型，转换为子类对象，得到原数据记录。
  for (let i = 0; i < records.length; i ++) {
    let unifiedDataRecord = records[i] as unifiedDataChannel.UnifiedRecord;
    let record = unifiedDataRecord.getValue() as object;
    if (record != undefined) {
      // 读取该数据记录的类型
      let type : string = record["uniformDataType"];
      switch (type) {
        case uniformTypeDescriptor.UniformDataType.HYPERLINK:
          Object.keys(record).forEach(key => {
            console.info('show records: ' + key + ', value:' + record[key]);
          });
          break;
        case uniformTypeDescriptor.UniformDataType.PLAIN_TEXT:
          Object.keys(record).forEach(key => {
            console.info('show records: ' + key + ', value:' + record[key]);
          });
          break;
        default:
          break;
      }
    }
  }
  ```