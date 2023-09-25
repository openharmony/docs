# ArkUI Subsystem Changelog

## cl.arkui.1 Change in Processing for When scrollBar of the \<List> Component Is Set to undefined or an Invalid Value

**Change Impact**

In versions earlier than OpenHarmony_4.0.10.1, the following values evaluate to **BarState.Off**: **scrollBar(undefined)**, **scrollBar('aaa')**, **scrollBar(-1)**.

In OpenHarmony_4.0.10.2 and later versions, the preceding values evaluate to the default value **BarState.Auto**.

**Key API/Component Changes**

The processing of the **\<List>** component's **scrollBar** attribute, when it is set to **undefined** or an invalid value, is changed from using **BarState.Off** to using **BarState.Auto**.

## cl.arkui.2 Change in Processing for When scrollBar of the \<Grid> Component Is Set to undefined or an Invalid Value

**Change Impact**

In versions earlier than OpenHarmony_4.0.10.1, the following values evaluate to the default value **BarState.Off**: **scrollBar(undefined)**, **scrollBar('aaa')**, **scrollBar(-1)**.

In OpenHarmony_4.0.10.2 and later versions, the preceding values evaluate to **BarState.Auto**.

**Key API/Component Changes**

The processing of the **\<Grid>** component's **scrollBar** attribute, when it is set to **undefined** or an invalid value, is changed from using **BarState.Off** to using **BarState.Auto**.
