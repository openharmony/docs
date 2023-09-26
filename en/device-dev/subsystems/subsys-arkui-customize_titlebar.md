# Custom Window Title Bar Development
## Overview
While OpenHarmony provides default UX styles for window title bars, it allows device vendors to develop custom window title bars to meet specific needs.
## Development Guidelines

### How to Develop
Perform the following steps:
1. In **MaximizeMode** (in **frameworks/core/components/common/layout/constants.h**), define the enums, for example, **MODE_AVOID_SYSTEM_BAR** and **MODE_FULL_FILL**.
    ```cpp
    enum class MaximizeMode : uint32_t {
        MODE_AVOID_SYSTEM_BAR,
        MODE_FULL_FILL,
        MODE_RECOVER,
    };
    ```
2. In **ContainerModalViewFactory::GetView** (in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/container_modal_view_factory.h**), add the creation of the custom window title bar based on the current value of **MaximizeMode**.
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
    >
    > The **ContainerModalViewFactory::GetView** method is a factory method. Below shows the method expanded:
    
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
In the preceding example, vendor enhance creates a custom title bar branch based on the value of **MaximizeMode** (**MaximizeMode::MODE_AVOID_SYSTEM_BAR** or **MaximizeMode::MODE_FULL_FILL**).
    
3. Create a folder in the **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal** directory to store your custom title bar code.
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
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
    The **container_modal_\*** files in the **container_modal** folder contain the code related to the default title bar view. You can add your custom code files in the created folder, **enhance** in this example.

4. Complete build configuration for the new .cpp files in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn**.

When your development of the custom title bar is complete, debug and verify the title bar.
### Debugging and Verification
Before the verification, prepare the following files (which must be stored in the same path):
- **open_maximize.bat**
  
    Below shows the content of this file:
    
    ```shell
    hdc shell mount -o rw,remount /sys_prod
    hdc file send window_manager_config_open.xml sys_prod/etc/window/resources/window_manager_config.xml
    hdc shell reboot
    ```
    
- **window_manager_config_open.xml**
  
    Below shows the content of this file:
    
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
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
    >
    > The **window_manager_config_open.xml** file contains various configuration items. Before the verification, you must change the default value of **MaximizeMode** to the one you have defined, that is, the value obtained by **MaximizeMode maximizeMode = GetWindowManager()->GetWindowMaximizeMode()**. The system loads the corresponding title bar according to the value.

Then, debug the custom title bar as follows:
1. Burn the image that contains the custom title bar code to the device.
2. Run the **open_maximize.bat** script.
3. Run the demo to check whether the title bar works properly.
