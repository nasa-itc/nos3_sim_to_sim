#include <subsim_data_provider.hpp>

namespace Nos3
{
    REGISTER_DATA_PROVIDER(SubsimDataProvider,"SUBSIM_PROVIDER");

    extern ItcLogger::Logger *sim_logger;

    SubsimDataProvider::SubsimDataProvider(const boost::property_tree::ptree& config) : SimIDataProvider(config)
    {
        sim_logger->trace("SubsimDataProvider::SubsimDataProvider:  Constructor executed");
        _request_count = 0;
    }

    boost::shared_ptr<SimIDataPoint> SubsimDataProvider::get_data_point(void) const
    {
        sim_logger->trace("SubsimDataProvider::get_data_point:  Executed");

        /* Prepare the provider data */
        _request_count++;

        /* Request a data point */
        SimIDataPoint *dp = new SubsimDataPoint(_request_count);

        /* Return the data point */
        return boost::shared_ptr<SimIDataPoint>(dp);
    }
}
