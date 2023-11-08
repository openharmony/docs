# ArkUI Subsystem Changelog

## cl.arkui.1 Change in Handling Rules on Negative Values of fontSize for Buttons

**Change Impact**

Before change, a negative value of **fontSize** evaluates to **0**. That is, the text is not displayed.

After change, a negative value of **fontSize** evaluates to the default value **16fp**.

Note: This change does not affect the effect of **fontSize=0**.

## cl.arkui.2 Change in the Search Text Box for When the Attributes of the \<Search> Component Are Dynamically Changed

**Change Impact**

Before change, when **placeholder**, but not **value**, is set for the **\<Search>** component, dynamically changing the component attributes will clear the search text box.

After change, when **placeholder**, but not **value**, is set for the **\<Search>** component, dynamically changing the component attributes will not clear the search text box.

Note: After change, the behavior of the **\<Search>** component is what is expected of the component in normal cases.

## cl.arkui.3 Change in the Width Specification of the \<Menu> Component

Changed the width specification of the [\<Menu>](../../../application-dev/reference/arkui-ts/ts-basic-components-menu.md) component as follows: If the width is not set, the component takes up two columns. If the width is set, the component adapts its content to the set width. 

The **\<Menu>** component has a default minimum width of 64 vp.

**Change Impact**

1. By default, the menu takes up two columns. If the content of the [\<MenuItem>](../../../application-dev/reference/arkui-ts/ts-basic-components-menuitem.md) is wider than 2 columns, the menu width is automatically extended.
2. The default minimum width of the menu is 64 vp. You can change the minimum width through the [constraintSize](../../../application-dev/reference/arkui-ts/ts-universal-attributes-size.md) attribute.

**Key API/Component Changes**

[Menu](../../../application-dev/reference/arkui-ts/ts-basic-components-menu.md)

**Adaptation Guide**

You can set the minimum width to a value less than 64 vp or remove the limit altogether, by setting **constraintSize**.

**Example**
```ts
@Entry
@Component
struct Index {
  @Builder
  MyMenu(){
    Menu() {
      MenuItem({ startIcon: $r("app.media.icon"), content: "Menu option" })
    }
    .width(30)
    .constraintSize({minWidth: 0}) //Overwrite the default minimum width of 64 vp.
  }

  build() {
    Row() {
      Column() {
        Text('click to show menu')
      }
      .bindMenu(this.MyMenu)
      .width('100%')
    }
    .height('100%')
  }
}
```

## cl.arkui.4 Change in the Velocity Direction Specification of springCurve

**Change Impact**

In API version 9, when the [interpolate](../../../application-dev/reference/apis/js-apis-curve.md#interpolate9) method of [springCurve](../../../application-dev/reference/apis/js-apis-curve.md#curvesspringcurve9) is used for calculation, an initial velocity greater than 0 means to move in the reverse direction of the end point, and an initial velocity less than 0 means move in the direction of the end point.

Since API version 10, when the **interpolate** method of **springCurve** is used for calculation, an initial velocity greater than 0 means to move in the direction of the end point, and an initial velocity less than 0 means move in the reverse direction of the end point. As a result, when the initial velocity is not 0, the result obtained using the **interpolate** method of **springCurve** in API version 10 is different from that in API version 9.

## cl.arkui.5 Change in the Actual Curve Time Estimation Threshold Specification of springCurve

**Change Impact**

In API version 9, the maximum duration estimated by the [interpolate](../../../application-dev/reference/apis/js-apis-curve.md#interpolate9) method of [springCurve](../../../application-dev/reference/apis/js-apis-curve.md#curvesspringcurve9) for the actual spring curve is 1 second. When the physics-based curve duration exceeds 1 second, the estimated duration is still 1 second. As a result, the animation duration of the spring curve that exceeds 1 second is incorrectly normalized, and the interpolation result changes abruptly when t=1.

Since API version 10, the maximum duration estimated by the **interpolate** method of **springCurve** is 1000 seconds, so as to cover most spring curves. This change will result in differences from the calculation results by the **interpolate** method of **springCurve** in API versions earlier than 10.