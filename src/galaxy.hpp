#pragma once

#include "runtime/initialise.hpp"
#include "runtime/make_system.hpp"

#include "scene_tree/load_yml.hpp"
#include "scene_tree/make_tree.hpp"

#include "utility/compose.hpp"

namespace g2 {

constexpr auto galaxy(utils::make_composed(
  scene_tree::load_yml,
  scene_tree::make_tree,
  runtime::make_system,
  runtime::initialise
));

/*

galaxy is a composition of functions that start as a yaml configuration file and
end as a runtime with a world_tree.

template <typename... Ts,
  requires_t<Component<Ts>...> = 0>
using galaxy = compose<
  load_config,
  make_tree<Ts...>,
  make_world<Ts...>,
  execute
>;

int main()
{
  using my_components = meta::list<
    transform,
    render
  >;

  g2::galaxy<my_components> game;

  return game("config.yml");
}

*/

} // namespace g2

