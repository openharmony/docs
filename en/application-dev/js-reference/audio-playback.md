# Audio Playback<a name="EN-US_TOPIC_0000001103383404"></a>

-   [Modules to Import](#s56d19203690d4782bfc74069abb6bd71)
-   [Required Permissions](#section11257113618419)
-   [Methods](#section125675489541)
-   [createAudioPlayer\(\)](#section582314017253)
-   [Appendixes](#section1933416317165)
-   [AudioPlayer](#section5174142818365)
    -   [Attributes](#section4947115405)
    -   [play\(\)](#section964512672913)
    -   [pause\(\)](#section78173258296)
    -   [stop\(\)](#section122114334296)
    -   [seek\(number\)](#section1387113816298)
    -   [setVolume\(number\)](#section164235176552)
    -   [reset\(\)7+](#section1473283011356)
    -   [release\(\)](#section9224621145512)
    -   [Events](#section5453721192911)
    -   [play](#section87307411494)
    -   [pause](#section198217471590)
    -   [stop](#section437616531910)
    -   [dataLoad](#section982114219106)
    -   [timeUpdate](#section13687114181014)
    -   [volumeChange](#section139227715717)
    -   [finish](#section15181321181018)
    -   [error](#section5593132921016)

-   [AudioState](#section5181155710523)

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import audio from '@ohos.multimedia.media';
```

## Required Permissions<a name="section11257113618419"></a>

None

## Methods<a name="section125675489541"></a>

## createAudioPlayer\(\)<a name="section582314017253"></a>

Creates an  **AudioPlayer**  instance to control audio playback.

**Return Values**

<a name="table482411406254"></a>
<table><thead align="left"><tr id="row138241940172518"><th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.3.1.1"><p id="p28256407257"><a name="p28256407257"></a><a name="p28256407257"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.95%" id="mcps1.1.3.1.2"><p id="p1582544017256"><a name="p1582544017256"></a><a name="p1582544017256"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0825540192520"><td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.3.1.1 "><p id="p482574042511"><a name="p482574042511"></a><a name="p482574042511"></a><a href="#section5174142818365">AudioPlayer</a></p>
</td>
<td class="cellrowborder" valign="top" width="83.95%" headers="mcps1.1.3.1.2 "><p id="p14825194014258"><a name="p14825194014258"></a><a name="p14825194014258"></a>Returns the <strong id="b1322434113810"><a name="b1322434113810"></a><a name="b1322434113810"></a>AudioPlayer</strong> instance if the operation is successful; returns <strong id="b114701838153811"><a name="b114701838153811"></a><a name="b114701838153811"></a>null</strong> otherwise.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
var audioplayer = audio.createAudioPlayer(); 
```

## Appendixes<a name="section1933416317165"></a>

## AudioPlayer<a name="section5174142818365"></a>

Represents an audio player.

### Attributes<a name="section4947115405"></a>

<a name="table92548495595"></a>
<table><thead align="left"><tr id="row132541749175917"><th class="cellrowborder" valign="top" width="15.8015801580158%" id="mcps1.1.6.1.1"><p id="p925404965919"><a name="p925404965919"></a><a name="p925404965919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.591959195919593%" id="mcps1.1.6.1.2"><p id="p325464914599"><a name="p325464914599"></a><a name="p325464914599"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.660766076607661%" id="mcps1.1.6.1.3"><p id="p025484918596"><a name="p025484918596"></a><a name="p025484918596"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.29082908290829%" id="mcps1.1.6.1.4"><p id="p025414499590"><a name="p025414499590"></a><a name="p025414499590"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="48.65486548654865%" id="mcps1.1.6.1.5"><p id="p20254134925912"><a name="p20254134925912"></a><a name="p20254134925912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18254849155915"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="p20254204935915"><a name="p20254204935915"></a><a name="p20254204935915"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="p1525413497591"><a name="p1525413497591"></a><a name="p1525413497591"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="p8254749195914"><a name="p8254749195914"></a><a name="p8254749195914"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="p5255549115910"><a name="p5255549115910"></a><a name="p5255549115910"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="p72551449145914"><a name="p72551449145914"></a><a name="p72551449145914"></a>URI of the audio resources</p>
</td>
</tr>
<tr id="row10255134945917"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="p82551349125910"><a name="p82551349125910"></a><a name="p82551349125910"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="p18255154913598"><a name="p18255154913598"></a><a name="p18255154913598"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="p525516497595"><a name="p525516497595"></a><a name="p525516497595"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="p2025504917593"><a name="p2025504917593"></a><a name="p2025504917593"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="p7255194925919"><a name="p7255194925919"></a><a name="p7255194925919"></a>Whether to loop audio playback</p>
</td>
</tr>
<tr id="row18256049165911"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="p2256154919590"><a name="p2256154919590"></a><a name="p2256154919590"></a>currentTime</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="p10256849165915"><a name="p10256849165915"></a><a name="p10256849165915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="p19256149155915"><a name="p19256149155915"></a><a name="p19256149155915"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="p3256174935919"><a name="p3256174935919"></a><a name="p3256174935919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="p12256144995913"><a name="p12256144995913"></a><a name="p12256144995913"></a>Current playback position</p>
</td>
</tr>
<tr id="row11256144911598"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="p92561949125910"><a name="p92561949125910"></a><a name="p92561949125910"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="p9256124914597"><a name="p9256124914597"></a><a name="p9256124914597"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="p1725654915911"><a name="p1725654915911"></a><a name="p1725654915911"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="p192562049125910"><a name="p192562049125910"></a><a name="p192562049125910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="p125684995913"><a name="p125684995913"></a><a name="p125684995913"></a>Playback duration</p>
</td>
</tr>
<tr id="row6256149115920"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="p2256144918596"><a name="p2256144918596"></a><a name="p2256144918596"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="p9256144918593"><a name="p9256144918593"></a><a name="p9256144918593"></a><a href="#section5181155710523">AudioState</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="p102563495592"><a name="p102563495592"></a><a name="p102563495592"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="p625620497594"><a name="p625620497594"></a><a name="p625620497594"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="p162571549195920"><a name="p162571549195920"></a><a name="p162571549195920"></a>Playback status</p>
</td>
</tr>
</tbody>
</table>

### play\(\)<a name="section964512672913"></a>

Starts audio playback.

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.info('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to play the audio.');
  audioplayer.play();
};

audioplayer.on('play', (err, action) => {
  if (err) {
     console.info('Error returned in the play() callback.');
     return;
  }
  console.info('Succeeded in playing the audio.');
};
audioplayer.src = 'common/mydream.mp3';
```

### pause\(\)<a name="section78173258296"></a>

Pauses audio playback.

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.info('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to play the audio.');
  audioplayer.play();
}
audioplayer.on('play', (err, action) => {
  if (err) {
     console.info('Error returned in the play() callback.');
     return;
  }
  console.info('Start to pause audio playback.');
  audioplayer.pause();
};
audioplayer.on('pause', (err, action) => {
  if (err) {
     console.info('Error returned in the pause() callback.');
     return;
  }
  console.info('Succeeded in pausing audio playback.');
};
audioplayer.src = 'common/mydream.mp3';
```

### stop\(\)<a name="section122114334296"></a>

Stops audio playback.

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.info('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to play the audio.');
  audioplayer.play();
};
audioplayer.on('play', (err, action) => {
  if (err) {
     console.info('Error returned in the play() callback.');
     return;
  }
  console.info('Start to pause audio playback.');
  audioplayer.pause();
};
audioplayer.on('stop', (err, action) => {
  if (err) {
     console.info('Error returned in the stop() callback.');
     return;
  }
  console.info('Succeeded in stopping audio playback.');
};
audioplayer.src = 'common/mydream.mp3';
```

### seek\(number\)<a name="section1387113816298"></a>

Goes to a specified playback position.

**Parameters**

<a name="table1442723852917"></a>
<table><thead align="left"><tr id="row84261138172911"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p204261938182919"><a name="p204261938182919"></a><a name="p204261938182919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="p1342683842920"><a name="p1342683842920"></a><a name="p1342683842920"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p134260383297"><a name="p134260383297"></a><a name="p134260383297"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="p442663832912"><a name="p442663832912"></a><a name="p442663832912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18427738202910"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p184261338192913"><a name="p184261338192913"></a><a name="p184261338192913"></a>timeMs</p>
</td>
<td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="p1242643819295"><a name="p1242643819295"></a><a name="p1242643819295"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p44261838112918"><a name="p44261838112918"></a><a name="p44261838112918"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="p16427163812913"><a name="p16427163812913"></a><a name="p16427163812913"></a>Target playback position</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.info('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to play the audio.');
  audioplayer.play();
};
audioplayer.on('play', (err, action) => {
  if (err) {
     console.info('Error returned in the play() callback.');
     return;
  }
  console.info('Succeeded in playing the audio.')
};
audioplayer.on('timeUpdate', (seekTime, action) => {
  console.info('Seek time returned in the seek() callback: ' + seekTime);
  var newTime = audioplayer.currenTime;
  if(newTime == 30000) {
    console.info('Seek succeeded. New time: ' + newTime);
  } else {
    console.info('Seek failed.');
  }
};
audioplayer.src = 'common/mydream.mp3';
audioplayer.seek(30000);
```

### setVolume\(number\)<a name="section164235176552"></a>

Sets the volume.

**Parameters**

<a name="table1242391713555"></a>
<table><thead align="left"><tr id="row14424217195517"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1424917135519"><a name="p1424917135519"></a><a name="p1424917135519"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="p10424121795520"><a name="p10424121795520"></a><a name="p10424121795520"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1042415178559"><a name="p1042415178559"></a><a name="p1042415178559"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="p13424717125513"><a name="p13424717125513"></a><a name="p13424717125513"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13424171745513"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p204241517125517"><a name="p204241517125517"></a><a name="p204241517125517"></a>vol</p>
</td>
<td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="p18424121755517"><a name="p18424121755517"></a><a name="p18424121755517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p2042417176554"><a name="p2042417176554"></a><a name="p2042417176554"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="p9424171717557"><a name="p9424171717557"></a><a name="p9424171717557"></a>Volume to set. The value ranges from 0 to 1.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.error('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to play the audio.');
  audioplayer.play();
};
audioplayer.on('play', (err, action) => {
  if (err) {
     console.error('Error returned in the play() callback.');
     return;
  }
  console.info('Succeeded in playing the audio.')
};
audioplayer.on('volumeChange', (err, action) => {
  if (err) {
     console.error('Error returned in the setVolume() callback.');
     return;
  }
  console.info('Playback volume changed.');
};
audioplayer.src = 'common/mydream.mp3';
audioplayer.setVolume(0.5);
```

### reset\(\)<sup>7+</sup><a name="section1473283011356"></a>

Switches the audio resource to be played.

**Example**

```
audioplayer.on('dataload', (err, action) => {
  if (err) {
     console.error('Error returned in the prepare() callback.');
     return;
  }
  console.info('Start to reset audio playback.');
  audioplayer.reset();
};
audioplayer.on('reset', (err, action) => {
  if (err) {
     console.error('Error returned in the reset() callback.');
     return;
  }
  console.info('Reset succeeded.');
};
audioplayer.src = 'common/mydream.mp3';
```

### release\(\)<a name="section9224621145512"></a>

Releases audio resources.

**Example**

```
audioplay.release();
```

### Events<a name="section5453721192911"></a>

### play<a name="section87307411494"></a>

Triggered when  **play\(\)**  is called

### pause<a name="section198217471590"></a>

Triggered when  **pause\(\)**  is called

### stop<a name="section437616531910"></a>

Triggered when  **stop\(\)**  is called

### dataLoad<a name="section982114219106"></a>

Triggered when audio data is loaded

### timeUpdate<a name="section13687114181014"></a>

Triggered when the playback position changes

### volumeChange<a name="section139227715717"></a>

Triggered when playback volume changes

### finish<a name="section15181321181018"></a>

Triggered when playback is finished

### error<a name="section5593132921016"></a>

Triggered when a playback error occurs

<a name="table24591722143619"></a>
<table><thead align="left"><tr id="row1945962219364"><th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.1.4.1.1"><p id="p84591522103610"><a name="p84591522103610"></a><a name="p84591522103610"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.25%" id="mcps1.1.4.1.2"><p id="p11459102243616"><a name="p11459102243616"></a><a name="p11459102243616"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="p14591922113616"><a name="p14591922113616"></a><a name="p14591922113616"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2459622183611"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="p17338122234119"><a name="p17338122234119"></a><a name="p17338122234119"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="p174601822193612"><a name="p174601822193612"></a><a name="p174601822193612"></a>ErrorCallback</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p7460222123612"><a name="p7460222123612"></a><a name="p7460222123612"></a>Callback function for handling this event</p>
</td>
</tr>
</tbody>
</table>

## AudioState<a name="section5181155710523"></a>

Describes playback status.

<a name="table919114616314"></a>
<table><thead align="left"><tr id="row31917610318"><th class="cellrowborder" valign="top" width="33.739999999999995%" id="mcps1.1.3.1.1"><p id="p219196531"><a name="p219196531"></a><a name="p219196531"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="66.25999999999999%" id="mcps1.1.3.1.2"><p id="p14191563313"><a name="p14191563313"></a><a name="p14191563313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3427194315719"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="p642711431172"><a name="p642711431172"></a><a name="p642711431172"></a>idle</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="p24281543777"><a name="p24281543777"></a><a name="p24281543777"></a>Audio playback is idle.</p>
</td>
</tr>
<tr id="row2019146539"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="p201913617311"><a name="p201913617311"></a><a name="p201913617311"></a>playing</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="p81911362316"><a name="p81911362316"></a><a name="p81911362316"></a>The audio is being played.</p>
</td>
</tr>
<tr id="row11912612316"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="p9191136731"><a name="p9191136731"></a><a name="p9191136731"></a>paused</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="p419166738"><a name="p419166738"></a><a name="p419166738"></a>Audio playback is paused.</p>
</td>
</tr>
<tr id="row111912617314"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="p9191156333"><a name="p9191156333"></a><a name="p9191156333"></a>stopped</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="p2019215618316"><a name="p2019215618316"></a><a name="p2019215618316"></a>Audio playback is stopped.</p>
</td>
</tr>
</tbody>
</table>

