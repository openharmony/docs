# 窗口标题栏定制开发指导（ArkTS）

## 概述

### 功能简介

窗口标题栏是图形用户界面中的一个重要元素，它位于窗口的顶部，通常包含了窗口的标题以及一些控制按钮。标题栏的主要作用是提供关于窗口的基本信息，同时也为用户提供了一些控制选项。OpenHarmony有默认的窗口标题栏样式，本文基于ArkTS语言，提供窗口标题栏自定义方法。

### 约束与限制

需要在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces`路径下加入有自定义标题栏代码的js文件。并且在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces/BUILD.gn`中配置js文件编译成abc文件，最后在`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn`完成编译配置。

## 开发步骤

以默认的系统标题栏为例，定制窗口标题栏的开发步骤如下：

1. 使用ArkTS语言编写定制的窗口标题栏。
    ```ts
    import image from '@ohos.multimedia.image';

    const TITLE_ICON_SIZE: string = '20vp'
    const TITLE_PADDING_START: string = '20vp'
    const TITLE_ELEMENT_MARGIN_HORIZONTAL: string = '12vp'
    const TITLE_TEXT_FONT_SIZE: string = '16fp'
    const TITLE_TEXT_FONT_WEIGHT: string = '500px'
    const TITLE_ROW_HEIGHT: string = '37vp'

    @Entry
    @Component
    struct Index {
      @State appLabel: string = '';
      @State appLabelColor: Color = 0xff000000;
      @State appIcon: PixelMap | undefined = undefined;

      // 1、重写失焦和获焦函数，用于改变字体颜色
      onWindowFocused() {
        this.appLabelColor = 0xff000000;
      }

      onWindowUnfocused() {
        this.appLabelColor = 0x66000000;
      }

      // 2、重写标题栏设置应用图标和名称的方法
      setAppTitle(content: string ) {
        this.appLabel = content;
      }

      setAppIcon(pixelMap: image.PixelMap) {
        this.appIcon = pixelMap;
      }

      build() {
        Row() {
          // 3、Image组件用于显示应用图标
          Image(this.appIcon)
            .id("enhanceAppIcon")
            .height(TITLE_ICON_SIZE)
            .width(TITLE_ICON_SIZE)
            .interpolation(ImageInterpolation.Medium)
            .focusable(false)
            .margin({ left: TITLE_PADDING_START, right: TITLE_ELEMENT_MARGIN_HORIZONTAL })
          // 4、Text组件用于显示应用名称
          Text(this.appLabel)
            .id("enhanceAppLabel")
            .fontSize(TITLE_TEXT_FONT_SIZE)
            .fontColor(this.appLabelColor)
            .fontWeight(TITLE_TEXT_FONT_WEIGHT)
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .textAlign(TextAlign.Start)
            .layoutWeight(1.0)
          }
          .width('100%')
          .height(TITLE_ROW_HEIGHT)
          .justifyContent(FlexAlign.Start)
          .alignItems(VerticalAlign.Center)
          .padding({ top: 6, bottom: 6 })
      }
    }
    ```
2. 将ets文件编译成js文件。
    ```js
    const TITLE_ICON_SIZE = '20vp';
    const TITLE_PADDING_START = '20vp';
    const TITLE_ELEMENT_MARGIN_HORIZONTAL = '12vp';
    const TITLE_TEXT_FONT_SIZE = '16fp';
    const TITLE_TEXT_FONT_WEIGHT = '500px';
    const TITLE_ROW_HEIGHT = '37vp'
    export class Index extends ViewPU {
        constructor(parent, params, __localStorage, elmtId = -1) {
            super(parent, __localStorage, elmtId);
            this.__appLabel = new ObservedPropertySimplePU('', this, "appLabel");
            this.__textColor = new ObservedPropertySimplePU(0xff000000, this, "textColor");
            this.__pixelMap = new ObservedPropertyObjectPU(undefined, this, "appIcon");
            this.setInitiallyProvidedValue(params);
        }
        setInitiallyProvidedValue(params) {
            if (params.textColor !== undefined) {
                this.textColor = params.textColor;
            }
            if (params.appLabel !== undefined) {
                this.appLabel = params.appLabel;
            }
            if (params.appIcon !== undefined) {
                this.appIcon = params.appIcon;
            }
        }
        updateStateVars(params) {
        }
        purgeVariableDependenciesOnElmtId(rmElmtId) {
            this.__textColor.purgeDependencyOnElmtId(rmElmtId);
            this.__appLabel.purgeDependencyOnElmtId(rmElmtId);
            this.__appIcon.purgeDependencyOnElmtId(rmElmtId);
        }
        aboutToBeDeleted() {
            this.__textColor.aboutToBeDeleted();
            this.__appLabel.aboutToBeDeleted();
            this.__appIcon.aboutToBeDeleted();
            SubscriberManager.Get().delete(this.id__());
            this.aboutToBeDeletedInternal();
        }
        get textColor() {
            return this.__textColor.get();
        }
        set textColor(newValue) {
            this.__textColor.set(newValue);
        }
        get appLabel() {
            return this.__appLabel.get();
        }
        set appLabel(newValue) {
            this.__appLabel.set(newValue);
        }
        get appIcon() {
            return this.__appIcon.get();
        }
        set appIcon(newValue) {
            this.__appIcon.set(newValue);
        }
        onWindowFocused() {
            this.textColor = 0xff000000;
        }
        onWindowUnfocused() {
            this.textColor = 0x66000000;
        }
        setAppTitle(content) {
            this.appLabel = content;
        }
        setAppIcon(pixelMap) {
            this.appIcon = pixelMap;
        }
        initialRender() {
            this.observeComponentCreation((elmtId, isInitialRender) => {
                ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
                Row.create();
                Row.width('100%');
                Row.height(TITLE_ROW_HEIGHT);
                Row.justifyContent(FlexAlign.Start);
                Row.alignItems(VerticalAlign.Center);
                Row.padding({ top: 6, bottom: 6 });
                if (!isInitialRender) {
                    Row.pop();
                }
                ViewStackProcessor.StopGetAccessRecording();
            });
            this.observeComponentCreation((elmtId, isInitialRender) => {
                ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
                Image.create(this.appIcon);
                Image.id("enhanceAppIcon");
                Image.height(TITLE_ICON_SIZE);
                Image.width(TITLE_ICON_SIZE);
                Image.interpolation(ImageInterpolation.Medium);
                Image.focusable(false);
                Image.margin({ left: TITLE_PADDING_START, right: TITLE_ELEMENT_MARGIN_HORIZONTAL });
                if (!isInitialRender) {
                    Image.pop();
                }
                ViewStackProcessor.StopGetAccessRecording();
            });
            this.observeComponentCreation((elmtId, isInitialRender) => {
                ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
                Text.create(this.appLabel);
                Image.id("enhanceAppLabel");
                Text.maxLines(1);
                Text.fontSize(TITLE_TEXT_FONT_SIZE);
                Text.fontColor(this.textColor);
                Text.fontWeight(TITLE_TEXT_FONT_WEIGHT);
                Text.textOverflow({ overflow: TextOverflow.Ellipsis });
                Text.textAlign(TextAlign.Start);
                Text.layoutWeight(1.0);
                if (!isInitialRender) {
                    Text.pop();
                }
                ViewStackProcessor.StopGetAccessRecording();
            });
            Text.pop();
            Row.pop();
        }
        rerender() {
            this.updateDirtyElements();
        }
    }
    ViewStackProcessor.StartGetAccessRecordingFor(ViewStackProcessor.AllocateNewElmetIdForNextComponent());
    // loadDocument方法需要更改为loadCustomTitleBar
    loadCustomTitleBar(new Index(undefined, {}));
    ViewStackProcessor.StopGetAccessRecording();
    ```
    - DevEco Studio编译生成的js文件或ts文件一般在工程的如下目录下：build/default/cache/default/default@CompileArkTS/esmodule/debug/entry/src/main/ets/pages/。
    - 处理ts文件，使其符合js语法规范。
    - js文件中的loadDocument或registerNameRouter方法需要更改使用loadCustomTitleBar方法。
        ```js
        loadCustomTitleBar(new Index(undefined, {}));
        ```

3. 通过BUILD.gn文件将处理后的js文件加入系统编译依赖，进一步生成.abc文件。
    ```
    import("//arkcompiler/ets_frontend/es2panda/es2abc_config.gni")

    es2abc_gen_abc("gen_customtitle_abc") {
    src_js = rebase_path("customtitle.js")
    dst_file = rebase_path(target_out_dir + "/customtitle.abc")
    in_puts = [ "customtitle.js" ]
    out_puts = [ target_out_dir + "/customtitle.abc" ]
    extra_args = [ "--module" ]
    }
    ```
   将上述gen_customtitle_abc加入到`foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn`文件的编译依赖中。编译后生成的.abc文件在`obj/foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces`目录下。
   
   具体可参考如下路径下的实现：[foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces](https://gitee.com/openharmony/arkui_ace_engine/tree/master/frameworks/core/components_ng/pattern/container_modal/interfaces)。


4. 将.abc文件配置到系统中的指定目录，如/system/lib64/，然后命令行设置配置参数"persist.sys.arkui.customtitle"的值为.abc文件的路径，就可以读取并显示自定义的标题栏。

    ```
    hdc shell param set persist.sys.arkui.customtitle /system/lib64/customtitle.abc
    ```
