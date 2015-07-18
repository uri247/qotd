#ifndef SERVER_HH
#define SERVER_HH

#include <functional>
#include <memory>

class ClientSocket;

class Server
{
public:
  ~Server();

  void setBacklog( int backlog );
  void setPort( int port );

  void close();
  void listen();

  template <class F> void onAccept( F&& f )
  {
    _handleAccept = f;
  }

private:
  int _backlog =  1;
  int _port    = -1;
  int _socket  = -1;

  std::function< void ( std::unique_ptr<ClientSocket> socket ) > _handleAccept;
};

#endif
