# Graphics and Image Development

## Why do the isStatusBarLightIcon and isNavigationBarLightIcon attributes not take effect when window.setSystemBarProperties() is called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

In effect, the **isStatusBarLightIcon** and **isNavigationBarLightIcon** attributes turn the font white when set to **true**. If **statusBarContentColor** is also set in **window.setSystemBarProperties()**, the **isStatusBarLightIcon** attribute does not take effect. Similarly, if **navigationBarContentColor** is set, the **isNavigationBarLightIcon** attribute does not take effect.

## How do I set the style of the system bar?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Import the **\@ohos.window** module, and call **window.setSystemBarProperties()**.
