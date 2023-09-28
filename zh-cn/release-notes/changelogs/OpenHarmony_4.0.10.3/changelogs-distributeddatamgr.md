
# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 @ohos.data.UDMF.d.ts拆分为@ohos.data.unifiedDataChannel.d.ts和@ohos.data.uniformTypeDescriptor.d.ts

**变更影响**

该变更为不兼容变更，原@ohos.data.UDMF.d.ts拆分为@ohos.data.unifiedDataChannel.d.ts和@ohos.data.uniformTypeDescriptor.d.ts。
将原@ohos.data.UDMF.d.ts中定义的枚举类UnifiedDataType移动到@ohos.data.uniformTypeDescriptor.d.ts中并改名为UniformDataType，
剩余接口定义移动到@ohos.data.unifiedDataChannel.d.ts中不做变化。

**关键接口/组件变更**

拆分前UnifiedDataType枚举类的定义：

 | 名称                         | 值                            | 说明        |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'Text'                       | 文本类型。     |
| PLAIN_TEXT                 | 'Text.PlainText'             | 纯文本类型。    |
| HYPERLINK                  | 'Text.Hyperlink'             | 超链接类型。    |
| HTML                       | 'Text.HTML'                  | 富文本类型。    |
| FILE                       | 'File'                       | 文件类型。     |
| IMAGE                      | 'File.Media.Image'           | 图片类型。     |
| VIDEO                      | 'File.Media.Video'           | 视频类型。     |
| AUDIO                      | 'File.Media.Audio'           | 音频类型。     |
| FOLDER                     | 'File.Folder'                | 文件夹类型。    |
| SYSTEM_DEFINED_RECORD      | 'SystemDefinedType'          | 系统服务数据类型。 |
| SYSTEM_DEFINED_FORM        | 'SystemDefinedType.Form'     | 卡片类型。     |
| SYSTEM_DEFINED_APP_ITEM    | 'SystemDefinedType.AppItem'  | 图标类型。     |
| SYSTEM_DEFINED_PIXEL_MAP   | 'SystemDefinedType.PixelMap' | 二进制图片类型。  |
| APPLICATION_DEFINED_RECORD | 'ApplicationDefinedType'     | 应用自定义类型。  |

拆分后改名为UniformDataType枚举类的定义：  
1、删除了枚举值定义SYSTEM_DEFINED_RECORD和APPLICATION_DEFINED_RECORD。  
2、枚举值SYSTEM_DEFINED_FORM改名为OPENHARMONY_FORM，枚举值SYSTEM_DEFINED_APP_ITEM改名为OPENHARMONY_APP_ITEM，枚举值SYSTEM_DEFINED_PIXEL_MAP改名为OPENHARMONY_PIXEL_MAP。  
3、枚举值的字符串定义发生了变化。

 | 名称                         | 值                            | 说明        |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'general.text'                   | 文本类型。     |
| PLAIN_TEXT                 | 'general.plain-text'             | 纯文本类型。    |
| HYPERLINK                  | 'general.hyperlink'              | 超链接类型。    |
| HTML                       | 'general.html'                   | 富文本类型。    |
| FILE                       | 'general.file'                   | 文件类型。     |
| IMAGE                      | 'general.image'                  | 图片类型。     |
| VIDEO                      | 'general.video'                  | 视频类型。     |
| AUDIO                      | 'general.audio'                  | 音频类型。     |
| FOLDER                     | 'general.folder'                 | 文件夹类型。    |
| OPENHARMONY_FORM           | 'openharmony.form'               | 卡片类型。     |
| OPENHARMONY_APP_ITEM       | 'openharmony.app-item'           | 图标类型。     |
| OPENHARMONY_PIXEL_MAP      | 'openharmony.pixel-map'          | 二进制图片类型。  |

**适配指导**

本次变更主要有以下几点需要开发人员适配：  
1、将前文中的枚举值变化进行相应适配。  
2、将导入模块由修改前的@ohos.data.UDMF模块更改为@ohos.data.unifiedDataChannel和@ohos.data.uniformTypeDescriptor两个模块。  
3、根据导入模块的变化，将命名空间UDMF替换成对应的导入模块名，UnifiedDataType替换为UniformDataType。

变更前代码示例：

```
// 导入@ohos.data.UDMF模块
import UDMF from '@ohos.data.UDMF';

// 创建一个统一数据对象实例
let unifiedData = new UDMF.UnifiedData(image);

// 创建纯文本数据类型记录，将其添加到刚才创建的UnifiedData对象
let plainText = new UDMF.PlainText();
plainText.textContent = 'this is textContent of plainText';
unifiedData.addRecord(plainText);

// 遍历每条记录，判断该记录的数据类型，转换为子类对象，得到原数据记录
let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i ++) {
  // 读取该数据记录的类型
  let type = records[i].getType();
  switch (type) {
    case UDMF.UnifiedDataType.IMAGE:
      // 转换得到原图片数据记录
      let image = <UDMF.Image>(records[i]);
      break;
    case UDMF.UnifiedDataType.PLAIN_TEXT:
      // 转换得到原文本数据记录
      let plainText = <UDMF.PlainText>(records[i]);
      break;
    default:
      break;
  }
}
```

变更后代码示例：

```
// 导入@ohos.data.unifiedDataChannel和@ohos.data.uniformTypeDescriptor模块
import UDC from '@ohos.data.unifiedDataChannel';
import UTD from '@ohos.data.uniformTypeDescriptor';

// 创建一个统一数据对象实例
let unifiedData = new UDC.UnifiedData(image);

// 创建纯文本数据类型记录，将其添加到刚才创建的UnifiedData对象
let plainText = new UDC.PlainText();
plainText.textContent = 'this is textContent of plainText';
unifiedData.addRecord(plainText);

// 遍历每条记录，判断该记录的数据类型，转换为子类对象，得到原数据记录
let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i ++) {
  // 读取该数据记录的类型
  let type = records[i].getType();
  switch (type) {
    case UTD.UniformDataType.IMAGE:
      // 转换得到原图片数据记录
      let image = <UDC.Image>(records[i]);
      break;
    case UTD.UniformDataType.PLAIN_TEXT:
      // 转换得到原文本数据记录
      let plainText = <UDC.PlainText>(records[i]);
      break;
    default:
      break;
  }
}
```
