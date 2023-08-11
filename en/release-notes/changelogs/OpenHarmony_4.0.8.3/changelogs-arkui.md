# ArkUI Subsystem Changelog

## cl.arkui.1 Disabling of Online Images for JS Widgets in \<FormComponent>

Disabled online images for JS widgets in the **\<FormComponent>**.

**Change Impact**

After the change, JS widgets in the **\<FormComponent>** cannot load or display online images. You are advised to save online images to the memory to display them in JS widgets.
## cl.arkui.2 Behavior Change of \<TextInput>, \<TextArea>, and \<Search> Components
Changed the behavior of **\<TextInput>**, **\<TextArea>**, and **\<Search>** components so that their obtaining focus will enable the input method.

You need to adapt your application based on the following information.


**Change Impact**

The **\<TextInput>**, **\<TextArea>**, and **\<Search>** components of API version 10 are affected.

**Key API/Component Changes**

When the **\<TextInput>**, **\<TextArea>**, and **\<Search>** components obtain focus, the input method is displayed.

**Adaptation Guide**  

Use **enableKeyboardOnFocus(bool)** to set whether to enable the input method when the component obtains focus. The default value of this parameter is **true**.

## cl.arkui.3 Intercepting of Invalid Component Attribute and Parameter Values 


Changed invalid values to default values.

You need to adapt your application based on the following information.


**Change Impact**

All component attributes and parameters with invalid values are affected.

**Key API/Component Changes**

When an attribute value is changed from a normal value to an invalid value:

- Before change: The invalid value setting is skipped.

- After change: The invalid value is intercepted and the default value is used. For attributes that do not have default values, such as **width** and **height**, the original normal value settings are canceled.

**Adaptation Guide**


Check for Invalid values of component attributes and parameters, such as **"100abc"**, and change them to normal values.
        
