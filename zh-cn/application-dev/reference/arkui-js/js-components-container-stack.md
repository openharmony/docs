# stack<a name="ZH-CN_TOPIC_0000001127125064"></a>

堆叠容器，子组件按照顺序依次入栈，后一个子组件覆盖前一个子组件。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="s2936fc34a22b44aa8389d1ec3de8fa61"></a>

支持。

## 属性<a name="s7207d4d586504fa3be62558273017fbe"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section1774719169253"></a>

支持[通用样式](js-components-common-styles.md)。

## 事件<a name="section1948143416285"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section2279124532420"></a>

支持[通用方法](js-components-common-methods.md)。

## 示例<a name="section18137649112711"></a>

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

![](figures/zh-cn_image_0000001127284958.png)

