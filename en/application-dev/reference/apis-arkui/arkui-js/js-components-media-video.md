# video


>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **\<video>** component provides a video player.


## Child Components

Not supported


## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name      | Type     | Default Value  | Mandatory  | Description                                      |
| -------- | ------- | ----- | ---- | ---------------------------------------- |
| muted    | boolean | false | No   | Whether the video is muted.                               |
| src      | string  | -     | No   | Path of the video content to play.                              |
| autoplay | boolean | false | No   | Whether the video is played automatically after being rendered.                               |
| controls | boolean | true  | No   | Whether the control bar is displayed during video playback. If the value is set to **false**, the control bar is not displayed. The default value is **true**, indicating that the platform can either show or hide the control bar.|


## Styles

In addition to the [universal styles](js-components-common-styles.md), the following styles are supported.

| Name        | Type    | Default Value    | Mandatory  | Description                                      |
| ---------- | ------ | ------- | ---- | ---------------------------------------- |
| object-fit | string | contain | No   | Video scale type. If **poster** has been assigned a value, the setting of this style will affect the scaling type of the video poster. For details, see object-fit enums.|

**Table 1** object-fit enums

| Type  | Description                       |
| ---- | ------------------------- |
| fill | The image is resized to fill the display area, and its aspect ratio is not retained.|


## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name        | Parameter                                      | Description                                   |
| ---------- | ---------------------------------------- | ------------------------------------- |
| prepared   | { duration: value }<sup>5+</sup> | Triggered when the video preparation is complete. The video duration (in seconds) is obtained from **duration**.|
| start      | -                                        | Triggered when the video is played.                            |
| pause      | -                                        | Triggered when the video playback is paused.                            |
| finish     | -                                        | Triggered when the video playback is finished.                          |
| error      | -                                        | Triggered when the video playback fails.                          |
| seeking    | { currenttime: value }    | Triggered to report the time (in seconds) when the progress bar is being dragged.                 |
| seeked     | { currenttime: value }    | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar.              |
| timeupdate | { currenttime: value }    | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second.      |


## Methods

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.

| Name            | Parameter                                   | Description               |
| -------------- | ------------------------------------- | ----------------- |
| start          | -                                     | Starts playing a video.          |
| pause          | -                                     | Pauses a video.        |
| setCurrentTime | { currenttime: value } | Sets the video playback position, in seconds.|

>  **NOTE**
>
>  The methods in the above table can be called after the **attached** callback is invoked.

## Example

```html
<!-- xxx.hml -->
<div class="container">
  <video id='videoId' src='/common/myDeram.mp4' muted='false' autoplay='false'
         controls='true' onprepared='preparedCallback' onstart='startCallback'
         onpause='pauseCallback' onfinish='finishCallback' onerror='errorCallback'
         onseeking='seekingCallback' onseeked='seekedCallback' 
         ontimeupdate='timeupdateCallback'
         style="object-fit:fill; width:80%; height:400px;"
         onclick="change_start_pause">
   </video>
</div>
```

```css
/* xxx.css */
.container {
  justify-content: center;
  align-items: center;
}
```

```js
// xxx.js
export default {
  data: {
    event:'',
    seekingtime:'',
    timeupdatetime:'',
    seekedtime:'',
    isStart: true,
    duration: '',
  },
  preparedCallback:function(e){ this.event = 'Video successfully connected'; this.duration = e.duration;},
  startCallback:function(){this.event = 'Playback starts.';},
  pauseCallback:function(){this.event = 'Playback pauses.';},
  finishCallback:function(){this.event = 'Playback ends.';},
  errorCallback:function(){this.event = 'Playback error.';},
  seekingCallback:function(e){ this.seekingtime = e.currenttime; },
  timeupdateCallback:function(e){ this.timeupdatetime = e.currenttime;},
  change_start_pause: function() {
    if(this.isStart) {
      this.$element('videoId').pause();
      this.isStart = false;
    } else {
      this.$element('videoId').start();
      this.isStart = true; 
    }
  },
}
```
