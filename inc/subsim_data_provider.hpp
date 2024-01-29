#ifndef NOS3_SUBSIMDATAPROVIDER_HPP
#define NOS3_SUBSIMDATAPROVIDER_HPP

#include <boost/property_tree/xml_parser.hpp>
#include <ItcLogger/Logger.hpp>
#include <subsim_data_point.hpp>
#include <sim_i_data_provider.hpp>

namespace Nos3
{
    class SubsimDataProvider : public SimIDataProvider
    {
    public:
        /* Constructors */
        SubsimDataProvider(const boost::property_tree::ptree& config);

        /* Accessors */
        boost::shared_ptr<SimIDataPoint> get_data_point(void) const;

    private:
        /* Disallow these */
        ~SubsimDataProvider(void) {};
        SubsimDataProvider& operator=(const SubsimDataProvider&) {return *this;};

        mutable double _request_count;
    };
}

#endif
