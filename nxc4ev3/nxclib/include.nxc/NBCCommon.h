/** \file NBCCommon.h
 * \brief Constants and macros common to both NBC and NXC
 *
 * NBCCommon.h contains declarations for the NBC and NXC NXT API functions.
 *
 * License:
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Initial Developer of this code is John Hansen.
 * Portions created by John Hansen are Copyright (C) 2009-2013 John Hansen.
 * All Rights Reserved.
 *
 * ----------------------------------------------------------------------------
 *
 * \author John Hansen (bricxcc_at_comcast.net)
 * \date 2013-02-16
 * \version 74
 * 
 * \author Faculty of Electrical Engineering, CTU in Prague (Jakub Vanek <nxc4ev3@vankovi.net>)
 * \date 2017-01-08
 */
 
#ifndef NBCCOMMON_H
#define NBCCOMMON_H
#define NA 0xFFFF 
#define RC_PROP_BTONOFF       0x0  
#define RC_PROP_SOUND_LEVEL   0x1  
#define RC_PROP_SLEEP_TIMEOUT 0x2  
#define RC_PROP_DEBUGGING     0xF  

#define VT_UBYTE     0x01  
#define VT_SBYTE     0x02  
#define VT_UWORD     0x03  
#define VT_SWORD     0x04  
#define VT_ULONG     0x05  
#define VT_SLONG     0x06  
#define VT_STRUCT    0x08  
#define VT_MUTEX     0x09  
#define VT_FLOAT     0x0A  
#define VT_A1_UBYTE  0x11  
#define VT_A1_SBYTE  0x12  
#define VT_A1_UWORD  0x13  
#define VT_A1_SWORD  0x14  
#define VT_A1_ULONG  0x15  
#define VT_A1_SLONG  0x16  
#define VT_A1_STRUCT 0x17  
#define VT_A1_FLOAT  0x1A  
#define VT_A2_UBYTE  0x21  
#define VT_A2_SBYTE  0x22  
#define VT_A2_UWORD  0x23  
#define VT_A2_SWORD  0x24  
#define VT_A2_ULONG  0x25  
#define VT_A2_SLONG  0x26  
#define VT_A2_STRUCT 0x27  
#define VT_A2_FLOAT  0x2A  
#define VT_ARRAY_MASK   0xF0  

#ifdef __ENHANCED_FIRMWARE
#define OPARR_SUM     0x00 
#define OPARR_MEAN    0x01 
#define OPARR_SUMSQR  0x02 
#define OPARR_STD     0x03 
#define OPARR_MIN     0x04 
#define OPARR_MAX     0x05 
#define OPARR_SORT    0x06 
#define OPARR_TOUPPER 0x07 
#define OPARR_TOLOWER 0x08 

#endif
#if __FIRMWARE_VERSION > 107
#define PI 3.141593               
#define RADIANS_PER_DEGREE PI/180 
#define DEGREES_PER_RADIAN 180/PI 
#endif

#if __FIRMWARE_VERSION <= 107
#define IO_BASE    0xC000
#define MOD_INPUT  0x0000
#define MOD_OUTPUT 0x0200
#define IO_IN_FPP  6
#define IO_OUT_FPP 15
#define InputIOType(p)            (IO_BASE+MOD_INPUT+TypeField+((p)*IO_IN_FPP))
#define InputIOInputMode(p)       (IO_BASE+MOD_INPUT+InputModeField+((p)*IO_IN_FPP))
#define InputIORawValue(p)        (IO_BASE+MOD_INPUT+RawValueField+((p)*IO_IN_FPP))
#define InputIONormalizedValue(p) (IO_BASE+MOD_INPUT+NormalizedValueField+((p)*IO_IN_FPP))
#define InputIOScaledValue(p)     (IO_BASE+MOD_INPUT+ScaledValueField+((p)*IO_IN_FPP))
#define InputIOInvalidData(p)     (IO_BASE+MOD_INPUT+InvalidDataField+((p)*IO_IN_FPP))
#define OutputIOUpdateFlags(p)     (IO_BASE+MOD_OUTPUT+UpdateFlagsField+((p)*IO_OUT_FPP))
#define OutputIOOutputMode(p)      (IO_BASE+MOD_OUTPUT+OutputModeField+((p)*IO_OUT_FPP))
#define OutputIOPower(p)           (IO_BASE+MOD_OUTPUT+PowerField+((p)*IO_OUT_FPP))
#define OutputIOActualSpeed(p)     (IO_BASE+MOD_OUTPUT+ActualSpeedField+((p)*IO_OUT_FPP))
#define OutputIOTachoCount(p)      (IO_BASE+MOD_OUTPUT+TachoCountField+((p)*IO_OUT_FPP))
#define OutputIOTachoLimit(p)      (IO_BASE+MOD_OUTPUT+TachoLimitField+((p)*IO_OUT_FPP))
#define OutputIORunState(p)        (IO_BASE+MOD_OUTPUT+RunStateField+((p)*IO_OUT_FPP))
#define OutputIOTurnRatio(p)       (IO_BASE+MOD_OUTPUT+TurnRatioField+((p)*IO_OUT_FPP))
#define OutputIORegMode(p)         (IO_BASE+MOD_OUTPUT+RegModeField+((p)*IO_OUT_FPP))
#define OutputIOOverload(p)        (IO_BASE+MOD_OUTPUT+OverloadField+((p)*IO_OUT_FPP))
#define OutputIORegPValue(p)       (IO_BASE+MOD_OUTPUT+RegPValueField+((p)*IO_OUT_FPP))
#define OutputIORegIValue(p)       (IO_BASE+MOD_OUTPUT+RegIValueField+((p)*IO_OUT_FPP))
#define OutputIORegDValue(p)       (IO_BASE+MOD_OUTPUT+RegDValueField+((p)*IO_OUT_FPP))
#define OutputIOBlockTachoCount(p) (IO_BASE+MOD_OUTPUT+BlockTachoCountField+((p)*IO_OUT_FPP))
#define OutputIORotationCount(p)   (IO_BASE+MOD_OUTPUT+RotationCountField+((p)*IO_OUT_FPP))
#define InputIOType0             0xc000
#define InputIOInputMode0        0xc001
#define InputIORawValue0         0xc002
#define InputIONormalizedValue0  0xc003
#define InputIOScaledValue0      0xc004
#define InputIOInvalidData0      0xc005
#define InputIOType1             0xc006
#define InputIOInputMode1        0xc007
#define InputIORawValue1         0xc008
#define InputIONormalizedValue1  0xc009
#define InputIOScaledValue1      0xc00a
#define InputIOInvalidData1      0xc00b
#define InputIOType2             0xc00c
#define InputIOInputMode2        0xc00d
#define InputIORawValue2         0xc00e
#define InputIONormalizedValue2  0xc00f
#define InputIOScaledValue2      0xc010
#define InputIOInvalidData2      0xc011
#define InputIOType3             0xc012
#define InputIOInputMode3        0xc013
#define InputIORawValue3         0xc014
#define InputIONormalizedValue3  0xc015
#define InputIOScaledValue3      0xc016
#define InputIOInvalidData3      0xc017
#define OutputIOUpdateFlags0     0xc200
#define OutputIOOutputMode0      0xc201
#define OutputIOPower0           0xc202
#define OutputIOActualSpeed0     0xc203
#define OutputIOTachoCount0      0xc204
#define OutputIOTachoLimit0      0xc205
#define OutputIORunState0        0xc206
#define OutputIOTurnRatio0       0xc207
#define OutputIORegMode0         0xc208
#define OutputIOOverload0        0xc209
#define OutputIORegPValue0       0xc20a
#define OutputIORegIValue0       0xc20b
#define OutputIORegDValue0       0xc20c
#define OutputIOBlockTachoCount0 0xc20d
#define OutputIORotationCount0   0xc20e
#define OutputIOUpdateFlags1     0xc20f
#define OutputIOOutputMode1      0xc210
#define OutputIOPower1           0xc211
#define OutputIOActualSpeed1     0xc212
#define OutputIOTachoCount1      0xc213
#define OutputIOTachoLimit1      0xc214
#define OutputIORunState1        0xc215
#define OutputIOTurnRatio1       0xc216
#define OutputIORegMode1         0xc217
#define OutputIOOverload1        0xc218
#define OutputIORegPValue1       0xc219
#define OutputIORegIValue1       0xc21a
#define OutputIORegDValue1       0xc21b
#define OutputIOBlockTachoCount1 0xc21c
#define OutputIORotationCount1   0xc21d
#define OutputIOUpdateFlags2     0xc21e
#define OutputIOOutputMode2      0xc21f
#define OutputIOPower2           0xc220
#define OutputIOActualSpeed2     0xc221
#define OutputIOTachoCount2      0xc222
#define OutputIOTachoLimit2      0xc223
#define OutputIORunState2        0xc224
#define OutputIOTurnRatio2       0xc225
#define OutputIORegMode2         0xc226
#define OutputIOOverload2        0xc227
#define OutputIORegPValue2       0xc228
#define OutputIORegIValue2       0xc229
#define OutputIORegDValue2       0xc22a
#define OutputIOBlockTachoCount2 0xc22b
#define OutputIORotationCount2   0xc22c

#endif
#define FileOpenRead       0 
#define FileOpenWrite      1 
#define FileOpenAppend     2 
#define FileRead           3 
#define FileWrite          4 
#define FileClose          5 
#define FileResolveHandle  6 
#define FileRename         7 
#define FileDelete         8 
#define SoundPlayFile      9 
#define SoundPlayTone     10 
#define SoundGetState     11 
#define SoundSetState     12 
#define DrawText          13 
#define DrawPoint         14 
#define DrawLine          15 
#define DrawCircle        16 
#define DrawRect          17 
#define DrawGraphic       18 
#define SetScreenMode     19 
#define ReadButton        20 
#define CommLSWrite       21 
#define CommLSRead        22 
#define CommLSCheckStatus 23 
#define RandomNumber      24 
#define GetStartTick      25 
#define MessageWrite      26 
#define MessageRead       27 
#define CommBTCheckStatus 28 
#define CommBTWrite       29 
#define CommBTRead        30 
#define KeepAlive         31 
#define IOMapRead         32 
#define IOMapWrite        33 
#if __FIRMWARE_VERSION <= 107
#ifdef __ENHANCED_FIRMWARE
#define IOMapReadByID          34
#define IOMapWriteByID         35
#define DisplayExecuteFunction 36
#define CommExecuteFunction    37
#define LoaderExecuteFunction  38
#define FileFindFirst          39
#define FileFindNext           40
#define FileOpenWriteLinear    41
#define FileOpenWriteNonLinear 42
#define FileOpenReadLinear     43
#define CommHSControl          44
#define CommHSCheckStatus      45
#define CommHSWrite            46
#define CommHSRead             47 
#endif
#else
#define ColorSensorRead        34 
#define CommBTOnOff            35 
#define CommBTConnection       36 
#define CommHSWrite            37 
#define CommHSRead             38 
#define CommHSCheckStatus      39 
#define ReadSemData            40 
#define WriteSemData           41 
#define ComputeCalibValue      42 
#define UpdateCalibCacheInfo   43 
#define DatalogWrite           44 
#define DatalogGetTimes        45 
#define SetSleepTimeoutVal     46 
#define ListFiles              47 
#ifdef __ENHANCED_FIRMWARE
#define InputPinFunction       77 
#define IOMapReadByID          78 
#define IOMapWriteByID         79 
#define DisplayExecuteFunction 80 
#define CommExecuteFunction    81 
#define LoaderExecuteFunction  82 
#define FileFindFirst          83 
#define FileFindNext           84 
#define FileOpenWriteLinear    85 
#define FileOpenWriteNonLinear 86 
#define FileOpenReadLinear     87 
#define CommHSControl          88 
#define CommLSWriteEx          89 
#define FileSeek               90 
#define FileResize             91 
#define DrawGraphicArray       92 
#define DrawPolygon            93 
#define DrawEllipse            94 
#define DrawFont               95 
#define MemoryManager          96 
#define ReadLastResponse       97 
#define FileTell               98 
#define RandomEx               99 
#endif
#endif

#define LCD_LINE8  0 
#define LCD_LINE7  8 
#define LCD_LINE6 16 
#define LCD_LINE5 24 
#define LCD_LINE4 32 
#define LCD_LINE3 40 
#define LCD_LINE2 48 
#define LCD_LINE1 56 

#define MS_1        1 
#define MS_2        2 
#define MS_3        3 
#define MS_4        4 
#define MS_5        5 
#define MS_6        6 
#define MS_7        7 
#define MS_8        8 
#define MS_9        9 
#define MS_10      10 
#define MS_20      20 
#define MS_30      30 
#define MS_40      40 
#define MS_50      50 
#define MS_60      60 
#define MS_70      70 
#define MS_80      80 
#define MS_90      90 
#define MS_100    100 
#define MS_150    150 
#define MS_200    200 
#define MS_250    250 
#define MS_300    300 
#define MS_350    350 
#define MS_400    400 
#define MS_450    450 
#define MS_500    500 
#define MS_600    600 
#define MS_700    700 
#define MS_800    800 
#define MS_900    900 
#define SEC_1    1000 
#define SEC_2    2000 
#define SEC_3    3000 
#define SEC_4    4000 
#define SEC_5    5000 
#define SEC_6    6000 
#define SEC_7    7000 
#define SEC_8    8000 
#define SEC_9    9000 
#define SEC_10  10000 
#define SEC_15  15000 
#define SEC_20  20000 
#define SEC_30  30000 
#define MIN_1   60000 
#define NOTE_WHOLE   1000            
#define NOTE_HALF    (NOTE_WHOLE/2)  
#define NOTE_QUARTER (NOTE_WHOLE/4)  
#define NOTE_EIGHT   (NOTE_WHOLE/8)  
#define NOTE_SIXTEEN (NOTE_WHOLE/16) 

#define MAILBOX1  0 
#define MAILBOX2  1 
#define MAILBOX3  2 
#define MAILBOX4  3 
#define MAILBOX5  4 
#define MAILBOX6  5 
#define MAILBOX7  6 
#define MAILBOX8  7 
#define MAILBOX9  8 
#define MAILBOX10 9 

#define CommandModuleName  "Command.mod"   
#define IOCtrlModuleName   "IOCtrl.mod"    
#define LoaderModuleName   "Loader.mod"    
#define SoundModuleName    "Sound.mod"     
#define ButtonModuleName   "Button.mod"    
#define UIModuleName       "Ui.mod"        
#define InputModuleName    "Input.mod"     
#define OutputModuleName   "Output.mod"    
#define LowSpeedModuleName "Low Speed.mod" 
#define DisplayModuleName  "Display.mod"   
#define CommModuleName     "Comm.mod"      

#define CommandModuleID  0x00010001 
#define IOCtrlModuleID   0x00060001 
#define LoaderModuleID   0x00090001 
#define SoundModuleID    0x00080001 
#define ButtonModuleID   0x00040001 
#define UIModuleID       0x000C0001 
#define InputModuleID    0x00030001 
#define OutputModuleID   0x00020001 
#define LowSpeedModuleID 0x000B0001 
#define DisplayModuleID  0x000A0001 
#define CommModuleID     0x00050001 

#define STAT_MSG_EMPTY_MAILBOX 64 
#define STAT_COMM_PENDING 32      
#define POOL_MAX_SIZE 32768      
#define TIMES_UP      6 
#define ROTATE_QUEUE  5 
#define STOP_REQ      4 
#define BREAKOUT_REQ  3 
#define CLUMP_SUSPEND 2 
#define CLUMP_DONE    1 

#define NO_ERR        0 
#define ERR_ARG             -1 
#define ERR_INSTR           -2 
#define ERR_FILE            -3 
#define ERR_VER             -4 
#define ERR_MEM             -5 
#define ERR_BAD_PTR         -6 
#define ERR_CLUMP_COUNT     -7 
#define ERR_NO_CODE         -8 
#define ERR_INSANE_OFFSET   -9 
#define ERR_BAD_POOL_SIZE   -10 
#define ERR_LOADER_ERR      -11 
#define ERR_SPOTCHECK_FAIL  -12 
#define ERR_NO_ACTIVE_CLUMP -13 
#define ERR_DEFAULT_OFFSETS -14 
#define ERR_MEMMGR_FAIL     -15 
#define ERR_NON_FATAL -16 

#define ERR_INVALID_PORT   -16 
#define ERR_INVALID_FIELD  -17 
#define ERR_INVALID_QUEUE  -18 
#define ERR_INVALID_SIZE   -19 
#define ERR_NO_PROG        -20 

#define ERR_COMM_CHAN_NOT_READY -32 
#define ERR_COMM_CHAN_INVALID   -33 
#define ERR_COMM_BUFFER_FULL    -34 
#define ERR_COMM_BUS_ERR        -35 

#define ERR_RC_ILLEGAL_VAL -64 
#define ERR_RC_BAD_PACKET  -65 
#define ERR_RC_UNKNOWN_CMD -66 
#define ERR_RC_FAILED      -67 

#define PROG_IDLE     0 
#define PROG_OK       1 
#define PROG_RUNNING  2 
#define PROG_ERROR    3 
#define PROG_ABORT    4 
#define PROG_RESET    5 

#define CommandOffsetFormatString   0 
#define CommandOffsetPRCHandler     16 
#define CommandOffsetTick           20 
#define CommandOffsetOffsetDS       24 
#define CommandOffsetOffsetDVA      26 
#define CommandOffsetProgStatus     28 
#define CommandOffsetAwake          29 
#define CommandOffsetActivateFlag   30 
#define CommandOffsetDeactivateFlag 31 
#define CommandOffsetFileName       32 
#define CommandOffsetMemoryPool     52 
#if __FIRMWARE_VERSION > 107
#define CommandOffsetSyncTime       32820 
#define CommandOffsetSyncTick       32824 
#endif

#define IOCTRL_POWERDOWN  0x5A00 
#define IOCTRL_BOOT       0xA55A 

#define IOCtrlOffsetPowerOn 0 

#define LoaderOffsetPFunc         0 
#define LoaderOffsetFreeUserFlash 4 

#define EOF -1 
#define NULL 0 
#define LDR_SUCCESS             0x0000 
#define LDR_INPROGRESS          0x0001 
#define LDR_REQPIN              0x0002 
#define LDR_NOMOREHANDLES       0x8100 
#define LDR_NOSPACE             0x8200 
#define LDR_NOMOREFILES         0x8300 
#define LDR_EOFEXPECTED         0x8400 
#define LDR_ENDOFFILE           0x8500 
#define LDR_NOTLINEARFILE       0x8600 
#define LDR_FILENOTFOUND        0x8700 
#define LDR_HANDLEALREADYCLOSED 0x8800 
#define LDR_NOLINEARSPACE       0x8900 
#define LDR_UNDEFINEDERROR      0x8A00 
#define LDR_FILEISBUSY          0x8B00 
#define LDR_NOWRITEBUFFERS      0x8C00 
#define LDR_APPENDNOTPOSSIBLE   0x8D00 
#define LDR_FILEISFULL          0x8E00 
#define LDR_FILEEXISTS          0x8F00 
#define LDR_MODULENOTFOUND      0x9000 
#define LDR_OUTOFBOUNDARY       0x9100 
#define LDR_ILLEGALFILENAME     0x9200 
#define LDR_ILLEGALHANDLE       0x9300 
#define LDR_BTBUSY              0x9400 
#define LDR_BTCONNECTFAIL       0x9500 
#define LDR_BTTIMEOUT           0x9600 
#define LDR_FILETX_TIMEOUT      0x9700 
#define LDR_FILETX_DSTEXISTS    0x9800 
#define LDR_FILETX_SRCMISSING   0x9900 
#define LDR_FILETX_STREAMERROR  0x9A00 
#define LDR_FILETX_CLOSEERROR   0x9B00 
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define LDR_INVALIDSEEK         0x9C00 
#endif

#define LDR_CMD_OPENREAD        0x80 
#define LDR_CMD_OPENWRITE       0x81 
#define LDR_CMD_READ            0x82 
#define LDR_CMD_WRITE           0x83 
#define LDR_CMD_CLOSE           0x84 
#define LDR_CMD_DELETE          0x85 
#define LDR_CMD_FINDFIRST       0x86 
#define LDR_CMD_FINDNEXT        0x87 
#define LDR_CMD_VERSIONS        0x88 
#define LDR_CMD_OPENWRITELINEAR 0x89 
#define LDR_CMD_OPENREADLINEAR  0x8A 
#define LDR_CMD_OPENWRITEDATA   0x8B 
#define LDR_CMD_OPENAPPENDDATA  0x8C 
#if __FIRMWARE_VERSION > 107
#define LDR_CMD_CROPDATAFILE    0x8D 
#endif
#define LDR_CMD_FINDFIRSTMODULE 0x90 
#define LDR_CMD_FINDNEXTMODULE  0x91 
#define LDR_CMD_CLOSEMODHANDLE  0x92 
#define LDR_CMD_IOMAPREAD       0x94 
#define LDR_CMD_IOMAPWRITE      0x95 
#define LDR_CMD_BOOTCMD         0x97 
#define LDR_CMD_SETBRICKNAME    0x98 
#define LDR_CMD_BTGETADR        0x9A 
#define LDR_CMD_DEVICEINFO      0x9B 
#define LDR_CMD_DELETEUSERFLASH 0xA0 
#define LDR_CMD_POLLCMDLEN      0xA1 
#define LDR_CMD_POLLCMD         0xA2 
#define LDR_CMD_RENAMEFILE      0xA3 
#define LDR_CMD_BTFACTORYRESET  0xA4 
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define LDR_CMD_RESIZEDATAFILE  0xD0 
#define LDR_CMD_SEEKFROMSTART   0xD1 
#define LDR_CMD_SEEKFROMCURRENT 0xD2 
#define LDR_CMD_SEEKFROMEND     0xD3 
#endif

#define SOUND_FLAGS_IDLE    0x00 
#define SOUND_FLAGS_UPDATE  0x01 
#define SOUND_FLAGS_RUNNING 0x02 

#define SOUND_STATE_IDLE 0x00 
#define SOUND_STATE_FILE 0x02 
#define SOUND_STATE_TONE 0x03 
#define SOUND_STATE_STOP 0x04 

#define SOUND_MODE_ONCE 0x00 
#define SOUND_MODE_LOOP 0x01 
#define SOUND_MODE_TONE 0x02 

#define SoundOffsetFreq           0 
#define SoundOffsetDuration       2 
#define SoundOffsetSampleRate     4 
#define SoundOffsetSoundFilename  6 
#define SoundOffsetFlags         26 
#define SoundOffsetState         27 
#define SoundOffsetMode          28 
#define SoundOffsetVolume        29 

#define FREQUENCY_MIN       220       
#define FREQUENCY_MAX       14080     
#define SAMPLERATE_MIN      2000      
#define SAMPLERATE_DEFAULT  8000      
#define SAMPLERATE_MAX      16000     

#define TONE_C3      131 
#define TONE_CS3     139 
#define TONE_D3      147 
#define TONE_DS3     156 
#define TONE_E3      165 
#define TONE_F3      175 
#define TONE_FS3     185 
#define TONE_G3      196 
#define TONE_GS3     208 
#define TONE_A3      220 
#define TONE_AS3     233 
#define TONE_B3      247 
#define TONE_C4      262 
#define TONE_CS4     277 
#define TONE_D4      294 
#define TONE_DS4     311 
#define TONE_E4      330 
#define TONE_F4      349 
#define TONE_FS4     370 
#define TONE_G4      392 
#define TONE_GS4     415 
#define TONE_A4      440 
#define TONE_AS4     466 
#define TONE_B4      494 
#define TONE_C5      523 
#define TONE_CS5     554 
#define TONE_D5      587 
#define TONE_DS5     622 
#define TONE_E5      659 
#define TONE_F5      698 
#define TONE_FS5     740 
#define TONE_G5      784 
#define TONE_GS5     831 
#define TONE_A5      880 
#define TONE_AS5     932 
#define TONE_B5      988 
#define TONE_C6     1047 
#define TONE_CS6    1109 
#define TONE_D6     1175 
#define TONE_DS6    1245 
#define TONE_E6     1319 
#define TONE_F6     1397 
#define TONE_FS6    1480 
#define TONE_G6     1568 
#define TONE_GS6    1661 
#define TONE_A6     1760 
#define TONE_AS6    1865 
#define TONE_B6     1976 
#define TONE_C7     2093 
#define TONE_CS7    2217 
#define TONE_D7     2349 
#define TONE_DS7    2489 
#define TONE_E7     2637 
#define TONE_F7     2794 
#define TONE_FS7    2960 
#define TONE_G7     3136 
#define TONE_GS7    3322 
#define TONE_A7     3520 
#define TONE_AS7    3729 
#define TONE_B7     3951 

#define BTN1 0 
#define BTN2 1 
#define BTN3 2 
#define BTN4 3 
#define BTNEXIT   BTN1 
#define BTNRIGHT  BTN2 
#define BTNLEFT   BTN3 
#define BTNCENTER BTN4 
#define NO_OF_BTNS 4 

#define BTNSTATE_PRESSED_EV         0x01 
#define BTNSTATE_SHORT_RELEASED_EV  0x02 
#define BTNSTATE_LONG_PRESSED_EV    0x04 
#define BTNSTATE_LONG_RELEASED_EV   0x08 
#define BTNSTATE_PRESSED_STATE      0x80 
#define BTNSTATE_NONE               0x10 

#define ButtonOffsetPressedCnt(b)   (((b)*8)+0) 
#define ButtonOffsetLongPressCnt(b) (((b)*8)+1) 
#define ButtonOffsetShortRelCnt(b)  (((b)*8)+2) 
#define ButtonOffsetLongRelCnt(b)   (((b)*8)+3) 
#define ButtonOffsetRelCnt(b)       (((b)*8)+4) 
#define ButtonOffsetState(b)        ((b)+32)    

#define UI_FLAGS_UPDATE                   0x01 
#define UI_FLAGS_DISABLE_LEFT_RIGHT_ENTER 0x02 
#define UI_FLAGS_DISABLE_EXIT             0x04 
#define UI_FLAGS_REDRAW_STATUS            0x08 
#define UI_FLAGS_RESET_SLEEP_TIMER        0x10 
#define UI_FLAGS_EXECUTE_LMS_FILE         0x20 
#define UI_FLAGS_BUSY                     0x40 
#define UI_FLAGS_ENABLE_STATUS_UPDATE     0x80 

#define UI_STATE_INIT_DISPLAY       0 
#define UI_STATE_INIT_LOW_BATTERY   1 
#define UI_STATE_INIT_INTRO         2 
#define UI_STATE_INIT_WAIT          3 
#define UI_STATE_INIT_MENU          4 
#define UI_STATE_NEXT_MENU          5 
#define UI_STATE_DRAW_MENU          6 
#define UI_STATE_TEST_BUTTONS       7 
#define UI_STATE_LEFT_PRESSED       8 
#define UI_STATE_RIGHT_PRESSED      9 
#define UI_STATE_ENTER_PRESSED     10 
#define UI_STATE_EXIT_PRESSED      11 
#define UI_STATE_CONNECT_REQUEST   12 
#define UI_STATE_EXECUTE_FILE      13 
#define UI_STATE_EXECUTING_FILE    14 
#define UI_STATE_LOW_BATTERY       15 
#define UI_STATE_BT_ERROR          16 

#define UI_BUTTON_NONE             0 
#define UI_BUTTON_LEFT             1 
#define UI_BUTTON_ENTER            2 
#define UI_BUTTON_RIGHT            3 
#define UI_BUTTON_EXIT             4 

#define UI_BT_STATE_VISIBLE        0x01 
#define UI_BT_STATE_CONNECTED      0x02 
#define UI_BT_STATE_OFF            0x04 
#define UI_BT_ERROR_ATTENTION      0x08 
#define UI_BT_CONNECT_REQUEST      0x40 
#define UI_BT_PIN_REQUEST          0x80 

#define UI_VM_IDLE        0 
#define UI_VM_RUN_FREE    1 
#define UI_VM_RUN_SINGLE  2 
#define UI_VM_RUN_PAUSE   3 
#define UI_VM_RESET1      4 
#define UI_VM_RESET2      5 

#define UIOffsetPMenu            0 
#define UIOffsetBatteryVoltage   4 
#define UIOffsetLMSfilename      6 
#define UIOffsetFlags           26 
#define UIOffsetState           27 
#define UIOffsetButton          28 
#define UIOffsetRunState        29 
#define UIOffsetBatteryState    30 
#define UIOffsetBluetoothState  31 
#define UIOffsetUsbState        32 
#define UIOffsetSleepTimeout    33 
#define UIOffsetSleepTimer      34 
#define UIOffsetRechargeable    35 
#define UIOffsetVolume          36 
#define UIOffsetError           37 
#define UIOffsetOBPPointer      38 
#define UIOffsetForceOff        39 
#define UIOffsetAbortFlag       40 

#define IN_1 0x00 
#define IN_2 0x01 
#define IN_3 0x02 
#define IN_4 0x03 
#define S1   IN_1 
#define S2   IN_2 
#define S3   IN_3 
#define S4   IN_4 

#define IN_TYPE_NO_SENSOR      0x00 
#define IN_TYPE_SWITCH         0x01 
#define IN_TYPE_TEMPERATURE    0x02 
#define IN_TYPE_REFLECTION     0x03 
#define IN_TYPE_ANGLE          0x04 
#define IN_TYPE_LIGHT_ACTIVE   0x05 
#define IN_TYPE_LIGHT_INACTIVE 0x06 
#define IN_TYPE_SOUND_DB       0x07 
#define IN_TYPE_SOUND_DBA      0x08 
#define IN_TYPE_CUSTOM         0x09 
#define IN_TYPE_LOWSPEED       0x0A 
#define IN_TYPE_LOWSPEED_9V    0x0B 
#define IN_TYPE_HISPEED        0x0C 
#if __FIRMWARE_VERSION > 107
#define IN_TYPE_COLORFULL      0x0D 
#define IN_TYPE_COLORRED       0x0E 
#define IN_TYPE_COLORGREEN     0x0F 
#define IN_TYPE_COLORBLUE      0x10 
#define IN_TYPE_COLORNONE      0x11 
#define IN_TYPE_COLOREXIT      0x12 
#endif

#define IN_MODE_RAW           0x00 
#define IN_MODE_BOOLEAN       0x20 
#define IN_MODE_TRANSITIONCNT 0x40 
#define IN_MODE_PERIODCOUNTER 0x60 
#define IN_MODE_PCTFULLSCALE  0x80 
#define IN_MODE_CELSIUS       0xA0 
#define IN_MODE_FAHRENHEIT    0xC0 
#define IN_MODE_ANGLESTEP     0xE0 
#define IN_MODE_SLOPEMASK     0x1F 
#define IN_MODE_MODEMASK      0xE0 

#define TypeField            0 
#define InputModeField       1 
#define RawValueField        2 
#define NormalizedValueField 3 
#define ScaledValueField     4 
#define InvalidDataField     5 

#define INPUT_DIGI0    0x01 
#define INPUT_DIGI1    0x02 

#define INPUT_CUSTOMINACTIVE 0x00 
#define INPUT_CUSTOM9V       0x01 
#define INPUT_CUSTOMACTIVE   0x02 
#define INPUT_INVALID_DATA   0x01 
#if __FIRMWARE_VERSION > 107
#define INPUT_RED          0 
#define INPUT_GREEN        1 
#define INPUT_BLUE         2 
#define INPUT_BLANK        3 
#define INPUT_NO_OF_COLORS 4 

#define INPUT_BLACKCOLOR  1 
#define INPUT_BLUECOLOR   2 
#define INPUT_GREENCOLOR  3 
#define INPUT_YELLOWCOLOR 4 
#define INPUT_REDCOLOR    5 
#define INPUT_WHITECOLOR  6 

#define INPUT_SENSORCAL  0x01 
#define INPUT_SENSOROFF  0x02 
#define INPUT_RUNNINGCAL 0x20 
#define INPUT_STARTCAL   0x40 
#define INPUT_RESETCAL   0x80 

#define INPUT_CAL_POINT_0  0 
#define INPUT_CAL_POINT_1  1 
#define INPUT_CAL_POINT_2  2 
#define INPUT_NO_OF_POINTS 3 

#endif
#define InputOffsetCustomZeroOffset(p)   (((p)*20)+0)  
#define InputOffsetADRaw(p)              (((p)*20)+2)  
#define InputOffsetSensorRaw(p)          (((p)*20)+4)  
#define InputOffsetSensorValue(p)        (((p)*20)+6)  
#define InputOffsetSensorType(p)         (((p)*20)+8)  
#define InputOffsetSensorMode(p)         (((p)*20)+9)  
#define InputOffsetSensorBoolean(p)      (((p)*20)+10) 
#define InputOffsetDigiPinsDir(p)        (((p)*20)+11) 
#define InputOffsetDigiPinsIn(p)         (((p)*20)+12) 
#define InputOffsetDigiPinsOut(p)        (((p)*20)+13) 
#define InputOffsetCustomPctFullScale(p) (((p)*20)+14) 
#define InputOffsetCustomActiveStatus(p) (((p)*20)+15) 
#define InputOffsetInvalidData(p)        (((p)*20)+16) 
#if __FIRMWARE_VERSION > 107
#define InputOffsetColorCalibration(p, np, nc) (80+((p)*84)+0+((np)*16)+((nc)*4)) 
#define InputOffsetColorCalLimits(p, np)       (80+((p)*84)+48+((np)*2)) 
#define InputOffsetColorADRaw(p, nc)           (80+((p)*84)+52+((nc)*2)) 
#define InputOffsetColorSensorRaw(p, nc)       (80+((p)*84)+60+((nc)*2)) 
#define InputOffsetColorSensorValue(p, nc)     (80+((p)*84)+68+((nc)*2)) 
#define InputOffsetColorBoolean(p, nc)         (80+((p)*84)+76+((nc)*2)) 
#define InputOffsetColorCalibrationState(p)    (80+((p)*84)+80)          
#endif

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define INPUT_PINCMD_DIR    0x00 
#define INPUT_PINCMD_SET    0x01 
#define INPUT_PINCMD_CLEAR  0x02 
#define INPUT_PINCMD_READ   0x03 
#define INPUT_PINCMD_MASK   0x03 
#define INPUT_PINCMD_WAIT(_usec) ((_usec)<<2) 
#define INPUT_PINDIR_OUTPUT 0x00 
#define INPUT_PINDIR_INPUT  0x04 

#endif

#define OUT_A   0x00 
#define OUT_B   0x01 
#define OUT_C   0x02 
#define OUT_AB  0x03 
#define OUT_AC  0x04 
#define OUT_BC  0x05 
#define OUT_ABC 0x06 

#define PID_0   0 
#define PID_1  32 
#define PID_2  64 
#define PID_3  96 
#define PID_4 128 
#define PID_5 160 
#define PID_6 192 
#define PID_7 224 

#define UF_UPDATE_MODE                 0x01 
#define UF_UPDATE_SPEED                0x02 
#define UF_UPDATE_TACHO_LIMIT          0x04 
#define UF_UPDATE_RESET_COUNT          0x08 
#define UF_UPDATE_PID_VALUES           0x10 
#define UF_UPDATE_RESET_BLOCK_COUNT    0x20 
#define UF_UPDATE_RESET_ROTATION_COUNT 0x40 
#define UF_PENDING_UPDATES             0x80 

#define RESET_NONE           0x00 
#define RESET_COUNT          0x08 
#define RESET_BLOCK_COUNT    0x20 
#define RESET_ROTATION_COUNT 0x40 
#define RESET_BLOCKANDTACHO  0x28 
#define RESET_ALL            0x68 

#define OUT_MODE_COAST     0x00 
#define OUT_MODE_MOTORON   0x01 
#define OUT_MODE_BRAKE     0x02 
#define OUT_MODE_REGULATED 0x04 
#define OUT_MODE_REGMETHOD 0xF0 

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OUT_OPTION_HOLDATLIMIT     0x10 
#define OUT_OPTION_RAMPDOWNTOLIMIT 0x20 

#define OUT_REGOPTION_NO_SATURATION 0x01 

#endif
#define OUT_RUNSTATE_IDLE     0x00 
#define OUT_RUNSTATE_RAMPUP   0x10 
#define OUT_RUNSTATE_RUNNING  0x20 
#define OUT_RUNSTATE_RAMPDOWN 0x40 
#define OUT_RUNSTATE_HOLD     0x60 

#define OUT_REGMODE_IDLE  0 
#define OUT_REGMODE_SPEED 1 
#define OUT_REGMODE_SYNC  2 
#define OUT_REGMODE_POS   4 

#define UpdateFlagsField     0
#define OutputModeField      1
#define PowerField           2
#define ActualSpeedField     3
#define TachoCountField      4
#define TachoLimitField      5
#define RunStateField        6
#define TurnRatioField       7
#define RegModeField         8
#define OverloadField        9
#define RegPValueField       10
#define RegIValueField       11
#define RegDValueField       12
#define BlockTachoCountField 13
#define RotationCountField   14
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OutputOptionsField   15
#define MaxSpeedField   16
#define MaxAccelerationField   17
#endif

#define OutputOffsetTachoCount(p)        (((p)*32)+0)  
#define OutputOffsetBlockTachoCount(p)   (((p)*32)+4)  
#define OutputOffsetRotationCount(p)     (((p)*32)+8)  
#define OutputOffsetTachoLimit(p)        (((p)*32)+12) 
#define OutputOffsetMotorRPM(p)          (((p)*32)+16) 
#define OutputOffsetFlags(p)             (((p)*32)+18) 
#define OutputOffsetMode(p)              (((p)*32)+19) 
#define OutputOffsetSpeed(p)             (((p)*32)+20) 
#define OutputOffsetActualSpeed(p)       (((p)*32)+21) 
#define OutputOffsetRegPParameter(p)     (((p)*32)+22) 
#define OutputOffsetRegIParameter(p)     (((p)*32)+23) 
#define OutputOffsetRegDParameter(p)     (((p)*32)+24) 
#define OutputOffsetRunState(p)          (((p)*32)+25) 
#define OutputOffsetRegMode(p)           (((p)*32)+26) 
#define OutputOffsetOverloaded(p)        (((p)*32)+27) 
#define OutputOffsetSyncTurnParameter(p) (((p)*32)+28) 
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OutputOffsetOptions(p)           (((p)*32)+29) 
#define OutputOffsetMaxSpeed(p)          (((p)*32)+30) 
#define OutputOffsetMaxAccel(p)          (((p)*32)+31) 
#endif
#define OutputOffsetRegulationTime       96 
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define OutputOffsetRegulationOptions    97 
#endif

#define COM_CHANNEL_NONE_ACTIVE  0x00 
#define COM_CHANNEL_ONE_ACTIVE   0x01 
#define COM_CHANNEL_TWO_ACTIVE   0x02 
#define COM_CHANNEL_THREE_ACTIVE 0x04 
#define COM_CHANNEL_FOUR_ACTIVE  0x08 

#define LOWSPEED_IDLE          0 
#define LOWSPEED_INIT          1 
#define LOWSPEED_LOAD_BUFFER   2 
#define LOWSPEED_COMMUNICATING 3 
#define LOWSPEED_ERROR         4 
#define LOWSPEED_DONE          5 

#define LOWSPEED_TRANSMITTING   1 
#define LOWSPEED_RECEIVING      2 
#define LOWSPEED_DATA_RECEIVED  3 

#define LOWSPEED_NO_ERROR     0 
#define LOWSPEED_CH_NOT_READY 1 
#define LOWSPEED_TX_ERROR     2 
#define LOWSPEED_RX_ERROR     3 

#define LowSpeedOffsetInBufBuf(p)       (((p)*19)+0)  
#define LowSpeedOffsetInBufInPtr(p)     (((p)*19)+16) 
#define LowSpeedOffsetInBufOutPtr(p)    (((p)*19)+17) 
#define LowSpeedOffsetInBufBytesToRx(p) (((p)*19)+18) 
#define LowSpeedOffsetOutBufBuf(p)       (((p)*19)+76) 
#define LowSpeedOffsetOutBufInPtr(p)     (((p)*19)+92) 
#define LowSpeedOffsetOutBufOutPtr(p)    (((p)*19)+93) 
#define LowSpeedOffsetOutBufBytesToRx(p) (((p)*19)+94) 
#define LowSpeedOffsetMode(p)            ((p)+152) 
#define LowSpeedOffsetChannelState(p)    ((p)+156) 
#define LowSpeedOffsetErrorType(p)       ((p)+160) 
#define LowSpeedOffsetState            164 
#define LowSpeedOffsetSpeed            165 
#ifdef __ENHANCED_FIRMWARE
#define LowSpeedOffsetNoRestartOnRead  166 
#endif

#ifdef __ENHANCED_FIRMWARE
#define LSREAD_RESTART_ALL     0x00 
#define LSREAD_NO_RESTART_1    0x01 
#define LSREAD_NO_RESTART_2    0x02 
#define LSREAD_NO_RESTART_3    0x04 
#define LSREAD_NO_RESTART_4    0x08 
#define LSREAD_RESTART_NONE    0x0F 
#define LSREAD_NO_RESTART_MASK 0x10 
#endif

#define I2C_ADDR_DEFAULT  0x02 
#define I2C_REG_VERSION   0x00 
#define I2C_REG_VENDOR_ID 0x08 
#define I2C_REG_DEVICE_ID 0x10 
#define I2C_REG_CMD       0x41 

#define LEGO_ADDR_US         0x02 
#define LEGO_ADDR_TEMP       0x98 
#define LEGO_ADDR_EMETER     0x04 

#define US_CMD_OFF           0x00 
#define US_CMD_SINGLESHOT    0x01 
#define US_CMD_CONTINUOUS    0x02 
#define US_CMD_EVENTCAPTURE  0x03 
#define US_CMD_WARMRESET     0x04 
#define US_REG_CM_INTERVAL   0x40 
#define US_REG_ACTUAL_ZERO   0x50 
#define US_REG_SCALE_FACTOR  0x51 
#define US_REG_SCALE_DIVISOR 0x52 
#define US_REG_FACTORY_ACTUAL_ZERO   0x11 
#define US_REG_FACTORY_SCALE_FACTOR  0x12 
#define US_REG_FACTORY_SCALE_DIVISOR 0x13 
#define US_REG_MEASUREMENT_UNITS     0x14 

#define TEMP_RES_9BIT      0x00 
#define TEMP_RES_10BIT     0x20 
#define TEMP_RES_11BIT     0x40 
#define TEMP_RES_12BIT     0x60 
#define TEMP_SD_CONTINUOUS 0x00 
#define TEMP_SD_SHUTDOWN   0x01 
#define TEMP_TM_COMPARATOR 0x00 
#define TEMP_TM_INTERRUPT  0x02 
#define TEMP_OS_ONESHOT    0x80 
#define TEMP_FQ_1          0x00 
#define TEMP_FQ_2          0x08 
#define TEMP_FQ_4          0x10 
#define TEMP_FQ_6          0x18 
#define TEMP_POL_LOW       0x00 
#define TEMP_POL_HIGH      0x04 
#define TEMP_REG_TEMP      0x00 
#define TEMP_REG_CONFIG    0x01 
#define TEMP_REG_TLOW      0x02 
#define TEMP_REG_THIGH     0x03 

#define EMETER_REG_VIN    0x0a 
#define EMETER_REG_AIN    0x0c 
#define EMETER_REG_VOUT   0x0e 
#define EMETER_REG_AOUT   0x10 
#define EMETER_REG_JOULES 0x12 
#define EMETER_REG_WIN    0x14 
#define EMETER_REG_WOUT   0x16 

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define I2C_OPTION_STANDARD  0x00 
#define I2C_OPTION_NORESTART 0x04 
#define I2C_OPTION_FAST      0x08 
#endif

#define DISPLAY_ERASE_ALL       0x00     
#define DISPLAY_PIXEL           0x01     
#define DISPLAY_HORIZONTAL_LINE 0x02     
#define DISPLAY_VERTICAL_LINE   0x03     
#define DISPLAY_CHAR            0x04     
#define DISPLAY_ERASE_LINE      0x05     
#define DISPLAY_FILL_REGION     0x06     
#define DISPLAY_FRAME           0x07     

#define DRAW_OPT_NORMAL                     (0x0000) 
#define DRAW_OPT_CLEAR_WHOLE_SCREEN         (0x0001) 
#define DRAW_OPT_CLEAR_EXCEPT_STATUS_SCREEN (0x0002) 
#define DRAW_OPT_CLEAR_PIXELS               (0x0004) 
#define DRAW_OPT_CLEAR                      (0x0004) 
#define DRAW_OPT_INVERT                     (0x0004) 
#define DRAW_OPT_LOGICAL_COPY               (0x0000) 
#define DRAW_OPT_LOGICAL_AND                (0x0008) 
#define DRAW_OPT_LOGICAL_OR                 (0x0010) 
#define DRAW_OPT_LOGICAL_XOR                (0x0018) 
#define DRAW_OPT_FILL_SHAPE                 (0x0020) 
#define DRAW_OPT_CLEAR_SCREEN_MODES         (0x0003) 
#define DRAW_OPT_LOGICAL_OPERATIONS         (0x0018) 
#define DRAW_OPT_POLYGON_POLYLINE           (0x0400) 
#define DRAW_OPT_CLEAR_LINE                 (0x0800) 
#define DRAW_OPT_CLEAR_EOL                  (0x1000) 
#define DRAW_OPT_FONT_DIRECTIONS            (0x01C0) 
#define DRAW_OPT_FONT_WRAP       (0x0200) 
#define DRAW_OPT_FONT_DIR_L2RB   (0x0000) 
#define DRAW_OPT_FONT_DIR_L2RT   (0x0040) 
#define DRAW_OPT_FONT_DIR_R2LB   (0x0080) 
#define DRAW_OPT_FONT_DIR_R2LT   (0x00C0) 
#define DRAW_OPT_FONT_DIR_B2TL   (0x0100) 
#define DRAW_OPT_FONT_DIR_B2TR   (0x0140) 
#define DRAW_OPT_FONT_DIR_T2BL   (0x0180) 
#define DRAW_OPT_FONT_DIR_T2BR   (0x01C0) 

#define DISPLAY_ON               0x01     
#define DISPLAY_REFRESH          0x02     
#define DISPLAY_POPUP            0x08     
#define DISPLAY_REFRESH_DISABLED 0x40     
#define DISPLAY_BUSY             0x80     

#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define DISPLAY_CONTRAST_DEFAULT 0x5A 
#define DISPLAY_CONTRAST_MAX     0x7F 

#endif
#define SCREEN_MODE_RESTORE 0x00 
#define SCREEN_MODE_CLEAR   0x01 
#define DISPLAY_HEIGHT 64  
#define DISPLAY_WIDTH  100 
#define DISPLAY_MENUICONS_Y       40 
#define DISPLAY_MENUICONS_X_OFFS  7  
#define DISPLAY_MENUICONS_X_DIFF  31 
#define TEXTLINE_1 0 
#define TEXTLINE_2 1 
#define TEXTLINE_3 2 
#define TEXTLINE_4 3 
#define TEXTLINE_5 4 
#define TEXTLINE_6 5 
#define TEXTLINE_7 6 
#define TEXTLINE_8 7 
#define TEXTLINES  8 

#define MENUICON_LEFT   0 
#define MENUICON_CENTER 1 
#define MENUICON_RIGHT  2 
#define MENUICONS       3 
#define FRAME_SELECT 0   
#define STATUSTEXT   1   
#define MENUTEXT     2   
#define STEPLINE     3   
#define TOPLINE      4   
#define SPECIALS     5   
#define STATUSICON_BLUETOOTH 0 
#define STATUSICON_USB       1 
#define STATUSICON_VM        2 
#define STATUSICON_BATTERY   3 
#define STATUSICONS          4 
#define SCREEN_BACKGROUND 0 
#define SCREEN_LARGE      1 
#define SCREEN_SMALL      2 
#define SCREENS           3 
#define BITMAP_1 0 
#define BITMAP_2 1 
#define BITMAP_3 2 
#define BITMAP_4 3 
#define BITMAPS  4 
#define STEPICON_1 0 
#define STEPICON_2 1 
#define STEPICON_3 2 
#define STEPICON_4 3 
#define STEPICON_5 4 
#define STEPICONS  5 
#define DisplayOffsetPFunc          0             
#define DisplayOffsetEraseMask      4             
#define DisplayOffsetUpdateMask     8             
#define DisplayOffsetPFont          12            
#define DisplayOffsetPTextLines(p)  (((p)*4)+16)  
#define DisplayOffsetPStatusText    48            
#define DisplayOffsetPStatusIcons   52            
#define DisplayOffsetPScreens(p)    (((p)*4)+56)  
#define DisplayOffsetPBitmaps(p)    (((p)*4)+68)  
#define DisplayOffsetPMenuText      84            
#define DisplayOffsetPMenuIcons(p)  (((p)*4)+88)  
#define DisplayOffsetPStepIcons     100           
#define DisplayOffsetDisplay        104           
#define DisplayOffsetStatusIcons(p) ((p)+108)     
#define DisplayOffsetStepIcons(p)   ((p)+112)     
#define DisplayOffsetFlags          117           
#define DisplayOffsetTextLinesCenterFlags 118     
#define DisplayOffsetNormal(l,w)    (((l)*100)+(w)+119) 
#define DisplayOffsetPopup(l,w)     (((l)*100)+(w)+919) 
#if defined(__ENHANCED_FIRMWARE) && (__FIRMWARE_VERSION > 107)
#define DisplayOffsetContrast       1719 
#endif

#define SIZE_OF_USBBUF                64  
#define USB_PROTOCOL_OVERHEAD         2   
#define SIZE_OF_USBDATA               62  
#define SIZE_OF_HSBUF                 128 
#define SIZE_OF_BTBUF                 128 
#define BT_CMD_BYTE                   1  
#define SIZE_OF_BT_DEVICE_TABLE       30 
#define SIZE_OF_BT_CONNECT_TABLE      4  
#define SIZE_OF_BT_NAME               16 
#define SIZE_OF_BRICK_NAME            8  
#define SIZE_OF_CLASS_OF_DEVICE       4  
#define SIZE_OF_BT_PINCODE            16 
#define SIZE_OF_BDADDR                7  
#define MAX_BT_MSG_SIZE               60000 
#define BT_DEFAULT_INQUIRY_MAX        0   
#define BT_DEFAULT_INQUIRY_TIMEOUT_LO 15  

#define JOY_BTN_01 0x00000001 
#define JOY_BTN_02 0x00000002 
#define JOY_BTN_03 0x00000004 
#define JOY_BTN_04 0x00000008 
#define JOY_BTN_05 0x00000010 
#define JOY_BTN_06 0x00000020 
#define JOY_BTN_07 0x00000040 
#define JOY_BTN_08 0x00000080 
#define JOY_BTN_09 0x00000100 
#define JOY_BTN_10 0x00000200 
#define JOY_BTN_11 0x00000400 
#define JOY_BTN_12 0x00000800 
#define JOY_BTN_13 0x00001000 
#define JOY_BTN_14 0x00002000 
#define JOY_BTN_15 0x00004000 
#define JOY_BTN_16 0x00008000 
#define JOY_BTN_17 0x00010000 
#define JOY_BTN_18 0x00020000 
#define JOY_BTN_19 0x00040000 
#define JOY_BTN_20 0x00080000 
#define JOY_BTN_21 0x00100000 
#define JOY_BTN_22 0x00200000 
#define JOY_BTN_23 0x00400000 
#define JOY_BTN_24 0x00800000 
#define JOY_BTN_25 0x01000000 
#define JOY_BTN_26 0x02000000 
#define JOY_BTN_27 0x04000000 
#define JOY_BTN_28 0x08000000 
#define JOY_BTN_29 0x10000000 
#define JOY_BTN_30 0x20000000 
#define JOY_BTN_31 0x40000000 
#define JOY_BTN_32 0x80000000 
#define JOY_POV_FORWARD  0     
#define JOY_POV_TOPRIGHT 4500  
#define JOY_POV_RIGHT    9000  
#define JOY_POV_BOTRIGHT 13500 
#define JOY_POV_BACKWARD 18000 
#define JOY_POV_BOTLEFT  22500 
#define JOY_POV_LEFT     27000 
#define JOY_POV_TOPLEFT  31500 
#define JOY_POV_CENTERED 65535 

#define BT_ARM_OFF              0 
#define BT_ARM_CMD_MODE         1 
#define BT_ARM_DATA_MODE        2 

#define DATA_MODE_NXT    0x00 
#define DATA_MODE_GPS    0x01 
#define DATA_MODE_RAW    0x02 
#define DATA_MODE_MASK   0x07 
#define DATA_MODE_UPDATE 0x08 

#define BT_BRICK_VISIBILITY     0x01 
#define BT_BRICK_PORT_OPEN      0x02 
#define BT_CONNECTION_0_ENABLE  0x10 
#define BT_CONNECTION_1_ENABLE  0x20 
#define BT_CONNECTION_2_ENABLE  0x40 
#define BT_CONNECTION_3_ENABLE  0x80 

#define CONN_BT0    0x0 
#define CONN_BT1    0x1 
#define CONN_BT2    0x2 
#define CONN_BT3    0x3 
#define CONN_HS4    0x4 
#define CONN_HS_ALL 0x4 
#define CONN_HS_1   0x5 
#define CONN_HS_2   0x6 
#define CONN_HS_3   0x7 
#define CONN_HS_4   0x8 
#define CONN_HS_5   0x9 
#define CONN_HS_6   0xa 
#define CONN_HS_7   0xb 
#define CONN_HS_8   0xc 

#define BT_ENABLE               0x00 
#define BT_DISABLE              0x01 

#define HS_UPDATE        1 

#define HS_INITIALISE       1 
#define HS_INIT_RECEIVER    2 
#define HS_SEND_DATA        3 
#define HS_DISABLE          4 
#define HS_ENABLE           5 
#define HS_DEFAULT          6 
#define HS_BYTES_REMAINING 16 

#ifdef __ENHANCED_FIRMWARE
#define HS_CTRL_INIT 0 
#define HS_CTRL_UART 1 
#define HS_CTRL_EXIT 2 

#if __FIRMWARE_VERSION > 107
#define HS_BAUD_1200     0 
#define HS_BAUD_2400     1 
#define HS_BAUD_3600     2 
#define HS_BAUD_4800     3 
#define HS_BAUD_7200     4 
#define HS_BAUD_9600     5 
#define HS_BAUD_14400    6 
#define HS_BAUD_19200    7 
#define HS_BAUD_28800    8 
#define HS_BAUD_38400    9 
#define HS_BAUD_57600   10 
#define HS_BAUD_76800   11 
#define HS_BAUD_115200  12 
#define HS_BAUD_230400  13 
#define HS_BAUD_460800  14 
#define HS_BAUD_921600  15 
#define HS_BAUD_DEFAULT 15 

#define HS_MODE_UART_RS485 0x0    
#define HS_MODE_UART_RS232 0x1    
#define HS_MODE_MASK 0x3EC0        
#define HS_UART_MASK 0x000F        
#define HS_MODE_DEFAULT HS_MODE_8N1 
#define HS_MODE_5_DATA 0x0000 
#define HS_MODE_6_DATA 0x0040 
#define HS_MODE_7_DATA 0x0080 
#define HS_MODE_8_DATA 0x00C0 

#define HS_MODE_10_STOP 0x0000 
#define HS_MODE_15_STOP 0x1000 
#define HS_MODE_20_STOP 0x2000 

#define HS_MODE_E_PARITY 0x0000 
#define HS_MODE_O_PARITY 0x0200 
#define HS_MODE_S_PARITY 0x0400 
#define HS_MODE_M_PARITY 0x0600 
#define HS_MODE_N_PARITY 0x0800 

#define HS_MODE_8N1 (HS_MODE_8_DATA|HS_MODE_N_PARITY|HS_MODE_10_STOP) 
#define HS_MODE_7E1 (HS_MODE_7_DATA|HS_MODE_E_PARITY|HS_MODE_10_STOP) 

#define HS_ADDRESS_ALL 0 
#define HS_ADDRESS_1   1 
#define HS_ADDRESS_2   2 
#define HS_ADDRESS_3   3 
#define HS_ADDRESS_4   4 
#define HS_ADDRESS_5   5 
#define HS_ADDRESS_6   6 
#define HS_ADDRESS_7   7 
#define HS_ADDRESS_8   8 

#endif
#endif

#define BT_DEVICE_EMPTY   0x00 
#define BT_DEVICE_UNKNOWN 0x01 
#define BT_DEVICE_KNOWN   0x02 
#define BT_DEVICE_NAME    0x40 
#define BT_DEVICE_AWAY    0x80 

#define INTF_SENDFILE      0 
#define INTF_SEARCH        1 
#define INTF_STOPSEARCH    2 
#define INTF_CONNECT       3 
#define INTF_DISCONNECT    4 
#define INTF_DISCONNECTALL 5 
#define INTF_REMOVEDEVICE  6 
#define INTF_VISIBILITY    7 
#define INTF_SETCMDMODE    8 
#define INTF_OPENSTREAM    9 
#define INTF_SENDDATA      10 
#define INTF_FACTORYRESET  11 
#define INTF_BTON          12 
#define INTF_BTOFF         13 
#define INTF_SETBTNAME     14 
#define INTF_EXTREAD       15 
#define INTF_PINREQ        16 
#define INTF_CONNECTREQ    17 
#if __FIRMWARE_VERSION > 107
#define INTF_CONNECTBYNAME 18 
#endif

#define LR_SUCCESS        0x50 
#define LR_COULD_NOT_SAVE 0x51 
#define LR_STORE_IS_FULL  0x52 
#define LR_ENTRY_REMOVED  0x53 
#define LR_UNKNOWN_ADDR   0x54 
#define USB_CMD_READY     0x01 
#define BT_CMD_READY      0x02 
#define HS_CMD_READY      0x04 

#define CommOffsetPFunc    0 
#define CommOffsetPFuncTwo 4 
#define CommOffsetBtDeviceTableName(p)           (((p)*31)+8) 
#define CommOffsetBtDeviceTableClassOfDevice(p)  (((p)*31)+24) 
#define CommOffsetBtDeviceTableBdAddr(p)         (((p)*31)+28) 
#define CommOffsetBtDeviceTableDeviceStatus(p)   (((p)*31)+35) 
#define CommOffsetBtConnectTableName(p)          (((p)*47)+938) 
#define CommOffsetBtConnectTableClassOfDevice(p) (((p)*47)+954) 
#define CommOffsetBtConnectTablePinCode(p)       (((p)*47)+958) 
#define CommOffsetBtConnectTableBdAddr(p)        (((p)*47)+974) 
#define CommOffsetBtConnectTableHandleNr(p)      (((p)*47)+981) 
#define CommOffsetBtConnectTableStreamStatus(p)  (((p)*47)+982) 
#define CommOffsetBtConnectTableLinkQuality(p)   (((p)*47)+983) 
#define CommOffsetBrickDataName            1126 
#define CommOffsetBrickDataBluecoreVersion 1142 
#define CommOffsetBrickDataBdAddr          1144 
#define CommOffsetBrickDataBtStateStatus   1151 
#define CommOffsetBrickDataBtHwStatus      1152 
#define CommOffsetBrickDataTimeOutValue    1153 
#define CommOffsetBtInBufBuf       1157 
#define CommOffsetBtInBufInPtr     1285 
#define CommOffsetBtInBufOutPtr    1286 
#define CommOffsetBtOutBufBuf      1289 
#define CommOffsetBtOutBufInPtr    1417 
#define CommOffsetBtOutBufOutPtr   1418 
#define CommOffsetHsInBufBuf       1421 
#define CommOffsetHsInBufInPtr     1549 
#define CommOffsetHsInBufOutPtr    1550 
#define CommOffsetHsOutBufBuf      1553 
#define CommOffsetHsOutBufInPtr    1681 
#define CommOffsetHsOutBufOutPtr   1682 
#define CommOffsetUsbInBufBuf        1685 
#define CommOffsetUsbInBufInPtr      1749 
#define CommOffsetUsbInBufOutPtr     1750 
#define CommOffsetUsbOutBufBuf       1753 
#define CommOffsetUsbOutBufInPtr     1817 
#define CommOffsetUsbOutBufOutPtr    1818 
#define CommOffsetUsbPollBufBuf      1821 
#define CommOffsetUsbPollBufInPtr    1885 
#define CommOffsetUsbPollBufOutPtr   1886 
#define CommOffsetBtDeviceCnt      1889 
#define CommOffsetBtDeviceNameCnt  1890 
#define CommOffsetHsFlags          1891 
#define CommOffsetHsSpeed          1892 
#define CommOffsetHsState          1893 
#define CommOffsetUsbState         1894 
#define CommOffsetHsAddress        1895 
#ifdef __ENHANCED_FIRMWARE
#define CommOffsetHsMode           1896 
#define CommOffsetBtDataMode       1898 
#define CommOffsetHsDataMode       1899 
#endif

#define RCX_OUT_A   0x01 
#define RCX_OUT_B   0x02 
#define RCX_OUT_C   0x04 
#define RCX_OUT_AB  0x03 
#define RCX_OUT_AC  0x05 
#define RCX_OUT_BC  0x06 
#define RCX_OUT_ABC 0x07 

#define RCX_OUT_FLOAT 0    
#define RCX_OUT_OFF   0x40 
#define RCX_OUT_ON    0x80 

#define RCX_OUT_REV    0    
#define RCX_OUT_TOGGLE 0x40 
#define RCX_OUT_FWD    0x80 

#define RCX_OUT_LOW  0 
#define RCX_OUT_HALF 3 
#define RCX_OUT_FULL 7 

#define RCX_RemoteKeysReleased 0x0000 
#define RCX_RemotePBMessage1   0x0100 
#define RCX_RemotePBMessage2   0x0200 
#define RCX_RemotePBMessage3   0x0400 
#define RCX_RemoteOutAForward  0x0800 
#define RCX_RemoteOutBForward  0x1000 
#define RCX_RemoteOutCForward  0x2000 
#define RCX_RemoteOutABackward 0x4000 
#define RCX_RemoteOutBBackward 0x8000 
#define RCX_RemoteOutCBackward 0x0001 
#define RCX_RemoteSelProgram1  0x0002 
#define RCX_RemoteSelProgram2  0x0004 
#define RCX_RemoteSelProgram3  0x0008 
#define RCX_RemoteSelProgram4  0x0010 
#define RCX_RemoteSelProgram5  0x0020 
#define RCX_RemoteStopOutOff   0x0040 
#define RCX_RemotePlayASound   0x0080 

#define SOUND_CLICK       0 
#define SOUND_DOUBLE_BEEP 1 
#define SOUND_DOWN        2 
#define SOUND_UP          3 
#define SOUND_LOW_BEEP    4 
#define SOUND_FAST_UP     5 

#define SCOUT_LIGHT_ON        0x80 
#define SCOUT_LIGHT_OFF       0    

#define SCOUT_SOUND_REMOTE           6 
#define SCOUT_SOUND_ENTERSA          7 
#define SCOUT_SOUND_KEYERROR         8 
#define SCOUT_SOUND_NONE             9 
#define SCOUT_SOUND_TOUCH1_PRES     10 
#define SCOUT_SOUND_TOUCH1_REL      11 
#define SCOUT_SOUND_TOUCH2_PRES     12 
#define SCOUT_SOUND_TOUCH2_REL      13 
#define SCOUT_SOUND_ENTER_BRIGHT    14 
#define SCOUT_SOUND_ENTER_NORMAL    15 
#define SCOUT_SOUND_ENTER_DARK      16 
#define SCOUT_SOUND_1_BLINK         17 
#define SCOUT_SOUND_2_BLINK         18 
#define SCOUT_SOUND_COUNTER1        19 
#define SCOUT_SOUND_COUNTER2        20 
#define SCOUT_SOUND_TIMER1          21 
#define SCOUT_SOUND_TIMER2          22 
#define SCOUT_SOUND_TIMER3          23 
#define SCOUT_SOUND_MAIL_RECEIVED   24 
#define SCOUT_SOUND_SPECIAL1        25 
#define SCOUT_SOUND_SPECIAL2        26 
#define SCOUT_SOUND_SPECIAL3        27 

#define SCOUT_SNDSET_NONE           0 
#define SCOUT_SNDSET_BASIC          1 
#define SCOUT_SNDSET_BUG            2 
#define SCOUT_SNDSET_ALARM          3 
#define SCOUT_SNDSET_RANDOM         4 
#define SCOUT_SNDSET_SCIENCE        5 

#define SCOUT_MODE_STANDALONE       0 
#define SCOUT_MODE_POWER            1 

#define SCOUT_MR_NO_MOTION          0 
#define SCOUT_MR_FORWARD            1 
#define SCOUT_MR_ZIGZAG             2 
#define SCOUT_MR_CIRCLE_RIGHT       3 
#define SCOUT_MR_CIRCLE_LEFT        4 
#define SCOUT_MR_LOOP_A             5 
#define SCOUT_MR_LOOP_B             6 
#define SCOUT_MR_LOOP_AB            7 

#define SCOUT_TR_IGNORE             0 
#define SCOUT_TR_REVERSE            1 
#define SCOUT_TR_AVOID              2 
#define SCOUT_TR_WAIT_FOR           3 
#define SCOUT_TR_OFF_WHEN           4 

#define SCOUT_LR_IGNORE             0 
#define SCOUT_LR_SEEK_LIGHT         1 
#define SCOUT_LR_SEEK_DARK          2 
#define SCOUT_LR_AVOID              3 
#define SCOUT_LR_WAIT_FOR           4 
#define SCOUT_LR_OFF_WHEN           5 

#define SCOUT_TGS_SHORT             0 
#define SCOUT_TGS_MEDIUM            1 
#define SCOUT_TGS_LONG              2 

#define SCOUT_FXR_NONE              0 
#define SCOUT_FXR_BUG               1 
#define SCOUT_FXR_ALARM             2 
#define SCOUT_FXR_RANDOM            3 
#define SCOUT_FXR_SCIENCE           4 

#define RCX_VariableSrc             0  
#define RCX_TimerSrc                1  
#define RCX_ConstantSrc             2  
#define RCX_OutputStatusSrc         3  
#define RCX_RandomSrc               4  
#define RCX_ProgramSlotSrc          8  
#define RCX_InputValueSrc           9  
#define RCX_InputTypeSrc            10 
#define RCX_InputModeSrc            11 
#define RCX_InputRawSrc             12 
#define RCX_InputBooleanSrc         13 
#define RCX_WatchSrc                14 
#define RCX_MessageSrc              15 
#define RCX_GlobalMotorStatusSrc    17 
#define RCX_ScoutRulesSrc           18 
#define RCX_ScoutLightParamsSrc     19 
#define RCX_ScoutTimerLimitSrc      20 
#define RCX_CounterSrc              21 
#define RCX_ScoutCounterLimitSrc    22 
#define RCX_TaskEventsSrc           23 
#define RCX_ScoutEventFBSrc         24 
#define RCX_EventStateSrc           25 
#define RCX_TenMSTimerSrc           26 
#define RCX_ClickCounterSrc         27 
#define RCX_UpperThresholdSrc       28 
#define RCX_LowerThresholdSrc       29 
#define RCX_HysteresisSrc           30 
#define RCX_DurationSrc             31 
#define RCX_UARTSetupSrc            33 
#define RCX_BatteryLevelSrc         34 
#define RCX_FirmwareVersionSrc      35 
#define RCX_IndirectVarSrc          36 
#define RCX_DatalogSrcIndirectSrc   37 
#define RCX_DatalogSrcDirectSrc     38 
#define RCX_DatalogValueIndirectSrc 39 
#define RCX_DatalogValueDirectSrc   40 
#define RCX_DatalogRawIndirectSrc   41 
#define RCX_DatalogRawDirectSrc     42 

#define RCX_PingOp           0x10 
#define RCX_BatteryLevelOp   0x30 
#define RCX_DeleteTasksOp    0x40 
#define RCX_StopAllTasksOp   0x50 
#define RCX_PBTurnOffOp      0x60 
#define RCX_DeleteSubsOp     0x70 
#define RCX_ClearSoundOp     0x80 
#define RCX_ClearMsgOp       0x90 
#define RCX_LSCalibrateOp    0xc0 
#define RCX_MuteSoundOp      0xd0 
#define RCX_UnmuteSoundOp    0xe0 
#define RCX_ClearAllEventsOp 0x06 
#define RCX_OnOffFloatOp     0x21 
#define RCX_IRModeOp         0x31 
#define RCX_PlaySoundOp      0x51 
#define RCX_DeleteTaskOp     0x61 
#define RCX_StartTaskOp      0x71 
#define RCX_StopTaskOp       0x81 
#define RCX_SelectProgramOp  0x91 
#define RCX_ClearTimerOp     0xa1 
#define RCX_AutoOffOp        0xb1 
#define RCX_DeleteSubOp      0xc1 
#define RCX_ClearSensorOp    0xd1 
#define RCX_OutputDirOp      0xe1 
#define RCX_PlayToneVarOp    0x02 
#define RCX_PollOp           0x12 
#define RCX_SetWatchOp       0x22 
#define RCX_InputTypeOp      0x32 
#define RCX_InputModeOp      0x42 
#define RCX_SetDatalogOp     0x52 
#define RCX_DatalogOp        0x62 
#define RCX_SendUARTDataOp   0xc2 
#define RCX_RemoteOp         0xd2 
#define RCX_VLLOp            0xe2 
#define RCX_DirectEventOp    0x03 
#define RCX_OutputPowerOp    0x13 
#define RCX_PlayToneOp       0x23 
#define RCX_DisplayOp        0x33 
#define RCX_PollMemoryOp     0x63 
#define RCX_SetFeedbackOp    0x83 
#define RCX_SetEventOp       0x93 
#define RCX_GOutputPowerOp   0xa3 
#define RCX_LSUpperThreshOp  0xb3 
#define RCX_LSLowerThreshOp  0xc3 
#define RCX_LSHysteresisOp   0xd3 
#define RCX_LSBlinkTimeOp    0xe3 
#define RCX_CalibrateEventOp 0x04 
#define RCX_SetVarOp         0x14 
#define RCX_SumVarOp         0x24 
#define RCX_SubVarOp         0x34 
#define RCX_DivVarOp         0x44 
#define RCX_MulVarOp         0x54 
#define RCX_SgnVarOp         0x64 
#define RCX_AbsVarOp         0x74 
#define RCX_AndVarOp         0x84 
#define RCX_OrVarOp          0x94 
#define RCX_UploadDatalogOp  0xa4 
#define RCX_SetTimerLimitOp  0xc4 
#define RCX_SetCounterOp     0xd4 
#define RCX_SetSourceValueOp 0x05 
#define RCX_UnlockOp         0x15 
#define RCX_BootModeOp       0x65 
#define RCX_UnlockFirmOp     0xa5 
#define RCX_ScoutRulesOp     0xd5 
#define RCX_ViewSourceValOp  0xe5 
#define RCX_ScoutOp          0x47 
#define RCX_SoundOp          0x57 
#define RCX_GOutputModeOp    0x67 
#define RCX_GOutputDirOp     0x77 
#define RCX_LightOp          0x87 
#define RCX_IncCounterOp     0x97 
#define RCX_DecCounterOp     0xa7 
#define RCX_ClearCounterOp   0xb7 
#define RCX_SetPriorityOp    0xd7 
#define RCX_MessageOp        0xf7 

#define PF_CMD_STOP  0 
#define PF_CMD_FLOAT 0 
#define PF_CMD_FWD   1 
#define PF_CMD_REV   2 
#define PF_CMD_BRAKE 3 

#define PF_CHANNEL_1 0 
#define PF_CHANNEL_2 1 
#define PF_CHANNEL_3 2 
#define PF_CHANNEL_4 3 

#define PF_MODE_TRAIN             0 
#define PF_MODE_COMBO_DIRECT      1 
#define PF_MODE_SINGLE_PIN_CONT   2 
#define PF_MODE_SINGLE_PIN_TIME   3 
#define PF_MODE_COMBO_PWM         4 
#define PF_MODE_SINGLE_OUTPUT_PWM 4 
#define PF_MODE_SINGLE_OUTPUT_CST 6 

#define TRAIN_FUNC_STOP         0 
#define TRAIN_FUNC_INCR_SPEED   1 
#define TRAIN_FUNC_DECR_SPEED   2 
#define TRAIN_FUNC_TOGGLE_LIGHT 4 

#define TRAIN_CHANNEL_1   0 
#define TRAIN_CHANNEL_2   1 
#define TRAIN_CHANNEL_3   2 
#define TRAIN_CHANNEL_ALL 3 

#define PF_OUT_A 0 
#define PF_OUT_B 1 

#define PF_PIN_C1 0 
#define PF_PIN_C2 1 

#define PF_FUNC_NOCHANGE 0 
#define PF_FUNC_CLEAR    1 
#define PF_FUNC_SET      2 
#define PF_FUNC_TOGGLE   3 

#define PF_CST_CLEAR1_CLEAR2 0 
#define PF_CST_SET1_CLEAR2   1 
#define PF_CST_CLEAR1_SET2   2 
#define PF_CST_SET1_SET2     3 
#define PF_CST_INCREMENT_PWM 4 
#define PF_CST_DECREMENT_PWM 5 
#define PF_CST_FULL_FWD      6 
#define PF_CST_FULL_REV      7 
#define PF_CST_TOGGLE_DIR    8 

#define PF_PWM_FLOAT 0  
#define PF_PWM_FWD1  1  
#define PF_PWM_FWD2  2  
#define PF_PWM_FWD3  3  
#define PF_PWM_FWD4  4  
#define PF_PWM_FWD5  5  
#define PF_PWM_FWD6  6  
#define PF_PWM_FWD7  7  
#define PF_PWM_BRAKE 8  
#define PF_PWM_REV7  9  
#define PF_PWM_REV6  10 
#define PF_PWM_REV5  11 
#define PF_PWM_REV4  12 
#define PF_PWM_REV3  13 
#define PF_PWM_REV2  14 
#define PF_PWM_REV1  15 

#define HT_ADDR_IRSEEKER   0x02 
#define HT_ADDR_IRSEEKER2  0x10 
#define HT_ADDR_IRRECEIVER 0x02 
#define HT_ADDR_COMPASS    0x02 
#define HT_ADDR_ACCEL      0x02 
#define HT_ADDR_COLOR      0x02 
#define HT_ADDR_COLOR2     0x02 
#define HT_ADDR_IRLINK     0x02 
#define HT_ADDR_ANGLE      0x02 
#define HT_ADDR_BAROMETRIC 0x02 
#define HT_ADDR_PROTOBOARD 0x02 
#define HT_ADDR_SUPERPRO   0x10 
#define HT_ADDR_PIR        0x02 
#define HTIR2_MODE_1200 0 
#define HTIR2_MODE_600  1 
#define HTIR2_REG_MODE  0x41 
#define HTIR2_REG_DCDIR 0x42 
#define HTIR2_REG_DC01  0x43 
#define HTIR2_REG_DC02  0x44 
#define HTIR2_REG_DC03  0x45 
#define HTIR2_REG_DC04  0x46 
#define HTIR2_REG_DC05  0x47 
#define HTIR2_REG_DCAVG 0x48 
#define HTIR2_REG_ACDIR 0x49 
#define HTIR2_REG_AC01  0x4A 
#define HTIR2_REG_AC02  0x4B 
#define HTIR2_REG_AC03  0x4C 
#define HTIR2_REG_AC04  0x4D 
#define HTIR2_REG_AC05  0x4E 

#define HT_CH1_A 0 
#define HT_CH1_B 1 
#define HT_CH2_A 2 
#define HT_CH2_B 3 
#define HT_CH3_A 4 
#define HT_CH3_B 5 
#define HT_CH4_A 6 
#define HT_CH4_B 7 

#define HT_CMD_COLOR2_ACTIVE  0x00 
#define HT_CMD_COLOR2_PASSIVE 0x01 
#define HT_CMD_COLOR2_RAW     0x03 
#define HT_CMD_COLOR2_50HZ    0x35 
#define HT_CMD_COLOR2_60HZ    0x36 
#define HT_CMD_COLOR2_BLCAL   0x42 
#define HT_CMD_COLOR2_WBCAL   0x43 
#define HT_CMD_COLOR2_FAR     0x46 
#define HT_CMD_COLOR2_LED_HI  0x48 
#define HT_CMD_COLOR2_LED_LOW 0x4C 
#define HT_CMD_COLOR2_NEAR    0x4E 

#define HTANGLE_MODE_NORMAL    0x00 
#define HTANGLE_MODE_CALIBRATE 0x43 
#define HTANGLE_MODE_RESET     0x52 
#define HTANGLE_REG_MODE  0x41 
#define HTANGLE_REG_DCDIR 0x42 
#define HTANGLE_REG_DC01  0x43 
#define HTANGLE_REG_DC02  0x44 
#define HTANGLE_REG_DC03  0x45 
#define HTANGLE_REG_DC04  0x46 
#define HTANGLE_REG_DC05  0x47 
#define HTANGLE_REG_DCAVG 0x48 
#define HTANGLE_REG_ACDIR 0x49 

#define HTBAR_REG_COMMAND     0x40 
#define HTBAR_REG_TEMPERATURE 0x42 
#define HTBAR_REG_PRESSURE    0x44 
#define HTBAR_REG_CALIBRATION 0x46 

#define HTPROTO_REG_A0    0x42 
#define HTPROTO_REG_A1    0x44 
#define HTPROTO_REG_A2    0x46 
#define HTPROTO_REG_A3    0x48 
#define HTPROTO_REG_A4    0x4A 
#define HTPROTO_REG_DIN   0x4C 
#define HTPROTO_REG_DOUT  0x4D 
#define HTPROTO_REG_DCTRL 0x4E 
#define HTPROTO_REG_SRATE 0x4F 
#define HTPROTO_A0 0x42 
#define HTPROTO_A1 0x44 
#define HTPROTO_A2 0x46 
#define HTPROTO_A3 0x48 
#define HTPROTO_A4 0x4A 

#define HTSPRO_REG_CTRL         0x40 
#define HTSPRO_REG_A0           0x42 
#define HTSPRO_REG_A1           0x44 
#define HTSPRO_REG_A2           0x46 
#define HTSPRO_REG_A3           0x48 
#define HTSPRO_REG_DIN          0x4C 
#define HTSPRO_REG_DOUT         0x4D 
#define HTSPRO_REG_DCTRL        0x4E 
#define HTSPRO_REG_STROBE       0x50 
#define HTSPRO_REG_LED          0x51 
#define HTSPRO_REG_DAC0_MODE    0x52 
#define HTSPRO_REG_DAC0_FREQ    0x53 
#define HTSPRO_REG_DAC0_VOLTAGE 0x55 
#define HTSPRO_REG_DAC1_MODE    0x57 
#define HTSPRO_REG_DAC1_FREQ    0x58 
#define HTSPRO_REG_DAC1_VOLTAGE 0x5A 
#define HTSPRO_REG_DLADDRESS    0x60 
#define HTSPRO_REG_DLDATA       0x62 
#define HTSPRO_REG_DLCHKSUM     0x6A 
#define HTSPRO_REG_DLCONTROL    0x6B 
#define HTSPRO_REG_MEMORY_20    0x80 
#define HTSPRO_REG_MEMORY_21    0x84 
#define HTSPRO_REG_MEMORY_22    0x88 
#define HTSPRO_REG_MEMORY_23    0x8C 
#define HTSPRO_REG_MEMORY_24    0x90 
#define HTSPRO_REG_MEMORY_25    0x94 
#define HTSPRO_REG_MEMORY_26    0x98 
#define HTSPRO_REG_MEMORY_27    0x9C 
#define HTSPRO_REG_MEMORY_28    0xA0 
#define HTSPRO_REG_MEMORY_29    0xA4 
#define HTSPRO_REG_MEMORY_2A    0xA8 
#define HTSPRO_REG_MEMORY_2B    0xAC 
#define HTSPRO_REG_MEMORY_2C    0xB0 
#define HTSPRO_REG_MEMORY_2D    0xB4 
#define HTSPRO_REG_MEMORY_2E    0xB8 
#define HTSPRO_REG_MEMORY_2F    0xBC 
#define HTSPRO_REG_MEMORY_30    0xC0 
#define HTSPRO_REG_MEMORY_31    0xC4 
#define HTSPRO_REG_MEMORY_32    0xC8 
#define HTSPRO_REG_MEMORY_33    0xCC 
#define HTSPRO_REG_MEMORY_34    0xD0 
#define HTSPRO_REG_MEMORY_35    0xD4 
#define HTSPRO_REG_MEMORY_36    0xD8 
#define HTSPRO_REG_MEMORY_37    0xDC 
#define HTSPRO_REG_MEMORY_38    0xE0 
#define HTSPRO_REG_MEMORY_39    0xE4 
#define HTSPRO_REG_MEMORY_3A    0xE8 
#define HTSPRO_REG_MEMORY_3B    0xEC 
#define HTSPRO_REG_MEMORY_3C    0xF0 
#define HTSPRO_REG_MEMORY_3D    0xF4 
#define HTSPRO_REG_MEMORY_3E    0xF8 
#define HTSPRO_REG_MEMORY_3F    0xFC 
#define HTSPRO_A0 0x42 
#define HTSPRO_A1 0x44 
#define HTSPRO_A2 0x46 
#define HTSPRO_A3 0x48 

#define HTSPRO_DAC0 0x52 
#define HTSPRO_DAC1 0x57 

#define LED_BLUE 0x02 
#define LED_RED  0x01 
#define LED_NONE 0x00 

#define DAC_MODE_DCOUT        0 
#define DAC_MODE_SINEWAVE     1 
#define DAC_MODE_SQUAREWAVE   2 
#define DAC_MODE_SAWPOSWAVE   3 
#define DAC_MODE_SAWNEGWAVE   4 
#define DAC_MODE_TRIANGLEWAVE 5 
#define DAC_MODE_PWMVOLTAGE   6 
#define DAC_MODE_RESTART_MASK 0x80 

#define DIGI_PIN0 0x01 
#define DIGI_PIN1 0x02 
#define DIGI_PIN2 0x04 
#define DIGI_PIN3 0x08 
#define DIGI_PIN4 0x10 
#define DIGI_PIN5 0x20 
#define DIGI_PIN6 0x40 
#define DIGI_PIN7 0x80 

#define STROBE_S0    0x01 
#define STROBE_S1    0x02 
#define STROBE_S2    0x04 
#define STROBE_S3    0x08 
#define STROBE_READ  0x10 
#define STROBE_WRITE 0x20 

#define HTPIR_REG_DEADBAND 0x41 
#define HTPIR_REG_READING  0x42 

#define MS_CMD_ENERGIZED   0x45 
#define MS_CMD_DEENERGIZED 0x44 
#define MS_CMD_ADPA_ON     0x4E 
#define MS_CMD_ADPA_OFF    0x4F 
#define MS_ADDR_RTCLOCK     0xD0 
#define MS_ADDR_DISTNX      0x02 
#define MS_ADDR_NRLINK      0x02 
#define MS_ADDR_ACCLNX      0x02 
#define MS_ADDR_CMPSNX      0x02 
#define MS_ADDR_PSPNX       0x02 
#define MS_ADDR_LINELDR     0x02 
#define MS_ADDR_NXTCAM      0x02 
#define MS_ADDR_NXTHID      0x04 
#define MS_ADDR_NXTSERVO    0xB0 
#define MS_ADDR_NXTSERVO_EM 0x40 
#define MS_ADDR_PFMATE      0x48 
#define MS_ADDR_MTRMUX      0xB4 
#define MS_ADDR_NXTMMX      0x06 
#define MS_ADDR_IVSENS      0x12 
#define MS_ADDR_RXMUX       0x7E 
#define MS_ADDR_NUMERICPAD  0xB4 
#define MS_ADDR_TOUCHPANEL  0x04 
#define MS_ADDR_PPS58       0x18 
#define DIST_CMD_GP2D12      0x31 
#define DIST_CMD_GP2D120     0x32 
#define DIST_CMD_GP2YA21     0x33 
#define DIST_CMD_GP2YA02     0x34 
#define DIST_CMD_CUSTOM      0x35 
#define DIST_REG_DIST          0x42 
#define DIST_REG_VOLT          0x44 
#define DIST_REG_MODULE_TYPE   0x50 
#define DIST_REG_NUM_POINTS    0x51 
#define DIST_REG_DIST_MIN      0x52 
#define DIST_REG_DIST_MAX      0x54 
#define DIST_REG_VOLT1         0x56 
#define DIST_REG_DIST1         0x58 

#define PSP_CMD_DIGITAL 0x41 
#define PSP_CMD_ANALOG  0x73 
#define PSP_REG_BTNSET1 0x42 
#define PSP_REG_BTNSET2 0x43 
#define PSP_REG_XLEFT   0x44 
#define PSP_REG_YLEFT   0x45 
#define PSP_REG_XRIGHT  0x46 
#define PSP_REG_YRIGHT  0x47 
#define PSP_BTNSET1_LEFT     0x80 
#define PSP_BTNSET1_DOWN     0x40 
#define PSP_BTNSET1_RIGHT    0x20 
#define PSP_BTNSET1_UP       0x10 
#define PSP_BTNSET1_START    0x08 
#define PSP_BTNSET1_R3       0x04 
#define PSP_BTNSET1_L3       0x02 
#define PSP_BTNSET1_SELECT   0x01 

#define PSP_BTNSET2_SQUARE   0x80 
#define PSP_BTNSET2_CROSS    0x40 
#define PSP_BTNSET2_CIRCLE   0x20 
#define PSP_BTNSET2_TRIANGLE 0x10 
#define PSP_BTNSET2_R1       0x08 
#define PSP_BTNSET2_L1       0x04 
#define PSP_BTNSET2_R2       0x02 
#define PSP_BTNSET2_L2       0x01 

#define NRLINK_CMD_2400      0x44 
#define NRLINK_CMD_FLUSH     0x46 
#define NRLINK_CMD_4800      0x48 
#define NRLINK_CMD_IR_LONG   0x4C 
#define NRLINK_CMD_IR_SHORT  0x53 
#define NRLINK_CMD_RUN_MACRO 0x52 
#define NRLINK_CMD_TX_RAW    0x55 
#define NRLINK_CMD_SET_RCX   0x58 
#define NRLINK_CMD_SET_TRAIN 0x54 
#define NRLINK_CMD_SET_PF    0x50 
#define NRLINK_REG_BYTES  0x40 
#define NRLINK_REG_DATA   0x42 
#define NRLINK_REG_EEPROM 0x50 

#define ACCL_CMD_X_CAL      0x58 
#define ACCL_CMD_Y_CAL      0x59 
#define ACCL_CMD_Z_CAL      0x5a 
#define ACCL_CMD_X_CAL_END  0x78 
#define ACCL_CMD_Y_CAL_END  0x79 
#define ACCL_CMD_Z_CAL_END  0x7a 
#define ACCL_CMD_RESET_CAL  0x52 
#define ACCL_REG_SENS_LVL 0x19 
#define ACCL_REG_X_TILT   0x42 
#define ACCL_REG_Y_TILT   0x43 
#define ACCL_REG_Z_TILT   0x44 
#define ACCL_REG_X_ACCEL  0x45 
#define ACCL_REG_Y_ACCEL  0x47 
#define ACCL_REG_Z_ACCEL  0x49 
#define ACCL_REG_X_OFFSET 0x4b 
#define ACCL_REG_X_RANGE  0x4d 
#define ACCL_REG_Y_OFFSET 0x4f 
#define ACCL_REG_Y_RANGE  0x51 
#define ACCL_REG_Z_OFFSET 0x53 
#define ACCL_REG_Z_RANGE  0x55 
#define ACCL_SENSITIVITY_LEVEL_1 0x31 
#define ACCL_SENSITIVITY_LEVEL_2 0x32 
#define ACCL_SENSITIVITY_LEVEL_3 0x33 
#define ACCL_SENSITIVITY_LEVEL_4 0x34 

#define PFMATE_REG_CMD     0x41 
#define PFMATE_REG_CHANNEL 0x42 
#define PFMATE_REG_MOTORS  0x43 
#define PFMATE_REG_A_CMD   0x44 
#define PFMATE_REG_A_SPEED 0x45 
#define PFMATE_REG_B_CMD   0x46 
#define PFMATE_REG_B_SPEED 0x47 
#define PFMATE_CMD_GO      0x47 
#define PFMATE_CMD_RAW     0x52 
#define PFMATE_MOTORS_BOTH 0x00 
#define PFMATE_MOTORS_A    0x01 
#define PFMATE_MOTORS_B    0x02 

#define PFMATE_CHANNEL_1 1 
#define PFMATE_CHANNEL_2 2 
#define PFMATE_CHANNEL_3 3 
#define PFMATE_CHANNEL_4 4 

#define NXTSERVO_REG_VOLTAGE   0x41 
#define NXTSERVO_REG_CMD       0x41 
#define NXTSERVO_REG_S1_POS    0x42 
#define NXTSERVO_REG_S2_POS    0x44 
#define NXTSERVO_REG_S3_POS    0x46 
#define NXTSERVO_REG_S4_POS    0x48 
#define NXTSERVO_REG_S5_POS    0x4A 
#define NXTSERVO_REG_S6_POS    0x4C 
#define NXTSERVO_REG_S7_POS    0x4E 
#define NXTSERVO_REG_S8_POS    0x50 
#define NXTSERVO_REG_S1_SPEED  0x52 
#define NXTSERVO_REG_S2_SPEED  0x53 
#define NXTSERVO_REG_S3_SPEED  0x54 
#define NXTSERVO_REG_S4_SPEED  0x55 
#define NXTSERVO_REG_S5_SPEED  0x56 
#define NXTSERVO_REG_S6_SPEED  0x57 
#define NXTSERVO_REG_S7_SPEED  0x58 
#define NXTSERVO_REG_S8_SPEED  0x59 
#define NXTSERVO_REG_S1_QPOS   0x5A 
#define NXTSERVO_REG_S2_QPOS   0x5B 
#define NXTSERVO_REG_S3_QPOS   0x5C 
#define NXTSERVO_REG_S4_QPOS   0x5D 
#define NXTSERVO_REG_S5_QPOS   0x5E 
#define NXTSERVO_REG_S6_QPOS   0x5F 
#define NXTSERVO_REG_S7_QPOS   0x60 
#define NXTSERVO_REG_S8_QPOS   0x61 
#define NXTSERVO_EM_REG_CMD          0x00 
#define NXTSERVO_EM_REG_EEPROM_START 0x21 
#define NXTSERVO_EM_REG_EEPROM_END   0xFF 

#define NXTSERVO_POS_CENTER 1500 
#define NXTSERVO_POS_MIN     500 
#define NXTSERVO_POS_MAX    2500 

#define NXTSERVO_QPOS_CENTER 150 
#define NXTSERVO_QPOS_MIN     50 
#define NXTSERVO_QPOS_MAX    250 

#define NXTSERVO_SERVO_1 0 
#define NXTSERVO_SERVO_2 1 
#define NXTSERVO_SERVO_3 2 
#define NXTSERVO_SERVO_4 3 
#define NXTSERVO_SERVO_5 4 
#define NXTSERVO_SERVO_6 5 
#define NXTSERVO_SERVO_7 6 
#define NXTSERVO_SERVO_8 7 

#define NXTSERVO_CMD_INIT    0x49 
#define NXTSERVO_CMD_RESET   0x53 
#define NXTSERVO_CMD_HALT    0x48 
#define NXTSERVO_CMD_RESUME  0x52 
#define NXTSERVO_CMD_GOTO    0x47 
#define NXTSERVO_CMD_PAUSE   0x50 
#define NXTSERVO_CMD_EDIT1   0x45 
#define NXTSERVO_CMD_EDIT2   0x4D 
#define NXTSERVO_EM_CMD_QUIT 0x51 

#define NXTHID_REG_CMD       0x41 
#define NXTHID_REG_MODIFIER  0x42 
#define NXTHID_REG_DATA      0x43 

#define NXTHID_MOD_NONE        0x00 
#define NXTHID_MOD_LEFT_CTRL   0x01 
#define NXTHID_MOD_LEFT_SHIFT  0x02 
#define NXTHID_MOD_LEFT_ALT    0x04 
#define NXTHID_MOD_LEFT_GUI    0x08 
#define NXTHID_MOD_RIGHT_CTRL  0x10 
#define NXTHID_MOD_RIGHT_SHIFT 0x20 
#define NXTHID_MOD_RIGHT_ALT   0x40 
#define NXTHID_MOD_RIGHT_GUI   0x80 

#define NXTHID_CMD_ASCII    0x41 
#define NXTHID_CMD_DIRECT   0x44 
#define NXTHID_CMD_TRANSMIT 0x54 

#define NXTPM_REG_CMD        0x41 
#define NXTPM_REG_CURRENT    0x42 
#define NXTPM_REG_VOLTAGE    0x44 
#define NXTPM_REG_CAPACITY   0x46 
#define NXTPM_REG_POWER      0x48 
#define NXTPM_REG_TOTALPOWER 0x4A 
#define NXTPM_REG_MAXCURRENT 0x4E 
#define NXTPM_REG_MINCURRENT 0x50 
#define NXTPM_REG_MAXVOLTAGE 0x52 
#define NXTPM_REG_MINVOLTAGE 0x54 
#define NXTPM_REG_TIME       0x56 
#define NXTPM_REG_USERGAIN   0x5A 
#define NXTPM_REG_GAIN       0x5E 
#define NXTPM_REG_ERRORCOUNT 0x5F 

#define NXTPM_CMD_RESET    0x52 

#define NXTSE_ZONE_NONE  0 
#define NXTSE_ZONE_FRONT 1 
#define NXTSE_ZONE_LEFT  2 
#define NXTSE_ZONE_RIGHT 3 

#define NXTLL_REG_CMD         0x41 
#define NXTLL_REG_STEERING    0x42 
#define NXTLL_REG_AVERAGE     0x43 
#define NXTLL_REG_RESULT      0x44 
#define NXTLL_REG_SETPOINT    0x45 
#define NXTLL_REG_KP_VALUE    0x46 
#define NXTLL_REG_KI_VALUE    0x47 
#define NXTLL_REG_KD_VALUE    0x48 
#define NXTLL_REG_CALIBRATED  0x49 
#define NXTLL_REG_WHITELIMITS 0x51 
#define NXTLL_REG_BLACKLIMITS 0x59 
#define NXTLL_REG_KP_FACTOR   0x61 
#define NXTLL_REG_KI_FACTOR   0x62 
#define NXTLL_REG_KD_FACTOR   0x63 
#define NXTLL_REG_WHITEDATA   0x64 
#define NXTLL_REG_BLACKDATA   0x6C 
#define NXTLL_REG_RAWVOLTAGE  0x74 

#define NXTLL_CMD_USA       0x41 
#define NXTLL_CMD_BLACK     0x42 
#define NXTLL_CMD_POWERDOWN 0x44 
#define NXTLL_CMD_EUROPEAN  0x45 
#define NXTLL_CMD_INVERT    0x49 
#define NXTLL_CMD_POWERUP   0x50 
#define NXTLL_CMD_RESET     0x52 
#define NXTLL_CMD_SNAPSHOT  0x53 
#define NXTLL_CMD_UNIVERSAL 0x55 
#define NXTLL_CMD_WHITE     0x57 

#define NXTNP_REG_BUTTONS  0x00 

#define NXTTP_REG_CMD         0x41 

#define NXTTP_CMD_USA       0x41 

#define RFID_MODE_STOP       0  
#define RFID_MODE_SINGLE     1  
#define RFID_MODE_CONTINUOUS 2  

#define CT_ADDR_RFID     0x04   
#define CT_REG_STATUS    0x32   
#define CT_REG_MODE      0x41   
#define CT_REG_DATA      0x42   

#define DI_ADDR_DGPS          0x06 
#define DGPS_REG_TIME         0x00 
#define DGPS_REG_STATUS       0x01 
#define DGPS_REG_LATITUDE     0x02 
#define DGPS_REG_LONGITUDE    0x04 
#define DGPS_REG_VELOCITY     0x06 
#define DGPS_REG_HEADING      0x07 
#define DGPS_REG_DISTANCE     0x08 
#define DGPS_REG_WAYANGLE     0x09 
#define DGPS_REG_LASTANGLE    0x0A 
#define DGPS_REG_SETLATITUDE  0x0B 
#define DGPS_REG_SETLONGITUDE 0x0C 

#define DI_ADDR_GYRO     0xD2  
#define DI_ADDR_ACCL     0x3A  
#define DIGYRO_REG_WHOAMI    0x0F  
#define DIGYRO_REG_CTRL1     0x20  
#define DIGYRO_REG_CTRL2     0x21  
#define DIGYRO_REG_CTRL3     0x22  
#define DIGYRO_REG_CTRL4     0x23  
#define DIGYRO_REG_CTRL5     0x24  
#define DIGYRO_REG_REFERENCE 0x25  
#define DIGYRO_REG_OUTTEMP   0x26  
#define DIGYRO_REG_STATUS    0x27  
#define DIGYRO_REG_XLOW      0x28  
#define DIGYRO_REG_XHIGH     0x29  
#define DIGYRO_REG_YLOW      0x2A  
#define DIGYRO_REG_YHIGH     0x2B  
#define DIGYRO_REG_ZLOW      0x2C  
#define DIGYRO_REG_ZHIGH     0x2D  
#define DIGYRO_REG_FIFOCTRL  0x2E  
#define DIGYRO_REG_FIFOSRC   0x2F  
#define DIGYRO_REG_INT1_CFG  0x30  
#define DIGYRO_REG_INT1_SRC  0x31  
#define DIGYRO_REG_INT1_XHI  0x32  
#define DIGYRO_REG_INT1_XLO  0x33  
#define DIGYRO_REG_INT1_YHI  0x34  
#define DIGYRO_REG_INT1_YLO  0x35  
#define DIGYRO_REG_INT1_ZHI  0x36  
#define DIGYRO_REG_INT1_ZLO  0x37  
#define DIGYRO_REG_INT1_DUR  0x38  
#define DIGYRO_REG_CTRL1AUTO 0xA0  
#define DIGYRO_REG_TEMPAUTO  0xA6  
#define DIGYRO_REG_XLOWBURST 0xA8  
#define DIGYRO_REG_YLOWBURST 0xAA  
#define DIGYRO_REG_ZLOWBURST 0xAC  

#define DIGYRO_CTRL1_XENABLE      0x01 
#define DIGYRO_CTRL1_YENABLE      0x02 
#define DIGYRO_CTRL1_ZENABLE      0x04 
#define DIGYRO_CTRL1_POWERDOWN    0x00 
#define DIGYRO_CTRL1_NORMAL       0x08 
#define DIGYRO_CTRL1_BANDWIDTH_1  0x00 
#define DIGYRO_CTRL1_BANDWIDTH_2  0x10 
#define DIGYRO_CTRL1_BANDWIDTH_3  0x20 
#define DIGYRO_CTRL1_BANDWIDTH_4  0x30 
#define DIGYRO_CTRL1_DATARATE_100 0x00 
#define DIGYRO_CTRL1_DATARATE_200 0x40 
#define DIGYRO_CTRL1_DATARATE_400 0x80 
#define DIGYRO_CTRL1_DATARATE_800 0xC0 

#define DIGYRO_CTRL2_CUTOFF_FREQ_8   0x00 
#define DIGYRO_CTRL2_CUTOFF_FREQ_4   0x01 
#define DIGYRO_CTRL2_CUTOFF_FREQ_2   0x02 
#define DIGYRO_CTRL2_CUTOFF_FREQ_1   0x03 
#define DIGYRO_CTRL2_CUTOFF_FREQ_05  0x04 
#define DIGYRO_CTRL2_CUTOFF_FREQ_02  0x05 
#define DIGYRO_CTRL2_CUTOFF_FREQ_01  0x06 
#define DIGYRO_CTRL2_CUTOFF_FREQ_005 0x07 
#define DIGYRO_CTRL2_CUTOFF_FREQ_002 0x08 
#define DIGYRO_CTRL2_CUTOFF_FREQ_001 0x09 
#define DIGYRO_CTRL2_HPMODE_RESET    0x00 
#define DIGYRO_CTRL2_HPMODE_REFSIG   0x10 
#define DIGYRO_CTRL2_HPMODE_NORMAL   0x20 
#define DIGYRO_CTRL2_HPMODE_AUTOINT  0x30 

#define DIGYRO_CTRL3_INT1_ENABLE    0x80 
#define DIGYRO_CTRL3_INT1_BOOT      0x40 
#define DIGYRO_CTRL3_INT1_LOWACTIVE 0x20 
#define DIGYRO_CTRL3_OPENDRAIN      0x10 
#define DIGYRO_CTRL3_INT2_DATAREADY 0x08 
#define DIGYRO_CTRL3_INT2_WATERMARK 0x04 
#define DIGYRO_CTRL3_INT2_OVERRUN   0x02 
#define DIGYRO_CTRL3_INT2_EMPTY     0x01 

#define DIGYRO_CTRL4_BLOCKDATA  0x80 
#define DIGYRO_CTRL4_BIGENDIAN  0x40 
#define DIGYRO_CTRL4_SCALE_250  0x00 
#define DIGYRO_CTRL4_SCALE_500  0x10 
#define DIGYRO_CTRL4_SCALE_2000 0x30 

#define DIGYRO_CTRL5_REBOOTMEM  0x80 
#define DIGYRO_CTRL5_FIFOENABLE 0x40 
#define DIGYRO_CTRL5_HPENABLE   0x10 
#define DIGYRO_CTRL5_OUT_SEL_1  0x00 
#define DIGYRO_CTRL5_OUT_SEL_2  0x01 
#define DIGYRO_CTRL5_OUT_SEL_3  0x02 
#define DIGYRO_CTRL5_INT1_SEL_1 0x00 
#define DIGYRO_CTRL5_INT1_SEL_2 0x04 
#define DIGYRO_CTRL5_INT1_SEL_3 0x08 

#define DIGYRO_FIFOCTRL_BYPASS        0x00 
#define DIGYRO_FIFOCTRL_FIFO          0x20 
#define DIGYRO_FIFOCTRL_STREAM        0x40 
#define DIGYRO_FIFOCTRL_STREAM2FIFO   0x60 
#define DIGYRO_FIFOCTRL_BYPASS2STREAM 0x80 
#define DIGYRO_FIFOCTRL_WATERMARK_MASK 0x1F 

#define DIGYRO_STATUS_XDATA   0x01 
#define DIGYRO_STATUS_YDATA   0x02 
#define DIGYRO_STATUS_ZDATA   0x04 
#define DIGYRO_STATUS_XYZDATA 0x08 
#define DIGYRO_STATUS_XOVER   0x10 
#define DIGYRO_STATUS_YOVER   0x20 
#define DIGYRO_STATUS_ZOVER   0x40 
#define DIGYRO_STATUS_XYZOVER 0x80 

#define DIACCL_REG_XLOW       0x00  
#define DIACCL_REG_XHIGH      0x01  
#define DIACCL_REG_YLOW       0x02  
#define DIACCL_REG_YHIGH      0x03  
#define DIACCL_REG_ZLOW       0x04  
#define DIACCL_REG_ZHIGH      0x05  
#define DIACCL_REG_X8         0x06  
#define DIACCL_REG_Y8         0x07  
#define DIACCL_REG_Z8         0x08  
#define DIACCL_REG_STATUS     0x09  
#define DIACCL_REG_DETECTSRC  0x0A  
#define DIACCL_REG_OUTTEMP    0x0B  
#define DIACCL_REG_I2CADDR    0x0D  
#define DIACCL_REG_USERINFO   0x0E  
#define DIACCL_REG_WHOAMI     0x0F  
#define DIACCL_REG_XLOWDRIFT  0x10  
#define DIACCL_REG_XHIGHDRIFT 0x11  
#define DIACCL_REG_YLOWDRIFT  0x12  
#define DIACCL_REG_YHIGHDRIFT 0x13  
#define DIACCL_REG_ZLOWDRIFT  0x14  
#define DIACCL_REG_ZHIGHDRIFT 0x15  
#define DIACCL_REG_MODECTRL   0x16  
#define DIACCL_REG_INTLATCH   0x17  
#define DIACCL_REG_CTRL1      0x18  
#define DIACCL_REG_CTRL2      0x19  
#define DIACCL_REG_LVLDETTHR  0x1A  
#define DIACCL_REG_PLSDETTHR  0x1B  
#define DIACCL_REG_PLSDURVAL  0x1C  
#define DIACCL_REG_LATENCYTM  0x1D  
#define DIACCL_REG_TIMEWINDOW 0x1E  

#define DIACCL_STATUS_DATAREADY 0x01  
#define DIACCL_STATUS_DATAOVER  0x02  
#define DIACCL_STATUS_PARITYERR 0x04  

#define DIACCL_MODE_STANDBY   0x00  
#define DIACCL_MODE_MEASURE   0x01  
#define DIACCL_MODE_LVLDETECT 0x02  
#define DIACCL_MODE_PLSDETECT 0x03  
#define DIACCL_MODE_GLVL8     0x00  
#define DIACCL_MODE_GLVL2     0x04  
#define DIACCL_MODE_GLVL4     0x08  

#define DIACCL_INTERRUPT_LATCH_CLEAR1 0x01  
#define DIACCL_INTERRUPT_LATCH_CLEAR2 0x02  

#define DIACCL_CTRL1_INT2TOINT1 0x01  
#define DIACCL_CTRL1_LEVELPULSE 0x00  
#define DIACCL_CTRL1_PULSELEVEL 0x02  
#define DIACCL_CTRL1_PULSEPULSE 0x04  
#define DIACCL_CTRL1_NO_XDETECT 0x08  
#define DIACCL_CTRL1_NO_YDETECT 0x10  
#define DIACCL_CTRL1_NO_ZDETECT 0x20  
#define DIACCL_CTRL1_THRESH_INT 0x40  
#define DIACCL_CTRL1_FILT_BW125 0x80  

#define DIACCL_CTRL2_LVLPOL_NEGAND 0x01  
#define DIACCL_CTRL2_DETPOL_NEGAND 0x02  
#define DIACCL_CTRL2_DRIVE_STRONG  0x04  

#define MI_ADDR_XG1300L      0x02 
#define XG1300L_REG_ANGLE    0x42 
#define XG1300L_REG_TURNRATE 0x44 
#define XG1300L_REG_XAXIS    0x46 
#define XG1300L_REG_YAXIS    0x48 
#define XG1300L_REG_ZAXIS    0x4A 
#define XG1300L_REG_RESET    0x60 
#define XG1300L_REG_2G       0x61 
#define XG1300L_REG_4G       0x62 
#define XG1300L_REG_8G       0x63 
#define XG1300L_SCALE_2G     0x01 
#define XG1300L_SCALE_4G     0x02 
#define XG1300L_SCALE_8G     0x04 

#define RICImgPoint(_X, _Y) (_X)&0xFF, (_X)>>8, (_Y)&0xFF, (_Y)>>8
#define RICImgRect(_Pt, _W, _H) _Pt, (_W)&0xFF, (_W)>>8, (_H)&0xFF, (_H)>>8
#define RICOpDescription(_Options, _Width, _Height) 8, 0, 0, 0, (_Options)&0xFF, (_Options)>>8, (_Width)&0xFF, (_Width)>>8, (_Height)&0xFF, (_Height)>>8
#define RICOpCopyBits(_CopyOptions, _DataAddr, _SrcRect, _DstPoint) 18, 0, 3, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, (_DataAddr)&0xFF, (_DataAddr)>>8, _SrcRect, _DstPoint
#define RICOpPixel(_CopyOptions, _Point, _Value) 10, 0, 4, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Value)&0xFF, (_Value)>>8
#define RICOpLine(_CopyOptions, _Point1, _Point2) 12, 0, 5, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point1, _Point2
#define RICOpRect(_CopyOptions, _Point, _Width, _Height) 12, 0, 6, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Width)&0xFF, (_Width)>>8, (_Height)&0xFF, (_Height)>>8
#define RICOpCircle(_CopyOptions, _Point, _Radius) 10, 0, 7, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Radius)&0xFF, (_Radius)>>8
#define RICOpNumBox(_CopyOptions, _Point, _Value) 10, 0, 8, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_Value)&0xFF, (_Value)>>8
#define RICOpSprite(_DataAddr, _Rows, _BytesPerRow, _SpriteData) ((_Rows*_BytesPerRow)+((_Rows*_BytesPerRow)%2)+8)&0xFF, ((_Rows*_BytesPerRow)+((_Rows*_BytesPerRow)%2)+8)>>8, 1, 0, (_DataAddr)&0xFF, (_DataAddr)>>8, (_Rows)&0xFF, (_Rows)>>8, (_BytesPerRow)&0xFF, (_BytesPerRow)>>8, _SpriteData
#define RICSpriteData(...) __VA_ARGS__
#define RICOpVarMap(_DataAddr, _MapCount, _MapFunction) ((_MapCount*4)+6)&0xFF, ((_MapCount*4)+6)>>8, 2, 0, (_DataAddr)&0xFF, (_DataAddr)>>8, (_MapCount)&0xFF, (_MapCount)>>8, _MapFunction
#define RICMapElement(_Domain, _Range) (_Domain)&0xFF, (_Domain)>>8, (_Range)&0xFF, (_Range)>>8
#define RICMapFunction(_MapElement, ...) _MapElement, __VA_ARGS__
#define RICArg(_arg) ((_arg)|0x1000)
#define RICMapArg(_mapidx, _arg) ((_arg)|0x1000|(((_mapidx)&0xF)<<8))
#define RICOpPolygon(_CopyOptions, _Count, _ThePoints)  ((_Count*4)+6)&0xFF, ((_Count*4)+6)>>8, 10, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, (_Count)&0xFF, (_Count)>>8, _ThePoints
#define RICPolygonPoints(_pPoint1, _pPoint2, ...) _pPoint1, _pPoint2, __VA_ARGS__
#define RICOpEllipse(_CopyOptions, _Point, _RadiusX, _RadiusY) 12, 0, 9, 0, (_CopyOptions)&0xFF, (_CopyOptions)>>8, _Point, (_RadiusX)&0xFF, (_RadiusX)>>8, (_RadiusY)&0xFF, (_RadiusY)>>8

#define CHAR_BIT   8           
#define SCHAR_MIN  -128        
#define SCHAR_MAX  127         
#define UCHAR_MAX  255         
/*
#define CHAR_MIN   -128        
#define CHAR_MAX   127         
*/
#define CHAR_MIN   0           
#define CHAR_MAX   255         

#define SHRT_MIN   -32768      
#define SHRT_MAX   32767       
#define USHRT_MAX  65535       
#define INT_MIN    -32768      
#define INT_MAX    32767       
#define UINT_MAX   65535       
#define LONG_MIN   -2147483648 
#define LONG_MAX   2147483647  
#define ULONG_MAX  4294967295  
#ifdef __ENHANCED_FIRMWARE
#define RAND_MAX   2147483646  
#else
#define RAND_MAX   65535       
#endif

#define GL_POLYGON             1 
#define GL_LINE                2 
#define GL_POINT               3 
#define GL_CIRCLE              4 

#define GL_TRANSLATE_X       1 
#define GL_TRANSLATE_Y       2 
#define GL_TRANSLATE_Z       3 
#define GL_ROTATE_X          4 
#define GL_ROTATE_Y          5 
#define GL_ROTATE_Z          6 
#define GL_SCALE_X           7 
#define GL_SCALE_Y           8 
#define GL_SCALE_Z           9 

#define GL_CIRCLE_SIZE          1 
#define GL_CULL_MODE            2 
#define GL_CAMERA_DEPTH         3 
#define GL_ZOOM_FACTOR          4 

#define GL_CULL_BACK           2 
#define GL_CULL_FRONT          3 
#define GL_CULL_NONE           4 

#endif 
