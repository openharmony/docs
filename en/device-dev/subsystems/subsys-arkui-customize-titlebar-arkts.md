# Window Title Bar Customization Development (ArkTS)

## Overview

### Introduction

As a crucial element of the GUI, the window title bar is located at the top of a window. It is intended to help users identify the purpose or content of the window, complete with some handy control options. OpenHarmony provides a default window title bar. You can customize it to match your needs. This topic provides guidance on customizing your title bar in ArkTS.

### Constraints

The .js files that contain the custom title bar code must be placed in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces**.

The JS files must be built into ABC files with the **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces/BUILD.gn** file.

The build configuration must be specified in **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn**.

## How to Develop

In this example, a custom system title bar is developed.

1. Write the following code in an .ets file.
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

      // 1. Override the following methods to change the font color when the window obtains or loses focus.
      onWindowFocused() {
        this.appLabelColor = 0xff000000;
      }

      onWindowUnfocused() {
        this.appLabelColor = 0x66000000;
      }

      // 2. Override the following methods for setting the application icon and name on the title bar.
      setAppTitle(content: string ) {
        this.appLabel = content;
      }

      setAppIcon(pixelMap: image.PixelMap) {
        this.appIcon = pixelMap;
      }

      build() {
        Row() {
          // 3. Create an <Image> component for showing the application icon.
          Image(this.appIcon)
            .id("enhanceAppIcon")
            .height(TITLE_ICON_SIZE)
            .width(TITLE_ICON_SIZE)
            .interpolation(ImageInterpolation.Medium)
            .focusable(false)
            .margin({ left: TITLE_PADDING_START, right: TITLE_ELEMENT_MARGIN_HORIZONTAL })
          // 4. Create a <Text> component for showing the application name.
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
2. Compile the .ets file into a .js file.
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
    // The loadDocument method needs to be changed to loadCustomTitleBar.
    loadCustomTitleBar(new Index(undefined, {}));
    ViewStackProcessor.StopGetAccessRecording();
    ```
    - In general cases, the .js or .ts (.ets) files generated in DevEco Studio are stored in the **build/default/cache/default/default@CompileArkTS/esmodule/debug/entry/src/main/ets/pages/** directory of the project.
    - Process the .ets file so that it complies with the JS syntax specifications.
    - The **loadDocument** or **registerNameRouter** method in the .js file must be be changed to **loadCustomTitleBar**.
        ```js
        loadCustomTitleBar(new Index(undefined, {}));
        ```

3. Use the **BUILD.gn** file to add the .js file as a system build dependency to generate an .abc file.
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
   Add **gen_customtitle_abc** to the build dependencies in the **foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/BUILD.gn** file. The .abc file generated after compilation is stored in the **obj/foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces** directory.
   
   For details, see the implementation in [foundation/arkui/ace_engine/frameworks/core/components_ng/pattern/container_modal/interfaces](https://gitee.com/openharmony/arkui_ace_engine/tree/master/frameworks/core/components_ng/pattern/container_modal/interfaces).


4. Add the .abc file to a specific directory in the system, for example, **/system/lib64/**, and run the following command to set **persist.sys.arkui.customtitle** to the path of the .abc file so that the custom title bar can be read and displayed properly.

    ```
    hdc shell param set persist.sys.arkui.customtitle /system/lib64/customtitle.abc
    ```
