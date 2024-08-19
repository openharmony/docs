# Globalization Changelog

## cl.global.1 Change of the Default Behavior in Dark Color Mode

**Access Level**

Other

**Reason for Change**

Many applications have not adapted to the dark color mode. To ensure user experience in dark color mode, the system adds a judgment rule as follows: If an application does not have dark color resources and does not call **setColorMode** to specify the color mode, the built-in components of the system do not invert colors.

**Change Impact**

This change is a non-compatible change. If an application does not have dark color resources and does not call **setColorMode** to specify the color mode, the built-in components of the system do not invert colors.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.26

**Key API/Component Changes**

Before change: The built-in components of the system automatically switch between dark and light colors based on the color mode setting of the application.

After change: The built-in components of the system switch between dark and light colors only when the application has dark color resources or **setColorMode** is used to configure the application to follow the color mode setting of the system.

**Adaptation Guide**

If all your application is developed using system controls or system colors and you want to switch to the dark or light color mode with the system, modify your code as shown below to ensure user experience.

```typescript
onCreate(): void {
  this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
}
```
