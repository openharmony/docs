# native_audio_channel_layout.h

## Overview

The file declares the functions related to the speaker layout during recording and playback.

**File to include**: <multimedia/native_audio_channel_layout.h>

**Library**: none

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Related module**: [Core](capi-core.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioChannelSet](#oh_audiochannelset) | OH_AudioChannelSet | Enumerates the audio channels.<br>Each channel is mapped to a variable of int64.|
| [OH_AmbAttributeSet](#oh_ambattributeset) | OH_AmbAttributeSet | Enumerates the Hi-Fi stereo reverberation settings.<br>Int64 integers are used to indicate the Hi-Fi stereo reverberation attributes.|
| [OH_AudioChannelLayout](#oh_audiochannellayout) | OH_AudioChannelLayout | Enumerates the layouts of audio channels.<br>Int64 integers are used to indicate the appearance and sequence of speakers during recording or playback.|

## Enum Description

### OH_AudioChannelSet

```
enum OH_AudioChannelSet
```

**Description**

Enumerates the audio channels.<br>Each channel is mapped to a variable of int64.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description|
| -- | -- |
| CH_SET_FRONT_LEFT = 1ULL << 0U | Front left channel.|
| CH_SET_FRONT_RIGHT = 1ULL << 1U | Front right channel.|
| CH_SET_FRONT_CENTER = 1ULL << 2U | Front center channel.|
| CH_SET_LOW_FREQUENCY = 1ULL << 3U | Low-frequency channel.|
| CH_SET_BACK_LEFT = 1ULL << 4U | Rear left channel.|
| CH_SET_BACK_RIGHT = 1ULL << 5U | Rear right channel.|
| CH_SET_FRONT_LEFT_OF_CENTER = 1ULL << 6U | Front left center channel.|
| CH_SET_FRONT_RIGHT_OF_CENTER = 1ULL << 7U | Front right center channel.|
| CH_SET_BACK_CENTER = 1ULL << 8U | Rear center channel.|
| CH_SET_SIDE_LEFT = 1ULL << 9U | Left channel.|
| CH_SET_SIDE_RIGHT = 1ULL << 10U | Right channel.|
| CH_SET_TOP_CENTER = 1ULL << 11U | Top center channel.|
| CH_SET_TOP_FRONT_LEFT = 1ULL << 12U | Top left front channel.|
| CH_SET_TOP_FRONT_CENTER = 1ULL << 13U | Top center front channel.|
| CH_SET_TOP_FRONT_RIGHT = 1ULL << 14U | Top right front channel.|
| CH_SET_TOP_BACK_LEFT = 1ULL << 15U | Top left rear channel.|
| CH_SET_TOP_BACK_CENTER = 1ULL << 16U | Top center rear channel.|
| CH_SET_TOP_BACK_RIGHT = 1ULL << 17U | Top right rear channel.|
| CH_SET_STEREO_LEFT = 1ULL << 29U | Stereo left channel.|
| CH_SET_STEREO_RIGHT = 1ULL << 30U | Stereo right channel.|
| CH_SET_WIDE_LEFT = 1ULL << 31U | Wide left channel.|
| CH_SET_WIDE_RIGHT = 1ULL << 32U | Wide right channel.|
| CH_SET_SURROUND_DIRECT_LEFT = 1ULL << 33U | Left surround channel.|
| CH_SET_SURROUND_DIRECT_RIGHT = 1ULL << 34U | Right surround channel.|
| CH_SET_LOW_FREQUENCY_2 = 1ULL << 35U | Low-frequency channel 2.|
| CH_SET_TOP_SIDE_LEFT = 1ULL << 36U | Top left channel.|
| CH_SET_TOP_SIDE_RIGHT = 1ULL << 37U | Top right channel.|
| CH_SET_BOTTOM_FRONT_CENTER = 1ULL << 38U | Bottom center front channel.|
| CH_SET_BOTTOM_FRONT_LEFT = 1ULL << 39U | Bottom left front channel.|
| CH_SET_BOTTOM_FRONT_RIGHT = 1ULL << 40U | Bottom right front channel.|

### OH_AmbAttributeSet

```
enum OH_AmbAttributeSet
```

**Description**

Enumerates the Hi-Fi stereo reverberation settings.<br>Int64 integers are used to indicate the Hi-Fi stereo reverberation attributes.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description|
| -- | -- |
| AMB_ORD_1 = 1ULL << 0U | First-order Hi-Fi stereo reverberation.|
| AMB_ORD_2 = 2ULL << 0U | Second-order Hi-Fi stereo reverberation.|
| AMB_ORD_3 = 3ULL << 0U | Third-order Hi-Fi stereo reverberation.|
| AMB_COM_ACN = 0ULL << 8U | Hi-Fi stereo reverberation with ACN channel sorting.|
| AMB_COM_FUMA = 1ULL << 8U | Hi-Fi stereo reverberation with FUMA channel sorting.|
| AMB_NOR_N3D = 0ULL << 12U | N3D normalized Hi-Fi stereo reverberation.|
| AMB_NOR_SN3D = 1ULL << 12U | SN3D normalized Hi-Fi stereo reverberation.|
| AMB_MODE = 1ULL << 44U | Audio channel layout for Hi-Fi stereo reverberation.|

### OH_AudioChannelLayout

```
enum OH_AudioChannelLayout
```

**Description**

Enumerates the audio channel layouts.<br>Int64 integers are used to indicate the appearance and sequence of speakers during recording or playback.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description|
| -- | -- |
| CH_LAYOUT_UNKNOWN = 0ULL | Unknown.|
| CH_LAYOUT_MONO = CH_SET_FRONT_CENTER | Mono layout; 1 audio channel in total.|
| CH_LAYOUT_STEREO = CH_SET_FRONT_LEFT \| CH_SET_FRONT_RIGHT | Stereo layout; 2 audio channels in total.|
| CH_LAYOUT_STEREO_DOWNMIX = CH_SET_STEREO_LEFT \| CH_SET_STEREO_RIGHT | Stereo downmix layout; 2 audio channels in total.|
| CH_LAYOUT_2POINT1 = CH_LAYOUT_STEREO \| CH_SET_LOW_FREQUENCY | 2.1 layout; 3 audio channels in total.|
| CH_LAYOUT_3POINT0 = CH_LAYOUT_STEREO \| CH_SET_BACK_CENTER | 3.0 layout; 3 audio channels in total.|
| CH_LAYOUT_SURROUND = CH_LAYOUT_STEREO \| CH_SET_FRONT_CENTER | Surround; 3 audio channels in total.|
| CH_LAYOUT_3POINT1 = CH_LAYOUT_SURROUND \| CH_SET_LOW_FREQUENCY | 3.1 layout; 4 audio channels in total.|
| CH_LAYOUT_4POINT0 = CH_LAYOUT_SURROUND \| CH_SET_BACK_CENTER | 4.0 layout; 4 audio channels in total.|
| CH_LAYOUT_QUAD_SIDE = CH_LAYOUT_STEREO \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT | Quad side layout; 4 audio channels in total.|
| CH_LAYOUT_QUAD = CH_LAYOUT_STEREO \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT | Quad layout; 4 audio channels in total.|
| CH_LAYOUT_2POINT0POINT2 = CH_LAYOUT_STEREO \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT | 2.0.2 layout; 4 audio channels in total.|
| CH_LAYOUT_AMB_ORDER1_ACN_N3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_N3D | First-order FOA layout in ACN_N3D (ITU standards); 4 audio channels in total.|
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_SN3D | First-order FOA layout in ACN_SN3D (ITU standards); 4 audio channels in total.|
| CH_LAYOUT_AMB_ORDER1_FUMA = AMB_MODE \| AMB_ORD_1 \| AMB_COM_FUMA | First-order FOA layout in FUMA (ITU standards); 4 audio channels in total.|
| CH_LAYOUT_4POINT1 = CH_LAYOUT_4POINT0 \| CH_SET_LOW_FREQUENCY | 4.1 layout; 5 audio channels in total.|
| CH_LAYOUT_5POINT0 = CH_LAYOUT_SURROUND \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT | 5.0 layout; 5 audio channels in total.|
| CH_LAYOUT_5POINT0_BACK = CH_LAYOUT_SURROUND \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT | 5.0 rear layout; 5 audio channels in total.|
| CH_LAYOUT_2POINT1POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_LOW_FREQUENCY | 2.1.2 layout; 5 audio channels in total.|
| CH_LAYOUT_3POINT0POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_FRONT_CENTER | 3.0.2 layout; 5 audio channels in total.|
| CH_LAYOUT_5POINT1 = CH_LAYOUT_5POINT0 \| CH_SET_LOW_FREQUENCY | 5.1 layout; 6 audio channels in total.|
| CH_LAYOUT_5POINT1_BACK = CH_LAYOUT_5POINT0_BACK \| CH_SET_LOW_FREQUENCY | 5.1 rear layout; 6 audio channels in total.|
| CH_LAYOUT_6POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_CENTER | 6.0 layout; 6 audio channels in total.|
| CH_LAYOUT_3POINT1POINT2 = CH_LAYOUT_3POINT1 \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT | 3.1.2 layout; 6 audio channels in total.|
| CH_LAYOUT_6POINT0_FRONT = CH_LAYOUT_QUAD_SIDE \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER | 6.0 front layout; 6 audio channels in total.|
| CH_LAYOUT_HEXAGONAL = CH_LAYOUT_5POINT0_BACK \| CH_SET_BACK_CENTER | Hexagonal layout; 6 audio channels in total.|
| CH_LAYOUT_6POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_CENTER | 6.1 layout; 7 audio channels in total.|
| CH_LAYOUT_6POINT1_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_BACK_CENTER | 6.1 rear layout; 7 audio channels in total.|
| CH_LAYOUT_6POINT1_FRONT = CH_LAYOUT_6POINT0_FRONT \| CH_SET_LOW_FREQUENCY | 6.1 front layout; 7 audio channels in total.|
| CH_LAYOUT_7POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT | 7.0 layout; 7 audio channels in total.|
| CH_LAYOUT_7POINT0_FRONT = CH_LAYOUT_5POINT0 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER | 7.0 front layout; 7 audio channels in total.|
| CH_LAYOUT_7POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT | 7.1 layout; 8 audio channels in total.|
| CH_LAYOUT_OCTAGONAL = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_CENTER \| CH_SET_BACK_RIGHT | Octagonal layout; 8 audio channels in total.|
| CH_LAYOUT_5POINT1POINT2 = CH_LAYOUT_5POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT | 5.1.2 layout; 8 audio channels in total.|
| CH_LAYOUT_7POINT1_WIDE = CH_LAYOUT_5POINT1 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER | 7.1 wide layout; 8 audio channels in total.|
| CH_LAYOUT_7POINT1_WIDE_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER | 7.1 rear wide layout; 8 audio channels in total.|
| CH_LAYOUT_AMB_ORDER2_ACN_N3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_N3D | Second-order HOA layout in ACN_N3D (ITU standards); 9 audio channels in total.|
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_SN3D | Second-order HOA layout in ACN_SN3D (ITU standards); 9 audio channels in total.|
| CH_LAYOUT_AMB_ORDER2_FUMA = AMB_MODE \| AMB_ORD_2 \| AMB_COM_FUMA | Second-order HOA layout in FUMA (ITU standards); 9 audio channels in total.|
| CH_LAYOUT_5POINT1POINT4 = CH_LAYOUT_5POINT1 \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT \| CH_SET_TOP_BACK_LEFT \| CH_SET_TOP_BACK_RIGHT | 5.1.4 layout; 10 audio channels in total.|
| CH_LAYOUT_7POINT1POINT2 = CH_LAYOUT_7POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT | 7.1.2 layout; 10 audio channels in total.|
| CH_LAYOUT_7POINT1POINT4 = CH_LAYOUT_7POINT1 \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT \| CH_SET_TOP_BACK_LEFT \| CH_SET_TOP_BACK_RIGHT | 7.1.4 layout; 12 audio channels in total.|
| CH_LAYOUT_10POINT2 = CH_SET_FRONT_LEFT \| CH_SET_FRONT_RIGHT \| CH_SET_FRONT_CENTER \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT \| CH_SET_BACK_CENTER \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT \| CH_SET_WIDE_LEFT \| CH_SET_WIDE_RIGHT | 10.2 layout; 12 audio channels in total.|
| CH_LAYOUT_9POINT1POINT4 = CH_LAYOUT_7POINT1POINT4 \| CH_SET_WIDE_LEFT \| CH_SET_WIDE_RIGHT | 9.1.4 layout; 14 audio channels in total.|
| CH_LAYOUT_9POINT1POINT6 = CH_LAYOUT_9POINT1POINT4 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT | 9.1.6 layout; 16 audio channels in total.|
| CH_LAYOUT_HEXADECAGONAL = CH_LAYOUT_OCTAGONAL \| CH_SET_WIDE_LEFT \| CH_SET_WIDE_RIGHT \| CH_SET_TOP_BACK_LEFT \| CH_SET_TOP_BACK_RIGHT \| CH_SET_TOP_BACK_CENTER \| CH_SET_TOP_FRONT_CENTER \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT | Hexadecagonal layout; 16 audio channels in total.|
| CH_LAYOUT_AMB_ORDER3_ACN_N3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_N3D | Third-order HOA layout in ACN_N3D (ITU standards); 16 audio channels in total.|
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_SN3D | Third-order HOA layout in ACN_SN3D (ITU standards); 16 audio channels in total.|
| CH_LAYOUT_AMB_ORDER3_FUMA = AMB_MODE \| AMB_ORD_3 \| AMB_COM_FUMA | Third-order HOA layout in FUMA (ITU standards); 16 audio channels in total.|
| CH_LAYOUT_22POINT2 = CH_LAYOUT_7POINT1POINT4 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER \| CH_SET_BACK_CENTER \| CH_SET_TOP_CENTER \| CH_SET_TOP_FRONT_CENTER \| CH_SET_TOP_BACK_CENTER \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT \| CH_SET_BOTTOM_FRONT_LEFT \| CH_SET_BOTTOM_FRONT_RIGHT \| CH_SET_BOTTOM_FRONT_CENTER \| CH_SET_LOW_FREQUENCY_2 | 22.2 layout; 24 audio channels in total.|
