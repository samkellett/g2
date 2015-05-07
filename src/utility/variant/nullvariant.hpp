#pragma once

namespace g2 {
namespace utils {

struct nullvariant_t {
  constexpr explicit nullvariant_t(int) noexcept;
};

inline
constexpr nullvariant_t::nullvariant_t(int) noexcept
{
}

static constexpr const nullvariant_t nullvariant{0};

} // namespace utils
} // namespace g2
