# Audio/Video Playback Development<a name="EN-US_TOPIC_0000001051930589"></a>

## When to Use<a name="section186634310418"></a>

Audio and video playback is a process to decode audio and video files or stream data and play them by an output device. During the process, playback tasks are managed.

## Available APIs<a name="section125479541744"></a>

The following table describes APIs available for audio and video playback.

**Table  1**  APIs available for media playback

<a name="table1139164071320"></a>
<table><thead align="left"><tr id="row85501040111310"><th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.2.4.1.1"><p id="p755044051316"><a name="p755044051316"></a><a name="p755044051316"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="47.77%" id="mcps1.2.4.1.2"><p id="p1755024018131"><a name="p1755024018131"></a><a name="p1755024018131"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="36.27%" id="mcps1.2.4.1.3"><p id="p8550134015131"><a name="p8550134015131"></a><a name="p8550134015131"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14550164011132"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p55505406135"><a name="p55505406135"></a><a name="p55505406135"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p15550240191312"><a name="p15550240191312"></a><a name="p15550240191312"></a>int32_t SetSource(const Source &amp;source);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p125502402132"><a name="p125502402132"></a><a name="p125502402132"></a>Sets the playback source for the player.</p>
</td>
</tr>
<tr id="row155044001318"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p255064021310"><a name="p255064021310"></a><a name="p255064021310"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p10550104014132"><a name="p10550104014132"></a><a name="p10550104014132"></a>int32_t Prepare();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p155503406138"><a name="p155503406138"></a><a name="p155503406138"></a>Prepares the playback environment.</p>
</td>
</tr>
<tr id="row165502040141313"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p3550174081313"><a name="p3550174081313"></a><a name="p3550174081313"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p9550144011310"><a name="p9550144011310"></a><a name="p9550144011310"></a>int32_t Play();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p255094041314"><a name="p255094041314"></a><a name="p255094041314"></a>Starts playback.</p>
</td>
</tr>
<tr id="row855064010130"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p3550840151318"><a name="p3550840151318"></a><a name="p3550840151318"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p195501409137"><a name="p195501409137"></a><a name="p195501409137"></a>bool IsPlaying()</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p255114020137"><a name="p255114020137"></a><a name="p255114020137"></a>Checks whether the player is playing.</p>
</td>
</tr>
<tr id="row1555111402135"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p05511840151313"><a name="p05511840151313"></a><a name="p05511840151313"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p16551340151314"><a name="p16551340151314"></a><a name="p16551340151314"></a>int32_t Pause();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p14551164021311"><a name="p14551164021311"></a><a name="p14551164021311"></a>Pauses playback.</p>
</td>
</tr>
<tr id="row155511740111315"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p185515403139"><a name="p185515403139"></a><a name="p185515403139"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p19551184031318"><a name="p19551184031318"></a><a name="p19551184031318"></a>int32_t Stop();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p555154041312"><a name="p555154041312"></a><a name="p555154041312"></a>Stops playback.</p>
</td>
</tr>
<tr id="row1255118400138"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p6551114081317"><a name="p6551114081317"></a><a name="p6551114081317"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p8551154015135"><a name="p8551154015135"></a><a name="p8551154015135"></a>int32_t Rewind(int_64 mSeconds, int32_t mode);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p1255184019138"><a name="p1255184019138"></a><a name="p1255184019138"></a>Changes the playback position.</p>
</td>
</tr>
<tr id="row195511640141312"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1455164061314"><a name="p1455164061314"></a><a name="p1455164061314"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p5551340151313"><a name="p5551340151313"></a><a name="p5551340151313"></a>int32_t SetVolume(float leftVolume, float rightVolume);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p19551940181320"><a name="p19551940181320"></a><a name="p19551940181320"></a>Sets player volume, including volume of left and right channels.</p>
</td>
</tr>
<tr id="row19551144015130"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p2055113408131"><a name="p2055113408131"></a><a name="p2055113408131"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1055124011314"><a name="p1055124011314"></a><a name="p1055124011314"></a>int32_t SetVideoSurface(Surface *surface)</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p1355104041311"><a name="p1355104041311"></a><a name="p1355104041311"></a>Sets a surface for video playback.</p>
</td>
</tr>
<tr id="row1355174010135"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p85511140161313"><a name="p85511140161313"></a><a name="p85511140161313"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p155114401137"><a name="p155114401137"></a><a name="p155114401137"></a>int32_t EnableSingleLooping(bool loop)</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p05513403130"><a name="p05513403130"></a><a name="p05513403130"></a>Enables loop playback.</p>
</td>
</tr>
<tr id="row185511040151319"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p3552124010139"><a name="p3552124010139"></a><a name="p3552124010139"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p6552144021318"><a name="p6552144021318"></a><a name="p6552144021318"></a>bool IsSingleLooping();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p555220403134"><a name="p555220403134"></a><a name="p555220403134"></a>Checks whether loop playback is enabled.</p>
</td>
</tr>
<tr id="row24941622111618"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1555214041314"><a name="p1555214041314"></a><a name="p1555214041314"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1655294011317"><a name="p1655294011317"></a><a name="p1655294011317"></a>int32_t GetCurrentTime(int64_t &amp;time) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p255234031315"><a name="p255234031315"></a><a name="p255234031315"></a>Obtains the current playback duration, accurate to millisecond.</p>
</td>
</tr>
<tr id="row655224015139"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p165520406137"><a name="p165520406137"></a><a name="p165520406137"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p7552164071320"><a name="p7552164071320"></a><a name="p7552164071320"></a>int32_t GetDuration(int64_t &amp;duration) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p17552640141312"><a name="p17552640141312"></a><a name="p17552640141312"></a>Obtains the total duration of media files, in milliseconds.</p>
</td>
</tr>
<tr id="row11552194019131"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p955214013132"><a name="p955214013132"></a><a name="p955214013132"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p655234018131"><a name="p655234018131"></a><a name="p655234018131"></a>int32_t GetVideoWidth(int32_t &amp;videoWidth);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p12552174081314"><a name="p12552174081314"></a><a name="p12552174081314"></a>Obtains the width of the video.</p>
</td>
</tr>
<tr id="row8552164013134"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p125525404136"><a name="p125525404136"></a><a name="p125525404136"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p13552114011316"><a name="p13552114011316"></a><a name="p13552114011316"></a>int32_t GetVideoHeight(int32_t &amp;videoHeight);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p14552134011138"><a name="p14552134011138"></a><a name="p14552134011138"></a>Obtains the height of the video.</p>
</td>
</tr>
<tr id="row6552340181312"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1155244017138"><a name="p1155244017138"></a><a name="p1155244017138"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1955374031313"><a name="p1955374031313"></a><a name="p1955374031313"></a>int32_t Reset();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p1553124061317"><a name="p1553124061317"></a><a name="p1553124061317"></a>Restores the player to the initial state.</p>
</td>
</tr>
<tr id="row6553134021311"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1655314021316"><a name="p1655314021316"></a><a name="p1655314021316"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p13553194018132"><a name="p13553194018132"></a><a name="p13553194018132"></a>int32_t Release();</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p455354018139"><a name="p455354018139"></a><a name="p455354018139"></a>Releases player resources.</p>
</td>
</tr>
<tr id="row25531940151318"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p95531440191318"><a name="p95531440191318"></a><a name="p95531440191318"></a>Player</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1955317400131"><a name="p1955317400131"></a><a name="p1955317400131"></a>void SetPlayerCallback(const std::shared_ptr&lt;PlayerCallback&gt; &amp;cb);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p135530402139"><a name="p135530402139"></a><a name="p135530402139"></a>Sets a player callback.</p>
</td>
</tr>
<tr id="row26841936205916"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p155531940171317"><a name="p155531940171317"></a><a name="p155531940171317"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1955314012137"><a name="p1955314012137"></a><a name="p1955314012137"></a>Source(const std::string&amp; uri);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p755314031315"><a name="p755314031315"></a><a name="p755314031315"></a>A constructor used to create a <strong id="b898542419341"><a name="b898542419341"></a><a name="b898542419341"></a>Source</strong> instance based on a specified URI.</p>
</td>
</tr>
<tr id="row16713165319598"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p195531740141316"><a name="p195531740141316"></a><a name="p195531740141316"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p655310403132"><a name="p655310403132"></a><a name="p655310403132"></a>Source(const std::shared_ptr&lt;StreamSource&gt; &amp;stream, const Format &amp;formats);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p05536401138"><a name="p05536401138"></a><a name="p05536401138"></a>A constructor used to create a <strong id="b39632476347"><a name="b39632476347"></a><a name="b39632476347"></a>Source</strong> instance based on the stream source and format information.</p>
</td>
</tr>
<tr id="row39004563590"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p15531340191312"><a name="p15531340191312"></a><a name="p15531340191312"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p13553174091318"><a name="p13553174091318"></a><a name="p13553174091318"></a>SourceType GetSourceType() const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p1455354016136"><a name="p1455354016136"></a><a name="p1455354016136"></a>Obtains the source type.</p>
</td>
</tr>
<tr id="row15429101008"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1655434018139"><a name="p1655434018139"></a><a name="p1655434018139"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p7554154013137"><a name="p7554154013137"></a><a name="p7554154013137"></a>const std::string &amp;GetSourceUri() const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p1855414071310"><a name="p1855414071310"></a><a name="p1855414071310"></a>Obtains the media source URI.</p>
</td>
</tr>
<tr id="row17477411011"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p105540409134"><a name="p105540409134"></a><a name="p105540409134"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1355434014138"><a name="p1355434014138"></a><a name="p1355434014138"></a>const std::shared_ptr&lt;StreamSource&gt; &amp;GetSourceStream() const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p455415408132"><a name="p455415408132"></a><a name="p455415408132"></a>Obtains information about the media source stream.</p>
</td>
</tr>
<tr id="row19135971706"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p257064871110"><a name="p257064871110"></a><a name="p257064871110"></a>Source</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p151191016151214"><a name="p151191016151214"></a><a name="p151191016151214"></a>const Format &amp;GetSourceStreamFormat() const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p14257126131210"><a name="p14257126131210"></a><a name="p14257126131210"></a>Obtains the media source stream format.</p>
</td>
</tr>
<tr id="row1543179104"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p255412409135"><a name="p255412409135"></a><a name="p255412409135"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p655454001314"><a name="p655454001314"></a><a name="p655454001314"></a>bool PutIntValue(const std::string &amp;key, int32_t value);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p205661711619"><a name="p205661711619"></a><a name="p205661711619"></a>Sets metadata of the integer type.</p>
</td>
</tr>
<tr id="row695314111204"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p655454019138"><a name="p655454019138"></a><a name="p655454019138"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1554840111319"><a name="p1554840111319"></a><a name="p1554840111319"></a>bool PutLongValue(const std::string &amp;key, int64_t value);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p230317337163"><a name="p230317337163"></a><a name="p230317337163"></a>Sets metadata of the long integer type.</p>
</td>
</tr>
<tr id="row3518133213019"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1855434031312"><a name="p1855434031312"></a><a name="p1855434031312"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p1555484014139"><a name="p1555484014139"></a><a name="p1555484014139"></a>bool PutFloatValue(const std::string &amp;key, float value);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p12391147111614"><a name="p12391147111614"></a><a name="p12391147111614"></a>Sets metadata of the single-precision floating-point type.</p>
</td>
</tr>
<tr id="row176434351308"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p655534031317"><a name="p655534031317"></a><a name="p655534031317"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p5555640111320"><a name="p5555640111320"></a><a name="p5555640111320"></a>bool PutDoubleValue(const std::string &amp;key, double value);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p185881525191711"><a name="p185881525191711"></a><a name="p185881525191711"></a>Sets metadata of the double-precision floating-point type.</p>
</td>
</tr>
<tr id="row9476163810013"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p3555154017133"><a name="p3555154017133"></a><a name="p3555154017133"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p3555124015133"><a name="p3555124015133"></a><a name="p3555124015133"></a>bool PutStringValue(const std::string &amp;key, const std::string &amp;value);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p16021743131719"><a name="p16021743131719"></a><a name="p16021743131719"></a>Sets metadata of the string type.</p>
</td>
</tr>
<tr id="row879515406015"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p15551540181313"><a name="p15551540181313"></a><a name="p15551540181313"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p19555164041313"><a name="p19555164041313"></a><a name="p19555164041313"></a>bool GetIntValue(const std::string &amp;key, int32_t &amp;value) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p435725714171"><a name="p435725714171"></a><a name="p435725714171"></a>Obtains the metadata value of the integer type.</p>
</td>
</tr>
<tr id="row462919431104"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1655544021318"><a name="p1655544021318"></a><a name="p1655544021318"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p0555194031314"><a name="p0555194031314"></a><a name="p0555194031314"></a>bool GetLongValue(const std::string &amp;key, int64_t &amp;value) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p7330132141811"><a name="p7330132141811"></a><a name="p7330132141811"></a>Obtains the metadata value of the long integer type.</p>
</td>
</tr>
<tr id="row1797513451904"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1655624011319"><a name="p1655624011319"></a><a name="p1655624011319"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p155567401134"><a name="p155567401134"></a><a name="p155567401134"></a>bool GetFloatValue(const std::string &amp;key, float &amp;value) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p080203817189"><a name="p080203817189"></a><a name="p080203817189"></a>Obtains the metadata value of the single-precision floating-point type.</p>
</td>
</tr>
<tr id="row012319491603"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p855694013132"><a name="p855694013132"></a><a name="p855694013132"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p10556124015132"><a name="p10556124015132"></a><a name="p10556124015132"></a>bool GetDoubleValue(const std::string &amp;key, double &amp;value) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p116117558189"><a name="p116117558189"></a><a name="p116117558189"></a>Obtains the metadata value of the double-precision floating-point type.</p>
</td>
</tr>
<tr id="row22531651901"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p1855604081314"><a name="p1855604081314"></a><a name="p1855604081314"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p9556840171310"><a name="p9556840171310"></a><a name="p9556840171310"></a>bool GetStringValue(const std::string &amp;key, std::string &amp;value) const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p6495161451914"><a name="p6495161451914"></a><a name="p6495161451914"></a>Obtains the metadata value of the string type.</p>
</td>
</tr>
<tr id="row552743019"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p165563405133"><a name="p165563405133"></a><a name="p165563405133"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p4556134061315"><a name="p4556134061315"></a><a name="p4556134061315"></a>const std::map&lt;std::string, FormatData *&gt; &amp;GetFormatMap() const;</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p4933161261817"><a name="p4933161261817"></a><a name="p4933161261817"></a>Obtains the metadata map.</p>
</td>
</tr>
<tr id="row127651251115"><td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.2.4.1.1 "><p id="p16556240111315"><a name="p16556240111315"></a><a name="p16556240111315"></a>Format</p>
</td>
<td class="cellrowborder" valign="top" width="47.77%" headers="mcps1.2.4.1.2 "><p id="p195561240111317"><a name="p195561240111317"></a><a name="p195561240111317"></a>bool CopyFrom(const Format &amp;format);</p>
</td>
<td class="cellrowborder" valign="top" width="36.27%" headers="mcps1.2.4.1.3 "><p id="p185953195717"><a name="p185953195717"></a><a name="p185953195717"></a>Sets all metadata to a specified format.</p>
</td>
</tr>
</tbody>
</table>

## Limitations and Constraints<a name="section1165911177314"></a>

When the input source is a media stream, the playback progress cannot be controlled and the file duration cannot be obtained.

## How to Develop<a name="section34171333656"></a>

1.  Implement a  **PlayerCallback**  function, register the callback via  **SetPlayerCallback**  for event processing.

    ```
    class TestPlayerCallback : public PlayerCallback{ 
        void OnPlaybackComplete() override 
        { 
            // Process the event that the file playback is complete.
        } 
        void OnError(int32_t errorType, int32_t errorCode) override 
        { 
            // Process the error event.
        } 
        void OnInfo(int type, int extra) override 
        { 
            // Process a common event.
        } 
        void OnRewindToComplete() override 
        { 
            // Process the event that playback position is changed.
        } 
    };
    
    ```

2.  Create a  **Player**  instance, set the playback source, and start playback.

    ```
    Player *player = new Player(); 
    std::shared_ptr<PlayerCallback> callback = std::make_shared<TestPlayerCallback>(); 
    player->SetPlayerCallback(callback);// Set a player callback.
    std::string uri(filePath);// filePath is a local file path.
    Source source(uri);// Create a Source instance and save the URI to the instance.
    player->SetSource(source);// Set the Source instance to the player.
    player->Prepare(); // Prepare for the playback.
    player->SetVideoSurface(surface);// Set the playback surface.
    player->Play(); // Start playback.
    ```

3.  Control the playback as needed.

    ```
    player->SetVolume(lvolume, rvolume);// Set volume for left and right channels.
    player->EnableSingleLooping(true);// Enable loop playback.
    player->Pause(); // Pause playback.
    player->Play(); // Resume playing.
    ```

4.  Release resources after the playback is complete.

    ```
    player->Stop(); // Stop playback.
    player->Release(); // Release resources.
    ```


