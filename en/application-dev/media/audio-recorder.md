# Audio Recording Development<a name="EN-US_TOPIC_0000001163844398"></a>

## When to Use<a name="section910413166166"></a>

During audio recording, audio signals are recorded and saved. You can set the sampling rate, number of audio channels, bit rate, encoding format, encapsulation format, and file path for audio recording.

## Available APIs<a name="section1225204317126"></a>

**Table  1**  APIs for audio recording

<a name="table17619171017258"></a>
<table><thead align="left"><tr id="row9619111017256"><th class="cellrowborder" valign="top" width="42.29%" id="mcps1.2.3.1.1"><p id="p19739153111253"><a name="p19739153111253"></a><a name="p19739153111253"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.709999999999994%" id="mcps1.2.3.1.2"><p id="p761918101259"><a name="p761918101259"></a><a name="p761918101259"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row186191310102518"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p152227722614"><a name="p152227722614"></a><a name="p152227722614"></a>media.createAudioRecorder()</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p11619510202511"><a name="p11619510202511"></a><a name="p11619510202511"></a>Creates an <strong id="b114853895016"><a name="b114853895016"></a><a name="b114853895016"></a>AudioRecorder</strong> instance.</p>
</td>
</tr>
<tr id="row78247183285"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p78241186287"><a name="p78241186287"></a><a name="p78241186287"></a><a href="#table3407174718274">AudioRecorder</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p1382410184281"><a name="p1382410184281"></a><a name="p1382410184281"></a>Provides audio recording methods.</p>
</td>
</tr>
<tr id="row14556918192315"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p355791892318"><a name="p355791892318"></a><a name="p355791892318"></a><a href="#table27151637152218">AudioRecorderConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p1855713186239"><a name="p1855713186239"></a><a name="p1855713186239"></a>Provides parameters related to audio recording.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  AudioRecorder methods

<a name="table3407174718274"></a>
<table><thead align="left"><tr id="row640744712719"><th class="cellrowborder" valign="top" width="42.980000000000004%" id="mcps1.2.3.1.1"><p id="p1540794717271"><a name="p1540794717271"></a><a name="p1540794717271"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="57.02%" id="mcps1.2.3.1.2"><p id="p14407204712274"><a name="p14407204712274"></a><a name="p14407204712274"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12408104792716"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p207548103229"><a name="p207548103229"></a><a name="p207548103229"></a>prepare(config: AudioRecorderConfig): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p45511713162216"><a name="p45511713162216"></a><a name="p45511713162216"></a>Prepares for audio recording and sets parameters.</p>
</td>
</tr>
<tr id="row84081747182715"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p174086470278"><a name="p174086470278"></a><a name="p174086470278"></a>start(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p14552121332211"><a name="p14552121332211"></a><a name="p14552121332211"></a>Starts audio recording.</p>
</td>
</tr>
<tr id="row184082047132717"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p675201017227"><a name="p675201017227"></a><a name="p675201017227"></a>pause(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1854914138228"><a name="p1854914138228"></a><a name="p1854914138228"></a>Pauses audio recording. (Not supported yet)</p>
</td>
</tr>
<tr id="row93063645415"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1775111102227"><a name="p1775111102227"></a><a name="p1775111102227"></a>resume(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p14548313122218"><a name="p14548313122218"></a><a name="p14548313122218"></a>Resumes audio recording. (Not supported yet)</p>
</td>
</tr>
<tr id="row36221450105715"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1575061019226"><a name="p1575061019226"></a><a name="p1575061019226"></a>stop(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p154771342219"><a name="p154771342219"></a><a name="p154771342219"></a>Stops audio recording.</p>
</td>
</tr>
<tr id="row1240804752711"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p137492010162214"><a name="p137492010162214"></a><a name="p137492010162214"></a>release(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p854671312228"><a name="p854671312228"></a><a name="p854671312228"></a>Releases audio recording resources.</p>
</td>
</tr>
<tr id="row5408194714279"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p974821019225"><a name="p974821019225"></a><a name="p974821019225"></a>reset(): void</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1554551342219"><a name="p1554551342219"></a><a name="p1554551342219"></a>Resets audio recording.</p>
</td>
</tr>
<tr id="row44091647192718"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p18937155862412"><a name="p18937155862412"></a><a name="p18937155862412"></a>on('prepare', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p13409164722717"><a name="p13409164722717"></a><a name="p13409164722717"></a>Subscribes to the audio recording preparation event.</p>
</td>
</tr>
<tr id="row12409154711272"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p124091474279"><a name="p124091474279"></a><a name="p124091474279"></a>on('start', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p7409174714274"><a name="p7409174714274"></a><a name="p7409174714274"></a>Subscribes to the audio recording start event.</p>
</td>
</tr>
<tr id="row040917477273"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p18981171411254"><a name="p18981171411254"></a><a name="p18981171411254"></a>on('pause', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1409164772714"><a name="p1409164772714"></a><a name="p1409164772714"></a>Subscribes to the audio recording pause event.</p>
</td>
</tr>
<tr id="row712184163016"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1167517115311"><a name="p1167517115311"></a><a name="p1167517115311"></a>on('resume', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1113134115301"><a name="p1113134115301"></a><a name="p1113134115301"></a>Subscribes to the audio recording resumption event.</p>
</td>
</tr>
<tr id="row11409747202711"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p189901420102514"><a name="p189901420102514"></a><a name="p189901420102514"></a>on('stop',function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p8410124742713"><a name="p8410124742713"></a><a name="p8410124742713"></a>Subscribes to the audio recording end event.</p>
</td>
</tr>
<tr id="row64105474278"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p166588276253"><a name="p166588276253"></a><a name="p166588276253"></a>on('release', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p54101047102712"><a name="p54101047102712"></a><a name="p54101047102712"></a>Subscribes to the event of releasing audio recording resources.</p>
</td>
</tr>
<tr id="row1410154715273"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p135217361257"><a name="p135217361257"></a><a name="p135217361257"></a>on('reset', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1541054719271"><a name="p1541054719271"></a><a name="p1541054719271"></a>Subscribes to the audio recording reset event.</p>
</td>
</tr>
<tr id="row126521548145814"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p2652134812586"><a name="p2652134812586"></a><a name="p2652134812586"></a>on('error', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p116527483584"><a name="p116527483584"></a><a name="p116527483584"></a>Subscribes to the audio recording error event.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  AudioRecorderConfig

<a name="table27151637152218"></a>
<table><thead align="left"><tr id="row14715123712210"><th class="cellrowborder" valign="top" width="42.29%" id="mcps1.2.3.1.1"><p id="p6715123732219"><a name="p6715123732219"></a><a name="p6715123732219"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.709999999999994%" id="mcps1.2.3.1.2"><p id="p16715123712212"><a name="p16715123712212"></a><a name="p16715123712212"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row47151137112219"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p1568214420266"><a name="p1568214420266"></a><a name="p1568214420266"></a>audioEncoder?: <a href="#table104591279272">AudioEncoder</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p17715173772211"><a name="p17715173772211"></a><a name="p17715173772211"></a>Audio encoding format. The default value is <strong id="b14896101415519"><a name="b14896101415519"></a><a name="b14896101415519"></a>AAC_LC</strong>.</p>
</td>
</tr>
<tr id="row67151337152214"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p167591344132312"><a name="p167591344132312"></a><a name="p167591344132312"></a>audioEncodeBitRate?: number</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p20715537112211"><a name="p20715537112211"></a><a name="p20715537112211"></a>Bit rate for audio encoding. The default value is <strong id="b1433419231554"><a name="b1433419231554"></a><a name="b1433419231554"></a>48000</strong>.</p>
</td>
</tr>
<tr id="row16715637152212"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p141241772714"><a name="p141241772714"></a><a name="p141241772714"></a>audioSampleRate?: number</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p15991111611271"><a name="p15991111611271"></a><a name="p15991111611271"></a>Sampling rate for audio encoding. The default value is <strong id="b11540104210555"><a name="b11540104210555"></a><a name="b11540104210555"></a>48000</strong>.</p>
</td>
</tr>
<tr id="row1453682316356"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p205375231352"><a name="p205375231352"></a><a name="p205375231352"></a>numberOfChannels?: number</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p7537102393512"><a name="p7537102393512"></a><a name="p7537102393512"></a>Number of audio channels. The default value is <strong id="b1437255075515"><a name="b1437255075515"></a><a name="b1437255075515"></a>2</strong>.</p>
</td>
</tr>
<tr id="row10719112912355"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p16719132917355"><a name="p16719132917355"></a><a name="p16719132917355"></a>format?: <a href="#table585044112375">AudioOutputFormat</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p6719182923513"><a name="p6719182923513"></a><a name="p6719182923513"></a>Audio output format. The default value is <strong id="b1290655565511"><a name="b1290655565511"></a><a name="b1290655565511"></a>MPEG_4</strong>.</p>
</td>
</tr>
<tr id="row0918827163516"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p1991815270351"><a name="p1991815270351"></a><a name="p1991815270351"></a>uri: string</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p14918142711351"><a name="p14918142711351"></a><a name="p14918142711351"></a>Audio output path, which starts with <strong id="b148591619165613"><a name="b148591619165613"></a><a name="b148591619165613"></a>file://path</strong> or <strong id="b421882325615"><a name="b421882325615"></a><a name="b421882325615"></a>file://fd</strong>.</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  AudioEncoder

<a name="table104591279272"></a>
<table><thead align="left"><tr id="row8459427122719"><th class="cellrowborder" valign="top" width="42.29%" id="mcps1.2.3.1.1"><p id="p124591927192720"><a name="p124591927192720"></a><a name="p124591927192720"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.709999999999994%" id="mcps1.2.3.1.2"><p id="p1459152720276"><a name="p1459152720276"></a><a name="p1459152720276"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6467142013014"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p5467152073014"><a name="p5467152073014"></a><a name="p5467152073014"></a>AAC_LC = 3</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p1468162093010"><a name="p1468162093010"></a><a name="p1468162093010"></a>AAC_LC format.</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  AudioOutputFormat

<a name="table585044112375"></a>
<table><thead align="left"><tr id="row16850841183712"><th class="cellrowborder" valign="top" width="42.29%" id="mcps1.2.3.1.1"><p id="p785094123715"><a name="p785094123715"></a><a name="p785094123715"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.709999999999994%" id="mcps1.2.3.1.2"><p id="p158504412378"><a name="p158504412378"></a><a name="p158504412378"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2085115412379"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p1851641143711"><a name="p1851641143711"></a><a name="p1851641143711"></a>MPEG_4 = 2</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p385174163718"><a name="p385174163718"></a><a name="p385174163718"></a>MPEG-4 format.</p>
</td>
</tr>
<tr id="row485118415378"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p13851241123719"><a name="p13851241123719"></a><a name="p13851241123719"></a>AAC_ADTS= 6</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p885118412377"><a name="p885118412377"></a><a name="p885118412377"></a>AAC_ADTS format.</p>
</td>
</tr>
</tbody>
</table>

1.  Create an audio recorder.

    ```
    import media from '@ohos.multimedia.media';
    var recorder = media.createAudioRecorder();
    ```

2.  Prepare for audio recording and set parameters.

    ```
    let audioRecorderConfig = {
        audioEncoder : AAC_LC ,
        audioEncodeBitRate : 22050,
        audioSampleRate : 22050,
        numberOfChannels : 2,
        format : AAC_ADTS,
        uri : 'file:///data/accounts/account_0/appdata/appdata/recorder/test.m4a',
    }
    recorder.prepare(audioRecorderConfig);
    ```

3.  Set the subscription events.

    ```
    recorder.on('prepare', () => {
        console.info('setCallback prepare() case callback is called');
        recorder.start();
    });
    recorder.on('start', () => {
        console.info('setCallback start() case callback is called');
        setTimeout(function(){
           recorder.pause();
        }, 10000); // Pause recording 10 seconds after the recording starts.
    });
    recorder.on('pause', () => {
        console.info('setCallback pause() case callback is called');
        setTimeout(function(){
           recorder.resume(); 
        }, 10000); // Resume recording 10 seconds after the recording is paused.
    });
    recorder.on('resume', () => {
        console.info('setCallback resume() case callback is called');
        setTimeout(function(){
           recorder.stop();
        }, 10000); // Stop recording 10 seconds after the recording is resumed.
    });
    recorder.on('stop', () => {
        console.info('setCallback stop() case callback is called');
        recorder.release();
    });
    recorder.on('release', () => {
         console.info('setCallback release() case callback is called');
    });
    recorder.on('error', (err) => {
         console.info(`case error called,errCode is ${err.code}`);
         console.info(`case error called,errMessage is ${err.message}`);
         recorder.reset();
    });
    ```


