#include "galaxy.hpp"

#include <boost/filesystem.hpp>

#include <iostream>

int main()
{
  const auto &game = g2::galaxy;

  const boost::filesystem::path cwd(boost::filesystem::current_path());
  const std::string config((cwd / "basic.yml").string());

  std::cout << config << std::endl;
  return game(config);
}

