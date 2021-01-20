//
// Copyright 2020 Levon Avakimyanc levon.avakimyanc.01@mail.ru
//

#ifndef INCLUDE_CLIENT_CLIENT_HPP
#define INCLUDE_CLIENT_CLIENT_HPP
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "URLAddres.hpp"

namespace beast = boost::beast;  // from <boost/beast.hpp>
namespace http = beast::http;    // from <boost/beast/http.hpp>
namespace net = boost::asio;     // from <boost/asio.hpp>
using tcp = net::ip::tcp;        // from <boost/asio/ip/tcp.hpp>

struct Request_parameters {
  std::string url;
  std::string host;
  std::string port;
  std::string target;
  std::string request_body;
  int version;
};

class Client {
 public:
  Client(int argc, char* argv[]);
  int Run();

 private:
  void prepareCommandLine();
  int argc_;
  char** argv_;
  Request_parameters Params;
};

#endif  // INCLUDE_CLIENT_CLIENT_HPP
