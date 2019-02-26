//
// Created by dchansen on 1/17/19.
//

#pragma once

#include <cstdint>

namespace Gadgetron::Core {
    enum MessageID : uint16_t {
        FILENAME                                           = 1,
        CONFIG                                             = 2,
        HEADER                                             = 3,
        CLOSE                                              = 4,
        TEXT                                               = 5,
        QUERY                                              = 6,
        RESPONSE                                           = 7,
        ERROR                                              = 8,
        GADGET_MESSAGE_ACQUISITION                         = 1001, // DEPRECATED
        GADGET_MESSAGE_NEW_MEASUREMENT                     = 1002, // DEPRECATED
        GADGET_MESSAGE_END_OF_SCAN                         = 1003, // DEPRECATED
        GADGET_MESSAGE_IMAGE_CPLX_FLOAT                    = 1004, // DEPRECATED
        GADGET_MESSAGE_IMAGE_REAL_FLOAT                    = 1005, // DEPRECATED
        GADGET_MESSAGE_IMAGE_REAL_USHORT                   = 1006, // DEPRECATED
        GADGET_MESSAGE_EMPTY                               = 1007, // DEPRECATED
        GADGET_MESSAGE_ISMRMRD_ACQUISITION                 = 1008,
        GADGET_MESSAGE_ISMRMRD_IMAGE_CPLX_FLOAT            = 1009,
        GADGET_MESSAGE_ISMRMRD_IMAGE_REAL_FLOAT            = 1010,
        GADGET_MESSAGE_ISMRMRD_IMAGE_REAL_USHORT           = 1011,
        GADGET_MESSAGE_DICOM                               = 1012,
        GADGET_MESSAGE_CLOUD_JOB                           = 1013, // DEPRECATED
        GADGET_MESSAGE_GADGETCLOUD_JOB                     = 1014, // DEPRECATED
        GADGET_MESSAGE_ISMRMRD_IMAGEWITHATTRIB_CPLX_FLOAT  = 1015,
        GADGET_MESSAGE_ISMRMRD_IMAGEWITHATTRIB_REAL_FLOAT  = 1016,
        GADGET_MESSAGE_ISMRMRD_IMAGEWITHATTRIB_REAL_USHORT = 1017,
        GADGET_MESSAGE_DICOM_WITHNAME                      = 1018,
        GADGET_MESSAGE_DEPENDENCY_QUERY                    = 1019,
        GADGET_MESSAGE_ISMRMRD_BUFFER                      = 1020,
        GADGET_MESSAGE_ISMRMRD_IMAGE_ARRAY                 = 1021
    };
}
