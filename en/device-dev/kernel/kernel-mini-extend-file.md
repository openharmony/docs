# File System

The OpenHarmony LiteOS-M kernel supports File Allocation Table file system \(FATFS\) and LittleFS file systems. Like the OpenHarmony LiteOS-A kernel, the OpenHarmony LiteOS-M kernel provides POSIX over the virtual file system \(VFS\) to ensure interface consistency. However, the VFS of the LiteOS-M kernel is light due to insufficient resources and does not provide advanced functions \(such as pagecache\). Therefore, the VFS of the LiteOS-M kernel implements only API standardization and adaptation. The file systems handle specific transactions. The following table lists the functions supported by the file systems.

**Table 1** Function list

<a name="table147491853163018"></a>
<table><thead align="left"><tr id="row10807205323013"><th class="cellrowborder" valign="top" width="12.738726127387261%" id="mcps1.2.6.1.1"><p id="p980714539304"><a name="p980714539304"></a><a name="p980714539304"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="12.418758124187582%" id="mcps1.2.6.1.2"><p id="p1780715533305"><a name="p1780715533305"></a><a name="p1780715533305"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="44.605539446055396%" id="mcps1.2.6.1.3"><p id="p18807185316301"><a name="p18807185316301"></a><a name="p18807185316301"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="14.87851214878512%" id="mcps1.2.6.1.4"><p id="p12498884271"><a name="p12498884271"></a><a name="p12498884271"></a>FATFS</p>
</th>
<th class="cellrowborder" valign="top" width="15.358464153584642%" id="mcps1.2.6.1.5"><p id="p348021419272"><a name="p348021419272"></a><a name="p348021419272"></a>LITTLEFS</p>
</th>
</tr>
</thead>
<tbody><tr id="row15807135373016"><td class="cellrowborder" rowspan="10" valign="top" width="12.738726127387261%" headers="mcps1.2.6.1.1 "><p id="p13807185311309"><a name="p13807185311309"></a><a name="p13807185311309"></a>File management</p>
</td>
<td class="cellrowborder" valign="top" width="12.418758124187582%" headers="mcps1.2.6.1.2 "><p id="p1844913783415"><a name="p1844913783415"></a><a name="p1844913783415"></a>open</p>
</td>
<td class="cellrowborder" valign="top" width="44.605539446055396%" headers="mcps1.2.6.1.3 "><p id="p1807145320308"><a name="p1807145320308"></a><a name="p1807145320308"></a>Opens a file.</p>
</td>
<td class="cellrowborder" valign="top" width="14.87851214878512%" headers="mcps1.2.6.1.4 "><p id="p349815892714"><a name="p349815892714"></a><a name="p349815892714"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" width="15.358464153584642%" headers="mcps1.2.6.1.5 "><p id="p114805143273"><a name="p114805143273"></a><a name="p114805143273"></a>Supported</p>
</td>
</tr>
<tr id="row3807145310300"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p14450133710344"><a name="p14450133710344"></a><a name="p14450133710344"></a>close</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p61801940174715"><a name="p61801940174715"></a><a name="p61801940174715"></a>Closes a file.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p124985842719"><a name="p124985842719"></a><a name="p124985842719"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p8247202914439"><a name="p8247202914439"></a><a name="p8247202914439"></a>Supported</p>
</td>
</tr>
<tr id="row17983567378"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1132194016370"><a name="p1132194016370"></a><a name="p1132194016370"></a>read</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p83859178485"><a name="p83859178485"></a><a name="p83859178485"></a>Reads a file.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p124983832712"><a name="p124983832712"></a><a name="p124983832712"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p146813284314"><a name="p146813284314"></a><a name="p146813284314"></a>Supported</p>
</td>
</tr>
<tr id="row2997112220379"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1032940123712"><a name="p1032940123712"></a><a name="p1032940123712"></a>write</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p176091241485"><a name="p176091241485"></a><a name="p176091241485"></a>Writes data to a file.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p194988822715"><a name="p194988822715"></a><a name="p194988822715"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p1148041415271"><a name="p1148041415271"></a><a name="p1148041415271"></a>Supported</p>
</td>
</tr>
<tr id="row882312633713"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1433144063711"><a name="p1433144063711"></a><a name="p1433144063711"></a>lseek</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p138512964919"><a name="p138512964919"></a><a name="p138512964919"></a>Sets the file offset.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p849848182715"><a name="p849848182715"></a><a name="p849848182715"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p114801914122716"><a name="p114801914122716"></a><a name="p114801914122716"></a>Supported</p>
</td>
</tr>
<tr id="row1255192920378"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p12211034184314"><a name="p12211034184314"></a><a name="p12211034184314"></a>unlink</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p625522973712"><a name="p625522973712"></a><a name="p625522973712"></a>Deletes a file.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p194989811278"><a name="p194989811278"></a><a name="p194989811278"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p1480141419274"><a name="p1480141419274"></a><a name="p1480141419274"></a>Supported</p>
</td>
</tr>
<tr id="row1748513315379"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p6221123412439"><a name="p6221123412439"></a><a name="p6221123412439"></a>rename</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p14485193113376"><a name="p14485193113376"></a><a name="p14485193113376"></a>Renames a file. </p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p0498178152719"><a name="p0498178152719"></a><a name="p0498178152719"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p5480181410274"><a name="p5480181410274"></a><a name="p5480181410274"></a>Supported</p>
</td>
</tr>
<tr id="row14711133314377"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1622183424312"><a name="p1622183424312"></a><a name="p1622183424312"></a>fstat</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p47118331374"><a name="p47118331374"></a><a name="p47118331374"></a>Obtains file information based on the file handle.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p2049815815270"><a name="p2049815815270"></a><a name="p2049815815270"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p114800145275"><a name="p114800145275"></a><a name="p114800145275"></a>Supported</p>
</td>
</tr>
<tr id="row275965713434"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p0760257194311"><a name="p0760257194311"></a><a name="p0760257194311"></a>stat</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p0760185744315"><a name="p0760185744315"></a><a name="p0760185744315"></a>Obtains file information based on the file path name.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p54980817274"><a name="p54980817274"></a><a name="p54980817274"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p17480121418275"><a name="p17480121418275"></a><a name="p17480121418275"></a>Supported</p>
</td>
</tr>
<tr id="row1338825534315"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1138911557439"><a name="p1138911557439"></a><a name="p1138911557439"></a>fsync</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p11857231165014"><a name="p11857231165014"></a><a name="p11857231165014"></a>Saves file updates to a storage device.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p6498178142713"><a name="p6498178142713"></a><a name="p6498178142713"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p94801714142720"><a name="p94801714142720"></a><a name="p94801714142720"></a>Supported</p>
</td>
</tr>
<tr id="row14808175393014"><td class="cellrowborder" rowspan="5" valign="top" width="12.738726127387261%" headers="mcps1.2.6.1.1 "><p id="p19808155313303"><a name="p19808155313303"></a><a name="p19808155313303"></a>Directory management</p>
</td>
<td class="cellrowborder" valign="top" width="12.418758124187582%" headers="mcps1.2.6.1.2 "><p id="p19562203615452"><a name="p19562203615452"></a><a name="p19562203615452"></a>mkdir</p>
</td>
<td class="cellrowborder" valign="top" width="44.605539446055396%" headers="mcps1.2.6.1.3 "><p id="p1977064334716"><a name="p1977064334716"></a><a name="p1977064334716"></a>Creates a directory.</p>
</td>
<td class="cellrowborder" valign="top" width="14.87851214878512%" headers="mcps1.2.6.1.4 "><p id="p74982812711"><a name="p74982812711"></a><a name="p74982812711"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" width="15.358464153584642%" headers="mcps1.2.6.1.5 "><p id="p8480414162713"><a name="p8480414162713"></a><a name="p8480414162713"></a>Supported</p>
</td>
</tr>
<tr id="row179843414459"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p10562113616452"><a name="p10562113616452"></a><a name="p10562113616452"></a>opendir</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p179816348457"><a name="p179816348457"></a><a name="p179816348457"></a>Opens a directory.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p149813816279"><a name="p149813816279"></a><a name="p149813816279"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p17480131410276"><a name="p17480131410276"></a><a name="p17480131410276"></a>Supported</p>
</td>
</tr>
<tr id="row6816331134517"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p155621836104517"><a name="p155621836104517"></a><a name="p155621836104517"></a>readdir</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p198171131194514"><a name="p198171131194514"></a><a name="p198171131194514"></a>Reads the content of a directory.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p174981984274"><a name="p174981984274"></a><a name="p174981984274"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p1248061492717"><a name="p1248061492717"></a><a name="p1248061492717"></a>Supported</p>
</td>
</tr>
<tr id="row1480855311301"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1556233618452"><a name="p1556233618452"></a><a name="p1556233618452"></a>closedir</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p128021415175112"><a name="p128021415175112"></a><a name="p128021415175112"></a>Closes a directory.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p194982086279"><a name="p194982086279"></a><a name="p194982086279"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p6480214152710"><a name="p6480214152710"></a><a name="p6480214152710"></a>Supported</p>
</td>
</tr>
<tr id="row10808353153012"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p8563336154511"><a name="p8563336154511"></a><a name="p8563336154511"></a>rmdir</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p5786174617471"><a name="p5786174617471"></a><a name="p5786174617471"></a>Deletes a directory.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p17498148142710"><a name="p17498148142710"></a><a name="p17498148142710"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p848021432713"><a name="p848021432713"></a><a name="p848021432713"></a>Supported</p>
</td>
</tr>
<tr id="row680812535306"><td class="cellrowborder" rowspan="4" valign="top" width="12.738726127387261%" headers="mcps1.2.6.1.1 "><p id="p13808125314307"><a name="p13808125314307"></a><a name="p13808125314307"></a>Partition management</p>
</td>
<td class="cellrowborder" valign="top" width="12.418758124187582%" headers="mcps1.2.6.1.2 "><p id="p1244416484610"><a name="p1244416484610"></a><a name="p1244416484610"></a>mount</p>
</td>
<td class="cellrowborder" valign="top" width="44.605539446055396%" headers="mcps1.2.6.1.3 "><p id="p1312794814473"><a name="p1312794814473"></a><a name="p1312794814473"></a>Mounts a partition.</p>
</td>
<td class="cellrowborder" valign="top" width="14.87851214878512%" headers="mcps1.2.6.1.4 "><p id="p1849878112714"><a name="p1849878112714"></a><a name="p1849878112714"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" width="15.358464153584642%" headers="mcps1.2.6.1.5 "><p id="p15480111452717"><a name="p15480111452717"></a><a name="p15480111452717"></a>Supported</p>
</td>
</tr>
<tr id="row1275526194617"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p77561265464"><a name="p77561265464"></a><a name="p77561265464"></a>umount</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1275610616466"><a name="p1275610616466"></a><a name="p1275610616466"></a>Unmounts a partition.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p649819872719"><a name="p649819872719"></a><a name="p649819872719"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p3480714132712"><a name="p3480714132712"></a><a name="p3480714132712"></a>Supported</p>
</td>
</tr>
<tr id="row11601915134614"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p121601615164614"><a name="p121601615164614"></a><a name="p121601615164614"></a>umount2</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p171607155464"><a name="p171607155464"></a><a name="p171607155464"></a>Forcibly unmounts a partition using the <strong id="b172144710378"><a name="b172144710378"></a><a name="b172144710378"></a>MNT_FORCE</strong> parameter.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p5498178112713"><a name="p5498178112713"></a><a name="p5498178112713"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p0480141442714"><a name="p0480141442714"></a><a name="p0480141442714"></a>Not supported</p>
</td>
</tr>
<tr id="row713261764616"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1133171734610"><a name="p1133171734610"></a><a name="p1133171734610"></a>statfs</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1813311174468"><a name="p1813311174468"></a><a name="p1813311174468"></a>Obtains partition information.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p349917817278"><a name="p349917817278"></a><a name="p349917817278"></a>Supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.4 "><p id="p548112141279"><a name="p548112141279"></a><a name="p548112141279"></a>Not supported</p>
</td>
</tr>
</tbody>
</table>

-   **[FAT](kernel-mini-extend-file-fat.md)**  

-   **[LittleFS](kernel-mini-extend-file-lit.md)**  


