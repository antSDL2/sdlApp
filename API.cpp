//API.cpp
#include "API.h"

namespace AtApp {
    State *API::Application = NULL;

    API::API() {
        Application = NULL;
    }

    API::~API() {
        Application = NULL;
    }
}
