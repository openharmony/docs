# HiSysEvent Listening<a name="EN-US_TOPIC_0000001185655868"></a>

-   [Overview](#section315316685112)
-   [Available APIs](#section0342191810519)
-   [How to Develop](#section123181432175110)
    -   [C++](#section2016116181902)


## Overview<a name="section315316685112"></a>

HiSysEvent supports listening for events across processes. You can register a listener to listen for concerned events on a real-time basis. For example, you can enable the battery module to listen for power consumption event for power usage analysis.

## Available APIs<a name="section0342191810519"></a>

**Table  1**  HiSysEvent listener APIs

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="51.88%" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p877916438211"><a name="p877916438211"></a><a name="p877916438211"></a>int HiSysEventManager::AddEventListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener, std::vector&lt;struct ListenerRule&gt;&amp; rules)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>Registers a listener for system events. You can listen for certain events by specifying rules.</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>Input arguments:</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li><strong id="b5330432115819"><a name="b5330432115819"></a><a name="b5330432115819"></a>listener</strong>: callback object for system events.</li><li><strong id="b1518805912597"><a name="b1518805912597"></a><a name="b1518805912597"></a>rules</strong>: rules for event listening.</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>Return values</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li><strong id="b117641849702"><a name="b117641849702"></a><a name="b117641849702"></a>0</strong>: Repeated registration is successful.</li><li><strong id="b2682415314"><a name="b2682415314"></a><a name="b2682415314"></a>1</strong>: Initial registration is successful.</li><li>Other values: Registration has failed.</li></ul>
</td>
</tr>
<tr id="row910319443242"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p15104154411248"><a name="p15104154411248"></a><a name="p15104154411248"></a>void HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p1104194420248"><a name="p1104194420248"></a><a name="p1104194420248"></a>Removes the listener for system events.</p>
<p id="p7943171095411"><a name="p7943171095411"></a><a name="p7943171095411"></a>Input arguments:</p>
<a name="ul894321075411"></a><a name="ul894321075411"></a><ul id="ul894321075411"><li><strong id="b178371510181317"><a name="b178371510181317"></a><a name="b178371510181317"></a>listener</strong>: callback object for system events.</li></ul>
<p id="p9744631162515"><a name="p9744631162515"></a><a name="p9744631162515"></a>Return value: none</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  HiSysEvent listener rules

<a name="table1144011610564"></a>
<table><thead align="left"><tr id="row124411716175611"><th class="cellrowborder" valign="top" width="48.11%" id="mcps1.2.3.1.1"><p id="p19441151675610"><a name="p19441151675610"></a><a name="p19441151675610"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="51.89%" id="mcps1.2.3.1.2"><p id="p16441171616563"><a name="p16441171616563"></a><a name="p16441171616563"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row174411216105615"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p496413536613"><a name="p496413536613"></a><a name="p496413536613"></a><span>uint32_t</span> ruleType</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><p id="p94416160565"><a name="p94416160565"></a><a name="p94416160565"></a>Rule type. The matching scope includes <strong id="b638713414175"><a name="b638713414175"></a><a name="b638713414175"></a>domain</strong> and <strong id="b128648618171"><a name="b128648618171"></a><a name="b128648618171"></a>eventName</strong>. The value can be any of the following:</p>
<a name="ul1652866141814"></a><a name="ul1652866141814"></a><ul id="ul1652866141814"><li>1: whole word matching.</li><li>2: prefix matching.</li><li>3: regular expression matching.</li><li>Other values: invalid matching mode.</li></ul>
</td>
</tr>
<tr id="row64411816125614"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p1258135313712"><a name="p1258135313712"></a><a name="p1258135313712"></a>std::string domain</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><a name="ul14905926102311"></a><a name="ul14905926102311"></a><ul id="ul14905926102311"><li><strong id="b152431514132110"><a name="b152431514132110"></a><a name="b152431514132110"></a>domain</strong>: domain to which the event belongs. By default, an empty string indicates that the domain is successfully matched.</li></ul>
</td>
</tr>
<tr id="row244161615619"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p227913101887"><a name="p227913101887"></a><a name="p227913101887"></a>std::string eventName</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><a name="ul248063132319"></a><a name="ul248063132319"></a><ul id="ul248063132319"><li><strong id="b197622401229"><a name="b197622401229"></a><a name="b197622401229"></a>eventName</strong>: event name. By default, an empty string indicates that the event name is successfully matched.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  3**  HiSysEvent callback object

<a name="table1011703742711"></a>
<table><thead align="left"><tr id="row121187375270"><th class="cellrowborder" valign="top" width="48.25%" id="mcps1.2.3.1.1"><p id="p2118143782719"><a name="p2118143782719"></a><a name="p2118143782719"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="51.74999999999999%" id="mcps1.2.3.1.2"><p id="p4118037152710"><a name="p4118037152710"></a><a name="p4118037152710"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row111823719274"><td class="cellrowborder" valign="top" width="48.25%" headers="mcps1.2.3.1.1 "><p id="p161181537112712"><a name="p161181537112712"></a><a name="p161181537112712"></a>void HiSysEventSubscribeCallBackBase::OnHandle(const std::string&amp; domain, const std::string&amp; eventName, const int eventType, const std::string&amp; eventDetail)</p>
</td>
<td class="cellrowborder" valign="top" width="51.74999999999999%" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>Callback object for system events.</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>Input arguments:</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li><strong id="b19691125212280"><a name="b19691125212280"></a><a name="b19691125212280"></a>domain</strong>: domain to which the event belongs.</li><li><strong id="b144121713192910"><a name="b144121713192910"></a><a name="b144121713192910"></a>eventName</strong>: event name.</li><li><strong id="b410512122915"><a name="b410512122915"></a><a name="b410512122915"></a>eventType</strong>: event type.</li><li><strong id="b89521717103013"><a name="b89521717103013"></a><a name="b89521717103013"></a>eventDetail</strong>: JSON string containing event information.</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>Return value: none</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section123181432175110"></a>

### **C++**<a name="section2016116181902"></a>

In this example, you'll be instructed to register a listener for all system events that belong to the  **HIVIEWDFX**  domain.

1.  Develop the source code.

    -   Import the corresponding header file:

        hisysevent\_manager.h

    -   Implement the callback API.

        HiSysEventSubscribeCallBackBase::OnHandle\(const std::string& domain, const std::string& eventName, const int eventType, const std::string& eventDetail\)

    -   Register a callback object.

        HiSysEventManager::AddEventListener\(std::shared\_ptr<HiSysEventSubscribeCallBackBase\> listener, std::vector<struct ListenerRule\>& rules\)


    ```
    // Register a listener for all system events that belong to the HIVIEWDFX domain.
    #include "hisysevent_manager.h"
    #include <iostream>
    namespace OHOS {
    namespace HiviewDFX {
    // Implement the API for registering a listener for callback objects.
    void HiSysEventToolListener::OnHandle(const std::string& domain, const std::string& eventName,
        const int eventType, const std::string& eventDetail)
    {
        std::cout << eventDetail << std::endl;
    }
    
    void HiSysEventToolListener::OnServiceDied()
    {
        std::cout << std::string("service disconnect, exit") << std::endl;
        exit(0);
    }
    } // namespace HiviewDFX
    } // namespace OHOS
    
    // Register a listener for callback objects.
    auto toolListener = std::make_shared<HiSysEventToolListener>();
    struct ListenerRule rule;
    rule.ruleType = 1; // 1: default type
    rule.domain = "HIVIEWDFX";
    std::vector<struct ListenerRule> sysRules;
    sysRules.push_back(rule);
    HiSysEventManager::AddEventListener(toolListener, sysRules);
    ```

2.  Modify the  **BUILD.gn**  file.

    In the  **BUILD.gn**  file, add the  **libhisyseventmanager**  library that depends on the** hisysevent\_native**  component.

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```


