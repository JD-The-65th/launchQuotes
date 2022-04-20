#pragma once
#include <string>

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
    
    CONFIG_VALUE(custQuoteActive, bool, "custQuoteActive", false);

    CONFIG_VALUE(quote1, std::string, "quote1", "i forgor");

    CONFIG_VALUE(quote2, std::string, "quote2", "lmao");

    CONFIG_VALUE(quote3, std::string, "quote3", "e");

    CONFIG_VALUE(quote4, std::string, "quote4", "mr strimer play rap gode");

    CONFIG_VALUE(quote5, std::string, "quote5", "i forgor");

    CONFIG_VALUE(quote6, std::string, "quote6", "lmao");

    CONFIG_VALUE(quote7, std::string, "quote7", "e");

    CONFIG_VALUE(quote8, std::string, "quote8", "mr strimer play rap gode");

    CONFIG_VALUE(quote9, std::string, "quote9", "i forgor");

    CONFIG_VALUE(quote10, std::string, "quote10", "lmao");

    CONFIG_VALUE(quote11, std::string, "quote11", "e");

    CONFIG_VALUE(quote12, std::string, "quote12", "mr strimer play rap gode");

    CONFIG_VALUE(quote13, std::string, "quote13", "i forgor");

    CONFIG_VALUE(quote14, std::string, "quote14", "lmao");

    CONFIG_VALUE(quote15, std::string, "quote15", "e");


    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(custQuoteActive);
        CONFIG_INIT_VALUE(quote1);
        CONFIG_INIT_VALUE(quote2);
        CONFIG_INIT_VALUE(quote3);
        CONFIG_INIT_VALUE(quote4);
        CONFIG_INIT_VALUE(quote5);
        CONFIG_INIT_VALUE(quote6);
        CONFIG_INIT_VALUE(quote7);
        CONFIG_INIT_VALUE(quote8);
        CONFIG_INIT_VALUE(quote9);
        CONFIG_INIT_VALUE(quote10);
        CONFIG_INIT_VALUE(quote11);
        CONFIG_INIT_VALUE(quote12);
        CONFIG_INIT_VALUE(quote13);
        CONFIG_INIT_VALUE(quote14);
        CONFIG_INIT_VALUE(quote15);

        
    )
)