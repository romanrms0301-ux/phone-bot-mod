#include <Geode/Geode.hpp>
using namespace geode::prelude;

$on_mod(Loaded) {
    const bool enabled = Mod::get()->getSettingValue<bool>("bot-enabled");

    log::info("Phone Bot cargado correctamente");
    log::info("Estado del bot: {}", enabled ? "activado" : "desactivado");
}
