# 环境变量

Environment是框架在应用程序启动时创建的单例对象，它为AppStorage提供了一系列应用程序需要的环境状态属性，这些属性描述了应用程序运行的设备环境。Environment及其属性是不可变的，所有属性值类型均为简单类型。如下示例展示了从Environment获取语音环境：


```
Environment.EnvProp("accessibilityEnabled", "default");
var enable = AppStorage.Get("accessibilityEnabled");
```

accessibilityEnabled是Environment提供默认系统变量识别符。首先需要将对应系统属性绑定到AppStorage中，再通过AppStorage中的方法或者装饰器访问对应系统的属性数据。


## Environment接口

| key | 参数 | 返回值 | 说明 | 
| -------- | -------- | -------- | -------- |
| EnvProp | key:&nbsp;string,<br/>defaultValue:&nbsp;any | boolean | 关联此系统项到AppStorage中，建议在app启动时使用此接口。如果该属性在AppStorage已存在，返回false。请勿使用AppStorage中的变量，在调用此方法关联环境变量。 | 
| EnvProps | keys:&nbsp;{<br/>key:&nbsp;string,<br/>defaultValue:&nbsp;any<br/>}[] | void | 关联此系统项数组到AppStorage中。 | 
| Keys | Array&lt;string&gt; | number | 返回关联的系统项。 | 


## Environment内置的环境变量

| key | 类型 | 说明 | 
| -------- | -------- | -------- |
| accessibilityEnabled | boolean | 无障碍屏幕朗读是否启用。 | 
| colorMode | ColorMode | 深浅色模式，可选值为：<br/>-&nbsp;ColorMode.LIGHT：浅色模式；<br/>-&nbsp;ColorMode.DARK：深色模式。 | 
| fontScale | number | 字体大小比例，取值范围为[0.85,&nbsp;1.45]。 | 
| fontWeightScale | number | 字体权重比例，取值范围为[0.6,&nbsp;1.6]。 | 
| layoutDirection | LayoutDirection | 布局方向类型，可选值为：<br/>-&nbsp;LayoutDirection.LTR：从左到右；<br/>-&nbsp;LayoutDirection.RTL：从右到左。 | 
| languageCode | string | 设置当前系统的语言，小写字母，例如zh。 | 
