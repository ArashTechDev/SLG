
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>

namespace sdds {
    extern double g_taxrate;
    extern double g_discount;


    class RideRequest {
    private:
        char m_customerName[11];
        char m_rideDescription[26];
        double m_price;
        bool discount;

    public:
        RideRequest();
        void read(std::istream& is);
        void display() const;
        RideRequest(const RideRequest& src);
        RideRequest& operator=(const RideRequest& src);

    };
}

#endif