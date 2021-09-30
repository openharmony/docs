# 自定义字体样式<a name="ZH-CN_TOPIC_0000001163812210"></a>

-   [定义font-face](#zh-cn_topic_0000001173324599_section185107316712)
-   [使用font-face](#zh-cn_topic_0000001173324599_section713052011710)

font-face用于定义字体样式。应用可以在style中定义font-face来指定相应的字体名和字体资源，然后在font-family样式中引用该字体。

自定义字体可以是从项目中的字体文件中加载的字体。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>字体格式支持ttf和otf。

## 定义font-face<a name="zh-cn_topic_0000001173324599_section185107316712"></a>

```
@font-face {   
  font-family: HWfont; 
  src: url('/common/HWfont.ttf'); 
}
```

**font-family：**

自定义字体的名称。

**src：**

自定义字体的来源，支持如下类别：

-   项目中的字体文件：通过url指定项目中的字体文件路径\(只支持绝对路径，详见[资源和文件访问规则](../js-framework-file.md#zh-cn_topic_0000001127125012_section6620355202117)章节\)。

-   不支持设置多个src。

## 使用font-face<a name="zh-cn_topic_0000001173324599_section713052011710"></a>

可以在style中定义font-face，然后在font-family样式中指定该font-face的名称，从而应用font-face定义的字体。

**示例：**

页面布局：

```
<div>    
  <text class="demo-text">测试自定义字体</text>  
</div>
```

页面样式：

```
@font-face {
  font-family: HWfont;
  src: url("/common/HWfont.ttf");
}
.demo-text {
  font-family: HWfont;
}
```

