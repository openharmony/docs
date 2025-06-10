# js标签配置

js标签用于配置实例名称、页面路由和窗口样式信息。


| 标签     | 类型     | 默认值     | 必填   | 描述                              |
| ------ | ------ | ------- | ---- | ------------------------------- |
| name   | string | default | 是    | 标识JS实例的名字。                      |
| pages  | Array  | -       | 是    | 路由信息，详见“**[pages](#pages)**”。   |
| window | Object | -       | 否    | 窗口信息，详见“**[Window](#window)**”。 |


> **说明：**
> name、pages和window等标签配置需在配置文件（config.json）中的“js”标签中完成设置。


## pages

定义每个页面的路由信息，每个页面由页面路径和页面名组成，页面的文件名即为页面名，例如：

```json
{
    // ...
    "pages": [
        "pages/index/index",
        "pages/detail/detail"
    ]
    // ...
}
```

> **说明：**
>
> - pages列表中第一个页面是应用的首页，即entry入口。
>
>
> - 页面文件名不能使用组件名称，比如：text.hml、button.hml等。

## window

window用于定义与显示窗口相关的配置。屏幕适配问题可通过以下两种方式配置：

- 指定designWidth（屏幕逻辑宽度），所有与大小相关的样式（例如width、font-size）均以designWidth和实际屏幕宽度的比例进行缩放，例如在designWidth为720时，如果设置width为100px时，在实际宽度为1440物理像素的屏幕上，width实际渲染像素为200物理像素。

- 设置autoDesignWidth为true，此时designWidth字段将会被忽略，渲染组件和布局时按屏幕密度进行缩放。屏幕逻辑宽度由设备宽度和屏幕密度自动计算得出，在不同设备上可能不同，请使用相对布局来适配多种设备。例如：在466\*466分辨率，320dpi的设备上，屏幕密度为2（以160dpi为基准），1px等于渲染出的2物理像素。

  > **说明：**
  > 1. 组件样式中&lt;length&gt;类型的默认值，基于屏幕密度进行计算和绘制。例如：在屏幕密度为2（以160dpi为基准）的设备上，默认&lt;length&gt;为1px时，设备上实际渲染出2物理像素。
  >
  > 2. autoDesignWidth、designWidth的设置不影响默认值计算方式和绘制结果。

| 属性              | 类型      | 必填   | 缺省值      | 描述                                       |
| --------------- | ------- | ---- | -------- | ---------------------------------------- |
| designWidth     | number  | 否    | 720<br/> | 页面显示设计时的参考值，实际显示效果基于设备宽度与参考值之间的比例进行缩放。   |
| autoDesignWidth | boolean | 否    | false    | 页面设计基准宽度是否自动计算。<br/>true表示页面设计基准宽度自动计算，false表示页面设计基准宽度不自动计算。<br/>当设为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 |

示例如下：
```json
{
    // ...
    "window": {
        "designWidth": 720,
        "autoDesignWidth": false
    }
    // ...
}
```


## 示例

```json
{
  "app": {
    "bundleName": "com.example.player",
    "version": {
        "code": 1,
        "name": "1.0"
    },
    "vendor": "example"
  }
  "module": {
      // ...
      "js": [
      {
          "name": "default",
          "pages": [
              "pages/index/index",
              "pages/detail/detail"
          ],
          "window": {
              "designWidth": 720,
              "autoDesignWidth": false
          }
      }
      ],
      "abilities": [
      {
          // ...
      }
    ]
  }
}
```
