# Window Manager

## Introduction

The Window Manager subsystem provides basic capabilities of window and display management. It is the basis for UI display. The following figure shows the architecture of the Window Manager subsystem.

**Figure 1** Architecture of the Window Manager subsystem

![WindowManager-subsystem-architecture](./figures/WindowManager.png)

- **Window Manager Client**

    Provides window object abstraction and window management interfaces, and connects to the ability and UI framework.

- **Display Manager Client**

    Provides display information abstraction and display management interfaces.

- **Window Manager Server**

    Provides capabilities such as window layout, Z-order control, window tree structure, window dragging, and window snapshot, and offers the window layout and focus window for multimodal input.

- **Display Manager Server**

    Provides display information, screenshot, screen on/off, and brightness processing control, and processes the mapping between the display and screen.

## Directory Structure

```text
foundation/window/window_manager/
├── dm                      # Stores Display Manager Client implementation code
├── dmserver                # Stores Display Manager Server implementation code
├── interfaces              # Stores external APIs
│   ├── innerkits           # Stores native APIs
│   └── kits                # Stores JS APIs and native APIs
├── resources               # Stores resource files used by the framework
├── sa_profile              # Stores system service configuration files
├── snapshot                # Stores implementation code of the screenshot command line tool
├── utils                   # Stores tools
├── wm                      # Stores Window Manager Client implementation code
├── wmserver                # Stores Window Manager Server implementation code
```

## Constraints

- Programming language version
  - C++ 11 or later

## Available APIs

- [Window](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-window.md)
- [Display](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-display.md)

## Repositories Involved

- [graphic_graphic_2d](https://gitee.com/openharmony/graphic_graphic_2d)
- [arkui_ace_engine](https://gitee.com/openharmony/arkui_ace_engine)
- [ability_ability_runtime](https://gitee.com/openharmony/ability_ability_runtime)
- [multimodalinput_input](https://gitee.com/openharmony/multimodalinput_input)
