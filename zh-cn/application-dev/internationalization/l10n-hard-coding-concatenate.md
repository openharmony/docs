# 避免硬编码与拼接

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 使用场景

本地化的关键操作是资源文件的翻译，为提升翻译可行性在开发过程中应避免硬编码与拼接。

例如，下图中将"Rain tomorrow"和"Bring an umbrella"两句直接拼接在一起，造成语句大小写问题。

![information-weather-forecast](figures/information-weather-forecast.png)

## 约束与限制

1. 避免使用硬编码，将需要翻译的字符串提取到资源文件中，与代码分离，然后使用相关的接口加载，具体请参考[提供多语言资源](./l10n-multilingual-resources.md)。

2. 避免字符串直接拼接，若语句存在变化部分（如“打开视频”和“打开浏览器”，变化部分是“视频”和“浏览器”），对应变量应使用占位标识，呈现完整的语句表达。

   资源占位符示例：

   ```ts
   {
     "name": "string1",
     "value": "打开%s"
   }
   ```