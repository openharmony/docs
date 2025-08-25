# @Entry：页面入口

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Entry装饰的自定义组件将作为UI页面的入口。

> **说明：**
>
> 本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## @Entry

在单个UI页面中，仅允许存在一个由@Entry装饰的自定义组件作为页面的入口。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
@Entry
@Component
struct Index {
  build() {
    Text('@Entry Test')
  }
}
```

## EntryOptions<sup>10+</sup>

命名路由跳转选项。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                         | 类型                                                         | 必填 | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| routeName                      | string                                                       | 否   | 表示作为命名路由页面的名字。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| storage                        | [LocalStorage](../../../ui/state-management/arkts-localstorage.md) | 否   | 页面级的UI状态存储。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| useSharedStorage<sup>12+</sup> | boolean                                                      | 否   | 是否使用[LocalContent](../arkts-apis-window-WindowStage.md#loadcontent9)传入的LocalStorage实例对象。默认值false。true：使用共享的LocalStorage实例对象。false：不使用共享的LocalStorage实例对象。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

**示例：**

```ts
@Entry({routeName: 'myPage'})
@Component
struct Index {
  build() {
    Text('Index')
  }
}
```

