# Application Configuration<a name="EN-US_TOPIC_0000001173324675"></a>

## Module to Import<a name="section15536249155915"></a>

```
import configuration from '@system.configuration';
```

## Required Permissions<a name="section8152081004"></a>

None

## configuration.getLocale<a name="section8389829903"></a>

getLocale\(\): <[LocaleResponse](#table1544853546)\>

Obtains the current locale of the application, which is the same as the system locale.

-   Return values

    **Table  1**  LocaleResponse

    <a name="table1544853546"></a>
    <table><thead align="left"><tr id="row1670755549"><th class="cellrowborder" valign="top" width="17.77177717771777%" id="mcps1.2.4.1.1"><p id="p57013505413"><a name="p57013505413"></a><a name="p57013505413"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.5012501250125%" id="mcps1.2.4.1.2"><p id="p9706511540"><a name="p9706511540"></a><a name="p9706511540"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.72697269726973%" id="mcps1.2.4.1.3"><p id="p16701957548"><a name="p16701957548"></a><a name="p16701957548"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15709513545"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p1370154548"><a name="p1370154548"></a><a name="p1370154548"></a>language</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="p19701653545"><a name="p19701653545"></a><a name="p19701653545"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="p37010510548"><a name="p37010510548"></a><a name="p37010510548"></a>Current language of the application, for example, <strong id="b1260120418488"><a name="b1260120418488"></a><a name="b1260120418488"></a>zh</strong>.</p>
    </td>
    </tr>
    <tr id="row970165135413"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p97055105414"><a name="p97055105414"></a><a name="p97055105414"></a>countryOrRegion</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="p1770175115413"><a name="p1770175115413"></a><a name="p1770175115413"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="p77015518544"><a name="p77015518544"></a><a name="p77015518544"></a>Country or region, for example, <strong id="b6258316114819"><a name="b6258316114819"></a><a name="b6258316114819"></a>CN</strong>.</p>
    </td>
    </tr>
    <tr id="row6332114185611"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p53321542567"><a name="p53321542567"></a><a name="p53321542567"></a>dir</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="p1433216410564"><a name="p1433216410564"></a><a name="p1433216410564"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="p33321417565"><a name="p33321417565"></a><a name="p33321417565"></a>Text layout direction. Available values are as follows:</p>
    <a name="ul1861816241119"></a><a name="ul1861816241119"></a><ul id="ul1861816241119"><li><strong id="b16720155216481"><a name="b16720155216481"></a><a name="b16720155216481"></a>ltr</strong>: The text direction is from left to right.</li><li><strong id="b1910563194919"><a name="b1910563194919"></a><a name="b1910563194919"></a>rtl</strong>: The text direction is from right to left.</li></ul>
    </td>
    </tr>
    <tr id="row165137101137"><td class="cellrowborder" valign="top" width="17.77177717771777%" headers="mcps1.2.4.1.1 "><p id="p1351311101333"><a name="p1351311101333"></a><a name="p1351311101333"></a>unicodeSetting<sup id="sup1646171814502"><a name="sup1646171814502"></a><a name="sup1646171814502"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.5012501250125%" headers="mcps1.2.4.1.2 "><p id="p1513121019313"><a name="p1513121019313"></a><a name="p1513121019313"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.72697269726973%" headers="mcps1.2.4.1.3 "><p id="p97106183311"><a name="p97106183311"></a><a name="p97106183311"></a>Unicode key set determined by the locale.</p>
    <p id="p213145115319"><a name="p213145115319"></a><a name="p213145115319"></a>For example, <strong id="b14471162633518"><a name="b14471162633518"></a><a name="b14471162633518"></a>{"nu":"arab"}</strong> indicates that the current locale uses Arabic numerals.</p>
    <p id="p849701364"><a name="p849701364"></a><a name="p849701364"></a>If the current locale does not have a specific key set, an empty set is returned.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {    
      getLocale() {        
        const localeInfo = configuration.getLocale();        
        console.info(localeInfo.language);    
      }
    }
    ```


