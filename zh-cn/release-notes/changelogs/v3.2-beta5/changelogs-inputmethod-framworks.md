# 输入法框架changeLog

## cl.inputmethod_frameworks.1 API文件名变更

下列模块不符合OpenHarmony接口文件名命名规范。在API9进行变更。

 **变更影响**
 
 修改后的SDK与先前已发布版本不兼容，影响在此前版本已开发的应用，应用需要进行适配改动才可以在新版本SDK环境正常编译通过。
 
 **关键的接口/组件变更**
 
| 模块 | 变更前文件名 | 变更后文件名 |
|------|--------------|--------------|
| 输入法框架模块 | @ohos.inputmethod.d.ts |@ohos.inputMethod.d.ts |
| 输入法服务模块 |@ohos.inputmethodengine.d.ts | @ohos.inputMethodEngine.d.ts |
| 输入法ExtentionAbility模块 | @ohos.inputmethodextensionability.d.ts | @ohos.InputMethodExtensionAbility.d.ts |
| 输入法ExtentionContext模块 |@ohos.inputmethodextensioncontext.d.ts | @ohos.InputMethodExtensionContext.d.ts |
| 输入法子类型模块 | @ohos.inputMethodSubtype.d.ts | @ohos.InputMethodSubtype.d.ts |
 
 **适配指导**
 
 应用中对输入法框架d.ts文件的import后的文件名要写为变更后文件名，即小驼峰/大驼峰命名格式。
 如：
 
```js
import inputMethodEngine from '@ohos.inputMethodEngine';
```
 
 