# 资源访问


## 访问应用资源

在工程中，通过```"$r('app.type.name')"```的形式引用应用资源。app代表是应用内resources目录中定义的资源；type代表资源类型（或资源的存放位置），可以取“color”、“float”、“string”、“plural”、“media”，name代表资源命名，由开发者定义资源时确定。

引用rawfile下资源时使用```"$rawfile('filename')"```的形式，当前$rawfile仅支持Image控件引用图片资源，filename需要表示为rawfile目录下的文件相对路径，文件名需要包含后缀，路径开头不可以以"/"开头。

> **说明：**
>
> 资源描述符不能拼接使用，仅支持普通字符串如`'app.type.name'`。
>
> `$r`返回值为Resource对象，可通过[getString](../reference/apis/js-apis-resource-manager.md#getstring) 方法获取对应的字符串。

在xxx.ets文件中，可以使用在resources目录中定义的资源。

```ts
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
## 访问系统资源

系统资源包含色彩、圆角、字体、间距、字符串及图片等。通过使用系统资源，不同的开发者可以开发出具有相同视觉风格的应用。


开发者可以通过```“$r('sys.type.resource_id')”```的形式引用系统资源。sys代表是系统资源；type代表资源类型，可以取“color”、“float”、“string”、“media”；resource_id代表资源id。

```ts
Text('Hello')
    .fontColor($r('sys.color.ohos_id_color_emphasize'))
    .fontSize($r('sys.float.ohos_id_text_size_headline1'))
    .fontFamily($r('sys.string.ohos_id_text_font_family_medium'))
    .backgroundColor($r('sys.color.ohos_id_color_palette_aux1'))
Image($r('sys.media.ohos_app_icon'))
    .border({color: $r('sys.color.ohos_id_color_palette_aux1'), radius: $r('sys.float.ohos_id_corner_radius_button'), width: 2})
    .margin({top: $r('sys.float.ohos_id_elements_margin_horizontal_m'), bottom: $r('sys.float.ohos_id_elements_margin_horizontal_l')})
    .height(200)
    .width(300)
```
## 资源文件示例

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

 


## 相关实例

针对访问应用资源，有以下相关实例可供参考：

- [`ResourceManager`：资源管理器（eTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/samples_monthly_0730/common/ResourceManager)
