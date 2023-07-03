# arkui子系统ChangeLog

## cl.arkui.1 通用事件参数支持undefined

通用事件（点击事件、触摸事件、挂载卸载事件、按键事件、焦点事件、鼠标事件、组件区域变化事件）参数支持undefined。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Example {
  build() {
    Button("test")
    .onClick(()=>{
      console.log("click");
    })
    .onClick(undefined)
  }
}
```

**变更影响**

如果事件回调参数为undefined，那么将不再响应已经设置的事件回调。


**关键的接口/组件变更**

不涉及。

**适配指导**

当事件参数设置为undefined，将会禁用该事件，依据实际应用开发场景进行参数设置即可。
