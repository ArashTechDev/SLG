#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
#include <iomanip>
#include <cstring>

namespace sdds {

    double g_taxrate;
    double g_discount;

    RideRequest::RideRequest() {
        m_customerName[0] = '\0';
        m_rideDescription[0] = '\0';
        m_price = 0.0;
        discount = false;
    }


    void RideRequest::read(std::istream& is) {
        if (is.good()) {
            is.getline(m_customerName, 10, ',');
            is.getline(m_rideDescription, 25, ',');
            is >> m_price;
            char discountStatus;
            is >> discountStatus;
            discount = (discountStatus == 'Y');
            is.ignore(1000, '\n');
        }
    }

    void RideRequest::display() const {
        static int counter = 0;
        ++counter;

        std::cout << std::setw(2) << std::left << counter << ". ";

        if (m_customerName[0] == '\0') {
            std::cout << "No Ride Request" << std::endl;
        }
        else {
            double price_with_tax = m_price * (1 + g_taxrate);
            double price_with_discount = discount ? price_with_tax * (1 - g_discount) : price_with_tax;

            std::cout << std::setw(10) << std::left << m_customerName << "|"
                << std::setw(25) << std::left << m_rideDescription << "|"
                << std::setw(12) << std::left << std::fixed << std::setprecision(2) << price_with_tax << "|";

            if (discount) {
                std::cout << std::setw(13) << std::right << std::fixed << std::setprecision(2) << price_with_discount;
            }
            std::cout << std::endl;
        }
    }

    RideRequest::RideRequest(const RideRequest& src) {
        *this = src;
    }

    RideRequest& RideRequest::operator=(const RideRequest& src) {
        if (this != &src) {
            strncpy(m_customerName, src.m_customerName, 11);
            strncpy(m_rideDescription, src.m_rideDescription, 26);
            m_price = src.m_price;
            discount = src.discount;
        }
        return *this;
    }

} // namespace