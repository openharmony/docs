#  Internationalization (i18n)<a name="EN-US_TOPIC_0000001222383529"></a>


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

- Parameters

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


## i18n.isRTL<sup>8+</sup><a name="section192634363279"></a>

isRTL\(locale: string\): boolean

Checks whether the localized script for the specified language is displayed from right to left.

-   Parameters

    <a name="table7263153692718"></a>
    <table><thead align="left"><tr id="row1226353614278"><th class="cellrowborder" valign="top" width="16.13%" id="mcps1.1.4.1.1"><p id="p17263103682718"><a name="p17263103682718"></a><a name="p17263103682718"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.44%" id="mcps1.1.4.1.2"><p id="p13263153682713"><a name="p13263153682713"></a><a name="p13263153682713"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.43%" id="mcps1.1.4.1.3"><p id="p7263536162720"><a name="p7263536162720"></a><a name="p7263536162720"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8263136142717"><td class="cellrowborder" valign="top" width="16.13%" headers="mcps1.1.4.1.1 "><p id="p11263103682713"><a name="p11263103682713"></a><a name="p11263103682713"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.44%" headers="mcps1.1.4.1.2 "><p id="p626313692711"><a name="p626313692711"></a><a name="p626313692711"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.43%" headers="mcps1.1.4.1.3 "><p id="p82641036162710"><a name="p82641036162710"></a><a name="p82641036162710"></a>Locale ID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table826516366273"></a>
    <table><thead align="left"><tr id="row6265143616271"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p626533612715"><a name="p626533612715"></a><a name="p626533612715"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p1026563682714"><a name="p1026563682714"></a><a name="p1026563682714"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22651136172714"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1326573610275"><a name="p1326573610275"></a><a name="p1326573610275"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p1426512364278"><a name="p1426512364278"></a><a name="p1426512364278"></a>The value <strong id="b19401141034713"><a name="b19401141034713"></a><a name="b19401141034713"></a>true</strong> indicates that the localized script is displayed from right to left, and value <strong id="b1140191054710"><a name="b1140191054710"></a><a name="b1140191054710"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.isRTL("zh-CN");// Since Chinese is not written from right to left, false is returned.
    i18n.isRTL("ar-EG");// Since Arabic is written from right to left, true is returned.
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


## i18n.getCalendar<sup>8+</sup><a name="section735791310514"></a>

getCalendar\(locale: string, type? : string\): Calendar

Obtains a  **Calendar**  object.

-   Parameters

    <a name="table33577139517"></a>
    <table><thead align="left"><tr id="row1835791317513"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p17357913125116"><a name="p17357913125116"></a><a name="p17357913125116"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p3357171316511"><a name="p3357171316511"></a><a name="p3357171316511"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p1521711445145"><a name="p1521711445145"></a><a name="p1521711445145"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p2357813165115"><a name="p2357813165115"></a><a name="p2357813165115"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16358101325118"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p173582131516"><a name="p173582131516"></a><a name="p173582131516"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p335881385113"><a name="p335881385113"></a><a name="p335881385113"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p4217144411145"><a name="p4217144411145"></a><a name="p4217144411145"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p23582134513"><a name="p23582134513"></a><a name="p23582134513"></a>Valid locale value, for example, <strong id="b1219551917559"><a name="b1219551917559"></a><a name="b1219551917559"></a>zh-Hans-CN</strong>.</p>
    </td>
    </tr>
    <tr id="row408511276"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p1301251675"><a name="p1301251675"></a><a name="p1301251675"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p20751571"><a name="p20751571"></a><a name="p20751571"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p14217134441420"><a name="p14217134441420"></a><a name="p14217134441420"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p17125116718"><a name="p17125116718"></a><a name="p17125116718"></a>Valid calendar type. Currently, the valid types are as follows: <strong id="b10639957185911"><a name="b10639957185911"></a><a name="b10639957185911"></a>buddhist</strong>, <strong id="b612865985915"><a name="b612865985915"></a><a name="b612865985915"></a>chinese</strong>, <strong id="b0224611007"><a name="b0224611007"></a><a name="b0224611007"></a>coptic</strong>, <strong id="b1967913709"><a name="b1967913709"></a><a name="b1967913709"></a>ethiopic</strong>, <strong id="b173801451015"><a name="b173801451015"></a><a name="b173801451015"></a>hebrew</strong>, <strong id="b97751671105"><a name="b97751671105"></a><a name="b97751671105"></a>gregory</strong>, <strong id="b112149908"><a name="b112149908"></a><a name="b112149908"></a>indian</strong>, <strong id="b136596125012"><a name="b136596125012"></a><a name="b136596125012"></a>islamic_civil</strong>, <strong id="b1074811513017"><a name="b1074811513017"></a><a name="b1074811513017"></a>islamic_tbla</strong>, <strong id="b1623221911014"><a name="b1623221911014"></a><a name="b1623221911014"></a>islamic_umalqura</strong>, <strong id="b49202205010"><a name="b49202205010"></a><a name="b49202205010"></a>japanese</strong>, and <strong id="b105731443996"><a name="b105731443996"></a><a name="b105731443996"></a>persian</strong>. If this parameter is left unspecified, the default calendar type of the specified locale is used.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table4358161315113"></a>
    <table><thead align="left"><tr id="row935810136511"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p835814136514"><a name="p835814136514"></a><a name="p835814136514"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p19358013175114"><a name="p19358013175114"></a><a name="p19358013175114"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8358101314512"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p4521253399"><a name="p4521253399"></a><a name="p4521253399"></a><a href="#section734252215124">Calendar</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p835801305116"><a name="p835801305116"></a><a name="p835801305116"></a><strong id="b198875285514"><a name="b198875285514"></a><a name="b198875285514"></a>Calendar</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getCalendar("zh-Hans", "gregory");
    ```


## Calendar<sup>8+</sup><a name="section734252215124"></a>

### setTime<sup>8+</sup><a name="section15209181154511"></a>

setTime\(date: Date\): void

Sets the date for this  **Calendar**  object.

-   Parameters

    <a name="table142096113459"></a>
    <table><thead align="left"><tr id="row920913134517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p02091913452"><a name="p02091913452"></a><a name="p02091913452"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p0209015455"><a name="p0209015455"></a><a name="p0209015455"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p132092113453"><a name="p132092113453"></a><a name="p132092113453"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p520961194514"><a name="p520961194514"></a><a name="p520961194514"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row22096114512"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7209111164514"><a name="p7209111164514"></a><a name="p7209111164514"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p520910154516"><a name="p520910154516"></a><a name="p520910154516"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p172093194517"><a name="p172093194517"></a><a name="p172093194517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p142092114452"><a name="p142092114452"></a><a name="p142092114452"></a>Date to be set for the <strong id="b1825112714818"><a name="b1825112714818"></a><a name="b1825112714818"></a>Calendar</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var calendar = I18n.getCalendar("en-US", "gregory");
    var date = new Date(2021, 10, 7, 8, 0, 0, 0);
    calendar.setTime(date);
    ```


### setTime<sup>8+</sup><a name="section52101815455"></a>

setTime\(time: number\): void

Sets the date and time for this  **Calendar**  object. The value is represented by the number of milliseconds that have elapsed since the Unix epoch \(00:00:00 UTC on January 1, 1970\).

-   Parameters

    <a name="table1952384532312"></a>
    <table><thead align="left"><tr id="row175232458238"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p552324542310"><a name="p552324542310"></a><a name="p552324542310"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p8523174572318"><a name="p8523174572318"></a><a name="p8523174572318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p7523144516230"><a name="p7523144516230"></a><a name="p7523144516230"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p25231545152312"><a name="p25231545152312"></a><a name="p25231545152312"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15231745172312"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1952315452234"><a name="p1952315452234"></a><a name="p1952315452234"></a>time</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p45241458234"><a name="p45241458234"></a><a name="p45241458234"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p852411459231"><a name="p852411459231"></a><a name="p852411459231"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9524104532320"><a name="p9524104532320"></a><a name="p9524104532320"></a>Number of milliseconds that have elapsed since the Unix epoch.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var calendar = I18n.getCalendar("en-US", "gregory");
    calendar.setTime(10540800000);
    ```


### set<sup>8+</sup><a name="section1921014119450"></a>

set\(year: number, month: number, date:number, hour?: number, minute?: number, second?: number\): void

Sets the year, month, day, hour, minute, and second for this  **Calendar**  object.

-   Parameters

    <a name="table1121041124517"></a>
    <table><thead align="left"><tr id="row72119111452"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1721171154513"><a name="p1721171154513"></a><a name="p1721171154513"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p122112154518"><a name="p122112154518"></a><a name="p122112154518"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p12111164518"><a name="p12111164518"></a><a name="p12111164518"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p121119184515"><a name="p121119184515"></a><a name="p121119184515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0211161144516"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p72117118454"><a name="p72117118454"></a><a name="p72117118454"></a>year</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p82113120459"><a name="p82113120459"></a><a name="p82113120459"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p321115194518"><a name="p321115194518"></a><a name="p321115194518"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p221118118453"><a name="p221118118453"></a><a name="p221118118453"></a>Year to set.</p>
    </td>
    </tr>
    <tr id="row8345101714272"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11346191713274"><a name="p11346191713274"></a><a name="p11346191713274"></a>month</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p634616178276"><a name="p634616178276"></a><a name="p634616178276"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1934681772714"><a name="p1934681772714"></a><a name="p1934681772714"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1434621732712"><a name="p1434621732712"></a><a name="p1434621732712"></a>Month to set.</p>
    </td>
    </tr>
    <tr id="row8623420192713"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p15623920102711"><a name="p15623920102711"></a><a name="p15623920102711"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p136231205271"><a name="p136231205271"></a><a name="p136231205271"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p176231420112714"><a name="p176231420112714"></a><a name="p176231420112714"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p76237206271"><a name="p76237206271"></a><a name="p76237206271"></a>Day to set.</p>
    </td>
    </tr>
    <tr id="row8528633152712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6528933182719"><a name="p6528933182719"></a><a name="p6528933182719"></a>hour</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p352863315278"><a name="p352863315278"></a><a name="p352863315278"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12528533182720"><a name="p12528533182720"></a><a name="p12528533182720"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p55281433192714"><a name="p55281433192714"></a><a name="p55281433192714"></a>Hour to set.</p>
    </td>
    </tr>
    <tr id="row18534224162711"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6534192412275"><a name="p6534192412275"></a><a name="p6534192412275"></a>minute</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1453402411277"><a name="p1453402411277"></a><a name="p1453402411277"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p853472412717"><a name="p853472412717"></a><a name="p853472412717"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p95343245272"><a name="p95343245272"></a><a name="p95343245272"></a>Minute to set.</p>
    </td>
    </tr>
    <tr id="row5222529102715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p182221291275"><a name="p182221291275"></a><a name="p182221291275"></a>second</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1522211290279"><a name="p1522211290279"></a><a name="p1522211290279"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12222295277"><a name="p12222295277"></a><a name="p12222295277"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18222229162710"><a name="p18222229162710"></a><a name="p18222229162710"></a>Second to set.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setTime(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
    ```


### setTimeZone<sup>8+</sup><a name="section7560193714354"></a>

setTimeZone\(timezone: string\): void

Sets the time zone of this  **Calendar**  object.

-   Parameters

    <a name="table1956173763518"></a>
    <table><thead align="left"><tr id="row205611637163512"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p12561113717355"><a name="p12561113717355"></a><a name="p12561113717355"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p18561237113513"><a name="p18561237113513"></a><a name="p18561237113513"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p25611637103514"><a name="p25611637103514"></a><a name="p25611637103514"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p45611237203517"><a name="p45611237203517"></a><a name="p45611237203517"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1561143743514"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1856173714353"><a name="p1856173714353"></a><a name="p1856173714353"></a>timezone</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1756117377352"><a name="p1756117377352"></a><a name="p1756117377352"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p0561133773516"><a name="p0561133773516"></a><a name="p0561133773516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p11561103713359"><a name="p11561103713359"></a><a name="p11561103713359"></a>Time zone, for example, <strong id="b174087184476"><a name="b174087184476"></a><a name="b174087184476"></a>Asia/Shanghai</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setTimeZone("Asia/Shanghai");
    ```


### getTimeZone<sup>8+</sup><a name="section132132174510"></a>

getTimeZone\(\): string

Obtains the time zone of this  **Calendar**  object.

-   Return values

    <a name="table1021321154511"></a>
    <table><thead align="left"><tr id="row172132011454"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p182131119455"><a name="p182131119455"></a><a name="p182131119455"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p421314104515"><a name="p421314104515"></a><a name="p421314104515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5213171154518"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1621320113459"><a name="p1621320113459"></a><a name="p1621320113459"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p1021319117453"><a name="p1021319117453"></a><a name="p1021319117453"></a>Time zone of the <strong id="b141952612917"><a name="b141952612917"></a><a name="b141952612917"></a>Calendar</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setTimeZone("Asia/Shanghai");
    calendar.getTimeZone(); // Asia/Shanghai"
    ```


### getFirstDayOfWeek<sup>8+</sup><a name="section17342422101214"></a>

getFirstDayOfWeek\(\): number

Obtains the start day of a week for this  **Calendar**  object.

-   Return values

    <a name="table2356104116435"></a>
    <table><thead align="left"><tr id="row1135614115437"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p173565418432"><a name="p173565418432"></a><a name="p173565418432"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p235615418434"><a name="p235615418434"></a><a name="p235615418434"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17356441174317"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p113564413432"><a name="p113564413432"></a><a name="p113564413432"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p1235634134317"><a name="p1235634134317"></a><a name="p1235634134317"></a>Start day of a week. The value <strong id="b1142754320316"><a name="b1142754320316"></a><a name="b1142754320316"></a>1</strong> indicates Sunday, and value <strong id="b343334343113"><a name="b343334343113"></a><a name="b343334343113"></a>7</strong> indicates Saturday.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var calendar = I18n.getCalendar("en-US", "gregory");
    calendar.getFirstDayOfWeek();
    ```


### setFirstDayOfWeek<sup>8+</sup><a name="section63421322151217"></a>

setFirstDayOfWeek\(value: number\): void

Sets the start day of a week for this  **Calendar**  object.

-   Parameters

    <a name="table14342222151217"></a>
    <table><thead align="left"><tr id="row1834218229121"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18343322171211"><a name="p18343322171211"></a><a name="p18343322171211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1343122121215"><a name="p1343122121215"></a><a name="p1343122121215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p7343122217127"><a name="p7343122217127"></a><a name="p7343122217127"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1334342211213"><a name="p1334342211213"></a><a name="p1334342211213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1934316225127"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1434392241210"><a name="p1434392241210"></a><a name="p1434392241210"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p634314227129"><a name="p634314227129"></a><a name="p634314227129"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1834342221216"><a name="p1834342221216"></a><a name="p1834342221216"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p73431922121210"><a name="p73431922121210"></a><a name="p73431922121210"></a>Start day of a week. The value <strong id="b166613239283"><a name="b166613239283"></a><a name="b166613239283"></a>1</strong> indicates Sunday, and value <strong id="b10661923142819"><a name="b10661923142819"></a><a name="b10661923142819"></a>7</strong> indicates Saturday.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setFirstDayOfWeek(0);
    ```


### getMinimalDaysInFirstWeek<sup>8+</sup><a name="section756814562910"></a>

getMinimalDaysInFirstWeek\(\): number

Obtains the minimum number of days in the first week of a year.

-   Return values

    <a name="table1756817512291"></a>
    <table><thead align="left"><tr id="row1856814572913"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p125685592919"><a name="p125685592919"></a><a name="p125685592919"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p656813532920"><a name="p656813532920"></a><a name="p656813532920"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row65686518298"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1956813516294"><a name="p1956813516294"></a><a name="p1956813516294"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p195721334308"><a name="p195721334308"></a><a name="p195721334308"></a>Minimum number of days in the first week of a year.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.getMinimalDaysInFirstWeek();
    ```


### setMinimalDaysInFirstWeek<sup>8+</sup><a name="section65683572912"></a>

setMinimalDaysInFirstWeek\(value: number\): void

Sets the minimum number of days in the first week of a year.

-   Parameters

    <a name="table14569155102912"></a>
    <table><thead align="left"><tr id="row5569125162916"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p45691357297"><a name="p45691357297"></a><a name="p45691357297"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p20569359294"><a name="p20569359294"></a><a name="p20569359294"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p105698542916"><a name="p105698542916"></a><a name="p105698542916"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1056919517296"><a name="p1056919517296"></a><a name="p1056919517296"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195699552910"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2569125162919"><a name="p2569125162919"></a><a name="p2569125162919"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1156916517296"><a name="p1156916517296"></a><a name="p1156916517296"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p6569153294"><a name="p6569153294"></a><a name="p6569153294"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p756935102918"><a name="p756935102918"></a><a name="p756935102918"></a>Minimum number of days in the first week of a year.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setMinimalDaysInFirstWeek(3);
    ```


### get<sup>8+</sup><a name="section590202354711"></a>

get\(field: string\): number

Obtains the value of the specified field in the  **Calendar**  object.

-   Parameters

    <a name="table11902323154711"></a>
    <table><thead align="left"><tr id="row3902112315470"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p59021223114717"><a name="p59021223114717"></a><a name="p59021223114717"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p890217233478"><a name="p890217233478"></a><a name="p890217233478"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p14903823184720"><a name="p14903823184720"></a><a name="p14903823184720"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p189033232474"><a name="p189033232474"></a><a name="p189033232474"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1690312334712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p99032233476"><a name="p99032233476"></a><a name="p99032233476"></a>field</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p29031023134711"><a name="p29031023134711"></a><a name="p29031023134711"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p17903192354719"><a name="p17903192354719"></a><a name="p17903192354719"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10903182317472"><a name="p10903182317472"></a><a name="p10903182317472"></a>Value of the specified field in the <strong id="b973814135911"><a name="b973814135911"></a><a name="b973814135911"></a>Calendar</strong> object. Currently, the valid fields are as follows: <strong id="b54517313373"><a name="b54517313373"></a><a name="b54517313373"></a>era</strong>, <strong id="b4603113353718"><a name="b4603113353718"></a><a name="b4603113353718"></a>year</strong>, <strong id="b139045344374"><a name="b139045344374"></a><a name="b139045344374"></a>month</strong>, <strong id="b1779363917373"><a name="b1779363917373"></a><a name="b1779363917373"></a>week_of_year</strong>, <strong id="b111284843711"><a name="b111284843711"></a><a name="b111284843711"></a>week_of_month</strong>, <strong id="b6644550123711"><a name="b6644550123711"></a><a name="b6644550123711"></a>date</strong>, <strong id="b2082310568374"><a name="b2082310568374"></a><a name="b2082310568374"></a>day_of_year</strong>, <strong id="b1755416033813"><a name="b1755416033813"></a><a name="b1755416033813"></a>day_of_week</strong>, <strong id="b79272383819"><a name="b79272383819"></a><a name="b79272383819"></a>day_of_week_in_month</strong>, <strong id="b446018516385"><a name="b446018516385"></a><a name="b446018516385"></a>hour</strong>, <strong id="b642312811386"><a name="b642312811386"></a><a name="b642312811386"></a>hour_of_day</strong>, <strong id="b1677913911383"><a name="b1677913911383"></a><a name="b1677913911383"></a>minute</strong>, <strong id="b590131115381"><a name="b590131115381"></a><a name="b590131115381"></a>second</strong>, <strong id="b17195201218383"><a name="b17195201218383"></a><a name="b17195201218383"></a>millisecond</strong>, <strong id="b18720161403816"><a name="b18720161403816"></a><a name="b18720161403816"></a>zone_offset</strong>, <strong id="b11319317173815"><a name="b11319317173815"></a><a name="b11319317173815"></a>dst_offset</strong>, <strong id="b7836920153817"><a name="b7836920153817"></a><a name="b7836920153817"></a>year_woy</strong>, <strong id="b5994125153817"><a name="b5994125153817"></a><a name="b5994125153817"></a>dow_local</strong>, <strong id="b14359193012387"><a name="b14359193012387"></a><a name="b14359193012387"></a>extended_year</strong>, <strong id="b1995813216385"><a name="b1995813216385"></a><a name="b1995813216385"></a>julian_day</strong>, <strong id="b13343204014389"><a name="b13343204014389"></a><a name="b13343204014389"></a>milliseconds_in_day</strong>, and <strong id="b208981843193819"><a name="b208981843193819"></a><a name="b208981843193819"></a>is_leap_month</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1574210103588"></a>
    <table><thead align="left"><tr id="row57436102582"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p17743210135814"><a name="p17743210135814"></a><a name="p17743210135814"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p117433101587"><a name="p117433101587"></a><a name="p117433101587"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row174316101582"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1974361035815"><a name="p1974361035815"></a><a name="p1974361035815"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p197430101589"><a name="p197430101589"></a><a name="p197430101589"></a>Value of the specified field. For example, if the year in the internal date of this <strong id="b713617105454"><a name="b713617105454"></a><a name="b713617105454"></a>Calendar</strong> object is <strong id="b4545113104514"><a name="b4545113104514"></a><a name="b4545113104514"></a>1990</strong>, the <strong id="b1780019104518"><a name="b1780019104518"></a><a name="b1780019104518"></a>get("year")</strong> function will return <strong id="b857122216453"><a name="b857122216453"></a><a name="b857122216453"></a>1990</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setTime(2021, 10, 1, 8, 0, 0); // set time to 2021.10.1 08:00:00
    calendar.get("hour_of_day"); // 8
    ```


### getDisplayName<sup>8+</sup><a name="section1443644124714"></a>

getDisplayName\(locale: string\): string

Obtains the name of the  **Calendar**  object displayed for the specified locale.

-   Parameters

    <a name="table1043717444710"></a>
    <table><thead align="left"><tr id="row164371442478"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1043719484720"><a name="p1043719484720"></a><a name="p1043719484720"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p134376417476"><a name="p134376417476"></a><a name="p134376417476"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p164373419474"><a name="p164373419474"></a><a name="p164373419474"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p443717418472"><a name="p443717418472"></a><a name="p443717418472"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1943710444712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p14437645479"><a name="p14437645479"></a><a name="p14437645479"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p74374417474"><a name="p74374417474"></a><a name="p74374417474"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1643734134715"><a name="p1643734134715"></a><a name="p1643734134715"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1943754204711"><a name="p1943754204711"></a><a name="p1943754204711"></a>Locale for which the name of the <strong id="b153411615135514"><a name="b153411615135514"></a><a name="b153411615135514"></a>Calendar</strong> object is displayed. For example, if <strong id="b15956959165512"><a name="b15956959165512"></a><a name="b15956959165512"></a>locale</strong> is <strong id="b3135193195616"><a name="b3135193195616"></a><a name="b3135193195616"></a>en-US</strong>, the name of the Buddhist calendar will be <strong id="b1136103015554"><a name="b1136103015554"></a><a name="b1136103015554"></a>Buddhist Calendar</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table829311451878"></a>
    <table><thead align="left"><tr id="row6293745570"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p629314454719"><a name="p629314454719"></a><a name="p629314454719"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p162934451773"><a name="p162934451773"></a><a name="p162934451773"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row62930457717"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1429419456710"><a name="p1429419456710"></a><a name="p1429419456710"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p1329434513717"><a name="p1329434513717"></a><a name="p1329434513717"></a>Name of the <strong id="b11296192614204"><a name="b11296192614204"></a><a name="b11296192614204"></a>Calendar</strong> object displayed for the specified locale.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("en-US", "buddhist");
    calendar.getDisplayName("zh"); // Obtain the name of the Buddhist calendar in zh.
    ```


### isWeekend<sup>8+</sup><a name="section10596150144719"></a>

isWeekend\(date?: Date\): boolean

Checks whether the specified date in this  **Calendar**  object is a weekend.

-   Parameters

    <a name="table1259640194712"></a>
    <table><thead align="left"><tr id="row459680124710"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1859716094719"><a name="p1859716094719"></a><a name="p1859716094719"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1159711064717"><a name="p1159711064717"></a><a name="p1159711064717"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p165971309473"><a name="p165971309473"></a><a name="p165971309473"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1959713024719"><a name="p1959713024719"></a><a name="p1959713024719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row259710064714"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p05978019477"><a name="p05978019477"></a><a name="p05978019477"></a>date</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p195976014711"><a name="p195976014711"></a><a name="p195976014711"></a>Date</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p059710012474"><a name="p059710012474"></a><a name="p059710012474"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p759790184716"><a name="p759790184716"></a><a name="p759790184716"></a>Specified date in this <strong id="b12909151184614"><a name="b12909151184614"></a><a name="b12909151184614"></a>Calendar</strong> object. If this parameter is left unspecified, the system checks whether the current date in the <strong id="b5327113114916"><a name="b5327113114916"></a><a name="b5327113114916"></a>Calendar</strong> object is a weekend.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table446781310810"></a>
    <table><thead align="left"><tr id="row194677130812"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p144671131983"><a name="p144671131983"></a><a name="p144671131983"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p104672138812"><a name="p104672138812"></a><a name="p104672138812"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13467181313813"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p17467141313814"><a name="p17467141313814"></a><a name="p17467141313814"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p134689131085"><a name="p134689131085"></a><a name="p134689131085"></a>The value true indicates that the date is a weekend, and value <strong id="b1878515462424"><a name="b1878515462424"></a><a name="b1878515462424"></a>false</strong> indicates a weekday.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var calendar = i18n.getCalendar("zh-Hans");
    calendar.setTime(2021, 11, 11, 8, 0, 0); // Set the time to 2021.11.11 08:00:00.
    calendar.isWeekend(); // false
    var date = new Date(2011, 11, 6, 9, 0, 0);
    calendar.isWeekend(date); // true
    ```


## PhoneNumberFormat<sup>8+</sup><a name="section1693273262315"></a>

### constructor<sup>8+</sup><a name="section186273446118"></a>

constructor\(country: string, options?: PhoneNumberFormatOptions\)

Creates a  **PhoneNumberFormat**  object.

Parameters

<a name="table6627244111119"></a>
<table><thead align="left"><tr id="row562834412111"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p1462854451114"><a name="p1462854451114"></a><a name="p1462854451114"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1762819446119"><a name="p1762819446119"></a><a name="p1762819446119"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p15628044141119"><a name="p15628044141119"></a><a name="p15628044141119"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p76286443111"><a name="p76286443111"></a><a name="p76286443111"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7628164419115"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p8628124414113"><a name="p8628124414113"></a><a name="p8628124414113"></a>country</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p862864421112"><a name="p862864421112"></a><a name="p862864421112"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p2062864441119"><a name="p2062864441119"></a><a name="p2062864441119"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p0628344161114"><a name="p0628344161114"></a><a name="p0628344161114"></a>Country or region to which the phone number to be formatted belongs.</p>
</td>
</tr>
<tr id="row1628344191118"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p7628114421115"><a name="p7628114421115"></a><a name="p7628114421115"></a>options</p>
</td>
<td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p19629144491117"><a name="p19629144491117"></a><a name="p19629144491117"></a><a href="#section208137352082">PhoneNumberFormatOptions</a></p>
</td>
<td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p11629134471115"><a name="p11629134471115"></a><a name="p11629134471115"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p2629134411115"><a name="p2629134411115"></a><a name="p2629134411115"></a>Options of the <strong id="b133271441355"><a name="b133271441355"></a><a name="b133271441355"></a>PhoneNumberFormat</strong> object.</p>
</td>
</tr>
</tbody>
</table>

-   Example

    ```
    var phoneNumberFormat= new i18n.PhoneNumberFormat("CN", {"type": "E164"});
    ```


### isValidNumber<sup>8+</sup><a name="section179323320232"></a>

isValidNumber\(number: string\): boolean

Checks whether the format of the specified phone number is valid.

-   Parameters

    <a name="table18932123242316"></a>
    <table><thead align="left"><tr id="row1193323214232"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p293317321234"><a name="p293317321234"></a><a name="p293317321234"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p6933163262311"><a name="p6933163262311"></a><a name="p6933163262311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p19933732112317"><a name="p19933732112317"></a><a name="p19933732112317"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p10933193232316"><a name="p10933193232316"></a><a name="p10933193232316"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8933932172315"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p9933193262319"><a name="p9933193262319"></a><a name="p9933193262319"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p149331632172311"><a name="p149331632172311"></a><a name="p149331632172311"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p293315321233"><a name="p293315321233"></a><a name="p293315321233"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p1993323202316"><a name="p1993323202316"></a><a name="p1993323202316"></a>Phone number to be checked.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10933163210234"></a>
    <table><thead align="left"><tr id="row3933193282318"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p0934032132314"><a name="p0934032132314"></a><a name="p0934032132314"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p8934103272315"><a name="p8934103272315"></a><a name="p8934103272315"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row189342326238"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p1293423232314"><a name="p1293423232314"></a><a name="p1293423232314"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p159346329238"><a name="p159346329238"></a><a name="p159346329238"></a>The value <strong id="b655418371355"><a name="b655418371355"></a><a name="b655418371355"></a>true</strong> indicates the phone number format is valid, and value <strong id="b551063319513"><a name="b551063319513"></a><a name="b551063319513"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
    phonenumberfmt.isValidNumber("15812312312");
    ```


### format<sup>8+</sup><a name="section34181141163218"></a>

format\(number: string\): string

Formats a phone number.

-   Parameters

    <a name="table154195418327"></a>
    <table><thead align="left"><tr id="row16419184103211"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p14199413321"><a name="p14199413321"></a><a name="p14199413321"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p34191041183213"><a name="p34191041183213"></a><a name="p34191041183213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p5419741103214"><a name="p5419741103214"></a><a name="p5419741103214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p44195415320"><a name="p44195415320"></a><a name="p44195415320"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row144194414329"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p04191341163218"><a name="p04191341163218"></a><a name="p04191341163218"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p11420141173218"><a name="p11420141173218"></a><a name="p11420141173218"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p20420114112327"><a name="p20420114112327"></a><a name="p20420114112327"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p8420204113328"><a name="p8420204113328"></a><a name="p8420204113328"></a>Phone number to be formatted.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table6420104123215"></a>
    <table><thead align="left"><tr id="row134201641123218"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1642054113213"><a name="p1642054113213"></a><a name="p1642054113213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p184201041113219"><a name="p184201041113219"></a><a name="p184201041113219"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1142014118324"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p194201741193214"><a name="p194201741193214"></a><a name="p194201741193214"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p9420241203211"><a name="p9420241203211"></a><a name="p9420241203211"></a>Formatted phone number.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var phonenumberfmt = new i18n.PhoneNumberFormat("CN");
    phonenumberfmt.format("15812312312");
    ```


## PhoneNumberFormatOptions<sup>8+</sup><a name="section208137352082"></a>

Defines the options for this  **PhoneNumberFormat**  object.

<a name="table581363516811"></a>
<table><thead align="left"><tr id="row581393517817"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p881312351783"><a name="p881312351783"></a><a name="p881312351783"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p138134351288"><a name="p138134351288"></a><a name="p138134351288"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p1481313351381"><a name="p1481313351381"></a><a name="p1481313351381"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p28132351689"><a name="p28132351689"></a><a name="p28132351689"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p7813635689"><a name="p7813635689"></a><a name="p7813635689"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row158131835687"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1181443520810"><a name="p1181443520810"></a><a name="p1181443520810"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p1581416352086"><a name="p1581416352086"></a><a name="p1581416352086"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p9814133515816"><a name="p9814133515816"></a><a name="p9814133515816"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p12814435287"><a name="p12814435287"></a><a name="p12814435287"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p781453518814"><a name="p781453518814"></a><a name="p781453518814"></a>Format type of a phone number. The available options are as follows: <strong id="b2090653219128"><a name="b2090653219128"></a><a name="b2090653219128"></a>E164</strong>, <strong id="b8729133516126"><a name="b8729133516126"></a><a name="b8729133516126"></a>INTERNATIONAL</strong>, <strong id="b78591736171217"><a name="b78591736171217"></a><a name="b78591736171217"></a>NATIONAL</strong>, and <strong id="b427354020121"><a name="b427354020121"></a><a name="b427354020121"></a>RFC3966</strong>.</p>
</td>
</tr>
</tbody>
</table>

## UnitInfo<sup>8+</sup><a name="section2018814515186"></a>

Defines the measurement unit information.

<a name="table581614110198"></a>
<table><thead align="left"><tr id="row168171119196"><th class="cellrowborder" valign="top" width="19.15%" id="mcps1.1.6.1.1"><p id="p17817311151914"><a name="p17817311151914"></a><a name="p17817311151914"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.8%" id="mcps1.1.6.1.2"><p id="p128170116192"><a name="p128170116192"></a><a name="p128170116192"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="6.12%" id="mcps1.1.6.1.3"><p id="p128171511141916"><a name="p128171511141916"></a><a name="p128171511141916"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.48%" id="mcps1.1.6.1.4"><p id="p38171011121920"><a name="p38171011121920"></a><a name="p38171011121920"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.6.1.5"><p id="p2817161118191"><a name="p2817161118191"></a><a name="p2817161118191"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1181719115198"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p1181751111919"><a name="p1181751111919"></a><a name="p1181751111919"></a>unit</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p48171711131920"><a name="p48171711131920"></a><a name="p48171711131920"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p11817151114194"><a name="p11817151114194"></a><a name="p11817151114194"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p6817711191916"><a name="p6817711191916"></a><a name="p6817711191916"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p28171511181914"><a name="p28171511181914"></a><a name="p28171511181914"></a>Name of the measurement unit, for example, <strong id="b01831838118"><a name="b01831838118"></a><a name="b01831838118"></a>meter</strong>, <strong id="b16720174116"><a name="b16720174116"></a><a name="b16720174116"></a>inch</strong>, or <strong id="b8771567115"><a name="b8771567115"></a><a name="b8771567115"></a>cup</strong>.</p>
</td>
</tr>
<tr id="row472203019193"><td class="cellrowborder" valign="top" width="19.15%" headers="mcps1.1.6.1.1 "><p id="p6721930191916"><a name="p6721930191916"></a><a name="p6721930191916"></a>measureSystem</p>
</td>
<td class="cellrowborder" valign="top" width="10.8%" headers="mcps1.1.6.1.2 "><p id="p15821738101917"><a name="p15821738101917"></a><a name="p15821738101917"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="6.12%" headers="mcps1.1.6.1.3 "><p id="p16821638171911"><a name="p16821638171911"></a><a name="p16821638171911"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.48%" headers="mcps1.1.6.1.4 "><p id="p682103851920"><a name="p682103851920"></a><a name="p682103851920"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.6.1.5 "><p id="p167223061914"><a name="p167223061914"></a><a name="p167223061914"></a>Measurement system. The value can be <strong id="b94239164313"><a name="b94239164313"></a><a name="b94239164313"></a>SI</strong>, <strong id="b9791317137"><a name="b9791317137"></a><a name="b9791317137"></a>US</strong>, or <strong id="b81571719033"><a name="b81571719033"></a><a name="b81571719033"></a>UK</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Util<sup>8+</sup><a name="section1183183813415"></a>

### unitConvert<sup>8+</sup><a name="section721519102512"></a>

unitConvert\(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string\): string

Converts one measurement unit into another and formats the unit based on the specified locale and style.

-   Parameters

    <a name="table132514517137"></a>
    <table><thead align="left"><tr id="row5325745111320"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p8325945151311"><a name="p8325945151311"></a><a name="p8325945151311"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p7325184514133"><a name="p7325184514133"></a><a name="p7325184514133"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p93255453132"><a name="p93255453132"></a><a name="p93255453132"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p18326184518133"><a name="p18326184518133"></a><a name="p18326184518133"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13261045181313"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p832694591312"><a name="p832694591312"></a><a name="p832694591312"></a>fromUnit</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p11326144521314"><a name="p11326144521314"></a><a name="p11326144521314"></a><a href="#section2018814515186">UnitInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p143261045161312"><a name="p143261045161312"></a><a name="p143261045161312"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p3326154515136"><a name="p3326154515136"></a><a name="p3326154515136"></a>Measurement unit to be converted.</p>
    </td>
    </tr>
    <tr id="row125831117146"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p35831819144"><a name="p35831819144"></a><a name="p35831819144"></a>toUnit</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1969491915145"><a name="p1969491915145"></a><a name="p1969491915145"></a><a href="#section2018814515186">UnitInfo</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p105834161412"><a name="p105834161412"></a><a name="p105834161412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p185841414140"><a name="p185841414140"></a><a name="p185841414140"></a>Measurement unit to be converted to.</p>
    </td>
    </tr>
    <tr id="row7950196111410"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1950176111419"><a name="p1950176111419"></a><a name="p1950176111419"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p18950196191417"><a name="p18950196191417"></a><a name="p18950196191417"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1095012671415"><a name="p1095012671415"></a><a name="p1095012671415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p59502617146"><a name="p59502617146"></a><a name="p59502617146"></a>Value of the measurement unit to be converted.</p>
    </td>
    </tr>
    <tr id="row1749198149"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p107507971418"><a name="p107507971418"></a><a name="p107507971418"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p2075011916143"><a name="p2075011916143"></a><a name="p2075011916143"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p11750396148"><a name="p11750396148"></a><a name="p11750396148"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p575069171414"><a name="p575069171414"></a><a name="p575069171414"></a>Locale used for formatting, for example, <strong id="b8984198172911"><a name="b8984198172911"></a><a name="b8984198172911"></a>zh-Hans-CN</strong>.</p>
    </td>
    </tr>
    <tr id="row5452141241414"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p124521512111412"><a name="p124521512111412"></a><a name="p124521512111412"></a>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1945211121146"><a name="p1945211121146"></a><a name="p1945211121146"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1845214126144"><a name="p1845214126144"></a><a name="p1845214126144"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p12452181271416"><a name="p12452181271416"></a><a name="p12452181271416"></a>Style used for formatting. The value can be <strong id="b13885195303818"><a name="b13885195303818"></a><a name="b13885195303818"></a>long</strong>, <strong id="b965955523812"><a name="b965955523812"></a><a name="b965955523812"></a>short</strong>, or <strong id="b15861057203811"><a name="b15861057203811"></a><a name="b15861057203811"></a>medium</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table23265456133"></a>
    <table><thead align="left"><tr id="row53268458135"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p19326174512130"><a name="p19326174512130"></a><a name="p19326174512130"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p163261445131318"><a name="p163261445131318"></a><a name="p163261445131318"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row332704514139"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p43271245131313"><a name="p43271245131313"></a><a name="p43271245131313"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p20327845141310"><a name="p20327845141310"></a><a name="p20327845141310"></a>Character string obtained after formatting based on the measurement unit specified by <strong id="b14371143487"><a name="b14371143487"></a><a name="b14371143487"></a>toUnit</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    I18n.Util.unitConvert({unit: "cup", measureSystem: "US"}, {unit: "liter", measureSystem: "SI"}, 1000, "en-US", "long");
    ```


## i18n.getInstance<sup>8+</sup><a name="section465715244426"></a>

getInstance\(locale?: string\): IndexUtil

Creates an  **IndexUtil**  object.

-   Parameters

    <a name="table6988825184613"></a>
    <table><thead align="left"><tr id="row129881025134618"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p149882025184617"><a name="p149882025184617"></a><a name="p149882025184617"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p898932584613"><a name="p898932584613"></a><a name="p898932584613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p598942516461"><a name="p598942516461"></a><a name="p598942516461"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p20989925134610"><a name="p20989925134610"></a><a name="p20989925134610"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13989112512465"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1655813392467"><a name="p1655813392467"></a><a name="p1655813392467"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p355816397461"><a name="p355816397461"></a><a name="p355816397461"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p19558163916466"><a name="p19558163916466"></a><a name="p19558163916466"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p75581739194613"><a name="p75581739194613"></a><a name="p75581739194613"></a>A string containing locale information, including the language, optional script, and region.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table899112516464"></a>
    <table><thead align="left"><tr id="row139911125124619"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1999122514464"><a name="p1999122514464"></a><a name="p1999122514464"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p89918251469"><a name="p89918251469"></a><a name="p89918251469"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4991192544611"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p944444554613"><a name="p944444554613"></a><a name="p944444554613"></a><a href="#section6846195915243">IndexUtil</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p94441945144614"><a name="p94441945144614"></a><a name="p94441945144614"></a><strong id="b2054265864916"><a name="b2054265864916"></a><a name="b2054265864916"></a>IndexUtil</strong> object mapping to the specified locale.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var indexUtil= i18n.getInstance("zh-CN");
    ```


## IndexUtil<sup>8+</sup><a name="section6846195915243"></a>

### getIndexList<sup>8+</sup><a name="section108481959142414"></a>

getIndexList\(\): Array<string\>

Obtains the index list for this  **locale**  object.

-   Return values

    <a name="table4850759112412"></a>
    <table><thead align="left"><tr id="row485055942414"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p14850115918248"><a name="p14850115918248"></a><a name="p14850115918248"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p68501459192413"><a name="p68501459192413"></a><a name="p68501459192413"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row28505594244"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p118501359122419"><a name="p118501359122419"></a><a name="p118501359122419"></a>Array&lt;string&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1085095982419"><a name="p1085095982419"></a><a name="p1085095982419"></a>Index list for this locale.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var indexUtil = i18n.getInstance("zh-CN");
    var indexList = indexUtil.getIndexList();
    ```


### addLocale<sup>8+</sup><a name="section1085195918241"></a>

addLocale\(locale: string\)

Adds the index of the new  **locale**  object to the index list.

-   Parameters

    <a name="table12851175917249"></a>
    <table><thead align="left"><tr id="row1185165919241"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p4851115915244"><a name="p4851115915244"></a><a name="p4851115915244"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p885285982419"><a name="p885285982419"></a><a name="p885285982419"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p485215596245"><a name="p485215596245"></a><a name="p485215596245"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1885255962411"><a name="p1885255962411"></a><a name="p1885255962411"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4852559102416"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p16852185915248"><a name="p16852185915248"></a><a name="p16852185915248"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p18521259122418"><a name="p18521259122418"></a><a name="p18521259122418"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p13852155972413"><a name="p13852155972413"></a><a name="p13852155972413"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p085255914241"><a name="p085255914241"></a><a name="p085255914241"></a>A string containing locale information, including the language, optional script, and region.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var indexUtil = i18n.getInstance("zh-CN");
    indexUtil.addLocale("en-US");
    ```


### getIndex<sup>8+</sup><a name="section477585175017"></a>

getIndex\(text: string\): string

Obtains the index of a  **text**  object.

-   Parameters

    <a name="table16538977518"></a>
    <table><thead align="left"><tr id="row115381871512"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p20539974512"><a name="p20539974512"></a><a name="p20539974512"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1253911785116"><a name="p1253911785116"></a><a name="p1253911785116"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p205392720518"><a name="p205392720518"></a><a name="p205392720518"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p105396725118"><a name="p105396725118"></a><a name="p105396725118"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row135399755112"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p105392725114"><a name="p105392725114"></a><a name="p105392725114"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p9539175516"><a name="p9539175516"></a><a name="p9539175516"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p8539176511"><a name="p8539176511"></a><a name="p8539176511"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p17539177165113"><a name="p17539177165113"></a><a name="p17539177165113"></a><strong id="b345663119182"><a name="b345663119182"></a><a name="b345663119182"></a>text</strong> object whose index is to be obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table145391373515"></a>
    <table><thead align="left"><tr id="row9540107185113"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p854016795113"><a name="p854016795113"></a><a name="p854016795113"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p65406795110"><a name="p65406795110"></a><a name="p65406795110"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row85401875512"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p1454037125110"><a name="p1454037125110"></a><a name="p1454037125110"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p135409717510"><a name="p135409717510"></a><a name="p135409717510"></a>Index of the <strong id="b42196822416"><a name="b42196822416"></a><a name="b42196822416"></a>text</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var indexUtil= i18n.getInstance("zh-CN");
    indexUtil.getIndex("hi"); // Return h.
    ```


## Character<sup>8+</sup><a name="section12707113365210"></a>

### isDigit<sup>8+</sup><a name="section191618218539"></a>

isDigit\(char: string\): boolean

Checks whether the input character string is comprised of digits.

-   Parameters

    <a name="table16162132110538"></a>
    <table><thead align="left"><tr id="row1916362175315"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p616382117532"><a name="p616382117532"></a><a name="p616382117532"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1163021125320"><a name="p1163021125320"></a><a name="p1163021125320"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1216372145317"><a name="p1216372145317"></a><a name="p1216372145317"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1016342125317"><a name="p1016342125317"></a><a name="p1016342125317"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2016392120530"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p16163521175310"><a name="p16163521175310"></a><a name="p16163521175310"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p21631421155317"><a name="p21631421155317"></a><a name="p21631421155317"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p131635217531"><a name="p131635217531"></a><a name="p131635217531"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p201632021145314"><a name="p201632021145314"></a><a name="p201632021145314"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table916418215531"></a>
    <table><thead align="left"><tr id="row20164192195319"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p121641021195311"><a name="p121641021195311"></a><a name="p121641021195311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1316492135311"><a name="p1316492135311"></a><a name="p1316492135311"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1416410211538"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p1816419213534"><a name="p1816419213534"></a><a name="p1816419213534"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p4164142145313"><a name="p4164142145313"></a><a name="p4164142145313"></a>The value <strong id="b3814161419326"><a name="b3814161419326"></a><a name="b3814161419326"></a>true</strong> indicates that the input character is a digit, and value <strong id="b06351730113213"><a name="b06351730113213"></a><a name="b06351730113213"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isdigit = Character.isDigit("1"); // Return true.
    ```


### isSpaceChar<sup>8+</sup><a name="section410075273413"></a>

isSpaceChar\(char: string\): boolean

Checks whether the input character is comprised of space.

-   Parameters

    <a name="table1010015283414"></a>
    <table><thead align="left"><tr id="row15100145273412"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p111001352163415"><a name="p111001352163415"></a><a name="p111001352163415"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1010116528342"><a name="p1010116528342"></a><a name="p1010116528342"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p13101145273412"><a name="p13101145273412"></a><a name="p13101145273412"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p11011952183415"><a name="p11011952183415"></a><a name="p11011952183415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1310135220340"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1310175210349"><a name="p1310175210349"></a><a name="p1310175210349"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1010115214341"><a name="p1010115214341"></a><a name="p1010115214341"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p61011752113413"><a name="p61011752113413"></a><a name="p61011752113413"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p4101052143417"><a name="p4101052143417"></a><a name="p4101052143417"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1310105283419"></a>
    <table><thead align="left"><tr id="row12102105223420"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p31022052143418"><a name="p31022052143418"></a><a name="p31022052143418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p2102125219349"><a name="p2102125219349"></a><a name="p2102125219349"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9102185211341"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p81025527347"><a name="p81025527347"></a><a name="p81025527347"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1210245243410"><a name="p1210245243410"></a><a name="p1210245243410"></a>The value <strong id="b42481754183718"><a name="b42481754183718"></a><a name="b42481754183718"></a>true</strong> indicates that the input character is a space, and value <strong id="b2248165443715"><a name="b2248165443715"></a><a name="b2248165443715"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isspacechar = Character.isSpaceChar("a"); // Return false.
    ```


### isWhitespace<sup>8+</sup><a name="section330415260418"></a>

isWhitespace\(char: string\): boolean

Checks whether the input character is comprised of white space.

-   Parameters

    <a name="table1930542674113"></a>
    <table><thead align="left"><tr id="row103051626114116"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p153051226124110"><a name="p153051226124110"></a><a name="p153051226124110"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1230512674118"><a name="p1230512674118"></a><a name="p1230512674118"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p430532654118"><a name="p430532654118"></a><a name="p430532654118"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p18306132617413"><a name="p18306132617413"></a><a name="p18306132617413"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row73061026154119"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p11306326184113"><a name="p11306326184113"></a><a name="p11306326184113"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p230642664120"><a name="p230642664120"></a><a name="p230642664120"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p6306202613417"><a name="p6306202613417"></a><a name="p6306202613417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p6306132694115"><a name="p6306132694115"></a><a name="p6306132694115"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1230602619416"></a>
    <table><thead align="left"><tr id="row530652615419"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p93073265414"><a name="p93073265414"></a><a name="p93073265414"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p030717261415"><a name="p030717261415"></a><a name="p030717261415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row430742619412"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p18307152634115"><a name="p18307152634115"></a><a name="p18307152634115"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p330710269413"><a name="p330710269413"></a><a name="p330710269413"></a>The value <strong id="b6934348153810"><a name="b6934348153810"></a><a name="b6934348153810"></a>true</strong> indicates that the input character is a white space, and value <strong id="b1794094873813"><a name="b1794094873813"></a><a name="b1794094873813"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var iswhitespace = Character.isWhitespace("a"); // Return false.
    ```


### isRTL<sup>8+</sup><a name="section1129311984317"></a>

isRTL\(char: string\): boolean

Checks whether the input character string is of the right to left \(RTL\) language.

-   Parameters

    <a name="table729361964318"></a>
    <table><thead align="left"><tr id="row4294171912436"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p3294119124316"><a name="p3294119124316"></a><a name="p3294119124316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p929414198432"><a name="p929414198432"></a><a name="p929414198432"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p7294151910437"><a name="p7294151910437"></a><a name="p7294151910437"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p129431912431"><a name="p129431912431"></a><a name="p129431912431"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row52945197432"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p192941192436"><a name="p192941192436"></a><a name="p192941192436"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1529418195437"><a name="p1529418195437"></a><a name="p1529418195437"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1295119104311"><a name="p1295119104311"></a><a name="p1295119104311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p429571912437"><a name="p429571912437"></a><a name="p429571912437"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table92951219114318"></a>
    <table><thead align="left"><tr id="row829531924320"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p10295519144315"><a name="p10295519144315"></a><a name="p10295519144315"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p122951019164311"><a name="p122951019164311"></a><a name="p122951019164311"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row192954190433"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p829681914435"><a name="p829681914435"></a><a name="p829681914435"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p11296131944316"><a name="p11296131944316"></a><a name="p11296131944316"></a>The value <strong id="b336183710499"><a name="b336183710499"></a><a name="b336183710499"></a>true</strong> indicates that the input character is of the RTL language, and value <strong id="b93673764913"><a name="b93673764913"></a><a name="b93673764913"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isrtl = Character.isRTL("a"); // Return false.
    ```


### isIdeograph<sup>8+</sup><a name="section15378192818476"></a>

isIdeograph\(char: string\): boolean

Checks whether the input character string is comprised of ideographic characters.

-   Parameters

    <a name="table9379122818476"></a>
    <table><thead align="left"><tr id="row937952816471"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p13379728104718"><a name="p13379728104718"></a><a name="p13379728104718"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p1837982844719"><a name="p1837982844719"></a><a name="p1837982844719"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p1379028104717"><a name="p1379028104717"></a><a name="p1379028104717"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p537918285478"><a name="p537918285478"></a><a name="p537918285478"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1638015286474"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p1438014285478"><a name="p1438014285478"></a><a name="p1438014285478"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p1638011288479"><a name="p1638011288479"></a><a name="p1638011288479"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p338062814712"><a name="p338062814712"></a><a name="p338062814712"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p1938002834713"><a name="p1938002834713"></a><a name="p1938002834713"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1238042815470"></a>
    <table><thead align="left"><tr id="row13380328134717"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p1638072854718"><a name="p1638072854718"></a><a name="p1638072854718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p538152820479"><a name="p538152820479"></a><a name="p538152820479"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1638142818473"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p133813289478"><a name="p133813289478"></a><a name="p133813289478"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1238110284470"><a name="p1238110284470"></a><a name="p1238110284470"></a>The value <strong id="b16492153345214"><a name="b16492153345214"></a><a name="b16492153345214"></a>true</strong> indicates that the input character is an ideographic character, and value <strong id="b44924338527"><a name="b44924338527"></a><a name="b44924338527"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isideograph = Character.isIdeograph("a"); // Return false.
    ```


### isLetter<sup>8+</sup><a name="section9130836184917"></a>

isLetter\(char: string\): boolean

Checks whether the input character string is comprised of letters.

-   Parameters

    <a name="table10130123619492"></a>
    <table><thead align="left"><tr id="row013153614917"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p18131153612491"><a name="p18131153612491"></a><a name="p18131153612491"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p7131336134917"><a name="p7131336134917"></a><a name="p7131336134917"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p3131236134915"><a name="p3131236134915"></a><a name="p3131236134915"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p513153610499"><a name="p513153610499"></a><a name="p513153610499"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11131133654918"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p813143654911"><a name="p813143654911"></a><a name="p813143654911"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p31311436194916"><a name="p31311436194916"></a><a name="p31311436194916"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p20131103694910"><a name="p20131103694910"></a><a name="p20131103694910"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p18132163620493"><a name="p18132163620493"></a><a name="p18132163620493"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table313253620492"></a>
    <table><thead align="left"><tr id="row17132133694915"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p4132193619496"><a name="p4132193619496"></a><a name="p4132193619496"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p131322036164912"><a name="p131322036164912"></a><a name="p131322036164912"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15132536124910"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p213213368493"><a name="p213213368493"></a><a name="p213213368493"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p813353654910"><a name="p813353654910"></a><a name="p813353654910"></a>The value <strong id="b1364011716543"><a name="b1364011716543"></a><a name="b1364011716543"></a>true</strong> indicates that the input character is a letter, and value <strong id="b1564013745415"><a name="b1564013745415"></a><a name="b1564013745415"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isletter = Character.isLetter("a"); // Return true.
    ```


### isLowerCase<sup>8+</sup><a name="section75441848115112"></a>

isLowerCase\(char: string\): boolean

Checks whether the input character is comprised of lowercase letters.

-   Parameters

    <a name="table11544174819511"></a>
    <table><thead align="left"><tr id="row155451948135119"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p5545104835117"><a name="p5545104835117"></a><a name="p5545104835117"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p5545164855117"><a name="p5545164855117"></a><a name="p5545164855117"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p25458486511"><a name="p25458486511"></a><a name="p25458486511"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p1554554895116"><a name="p1554554895116"></a><a name="p1554554895116"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1054515485511"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p18545144819512"><a name="p18545144819512"></a><a name="p18545144819512"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p05451048105112"><a name="p05451048105112"></a><a name="p05451048105112"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p054514487515"><a name="p054514487515"></a><a name="p054514487515"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p554644817513"><a name="p554644817513"></a><a name="p554644817513"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1354674885115"></a>
    <table><thead align="left"><tr id="row1546148155111"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p9546164810510"><a name="p9546164810510"></a><a name="p9546164810510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p19546184812515"><a name="p19546184812515"></a><a name="p19546184812515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17546448135118"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p155461483515"><a name="p155461483515"></a><a name="p155461483515"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p19546124855120"><a name="p19546124855120"></a><a name="p19546124855120"></a>The value <strong id="b1611413487548"><a name="b1611413487548"></a><a name="b1611413487548"></a>true</strong> indicates that the input character is a lowercase letter, and value <strong id="b411484895417"><a name="b411484895417"></a><a name="b411484895417"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var islowercase = Character.isLowerCase("a"); // Return true.
    ```


### isUpperCase<sup>8+</sup><a name="section175252051125212"></a>

isUpperCase\(char: string\): boolean

Checks whether the input character is comprised of uppercase letters.

-   Parameters

    <a name="table1552555110523"></a>
    <table><thead align="left"><tr id="row14526135145210"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p7526351145213"><a name="p7526351145213"></a><a name="p7526351145213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p3526165119524"><a name="p3526165119524"></a><a name="p3526165119524"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p15526195195210"><a name="p15526195195210"></a><a name="p15526195195210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p25261951155214"><a name="p25261951155214"></a><a name="p25261951155214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row205269518525"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p052675185219"><a name="p052675185219"></a><a name="p052675185219"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p195266516523"><a name="p195266516523"></a><a name="p195266516523"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p5527125135218"><a name="p5527125135218"></a><a name="p5527125135218"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p1552705119525"><a name="p1552705119525"></a><a name="p1552705119525"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table95276511520"></a>
    <table><thead align="left"><tr id="row205271519525"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p75271651105212"><a name="p75271651105212"></a><a name="p75271651105212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p1527165155215"><a name="p1527165155215"></a><a name="p1527165155215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row85271851105216"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p35281051185212"><a name="p35281051185212"></a><a name="p35281051185212"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p1552813513525"><a name="p1552813513525"></a><a name="p1552813513525"></a>The value <strong id="b17483125210558"><a name="b17483125210558"></a><a name="b17483125210558"></a>true</strong> indicates that the input character is an uppercase letter, and value <strong id="b1448915285516"><a name="b1448915285516"></a><a name="b1448915285516"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var isuppercase = Character.isUpperCase("a"); // Return false.
    ```


### getType<sup>8+</sup><a name="section1390854618533"></a>

getType\(char: string\): string

Obtains the type of the input character string.

-   Parameters

    <a name="table18908184685315"></a>
    <table><thead align="left"><tr id="row990810467535"><th class="cellrowborder" valign="top" width="11.119698579847357%" id="mcps1.1.5.1.1"><p id="p18909154665318"><a name="p18909154665318"></a><a name="p18909154665318"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.905999420345864%" id="mcps1.1.5.1.2"><p id="p590914463534"><a name="p590914463534"></a><a name="p590914463534"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.356873732006569%" id="mcps1.1.5.1.3"><p id="p7909146115311"><a name="p7909146115311"></a><a name="p7909146115311"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.61742826780022%" id="mcps1.1.5.1.4"><p id="p14909114618539"><a name="p14909114618539"></a><a name="p14909114618539"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14909114612532"><td class="cellrowborder" valign="top" width="11.119698579847357%" headers="mcps1.1.5.1.1 "><p id="p8909104685312"><a name="p8909104685312"></a><a name="p8909104685312"></a>char</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.905999420345864%" headers="mcps1.1.5.1.2 "><p id="p0909114635312"><a name="p0909114635312"></a><a name="p0909114635312"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.356873732006569%" headers="mcps1.1.5.1.3 "><p id="p1890911461533"><a name="p1890911461533"></a><a name="p1890911461533"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.61742826780022%" headers="mcps1.1.5.1.4 "><p id="p1890910468535"><a name="p1890910468535"></a><a name="p1890910468535"></a>Input character.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table4910146195313"></a>
    <table><thead align="left"><tr id="row20910194635320"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.3.1.1"><p id="p13910204645311"><a name="p13910204645311"></a><a name="p13910204645311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.95%" id="mcps1.1.3.1.2"><p id="p991014465534"><a name="p991014465534"></a><a name="p991014465534"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99101046155318"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.3.1.1 "><p id="p1091024614533"><a name="p1091024614533"></a><a name="p1091024614533"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.95%" headers="mcps1.1.3.1.2 "><p id="p12910104619531"><a name="p12910104619531"></a><a name="p12910104619531"></a>Type of the input character.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var type = Character.getType("a");
    ```


## i18n.getLineInstance<sup>8+</sup><a name="section8120192671613"></a>

getLineInstance\(locale: string\): BreakIterator

Obtains a  [BreakIterator](#section1312302611613)  object for text segmentation.

-   Parameters

    <a name="table612111269169"></a>
    <table><thead align="left"><tr id="row1912111269163"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p312115260160"><a name="p312115260160"></a><a name="p312115260160"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p1712102641613"><a name="p1712102641613"></a><a name="p1712102641613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p6121182651610"><a name="p6121182651610"></a><a name="p6121182651610"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p2121142612162"><a name="p2121142612162"></a><a name="p2121142612162"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9122172631618"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p1912262614167"><a name="p1912262614167"></a><a name="p1912262614167"></a>locale</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p18122192651620"><a name="p18122192651620"></a><a name="p18122192651620"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p612272611169"><a name="p612272611169"></a><a name="p612272611169"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p16122192612166"><a name="p16122192612166"></a><a name="p16122192612166"></a>Valid locale value, for example, <strong id="b1619069580"><a name="b1619069580"></a><a name="b1619069580"></a>zh-Hans-CN</strong>. The <a href="#section1312302611613">BreakIterator</a> object segments text according to the rules of the specified locale.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table16122132610166"></a>
    <table><thead align="left"><tr id="row17122152671613"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p81223269169"><a name="p81223269169"></a><a name="p81223269169"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p712282612164"><a name="p712282612164"></a><a name="p712282612164"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row212332614167"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p3123626201611"><a name="p3123626201611"></a><a name="p3123626201611"></a><a href="#section1312302611613">BreakIterator</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p41231726101615"><a name="p41231726101615"></a><a name="p41231726101615"></a>Break iterator used for text segmentation.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    i18n.getLineInstance("en");
    ```


## BreakIterator<sup>8+</sup><a name="section1312302611613"></a>

### setLineBreakText<sup>8+</sup><a name="section14135918111319"></a>

setLineBreakText\(text: string\): void

Sets the text to be processed by the  [BreakIterator](#section1312302611613)  object.

-   Parameters

    <a name="table975084719224"></a>
    <table><thead align="left"><tr id="row1275024792220"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p875074702214"><a name="p875074702214"></a><a name="p875074702214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p157501747182218"><a name="p157501747182218"></a><a name="p157501747182218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p11750204713227"><a name="p11750204713227"></a><a name="p11750204713227"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p675120477220"><a name="p675120477220"></a><a name="p675120477220"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row187511847112216"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p6751104742216"><a name="p6751104742216"></a><a name="p6751104742216"></a>text</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p375116474227"><a name="p375116474227"></a><a name="p375116474227"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p27511476228"><a name="p27511476228"></a><a name="p27511476228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p10751194713229"><a name="p10751194713229"></a><a name="p10751194713229"></a>Text to be processed by the <a href="#section1312302611613">BreakIterator</a> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    ```


### getLineBreakText<sup>8+</sup><a name="section1671125315251"></a>

getLineBreakText\(\): string

Obtains the text being processed by the  [BreakIterator](#section1312302611613)  object.

-   Return values

    <a name="table1961174210267"></a>
    <table><thead align="left"><tr id="row1611742122611"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p461217424264"><a name="p461217424264"></a><a name="p461217424264"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p96121342102616"><a name="p96121342102616"></a><a name="p96121342102616"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7612164218269"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1061218424266"><a name="p1061218424266"></a><a name="p1061218424266"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p5612842162613"><a name="p5612842162613"></a><a name="p5612842162613"></a>Text being processed by the <a href="#section1312302611613">BreakIterator</a> object.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.getLineBreakText(); // Apple is my favorite fruit.
    ```


### current<sup>8+</sup><a name="section7123172618164"></a>

current\(\): number

Obtains the position of the  [BreakIterator](#section1312302611613)  object in the text being processed.

-   Return values

    <a name="table1784864163519"></a>
    <table><thead align="left"><tr id="row4849204123517"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p484904103518"><a name="p484904103518"></a><a name="p484904103518"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p684984153516"><a name="p684984153516"></a><a name="p684984153516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7849104114350"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p178491441153520"><a name="p178491441153520"></a><a name="p178491441153520"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p184954143512"><a name="p184954143512"></a><a name="p184954143512"></a>Position of the <a href="#section1312302611613">BreakIterator</a> object in the text being processed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    breakIter.current(); // 0
    ```


### first<sup>8+</sup><a name="section1456982120391"></a>

first\(\): number

Puts the  [BreakIterator](#section1312302611613)  object to the first text boundary, which is always at the beginning of the processed text.

-   Return values

    <a name="table4569162114397"></a>
    <table><thead align="left"><tr id="row2569202143920"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p1569172120392"><a name="p1569172120392"></a><a name="p1569172120392"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p1357072119393"><a name="p1357072119393"></a><a name="p1357072119393"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row257018219397"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1957072113918"><a name="p1957072113918"></a><a name="p1957072113918"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p5570132112394"><a name="p5570132112394"></a><a name="p5570132112394"></a>Offset to the first text boundary of the processed text.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    breakIter.first(); // 0
    ```


### last<sup>8+</sup><a name="section5296105618422"></a>

last\(\): number

Puts the  [BreakIterator](#section1312302611613)  object to the last text boundary, which is always the next position after the end of the processed text.

-   Return values

    <a name="table1029725654211"></a>
    <table><thead align="left"><tr id="row1429713561420"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p529745614212"><a name="p529745614212"></a><a name="p529745614212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p142971656164214"><a name="p142971656164214"></a><a name="p142971656164214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row729717564429"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p52977566423"><a name="p52977566423"></a><a name="p52977566423"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p142981556104212"><a name="p142981556104212"></a><a name="p142981556104212"></a>Offset of the last text boundary of the processed text.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.last(); // 27
    ```


### next<sup>8+</sup><a name="section121321618141318"></a>

next\(index?: number\): number

Moves the  [BreakIterator](#section1312302611613)  object backward by the specified number of text boundaries if the specified index is a positive number. If the index is a negative number, the  [BreakIterator](#section1312302611613)  object will be moved forward by the corresponding number of text boundaries. If no index is specified, the index will be treated as  **1**.

-   Parameters

    <a name="table1269107161611"></a>
    <table><thead align="left"><tr id="row117016713169"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p87013771612"><a name="p87013771612"></a><a name="p87013771612"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p14700710164"><a name="p14700710164"></a><a name="p14700710164"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p570187151617"><a name="p570187151617"></a><a name="p570187151617"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p18703751612"><a name="p18703751612"></a><a name="p18703751612"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10701670162"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p137087111612"><a name="p137087111612"></a><a name="p137087111612"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p157015791613"><a name="p157015791613"></a><a name="p157015791613"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p14705712167"><a name="p14705712167"></a><a name="p14705712167"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p157113716161"><a name="p157113716161"></a><a name="p157113716161"></a>Number of text boundaries by which the <a href="#section1312302611613">BreakIterator</a> object is moved. A positive value indicates that the text boundary is moved backward, and a negative value indicates the opposite. If no index is specified, the index will be treated as <strong id="b195933232918"><a name="b195933232918"></a><a name="b195933232918"></a>1</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table4132111812136"></a>
    <table><thead align="left"><tr id="row1613271811319"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p1713371815135"><a name="p1713371815135"></a><a name="p1713371815135"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p12133318161320"><a name="p12133318161320"></a><a name="p12133318161320"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1913314184133"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1613310185131"><a name="p1613310185131"></a><a name="p1613310185131"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p13133111851319"><a name="p13133111851319"></a><a name="p13133111851319"></a>Position of the <a href="#section1312302611613">BreakIterator</a> object in the text after it is moved by the specified number of text boundaries. The value <strong id="b4493281401"><a name="b4493281401"></a><a name="b4493281401"></a>-1</strong> is returned if the position of the <a href="#section1312302611613">BreakIterator</a> object is outside of the processed text after it is moved by the specified number of text boundaries.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.first(); // 0
    iterator.next(); // 6
    iterator.next(10); // -1
    ```


### previous<sup>8+</sup><a name="section61331018121314"></a>

previous\(\): number

Moves the  [BreakIterator](#section1312302611613)  object to the previous text boundary.

-   Return values

    <a name="table71342183138"></a>
    <table><thead align="left"><tr id="row6134918201320"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p113461861318"><a name="p113461861318"></a><a name="p113461861318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p15134201818139"><a name="p15134201818139"></a><a name="p15134201818139"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row41341218181315"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p19135918121317"><a name="p19135918121317"></a><a name="p19135918121317"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p313510183133"><a name="p313510183133"></a><a name="p313510183133"></a>Position of the <a href="#section1312302611613">BreakIterator</a> object in the text after it is moved to the previous text boundary. The value <strong id="b152571690117"><a name="b152571690117"></a><a name="b152571690117"></a>-1</strong> is returned if the position of the <a href="#section1312302611613">BreakIterator</a> object is outside of the processed text after it is moved by the specified number of text boundaries.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.first(); // 0
    iterator.next(3); // 12
    iterator.previous(); // 9
    ```


### following<sup>8+</sup><a name="section1743155314301"></a>

following\(offset: number\): number

Moves the  [BreakIterator](#section1312302611613)  object to the text boundary after the position specified by the offset. 

-   Parameters

    <a name="table18744453173010"></a>
    <table><thead align="left"><tr id="row10744125373013"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p117441453113020"><a name="p117441453113020"></a><a name="p117441453113020"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p77441853133020"><a name="p77441853133020"></a><a name="p77441853133020"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p18745153183012"><a name="p18745153183012"></a><a name="p18745153183012"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p19745145318303"><a name="p19745145318303"></a><a name="p19745145318303"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row197451753113015"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p674595333013"><a name="p674595333013"></a><a name="p674595333013"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p1974510534304"><a name="p1974510534304"></a><a name="p1974510534304"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p107459535303"><a name="p107459535303"></a><a name="p107459535303"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p1274585312307"><a name="p1274585312307"></a><a name="p1274585312307"></a>Offset to the position before the text boundary to which the <a href="#section1312302611613">BreakIterator</a> object is moved.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table4746853183018"></a>
    <table><thead align="left"><tr id="row7746135323019"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p774605393016"><a name="p774605393016"></a><a name="p774605393016"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p137461853163019"><a name="p137461853163019"></a><a name="p137461853163019"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9746653143017"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p174675316301"><a name="p174675316301"></a><a name="p174675316301"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p1374625317301"><a name="p1374625317301"></a><a name="p1374625317301"></a>The value <strong id="b1066631131915"><a name="b1066631131915"></a><a name="b1066631131915"></a>-1</strong> is returned if the text boundary to which the <a href="#section1312302611613">BreakIterator</a> object is moved is outside of the processed text.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.following(0); // 6
    iterator.following(100); // -1
    iterator.current(); // 27
    ```


### isBoundary<sup>8+</sup><a name="section1908145612303"></a>

isBoundary\(offset: number\): boolean

Checks whether the position specified by the offset is a text boundary. If  **true**  is returned, the  [BreakIterator](#section1312302611613)  object is moved to the position specified by the offset. If  **false**  is returned, the  [BreakIterator](#section1312302611613)  object is moved to the text boundary after the position specified by the offset, which is equivalent to calling  [following\(offset\)](#section1743155314301).

-   Parameters

    <a name="table4909956103010"></a>
    <table><thead align="left"><tr id="row19909155673019"><th class="cellrowborder" valign="top" width="14.918508149185081%" id="mcps1.1.5.1.1"><p id="p17909155613016"><a name="p17909155613016"></a><a name="p17909155613016"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.498850114988501%" id="mcps1.1.5.1.2"><p id="p1190919562303"><a name="p1190919562303"></a><a name="p1190919562303"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p11909195673012"><a name="p11909195673012"></a><a name="p11909195673012"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.06339366063393%" id="mcps1.1.5.1.4"><p id="p2909115633012"><a name="p2909115633012"></a><a name="p2909115633012"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12909195617305"><td class="cellrowborder" valign="top" width="14.918508149185081%" headers="mcps1.1.5.1.1 "><p id="p139091856193015"><a name="p139091856193015"></a><a name="p139091856193015"></a>offset</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.498850114988501%" headers="mcps1.1.5.1.2 "><p id="p1991016565305"><a name="p1991016565305"></a><a name="p1991016565305"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p9910195619306"><a name="p9910195619306"></a><a name="p9910195619306"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.06339366063393%" headers="mcps1.1.5.1.4 "><p id="p1491005643015"><a name="p1491005643015"></a><a name="p1491005643015"></a>Position to check.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Return values

    <a name="table169103564306"></a>
    <table><thead align="left"><tr id="row1910756133018"><th class="cellrowborder" valign="top" width="22.759999999999998%" id="mcps1.1.3.1.1"><p id="p691015615307"><a name="p691015615307"></a><a name="p691015615307"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.24%" id="mcps1.1.3.1.2"><p id="p991135673015"><a name="p991135673015"></a><a name="p991135673015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row109111456103010"><td class="cellrowborder" valign="top" width="22.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p1091175683014"><a name="p1091175683014"></a><a name="p1091175683014"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.24%" headers="mcps1.1.3.1.2 "><p id="p291165623012"><a name="p291165623012"></a><a name="p291165623012"></a>The value <strong id="b910010472195"><a name="b910010472195"></a><a name="b910010472195"></a>true</strong> indicates that the position specified by the offset is a text boundary, and value <strong id="b4301203582014"><a name="b4301203582014"></a><a name="b4301203582014"></a>false</strong> indicates the opposite.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    iterator = I18n.getLineInstance("en");
    iterator.setLineBreakText("Apple is my favorite fruit.");
    iterator.isBoundary(0); // true;
    iterator.isBoundary(5); // false;
    ```

