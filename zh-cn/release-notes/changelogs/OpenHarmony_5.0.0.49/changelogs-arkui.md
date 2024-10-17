# ArkUI子系统Changelog

## cl.arkui.1 在字节码HAR中通过router.getState()获取的path内容变更

**访问级别**

公开接口

**变更原因**

当开发者使用中间码HAR升级到字节码HAR时，通过router.getState()方法获取的path信息不正确。

**变更影响**

该变更为不兼容变更。

此不兼容变更的前提是：源码HAR或者中间码HAR升级为字节码HAR时产生的不兼容。

不兼容场景示例1：

变更前：

当开发者使用的是源码HAR时使用router.getState()方法获取的是**相对路径**。

![pagePath](figures/pagePath2.PNG)

通过router.getState()方法获取的path信息为"../../../../library/src/main/ets/components/"。

当开发者把源码HAR升级为字节码HAR时，通过router.getState()方法获取的path信息为"/\_\_harDefaultPagePath\_\_"。

![pagePath](figures/pagePath3.PNG)

变更后：

当开发者把源码HAR升级为字节码HAR时使用router.getState()方法获取的是**绝对路径**。

![pagePath](figures/pagePath1.PNG)

通过router.getState()方法获取的path信息为"library/src/main/ets/components/"。

不兼容场景示例2：

变更前：

当开发者使用的是中间码HAR时使用router.getState()方法获取的是**相对路径**。

![pagePath](figures/pagePath.PNG)

通过router.getState()方法获取的path信息为"../../../../ + 哈希值 + library/src/main/ets/components/"。

当开发者把中间码HAR升级为字节码HAR时，通过router.getState()方法获取的path信息为"/\_\_harDefaultPagePath\_\_"。

![pagePath](figures/pagePath3.PNG)

变更后：

当开发者把中间码HAR升级为字节码HAR时使用router.getState()方法获取的是**绝对路径**。

![pagePath](figures/pagePath1.PNG)

通过router.getState()方法获取的path信息为"library/src/main/ets/components/"。

**起始API Level**

API 13

**变更发生版本**

从OpenHarmony SDK 5.0.0.49开始

**变更的接口/组件**

router.getState()

**适配指导**

当开发者在代码中有通过router.getState()使用path值时，需要根据获取到的内容进行整改。


## cl.arkui.2 enabled属性UX样式变更

**访问级别**

公开接口

**变更原因**

Rating组件与Slider组件enabled属性UX样式不符合规范

**变更影响**

该变更为不兼容变更。

Rating组件变更场景：

| 变更前 | 变更后 |
|------ |--------|
|Rating组件设置enable为false时，未叠加40%透明度。</br>![rating_enable](figures/rating_enable.PNG)|Rating组件设置enable为false时，叠加40%透明度。</br>![rating_enable_opacity](figures/rating_enable_opacity.PNG)|

Slider组件变更场景：

| 变更前 | 变更后 |
|------ |--------|
|Slider组件设置enable为false时，未叠加40%透明度。</br>![slider_enable](figures/slider_enable.PNG)|Slider组件设置enable为false时，叠加40%透明度。</br>![slider_enable_opacity](figures/slider_enable_opacity.PNG)|

**起始API Level**

7

**变更发生版本**

从OpenHarmony 5.0.0.49 版本开始。

**变更的接口/组件**

通用属性enabled属性。

**适配指导**

默认行为变更，无需适配。
