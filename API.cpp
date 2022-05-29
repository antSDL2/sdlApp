//API.cpp
#include "API.h"

namespace AtApp {
    State *API::Application = NULL;

    /// Basic constructor.
    API::API() {
        Application = NULL;
    }

    /// Basic destructor.
    API::~API() {
        Application = NULL;
    }
}
