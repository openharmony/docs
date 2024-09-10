# CSS语法参考

CSS是描述HML页面结构的样式语言。所有组件均存在系统默认样式，也可在页面CSS样式文件中对组件、页面自定义不同的样式。请参考[通用样式](../reference/apis-arkui/arkui-js/js-components-common-styles.md)了解兼容JS的类Web开发范式支持的组件样式。

## 尺寸单位

- 逻辑像素px（文档中以&lt;length&gt;表示）：

   - 默认屏幕具有的逻辑宽度为720px（配置见[配置文件](js-framework-js-tag.md)中的window小节），实际显示时会将页面布局缩放至屏幕实际宽度，如100px在实际宽度为1440物理像素的屏幕上，实际渲染为200物理像素（从720px向1440物理像素，所有尺寸放大2倍）。
   - 额外配置autoDesignWidth为true时（配置见[配置文件](js-framework-js-tag.md)中的window小节），逻辑像素px将按照屏幕密度进行缩放，如100px在屏幕密度为3的设备上，实际渲染为300物理像素。应用需要适配多种设备时，建议采用此方法。

- 百分比（文档中以&lt;percentage&gt;表示）：表示该组件占父组件尺寸的百分比，如组件的width设置为50%，代表其宽度为父组件的50%。


## 样式导入

为了模块化管理和代码复用，CSS样式文件支持 \@import 语句，导入css文件。


## 声明样式

每个页面目录下存在一个与布局hml文件同名的css文件，用来描述该hml页面中组件的样式，决定组件应该如何显示。

1. 内部样式，支持使用style、class属性来控制组件的样式。例如：
   ```html
   <!-- index.hml -->
   <div class="container">
     <text style="color: red">Hello World</text>
   </div>
   ```

   ```css
   /* index.css */
   .container {
     justify-content: center;
   }
   ```

2. 文件导入，合并外部样式文件。例如，在common目录中定义样式文件style.css，并在index.css文件首行中进行导入：
   ```css
   /* style.css */
   .title {
     font-size: 50px;
   }
   ```

   ```css
   /* index.css */
   @import '../../common/style.css';
   .container {
     justify-content: center;
   }
   ```


## 选择器

css选择器用于选择需要添加样式的元素，支持的选择器如下表所示：

| 选择器                       | 样例                                    | 样例描述                                     |
| ------------------------- | ------------------------------------- | ---------------------------------------- |
| .class                    | .container                            | 用于选择class="container"的组件。                |
| \#id                      | \#titleId                             | 用于选择id="titleId"的组件。                     |
| tag                       | text                                  | 用于选择text组件。                              |
| ,                         | .title,&nbsp;.content                 | 用于选择class="title"和class="content"的组件。    |
| \#id&nbsp;.class&nbsp;tag | \#containerId&nbsp;.content&nbsp;text | 非严格父子关系的后代选择器，选择具有id="containerId"作为祖先元素，class="content"作为次级祖先元素的所有text组件。如需使用严格的父子关系，可以使用“&gt;”代替空格，如：\#containerId&gt;.content。 |

示例：

```html
<!-- 页面布局xxx.hml -->
<div id="containerId" class="container">
  <text id="titleId" class="title">标题</text>
  <div class="content">
    <text id="contentId">内容</text>
  </div>
</div>
```

```css
/* 页面样式xxx.css */
/* 对所有div组件设置样式 */
div {
  flex-direction: column;
}
/* 对class="title"的组件设置样式 */
.title {
  font-size: 30px;
}
/* 对id="contentId"的组件设置样式 */
#contentId {
  font-size: 20px;
}
/* 对所有class="title"以及class="content"的组件都设置padding为5px */
.title, .content {
  padding: 5px;
}
/* 对class="container"的组件下的所有text设置样式 */
.container text {
  color: #007dff;
}
/* 对class="container"的组件下的直接后代text设置样式 */
.container > text {
  color: #fa2a2d;
}
```

以上样式运行效果如下：

![zh-cn_image_0000001127125270](figures/zh-cn_image_0000001127125270.png)

其中“.container text”将“标题”和“内容”设置为蓝色，而“.container &gt; text”直接后代选择器将“标题”设置为红色。2者优先级相同，但直接后代选择器声明顺序靠后，将前者样式覆盖（优先级计算见[选择器优先级](#选择器优先级)）。

## 选择器优先级

选择器的优先级计算规则与w3c规则保持一致（只支持：内联样式，id，class，tag，后代和直接后代），其中内联样式为在元素style属性中声明的样式。

当多条选择器声明匹配到同一元素时，各类选择器优先级由高到低顺序为：内联样式 &gt; id &gt; class &gt; tag。


## 伪类

css伪类是选择器中的关键字，用于指定要选择元素的特殊状态。例如，:disabled状态可以用来设置元素的disabled属性变为true时的样式。

除了单个伪类之外，还支持伪类的组合，例如，:focus:checked状态可以用来设置元素的focus属性和checked属性同时为true时的样式。支持的单个伪类如下表所示，按照优先级降序排列：

| 名称        | 支持组件                                     | 描述                                       |
| --------- | ---------------------------------------- | ---------------------------------------- |
| :disabled | 支持disabled属性的组件                          | 表示disabled属性变为true时的元素（不支持动画样式的设置）。      |
| :active   | 支持click事件的组件<br/>                        | 表示被用户激活的元素，如：被用户按下的按钮、被激活的tab-bar页签（不支持动画样式的设置）。 |
| :waiting  | button                                   | 表示waiting属性为true的元素（不支持动画样式的设置）。         |
| :checked  | input[type="checkbox"、type="radio"]、&nbsp;switch | 表示checked属性为true的元素（不支持动画样式的设置）。         |

伪类示例如下，设置按钮的:active伪类可以控制被用户按下时的样式：

```html
<!-- index.hml -->
<div class="container">
  <input type="button" class="button" value="Button"></input>
</div>
```

```css
/* index.css */
.button:active {
  background-color: #888888;/*按钮被激活时，背景颜色变为#888888 */
}
```

> **说明：** 
>
> 针对弹窗类组件及其子元素不支持伪类效果，包括popup、dialog、menu、option、picker。


## 样式预编译

预编译提供了利用特有语法生成css的程序，可以提供变量、运算等功能，令开发者更便捷地定义组件样式，目前支持less、sass和scss的预编译。使用样式预编译时，需要将原css文件后缀改为less、sass或scss，如index.css改为index.less、index.sass或index.scss。

- 当前文件使用样式预编译，例如将原index.css改为index.less：
  ```less
  /* index.less */
  /* 定义变量 */
  @colorBackground: #000000;
  .container {
    background-color: @colorBackground; /* 使用当前less文件中定义的变量 */
  }
  ```

- 引用预编译文件，例如common中存在style.scss文件，将原index.css改为index.scss，并引入style.scss：
  ```scss
  /* style.scss */
  /* 定义变量 */
  $colorBackground: #000000;
  ```

  在index.scss中引用：

  ```scss
  /* index.scss */
  /* 引入外部scss文件 */
  @import '../../common/style.scss';
  .container {
    background-color: $colorBackground; /* 使用style.scss中定义的变量 */
  }
  ```

  > **说明：** 
  >
  > 引用的预编译文件建议放在common目录进行管理。

## CSS样式继承<sup>6+</sup>

css样式继承提供了子节点继承父节点样式的能力，继承下来的样式在多选择器样式匹配的场景下，优先级排最低，当前支持以下样式的继承：

- font-family

- font-weight

- font-size

- font-style

- text-align

- line-height

- letter-spacing

- color

- visibility
