#ifdef __linux__

#ifndef _SELECTOR_EPOLL_H_
#define _SELECTOR_EPOLL_H_

//internal
#include "base_selector.h"
#include "connection_traits.h"
#include "base_session.h"

//std
#include <memory>

namespace network
{
    class selector_epoll : public base_selector
    {
    public:
        selector_epoll();

        ~selector_epoll() override;

        void add_connection
          (network::base_session*) noexcept override;

        void delete_connection
          (network::base_session*) noexcept override;

        void delete_all_connection() noexcept;

        void check_data_ready(int max_event, int wait_timeout) noexcept override;

        selector_epoll(const selector_epoll& other) = delete;

        selector_epoll& operator=(const selector_epoll& other) = delete;

    private:
        struct impl;
        std::unique_ptr<impl> d_;
    };

} //namespace

#endif //_SELECTOR_EPOLL_H_

#endif //__linux__
