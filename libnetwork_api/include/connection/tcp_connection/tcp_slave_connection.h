#ifndef _TCP_SLAVE_CONNECTION_H_
#define _TCP_SLAVE_CONNECTION_H_

//internal
#include "slave_connection.h"
#include "connection_traits.h"

namespace network
{
    class tcp_slave_connection : public network::slave_connection
    {
    public:
        tcp_slave_connection(int slave_socket, endpoint_unique_ptr& ep);

        ~tcp_slave_connection() override;

        std::int64_t send_data(const byte_vector&) noexcept;

        std::int64_t send_data(const std::string&) noexcept;

        std::int64_t read_data(byte_vector&) override;

        std::int64_t read_data(std::string&) override;

        int get_socket() const noexcept;

    private:
        struct impl;
        std::unique_ptr<impl> d_;
    };

} //namespace

#endif //_TCP_SLAVE_CONNECTION_H_
