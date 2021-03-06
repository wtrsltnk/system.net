#include <fstream>
#include <iostream>
#include <system.net/system.net.http.httplistener.h>
#include <system.net/system.net.http.httplistenerexception.h>

using namespace System::Net::Http;

int main(int argc, char *argv[])
{
    HttpListener listener;

    listener.Prefixes().push_back("http://localhost:8383/");

    try
    {
        listener.Start();

        auto context = listener.GetContext();

        std::ifstream content("nova.jpg", std::ios::binary);
        std::vector<char> buffer((std::istreambuf_iterator<char>(content)),
                                 (std::istreambuf_iterator<char>()));

        context->Response()->WriteOutput(buffer);
        context->Response()->CloseOutput();

        delete context;

        listener.Stop();
    } catch (HttpListenerException const *ex)
    {
        std::cout << "Exception in http listener: " << ex->Message() << "\n";
    }

    return 0;
}
