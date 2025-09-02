# 资源限定与访问
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sunfei2021-->
<!--Designer: @sunfei2021-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## 资源限定词

资源限定词可以由一个或多个表示应用场景或设备特征的限定词组合而成，包括屏幕密度等维度，限定词之间通过中划线（-）连接。开发者在**resources**目录下创建限定词文件时，需要掌握限定词文件的命名要求以及与限定词文件与设备状态的匹配规则。


## 资源限定词的命名要求

- 限定词的组合顺序：屏幕密度。开发者可以根据应用的使用场景和设备特征，选择其中的一类或几类限定词组成目录名称，顺序不可颠倒。

- 限定词的连接方式：限定词之间均采用中划线（-）连接。例如：res-dark-ldpi.json 。

- 限定词的取值范围：每类限定词的取值必须符合下表的条件，否则，将无法匹配目录中的资源文件，限定词大小写敏感。

- 限定词前缀：**resources**资源文件的资源限定词有前缀res，例如res-ldpi.json。

- 默认资源限定文件：**resources**资源文件的默认资源限定文件为res-defaults.json。

- 资源限定文件中不支持使用枚举格式的颜色来设置资源。


**表1** 资源限定词

| 类型 | 含义与取值说明 |
| -------- | -------- |
| 屏幕密度 | 表示设备的屏幕密度（单位为dpi），取值如下：<br/>-&nbsp;ldpi：表示低密度屏幕（\~120dpi）（0.75基准密度）<br/>-&nbsp;mdpi：表示中密度屏幕（\~160dpi）（基准密度）<br/>-&nbsp;hdpi：表示高密度屏幕（\~240dpi）（1.5基准密度）<br/>-&nbsp;xhdpi：表示加高密度屏幕（\~320dpi）（2.0基准密度）<br/>-&nbsp;xxhdpi：表示超超高密度屏幕（\~480dpi）（3.0基准密度）<br/>-&nbsp;xxxhdpi：表示超超超高密度屏幕（\~640dpi）（4.0基准密度） |


## 限定词与设备状态的匹配规则

- 在为设备匹配对应的资源文件时，限定词目录匹配的优先级从高到低依次为：MCC和MNC&gt; 横竖屏 &gt; 深色模式 &gt; 设备类型 &gt; 屏幕密度。在资源限定词目录均未匹配的情况下，则匹配默认资源限定文件。

- 如果限定词目录中包含资源限定词，则对应限定词的取值必须与当前的设备状态完全一致，该目录才能够参与设备的资源匹配。例如：资源限定文件res-hdpi.json与当前设备密度xhdpi无法匹配。


## 引用JS模块内resources资源

在应用开发的hml和js文件中使用$r的语法，可以对JS模块内的resources目录下的json资源进行格式化，获取相应的资源内容，该目录与pages目录同级，具体目录结构请参考[文件组织](js-framework-file.md)。

| 属性 | 类型 | 描述 |
| -------- | -------- | -------- |
| $r | (key:&nbsp;string)&nbsp;=&gt;&nbsp;string | 获取资源限定下具体的资源内容。例如：$r('strings.hello')。<br/>参数说明：<br/>-&nbsp;key：定义在资源限定文件中的键值，如strings.hello。 |

**res-defaults.json示例：**<br/>

```json
{
    "strings": {        
        "hello": "hello world" 
    }
}
```

## 示例

resources/res-dark.json:

```json
{
    "image": {
        "clockFace": "common/dark_face.png"
    },
    "colors": {
	"background": "#000000"
    }
}
```

resources/res-defaults.json:

```json
{
    "image": {
        "clockFace": "common/face.png"
    },
    "colors": {
	"background": "#ffffff"
    }
}
```

```html
<!-- xxx.hml -->
<div style="background-color: {{ $r('colors.background') }}">
    <image src="{{ $r('image.clockFace') }}"></image>
</div>
```

> **说明：**
> 资源限定文件中不支持颜色枚举格式。
