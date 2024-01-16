#  arkui子系统ChangeLog

## cl.arkui.1 尺寸设置constraintSize minWidth接口变更

**访问级别**

公开接口

**变更原因**

在API version 10上使用constraintSize minWidth存在错误，因此需要限制constraintSize minWidth接口生效的API版本范围，使得minWidth在API version 10及以下的SDK中不生效。

**变更影响**

该变更为非兼容变更。

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始。

**flex组件**

变更前：API version 10使用constraintSize minWidth接口正常生效。

变更后：API version 11及更高的版本使用constraintSize minWidth接口正常生效。API version 10及更低的版本中constraintSize minWidth接口不再生效。

**适配指导**

若使用API version 10及以下的SDK时，通过constraintSize minWidth接口约束组件的最小宽度，需要修改代码。当宽度变化时，若当前宽度小于minWidth，则直接设置组件宽度的数值。
从API version 11开始，设置minWidth约束组件的最小宽度正常生效。

## cl.arkui.2 Navigation组件hideNavBar属性生效范围变更

**访问级别**

公开接口

**变更原因**

hideNavBar能力增强，从仅在双栏场景生效，扩展为单、双栏模式下均生效。

**变更影响**

该变更为非兼容性变更。变更前，单栏场景下使用hideNavBar无任何效果，变更后，可能由于未提供可显示页面，从而在生效hideNavBar后隐藏导航栏，产生白屏。

**API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始。

**适配指导**

使用该接口，会隐藏Navigation的导航栏，包括Navigation的标题栏、内容区和工具栏。此时，若路由栈NavPathStack中存在NavDestination页面，则显示栈顶页面，否则显示空白。该接口API11以前，仅对双栏模式生效，其他模式误用该接口无任何效果。API11开始，该接口对单栏、双栏和自适应模式均生效。若因使用该接口产生白屏，可直接去掉该接口或在路由栈中提供需要显示在首页的NavDestination页面。
