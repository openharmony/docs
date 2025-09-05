# avcodec_audio_channel_layout.h

## Overview

The file declares the enums used for audio encoding and decoding.

**File to include**: <multimedia/player_framework/avcodec_audio_channel_layout.h>

**Library**: libnative_media_codecbase.so

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 9

**Deprecated from**: 11

**Related module**: [CodecBase](capi-codecbase.md)

## Summary

### Enums

| Name| Description|
| -- | -- |
| [AudioChannelSet](#audiochannelset) | Enumerates the audio channels. Each channel is mapped to a variable of int64.|
| [AudioChannelLayout](#audiochannellayout) | Enumerates the layouts of audio channels. The output format of the decoder is described using the channel layout of the codec.|

## Enum Description

### AudioChannelSet

```
enum AudioChannelSet : uint64_t
```

**Description**

Enumerates the audio channels. Each channel is mapped to a variable of int64.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AudioChannelSet](_core.md#oh_audiochannelset-1)

| Value| Description|
| -- | -- |
| FRONT_LEFT = 1ULL << 0U | Front left channel.|
| FRONT_RIGHT = 1ULL << 1U | Front right channel.|
| FRONT_CENTER = 1ULL << 2U | Front center channel.|
| LOW_FREQUENCY = 1ULL << 3U | Low-frequency channel.|
| BACK_LEFT = 1ULL << 4U | Rear left channel.|
| BACK_RIGHT = 1ULL << 5U | Rear right channel.|
| FRONT_LEFT_OF_CENTER = 1ULL << 6U | Front left center channel.|
| FRONT_RIGHT_OF_CENTER = 1ULL << 7U | Front right center channel.|
| BACK_CENTER = 1ULL << 8U | Rear center channel.|
| SIDE_LEFT = 1ULL << 9U | Left channel.|
| SIDE_RIGHT = 1ULL << 10U | Right channel.|
| TOP_CENTER = 1ULL << 11U | Top center channel.|
| TOP_FRONT_LEFT = 1ULL << 12U | Top left front channel.|
| TOP_FRONT_CENTER = 1ULL << 13U | Top center front channel.|
| TOP_FRONT_RIGHT = 1ULL << 14U | Top right front channel.|
| TOP_BACK_LEFT = 1ULL << 15U | Top left rear channel.|
| TOP_BACK_CENTER = 1ULL << 16U | Top center rear channel.|
| TOP_BACK_RIGHT = 1ULL << 17U | Top right rear channel.|
| STEREO_LEFT = 1ULL << 29U | Stereo left channel.|
| STEREO_RIGHT = 1ULL << 30U | Stereo right channel.|
| WIDE_LEFT = 1ULL << 31U | Wide left channel.|
| WIDE_RIGHT = 1ULL << 32U | Wide right channel.|
| SURROUND_DIRECT_LEFT = 1ULL << 33U | Left surround channel.|
| SURROUND_DIRECT_RIGHT = 1ULL << 34U | Right surround channel.|
| LOW_FREQUENCY_2 = 1ULL << 35U | Low-frequency channel 2.|
| TOP_SIDE_LEFT = 1ULL << 36U | Top left channel.|
| TOP_SIDE_RIGHT = 1ULL << 37U | Top right channel.|
| BOTTOM_FRONT_CENTER = 1ULL << 38U | Bottom center front channel.|
| BOTTOM_FRONT_LEFT = 1ULL << 39U | Bottom left front channel.|
| BOTTOM_FRONT_RIGHT = 1ULL << 40U | Bottom right front channel.|
| AMBISONICS_ACN0 = 1ULL << 41U | Channel 0 for the zero-order stereo.|
| AMBISONICS_ACN1 = 1ULL << 42U | Channel 1 for the first-order stereo.|
| AMBISONICS_ACN2 = 1ULL << 43U | Channel 2 for the first-order stereo.|
| AMBISONICS_ACN3 = 1ULL << 44U | Channel 3 for the first-order stereo.|
| AMBISONICS_W = AMBISONICS_ACN0 | Equivalent to channel 0 for the zero-order stereo.|
| AMBISONICS_Y = AMBISONICS_ACN1 | Equivalent to channel 1 for the first-order stereo.|
| AMBISONICS_Z = AMBISONICS_ACN2 | Equivalent to channel 2 for the first-order stereo.|
| AMBISONICS_X = AMBISONICS_ACN3 | Equivalent to channel 3 for the first-order stereo.|
| AMBISONICS_ACN4 = 1ULL << 45U | Channel 4 for the second-order stereo.|
| AMBISONICS_ACN5 = 1ULL << 46U | Channel 5 for the second-order stereo.|
| AMBISONICS_ACN6 = 1ULL << 47U | Channel 6 for the second-order stereo.|
| AMBISONICS_ACN7 = 1ULL << 48U | Channel 7 for the second-order stereo.|
| AMBISONICS_ACN8 = 1ULL << 49U | Channel 8 for the second-order stereo.|
| AMBISONICS_ACN9 = 1ULL << 50U | Channel 9 for the third-order stereo.|
| AMBISONICS_ACN10 = 1ULL << 51U | Channel 10 for the third-order stereo.|
| AMBISONICS_ACN11 = 1ULL << 52U | Channel 11 for the third-order stereo.|
| AMBISONICS_ACN12 = 1ULL << 53U | Channel 12 for the third-order stereo.|
| AMBISONICS_ACN13 = 1ULL << 54U | Channel 13 for the third-order stereo.|
| AMBISONICS_ACN14 = 1ULL << 55U | Channel 14 for the third-order stereo.|
| AMBISONICS_ACN15 = 1ULL << 56U | Channel 15 for the third-order stereo.|

### AudioChannelLayout

```
enum AudioChannelLayout : uint64_t
```

**Description**

Enumerates the layouts of audio channels. The output format of the decoder is described using the channel layout of the codec.

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AudioChannelLayout](_core.md#oh_audiochannellayout-1)

| Value| Description|
| -- | -- |
| UNKNOWN_CHANNEL_LAYOUT = 0 | Unknown.|
| MONO = (AudioChannelSet::FRONT_CENTER) | Mono layout.|
| STEREO = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT) | Stereo layout.|
| CH_2POINT1 = (STEREO \| AudioChannelSet::LOW_FREQUENCY) | 2.1 layout.|
| CH_2_1 = (STEREO \| AudioChannelSet::BACK_CENTER) | 2_1 layout.|
| SURROUND = (STEREO \| AudioChannelSet::FRONT_CENTER) | Surround layout.|
| CH_3POINT1 = (SURROUND \| AudioChannelSet::LOW_FREQUENCY) | 3.1 layout.|
| CH_4POINT0 = (SURROUND \| AudioChannelSet::BACK_CENTER) | 4.0 layout.|
| CH_4POINT1 = (CH_4POINT0 \| AudioChannelSet::LOW_FREQUENCY) | 4.1 layout.|
| CH_2_2 = (STEREO \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT) | 2_2 layout.|
| QUAD = (STEREO \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT) | Quad layout.|
| CH_5POINT0 = (SURROUND \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT) | 5.0 layout.|
| CH_5POINT1 = (CH_5POINT0 \| AudioChannelSet::LOW_FREQUENCY) | 5.1 layout.|
| CH_5POINT0_BACK = (SURROUND \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT) | 5.0 rear layout.|
| CH_5POINT1_BACK = (CH_5POINT0_BACK \| AudioChannelSet::LOW_FREQUENCY) | 5.1 rear layout.|
| CH_6POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_CENTER) | 6.0 layout.|
| CH_6POINT0_FRONT = (CH_2_2 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER) | 6.0 front layout.|
| HEXAGONAL = (CH_5POINT0_BACK \| AudioChannelSet::BACK_CENTER) | Hexagonal layout.|
| CH_6POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_CENTER) | 6.1 layout.|
| CH_6POINT1_BACK = (CH_5POINT1_BACK \| AudioChannelSet::BACK_CENTER) | 6.1 rear layout.|
| CH_6POINT1_FRONT = (CH_6POINT0_FRONT \| AudioChannelSet::LOW_FREQUENCY) | 6.1 front layout.|
| CH_7POINT0 = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT) | 7.0 layout.|
| CH_7POINT0_FRONT = (CH_5POINT0 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER) | 7.0 front layout.|
| CH_7POINT1 = (CH_5POINT1 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT) | 7.1 layout.|
| CH_7POINT1_WIDE = (CH_5POINT1 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER) | 7.1 wide layout.|
| CH_7POINT1_WIDE_BACK = | 7.1 rear wide layout.|
| CH_3POINT1POINT2 = (CH_3POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT) | 3.1.2 layout.|
| CH_5POINT1POINT2 = (CH_5POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT) | 5.1.2 layout.|
| (CH_5POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT \|AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT) | 5.1.4 layout.|
| CH_7POINT1POINT2 = (CH_7POINT1 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT) | 7.1.2 layout.|
| CH_7POINT1POINT4 = (CH_7POINT1 \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT \| AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT) | 7.1.4 layout.|
| CH_9POINT1POINT4 = (CH_7POINT1POINT4 \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT) | 9.1.4 layout.|
| CH_9POINT1POINT6 = (CH_9POINT1POINT4 \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT) | 9.1.6 layout.|
| CH_10POINT2 = (AudioChannelSet::FRONT_LEFT \| AudioChannelSet::FRONT_RIGHT \| AudioChannelSet::FRONT_CENTER \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_RIGHT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::SIDE_LEFT \| AudioChannelSet::SIDE_RIGHT \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT) | 10.2 layout.|
| CH_22POINT2 = (CH_7POINT1POINT4 \| AudioChannelSet::FRONT_LEFT_OF_CENTER \| AudioChannelSet::FRONT_RIGHT_OF_CENTER \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::TOP_CENTER \| AudioChannelSet::TOP_FRONT_CENTER \| AudioChannelSet::TOP_BACK_CENTER \| AudioChannelSet::TOP_SIDE_LEFT \| AudioChannelSet::TOP_SIDE_RIGHT \| AudioChannelSet::BOTTOM_FRONT_LEFT \| AudioChannelSet::BOTTOM_FRONT_RIGHT \| AudioChannelSet::BOTTOM_FRONT_CENTER \| AudioChannelSet::LOW_FREQUENCY_2) | 22.2 layout.|
| OCTAGONAL = (CH_5POINT0 \| AudioChannelSet::BACK_LEFT \| AudioChannelSet::BACK_CENTER \| AudioChannelSet::BACK_RIGHT) | Octagonal layout.|
| HEXADECAGONAL = (OCTAGONAL \| AudioChannelSet::WIDE_LEFT \| AudioChannelSet::WIDE_RIGHT \| AudioChannelSet::TOP_BACK_LEFT \| AudioChannelSet::TOP_BACK_RIGHT \| AudioChannelSet::TOP_BACK_CENTER \| AudioChannelSet::TOP_FRONT_CENTER \| AudioChannelSet::TOP_FRONT_LEFT \| AudioChannelSet::TOP_FRONT_RIGHT)| Hexadecagonal layout.|
| STEREO_DOWNMIX = (AudioChannelSet::STEREO_LEFT \| AudioChannelSet::STEREO_RIGHT) | Stereo downmix layout.|
| HOA_FIRST = AudioChannelSet::AMBISONICS_ACN0 \| AudioChannelSet::AMBISONICS_ACN1 \| AudioChannelSet::AMBISONICS_ACN2 \| AudioChannelSet::AMBISONICS_ACN3 | High-Order Ambisonics (HOA) first-order layout.|
| HOA_SECOND = HOA_FIRST \| AudioChannelSet::AMBISONICS_ACN4 \| AudioChannelSet::AMBISONICS_ACN5 \| AudioChannelSet::AMBISONICS_ACN6 \| AudioChannelSet::AMBISONICS_ACN7 \| AudioChannelSet::AMBISONICS_ACN8 | HOA second-order layout.|
| HOA_THIRD = HOA_SECOND \| AudioChannelSet::AMBISONICS_ACN9 \| AudioChannelSet::AMBISONICS_ACN10 \| AudioChannelSet::AMBISONICS_ACN11 \| AudioChannelSet::AMBISONICS_ACN12 \| AudioChannelSet::AMBISONICS_ACN13 \| AudioChannelSet::AMBISONICS_ACN14 \| AudioChannelSet::AMBISONICS_ACN15 | HOA third-order layout.|
