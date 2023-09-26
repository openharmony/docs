# ArkUI Subsystem Changelog

## cl.arkui.1 Value Change of the PanelHeight Enum WRAP_CONTENT from 0 to 'wrapContent'

**Change Impact**

Before the change, both **customHeight(0)** and **customHeight(PanelHeight.WRAP_CONTENT)** configure the component to adapt to the content height.
After the change, **customHeight(0)** sets the content height to **0**, and **customHeight(PanelHeight.WRAP_CONTENT)** configures the component to adapt to the content height.

**Key API/Component Changes**

The value of **WRAP_CONTENT** of the **PanelHeight** enum is changed from **0** to **'wrapContent'**. This API behavior change does not affect your use of the API.

## cl.arkui.2 Change of the Default Value for aspectRatio Set to an Invalid Value or undefined

**Change Impact**

Before the change, if **aspectRatio** is set to a negative value or **undefined**, the default value **1.0** is used.

After the change, if **aspectRatio** is set to a negative value or **undefined**, the default value **null** is used. For example, if a **\<Row>** component has only its width set and does not have any child component, then when **aspectRatio** is not set or is set to a negative value, the height of the **\<Row>** component is 0.

## cl.arkui.3 Change of Effect in Setting defaultFocus to true

**Change Impact**
In versions earlier than 4.0.9.1, setting **defaultFocus** to **true** does not take effect.

In 4.0.9.1 and later versions, setting **defaultFocus** to **true** takes effect.

## cl.arkui.4 Change of Focus Navigation for tabIndex

**Change Impact**
In versions earlier than 4.0.10.2, the focus navigation for **tabIndex** is not cyclic.

In 4.0.10.2 and later versions, the focus navigation for **tabIndex** is cyclic.

## cl.arkui.5 Change of Constraint Calculation for the \<TextInput> Component

**Change Impact**

In versions earlier than 4.0.11.2, when **margin** is set for the **\<TextInput>** component, the value of **margin** is subtracted from the component's constraint.

In versions earlier than 4.0.11.2, the value of **margin** is not subtracted from the **\<TextInput>** component's constraint.
