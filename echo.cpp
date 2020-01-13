#include <csignal>
#include "ClientSocket.h"
#include "Server.h"

Server server;

void handleExitSignal( int /* signal */ )
{
  server.close();
}


int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    std::signal( SIGINT, handleExitSignal );

    server.setPort( 5007 );
    server.onRead( [&] ( const std::weak_ptr<ClientSocket>& socket )
    {
        if( auto s = socket.lock() )
        {
            auto data = s->read();
            s->write( data );
        }
    });

    server.listen();
    return 0;
}
