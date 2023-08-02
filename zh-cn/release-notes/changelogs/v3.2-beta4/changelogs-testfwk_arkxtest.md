# 测试子系统ChangeLog

## cl.testfwk_arkxtest.1 On、Driver、Component类接口新增支持异常处理

API8原有接口废弃，API9新增替代接口，API9接口支持异常处理，需使用try catch捕获接口抛出的异常。

## 变更影响

此变更影响@ohos.uitest提供的api9-JS接口。用户此前在测试用例开发中使用了@ohos.uitest-api9接口的，需要进行适配才可以在新版本SDK环境正常编译通过。

## 关键的接口/组件变更

- 废弃API8原有的`By`类，在API9中使用`On`类代替，`On`类接口新增支持异常处理机制；类内接口名称保持不变，**例外**：`By#key`接口替换为`On.id`。
- 废弃API8原有的`BY`对象，在API9中使用`ON`对象代替。
- 废弃API8原有的`UiDriver`类，在API9中使用`Driver`类代替，`Driver`类接口新增支持异常处理机制；类内接口名称保持不变。
- 废弃API8原有的`UiComponent`类，在API9中使用`Component`类代替，`Component`类接口新增支持异常处理机制；类内接口名称保持不变。

## 适配指导

### 1.适配接口名称变更

可按照如下规则做类名替换：

- `By-->On`
- `BY-->ON`
- `UiDriver-->Driver`
- `UiComponent-->Component`

### 2.捕获处理异常

使用try-catch处理接口捕获可能抛出的异常，例如：

```typescript
import {Driver,ON,Component} from '@ohos.uitest'

try {
    let driver = Driver.create();
} catch (error) {
    // error handle; error.code为错误码
}
```