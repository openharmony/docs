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

## cl.arkui.2 setSpecificSystemBarEnabled接口在横屏的行为变更

**访问级别**

公开接口

**变更原因**

该接口当前的实现存在规格缺失，导致应用无法在横屏时设置状态栏显示

**变更影响**

该变更为不兼容变更。

不兼容场景示例1：

应用预期：横屏时隐藏状态栏

变更前：

应用使用该接口设置了状态栏显示，横屏后没有再次调用该接口设置状态栏隐藏，此时状态栏仍然为隐藏状态。

变更后：

应用使用该接口设置了状态栏显示，横屏后没有再次调用该接口设置状态栏隐藏，此时状态栏将变为显示状态。

**起始API Level**

API 14

**变更发生版本**

从OpenHarmony SDK 5.0.0.49开始

**变更的接口/组件**

Window#setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean, enableAnimation?: boolean): Promise<void>

**适配指导**

应用如果设置过状态栏显示，并且预期在横屏时隐藏状态栏，则需要监听横竖屏变化事件，并在横屏时使用该接口设置状态栏隐藏。