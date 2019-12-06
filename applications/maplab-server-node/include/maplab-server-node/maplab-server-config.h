#ifndef MAPLAB_SERVER_NODE_MAPLAB_SERVER_CONFIG_H_
#define MAPLAB_SERVER_NODE_MAPLAB_SERVER_CONFIG_H_

#include <string>
#include <vector>

#include <aslam/common/yaml-file-serialization.h>
#include <aslam/common/yaml-serialization.h>

DECLARE_string(maplab_server_merged_map_folder);
DECLARE_string(maplab_server_resource_folder);
DECLARE_int32(maplab_server_backup_interval_s);

namespace maplab {

class MaplabServerNodeConfig : public aslam::YamlFileSerializable {
 public:
  std::vector<std::string> submap_commands;
  std::vector<std::string> global_map_commands;

  bool deserialize(const YAML::Node& config_node) override;
  void serialize(YAML::Node* config_node_ptr) const override;

  const std::string kYamlFieldNameSubmapCommands = "submap_commands";
  const std::string kYamlFieldNameGlobalMapCommands = "global_map_commands";
};

}  // namespace maplab

#endif  // MAPLAB_SERVER_NODE_MAPLAB_SERVER_CONFIG_H_
