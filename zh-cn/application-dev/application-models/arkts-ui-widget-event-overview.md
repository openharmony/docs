# 卡片事件能力说明

针对动态卡片，ArkTS卡片中提供了[postCardAction()](../reference/apis/js-apis-postCardAction.md#postCardAction)接口用于卡片内部和提供方应用间的交互，当前支持router、message和call三种类型的事件，仅在卡片中可以调用。
<br/>针对静态卡片，ArkTS卡片提供了[FormLink](../reference/arkui-ts/ts-container-formlink.md)用于卡片内部和提供方应用间的交互。

## 动态卡片事件能力说明
![WidgetPostCardAction](figures/WidgetPostCardAction.png)

`postCardAction()`接口示例代码：

```ts
Button('跳转')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'router',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        message: 'testForRouter' // 自定义要发送的message
      }
    });
  })

Button('拉至后台')
  .width('40%')
  .height('20%')
  .onClick(() => {
    postCardAction(this, {
      action: 'call',
      bundleName: 'com.example.myapplication',
      abilityName: 'EntryAbility',
      params: {
        method: 'fun', // 自定义调用的方法名，必填
        message: 'testForCall' // 自定义要发送的message
      }
    });
  })
```

## 静态卡片事件能力说明
请参见[FormLink](../reference/arkui-ts/ts-container-formlink.md)
