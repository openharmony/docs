# Creating an ArkTS Widget

You can create a widget in either of the following modes:

- When creating a project, select **Application**, and then right-click a module folder and choose **New** > **Service Widget** to create a widget.
- When creating a project, select **Atomic Service**, and then right-click a module folder and choose **New** > **Service Widget** to create a widget.

![WidgetCreateProject](figures/WidgetCreateProject.png)

> **NOTE**
>
> The UI may be different in DevEco Studio of a different version.

To create an ArkTS widget in an existing project, perform the following steps:

1. Right-click a module folder and choose **New** > **Service Widget**.
   ![WidgetProjectCreate1](figures/WidgetProjectCreate1.png)
> **NOTE**
>
> For a project developed using API version 10 or later based on the stage model, you can create a dynamic or static widget from the **Service Widget** menu. You can also change the widget type by setting the **isDynamic** parameter in the [form_config.json file](arkts-ui-widget-configuration.md) of the widget. If **isDynamic** is left unspecified or set to **true**, the widget is a [dynamic widget](./arkts-ui-widget-configuration.md#isdynamic-field). If **isDynamic** is set to **false**, the widget is a [static widget](./arkts-ui-widget-configuration.md#isdynamic-field).
   
2. Select a widget template based on the actual service scenario.
   
   ![WidgetProjectCreate2](figures/WidgetProjectCreate2.png)

3. Set **Language** to **ArkTS** and click **Finish**.

   ![WidgetProjectCreate3](figures/WidgetProjectCreate3.png)
   
   You are advised to name the widget based on the actual scenario. After an ArkTS widget is created, the following widget-related files are automatically added to the project directory: **EntryFormAbility.ets** (widget lifecycle management file), **WidgetCard.ets** (widget page file), and **form_config.json** (widget configuration file).

   ![WidgetProjectView](figures/WidgetProjectView.png)
