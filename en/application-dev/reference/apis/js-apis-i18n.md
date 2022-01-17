# Internationalization \(i18n\) <a name="EN-US_TOPIC_0000001155058572"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>-   This module contains enhanced i18n APIs, which are not defined in ECMA 402.


## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import i18n from '@ohos.i18n';
```

## Required Permissions<a name="section11257113618419"></a>

None

## i18n.getDisplayLanguage<a name="section4734636131914"></a>

getDisplayLanguage\(language: string, locale: string, sentenceCase?: boolean\): string

Obtains the localized script for the specified language.

-   Parameters

    <a name="table8262171319013"></a>
    <table><thead align="left"><tr id="row726281313010"><th class="cellrowborder" valign="top" width="14.92%" id="mcps1.1.5.1.1"><p id="p426217131016"><a name="p426217131016"></a><a name="p426217131016"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.5%" id="mcps1.1.5.1.2"><p id="p42622131804"><a name="p42622131804"></a><a name="p42622131804"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p208801115312"><a name="p208801115312"></a><a name="p208801115312"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06%" id="mcps1.1.5.1.4"><p id="p926251313010"><a name="p926251313010"></a><a name="p926251313010"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row42621713304"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p0262813102"><a name="p0262813102"></a><a name="p0262813102"></a>language</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p1926261314016"><a name="p1926261314016"></a><a name="p1926261314016"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p088011110311"><a name="p088011110311"></a><a name="p088011110311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p152627133014"><a name="p152627133014"></a><a name="p152627133014"></a>Specified language.</p>
    </td>
    </tr>
    <tr id="row15880755501"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p1348011161519"><a name="p1348011161519"></a><a name="p1348011161519"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p68801855808"><a name="p68801855808"></a><a name="p68801855808"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1188014118315"><a name="p1188014118315"></a><a name="p1188014118315"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p78803551506"><a name="p78803551506"></a><a name="p78803551506"></a>Locale ID.</p>
    </td>
    </tr>
    <tr id="row109041353904"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p199055531001"><a name="p199055531001"></a><a name="p199055531001"></a>sentenceCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p59058531015"><a name="p59058531015"></a><a name="p59058531015"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1888021103111"><a name="p1888021103111"></a><a name="p1888021103111"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p199051053209"><a name="p199051053209"></a><a name="p199051053209"></a>Whether to use sentence case for the localized script.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table0483117706"></a>
    <table><thead align="left"><tr id="row6483417306"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p7483617903"><a name="p7483617903"></a><a name="p7483617903"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p14835171705"><a name="p14835171705"></a><a name="p14835171705"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8483111717020"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1248320178013"><a name="p1248320178013"></a><a name="p1248320178013"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p24836172000"><a name="p24836172000"></a><a name="p24836172000"></a>Localized script for the specified language.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getDisplayLanguage("zh", "en-GB", true);
    i18n.getDisplayLanguage("zh", "en-GB");
    ```


## i18n.getDisplayCountry<a name="section156643561735"></a>

getDisplayCountry\(country: string, locale: string, sentenceCase?: boolean\): string

Obtains the localized script for the specified country.

-   Parameters

    <a name="table566415619320"></a>
    <table><thead align="left"><tr id="row86656561632"><th class="cellrowborder" valign="top" width="14.92%" id="mcps1.1.5.1.1"><p id="p366595612316"><a name="p366595612316"></a><a name="p366595612316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.5%" id="mcps1.1.5.1.2"><p id="p766513561836"><a name="p766513561836"></a><a name="p766513561836"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p5380185513302"><a name="p5380185513302"></a><a name="p5380185513302"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06%" id="mcps1.1.5.1.4"><p id="p466585612312"><a name="p466585612312"></a><a name="p466585612312"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row196651356536"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p1666515564316"><a name="p1666515564316"></a><a name="p1666515564316"></a>country</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p19665135612319"><a name="p19665135612319"></a><a name="p19665135612319"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p13380155519303"><a name="p13380155519303"></a><a name="p13380155519303"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p15665205611310"><a name="p15665205611310"></a><a name="p15665205611310"></a>Specified country.</p>
    </td>
    </tr>
    <tr id="row1766595615310"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p16651156431"><a name="p16651156431"></a><a name="p16651156431"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p6665656936"><a name="p6665656936"></a><a name="p6665656936"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p638045563019"><a name="p638045563019"></a><a name="p638045563019"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p18665456932"><a name="p18665456932"></a><a name="p18665456932"></a>Locale ID.</p>
    </td>
    </tr>
    <tr id="row186658561436"><td class="cellrowborder" valign="top" width="14.92%" headers="mcps1.1.5.1.1 "><p id="p146650564311"><a name="p146650564311"></a><a name="p146650564311"></a>sentenceCase</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.5%" headers="mcps1.1.5.1.2 "><p id="p466510566311"><a name="p466510566311"></a><a name="p466510566311"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p143800551304"><a name="p143800551304"></a><a name="p143800551304"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06%" headers="mcps1.1.5.1.4 "><p id="p13665145612315"><a name="p13665145612315"></a><a name="p13665145612315"></a>Whether to use sentence case for the localized script.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table14665145616317"></a>
    <table><thead align="left"><tr id="row46651556932"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p366535611320"><a name="p366535611320"></a><a name="p366535611320"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p066512561431"><a name="p066512561431"></a><a name="p066512561431"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4665115614318"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1766615561337"><a name="p1766615561337"></a><a name="p1766615561337"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p18666185614320"><a name="p18666185614320"></a><a name="p18666185614320"></a>Localized script for the specified country.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getDisplayCountry("zh-CN", "en-GB", true);
    i18n.getDisplayCountry("zh-CN", "en-GB");
    ```


## i18n.getSystemLanguage<a name="section25111622174311"></a>

getSystemLanguage\(\): string

Obtains the system language.

-   Return values

    <a name="table10512322154313"></a>
    <table><thead align="left"><tr id="row35125225432"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p251212225435"><a name="p251212225435"></a><a name="p251212225435"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p10512132211433"><a name="p10512132211433"></a><a name="p10512132211433"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row451262234310"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p155122222439"><a name="p155122222439"></a><a name="p155122222439"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p651218222432"><a name="p651218222432"></a><a name="p651218222432"></a>System language ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getSystemLanguage();
    ```


## i18n.getSystemRegion<a name="section65121922114312"></a>

getSystemRegion\(\): string

Obtains the system region.

-   Return values

    <a name="table145141228431"></a>
    <table><thead align="left"><tr id="row85141522184310"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p75141722184315"><a name="p75141722184315"></a><a name="p75141722184315"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p651482224315"><a name="p651482224315"></a><a name="p651482224315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1051442244317"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p7514222164318"><a name="p7514222164318"></a><a name="p7514222164318"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p11514522104314"><a name="p11514522104314"></a><a name="p11514522104314"></a>System region ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getSystemRegion();
    ```


## i18n.getSystemLocale<a name="section10514122204316"></a>

getSystemLocale\(\): string

Obtains the system locale.

-   Return values

    <a name="table11515122294317"></a>
    <table><thead align="left"><tr id="row15515422144313"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p205151722194316"><a name="p205151722194316"></a><a name="p205151722194316"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p12515132211434"><a name="p12515132211434"></a><a name="p12515132211434"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row551612214432"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p8516142217436"><a name="p8516142217436"></a><a name="p8516142217436"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p45163224436"><a name="p45163224436"></a><a name="p45163224436"></a>System locale ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getSystemLocale();
    ```


