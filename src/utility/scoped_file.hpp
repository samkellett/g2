#pragma once

#include <boost/filesystem.hpp>

#include <fstream>

namespace g2 {
namespace utils {

class scoped_file
{
public:
  scoped_file();
  scoped_file(const std::string &name);

  ~scoped_file();

  scoped_file(const scoped_file &) = delete;
  scoped_file &operator=(const scoped_file &) = delete;

  scoped_file(scoped_file &&) = default;
  scoped_file &operator=(scoped_file&&) = default;

  const boost::filesystem::path &path() const &;

private:
  boost::filesystem::path path_;
};

inline
scoped_file::scoped_file()
: scoped_file(boost::filesystem::unique_path().native())
{
}

inline
scoped_file::scoped_file(const std::string &name)
: path_{boost::filesystem::temp_directory_path() / name}
{
  // Open the path to create the file.
  std::ofstream stream;
  stream.open(path_.native());
}

inline
scoped_file::~scoped_file()
{
  const bool success(boost::filesystem::remove(path_));
  assert(success);
}

inline
const boost::filesystem::path &scoped_file::path() const &
{
  return path_;
}

} // namespace utils
} // namespace g2
