#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

# Constants
VENDOR=samsung
DEVICE=zerofltexx
ANDROID_ROOT="$(dirname "$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")")"
HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
CLEAN_VENDOR=true
KANG=""
SECTION=""

# Load helper script
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

# Parse command-line arguments
while getopts ":nks:" opt; do
    case ${opt} in
        n )
            CLEAN_VENDOR=false
            ;;
        k )
            KANG="--kang"
            ;;
        s )
            SECTION="${OPTARG}"
            CLEAN_VENDOR=false
            ;;
        \? )
            echo "Invalid option: $OPTARG" 1>&2
            exit 1
            ;;
        : )
            echo "Invalid option: $OPTARG requires an argument" 1>&2
            exit 1
            ;;
    esac
done
shift $((OPTIND -1))

# Set default source if not provided
SRC="${1:-adb}"

# Initialize vendor setup
setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}" false "${CLEAN_VENDOR}"

# Extract proprietary files
extract "${ANDROID_ROOT}/device/${VENDOR}/${DEVICE}/proprietary-files.txt" "${SRC}" "${KANG}" --section "${SECTION}"

# Fix proprietary blobs
BLOB_ROOT="${ANDROID_ROOT}/vendor/${VENDOR}/${DEVICE}/proprietary"

# Patch shared library dependencies
"${PATCHELF}" --replace-needed libgui.so libsensor.so "${BLOB_ROOT}/bin/gpsd"
"${PATCHELF}" --replace-needed libprotobuf-cpp-full.so libprotobuf-cpp-fl24.so "${BLOB_ROOT}/vendor/lib/libsec-ril.so"
sed -i "s/libprotobuf-cpp-full/libprotobuf-cpp-fl24/" "${BLOB_ROOT}/vendor/lib64/libsec-ril.so"
"${PATCHELF}" --replace-needed libprotobuf-cpp-full.so libprotobuf-cpp-fl24.so "${BLOB_ROOT}/vendor/lib/libsec-ril-dsds.so"
sed -i "s/libprotobuf-cpp-full/libprotobuf-cpp-fl24/" "${BLOB_ROOT}/vendor/lib64/libsec-ril-dsds.so"

# Remove unnecessary library dependency
"${PATCHELF}" --remove-needed vendor.samsung.hardware.nfc@1.0.so "${BLOB_ROOT}/vendor/lib/hw/nfc_nci.default.so"
"${PATCHELF}" --remove-needed vendor.samsung.hardware.nfc@1.0.so "${BLOB_ROOT}/vendor/lib64/hw/nfc_nci.default.so"

# Modify file paths
sed -i "s/\/system\/app/\/vendor\/app/g" "${BLOB_ROOT}/vendor/bin/mcDriverDaemon"

# Generate makefiles
"${ANDROID_ROOT}/device/${VENDOR}/${DEVICE}/setup-makefiles.sh"
