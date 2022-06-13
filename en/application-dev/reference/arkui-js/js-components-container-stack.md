# stack

The **\<stack>** component provides a stack container where child components are successively stacked and the latter one overwrites the previous one.

## Required Permissions

None

## Child Components

Supported

## Attributes

Attributes in [Universal Attributes](js-components-common-attributes.md) are supported.

## Styles

Styles in [Universal Styles](js-components-common-styles.md) are supported.

## Events

Events in [Universal Events](js-components-common-events.md) are supported.

## Methods

Methods in [Universal Methods](js-components-common-methods.md) are supported.

## Example

```
<!-- xxx.hml -->
<stack class="stack-parent">
  <div class="back-child bd-radius"></div>
  <div class="positioned-child bd-radius"></div>
  <div class="front-child bd-radius"></div>
</stack>
/* xxx.css */
.stack-parent {
  width: 400px;
  height: 400px;
  background-color: #ffffff;
  border-width: 1px;
  border-style: solid;
}
.back-child {
  width: 300px;
  height: 300px;
  background-color: #3f56ea;
}
.front-child {
  width: 100px;
  height: 100px;
  background-color: #00bfc9;
}
.positioned-child {
  width: 100px;
  height: 100px;
  left: 50px;
  top: 50px;
  background-color: #47cc47;
}
.bd-radius {
  border-radius: 16px;
}
```

![img](figures/en-us_image_0000001127284958.png)