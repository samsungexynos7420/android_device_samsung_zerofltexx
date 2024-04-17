/*
 * Bluetooth Configuration Header File
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

// Set the default local Bluetooth name
#define BTM_DEF_LOCAL_NAME   "Samsung Galaxy S6"

// Enable Wideband Speech (WBS) support
#define BTM_WBS_INCLUDED        TRUE
// Set Wideband Speech as preferred codec for Hands-Free Profile (HFP)
#define BTIF_HF_WBS_PREFERRED   TRUE

// Enable Vendor Specific Extensions for BLE
#define BLE_VND_INCLUDED        TRUE

// Disable Enhanced Synchronous Connection Oriented (eSCO) commands
#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE

#endif
