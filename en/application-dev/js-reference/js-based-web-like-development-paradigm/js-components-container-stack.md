# stack<a name="EN-US_TOPIC_0000001127125064"></a>

The  **<stack\>**  component provides a stack container where child components are successively stacked and the latter one overwrites the previous one.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="s2936fc34a22b44aa8389d1ec3de8fa61"></a>

Supported

## Attribute<a name="s7207d4d586504fa3be62558273017fbe"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Style<a name="section1774719169253"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Event<a name="section1948143416285"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example Code<a name="section18137649112711"></a>

```
<!-- xxx.hml -->
<stack class="stack-parent">
  <div class="back-child bd-radius"></div>
  <div class="positioned-child bd-radius"></div>
  <div class="front-child bd-radius"></div>
</stack>
```

```
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

![](figures/en-us_image_0000001127284958.png)

