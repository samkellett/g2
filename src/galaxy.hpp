#pragma once

#include "config/load.hpp"
#include "config/make_tree.hpp"

#include "utility/compose.hpp"

namespace g2 {

using galaxy = utils::compose<
  config::load,
  config::make_tree
>;

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

  g2::galaxy<my_components> world;

  return world("game.yml");
}

*/

} // namespace g2
