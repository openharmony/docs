# ArkUI子系统ChangeLog

##  cl.arkui.1 工具链对Scroll的拦截规则变更

**访问级别**

公开接口

**变更原因**

Scroll组件在设计上仅支持添加单个子组件，当前在开发者文档上也已注明Scroll组件仅支持单个子组件，如下：
https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-container-scroll.md#%E5%AD%90%E7%BB%84%E4%BB%B6
但在IDE中，由于没有配置工具链在编译时对该点进行拦截，导致开发者在Scroll组件下添加多个子组件后也可以编译成功。为了避免开发者误用，需要通过修改工具链，添加编译器报错提示。

**变更影响**

该变更为非兼容性变更。由于当前Scroll组件在C++的实现逻辑是即使开发者在前端Scroll组件下添加了多个子组件也只会取第一个组件作为自己的可滑动子组件，在其之上运行功能逻辑。因此添加工具链编译拦截，只会影响到一些少量的之前添加了多个子组件的存量应用（因为这个用法本来就是错误的用法），使其编译不过，但是并不会改变其应用布局和行为。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

通过增加compiler/components/scroll.json的single:true配置项，使得工具链编译时报错。

修改前：
```json
{
  "name": "Scroll",
  "attrs": []
}
```
修改后：
```json
{
  "name": "Scroll",
  "single": true,
  "attrs": []
}
```
**适配指导**

添加了多个子组件的存量应用只会编译不通过，不会改变其应用布局和行为。这些存量应用也只需要删除Scroll组件下添加的多余子组件，即可编译成功。