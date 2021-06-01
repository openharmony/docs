# Audio Playback<a name="EN-US_TOPIC_0000001115974764"></a>

-   [Modules to Import](#en-us_topic_0000001103383404_s56d19203690d4782bfc74069abb6bd71)
-   [Required Permissions](#en-us_topic_0000001103383404_section11257113618419)
-   [Methods](#en-us_topic_0000001103383404_section125675489541)
-   [createAudioPlayer\(\)](#en-us_topic_0000001103383404_section582314017253)
-   [Appendixes](#en-us_topic_0000001103383404_section1933416317165)
-   [AudioPlayer](#en-us_topic_0000001103383404_section5174142818365)
    -   [Attributes](#en-us_topic_0000001103383404_section4947115405)
    -   [play\(\)](#en-us_topic_0000001103383404_section964512672913)
    -   [pause\(\)](#en-us_topic_0000001103383404_section78173258296)
    -   [stop\(\)](#en-us_topic_0000001103383404_section122114334296)
    -   [seek\(number\)](#en-us_topic_0000001103383404_section1387113816298)
    -   [setVolume\(number\)](#en-us_topic_0000001103383404_section164235176552)
    -   [release\(\)](#en-us_topic_0000001103383404_section9224621145512)
    -   [Events](#en-us_topic_0000001103383404_section5453721192911)
    -   [play](#en-us_topic_0000001103383404_section87307411494)
    -   [pause](#en-us_topic_0000001103383404_section198217471590)
    -   [stop](#en-us_topic_0000001103383404_section437616531910)
    -   [dataLoad](#en-us_topic_0000001103383404_section982114219106)
    -   [timeUpdate](#en-us_topic_0000001103383404_section13687114181014)
    -   [volumeChange](#en-us_topic_0000001103383404_section139227715717)
    -   [finish](#en-us_topic_0000001103383404_section15181321181018)
    -   [error](#en-us_topic_0000001103383404_section5593132921016)

-   [AudioState](#en-us_topic_0000001103383404_section5181155710523)

## Modules to Import<a name="en-us_topic_0000001103383404_s56d19203690d4782bfc74069abb6bd71"></a>

```
import audio from '@ohos.multimedia.media';
```

## Required Permissions<a name="en-us_topic_0000001103383404_section11257113618419"></a>

None

## Methods<a name="en-us_topic_0000001103383404_section125675489541"></a>

## createAudioPlayer\(\)<a name="en-us_topic_0000001103383404_section582314017253"></a>

Creates an  **AudioPlayer**  instance to control audio playback.

**Return Values**

<a name="en-us_topic_0000001103383404_table482411406254"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row138241940172518"><th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001103383404_p28256407257"><a name="en-us_topic_0000001103383404_p28256407257"></a><a name="en-us_topic_0000001103383404_p28256407257"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.95%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001103383404_p1582544017256"><a name="en-us_topic_0000001103383404_p1582544017256"></a><a name="en-us_topic_0000001103383404_p1582544017256"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row0825540192520"><td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001103383404_p482574042511"><a name="en-us_topic_0000001103383404_p482574042511"></a><a name="en-us_topic_0000001103383404_p482574042511"></a><a href="#en-us_topic_0000001103383404_section5174142818365">AudioPlayer</a></p>
</td>
<td class="cellrowborder" valign="top" width="83.95%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001103383404_p14825194014258"><a name="en-us_topic_0000001103383404_p14825194014258"></a><a name="en-us_topic_0000001103383404_p14825194014258"></a>Returns the <strong id="en-us_topic_0000001103383404_b1322434113810"><a name="en-us_topic_0000001103383404_b1322434113810"></a><a name="en-us_topic_0000001103383404_b1322434113810"></a>AudioPlayer</strong> instance if the operation is successful; returns <strong id="en-us_topic_0000001103383404_b114701838153811"><a name="en-us_topic_0000001103383404_b114701838153811"></a><a name="en-us_topic_0000001103383404_b114701838153811"></a>null</strong> otherwise.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
var audioplayer = audio.createAudioPlayer(); 
```

## Appendixes<a name="en-us_topic_0000001103383404_section1933416317165"></a>

## AudioPlayer<a name="en-us_topic_0000001103383404_section5174142818365"></a>

Represents an audio player.

### Attributes<a name="en-us_topic_0000001103383404_section4947115405"></a>

<a name="en-us_topic_0000001103383404_table92548495595"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row132541749175917"><th class="cellrowborder" valign="top" width="15.8015801580158%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001103383404_p925404965919"><a name="en-us_topic_0000001103383404_p925404965919"></a><a name="en-us_topic_0000001103383404_p925404965919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="19.591959195919593%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001103383404_p325464914599"><a name="en-us_topic_0000001103383404_p325464914599"></a><a name="en-us_topic_0000001103383404_p325464914599"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.660766076607661%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001103383404_p025484918596"><a name="en-us_topic_0000001103383404_p025484918596"></a><a name="en-us_topic_0000001103383404_p025484918596"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.29082908290829%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001103383404_p025414499590"><a name="en-us_topic_0000001103383404_p025414499590"></a><a name="en-us_topic_0000001103383404_p025414499590"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="48.65486548654865%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001103383404_p20254134925912"><a name="en-us_topic_0000001103383404_p20254134925912"></a><a name="en-us_topic_0000001103383404_p20254134925912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row18254849155915"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103383404_p20254204935915"><a name="en-us_topic_0000001103383404_p20254204935915"></a><a name="en-us_topic_0000001103383404_p20254204935915"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103383404_p1525413497591"><a name="en-us_topic_0000001103383404_p1525413497591"></a><a name="en-us_topic_0000001103383404_p1525413497591"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103383404_p8254749195914"><a name="en-us_topic_0000001103383404_p8254749195914"></a><a name="en-us_topic_0000001103383404_p8254749195914"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103383404_p5255549115910"><a name="en-us_topic_0000001103383404_p5255549115910"></a><a name="en-us_topic_0000001103383404_p5255549115910"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103383404_p72551449145914"><a name="en-us_topic_0000001103383404_p72551449145914"></a><a name="en-us_topic_0000001103383404_p72551449145914"></a>URI of the audio resources</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row10255134945917"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103383404_p82551349125910"><a name="en-us_topic_0000001103383404_p82551349125910"></a><a name="en-us_topic_0000001103383404_p82551349125910"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103383404_p18255154913598"><a name="en-us_topic_0000001103383404_p18255154913598"></a><a name="en-us_topic_0000001103383404_p18255154913598"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103383404_p525516497595"><a name="en-us_topic_0000001103383404_p525516497595"></a><a name="en-us_topic_0000001103383404_p525516497595"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103383404_p2025504917593"><a name="en-us_topic_0000001103383404_p2025504917593"></a><a name="en-us_topic_0000001103383404_p2025504917593"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103383404_p7255194925919"><a name="en-us_topic_0000001103383404_p7255194925919"></a><a name="en-us_topic_0000001103383404_p7255194925919"></a>Whether to loop audio playback</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row18256049165911"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103383404_p2256154919590"><a name="en-us_topic_0000001103383404_p2256154919590"></a><a name="en-us_topic_0000001103383404_p2256154919590"></a>currentTime</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103383404_p10256849165915"><a name="en-us_topic_0000001103383404_p10256849165915"></a><a name="en-us_topic_0000001103383404_p10256849165915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103383404_p19256149155915"><a name="en-us_topic_0000001103383404_p19256149155915"></a><a name="en-us_topic_0000001103383404_p19256149155915"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103383404_p3256174935919"><a name="en-us_topic_0000001103383404_p3256174935919"></a><a name="en-us_topic_0000001103383404_p3256174935919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103383404_p12256144995913"><a name="en-us_topic_0000001103383404_p12256144995913"></a><a name="en-us_topic_0000001103383404_p12256144995913"></a>Current playback position</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row11256144911598"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103383404_p92561949125910"><a name="en-us_topic_0000001103383404_p92561949125910"></a><a name="en-us_topic_0000001103383404_p92561949125910"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103383404_p9256124914597"><a name="en-us_topic_0000001103383404_p9256124914597"></a><a name="en-us_topic_0000001103383404_p9256124914597"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103383404_p1725654915911"><a name="en-us_topic_0000001103383404_p1725654915911"></a><a name="en-us_topic_0000001103383404_p1725654915911"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103383404_p192562049125910"><a name="en-us_topic_0000001103383404_p192562049125910"></a><a name="en-us_topic_0000001103383404_p192562049125910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103383404_p125684995913"><a name="en-us_topic_0000001103383404_p125684995913"></a><a name="en-us_topic_0000001103383404_p125684995913"></a>Playback duration</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row6256149115920"><td class="cellrowborder" valign="top" width="15.8015801580158%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001103383404_p2256144918596"><a name="en-us_topic_0000001103383404_p2256144918596"></a><a name="en-us_topic_0000001103383404_p2256144918596"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001103383404_p9256144918593"><a name="en-us_topic_0000001103383404_p9256144918593"></a><a name="en-us_topic_0000001103383404_p9256144918593"></a><a href="#en-us_topic_0000001103383404_section5181155710523">AudioState</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.660766076607661%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001103383404_p102563495592"><a name="en-us_topic_0000001103383404_p102563495592"></a><a name="en-us_topic_0000001103383404_p102563495592"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.29082908290829%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001103383404_p625620497594"><a name="en-us_topic_0000001103383404_p625620497594"></a><a name="en-us_topic_0000001103383404_p625620497594"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.65486548654865%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001103383404_p162571549195920"><a name="en-us_topic_0000001103383404_p162571549195920"></a><a name="en-us_topic_0000001103383404_p162571549195920"></a>Playback status</p>
</td>
</tr>
</tbody>
</table>

### play\(\)<a name="en-us_topic_0000001103383404_section964512672913"></a>

Starts audio playback.

**Example**

```
audioplayer.src = 'common/mydream.mp3';
audioplayer.on('play', (err, action) => {
  if (err) {
     console.log(`err returned in play() callback`);
     return;
  }
  console.log('start to play');
  audioplayer.pause();
};
audioplayer.play();
```

### pause\(\)<a name="en-us_topic_0000001103383404_section78173258296"></a>

Pauses audio playback.

**Example**

```
audioplayer.src = 'common/mydream.mp3';
audioplayer.on('pause', (err, action) => {
  if (err) {
     console.log(`err returned in pause() callback`);
     return;
  }
  console.log('playback pause');
};
audioplayer.pause();
```

### stop\(\)<a name="en-us_topic_0000001103383404_section122114334296"></a>

Stops audio playback.

**Example**

```
audioplayer.src = 'common/mydream.mp3';
audioplayer.on('stop',(err, action) => {
  if (err) {
     console.log(`err returned in stop() callback`);
     return;
  }
  console.log('playback stop');
};
audioplayer.stop();
```

### seek\(number\)<a name="en-us_topic_0000001103383404_section1387113816298"></a>

Goes to a specified playback position.

**Parameters**

<a name="en-us_topic_0000001103383404_table1442723852917"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row84261138172911"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103383404_p204261938182919"><a name="en-us_topic_0000001103383404_p204261938182919"></a><a name="en-us_topic_0000001103383404_p204261938182919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103383404_p1342683842920"><a name="en-us_topic_0000001103383404_p1342683842920"></a><a name="en-us_topic_0000001103383404_p1342683842920"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001103383404_p134260383297"><a name="en-us_topic_0000001103383404_p134260383297"></a><a name="en-us_topic_0000001103383404_p134260383297"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103383404_p442663832912"><a name="en-us_topic_0000001103383404_p442663832912"></a><a name="en-us_topic_0000001103383404_p442663832912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row18427738202910"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103383404_p184261338192913"><a name="en-us_topic_0000001103383404_p184261338192913"></a><a name="en-us_topic_0000001103383404_p184261338192913"></a>timeMs</p>
</td>
<td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103383404_p1242643819295"><a name="en-us_topic_0000001103383404_p1242643819295"></a><a name="en-us_topic_0000001103383404_p1242643819295"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001103383404_p44261838112918"><a name="en-us_topic_0000001103383404_p44261838112918"></a><a name="en-us_topic_0000001103383404_p44261838112918"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103383404_p16427163812913"><a name="en-us_topic_0000001103383404_p16427163812913"></a><a name="en-us_topic_0000001103383404_p16427163812913"></a>Target playback position</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
audioplayer.src = 'common/mydream.mp3';
audioplayer.on('timeupdate', (err, action) => {
  if (err) {
     console.log(`err returned in seek() callback`);
     return;
  }
  var newTime = audioplayer.currenTime;
  if(newTime = 30000) {
    console.info('Seek success, new time : ' + newTime);
  } else {
    console.info('Seek Failed');
  }
};
audioplayer.seek(30000);
```

### setVolume\(number\)<a name="en-us_topic_0000001103383404_section164235176552"></a>

Sets the volume.

**Parameters**

<a name="en-us_topic_0000001103383404_table1242391713555"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row14424217195517"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103383404_p1424917135519"><a name="en-us_topic_0000001103383404_p1424917135519"></a><a name="en-us_topic_0000001103383404_p1424917135519"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103383404_p10424121795520"><a name="en-us_topic_0000001103383404_p10424121795520"></a><a name="en-us_topic_0000001103383404_p10424121795520"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001103383404_p1042415178559"><a name="en-us_topic_0000001103383404_p1042415178559"></a><a name="en-us_topic_0000001103383404_p1042415178559"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="62.89%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103383404_p13424717125513"><a name="en-us_topic_0000001103383404_p13424717125513"></a><a name="en-us_topic_0000001103383404_p13424717125513"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row13424171745513"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103383404_p204241517125517"><a name="en-us_topic_0000001103383404_p204241517125517"></a><a name="en-us_topic_0000001103383404_p204241517125517"></a>vol</p>
</td>
<td class="cellrowborder" valign="top" width="12.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103383404_p18424121755517"><a name="en-us_topic_0000001103383404_p18424121755517"></a><a name="en-us_topic_0000001103383404_p18424121755517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001103383404_p2042417176554"><a name="en-us_topic_0000001103383404_p2042417176554"></a><a name="en-us_topic_0000001103383404_p2042417176554"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="62.89%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103383404_p9424171717557"><a name="en-us_topic_0000001103383404_p9424171717557"></a><a name="en-us_topic_0000001103383404_p9424171717557"></a>Volume to set</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
audioplayer.src = 'common/mydream.mp3';
audioplayer.on('volumeChange', (err, action) => {
  if (err) {
     console.log(`err returned in setVolume() callback`);
     return;
  }
  console.log('playback volume change');
};
audioplayer.setVolume(30);
```

### release\(\)<a name="en-us_topic_0000001103383404_section9224621145512"></a>

Releases audio resources.

**Example**

```
audioplay.release();
```

### Events<a name="en-us_topic_0000001103383404_section5453721192911"></a>

### play<a name="en-us_topic_0000001103383404_section87307411494"></a>

Triggered when  **play\(\)**  is called

### pause<a name="en-us_topic_0000001103383404_section198217471590"></a>

Triggered when  **pause\(\)**  is called

### stop<a name="en-us_topic_0000001103383404_section437616531910"></a>

Triggered when  **stop\(\)**  is called

### dataLoad<a name="en-us_topic_0000001103383404_section982114219106"></a>

Triggered when audio data is loaded

### timeUpdate<a name="en-us_topic_0000001103383404_section13687114181014"></a>

Triggered when the playback position changes

### volumeChange<a name="en-us_topic_0000001103383404_section139227715717"></a>

Triggered when playback volume changes

### finish<a name="en-us_topic_0000001103383404_section15181321181018"></a>

Triggered when playback is finished

### error<a name="en-us_topic_0000001103383404_section5593132921016"></a>

Triggered when a playback error occurs

<a name="en-us_topic_0000001103383404_table24591722143619"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row1945962219364"><th class="cellrowborder" valign="top" width="24.060000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001103383404_p84591522103610"><a name="en-us_topic_0000001103383404_p84591522103610"></a><a name="en-us_topic_0000001103383404_p84591522103610"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25.25%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001103383404_p11459102243616"><a name="en-us_topic_0000001103383404_p11459102243616"></a><a name="en-us_topic_0000001103383404_p11459102243616"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.690000000000005%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001103383404_p14591922113616"><a name="en-us_topic_0000001103383404_p14591922113616"></a><a name="en-us_topic_0000001103383404_p14591922113616"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row2459622183611"><td class="cellrowborder" valign="top" width="24.060000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001103383404_p17338122234119"><a name="en-us_topic_0000001103383404_p17338122234119"></a><a name="en-us_topic_0000001103383404_p17338122234119"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25.25%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001103383404_p174601822193612"><a name="en-us_topic_0000001103383404_p174601822193612"></a><a name="en-us_topic_0000001103383404_p174601822193612"></a>ErrorCallback</p>
</td>
<td class="cellrowborder" valign="top" width="50.690000000000005%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001103383404_p7460222123612"><a name="en-us_topic_0000001103383404_p7460222123612"></a><a name="en-us_topic_0000001103383404_p7460222123612"></a>Callback function for handling this event</p>
</td>
</tr>
</tbody>
</table>

## AudioState<a name="en-us_topic_0000001103383404_section5181155710523"></a>

Describes playback status.

<a name="en-us_topic_0000001103383404_table919114616314"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103383404_row31917610318"><th class="cellrowborder" valign="top" width="33.739999999999995%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001103383404_p219196531"><a name="en-us_topic_0000001103383404_p219196531"></a><a name="en-us_topic_0000001103383404_p219196531"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="66.25999999999999%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001103383404_p14191563313"><a name="en-us_topic_0000001103383404_p14191563313"></a><a name="en-us_topic_0000001103383404_p14191563313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103383404_row2019146539"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001103383404_p201913617311"><a name="en-us_topic_0000001103383404_p201913617311"></a><a name="en-us_topic_0000001103383404_p201913617311"></a>playing</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001103383404_p81911362316"><a name="en-us_topic_0000001103383404_p81911362316"></a><a name="en-us_topic_0000001103383404_p81911362316"></a>The audio is being played.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row11912612316"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001103383404_p9191136731"><a name="en-us_topic_0000001103383404_p9191136731"></a><a name="en-us_topic_0000001103383404_p9191136731"></a>paused</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001103383404_p419166738"><a name="en-us_topic_0000001103383404_p419166738"></a><a name="en-us_topic_0000001103383404_p419166738"></a>Audio playback is paused.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103383404_row111912617314"><td class="cellrowborder" valign="top" width="33.739999999999995%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001103383404_p9191156333"><a name="en-us_topic_0000001103383404_p9191156333"></a><a name="en-us_topic_0000001103383404_p9191156333"></a>stopped</p>
</td>
<td class="cellrowborder" valign="top" width="66.25999999999999%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001103383404_p2019215618316"><a name="en-us_topic_0000001103383404_p2019215618316"></a><a name="en-us_topic_0000001103383404_p2019215618316"></a>Audio playback is stopped.</p>
</td>
</tr>
</tbody>
</table>

