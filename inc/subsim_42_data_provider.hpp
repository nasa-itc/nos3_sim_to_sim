#ifndef NOS3_SUBSIM42DATAPROVIDER_HPP
#define NOS3_SUBSIM42DATAPROVIDER_HPP

#include <boost/property_tree/ptree.hpp>
#include <ItcLogger/Logger.hpp>
#include <subsim_data_point.hpp>
#include <sim_data_42socket_provider.hpp>

namespace Nos3
{
    /* Standard for a 42 data provider */
    class Subsim42DataProvider : public SimData42SocketProvider
    {
    public:
        /* Constructors */
        Subsim42DataProvider(const boost::property_tree::ptree& config);

        /* Accessors */
        boost::shared_ptr<SimIDataPoint> get_data_point(void) const;

    private:
        /* Disallow these */
        ~Subsim42DataProvider(void) {};
        Subsim42DataProvider& operator=(const Subsim42DataProvider&) {return *this;};

        int16_t _sc;  /* Which spacecraft number to parse out of 42 data */
    };
}

#endif
