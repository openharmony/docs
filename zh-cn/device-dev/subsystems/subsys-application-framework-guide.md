# 开发指导<a name="ZH-CN_TOPIC_0000001062229264"></a>

-   [场景介绍](#section93012287133)
-   [接口说明](#section11821047161319)
-   [开发步骤](#section10514141679)
    -   [创建Service类型的Ability](#section19921154214315)
    -   [包管理接口使用指导](#section1724016743217)
    -   [Hap包打包](#section171771212328)


## 场景介绍<a name="section93012287133"></a>

-   带界面的Ability的应用，比如：新闻类的应用、视频类的应用、导航类的应用、支付类的应用等等，目前我们看到的大部分应用都是带有界面的用于人机交互的应用。

-   不带界面的Ability应用，比如：音乐播放器能在后台播放音乐、后台提供计算服务、导航服务的各类应用等。

-   不管是带界面的Ability应用还是不带界面的Ability应用，都要打包成Hap包，最终发布到应用市场，用户通过应用市场下载安装相应的应用。

## 接口说明<a name="section11821047161319"></a>

**表 1**  Ability子系统的对外接口

<a name="table36761640135514"></a>
<table><thead align="left"><tr id="row570215713380"><th class="cellrowborder" valign="top" width="53.849999999999994%" id="mcps1.2.3.1.1"><p id="p1703155733819"><a name="p1703155733819"></a><a name="p1703155733819"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="46.150000000000006%" id="mcps1.2.3.1.2"><p id="p37035579380"><a name="p37035579380"></a><a name="p37035579380"></a>接口描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row39211240205510"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p49215401550"><a name="p49215401550"></a><a name="p49215401550"></a>Want *WantParseUri(const char *uri)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592164014553"><a name="p592164014553"></a><a name="p592164014553"></a>反序列化接口，由字符串生成Want对象。</p>
</td>
</tr>
<tr id="row192154055512"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p139212040175520"><a name="p139212040175520"></a><a name="p139212040175520"></a>const char *WantToUri(Want want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9921640135519"><a name="p9921640135519"></a><a name="p9921640135519"></a>序列化，把Want对象生成字符串。</p>
</td>
</tr>
<tr id="row16921440135520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1892124075519"><a name="p1892124075519"></a><a name="p1892124075519"></a>void SetWantElement(Want *want, ElementName element);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p129214403555"><a name="p129214403555"></a><a name="p129214403555"></a>设置ElementName对象。</p>
</td>
</tr>
<tr id="row3921114018552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p79210404555"><a name="p79210404555"></a><a name="p79210404555"></a>void SetWantData(Want *want, const void *data, uint16_t dataLength)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p09218402559"><a name="p09218402559"></a><a name="p09218402559"></a>设置数据。</p>
</td>
</tr>
<tr id="row892124013556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4921040155510"><a name="p4921040155510"></a><a name="p4921040155510"></a>bool SetWantSvcIdentity(Want *want, SvcIdentity sid)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p992204013553"><a name="p992204013553"></a><a name="p992204013553"></a>设置SvcIdentity。</p>
</td>
</tr>
<tr id="row99221840135520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p139221840155519"><a name="p139221840155519"></a><a name="p139221840155519"></a>void ClearWant(Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79221440185511"><a name="p79221440185511"></a><a name="p79221440185511"></a>清除Want的内部内存数据。</p>
</td>
</tr>
<tr id="row69221640125519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792244017555"><a name="p1792244017555"></a><a name="p1792244017555"></a>void SetMainRoute(const std::string &amp;entry)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p7922174016558"><a name="p7922174016558"></a><a name="p7922174016558"></a>设置AbilitySlice主路由。</p>
</td>
</tr>
<tr id="row189221840165516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p3922340125511"><a name="p3922340125511"></a><a name="p3922340125511"></a>void SetUIContent(RootView *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9922240175511"><a name="p9922240175511"></a><a name="p9922240175511"></a>设置布局资源。</p>
</td>
</tr>
<tr id="row159226407552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1292213402552"><a name="p1292213402552"></a><a name="p1292213402552"></a>void OnStart(const Want&amp; intent)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p14922440195515"><a name="p14922440195515"></a><a name="p14922440195515"></a>Ability生命周期状态回调，Ability启动时被回调。</p>
</td>
</tr>
<tr id="row1392217402551"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1292284065516"><a name="p1292284065516"></a><a name="p1292284065516"></a>void OnStop()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p149223403554"><a name="p149223403554"></a><a name="p149223403554"></a>Ability生命周期状态回调，Ability销毁时被回调。</p>
</td>
</tr>
<tr id="row169221407555"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p992218400556"><a name="p992218400556"></a><a name="p992218400556"></a>void OnActive(const Want&amp; intent)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1923440135515"><a name="p1923440135515"></a><a name="p1923440135515"></a>Ability生命周期状态回调，Ability显示时被回调。</p>
</td>
</tr>
<tr id="row9923640205516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p19231340185511"><a name="p19231340185511"></a><a name="p19231340185511"></a>void OnInactive()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p992311408556"><a name="p992311408556"></a><a name="p992311408556"></a>Ability生命周期状态回调，Ability隐藏时被回调。</p>
</td>
</tr>
<tr id="row4923154015557"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p99233404556"><a name="p99233404556"></a><a name="p99233404556"></a>void OnBackground()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79238400554"><a name="p79238400554"></a><a name="p79238400554"></a>Ability生命周期状态回调，Ability退到后台时被回调。</p>
</td>
</tr>
<tr id="row14923144045513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p692354019558"><a name="p692354019558"></a><a name="p692354019558"></a>const SvcIdentity *OnConnect(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p17923154085512"><a name="p17923154085512"></a><a name="p17923154085512"></a>Service类型Ability第一次连接时被回调。</p>
</td>
</tr>
<tr id="row592313405552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1692312404551"><a name="p1692312404551"></a><a name="p1692312404551"></a>void OnDisconnect(const Want &amp;want);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p892394017551"><a name="p892394017551"></a><a name="p892394017551"></a>Service类型Ability断开连接被回调。</p>
</td>
</tr>
<tr id="row3923194075515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p5923240175516"><a name="p5923240175516"></a><a name="p5923240175516"></a>void MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p2923184055518"><a name="p2923184055518"></a><a name="p2923184055518"></a>Service类型Ability接收消息处理。</p>
</td>
</tr>
<tr id="row15923540155517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p99231940105514"><a name="p99231940105514"></a><a name="p99231940105514"></a>void Dump(const std::string &amp;extra)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p18924174016554"><a name="p18924174016554"></a><a name="p18924174016554"></a>dump Ability信息。</p>
</td>
</tr>
<tr id="row1792414055517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1592454025513"><a name="p1592454025513"></a><a name="p1592454025513"></a>void Present(AbilitySlice *abilitySlice, const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p11924104045517"><a name="p11924104045517"></a><a name="p11924104045517"></a>发起AbilitySlice跳转。</p>
</td>
</tr>
<tr id="row15924114012556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13924154017551"><a name="p13924154017551"></a><a name="p13924154017551"></a>void Terminate()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p11924104012557"><a name="p11924104012557"></a><a name="p11924104012557"></a>退出当前AbilitySlice。</p>
</td>
</tr>
<tr id="row2092484010558"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4924540155515"><a name="p4924540155515"></a><a name="p4924540155515"></a>void SetUIContent(RootView *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79241640185514"><a name="p79241640185514"></a><a name="p79241640185514"></a>设置当前AbilitySlice所在Ability的布局资源。</p>
</td>
</tr>
<tr id="row16924640195518"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p169245407559"><a name="p169245407559"></a><a name="p169245407559"></a>void OnStart(const Want&amp; want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p492494095517"><a name="p492494095517"></a><a name="p492494095517"></a>AbilitySlice生命周期状态回调，AbilitySlice启动时被回调。</p>
</td>
</tr>
<tr id="row15924154065513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p159242407559"><a name="p159242407559"></a><a name="p159242407559"></a>void OnStop()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p13924114017556"><a name="p13924114017556"></a><a name="p13924114017556"></a>AbilitySlice生命周期状态回调，AbilitySlice销毁时被回调。</p>
</td>
</tr>
<tr id="row13924154065517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p292494005513"><a name="p292494005513"></a><a name="p292494005513"></a>void OnActive(const Want&amp; want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p89256408553"><a name="p89256408553"></a><a name="p89256408553"></a>AbilitySlice生命周期状态回调，AbilitySlice显示时被回调。</p>
</td>
</tr>
<tr id="row1925540125515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13925114015514"><a name="p13925114015514"></a><a name="p13925114015514"></a>void OnInactive()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p892534025515"><a name="p892534025515"></a><a name="p892534025515"></a>AbilitySlice生命周期状态回调，AbilitySlice隐藏时被回调。</p>
</td>
</tr>
<tr id="row692519401558"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792515408558"><a name="p1792515408558"></a><a name="p1792515408558"></a>void OnBackground()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p292554013551"><a name="p292554013551"></a><a name="p292554013551"></a>AbilitySlice生命周期状态回调，AbilitySlice退到后台时被回调。</p>
</td>
</tr>
<tr id="row129251040115515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p0925174011553"><a name="p0925174011553"></a><a name="p0925174011553"></a>int StartAbility(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p129251408557"><a name="p129251408557"></a><a name="p129251408557"></a>启动Ability。</p>
</td>
</tr>
<tr id="row3925940195519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p19251440135512"><a name="p19251440135512"></a><a name="p19251440135512"></a>int StopAbility(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p19925174035510"><a name="p19925174035510"></a><a name="p19925174035510"></a>停止Service类型的Ability。</p>
</td>
</tr>
<tr id="row14925164055520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p14925114015553"><a name="p14925114015553"></a><a name="p14925114015553"></a>int TerminateAbility()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p39254405557"><a name="p39254405557"></a><a name="p39254405557"></a>销毁当前的Ability。</p>
</td>
</tr>
<tr id="row19925940115515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p892584015559"><a name="p892584015559"></a><a name="p892584015559"></a>int ConnectAbility(const Want &amp;want, const IAbilityConnection &amp;conn, void *data);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p4926640165513"><a name="p4926640165513"></a><a name="p4926640165513"></a>绑定Service类型的Ability。</p>
</td>
</tr>
<tr id="row10926540155513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p119267409559"><a name="p119267409559"></a><a name="p119267409559"></a>int DisconnectAbility(const IAbilityConnection &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592644085512"><a name="p592644085512"></a><a name="p592644085512"></a>解绑Service类型的Ability。</p>
</td>
</tr>
<tr id="row11926340145516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p892614035513"><a name="p892614035513"></a><a name="p892614035513"></a>const char *GetBundleName()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p99261040105511"><a name="p99261040105511"></a><a name="p99261040105511"></a>获取当前ability的对应应用的包名。</p>
</td>
</tr>
<tr id="row7926440125519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4926114065519"><a name="p4926114065519"></a><a name="p4926114065519"></a>const char *GetSrcPath()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p4926194055516"><a name="p4926194055516"></a><a name="p4926194055516"></a>获取当前ability的对应应用的安装路径。</p>
</td>
</tr>
<tr id="row29261840115519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1992604045519"><a name="p1992604045519"></a><a name="p1992604045519"></a>const char *GetDataPath()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p109268403551"><a name="p109268403551"></a><a name="p109268403551"></a>获取当前ability的对应应用的数据路径。</p>
</td>
</tr>
<tr id="row29261940195516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p159267407555"><a name="p159267407555"></a><a name="p159267407555"></a>int StartAbility(const Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1340210145179"><a name="p1340210145179"></a><a name="p1340210145179"></a>启动Ability，该接口可以不需要在基于Ability开发的应用中使用。</p>
</td>
</tr>
<tr id="row16926240155514"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792617404558"><a name="p1792617404558"></a><a name="p1792617404558"></a>int ConnectAbility(const Want *want, const IAbilityConnection *conn, void *data);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1092612181812"><a name="p1092612181812"></a><a name="p1092612181812"></a>绑定Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。</p>
</td>
</tr>
<tr id="row5927164010552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p49271540165510"><a name="p49271540165510"></a><a name="p49271540165510"></a>int DisconnectAbility(const IAbilityConnection *conn);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1296152820189"><a name="p1296152820189"></a><a name="p1296152820189"></a>解绑Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。</p>
</td>
</tr>
<tr id="row89271040135517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13927194011558"><a name="p13927194011558"></a><a name="p13927194011558"></a>int StopAbility(const Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p7699548131819"><a name="p7699548131819"></a><a name="p7699548131819"></a>停止Service类型的Ability，该接口可以不需要在基于Ability开发的应用中使用。</p>
</td>
</tr>
<tr id="row1992764065516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p192716406556"><a name="p192716406556"></a><a name="p192716406556"></a>void (*OnAbilityConnectDone)(ElementName *elementName, SvcIdentity *serviceSid, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p0927940195510"><a name="p0927940195510"></a><a name="p0927940195510"></a>绑定Service Ability的回调。</p>
</td>
</tr>
<tr id="row7927134010559"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p692764095510"><a name="p692764095510"></a><a name="p692764095510"></a>void (*OnAbilityDisconnectDone)(ElementName *elementName, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p18927124035516"><a name="p18927124035516"></a><a name="p18927124035516"></a>解绑Service Ability的回调。</p>
</td>
</tr>
<tr id="row692784020556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p17927104010557"><a name="p17927104010557"></a><a name="p17927104010557"></a>void PostTask(const Task&amp; task)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p13927940105516"><a name="p13927940105516"></a><a name="p13927940105516"></a>投递任务到异步线程进行处理。</p>
</td>
</tr>
<tr id="row392784013552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1092794014555"><a name="p1092794014555"></a><a name="p1092794014555"></a>void PostQuit()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p19281940185510"><a name="p19281940185510"></a><a name="p19281940185510"></a>退出当前线程的消息循环。</p>
</td>
</tr>
<tr id="row2928140145519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p292813401555"><a name="p292813401555"></a><a name="p292813401555"></a>static AbilityEventHandler* GetCurrentHandler()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9928154012554"><a name="p9928154012554"></a><a name="p9928154012554"></a>获取当前线程的事件处理器。</p>
</td>
</tr>
<tr id="row15928174035513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1692824017551"><a name="p1692824017551"></a><a name="p1692824017551"></a>void Run()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592820401558"><a name="p592820401558"></a><a name="p592820401558"></a>执行当前线程的消息循环。</p>
</td>
</tr>
<tr id="row15928174013554"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p17928440125516"><a name="p17928440125516"></a><a name="p17928440125516"></a>#define REGISTER_AA(className)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1892817404554"><a name="p1892817404554"></a><a name="p1892817404554"></a>注册开发者的Ability到框架中。</p>
</td>
</tr>
<tr id="row17928640135519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p199281640125520"><a name="p199281640125520"></a><a name="p199281640125520"></a>#define REGISTER_AS(className)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1792811409556"><a name="p1792811409556"></a><a name="p1792811409556"></a>注册开发者的AbilitySlice到框架中。</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section10514141679"></a>

### 创建Service类型的Ability<a name="section19921154214315"></a>

1.  在my\_service\_ability.h中创建Ability的子类MyServiceAbility。

    ```
    class MyServiceAbility: public Ability {
    protected:
        void OnStart(const Want& want);
        const SvcIdentity *OnConnect(const Want &want) override;
        void MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply) override;
    };
    ```

2.  调用REGISTER\_AA宏将ServiceAbility注册到应用框架中，以便应用框架实例化开发者的MyServiceAbility。

    ```
    #include "my_service_ability.h"
    
    REGISTER_AA(ServiceAbility)
    
    void MyServiceAbility::OnStart(const Want& want)
    {
        printf("ServiceAbility::OnStart\n");
        Ability::OnStart(want);
    }
    
    const SvcIdentity *MyServiceAbility::OnConnect(const Want &want)
    {
        printf("ServiceAbility::OnConnect\n");
        return Ability::OnConnect(want);
    }
    
    void MyServiceAbility::MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply)
    {
        printf("ServiceAbility::MsgHandle, funcId is %u\n", funcId);
        int result = 0;
        if (funcId == 0) {
            result = IpcIoPopInt32(request) + IpcIoPopInt32(request);
        }
        // push data
        IpcIoPushInt32(reply, result);
    }
    ```

3.  实现Service相关的生命周期方法。Service也是一种Ability，Ability为服务提供了以下生命周期方法，用户可以重写这些方法来添加自己的处理。用户在重写的方法里，需要调用父类对应的方法。
    -   OnStart\(\)

        该方法在创建Service的时候调用，用于做一些Service初始化且耗时较短的工作，在Service的整个生命周期只会调用一次。

        ```
        void MyServiceAbility::OnStart(const Want& want)
        {
            printf("ServiceAbility::OnStart\n");
            Ability::OnStart(want);
        }
        ```

    -   OnConnect​\(\)

        在组件和服务连接时调用，该方法返回SvcIdentity，组件可以通过它，与服务交互。

        ```
        const SvcIdentity *MyServiceAbility::OnConnect(const Want &want)
        {
            printf("ServiceAbility::OnConnect\n");
            return Ability::OnConnect(want);
        }
        ```

    -   OnDisconnect​\(\)

        在组件与绑定的Service断开连接时调用。

    -   OnStop\(\)

        在Service销毁时调用。Service应通过实现此方法来清理任何资源，如关闭线程、注册的侦听器等。

4.  重写消息处理方法。

    MsgHandle是Service用来处理客户端消息的方法。其中funcId是客户端传过来的消息类型，request是客户端传过来的序列化请求参数。如果用户在处理完成之后想要把结果传回去，需要把结果序列化后写入reply中。

    ```
    void ServiceAbility::MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply)
    {
        printf("ServiceAbility::MsgHandle, funcId is %d\n", funcId);
        int result = 0;
        if (funcId == PLUS) {
            result = IpcIoPopInt32(request) + IpcIoPopInt32(request);
        }
        // push data
        IpcIoPushInt32(reply, result);
    }
    ```

5.  注册Service。

    Service也需要在应用清单文件config.json中进行注册，注册类型type需要设置为service。

    ```
    "abilities": [{
        "name": "ServiceAbility",
        "icon": "res/drawable/phone.png",
        "label": "test app 2", 
        "launchType": "standard",
        "type": "service",
        "visible": true
    }
    ]
    ```

6.  启动Service。
    -   Ability为用户提供了StartAbility\(\)方法来启动另外一个Ability，因为Service也是Ability的一种，开发者同样可以通过将Want传递给该方法来启动Service。

        开发者可以通过Want的SetWantElement \(\)来设置目标服务信息。ElementName结构体的两个主要参数：第一个参数为包名称；第二个参数为目标Ability。

        ```
        {
            Want want = { nullptr };
            ElementName element = { nullptr };
            SetElementBundleName(&element, "com.company.appname");
            SetElementAbilityName(&element, "ServiceAbility");
            SetWantElement(&want, element);
            StartAbility(want);
            ClearElement(&element);
            ClearWant(&want);
        }
        ```

        StartAbility\(\) 方法会立即执行，如果Service尚未运行，则系统首先会调用OnStart\(\)。

    -   停止Service。

        Service一旦创建就会一直保持在后台运行，开发者可以通过调用StopAbility\(\)来停止Service。

7.  连接Service。
    -   如果Service需要与Page Ability或其他应用组件中的Service进行交互，则应创建用于连接的Service。Service支持其他Ability通过ConnectAbility\(\)与其进行连接，ConnectAbility\(\)需要传入目标Service的Want，以及IAbilityConnection的实例来处理回调。IAbilityConnection提供了两个方法供用户实现，OnAbilityConnectDone\(\)用来处理连接的回调，OnAbilityDisconnectDone\(\)用来处理断开连接的回调。

        ```
        {
            // ability创建IAbilityConnection对象和定义IAbilityConnection的两个方法实现
            IAbilityConnection abilityConnection = new IAbilityConnection();
            abilityConnection->OnAbilityConnectDone = OnAbilityConnectDone;
            abilityConnection->OnAbilityDisconnectDone = OnAbilityDisconnectDone;
         
            void OnAbilityConnectDone(ElementName *elementName, SvcIdentity *serviceSid, 
                int resultCode, void *data)
            {
                if (resultCode != 0) {
                    return;
                }
                // push data
                IpcIo request;
                char dataBuffer[IPC_IO_DATA_MAX];
                IpcIoInit(&request, dataBuffer, IPC_IO_DATA_MAX, 0);
                IpcIoPushInt32(&request, 10);
                IpcIoPushInt32(&request, 6);
         
                // send and getReply
                IpcIo reply;
                uintptr_t ptr = 0;
                if (Transact(nullptr, *serviceSid, 0, &request, &reply, 
                    LITEIPC_FLAG_DEFAULT, &ptr) != LITEIPC_OK) {
                    printf("transact error\n");
                    return;
                }
                int result = IpcIoPopInt32(&reply);
                printf("execute add method, result is %d\n", result);
                if (ptr != 0) {
                    FreeBuffer(nullptr, reinterpret_cast<void *>(ptr));
                }
            }
         
            void OnAbilityDisconnectDone(ElementName *elementName, 
                int resultCode, void *data)
            {
                printf("elementName is %s, %s\n", 
                    elementName->bundleName, elementName->abilityName);
            }
        }
        ```

    -   发起connect和disconnect。

        ```
        {
            // ability发起connect
            Want want = { nullptr };
            ElementName element = { nullptr };
            SetElementBundleName(&element, "com.company.appname");
            SetElementAbilityName(&element, "ServiceAbility");
            SetWantElement(&want, element);
            ConnectAbility(want, *abilityConnection, this);
         
            // ability发起disconnect
            DisconnectAbility(*abilityConnection);
        }
        ```



### 包管理接口使用指导<a name="section1724016743217"></a>

**安装应用**

安装接口只能给内置的系统应用使用。根据应用的安装路径，可以在安装应用时进行选择：

-   将应用安装到系统默认的文件目录/storage/app/。
-   将应用安装到系统外挂的存储介质中，例如micro sdcard。

这两种选择可以在创建InstallParam实例的时候指定，当InstallParam的成员变量installLocation为 INSTALL\_LOCATION\_INTERNAL\_ONLY时，意味着应用将会被安装到/storage/app/目录下；当InstallParam的成员变量installLocation为INSTALL\_LOCATION\_PREFER\_EXTERNAL时，意味着应用将被安装到存储介质，其安装目录是/sdcard/app/。由于安装应用的过程是异步的，所以需要使用类似信号量的机制来确保安装的回调可以被执行。

安装应用的步骤如下（示例代码以安装到系统目录为例）：

1.  将经过安全签名的应用放置于指定的目录下。
2.  创建InstallParam实例和信号量。

    ```
    InstallParam installParam = { 
    .installLocation = INSTALL_LOCATION_INTERNAL_ONLY, // 安装到系统目录
    .keepData = false
    };
    static sem_t g_sem;
    ```

3.  定义回调函数。

    ```
    static void InstallCallback(const uint8_t resultCode, const void *resultMessage)
    {
         std::string strMessage = reinterpret_cast<const char *>(resultMessage);
         if (!strMessage.empty()) {
            printf("install resultMessage is %s, %d\n", strMessage.c_str(),resultCode);
         }
         sem_post(&g_sem);
    }
    ```

4.  调用Install接口。

    ```
    const uint32_t WAIT_TIMEOUT = 30;
    sem_init(&g_sem, 0, 0);
    std::string installPath = “/storage/bundle/demo.hap”; // hap包的存储路径
    bool result = Install(installPath.c_str(), &installParam, InstallCallback);
    struct timespec ts = {};
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += WAIT_TIMEOUT; // 超时即释放信号量
    sem_timedwait(&g_sem, &ts);
    ```


**卸载应用**

卸载应用的时候可以选择是否保留应用的数据，开发者可以通过创建的InstallParam实例的成员变量keepData来确定。当keepData为true, 卸载应用之后将保留应用的数据，当keepData为false时，卸载应用之后将不会保留应用的数据。

1.  创建InstallParam实例和信号量。

    ```
    static sem_t g_sem;
    InstallParam installParam = {
    .installLocation = 1,
         .keepData = false // 不保留应用数据
    };
    ```

2.  定义回调函数。

    ```
    static void UninstallCallback(const uint8_t resultCode, const void *resultMessage)
    {
        std::string strMessage = reinterpret_cast<const char *>(resultMessage);
        if (!strMessage.empty()) {
            printf("uninstall resultMessage is %s\n", strMessage.c_str());
            g_resultMessage = strMessage;
        }
        g_resultCode = resultCode;
        sem_post(&g_sem);
    }
    ```

3.  调用Uninstall接口。

    ```
    sem_init(&g_sem, 0, 0);
    const uint32_t WAIT_TIMEOUT = 30;
    std::string BUNDLE_NAME = “com.huawei.demo”; // 卸载应用的包名
    Uninstall(BUNDLE_NAME.c_str(), &installParam, UninstallCallback);
    struct timespec ts = {};
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += WAIT_TIMEOUT;
    sem_timedwait(&g_sem, &ts);
    ```


**查询已安装应用的包信息**

开发者可以利用BundleManager提供的接口GetBundleInfo来查询系统内已安装应用的包信息。

1.  创建以及初始化BundleInfo。

    ```
    BundleInfo bundleInfo;
    (void) memset_s(&bundleInfo, sizeof(BundleInfo), 0, sizeof(BundleInfo));
    ```

2.  调用GetBundleInfo接口，指定查询应用的包名，同时指定flag来确定获取的BundleInfo中是否含有元能力信息（实例代码以含有元能力信息为例）。

    ```
    std::string BUNDLE_NAME = "com.huawei.demo";
    uint8_t ret = GetBundleInfo(BUNDLE_NAME.c_str(), 1, &bundleInfo); // flags = 1，获取包信息中含有元能力信息
    ```

3.  使用完获取的BundleInfo之后，要及时清理掉其内部所占用的内存空间避免内存泄漏。

    ```
    ClearBundleInfo(&bundleInfo);
    ```


### Hap包打包<a name="section171771212328"></a>

打包工具一般集成到开发工具或者ide中，开发者一般不涉及直接使用该工具，下面的介绍开发者可以作为了解。打包工具的jar包在开源代码中的位置：developtools/packing\_tool/jar。

-   打包命令行参数

    **表 2**  打包所需要的资源文件描述

    <a name="table2151102833212"></a>
    <table><thead align="left"><tr id="row314812893218"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p1614732812320"><a name="p1614732812320"></a><a name="p1614732812320"></a>命令参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p214722819322"><a name="p214722819322"></a><a name="p214722819322"></a>对应的资源文件</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p214714286324"><a name="p214714286324"></a><a name="p214714286324"></a>说明</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1014712863211"><a name="p1014712863211"></a><a name="p1014712863211"></a>是否可缺省</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row614812289322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p16148182853216"><a name="p16148182853216"></a><a name="p16148182853216"></a>--mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p5148162814328"><a name="p5148162814328"></a><a name="p5148162814328"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p11481228143215"><a name="p11481228143215"></a><a name="p11481228143215"></a>为“hap”字段，打包生成hap</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p11148132811325"><a name="p11148132811325"></a><a name="p11148132811325"></a>否</p>
    </td>
    </tr>
    <tr id="row81486283327"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p6148132833215"><a name="p6148132833215"></a><a name="p6148132833215"></a>--json-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p214810286325"><a name="p214810286325"></a><a name="p214810286325"></a>清单文件config.json</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p514802823216"><a name="p514802823216"></a><a name="p514802823216"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4148182813326"><a name="p4148182813326"></a><a name="p4148182813326"></a>否</p>
    </td>
    </tr>
    <tr id="row1214917281322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p171497285322"><a name="p171497285322"></a><a name="p171497285322"></a>--resources-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p414914286320"><a name="p414914286320"></a><a name="p414914286320"></a>资源文件resources</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p41492286324"><a name="p41492286324"></a><a name="p41492286324"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1114922812327"><a name="p1114922812327"></a><a name="p1114922812327"></a>是</p>
    </td>
    </tr>
    <tr id="row14149122817322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11149528173218"><a name="p11149528173218"></a><a name="p11149528173218"></a>--assets-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p314918286324"><a name="p314918286324"></a><a name="p314918286324"></a>资源文件assets</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1414916284327"><a name="p1414916284327"></a><a name="p1414916284327"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p9149122817324"><a name="p9149122817324"></a><a name="p9149122817324"></a>是</p>
    </td>
    </tr>
    <tr id="row41501728193219"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p514918280325"><a name="p514918280325"></a><a name="p514918280325"></a>--lib-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p16149162823212"><a name="p16149162823212"></a><a name="p16149162823212"></a>依赖库文件</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p12149122853216"><a name="p12149122853216"></a><a name="p12149122853216"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p614962853217"><a name="p614962853217"></a><a name="p614962853217"></a>是</p>
    </td>
    </tr>
    <tr id="row131501928183212"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p4150122833213"><a name="p4150122833213"></a><a name="p4150122833213"></a>--shared-libs-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p15150112814322"><a name="p15150112814322"></a><a name="p15150112814322"></a>共享库文件</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p20150128113212"><a name="p20150128113212"></a><a name="p20150128113212"></a>针对系统应用的共享库，特殊情况下使用</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p181501928183214"><a name="p181501928183214"></a><a name="p181501928183214"></a>是</p>
    </td>
    </tr>
    <tr id="row10150142812329"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1015011286320"><a name="p1015011286320"></a><a name="p1015011286320"></a>--ability-so-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p6150728123214"><a name="p6150728123214"></a><a name="p6150728123214"></a>主功能so文件</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p16150192813323"><a name="p16150192813323"></a><a name="p16150192813323"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1315052811325"><a name="p1315052811325"></a><a name="p1315052811325"></a>是</p>
    </td>
    </tr>
    <tr id="row51519280321"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p315092813214"><a name="p315092813214"></a><a name="p315092813214"></a>--index-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1115012813325"><a name="p1115012813325"></a><a name="p1115012813325"></a>资源索引</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p111501028123220"><a name="p111501028123220"></a><a name="p111501028123220"></a>资源索引文件由资源生成工具生成，由资源流水线会集成该工具</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1115122811326"><a name="p1115122811326"></a><a name="p1115122811326"></a>是</p>
    </td>
    </tr>
    <tr id="row91511928203211"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0151328173211"><a name="p0151328173211"></a><a name="p0151328173211"></a>--out-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p215112833214"><a name="p215112833214"></a><a name="p215112833214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p11151152833217"><a name="p11151152833217"></a><a name="p11151152833217"></a>生成的hap包输出路径，默认为当前目录</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1815110281328"><a name="p1815110281328"></a><a name="p1815110281328"></a>是</p>
    </td>
    </tr>
    <tr id="row4151162812329"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1015112280329"><a name="p1015112280329"></a><a name="p1015112280329"></a>--force</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p2151128133219"><a name="p2151128133219"></a><a name="p2151128133219"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p9151928183218"><a name="p9151928183218"></a><a name="p9151928183218"></a>是否覆盖原有同名文件，默认为false</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p171511728143217"><a name="p171511728143217"></a><a name="p171511728143217"></a>是</p>
    </td>
    </tr>
    </tbody>
    </table>

-   打包示例
    -   开发视图

        ![](figure/zh-cn_image_0000001062942690.png)

    -   编译视图

        ![](figure/zh-cn_image_0000001062334618.png)

    -   使用打包工具执行以下命令打包：

        ![](figure/zh-cn_image_0000001062476933.png)

        ```
        $ java -jar hmos_app_packing_tool.jar --mode hap --json-path ./config.json --assets-path ./assets/ --ability-so-path ./libentry.so --index-path ./resources.index --out-path out/entry.hap --force true
        ```



