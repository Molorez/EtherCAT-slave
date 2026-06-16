/**
 * \addtogroup EL9800Appl EL9800 application
 * @{
 * This application includes three functional modules:<br>
 * Digital Input<br>
 * Digital Outputs<br>
 * Analog Input<br>
 * The objects of the modules are defined according the ETG.5001.<br>
 */

/**
\file el9800appl.h
\author EthercatSSC@beckhoff.com
\brief EL9800 Application defines, typedefs and global variables

\version 5.01

<br>Changes to version - :<br>
V5.01 : Start file change log
 */
#ifndef _EL9800APPL_H_
#define _EL9800APPL_H_

/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecatappl.h"


/*************************************************************************************************************************************************************************/
/**************************************************************************1、结构体定义部分******************************************************************************/
/*************************************************************************************************************************************************************************/

/*-------------------------------------------------------------------------------------------Struct 0x1C12---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[2]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C12;

/*-------------------------------------------------------------------------------------------Struct 0x1601---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[9]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1601;

/*-------------------------------------------------------------------------------------------Struct 0x7010---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(bLED1); /**< \brief LED 1*/
   BOOLEAN(bLED2); /**< \brief LED 2*/
   BOOLEAN(bLED3); /**< \brief LED 3*/
   BOOLEAN(bLED4); /**< \brief LED 4*/
   BOOLEAN(bLED5); /**< \brief LED 5*/
   BOOLEAN(bLED6); /**< \brief LED 6*/
   BOOLEAN(bLED7); /**< \brief LED 7*/
   BOOLEAN(bLED8); /**< \brief LED 8*/
   ALIGN8(SubIndex008) /**< \brief 8Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ7010;

/*-------------------------------------------------------------------------------------------Struct 0x1602---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[1]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1602;

/*-------------------------------------------------------------------------------------------Struct 0x7011---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   controldata;
} OBJ_STRUCT_PACKED_END
TOBJ7011;

/*-------------------------------------------------------------------------------------------Struct 0x1C13---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[2]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C13;

/*-------------------------------------------------------------------------------------------Struct 0x1A00---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[9]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A00;

/*-------------------------------------------------------------------------------------------Struct 0x6000---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(bSwitch1); /**< \brief Switch 1*/
   BOOLEAN(bSwitch2); /**< \brief Switch 2*/
   BOOLEAN(bSwitch3); /**< \brief Switch 3*/
   BOOLEAN(bSwitch4); /**< \brief Switch 4*/
   BOOLEAN(bSwitch5); /**< \brief Switch 5*/
   BOOLEAN(bSwitch6); /**< \brief Switch 6*/
   BOOLEAN(bSwitch7); /**< \brief Switch 7*/
   BOOLEAN(bSwitch8); /**< \brief Switch 8*/
   ALIGN8(SubIndex009) /**< \brief 8Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ6000;

/*-------------------------------------------------------------------------------------------Struct 0x1A02---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[8]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A02;

/*-------------------------------------------------------------------------------------------Struct 0x6020---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(bUnderrange); /**< \brief (SI1) Analog input under range*/
   BOOLEAN(bOverrange); /**< \brief (SI2) Analog input over range*/
   BIT2(b2Limit1); /**< \brief (SI3) Analog input 1st limit*/
   BIT2(b2Limit2); /**< \brief (SI5) Analog input 2nd limit*/
   ALIGN2(SubIndex006) /**< \brief 2Bit alignment*/
   ALIGN6(SubIndex007) /**< \brief 2Bit alignment*/
   BOOLEAN(bTxPDOState); /**< \brief (SI15) TxPdo state*/
   BOOLEAN(bTxPDOToggle); /**< \brief (SI16) TxPdo toggle*/
   INT16   i16Analoginput; /**< \brief (SI17) Analog input value*/
} OBJ_STRUCT_PACKED_END
TOBJ6020;

/*-------------------------------------------------------------------------------------------Struct 0x8020---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(bEnableuserscale); /**< \brief Enable user scaling*/
   BIT3(b3Presentation); /**< \brief Value presentation*/
   ALIGN2(SubIndex005) /**< \brief 2Bit Alignment*/
   BOOLEAN(bEnablelimit1); /**< \brief Enable limit 1*/
   BOOLEAN(bEnablelimit2); /**< \brief Enable limit 2*/
   ALIGN8(SubIndex009) /**< \brief 8Bit Alignment*/
   INT16   i16Offset; /**< \brief Value offset*/
   INT32   i32Gain; /**< \brief Value gain*/
   INT16   i16Limit1; /**< \brief Value limit 1*/
   INT16   i16Limit2; /**< \brief Value limit 2*/
} OBJ_STRUCT_PACKED_END
TOBJ8020;

/*-------------------------------------------------------------------------------------------Struct 0xF000---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT16   u16Moduleindexdistance; /**< \brief Module Index distance
                                     * 
                                     * I
                                     * Default: 0x10*/
   UINT16   u16Maximumnumberofmodules; /**< \brief Maximum number of modules*/
} OBJ_STRUCT_PACKED_END
TOBJF000;

/*-------------------------------------------------------------------------------------------Struct 0xF010---------------------------------------------------------------*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT32   aEntries[3]; /**< \brief Module profile information buffer
                          * 
                          * Bit 0..15: Profile number of the module on position 1<br>
                          * Bit 16..31: Profile specific*/
} OBJ_STRUCT_PACKED_END
TOBJF010;
/** @}*/

#endif //_EL9800APPL_H_





#ifdef _EVALBOARD_
    #define PROTO
#else
    #define PROTO extern
#endif


		
		
/*************************************************************************************************************************************************************************/
/**************************************************************************2、EntryDesc 和 Name 部分**********************************************************************/
/*************************************************************************************************************************************************************************/
#ifdef _OBJD_

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1C12 0x1C13------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asPDOAssignEntryDesc[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};

/*---------------------------------------------
-    0x0800: ENUM (Signed/Unsigned Presentation)
-----------------------------------------------*/
CHAR sEnum0800_Value00[] = "\000\000\000\000Signed presentation"; /**< \brief Value = 0x00, Text = Signed presentation */
CHAR sEnum0800_Value01[] = "\001\000\000\000Unsigned presentation"; /**< \brief Value = 0x01, Text = Unsigned presentation */
CHAR *apEnum0800[2] = { sEnum0800_Value00, sEnum0800_Value01};/**< \brief List of Enum (0x800) values*/

OBJCONST UCHAR OBJMEM aName0x1C13[] = "TxPDO assign";
OBJCONST UCHAR OBJMEM aName0x1C12[] = "RxPDO assign";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1601-------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1601[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },    // index
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 1
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 2
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 3
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 4
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 5
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 6
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 7
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 8
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 9
};

OBJCONST UCHAR OBJMEM aName0x1601[] = "DO RxPDO-Map\000\377";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x7010--------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7010[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: LED 1 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: LED 2 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: LED 3 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: LED 4 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 005: LED 5 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 006: LED 6 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 007: LED 7 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 008: LED 8 */
   {0x0000, 0x08, 0}}; /* Subindex 008 for align */

OBJCONST UCHAR OBJMEM aName0x7010[] = "DO Outputs\000LED 1\000LED 2\000LED 3\000LED 4\000LED 5\000LED 6\000LED 7\000LED 8\000\000\377";
	 
/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1602--------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1602[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },    // index
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},   // entry 1
};

OBJCONST UCHAR OBJMEM aName0x1602[] = "Control Data RxPDO-Map\000\377";	 
	 
/*-------------------------------------------------------------------------------------------EntryDesc Name 0x7011--------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x7011[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },    // index
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_RXPDOMAPPING},   // entry 1
};

OBJCONST UCHAR OBJMEM aName0x7011[] = "Control Data\000\377";	 
/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1A00--------------------------------------------------*/ 
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A00[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

OBJCONST UCHAR OBJMEM aName0x1A00[] = "DI TxPDO-Map\000\377";
	
/*-------------------------------------------------------------------------------------------EntryDesc Name 0x6000--------------------------------------------------*/ 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 001: Switch 1 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 002: Switch 2 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 003: Switch 3 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 004: Switch 4 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 005: Switch 5 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 006: Switch 6 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 007: Switch 7 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 008: Switch 8 */
   {0x0000, 0x08, 0}}; /* Subindex 009 for align */

OBJCONST UCHAR OBJMEM aName0x6000[] = "DI Inputs\000Switch 1\000Switch 2\000Switch 3\000Switch 4\000Switch 5\000Switch 6\000Switch 7\000Switch 8\000\000\377";
	 
/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1A02--------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A02[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 001: SubIndex 001 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 002: SubIndex 002 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 003: SubIndex 003 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 004: SubIndex 004 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 005: SubIndex 005 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 006: SubIndex 006 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 007: SubIndex 007 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}}; /* SubIndex 008: SubIndex 008 */

OBJCONST UCHAR OBJMEM aName0x1A02[] = "AI TxPDO-Map\000\377";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x6020--------------------------------------------------*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6020[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_BIT2, 0x02, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {0x0000, 0, 0},
   {DEFTYPE_BIT2, 0x02, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {0x0000, 0x02, 0},
   {0x0000, 0x06, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING}};

OBJCONST UCHAR OBJMEM aName0x6020[] = "AI Inputs\000Underrange\000Overrange\000Limit 1\000\000Limit 2\000\000\000\000\000\000\000\000\000\000TxPDO State\000TxPDO Toggle\000Analog input\000\377";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x1802--------------------------------------------------*/	 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1802[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {DEFTYPE_OCTETSTRING, 0x00, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {0, 0x0, 0},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}};

OBJCONST UCHAR OBJMEM aName0x1802[] = "TxPDO Parameter\000\000\000\000\000\000Exclude TxPDOs\000TxPDOState\000\000TxPDO Toggle\000\377";
PROTO UINT8 ReadObject0x1802( UINT16 index, UINT8 subindex, UINT32 dataSize, UINT16 MBXMEM * pData, UINT8 bCompleteAccess );

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x8020--------------------------------------------------*/ 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8020[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0800, 0x03, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0x02, 0},
   {0x0000, 0, 0},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0000, 0x08, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER32, 0x20, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS}};


OBJCONST UCHAR OBJMEM aName0x8020[] = "AI Settings\000Enable user scale\000Presentation\000\000\000\000\000Enable limit 1\000Enable limit 2\000\000\000\000\000\000\000\000\000Offset\000Gain\000Limit 1\000Limit 2\000\377";

	 
/*-------------------------------------------------------------------------------------------EntryDesc Name 0xF000--------------------------------------------------*/ 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};

/** \brief 0xF000 (Modular Device Profile) object and entry names*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular device profile\000Module index distance\000Maximum number of modules\000\377";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0xF010--------------------------------------------------*/ 	 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF010[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

OBJCONST UCHAR OBJMEM aName0xF010[] = "Module profile list";

/*-------------------------------------------------------------------------------------------EntryDesc Name 0x0800--------------------------------------------------*/ 	 
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x0800[] =
   {{DEFTYPE_UNSIGNED8, 8, ACCESS_READ | OBJACCESS_NOPDOMAPPING},
    {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value00), ACCESS_READ | OBJACCESS_NOPDOMAPPING},
   {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value01), ACCESS_READ | OBJACCESS_NOPDOMAPPING}};


#endif

/*************************************************************************************************************************************************************************/
/**************************************************************************3、初始值定义部分******************************************************************************/
/*************************************************************************************************************************************************************************/
	 
/*-------------------------------------------------------------------------------------------Value 0x1C12----------------------------------------------------------------*/
PROTO TOBJ1C12 sRxPDOassign
#ifdef _EVALBOARD_
= {0x02, {0x1601,0x1602}}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x1601----------------------------------------------------------------*/
PROTO TOBJ1601 sDORxPDOMap
#ifdef _EVALBOARD_
 = {9,                 // sum of entries 
	      {0x70100101,    // entry 1, 0x7010, subindex 1, 1bit
         0x70100201,    // entry 2, 0x7010, subindex 2, 1bit
         0x70100301,    // entry 3, 0x7010, subindex 3, 1bit
         0x70100401,    // entry 4, 0x7010, subindex 4, 1bit
         0x70100501,    // entry 5, 0x7010, subindex 5, 1bit
         0x70100601,    // entry 6, 0x7010, subindex 6, 1bit
         0x70100701,    // entry 7, 0x7010, subindex 7, 1bit
         0x70100801,    // entry 8, 0x7010, subindex 8, 1bit
         0x08}          // entry 9
 }
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x7010----------------------------------------------------------------*/
PROTO TOBJ7010 sDOOutputs
#ifdef _EVALBOARD_
= {8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x1602----------------------------------------------------------------*/
PROTO TOBJ1602 sControlDataMap
#ifdef _EVALBOARD_
 = {1,                       // sum of entries 
	      {0x70110120}         // entry 1, 0x7010, subindex 1, 1bit
 }
#endif
;
 
/*-------------------------------------------------------------------------------------------Value 0x7011----------------------------------------------------------------*/
PROTO TOBJ7011 sControlData
#ifdef _EVALBOARD_
 = {1, 0}
#endif
;
/*-------------------------------------------------------------------------------------------Value 0x1C13----------------------------------------------------------------*/
PROTO TOBJ1C13 sTxPDOassign
#ifdef _EVALBOARD_
= {0x02, {0x1A00, 0x1A02}}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x1A00----------------------------------------------------------------*/
PROTO TOBJ1A00 sDITxPDOMap
#ifdef _EVALBOARD_
 = {9, {0x60000101, 0x60000201, 0x60000301, 0x60000401,0x60000501, 0x60000601, 0x60000701, 0x60000801, 0x08}}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x6000----------------------------------------------------------------*/
PROTO TOBJ6000 sDIInputs
#ifdef _EVALBOARD_
= {8, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0}
#endif
;

 /*-------------------------------------------------------------------------------------------Value 0x1A02----------------------------------------------------------------*/
PROTO TOBJ1A02 sAITxPDOMap
#ifdef _EVALBOARD_
= {8,                   // sum of index
	     {0x60200101,     // entry 1, 0x6020, subindex 1, 1bit, Underrange
        0x60200201,     // entry 2, 0x6020, subindex 2, 1bit, Overrange
        0x60200302,     // entry 3, 0x6020, subindex 3, 1bit, Limit 1
        0x60200502,     // entry 4, 0x6020, subindex 5, 2bit, Limit 2
        0x08,           // entry 5
        0x18020701,     // entry 6, 0x1802, subindex 7, 1bit, TxPDOState
        0x18020901,     // entry 7, 0x1802, subindex 9, 1bit, TXPDOToggle
        0x60201110,     // entry 8, 0x6020, sunindex 17,16bit, AnalogInput
			 }     
}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x6020----------------------------------------------------------------*/
PROTO TOBJ6020 sAIInputs
#ifdef _EVALBOARD_
= {17, 0x00, 0x00, 0x00, 0x00, 0, 0, 0x00, 0x00, 0x7FFF}
#endif
;

/*-------------------------------------------------------------------------------------------Value 0x1802----------------------------------------------------------------*/
PROTO UINT16 TxPDO1802Subindex0
#ifdef _EVALBOARD_
    = 9
#endif
  ;

/*-------------------------------------------------------------------------------------------Value 0x8020----------------------------------------------------------------*/
PROTO TOBJ8020 sAISettings
#ifdef _EVALBOARD_
= {20, 0x00, 0x00, 0, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00}
#endif
;
/*-------------------------------------------------------------------------------------------Value 0xF000---------------------------------------------------------------*/
PROTO TOBJF000 sModulardeviceprofile
#ifdef _EVALBOARD_
= {2, 0x10, 0x03}
#endif
;
/*-------------------------------------------------------------------------------------------Value 0xF010----------------------------------------------------------------*/
PROTO TOBJF010 sModulelist
#ifdef _EVALBOARD_
= {0x03,{0x64, 0xC8, 0x12C}}
#endif
;



#ifdef _OBJD_



//typedef struct OBJ_STRUCT_PACKED_START
//{
//		UINT16 objControlWord;
//		INT32  objTargetPosition;
//		INT32  objTargetVelocity;
//		INT16  objTargetTorque;
//		UINT16 objModesOfOperation;
//}OBJ_STRUCT_PACKED_END
//RXPDO;

//typedef struct OBJ_STRUCT_PACKED_START
//{
//		UINT16 objStatusWord;
//		INT32  objActualPosition;
//		INT32  objActualVelocity;
//		INT16  objActualTorque;
//		UINT16 objModesOfOperationDisplay;
//}OBJ_STRUCT_PACKED_END
//TXPDO;


//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6040 = {DEFTYPE_UNSIGNED16, 0x10, {ACCESS_READ | OBJACCESS_RXPDOMAPPING}};   // 数据类型，位长度，读写说明
//OBJCONST UCHAR OBJMEM aName0x6040[] = "Control Word";
//PROTO UINT16 Var0x6040 = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x607A = {DEFTYPE_INTEGER32, 0x20, {ACCESS_READ | OBJACCESS_RXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x607A[] = "Target Position";
//PROTO INT32 Var0x607A = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x60FF = {DEFTYPE_INTEGER32, 0x20, {ACCESS_READ | OBJACCESS_RXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x60FF[] = "Target Velocity";
//PROTO INT32 Var0x60FF = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6071 = {DEFTYPE_INTEGER16, 0x10, {ACCESS_READ | OBJACCESS_RXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6071[] = "Target Torque";
//PROTO INT16 Var0x6071 = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6060 = {DEFTYPE_UNSIGNED16, 0x10, {ACCESS_READ | OBJACCESS_RXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6060[] = "Modes of Operation";
//PROTO UINT16 Var0x6060 = 0x00;




//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6041 = {DEFTYPE_UNSIGNED16, 0x10, {ACCESS_READ | OBJACCESS_TXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6041[] = "Status Word";
//PROTO UINT16 Var0x6041 = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6064 = {DEFTYPE_INTEGER32, 0x20, {ACCESS_READ | OBJACCESS_TXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6064[] = "Actual Position";
//PROTO INT32 Var0x6064 = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x606C = {DEFTYPE_INTEGER32, 0x20, {ACCESS_READ | OBJACCESS_TXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x606C[] = "Actual Velocity";
//PROTO INT32 Var0x606C = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6077 = {DEFTYPE_INTEGER16, 0x10, {ACCESS_READ | OBJACCESS_TXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6077[] = "Actual Tarque";
//PROTO INT16 Var0x6077 = 0x00;

//OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6061 = {DEFTYPE_UNSIGNED16, 0x10, {ACCESS_READ | OBJACCESS_TXPDOMAPPING}};
//OBJCONST UCHAR OBJMEM aName0x6061[] = "Modes of Operation Display";
//PROTO UINT16 Var0x6061 = 0x00;


/*************************************************************************************************************************************************************************/
/**************************************************************************4、对象字典部分********************************************************************************/
/*************************************************************************************************************************************************************************/

/**
 *\brief EL9800 Application specific object dictionary
 * 
 */
TOBJECT    OBJMEM ApplicationObjDic[] = {
     /* Enum 0x0800 */
    {NULL,NULL,  0x0800, {DEFTYPE_ENUM,       2 | (OBJCODE_REC << 8)}, asEntryDesc0x0800,    0, apEnum0800 },
		
		
		/****************************************************************************/
		{NULL,NULL,  0x1C12, {DEFTYPE_UNSIGNED16, 2 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C12, &sRxPDOassign,       NULL, NULL, 0x0000 }, // 0x1601, 0x1602
    {NULL,NULL,  0x1601, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1601,    aName0x1601, &sDORxPDOMap,        NULL, NULL, 0x0000 }, // 0x7010
		{NULL,NULL,  0x7010, {DEFTYPE_RECORD,     8 | (OBJCODE_REC << 8)}, asEntryDesc0x7010,    aName0x7010, &sDOOutputs,         NULL, NULL, 0x0000 }, // led
		{NULL,NULL,  0x1602, {DEFTYPE_PDOMAPPING, 1 | (OBJCODE_REC << 8)}, asEntryDesc0x1602,    aName0x1602, &sControlDataMap,    NULL, NULL, 0x0000 }, // 0x1602
		{NULL,NULL,  0x7011, {DEFTYPE_RECORD,     1 | (OBJCODE_REC << 8)}, asEntryDesc0x7011,    aName0x7011, &sControlData,       NULL, NULL, 0x0000 },

//	  // 接收
//	  {NULL, NULL, 0x6040, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6040,   aName0x6040, &Var0x6040,          NULL, NULL, 0x0000},  // contol word
//	  {NULL, NULL, 0x607A, {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x607A,   aName0x607A, &Var0x607A,          NULL, NULL, 0x0000},  // target position
//		{NULL, NULL, 0X60FF, {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x60FF,   aName0x60FF, &Var0x60FF,          NULL, NULL, 0x0000},  // target velocity
//	  {NULL, NULL, 0x6071, {DEFTYPE_INTEGER16 , 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6071,   aName0x6071, &Var0x6071,          NULL, NULL, 0x0000},  // targer tarque
//	  {NULL, NULL, 0x6060, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6060,   aName0x6060, &Var0x6060,          NULL, NULL, 0x0000},  // mode of operation

		
		
		/****************************************************************************/
    {NULL,NULL,  0x1C13, {DEFTYPE_UNSIGNED16, 2 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C13, &sTxPDOassign,       NULL, NULL, 0x0000 }, // 0x1A00, 0x1A02 
    {NULL,NULL,  0x1A00, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A00,    aName0x1A00, &sDITxPDOMap,        NULL, NULL, 0x0000 }, // 0x6000
    {NULL,NULL,  0x1A02, {DEFTYPE_PDOMAPPING, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x1A02,    aName0x1A02, &sAITxPDOMap,        NULL, NULL, 0x0000 }, // 0x6020, 0x1820

		{NULL,NULL,  0x6000, {DEFTYPE_RECORD,     8 | (OBJCODE_REC << 8)}, asEntryDesc0x6000,    aName0x6000, &sDIInputs,          NULL, NULL, 0x0000 },  // switch
		{NULL,NULL,  0x6020, {DEFTYPE_RECORD,    17 | (OBJCODE_REC << 8)}, asEntryDesc0x6020,    aName0x6020, &sAIInputs,          NULL, NULL, 0x0000 },  // adc
    {NULL,NULL,  0x1802, {DEFTYPE_RECORD,     9 | (OBJCODE_REC << 8)}, asEntryDesc0x1802,    aName0x1802, &TxPDO1802Subindex0, ReadObject0x1802, NULL, 0x0000 },
	 
//	   // 上传
//		{NULL, NULL, 0x6041, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6041,   aName0x6041, &Var0x6041,          NULL, NULL, 0x0000},  // status word
//		{NULL, NULL, 0x6064, {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6064,   aName0x6064, &Var0x6064,          NULL, NULL, 0x0000},  // actual positon
//		{NULL, NULL, 0x606C, {DEFTYPE_INTEGER32 , 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x606C,   aName0x606C, &Var0x606C,          NULL, NULL, 0x0000},  // actual velocity
//		{NULL, NULL, 0x6077, {DEFTYPE_INTEGER16,  0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6077,   aName0x6077, &Var0x6077,          NULL, NULL, 0x0000},  // actual tarque
//		{NULL, NULL, 0x6061, {DEFTYPE_UNSIGNED16, 0 | (OBJCODE_VAR << 8)}, &asEntryDesc0x6061,   aName0x6061, &Var0x6061,          NULL, NULL, 0x0000},  // mode of operation
		
		/*************************************************************************/
		
		{NULL,NULL,  0x8020, {DEFTYPE_RECORD,    20 | (OBJCODE_REC << 8)}, asEntryDesc0x8020,    aName0x8020, &sAISettings,        NULL, NULL, 0x0008 },
    /* Object 0xF000 */
    {NULL,NULL,   0xF000, {DEFTYPE_RECORD, 2 | (OBJCODE_REC << 8)}, asEntryDesc0xF000, aName0xF000, &sModulardeviceprofile, NULL, NULL, 0x0000 },
    /* Object 0xF010 */
    {NULL,NULL,   0xF010, {DEFTYPE_UNSIGNED32, 3 | (OBJCODE_ARR << 8)}, asEntryDesc0xF010, aName0xF010, &sModulelist, NULL, NULL, 0x0000 },
    {NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

PROTO void APPL_Application(void);

PROTO void   APPL_AckErrorInd(UINT16 stateTrans);
PROTO UINT16 APPL_StartMailboxHandler(void);
PROTO UINT16 APPL_StopMailboxHandler(void);
PROTO UINT16 APPL_StartInputHandler(UINT16 *pIntMask);
PROTO UINT16 APPL_StopInputHandler(void);
PROTO UINT16 APPL_StartOutputHandler(void);
PROTO UINT16 APPL_StopOutputHandler(void);

PROTO UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize);
PROTO void APPL_InputMapping(UINT16* pData);
PROTO void APPL_OutputMapping(UINT16* pData);


#undef PROTO
/** @}*/
