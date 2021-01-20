//
// Copyright 2020 Levon Avakimyanc levon.avakimyanc.01@mail.ru
//

#ifndef INCLUDE_CLIENT_URLADDRES_HPP
#define INCLUDE_CLIENT_URLADDRES_HPP
#include <string>

const char protocol_name[] = "http://";
const size_t size_of_protocol = 7;

class URLAddress {
 public:
  explicit URLAddress(std::string);
  std::string Full_URL();
  std::string Host();
  std::string Port();
  std::string Target();
 private:
  std::string URL;
};
#endif  // INCLUDE_CLIENT_URLADDRES_HPP
