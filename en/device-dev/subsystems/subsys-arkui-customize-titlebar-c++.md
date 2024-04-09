# Window Title Bar Customization Development (C++)
## Overview
### Introduction
OpenHarmony has a default UX style for window titles. It also allows you to customize the window titles in your own style to accommodate diverse needs.
### Constraints
A folder for storing the custom title bar code must be placed in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal**. The build configuration must be specified in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn**.
## How to Develop

### Development
To customize the title bar:
1. In the **frameworks/core/components/common/layout/constants.h** file, define the values for **MaximizeMode** – a parameter that specifies the mode for maximizing or minimizing the window. In the following example, **MODE_AVOID_SYSTEM_BAR** and **MODE_FULL_FILL** are the values defined by vendor enhance.
    ```cpp
    enum class MaximizeMode : uint32_t {
        MODE_AVOID_SYSTEM_BAR,
        MODE_FULL_FILL,
        MODE_RECOVER,
    };
    ```
2. In the **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/container_modal_view_factory.h** file, add code to **ContainerModalViewFactory::GetView** for creating a custom window title bar based on the **MaximizeMode** settings.
    > **NOTE**
    >
> **ContainerModalViewFactory::GetView** is a factory method that creates a window title bar based on the **MaximizeMode** settings. It is expanded as follows:
    
    ```cpp
        class ACE_EXPORT ContainerModalViewFactory {
        public:
            static RefPtr<FrameNode> GetView(RefPtr<FrameNode>& content, MaximizeMode mode) {
                if (mode == MaximizeMode::MODE_AVOID_SYSTEM_BAR ||
                    mode == MaximizeMode::MODE_FULL_FILL) {
                    return ContainerModalViewEnhance::Create(content);
                } else {
                    return ContainerModalView::Create(content);
                }
             }
        };
    ```
In the preceding example from vendor enhance, a custom window title bar is created depending on the value of **MaximizeMode** (**MaximizeMode::MODE_AVOID_SYSTEM_BAR** or **MaximizeMode::MODE_FULL_FILL**).
    
3. Create a folder in the **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal** directory to store the custom title bar code.
    > **NOTE**
    >
> The entry to a custom title bar has been completed in steps 1 and 2. This step is to write the specific implementation code.
    >
    > The structure of the **container_modal** folder is as follows:
    ```shell
    ├── container_modal_accessibility_property.cpp
    ├── container_modal_accessibility_property.h
    ├── container_modal_pattern.cpp
    ├── container_modal_pattern.h
    ├── container_modal_view.cpp
    ├── container_modal_view_factory.h
    ├── container_modal_view.h
    └── enhance
        ├── container_modal_pattern_enhance.cpp
        ├── container_modal_pattern_enhance.h
        ├── container_modal_view_enhance.cpp
        └── container_modal_view_enhance.h
```
    The **container_modal_*** file under **container_modal** contains the code related to the default title bar view. You can add your code file in the created folder for the custom title bar. In the preceding example, the **container_modal_*** file under **enhance** is the code file by vendor enhance.
    
4. Complete the build configuration for .cpp files in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn**.

When the development is complete, you can debug and verify the custom title bar.
### Debugging and Verification
Before getting started, prepare the following files in the same directory:
- **open_maximize.bat**, the content of which is as follows:
    ```shell
    hdc shell mount -o rw,remount /sys_prod
    hdc file send window_manager_config_open.xml sys_prod/etc/window/resources/window_manager_config.xml
    hdc shell reboot
    ```
- **window_manager_config_open.xml**, the content of which is as follows:
    ```html
    <?xml version="1.0" encoding="utf-8"?>
        <Configs>
          <decor enable="true"/>
          <modeChangeHotZones>50 50 50</modeChangeHotZones>
          <maxFloatingWidth>1706</maxFloatingWidth>
          <maxFloatingHeight>1000</maxFloatingHeight>
          <minFloatingWidth>398</minFloatingWidth>
          <minFloatingHeight>528</minFloatingHeight>
          <floatingBottomPosY>0</floatingBottomPosY>
          <defaultFloatingWindow>82 121 1068 706</defaultFloatingWindow>
          <defaultWindowMode>102</defaultWindowMode>
          <defaultMaximizeMode>0</defaultMaximizeMode>
          <dragFrameGravity>5</dragFrameGravity>
          <maxUniRenderAppWindowNumber>10</maxUniRenderAppWindowNumber>
          <maxFloatingWindowSize>2880</maxFloatingWindowSize>
          <splitRatios>0.5 0.33 0.67</splitRatios>
          <keyboardAnimation>
            <timing>
              <durationIn>500</durationIn>
              <durationOut>150</durationOut>
              <curve name="cubic">0.2 0.0 0.2 1.0</curve>
            </timing>
          </keyboardAnimation>
          <windowAnimation>
            <timing>
              <duration>200</duration>
              <curve name="cubic">0.0 0.0 0.2 1.0</curve>
            </timing>
            <scale>0.9 0.9</scale>
            <rotation>0 0 1 0</rotation>
            <translate>0 0</translate>
            <opacity>0</opacity>
          </windowAnimation>
          <windowEffect>
            <appWindows>
              <cornerRadius>
                <fullScreen>off</fullScreen>
                <split>off</split>
                <float>defaultCornerRadiusL</float>
              </cornerRadius>
              <shadow>
                <focused>
                  <elevation>0</elevation>
                  <color>#000000</color>
                  <offsetX>0</offsetX>
                  <offsetY>15</offsetY>
                  <alpha>0.4</alpha>
                  <radius>34</radius>
                </focused>
                <unfocused>
                  <elevation>0</elevation>
                  <color>#000000</color>
                  <offsetX>0</offsetX>
                  <offsetY>15</offsetY>
                  <alpha>0.2</alpha>
                  <radius>17</radius>
                </unfocused>
              </shadow>
            </appWindows>
          </windowEffect>
        </Configs>
    ```
    > **NOTE**
    >
    > **window_manager_config_open.xml** contains configuration items. Among them, change the value of **defaultMaximizeMode** to one of the values you define for **MaximizeMode**. The value is the one obtained by **MaximizeMode maximizeMode = GetWindowManager()->GetWindowMaximizeMode()**. The system loads the title bar according to this value.

Now with the prepared files, debug and verify your title bar as follows:
1. Burn the image that contains the title bar code to the target device.
2. Run the **open_maximize.bat** script.
3. Run the demo to examine the effect.
