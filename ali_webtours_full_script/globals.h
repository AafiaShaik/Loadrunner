#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables

Extended_Log_On()
{
lr_set_debug_message (LR_MSG_CLASS_EXTENDED_LOG | LR_MSG_CLASS_FULL_TRACE, LR_SWITCH_ON);
return 0;
}
Extended_Log_Off()
{
lr_set_debug_message (LR_MSG_CLASS_EXTENDED_LOG | LR_MSG_CLASS_FULL_TRACE, LR_SWITCH_OFF);
return 0;
}

#endif // _GLOBALS_H
