# 公共基础类库子系统JS API变更Changelog

## cl.commonlibrary.1.URLParams类接口变更
公共基础类库子系统url模块URLParams类构造函数存在变更：

constructor(init?: string[][] | Record<string, string> | string | URLSearchParams) 改为 constructor(init?: string[][] | Record<string, string> | string | URLParams);参数类型为原来的URLSearchParams类改为URLParams类。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| :------------------------ | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.url        | URLParams         | constructor(string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams) | 删除  |
| @ohos.url         | URLParams       | constructor(string[][] \| Record&lt;string, string&gt; \| string \| URLParams)| 变更

**适配指导**

应用中创建URLParams对象实例可参考下列代码

示例：

```ts
import url from '@ohos.url'
try {
    let params1 = new Url.URLParams('?user=abc&query=xyz')
    let params2 = new Url.URLParams(params1)
    var result= params2.toString()
    console.log(result) //"user=abc&query=xyz"
} catch (err) {
    console.error(`Fail to ceate URLParams.codeis${err.code},message is ${err.message}`);
}
```
## cl.commonlibrary.2.URL类属性变更url子系统URLParams类构造函数存在变更：
公共基础类库子系统url模块URL类属性存在变更：

废弃searchParams: URLSearchParams属性，新增params: URLParams属性

开发者需要根据以下说明对应用进行适配。 

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| :------------------------ | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.url        | URL         |  searchParams: URLSearchParams; |废弃版本：9<br>    |
| @ohos.url        | URL         |  params: URLParams; | 新增     |

**适配指导**

应用中创建URLParams对象实例可参考下列代码

示例：

```ts
import url from '@ohos.url'
let that = new Url.URL('http://username:password@host:8080/directory/file?你好=china#qwer=da')
let params = that.URLParams
var result = params.toString()
console.log(result) //%E4%BD%A0%E5%A5%BD=china
```