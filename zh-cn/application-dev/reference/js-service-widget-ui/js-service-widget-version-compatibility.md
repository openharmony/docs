# 低版本兼容


卡片特性不断增加，使用了新特性的卡片，在不支持这些新特性的老系统上可能显示异常。可以在卡片工程中指定最小SDK版本，防止使用新特性的卡片推送安装在老的系统上。也可以参考本章节的内容，在卡片开发阶段做前向兼容适配。


>  **说明：**
> 低版本兼容能力从 API Version 6 开始支持。


开发者可以通过JSON配置文件配置前向兼容能力。该文件提供了apiVersion属性用于兼容版本，该字段和卡片配置文件的数据字段data、事件字段actions同级。在apiVersion标签下定义的内容会基于当前运行版本信息，覆盖原始的data标签内容。


示例如下：


假设JS服务卡片框架从API Version 6开始，支持引用系统内置资源颜色，从API Version 7开始支持slider组件（仅用于举例，不代表实际情况），则可以按照如下的方式，做前向兼容。



```html
<!-- xxx.hml -->
<div style="background-color: {{myBackgroundColor}}">
    <text>hello world</text>
    <slider if="{{canUseSlider}}" min="0" max="100"></slider>
</div>
```


xxx.json配置文件：



```json
{
  "data": {
    "myBackgroundColor": "#87ceeb",
    "canUseSlider": "false"
  },
  "apiVersion": {
    "6": {
      "myBackgroundColor": "@sys.color.fa_background"
    },
    "7": {
      "canUseSlider": "true"
    }
  }
}
```


JS服务卡片开发框架会根据应用中的配置及当前系统运行版本，选取最合适的数据。


假设系统运行版本在5及以下，则实际解析的myBackgroundColor值为\#87ceeb，canUseSlider值为false；


假设系统运行版本为6，则实际解析的myBackgroundColor值为\@sys.color.fa_background，canUseSlider值为false；


假设系统运行版本为7及以上，则实际解析的际解析的myBackgroundColor值为\@sys.color.fa_background，canUseSlider值为true。
