# hdc\_std Usage Guidelines<a name="EN-US_TOPIC_0000001080478129"></a>

-   [Preparations](#section05992022154916)
-   [Important Notes](#section19543134915210)
-   [Option-related Commands](#section618522925119)
    -   [-h/help -v/version](#section51533527212)
    -   [-t key](#section1180555115159)

-   [Querying the Device List](#section174891132104218)
    -   [list targets\[-v\]](#section12911142313168)

-   [Service Process Commands](#section680531510497)
    -   [target mount](#section396717571168)
    -   [smode \[off\]](#section179951621713)
    -   [kill \[-r\]](#section419144621712)
    -   [start \[-r\]](#section184811812183)

-   [Network Commands](#section71176123212)
    -   [tconn host\[:port\]\[-remove\]](#section191911334206)
    -   [tmode usb](#section17840182562015)
    -   [tmode port port-number](#section101113462113)

-   [File Commands](#section173133523013)
    -   [file send local remote](#section126223231307)
    -   [file recv \[-a\] remote local](#section26966541304)

-   [App Commands](#section2072647133819)
    -   [install \[-r/-d/-g\] package](#section49615195111)
    -   [uninstall \[-k\] package](#section167618461814)

-   [Debugging Commands](#section112861250195015)
    -   [hilog](#section32171612221)
    -   [shell \[command\]](#section524235625)

-   [Troubleshooting](#section592920255582)
    -   [hdc\_std Fails to Connect to a Device](#section74019384588)

-   [hdc\_std Fails to Run](#section6825095917)

hdc\_std \(OpenHarmony Device Connector\) is a command line tool provided by OpenHarmony for debugging. With this tool, you can interact with real devices or simulators from a Windows or Linux OS.

This section describes how to set up the hdc\_std environment and use its common commands.

## Preparations<a name="section05992022154916"></a>

**Obtaining hdc\_std:**

Obtain **hdc\_std** from the **prebuilt** directory at [developtools\_hdc\_standard](https://gitee.com/openharmony/developtools_hdc_standard).

**Example:**

To obtain hdc\_std on Windows, obtain the executable file  **hdc\_std.exe**  from  **prebuilt/windows**  and place it in a directory on the disk.

## Important Notes<a name="section19543134915210"></a>

-   If an exception occurs when you are using hdc\_std, run the  **hdc\_std kill**  command to kill the hdc\_std service or run the  **hdc\_std start -r**  command to restart the service process.
-   If no device information is obtained after  **hdc\_std list targets**  is executed, use the task manager to check whether the  **hdc.exe**  process exists. If it exists, kill the process.

## Option-related Commands<a name="section618522925119"></a>

The following commands are available:

### -h/help -v/version<a name="section51533527212"></a>

Obtains hdc help and version information.

**Table  1**  Command description

<a name="table2560141891610"></a>
<table><tbody><tr id="row11561818151618"><td class="cellrowborder" valign="top" width="50%"><p id="p1656118183162"><a name="p1656118183162"></a><a name="p1656118183162"></a><strong id="b1041812818435"><a name="b1041812818435"></a><a name="b1041812818435"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p55613181166"><a name="p55613181166"></a><a name="p55613181166"></a><strong id="b14295163017435"><a name="b14295163017435"></a><a name="b14295163017435"></a>Description</strong></p>
</td>
</tr>
<tr id="row19561618141617"><td class="cellrowborder" valign="top" width="50%"><p id="p15615185161"><a name="p15615185161"></a><a name="p15615185161"></a>Required information</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p135611718111618"><a name="p135611718111618"></a><a name="p135611718111618"></a>hdc help or version information</p>
</td>
</tr>
</tbody>
</table>

Examples:

hdc\_std -h / hdc\_std  help

hdc\_std -v / hdc\_std  version

### -t key<a name="section1180555115159"></a>

Connects to a device with a specified key.

**Table  2**  Command description

<a name="table16605101217544"></a>
<table><tbody><tr id="row14605141255412"><td class="cellrowborder" valign="top" width="50%"><p id="p14605121212541"><a name="p14605121212541"></a><a name="p14605121212541"></a><strong id="b1693351765919"><a name="b1693351765919"></a><a name="b1693351765919"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18605111285411"><a name="p18605111285411"></a><a name="p18605111285411"></a><strong id="b3538122335916"><a name="b3538122335916"></a><a name="b3538122335916"></a>Description</strong></p>
</td>
</tr>
<tr id="row260514129547"><td class="cellrowborder" valign="top" width="50%"><p id="p1060512126548"><a name="p1060512126548"></a><a name="p1060512126548"></a><span>key</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p26051123547"><a name="p26051123547"></a><a name="p26051123547"></a>Key that identifies the device. The value is in the <em id="i15978153415214"><a name="i15978153415214"></a><a name="i15978153415214"></a>IP address:Port number</em> format or is a USB serial number.</p>
</td>
</tr>
<tr id="row46051121548"><td class="cellrowborder" valign="top" width="50%"><p id="p11605111285411"><a name="p11605111285411"></a><a name="p11605111285411"></a><strong id="b4943122111415"><a name="b4943122111415"></a><a name="b4943122111415"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18605101265413"><a name="p18605101265413"></a><a name="p18605101265413"></a><strong id="b828172265915"><a name="b828172265915"></a><a name="b828172265915"></a>Description</strong></p>
</td>
</tr>
<tr id="row1760531211546"><td class="cellrowborder" valign="top" width="50%"><p id="p232481834"><a name="p232481834"></a><a name="p232481834"></a>1. error: device '***' not found</p>
<p id="p12191171320"><a name="p12191171320"></a><a name="p12191171320"></a>②Nothing to do...</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p85527328314"><a name="p85527328314"></a><a name="p85527328314"></a>1. The device does not exist.</p>
<p id="p10343124416277"><a name="p10343124416277"></a><a name="p10343124416277"></a>2. The command appended to <strong id="b18734194624117"><a name="b18734194624117"></a><a name="b18734194624117"></a>-t key</strong> does not exist.</p>
</td>
</tr>
</tbody>
</table>

Examples:

This option must be used together with a specific operation command. The following uses the shell command as an example:

**hdc\_std list targets**  \(obtain device information\)

**hdc\_std  -t   _key_   shell**  \(replace  _key_  with the device information obtained\)

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>You can connect to multiple devices from the device you use for development. Each device has a unique key. The key can be  _IP address:Port number_  for a device connected through a network or the serial number for a device connected through USB.

## Querying the Device List<a name="section174891132104218"></a>

The following command is used to query the device list:

### list targets\[-v\]<a name="section12911142313168"></a>

Displays all the connected devices.

**Table  3**  Command description

<a name="table1233315596432"></a>
<table><tbody><tr id="row1033313596434"><td class="cellrowborder" valign="top" width="50%"><p id="p13333115919432"><a name="p13333115919432"></a><a name="p13333115919432"></a><strong id="b629174175516"><a name="b629174175516"></a><a name="b629174175516"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p033320595430"><a name="p033320595430"></a><a name="p033320595430"></a><strong id="b1654018421552"><a name="b1654018421552"></a><a name="b1654018421552"></a>Description</strong></p>
</td>
</tr>
<tr id="row733310596437"><td class="cellrowborder" valign="top" width="50%"><p id="p13333115911433"><a name="p13333115911433"></a><a name="p13333115911433"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p123331159134314"><a name="p123331159134314"></a><a name="p123331159134314"></a>Prints detailed device information.</p>
</td>
</tr>
<tr id="row1833305944314"><td class="cellrowborder" valign="top" width="50%"><p id="p833445916438"><a name="p833445916438"></a><a name="p833445916438"></a><strong id="b143101411185710"><a name="b143101411185710"></a><a name="b143101411185710"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p23341159134320"><a name="p23341159134320"></a><a name="p23341159134320"></a><strong id="b102594345918"><a name="b102594345918"></a><a name="b102594345918"></a>Description</strong></p>
</td>
</tr>
<tr id="row03341859154311"><td class="cellrowborder" valign="top" width="50%"><p id="p13334659154310"><a name="p13334659154310"></a><a name="p13334659154310"></a>1. Device information</p>
<p id="p19553114217533"><a name="p19553114217533"></a><a name="p19553114217533"></a>②[Empty]</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p6334859174310"><a name="p6334859174310"></a><a name="p6334859174310"></a>1. A list of connected devices</p>
<p id="p57581926125318"><a name="p57581926125318"></a><a name="p57581926125318"></a>2. No device information is found.</p>
</td>
</tr>
</tbody>
</table>

Examples:

hdc\_std list targets

hdc\_std list targets -v

## Service Process Commands<a name="section680531510497"></a>

The following commands are available:

### target mount<a name="section396717571168"></a>

Mounts a partition, such as  **/system**, with the read and write permissions.

**Table  4**  Command description

<a name="table5346719144119"></a>
<table><tbody><tr id="row9346419124120"><td class="cellrowborder" valign="top" width="50%"><p id="p134612191413"><a name="p134612191413"></a><a name="p134612191413"></a><strong id="b1610754091316"><a name="b1610754091316"></a><a name="b1610754091316"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p12346141944113"><a name="p12346141944113"></a><a name="p12346141944113"></a><strong id="b1176325714137"><a name="b1176325714137"></a><a name="b1176325714137"></a>Description</strong></p>
</td>
</tr>
<tr id="row1534681974114"><td class="cellrowborder" valign="top" width="50%"><p id="p16346131914118"><a name="p16346131914118"></a><a name="p16346131914118"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18346191954119"><a name="p18346191954119"></a><a name="p18346191954119"></a>None</p>
</td>
</tr>
<tr id="row18346131964114"><td class="cellrowborder" valign="top" width="50%"><p id="p1934671934110"><a name="p1934671934110"></a><a name="p1934671934110"></a><strong id="b84275081410"><a name="b84275081410"></a><a name="b84275081410"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18346101911411"><a name="p18346101911411"></a><a name="p18346101911411"></a><strong id="b199052032147"><a name="b199052032147"></a><a name="b199052032147"></a>Description</strong></p>
</td>
</tr>
<tr id="row19346919164116"><td class="cellrowborder" valign="top" width="50%"><p id="p44221428143012"><a name="p44221428143012"></a><a name="p44221428143012"></a>①Mount finish</p>
<p id="p43471519204114"><a name="p43471519204114"></a><a name="p43471519204114"></a>2. Returned information</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1551336123011"><a name="p1551336123011"></a><a name="p1551336123011"></a>1. Information returned when the operation is successful.</p>
<p id="p2034731984115"><a name="p2034731984115"></a><a name="p2034731984115"></a>2. Information returned when the operation fails.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std target mount

### smode \[off\]<a name="section179951621713"></a>

Grants the root permission to a background service process. The  **off**  option is used to revoke the granted permission.

Examples:

hdc\_std smode

hdc\_std smode off

### kill \[-r\]<a name="section419144621712"></a>

Stops a service process.

**Table  5**  Command description

<a name="table540423782919"></a>
<table><tbody><tr id="row8404937152910"><td class="cellrowborder" valign="top" width="50%"><p id="p7404113711295"><a name="p7404113711295"></a><a name="p7404113711295"></a><strong id="b2110200670"><a name="b2110200670"></a><a name="b2110200670"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p4405193792919"><a name="p4405193792919"></a><a name="p4405193792919"></a><strong id="b14394223434"><a name="b14394223434"></a><a name="b14394223434"></a>Description</strong></p>
</td>
</tr>
<tr id="row174051037112912"><td class="cellrowborder" valign="top" width="50%"><p id="p134056375291"><a name="p134056375291"></a><a name="p134056375291"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18405337142911"><a name="p18405337142911"></a><a name="p18405337142911"></a>Triggers the service restart.</p>
</td>
</tr>
<tr id="row164052037162913"><td class="cellrowborder" valign="top" width="50%"><p id="p124051837182918"><a name="p124051837182918"></a><a name="p124051837182918"></a><strong id="b486075369"><a name="b486075369"></a><a name="b486075369"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p8405113782918"><a name="p8405113782918"></a><a name="p8405113782918"></a><strong id="b1831332274"><a name="b1831332274"></a><a name="b1831332274"></a>Description</strong></p>
</td>
</tr>
<tr id="row15405163702915"><td class="cellrowborder" valign="top" width="50%"><p id="p0976152811311"><a name="p0976152811311"></a><a name="p0976152811311"></a>①Kill server finish</p>
<p id="p2405163713299"><a name="p2405163713299"></a><a name="p2405163713299"></a>2. Error information</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10405123732915"><a name="p10405123732915"></a><a name="p10405123732915"></a>1. Information returned when the operation is successful.</p>
<p id="p19405337152916"><a name="p19405337152916"></a><a name="p19405337152916"></a>2. The operation fails.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std kill

### start \[-r\]<a name="section184811812183"></a>

Starts a service process.

**Table  6**  Command description

<a name="table11605125417348"></a>
<table><tbody><tr id="row176051354123419"><td class="cellrowborder" valign="top" width="50%"><p id="p16605185413418"><a name="p16605185413418"></a><a name="p16605185413418"></a><strong id="b210257599"><a name="b210257599"></a><a name="b210257599"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p3605125413346"><a name="p3605125413346"></a><a name="p3605125413346"></a><strong id="b415620225414"><a name="b415620225414"></a><a name="b415620225414"></a>Description</strong></p>
</td>
</tr>
<tr id="row1560575443411"><td class="cellrowborder" valign="top" width="50%"><p id="p17605135411347"><a name="p17605135411347"></a><a name="p17605135411347"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1860525413414"><a name="p1860525413414"></a><a name="p1860525413414"></a>Restarts the service process if it has started.</p>
</td>
</tr>
<tr id="row14606154183415"><td class="cellrowborder" valign="top" width="50%"><p id="p160695453412"><a name="p160695453412"></a><a name="p160695453412"></a><strong id="b1555473538"><a name="b1555473538"></a><a name="b1555473538"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1606154163419"><a name="p1606154163419"></a><a name="p1606154163419"></a><strong id="b773206990"><a name="b773206990"></a><a name="b773206990"></a>Description</strong></p>
</td>
</tr>
<tr id="row7606135433416"><td class="cellrowborder" valign="top" width="50%"><p id="p716462216389"><a name="p716462216389"></a><a name="p716462216389"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p360645453415"><a name="p360645453415"></a><a name="p360645453415"></a>None</p>
</td>
</tr>
</tbody>
</table>

Examples:

hdc\_std start

## Network Commands<a name="section71176123212"></a>

The following commands are available:

### tconn  _host_\[:_port_\]\[-remove\]<a name="section191911334206"></a>

Connects to a device with a specified IP address and port number.

**Table  7**  Command description

<a name="table71285383412"></a>
<table><tbody><tr id="row6128123818419"><td class="cellrowborder" valign="top" width="50%"><p id="p812814386413"><a name="p812814386413"></a><a name="p812814386413"></a><strong id="b1030315493346"><a name="b1030315493346"></a><a name="b1030315493346"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p131291038641"><a name="p131291038641"></a><a name="p131291038641"></a><strong id="b3236125017346"><a name="b3236125017346"></a><a name="b3236125017346"></a>Description</strong></p>
</td>
</tr>
<tr id="row101292381149"><td class="cellrowborder" valign="top" width="50%"><p id="p712914385410"><a name="p712914385410"></a><a name="p712914385410"></a>host[:port]</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p14129038443"><a name="p14129038443"></a><a name="p14129038443"></a>IP address and port number of the device to be connected</p>
</td>
</tr>
<tr id="row18468719662"><td class="cellrowborder" valign="top" width="50%"><p id="p8469141919614"><a name="p8469141919614"></a><a name="p8469141919614"></a>-remove</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p24693194612"><a name="p24693194612"></a><a name="p24693194612"></a>Disconnects from the specified device.</p>
</td>
</tr>
<tr id="row12129133811418"><td class="cellrowborder" valign="top" width="50%"><p id="p121301738546"><a name="p121301738546"></a><a name="p121301738546"></a><strong id="b196328104518"><a name="b196328104518"></a><a name="b196328104518"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p413019381140"><a name="p413019381140"></a><a name="p413019381140"></a><strong id="b945423234519"><a name="b945423234519"></a><a name="b945423234519"></a>Description</strong></p>
</td>
</tr>
<tr id="row1813093818415"><td class="cellrowborder" valign="top" width="50%"><p id="p453212235494"><a name="p453212235494"></a><a name="p453212235494"></a>1. Error information</p>
<p id="p753222334914"><a name="p753222334914"></a><a name="p753222334914"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1353282314492"><a name="p1353282314492"></a><a name="p1353282314492"></a>1. The operation fails.</p>
<p id="p053312316491"><a name="p053312316491"></a><a name="p053312316491"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std tconn 192.168.0.100:8710

### tmode usb<a name="section17840182562015"></a>

Restarts the daemon process and connects to the device using USB.

**Table  8**  Command description

<a name="table94491851798"></a>
<table><tbody><tr id="row3450451595"><td class="cellrowborder" valign="top" width="50%"><p id="p1450551394"><a name="p1450551394"></a><a name="p1450551394"></a><strong id="b846114213215"><a name="b846114213215"></a><a name="b846114213215"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1645016511493"><a name="p1645016511493"></a><a name="p1645016511493"></a><strong id="b1460217222219"><a name="b1460217222219"></a><a name="b1460217222219"></a>Description</strong></p>
</td>
</tr>
<tr id="row245010513917"><td class="cellrowborder" valign="top" width="50%"><p id="p64509517910"><a name="p64509517910"></a><a name="p64509517910"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p134501517910"><a name="p134501517910"></a><a name="p134501517910"></a>None</p>
</td>
</tr>
<tr id="row184501851891"><td class="cellrowborder" valign="top" width="50%"><p id="p18450205118919"><a name="p18450205118919"></a><a name="p18450205118919"></a><strong id="b5890324142117"><a name="b5890324142117"></a><a name="b5890324142117"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p44504518913"><a name="p44504518913"></a><a name="p44504518913"></a><strong id="b477462615214"><a name="b477462615214"></a><a name="b477462615214"></a>Description</strong></p>
</td>
</tr>
<tr id="row3450551196"><td class="cellrowborder" valign="top" width="50%"><p id="p819142715546"><a name="p819142715546"></a><a name="p819142715546"></a>1. Error information</p>
<p id="p11911427195411"><a name="p11911427195411"></a><a name="p11911427195411"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p81911527145413"><a name="p81911527145413"></a><a name="p81911527145413"></a>1. The operation fails.</p>
<p id="p4191192720546"><a name="p4191192720546"></a><a name="p4191192720546"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std tmode usb

### tmode port  _port-number_<a name="section101113462113"></a>

Restarts the daemon process and connects to the device over TCP.

**Table  9**  Command description

<a name="table019772118177"></a>
<table><tbody><tr id="row11972213173"><td class="cellrowborder" valign="top" width="50%"><p id="p319752111178"><a name="p319752111178"></a><a name="p319752111178"></a><strong id="b36026232916"><a name="b36026232916"></a><a name="b36026232916"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p17198121121713"><a name="p17198121121713"></a><a name="p17198121121713"></a><strong id="b19575432914"><a name="b19575432914"></a><a name="b19575432914"></a>Description</strong></p>
</td>
</tr>
<tr id="row519812161713"><td class="cellrowborder" valign="top" width="50%"><p id="p819872114179"><a name="p819872114179"></a><a name="p819872114179"></a>port-number</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18198921171715"><a name="p18198921171715"></a><a name="p18198921171715"></a>Port number used to connect to the device</p>
</td>
</tr>
<tr id="row1519872118175"><td class="cellrowborder" valign="top" width="50%"><p id="p219882112179"><a name="p219882112179"></a><a name="p219882112179"></a><strong id="b8133858163410"><a name="b8133858163410"></a><a name="b8133858163410"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10198621111710"><a name="p10198621111710"></a><a name="p10198621111710"></a><strong id="b5734135914341"><a name="b5734135914341"></a><a name="b5734135914341"></a>Description</strong></p>
</td>
</tr>
<tr id="row1019822118176"><td class="cellrowborder" valign="top" width="50%"><p id="p742693415541"><a name="p742693415541"></a><a name="p742693415541"></a>1. Error information</p>
<p id="p2426234155414"><a name="p2426234155414"></a><a name="p2426234155414"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p17426133416542"><a name="p17426133416542"></a><a name="p17426133416542"></a>1. The operation fails.</p>
<p id="p20426834195419"><a name="p20426834195419"></a><a name="p20426834195419"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std tmode port 8710

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>After this command is executed, the remote daemon process exits and restarts, and the TCP connection is enabled by default. If you do not include  **port-number**  in this command, a random port will be used to connect to the device.

## File Commands<a name="section173133523013"></a>

The following commands are available:

### file send  _local remote_<a name="section126223231307"></a>

Sends a file to a remote device.

**Table  10**  Command description

<a name="table14621451193116"></a>
<table><tbody><tr id="row1062451113113"><td class="cellrowborder" valign="top" width="50%"><p id="p1262115173111"><a name="p1262115173111"></a><a name="p1262115173111"></a><strong id="b15171734193117"><a name="b15171734193117"></a><a name="b15171734193117"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1362135193113"><a name="p1362135193113"></a><a name="p1362135193113"></a><strong id="b1515353518311"><a name="b1515353518311"></a><a name="b1515353518311"></a>Description</strong></p>
</td>
</tr>
<tr id="row9627518318"><td class="cellrowborder" valign="top" width="50%"><p id="p14620519314"><a name="p14620519314"></a><a name="p14620519314"></a><span>l</span><span>ocal</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p176225193115"><a name="p176225193115"></a><a name="p176225193115"></a>Path of the file to send</p>
</td>
</tr>
<tr id="row1462451183119"><td class="cellrowborder" valign="top" width="50%"><p id="p14622051193115"><a name="p14622051193115"></a><a name="p14622051193115"></a><span>r</span><span>emote</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1634515316"><a name="p1634515316"></a><a name="p1634515316"></a>Destination path on the remote device</p>
</td>
</tr>
<tr id="row2063145116319"><td class="cellrowborder" valign="top" width="50%"><p id="p4632515314"><a name="p4632515314"></a><a name="p4632515314"></a><strong id="b5438824103211"><a name="b5438824103211"></a><a name="b5438824103211"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p136375117312"><a name="p136375117312"></a><a name="p136375117312"></a><strong id="b1492063173210"><a name="b1492063173210"></a><a name="b1492063173210"></a>Description</strong></p>
</td>
</tr>
<tr id="row663125113314"><td class="cellrowborder" valign="top" width="50%"><p id="p17550131319559"><a name="p17550131319559"></a><a name="p17550131319559"></a>1. Error information</p>
<p id="p0550151385512"><a name="p0550151385512"></a><a name="p0550151385512"></a>2. File transfer result</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1955091315517"><a name="p1955091315517"></a><a name="p1955091315517"></a>1. The operation fails.</p>
<p id="p1555041375519"><a name="p1555041375519"></a><a name="p1555041375519"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std file send E:\\a.txt   /data/local/tmp/a.txt

### file recv \[-a\]  _remote local_<a name="section26966541304"></a>

Receives a file from a remote device.

**Table  11**  Command description

<a name="table158381145153317"></a>
<table><tbody><tr id="row17838945183314"><td class="cellrowborder" valign="top" width="50%"><p id="p383884515338"><a name="p383884515338"></a><a name="p383884515338"></a><strong id="b1561985893318"><a name="b1561985893318"></a><a name="b1561985893318"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p583844511335"><a name="p583844511335"></a><a name="p583844511335"></a><strong id="b77671759123312"><a name="b77671759123312"></a><a name="b77671759123312"></a>Description</strong></p>
</td>
</tr>
<tr id="row1983814583315"><td class="cellrowborder" valign="top" width="50%"><p id="p1383834510332"><a name="p1383834510332"></a><a name="p1383834510332"></a><span>-a</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18391745103318"><a name="p18391745103318"></a><a name="p18391745103318"></a>File retention timestamp mode</p>
</td>
</tr>
<tr id="row1683910452331"><td class="cellrowborder" valign="top" width="50%"><p id="p14839164511331"><a name="p14839164511331"></a><a name="p14839164511331"></a><span>l</span><span>ocal</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1783912455333"><a name="p1783912455333"></a><a name="p1783912455333"></a>Path on the local device to receive the file</p>
</td>
</tr>
<tr id="row3941318173410"><td class="cellrowborder" valign="top" width="50%"><p id="p49411618153419"><a name="p49411618153419"></a><a name="p49411618153419"></a><span>r</span><span>emote</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p179411118193416"><a name="p179411118193416"></a><a name="p179411118193416"></a>File path on the remote device</p>
</td>
</tr>
<tr id="row88390451339"><td class="cellrowborder" valign="top" width="50%"><p id="p2839194516338"><a name="p2839194516338"></a><a name="p2839194516338"></a><strong id="b527817345362"><a name="b527817345362"></a><a name="b527817345362"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p683984533315"><a name="p683984533315"></a><a name="p683984533315"></a><strong id="b14550163610360"><a name="b14550163610360"></a><a name="b14550163610360"></a>Description</strong></p>
</td>
</tr>
<tr id="row48391459333"><td class="cellrowborder" valign="top" width="50%"><p id="p13206132716566"><a name="p13206132716566"></a><a name="p13206132716566"></a>1. Error information</p>
<p id="p620632745613"><a name="p620632745613"></a><a name="p620632745613"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p120662717562"><a name="p120662717562"></a><a name="p120662717562"></a>1. The operation fails.</p>
<p id="p182060275563"><a name="p182060275563"></a><a name="p182060275563"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std file recv  /data/local/tmp/a.txt   ./a.txt

## App Commands<a name="section2072647133819"></a>

The following commands are available:

### install \[-r/-d/-g\]  _package_<a name="section49615195111"></a>

Installs the OpenHarmony application.

**Table  12**  Command description

<a name="table17750145274216"></a>
<table><tbody><tr id="row20750115294217"><td class="cellrowborder" valign="top" width="50%"><p id="p075011520420"><a name="p075011520420"></a><a name="p075011520420"></a><strong id="b11989104513717"><a name="b11989104513717"></a><a name="b11989104513717"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p8750352174213"><a name="p8750352174213"></a><a name="p8750352174213"></a><strong id="b557147153718"><a name="b557147153718"></a><a name="b557147153718"></a>Description</strong></p>
</td>
</tr>
<tr id="row10750145215423"><td class="cellrowborder" valign="top" width="50%"><p id="p87501852144219"><a name="p87501852144219"></a><a name="p87501852144219"></a>package</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1175045234218"><a name="p1175045234218"></a><a name="p1175045234218"></a><span id="text16401191544314"><a name="text16401191544314"></a><a name="text16401191544314"></a>OpenHarmony</span> application installation package</p>
</td>
</tr>
<tr id="row675055212422"><td class="cellrowborder" valign="top" width="50%"><p id="p875111524420"><a name="p875111524420"></a><a name="p875111524420"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p117511052144218"><a name="p117511052144218"></a><a name="p117511052144218"></a>Replaces an existing application.</p>
</td>
</tr>
<tr id="row27512529425"><td class="cellrowborder" valign="top" width="50%"><p id="p975125234214"><a name="p975125234214"></a><a name="p975125234214"></a>-d</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p13784141616446"><a name="p13784141616446"></a><a name="p13784141616446"></a>Allows downgraded installation.</p>
</td>
</tr>
<tr id="row137312316446"><td class="cellrowborder" valign="top" width="50%"><p id="p6374623104414"><a name="p6374623104414"></a><a name="p6374623104414"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p6374122319440"><a name="p6374122319440"></a><a name="p6374122319440"></a>Grants permission dynamically</p>
</td>
</tr>
<tr id="row12751652184219"><td class="cellrowborder" valign="top" width="50%"><p id="p475195234219"><a name="p475195234219"></a><a name="p475195234219"></a><strong id="b1597414419421"><a name="b1597414419421"></a><a name="b1597414419421"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p117511452174214"><a name="p117511452174214"></a><a name="p117511452174214"></a><strong id="b19771771427"><a name="b19771771427"></a><a name="b19771771427"></a>Description</strong></p>
</td>
</tr>
<tr id="row1275111528426"><td class="cellrowborder" valign="top" width="50%"><p id="p472019319564"><a name="p472019319564"></a><a name="p472019319564"></a>1. Error information</p>
<p id="p5720123110569"><a name="p5720123110569"></a><a name="p5720123110569"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16720113145610"><a name="p16720113145610"></a><a name="p16720113145610"></a>1. The operation fails.</p>
<p id="p8720031185611"><a name="p8720031185611"></a><a name="p8720031185611"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std install  _hwadmin.hap_

### uninstall \[-k\]  _package_<a name="section167618461814"></a>

Uninstalls the OpenHarmony application.

**Table  13**  Command description

<a name="table35114624716"></a>
<table><tbody><tr id="row125646174717"><td class="cellrowborder" valign="top" width="50%"><p id="p166204610478"><a name="p166204610478"></a><a name="p166204610478"></a><strong id="b1037216202443"><a name="b1037216202443"></a><a name="b1037216202443"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p96146184715"><a name="p96146184715"></a><a name="p96146184715"></a><strong id="b1421672174417"><a name="b1421672174417"></a><a name="b1421672174417"></a>Description</strong></p>
</td>
</tr>
<tr id="row26164617475"><td class="cellrowborder" valign="top" width="50%"><p id="p26124612474"><a name="p26124612474"></a><a name="p26124612474"></a>package</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1634674710"><a name="p1634674710"></a><a name="p1634674710"></a><span id="text442592314413"><a name="text442592314413"></a><a name="text442592314413"></a>OpenHarmony</span> application installation package</p>
</td>
</tr>
<tr id="row06104616471"><td class="cellrowborder" valign="top" width="50%"><p id="p1461146144719"><a name="p1461146144719"></a><a name="p1461146144719"></a>-k</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p19613463476"><a name="p19613463476"></a><a name="p19613463476"></a>Retains <strong id="b57611340114410"><a name="b57611340114410"></a><a name="b57611340114410"></a>/data/cache</strong>.</p>
</td>
</tr>
<tr id="row3624614478"><td class="cellrowborder" valign="top" width="50%"><p id="p46114644719"><a name="p46114644719"></a><a name="p46114644719"></a><strong id="b117338433441"><a name="b117338433441"></a><a name="b117338433441"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p186114618474"><a name="p186114618474"></a><a name="p186114618474"></a><strong id="b11453164518441"><a name="b11453164518441"></a><a name="b11453164518441"></a>Description</strong></p>
</td>
</tr>
<tr id="row17654616471"><td class="cellrowborder" valign="top" width="50%"><p id="p2071893615564"><a name="p2071893615564"></a><a name="p2071893615564"></a>1. Error information</p>
<p id="p1971893615560"><a name="p1971893615560"></a><a name="p1971893615560"></a>2. None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p167181136125610"><a name="p167181136125610"></a><a name="p167181136125610"></a>1. The operation fails.</p>
<p id="p1371811369562"><a name="p1371811369562"></a><a name="p1371811369562"></a>2. The operation is successful.</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std uninstall  _package_

## Debugging Commands<a name="section112861250195015"></a>

The following commands are available:

### hilog<a name="section32171612221"></a>

Obtains logs for debugging.

**Table  14**  Command description

<a name="table1494175214518"></a>
<table><tbody><tr id="row1994119527515"><td class="cellrowborder" valign="top" width="50%"><p id="p19411552205117"><a name="p19411552205117"></a><a name="p19411552205117"></a><strong id="b975982755219"><a name="b975982755219"></a><a name="b975982755219"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p139412052195113"><a name="p139412052195113"></a><a name="p139412052195113"></a><strong id="b82231429105217"><a name="b82231429105217"></a><a name="b82231429105217"></a>Description</strong></p>
</td>
</tr>
<tr id="row994275265110"><td class="cellrowborder" valign="top" width="50%"><p id="p69421852115119"><a name="p69421852115119"></a><a name="p69421852115119"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1694213525517"><a name="p1694213525517"></a><a name="p1694213525517"></a>None</p>
</td>
</tr>
<tr id="row149421752145113"><td class="cellrowborder" valign="top" width="50%"><p id="p16942152205114"><a name="p16942152205114"></a><a name="p16942152205114"></a><strong id="b624913217525"><a name="b624913217525"></a><a name="b624913217525"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p5942452195116"><a name="p5942452195116"></a><a name="p5942452195116"></a><strong id="b13941933175217"><a name="b13941933175217"></a><a name="b13941933175217"></a>Description</strong></p>
</td>
</tr>
<tr id="row11942105275116"><td class="cellrowborder" valign="top" width="50%"><p id="p194213523517"><a name="p194213523517"></a><a name="p194213523517"></a>Returned information</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p4942155215112"><a name="p4942155215112"></a><a name="p4942155215112"></a>Obtained logs</p>
</td>
</tr>
</tbody>
</table>

Example:

hdc\_std hilog

### shell \[_command_\]<a name="section524235625"></a>

Executes a command remotely or enters an interactive command environment.

**Table  15**  Command description

<a name="table365554575617"></a>
<table><tbody><tr id="row26551545185617"><td class="cellrowborder" valign="top" width="50%"><p id="p126558451567"><a name="p126558451567"></a><a name="p126558451567"></a><strong id="b7597114010310"><a name="b7597114010310"></a><a name="b7597114010310"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16655164518568"><a name="p16655164518568"></a><a name="p16655164518568"></a><strong id="b154431541936"><a name="b154431541936"></a><a name="b154431541936"></a>Description</strong></p>
</td>
</tr>
<tr id="row1465534525610"><td class="cellrowborder" valign="top" width="50%"><p id="p1265511453563"><a name="p1265511453563"></a><a name="p1265511453563"></a><span>command</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p365616459567"><a name="p365616459567"></a><a name="p365616459567"></a>Command to be executed</p>
</td>
</tr>
<tr id="row7656245165619"><td class="cellrowborder" valign="top" width="50%"><p id="p865624565611"><a name="p865624565611"></a><a name="p865624565611"></a><strong id="b1597017555312"><a name="b1597017555312"></a><a name="b1597017555312"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p10656194595611"><a name="p10656194595611"></a><a name="p10656194595611"></a><strong id="b061175715310"><a name="b061175715310"></a><a name="b061175715310"></a>Description</strong></p>
</td>
</tr>
<tr id="row9656114585615"><td class="cellrowborder" valign="top" width="50%"><p id="p765624513561"><a name="p765624513561"></a><a name="p765624513561"></a>Returned information</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p2481349195711"><a name="p2481349195711"></a><a name="p2481349195711"></a>Execution result of the command</p>
</td>
</tr>
</tbody>
</table>

Examples:

hdc\_std shell

## Troubleshooting<a name="section592920255582"></a>

### hdc\_std Fails to Connect to a Device<a name="section74019384588"></a>

-   **Symptom**

    **\[Empty\]**  is displayed in the output after the  **hdc\_std list targets**  command is executed.

-   **Solutions**
    1.  The device cannot be identified.

        Check whether  **HDC Device**  exists in the universal serial bus device of the device manager. If  **HDC Device**  does not exist, the device cannot be connected. In this case, remove and then insert the device or burn the latest image for the device.

    2.  hdc\_std works improperly.

        Run the  **hdc kill**  or  **hdc start -r**  command to kill or restart the hdc service. Then, run the  **hdc list targets**  command to check whether device information can be obtained.

    3.  hdc\_std does not match the device.

        If the latest image is burnt on the device, the latest hdc\_std version must be used. As hdc\_std is updated continuously, obtain hdc\_std of the latest version from the  **developtools\_hdc\_standard**  repository in the  **prebuilt**  directory.



## hdc\_std Fails to Run<a name="section6825095917"></a>

-   **Symptom**

    The  **hdc\_std.exe**  file does not run after being clicked.

-   **Solutions**

    **hdc\_std.exe**  requires no installation. It can be directly used on a disk or added to environment variables. Open the cmd window and run the  **hdc\_std**  command to use  **hdc\_std.exe**.
