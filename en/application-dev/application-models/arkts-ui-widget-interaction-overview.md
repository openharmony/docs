# Widget Data Interaction


The ArkTS widget framework provides the **updateForm()** and **requestForm()** APIs to proactively trigger widget updates.


![WidgetLocalStorageProp](figures/WidgetLocalStorageProp.png)


| API| System Capability| Constraints|
| -------- | -------- | -------- |
| updateForm | No| 1. Invoked by the provider.<br>2. Allows only the widget provider to update its own widgets. It cannot be used to update widgets by other providers.|
| requestForm | Yes| 1. Invoked by the host.<br>2. Allows only the widget host to update the widgets added to it. It cannot be used to update widgets added to other hosts.|

The following describes the typical use cases of widget updates:

- [Configuring a Widget to Update Periodically](arkts-ui-widget-update-by-time.md)
- [Updating Local and Online Images](arkts-ui-widget-image-update.md)
- [Updating Widget Content by State](arkts-ui-widget-update-by-status.md)
- [Updating Widget Content by Widget Host (for System Applications Only)](arkts-ui-widget-content-update.md)
