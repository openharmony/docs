# 普通组件开发指导<a name="ZH-CN_TOPIC_0000001052170409"></a>



普通组件均继承于基类UIView，不可以添加子组件，常用的普通组件有button、image、label等。

**图 1**  普通组件树结构<a name="fig3386518305"></a>  
![](figure/普通组件树结构.png "普通组件树结构")

UIView为基础类，UIAbstractProgress、UIArcLabel（旋转字体）、UIButton（按键）、UICanvas（画布）、UILabel（字体）、UIImageView（图片）从UIView继承。UIBoxProgress、UICircleProgress从UIAbstractProgress继承，UILabelButton和UIRepeatButton从UIButton继承，UIImageAnimatorView和UITextureMapper从UIImageView继承。

## UIButton<a name="section145353310214"></a>

## 使用场景<a name="section1169616141577"></a>

UIButton组件，提供可点击功能，同时可设置不同状态下样式。

## 接口说明<a name="section341211538315"></a>

**表 1**  button接口说明

<a name="table172083013117"></a>
<table><thead align="left"><tr id="row13192303311"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1019330103113"><a name="p1019330103113"></a><a name="p1019330103113"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p181963020318"><a name="p181963020318"></a><a name="p181963020318"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row191914306313"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p161963010314"><a name="p161963010314"></a><a name="p161963010314"></a>void SetImageSrc (const char *defaultImgSrc, const char *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1619143014312"><a name="p1619143014312"></a><a name="p1619143014312"></a>设置button图片</p>
</td>
</tr>
<tr id="row141915307313"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p419193017312"><a name="p419193017312"></a><a name="p419193017312"></a>void SetImagePosition (const int16_t x, const int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p919030173119"><a name="p919030173119"></a><a name="p919030173119"></a>设置button图片位置</p>
</td>
</tr>
<tr id="row1119930183115"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1619430193110"><a name="p1619430193110"></a><a name="p1619430193110"></a>int16_t GetImageX () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p151933012315"><a name="p151933012315"></a><a name="p151933012315"></a>获取图片X坐标</p>
</td>
</tr>
<tr id="row62083017317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p122093053112"><a name="p122093053112"></a><a name="p122093053112"></a>int16_t GetImageY () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p62016307314"><a name="p62016307314"></a><a name="p62016307314"></a>获取图片Y坐标</p>
</td>
</tr>
<tr id="row72013013114"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p720203016314"><a name="p720203016314"></a><a name="p720203016314"></a>const ImageInfo* GetCurImageSrc() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1201730123116"><a name="p1201730123116"></a><a name="p1201730123116"></a>获取当前状态图片</p>
</td>
</tr>
<tr id="row320103017318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12010308314"><a name="p12010308314"></a><a name="p12010308314"></a>Style&amp;  GetStyleForState (ButtonState state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17201030133117"><a name="p17201030133117"></a><a name="p17201030133117"></a>设置button当前状态的style</p>
</td>
</tr>
<tr id="row420730193117"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11201830183112"><a name="p11201830183112"></a><a name="p11201830183112"></a>voidSetStyleForState (const Style &amp;style, ButtonState state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p82016308311"><a name="p82016308311"></a><a name="p82016308311"></a>设置button指定状态的style</p>
</td>
</tr>
<tr id="row1320193010317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1020153014319"><a name="p1020153014319"></a><a name="p1020153014319"></a>void Disable ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p192063023119"><a name="p192063023119"></a><a name="p192063023119"></a>去使能button</p>
</td>
</tr>
<tr id="row02017308315"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p620173011318"><a name="p620173011318"></a><a name="p620173011318"></a>void Enable ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p52093073119"><a name="p52093073119"></a><a name="p52093073119"></a>使能button</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section22501726193214"></a>

1.  实现点击事件。

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

2.  创建一个UIButton。

    ```
    UIButton* button = new UIButton();
    button->SetPosition(50, 50);
    button->SetWidth(100);
    button->SetHeight(50);
    ```

3.  给UIButton注册点击事件回调。

    ```
    button->SetOnClickListener(new TestBtnOnClickListener());
    ```

4.  检查Button点击效果如下图所示，Button逐渐变大。

    **图 2**  UIButton点击效果<a name="fig1921134162020"></a>  
    ![](figure/UIButton点击效果.gif "UIButton点击效果")


## UIImageView<a name="section19523161611259"></a>

## 使用场景<a name="section1274484210400"></a>

图片组件，提供图片显示，透明度设置，图片旋转、缩放功能。支持的图片格式为RGB565、RGB888、RGBA8888、PNG、JPG。

## 接口说明<a name="section74981992411"></a>

**表 2**  image接口说明

<a name="table1584094244019"></a>
<table><thead align="left"><tr id="row483811426401"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1883814294017"><a name="p1883814294017"></a><a name="p1883814294017"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p168383425408"><a name="p168383425408"></a><a name="p168383425408"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row198391442134016"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1383934284013"><a name="p1383934284013"></a><a name="p1383934284013"></a>void SetSrc (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16839204211400"><a name="p16839204211400"></a><a name="p16839204211400"></a>设置二进制图片路径</p>
</td>
</tr>
<tr id="row9839642194011"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6839194218409"><a name="p6839194218409"></a><a name="p6839194218409"></a>void SetSrc (const ImageInfo *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1483944218401"><a name="p1483944218401"></a><a name="p1483944218401"></a>设置图片指针</p>
</td>
</tr>
<tr id="row158391342194014"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p188395427401"><a name="p188395427401"></a><a name="p188395427401"></a>void SetAutoEnable (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p15839642204010"><a name="p15839642204010"></a><a name="p15839642204010"></a>设置组件大小跟随image大小变化</p>
</td>
</tr>
<tr id="row4839342154012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11839142154019"><a name="p11839142154019"></a><a name="p11839142154019"></a>const void* GetSrcType () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p283913422406"><a name="p283913422406"></a><a name="p283913422406"></a>获取图片类型</p>
</td>
</tr>
<tr id="row283918426406"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14839134217401"><a name="p14839134217401"></a><a name="p14839134217401"></a>bool GetAutoEnable () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p58391242154014"><a name="p58391242154014"></a><a name="p58391242154014"></a>获取组件大小是否跟随image大小变化</p>
</td>
</tr>
<tr id="row183912426406"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p78391242134016"><a name="p78391242134016"></a><a name="p78391242134016"></a>void SetBlurLevel(BlurLevel level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p38391342174018"><a name="p38391342174018"></a><a name="p38391342174018"></a>设置模糊等级</p>
</td>
</tr>
<tr id="row9840842174012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3839442184018"><a name="p3839442184018"></a><a name="p3839442184018"></a>BlurLevel GetBlurLevel() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4840342134016"><a name="p4840342134016"></a><a name="p4840342134016"></a>获取模糊等级</p>
</td>
</tr>
<tr id="row184015424405"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13840144214405"><a name="p13840144214405"></a><a name="p13840144214405"></a>void SetTransformAlgorithm(TransformAlgorithm algorithm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1284034224016"><a name="p1284034224016"></a><a name="p1284034224016"></a>设置旋转算法</p>
</td>
</tr>
<tr id="row1484064244017"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11840204211402"><a name="p11840204211402"></a><a name="p11840204211402"></a>TransformAlgorithm GetTransformAlgorithm() const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5840124219407"><a name="p5840124219407"></a><a name="p5840124219407"></a>获取旋转算法</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤（自适应）<a name="section144341333134114"></a>

1.  创建一个UIImageView。

    ```
    UIImageView* imageView = new UIImageView();
    imageView->SetPosition(0, 30);
    ```

2.  设置二进制格式的图片。

    ```
    imageView->SetSrc("..\\config\\images\\A021_001.bin");
    ```

3.  检查UIImageView控件大小与图片相同。

    **图 3**  自适应模式图片效果图<a name="fig64751933144118"></a>  
    ![](figure/自适应模式图片效果图.png "自适应模式图片效果图")


## 开发步骤（平铺模式）<a name="section97178160421"></a>

1.  创建一个UIImageView。

    ```
    UIImageView* imageView = new UIImageView();
    imageView->SetPosition(0, 30);
    ```

2.  设置图片。

    ```
    imageView->SetSrc("..\\config\\images\\A021_001.bin");
    ```

3.  取消图片自适应，设置图片大小，平铺显示效果。

    ```
    imageView->SetAutoEnable(false);
    imageView->Resize(454, 150);
    ```

4.  检查UIImageView控件显示为平铺效果。

    **图 4**  平铺模式图片效果图<a name="fig1075461619424"></a>  
    ![](figure/平铺模式图片效果图.png "平铺模式图片效果图")


## UILabel<a name="section16588132012911"></a>

## 使用场景<a name="section6870195634218"></a>

标签（label）是在一块区域上显示文本字符串的组件，可设置区域背景色、文字的显示样式和长文本的显示效果等。

## 接口说明<a name="section2012714510433"></a>

**表 3**  label接口说明

<a name="table9571115310551"></a>
<table><thead align="left"><tr id="row13571155335511"><th class="cellrowborder" valign="top" width="46.37%" id="mcps1.2.3.1.1"><p id="p057195365510"><a name="p057195365510"></a><a name="p057195365510"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="53.63%" id="mcps1.2.3.1.2"><p id="p15717538555"><a name="p15717538555"></a><a name="p15717538555"></a>功能</p>
</th>
</tr>
</thead>
<tbody><tr id="row18571195317556"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p3571185305517"><a name="p3571185305517"></a><a name="p3571185305517"></a>void SetText(const char* text);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p757119532556"><a name="p757119532556"></a><a name="p757119532556"></a>设置文字</p>
</td>
</tr>
<tr id="row7572175325513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1857216534552"><a name="p1857216534552"></a><a name="p1857216534552"></a>const char* GetText() const;</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p85721653105514"><a name="p85721653105514"></a><a name="p85721653105514"></a>获取text</p>
</td>
</tr>
<tr id="row105721153175516"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p3572195312555"><a name="p3572195312555"></a><a name="p3572195312555"></a>void SetLineBreakMode(const uint8_t lineBreakMode);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p1757215316557"><a name="p1757215316557"></a><a name="p1757215316557"></a>设置label模式，例如截断，自动扩展等。</p>
</td>
</tr>
<tr id="row957211531555"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p195721953105517"><a name="p195721953105517"></a><a name="p195721953105517"></a>uint8_t GetLineBreakMode() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p4572853175514"><a name="p4572853175514"></a><a name="p4572853175514"></a>获取label模式</p>
</td>
</tr>
<tr id="row257225313559"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p35721253155516"><a name="p35721253155516"></a><a name="p35721253155516"></a>void SetTextColor(ColorType color)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p145724539550"><a name="p145724539550"></a><a name="p145724539550"></a>设置文本颜色</p>
</td>
</tr>
<tr id="row105721253175517"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p125722538551"><a name="p125722538551"></a><a name="p125722538551"></a>ColorType GetTextColor() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p9572753205515"><a name="p9572753205515"></a><a name="p9572753205515"></a>获取文本颜色</p>
</td>
</tr>
<tr id="row757265320558"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p10572185345516"><a name="p10572185345516"></a><a name="p10572185345516"></a>void SetAlign(UITextLanguageAlignment horizontalAlign,</p>
<p id="p135721653115514"><a name="p135721653115514"></a><a name="p135721653115514"></a>UITextLanguageAlignment verticalAlign = TEXT_ALIGNMENT_TOP);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p18572105335516"><a name="p18572105335516"></a><a name="p18572105335516"></a>设置文本对齐方式</p>
</td>
</tr>
<tr id="row6572553105518"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p175721253165515"><a name="p175721253165515"></a><a name="p175721253165515"></a>UITextLanguageAlignment GetHorAlign() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p857395313555"><a name="p857395313555"></a><a name="p857395313555"></a>获取文本水平对齐方式</p>
</td>
</tr>
<tr id="row1657320534557"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p75731853115511"><a name="p75731853115511"></a><a name="p75731853115511"></a>UITextLanguageAlignment GetVerAlign() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p5573953195514"><a name="p5573953195514"></a><a name="p5573953195514"></a>获取文本竖直对齐方式</p>
</td>
</tr>
<tr id="row7573125318554"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1957355345516"><a name="p1957355345516"></a><a name="p1957355345516"></a>void SetDirect(UITextLanguageDirect direct)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p95731753135519"><a name="p95731753135519"></a><a name="p95731753135519"></a>设置文本显示方向</p>
</td>
</tr>
<tr id="row145736533559"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p12573145311555"><a name="p12573145311555"></a><a name="p12573145311555"></a>UITextLanguageDirect GetDirect() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157375316552"><a name="p157375316552"></a><a name="p157375316552"></a>获取文本显示方向</p>
</td>
</tr>
<tr id="row1857375315553"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p4573185385519"><a name="p4573185385519"></a><a name="p4573185385519"></a>void SetFontId(uint8_t fontId);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p657345318554"><a name="p657345318554"></a><a name="p657345318554"></a>设置动态字体id</p>
</td>
</tr>
<tr id="row7573175310550"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p7573155310558"><a name="p7573155310558"></a><a name="p7573155310558"></a>uint8_t GetFontId() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157312534551"><a name="p157312534551"></a><a name="p157312534551"></a>获取动态字体id</p>
</td>
</tr>
<tr id="row7573105345519"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1573185314559"><a name="p1573185314559"></a><a name="p1573185314559"></a>void SetFont(const char *name, uint8_t size);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p45736536559"><a name="p45736536559"></a><a name="p45736536559"></a>设置字的名字和大小</p>
</td>
</tr>
<tr id="row257355317551"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p205731953125520"><a name="p205731953125520"></a><a name="p205731953125520"></a>void SetAnimatorSpeed(uint16_t animSpeed);</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p15573155318551"><a name="p15573155318551"></a><a name="p15573155318551"></a>设置字体旋转的速度</p>
</td>
</tr>
<tr id="row1557413530552"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p657435365518"><a name="p657435365518"></a><a name="p657435365518"></a>uint16_t GetTextWidth();</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p75740538554"><a name="p75740538554"></a><a name="p75740538554"></a>获取字体的宽</p>
</td>
</tr>
<tr id="row10574155314557"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p2057425385510"><a name="p2057425385510"></a><a name="p2057425385510"></a>uint16_t GetTextHeight();</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p12574135365514"><a name="p12574135365514"></a><a name="p12574135365514"></a>获取字体的高</p>
</td>
</tr>
<tr id="row1257413534553"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p05741553125511"><a name="p05741553125511"></a><a name="p05741553125511"></a>void SetRollStartPos(int16_t pos)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p757411538558"><a name="p757411538558"></a><a name="p757411538558"></a>设置旋转的位置</p>
</td>
</tr>
<tr id="row195749536552"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p65741253115518"><a name="p65741253115518"></a><a name="p65741253115518"></a>int16_t GetRollStartPos() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p3574185319552"><a name="p3574185319552"></a><a name="p3574185319552"></a>获取旋转的位置</p>
</td>
</tr>
<tr id="row35741453155518"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p757415535558"><a name="p757415535558"></a><a name="p757415535558"></a>void SetTextRotation(LabelRotateDegree angle)</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p157416532558"><a name="p157416532558"></a><a name="p157416532558"></a>设置文本旋转角度枚举值</p>
</td>
</tr>
<tr id="row175741753165513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p157425385516"><a name="p157425385516"></a><a name="p157425385516"></a>LabelRotateDegree GetTextRotation() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p1357425365518"><a name="p1357425365518"></a><a name="p1357425365518"></a>获取文本旋转角度枚举值</p>
</td>
</tr>
<tr id="row5574185335513"><td class="cellrowborder" valign="top" width="46.37%" headers="mcps1.2.3.1.1 "><p id="p1157455325519"><a name="p1157455325519"></a><a name="p1157455325519"></a>uint16_t GetTextRotateDegree() const</p>
</td>
<td class="cellrowborder" valign="top" width="53.63%" headers="mcps1.2.3.1.2 "><p id="p16574115318551"><a name="p16574115318551"></a><a name="p16574115318551"></a>获取文本旋转角度数值</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤（默认模式）<a name="section83221538114410"></a>

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置文本数据。

    ```
    label->SetText("label");
    ```

4.  检查label大小和显示效果正常，如下图所示。

    ![](figure/zh-cn_image_0000001051782526.png)


## 开发步骤（背景色和透明度）<a name="section933360204510"></a>

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置背景颜色及透明度效果。

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_BACKGROUND_OPA, 127);
    label->SetText("Label");
    ```

4.  检查label背景色为Gray，如下图所示。

    ![](figure/zh-cn_image_0000001052582522.png)


## 开发步骤（字符间距）<a name="section19447826124518"></a>

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置字体颜色和字间距效果。

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_LETTER_SPACE, 5);
    label->SetText("Label");
    ```

4.  检查label字符间距为5，如下图所示。

    ![](figure/zh-cn_image_0000001052942531.png)


## 开发步骤（大小自适应）<a name="section101711842154617"></a>

当文本过长时，可根据文本信息自动调整label组件大小，也可以设置文本截断或者文本滚动效果。

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置字体颜色为Gray，组件大小自适应文本内容。

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetLineBreakMode(UILabel::LINE_BREAK_ADAPT);
    label->SetText("123\n567890");
    ```

4.  检查label大小自适应文本内容，如下图所示。

    ![](figure/zh-cn_image_0000001052782555.png)


## 开发步骤（省略号模式）<a name="section1249519410471"></a>

省略号模式指文本内容显示不下时，在末尾显示省略号。

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置换行模式为DOT模式

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetLineBreakMode(UILabel::LINE_BREAK_ELLIPSIS);
    label->SetText("123567890");
    ```

4.  检查label DOT模式效果，如下图所示，末尾显示省略号。

    ![](figure/zh-cn_image_0000001052662559.png)


## 开发步骤（滚动模式）<a name="section15643122618478"></a>

文本滚动显示。

1.  创建label，设置大小和位置信息。

    ```
    UILabel* label = new UILabel();
    label->SetPosition(x, y);
    label->Resize(width, height);
    ```

2.  设置字形信息。

    ```
    label->SetFont("SourceHanSansSC-Regular.otf", 30);
    ```

3.  设置换行模式为滚动模式

    ```
    label->SetStyle(STYLE_BACKGROUND_COLOR, Color::Gray().full);
    label->SetStyle(STYLE_BACKGROUND_OPA, 127);
    label->SetLineBreakMode(UILabel::LINE_BREAK_MARQUEE);
    label->SetText("123567890");
    ```

4.  检查label滚动模式效果，如下图所示。

    ![](figure/20200721-223604(eSpace).gif)


