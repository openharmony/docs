# @ohos.security.identifySensitiveContent (识别敏感内容)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @Yuan_bys-->
<!--Designer: @zhengdu_628-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

识别敏感内容通过输入的[Policy](#policy)来检测指定文件中的敏感信息。系统根据提供的[Policy](#policy)策略（包括敏感标签、关键字集合和正则表达式），对文件内容进行关键字匹配和正则表达式匹配，返回匹配到的敏感内容结果。

> **说明：**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { identifySensitiveContent } from '@kit.DataProtectionKit';
```

## identifySensitiveContent.scanFile
scanFile(filePath: string, identifyPolicies:Array&lt;Policy&gt;): Promise&lt;Array&lt;MatchResult&gt;&gt;

根据设置的策略，识别指定文件中的敏感内容，返回识别的结果数组，包含匹配的敏感标签、匹配内容及匹配数量。使用Promise异步回调。

**需要权限**：ohos.permission.ENTERPRISE_DATA_IDENTIFY_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filePath | string | 是 | 识别的文件路径，需使用物理路径，路径指向的文件必须存在且支持访问。 |
| identifyPolicies | Array&lt;[Policy](#policy)&gt; | 是 | 用于识别敏感内容的策略数组。每个Policy定义识别规则（标签、关键字、正则表达式），系统将根据这些规则扫描文件内容并返回匹配结果。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[MatchResult](#matchresult)&gt;&gt; | Promise对象，返回敏感内容识别的结果。成功时返回匹配结果数组，异常返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[数据泄露防护DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | permission denied. |
| 801 | Capability not supported. |
| 19110001 | Parameter error. Possible causes: 1. Incorrect policy format. 2. Invalid parameter range. |
| 19110002 | Sensitive file content identification timed out. |
| 19110003 | The file is not supported. Possible causes: 1. The file path does not exist. 2. The file type is not supported. 3. The file permission is not supported. |
| 19110004 | A system error has occurred. |

**示例：**

```ts
import { identifySensitiveContent } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义待扫描的文件物理路径
const filePath = '/data/service/el2/100/hmdfs/account/files/Docs/Documents/test.txt';

// 配置敏感内容识别策略
const policies: Array<identifySensitiveContent.Policy> = [
  {"sensitiveLabel":"name", "keywords":["姓名"], "regex":""},
  {"sensitiveLabel":"phone", "keywords":[], "regex":"电话"},
  {"sensitiveLabel":"address", "keywords":["地址"], "regex":"xx省xx市"}
];
try {
  identifySensitiveContent.scanFile(filePath, policies).then(records => {
    console.info('scanFile finish');
    for (let i = 0; i < records.length; ++i) {
      const sensitiveLabel = records[i].sensitiveLabel;
      const matchContent = records[i].matchContent;
      const matchNumber = records[i].matchNumber;
      console.info(`scanFile result sensitiveLabel: ${sensitiveLabel} matchNumber ${matchNumber} matchContent ${matchContent}`);
    }
  }).catch((err: BusinessError) => {
    // 处理识别失败
    console.error(`Failed to scanFile. Code: ${err.code}, message: ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to scanFile. Code: ${err.code}, message: ${err.message}`);
}
```

## Policy

定义敏感内容识别策略。

- 单个策略内，关键字与正则表达式为顺序组合关系，实行两级匹配：首先进行关键字匹配，若命中，则仅在该关键字匹配位置的前后各50字节窗口内，进行正则表达式匹配。若只设置关键字，则仅进行关键字匹配。若只设置正则表达式，则仅进行正则表达式匹配。
- 多个Policy策略之间独立，扫描时会分别应用每个策略。
- sensitiveLabel用于标记匹配结果，便于识别具体匹配的策略。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| sensitiveLabel | string | 否 | 否 | 表示识别策略的标签，用于标识和分类匹配结果。长度范围1-30字节。 |
| keywords | Array&lt;string&gt; | 否 | 否 | 表示关键字集合，用于匹配文件中的敏感关键字。<br>系统会在文件内容中搜索这些关键字，匹配时区分大小写，匹配成功则返回识别结果。Array最大50，每个元素最大30字节。 |
| regex | string | 否 | 否 | 表示匹配敏感内容的正则表达式。系统将在文件内容中按此正则表达式进行模式匹配，匹配成功的内容将返回在结果中。长度范围0-512字节。<br>在输入字符串时，需检查某些特殊字符（如反斜杠 \、双引号 "、换行符等），不会被自动转义，确保字符串的输入效果。 |

## MatchResult

表示敏感内容的识别结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| sensitiveLabel | string | 是 | 否 | 表示识别策略的标签，与输入策略中的sensitiveLabel对应，用于标识匹配结果对应的识别策略。 |
| matchContent | string | 是 | 否 | 表示匹配到的敏感内容片段，即文件中实际匹配到关键字或正则表达式的文本内容。 |
| matchNumber | number | 是 | 否 | 表示匹配内容的总数。 |
