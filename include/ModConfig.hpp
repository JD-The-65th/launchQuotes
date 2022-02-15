#pragma once
#include <string>

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(quote1, std::String, "quote1", "i forgor");
    CONFIG_VALUE(quote2, std::String, "quote2", "lmao");
    CONFIG_VALUE(quote3, std::String, "quote3", "e");
    CONFIG_VALUE(quote4, std::String, "quote4", "mr strimer play rap gode");
    CONFIG_VALUE(quote5, std::String, "quote5", "i forgor");
    CONFIG_VALUE(quote6, std::String, "quote6", "lmao");

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(quote1);
        CONFIG_INIT_VALUE(quote2);
        CONFIG_INIT_VALUE(quote3);
        CONFIG_INIT_VALUE(quote4);
        CONFIG_INIT_VALUE(quote5);
        CONFIG_INIT_VALUE(quote6);

        
    )
)