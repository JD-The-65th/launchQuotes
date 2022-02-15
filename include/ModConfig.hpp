#pragma once
#include <string>

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(quote1, string, "quote1", "i forgor");
    CONFIG_VALUE(quote2, string, "quote2", "lmao");
    CONFIG_VALUE(quote3, string, "quote3", "e");
    CONFIG_VALUE(quote4, string, "quote4", "mr strimer play rap gode");
    CONFIG_VALUE(quote5, string, "quote5", "i forgor");
    CONFIG_VALUE(quote6, string, "quote6", "lmao");

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(quote1);
        CONFIG_INIT_VALUE(quote2);
        CONFIG_INIT_VALUE(quote3);
        CONFIG_INIT_VALUE(quote4);
        CONFIG_INIT_VALUE(quote5);
        CONFIG_INIT_VALUE(quote6);

        
    )
)