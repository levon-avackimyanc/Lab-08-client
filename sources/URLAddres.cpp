//
// Copyright 2020 Levon Avakimyanc levon.avakimyanc.01@mail.ru
//
#include "URLAddres.hpp"

#include <utility>
URLAddress::URLAddress(std::string url) { URL = url; }
std::string URLAddress::Full_URL() { return URL; }
std::string URLAddress::Host() {
  if (URL.find(protocol_name) == 0) {
    URL = URL.substr(size_of_protocol);
  }
  std::string Res_Host;
  for (char i : URL) {
    if (i == ':') {
      break;
    }
    Res_Host += i;
  }
  return Res_Host;
}
std::string URLAddress::Port() {
  if (URL.find(protocol_name) == 0) URL = URL.substr(size_of_protocol);
  std::string Res_Port;
  unsigned pos = 0;
  for (; pos < URL.size(); ++pos) {
    if (URL[pos] == ':') {
      break;
    }
  }
  for (unsigned i = pos + 1; i < URL.size(); ++i) {
    if (URL[i] == '/') {
      break;
    }
    Res_Port += URL[i];
  }
  return Res_Port;
}
std::string URLAddress::Target() {
  if (URL.find(protocol_name) == 0) URL = URL.substr(size_of_protocol);
  std::string Res_Target;
  unsigned pos = 0;
  for (; pos < URL.size(); ++pos) {
    if (URL[pos] == '/') break;
  }
  for (unsigned i = pos; i < URL.size(); ++i) {
    Res_Target += URL[i];
  }
  return Res_Target;
}