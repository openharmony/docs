# 配置文件


js标签中包含了实例名称、窗口样式和卡片页面信息。


| 标签 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| name | String | default | 是 | 标识JS实例的名字。 |
| pages | Array | - | 是 | 路由信息，详见“[pages](#pages)”。 |
| window | Object | - | 否 | 窗口信息，详见“[window](#window)”。 |

> **说明：**
> name、pages、window等标签配置需在[配置文件]()中的“js”标签中完成设置。


## pages

定义卡片页面信息，由卡片页面路径和卡片页面名组成，卡片仅包含一个页面。比如：


```
{
  ...
  "src": "./js/widget/pages/index/index" //卡片仅包含一个页面
  ...
}
```


>  **说明：**
> - pages列表中仅包含一个页面。
> 
> - 页面文件名不能使用组件名称，比如：text.hml、button.hml等。


## window

window用于定义与显示窗口相关的配置。对于卡片尺寸适配问题，有2种配置方法，建议使用autoDesignWidth：

- 指定卡片designWidth 150px（2×2），所有与大小相关的样式（例如width、font-size）均以designWidth和实际卡片宽度的比例进行缩放，例如在designWidth为150时，如果设置width为100px时，在卡片实际宽度为300物理像素时，width实际渲染像素为200物理像素。

- 设置autoDesignWidth为true，此时designWidth字段将会被忽略，渲染组件和布局时按屏幕密度进行缩放。屏幕逻辑宽度由设备宽度和屏幕密度自动计算得出，在不同设备上可能不同，请使用相对布局来适配多种设备。例如：在466\*466分辨率，320dpi的设备上，屏幕密度为2（以160dpi为基准），1px等于渲染出的2物理像素。
  > **说明：**
  > - 组件样式中&lt;length&gt;类型的默认值，按屏幕密度进行计算和绘制，如：在屏幕密度为2（以160dpi为基准）的设备上，默认&lt;length&gt;为1px时，设备上实际渲染出2物理像素。
  > 
  > - autoDesignWidth、designWidth的设置不影响默认值计算方式和绘制结果。

  | 属性 | 类型 | 必填 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| designWidth | number | 否 | 150px | 页面显示设计时的参考值，实际显示效果基于设备宽度与参考值之间的比例进行缩放。 |
| autoDesignWidth | boolean | 否 | false | 页面设计基准宽度是否自动计算，当设为true时，designWidth将会被忽略，设计基准宽度由设备宽度与屏幕密度计算得出。 |

  示例如下：
    ```
    {
      ...
      "window": {
        "autoDesignWidth": true
      }
      ...
    }
    ```


## 示例


```json
{
  "forms": [
    {
      "name": "widget",
      "description": "This is a service widget.",
      "src": "./js/widget/pages/index/index",
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      },
      "colorMode": "auto",
      "isDefault": true,
      "updateEnabled": true,
      "scheduledUpdateTime": "10:30",
      "updateDuration": 1,
      "defaultDimension": "2*2",
      "supportDimensions": [
        "1*2","2*2","2*4","4*4"
      ],
      "formConfigAbility": "ability://xxxxx"
    }
  ]
}
```
