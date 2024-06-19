# 窗口子系统变更说明

## cl.window.1 Orientation枚举值LANDSCAPE/LANDSCAPE_INVERTED/AUTO_ROTATION_LANDSCAPE/AUTO_ROTATION_LANDSCAPE_RESTRICTED/USER_ROTATION_LANDSCAPE/USER_ROTATION_LANDSCAPE_INVERTED设置横屏行为变更

**访问级别**

公开接口

**变更原因**

应用通过配置在module.json中ability标签"orientation"或setPreferredOrientation接口设置横屏时，习惯性使用LANDSCAPE，此时会旋转到电源键在手机下方，与业界通用逻辑相反，不符合用户使用习惯，影响使用手机体验。

**变更影响**

该变更为非兼容性变更。
此变更从OpenHarmony SDK 5.0.0.25，API 12以后开始生效，API 12之前的应用保持原状。开始更改后应用通过配置在module.json中ability标签"orientation"或setPreferredOrientation接口设置LANDSCAPE/LANDSCAPE_INVERTED/AUTO_ROTATION_LANDSCAPE/AUTO_ROTATION_LANDSCAPE_RESTRICTED/USER_ROTATION_LANDSCAPE/USER_ROTATION_LANDSCAPE_INVERTED横屏时，旋转方向会给用户带来与更改前相反的体验效果。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.25开始。

**变更的接口/组件**

变更前，应用通过配置在module.json中ability标签"orientation"或setPreferredOrientation接口设置LANDSCAPE/AUTO_ROTATION_LANDSCAPE/AUTO_ROTATION_LANDSCAPE_RESTRICTED/USER_ROTATION_LANDSCAPE时，会旋转到电源键在手机下方，设置LANDSCAPE_INVERTED/USER_ROTATION_LANDSCAPE_INVERTED时，会旋转到电源键在手机上方。
变更后，应用通过配置在module.json中ability标签"orientation"或setPreferredOrientation接口设置LANDSCAPE/AUTO_ROTATION_LANDSCAPE/AUTO_ROTATION_LANDSCAPE_RESTRICTED/USER_ROTATION_LANDSCAPE时，会旋转到电源键在手机上方，设置LANDSCAPE_INVERTED/USER_ROTATION_LANDSCAPE_INVERTED时，会旋转到电源键在手机下方。

横屏效果对照表：
|Orientation值| 变更前          | 变更后   | 
|-------| -------- | --------------- | 
|LANDSCAPE|  电源键向下    |  电源键向上   |
|LANDSCAPE_INVERTED|  电源键向上    |  电源键向下  | 
|AUTO_ROTATION_LANDSCAPE|  电源键向下    |  电源键向上 | 
|AUTO_ROTATION_LANDSCAPE_RESTRICTED|  电源键向下    |  电源键向上   | 
|USER_ROTATION_LANDSCAPE   |  电源键向下   | 电源键向上   | 
|USER_ROTATION_LANDSCAPE_INVERTED|  电源键向上  |  电源键向下   | 

**适配指导**

更改前如果传入LANDSCAPE参数，更改后为保持相同的体验效果，需传入LANDSCAPE_INVERTED参数；更改前如果传入LANDSCAPE_INVERTED参数，更改后为保持相同的体验效果，需传入LANDSCAPE参数。更改前如果传入USER_ROTATION_LANDSCAPE参数，更改后为保持相同的体验效果，需传入USER_ROTATION_LANDSCAPE_INVERTED参数；更改前如果传入USER_ROTATION_LANDSCAPE_INVERTED参数，更改后为保持相同的体验效果，需传入USER_ROTATION_LANDSCAPE参数。

当手机电源键在右侧时，更改前如果传入LANDSCAPE参数，旋转后通过监听display.on('change')来获取display的orientation为1，更改后通过监听display.on('change')来获取display的orientation为3；更改前如果传入LANDSCAPE_INVERTED参数，旋转后通过监听display.on('change')来获取display的orientation为3，更改后通过监听display.on('change')来获取display的orientation为1；
当手机电源键在左侧时，更改后横屏旋转通过监听display.on('change')来获取display的orientation值与更改前保持一致。