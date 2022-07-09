# 访问应用资源


## 资源定义

应用资源由开发者在工程的resources目录中定义，resources目录按照两级目录的形式来组织：

- 一级目录为base目录、限定词目录以及rawfile目录
  - base目录是默认存在的目录。当应用的resources资源目录中没有与设备状态匹配的限定词目录时，会自动引用该目录中的资源文件。
  - 限定词目录需要开发者自行创建，其可以由一个或多个表征应用场景或设备特征的限定词组合而成，包括移动国家码和移动网络码、语言、文字、国家或地区、横竖屏、设备类型、颜色模式和屏幕密度等维度，限定词之间通过下划线（_）或者中划线（-）连接。
  - 在引用rawfile中的资源时，不会根据系统的状态去匹配，rawfile目录中可以直接存放资源文件。

- 二级目录为资源目录
  - 用于存放字符串、颜色、浮点数等基础元素，以及媒体等资源文件。
  - 当前支持的文件和资源类型如下：
       | 文件名 | 资源类型 |
     | -------- | -------- |
     | color.json | 颜色资源。 |
     | float.json | 间距、圆角、字体等资源。 |
     | string.json | 字符串资源。 |
     | plural.json | 字符串资源。 |
     | media目录 | 图片资源。 |


## 资源引用

在工程中，通过```"$r('app.type.name')"```的形式引用应用资源。app代表是应用内resources目录中定义的资源；type代表资源类型（或资源的存放位置），可以取“color”、“float”、“string”、“plural”、“media”，name代表资源命名，由开发者定义资源时确定。

引用rawfile下资源时使用```"$rawfile('filename')"```的形式，当前$rawfile仅支持Image控件引用图片资源，filename需要表示为rawfile目录下的文件相对路径，文件名需要包含后缀，路径开头不可以以"/"开头。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 资源描述符不能拼接使用，仅支持普通字符串如`'app.type.name'`。


## 示例

base目录中部分自定义资源如下所示：


```
    resources
      ├─ base 
      │    ├─ element 
      │    │   ├─ color.json
      │    │   ├─ string.json
      │    │   └─ float.json
      │    └─ media
      │       └─ my_background_image.png
      └─ rawfile
           ├─ test.png
           └─ newDir
               └─ newTest.png  
```

color.json文件的内容如下：


```
{
    "color": [
        {
            "name": "color_hello",
            "value": "#ffff0000"
        },
        {
            "name": "color_world",
            "value": "#ff0000ff"
        }
    ]
}
```

float.json文件的内容如下：


```
{
    "float":[
        {
            "name":"font_hello",
            "value":"28.0fp"
        },
	{
            "name":"font_world",
            "value":"20.0fp"
        }
    ]
}
```

string.json文件的内容如下：


```
{
    "string":[
        {
            "name":"string_hello",
            "value":"Hello"
        },
	{
            "name":"string_world",
            "value":"World"
        },
	{
            "name":"message_arrive",
            "value":"We will arrive at %s."
        }
    ]
}
```

plural.json文件的内容如下：


```
{
    "plural":[
        {
            "name":"eat_apple",
            "value":[
                {
                    "quantity":"one",
                    "value":"%d apple"
                },
                {
                    "quantity":"other",
                    "value":"%d apples"
                }
            ]
        }
    ]
}
```

  在ets文件中，可以使用在resources目录中定义的资源。

```
Text($r('app.string.string_hello'))
    .fontColor($r('app.color.color_hello'))
    .fontSize($r('app.float.font_hello'))
}

Text($r('app.string.string_world'))
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Text($r('app.string.message_arrive', "five of the clock")) // 引用string资源，$r的第二个参数用于替换%s
    .fontColor($r('app.color.color_hello'))
    .fontSize($r('app.float.font_hello'))
}

Text($r('app.plural.eat_apple', 5, 5))       // plural$r引用，第一个指定plural资源，第二个参数指定单复数的数量，此处第三个数字为对%d的替换
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Image($r('app.media.my_background_image'))  // media资源的$r引用

Image($rawfile('test.png'))                 // rawfile$r引用rawfile目录下图片

Image($rawfile('newDir/newTest.png'))       // rawfile$r引用rawfile目录下图片
```


## 相关实例

针对访问应用资源，有以下相关实例可供参考：

- [`ResourceManager`：资源管理器（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/common/ResourceManager)
