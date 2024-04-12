/*
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SAMSUNG_AUDIO_H
#define SAMSUNG_AUDIO_H

#include <telephony/ril.h>

#define MIXER_CARD 0
#define SOUND_CARD 0

#define SOUND_DEEP_BUFFER_DEVICE 3
#define SOUND_PLAYBACK_DEVICE 6
#define SOUND_PLAYBACK_SCO_DEVICE 2
#define SOUND_CAPTURE_DEVICE 0
#define SOUND_CAPTURE_SCO_DEVICE 2
#define SOUND_PLAYBACK_VOICE_DEVICE 1
#define SOUND_CAPTURE_VOICE_DEVICE 1
#define SOUND_COMPRESS_OFFLOAD_DEVICE 11

#define SWAP_SPEAKER_ON_SCREEN_ROTATION 0
#define SUPPORTS_IRQ_AFFINITY 0

#ifdef RIL_UNSOL_SNDMGR_WB_AMR_REPORT
#undef RIL_UNSOL_SNDMGR_WB_AMR_REPORT
#endif
#define RIL_UNSOL_SNDMGR_WB_AMR_REPORT RIL_UNSOL_WB_AMR_STATE

#ifdef DISABLE_CALL_CLOCK_SYNC
#undef DISABLE_CALL_CLOCK_SYNC
#endif

#endif // SAMSUNG_AUDIO_H
