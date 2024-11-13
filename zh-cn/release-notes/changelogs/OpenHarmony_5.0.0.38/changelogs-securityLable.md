# 文件子系统变更说明

## cl.CoreFileKit.1 setSecurityLabel接口行为变更

**访问级别**

公开接口

**变更原因**

setSecurityLabel接口未对设置的安全等级进行校验，未阻止应用将高风险等级数据设置为低风险等级，有安全风险，需要进行整改。

**变更影响**

该变更为不兼容变更。

变更前：应用数据如果已设置过等级，仍可以降低数据安全等级，调用以下代码接口可设置成功。

变更后：应用数据设置过数据风险等级后，无法降低数据风险等级，接口抛错13900020。

```ts
import {fileIo,securityLabel} from '@kit.CoreFileKit';
try {
     let path = getContext().filesDir + '/text.txt';
     let file = fileIo.openSync(path,fileIo.OpenMode.CREATE);
     securityLabel.setSecurityLabelSync(file.path, "s4");
     securityLabel.setSecurityLabelSync(file.path, "s3");
     console.log( "set security label s3 success");
} catch (err) {
    console.log( "set security label s3  fail, " + err.message + err.code);
}
```

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

| 接口声明 | 变更前 | 变更后 |
| ------------------------------------------------------------ | --------- | ------ |
| setSecurityLabel(path:string, type:DataLevel):Promise&lt;void&gt; | 数据风险等级由高向低设置未做拦截 | 数据风险等级由高向低设置时抛错 |
| setSecurityLabel(path:string, type:DataLevel, callback: AsyncCallback&lt;void&gt;):void          | 数据风险等级由高向低设置未做拦截 | 数据风险等级由高向低设置时抛错 |
| setSecurityLabelSync(path:string, type:DataLevel):void       | 数据风险等级由高向低设置未做拦截 | 数据风险等级由高向低设置时抛错 |

**适配指导**

此修改为Bugfix，如果应用未多次设置数据风险等级，则无需适配，没有影响。

如果应用需多次设置数据风险等级，需注意设置数据风险等级应该符合安全规范，数据风险等级仅可由低向高或设置相同的等级。将高风险等级数据设置为低风险等级接口将会抛错。

## cl.CoreFileKit.2 getSecurityLabel接口行为变更

**访问级别**

公开接口

**变更原因**

getSecurityLabel接口获取未对设置过的数据风险等级的数据返回值为空字符串，不符合安全设计。需要修改实现返回“s3”。

**变更影响**

该变更为不兼容变更。

变更前：使用接口获取未设置过数据风险等级标签的数据时，默认返回了空字符。运行以下代码，日志中会打印label为空字符串。

变更后：使用接口获取未设置过数据风险等级标签的数据时，默认返回“s3”。运行以下代码，日志中会打印label为“s3”。

```ts
import {fileIo,securityLabel} from '@kit.CoreFileKit';
try {
     let path = getContext().filesDir + '/text.txt';
     let file = fileIo.openSync(path,fileIo.OpenMode.CREATE);
     let label = securityLabel.getSecurityLabelSync(file.path);
     console.log( "get security label success, label is" + label);
} catch (err) {
    console.log( "get security label fail, " + err.message + err.code);
}
```

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

| 接口声明 | 变更前 | 变更后 |
| ------------------------------------------------------------ | --------- | ------ |
| getSecurityLabel(path:string, callback:AsyncCallback&lt;string&gt;): void | 默认返回空字符串 | 默认返回“s3” |
| getSecurityLabel(path:string):Promise&lt;string&gt; | 默认返回空字符串 | 默认返回“s3” |
| getSecurityLabelSync(path:string):string | 默认返回空字符串 | 默认返回“s3” |

**适配指导**

此变更属于Bugfix，应用无需适配。使用getSecurityLabel接口获取未设置过数据风险等级标签的数据时，默认返回“s3”。
