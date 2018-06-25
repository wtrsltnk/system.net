#ifndef _SYSTEM_NET_HTTP_HTTPLISTENERCONTEXT_H_
#define _SYSTEM_NET_HTTP_HTTPLISTENERCONTEXT_H_

#include <system.net/system.net.http.httplistenerrequest.h>
#include <system.net/system.net.http.httplistenerresponse.h>

namespace System {
namespace Net {
namespace Http {

class HttpListenerContext
{
protected:
    HttpListenerRequest *_request;
    HttpListenerResponse *_response;

public:
    HttpListenerContext();
    virtual ~HttpListenerContext();

    // Gets the HttpListenerRequest that represents a client's request for a resource.
    HttpListenerRequest *Request();

    // Gets the HttpListenerResponse object that will be sent to the client in response to the client's request.
    HttpListenerResponse *Response();

    // Gets an object used to obtain identity, authentication information, and security roles for the client whose request is represented by this HttpListenerContext object.
    // IPrincipal &User();
};

} // namespace Http
} // namespace Net
} // namespace System

#endif // _SYSTEM_NET_HTTP_HTTPLISTENERCONTEXT_H_
