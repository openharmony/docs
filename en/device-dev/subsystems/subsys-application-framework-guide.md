# Development Guidelines<a name="EN-US_TOPIC_0000001062229264"></a>

## When to Use<a name="section93012287133"></a>

-   Develop Page abilities for applications that have a UI for human-machine interaction, such as news applications, video players, navigation applications, and payment applications. Most applications we use in our daily lives are such type of applications.

-   Develop Service abilities for applications so that they can run particular services in the background, such as music playing, computing, and navigation services.

-   Pack both Page and Service abilities into HarmonyOS Ability Packages \(HAPs\). All applications must be packed into HAP files before being published to the application market. Once published, users can then download the applications from the application market.

## Available APIs<a name="section11821047161319"></a>

**Table  1**  APIs of the ability management framework

<a name="table36761640135514"></a>
<table><thead align="left"><tr id="row570215713380"><th class="cellrowborder" valign="top" width="53.849999999999994%" id="mcps1.2.3.1.1"><p id="p1703155733819"><a name="p1703155733819"></a><a name="p1703155733819"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="46.150000000000006%" id="mcps1.2.3.1.2"><p id="p37035579380"><a name="p37035579380"></a><a name="p37035579380"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row39211240205510"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p49215401550"><a name="p49215401550"></a><a name="p49215401550"></a>Want *WantParseUri(const char *uri)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592164014553"><a name="p592164014553"></a><a name="p592164014553"></a>Converts a specified character string into a <strong id="b123303298245"><a name="b123303298245"></a><a name="b123303298245"></a>Want</strong> object.</p>
</td>
</tr>
<tr id="row192154055512"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p139212040175520"><a name="p139212040175520"></a><a name="p139212040175520"></a>const char *WantToUri(Want want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9921640135519"><a name="p9921640135519"></a><a name="p9921640135519"></a>Converts a specified <strong id="b26361419162420"><a name="b26361419162420"></a><a name="b26361419162420"></a>Want</strong> object into a character string.</p>
</td>
</tr>
<tr id="row16921440135520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1892124075519"><a name="p1892124075519"></a><a name="p1892124075519"></a>void SetWantElement(Want *want, ElementName element);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p129214403555"><a name="p129214403555"></a><a name="p129214403555"></a>Sets the <strong id="b6704163515267"><a name="b6704163515267"></a><a name="b6704163515267"></a>element</strong> variable for a specified <strong id="b1759143810269"><a name="b1759143810269"></a><a name="b1759143810269"></a>Want</strong> object.</p>
</td>
</tr>
<tr id="row3921114018552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p79210404555"><a name="p79210404555"></a><a name="p79210404555"></a>void SetWantData(Want *want, const void *data, uint16_t dataLength)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p09218402559"><a name="p09218402559"></a><a name="p09218402559"></a>Sets data to carry in a specified <strong id="b1317045311262"><a name="b1317045311262"></a><a name="b1317045311262"></a>Want</strong> object for starting a particular ability.</p>
</td>
</tr>
<tr id="row892124013556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4921040155510"><a name="p4921040155510"></a><a name="p4921040155510"></a>bool SetWantSvcIdentity(Want *want, SvcIdentity sid)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p992204013553"><a name="p992204013553"></a><a name="p992204013553"></a>Sets the <strong id="b171231625124319"><a name="b171231625124319"></a><a name="b171231625124319"></a>sid</strong> member variable for a specified <strong id="b11565173054314"><a name="b11565173054314"></a><a name="b11565173054314"></a>Want</strong> object.</p>
</td>
</tr>
<tr id="row99221840135520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p139221840155519"><a name="p139221840155519"></a><a name="p139221840155519"></a>void ClearWant(Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79221440185511"><a name="p79221440185511"></a><a name="p79221440185511"></a>Clears the memory of a specified <strong id="b233731018449"><a name="b233731018449"></a><a name="b233731018449"></a>Want</strong> object.</p>
</td>
</tr>
<tr id="row69221640125519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792244017555"><a name="p1792244017555"></a><a name="p1792244017555"></a>void SetMainRoute(const std::string &amp;entry)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p7922174016558"><a name="p7922174016558"></a><a name="p7922174016558"></a>Sets the main route for the ability.</p>
</td>
</tr>
<tr id="row189221840165516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p3922340125511"><a name="p3922340125511"></a><a name="p3922340125511"></a>void SetUIContent(RootView *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9922240175511"><a name="p9922240175511"></a><a name="p9922240175511"></a>Sets the UI layout for the ability.</p>
</td>
</tr>
<tr id="row159226407552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1292213402552"><a name="p1292213402552"></a><a name="p1292213402552"></a>void OnStart(const Want&amp; intent)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p14922440195515"><a name="p14922440195515"></a><a name="p14922440195515"></a>Called when the ability is started. This callback is invoked to handle transitions between ability lifecycle states.</p>
</td>
</tr>
<tr id="row1392217402551"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1292284065516"><a name="p1292284065516"></a><a name="p1292284065516"></a>void OnStop()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p149223403554"><a name="p149223403554"></a><a name="p149223403554"></a>Called when the ability is being destroyed. This callback is invoked to handle transitions between ability lifecycle states.</p>
</td>
</tr>
<tr id="row169221407555"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p992218400556"><a name="p992218400556"></a><a name="p992218400556"></a>void OnActive(const Want&amp; intent)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1923440135515"><a name="p1923440135515"></a><a name="p1923440135515"></a>Called when the ability is visible to users. This callback is invoked to handle transitions between ability lifecycle states.</p>
</td>
</tr>
<tr id="row9923640205516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p19231340185511"><a name="p19231340185511"></a><a name="p19231340185511"></a>void OnInactive()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p992311408556"><a name="p992311408556"></a><a name="p992311408556"></a>Called when the ability is invisible to users. This callback is invoked to handle transitions between ability lifecycle states.</p>
</td>
</tr>
<tr id="row4923154015557"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p99233404556"><a name="p99233404556"></a><a name="p99233404556"></a>void OnBackground()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79238400554"><a name="p79238400554"></a><a name="p79238400554"></a>Called when the ability is moved to the background. This callback is invoked to handle transitions between ability lifecycle states.</p>
</td>
</tr>
<tr id="row14923144045513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p692354019558"><a name="p692354019558"></a><a name="p692354019558"></a>const SvcIdentity *OnConnect(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p17923154085512"><a name="p17923154085512"></a><a name="p17923154085512"></a>Called when the Service ability is connected for the first time.</p>
</td>
</tr>
<tr id="row592313405552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1692312404551"><a name="p1692312404551"></a><a name="p1692312404551"></a>void OnDisconnect(const Want &amp;want);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p892394017551"><a name="p892394017551"></a><a name="p892394017551"></a>Called when all abilities connected to the Service ability are disconnected.</p>
</td>
</tr>
<tr id="row3923194075515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p5923240175516"><a name="p5923240175516"></a><a name="p5923240175516"></a>void MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p2923184055518"><a name="p2923184055518"></a><a name="p2923184055518"></a>Handles a message sent by the client to the Service ability.</p>
</td>
</tr>
<tr id="row15923540155517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p99231940105514"><a name="p99231940105514"></a><a name="p99231940105514"></a>void Dump(const std::string &amp;extra)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p18924174016554"><a name="p18924174016554"></a><a name="p18924174016554"></a>Prints ability information to the console.</p>
</td>
</tr>
<tr id="row1792414055517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1592454025513"><a name="p1592454025513"></a><a name="p1592454025513"></a>void Present(AbilitySlice *abilitySlice, const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p11924104045517"><a name="p11924104045517"></a><a name="p11924104045517"></a>Presents another ability slice.</p>
</td>
</tr>
<tr id="row15924114012556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13924154017551"><a name="p13924154017551"></a><a name="p13924154017551"></a>void Terminate()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p11924104012557"><a name="p11924104012557"></a><a name="p11924104012557"></a>Destroys the ability slice.</p>
</td>
</tr>
<tr id="row2092484010558"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4924540155515"><a name="p4924540155515"></a><a name="p4924540155515"></a>void SetUIContent(RootView *rootView)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p79241640185514"><a name="p79241640185514"></a><a name="p79241640185514"></a>Sets the UI layout for the host ability of the ability slice.</p>
</td>
</tr>
<tr id="row16924640195518"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p169245407559"><a name="p169245407559"></a><a name="p169245407559"></a>void OnStart(const Want&amp; want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p492494095517"><a name="p492494095517"></a><a name="p492494095517"></a>Called when the ability slice is started. This callback is invoked to handle transitions between ability slice lifecycle states.</p>
</td>
</tr>
<tr id="row15924154065513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p159242407559"><a name="p159242407559"></a><a name="p159242407559"></a>void OnStop()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p13924114017556"><a name="p13924114017556"></a><a name="p13924114017556"></a>Called when the ability slice is being destroyed. This callback is invoked to handle transitions between ability slice lifecycle states.</p>
</td>
</tr>
<tr id="row13924154065517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p292494005513"><a name="p292494005513"></a><a name="p292494005513"></a>void OnActive(const Want&amp; want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p89256408553"><a name="p89256408553"></a><a name="p89256408553"></a>Called when the ability slice is visible to users. This callback is invoked to handle transitions between ability slice lifecycle states.</p>
</td>
</tr>
<tr id="row1925540125515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13925114015514"><a name="p13925114015514"></a><a name="p13925114015514"></a>void OnInactive()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p892534025515"><a name="p892534025515"></a><a name="p892534025515"></a>Called when the ability slice is invisible to users. This callback is invoked to handle transitions between ability slice lifecycle states.</p>
</td>
</tr>
<tr id="row692519401558"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792515408558"><a name="p1792515408558"></a><a name="p1792515408558"></a>void OnBackground()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p292554013551"><a name="p292554013551"></a><a name="p292554013551"></a>Called when the ability slice is moved to the background. This callback is invoked to handle transitions between ability slice lifecycle states.</p>
</td>
</tr>
<tr id="row129251040115515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p0925174011553"><a name="p0925174011553"></a><a name="p0925174011553"></a>int StartAbility(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p129251408557"><a name="p129251408557"></a><a name="p129251408557"></a>Starts an ability based on the specified <strong id="b3667652155017"><a name="b3667652155017"></a><a name="b3667652155017"></a>Want</strong> information.</p>
</td>
</tr>
<tr id="row3925940195519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p19251440135512"><a name="p19251440135512"></a><a name="p19251440135512"></a>int StopAbility(const Want &amp;want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p19925174035510"><a name="p19925174035510"></a><a name="p19925174035510"></a>Stops a Service ability based on the specified <strong id="b1176241795114"><a name="b1176241795114"></a><a name="b1176241795114"></a>Want</strong> information.</p>
</td>
</tr>
<tr id="row14925164055520"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p14925114015553"><a name="p14925114015553"></a><a name="p14925114015553"></a>int TerminateAbility()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p39254405557"><a name="p39254405557"></a><a name="p39254405557"></a>Destroys the ability.</p>
</td>
</tr>
<tr id="row19925940115515"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p892584015559"><a name="p892584015559"></a><a name="p892584015559"></a>int ConnectAbility(const Want &amp;want, const IAbilityConnection &amp;conn, void *data);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p4926640165513"><a name="p4926640165513"></a><a name="p4926640165513"></a>Connects to a <strong id="b10891169125217"><a name="b10891169125217"></a><a name="b10891169125217"></a>Service</strong> ability based on the specified <strong id="b184091115165216"><a name="b184091115165216"></a><a name="b184091115165216"></a>Want</strong> information.</p>
</td>
</tr>
<tr id="row10926540155513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p119267409559"><a name="p119267409559"></a><a name="p119267409559"></a>int DisconnectAbility(const IAbilityConnection &amp;conn)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592644085512"><a name="p592644085512"></a><a name="p592644085512"></a>Disconnects from a <strong id="b37531635205214"><a name="b37531635205214"></a><a name="b37531635205214"></a>Service</strong> ability.</p>
</td>
</tr>
<tr id="row11926340145516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p892614035513"><a name="p892614035513"></a><a name="p892614035513"></a>const char *GetBundleName()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p99261040105511"><a name="p99261040105511"></a><a name="p99261040105511"></a>Obtains the bundle name of the application to which the ability belongs.</p>
</td>
</tr>
<tr id="row7926440125519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p4926114065519"><a name="p4926114065519"></a><a name="p4926114065519"></a>const char *GetSrcPath()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p4926194055516"><a name="p4926194055516"></a><a name="p4926194055516"></a>Obtains the source code path of the ability.</p>
</td>
</tr>
<tr id="row29261840115519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1992604045519"><a name="p1992604045519"></a><a name="p1992604045519"></a>const char *GetDataPath()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p109268403551"><a name="p109268403551"></a><a name="p109268403551"></a>Obtains the data path of the ability.</p>
</td>
</tr>
<tr id="row29261940195516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p159267407555"><a name="p159267407555"></a><a name="p159267407555"></a>int StartAbility(const Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1340210145179"><a name="p1340210145179"></a><a name="p1340210145179"></a>Starts an Ability. This function does not need to be used in applications developed based on <strong id="b12960101603119"><a name="b12960101603119"></a><a name="b12960101603119"></a>Ability</strong>.</p>
</td>
</tr>
<tr id="row16926240155514"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1792617404558"><a name="p1792617404558"></a><a name="p1792617404558"></a>int ConnectAbility(const Want *want, const IAbilityConnection *conn, void *data);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1092612181812"><a name="p1092612181812"></a><a name="p1092612181812"></a>Connects to a Service ability based on the specified <strong id="b71516265816"><a name="b71516265816"></a><a name="b71516265816"></a>Want</strong> information. This function does not need to be used in applications developed based on <strong id="b12877235205716"><a name="b12877235205716"></a><a name="b12877235205716"></a>Ability</strong>.</p>
</td>
</tr>
<tr id="row5927164010552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p49271540165510"><a name="p49271540165510"></a><a name="p49271540165510"></a>int DisconnectAbility(const IAbilityConnection *conn);</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1296152820189"><a name="p1296152820189"></a><a name="p1296152820189"></a>Disconnects from a Service ability. This function does not need to be used in applications developed based on <strong id="b1866210445818"><a name="b1866210445818"></a><a name="b1866210445818"></a>Ability</strong>.</p>
</td>
</tr>
<tr id="row89271040135517"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p13927194011558"><a name="p13927194011558"></a><a name="p13927194011558"></a>int StopAbility(const Want *want)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p7699548131819"><a name="p7699548131819"></a><a name="p7699548131819"></a>Stops a Service ability based on the specified <strong id="b53334211588"><a name="b53334211588"></a><a name="b53334211588"></a>Want</strong> information. This function does not need to be used in applications developed based on <strong id="b1466212716581"><a name="b1466212716581"></a><a name="b1466212716581"></a>Ability</strong>.</p>
</td>
</tr>
<tr id="row1992764065516"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p192716406556"><a name="p192716406556"></a><a name="p192716406556"></a>void (*OnAbilityConnectDone)(ElementName *elementName, SvcIdentity *serviceSid, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p0927940195510"><a name="p0927940195510"></a><a name="p0927940195510"></a>Called when a client is connected to a Service ability.</p>
</td>
</tr>
<tr id="row7927134010559"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p692764095510"><a name="p692764095510"></a><a name="p692764095510"></a>void (*OnAbilityDisconnectDone)(ElementName *elementName, int resultCode, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p18927124035516"><a name="p18927124035516"></a><a name="p18927124035516"></a>Called after all connections to a Service ability are disconnected.</p>
</td>
</tr>
<tr id="row692784020556"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p17927104010557"><a name="p17927104010557"></a><a name="p17927104010557"></a>void PostTask(const Task&amp; task)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p13927940105516"><a name="p13927940105516"></a><a name="p13927940105516"></a>Posts a task to an asynchronous thread.</p>
</td>
</tr>
<tr id="row392784013552"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1092794014555"><a name="p1092794014555"></a><a name="p1092794014555"></a>void PostQuit()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p19281940185510"><a name="p19281940185510"></a><a name="p19281940185510"></a>Quits the event loop of the current thread.</p>
</td>
</tr>
<tr id="row2928140145519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p292813401555"><a name="p292813401555"></a><a name="p292813401555"></a>static AbilityEventHandler* GetCurrentHandler()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p9928154012554"><a name="p9928154012554"></a><a name="p9928154012554"></a>Obtains the event handler of the current thread.</p>
</td>
</tr>
<tr id="row15928174035513"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p1692824017551"><a name="p1692824017551"></a><a name="p1692824017551"></a>void Run()</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p592820401558"><a name="p592820401558"></a><a name="p592820401558"></a>Starts running the event loop of the current thread.</p>
</td>
</tr>
<tr id="row15928174013554"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p17928440125516"><a name="p17928440125516"></a><a name="p17928440125516"></a>#define REGISTER_AA(className)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1892817404554"><a name="p1892817404554"></a><a name="p1892817404554"></a>Registers the class name of an <strong id="b102356594597"><a name="b102356594597"></a><a name="b102356594597"></a>Ability</strong> child class.</p>
</td>
</tr>
<tr id="row17928640135519"><td class="cellrowborder" valign="top" width="53.849999999999994%" headers="mcps1.2.3.1.1 "><p id="p199281640125520"><a name="p199281640125520"></a><a name="p199281640125520"></a>#define REGISTER_AS(className)</p>
</td>
<td class="cellrowborder" valign="top" width="46.150000000000006%" headers="mcps1.2.3.1.2 "><p id="p1792811409556"><a name="p1792811409556"></a><a name="p1792811409556"></a>Registers the class name of an <strong id="b691819710011"><a name="b691819710011"></a><a name="b691819710011"></a>AbilitySlice</strong> child class.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section10514141679"></a>

### Creating a Service Ability<a name="section19921154214315"></a>

1.  Create the  **MyServiceAbility**  child class from  **Ability**  in  **my\_service\_ability.h**.

    ```
    class MyServiceAbility: public Ability {
    protected:
        void OnStart(const Want& want);
        const SvcIdentity *OnConnect(const Want &want) override;
        void MsgHandle(uint32_t funcId, IpcIo *request, IpcIo *reply) override;
    };
    ```

2.  Call the  **REGISTER\_AA**  macro to register the  **ServiceAbility**  class with the application framework so that the framework can instantiate the  **MyServiceAbility**  class you have created.

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

3.  Override the following lifecycle callbacks for Service abilities to implement your own logic for your Service ability. When overriding a lifecycle callback, you must call the corresponding function from the parent class.
    -   OnStart\(\)

        This callback is invoked when a Service ability is being created to perform Service ability initialization operations that take a short time. This callback is invoked only once in the entire lifecycle of a Service ability.

        ```
        void MyServiceAbility::OnStart(const Want& want)
        {
            printf("ServiceAbility::OnStart\n");
            Ability::OnStart(want);
        }
        ```

    -   OnConnect\(\)

        This callback is invoked when another ability is connected to the Service ability. This callback returns an  **SvcIdentity**  object for the other ability to interact with the Service ability. 

        ```
        const SvcIdentity *MyServiceAbility::OnConnect(const Want &want)
        {
            printf("ServiceAbility::OnConnect\n");
            return Ability::OnConnect(want);
        }
        ```

    -   OnDisconnect​\(\)

        This callback is invoked when another ability is disconnected from the Service ability.

    -   OnStop\(\)

        This callback is invoked when a Service ability is destroyed. You should override this callback for your Service ability to clear its resources, such as threads and registered listeners.

4.  Override the message handling function.

    The  **MsgHandle**  function is used by Service abilities to handle messages sent from clients.  **funcId**  indicates the type of the message sent from the client, and  **request**  indicates the pointer to the serialized request parameters sent from the client. If you want to send the result back after the message is handled, serialize the result and write it into  **reply**.

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

5.  Register a Service ability.

    Declare your Service ability in the  **config.json**  file by setting its  **type**  attribute to  **service**.

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

6.  Start a Service ability.
    -   The  **Ability**  class provides the  **StartAbility\(\)**  function to start another ability. You can pass a  **Want**  object to this function to start a Service ability.

        You can use the  **SetWantElement\(\)**  function provided in the  **AbilityKit**  to set information about the target Service ability to start. The  **element**  parameter of the  **SetWantElement\(\)**  function indicates the  **ElementName**  structure that contains the bundle name and target ability name required for starting an ability.

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

        The  **StartAbility\(\)**  function is executed immediately. If the Service ability is not running while the function is called, the system invokes  **OnStart\(\)**  first.

    -   Stops a Service ability.

        Once created, the Service ability keeps running in the background. You can call  **StopAbility\(\)**  to stop the Service ability.

7.  Connect to a Service ability.
    -   If you need to connect a Service ability to a Page ability or to a Service ability in another application, you should first create a Service ability for connection. A Service ability allows other abilities to connect to it through  **ConnectAbility\(\)**  by passing a  **Want**  object that contains information about the target Service ability to the function. You can implement callbacks in  **IAbilityConnection**  to be invoked when a Service ability is connected or disconnected. The  **OnAbilityConnectDone\(\)**  callback is invoked when an ability is connected, and  **OnAbilityDisconnectDone\(\)**  is invoked when an ability is disconnected.

        ```
        {
            // Create an IAbilityConnection object and implement the two callbacks.
            IAbilityConnection abilityConnection = new IAbilityConnection();
            abilityConnection->OnAbilityConnectDone = OnAbilityConnectDone;
            abilityConnection->OnAbilityDisconnectDone = OnAbilityDisconnectDone;
         
            void OnAbilityConnectDone(ElementName *elementName, SvcIdentity *serviceSid, 
                int resultCode, void *data)
            {
                if (resultCode != 0) {
                    return;
                }
                // Push data.
                IpcIo request;
                char dataBuffer[IPC_IO_DATA_MAX];
                IpcIoInit(&request, dataBuffer, IPC_IO_DATA_MAX, 0);
                IpcIoPushInt32(&request, 10);
                IpcIoPushInt32(&request, 6);
         
                // Send and receive the reply.
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

    -   The following sample code snippet shows how to initiate ability connection and disconnection:

        ```
        {
            // Connect an ability to a specified Service ability.
            Want want = { nullptr };
            ElementName element = { nullptr };
            SetElementBundleName(&element, "com.company.appname");
            SetElementAbilityName(&element, "ServiceAbility");
            SetWantElement(&want, element);
            ConnectAbility(want, *abilityConnection, this);
         
            // Disconnect from a Service ability.
            DisconnectAbility(*abilityConnection);
        }
        ```



### Development Guidelines on Bundle Management<a name="section1724016743217"></a>

**Installing an Application**

The installation API can only be used by built-in system applications. Applications can be installed in either of the following paths:

-   Default installation directory  **/storage/app/**  in the system
-   Particular directory on the external storage, for example, a microSD card

You can specify the installation path when creating an  **InstallParam**  instance. To install the application in the  **/storage/app/**  directory, set the  **installLocation**  member variable in the  **InstallParam**  instance to  **INSTALL\_LOCATION\_INTERNAL\_ONLY**. To install the application in the  **/sdcard/app/**  directory of the external storage, set  **installLocation**  to  **INSTALL\_LOCATION\_PREFER\_EXTERNAL**. The application installation process is asynchronous, and a semaphore-like mechanism is required to ensure that the installation callback can be executed.

The procedure for installing an application is as follows \(the system directory is used as an example\):

1.  Place the signed HAP file in a specified directory.
2.  Create an  **InstallParam**  instance and define the semaphore.

    ```
    InstallParam installParam = { 
    .installLocation = INSTALL_LOCATION_INTERNAL_ONLY, // Install the application in the system directory.
    .keepData = false
    };
    static sem_t g_sem;
    ```

3.  Define the callback function.

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

4.  Call the  **Install**  function.

    ```
    const uint32_t WAIT_TIMEOUT = 30;
    sem_init(&g_sem, 0, 0);
    std::string installPath = "/storage/bundle/demo.hap"; // Specify the path where the HAP file is stored.
    bool result = Install(installPath.c_str(), &installParam, InstallCallback);
    struct timespec ts = {};
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += WAIT_TIMEOUT; // Release the semaphore upon timeout.
    sem_timedwait(&g_sem, &ts);
    ```


**Uninstalling an Application**

When uninstalling an application, you can specify whether to retain application data using the  **keepData**  member variable in the created  **InstallParam**  instance. If  **keepData**  is set to  **true**, the application data will be retained after the application is uninstalled. If the variable is set to  **false**, the application data will be removed during application installation.

1.  Create an  **InstallParam**  instance and define the semaphore.

    ```
    static sem_t g_sem;
    InstallParam installParam = {
    .installLocation = 1,
         .keepData = false // Remove application data.
    };
    ```

2.  Define the callback function.

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

3.  Call the  **Uninstall**  function.

    ```
    sem_init(&g_sem, 0, 0);
    const uint32_t WAIT_TIMEOUT = 30;
    std::string BUNDLE_NAME = "com.example.demo"; // Bundle name of the application to be uninstalled
    Uninstall(BUNDLE_NAME.c_str(), &installParam, UninstallCallback);
    struct timespec ts = {};
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += WAIT_TIMEOUT;
    sem_timedwait(&g_sem, &ts);
    ```


**Querying Bundle Information About an Installed Application**

You can use the  **GetBundleInfo**  function provided by  **BundleManager**  to query the bundle information about installed applications in the system.

1.  Create and initialize a  **BundleInfo**  object.

    ```
    BundleInfo bundleInfo;
    (void) memset_s(&bundleInfo, sizeof(BundleInfo), 0, sizeof(BundleInfo));
    ```

2.  Call  **GetBundleInfo**  to obtain bundle information about a specified application. The  **bundleName**  parameter indicates the pointer to the application bundle name, and the  **flags**  parameter specifies whether the obtained  **BundleInfo**  object can contain  **AbilityInfo**.

    ```
    std::string BUNDLE_NAME = "com.example.demo";
    uint8_t ret = GetBundleInfo(BUNDLE_NAME.c_str(), 1, &bundleInfo); // When flags is set to 1, the obtained BundleInfo object contains AbilityInfo.
    ```

3.  After you finish using the obtained  **BundleInfo**  object, clear the memory space occupied by the object in a timely manner to prevent memory leakage.

    ```
    ClearBundleInfo(&bundleInfo);
    ```


### Packing a HAP File<a name="section171771212328"></a>

The packing tool is generally integrated into the development tool or IDE, and you rarely have the occasion to use it directly. This section is provided for you to have a general knowledge of the packing tool. The JAR file of the packing tool is stored in the  **developtools/packing\_tool/jar**  directory of the open-source code.

-   CLI command parameters for packing a HAP file

    **Table  2**  Description of resource files required for packing

    <a name="table2151102833212"></a>
    <table><thead align="left"><tr id="row314812893218"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p1614732812320"><a name="p1614732812320"></a><a name="p1614732812320"></a>Command Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p214722819322"><a name="p214722819322"></a><a name="p214722819322"></a>Resource File</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p214714286324"><a name="p214714286324"></a><a name="p214714286324"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1014712863211"><a name="p1014712863211"></a><a name="p1014712863211"></a>Initial Value Allowed</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row614812289322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p16148182853216"><a name="p16148182853216"></a><a name="p16148182853216"></a>--mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p5148162814328"><a name="p5148162814328"></a><a name="p5148162814328"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p11481228143215"><a name="p11481228143215"></a><a name="p11481228143215"></a>This parameter is set to <strong id="b5192781718"><a name="b5192781718"></a><a name="b5192781718"></a>hap</strong> for packing the resource files into a HAP file.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p11148132811325"><a name="p11148132811325"></a><a name="p11148132811325"></a>No</p>
    </td>
    </tr>
    <tr id="row81486283327"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p6148132833215"><a name="p6148132833215"></a><a name="p6148132833215"></a>--json-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p214810286325"><a name="p214810286325"></a><a name="p214810286325"></a>Configuration file <strong id="b88502557175"><a name="b88502557175"></a><a name="b88502557175"></a>config.json</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p514802823216"><a name="p514802823216"></a><a name="p514802823216"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4148182813326"><a name="p4148182813326"></a><a name="p4148182813326"></a>No</p>
    </td>
    </tr>
    <tr id="row1214917281322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p171497285322"><a name="p171497285322"></a><a name="p171497285322"></a>--resources-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p414914286320"><a name="p414914286320"></a><a name="p414914286320"></a>Resource file <strong id="b62311484202"><a name="b62311484202"></a><a name="b62311484202"></a>resources</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p41492286324"><a name="p41492286324"></a><a name="p41492286324"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1114922812327"><a name="p1114922812327"></a><a name="p1114922812327"></a>Yes</p>
    </td>
    </tr>
    <tr id="row14149122817322"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11149528173218"><a name="p11149528173218"></a><a name="p11149528173218"></a>--assets-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p314918286324"><a name="p314918286324"></a><a name="p314918286324"></a>Resource file <strong id="b847745320206"><a name="b847745320206"></a><a name="b847745320206"></a>assets</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1414916284327"><a name="p1414916284327"></a><a name="p1414916284327"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p9149122817324"><a name="p9149122817324"></a><a name="p9149122817324"></a>Yes</p>
    </td>
    </tr>
    <tr id="row41501728193219"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p514918280325"><a name="p514918280325"></a><a name="p514918280325"></a>--lib-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p16149162823212"><a name="p16149162823212"></a><a name="p16149162823212"></a>Dependent library file</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p12149122853216"><a name="p12149122853216"></a><a name="p12149122853216"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p614962853217"><a name="p614962853217"></a><a name="p614962853217"></a>Yes</p>
    </td>
    </tr>
    <tr id="row131501928183212"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p4150122833213"><a name="p4150122833213"></a><a name="p4150122833213"></a>--shared-libs-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p15150112814322"><a name="p15150112814322"></a><a name="p15150112814322"></a>Shared library file</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p20150128113212"><a name="p20150128113212"></a><a name="p20150128113212"></a>The shared library is used by system applications in special cases.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p181501928183214"><a name="p181501928183214"></a><a name="p181501928183214"></a>Yes</p>
    </td>
    </tr>
    <tr id="row10150142812329"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1015011286320"><a name="p1015011286320"></a><a name="p1015011286320"></a>--ability-so-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p6150728123214"><a name="p6150728123214"></a><a name="p6150728123214"></a>SO file providing main functionality</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p16150192813323"><a name="p16150192813323"></a><a name="p16150192813323"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1315052811325"><a name="p1315052811325"></a><a name="p1315052811325"></a>Yes</p>
    </td>
    </tr>
    <tr id="row51519280321"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p315092813214"><a name="p315092813214"></a><a name="p315092813214"></a>--index-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1115012813325"><a name="p1115012813325"></a><a name="p1115012813325"></a>Resource index</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p111501028123220"><a name="p111501028123220"></a><a name="p111501028123220"></a>The resource index file is generated by the resource generation tool and integrated by the resource pipeline.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1115122811326"><a name="p1115122811326"></a><a name="p1115122811326"></a>Yes</p>
    </td>
    </tr>
    <tr id="row91511928203211"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0151328173211"><a name="p0151328173211"></a><a name="p0151328173211"></a>--out-path</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p215112833214"><a name="p215112833214"></a><a name="p215112833214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p11151152833217"><a name="p11151152833217"></a><a name="p11151152833217"></a>This parameter indicates the output path of the generated HAP file. The default value is the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1815110281328"><a name="p1815110281328"></a><a name="p1815110281328"></a>Yes</p>
    </td>
    </tr>
    <tr id="row4151162812329"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1015112280329"><a name="p1015112280329"></a><a name="p1015112280329"></a>--force</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p2151128133219"><a name="p2151128133219"></a><a name="p2151128133219"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p9151928183218"><a name="p9151928183218"></a><a name="p9151928183218"></a>This parameter specifies whether to overwrite an existing file with the same name. The default value is <strong id="b867781662412"><a name="b867781662412"></a><a name="b867781662412"></a>false</strong>.</p>
    </td>
    <td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p171511728143217"><a name="p171511728143217"></a><a name="p171511728143217"></a>Yes</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example HAP File Structure
    -   Development view

        ![](figures/en-us_image_0000001062942690.png)

    -   Compilation view

        ![](figures/en-us_image_0000001062334618.png)

    -   Run the following commands to pack a HAP file using the packing tool.

        ![](figures/en-us_image_0000001062476933.png)

        ```
        $ java -jar hmos_app_packing_tool.jar --mode hap --json-path ./config.json --assets-path ./assets/ --ability-so-path ./libentry.so --index-path ./resources.index --out-path out/entry.hap --force true
        ```



