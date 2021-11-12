# Console Logs<a name="EN-US_TOPIC_0000001115814846"></a>

-   [Module to Import](#en-us_topic_0000001058460515_s56d19203690d4782bfc74069abb6bd71)
-   [Permission List](#en-us_topic_0000001058460515_section11257113618419)
-   [Log Category](#en-us_topic_0000001058460515_s298a3cf59a3b470dbb0742706102ced7)

## Module to Import<a name="en-us_topic_0000001058460515_s56d19203690d4782bfc74069abb6bd71"></a>

No module is required.

## Permission List<a name="en-us_topic_0000001058460515_section11257113618419"></a>

None

## Log Category<a name="en-us_topic_0000001058460515_s298a3cf59a3b470dbb0742706102ced7"></a>

Prints a log using  **console.debug|log|info|warn|error\(message\)**.

-   Parameter

    <a name="en-us_topic_0000001058460515_t87748b0ba4e648079d53f9deccf4bfb2"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058460515_rc5033ad045c14c2e806d59041aab002c"><th class="cellrowborder" valign="top" width="12%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058460515_acf783ab6043e4ee1a7bb73b73a091e0b"><a name="en-us_topic_0000001058460515_acf783ab6043e4ee1a7bb73b73a091e0b"></a><a name="en-us_topic_0000001058460515_acf783ab6043e4ee1a7bb73b73a091e0b"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058460515_a6736505551534b819d5a6376065a25f6"><a name="en-us_topic_0000001058460515_a6736505551534b819d5a6376065a25f6"></a><a name="en-us_topic_0000001058460515_a6736505551534b819d5a6376065a25f6"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058460515_ac15c2a3de0e046af917cf09b48b3b46d"><a name="en-us_topic_0000001058460515_ac15c2a3de0e046af917cf09b48b3b46d"></a><a name="en-us_topic_0000001058460515_ac15c2a3de0e046af917cf09b48b3b46d"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058460515_aeb94b88e78974288bab1b4940b50c840"><a name="en-us_topic_0000001058460515_aeb94b88e78974288bab1b4940b50c840"></a><a name="en-us_topic_0000001058460515_aeb94b88e78974288bab1b4940b50c840"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058460515_r95c56d5cd62d4b518c3e7a3f158ed7fe"><td class="cellrowborder" valign="top" width="12%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058460515_a7af41aec9a404f418202d90c61774825"><a name="en-us_topic_0000001058460515_a7af41aec9a404f418202d90c61774825"></a><a name="en-us_topic_0000001058460515_a7af41aec9a404f418202d90c61774825"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058460515_aed6ae868d61349afa8f0e250108f8e47"><a name="en-us_topic_0000001058460515_aed6ae868d61349afa8f0e250108f8e47"></a><a name="en-us_topic_0000001058460515_aed6ae868d61349afa8f0e250108f8e47"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058460515_ab72ac8cc02e34da4b717ca144fc521c1"><a name="en-us_topic_0000001058460515_ab72ac8cc02e34da4b717ca144fc521c1"></a><a name="en-us_topic_0000001058460515_ab72ac8cc02e34da4b717ca144fc521c1"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058460515_ac53e6549d32f413e9c51cd8a53f4650a"><a name="en-us_topic_0000001058460515_ac53e6549d32f413e9c51cd8a53f4650a"></a><a name="en-us_topic_0000001058460515_ac53e6549d32f413e9c51cd8a53f4650a"></a>Text to print</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var versionCode = 1;
    console.info('Hello World. The current version code is ' + versionCode);
    ```

    Switch to the  **HiLog**  window at the bottom of HUAWEI DevEco Studio. Specifically, select the current device and process, set the log level to  **Info**, and enter  **Hello World**  in the search box. Logs that meet the search criteria are displayed, as shown in the following figure.

    ![](figures/打印日志.png)

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The  **console.log\(\)**  function prints logs at the debug level.


