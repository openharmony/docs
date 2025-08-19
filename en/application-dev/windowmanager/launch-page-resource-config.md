# Configuring Starting Window Resources
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @xiaochaobu-->
<!--Designer: @tenMiles-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

The configuration of starting window resources is similar to other resource configurations. You can classify the resources and configure them for different scenarios. Normally, this approach is used when you configure the starting window content for dark mode or different device types.

## Configuring the Starting Window for Dark Mode
<!--RP1-->
- The dark and light color mode of the starting window follows the system's color scheme.
<!--RP1End-->

The following uses the background color configuration of the [enhanced starting window](launch-page-config.md#configuring-an-enhanced-starting-window) as an example. In the default UIAbility template, the value of **startWindowBackgroundColor** is **$color:start_window_background**. You can configure the color in the **resources** directory in the following way so that the color setting takes effect for dark mode. The configuration of other fields is the same as that of the background color. You can configure the resources corresponding to the field in the **resources** directory.

1. Modify the color value of **start_window_background** in the **resources/base/element/color.json** file to set the default background color of the starting window in normal mode. Example:

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

2. Modify the color value of **start_window_background** to **#FF000000** in the **resources/dark/element/color.json** file to set the default background color of the starting window in dark mode. Example:

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

## Configuring the Starting Window for Different Devices

Similar to dark mode, you can create resource directories such as **car** and **tablet** in the **resources** directory and configure different starting window content for these devices. For details, see [Creating a Resource Directory and Resource File](.../quick-start/resource-categories-and-access.md#creating-a-resource-directory-and-resource-file).

If no resource file is configured for the starting window field in a specific scenario, the resource file in the **base** directory is used by default.
