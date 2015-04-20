#include "DebugHandStream.h"
#include <SenseKitUL/streams/hand_parameters.h>

namespace sensekit { namespace plugins { namespace hands {

    void DebugHandStream::set_parameter(sensekit_streamconnection_t connection,
                                        sensekit_parameter_id id,
                                        size_t inByteLength,
                                        sensekit_parameter_data_t inData)
    {
        switch (id)
        {
        case SENSEKIT_PARAMETER_DEBUG_HAND_VIEW_TYPE:
            set_view_parameter(inByteLength, inData);
            break;
        }
    }

    void DebugHandStream::get_parameter(sensekit_streamconnection_t connection,
                                        sensekit_parameter_id id,
                                        sensekit_parameter_bin_t& parameterBin)
    {
        switch (id)
        {
        case SENSEKIT_PARAMETER_DEBUG_HAND_VIEW_TYPE:
            get_view_parameter(parameterBin);
            break;
        }
    }

    void DebugHandStream::invoke(sensekit_streamconnection_t connection,
                                 sensekit_command_id commandId,
                                 size_t inByteLength,
                                 sensekit_parameter_data_t inData,
                                 sensekit_parameter_bin_t& parameterBin)
    {
    }

    void DebugHandStream::get_view_parameter(sensekit_parameter_bin_t& parameterBin)
    {
        size_t resultByteLength = sizeof(DebugHandViewType);

        sensekit_parameter_data_t parameterData;
        sensekit_status_t rc = get_pluginService().get_parameter_bin(resultByteLength,
                                                                     &parameterBin,
                                                                     &parameterData);
        if (rc == SENSEKIT_STATUS_SUCCESS)
        {
            memcpy(parameterData, &m_viewType, resultByteLength);
        }
    }

    void DebugHandStream::set_view_parameter(size_t inByteLength, sensekit_parameter_data_t& inData)
    {
        if (inByteLength >= sizeof(DebugHandViewType))
        {
            DebugHandViewType newViewType;
            memcpy(&newViewType, inData, sizeof(DebugHandViewType));

            set_view_type(newViewType);
        }
    }
} } }