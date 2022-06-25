//API.cpp
#include "API.h"

namespace sdlApp {
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
