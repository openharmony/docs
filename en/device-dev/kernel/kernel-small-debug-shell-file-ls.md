# ls

## Command Function<a name="section6538163771614"></a>

This command is used to display the content of a specified directory.

## Syntax<a name="section45881743111616"></a>

ls \[_-ACHLSZacdfhiklmnopqrstux1_\] \[_--color_\[_=auto_\]\] \[_directory..._\]

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>During the system boot process,  **ls=toybox ls --color=auto**,  **ll = ls -alF**,  **la=ls -A**, and  **l=ls -CF**  commands have been enabled using  **alias**  so that the initial actions of these commands are the same as those on Linux. For details, see the output description. To view help information, run  **toybox ls --help**.

## Parameters<a name="section17528148171617"></a>

**Table  1**  Command parameter description

<a name="table1244mcpsimp"></a>
<table><thead align="left"><tr id="row1250mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1252mcpsimp"><a name="p1252mcpsimp"></a><a name="p1252mcpsimp"></a><strong id="b85851402216"><a name="b85851402216"></a><a name="b85851402216"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1254mcpsimp"><a name="p1254mcpsimp"></a><a name="p1254mcpsimp"></a><strong id="b128175424215"><a name="b128175424215"></a><a name="b128175424215"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1256mcpsimp"><a name="p1256mcpsimp"></a><a name="p1256mcpsimp"></a><strong id="b184580431629"><a name="b184580431629"></a><a name="b184580431629"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1165411114303"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p16614161193017"><a name="p16614161193017"></a><a name="p16614161193017"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p161410110302"><a name="p161410110302"></a><a name="p161410110302"></a>Displays parameters supported by the <strong id="b05047195230"><a name="b05047195230"></a><a name="b05047195230"></a>ls</strong> command and their usage.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p196141211193014"><a name="p196141211193014"></a><a name="p196141211193014"></a>N/A</p>
</td>
</tr>
<tr id="row3653131173015"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p76141511123013"><a name="p76141511123013"></a><a name="p76141511123013"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p861431163012"><a name="p861431163012"></a><a name="p861431163012"></a>Displays all files, including .hidden files.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p161421153016"><a name="p161421153016"></a><a name="p161421153016"></a>N/A</p>
</td>
</tr>
<tr id="row6653161163013"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p10614131116307"><a name="p10614131116307"></a><a name="p10614131116307"></a>-b</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p6614511113013"><a name="p6614511113013"></a><a name="p6614511113013"></a>Escapes non-graphical characters.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p16614161110307"><a name="p16614161110307"></a><a name="p16614161110307"></a>N/A</p>
</td>
</tr>
<tr id="row165311113302"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p761517119300"><a name="p761517119300"></a><a name="p761517119300"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p6615121114307"><a name="p6615121114307"></a><a name="p6615121114307"></a>Uses ctime as the file timestamp. This parameter must be used together with <strong id="b644143217354"><a name="b644143217354"></a><a name="b644143217354"></a>-l</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p861561115308"><a name="p861561115308"></a><a name="p861561115308"></a>N/A</p>
</td>
</tr>
<tr id="row19652131193018"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1861591117301"><a name="p1861591117301"></a><a name="p1861591117301"></a>-d</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p126151511193010"><a name="p126151511193010"></a><a name="p126151511193010"></a>Displays only the directory, rather than listing the content of the directory.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p061521133020"><a name="p061521133020"></a><a name="p061521133020"></a>N/A</p>
</td>
</tr>
<tr id="row265212115302"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p12615151183012"><a name="p12615151183012"></a><a name="p12615151183012"></a>-i</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p11615511193012"><a name="p11615511193012"></a><a name="p11615511193012"></a>Displays the node ID of a file.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1361591103015"><a name="p1361591103015"></a><a name="p1361591103015"></a>N/A</p>
</td>
</tr>
<tr id="row66529118309"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p9615211133012"><a name="p9615211133012"></a><a name="p9615211133012"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3615131103017"><a name="p3615131103017"></a><a name="p3615131103017"></a>Adds a slash (/) after the directory.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1361551112302"><a name="p1361551112302"></a><a name="p1361551112302"></a>N/A</p>
</td>
</tr>
<tr id="row13651111183016"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p186151811183010"><a name="p186151811183010"></a><a name="p186151811183010"></a>-q</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p19615511123011"><a name="p19615511123011"></a><a name="p19615511123011"></a>Displays non-printable characters, such as "?".</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p6615151111303"><a name="p6615151111303"></a><a name="p6615151111303"></a>N/A</p>
</td>
</tr>
<tr id="row26511711113018"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1861581111304"><a name="p1861581111304"></a><a name="p1861581111304"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p161511114303"><a name="p161511114303"></a><a name="p161511114303"></a>Provides information about the memory occupied by the directory and its members, in 1024 bytes.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1061514115307"><a name="p1061514115307"></a><a name="p1061514115307"></a>N/A</p>
</td>
</tr>
<tr id="row4650181183020"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p8615101133017"><a name="p8615101133017"></a><a name="p8615101133017"></a>-u</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p761501113306"><a name="p761501113306"></a><a name="p761501113306"></a>Uses the last access time of the file as the timestamp. This option is used together with <strong id="b83441545164512"><a name="b83441545164512"></a><a name="b83441545164512"></a>-l</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p86153111309"><a name="p86153111309"></a><a name="p86153111309"></a>N/A</p>
</td>
</tr>
<tr id="row1365021120308"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p36151011193016"><a name="p36151011193016"></a><a name="p36151011193016"></a>-A</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p56151511183019"><a name="p56151511183019"></a><a name="p56151511183019"></a>Lists all files except implied . and ..</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p8615411193019"><a name="p8615411193019"></a><a name="p8615411193019"></a>N/A</p>
</td>
</tr>
<tr id="row13650151114302"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p20615411183017"><a name="p20615411183017"></a><a name="p20615411183017"></a>-H</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p19615151118304"><a name="p19615151118304"></a><a name="p19615151118304"></a>Follows symbolic links listed in the command line.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p10615161112307"><a name="p10615161112307"></a><a name="p10615161112307"></a>N/A</p>
</td>
</tr>
<tr id="row1865071119306"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p206151911123017"><a name="p206151911123017"></a><a name="p206151911123017"></a>-L</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p5615911203017"><a name="p5615911203017"></a><a name="p5615911203017"></a>Follows symbolic links.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p16615111111307"><a name="p16615111111307"></a><a name="p16615111111307"></a>N/A</p>
</td>
</tr>
<tr id="row16649411173019"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1861581116309"><a name="p1861581116309"></a><a name="p1861581116309"></a>-Z</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p7616151112301"><a name="p7616151112301"></a><a name="p7616151112301"></a>Displays security context.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p12616411173010"><a name="p12616411173010"></a><a name="p12616411173010"></a>N/A</p>
</td>
</tr>
<tr id="row186497114307"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p17616211113010"><a name="p17616211113010"></a><a name="p17616211113010"></a>path</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1761611110307"><a name="p1761611110307"></a><a name="p1761611110307"></a>If <strong id="b115515262034"><a name="b115515262034"></a><a name="b115515262034"></a>path</strong> is left blank, the content of the current directory is displayed.</p>
<p id="p10616141117308"><a name="p10616141117308"></a><a name="p10616141117308"></a>If <strong id="b9593204114312"><a name="b9593204114312"></a><a name="b9593204114312"></a>path</strong> is an invalid file name, the following failure message is displayed:</p>
<p id="p1061631112303"><a name="p1061631112303"></a><a name="p1061631112303"></a><strong id="b19604131716416"><a name="b19604131716416"></a><a name="b19604131716416"></a>ls error: No such directory</strong></p>
<p id="p206161111143018"><a name="p206161111143018"></a><a name="p206161111143018"></a>If <strong id="b615314272412"><a name="b615314272412"></a><a name="b615314272412"></a>path</strong> is a valid directory, the content of that directory is displayed.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p761617115309"><a name="p761617115309"></a><a name="p761617115309"></a>Left blank or a valid directory</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Output parameters

<a name="table197022663018"></a>
<table><thead align="left"><tr id="row7970172614303"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p8970122616304"><a name="p8970122616304"></a><a name="p8970122616304"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p197012633020"><a name="p197012633020"></a><a name="p197012633020"></a><strong id="b1961069541"><a name="b1961069541"></a><a name="b1961069541"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1397092603018"><a name="p1397092603018"></a><a name="p1397092603018"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row106817566303"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p365845683010"><a name="p365845683010"></a><a name="p365845683010"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1865811565309"><a name="p1865811565309"></a><a name="p1865811565309"></a>Lists one file per line.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p0658195616305"><a name="p0658195616305"></a><a name="p0658195616305"></a>N/A</p>
</td>
</tr>
<tr id="row15680155633011"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p116585565301"><a name="p116585565301"></a><a name="p116585565301"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1065865611302"><a name="p1065865611302"></a><a name="p1065865611302"></a>Lists entries by column.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p06581456113013"><a name="p06581456113013"></a><a name="p06581456113013"></a>N/A</p>
</td>
</tr>
<tr id="row11680556173014"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p86581756193012"><a name="p86581756193012"></a><a name="p86581756193012"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p20658356183018"><a name="p20658356183018"></a><a name="p20658356183018"></a>Like <strong id="b206161282355"><a name="b206161282355"></a><a name="b206161282355"></a>-l</strong>, but do not list owner.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p7658165663019"><a name="p7658165663019"></a><a name="p7658165663019"></a>N/A</p>
</td>
</tr>
<tr id="row19680105614309"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p17658185612306"><a name="p17658185612306"></a><a name="p17658185612306"></a>-h</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p16581756143014"><a name="p16581756143014"></a><a name="p16581756143014"></a>Displays the total size of files in the directory, in KiB.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1865814565305"><a name="p1865814565305"></a><a name="p1865814565305"></a>N/A</p>
</td>
</tr>
<tr id="row46801356143016"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p11658056123016"><a name="p11658056123016"></a><a name="p11658056123016"></a>-l</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1465875603018"><a name="p1465875603018"></a><a name="p1465875603018"></a>Displays detailed information about files in the directory.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p10658105673015"><a name="p10658105673015"></a><a name="p10658105673015"></a>N/A</p>
</td>
</tr>
<tr id="row136791256203013"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p10658125616303"><a name="p10658125616303"></a><a name="p10658125616303"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p15658115620304"><a name="p15658115620304"></a><a name="p15658115620304"></a>Fills width with a list of entries separated by a comma.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p26584563301"><a name="p26584563301"></a><a name="p26584563301"></a>N/A</p>
</td>
</tr>
<tr id="row176791156163014"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p265875611309"><a name="p265875611309"></a><a name="p265875611309"></a>-n</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1465895663016"><a name="p1465895663016"></a><a name="p1465895663016"></a>Like <strong id="b88319189351"><a name="b88319189351"></a><a name="b88319189351"></a>-l</strong>, but lists numeric user and group IDs.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p9658135613011"><a name="p9658135613011"></a><a name="p9658135613011"></a>N/A</p>
</td>
</tr>
<tr id="row10679185653015"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p365815562303"><a name="p365815562303"></a><a name="p365815562303"></a>-o</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p12658956193017"><a name="p12658956193017"></a><a name="p12658956193017"></a>Like <strong id="b24118395354"><a name="b24118395354"></a><a name="b24118395354"></a>-l</strong>, but do not list group information.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p8658155610309"><a name="p8658155610309"></a><a name="p8658155610309"></a>N/A</p>
</td>
</tr>
<tr id="row176791656123015"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1765865643019"><a name="p1765865643019"></a><a name="p1765865643019"></a>-x</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p13658456123014"><a name="p13658456123014"></a><a name="p13658456123014"></a>Lists entries by line, instead of by column.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p196581256103015"><a name="p196581256103015"></a><a name="p196581256103015"></a>N/A</p>
</td>
</tr>
<tr id="row1467820567304"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p06584565305"><a name="p06584565305"></a><a name="p06584565305"></a>-ll</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p365855610302"><a name="p365855610302"></a><a name="p365855610302"></a>Lists the file time attribute as ns.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p365845653010"><a name="p365845653010"></a><a name="p365845653010"></a>N/A</p>
</td>
</tr>
<tr id="row176781456183019"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p11659256133013"><a name="p11659256133013"></a><a name="p11659256133013"></a>--color</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2659756123020"><a name="p2659756123020"></a><a name="p2659756123020"></a>Colorizes the output.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2659135633011"><a name="p2659135633011"></a><a name="p2659135633011"></a>Default value: device=yellow symlink=turquoise/red dir=blue socket=purple files: exe=green suid=red suidfile=redback stickydir=greenback=auto means detect if output is a tty.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  Sorting parameters \(sorted by the initial letter by default\)

<a name="table164254153318"></a>
<table><thead align="left"><tr id="row2425191515317"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p74259156313"><a name="p74259156313"></a><a name="p74259156313"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p542501512317"><a name="p542501512317"></a><a name="p542501512317"></a><strong id="b237939680"><a name="b237939680"></a><a name="b237939680"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1342513154318"><a name="p1342513154318"></a><a name="p1342513154318"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row10358027153118"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p83441727153114"><a name="p83441727153114"></a><a name="p83441727153114"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p18344132717315"><a name="p18344132717315"></a><a name="p18344132717315"></a>Do not sort.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1834402753112"><a name="p1834402753112"></a><a name="p1834402753112"></a>N/A</p>
</td>
</tr>
<tr id="row4357112714312"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p6344162773117"><a name="p6344162773117"></a><a name="p6344162773117"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p11344102743115"><a name="p11344102743115"></a><a name="p11344102743115"></a>Reverse order while sorting.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p2344142719315"><a name="p2344142719315"></a><a name="p2344142719315"></a>N/A</p>
</td>
</tr>
<tr id="row133571827153114"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2344152717318"><a name="p2344152717318"></a><a name="p2344152717318"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p10344727103114"><a name="p10344727103114"></a><a name="p10344727103114"></a>Sort by time, newest first.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p73441927123116"><a name="p73441927123116"></a><a name="p73441927123116"></a>N/A</p>
</td>
</tr>
<tr id="row4357102773115"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p83444274318"><a name="p83444274318"></a><a name="p83444274318"></a>-S</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1134452715312"><a name="p1134452715312"></a><a name="p1134452715312"></a>Sort by file size, largest first.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1344122717310"><a name="p1344122717310"></a><a name="p1344122717310"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section041212533166"></a>

None

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>The file node information of the FAT file system inherits from its parent node. The parent node ID is  **0**. Therefore, if you run the  **ls -i**  command on the Hi3516D V300 development board, the file node IDs displayed are all  **0**.

## Example<a name="section986105716167"></a>

Run the following commands:

-   ls
-   ll

## Output<a name="section2036124918592"></a>

Example 1:  **ls**  command output

```
OHOS:/$ ls
bin  etc  nfs   sdcard   system    usr
dev  lib  proc  storage  userdata  vendor
```

Example 2:  **ll**  command output

```
OHOS:/$ ll
total 20
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 bin/
drwxr-xr-x 0 0 0    0 1970-01-01 00:00 dev/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 etc/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 lib/
drwxrwxrwx 0 0 0 4096 2021-10-25 02:17 nfs/
dr-xr-xr-x 0 0 0    0 1970-01-01 00:00 proc/
drwxrwxrwx 1 0 0 4096 1979-12-31 00:00 sdcard/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 storage/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 system/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 userdata/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 usr/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 vendor/
```

