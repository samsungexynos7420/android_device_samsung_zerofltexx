#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -euo pipefail

# Define variables
VENDOR="samsung"
DEVICE="zerofltexx"
MY_DIR="${BASH_SOURCE%/*}"
ANDROID_ROOT="${MY_DIR}/../../.."
HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"

# Functions
initialize() {
    # Check if the helper script exists
    if [ ! -f "${HELPER}" ]; then
        echo "Error: Unable to find helper script at ${HELPER}"
        exit 1
    fi

    # Source the helper script
    source "${HELPER}"
}

add_custom_makefile_rules() {
    # Add custom rules to the generated Android makefiles
    OUTDIR="vendor/${VENDOR}/${DEVICE}"
    ANDROID_MK="${ANDROID_ROOT}/${OUTDIR}/Android.mk"

    cat <<EOF >> "${ANDROID_MK}"
include \$(CLEAR_VARS)

LIFEVIBES_LIBS := libLifevibes_lvverx.so libLifevibes_lvvetx.so

LIFEVIBES_SYMLINKS := \$(addprefix \$(TARGET_OUT_VENDOR)/lib/,\$(notdir \$(LIFEVIBES_LIBS)))
\$(LIFEVIBES_SYMLINKS): \$(LOCAL_INSTALLED_MODULE)
	@echo "LifeVibes lib link: \$@"
	@mkdir -p \$(dir \$@)
	@rm -rf \$@
	\$(hide) ln -sf /vendor/lib/soundfx/\$(notdir \$@) \$@

ALL_DEFAULT_INSTALLED_MODULES += \$(LIFEVIBES_SYMLINKS)

EOF
}

# Main
main() {
    initialize
    setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}"
    write_headers
    write_makefiles "${MY_DIR}/proprietary-files.txt" true
    add_custom_makefile_rules
    write_footers
}

# Execute main
main
