# XComponent

可用于EGL/OpenGLES和媒体数据写入，并显示在XComponent组件。

> **说明：**
>
> 该组件从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

  


## 子组件

  不支持。

## 接口

  XComponent(value: {id: string, type: string, libraryname?: string, controller?: XComponentController})

**参数:** 

| 参数名       | 参数类型     | 必填   | 描述    |
| --------- | ------ | ---- | ----- |
| id  | string | 是    | 组件的唯一标识，支持最大的字符串长度128。 |
| type      | string | 是    |  用于指定XComponent组件类型，可选值为：<br/>-surface：组件内容单独送显，直接合成到屏幕。<br/>-component：组件内容与其他组件合成后统一送显。 |
| libraryname | string | 否    | 应用Native层编译输出动态库名称。 |
| controller   | [XComponentcontroller](#xcomponentcontroller) | 否    | 给组件绑定一个控制器，通过控制器调用组件方法。 |

## 事件

### onLoad

onLoad(callback: (event?: object) => void )

插件加载完成时回调事件。

**参数:**

| 参数名           | 参数类型   | 必填  | 描述                      |
| ------------- | ------ | ---- | ----------------------- |
| event  | object |   否  | 获取XComponent实例对象的context，context上挂载的方法由开发者在c++层定义。 |

### onDestroy

onDestroy(event: () => void )

插件卸载完成时回调事件。

## XComponentController

xcomponent 组件的控制器，可以将此对象绑定至XComponent组件，然后通过控制器来调用组件方法。

### 创建对象

```
xcomponentController: XComponentController = new XComponentController()
```

### getXComponentSurfaceId

getXComponentSurfaceId(): string

获取XComponent对应Surface的ID，供@ohos接口使用，比如camera相关接口。


**返回值:**

| 类型     | 描述                      |
| ------ | ----------------------- |
| string | XComponent持有Surface的ID。 |


### setXComponentSurfaceSize

setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void

设置XComponent持有Surface的宽度和高度。


**参数:**

| 参数名           | 参数类型   | 必填  | 描述                      |
| ------------- | ------ | ---- | ----------------------- |
| surfaceWidth  | number | 是    | XComponent持有Surface的宽度。 |
| surfaceHeight | number | 是    | XComponent持有Surface的高度。 |


### getXComponentContext

getXComponentContext(): Object

获取XComponent实例对象的context。

**返回值:**

| 类型     | 描述                                       |
| ------ | ---------------------------------------- |
| Object | 获取XComponent实例对象的context，context包含的具体接口方法由开发者自定义。 |


## 示例

示例效果请以真机运行为准，当前IDE预览器不支持。

```ts
// xxx.ets
@Entry
@Component
struct PreviewArea {
  private surfaceId : string =''
  xcomponentController: XComponentController = new XComponentController()
  build() {
    Row() {
      XComponent({
        id: 'xcomponent',
        type: 'surface',
        controller: this.xcomponentController
      })
        .onLoad(() => {
          this.xcomponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080});
          this.surfaceId = this.xcomponentController.getXComponentSurfaceId()
        })
        .width('640px')
        .height('480px')
    }
    .backgroundColor(Color.Black)
    .position({x: 0, y: 48})
  }
}
```
