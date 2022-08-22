# 图形图像开发常见问题



## 调用window实例的setSystemBarProperties接口时，设置isStatusBarLightIcon和isNavigationBarLightIcon属性不生效 

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

状态栏字体高亮属性的本质就只是让字体变成白色。调用window实例的setSystemBarProperties接口时，如果设置了状态栏内容颜色statusBarContentColor，就以开发者设置的颜色为准，isStatusBarLightIcon状态栏字体高亮属性就不生效；同理，如果设置了导航栏内容颜色navigationBarContentColor，isNavigationBarLightIcon导航栏字体高亮属性就不生效。

## 如何设置系统状态栏样式

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

导入\@ohos.window模块，开发者可以使用window.setSystemBarProperties()接口设置状态栏样式属性，达到自定义样式的效果。
