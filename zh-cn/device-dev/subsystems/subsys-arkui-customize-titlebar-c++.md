# 窗口标题栏定制开发指导（C++）
## 概述
### 功能简介
OpenHarmony有一套默认的窗口标题UX样式，但是不同的厂商的不同设备对于窗口有不同的UX样式的诉求，所以为了满足厂商自定义的需求，提供窗口标题栏自定义机制。
### 约束与限制
厂商需要在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal`路径下创建自己的文件夹，放置自定义标题栏代码。并且在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn`完成编译配置。
## 开发指导

### 开发步骤
厂商自定义窗口标题栏分四个步骤：
1. 在MaximizeMode（`frameworks/core/components/common/layout/constants.h`）中定义自己的最大最小化窗口的枚举值。例如MODE_AVOID_SYSTEM_BAR、MODE_FULL_FILL是enhance厂商定义的最大最小化窗口模式。<br>
    ```cpp
    enum class MaximizeMode : uint32_t {
        MODE_AVOID_SYSTEM_BAR,
        MODE_FULL_FILL,
        MODE_RECOVER,
    };
    ```
2. 在ContainerModalViewFactory::GetView（`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/container_modal_view_factory.h`）中根据当前最大最小化窗口模式，添加自定义窗口标题栏的创建。<br>
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
    > 窗口标题栏是工厂方法根据当前最大最小化窗口模式，创建相应的窗口标题栏。展开ContainerModalViewFactory::GetView方法：

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
    厂商enhance已经根据自定义的最大最小化窗口模式（MaximizeMode::MODE_AVOID_SYSTEM_BAR和MaximizeMode::MODE_FULL_FILL），创建了新的自定义标题栏分支。

3. `foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal`路径下创建自己的文件夹，放置自定义标题栏代码。
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
    > 自定义标题栏的创建入口已经在1、2中完成，接下来就是编写自定义窗口标题栏View的具体实现代码。
container_modal的文件夹结构如下：
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
    其中container_modal文件夹下的container_modal_*文件表示OpenHarmony默认的标题栏View相关代码。厂商可以在container_modal文件夹下添加自定义文件夹，包含自定义窗口标题栏代码。例如：enhance文件夹下的container_modal_*文件是enhance厂商自定义的标题栏View代码。

4. 新增cpp文件在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn`完成编译配置。

完成自定义窗口标题栏开发，即可以调试验证。
### 调试验证
在验证之前要先准备好两个文件（注：两个文件需要放在同一路径下）:
- open_maximize.bat，文件内容：
    ```shell
    hdc shell mount -o rw,remount /sys_prod
    hdc file send window_manager_config_open.xml sys_prod/etc/window/resources/window_manager_config.xml
    hdc shell reboot
    ```
- window_manager_config_open.xml，文件内容：
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
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
    > window_manager_config_open.xml具体内容是各种配置项，测试前，需要修改一下默认的最大最小窗口模式，可以修改为厂商定义的值。这个值对应的就是`MaximizeMode maximizeMode = GetWindowManager()->GetWindowMaximizeMode()`获取到的值，系统通过这个值来选择加载相应的标题栏。

完成以上准备工作，分三步完成测试：
1. 包含标题栏修改代码的镜像烧录到设备。
2. 执行脚本open_maximize.bat。
3. 运行demo即可查看修改效果。