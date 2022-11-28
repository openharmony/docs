# 资源分类与访问

应用开发过程中，经常需要用到颜色、字体、间距、图片等资源，在不同的设备或配置中，这些资源的值可能不同。

- 应用资源：借助资源文件能力，开发者在应用中自定义资源，自行管理这些资源在不同的设备或配置中的表现。

- 系统资源：开发者直接使用系统预置的资源定义（即[分层参数](../key-features/multi-device-app-dev/visual-basics.md)，同一资源ID在设备类型、深浅色等不同配置下有不同的取值）。

## 资源分类

### resources目录

应用开发中使用的各类资源文件，需要放入特定子目录中存储管理。resources目录包括三大类目录，一类为base目录，一类为限定词目录，还有一类为rawfile目录。stage模型多工程情况下共有的资源文件放到AppScope下的resources目录。

base目录默认存在，而限定词目录需要开发者自行创建。应用使用某资源时，系统会根据当前设备状态优先从相匹配的限定词目录中寻找该资源。只有当resources目录中没有与设备状态匹配的限定词目录，或者在限定词目录中找不到该资源时，才会去base目录中查找。rawfile是原始文件目录，不会根据设备状态去匹配不同的资源。

资源目录示例：

```
resources
|---base  // 默认存在的目录
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---en_GB-vertical-car-mdpi // 限定词目录示例，需要开发者自行创建   
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---rawfile
```

**表1** resources目录分类

| 分类   | base目录                           | 限定词目录                                    | rawfile目录                                |
| ---- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| 组织形式 | base目录是默认存在的目录。当应用的resources目录中没有与设备状态匹配的限定词目录时，会自动引用该目录中的资源文件。<br/>base目录的二级子目录为**资源组目录**，用于存放字符串、颜色、布尔值等基础元素，以及媒体、动画、布局等资源文件，具体要求参见[资源组目录](#资源组目录)。 | 限定词目录需要开发者自行创建。目录名称由一个或多个表征应用场景或设备特征的限定词组合而成，具体要求参见[限定词目录](#限定词目录)。<br/>限定词目录的二级子目录为**资源组目录**，用于存放字符串、颜色、布尔值等基础元素，以及媒体、动画、布局等资源文件，具体要求参见[资源组目录](#资源组目录)。 | 支持创建多层子目录，目录名称可以自定义，文件夹内可以自由放置各类资源文件。<br/>rawfile目录的文件不会根据设备状态去匹配不同的资源。 |
| 编译方式 | 目录中的资源文件会被编译成二进制文件，并赋予资源文件ID。            | 目录中的资源文件会被编译成二进制文件，并赋予资源文件ID。            | 目录中的资源文件会被直接打包进应用，不经过编译，也不会被赋予资源文件ID。    |
| 引用方式 | 通过指定资源类型（type）和资源名称（name）来引用。            | 通过指定资源类型（type）和资源名称（name）来引用。            | 通过指定文件路径和文件名来引用。                         |


### 限定词目录

限定词目录可以由一个或多个表征应用场景或设备特征的限定词组合而成，包括移动国家码和移动网络码、语言、文字、国家或地区、横竖屏、设备类型、颜色模式和屏幕密度等维度，限定词之间通过下划线（\_）或者中划线（\-）连接。开发者在创建限定词目录时，需要掌握限定词目录的命名要求，以及限定词目录与设备状态的匹配规则。

**限定词目录的命名要求**

- 限定词的组合顺序：\_移动国家码_移动网络码-语言_文字_国家或地区-横竖屏-设备类型-颜色模式-屏幕密度_。开发者可以根据应用的使用场景和设备特征，选择其中的一类或几类限定词组成目录名称。

- 限定词的连接方式：语言、文字、国家或地区之间采用下划线（\_）连接，移动国家码和移动网络码之间也采用下划线（\_）连接，除此之外的其他限定词之间均采用中划线（-）连接。例如：**zh_Hant_CN**、**zh_CN-car-ldpi**。

- 限定词的取值范围：每类限定词的取值必须符合限定词取值要求表中的条件，否则，将无法匹配目录中的资源文件。

**表2** 限定词取值要求

| 限定词类型       | 含义与取值说明                                  |
| ----------- | ---------------------------------------- |
| 移动国家码和移动网络码 | 移动国家码（MCC）和移动网络码（MNC）的值取自设备注册的网络。MCC后面可以跟随MNC，使用下划线（_）连接，也可以单独使用。例如：mcc460表示中国，mcc460_mnc00表示中国_中国移动。<br/>详细取值范围，请查阅**ITU-T&nbsp;E.212**（国际电联相关标准）。 |
| 语言          | 表示设备使用的语言类型，由2~3个小写字母组成。例如：zh表示中文，en表示英语，mai表示迈蒂利语。<br/>详细取值范围，请查阅**ISO&nbsp;639**（ISO制定的语言编码标准）。 |
| 文字          | 表示设备使用的文字类型，由1个大写字母（首字母）和3个小写字母组成。例如：Hans表示简体中文，Hant表示繁体中文。<br/>详细取值范围，请查阅**ISO&nbsp;15924**（ISO制定的文字编码标准）。 |
| 国家或地区       | 表示用户所在的国家或地区，由2~3个大写字母或者3个数字组成。例如：CN表示中国，GB表示英国。<br/>详细取值范围，请查阅**ISO&nbsp;3166-1**（ISO制定的国家和地区编码标准）。 |
| 横竖屏         | 表示设备的屏幕方向，取值如下：<br/>-&nbsp;vertical：竖屏<br/>-&nbsp;horizontal：横屏 |
| 设备类型        | 表示设备的类型，取值如下：<br/>-&nbsp;car：车机<br/>-&nbsp;tv：智慧屏<br/>-&nbsp;wearable：智能穿戴 |
| 颜色模式        | 表示设备的颜色模式，取值如下：<br/>-&nbsp;dark：深色模式<br/>-&nbsp;light：浅色模式 |
| 屏幕密度        | 表示设备的屏幕密度（单位为dpi），取值如下：<br/>-&nbsp;sdpi：表示小规模的屏幕密度（Small-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(0,&nbsp;120]的设备。<br/>-&nbsp;mdpi：表示中规模的屏幕密度（Medium-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(120,&nbsp;160]的设备。<br/>-&nbsp;ldpi：表示大规模的屏幕密度（Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(160,&nbsp;240]的设备。<br/>-&nbsp;xldpi：表示特大规模的屏幕密度（Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(240,&nbsp;320]的设备。<br/>-&nbsp;xxldpi：表示超大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(320,&nbsp;480]的设备。<br/>-&nbsp;xxxldpi：表示超特大规模的屏幕密度（Extra&nbsp;Extra&nbsp;Extra&nbsp;Large-scale&nbsp;Dots&nbsp;Per&nbsp;Inch），适用于dpi取值为(480,&nbsp;640]的设备。 |

**限定词目录与设备状态的匹配规则**

- 在为设备匹配对应的资源文件时，限定词目录匹配的优先级从高到低依次为：移动国家码和移动网络码 &gt; 区域（可选组合：语言、语言_文字、语言_国家或地区、语言_文字_国家或地区）&gt; 横竖屏 &gt; 设备类型 &gt; 颜色模式 &gt; 屏幕密度。

- 如果限定词目录中包含**移动国家码和移动网络码、语言、文字、横竖屏、设备类型、颜色模式**限定词，则对应限定词的取值必须与当前的设备状态完全一致，该目录才能够参与设备的资源匹配。例如，限定词目录“zh_CN-car-ldpi”不能参与“en_US”设备的资源匹配。


### 资源组目录

base目录与限定词目录下面可以创建资源组目录（包括element、media、profile），用于存放特定类型的资源文件，详见资源组目录说明。


  **表3** 资源组目录说明

| 资源组目录   | 目录说明                                     | 资源文件                                     |
| ------- | ---------------------------------------- | ---------------------------------------- |
| element | 表示元素资源，以下每一类数据都采用相应的JSON文件来表征。<br/>-&nbsp;boolean，布尔型<br/>-&nbsp;color，颜色<br/>-&nbsp;float，浮点型<br/>-&nbsp;intarray，整型数组<br/>-&nbsp;integer，整型<br/>-&nbsp;pattern，样式<br/>-&nbsp;plural，复数形式<br/>-&nbsp;strarray，字符串数组<br/>-&nbsp;string，字符串 | element目录中的文件名称建议与下面的文件名保持一致。每个文件中只能包含同一类型的数据。<br/>-&nbsp;boolean.json<br/>-&nbsp;color.json<br/>-&nbsp;float.json<br/>-&nbsp;intarray.json<br/>-&nbsp;integer.json<br/>-&nbsp;pattern.json<br/>-&nbsp;plural.json<br/>-&nbsp;strarray.json<br/>-&nbsp;string.json |
| media   | 表示媒体资源，包括图片、音频、视频等非文本格式的文件。              | 文件名可自定义，例如：icon.png。                     |
| rawfile | 表示其他类型文件，在应用构建为hap包后，以原始文件形式保存，不会被集成到resources.index文件中。 | 文件名可自定义。                                 |

**媒体资源类型说明**

**表4** 图片资源类型说明

| 格式   | 文件后缀名 |
| ---- | ----- |
| JPEG | .jpg  |
| PNG  | .png  |
| GIF  | .gif  |
| SVG  | .svg  |
| WEBP | .webp |
| BMP  | .bmp  |

**表5** 音视频资源类型说明

| 格式                                   | 支持的文件类型         |
| ------------------------------------ | --------------- |
| H.263                                | .3gp <br>.mp4   |
| H.264 AVC <br> Baseline Profile (BP) | .3gp <br>.mp4   |
| MPEG-4 SP                            | .3gp            |
| VP8                                  | .webm <br> .mkv |

**资源文件示例**

color.json文件的内容如下：


```json
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


```json
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


```json
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


```json
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

## 资源访问

### 应用资源

**创建资源文件**

在resources目录下，可按照限定词目录和资源组目录的说明创建子目录和目录内的文件。

同时，DevEco Studio也提供了创建资源目录和资源文件的界面。

- 创建资源目录及资源文件

  在resources目录右键菜单选择“New > Resource File”，此时可同时创建目录和文件。文件默认创建在base目录的对应资源组下。如果选择了限定词，则会按照命名规范自动生成限定词+资源组目录，并将文件创建在目录中。图中Avaliable qualifiers为供选择的限定词目录，通过右边的小箭头可添加或者删除。File name为需要创建的文件名，Resource type为资源组类型，默认是element。Root Element为资源类型。创建的目录名自动生成，格式固定为“限定词.资源组”，例如：创建一个限定词为dark的element目录，自动生成的目录名称为“dark.element”。

  ![create-resource-file-1](figures/create-resource-file-1.png)

- 创建资源目录

  在resources目录右键菜单选择“New > Resource Directory”，此时可创建资源目录。资源目录创建的是base目录，也可根据需求创建其它限定词目录。确定限定词后，选择资源组类型，当前资源组类型支持Element、Media、Profile三种，创建后自动生成目录名称。

  ![create-resource-file-2](figures/create-resource-file-2.png)

- 创建资源文件

  在资源目录的右键菜单选择“New > XXX Resource File”，即可创建对应资源组目录的资源文件。例如，在element目录下可新建Element Resource File。

  ![create-resource-file-3](figures/create-resource-file-3.png)

**访问应用资源**

在工程中，通过```"$r('app.type.name')"```的形式引用应用资源。app代表是应用内resources目录中定义的资源；type代表资源类型（或资源的存放位置），可以取“color”、“float”、“string”、“plural”、“media”，name代表资源命名，由开发者定义资源时确定。

引用rawfile下资源时使用```"$rawfile('filename')"```的形式，filename需要表示为rawfile目录下的文件相对路径，文件名需要包含后缀，路径开头不可以以"/"开头。

> **说明：**
> 
> 资源描述符不能拼接使用，仅支持普通字符串如`'app.type.name'`。
>
> `$r`返回值为Resource对象，可通过[getStringValue](../reference/apis/js-apis-resource-manager.md#getstringvalue9) 方法获取对应的字符串。

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

### 系统资源

系统资源包含色彩、圆角、字体、间距、字符串及图片等。通过使用系统资源，不同的开发者可以开发出具有相同视觉风格的应用。

开发者可以通过```“$r('sys.type.resource_id')”```的形式引用系统资源。sys代表是系统资源；type代表资源类型，可以取“color”、“float”、“string”、“media”；resource_id代表资源id。

可以查看[应用UX设计中关于资源的介绍](../key-features/multi-device-app-dev/design-resources.md)，获取OpenHarmony支持的系统资源ID及其在不同配置下的取值。

> **说明：**
>
> - 仅声明式开发范式支持使用系统资源，类Web开发范式不支持。
>
> - 可以查看[OpenHarmony/resources代码仓](https://gitee.com/openharmony/resources/tree/master/systemres/main/resources)了解系统预置资源的实现，这里的目录结构与工程中的resources目录类似，也是通过资源限定词匹配不同的设备或设备状态。
> - 系统资源的使用场景、id、参数详细对照表详见[OpenHarmony_系统资源分层设计表_V1.0.xlsm](../key-features/multi-device-app-dev/OpenHarmony_系统资源分层设计表_V1.0.xlsm)

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

## 相关实例

针对访问应用资源，有以下相关实例可供参考：

- [`ResourceManager`：资源管理器（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/common/ResourceManager)
