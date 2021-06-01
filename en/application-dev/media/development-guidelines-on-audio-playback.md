# Development Guidelines on Audio Playback<a name="EN-US_TOPIC_0000001100255784"></a>

-   [When to Use](#section910413166166)
-   [Available APIs](#section1225204317126)

## When to Use<a name="section910413166166"></a>

You use audio playback APIs to convert audio data into audible analog signals, play the audio signals using output devices, and manage playback tasks.

**Figure  1**  Playback status<a name="fig19537218164010"></a>  
![](figures/playback-status.png "playback-status")

## Available APIs<a name="section1225204317126"></a>

**Table  1**  media

<a name="table17619171017258"></a>
<table><thead align="left"><tr id="row9619111017256"><th class="cellrowborder" valign="top" width="42.29%" id="mcps1.2.3.1.1"><p id="p19739153111253"><a name="p19739153111253"></a><a name="p19739153111253"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.709999999999994%" id="mcps1.2.3.1.2"><p id="p761918101259"><a name="p761918101259"></a><a name="p761918101259"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row186191310102518"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p152227722614"><a name="p152227722614"></a><a name="p152227722614"></a>media.createAudioPlayer()</p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p11619510202511"><a name="p11619510202511"></a><a name="p11619510202511"></a>Creates an <strong id="b1189187131414"><a name="b1189187131414"></a><a name="b1189187131414"></a>AudioPlayer</strong> instance.</p>
</td>
</tr>
<tr id="row78247183285"><td class="cellrowborder" valign="top" width="42.29%" headers="mcps1.2.3.1.1 "><p id="p78241186287"><a name="p78241186287"></a><a name="p78241186287"></a><a href="#table3407174718274">AudioPlayer</a></p>
</td>
<td class="cellrowborder" valign="top" width="57.709999999999994%" headers="mcps1.2.3.1.2 "><p id="p1382410184281"><a name="p1382410184281"></a><a name="p1382410184281"></a>Provides audio playback methods.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  AudioPlayer

<a name="table3407174718274"></a>
<table><thead align="left"><tr id="row640744712719"><th class="cellrowborder" valign="top" width="42.980000000000004%" id="mcps1.2.3.1.1"><p id="p1540794717271"><a name="p1540794717271"></a><a name="p1540794717271"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="57.02%" id="mcps1.2.3.1.2"><p id="p14407204712274"><a name="p14407204712274"></a><a name="p14407204712274"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row540714712272"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p174086470278"><a name="p174086470278"></a><a name="p174086470278"></a>release()</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p204082047172719"><a name="p204082047172719"></a><a name="p204082047172719"></a>Releases audio resources.</p>
</td>
</tr>
<tr id="row12408104792716"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p640874762718"><a name="p640874762718"></a><a name="p640874762718"></a>play()</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1740894712718"><a name="p1740894712718"></a><a name="p1740894712718"></a>Starts audio playback.</p>
</td>
</tr>
<tr id="row84081747182715"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p04081947172716"><a name="p04081947172716"></a><a name="p04081947172716"></a>pause()</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p164081547132711"><a name="p164081547132711"></a><a name="p164081547132711"></a>Pauses playback.</p>
</td>
</tr>
<tr id="row184082047132717"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p74086479279"><a name="p74086479279"></a><a name="p74086479279"></a>stop()</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1140814471274"><a name="p1140814471274"></a><a name="p1140814471274"></a>Stops playback.</p>
</td>
</tr>
<tr id="row36221450105715"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p162210506572"><a name="p162210506572"></a><a name="p162210506572"></a>setVolume(vol: number)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p166221550165720"><a name="p166221550165720"></a><a name="p166221550165720"></a>Sets playback volume.</p>
</td>
</tr>
<tr id="row1240804752711"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p8408647172716"><a name="p8408647172716"></a><a name="p8408647172716"></a>seek(timeMs: number)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p440817478271"><a name="p440817478271"></a><a name="p440817478271"></a>Changes the playback position.</p>
</td>
</tr>
<tr id="row5408194714279"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p144081547102712"><a name="p144081547102712"></a><a name="p144081547102712"></a>src:string</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1040814782716"><a name="p1040814782716"></a><a name="p1040814782716"></a>Defines the URI of an audio file to play.</p>
</td>
</tr>
<tr id="row155026127182"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p5503812121819"><a name="p5503812121819"></a><a name="p5503812121819"></a>state:string</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p105031612141811"><a name="p105031612141811"></a><a name="p105031612141811"></a>Defines a playback state.</p>
</td>
</tr>
<tr id="row19408114732719"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p12209729141817"><a name="p12209729141817"></a><a name="p12209729141817"></a>autoplay:boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p19189929171811"><a name="p19189929171811"></a><a name="p19189929171811"></a>Defines whether playback starts automatically.</p>
</td>
</tr>
<tr id="row340854714273"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1840914712277"><a name="p1840914712277"></a><a name="p1840914712277"></a>currenttime:number</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p3409174762710"><a name="p3409174762710"></a><a name="p3409174762710"></a>Defines the current playback position.</p>
</td>
</tr>
<tr id="row6409134710274"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p114091047162711"><a name="p114091047162711"></a><a name="p114091047162711"></a>duration:number</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p154091247132715"><a name="p154091247132715"></a><a name="p154091247132715"></a>Defines the playback duration.</p>
</td>
</tr>
<tr id="row4409134772717"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p9681449141811"><a name="p9681449141811"></a><a name="p9681449141811"></a>loop:boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p94091847102711"><a name="p94091847102711"></a><a name="p94091847102711"></a>Defines whether to loop audio playback.</p>
</td>
</tr>
<tr id="row19915911171916"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p20915111121918"><a name="p20915111121918"></a><a name="p20915111121918"></a>muted:boolean</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p12915211131910"><a name="p12915211131910"></a><a name="p12915211131910"></a>Defines whether to mute the audio.</p>
</td>
</tr>
<tr id="row44091647192718"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p18937155862412"><a name="p18937155862412"></a><a name="p18937155862412"></a>on('play', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p13409164722717"><a name="p13409164722717"></a><a name="p13409164722717"></a>Listens for the playback start event.</p>
</td>
</tr>
<tr id="row12409154711272"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p124091474279"><a name="p124091474279"></a><a name="p124091474279"></a>on('pause', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p7409174714274"><a name="p7409174714274"></a><a name="p7409174714274"></a>Listens for the playback pause event.</p>
</td>
</tr>
<tr id="row040917477273"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p18981171411254"><a name="p18981171411254"></a><a name="p18981171411254"></a>on('stop', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1409164772714"><a name="p1409164772714"></a><a name="p1409164772714"></a>Listens for the playback stop event.</p>
</td>
</tr>
<tr id="row11409747202711"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p189901420102514"><a name="p189901420102514"></a><a name="p189901420102514"></a>on('ended',function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p8410124742713"><a name="p8410124742713"></a><a name="p8410124742713"></a>Listens for the playback end event.</p>
</td>
</tr>
<tr id="row64105474278"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p166588276253"><a name="p166588276253"></a><a name="p166588276253"></a>on('error', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p54101047102712"><a name="p54101047102712"></a><a name="p54101047102712"></a>Listens for the playback error event.</p>
</td>
</tr>
<tr id="row1410154715273"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p135217361257"><a name="p135217361257"></a><a name="p135217361257"></a>on('loaderdata', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p1541054719271"><a name="p1541054719271"></a><a name="p1541054719271"></a>Listens for the data loading event.</p>
</td>
</tr>
<tr id="row126521548145814"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p2652134812586"><a name="p2652134812586"></a><a name="p2652134812586"></a>on('volumeChange', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p116527483584"><a name="p116527483584"></a><a name="p116527483584"></a>Listens for the volume change event.</p>
</td>
</tr>
<tr id="row1410124732711"><td class="cellrowborder" valign="top" width="42.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p942310426254"><a name="p942310426254"></a><a name="p942310426254"></a>on('timeupdate', function callback)</p>
</td>
<td class="cellrowborder" valign="top" width="57.02%" headers="mcps1.2.3.1.2 "><p id="p18410144715271"><a name="p18410144715271"></a><a name="p18410144715271"></a>Listens for the progress change event.</p>
</td>
</tr>
</tbody>
</table>

1.  Create an audio player.

    ```
    var player = media.createAudioPlayer();
    ```

2.  Set the listeners.

    ```
    player.on('play', (err, action) => {
        if (err) {
            console.log(`err returned in play() callback`);
            return;
         }
         console.info('Current Song duration: '+duration);
         console.log(`In play callback current time: ${player.currentTime}`);
         console.info('Current Player Status: '+player.state);
         console.info('Pause Mp3');
         player.pause();
    });
    player.on('pause', (err, action) => {
         if (err) {
             console.log(`err returned in pause() callback`);
             return;
          }
          console.log(`pause callback, state: ${player.state}`);
          console.info('Current Player Status: '+player.state);
          var currentTime = player.currenTime;
          console.info('Current Player Time: '+currentTime);
          player.seek(30000); //seek for 30 seconds
    });
    player.on('stop', (err, action) => {
        if (err) {
            console.log(`err returned in stop() callback`);
            return;
        }
        console.log(`stop callback, state: ${player.state}`);
    });
    player.on('dataLoad', (err, action) => {
        if (err) {
            console.log(`err returned in dataLoad() callback`);
            return;
        }
         console.log(`dataLoad callback is called, current time: ${player.currentTime}`);
         console.log(`Duration of the source: ${player.duration}`);
    });
    player.on('finish', (err, action) => {
         if (err) {
            console.log(`err returned in finish() callback`);
            return;
         }
         console.log(`Player finish callback is called`);
    });
    player.on('timeUpdate', (err, action) => {
        if (err) {
            console.log(`err returned in timeUpdate() callback`);
            return;
        }
        console.log(`In timeupdate callback current time: ${player.currentTime}`);
        var newTime = player.currentTime;
        if(newTime = 30000) {
            console.info('Seek success, new time : '+newTime);
        } else {
            console.info('Seek Failed');
         }
            player.stop();
    });
    player.on('durationchange', (err, action) => {
         if (err) {
             console.log(`err returned in durationchange callback`);
             return;
         }
         console.log(`Durationchange callback is called`);
    });
    player.on('error', (err) => {
         console.error(`player error: ${err.message}`);
    });
    
    ```

3.  Start playback.

    ```
    var audioSourceMp3 = 'file://test.mp3';
    player.src = audioSourceMp3;
    player.loop = true;
    player.play();
    ```


