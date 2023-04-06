# Common Component Development<a name="EN-US_TOPIC_0000001052170409"></a>

Common components inherit from the base class  **UIView**. Child components cannot be added to common components, such as buttons, images, and labels.

**Figure  1**  Tree structure of common components<a name="fig3386518305"></a>  
![](figures/tree-structure-of-common-components.png "tree-structure-of-common-components")

**UIView**  is a base class of the following components:  **UIAbstractProgress**,  **UIArcLabel**,  **UIButton**,  **UICanvas**,  **UILabel**, and  **UIImageView**.  **UIBoxProgress**  and  **UICircleProgress**  inherit from  **UIAbstractProgress**.  **UILabelButton**  and  **UIRepeatButton**  inherit from  **UIButton**.  **UIImageAnimatorView**  and  **UITextureMapper**  inherit from  **UIImageView**.

## UIButton<a name="section145353310214"></a>

## When to Use<a name="section1169616141577"></a>

**UIButton**  supports the click event and allows you to set styles in different states.

## Available APIs<a name="section341211538315"></a>

**Table  1** Available functions  in UIButton

<a name="table172083013117"></a>
<table><thead align="left"><tr id="row13192303311"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1019330103113"><a name="p1019330103113"></a><a name="p1019330103113"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p181963020318"><a name="p181963020318"></a><a name="p181963020318"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row191914306313"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p161963010314"><a name="p161963010314"></a><a name="p161963010314"></a>void SetImageSrc (const char *defaultImgSrc, const char *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1619143014312"><a name="p1619143014312"></a><a name="p1619143014312"></a>Sets the button image.</p>
</td>
</tr>
<tr id="row141915307313"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p419193017312"><a name="p419193017312"></a><a name="p419193017312"></a>void SetImagePosition (const int16_t x, const int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p919030173119"><a name="p919030173119"></a><a name="p919030173119"></a>Sets the position of the button image.</p>
</td>
</tr>
<tr id="row1119930183115"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1619430193110"><a name="p1619430193110"></a><a name="p1619430193110"></a>int16_t GetImageX () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p151933012315"><a name="p151933012315"></a><a name="p151933012315"></a>Obtains the x-coordinate of the button image.</p>
</td>
</tr>
<tr id="row62083017317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p122093053112"><a name="p122093053112"></a><a name="p122093053112"></a>int16_t GetImageY () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p62016307314"><a name="p62016307314"></a><a name="p62016307314"></a>Obtains the y-coordinate of the button image.</p>
</td>
</tr>
<tr id="row72013013114"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p720203016314"><a name="p720203016314"></a><a name="p720203016314"></a>const ImageInfo* GetCurImageSrc() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1201730123116"><a name="p1201730123116"></a><a name="p1201730123116"></a>Obtains the image of the button in the current state.</p>
</td>
</tr>
<tr id="row320103017318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12010308314"><a name="p12010308314"></a><a name="p12010308314"></a>Style&amp;  GetStyleForState (ButtonState state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17201030133117"><a name="p17201030133117"></a><a name="p17201030133117"></a>Sets the style for the button in the current state.</p>
</td>
</tr>
<tr id="row420730193117"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11201830183112"><a name="p11201830183112"></a><a name="p11201830183112"></a>voidSetStyleForState (const Style &amp;style, ButtonState state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p82016308311"><a name="p82016308311"></a><a name="p82016308311"></a>Sets the style for the button in a specified state.</p>
</td>
</tr>
<tr id="row1320193010317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1020153014319"><a name="p1020153014319"></a><a name="p1020153014319"></a>void Disable ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p192063023119"><a name="p192063023119"></a><a name="p192063023119"></a>Disables the button.</p>
</td>
</tr>
<tr id="row02017308315"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p620173011318"><a name="p620173011318"></a><a name="p620173011318"></a>void Enable ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p52093073119"><a name="p52093073119"></a><a name="p52093073119"></a>Enables the button.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section22501726193214"></a>

1.  Implement the click event.

    ```
    class TestBtnOnClickListener : public OHOS::UIView::OnClickListener {
        bool OnClick(UIView& view, const ClickEvent& event) override
        {
            int16_t width = view.GetWidth() + 10;
            int16_t height = view.GetHeight() + 10;
            view.Resize(width, height);
            view.Invalidate();
            return true;
        }
    };
    ```

2.  Create a  **UIButton**  instance.

    ```
    UIButton* button = new UIButton();
    button->SetPosition(50, 50);
    button->SetWidth(100);
    button->SetHeight(50);
    ```

3.  Register the click event callback for  **UIButton**.

    ```
    button->SetOnClickListener(new TestBtnOnClickListener());
    ```

4.  Verify that the button is clicked and its size increases gradually, as shown in the following figure.

    **Figure  2**  Effect of clicking a  **UIButton**<a name="fig1921134162020"></a>  
    ![](figures/effect-of-clicking-a-uibutton.gif "effect-of-clicking-a-uibutton")


## UIImageView<a name="section19523161611259"></a>

## When to Use<a name="section1274484210400"></a>

**UIImageView**  supports the functions to display images, set opacity, rotate images, and zoom in or out images. The following image formats are supported: RGB565, RGB888, RGBA8888, PNG, and JPG.

## Available APIs<a name="section74981992411"></a>

**Table  2** Available functions  in UIImageView

<a name="table1584094244019"></a>
<table><thead align="left"><tr id="row483811426401"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1883814294017"><a name="p1883814294017"></a><a name="p1883814294017"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p168383425408"><a name="p168383425408"></a><a name="p168383425408"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row198391442134016"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1383934284013"><a name="p1383934284013"></a><a name="p1383934284013"></a>void SetSrc (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16839204211400"><a name="p16839204211400"></a><a name="p16839204211400"></a>Sets the image path with binary data.</p>
</td>
</tr>
<tr id="row9839642194011"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6839194218409"><a name="p6839194218409"></a><a name="p6839194218409"></a>void SetSrc (const ImageInfo *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1483944218401"><a name="p1483944218401"></a><a name="p1483944218401"></a>Sets the pointer to image information.</p>
</td>
</tr>
<tr id="row158391342194014"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p188395427401"><a name="p188395427401"></a><a name="p188395427401"></a>void SetAutoEnable (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15839642204010"><a name="p15839642204010"></a><a name="p15839642204010"></a>Sets whether the component size adapts to the image size.</p>
</td>
</tr>
<tr id="row4839342154012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11839142154019"><a name="p11839142154019"></a><a name="p11839142154019"></a>const void* GetSrcType () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p283913422406"><a name="p283913422406"></a><a name="p283913422406"></a>Obtains the image type.</p>
</td>
</tr>
<tr id="row283918426406"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14839134217401"><a name="p14839134217401"></a><a name="p14839134217401"></a>bool GetAutoEnable () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p58391242154014"><a name="p58391242154014"></a><a name="p58391242154014"></a>Checks whether the component size adapts to the image size.</p>
</td>
</tr>
<tr id="row183912426406"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p78391242134016"><a name="p78391242134016"></a><a name="p78391242134016"></a>void SetBlurLevel(BlurLevel level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p38391342174018"><a name="p38391342174018"></a><a name="p38391342174018"></a>Sets the blur level for the image background.</p>
</td>
</tr>
<tr id="row9840842174012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3839442184018"><a name="p3839442184018"></a><a name="p3839442184018"></a>BlurLevel GetBlurLevel() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4840342134016"><a name="p4840342134016"></a><a name="p4840342134016"></a>Obtains the blur level of the image background.</p>
</td>
</tr>
<tr id="row184015424405"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13840144214405"><a name="p13840144214405"></a><a name="p13840144214405"></a>void SetTransformAlgorithm(TransformAlgorithm algorithm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1284034224016"><a name="p1284034224016"></a><a name="p1284034224016"></a>Sets the transformation algorithm.</p>
</td>
</tr>
<tr id="row1484064244017"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11840204211402"><a name="p11840204211402"></a><a name="p11840204211402"></a>TransformAlgorithm GetTransformAlgorithm() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5840124219407"><a name="p5840124219407"></a><a name="p5840124219407"></a>Obtains the transformation algorithm.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop \(Adaptive Mode\)<a name="section144341333134114"></a>

1.  Create a  **UIImageView**  instance.

    ```
    UIImageView* imageView = new UIImageView();
    imageView->SetPosition(0, 30);
    ```

2.  Set the image path with binary data.

    ```
    imageView->SetSrc("..\\config\\images\\A021_001.bin");
    ```

3.  Verify that the  **UIImageView**  component is adaptive to the image.

    **Figure  3**  Image auto-adaption effect<a name="fig64751933144118"></a>  
    ![](figures/image-auto-adaption-effect.png "image-auto-adaption-effect")


## How to Develop \(Tile Mode\)<a name="section97178160421"></a>

1.  Create a  **UIImageView**  instance.

    ```
    UIImageView* imageView = new UIImageView();
    imageView->SetPosition(0, 30);
    ```

2.  Set the image path.

    ```
    imageView->SetSrc("..\\config\\images\\A021_001.bin");
    ```

3.  Disable the image auto-adaptation effect and resize the image to display the image in tile mode.

    ```
    imageView->SetAutoEnable(false);
    imageView->Resize(454, 150);
    ```

4.  Verify that the tile mode has been enabled for the  **UIImageView**.

    **Figure  4**  Image tile effect<a name="fig1075461619424"></a>  
    ![](figures/image-tile-effect.png "image-tile-effect")


## UILabel<a name="section16588132012911"></a>

## When to Use<a name="section6870195634218"></a>

**UILabel**  displays text in an area. You can set the background color, text display style, and long text display effect for a label.

## Available APIs<a name="section2012714510433"></a>

**Table  3** Available functions  in UILabel

<a name="table9571115310551"></a>
<table><thead align="left"><tr id="row13571155335511"><th class="cellrowborder" valign="top" width="46.37%" id="mcps1.2.3.1.1"><p id="p057195365510"><a name="p057195365510"></a><a name="p057195365510"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="53.63%" id="mcps1.2.3.1.2"><p id="p15717538555"><a name="p15717538555"></a><a name="p15717538555"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18571195317556"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p3571185305517"><a name="p3571185305517"></a><a name="p3571185305517"></a>void SetText(const char* text);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p757119532556"><a name="p757119532556"></a><a name="p757119532556"></a>Sets text for the label.</p>
</td>
</tr>
<tr id="row7572175325513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1857216534552"><a name="p1857216534552"></a><a name="p1857216534552"></a>const char* GetText() const;</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p85721653105514"><a name="p85721653105514"></a><a name="p85721653105514"></a>Obtains text of the label.</p>
</td>
</tr>
<tr id="row105721153175516"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p3572195312555"><a name="p3572195312555"></a><a name="p3572195312555"></a>void SetLineBreakMode(const uint8_t lineBreakMode);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p1757215316557"><a name="p1757215316557"></a><a name="p1757215316557"></a>Sets the label mode, such as truncation and automatic extension.</p>
</td>
</tr>
<tr id="row957211531555"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p195721953105517"><a name="p195721953105517"></a><a name="p195721953105517"></a>uint8_t GetLineBreakMode() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p4572853175514"><a name="p4572853175514"></a><a name="p4572853175514"></a>Obtains the label mode.</p>
</td>
</tr>
<tr id="row257225313559"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p35721253155516"><a name="p35721253155516"></a><a name="p35721253155516"></a>void SetTextColor(ColorType color)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p145724539550"><a name="p145724539550"></a><a name="p145724539550"></a>Set the text color.</p>
</td>
</tr>
<tr id="row105721253175517"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p125722538551"><a name="p125722538551"></a><a name="p125722538551"></a>ColorType GetTextColor() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p9572753205515"><a name="p9572753205515"></a><a name="p9572753205515"></a>Obtains the text color.</p>
</td>
</tr>
<tr id="row757265320558"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p10572185345516"><a name="p10572185345516"></a><a name="p10572185345516"></a>void SetAlign(UITextLanguageAlignment horizontalAlign,</p>
<p id="p135721653115514"><a name="p135721653115514"></a><a name="p135721653115514"></a>UITextLanguageAlignment verticalAlign = TEXT_ALIGNMENT_TOP);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p18572105335516"><a name="p18572105335516"></a><a name="p18572105335516"></a>Sets the text alignment mode.</p>
</td>
</tr>
<tr id="row6572553105518"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p175721253165515"><a name="p175721253165515"></a><a name="p175721253165515"></a>UITextLanguageAlignment GetHorAlign() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p857395313555"><a name="p857395313555"></a><a name="p857395313555"></a>Obtains the horizontal alignment mode of text.</p>
</td>
</tr>
<tr id="row1657320534557"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p75731853115511"><a name="p75731853115511"></a><a name="p75731853115511"></a>UITextLanguageAlignment GetVerAlign() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p5573953195514"><a name="p5573953195514"></a><a name="p5573953195514"></a>Obtains the vertical alignment mode of text.</p>
</td>
</tr>
<tr id="row7573125318554"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1957355345516"><a name="p1957355345516"></a><a name="p1957355345516"></a>void SetDirect(UITextLanguageDirect direct)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p95731753135519"><a name="p95731753135519"></a><a name="p95731753135519"></a>Sets the text display direction.</p>
</td>
</tr>
<tr id="row145736533559"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p12573145311555"><a name="p12573145311555"></a><a name="p12573145311555"></a>UITextLanguageDirect GetDirect() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157375316552"><a name="p157375316552"></a><a name="p157375316552"></a>Obtains the text display direction.</p>
</td>
</tr>
<tr id="row1857375315553"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p4573185385519"><a name="p4573185385519"></a><a name="p4573185385519"></a>void SetFontId(uint8_t fontId);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p657345318554"><a name="p657345318554"></a><a name="p657345318554"></a>Sets the dynamic font ID.</p>
</td>
</tr>
<tr id="row7573175310550"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p7573155310558"><a name="p7573155310558"></a><a name="p7573155310558"></a>uint8_t GetFontId() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157312534551"><a name="p157312534551"></a><a name="p157312534551"></a>Obtains the dynamic font ID.</p>
</td>
</tr>
<tr id="row7573105345519"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1573185314559"><a name="p1573185314559"></a><a name="p1573185314559"></a>void SetFont(const char *name, uint8_t size);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p45736536559"><a name="p45736536559"></a><a name="p45736536559"></a>Sets the font name and size.</p>
</td>
</tr>
<tr id="row257355317551"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p205731953125520"><a name="p205731953125520"></a><a name="p205731953125520"></a>void SetAnimatorSpeed(uint16_t animSpeed);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p15573155318551"><a name="p15573155318551"></a><a name="p15573155318551"></a>Sets the font rotation speed.</p>
</td>
</tr>
<tr id="row1557413530552"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p657435365518"><a name="p657435365518"></a><a name="p657435365518"></a>uint16_t GetTextWidth();</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p75740538554"><a name="p75740538554"></a><a name="p75740538554"></a>Obtains the font width.</p>
</td>
</tr>
<tr id="row10574155314557"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p2057425385510"><a name="p2057425385510"></a><a name="p2057425385510"></a>uint16_t GetTextHeight();</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p12574135365514"><a name="p12574135365514"></a><a name="p12574135365514"></a>Obtains the font height.</p>
</td>
</tr>
<tr id="row1257413534553"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p05741553125511"><a name="p05741553125511"></a><a name="p05741553125511"></a>void SetRollStartPos(int16_t pos)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p757411538558"><a name="p757411538558"></a><a name="p757411538558"></a>Sets the rotation position.</p>
</td>
</tr>
<tr id="row195749536552"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p65741253115518"><a name="p65741253115518"></a><a name="p65741253115518"></a>int16_t GetRollStartPos() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p3574185319552"><a name="p3574185319552"></a><a name="p3574185319552"></a>Obtains the rotation position.</p>
</td>
</tr>
<tr id="row35741453155518"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p757415535558"><a name="p757415535558"></a><a name="p757415535558"></a>void SetTextRotation(LabelRotateDegree angle)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157416532558"><a name="p157416532558"></a><a name="p157416532558"></a>Sets the enumerated value of the text rotation angle.</p>
</td>
</tr>
<tr id="row175741753165513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p157425385516"><a name="p157425385516"></a><a name="p157425385516"></a>LabelRotateDegree GetTextRotation() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p1357425365518"><a name="p1357425365518"></a><a name="p1357425365518"></a>Obtains the enumerated value of the text rotation angle.</p>
</td>
</tr>
<tr id="row5574185335513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1157455325519"><a name="p1157455325519"></a><a name="p1157455325519"></a>uint16_t GetTextRotateDegree() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p16574115318551"><a name="p16574115318551"></a><a name="p16574115318551"></a>Obtains the number of text rotation degrees.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop \(Default Mode\)<a name="section83221538114410"></a>

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the text.

    ```
    label->SetText("label");
    ```

4.  Verify the label size and display effect, as shown in the following figure.

    ![](figures/en-us_image_0000001051782526.png)


## How to Develop \(Background Color and Opacity\)<a name="section933360204510"></a>

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the background color and opacity.

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_BACKGROUND_OPA, 127);
    label->SetText("Label");
    ```

4.  Verify that the background color of the label is  **Gray**, as shown in the following figure.

    ![](figures/en-us_image_0000001052582522.png)


## How to Develop \(Letter Spacing\)<a name="section19447826124518"></a>

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the font color and letter spacing.

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_LETTER_SPACE, 5);
    label->SetText("Label");
    ```

4.  Verify that the letter spacing is  **5**  pixels on the label, as shown in the following figure.

    ![](figures/en-us_image_0000001052942531.png)


## How to Develop \(Size-Adaptive Mode\)<a name="section101711842154617"></a>

Regarding too long text, the size of a label can be automatically adjusted based on the text, or the text can be truncated or displayed with the scrolling effect.

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the font color to  **Gray**  and enable the label size to adapt to the text.

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetLineBreakMode(UILabel::LINE_BREAK_ADAPT);
    label->SetText("123\n567890");
    ```

4.  Verify that the label size adapts to the text, as shown in the following figure.

    ![](figures/en-us_image_0000001052782555.png)


## How to Develop \(Ellipsis Mode\)<a name="section1249519410471"></a>

In  ellipsis  mode, an ellipsis \(...\) is displayed at the end of the label if the text cannot be completely displayed.

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the text display mode to  **LINE\_BREAK\_ELLIPSIS**.

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetLineBreakMode(UILabel::LINE_BREAK_ELLIPSIS);
    label->SetText("123567890");
    ```

4.  Verify that the ellipsis mode has taken effect on the label, as shown in the following figure.

    ![](figures/en-us_image_0000001052662559.png)


## How to Develop \(Scrolling Mode\)<a name="section15643122618478"></a>

In scrolling mode, long text is kept scrolling on a screen to bring the entire text into view.

1.  Create a  **lUILabel**  instance and set its size and position.

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  Set the font.

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  Set the text display mode to  **UI\_LABEL\_LONG\_ROLL**.

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_BACKGROUND_OPA, 127);
    label->SetLineBreakMode(UILabel::LINE_BREAK_MARQUEE);
    label->SetText("123567890");
    ```

4.  Verify that the text is scrolling on the label, as shown in the following figure.

    ![](figures/20200721-223604(espace).gif)


