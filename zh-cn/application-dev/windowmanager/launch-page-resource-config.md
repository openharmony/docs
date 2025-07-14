# 启动页资源分类配置

启动页资源配置与其他资源配置相同，支持资源分类配置，可针对不同的场景配置不同资源，常用于在深色模式或不同设备类型上配置不同的启动页内容。

## 配置深色模式启动页

以[配置增强启动页](launch-page-config.md#配置增强启动页)的背景色为例：startWindowBackgroundColor字段值为"$color:start_window_background"，按如下方式在resources目录下分别配置字段值对应的颜色值，即可对深色模式生效。其他字段配置方式与背景色相同，在resources目录中配置其字段值对应的资源即可。

1. 修改resources/base/element/color.json中，对应配置项start_window_background的颜色值，对应一般情况下的默认启动页背景色，示例如下：

   ```json
   {
     "color": [
       {
         "name": "start_window_background",
         "value": "#FFFFFFFF"
       }
     ]
   }
   ```

2. 修改resources/dark/element/color.json中，对应配置项start_window_background的颜色值，对应深色模式下的默认启动页背景色，示例如下：

   ```json
   {
     "color": [
       {
         "name": "start_window_background",
         "value": "#FF000000"
       }
     ]
   }
   ```

## 配置不同设备启动页

与深色模式类似，通过在resources目录新建car、tablet等资源目录，配置上述字段对应的资源，则可在对应设备上配置显示不同的启动页内容，参考[创建资源目录和资源文件](../quick-start/resource-categories-and-access.md#创建资源目录和资源文件)。

如未针对特定场景的启动页字段配置资源文件，则该场景下默认以base目录中的对应资源文件为准。
