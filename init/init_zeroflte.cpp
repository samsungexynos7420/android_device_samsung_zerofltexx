/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>

#include "init_universal7420.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

void set_sim_info()
{
    const char *simslot_count_path = "/proc/simslot_count";
    std::string simslot_count;
    
    if (ReadFileToString(simslot_count_path, &simslot_count)) {
        simslot_count = Trim(simslot_count); // strip newline
        property_override("ro.multisim.simslotcount", simslot_count.c_str());
        if (simslot_count.compare("2") == 0) {
            property_override("vendor.rild.libpath2", "/vendor/lib/libsec-ril-dsds.so");
            property_override("persist.radio.multisim.config", "dsds");
        }
    }
    else {
        LOG(ERROR) << "Could not open '" << simslot_count_path << "'\n";
    }
}

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G920F") == 0) {
        /* heroltexx */
        property_override("ro.build.description", "zerofltexx-user 7.0 NRD90M G920FXXU6EVG1 release-keys");
        set_ro_product_prop("device", "zerofltexx");
        set_ro_build_prop("fingerprint", "samsung/zerofltexx/zeroflte:7.0/NRD90M/G920FXXU6EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G920F");
        set_ro_product_prop("name", "zerofltexx");
        gsm_properties("9");
    } else if (bootloader.find("G920W8") == 0) {
        /* heroltebmc */
        property_override("ro.build.description", "zerofltecan-user 7.0 NRD90M G920W8VLU6DVG1 release-keys");
        set_ro_product_prop("device", "zerofltecan");
        set_ro_build_prop("fingerprint", "samsung/zerofltecan/zerofltecan:7.0/NRD90M/G920W8VLU6DVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G920W8");
        set_ro_product_prop("name", "zerofltecan");
        gsm_properties("9");
    } else if (bootloader.find("G920S") == 0) {
        /* herolteskt */
        property_override("ro.build.description", "zeroflteskt-user 7.0 NRD90M G920SKSU3EVG1 release-keys");
        set_ro_product_prop("device", "zeroflteskt");
        set_ro_build_prop("fingerprint", "samsung/zeroflteskt/zeroflte:7.0/NRD90M/G920SKSU3EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G920S");
        set_ro_product_prop("name", "zeroflteskt");
        gsm_properties("9");
    }  else if (bootloader.find("G920L") == 0) {
        /* heroltelgt */
        property_override("ro.build.description", "zerofltelgt-user 7.0 NRD90M G920LKLU3EVG1 release-keys");
        set_ro_product_prop("device", "zerofltelgt");
        set_ro_build_prop("fingerprint", "samsung/zerofltelgt/zerofltelgt:7.0/NRD90M/G920LKLU3EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G920L");
        set_ro_product_prop("name", "zerofltelgt");
        gsm_properties("9");
    } else {
        gsm_properties("9");
    }

	set_sim_info();
    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
