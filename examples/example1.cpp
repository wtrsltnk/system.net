#include <http/httplistener.h>
#include <http/httplistenerexception.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <regex>
#include <memory>

using namespace System::Net::Http;

template<class T>
class i_will_be_deleted
{
    T _ptr;
public:
    i_will_be_deleted() : _ptr(nullptr) { }
    i_will_be_deleted(T ptr) : _ptr(ptr) { }
    ~i_will_be_deleted() { if (_ptr != nullptr) delete _ptr; }

    i_will_be_deleted& operator = (T& ptr) { _ptr = ptr; return *this; }
    T& operator -> () { return _ptr; }
};

int main(int argc, char* argv[])
{
    HttpListener listener;

    listener.Prefixes().push_back("http://localhost:8383/");

    try
    {
        listener.Start();
    }
    catch (HttpListenerException const *ex)
    {
        std::cout << "Exception starting http listener: " << ex->Message() << "\n";
    }

    try
    {
        i_will_be_deleted<HttpListenerContext*> context = listener.GetContext();

//        context->Response()->WriteResponse("<html><body><h1>Hello world</h1></body</html>");
//        context->Response()->Close();
        context->Response()->Redirect("https://tweakers.net/");
    }
    catch (HttpListenerException const *ex)
    {
        std::cout << "Exception getting context: " << ex->Message() << "\n";
    }

    try
    {
        listener.Stop();
    }
    catch (HttpListenerException const *ex)
    {
        std::cout << "Exception stopping http listener: " << ex->Message() << "\n";
    }

    return 0;
}
