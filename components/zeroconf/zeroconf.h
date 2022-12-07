#pragma once

#include <string>
#include <list>
#include "esphome/core/component.h"

namespace esphome {
namespace zeroconf {

struct Service {
    const char *name;
    const char *protocol;
    uint16_t port;
};

struct Txt {
    const char *key;
    const char *value;
};

class Zeroconf : public Component {
    public:
      void setup() override;
      void dump_config() override;
      float get_setup_priority() const override { return esphome::setup_priority::DATA; }

      void set_service(const char *name, const char *protocol, uint16_t port) { service_ = { name, protocol, port }; };
      void add_txt(const char *key, const char *value) { txts_.push_back({ key, value }); };

    protected:
      Service service_;
      std::list<Txt> txts_{};

      std::string txts_to_string();
};

}  // namespace zeroconf
}  // namespace esphome