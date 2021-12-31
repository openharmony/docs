# js标签配置

开发框架需要应用的config.json中配置相关的js标签，其中包含了实例名称、页面路由、视图窗口配置信息。


| 标签 | 类型 | 默认值 | 必填 | 描述 |
| -------- | -------- | -------- | -------- | -------- |
| name | string | default | 是 | 标识ETS实例的名字。 |
| pages | Array | - | 是 | 页面路由信息，详见[pages](#pages)说明。 |
| window | Object | - | 否 | 视图窗口配置信息，详见[window](#window)说明。 |
| mode | Object | - | 否 | 配置Js&nbsp;Component运行类型与语法风格，详见[mode](#mode)说明。 |


## pages

定义每个页面入口组件的路由信息，每个页面由页面路径和页面名组成，页面的文件名就是页面名。比如：

```
{
    "pages": [
        "pages/index",
        "pages/detail"
    ]
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - pages列表中第一个页面为应用的首页入口。
> 
> - 页面文件名不能使用组件名称，比如：Text.ets、Button.ets等。
> 
> - 每个页面文件中必须包含[页面入口组件](../ui/ts-component-based-entry.md)(\@Entry装饰)。


## window

window用于配置相关视图显示窗口，支持配置如下属性：

| 类型 | 默认值 | 说明 |
| -------- | -------- | -------- |
| designWidth | - | 配置视图显示的逻辑宽度，缺省默认720（智能穿戴默认454）。视图显示的逻辑宽度决定了lpx像素单位大小，如designWidth配置720时，在视图宽度为1440物理像素时，1lpx为2物理像素。详见[lpx像素单位](../ui/ts-pixel-units.md)说明。 |

```
{
  ...
  "window": {
    "designWidth": 720
  }
  ...
}
```


## mode

mode用于配置JS Component的运行类型与语法风格，支持如下属性：

| 类型 | 默认值 | 说明 |
| -------- | -------- | -------- |
| type | - | 配置该JS&nbsp;Component的运行类型，可选值为：<br/>-&nbsp;pageAbility：以ability的方式运行该JS&nbsp;Component。<br/>-&nbsp;form：以卡片的方式运行该JS&nbsp;Component。 |
| syntax | - | 配置该JS&nbsp;Component的语法风格，可选值为：<br/>-&nbsp;hml：以hml/css/js风格进行编写。<br/>-&nbsp;ets：以声明式语法风格进行编写。 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 不支持同时配置type类型为form，syntax类型为ets。


## 示例

config.json:

```
{
    "app": {
        "bundleName": "com.example.player",
        "version": {
            "code": 1,
            "name": "1.0"
        },
        "vendor": "example"
    },
    "module": {
        "js": [{            
            "name": "default",            
            "pages": [                
                "pages/index",                
                "pages/detail"            
            ],            
            "window": {                
                "designWidth": 720            
            },            
            "mode": {                
                "type": "pageAbility",                
                "syntax": "ets"            
            },        
        }],
        "abilities": [{
            ... 
        }]
    }
}
```
