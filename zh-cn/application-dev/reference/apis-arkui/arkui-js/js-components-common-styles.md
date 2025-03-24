# 通用样式

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

组件普遍支持的可以在style或css中设置组件外观样式。


| 名称                                       | 类型                                       | 默认值          | 描述                                       |
| ---------------------------------------- | ---------------------------------------- | ------------ | ---------------------------------------- |
| width                                    | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | -            | 设置组件自身的宽度。<br/>缺省时使用元素自身内容需要的宽度。<br/>    |
| height                                   | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | -            | 设置组件自身的高度。<br/>缺省时使用元素自身内容需要的高度。<br/>    |
| min-width<sup>5+</sup>                   | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | 0            | 设置元素的最小宽度。                               |
| min-height<sup>5+</sup>                  | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | 0            | 设置元素的最小高度。                               |
| max-width<sup>5+</sup>                   | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | -            | 设置元素的最大宽度。默认无限制。                         |
| max-height<sup>5+</sup>                  | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | -            | 设置元素的最大高度。默认无限制。                         |
| padding                                  | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 使用简写属性设置所有的内边距属性。<br/>该属性可以有1到4个值：<br/>-&nbsp;指定一个值时，该值指定四个边的内边距。<br/>-&nbsp;指定两个值时，第一个值指定上下两边的内边距，第二个指定左右两边的内边距。<br/>-&nbsp;指定三个值时，第一个指定上边的内边距，第二个指定左右两边的内边距，第三个指定下边的内边距。<br/>-&nbsp;指定四个值时分别为上、右、下、左边的内边距（顺时针顺序）。 |
| padding-[left\|top\|right\|bottom]       | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 设置左、上、右、下内边距属性。                          |
| padding-[start\|end]                     | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 设置起始和末端内边距属性。                            |
| margin                                   | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 使用简写属性设置所有的外边距属性，该属性可以有1到4个值。<br/>-&nbsp;只有一个值时，这个值会被指定给全部的四个边。<br/>-&nbsp;两个值时，第一个值被匹配给上和下，第二个值被匹配给左和右。<br/>-&nbsp;三个值时，第一个值被匹配给上,&nbsp;第二个值被匹配给左和右，第三个值被匹配给下。<br/>-&nbsp;四个值时，会依次按上、右、下、左的顺序匹配&nbsp;(即顺时针顺序)。 |
| margin-[left\|top\|right\|bottom]        | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 设置左、上、右、下外边距属性。                          |
| margin-[start\|end]                      | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>5+</sup> | 0            | 设置起始和末端外边距属性。                            |
| border                                   | -                                        | 0            | 使用简写属性设置所有的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置时，各属性值为默认值。 |
| border-style                             | string                                   | solid        | 使用简写属性设置所有边框的样式，可选值为：<br/>-&nbsp;dotted：显示为一系列圆点，圆点半径为border-width的一半。<br/>-&nbsp;dashed：显示为一系列短的方形虚线。<br/>-&nbsp;solid：显示为一条实线。 |
| border-[left\|top\|right\|bottom]-style  | string                                   | solid        | 分别设置左、上、右、下四个边框的样式，可选值为dotted、dashed、solid。 |
| border-[left\|top\|right\|bottom]        | -                                        | -            | 使用简写属性设置对应位置的边框属性，包含边框的宽度，样式，颜色属性，顺序设置为border-width、border-style、border-color，不设置的值为默认值。 |
| border-width                             | &lt;length&gt;                           | 0            | 使用简写属性设置元素的所有边框宽度，或者单独为各边边框设置宽度。         |
| border-[left\|top\|right\|bottom]-width  | &lt;length&gt;                           | 0            | 分别设置左、上、右、下四个边框的宽度。                      |
| border-color                             | &lt;color&gt;                            | black        | 使用简写属性设置元素的所有边框颜色，或者单独为各边边框设置颜色。         |
| border-[left\|top\|right\|bottom]-color  | &lt;color&gt;                            | black        | 分别设置左、上、右、下四个边框的颜色。                      |
| border-radius                            | &lt;length&gt;                           | -            | border-radius属性设置元素的外边框圆角半径。设置border-radius时不能单独设置某一个方向的border-[left\|top\|right\|bottom]-width，border-[left\|top\|right\|bottom]-color&nbsp;，border-[left\|top\|right\|bottom]-style，如果要设置color、width和style，需要将四个方向一起设置（border-width、border-color、border-style）。<br/>顺序为左下、右下、左上和右上。 |
| border-[top\|bottom]-[left\|right]-radius | &lt;length&gt;                           | -            | 分别设置左上，右上，右下和左下四个角的圆角半径。                 |
| background                               | &lt;linear-gradient&gt;                  | -            | 仅支持设置[渐变样式](js-components-common-gradient.md)，与background-color、background-image不兼容。 |
| background-color                         | &lt;color&gt;                            | -            | 设置背景颜色。                                  |
| background-image                         | string                                   | -            | 设置背景图片。与background-color、background不兼容，支持网络图片资源和本地图片资源地址。<br/>示例：<br/>-&nbsp;background-image:&nbsp;url("/common/background.png")<br>不支持svg格式图片。 |
| background-size                          | -&nbsp;string<br/>-&nbsp;&lt;length&gt;&nbsp;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | auto         | 设置背景图片的大小。<br/>-&nbsp;string可选值：<br/>&nbsp;&nbsp;-&nbsp;contain：把图片扩展至最大尺寸，以使其高度和宽度完全适用内容区域。<br/>&nbsp;&nbsp;-&nbsp;cover：把背景图片扩展至足够大，以使背景图片完全覆盖背景区域；背景图片的某些部分也许无法显示在背景定位区域中。<br/>&nbsp;&nbsp;-&nbsp;auto：保持原图的比例不变。<br/>-&nbsp;length值参数方式：<br/>&nbsp;&nbsp;设置背景图片的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。<br/>-&nbsp;百分比参数方式：<br/>&nbsp;&nbsp;以父元素的百分比来设置背景图片的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。 |
| background-repeat                        | string                                   | repeat       | 针对重复背景图片样式进行设置，背景图片默认在水平和垂直方向上重复。<br/>-&nbsp;repeat：在水平轴和竖直轴上同时重复绘制图片。<br/>-&nbsp;repeat-x：只在水平轴上重复绘制图片。<br/>-&nbsp;repeat-y：只在竖直轴上重复绘制图片。<br/>-&nbsp;no-repeat：不会重复绘制图片。 |
| background-position                      | -&nbsp;string&nbsp;string<br/>-&nbsp;&lt;length&gt;&nbsp;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | 0px&nbsp;0px | -&nbsp;关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<br/>&nbsp;&nbsp;-&nbsp;left：水平方向上最左侧。<br/>&nbsp;&nbsp;-&nbsp;right：水平方向上最右侧。<br/>&nbsp;&nbsp;-&nbsp;top：竖直方向上最顶部。<br/>&nbsp;&nbsp;-&nbsp;bottom：竖直方向上最底部。<br/>&nbsp;&nbsp;-&nbsp;center：水平方向或竖直方向上中间位置。<br/>-&nbsp;length值参数方式：第一个值是水平位置，第二个值是垂直位置。&nbsp;左上角是&nbsp;0&nbsp;0。单位是像素&nbsp;(0px&nbsp;0px)&nbsp;&nbsp;。如果仅规定了一个值，另外一个值将是50%。<br/>-&nbsp;百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是&nbsp;0%&nbsp;0%。右下角是&nbsp;100%&nbsp;100%。如果仅规定了一个值，另外一个值为50%。<br/>-&nbsp;可以混合使用&lt;percentage&gt;和&lt;length&gt;。 |
| box-shadow<sup>5+</sup>                  | string                                   | 0            | 语法：box-shadow:&nbsp;h-shadow&nbsp;v-shadow&nbsp;blur&nbsp;spread&nbsp;color<br/>通过这个样式可以设置当前组件的阴影样式，包括水平位置(必填)、垂直位置(必填)、模糊半径(可选，默认值为0)、阴影延展距离(可选，默认值为0)、阴影颜色(可选，默认值为黑色)。<br/>示例：<br/>-&nbsp;box-shadow&nbsp;:10px&nbsp;20px&nbsp;5px&nbsp;10px&nbsp;\#888888<br/>-&nbsp;box-shadow&nbsp;:100px&nbsp;100px&nbsp;30px&nbsp;red<br/>-&nbsp;box-shadow&nbsp;:-100px&nbsp;-100px&nbsp;0px&nbsp;40px |
| filter<sup>5+</sup>                      | string                                   | -            | 语法：filter:&nbsp;blur(px)<br/>通过这个样式可以设置当前组件布局范围的内容模糊，参数用于指定模糊半径，如果没有设置值，则默认是0(不模糊)，不支持百分比。<br/>示例：<br/>-&nbsp;filter:&nbsp;blur(10px) |
| backdrop-filter<sup>5+</sup>             | string                                   | -            | 语法：backdrop-filter:&nbsp;blur(px)<br/>通过这个样式可以设置当前组件布局范围的背景模糊，参数用于指定模糊半径，如果没有设置值，则默认是0(不模糊)，不支持百分比。<br/>示例：<br/>-&nbsp;backdrop-filter:&nbsp;blur(10px) |
| window-filter<sup>5+</sup>               | string                                   | -            | 语法：window-filter:&nbsp;blur(percent),&nbsp;style<sup>5+</sup><br/>通过这个样式可以设置当前组件布局范围的窗口模糊程度和模糊样式，如果没有设置值，则默认是0%(不模糊)，多块模糊区域时不支持设置不同的模糊值和模糊样式。style可选值：small_light(默认值),&nbsp;medium_light,&nbsp;large_light,&nbsp;xlarge_light,&nbsp;small_dark,&nbsp;medium_dark,&nbsp;large_dark,&nbsp;xlarge_dark。<br/>示例：<br/>-&nbsp;window-filter:&nbsp;blur(50%)<br/>-&nbsp;window-filter:&nbsp;blur(10%),&nbsp;large_light |
| opacity                                  | number                                   | 1            | 元素的透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。        |
| display                                  | string                                   | flex         | 确定一个元素所产生的框的类型，可选值为：<br/>-&nbsp;flex：弹性布局。<br/>-&nbsp;none：不渲染此元素。<br />- grid：网格布局（仅div支持display样式设置为grid）。 |
| visibility                               | string                                   | visible      | 是否显示元素所产生的框。不可见的框会占用布局（将'display'属性设置为'none'来完全去除框），可选值为：<br/>-&nbsp;visible：元素正常显示。<br/>-&nbsp;hidden：隐藏元素，但是其他元素的布局不改变，相当于此元素变成透明。<br/>visibility和display样式都设置时，仅display生效。 |
| flex                                     | number&nbsp;\|&nbsp;string               | -            | 规定当前组件如何适应父组件中的可用空间。<br/>flex可以指定1个、2个<sup>5+</sup>或3个<sup>5+</sup>值。<br/>单值语法：<br/>-&nbsp;一个无单位数：用来设置组件的flex-grow。<br/>-&nbsp;一个有效的宽度值<sup>5+</sup>：用来设置组件的flex-basis。<br/>双值语法<sup>5+</sup>：<br/>第一个值必须是无单位数，用来设置组件的flex-grow。第二个值是以下之一：<br/>-&nbsp;一个无单位数：用来设置组件的flex-shrink。<br/>-&nbsp;一个有效的宽度值：用来设置组件的flex-basis。<br/>三值语法<sup>5+</sup>：<br/>第一个值必须是无单位数，用来设置组件的flex-grow；第二个值必须是无单位数，用来设置组件的flex-shrink；第三个值必须是一个有效的宽度值，用来设置组件的flex-basis。<br/>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup>5+</sup>时生效。 |
| flex-grow                                | number                                   | 0            | 设置组件的拉伸样式，指定父组件容器主轴方向上剩余空间（容器本身大小减去所有flex子元素占用的大小）的分配权重。0为不伸展。<br/>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup>5+</sup>时生效。 |
| flex-shrink                              | number                                   | 1            | 设置组件的收缩样式，元素仅在默认宽度之和大于容器的时候才会发生收缩，0为不收缩。<br/>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup>5+</sup>时生效。 |
| flex-basis                               | &lt;length&gt;                           | -            | 设置组件在主轴方向上的初始大小。<br/>仅父容器为&lt;div&gt;、&lt;list-item&gt;、&lt;tabs&gt;、&lt;refresh&gt;、&lt;stepper-item&gt;<sup>5+</sup>时生效。 |
| align-self<sup>6+</sup>                  | string                                   | -            | 设置自身在父元素交叉轴上的对齐方式，该样式会覆盖父元素的align-items样式，仅在父容器为div、list。可选值为：<br/>-&nbsp;stretch&nbsp;弹性元素被在交叉轴方向被拉伸到与容器相同的高度或宽度。<br/>-&nbsp;flex-start&nbsp;元素向交叉轴起点对齐。<br/>-&nbsp;flex-end&nbsp;元素向交叉轴终点对齐。<br/>-&nbsp;center&nbsp;元素在交叉轴居中。<br/>-&nbsp;baseline&nbsp;元素在交叉轴基线对齐。 |
| position                                 | string                                   | relative     | 设置元素的定位类型，不支持动态变更。<br/>-&nbsp;fixed：相对与整个界面进行定位。<br/>-&nbsp;absolute：相对于父元素进行定位，仅在父容器为&lt;div&gt;、&lt;stack&gt;时生效。<br/>-&nbsp;relative：相对于其正常位置进行定位。 |
| [left&nbsp;\|&nbsp;top&nbsp;\|&nbsp;right&nbsp;\|&nbsp;bottom]               | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt;<sup>6+</sup> | -            | left\|top\|right\|bottom需要配合position样式使用，来确定元素的偏移位置。<br/>-&nbsp;left属性规定元素的左边缘。该属性定义了定位元素左外边距边界与其包含块左边界之间的偏移。<br/>-&nbsp;top属性规定元素的顶部边缘。该属性定义了一个定位元素的上外边距边界与其包含块上边界之间的偏移。<br/>-&nbsp;right属性规定元素的右边缘。该属性定义了定位元素右外边距边界与其包含块右边界之间的偏移。<br/>-&nbsp;bottom属性规定元素的底部边缘。该属性定义了一个定位元素的下外边距边界与其包含块下边界之间的偏移。 |
| [start&nbsp;\|&nbsp;end]<sup>6+</sup>    | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | -            | start&nbsp;\|&nbsp;end需要配合position样式使用，来确定元素的偏移位置。<br/>-&nbsp;start属性规定元素的起始边缘。该属性定义了定位元素起始外边距边界与其包含块起始边界之间的偏移。<br/>-&nbsp;end属性规定元素的结尾边缘。该属性定义了一个定位元素的结尾边距边界与其包含块结尾边界之间的偏移。 |
| z-index<sup>6+</sup>                     | number                                   | -            | 表示对于同一父节点其子节点的渲染顺序。数值越大，渲染数据越靠后。<br/>z-index不支持auto，并且opacity等其他样式不会影响z-index的渲染顺序。 |
| image-fill<sup>6+</sup>                  | &lt;color&gt;                            | -            | 为svg图片填充颜色，支持组件范围（与设置图片资源的属性）：button（icon属性）、piece（icon属性）、search（icon属性）、input（headericon属性）、textarea（headericon属性）、image（src属性）、toolbar-item(icon属性)。<br/>svg图片文件内的fill属性颜色值在渲染时将被替换为image-fill所配的颜色值，且仅对svg图片内显示声明的fill属性生效。 |
| clip-path<sup>6+</sup>                   | [&nbsp;&lt;geometry-box&gt;&nbsp;\|&nbsp;&lt;basic-shape&gt;&nbsp;]&nbsp;\|&nbsp;none | -            | 设置组件的裁剪区域。区域内的部分显示，区域外的不显示。<br/>&lt;geometry-box&gt;：表示裁剪区域的作用范围，默认为border-box。可选值为：<br/>-&nbsp;margin-box：margin计算入长宽尺寸内。<br/>-&nbsp;border-box：border计算入长宽尺寸内。<br/>-&nbsp;padding-box：padding计算入长宽尺寸内。<br/>-&nbsp;content-box：margin/border/padding不计算入长宽尺寸内。<br/>&lt;basic-shape&gt;：表示裁剪的形状。包含以下类型：<br/>-&nbsp;inset，格式为：inset(&nbsp;&lt;percentage&gt;{1,4}&nbsp;[&nbsp;round&nbsp;&lt;'border-radius'&gt;&nbsp;]?&nbsp;)。<br/>-&nbsp;circle，格式为：circle(&nbsp;[&nbsp;&lt;percentage&gt;&nbsp;]?&nbsp;[&nbsp;at&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt;&nbsp;]?&nbsp;)。<br/>-&nbsp;ellipse，格式为：ellipse(&nbsp;[&nbsp;&lt;percentage&gt;{2}&nbsp;]?&nbsp;[&nbsp;at&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt;&nbsp;]?&nbsp;)。<br/>-&nbsp;polygon，格式为：polygon(&nbsp;[&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt;&nbsp;]\#&nbsp;)。<br/>-&nbsp;path，格式为：path(&nbsp;&lt;string&gt;&nbsp;)。 |
| mask-image<sup>6+</sup>                  | -&nbsp;&lt;linear-gradient&gt;<br/>-&nbsp;string | -            | 设置渐变色遮罩或本地图片设置。<br/>设置渐变色遮罩，示例：<br/>linear-gradient(to&nbsp;left,&nbsp;black,&nbsp;white)<br/>设置纯色遮罩，示例：<br/>linear-gradient(to&nbsp;right,&nbsp;grey&nbsp;,&nbsp;grey)<br/>设置本地svg图片为遮罩，示例：url(common/mask.svg) |
| mask-size<sup>6+</sup>                   | -&nbsp;string<br/>-&nbsp;&lt;length&gt;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | auto         | 设置遮罩图片显示大小，仅当mask-image为图片资源时有效。<br/>string可选值：<br/>-&nbsp;contain：把图像扩展至最大尺寸，以使其高度和宽度完全适用内容区域。<br/>-&nbsp;cover：把图像扩展至足够大，以使背景图像完全覆盖背景区域；背景图像的某些部分也许无法显示在背景定位区域中。<br/>-&nbsp;auto：保持原图的比例不变。<br/>length值参数方式：设置图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。<br/>百分比参数方式：以原图宽高的百分比来设置图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为&nbsp;"auto"。 |
| mask-position<sup>6+</sup>               | -&nbsp;string&nbsp;string<br/>-&nbsp;&lt;length&gt;&nbsp;&lt;length&gt;<br/>-&nbsp;&lt;percentage&gt;&nbsp;&lt;percentage&gt; | 0px&nbsp;0px | 设置遮罩图片显示位置，仅当mask-image为图片资源时有效。关键词方式：如果仅规定了一个关键词，那么第二个值为"center"。两个值分别定义水平方向位置和竖直方向位置。<br/>string可选值：<br/>-&nbsp;left：水平方向上最左侧。<br/>-&nbsp;right：水平方向上最右侧。<br/>-&nbsp;top：竖直方向上最顶部。<br/>-&nbsp;bottom：竖直方向上最底部。<br/>-&nbsp;center：水平方向或竖直方向上中间位置。<br/>length值参数方式：第一个值是水平位置，第二个值是垂直位置。&nbsp;左上角是&nbsp;0&nbsp;0。单位是像素&nbsp;(0px&nbsp;0px)&nbsp;&nbsp;。如果仅规定了一个值，另外一个值将是50%。<br/>百分比参数方式：第一个值是水平位置，第二个值是垂直位置。左上角是&nbsp;0%&nbsp;0%。右下角是&nbsp;100%&nbsp;100%。如果仅规定了一个值，另外一个值为50%。<br/>可以混合使用&lt;percentage&gt;和&lt;length&gt;。 |
| border-image-source<sup>7+</sup>         | string                                   | -            | 指定元素的边框图片。<br/>示例：<br/>border-image-source:&nbsp;url("/common/images/border.png") |
| border-image-slice<sup>7+</sup>          | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | 0            | 指定图片的边界内向偏移。<br/>该属性可以有1到4个值：<br/>指定一个值时，该值指定四个边的内偏移。<br/>指定两个值时，第一个值指定上下两边的内偏移，第二个指定左右两边的内偏移。<br/>指定三个值时，第一个指定上边的内偏移，第二个指定左右两边的内偏移，第三个指定下边的内偏移。<br/>指定四个值时分别为上、右、下、左边的内偏移（顺时针顺序）。 |
| border-image-width<sup>7+</sup>          | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | 0            | 指定图片边界的宽度。<br/>指定一个值时，该值指定四个边的宽度。<br/>指定两个值时，第一个值指定上下两边的宽度&nbsp;，第二个指定左右两边的宽度。<br/>指定三个值时，第一个指定上边的宽度&nbsp;，第二个指定左右两边的宽度&nbsp;，第三个指定下边的宽度。<br/>指定四个值时分别为上、右、下、左边的宽度&nbsp;（顺时针顺序）。 |
| border-image-outset<sup>7+</sup>         | &lt;length&gt;&nbsp;\|&nbsp;&lt;percentage&gt; | 0            | 指定边框图像可超出边框的大小。<br/>指定一个值时，边框图像在四个方向超出边框的距离。<br/>指定两个值时，第一个值指定上下两边的边框图像超出边框的距离，第二个指定左右两边的&nbsp;。<br/>指定三个值时，第一个指定上边的边框图像超出边框的距离&nbsp;，第二个指定左右两边的边框图像超出边框的距离&nbsp;，第三个指定下边的边框图像超出边框的距离&nbsp;。<br/>指定四个值时分别为上、右、下、左边的边框图像超出边框的距离&nbsp;（顺时针顺序）。 |
| border-image-repeat<sup>7+</sup>         | string                                   | stretch      | 定义图片如何填充边框。<br/>stretch:&nbsp;拉伸图片以填充边框。<br/>repeat：平铺图片以填充边框。<br/>round：平铺图像。当不能整数次平铺时，根据情况放大或缩小图像。<br/> |
| border-image<sup>7+</sup>                | string                                   | -            | 简写属性，可以选择以下两种设置方式：<br/>-&nbsp;设置图片边框的每个属性。包含图像的边界向内偏移，图像边界的宽度，边框图像可超出边框盒的大小，图片如何填充边框，顺序设置为&nbsp;border-image-source&nbsp;,border-image-slice,border-image-width,border-image-outset,border-image-repeat，不设置的值为默认值。<br/>-&nbsp;渐变色边框<br/>&nbsp;&nbsp;示例:<br/>&nbsp;&nbsp;border-image:&nbsp;linear-gradient(red,&nbsp;yellow)&nbsp;10px |
| box-sizing<sup>9+</sup>                  | string                                   | border-box   | 设置组件的边框类型。<br/>content-box：标准盒子模型。设置的width和height只包含内容的宽和高，不包含边框（border）和内边距（padding）。<br/>border-box：设置的width和height包含内容，边框（border）和内边距（padding），即：组件内容区的实际宽度 = width - (border + padding) 。 |


>  **说明：**
>  通用样式都不是必填项。

## 示例

### box-sizing 

```html
<div class="container" onswipe="touchMove">
	<text style="margin: 10px; box-sizing: content-box; width: 300px;height: 300px; border-color: blue; border-width: 20px;">
		contentBox
	</text>
	<text style="margin: 10px; box-sizing: border-box; width: 300px;height: 300px;border-color: blue; border-width: 20px;">
		borderBox
	</text>
</div>
```

![zh-cn_image_0000001214837129](figures/zh-cn_image_0000001214837129.png)
