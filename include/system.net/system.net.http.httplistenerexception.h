#ifndef _SYSTEM_NET_HTTP_HTTPLISTENEREXCEPTION_H_
#define _SYSTEM_NET_HTTP_HTTPLISTENEREXCEPTION_H_

#include <exception>
#include <string>

namespace System {
namespace Net {
namespace Http {

class HttpListenerException : public std::exception
{
    std::string _message;

public:
    HttpListenerException(std::string const &message);

    std::string const &Message() const;
};

} // namespace Http
} // namespace Net
} // namespace System

#endif // _SYSTEM_NET_HTTP_HTTPLISTENEREXCEPTION_H_
