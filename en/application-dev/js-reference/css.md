# CSS<a name="EN-US_TOPIC_0000001162494587"></a>

-   [Size Unit](#en-us_topic_0000001058988944_section81638230913)
-   [Style Import](#en-us_topic_0000001058988944_section890312411592)
-   [Style Declaration](#en-us_topic_0000001058988944_section197695604215)
-   [Selector](#en-us_topic_0000001058988944_section381741144310)
-   [Selector Specificity](#en-us_topic_0000001058988944_section1460102134415)
-   [Pseudo-classes](#en-us_topic_0000001058988944_section633010213458)
-   [Precompiled Styles](#en-us_topic_0000001058988944_section1690162216454)

Cascading Style Sheets \(CSS\) is a language used to describe the HML page structure. All HML components have default styles. You can customize styles for these components using CSS to design various pages.

## Size Unit<a name="en-us_topic_0000001058988944_section81638230913"></a>

1.  Logical px set by  **<length\>**:
    1.  The default logical screen width is 720 px \(for details, see the  **"window"**  section in  [config.json](js-tag.md#EN-US_TOPIC_0000001162494585)\). Your page will be scaled to fit the actual width of the screen. For example, on a screen with the actual width of 1440 physical px, 100 px is displayed on 200 physical px, with all sizes doubled from 720 px to 1440 px.
    2.  If you set  **autoDesignWidth**  to  **true**  \(for details, see the  **"window"**  section in  [config.json](js-tag.md#EN-US_TOPIC_0000001162494585)\), the logical px are scaled based on the screen density. For example, if the screen density is 3x, 100 px will be rendered on 300 physical px. This approach is recommended when your application needs to adapt to multiple devices.

2.  Percentage set by  **<percentage\>**: The component size is represented by its percentage of the parent component size. For example, if the width  **<percentage\>**  of a component is set to  **50%**, the width of the component is half of its parent component's width.

## Style Import<a name="en-us_topic_0000001058988944_section890312411592"></a>

CSS files can be imported using the  **@import**  statement. This facilitates module management and code reuse.

## Style Declaration<a name="en-us_topic_0000001058988944_section197695604215"></a>

The  **.css**  file with the same name as the  **.hml**  file in each page directory describes the styles of components on the HML page, determining how the components will be displayed.

1.  Internal style: The  **style**  and  **class**  attributes can be used to specify the component style. Example:

    ```
    <!-- index.hml -->
    <div class="container">
      <text style="color: red">Hello World</text>
    </div>
    ```

    ```
    /* index.css */
    .container {
      justify-content: center;
    }
    ```

2.  External style files: You need to import the files. For example, create a  **style.css**  file in the  **common**  directory and import the file at the beginning of  **index.css**.

    ```
    /* style.css */
    .title {
      font-size: 50px;
    }
    ```

    ```
    /* index.css */
    @import '../../common/style.css';
    .container {
      justify-content: center;
    }
    ```


## Selector<a name="en-us_topic_0000001058988944_section381741144310"></a>

A CSS selector is used to select elements for which styles need to be added to. The following table lists the supported selectors.

<a name="en-us_topic_0000001058988944_table8917183413489"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988944_row1291753412489"><th class="cellrowborder" valign="top" width="15.341534153415342%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988944_p291763474818"><a name="en-us_topic_0000001058988944_p291763474818"></a><a name="en-us_topic_0000001058988944_p291763474818"></a>Selector</p>
</th>
<th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988944_p1491783412488"><a name="en-us_topic_0000001058988944_p1491783412488"></a><a name="en-us_topic_0000001058988944_p1491783412488"></a>Example</p>
</th>
<th class="cellrowborder" valign="top" width="59.805980598059804%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988944_p10917173404818"><a name="en-us_topic_0000001058988944_p10917173404818"></a><a name="en-us_topic_0000001058988944_p10917173404818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988944_row2091743484810"><td class="cellrowborder" valign="top" width="15.341534153415342%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p1891783411483"><a name="en-us_topic_0000001058988944_p1891783411483"></a><a name="en-us_topic_0000001058988944_p1891783411483"></a>.class</p>
</td>
<td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p169174348484"><a name="en-us_topic_0000001058988944_p169174348484"></a><a name="en-us_topic_0000001058988944_p169174348484"></a>.container</p>
</td>
<td class="cellrowborder" valign="top" width="59.805980598059804%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p991733474814"><a name="en-us_topic_0000001058988944_p991733474814"></a><a name="en-us_topic_0000001058988944_p991733474814"></a>Selects all components whose <strong id="en-us_topic_0000001058988944_b266804373915"><a name="en-us_topic_0000001058988944_b266804373915"></a><a name="en-us_topic_0000001058988944_b266804373915"></a>class</strong> is <strong id="en-us_topic_0000001058988944_b13862113914395"><a name="en-us_topic_0000001058988944_b13862113914395"></a><a name="en-us_topic_0000001058988944_b13862113914395"></a>container</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row189178343481"><td class="cellrowborder" valign="top" width="15.341534153415342%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p5917634124817"><a name="en-us_topic_0000001058988944_p5917634124817"></a><a name="en-us_topic_0000001058988944_p5917634124817"></a>#id</p>
</td>
<td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p89231120496"><a name="en-us_topic_0000001058988944_p89231120496"></a><a name="en-us_topic_0000001058988944_p89231120496"></a>#titleId</p>
</td>
<td class="cellrowborder" valign="top" width="59.805980598059804%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p132391416144917"><a name="en-us_topic_0000001058988944_p132391416144917"></a><a name="en-us_topic_0000001058988944_p132391416144917"></a>Selects all components whose <strong id="en-us_topic_0000001058988944_b97491740201315"><a name="en-us_topic_0000001058988944_b97491740201315"></a><a name="en-us_topic_0000001058988944_b97491740201315"></a>id</strong> is <strong id="en-us_topic_0000001058988944_b620774121515"><a name="en-us_topic_0000001058988944_b620774121515"></a><a name="en-us_topic_0000001058988944_b620774121515"></a>titleId</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row12917934154811"><td class="cellrowborder" valign="top" width="15.341534153415342%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p1041721913499"><a name="en-us_topic_0000001058988944_p1041721913499"></a><a name="en-us_topic_0000001058988944_p1041721913499"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p4917203424816"><a name="en-us_topic_0000001058988944_p4917203424816"></a><a name="en-us_topic_0000001058988944_p4917203424816"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="59.805980598059804%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p174847365491"><a name="en-us_topic_0000001058988944_p174847365491"></a><a name="en-us_topic_0000001058988944_p174847365491"></a>Selects all <strong id="en-us_topic_0000001058988944_b647149104015"><a name="en-us_topic_0000001058988944_b647149104015"></a><a name="en-us_topic_0000001058988944_b647149104015"></a>&lt;text&gt;</strong> components.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row99179340488"><td class="cellrowborder" valign="top" width="15.341534153415342%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p19918123424819"><a name="en-us_topic_0000001058988944_p19918123424819"></a><a name="en-us_topic_0000001058988944_p19918123424819"></a>,</p>
</td>
<td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p7918734154817"><a name="en-us_topic_0000001058988944_p7918734154817"></a><a name="en-us_topic_0000001058988944_p7918734154817"></a>.title, .content</p>
</td>
<td class="cellrowborder" valign="top" width="59.805980598059804%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p9240140154916"><a name="en-us_topic_0000001058988944_p9240140154916"></a><a name="en-us_topic_0000001058988944_p9240140154916"></a>Selects all components whose <strong id="en-us_topic_0000001058988944_b1792517381411"><a name="en-us_topic_0000001058988944_b1792517381411"></a><a name="en-us_topic_0000001058988944_b1792517381411"></a>class</strong> is <strong id="en-us_topic_0000001058988944_b123172282411"><a name="en-us_topic_0000001058988944_b123172282411"></a><a name="en-us_topic_0000001058988944_b123172282411"></a>title</strong> or <strong id="en-us_topic_0000001058988944_b13169142616410"><a name="en-us_topic_0000001058988944_b13169142616410"></a><a name="en-us_topic_0000001058988944_b13169142616410"></a>content</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row1091833418485"><td class="cellrowborder" valign="top" width="15.341534153415342%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p27744448492"><a name="en-us_topic_0000001058988944_p27744448492"></a><a name="en-us_topic_0000001058988944_p27744448492"></a>#id .class tag</p>
</td>
<td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p0402948154911"><a name="en-us_topic_0000001058988944_p0402948154911"></a><a name="en-us_topic_0000001058988944_p0402948154911"></a>#containerId .content text</p>
</td>
<td class="cellrowborder" valign="top" width="59.805980598059804%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p19830323135016"><a name="en-us_topic_0000001058988944_p19830323135016"></a><a name="en-us_topic_0000001058988944_p19830323135016"></a>Selects all grandchild <strong id="en-us_topic_0000001058988944_b912043612213"><a name="en-us_topic_0000001058988944_b912043612213"></a><a name="en-us_topic_0000001058988944_b912043612213"></a>&lt;text&gt;</strong> components whose grandparent components are identified as <strong id="en-us_topic_0000001058988944_b8266185815595"><a name="en-us_topic_0000001058988944_b8266185815595"></a><a name="en-us_topic_0000001058988944_b8266185815595"></a>containerId</strong> and whose parent components are of the <strong id="en-us_topic_0000001058988944_b1533612295015"><a name="en-us_topic_0000001058988944_b1533612295015"></a><a name="en-us_topic_0000001058988944_b1533612295015"></a>content</strong> class. To select child components, use <strong id="en-us_topic_0000001058988944_b1323417618"><a name="en-us_topic_0000001058988944_b1323417618"></a><a name="en-us_topic_0000001058988944_b1323417618"></a>&gt;</strong> to replace the space between <strong id="en-us_topic_0000001058988944_b123221349918"><a name="en-us_topic_0000001058988944_b123221349918"></a><a name="en-us_topic_0000001058988944_b123221349918"></a>#id</strong> and <strong id="en-us_topic_0000001058988944_b9863851313"><a name="en-us_topic_0000001058988944_b9863851313"></a><a name="en-us_topic_0000001058988944_b9863851313"></a>.class</strong>, for example, <strong id="en-us_topic_0000001058988944_b32921881723"><a name="en-us_topic_0000001058988944_b32921881723"></a><a name="en-us_topic_0000001058988944_b32921881723"></a>#containerId&gt;.content</strong>.</p>
</td>
</tr>
</tbody>
</table>

The following is an example:

```
<!-- Page layoutxxx.hml -->
<div id="containerId" class="container">
  <text id="titleId" class="title">Title</text>
  <div class="content">
    <text id="contentId">Content</text>
  </div>
</div>
```

```
/* Page style xxx.css */
/* Set the style for all <div> components. */
div {
  flex-direction: column;
}
/* Set the style for the component whose class is title. */
.title {
  font-size: 30px;
}
/* Set the style for the component whose id is contentId. */
#contentId {
  font-size: 20px;
}
/* Set padding for all components of the title or content class to 5 px. */
.title, .content {
  padding: 5px;
}
/* Set the style for all texts of components whose class is container.
 */
.container text {
  color: #007dff;
};
/* Set the style for direct descendant texts of components whose class is container.
*/
.container > text {
  color: #fa2a2d;
}
```

The above style works as follows:

![](figures/sample_css.png)

In the preceding example,  **.container text**  sets title and content to blue, and  **.container \> text**  sets title to red. The two styles have the same priority, but  **.container \> text**  declares the style later and overwrites the former style. \(For details about the priority, see  [Selector Specificity](#en-us_topic_0000001058988944_section1460102134415).\)

## Selector Specificity<a name="en-us_topic_0000001058988944_section1460102134415"></a>

The specificity rule of the selectors complies with the W3C rule, which is only available for inline styles,  **id**,  **class**,  **tag**, grandchild components, and child components. \(Inline styles are those declared in the  **style**  attribute.\)

When multiple selectors point to the same element, their priorities are as follows \(in descending order\): inline style \>  **id**  \>  **class**  \>  **tag**.

## Pseudo-classes<a name="en-us_topic_0000001058988944_section633010213458"></a>

A CSS pseudo-class is a keyword added to a selector that specifies a special state of the selected element\(s\). For example,  **:disabled**  can be used to select the element whose  **disabled**  attribute is  **true**.

In addition to a single pseudo-class, a combination of pseudo-classes is supported. For example,  **:disabled:checked**  selects the element whose  **disabled**  and  **checked**  attributes are both set to  **true**. The following table lists the supported single pseudo-class in descending order of priority.

<a name="en-us_topic_0000001058988944_table584491515455"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988944_row3844171516452"><th class="cellrowborder" valign="top" width="11.42114211421142%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988944_p3844151594510"><a name="en-us_topic_0000001058988944_p3844151594510"></a><a name="en-us_topic_0000001058988944_p3844151594510"></a>Pseudo-class</p>
</th>
<th class="cellrowborder" valign="top" width="26.162616261626166%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988944_p11844131512458"><a name="en-us_topic_0000001058988944_p11844131512458"></a><a name="en-us_topic_0000001058988944_p11844131512458"></a>Available Components</p>
</th>
<th class="cellrowborder" valign="top" width="62.41624162416242%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988944_p78441615184511"><a name="en-us_topic_0000001058988944_p78441615184511"></a><a name="en-us_topic_0000001058988944_p78441615184511"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988944_row104936528343"><td class="cellrowborder" valign="top" width="11.42114211421142%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p2235059193413"><a name="en-us_topic_0000001058988944_p2235059193413"></a><a name="en-us_topic_0000001058988944_p2235059193413"></a>:disabled</p>
</td>
<td class="cellrowborder" valign="top" width="26.162616261626166%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p1323545943417"><a name="en-us_topic_0000001058988944_p1323545943417"></a><a name="en-us_topic_0000001058988944_p1323545943417"></a>Components that support the <strong id="en-us_topic_0000001058988944_b774812224211"><a name="en-us_topic_0000001058988944_b774812224211"></a><a name="en-us_topic_0000001058988944_b774812224211"></a>disabled</strong> attribute</p>
</td>
<td class="cellrowborder" valign="top" width="62.41624162416242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p10235155912344"><a name="en-us_topic_0000001058988944_p10235155912344"></a><a name="en-us_topic_0000001058988944_p10235155912344"></a>Selects the element whose <strong id="en-us_topic_0000001058988944_b661616306815"><a name="en-us_topic_0000001058988944_b661616306815"></a><a name="en-us_topic_0000001058988944_b661616306815"></a>disabled</strong> attribute is changed to <strong id="en-us_topic_0000001058988944_b9301136081"><a name="en-us_topic_0000001058988944_b9301136081"></a><a name="en-us_topic_0000001058988944_b9301136081"></a>true</strong> (unavailable for animation attributes).</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row0844121554510"><td class="cellrowborder" valign="top" width="11.42114211421142%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p138441015144512"><a name="en-us_topic_0000001058988944_p138441015144512"></a><a name="en-us_topic_0000001058988944_p138441015144512"></a>:active</p>
</td>
<td class="cellrowborder" valign="top" width="26.162616261626166%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p1184441511457"><a name="en-us_topic_0000001058988944_p1184441511457"></a><a name="en-us_topic_0000001058988944_p1184441511457"></a><span id="en-us_topic_0000001058988944_ph32264934610"><a name="en-us_topic_0000001058988944_ph32264934610"></a><a name="en-us_topic_0000001058988944_ph32264934610"></a>Components that support the click event</span></p>
</td>
<td class="cellrowborder" valign="top" width="62.41624162416242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p1384471516454"><a name="en-us_topic_0000001058988944_p1384471516454"></a><a name="en-us_topic_0000001058988944_p1384471516454"></a>Selects the element activated by a user. For example, a pressed button<span id="en-us_topic_0000001058988944_ph1265519710112"><a name="en-us_topic_0000001058988944_ph1265519710112"></a><a name="en-us_topic_0000001058988944_ph1265519710112"></a> or a selected <strong id="en-us_topic_0000001058988944_b1655321419203"><a name="en-us_topic_0000001058988944_b1655321419203"></a><a name="en-us_topic_0000001058988944_b1655321419203"></a>tab-bar</strong> (unavailable for animation attributes)</span>. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row12925340193519"><td class="cellrowborder" valign="top" width="11.42114211421142%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p134731642153511"><a name="en-us_topic_0000001058988944_p134731642153511"></a><a name="en-us_topic_0000001058988944_p134731642153511"></a>:waiting</p>
</td>
<td class="cellrowborder" valign="top" width="26.162616261626166%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p114732420358"><a name="en-us_topic_0000001058988944_p114732420358"></a><a name="en-us_topic_0000001058988944_p114732420358"></a>button</p>
</td>
<td class="cellrowborder" valign="top" width="62.41624162416242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p2473742143511"><a name="en-us_topic_0000001058988944_p2473742143511"></a><a name="en-us_topic_0000001058988944_p2473742143511"></a>Selects the element whose <strong id="en-us_topic_0000001058988944_b194051157192412"><a name="en-us_topic_0000001058988944_b194051157192412"></a><a name="en-us_topic_0000001058988944_b194051157192412"></a>waiting</strong> attribute is <strong id="en-us_topic_0000001058988944_b1621716112515"><a name="en-us_topic_0000001058988944_b1621716112515"></a><a name="en-us_topic_0000001058988944_b1621716112515"></a>true</strong><span id="en-us_topic_0000001058988944_ph3323185819110"><a name="en-us_topic_0000001058988944_ph3323185819110"></a><a name="en-us_topic_0000001058988944_ph3323185819110"></a> (unavailable for animation attributes)</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988944_row1884431514452"><td class="cellrowborder" valign="top" width="11.42114211421142%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988944_p7844161512452"><a name="en-us_topic_0000001058988944_p7844161512452"></a><a name="en-us_topic_0000001058988944_p7844161512452"></a>:checked</p>
</td>
<td class="cellrowborder" valign="top" width="26.162616261626166%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988944_p198451215174516"><a name="en-us_topic_0000001058988944_p198451215174516"></a><a name="en-us_topic_0000001058988944_p198451215174516"></a>input[type="checkbox", type="radio"]<span id="en-us_topic_0000001058988944_ph55837371112"><a name="en-us_topic_0000001058988944_ph55837371112"></a><a name="en-us_topic_0000001058988944_ph55837371112"></a>, and switch</span></p>
</td>
<td class="cellrowborder" valign="top" width="62.41624162416242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988944_p9845415164512"><a name="en-us_topic_0000001058988944_p9845415164512"></a><a name="en-us_topic_0000001058988944_p9845415164512"></a>Selects the element whose <strong id="en-us_topic_0000001058988944_b23456295288"><a name="en-us_topic_0000001058988944_b23456295288"></a><a name="en-us_topic_0000001058988944_b23456295288"></a>checked</strong> attribute is <strong id="en-us_topic_0000001058988944_b734692962814"><a name="en-us_topic_0000001058988944_b734692962814"></a><a name="en-us_topic_0000001058988944_b734692962814"></a>true</strong><span id="en-us_topic_0000001058988944_ph879324710523"><a name="en-us_topic_0000001058988944_ph879324710523"></a><a name="en-us_topic_0000001058988944_ph879324710523"></a> (unavailable for animation attributes)</span>. </p>
</td>
</tr>
</tbody>
</table>

The following is an example for you to use the  **:active**  pseudo-class to control the style when a user presses the button. 

```
<!-- index.hml -->
<div class="container">
  <input type="button" class="button" value="Button"></input>
</div>
```

```
/* index.css */
.button:active {
  background-color: #888888;/* After the button is activated, the background color is changed to #888888. */
}
```

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Pseudo-classes are not supported for the  **<popup\>**  component and its child components, including,  **<dialog\>**,  **<menu\>**,  **<option\>**, and  **<picker\>**.

## Precompiled Styles<a name="en-us_topic_0000001058988944_section1690162216454"></a>

Precompilation is a program that uses specific syntax to generate CSS files. It provides variables and calculation, helping you define component styles more conveniently. Currently, Less, Sass, and Scss are supported. To use precompiled styles, change the suffix of the original  **.css**  file. For example, change  **index.css**  to  **index.less**,  **index.sass**, or  **index.scss**.

-   The following  **index.less**  file is changed from  **index.css**.

    ```
    /* index.less */
    /* Define a variable. */
    @colorBackground: #000000;
    .container {
      background-color: @colorBackground; /* Use the variable defined in the .less file. */
    }
    ```


-   Reference a precompiled style file. For example, if the  **style.scss**  file is located in the  **common**  directory, change the original  **index.css**  file to  **index.scss**  and import  **style.scss**.

    ```
    /* style.scss */
    /* Define a variable. */
    $colorBackground: #000000;
    ```

    Reference the precompiled style file in  **index.scss**:

    ```
    /* index.scss */
    /* Import style.scss. */
    @import '../../common/style.scss';
    .container {
      background-color: $colorBackground; /* Use the variable defined in style.scss. */
    }
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >Place precompiled style files in the  **common**  directory.


